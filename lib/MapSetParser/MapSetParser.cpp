
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
#line 43 "lib/MapSetParser/MapSetParser.cpp"


#include "MapSetParser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 224 "lib/MapSetParser/MapSetParser.ypp"

#include "../MapSetScanner.hpp"

/* Line 317 of lalr1.cc  */
#line 348 "lib/MapSetParser/MapSetParser.ypp"

#include "../MapSetScanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lexWrapper


/* Line 317 of lalr1.cc  */
#line 68 "lib/MapSetParser/MapSetParser.cpp"

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
#line 137 "lib/MapSetParser/MapSetParser.cpp"
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  MapSetParser::yytnamerr_ (const char *yystr)
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
  MapSetParser::MapSetParser (class MapSetDriver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {
  }

  MapSetParser::~MapSetParser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  MapSetParser::yy_symbol_value_print_ (int yytype,
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
  MapSetParser::yy_symbol_print_ (int yytype,
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
  MapSetParser::yydestruct_ (const char* yymsg,
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
  MapSetParser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  MapSetParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  MapSetParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  MapSetParser::debug_level_type
  MapSetParser::debug_level () const
  {
    return yydebug_;
  }

  void
  MapSetParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  int
  MapSetParser::parse ()
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
#line 37 "lib/MapSetParser/MapSetParser.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 553 of lalr1.cc  */
#line 321 "lib/MapSetParser/MapSetParser.cpp"

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
#line 363 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root = new MapSet();
      }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 370 "lib/MapSetParser/MapSetParser.ypp"
    {
#if REGEX_LIB == SWOb_DISABLED
      throw std::string("not compiled with REGEX_LIB: can't map ") + (yysemantic_stack_[(5) - (3)].p_Variable)->toString() + " from " + (yysemantic_stack_[(5) - (4)].p_RDFLiteral)->toString() + " to " + (yysemantic_stack_[(5) - (5)].p_RDFLiteral)->toString() + ".";
#else /* ! REGEX_LIB == SWOb_DISABLED */
#if NotYet
      driver.root->rewriteVars.push_back(POSmap((yysemantic_stack_[(5) - (3)].p_Variable), (yysemantic_stack_[(5) - (4)].p_RDFLiteral)->getLexicalValue(), (yysemantic_stack_[(5) - (5)].p_RDFLiteral)->getLexicalValue()));
#endif /* NotYet */
#endif /* ! REGEX_LIB == SWOb_DISABLED */
    }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 379 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->server = (yysemantic_stack_[(3) - (3)].p_RDFLiteral);
    }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 382 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->user = (yysemantic_stack_[(3) - (3)].p_RDFLiteral);
    }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 385 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->password = (yysemantic_stack_[(3) - (3)].p_RDFLiteral);
    }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 388 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->database = (yysemantic_stack_[(3) - (3)].p_RDFLiteral);
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 391 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->stemURI = (yysemantic_stack_[(3) - (3)].p_URI);
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 394 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->primaryKey = (yysemantic_stack_[(3) - (3)].p_RDFLiteral);
    }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 407 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 410 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 433 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 439 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 441 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 443 "lib/MapSetParser/MapSetParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 451 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POSList) = new POSList;
	(yyval.p_POSList)->push_back((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 455 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSList)->push_back((yysemantic_stack_[(2) - (2)].p_Variable));
	(yyval.p_POSList) = (yysemantic_stack_[(2) - (1)].p_POSList);
    }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 463 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 466 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 474 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 481 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 489 "lib/MapSetParser/MapSetParser.ypp"
    {
	/* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	Construct* constr = new Construct((DefaultGraphPattern*)(yysemantic_stack_[(6) - (3)].p_BasicGraphPattern), (yysemantic_stack_[(6) - (4)].p_DatasetClauses), (yysemantic_stack_[(6) - (5)].p_WhereClause), (yysemantic_stack_[(6) - (6)].p_SolutionModifier));
	driver.root->maps.push_back(LabeledConstruct((yysemantic_stack_[(6) - (1)].p_RDFLiteral), constr));
    }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 498 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 510 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_POS), driver.posFactory);
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 516 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_POS), driver.posFactory);
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 522 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 529 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.curOp ? driver.curOp : new DefaultGraphPattern(), (yysemantic_stack_[(3) - (3)].p_BindingsClause));
	driver.curOp = NULL;
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 542 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 549 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = NULL;
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 557 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 565 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 573 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 581 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 588 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 591 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 598 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 601 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 604 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 607 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new POSExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 613 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 619 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 622 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 634 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 641 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 645 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 655 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 663 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 666 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 674 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 683 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 690 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 694 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 702 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 710 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 717 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 723 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 736 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POSList) = new POSList;
	(yyval.p_POSList)->push_back((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 740 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSList)->push_back((yysemantic_stack_[(2) - (2)].p_Variable));
	(yyval.p_POSList) = (yysemantic_stack_[(2) - (1)].p_POSList);
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 747 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(1) - (1)].p_POS));
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 750 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(2) - (2)].p_POS));
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 756 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding = new Binding();
      }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 758 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BindingValue) = driver.curBinding;
	  driver.curBinding = NULL;
      }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 765 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BindingValues) = NULL;
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 768 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBindingsClause->push_back((yysemantic_stack_[(2) - (2)].p_BindingValue));
	(yyval.p_BindingValues) = NULL;
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 775 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBindingsClause = new BindingClause((yysemantic_stack_[(3) - (2)].p_POSList));
      }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 777 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BindingsClause) = driver.curBindingsClause;
	  driver.curBindingsClause = NULL;
      }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 784 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BindingsClause) = NULL;
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 790 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 793 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 796 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 799 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 802 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = driver.getNULL();
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 805 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 812 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = NULL;
	driver.curBGP = NULL;
      }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 815 "lib/MapSetParser/MapSetParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 888 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 890 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.curFilter;
      }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 892 "lib/MapSetParser/MapSetParser.ypp"
    {
	  OptionalGraphPattern* ret = new OptionalGraphPattern(driver.curOp);
	  if (driver.curFilter) {
	      driver.curFilter->copyExpressionsTo(ret);
	      delete driver.curFilter;
	  }
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), ret);
	  driver.curFilter = (yysemantic_stack_[(4) - (3)].p_ParserFilter);
      }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 904 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 906 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 908 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_POS) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_POS);
      }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 911 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_POS), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_POS);
      }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 919 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 921 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 923 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(5) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(5) - (4)].p_POS), driver.curOp, driver.posFactory, false));
      }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 930 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 932 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 934 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.curOp));
      }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 942 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 945 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 947 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 955 "lib/MapSetParser/MapSetParser.ypp"
    {
	if (driver.curOp == NULL)
	    driver.ensureBasicGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 960 "lib/MapSetParser/MapSetParser.ypp"
    {
	  if (driver.curOp == NULL)
	      driver.ensureBasicGraphPattern();
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.curOp);
      }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 975 "lib/MapSetParser/MapSetParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    if (driver.curOp == NULL)
		driver.ensureBasicGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 992 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1000 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1004 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1006 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = NULL;
      }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1013 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1016 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1023 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1031 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1038 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_DistExprPair).distinctness = (yysemantic_stack_[(4) - (2)].p_distinctness);
	  (yyval.p_DistExprPair).p_Expression = (yysemantic_stack_[(4) - (3)].p_Expression);
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1049 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1052 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 1054 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = NULL;
      }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 1062 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 1064 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 1092 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_POS);
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1095 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_POS);
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 1155 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.posFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_POS)));
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 1162 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_POS);
	driver.curPredicate = (yyval.p_POS);
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 1166 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_POS);
    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 1178 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 1182 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_POS) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 1191 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(4) - (1)].p_listModifier) == LIST_exact) {
	    (yyval.p_POS) = driver.createBNode();
	    const POS* tail = (yyval.p_POS);
	    ProductionVector<const POS*>* members = (yysemantic_stack_[(4) - (3)].p_POSs);
	    const URI* first = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#first");
	    const URI* rest = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#rest");
	    const POS* nil = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil");
	    driver.ensureBasicGraphPattern();
	    for (unsigned i = 0; i < members->size(); i++) {
		driver.curBGP->addTriplePattern(driver.posFactory->getTriple(tail, first, members->at(i)));
		const POS* nextTail = i == members->size()-1 ? nil : driver.createBNode();
		driver.curBGP->addTriplePattern(driver.posFactory->getTriple(tail, rest, nextTail));
		tail = nextTail;
	    }
	    members->clear();
	    delete members;
	} else {
	    error(*(yylocation_stack_.end()), "unsupported function");
	}
    }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 1216 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 1219 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 1222 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 1225 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1228 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 1235 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 1243 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POSs) = new ProductionVector<const POS*>();
	(yyval.p_POSs)->push_back((yysemantic_stack_[(1) - (1)].p_POS));
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 1247 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSs)->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSs) = (yysemantic_stack_[(2) - (1)].p_POSs);
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 1259 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 1266 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 1269 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 1280 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 1283 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 1286 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 1289 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 1293 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 1304 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 1313 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 1320 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 1323 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 1331 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 1340 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 1347 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 1350 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 1362 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_GeneralComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_GeneralComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_GeneralComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 1373 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 1376 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 1379 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 1382 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 1385 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 1388 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 1391 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 1394 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryNotIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 1401 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = NULL;
    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 1413 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 1422 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 1425 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 1432 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 1435 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 1442 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 1450 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 1453 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 1457 "lib/MapSetParser/MapSetParser.ypp"
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

  case 248:

/* Line 678 of lalr1.cc  */
#line 1471 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 1474 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 1482 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 1491 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 1494 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 1501 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 1504 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 1507 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 1517 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 1520 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 1523 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 1526 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 1533 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 1539 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-str"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 1542 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-lang"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 1545 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-langMatches"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 1548 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-datatype"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 1551 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-bound"), new POSExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 1554 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-iri"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 1557 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-iri"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 1561 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-bnode"), (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 1564 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-coalesce"), $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 1568 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-if"), (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 1571 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-strlang"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 1574 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-strdt"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 1577 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-sameTerm"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 1580 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 1583 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 1586 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isBlank"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 1589 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isLiteral"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 1600 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 1603 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 1610 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-regex"), (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 1617 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 1624 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-exists"), driver.curOp, NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 1631 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new BooleanNegation(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-exists"), driver.curOp, NULL, NULL)));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 1638 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-count"), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 1641 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-sum"), (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 1644 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-min"), (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 1647 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-max"), (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 1650 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-avg"), (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 1653 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-sample"), (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 1657 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(4) - (4)].p_Expression));
      }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 1659 "lib/MapSetParser/MapSetParser.ypp"
    {
	  // x = new ArgList($2, driver.curExprList);
	  delete driver.curExprList;
	  driver.curExprList = NULL;
	  w3c_sw_NEED_IMPL("GROUP_CONCAT"); // !!!
	  // $$ = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-group-concat"), $3, $4.p_Expression, $4.separator));
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 1669 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 1676 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 1682 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 1689 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new POSExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 1699 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 1707 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 1715 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 1722 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 1726 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 1734 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 2470 "lib/MapSetParser/MapSetParser.cpp"
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
  MapSetParser::yysyntax_error_ (int yystate, int tok)
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
  const short int MapSetParser::yypact_ninf_ = -418;
  const short int
  MapSetParser::yypact_[] =
  {
      -418,    45,    43,  -418,   -48,  -418,  -418,  -418,  -418,   238,
      54,   -57,    60,    60,    60,    60,   -35,    60,    25,  -418,
    -418,  -418,  -418,    60,  -418,  -418,  -418,  -418,  -418,   -53,
    -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,    60,
      78,  -418,   -39,    60,   -35,  -418,  -418,  -418,  -418,  -418,
      69,  -418,  -418,  -418,  -418,  -418,    -6,   626,     9,  -418,
    -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,
    -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,
      72,  -418,    74,  -418,  -418,  -418,  -418,    82,  -418,  -418,
    -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,     0,
    -418,  -418,    22,    90,    32,  -418,   626,  -418,  -418,    32,
     748,    32,   -35,  -418,  -418,  -418,  -418,  -418,   103,  -418,
      50,  -418,  -418,   105,  -418,    98,   748,  -418,  -418,  -418,
    -418,  -418,  -418,  -418,  -418,   657,  -418,  -418,  -418,  -418,
     757,   983,   128,  -418,   626,   -57,  -418,  -418,  -418,  -418,
    -418,  -418,  -418,  -418,  -418,   829,   117,   125,   -27,   -26,
     140,   144,   154,    90,    90,   155,   157,   158,   159,   167,
     168,   169,   170,   174,   180,   191,   757,  -418,  -418,  -418,
    -418,  -418,  -418,  -418,   -13,   829,   983,  -418,  -418,  -418,
    -418,  -418,   133,    56,  -418,   194,  -418,  -418,  -418,   192,
     -32,  -418,   185,   189,   906,   906,   906,   198,   199,   199,
     199,   199,   200,   199,  -418,   152,  -418,  -418,  -418,  -418,
     146,  -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,
    -418,  -418,   -13,   829,   829,   829,  -418,  -418,   829,  -418,
    -418,  -418,   829,   829,   829,  -418,  -418,   829,   829,   829,
     829,   -57,   829,   829,   829,   829,   829,   829,  -418,   223,
    -418,  -418,   211,  -418,   601,   153,   160,  -418,  -418,   225,
     224,  -418,   119,   626,  -418,  -418,  -418,  -418,    32,  -418,
     748,  -418,  -418,  -418,  -418,   223,   223,  -418,  -418,  -418,
    -418,   223,  -418,   -57,  -418,   215,   205,   206,   829,   829,
     829,   829,   829,   829,   -26,   -26,  -418,  -418,    70,     7,
    -418,  -418,   218,   221,   222,  -418,   216,   217,   219,   228,
     229,   226,   236,   239,   231,   240,   241,   243,   244,   242,
    -418,   829,  -418,  -418,  -418,   601,  -418,   248,  -418,  -418,
    -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,
    -418,  -418,   983,   246,  -418,  -418,  -418,  -418,  -418,  -418,
    -418,  -418,  -418,  -418,  -418,  -418,  -418,   748,  -418,   511,
     829,   829,  -418,  -418,   829,  -418,   829,  -418,  -418,  -418,
    -418,  -418,  -418,  -418,  -418,  -418,   829,   829,     7,  -418,
    -418,  -418,   829,   829,  -418,  -418,  -418,  -418,  -418,   829,
     829,   829,  -418,  -418,   829,  -418,  -418,   829,  -418,  -418,
    -418,  -418,   829,  -418,  -418,  -418,  -418,  -418,  -418,  -418,
    -418,  -418,   626,    90,     3,  -418,  -418,  -418,   250,   252,
    -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,    -4,
     247,   255,   256,   257,   258,   253,  -418,    67,    67,    90,
      90,  -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,
     829,  -418,   829,  -418,  -418,  -418,  -418,  -418,   259,     5,
    -418,    90,  -418,  -418,   260,   852,    95,  -418,   263,  -418,
    -418,    90,  -418,  -418,  -418,  -418,   414,  -418,  -418,  -418,
    -418,  -418,  -418,   232,  -418,   264,  -418,  -418,    90,  -418,
    -418,   254,  -418,  -418,    60,  -418
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  MapSetParser::yydefact_[] =
  {
         2,     0,    17,     1,     0,     4,    19,    18,    21,    12,
      16,     0,     0,     0,     0,     0,     0,     0,     3,    22,
      20,   208,   209,     0,   329,   331,   330,   332,     6,   313,
       7,     8,     9,   333,   336,   335,    10,   334,    11,     0,
       0,    13,     0,     0,     0,   311,   312,   314,   309,    15,
       0,    23,     5,   310,   159,    27,     0,   161,    40,    24,
     193,   194,   195,   196,   197,   190,   327,   328,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   337,   338,   215,
       0,   162,   165,   169,   189,   188,   199,     0,   167,   204,
     205,   211,   212,   315,   316,   317,   213,   210,   214,     0,
      41,    28,    43,     0,     0,   160,   161,   166,   163,   179,
     198,     0,     0,    33,    34,    35,    36,    38,     0,    32,
      45,    44,    99,    91,   187,     0,   198,   186,   206,   207,
     164,   180,   170,   178,   203,   198,   200,   202,   168,    37,
       0,     0,    47,    46,   103,     0,    39,    92,    80,   191,
     176,   183,   185,   192,   201,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,    52,    55,    57,
      54,   283,   284,   285,     0,     0,    58,    59,    61,   144,
     142,   143,     0,    49,    48,     0,   101,   110,   104,   114,
       0,    25,   171,   181,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   263,    30,   216,   219,   223,   225,
     235,   237,   248,   251,   256,   257,   258,   264,   259,   260,
     261,   262,   307,     0,     0,     0,   287,   273,     0,   156,
     274,   155,     0,     0,     0,   291,   292,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,   149,
     146,   145,     0,    60,     0,     0,     0,    42,    50,    74,
      76,   100,   102,   103,   115,   112,    89,    26,   173,   177,
     198,   184,   254,   255,   253,   149,   149,   294,   295,   296,
     297,   149,   298,     0,    31,     0,   217,   221,     0,     0,
       0,     0,     0,     0,     0,     0,   236,   226,   238,   250,
     308,   306,     0,     0,     0,   157,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     150,     0,   265,    67,    68,    62,    63,     0,    65,    66,
      70,    71,    78,    79,    72,    75,    73,    77,   124,   128,
     121,   131,     0,   107,   111,   105,   116,   119,   120,   117,
     118,   135,   106,   113,    87,   174,   175,   198,   182,     0,
       0,     0,    29,    56,     0,   220,     0,   224,   227,   228,
     229,   230,   231,   232,   233,   234,     0,     0,   243,   249,
     239,   240,     0,     0,   252,   271,   272,   286,   152,     0,
       0,     0,   266,   267,     0,   269,   270,     0,   279,   280,
     281,   282,     0,   147,    64,    69,   125,   129,   122,   132,
     141,   108,   103,     0,     0,   172,   301,   302,     0,     0,
     299,   218,   222,   245,   246,   244,   247,   241,   242,     0,
       0,     0,     0,     0,     0,   289,   152,     0,     0,     0,
       0,   109,   139,    90,    85,    88,   293,   154,   152,   158,
       0,   153,     0,   276,   277,   268,   278,   290,     0,     0,
     126,     0,   123,   133,   136,     0,   304,   151,     0,   288,
     148,     0,   130,   137,   140,    97,     0,    83,    98,    94,
      95,    96,    93,     0,   305,     0,   275,   127,     0,    86,
      84,     0,   300,   138,     0,   303
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yypgoto_[] =
  {
      -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,
    -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,
    -418,  -418,   195,  -418,  -418,  -418,  -418,  -418,  -418,  -418,
    -418,  -418,   127,  -418,  -418,   120,  -418,  -418,   -25,  -418,
    -418,  -418,  -418,  -418,  -418,    38,    40,  -418,  -418,  -418,
    -418,  -418,  -418,  -418,  -418,  -175,  -151,  -418,  -418,  -418,
    -266,  -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,
    -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,
    -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,  -245,
    -115,    81,  -418,  -212,  -131,  -417,     4,  -147,  -418,  -418,
    -418,  -418,   209,  -418,  -418,  -418,   -36,  -418,  -418,   -59,
    -418,  -418,  -418,  -418,  -418,  -418,   -51,  -418,  -418,    37,
      41,   -99,  -418,  -418,  -418,  -418,  -418,  -418,   -78,   -88,
    -284,   -11,  -418,   136,  -418,  -418,  -418,   -56,  -418,  -418,
     -54,  -418,  -418,  -418,   -79,  -418,  -418,   -65,  -418,  -418,
    -418,  -202,  -418,  -205,  -118,  -126,  -123,  -418,  -418,  -418,
    -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,    -9,
    -418,  -418,  -418,   -55,  -418,    17,    19,   -41,  -176,    10,
    -418,  -418
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yydefgoto_[] =
  {
        -1,     1,     2,     9,    18,    40,     5,     6,    10,     7,
      20,    42,    56,   200,    58,   294,   295,    41,   101,   113,
     114,   115,   116,   102,   103,   119,   120,   142,   193,   267,
     121,   176,   177,   143,   186,   187,   194,   335,   336,   337,
     338,   339,   268,   344,   346,   269,   270,   146,   486,   455,
     475,   424,   147,   364,   148,   487,   123,   144,   195,   196,
     197,   353,   422,   354,   272,   198,   274,   275,   355,   356,
     418,   449,   357,   416,   447,   481,   358,   417,   448,   359,
     419,   450,   360,   361,   423,   484,   498,   474,   362,   188,
     189,   261,   446,   331,   461,   439,   287,   240,   241,   398,
      55,    57,    80,    81,   107,   108,   199,   111,   109,   125,
     365,   366,   279,   202,   132,   133,   150,   281,   203,   151,
     126,    83,    84,   104,    85,    86,    87,   135,   152,    88,
     127,   214,    90,   215,   216,   375,   296,   217,   377,   297,
     218,   219,   306,   307,   220,   221,   388,   394,   436,   389,
     308,   222,   309,   223,   224,   225,   226,   237,   181,   468,
     182,   183,   227,   458,   428,   494,   495,   228,   311,   229,
      46,    47,    48,   230,    93,    94,    95,   231,    29,   232,
      37,    98
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int MapSetParser::yytable_ninf_ = -199;
  const short int
  MapSetParser::yytable_[] =
  {
        23,   276,    92,    28,    30,    31,    32,   363,    38,   235,
     238,   134,   245,   246,    43,   190,    96,   180,   191,   340,
     112,    82,   137,   259,   392,   178,    36,   134,    99,   469,
      49,    44,   136,   459,    52,    39,   134,   453,   137,   454,
     460,   476,   480,   -14,   100,     3,    89,   137,    91,   460,
     131,    92,   138,   180,    53,    92,     4,   154,    21,    22,
     190,   178,     8,   191,    45,    96,   393,    97,    19,    96,
      82,    92,    51,   369,   370,    33,    34,    35,   124,   371,
      92,   265,   266,    21,    22,    96,   282,   283,   284,    92,
     340,   236,   239,   128,    96,    89,    50,    91,   128,    89,
     128,    91,    54,    96,    59,   260,   105,   420,   118,   117,
      33,    34,    35,   106,   129,    89,    97,    91,   110,   129,
      97,   129,   117,   122,    89,   140,    91,   386,   387,   179,
     348,   349,   145,    89,   201,    91,    97,   141,   190,   460,
     493,   191,    33,    34,    35,    97,   149,    21,    22,   192,
     184,   184,  -134,   233,    97,   264,   451,   384,   385,   350,
     351,   234,   352,   470,   471,   179,    24,    25,    26,    27,
      71,    72,    73,    74,    75,    76,   242,    33,    34,    35,
     243,   134,    21,    22,   433,   434,   184,   437,   438,   277,
     244,   247,   137,   248,   249,   250,   184,   298,   299,   300,
     301,   302,   303,   251,   252,   253,   254,   304,   305,   190,
     255,   415,   191,   288,   289,   290,   256,   292,    92,   378,
     379,   380,   381,   382,   383,    92,   190,   257,   271,   191,
     278,   273,    96,   280,   285,   286,   291,   293,   330,    96,
     323,    11,    12,    13,    14,    15,    16,    17,   332,   265,
     342,   266,   373,   341,   374,   395,   376,   343,   396,   397,
     399,   400,    89,   401,    91,   402,   403,   128,   134,    89,
     404,    91,   452,   405,   184,   407,   406,   408,   409,   137,
     410,   411,   372,    97,   185,   421,   412,   456,   129,   457,
      97,   462,   463,   464,   465,   466,   479,   460,   472,   473,
     496,   502,   483,   258,   501,   504,   263,   139,   347,   345,
     414,   500,    92,   310,   467,   130,   425,   368,   431,   367,
     482,   262,   432,   435,   341,   390,    96,   391,   505,     0,
     497,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   184,     0,   503,     0,     0,
       0,     0,     0,     0,     0,     0,    89,     0,    91,     0,
       0,     0,   184,     0,     0,     0,     0,    92,     0,   312,
     313,   314,     0,     0,   315,     0,     0,    97,   316,   317,
     318,    96,     0,   319,   320,   321,   322,     0,   324,   325,
     326,   327,   328,   329,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    89,     0,    91,     0,     0,     0,     0,     0,     0,
     490,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   490,    97,     0,   491,     0,   128,   128,     0,     0,
       0,     0,     0,     0,     0,   491,     0,     0,     0,     0,
       0,   499,   485,     0,     0,     0,     0,   129,   129,     0,
       0,     0,     0,     0,   488,     0,   489,   413,     0,     0,
       0,     0,     0,     0,     0,   488,     0,   489,     0,     0,
       0,     0,     0,     0,     0,   492,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   492,     0,     0,     0,
       0,     0,     0,     0,     0,   427,   429,   430,     0,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      24,    25,    26,    27,    33,    34,    35,     0,   426,    21,
      22,     0,     0,     0,     0,   440,   441,   442,     0,     0,
     443,     0,     0,   444,     0,     0,     0,   185,   445,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   204,   205,
       0,   206,     0,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,     0,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,     0,   477,     0,   478,   207,
     208,   209,   210,   211,   212,   213,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    24,    25,    26,
      27,    33,    34,    35,   333,   334,    21,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   185,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    60,    61,    62,    63,    64,     0,
       0,     0,  -198,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,    65,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,    60,    61,    62,    63,    64,
       0,     0,     0,     0,   153,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    65,     0,     0,     0,     0,     0,
       0,    33,    34,    35,     0,     0,    21,    22,     0,     0,
       0,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    24,    25,    26,    27,    33,    34,    35,    77,
      78,    21,    22,     0,    79,     0,     0,     0,     0,     0,
       0,     0,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    24,    25,    26,    27,    33,    34,    35,
      77,    78,    21,    22,     0,    79,    60,    61,    62,    63,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   155,     0,    65,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,     0,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,     0,     0,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    24,    25,    26,    27,    33,    34,
      35,    77,    78,    21,    22,   185,    79,    33,    34,    35,
       0,     0,    21,    22,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   204,   205,     0,   206,
     485,     0,   156,   157,   158,   159,   160,   161,   162,   163,
     164,     0,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,     0,     0,     0,     0,   207,   208,   209,
     210,   211,   212,   213,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    24,    25,    26,    27,    33,
      34,    35,   185,     0,    21,    22,     0,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    24,    25,
      26,    27,    33,    34,    35,     0,     0,    21,    22,   156,
     157,   158,   159,   160,   161,   162,   163,   164,     0,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
       0,     0,     0,     0,   207,   208,   209,   210,   211,   212,
     213,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    24,    25,    26,    27,    33,    34,    35,   185,
       0,    21,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   156,   157,   158,   159,
     160,   161,   162,   163,   164,     0,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,    35
  };

  /* YYCHECK.  */
  const short int
  MapSetParser::yycheck_[] =
  {
        11,    33,    57,    12,    13,    14,    15,   273,    17,    36,
      36,   110,   163,   164,    23,   141,    57,   140,   141,   264,
      20,    57,   110,    36,    17,   140,    16,   126,    19,   446,
      39,    84,   110,    37,    43,    10,   135,    34,   126,    36,
      44,   458,    37,    18,    35,     0,    57,   135,    57,    44,
     109,   106,   111,   176,    44,   110,    13,   135,   115,   116,
     186,   176,   110,   186,   117,   106,    59,    57,    14,   110,
     106,   126,   111,   285,   286,   110,   111,   112,    46,   291,
     135,    25,    26,   115,   116,   126,   204,   205,   206,   144,
     335,   118,   118,   104,   135,   106,    18,   106,   109,   110,
     111,   110,    33,   144,   110,   118,    34,   352,    86,    99,
     110,   111,   112,    39,   104,   126,   106,   126,    36,   109,
     110,   111,   112,    33,   135,    22,   135,    57,    58,   140,
      11,    12,    27,   144,   145,   144,   126,    87,   264,    44,
      45,   264,   110,   111,   112,   135,    48,   115,   116,    21,
     140,   141,    33,    36,   144,    22,   422,   304,   305,    40,
      41,    36,    43,   447,   448,   176,   106,   107,   108,   109,
     100,   101,   102,   103,   104,   105,    36,   110,   111,   112,
      36,   280,   115,   116,   386,   387,   176,   392,   393,   200,
      36,    36,   280,    36,    36,    36,   186,    51,    52,    53,
      54,    55,    56,    36,    36,    36,    36,    61,    62,   335,
      36,   337,   335,   209,   210,   211,    36,   213,   273,   298,
     299,   300,   301,   302,   303,   280,   352,    36,    34,   352,
      45,    39,   273,    44,    36,    36,    36,    85,    15,   280,
     251,     3,     4,     5,     6,     7,     8,     9,    37,    25,
      97,    26,    37,   264,    49,    37,    50,    97,    37,    37,
      44,    44,   273,    44,   273,    37,    37,   278,   367,   280,
      44,   280,   423,    37,   264,    44,    37,    37,    37,   367,
      37,    37,   293,   273,    36,    39,    44,    37,   278,    37,
     280,    44,    37,    37,    37,    37,    37,    44,   449,   450,
      37,    37,    42,   176,    72,    51,   186,   112,   270,   269,
     335,   486,   367,   232,   445,   106,   367,   280,   374,   278,
     471,   185,   376,   388,   335,   308,   367,   308,   504,    -1,
     481,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   335,    -1,   498,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   367,    -1,   367,    -1,
      -1,    -1,   352,    -1,    -1,    -1,    -1,   422,    -1,   233,
     234,   235,    -1,    -1,   238,    -1,    -1,   367,   242,   243,
     244,   422,    -1,   247,   248,   249,   250,    -1,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   422,    -1,   422,    -1,    -1,    -1,    -1,    -1,    -1,
     475,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   486,   422,    -1,   475,    -1,   447,   448,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   486,    -1,    -1,    -1,    -1,
      -1,    37,    38,    -1,    -1,    -1,    -1,   447,   448,    -1,
      -1,    -1,    -1,    -1,   475,    -1,   475,   331,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   486,    -1,   486,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   475,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   486,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   369,   370,   371,    -1,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,    -1,    17,   115,
     116,    -1,    -1,    -1,    -1,   399,   400,   401,    -1,    -1,
     404,    -1,    -1,   407,    -1,    -1,    -1,    36,   412,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,
      -1,    60,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    -1,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    -1,   460,    -1,   462,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,    23,    24,   115,   116,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    36,    -1,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    47,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,
      -1,   110,   111,   112,    -1,    -1,   115,   116,    -1,    -1,
      -1,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,    -1,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,    -1,   118,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    -1,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    -1,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    -1,    -1,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,    36,   118,   110,   111,   112,
      -1,    -1,   115,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    -1,    60,
      38,    -1,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    -1,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,    36,    -1,   115,   116,    -1,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    -1,    -1,   115,   116,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    -1,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      -1,    -1,    -1,    -1,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,    36,
      -1,   115,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    -1,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   110,   111,   112
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  MapSetParser::yystos_[] =
  {
         0,   120,   121,     0,    13,   125,   126,   128,   110,   122,
     127,     3,     4,     5,     6,     7,     8,     9,   123,    14,
     129,   115,   116,   250,   106,   107,   108,   109,   288,   297,
     288,   288,   288,   110,   111,   112,   298,   299,   288,    10,
     124,   136,   130,   288,    84,   117,   289,   290,   291,   288,
      18,   111,   288,   298,    33,   219,   131,   220,   133,   110,
      28,    29,    30,    31,    32,    47,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   113,   114,   118,
     221,   222,   225,   240,   241,   243,   244,   245,   248,   250,
     251,   288,   292,   293,   294,   295,   296,   298,   300,    19,
      35,   137,   142,   143,   242,    34,    39,   223,   224,   227,
      36,   226,    20,   138,   139,   140,   141,   298,    86,   144,
     145,   149,    33,   175,    46,   228,   239,   249,   250,   298,
     221,   228,   233,   234,   240,   246,   247,   248,   228,   141,
      22,    87,   146,   152,   176,    27,   166,   171,   173,    48,
     235,   238,   247,    37,   247,    36,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,   150,   151,   209,   250,
     275,   277,   279,   280,   298,    36,   153,   154,   208,   209,
     274,   275,    21,   147,   155,   177,   178,   179,   184,   225,
     132,   250,   232,   237,    57,    58,    60,    88,    89,    90,
      91,    92,    93,    94,   250,   252,   253,   256,   259,   260,
     263,   264,   270,   272,   273,   274,   275,   281,   286,   288,
     292,   296,   298,    36,    36,    36,   118,   276,    36,   118,
     216,   217,    36,    36,    36,   175,   175,    36,    36,    36,
      36,    36,    36,    36,    36,    36,    36,    36,   151,    36,
     118,   210,   252,   154,    22,    25,    26,   148,   161,   164,
     165,    34,   183,    39,   185,   186,    33,   250,    45,   231,
      44,   236,   273,   273,   273,    36,    36,   215,   215,   215,
     215,    36,   215,    85,   134,   135,   255,   258,    51,    52,
      53,    54,    55,    56,    61,    62,   261,   262,   269,   271,
     210,   287,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   250,   252,   252,   252,   252,   252,   252,
      15,   212,    37,    23,    24,   156,   157,   158,   159,   160,
     208,   250,    97,    97,   162,   165,   163,   164,    11,    12,
      40,    41,    43,   180,   182,   187,   188,   191,   195,   198,
     201,   202,   207,   179,   172,   229,   230,   239,   238,   212,
     212,   212,   250,    37,    49,   254,    50,   257,   263,   263,
     263,   263,   263,   263,   216,   216,    57,    58,   265,   268,
     294,   295,    17,    59,   266,    37,    37,    37,   218,    44,
      44,    44,    37,    37,    44,    37,    37,    44,    37,    37,
      37,    37,    44,   252,   157,   274,   192,   196,   189,   199,
     208,    39,   181,   203,   170,   235,    17,   252,   283,   252,
     252,   256,   259,   270,   270,   266,   267,   272,   272,   214,
     252,   252,   252,   252,   252,   252,   211,   193,   197,   190,
     200,   179,   175,    34,    36,   168,    37,    37,   282,    37,
      44,   213,    44,    37,    37,    37,    37,   213,   278,   214,
     249,   249,   175,   175,   206,   169,   214,   252,   252,    37,
      37,   194,   175,    42,   204,    38,   167,   174,   250,   288,
     292,   296,   298,    45,   284,   285,    37,   175,   205,    37,
     174,    72,    37,   175,    51,   297
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  MapSetParser::yytoken_number_[] =
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
     365,   366,   367,   368,   369,   370,   371,   372,   373
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  MapSetParser::yyr1_[] =
  {
         0,   119,   121,   120,   122,   122,   122,   122,   122,   122,
     122,   122,   123,   123,   124,   124,   125,   126,   126,   127,
     127,   128,   130,   131,   129,   132,   132,   133,   133,   134,
     135,   135,   136,   137,   138,   138,   139,   140,   141,   142,
     143,   143,   144,   145,   145,   146,   146,   147,   147,   148,
     148,   149,   150,   150,   151,   151,   151,   151,   152,   153,
     153,   154,   155,   156,   156,   157,   157,   158,   158,   159,
     160,   160,   161,   161,   162,   162,   163,   163,   164,   165,
     166,   132,   132,   167,   167,   169,   168,   170,   170,   172,
     171,   173,   173,   174,   174,   174,   174,   174,   174,   176,
     175,   177,   178,   179,   179,   180,   180,   181,   181,   182,
     183,   183,   184,   185,   186,   186,   187,   187,   187,   187,
     187,   189,   190,   188,   192,   193,   194,   191,   196,   197,
     195,   199,   200,   198,   202,   203,   201,   205,   204,   206,
     206,   207,   208,   208,   208,   209,   210,   211,   210,   212,
     212,   213,   214,   214,   215,   216,   217,   218,   217,   220,
     219,   221,   221,   222,   223,   224,   224,   226,   225,   227,
     225,   228,   229,   230,   230,   231,   232,   232,   233,   234,
     234,   235,   236,   237,   237,   238,   239,   239,   240,   240,
     242,   241,   243,   244,   244,   244,   244,   244,   245,   245,
     246,   246,   247,   247,   248,   248,   249,   249,   250,   250,
     251,   251,   251,   251,   251,   251,   252,   253,   254,   255,
     255,   256,   257,   258,   258,   259,   260,   261,   261,   261,
     261,   261,   261,   261,   261,   262,   262,   263,   264,   265,
     265,   266,   266,   267,   267,   268,   268,   268,   269,   269,
     270,   271,   271,   272,   272,   272,   272,   273,   273,   273,
     273,   273,   273,   273,   273,   274,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   276,   276,   277,   278,
     278,   279,   280,   281,   281,   281,   281,   281,   281,   282,
     281,   283,   283,   284,   285,   285,   286,   287,   287,   288,
     289,   290,   290,   291,   291,   292,   292,   292,   293,   293,
     293,   294,   294,   294,   295,   295,   295,   296,   296,   297,
     297,   297,   297,   298,   298,   299,   299,   300,   300
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  MapSetParser::yyr2_[] =
  {
         0,     2,     0,     4,     0,     5,     3,     3,     3,     3,
       3,     3,     0,     2,     0,     2,     2,     0,     1,     0,
       2,     2,     0,     0,     5,     1,     2,     0,     2,     2,
       0,     1,     6,     2,     1,     1,     1,     2,     1,     3,
       0,     1,     4,     0,     1,     0,     1,     0,     1,     0,
       1,     3,     1,     2,     1,     1,     4,     1,     2,     1,
       2,     1,     3,     1,     2,     1,     1,     1,     1,     2,
       1,     1,     2,     2,     0,     1,     0,     1,     2,     2,
       1,     1,     2,     1,     2,     0,     4,     0,     2,     0,
       6,     0,     1,     1,     1,     1,     1,     1,     1,     0,
       4,     1,     2,     0,     1,     1,     1,     0,     1,     3,
       0,     2,     2,     2,     0,     1,     1,     1,     1,     1,
       1,     0,     0,     4,     0,     0,     0,     6,     0,     0,
       5,     0,     0,     4,     0,     0,     4,     0,     3,     0,
       2,     2,     1,     1,     1,     2,     1,     0,     6,     0,
       1,     2,     0,     2,     4,     1,     1,     0,     5,     0,
       4,     0,     1,     2,     2,     0,     1,     0,     3,     0,
       3,     3,     2,     0,     1,     2,     0,     2,     1,     0,
       1,     2,     2,     0,     2,     1,     1,     1,     1,     1,
       0,     4,     4,     1,     1,     1,     1,     1,     0,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     0,
       2,     2,     2,     0,     2,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     0,     1,     1,     2,     1,
       1,     2,     2,     0,     1,     2,     2,     2,     0,     2,
       2,     0,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     4,     4,     6,     4,
       4,     4,     4,     2,     2,     8,     6,     6,     6,     4,
       4,     4,     4,     1,     1,     1,     3,     1,     7,     0,
       1,     2,     2,     5,     2,     2,     2,     2,     2,     0,
       8,     1,     1,     4,     0,     1,     2,     0,     1,     2,
       2,     1,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const MapSetParser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "IT_REWRITEVAR", "IT_SERVER",
  "IT_USER", "IT_PASSWORD", "IT_DATABASE", "IT_STEMURI", "IT_PRIMARYKEY",
  "IT_LABEL", "IT_GRAPH", "IT_SERVICE", "IT_BASE", "IT_PREFIX",
  "IT_DISTINCT", "IT_REDUCED", "GT_TIMES", "IT_CONSTRUCT", "IT_FROM",
  "IT_NAMED", "IT_ORDER", "IT_BY", "IT_ASC", "IT_DESC", "IT_LIMIT",
  "IT_OFFSET", "IT_BINDINGS", "IT_MEMBERS", "IT_STARTS", "IT_ENDS",
  "IT_ANY", "IT_UNORDERED", "GT_LCURLEY", "GT_RCURLEY", "IT_WHERE",
  "GT_LPAREN", "GT_RPAREN", "IT_UNDEF", "GT_DOT", "IT_OPTIONAL",
  "IT_MINUS", "IT_UNION", "IT_FILTER", "GT_COMMA", "GT_SEMI", "IT_a",
  "GT_LBRACKET", "GT_RBRACKET", "GT_OR", "GT_AND", "GT_EQUAL", "GT_NEQUAL",
  "GT_LT", "GT_GT", "GT_LE", "GT_GE", "GT_PLUS", "GT_MINUS", "GT_DIVIDE",
  "GT_NOT", "IT_IN", "GT_NOT_SPACECHAR_IN", "IT_IRI", "IT_URI", "IT_BNODE",
  "IT_COALESCE", "IT_IF", "IT_STRLANG", "IT_STRDT", "IT_EXISTS",
  "GT_NOT_SPACECHAR_EXISTS", "IT_SEPARATOR", "IT_STR", "IT_LANG",
  "IT_LANGMATCHES", "IT_DATATYPE", "IT_BOUND", "IT_sameTerm", "IT_isIRI",
  "IT_isURI", "IT_isBLANK", "IT_isLITERAL", "IT_REGEX", "GT_DTYPE",
  "IT_AS", "IT_GROUP", "IT_HAVING", "IT_COUNT", "IT_SUM", "IT_MIN",
  "IT_MAX", "IT_AVG", "IT_GROUP_CONCAT", "IT_SAMPLE", "IT_true",
  "IT_false", "INTEGER", "DECIMAL", "DOUBLE", "INTEGER_POSITIVE",
  "DECIMAL_POSITIVE", "DOUBLE_POSITIVE", "INTEGER_NEGATIVE",
  "DECIMAL_NEGATIVE", "DOUBLE_NEGATIVE", "STRING_LITERAL1",
  "STRING_LITERAL_LONG1", "STRING_LITERAL2", "STRING_LITERAL_LONG2",
  "IRI_REF", "PNAME_NS", "PNAME_LN", "BLANK_NODE_LABEL", "ANON", "VAR1",
  "VAR2", "LANGTAG", "NIL", "$accept", "MapSet", "$@1", "AccessParms_Star",
  "Map_Star", "_QLabel_E_Opt", "Prologue", "_QBaseDecl_E_Opt",
  "_QPrefixDecl_E_Star", "BaseDecl", "PrefixDecl", "$@2", "$@3",
  "_QVar_E_Plus", "_QDatasetClause_E_Star", "_O_QIT_AS_E_S_QVar_E_C",
  "_Q_O_QIT_AS_E_S_QVar_E_C_E_Opt", "ConstructQuery", "DatasetClause",
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
  "OffsetClause", "BindingsClause", "_QBindingValue_E_Plus",
  "_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_C", "$@4",
  "_Q_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_C_E_Star",
  "_O_QIT_BINDINGS_E_S_QVar_E_Plus_S_QGT_LCURLEY_E_S_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Star_S_QGT_RCURLEY_E_C",
  "$@5",
  "_Q_O_QIT_BINDINGS_E_S_QVar_E_Plus_S_QGT_LCURLEY_E_S_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Star_S_QGT_RCURLEY_E_C_E_Opt",
  "BindingValue", "GroupGraphPattern", "$@6",
  "_O_QSubSelect_E_Or_QGroupGraphPatternSub_E_C", "GroupGraphPatternSub",
  "_QTriplesBlock_E_Opt", "_O_QGraphPatternNotTriples_E_Or_QFilter_E_C",
  "_QGT_DOT_E_Opt",
  "_O_QGraphPatternNotTriples_E_Or_QFilter_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGraphPatternNotTriples_E_Or_QFilter_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "TriplesBlock", "_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C_E_Opt", "GraphPatternNotTriples",
  "OptionalGraphPattern", "@7", "@8", "GraphGraphPattern", "@9", "@10",
  "@11", "ServiceGraphPattern", "@12", "@13", "MinusGraphPattern", "@14",
  "@15", "GroupOrUnionGraphPattern", "@16", "@17",
  "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@18",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList", "$@19", "_QIT_DISTINCT_E_Opt",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "ExprAggArg",
  "ExpressionList",
  "_O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C",
  "$@20", "ConstructTemplate", "$@21", "_QConstructTriples_E_Opt",
  "ConstructTriples", "_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C_E_Opt", "TriplesSameSubject",
  "$@22", "$@23", "PropertyListNotEmpty", "_O_QVerb_E_S_QObjectList_E_C",
  "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "ObjectList",
  "_O_QGT_COMMA_E_S_QObject_E_C", "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star",
  "Object", "Verb", "TriplesNode", "BlankNodePropertyList", "@24",
  "Generator",
  "_O_QIT_MEMBERS_E_Or_QIT_STARTS_E_Or_QIT_ENDS_E_Or_QIT_ANY_E_Or_QIT_UNORDERED_E_C",
  "_Q_O_QIT_MEMBERS_E_Or_QIT_STARTS_E_Or_QIT_ENDS_E_Or_QIT_ANY_E_Or_QIT_UNORDERED_E_C_E_Opt",
  "_QGraphNode_E_Plus", "GraphNode", "VarOrTerm", "VarOrIRIref", "Var",
  "GraphTerm", "Expression", "ConditionalOrExpression",
  "_O_QGT_OR_E_S_QConditionalAndExpression_E_C",
  "_Q_O_QGT_OR_E_S_QConditionalAndExpression_E_C_E_Star",
  "ConditionalAndExpression", "_O_QGT_AND_E_S_QValueLogical_E_C",
  "_Q_O_QGT_AND_E_S_QValueLogical_E_C_E_Star", "ValueLogical",
  "RelationalExpression",
  "_O_QGT_EQUAL_E_S_QNumericExpression_E_Or_QGT_NEQUAL_E_S_QNumericExpression_E_Or_QGT_LT_E_S_QNumericExpression_E_Or_QGT_GT_E_S_QNumericExpression_E_Or_QGT_LE_E_S_QNumericExpression_E_Or_QGT_GE_E_S_QNumericExpression_E_Or_QIT_IN_E_S_QExpressionList_E_Or_QGT_NOT_SPACECHAR_IN_E_S_QExpressionList_E_C",
  "_Q_O_QGT_EQUAL_E_S_QNumericExpression_E_Or_QGT_NEQUAL_E_S_QNumericExpression_E_Or_QGT_LT_E_S_QNumericExpression_E_Or_QGT_GT_E_S_QNumericExpression_E_Or_QGT_LE_E_S_QNumericExpression_E_Or_QGT_GE_E_S_QNumericExpression_E_Or_QIT_IN_E_S_QExpressionList_E_Or_QGT_NOT_SPACECHAR_IN_E_S_QExpressionList_E_C_E_Opt",
  "NumericExpression", "AdditiveExpression",
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
  "ExistsFunc", "NotExistsFunc", "Aggregate", "$@25",
  "_O_QGT_TIMES_E_Or_QExpression_E_C",
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
  const MapSetParser::rhs_number_type
  MapSetParser::yyrhs_[] =
  {
       120,     0,    -1,    -1,   121,   125,   122,   123,    -1,    -1,
     122,     3,   250,   288,   288,    -1,   122,     4,   288,    -1,
     122,     5,   288,    -1,   122,     6,   288,    -1,   122,     7,
     288,    -1,   122,     8,   298,    -1,   122,     9,   288,    -1,
      -1,   123,   136,    -1,    -1,    10,   288,    -1,   126,   127,
      -1,    -1,   128,    -1,    -1,   127,   129,    -1,    13,   110,
      -1,    -1,    -1,    14,   130,   111,   131,   110,    -1,   250,
      -1,   132,   250,    -1,    -1,   133,   137,    -1,    85,   250,
      -1,    -1,   134,    -1,   124,    18,   219,   133,   142,   144,
      -1,    19,   138,    -1,   139,    -1,   140,    -1,   141,    -1,
      20,   141,    -1,   298,    -1,   143,   175,   166,    -1,    -1,
      35,    -1,   145,   146,   147,   148,    -1,    -1,   149,    -1,
      -1,   152,    -1,    -1,   155,    -1,    -1,   161,    -1,    86,
      22,   150,    -1,   151,    -1,   150,   151,    -1,   275,    -1,
     209,    -1,    36,   252,   135,    37,    -1,   250,    -1,    87,
     153,    -1,   154,    -1,   153,   154,    -1,   208,    -1,    21,
      22,   156,    -1,   157,    -1,   156,   157,    -1,   159,    -1,
     160,    -1,    23,    -1,    24,    -1,   158,   274,    -1,   208,
      -1,   250,    -1,   164,   162,    -1,   165,   163,    -1,    -1,
     165,    -1,    -1,   164,    -1,    25,    97,    -1,    26,    97,
      -1,   173,    -1,   250,    -1,   132,   250,    -1,   174,    -1,
     167,   174,    -1,    -1,    36,   169,   167,    37,    -1,    -1,
     170,   168,    -1,    -1,    27,   132,    33,   172,   170,    34,
      -1,    -1,   171,    -1,   298,    -1,   288,    -1,   292,    -1,
     296,    -1,    38,    -1,   250,    -1,    -1,    33,   176,   177,
      34,    -1,   178,    -1,   179,   183,    -1,    -1,   184,    -1,
     187,    -1,   207,    -1,    -1,    39,    -1,   180,   181,   179,
      -1,    -1,   183,   182,    -1,   225,   186,    -1,    39,   179,
      -1,    -1,   185,    -1,   188,    -1,   198,    -1,   201,    -1,
     191,    -1,   195,    -1,    -1,    -1,    40,   189,   190,   175,
      -1,    -1,    -1,    -1,    11,   192,   193,   249,   194,   175,
      -1,    -1,    -1,    12,   196,   197,   249,   175,    -1,    -1,
      -1,    41,   199,   200,   175,    -1,    -1,    -1,   202,   203,
     175,   206,    -1,    -1,    42,   205,   175,    -1,    -1,   206,
     204,    -1,    43,   208,    -1,   274,    -1,   275,    -1,   209,
      -1,   298,   210,    -1,   118,    -1,    -1,    36,   212,   252,
     211,   214,    37,    -1,    -1,    15,    -1,    44,   252,    -1,
      -1,   214,   213,    -1,    36,   212,   252,    37,    -1,   217,
      -1,   118,    -1,    -1,    36,   252,   218,   214,    37,    -1,
      -1,    33,   220,   221,    34,    -1,    -1,   222,    -1,   225,
     224,    -1,    39,   221,    -1,    -1,   223,    -1,    -1,   248,
     226,   228,    -1,    -1,   240,   227,   233,    -1,   239,   235,
     232,    -1,   239,   235,    -1,    -1,   229,    -1,    45,   230,
      -1,    -1,   232,   231,    -1,   234,    -1,    -1,   228,    -1,
     238,   237,    -1,    44,   238,    -1,    -1,   237,   236,    -1,
     247,    -1,   249,    -1,    46,    -1,   243,    -1,   241,    -1,
      -1,    47,   242,   228,    48,    -1,   245,    36,   246,    37,
      -1,    28,    -1,    29,    -1,    30,    -1,    31,    -1,    32,
      -1,    -1,   244,    -1,   247,    -1,   246,   247,    -1,   248,
      -1,   240,    -1,   250,    -1,   251,    -1,   250,    -1,   298,
      -1,   115,    -1,   116,    -1,   298,    -1,   288,    -1,   292,
      -1,   296,    -1,   300,    -1,   118,    -1,   253,    -1,   256,
     255,    -1,    49,   256,    -1,    -1,   255,   254,    -1,   259,
     258,    -1,    50,   259,    -1,    -1,   258,   257,    -1,   260,
      -1,   263,   262,    -1,    51,   263,    -1,    52,   263,    -1,
      53,   263,    -1,    54,   263,    -1,    55,   263,    -1,    56,
     263,    -1,    61,   216,    -1,    62,   216,    -1,    -1,   261,
      -1,   264,    -1,   270,   269,    -1,   294,    -1,   295,    -1,
      17,   272,    -1,    59,   272,    -1,    -1,   266,    -1,    57,
     270,    -1,    58,   270,    -1,   265,   267,    -1,    -1,   269,
     268,    -1,   272,   271,    -1,    -1,   271,   266,    -1,    60,
     273,    -1,    57,   273,    -1,    58,   273,    -1,   273,    -1,
     274,    -1,   275,    -1,   286,    -1,   288,    -1,   292,    -1,
     296,    -1,   250,    -1,   281,    -1,    36,   252,    37,    -1,
      73,    36,   252,    37,    -1,    74,    36,   252,    37,    -1,
      75,    36,   252,    44,   252,    37,    -1,    76,    36,   252,
      37,    -1,    77,    36,   250,    37,    -1,    63,    36,   252,
      37,    -1,    64,    36,   252,    37,    -1,    65,   276,    -1,
      66,   216,    -1,    67,    36,   252,    44,   252,    44,   252,
      37,    -1,    68,    36,   252,    44,   252,    37,    -1,    69,
      36,   252,    44,   252,    37,    -1,    78,    36,   252,    44,
     252,    37,    -1,    79,    36,   252,    37,    -1,    80,    36,
     252,    37,    -1,    81,    36,   252,    37,    -1,    82,    36,
     252,    37,    -1,   277,    -1,   279,    -1,   280,    -1,    36,
     252,    37,    -1,   118,    -1,    83,    36,   252,    44,   252,
     278,    37,    -1,    -1,   213,    -1,    70,   175,    -1,    71,
     175,    -1,    88,    36,   212,   283,    37,    -1,    89,   215,
      -1,    90,   215,    -1,    91,   215,    -1,    92,   215,    -1,
      94,   215,    -1,    -1,    93,    36,   212,   252,   282,   214,
     285,    37,    -1,    17,    -1,   252,    -1,    45,    72,    51,
     297,    -1,    -1,   284,    -1,   298,   287,    -1,    -1,   210,
      -1,   297,   291,    -1,    84,   298,    -1,   117,    -1,   289,
      -1,    -1,   290,    -1,   293,    -1,   294,    -1,   295,    -1,
      97,    -1,    98,    -1,    99,    -1,   100,    -1,   101,    -1,
     102,    -1,   103,    -1,   104,    -1,   105,    -1,    95,    -1,
      96,    -1,   106,    -1,   108,    -1,   107,    -1,   109,    -1,
     110,    -1,   299,    -1,   112,    -1,   111,    -1,   113,    -1,
     114,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  MapSetParser::yyprhs_[] =
  {
         0,     0,     3,     4,     9,    10,    16,    20,    24,    28,
      32,    36,    40,    41,    44,    45,    48,    51,    52,    54,
      55,    58,    61,    62,    63,    69,    71,    74,    75,    78,
      81,    82,    84,    91,    94,    96,    98,   100,   103,   105,
     109,   110,   112,   117,   118,   120,   121,   123,   124,   126,
     127,   129,   133,   135,   138,   140,   142,   147,   149,   152,
     154,   157,   159,   163,   165,   168,   170,   172,   174,   176,
     179,   181,   183,   186,   189,   190,   192,   193,   195,   198,
     201,   203,   205,   208,   210,   213,   214,   219,   220,   223,
     224,   231,   232,   234,   236,   238,   240,   242,   244,   246,
     247,   252,   254,   257,   258,   260,   262,   264,   265,   267,
     271,   272,   275,   278,   281,   282,   284,   286,   288,   290,
     292,   294,   295,   296,   301,   302,   303,   304,   311,   312,
     313,   319,   320,   321,   326,   327,   328,   333,   334,   338,
     339,   342,   345,   347,   349,   351,   354,   356,   357,   364,
     365,   367,   370,   371,   374,   379,   381,   383,   384,   390,
     391,   396,   397,   399,   402,   405,   406,   408,   409,   413,
     414,   418,   422,   425,   426,   428,   431,   432,   435,   437,
     438,   440,   443,   446,   447,   450,   452,   454,   456,   458,
     460,   461,   466,   471,   473,   475,   477,   479,   481,   482,
     484,   486,   489,   491,   493,   495,   497,   499,   501,   503,
     505,   507,   509,   511,   513,   515,   517,   519,   522,   525,
     526,   529,   532,   535,   536,   539,   541,   544,   547,   550,
     553,   556,   559,   562,   565,   568,   569,   571,   573,   576,
     578,   580,   583,   586,   587,   589,   592,   595,   598,   599,
     602,   605,   606,   609,   612,   615,   618,   620,   622,   624,
     626,   628,   630,   632,   634,   636,   640,   645,   650,   657,
     662,   667,   672,   677,   680,   683,   692,   699,   706,   713,
     718,   723,   728,   733,   735,   737,   739,   743,   745,   753,
     754,   756,   759,   762,   768,   771,   774,   777,   780,   783,
     784,   793,   795,   797,   802,   803,   805,   808,   809,   811,
     814,   817,   819,   821,   822,   824,   826,   828,   830,   832,
     834,   836,   838,   840,   842,   844,   846,   848,   850,   852,
     854,   856,   858,   860,   862,   864,   866,   868,   870
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  MapSetParser::yyrline_[] =
  {
         0,   363,   363,   363,   368,   370,   379,   382,   385,   388,
     391,   394,   400,   402,   407,   410,   417,   421,   423,   427,
     429,   433,   439,   441,   439,   451,   455,   463,   466,   474,
     481,   484,   489,   498,   505,   506,   510,   516,   522,   529,
     536,   538,   542,   549,   552,   557,   560,   565,   568,   573,
     577,   581,   588,   591,   598,   601,   604,   607,   613,   619,
     622,   629,   634,   641,   645,   653,   655,   663,   666,   674,
     682,   683,   690,   694,   702,   705,   710,   713,   717,   723,
     731,   736,   740,   747,   750,   756,   756,   765,   768,   775,
     775,   784,   787,   790,   793,   796,   799,   802,   805,   812,
     812,   824,   829,   833,   835,   840,   841,   845,   847,   852,
     856,   859,   864,   869,   873,   876,   880,   881,   882,   883,
     884,   888,   890,   888,   904,   906,   908,   904,   919,   921,
     919,   930,   932,   930,   942,   945,   942,   955,   955,   969,
     971,   975,   986,   987,   988,   992,  1000,  1004,  1004,  1013,
    1016,  1023,  1029,  1031,  1038,  1045,  1049,  1052,  1052,  1062,
    1062,  1070,  1072,  1077,  1082,  1086,  1088,  1092,  1092,  1095,
    1095,  1102,  1107,  1111,  1113,  1118,  1122,  1124,  1129,  1133,
    1135,  1140,  1145,  1149,  1151,  1155,  1162,  1166,  1173,  1174,
    1178,  1178,  1191,  1216,  1219,  1222,  1225,  1228,  1235,  1238,
    1243,  1247,  1254,  1255,  1259,  1262,  1266,  1269,  1275,  1276,
    1280,  1283,  1286,  1289,  1292,  1293,  1299,  1304,  1313,  1320,
    1323,  1331,  1340,  1347,  1350,  1357,  1362,  1373,  1376,  1379,
    1382,  1385,  1388,  1391,  1394,  1401,  1404,  1408,  1413,  1422,
    1425,  1432,  1435,  1442,  1445,  1450,  1453,  1457,  1471,  1474,
    1482,  1491,  1494,  1501,  1504,  1507,  1510,  1514,  1515,  1516,
    1517,  1520,  1523,  1526,  1529,  1533,  1539,  1542,  1545,  1548,
    1551,  1554,  1557,  1561,  1564,  1568,  1571,  1574,  1577,  1580,
    1583,  1586,  1589,  1592,  1593,  1594,  1600,  1603,  1610,  1617,
    1620,  1624,  1631,  1638,  1641,  1644,  1647,  1650,  1653,  1657,
    1657,  1669,  1672,  1676,  1682,  1685,  1689,  1699,  1702,  1707,
    1715,  1722,  1726,  1734,  1738,  1742,  1743,  1744,  1748,  1749,
    1750,  1754,  1755,  1756,  1760,  1761,  1762,  1766,  1767,  1771,
    1772,  1773,  1774,  1778,  1779,  1783,  1784,  1788,  1789
  };

  // Print the state stack on the debug stream.
  void
  MapSetParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  MapSetParser::yy_reduce_print_ (int yyrule)
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
  MapSetParser::token_number_type
  MapSetParser::yytranslate_ (int t)
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
     115,   116,   117,   118
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int MapSetParser::yyeof_ = 0;
  const int MapSetParser::yylast_ = 1095;
  const int MapSetParser::yynnts_ = 182;
  const int MapSetParser::yyempty_ = -2;
  const int MapSetParser::yyfinal_ = 3;
  const int MapSetParser::yyterror_ = 1;
  const int MapSetParser::yyerrcode_ = 256;
  const int MapSetParser::yyntokens_ = 119;

  const unsigned int MapSetParser::yyuser_token_number_max_ = 373;
  const MapSetParser::token_number_type MapSetParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 3629 "lib/MapSetParser/MapSetParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 1795 "lib/MapSetParser/MapSetParser.ypp"
 /*** Additional Code ***/

void w3c_sw::MapSetParser::error(const MapSetParser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}

/* START Driver (@@ stand-alone would allow it to be shared with other parsers */

namespace w3c_sw {

    MapSetDriver::MapSetDriver (std::string baseURI, POSFactory* posFactory) : 
	YaccDriver(baseURI, posFactory), curSubject(NULL), curPredicate(NULL), 
	curBGP(NULL), curFilter(NULL), 
	curBindingsClause(NULL), curBinding(NULL), curExprList(NULL), 
	root(NULL)
{
}

    MapSetDriver::~MapSetDriver ()
{
}

bool MapSetDriver::parse(IStreamContext& in)
{
    streamname = in.nameStr;

    MapSetScanner scanner(this, in.p);
    scanner.set_debug(trace_scanning);
    lexer = &scanner;

    MapSetParser parser(*this);
    parser.set_debug_level(trace_parsing);
    // !!! Clear out namespaces!
    ignorePrefixFlag = false;
    return (parser.parse());
}

} // namespace w3c_sw

/* END Driver */


