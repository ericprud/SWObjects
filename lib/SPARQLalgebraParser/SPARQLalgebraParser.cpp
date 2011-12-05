
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
#line 43 "lib/SPARQLalgebraParser/SPARQLalgebraParser.cpp"


#include "SPARQLalgebraParser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 271 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"

#include "../SPARQLalgebraScanner.hpp"

/* Line 317 of lalr1.cc  */
#line 329 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"

#include <stdarg.h>
#include "SPARQLalgebraScanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc  */
#line 69 "lib/SPARQLalgebraParser/SPARQLalgebraParser.cpp"

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
#line 138 "lib/SPARQLalgebraParser/SPARQLalgebraParser.cpp"
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  SPARQLalgebraParser::yytnamerr_ (const char *yystr)
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
  SPARQLalgebraParser::SPARQLalgebraParser (class SPARQLalgebraDriver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {
  }

  SPARQLalgebraParser::~SPARQLalgebraParser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  SPARQLalgebraParser::yy_symbol_value_print_ (int yytype,
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
  SPARQLalgebraParser::yy_symbol_print_ (int yytype,
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
  SPARQLalgebraParser::yydestruct_ (const char* yymsg,
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
  SPARQLalgebraParser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  SPARQLalgebraParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  SPARQLalgebraParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  SPARQLalgebraParser::debug_level_type
  SPARQLalgebraParser::debug_level () const
  {
    return yydebug_;
  }

  void
  SPARQLalgebraParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  int
  SPARQLalgebraParser::parse ()
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
#line 37 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 553 of lalr1.cc  */
#line 322 "lib/SPARQLalgebraParser/SPARQLalgebraParser.cpp"

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
#line 346 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 3:

/* Line 678 of lalr1.cc  */
#line 349 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 359 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(4) - (3)].p_Operation);
    }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 366 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(4) - (3)].p_Operation);
    }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 373 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Select((yysemantic_stack_[(4) - (3)].p_protoSelect).distinctness, (yysemantic_stack_[(4) - (3)].p_protoSelect).varSet, (yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_protoSelect).p_WhereClause, (yysemantic_stack_[(4) - (3)].p_protoSelect).p_SolutionModifier);
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 376 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Select((yysemantic_stack_[(1) - (1)].p_protoSelect).distinctness, (yysemantic_stack_[(1) - (1)].p_protoSelect).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(1) - (1)].p_protoSelect).p_WhereClause, (yysemantic_stack_[(1) - (1)].p_protoSelect).p_SolutionModifier);
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 382 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>((yysemantic_stack_[(1) - (1)].p_DatasetClause));
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 385 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 393 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(1) - (1)].p_protoSelect);
	(yyval.p_protoSelect).p_SolutionModifier = new SolutionModifier(NULL, NULL, NULL, -1, -1);
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 401 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(1) - (1)].p_protoSelect);
	(yyval.p_protoSelect).distinctness = DIST_all;
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 409 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(1) - (1)].p_protoSelect);
	(yyval.p_protoSelect).varSet = new StarVarSet();
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 417 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(1) - (1)].p_protoSelect);
	(yyval.p_protoSelect).p_OrderConditions = NULL;
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 425 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(1) - (1)].p_protoSelect);
	(yyval.p_protoSelect).p_having = NULL;
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 432 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	throw std::string("ExtendOpt: not ready to parse aggregates");
	(yyval.p_protoSelect) = (yysemantic_stack_[(4) - (3)].p_protoSelect);
    }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 436 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(1) - (1)].p_protoSelect);
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 443 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect).p_WhereClause = new WhereClause((yysemantic_stack_[(1) - (1)].p_op));
    }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 451 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 461 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 463 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 465 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(6) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(6) - (5)].p_URI));
      }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 477 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(7) - (6)].p_protoSelect);
	(yyval.p_protoSelect).varSet = (yysemantic_stack_[(7) - (4)].p_ExpressionAliaseList);
    }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 484 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList();
    }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 487 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(2) - (2)].p_Variable))));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 494 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	throw std::string("Extend: not ready to parse aggregates");
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 527 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(4) - (3)].p_protoSelect);
	(yyval.p_protoSelect).distinctness = DIST_distinct;
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 531 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(4) - (3)].p_protoSelect);
	(yyval.p_protoSelect).distinctness = DIST_reduced;
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 567 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	throw std::string("GroupClause: not ready to parse aggregates");
	(yyval.p_protoSelect).p_WhereClause = new WhereClause((yysemantic_stack_[(10) - (9)].p_op));
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 586 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(5) - (4)].p_protoSelect);
	(yyval.p_protoSelect).p_having = new w3c_sw::ProductionVector<const w3c_sw::Expression*>((yysemantic_stack_[(5) - (3)].p_Expression)); // !!!
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 595 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(7) - (6)].p_protoSelect);
	(yyval.p_protoSelect).p_OrderConditions = (yysemantic_stack_[(7) - (4)].p_OrderConditions);
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 602 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 606 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 614 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 621 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 625 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 631 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(4) - (2)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(4) - (3)].p_Expression);
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 638 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(6) - (5)].p_protoSelect); // ($5.p_group, ...)
	(yyval.p_protoSelect).p_SolutionModifier = new SolutionModifier(NULL, (yysemantic_stack_[(6) - (5)].p_protoSelect).p_having, (yysemantic_stack_[(6) - (5)].p_protoSelect).p_OrderConditions, (yysemantic_stack_[(6) - (3)].p_int), (yysemantic_stack_[(6) - (4)].p_int)); // !!!
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 645 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_int) = ((IntegerRDFLiteral*)(yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 648 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_int) = LIMIT_None;
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 672 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(4) - (3)].p_Operation);
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 679 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(4) - (3)].p_Operation);
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 686 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(3) - (2)]. p_OperationSet);
}
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 692 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	OperationSet* ret = new OperationSet();
	ret->push_back((yysemantic_stack_[(1) - (1)].p_Operation));
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 696 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)]. p_OperationSet)->push_back((yysemantic_stack_[(2) - (2)].p_Operation));
	(yyval. p_OperationSet) = (yysemantic_stack_[(2) - (1)]. p_OperationSet);
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 719 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (4)].p_URI));
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 725 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 734 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(5) - (3)].p_Silence), (yysemantic_stack_[(5) - (4)].p_URI));
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 740 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 743 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 751 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(5) - (3)].p_Silence), (yysemantic_stack_[(5) - (4)].p_URI));
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 759 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(5) - (3)].p_Silence), (yysemantic_stack_[(5) - (4)].p_URI));
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 767 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Add((yysemantic_stack_[(6) - (3)].p_Silence), (yysemantic_stack_[(6) - (4)].p_URI), (yysemantic_stack_[(6) - (5)].p_URI));
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 775 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Move((yysemantic_stack_[(6) - (3)].p_Silence), (yysemantic_stack_[(6) - (4)].p_URI), (yysemantic_stack_[(6) - (5)].p_URI));
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 783 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Copy((yysemantic_stack_[(6) - (3)].p_Silence), (yysemantic_stack_[(6) - (4)].p_URI), (yysemantic_stack_[(6) - (5)].p_URI));
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 791 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Insert((yysemantic_stack_[(4) - (3)].p_op), NULL);
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 799 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(4) - (3)].p_op), NULL);
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 807 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(4) - (3)].p_op), NULL);
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 815 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Modify((yysemantic_stack_[(6) - (5)].p_DeleteInsert).del, (yysemantic_stack_[(6) - (5)].p_DeleteInsert).ins, new WhereClause((yysemantic_stack_[(6) - (4)].p_op)));
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 821 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 824 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 831 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Insert) = NULL;
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 838 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_DeleteInsert).del = (yysemantic_stack_[(2) - (1)].p_Delete);
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(2) - (2)].p_Insert);
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 842 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_DeleteInsert).del = NULL;
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(1) - (1)].p_Insert);
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 851 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Delete) = new Delete((yysemantic_stack_[(4) - (3)].p_op), NULL);
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 859 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Insert) = new Insert((yysemantic_stack_[(4) - (3)].p_op), NULL);
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 867 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(4) - (3)].p_URI), driver.atomFactory);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 870 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(5) - (3)].p_URI), driver.atomFactory);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 878 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 894 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	w3c_sw_NEED_IMPL("DEFAULT");
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 897 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	w3c_sw_NEED_IMPL("NAMED");
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 900 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	w3c_sw_NEED_IMPL("ALL");
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 916 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_op) = (yysemantic_stack_[(1) - (1)].p_conj);
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 927 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_conj) = new ParserTableConjunction();
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 930 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
      (yysemantic_stack_[(2) - (1)].p_conj)->addTableOperation((yysemantic_stack_[(2) - (2)].p_op), false);
	(yyval.p_conj) = (yysemantic_stack_[(2) - (1)].p_conj);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 937 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = driver.curGraphName;
	driver.curGraphName = (yysemantic_stack_[(2) - (2)].p_TTerm);
      }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 940 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	  (yyval.p_op) = (yysemantic_stack_[(4) - (4)].p_op);
	  driver.curGraphName = (yysemantic_stack_[(4) - (3)].p_TTerm);
      }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 947 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_op) = (yysemantic_stack_[(4) - (3)].p_BasicGraphPattern);
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 950 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_op) = driver.ensureGraphPattern();
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 956 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_BasicGraphPattern) = driver.ensureGraphPattern();
	(yyval.p_BasicGraphPattern)->addTriplePattern((yysemantic_stack_[(1) - (1)].p_TriplePattern));
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 960 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_BasicGraphPattern)->addTriplePattern((yysemantic_stack_[(2) - (2)].p_TriplePattern));
	(yyval.p_BasicGraphPattern) = (yysemantic_stack_[(2) - (1)].p_BasicGraphPattern);
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 969 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(5) - (4)].p_conj)->insertTableOperation((yysemantic_stack_[(5) - (3)].p_op));
	(yyval.p_op) = (yysemantic_stack_[(5) - (4)].p_conj);
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 978 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	throw new std::string("GroupGraphPatternNoSub: GT_LPAREN IT_path VarOrTerm Path VarOrTerm GT_RPAREN not implemented");
	(yyval.p_op) = driver.ensureGraphPattern();
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 990 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_conj) = new ParserTableConjunction();
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 993 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_conj)->addTableOperation((yysemantic_stack_[(2) - (1)].p_conj), driver.unnestTree);
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1001 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(5) - (4)].p_conj)->addTableOperation((yysemantic_stack_[(5) - (3)].p_op), driver.unnestTree);
	(yyval.p_op) = (yysemantic_stack_[(5) - (4)].p_conj);
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1010 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	throw new std::string("GroupGraphPatternNoSub: GT_LPAREN IT_path VarOrTerm Path VarOrTerm GT_RPAREN not implemented");
	(yyval.p_op) = driver.ensureGraphPattern();
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1014 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_op) = new SubSelect(new Select((yysemantic_stack_[(1) - (1)].p_protoSelect).distinctness, (yysemantic_stack_[(1) - (1)].p_protoSelect).varSet, NULL, (yysemantic_stack_[(1) - (1)].p_protoSelect).p_WhereClause, (yysemantic_stack_[(1) - (1)].p_protoSelect).p_SolutionModifier));
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1020 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_conj) = new ParserTableConjunction();
	(yyval.p_conj)->addTableOperation((yysemantic_stack_[(1) - (1)].p_op), driver.unnestTree);
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1024 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
      (yysemantic_stack_[(2) - (1)].p_conj)->addTableOperation((yysemantic_stack_[(2) - (2)].p_op), driver.unnestTree);
	(yyval.p_conj) = (yysemantic_stack_[(2) - (1)].p_conj);
    }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1031 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(4) - (3)].p_Expressions);
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 1037 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 1040 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 1047 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TriplePattern) = driver.atomFactory->getTriple((yysemantic_stack_[(6) - (3)].p_TTerm), (yysemantic_stack_[(6) - (4)].p_TTerm), (yysemantic_stack_[(6) - (5)].p_TTerm));
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 1061 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	TableConjunction* ret = new TableConjunction();
	ret->addTableOperation((yysemantic_stack_[(6) - (3)].p_op), driver.unnestTree);
	ret->addTableOperation((yysemantic_stack_[(6) - (4)].p_op), driver.unnestTree);
	(yyval.p_op) = ret;
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 1070 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 1077 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = driver.curGraphName;
	driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 1080 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	  (yyval.p_op) = (yysemantic_stack_[(6) - (5)].p_op);
	  driver.curGraphName = (yysemantic_stack_[(6) - (4)].p_TTerm);
      }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1087 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_op) = new ServiceGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), (yysemantic_stack_[(6) - (5)].p_op), (yysemantic_stack_[(6) - (3)].p_Silence), driver.atomFactory, false);
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 1095 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	TableConjunction* ret = new TableConjunction();
	ret->addTableOperation((yysemantic_stack_[(5) - (3)].p_op), driver.unnestTree);
	ret->addTableOperation(new MinusGraphPattern((yysemantic_stack_[(5) - (4)].p_op)), driver.unnestTree);
	(yyval.p_op) = ret;
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 1104 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	TableDisjunction* ret = new TableDisjunction();
	ret->addTableOperation((yysemantic_stack_[(5) - (3)].p_op), driver.unnestTree);
	ret->addTableOperation((yysemantic_stack_[(5) - (4)].p_op), driver.unnestTree);
	(yyval.p_op) = ret;
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1113 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_op) = new Filter((yysemantic_stack_[(5) - (4)].p_op), (yysemantic_stack_[(5) - (3)].p_Expressions)->begin(), (yysemantic_stack_[(5) - (3)].p_Expressions)->end());
	(yysemantic_stack_[(5) - (3)].p_Expressions)->clear();
	delete (yysemantic_stack_[(5) - (3)].p_Expressions);
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 1129 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 1132 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(4) - (3)].p_Expressions)->push_front((yysemantic_stack_[(4) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(4) - (3)].p_Expressions);
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 1139 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 1145 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 1148 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 1205 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	// $$ = new PathAlternative($3, $4);
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 1211 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	// $$ = new PathSequence($3, $4);
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 1219 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	// $$ = new PathEltOrInverse($3);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 1225 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	// $$ = $3;
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 1228 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	// $$ = $5;
      }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 1240 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 1243 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 1251 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(4) - (3)].p_TTerm);
    }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 1258 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	// $1->push_back($2);
	(yyval.p_TTerm) = (yysemantic_stack_[(2) - (1)].p_TTerm);
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 1265 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 1282 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1289 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 1292 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 1303 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 1307 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 1310 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 1314 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil");
    }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 1329 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	ProductionVector<const Expression*>* t = new ProductionVector<const Expression*>();
	t->push_back((yysemantic_stack_[(5) - (3)].p_Expression));
	t->push_back((yysemantic_stack_[(5) - (4)].p_Expression));
	(yyval.p_Expression) = new BooleanDisjunction(t);
    }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 1338 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	ProductionVector<const Expression*>* t = new ProductionVector<const Expression*>();
	t->push_back((yysemantic_stack_[(5) - (3)].p_Expression));
	t->push_back((yysemantic_stack_[(5) - (4)].p_Expression));
	(yyval.p_Expression) = new BooleanConjunction(t);
    }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 1356 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new BooleanEQ((yysemantic_stack_[(5) - (3)].p_Expression), (yysemantic_stack_[(5) - (4)].p_Expression));
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 1359 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNE((yysemantic_stack_[(5) - (3)].p_Expression), (yysemantic_stack_[(5) - (4)].p_Expression));
    }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 1362 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new BooleanLT((yysemantic_stack_[(5) - (3)].p_Expression), (yysemantic_stack_[(5) - (4)].p_Expression));
    }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 1365 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new BooleanGT((yysemantic_stack_[(5) - (3)].p_Expression), (yysemantic_stack_[(5) - (4)].p_Expression));
    }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 1368 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new BooleanLE((yysemantic_stack_[(5) - (3)].p_Expression), (yysemantic_stack_[(5) - (4)].p_Expression));
    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 1371 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new BooleanGE((yysemantic_stack_[(5) - (3)].p_Expression), (yysemantic_stack_[(5) - (4)].p_Expression));
    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 1374 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new NaryIn((yysemantic_stack_[(4) - (3)].p_Expressions));
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 1386 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	ProductionVector<const Expression*>* t = new ProductionVector<const Expression*>();
	t->push_back((yysemantic_stack_[(5) - (3)].p_Expression));
	t->push_back((yysemantic_stack_[(5) - (4)].p_Expression));
	(yyval.p_Expression) = new ArithmeticSum(t);
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 1392 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	ProductionVector<const Expression*>* t = new ProductionVector<const Expression*>();
	t->push_back((yysemantic_stack_[(5) - (3)].p_Expression));
	t->push_back(new ArithmeticNegation((yysemantic_stack_[(5) - (4)].p_Expression)));
	(yyval.p_Expression) = new ArithmeticSum(t);
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 1406 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	ProductionVector<const Expression*>* t = new ProductionVector<const Expression*>();
	t->push_back((yysemantic_stack_[(5) - (3)].p_Expression));
	t->push_back(new ArithmeticNegation((yysemantic_stack_[(5) - (4)].p_Expression)));
	(yyval.p_Expression) = new ArithmeticProduct(t);
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 1412 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	ProductionVector<const Expression*>* t = new ProductionVector<const Expression*>();
	t->push_back((yysemantic_stack_[(5) - (3)].p_Expression));
	t->push_back(new ArithmeticInverse((yysemantic_stack_[(5) - (4)].p_Expression)));
	(yyval.p_Expression) = new ArithmeticProduct(t);
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 1421 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(4) - (3)].p_Expression));
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 1424 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(4) - (3)].p_Expression);
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 1427 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(4) - (3)].p_Expression));
    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 1435 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 1438 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 1441 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 1444 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 1447 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 1458 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 1461 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 1464 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 1467 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 1470 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 1473 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 1476 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 1479 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 1482 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 1485 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 1488 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ciel, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 1491 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 1494 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 1497 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yysemantic_stack_[(4) - (3)].p_Expressions))));
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 1501 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 1504 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 1507 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 1510 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 1513 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 1516 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 1519 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 1522 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 1525 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 1528 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 1531 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 1534 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 1537 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 1540 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 1543 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 1546 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 1549 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 1552 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha224, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 1555 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 1558 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 1561 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 1564 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 1568 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 1571 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 1574 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 1577 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 1580 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 1583 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 1586 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 1589 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 1592 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 1600 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 1609 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 1615 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 1622 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 1628 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_exists, driver.ensureGraphPattern(), NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 1650 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
 	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(3) - (2)].p_distinctness), (yysemantic_stack_[(3) - (3)].p_Expression)));
    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 1656 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 1659 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
}
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 1665 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 1672 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(3) - (1)].p_URI), (yysemantic_stack_[(3) - (2)].p_distinctness), (yysemantic_stack_[(3) - (3)].p_Expression)));
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 1678 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 1681 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 1684 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 1687 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 1690 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 1696 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group_concat, (yysemantic_stack_[(3) - (2)].p_distinctness), (yysemantic_stack_[(3) - (3)].p_Expression)));
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 1699 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group_concat, (yysemantic_stack_[(4) - (2)].p_distinctness), (yysemantic_stack_[(4) - (4)].p_Expression)));
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 1709 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_URI));
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 1712 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(4) - (2)].p_URI), new ArgList((yysemantic_stack_[(4) - (3)].p_Expressions))));
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 1718 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 1725 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 1731 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 1735 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 1742 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 2426 "lib/SPARQLalgebraParser/SPARQLalgebraParser.cpp"
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
  SPARQLalgebraParser::yysyntax_error_ (int yystate, int tok)
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
  const short int SPARQLalgebraParser::yypact_ninf_ = -614;
  const short int
  SPARQLalgebraParser::yypact_[] =
  {
       -70,  1124,    41,  -614,  -614,  -614,  -614,  -614,  -614,  -614,
    -614,  -614,  -614,  -614,  -614,  -614,  -614,  -614,  -614,  -614,
    -614,  -614,  -614,  -614,  -614,  -614,  -614,  -614,  -614,  -614,
    -614,  -614,  -614,   -95,   -16,   -10,    -8,    -5,    -5,     5,
    1687,     9,    34,  -614,  -614,    39,    39,    83,  1392,    39,
      23,   -96,    99,   503,    49,    53,    55,    62,   -20,  -614,
    -614,  -614,  -614,  -614,  -614,  -614,  -614,  -614,  -614,  -614,
    -614,  -614,    64,  -614,  -614,  -614,  -614,  -614,  1361,    73,
      84,    76,   753,  -614,  -614,  -614,  -614,  -614,  -614,  -614,
    -614,  -614,  -614,  -614,  -614,  -614,  -614,  -614,  -614,  -614,
    -614,  -614,  -614,  -614,    39,  -614,    79,  -614,  -614,  -614,
    -614,  -614,  -614,  -614,  -614,  -614,  -614,  -614,  -614,  -614,
    -614,  -614,  -614,  -614,  -614,  -614,  -614,  -614,  -121,  -614,
    -614,  1710,   179,   -11,  -614,   431,    39,    39,  -614,  -614,
    -614,  -614,  -614,  -614,   -13,  -614,  -614,  -614,  -614,  -614,
    -614,  -614,    39,  -614,    83,  -614,  -614,   -96,  -614,   111,
     105,  -614,    23,   105,    23,   105,    23,    23,  -614,    23,
    -614,  -614,    23,  1242,   116,  -614,  1160,   142,   143,  1207,
     148,   157,   558,   168,  -614,   511,  -614,  1324,  -614,  -614,
    -614,  -614,  -614,  -614,  -614,    39,  -614,  -614,  -614,  -614,
    -614,  -614,     0,   -69,     1,  -614,  -614,   110,  -614,    20,
    1738,  1738,  1738,  1738,  1738,  1738,  1738,  1738,  1738,  -107,
    1738,  1738,  1738,  1738,  1738,  1738,  1738,  1738,  1738,  1738,
    1738,  1738,   -23,  1738,  1738,  1738,  1738,  1738,  1738,  1738,
    1738,  1738,  1738,  1738,  1738,  1738,  1738,   176,  1738,  1738,
    1738,  1738,  1738,  1738,  1738,  1738,  1738,    39,  1738,  1738,
    1738,  1738,  1738,  1738,  1738,  1738,  1738,  1738,  1738,  1738,
    1738,  1738,   181,  1738,   185,    43,   188,   105,  -614,  -614,
    -614,  -614,   634,  1416,  -614,  -614,  -614,  1392,  -614,  -614,
     186,   186,   195,    39,  -614,    17,  1392,  -614,  -614,  -614,
    -614,  -614,  -614,  -614,   196,    39,   191,  -614,   105,   193,
     105,   201,   -78,   105,     2,   -78,   211,  -614,   -68,   -78,
     212,  -614,   215,     2,  -614,  -614,  -614,  -614,  -614,  -614,
    1392,    64,  -614,    28,  -614,  -614,  -614,   214,  -614,  -614,
    -107,  -614,  1738,   218,  -614,   991,   205,   219,   222,   226,
     228,   230,   231,   232,   233,   234,  1474,  -614,   236,  1497,
    1738,   224,   225,  1738,   239,  1738,   240,  -614,   241,   244,
    -614,  1738,   245,   246,   237,   249,   251,   252,  1738,  1555,
     253,   254,   242,  1738,   248,   257,   259,  -614,   263,   264,
     267,   268,  1578,   256,   260,   270,  1738,   274,  1738,   262,
     276,  1738,  1738,   265,   279,   280,   282,  1636,  1738,   285,
     286,   290,  -614,  1659,  -614,  -614,  -614,  -614,  -614,  1738,
     287,  -614,  1392,   293,  -614,   299,  -614,   301,   -13,   -13,
    -614,  -614,  -614,   -13,   -13,   -96,   -13,   302,  -614,   303,
    1289,   305,   306,  1442,  -614,   300,   308,  -614,  -614,  -614,
     -78,  -614,   310,  -614,  -614,  -614,  -614,  -614,   311,   -78,
    -614,    -7,    83,  -614,  -614,  -614,   -78,  -614,  -614,   313,
     -13,    64,  -614,  -614,   258,  1382,   316,  1738,   322,   321,
    1738,  -614,  -614,  -614,  -614,  -614,  -614,  -614,  -614,  -614,
    -614,  -614,  -614,  -614,   330,  1738,  1738,   331,  -614,   332,
    -614,  -614,  -614,  -614,  -614,  -614,  1738,  -614,  -614,  -614,
     333,  -614,   335,  -614,  -614,  1738,   336,  1738,  -614,  -614,
    -614,  -614,  -614,  -614,  -614,  1738,  1738,  -614,   337,  -614,
     338,  1738,  -614,   339,   346,  1738,  -614,  -614,  -614,  -614,
     348,   353,  -614,  -614,  -614,  -614,   354,  1408,   356,  1392,
    -614,  -614,   358,   -13,  -614,   -17,   -13,   -96,   361,  -614,
    -614,  -614,  -614,   -12,   362,   359,  -614,  -614,   363,  -614,
    -614,   365,  -614,   367,  -614,  1392,  -614,    29,  -614,  -614,
     368,  -614,   309,  -614,    61,   360,  -614,   364,   360,  -614,
    -614,   -66,   371,  -614,  -614,   372,  -614,   375,   376,   378,
    -614,  -614,   382,  -614,  -614,   383,  -614,  -614,  -614,  -614,
     384,  -614,   385,  -614,  -614,   386,   -13,  -614,  -614,  -614,
    -614,   430,  -614,  -614,  -614,  -614,   387,  -614,   392,  -614,
    -614,   341,  -614,   390,    39,  -614,  1738,  -614,   393,  1738,
     398,  -614,  -614,  -614,  -614,  -614,  -614,  -614,  -614,  -614,
    -614,  -614,  -614,   400,   401,   402,  -614,  -614,   404,    21,
     405,   407,  -614,  -614,   409,  -614,  -614,  -614,  -614,  -614,
    -614,  -614,  -614,   445,  -614,  -614,   445,   417,  -614,  -614,
     445,  -614,  -614,  -614,  -614,  -614,  1358,  1761,  -614,  1738,
    -614,  -614,  -614,   872,  -614,  1738,  -614,   156,  -614,   419,
    -614
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  SPARQLalgebraParser::yydefact_[] =
  {
         0,     0,     0,     2,     4,     6,     8,    10,    14,    16,
      18,    20,    22,    24,    17,    15,    26,    25,    21,    19,
      13,     3,    68,    70,    72,   132,    50,   135,   136,   137,
     138,   139,   133,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   141,   142,     0,     0,     0,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,     0,    74,
      76,    77,    78,    82,    79,    80,    81,    83,    84,    85,
      86,    11,     0,     1,    27,    32,    35,    38,     0,     0,
       0,     0,     0,   333,   334,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   335,   337,   336,   338,   339,   342,
     341,   239,   199,   200,     0,   238,     0,   207,   208,   209,
     215,   217,   216,   225,   210,   211,   212,   233,   286,   254,
     287,   234,   235,   236,   321,   322,   323,   237,   319,   313,
     340,     0,     0,     0,   130,     0,     0,     0,   164,   197,
     198,   206,   343,   344,     0,   195,   196,   202,   203,   204,
     201,   205,     0,    92,     0,    67,   194,     0,    66,     0,
       0,   102,    91,     0,    91,     0,    91,    91,   124,    91,
     124,   124,    91,     0,     0,    12,     0,     0,     0,     0,
       0,     0,     0,     0,    73,     0,    75,     0,    45,   154,
      44,    47,    46,    43,   145,     0,   148,   149,   150,   151,
     152,   146,     0,     0,     0,    48,    49,     0,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     288,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   317,   318,
     320,   315,     0,     0,    58,    60,    61,     0,   128,   131,
       0,   162,     0,     0,   190,     0,     0,   175,   176,   177,
     178,   180,   179,   189,     0,     0,     0,   129,     0,     0,
       0,     0,     0,    88,     0,     0,     0,   119,   121,     0,
       0,   120,     0,     0,     9,     5,    69,     7,    71,    23,
       0,     0,   143,     0,    28,    29,    33,     0,    36,    37,
       0,    39,     0,     0,    53,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   158,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   289,     0,     0,
     170,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   269,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   248,     0,   169,    56,   316,    62,    63,     0,
       0,    59,     0,     0,   163,     0,   168,     0,     0,     0,
     188,   187,   186,     0,     0,     0,     0,     0,   167,     0,
       0,     0,     0,     0,   103,     0,     0,   114,   110,   112,
       0,   113,     0,    89,   117,   118,   116,   115,     0,     0,
     100,     0,     0,   125,   122,   123,     0,    99,    98,     0,
       0,     0,   134,   144,     0,     0,     0,     0,     0,     0,
       0,   257,   256,   273,   252,   267,   240,   251,   266,   244,
     224,   159,   265,   253,     0,     0,     0,     0,   250,     0,
     285,   247,   249,   173,   276,   255,     0,   230,   284,   246,
       0,   231,     0,   283,   275,     0,     0,     0,   245,   274,
     264,   282,   258,   268,   157,     0,     0,   263,     0,   294,
       0,     0,   262,     0,     0,     0,   281,   243,   272,   232,
       0,     0,   241,   271,   270,   314,     0,     0,     0,     0,
     161,   165,     0,     0,   192,     0,     0,     0,     0,   140,
     166,    65,   111,     0,     0,   104,   107,    94,     0,    87,
      93,     0,   126,     0,    90,     0,   155,     0,    30,    34,
       0,    41,     0,    54,     0,   291,   214,     0,   291,   223,
     221,     0,     0,   219,   226,     0,   228,     0,     0,     0,
     213,   222,     0,   218,   220,     0,   227,   229,    64,    57,
       0,   183,     0,   191,   193,     0,     0,   184,   124,   124,
     101,     0,   106,   105,    95,    96,     0,    97,     0,   147,
     156,     0,    40,     0,     0,    55,     0,   292,     0,     0,
       0,   171,   174,   259,   278,   260,   279,   261,   280,   242,
     160,   181,   182,     0,     0,     0,   127,   153,     0,     0,
       0,     0,   172,   293,     0,   290,   185,   109,   108,    31,
     306,   307,   305,   300,   308,   309,   300,     0,   296,   297,
     300,   298,    42,    51,   277,   301,     0,     0,   295,     0,
     302,   303,   299,     0,   310,     0,   304,     0,   311,     0,
     312
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLalgebraParser::yypgoto_[] =
  {
      -614,  -614,  -614,  -614,   463,   464,  -614,   473,   235,    69,
     194,   114,   433,   480,  -614,  -614,  -614,  -614,  -614,  -614,
     -60,  -614,  -614,  -614,  -614,   340,   -38,  -614,   -58,   -86,
    -614,  -614,  -614,   -56,   -55,  -614,   269,  -614,  -614,   -52,
    -149,  -614,  -614,   495,   498,  -614,   493,  -614,  -614,  -614,
     -21,  -614,  -614,  -614,  -614,  -614,  -614,  -614,  -614,  -614,
    -614,  -614,  -614,  -614,    -6,   -47,  -300,  -229,   243,  -508,
     389,    -9,  -614,  -614,  -614,  -614,   -71,  -614,   347,   370,
    -614,  -322,  -614,   271,  -204,   425,   -51,  -614,   -49,  -614,
     -48,   -41,   -33,   -32,  -614,   -26,  -614,  -307,  -614,  -614,
    -614,  -614,  -614,  -614,  -614,  -614,  -614,  -262,  -150,    14,
    -614,   -40,  -614,  -614,  -614,  -614,  -614,  -614,  -614,  -614,
    -614,  -614,  -614,  -614,  -614,   -19,  -614,  -614,  -614,  -614,
    -614,  -613,  -614,  -614,  -614,  -614,  -614,  -614,   -42,  -614,
    -614,  -614,   -37,  -614,  -614,  -614,   -35,  -120,   -45,  -614,
    -614
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLalgebraParser::yydefgoto_[] =
  {
        -1,     2,     3,     4,     5,     6,    54,     7,     8,     9,
      10,    11,    12,    13,    55,    56,   336,   474,   631,   202,
      14,   203,    57,   204,   341,   208,   583,   189,    15,    16,
      17,   209,   584,    18,    19,   283,   284,   419,   285,    20,
     157,    21,    22,    23,    24,    58,    59,    60,   452,    61,
     154,    62,    63,    64,    65,    66,    67,    68,    69,    70,
     309,   622,   564,   565,   566,    71,   450,   457,   458,   316,
     320,   317,   463,   318,   464,   626,    25,   133,    26,    72,
     333,   195,   577,   104,   356,   134,    27,   425,    28,   293,
      29,    30,    31,    32,   372,   637,   591,   296,   297,   298,
     299,   300,   436,   301,   302,   555,   158,   144,   138,   105,
     146,   357,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   368,   118,   638,   119,   120,   660,   677,
     678,   686,   692,   679,   680,   681,   695,   121,   122,   279,
     280,   281,   123,   124,   125,   126,   127,   128,   129,   130,
     151
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char SPARQLalgebraParser::yytable_ninf_ = -1;
  const unsigned short int
  SPARQLalgebraParser::yytable_[] =
  {
       106,   194,   140,   150,   305,    42,   147,   175,   306,   471,
     277,   148,   188,   149,   190,   459,   191,   192,   359,   466,
     193,   196,   454,   197,   198,   422,   455,   337,   294,   155,
     641,   199,   294,     1,   437,   461,   428,   273,   278,   200,
     201,    73,   156,   636,   462,   618,   456,   449,   392,    36,
     102,   103,    39,   290,   429,    42,    74,    43,    44,    45,
      46,   139,   145,   687,   619,    47,   430,   689,   470,   413,
     370,   431,    48,    98,    99,   100,   184,   432,    52,   613,
     371,   446,    49,   185,   453,   288,   295,    75,   102,   103,
     295,   286,   132,    76,   670,    77,   334,   339,    78,   303,
     671,   672,   673,   335,   340,   674,    79,    80,    81,   140,
     654,   655,   131,   675,    50,   308,   343,   159,   311,   676,
     313,   552,   553,   207,   472,   629,   554,   556,    52,   558,
     433,   135,   187,   434,    98,    99,   100,   132,    98,    99,
     100,   310,   135,   312,   435,   314,   315,   153,   319,   576,
     568,   323,   173,    98,    99,   100,   176,   634,   179,   571,
     549,   321,   321,   575,   582,   182,   573,   187,   139,   205,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   207,
     206,   358,   275,   360,   361,   362,   363,   364,   365,   366,
     367,   369,   287,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   307,   388,   389,
     390,   391,   324,   393,   394,   395,   396,   338,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   416,   355,    98,    99,   100,   273,   325,   326,
     102,   103,   150,   286,   327,   147,   612,   465,   614,   615,
     148,   150,   149,   328,   147,   630,    98,    99,   100,   148,
     194,   149,   444,   442,   329,   447,   342,   451,   447,   447,
     451,   188,   387,   190,   451,   191,   192,   412,   447,   193,
     196,   414,   197,   198,   415,   150,   557,   610,   147,   423,
     199,   426,   438,   148,   440,   149,   443,   448,   200,   201,
     273,   145,   478,    94,    95,    96,    97,   460,   467,   653,
     145,   468,   572,   628,   480,   481,   491,   475,   482,   491,
     494,   479,   483,   497,   484,   499,   485,   486,   487,   488,
     489,   503,   492,   495,   496,   498,   500,   501,   510,   512,
     502,   504,   505,   516,   145,   507,   506,   508,   509,   513,
     514,   515,   491,   518,   477,   519,   528,   517,   530,   520,
     521,   533,   534,   522,   523,   525,   527,   540,   541,   526,
     529,   531,   532,   491,   535,   536,   537,   150,   538,   546,
     147,   542,   543,   303,   303,   148,   544,   149,   303,   303,
     547,   303,   136,   137,   252,   550,   152,   551,   559,   560,
     194,   561,   562,   563,   567,   451,   569,   570,   616,   574,
     578,   188,   579,   190,   451,   191,   192,   140,   581,   193,
     196,   451,   197,   198,   582,   303,   586,   589,   590,   593,
     199,   594,   596,   600,   601,   603,   145,   580,   200,   201,
     585,   290,   604,    42,   606,    43,    44,    45,    46,   607,
     608,   274,   609,    47,   611,   587,   588,   617,   620,   624,
      48,   625,   621,   627,   632,   633,   592,   643,   644,   636,
      49,   645,   646,   639,   647,   595,   139,   597,   648,   649,
     650,   651,   652,   291,   292,   598,   599,   618,   657,   663,
     461,   602,   658,   659,   665,   605,   666,   667,   668,   304,
     669,   682,    50,   683,   150,   684,   194,   147,   303,   685,
     303,   303,   148,   688,   149,   700,    52,   188,   177,   190,
     180,   191,   192,   160,   161,   193,   196,   174,   197,   198,
     150,   476,   161,   147,   548,   162,   199,   183,   148,   276,
     149,   441,   332,   162,   200,   201,   635,   163,   661,   344,
     178,   186,   421,   164,   181,   656,   165,   331,   289,   623,
     322,   164,   424,   145,   165,   642,   469,    39,   290,   640,
      42,   303,    43,    44,    45,    46,     0,   699,   166,     0,
      47,     0,     0,     0,     0,     0,   166,    48,     0,   145,
       0,     0,     0,   167,   168,     0,   662,    49,     0,   664,
       0,   167,   168,   169,   397,     0,     0,     0,   170,     0,
       0,   169,     0,     0,     0,     0,   170,     0,     0,     0,
       0,     0,     0,   171,   172,     0,     0,     0,     0,    50,
       0,   171,   172,     0,     0,     0,     0,     0,     0,     0,
     427,     0,     0,    52,     0,     0,   691,   694,   273,   696,
       0,     0,   439,     0,     0,   698,   445,   210,     0,   211,
     212,   213,   214,     0,   215,   216,     0,   417,   418,   217,
     218,     0,   219,     0,   220,   221,   222,   223,     0,     0,
     473,   224,   225,     0,     0,   226,   227,     0,     0,     0,
     228,     0,   229,   230,     0,   231,   232,     0,     0,   233,
     234,   235,   236,   237,   238,     0,   239,     0,   240,     0,
       0,     0,   241,     0,     0,     0,   242,   243,     0,     0,
     244,   245,   246,   247,     0,     0,     0,     0,   248,   249,
       0,   250,     0,   251,     0,     0,   253,     0,   254,     0,
     255,   256,   257,     0,   258,   259,     0,     0,   260,   261,
       0,   262,     0,   263,     0,     0,     0,   264,     0,     0,
     265,     0,   266,   267,   268,     0,   269,   270,   271,   272,
       0,     0,     0,     0,     0,     0,   210,     0,   211,   212,
     213,   214,     0,   215,   216,    98,    99,   100,   217,   218,
       0,   219,     0,   220,   221,   222,   223,     0,     0,     0,
     224,   225,     0,     0,   226,   227,     0,     0,     0,   228,
       0,   229,   230,     0,   231,   232,     0,     0,   233,   234,
     235,   236,   237,   238,     0,   239,     0,   240,     0,     0,
       0,   241,     0,     0,     0,   242,   243,     0,     0,   244,
     245,   246,   247,     0,     0,     0,     0,   248,   249,     0,
     250,     0,   251,     0,   252,   253,     0,   254,     0,   255,
     256,   257,     0,   258,   259,     0,     0,   260,   261,     0,
     262,     0,   263,     0,     0,     0,   264,     0,     0,   265,
       0,   266,   267,   268,     0,   269,   270,   271,   272,     0,
       0,     0,     0,     0,     0,   210,     0,   211,   212,   213,
     214,     0,   215,   216,    98,    99,   100,   217,   218,     0,
     219,     0,   220,   221,   222,   223,     0,     0,     0,   224,
     225,     0,     0,   226,   227,     0,     0,   697,   228,     0,
     229,   230,     0,   231,   232,     0,     0,   233,   234,   235,
     236,   237,   238,     0,   239,     0,   240,     0,     0,     0,
     241,     0,     0,     0,   242,   243,     0,     0,   244,   245,
     246,   247,     0,     0,     0,     0,   248,   249,     0,   250,
       0,   251,     0,     0,   253,     0,   254,     0,   255,   256,
     257,     0,   258,   259,     0,     0,   260,   261,     0,   262,
       0,   263,     0,     0,     0,   264,     0,     0,   265,     0,
     266,   267,   268,     0,   269,   270,   271,   272,     0,     0,
       0,     0,     0,     0,   210,     0,   211,   212,   213,   214,
       0,   215,   216,    98,    99,   100,   217,   218,     0,   219,
       0,   220,   221,   222,   223,     0,     0,     0,   224,   225,
       0,     0,   226,   227,     0,     0,     0,   228,     0,   229,
     230,     0,   231,   232,     0,     0,   233,   234,   235,   236,
     237,   238,     0,   239,     0,   240,     0,     0,     0,   241,
       0,     0,     0,   242,   243,     0,     0,   244,   245,   246,
     247,     0,     0,     0,     0,   248,   249,     0,   250,     0,
     251,     0,     0,   253,     0,   254,     0,   255,   256,   257,
       0,   258,   259,     0,     0,   260,   261,     0,   262,     0,
     263,     0,     0,     0,   264,     0,     0,   265,     0,   266,
     267,   268,     0,   269,   270,   271,   272,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,     0,    43,    44,
      45,    46,    98,    99,   100,     0,    47,     0,     0,     0,
       0,     0,     0,    48,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,    34,    35,    36,    37,    38,    39,
      40,    41,    42,     0,    43,    44,    45,    46,     0,     0,
       0,     0,    47,     0,     0,     0,     0,     0,     0,    48,
       0,     0,     0,     0,     0,    50,     0,     0,     0,    49,
       0,    51,     0,     0,     0,     0,     0,     0,     0,    52,
       0,     0,    35,    36,    37,    38,    39,    40,    41,    42,
       0,    43,    44,    45,    46,     0,     0,    53,     0,    47,
       0,    50,     0,     0,     0,     0,    48,    51,     0,     0,
       0,     0,     0,     0,     0,    52,    49,    35,    36,    37,
      38,    39,    40,    41,    42,     0,    43,    44,    45,    46,
       0,     0,   160,    53,    47,     0,     0,     0,     0,     0,
       0,    48,     0,     0,     0,     0,     0,     0,    50,     0,
       0,    49,     0,     0,    51,     0,   163,     0,     0,     0,
       0,     0,    52,     0,    35,    36,    37,    38,    39,    40,
      41,    42,     0,    43,    44,    45,    46,     0,     0,     0,
      53,    47,     0,    50,     0,     0,     0,     0,    48,    51,
       0,     0,     0,     0,     0,     0,     0,    52,    49,    35,
       0,    37,    38,     0,    40,    41,    42,     0,    43,    44,
      45,    46,     0,     0,     0,     0,    47,     0,     0,     0,
       0,     0,     0,   330,     0,     0,     0,     0,     0,     0,
      50,     0,     0,    49,     0,     0,    35,    36,     0,     0,
      39,    40,    41,    42,    52,    43,    44,    45,    46,     0,
       0,     0,     0,    47,     0,     0,     0,     0,    36,     0,
      48,    39,    40,    41,    42,    50,    43,    44,    45,    46,
      49,    51,     0,     0,    47,     0,     0,     0,     0,    52,
       0,    48,     0,     0,    36,     0,     0,    39,    40,     0,
      42,    49,    43,    44,    45,    46,     0,     0,     0,     0,
      47,     0,    50,     0,     0,     0,     0,    48,     0,     0,
       0,   690,     0,     0,     0,     0,    52,    49,     0,     0,
       0,     0,   290,    50,    42,     0,    43,    44,    45,    46,
       0,   345,   160,     0,    47,     0,     0,    52,     0,     0,
       0,    48,     0,     0,     0,     0,     0,     0,     0,    50,
       0,    49,     0,     0,     0,   141,   163,     0,     0,     0,
       0,     0,     0,    52,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   420,    50,   101,   102,   103,     0,     0,   282,
       0,     0,     0,     0,     0,     0,     0,    52,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   142,   143,     0,   102,
     103,     0,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     490,     0,   101,   102,   103,     0,     0,   345,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   493,     0,     0,     0,     0,     0,     0,
     345,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,     0,     0,
     101,   102,   103,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   511,     0,   101,   102,   103,     0,     0,   345,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   524,     0,     0,     0,     0,     0,
       0,   345,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,     0,
       0,   101,   102,   103,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   539,     0,   101,   102,   103,     0,     0,   345,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   545,     0,     0,     0,     0,
       0,     0,   345,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
      82,     0,   101,   102,   103,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   282,     0,   101,   102,   103,     0,     0,
       0,     0,     0,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   345,     0,   101,   102,   103,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   693,     0,   101,   102,   103,     0,
       0,     0,     0,     0,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,     0,     0,   101,   102,   103,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,     0,     0,   101,   102,   103
  };

  /* YYCHECK.  */
  const short int
  SPARQLalgebraParser::yycheck_[] =
  {
        40,    72,    47,    48,   154,    12,    48,    54,   157,   331,
     131,    48,    72,    48,    72,   315,    72,    72,   222,   319,
      72,    72,    20,    72,    72,   287,    24,    96,    45,   125,
      96,    72,    45,   103,   296,   103,    19,    82,   159,    72,
      72,     0,   138,   109,   112,    57,    44,   125,   252,     6,
     157,   158,     9,    10,    37,    12,   151,    14,    15,    16,
      17,    47,    48,   676,    76,    22,    49,   680,   330,   273,
      93,    54,    29,   151,   152,   153,    96,    60,    85,    96,
     103,   310,    39,   103,   313,    96,   103,   103,   157,   158,
     103,   131,   103,   103,    73,   103,    96,    96,   103,   144,
      79,    80,    81,   103,   103,    84,    37,    38,   103,   154,
     618,   619,   103,    92,    71,   160,    96,    18,   163,    98,
     165,   428,   429,   103,    96,    96,   433,   434,    85,   436,
     113,   103,   103,   116,   151,   152,   153,   103,   151,   152,
     153,   162,   103,   164,   127,   166,   167,   124,   169,   471,
     450,   172,   103,   151,   152,   153,   103,    96,   103,   459,
     422,   170,   171,   470,   103,   103,   466,   103,   154,    96,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   103,
      96,   221,   103,   223,   224,   225,   226,   227,   228,   229,
     230,   231,    13,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,    96,   248,   249,
     250,   251,    96,   253,   254,   255,   256,   203,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   277,   219,   151,   152,   153,   282,    96,    96,
     157,   158,   287,   283,    96,   287,   553,   318,   555,   556,
     287,   296,   287,    96,   296,   577,   151,   152,   153,   296,
     331,   296,   309,   308,    96,   310,   156,   312,   313,   314,
     315,   331,    96,   331,   319,   331,   331,    96,   323,   331,
     331,    96,   331,   331,    96,   330,   435,   549,   330,   103,
     331,    96,    96,   330,   103,   330,   103,    96,   331,   331,
     345,   287,   342,   147,   148,   149,   150,    96,    96,   616,
     296,    96,   462,   575,   109,    96,   356,   103,    96,   359,
     360,   103,    96,   363,    96,   365,    96,    96,    96,    96,
      96,   371,    96,   109,   109,    96,    96,    96,   378,   379,
      96,    96,    96,   383,   330,    96,   109,    96,    96,    96,
      96,   109,   392,    96,   340,    96,   396,   109,   398,    96,
      96,   401,   402,    96,    96,   109,    96,   407,   408,   109,
      96,   109,    96,   413,   109,    96,    96,   422,    96,   419,
     422,    96,    96,   428,   429,   422,    96,   422,   433,   434,
     103,   436,    45,    46,   101,    96,    49,    96,    96,    96,
     471,    96,    96,   103,    96,   450,    96,    96,   557,    96,
     152,   471,    96,   471,   459,   471,   471,   462,    96,   471,
     471,   466,   471,   471,   103,   470,    96,    96,    96,    96,
     471,    96,    96,    96,    96,    96,   422,   477,   471,   471,
     480,    10,    96,    12,    96,    14,    15,    16,    17,    96,
      96,   104,    96,    22,    96,   495,   496,    96,    96,    96,
      29,    96,   103,    96,    96,   156,   506,    96,    96,   109,
      39,    96,    96,   109,    96,   515,   462,   517,    96,    96,
      96,    96,    96,   136,   137,   525,   526,    57,    96,    96,
     103,   531,   151,   103,    96,   535,    96,    96,    96,   152,
      96,    96,    71,    96,   549,    96,   577,   549,   553,    64,
     555,   556,   549,    96,   549,    96,    85,   577,    55,   577,
      56,   577,   577,    20,    21,   577,   577,    54,   577,   577,
     575,   337,    21,   575,   420,    32,   577,    57,   575,   106,
     575,   306,   195,    32,   577,   577,   584,    44,   634,   209,
      55,    58,   283,    50,    56,   626,    53,   187,   133,   565,
     171,    50,   291,   549,    53,   591,   323,     9,    10,   588,
      12,   616,    14,    15,    16,    17,    -1,   697,    75,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    75,    29,    -1,   575,
      -1,    -1,    -1,    90,    91,    -1,   636,    39,    -1,   639,
      -1,    90,    91,   100,   257,    -1,    -1,    -1,   105,    -1,
      -1,   100,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,    -1,   120,   121,    -1,    -1,    -1,    -1,    71,
      -1,   120,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     293,    -1,    -1,    85,    -1,    -1,   686,   687,   693,   689,
      -1,    -1,   305,    -1,    -1,   695,   309,    23,    -1,    25,
      26,    27,    28,    -1,    30,    31,    -1,    33,    34,    35,
      36,    -1,    38,    -1,    40,    41,    42,    43,    -1,    -1,
     333,    47,    48,    -1,    -1,    51,    52,    -1,    -1,    -1,
      56,    -1,    58,    59,    -1,    61,    62,    -1,    -1,    65,
      66,    67,    68,    69,    70,    -1,    72,    -1,    74,    -1,
      -1,    -1,    78,    -1,    -1,    -1,    82,    83,    -1,    -1,
      86,    87,    88,    89,    -1,    -1,    -1,    -1,    94,    95,
      -1,    97,    -1,    99,    -1,    -1,   102,    -1,   104,    -1,
     106,   107,   108,    -1,   110,   111,    -1,    -1,   114,   115,
      -1,   117,    -1,   119,    -1,    -1,    -1,   123,    -1,    -1,
     126,    -1,   128,   129,   130,    -1,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,    25,    26,
      27,    28,    -1,    30,    31,   151,   152,   153,    35,    36,
      -1,    38,    -1,    40,    41,    42,    43,    -1,    -1,    -1,
      47,    48,    -1,    -1,    51,    52,    -1,    -1,    -1,    56,
      -1,    58,    59,    -1,    61,    62,    -1,    -1,    65,    66,
      67,    68,    69,    70,    -1,    72,    -1,    74,    -1,    -1,
      -1,    78,    -1,    -1,    -1,    82,    83,    -1,    -1,    86,
      87,    88,    89,    -1,    -1,    -1,    -1,    94,    95,    -1,
      97,    -1,    99,    -1,   101,   102,    -1,   104,    -1,   106,
     107,   108,    -1,   110,   111,    -1,    -1,   114,   115,    -1,
     117,    -1,   119,    -1,    -1,    -1,   123,    -1,    -1,   126,
      -1,   128,   129,   130,    -1,   132,   133,   134,   135,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    -1,    25,    26,    27,
      28,    -1,    30,    31,   151,   152,   153,    35,    36,    -1,
      38,    -1,    40,    41,    42,    43,    -1,    -1,    -1,    47,
      48,    -1,    -1,    51,    52,    -1,    -1,    55,    56,    -1,
      58,    59,    -1,    61,    62,    -1,    -1,    65,    66,    67,
      68,    69,    70,    -1,    72,    -1,    74,    -1,    -1,    -1,
      78,    -1,    -1,    -1,    82,    83,    -1,    -1,    86,    87,
      88,    89,    -1,    -1,    -1,    -1,    94,    95,    -1,    97,
      -1,    99,    -1,    -1,   102,    -1,   104,    -1,   106,   107,
     108,    -1,   110,   111,    -1,    -1,   114,   115,    -1,   117,
      -1,   119,    -1,    -1,    -1,   123,    -1,    -1,   126,    -1,
     128,   129,   130,    -1,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    -1,    25,    26,    27,    28,
      -1,    30,    31,   151,   152,   153,    35,    36,    -1,    38,
      -1,    40,    41,    42,    43,    -1,    -1,    -1,    47,    48,
      -1,    -1,    51,    52,    -1,    -1,    -1,    56,    -1,    58,
      59,    -1,    61,    62,    -1,    -1,    65,    66,    67,    68,
      69,    70,    -1,    72,    -1,    74,    -1,    -1,    -1,    78,
      -1,    -1,    -1,    82,    83,    -1,    -1,    86,    87,    88,
      89,    -1,    -1,    -1,    -1,    94,    95,    -1,    97,    -1,
      99,    -1,    -1,   102,    -1,   104,    -1,   106,   107,   108,
      -1,   110,   111,    -1,    -1,   114,   115,    -1,   117,    -1,
     119,    -1,    -1,    -1,   123,    -1,    -1,   126,    -1,   128,
     129,   130,    -1,   132,   133,   134,   135,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    14,    15,
      16,    17,   151,   152,   153,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    39,
      -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    17,    -1,    -1,   103,    -1,    22,
      -1,    71,    -1,    -1,    -1,    -1,    29,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    39,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    14,    15,    16,    17,
      -1,    -1,    20,   103,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    39,    -1,    -1,    77,    -1,    44,    -1,    -1,    -1,
      -1,    -1,    85,    -1,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    17,    -1,    -1,    -1,
     103,    22,    -1,    71,    -1,    -1,    -1,    -1,    29,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    39,     5,
      -1,     7,     8,    -1,    10,    11,    12,    -1,    14,    15,
      16,    17,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    39,    -1,    -1,     5,     6,    -1,    -1,
       9,    10,    11,    12,    85,    14,    15,    16,    17,    -1,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,     6,    -1,
      29,     9,    10,    11,    12,    71,    14,    15,    16,    17,
      39,    77,    -1,    -1,    22,    -1,    -1,    -1,    -1,    85,
      -1,    29,    -1,    -1,     6,    -1,    -1,     9,    10,    -1,
      12,    39,    14,    15,    16,    17,    -1,    -1,    -1,    -1,
      22,    -1,    71,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    83,    -1,    -1,    -1,    -1,    85,    39,    -1,    -1,
      -1,    -1,    10,    71,    12,    -1,    14,    15,    16,    17,
      -1,   103,    20,    -1,    22,    -1,    -1,    85,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    39,    -1,    -1,    -1,    93,    44,    -1,    -1,    -1,
      -1,    -1,    -1,    85,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,    96,    71,   156,   157,   158,    -1,    -1,   103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,    -1,   157,
     158,    -1,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
      96,    -1,   156,   157,   158,    -1,    -1,   103,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,
     103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    -1,    -1,
     156,   157,   158,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,    96,    -1,   156,   157,   158,    -1,    -1,   103,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,
      -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,   156,   157,   158,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,    96,    -1,   156,   157,   158,    -1,    -1,   103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,
      -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     103,    -1,   156,   157,   158,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   103,    -1,   156,   157,   158,    -1,    -1,
      -1,    -1,    -1,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   103,    -1,   156,   157,   158,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   103,    -1,   156,   157,   158,    -1,
      -1,    -1,    -1,    -1,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,    -1,    -1,   156,   157,   158,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,    -1,   156,   157,   158
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLalgebraParser::yystos_[] =
  {
         0,   103,   161,   162,   163,   164,   165,   167,   168,   169,
     170,   171,   172,   173,   180,   188,   189,   190,   193,   194,
     199,   201,   202,   203,   204,   236,   238,   246,   248,   250,
     251,   252,   253,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    14,    15,    16,    17,    22,    29,    39,
      71,    77,    85,   103,   166,   174,   175,   182,   205,   206,
     207,   209,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   225,   239,     0,   151,   103,   103,   103,   103,   169,
     169,   103,   103,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   156,   157,   158,   243,   269,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   284,   286,
     287,   297,   298,   302,   303,   304,   305,   306,   307,   308,
     309,   103,   103,   237,   245,   103,   238,   238,   268,   269,
     308,    93,   154,   155,   267,   269,   270,   298,   302,   306,
     308,   310,   238,   124,   210,   125,   138,   200,   266,    18,
      20,    21,    32,    44,    50,    53,    75,    90,    91,   100,
     105,   120,   121,   103,   167,   225,   103,   164,   203,   103,
     165,   204,   103,   173,    96,   103,   206,   103,   180,   187,
     188,   193,   194,   199,   236,   241,   246,   248,   250,   251,
     252,   253,   179,   181,   183,    96,    96,   103,   185,   191,
      23,    25,    26,    27,    28,    30,    31,    35,    36,    38,
      40,    41,    42,    43,    47,    48,    51,    52,    56,    58,
      59,    61,    62,    65,    66,    67,    68,    69,    70,    72,
      74,    78,    82,    83,    86,    87,    88,    89,    94,    95,
      97,    99,   101,   102,   104,   106,   107,   108,   110,   111,
     114,   115,   117,   119,   123,   126,   128,   129,   130,   132,
     133,   134,   135,   308,   238,   103,   172,   131,   159,   299,
     300,   301,   103,   195,   196,   198,   271,    13,    96,   245,
      10,   238,   238,   249,    45,   103,   257,   258,   259,   260,
     261,   263,   264,   308,   238,   268,   200,    96,   308,   220,
     210,   308,   210,   308,   210,   210,   229,   231,   233,   210,
     230,   231,   230,   210,    96,    96,    96,    96,    96,    96,
      29,   239,   238,   240,    96,   103,   176,    96,   269,    96,
     103,   184,   156,    96,   185,   103,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   269,   244,   271,   271,   244,
     271,   271,   271,   271,   271,   271,   271,   271,   283,   271,
      93,   103,   254,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,    96,   271,   271,
     271,   271,   244,   271,   271,   271,   271,   238,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,    96,   244,    96,    96,   308,    33,    34,   197,
      96,   196,   267,   103,   243,   247,    96,   238,    19,    37,
      49,    54,    60,   113,   116,   127,   262,   267,    96,   238,
     103,   168,   308,   103,   225,   238,   227,   308,    96,   125,
     226,   308,   208,   227,    20,    24,    44,   227,   228,   226,
      96,   103,   112,   232,   234,   236,   226,    96,    96,   228,
     267,   241,    96,   238,   177,   103,   170,   269,   271,   103,
     109,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,   271,    96,    96,   271,   109,   109,   271,    96,   271,
      96,    96,    96,   271,    96,    96,   109,    96,    96,    96,
     271,    96,   271,    96,    96,   109,   271,   109,    96,    96,
      96,    96,    96,    96,    96,   109,   109,    96,   271,    96,
     271,   109,    96,   271,   271,   109,    96,    96,    96,    96,
     271,   271,    96,    96,    96,    96,   271,   103,   171,   267,
      96,    96,   257,   257,   257,   265,   257,   200,   257,    96,
      96,    96,    96,   103,   222,   223,   224,    96,   226,    96,
      96,   226,   268,   226,    96,   257,   241,   242,   152,    96,
     271,    96,   103,   186,   192,   271,    96,   271,   271,    96,
      96,   256,   271,    96,    96,   271,    96,   271,   271,   271,
      96,    96,   271,    96,    96,   271,    96,    96,    96,    96,
     267,    96,   257,    96,   257,   257,   200,    96,    57,    76,
      96,   103,   221,   224,    96,    96,   235,    96,   267,    96,
     241,   178,    96,   156,    96,   186,   109,   255,   285,   109,
     285,    96,   255,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,   257,   229,   229,   236,    96,   151,   103,
     288,   189,   271,    96,   271,    96,    96,    96,    96,    96,
      73,    79,    80,    81,    84,    92,    98,   289,   290,   293,
     294,   295,    96,    96,    96,    64,   291,   291,    96,   291,
      83,   271,   292,   103,   271,   296,   271,    55,   271,   307,
      96
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  SPARQLalgebraParser::yytoken_number_[] =
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
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  SPARQLalgebraParser::yyr1_[] =
  {
         0,   160,   161,   161,   162,   163,   163,   164,   164,   165,
     165,   166,   166,   167,   167,   168,   168,   169,   169,   170,
     170,   171,   171,   172,   172,   173,   173,   174,   175,   177,
     178,   176,   179,   179,   180,   181,   181,   182,   183,   183,
     184,   185,   186,   187,   187,   187,   187,   187,   188,   188,
     189,   190,   191,   191,   192,   192,   193,   194,   195,   195,
     196,   196,   197,   197,   198,   199,   200,   200,   201,   202,
     202,   203,   203,   204,   205,   205,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   207,   208,   208,
     209,   210,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   220,   221,   221,   222,   222,   223,   224,
     225,   225,   226,   226,   227,   228,   228,   228,   228,   229,
     230,   231,   232,   232,   233,   233,   235,   234,   236,   236,
     237,   237,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   239,   239,   240,   240,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   242,   242,   243,   244,   244,
     245,   246,   247,   247,   249,   248,   250,   251,   252,   253,
     254,   254,   255,   256,   256,   257,   257,   257,   257,   257,
     257,   258,   259,   260,   261,   261,   262,   262,   262,   263,
     263,   264,   265,   265,   266,   267,   267,   268,   268,   269,
     269,   270,   270,   270,   270,   270,   270,   271,   271,   271,
     271,   271,   271,   272,   273,   274,   275,   275,   276,   276,
     276,   276,   276,   276,   276,   277,   278,   278,   279,   279,
     280,   280,   280,   281,   281,   281,   281,   281,   281,   281,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   283,   283,
     284,   285,   285,   286,   287,   288,   289,   289,   289,   290,
     291,   291,   292,   292,   293,   294,   294,   294,   294,   294,
     295,   295,   296,   297,   297,   298,   299,   300,   300,   301,
     301,   302,   302,   302,   303,   303,   303,   304,   304,   304,
     305,   305,   305,   306,   306,   307,   307,   307,   307,   308,
     308,   309,   309,   310,   310
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  SPARQLalgebraParser::yyr2_[] =
  {
         0,     2,     1,     1,     1,     4,     1,     4,     1,     4,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     1,     1,     2,     4,     0,
       0,     6,     0,     2,     7,     0,     2,     4,     0,     2,
       4,     4,     4,     1,     1,     1,     1,     1,     4,     4,
       1,    10,     1,     2,     1,     2,     5,     7,     1,     2,
       1,     1,     1,     1,     4,     6,     1,     1,     1,     4,
       1,     4,     1,     3,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     0,     1,
       5,     0,     1,     5,     5,     6,     6,     6,     4,     4,
       4,     6,     0,     2,     0,     1,     2,     1,     4,     4,
       4,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     2,     0,     4,     4,     4,
       1,     2,     1,     1,     5,     1,     1,     1,     1,     1,
       6,     1,     1,     1,     2,     1,     1,     5,     1,     1,
       1,     1,     1,     6,     1,     1,     2,     4,     1,     2,
       6,     6,     0,     1,     0,     6,     6,     5,     5,     5,
       1,     4,     2,     0,     2,     1,     1,     1,     1,     1,
       1,     5,     5,     4,     4,     6,     1,     1,     1,     1,
       1,     4,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     5,     1,     1,     1,     5,     5,
       5,     5,     5,     5,     4,     1,     5,     5,     5,     5,
       4,     4,     4,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     6,     4,     4,     4,     4,     4,     3,     4,
       4,     4,     4,     4,     1,     4,     4,     4,     4,     6,
       6,     6,     4,     4,     4,     4,     4,     4,     4,     3,
       4,     4,     4,     4,     4,     4,     4,     8,     6,     6,
       6,     4,     4,     4,     4,     4,     1,     1,     0,     1,
       7,     0,     1,     7,     4,     3,     1,     1,     1,     3,
       0,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       3,     4,     4,     1,     4,     2,     2,     1,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const SPARQLalgebraParser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "IT_base", "IT_prefix",
  "IT_project", "IT_extend", "IT_distinct", "IT_reduced", "IT_group",
  "IT_filter", "IT_order", "IT_bgp", "IT_triple", "IT_join", "IT_sequence",
  "IT_leftjoin", "IT_union", "IT_unit", "IT_reverse", "IT_named",
  "IT_modify", "IT_graph", "IT_substr", "IT_all", "IT_lcase", "IT_ucase",
  "IT_sha256", "IT_round", "IT_path", "IT_seconds", "IT_str", "IT_create",
  "IT_asc", "IT_desc", "IT_floor", "IT_minutes", "IT_alt", "IT_bound",
  "IT_minus", "IT_in", "IT_hours", "IT_concat", "GT_AND", "IT_default",
  "IT_a", "TriplesSameSubject", "IT_if", "IT_regex", "GT_path_PLUS",
  "IT_add", "GT_GE", "IT_ceil", "IT_load", "GT_path_TIMES", "IT_separator",
  "GT_GT", "IT_insert", "IT_isnumeric", "IT_bnode", "GT_path_OPT",
  "IT_abs", "IT_coalesce", "GT_RCURLEY", "IT_DISTINCT", "IT_strlen",
  "IT_contains", "GT_NOT", "IT_isliteral", "IT_uri", "GT_NEQUAL",
  "IT_service", "GT_PLUS", "IT_MIN", "IT_isblank", "IT_drop", "IT_delete",
  "IT_slice", "IT_sha512", "IT_MAX", "IT_SUM", "IT_COUNT", "IT_strlang",
  "GT_TIMES", "IT_AVG", "IT_table", "IT_strstarts", "IT_iri", "IT_sha384",
  "IT_now", "IT_move", "IT_deletewhere", "IT_SAMPLE", "NIL", "IT_day",
  "IT_isuri", "GT_RPAREN", "IT_encode_for_uri", "IT_GROUP_CONCAT",
  "IT_timezone", "IT_copy", "IT_exprlist", "IT_strdt", "GT_LPAREN",
  "IT_strends", "IT_deletedata", "IT_month", "GT_OR", "IT_exists",
  "GT_COMMA", "GT_LE", "IT_sameterm", "IT_quads", "IT_notoneof", "IT_year",
  "GT_EQUAL", "IT_seq", "GT_LT", "GT_LCURLEY", "IT_langmatches",
  "IT_insertdata", "IT_clear", "GT_DOT", "IT_isiri", "IT_silent", "IT__",
  "IT_datatype", "IT_mod", "IT_sha224", "GT_MINUS", "GT_DIVIDE",
  "GT_DTYPE", "IT_lang", "IT_sha1", "IT_md5", "IT_RAND", "IT_true",
  "IT_false", "INTEGER", "DECIMAL", "DOUBLE", "INTEGER_POSITIVE",
  "DECIMAL_POSITIVE", "DOUBLE_POSITIVE", "INTEGER_NEGATIVE",
  "DECIMAL_NEGATIVE", "DOUBLE_NEGATIVE", "STRING_LITERAL1",
  "STRING_LITERAL_LONG1", "STRING_LITERAL2", "STRING_LITERAL_LONG2",
  "IRI_REF", "PNAME_NS", "PNAME_LN", "BLANK_NODE_LABEL", "ANON",
  "POSITION", "VAR1", "VAR2", "LANGTAG", "$accept", "Top", "QueryUnit",
  "Query", "PrefixOpt", "UsingOpt", "_QUsingClause_E_Plus", "SliceOpt",
  "DistinctOpt", "ProjectOpt", "OrderOpt", "HavingOpt", "ExtendOpt",
  "GroupOpt", "BaseDecl", "PrefixDecl",
  "_O_QGT_LPAREN_E_S_QPNAME_NS_E_S_QIRI_REF_E_S_QGT_RPAREN_E_C", "$@1",
  "$@2",
  "_Q_O_QGT_LPAREN_E_S_QPNAME_NS_E_S_QIRI_REF_E_S_QGT_RPAREN_E_C_E_Star",
  "Project", "_QVar_E_Star", "Extend", "_QBinding_E_Star", "Binding",
  "GroupExpression", "ProjectExpression", "SubSelect", "DistinctReduced",
  "WhereClause", "GroupClause", "_QGroupExpression_E_Plus",
  "_QProjectExpression_E_Plus", "HavingClause", "OrderClause",
  "_QOrderCondition_E_Plus", "OrderCondition",
  "_O_QIT_asc_E_Or_QIT_desc_E_C",
  "_O_QGT_LPAREN_E_S_QIT_asc_E_Or_QIT_desc_E_S_QExpression_E_S_QGT_RPAREN_E_C",
  "Slice", "_O_QInteger_E_Or_QIT___E_C", "UpdateUnit", "Update_Base",
  "Update_Prefix", "Updates", "_QUpdate1_E_Plus", "Update1", "Load",
  "_QGraphRef_E_Opt", "Clear", "_QIT_silent_E_Opt", "Drop", "Create",
  "Add", "Move", "Copy", "InsertData", "DeleteData", "DeleteWhere",
  "Modify", "_QUsingClause_E_Star", "_QInsertClause_E_Opt",
  "_O_QDeleteClause_E_S_QInsertClause_E_Opt_Or_QInsertClause_E_C",
  "DeleteClause", "InsertClause", "UsingClause", "GraphOrDefault",
  "GraphRef", "GraphRefAll", "QuadPattern", "QuadData", "Quads",
  "_O_QQuadsNotTriples_E_Or_QTriplesTemplate_E_C",
  "_Q_O_QQuadsNotTriples_E_Or_QTriplesTemplate_E_C_E_Star",
  "QuadsNotTriples", "@3", "TriplesTemplate", "_QMyTriple_E_Plus",
  "GroupGraphPatternNoSub", "_O_QIT_join_E_Or_QIT_sequence_E_C",
  "_QGroupGraphPatternNoSub_E_Plus", "GroupGraphPatternSub",
  "_QGroupGraphPatternSub_E_Plus", "ExprList", "_QExpression_E_Plus",
  "MyTriple", "OptionalGraphPattern", "_QExprList_E_Opt",
  "GraphGraphPattern", "@4", "ServiceGraphPattern", "MinusGraphPattern",
  "GroupOrUnionGraphPattern", "Filter", "ExpressionList",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "Path", "PathAlternative",
  "PathSequence", "PathEltOrInverse", "PathMod",
  "_O_QGT_path_OPT_E_Or_QGT_path_TIMES_E_Or_QGT_path_PLUS_E_C",
  "PathPrimary", "PathOneInPropertySet", "_QPath_E_Plus", "Integer",
  "VarOrTerm", "VarOrIRIref", "Var", "GraphTerm", "Expression",
  "ConditionalOrExpression", "ConditionalAndExpression", "ValueLogical",
  "RelationalExpression", "RelativeExpression", "NumericExpression",
  "AdditiveExpression", "MultiplicativeExpression", "UnaryExpression",
  "PrimaryExpression", "BuiltInCall", "_QExpression_E_Opt",
  "RegexExpression", "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Opt",
  "SubstringExpression", "ExistsFunc", "Aggregate",
  "_O_QCount_E_Or_QMiscAgg_E_Or_QGroupConcat_E_C", "Count",
  "_QIT_DISTINCT_E_Opt", "_O_QGT_TIMES_E_Or_QExpression_E_C", "MiscAgg",
  "_O_QIT_SUM_E_Or_QIT_MIN_E_Or_QIT_MAX_E_Or_QIT_AVG_E_Or_QIT_SAMPLE_E_C",
  "GroupConcat", "Separator", "IRIrefOrFunction", "RDFLiteral",
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
  const SPARQLalgebraParser::rhs_number_type
  SPARQLalgebraParser::yyrhs_[] =
  {
       161,     0,    -1,   162,    -1,   201,    -1,   163,    -1,   103,
     174,   164,    96,    -1,   164,    -1,   103,   175,   165,    96,
      -1,   165,    -1,   103,   166,   167,    96,    -1,   167,    -1,
     225,    -1,   166,   225,    -1,   199,    -1,   168,    -1,   188,
      -1,   169,    -1,   180,    -1,   170,    -1,   194,    -1,   171,
      -1,   193,    -1,   172,    -1,   103,   182,   173,    96,    -1,
     173,    -1,   190,    -1,   189,    -1,     3,   151,    -1,     4,
     103,   179,    96,    -1,    -1,    -1,   103,   177,   152,   178,
     151,    96,    -1,    -1,   179,   176,    -1,   103,     5,   103,
     181,    96,   170,    96,    -1,    -1,   181,   269,    -1,     6,
     103,   183,    96,    -1,    -1,   183,   184,    -1,   103,   269,
     271,    96,    -1,   103,   156,   271,    96,    -1,   103,   156,
     288,    96,    -1,   199,    -1,   188,    -1,   180,    -1,   194,
      -1,   193,    -1,   103,     7,   169,    96,    -1,   103,     8,
     169,    96,    -1,   238,    -1,   103,     9,   103,   191,    96,
     103,   192,    96,   189,    96,    -1,   185,    -1,   191,   185,
      -1,   186,    -1,   192,   186,    -1,   103,    10,   271,   172,
      96,    -1,   103,    11,   103,   195,    96,   171,    96,    -1,
     196,    -1,   195,   196,    -1,   198,    -1,   271,    -1,    33,
      -1,    34,    -1,   103,   197,   271,    96,    -1,   103,    77,
     200,   200,   168,    96,    -1,   266,    -1,   125,    -1,   202,
      -1,   103,   174,   203,    96,    -1,   203,    -1,   103,   175,
     204,    96,    -1,   204,    -1,   103,   205,    96,    -1,   206,
      -1,   205,   206,    -1,   207,    -1,   209,    -1,   211,    -1,
     213,    -1,   214,    -1,   215,    -1,   212,    -1,   216,    -1,
     217,    -1,   218,    -1,   219,    -1,   103,    53,   308,   208,
      96,    -1,    -1,   227,    -1,   103,   121,   210,   228,    96,
      -1,    -1,   124,    -1,   103,    75,   210,   228,    96,    -1,
     103,    32,   210,   227,    96,    -1,   103,    50,   210,   226,
     226,    96,    -1,   103,    90,   210,   226,   226,    96,    -1,
     103,   100,   210,   226,   226,    96,    -1,   103,   120,   230,
      96,    -1,   103,   105,   230,    96,    -1,   103,    91,   229,
      96,    -1,   103,    21,   220,   238,   222,    96,    -1,    -1,
     220,   225,    -1,    -1,   224,    -1,   223,   221,    -1,   224,
      -1,   103,    76,   229,    96,    -1,   103,    57,   229,    96,
      -1,   103,    44,   308,    96,    -1,   103,    20,   308,   308,
      96,    -1,   125,    -1,   308,    -1,   308,    -1,   227,    -1,
      44,    -1,    20,    -1,    24,    -1,   231,    -1,   231,    -1,
     233,    -1,   234,    -1,   236,    -1,    -1,   233,   232,    -1,
      -1,   112,   268,   235,   236,    -1,   103,    12,   237,    96,
      -1,   103,    85,    18,    96,    -1,   245,    -1,   237,   245,
      -1,   236,    -1,   253,    -1,   103,   239,   241,   240,    96,
      -1,   246,    -1,   248,    -1,   250,    -1,   251,    -1,   252,
      -1,   103,    29,   267,   257,   267,    96,    -1,    14,    -1,
      15,    -1,   238,    -1,   240,   238,    -1,   236,    -1,   253,
      -1,   103,   239,   241,   242,    96,    -1,   246,    -1,   248,
      -1,   250,    -1,   251,    -1,   252,    -1,   103,    29,   267,
     257,   267,    96,    -1,   187,    -1,   241,    -1,   242,   241,
      -1,   103,   101,   244,    96,    -1,   271,    -1,   244,   271,
      -1,   103,    13,   267,   267,   267,    96,    -1,   103,    16,
     238,   238,   247,    96,    -1,    -1,   243,    -1,    -1,   103,
      22,   268,   249,   238,    96,    -1,   103,    71,   210,   268,
     238,    96,    -1,   103,    39,   238,   238,    96,    -1,   103,
      17,   238,   238,    96,    -1,   103,    10,   243,   238,    96,
      -1,    93,    -1,   103,   271,   256,    96,    -1,   109,   271,
      -1,    -1,   256,   255,    -1,   258,    -1,   259,    -1,   260,
      -1,   261,    -1,   264,    -1,   263,    -1,   103,    37,   257,
     257,    96,    -1,   103,   116,   257,   257,    96,    -1,   103,
      19,   257,    96,    -1,   103,   262,   257,    96,    -1,   103,
     127,   200,   200,   257,    96,    -1,    60,    -1,    54,    -1,
      49,    -1,   308,    -1,    45,    -1,   103,   113,   265,    96,
      -1,   257,    -1,   265,   257,    -1,   138,    -1,   269,    -1,
     270,    -1,   269,    -1,   308,    -1,   157,    -1,   158,    -1,
     308,    -1,   298,    -1,   302,    -1,   306,    -1,   310,    -1,
      93,    -1,   272,    -1,   273,    -1,   274,    -1,   279,    -1,
     280,    -1,   281,    -1,   103,   107,   271,   271,    96,    -1,
     103,    43,   271,   271,    96,    -1,   275,    -1,   277,    -1,
     276,    -1,   103,   115,   271,   271,    96,    -1,   103,    70,
     271,   271,    96,    -1,   103,   117,   271,   271,    96,    -1,
     103,    56,   271,   271,    96,    -1,   103,   110,   271,   271,
      96,    -1,   103,    51,   271,   271,    96,    -1,   103,    40,
     244,    96,    -1,   278,    -1,   103,    72,   271,   271,    96,
      -1,   103,   129,   271,   271,    96,    -1,   103,    83,   271,
     271,    96,    -1,   103,   130,   271,   271,    96,    -1,   103,
      67,   271,    96,    -1,   103,    72,   271,    96,    -1,   103,
     129,   271,    96,    -1,   282,    -1,   297,    -1,   298,    -1,
     302,    -1,   306,    -1,   269,    -1,   156,    -1,   103,    31,
     271,    96,    -1,   103,   132,   271,    96,    -1,   103,   119,
     271,   109,   271,    96,    -1,   103,   126,   271,    96,    -1,
     103,    38,   269,    96,    -1,   103,    87,   271,    96,    -1,
     103,    69,   271,    96,    -1,   103,    59,   283,    96,    -1,
     103,   135,    96,    -1,   103,    61,   271,    96,    -1,   103,
      52,   271,    96,    -1,   103,    35,   271,    96,    -1,   103,
      28,   271,    96,    -1,   103,    42,   244,    96,    -1,   286,
      -1,   103,    65,   271,    96,    -1,   103,    26,   271,    96,
      -1,   103,    25,   271,    96,    -1,   103,    97,   271,    96,
      -1,   103,    66,   271,   109,   271,    96,    -1,   103,    86,
     271,   109,   271,    96,    -1,   103,   104,   271,   109,   271,
      96,    -1,   103,   114,   271,    96,    -1,   103,   106,   271,
      96,    -1,   103,    94,   271,    96,    -1,   103,    41,   271,
      96,    -1,   103,    36,   271,    96,    -1,   103,    30,   271,
      96,    -1,   103,    99,   271,    96,    -1,   103,    89,    96,
      -1,   103,   134,   271,    96,    -1,   103,   133,   271,    96,
      -1,   103,   128,   271,    96,    -1,   103,    27,   271,    96,
      -1,   103,    88,   271,    96,    -1,   103,    78,   271,    96,
      -1,   103,    62,   254,    96,    -1,   103,    47,   271,   109,
     271,   109,   271,    96,    -1,   103,    82,   271,   109,   271,
      96,    -1,   103,   102,   271,   109,   271,    96,    -1,   103,
     111,   271,   109,   271,    96,    -1,   103,   123,   271,    96,
      -1,   103,    95,   271,    96,    -1,   103,    74,   271,    96,
      -1,   103,    68,   271,    96,    -1,   103,    58,   271,    96,
      -1,   284,    -1,   287,    -1,    -1,   271,    -1,   103,    48,
     271,   109,   271,   285,    96,    -1,    -1,   255,    -1,   103,
      23,   271,   109,   271,   285,    96,    -1,   103,   108,   238,
      96,    -1,   103,   289,    96,    -1,   290,    -1,   293,    -1,
     295,    -1,    81,   291,   292,    -1,    -1,    64,    -1,    83,
      -1,   271,    -1,   294,   291,   271,    -1,    80,    -1,    73,
      -1,    79,    -1,    84,    -1,    92,    -1,    98,   291,   271,
      -1,    98,   291,   296,   271,    -1,   103,    55,   307,    96,
      -1,   308,    -1,   103,   308,   244,    96,    -1,   307,   301,
      -1,   131,   308,    -1,   159,    -1,   299,    -1,    -1,   300,
      -1,   303,    -1,   304,    -1,   305,    -1,   138,    -1,   139,
      -1,   140,    -1,   141,    -1,   142,    -1,   143,    -1,   144,
      -1,   145,    -1,   146,    -1,   136,    -1,   137,    -1,   147,
      -1,   149,    -1,   148,    -1,   150,    -1,   151,    -1,   309,
      -1,   153,    -1,   152,    -1,   154,    -1,   155,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  SPARQLalgebraParser::yyprhs_[] =
  {
         0,     0,     3,     5,     7,     9,    14,    16,    21,    23,
      28,    30,    32,    35,    37,    39,    41,    43,    45,    47,
      49,    51,    53,    55,    60,    62,    64,    66,    69,    74,
      75,    76,    83,    84,    87,    95,    96,    99,   104,   105,
     108,   113,   118,   123,   125,   127,   129,   131,   133,   138,
     143,   145,   156,   158,   161,   163,   166,   172,   180,   182,
     185,   187,   189,   191,   193,   198,   205,   207,   209,   211,
     216,   218,   223,   225,   229,   231,   234,   236,   238,   240,
     242,   244,   246,   248,   250,   252,   254,   256,   262,   263,
     265,   271,   272,   274,   280,   286,   293,   300,   307,   312,
     317,   322,   329,   330,   333,   334,   336,   339,   341,   346,
     351,   356,   362,   364,   366,   368,   370,   372,   374,   376,
     378,   380,   382,   384,   386,   387,   390,   391,   396,   401,
     406,   408,   411,   413,   415,   421,   423,   425,   427,   429,
     431,   438,   440,   442,   444,   447,   449,   451,   457,   459,
     461,   463,   465,   467,   474,   476,   478,   481,   486,   488,
     491,   498,   505,   506,   508,   509,   516,   523,   529,   535,
     541,   543,   548,   551,   552,   555,   557,   559,   561,   563,
     565,   567,   573,   579,   584,   589,   596,   598,   600,   602,
     604,   606,   611,   613,   616,   618,   620,   622,   624,   626,
     628,   630,   632,   634,   636,   638,   640,   642,   644,   646,
     648,   650,   652,   654,   660,   666,   668,   670,   672,   678,
     684,   690,   696,   702,   708,   713,   715,   721,   727,   733,
     739,   744,   749,   754,   756,   758,   760,   762,   764,   766,
     768,   773,   778,   785,   790,   795,   800,   805,   810,   814,
     819,   824,   829,   834,   839,   841,   846,   851,   856,   861,
     868,   875,   882,   887,   892,   897,   902,   907,   912,   917,
     921,   926,   931,   936,   941,   946,   951,   956,   965,   972,
     979,   986,   991,   996,  1001,  1006,  1011,  1013,  1015,  1016,
    1018,  1026,  1027,  1029,  1037,  1042,  1046,  1048,  1050,  1052,
    1056,  1057,  1059,  1061,  1063,  1067,  1069,  1071,  1073,  1075,
    1077,  1081,  1086,  1091,  1093,  1098,  1101,  1104,  1106,  1108,
    1109,  1111,  1113,  1115,  1117,  1119,  1121,  1123,  1125,  1127,
    1129,  1131,  1133,  1135,  1137,  1139,  1141,  1143,  1145,  1147,
    1149,  1151,  1153,  1155,  1157
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLalgebraParser::yyrline_[] =
  {
         0,   346,   346,   349,   355,   359,   362,   366,   369,   373,
     376,   382,   385,   392,   393,   400,   401,   408,   409,   416,
     417,   424,   425,   432,   436,   442,   443,   451,   457,   461,
     463,   461,   471,   473,   477,   484,   487,   494,   499,   501,
     505,   509,   513,   519,   520,   521,   522,   523,   527,   531,
     561,   567,   574,   575,   579,   580,   586,   595,   602,   606,
     613,   614,   621,   625,   631,   638,   645,   648,   668,   672,
     675,   679,   682,   686,   692,   696,   705,   706,   707,   708,
     709,   710,   711,   712,   713,   714,   715,   719,   725,   728,
     734,   740,   743,   751,   759,   767,   775,   783,   791,   799,
     807,   815,   821,   824,   831,   834,   838,   842,   851,   859,
     867,   870,   878,   881,   887,   893,   894,   897,   900,   908,
     912,   916,   922,   923,   927,   930,   937,   937,   947,   950,
     956,   960,   967,   968,   969,   973,   974,   975,   976,   977,
     978,   985,   986,   990,   993,   999,  1000,  1001,  1005,  1006,
    1007,  1008,  1009,  1010,  1014,  1020,  1024,  1031,  1037,  1040,
    1047,  1061,  1070,  1073,  1077,  1077,  1087,  1095,  1104,  1113,
    1129,  1132,  1139,  1145,  1148,  1196,  1197,  1198,  1199,  1200,
    1201,  1205,  1211,  1219,  1225,  1228,  1234,  1235,  1236,  1240,
    1243,  1251,  1257,  1258,  1265,  1282,  1285,  1289,  1292,  1298,
    1299,  1303,  1306,  1307,  1310,  1313,  1314,  1320,  1321,  1322,
    1323,  1324,  1325,  1329,  1338,  1347,  1351,  1352,  1356,  1359,
    1362,  1365,  1368,  1371,  1374,  1382,  1386,  1392,  1406,  1412,
    1421,  1424,  1427,  1433,  1434,  1435,  1438,  1441,  1444,  1447,
    1458,  1461,  1464,  1467,  1470,  1473,  1476,  1479,  1482,  1485,
    1488,  1491,  1494,  1497,  1500,  1501,  1504,  1507,  1510,  1513,
    1516,  1519,  1522,  1525,  1528,  1531,  1534,  1537,  1540,  1543,
    1546,  1549,  1552,  1555,  1558,  1561,  1564,  1568,  1571,  1574,
    1577,  1580,  1583,  1586,  1589,  1592,  1595,  1596,  1600,  1603,
    1609,  1615,  1618,  1622,  1628,  1640,  1644,  1645,  1646,  1650,
    1656,  1659,  1665,  1668,  1672,  1678,  1681,  1684,  1687,  1690,
    1696,  1699,  1705,  1709,  1712,  1718,  1725,  1731,  1735,  1742,
    1746,  1750,  1751,  1752,  1756,  1757,  1758,  1762,  1763,  1764,
    1768,  1769,  1770,  1774,  1775,  1779,  1780,  1781,  1782,  1786,
    1787,  1791,  1792,  1796,  1797
  };

  // Print the state stack on the debug stream.
  void
  SPARQLalgebraParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  SPARQLalgebraParser::yy_reduce_print_ (int yyrule)
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
  SPARQLalgebraParser::token_number_type
  SPARQLalgebraParser::yytranslate_ (int t)
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
     155,   156,   157,   158,   159
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int SPARQLalgebraParser::yyeof_ = 0;
  const int SPARQLalgebraParser::yylast_ = 1919;
  const int SPARQLalgebraParser::yynnts_ = 151;
  const int SPARQLalgebraParser::yyempty_ = -2;
  const int SPARQLalgebraParser::yyfinal_ = 73;
  const int SPARQLalgebraParser::yyterror_ = 1;
  const int SPARQLalgebraParser::yyerrcode_ = 256;
  const int SPARQLalgebraParser::yyntokens_ = 160;

  const unsigned int SPARQLalgebraParser::yyuser_token_number_max_ = 414;
  const SPARQLalgebraParser::token_number_type SPARQLalgebraParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 3818 "lib/SPARQLalgebraParser/SPARQLalgebraParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 1802 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
 /*** Additional Code ***/

void w3c_sw::SPARQLalgebraParser::error(const SPARQLalgebraParser::location_type& l,
				    const std::string& constM)
{
    driver.error(l, constM);
}

/* START Driver (@@ stand-alone would allow it to be shared with other parsers */

namespace w3c_sw {

    SPARQLalgebraDriver::SPARQLalgebraDriver (std::string baseURI, AtomFactory* atomFactory) : 
	YaccDriver(baseURI, atomFactory), curSubject(NULL), curPredicate(NULL), 
	curBGP(NULL), curFilter(NULL), 
	curResultSet(NULL), curResult(NULL), curExprList(NULL), 
	root(NULL), unnestTree(false)
{
}

    SPARQLalgebraDriver::~SPARQLalgebraDriver ()
{
}

const Operation* SPARQLalgebraDriver::parse (IStreamContext& in)
{
    root = NULL;
    curBGP = NULL;
    curGraphName = NULL;
    streamname = in.nameStr;

    SPARQLalgebraScanner scanner(this, in.p);
    scanner.set_debug(trace_scanning);
    lexer = &scanner;

    SPARQLalgebraParser parser(*this);
    parser.set_debug_level(trace_parsing);
    // !!! Clear out namespaces!
    ignorePrefixFlag = false;
    parser.parse();
    return root;
}

const Operation* SPARQLalgebraDriver::parse (std::string queryStr)
{
    IStreamContext in(queryStr.c_str(), IStreamContext::STRING);
    return parse(in);
}

void SPARQLalgebraDriver::executeSelect (IStreamContext& in, RdfDB* db, ResultSet* rs) {
    parse(in);
    root->execute(db, rs);
    delete root;
    root = NULL;
}
void SPARQLalgebraDriver::executeSelect (std::string queryStr, RdfDB* db, ResultSet* rs) {
    parse(queryStr);
    root->execute(db, rs);
    delete root;
    root = NULL;
}


} // namespace w3c_sw

/* END Driver */


