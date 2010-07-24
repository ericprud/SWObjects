
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
#line 223 "lib/MapSetParser/MapSetParser.ypp"

#include "../MapSetScanner.hpp"

/* Line 317 of lalr1.cc  */
#line 347 "lib/MapSetParser/MapSetParser.ypp"

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
#line 362 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root = new MapSet();
      }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 369 "lib/MapSetParser/MapSetParser.ypp"
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
#line 378 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->server = (yysemantic_stack_[(3) - (3)].p_RDFLiteral);
    }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 381 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->user = (yysemantic_stack_[(3) - (3)].p_RDFLiteral);
    }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 384 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->password = (yysemantic_stack_[(3) - (3)].p_RDFLiteral);
    }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 387 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->database = (yysemantic_stack_[(3) - (3)].p_RDFLiteral);
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 390 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->stemURI = (yysemantic_stack_[(3) - (3)].p_URI);
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 393 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->primaryKey = (yysemantic_stack_[(3) - (3)].p_RDFLiteral);
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 396 "lib/MapSetParser/MapSetParser.ypp"
    {
      static_cast<MapSet*>(driver.root)->sharedVars = (yysemantic_stack_[(3) - (3)].p_BooleanRDFLiteral)->getValue();
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 409 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = NULL;
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 412 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(2) - (2)].p_POS);
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 435 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 441 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 443 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 445 "lib/MapSetParser/MapSetParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 453 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 456 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 464 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 471 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 479 "lib/MapSetParser/MapSetParser.ypp"
    {
	/* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	Construct* constr = new Construct((DefaultGraphPattern*)(yysemantic_stack_[(6) - (3)].p_BasicGraphPattern), (yysemantic_stack_[(6) - (4)].p_DatasetClauses), (yysemantic_stack_[(6) - (5)].p_WhereClause), (yysemantic_stack_[(6) - (6)].p_SolutionModifier));
	driver.root->maps.push_back(LabeledConstruct((yysemantic_stack_[(6) - (1)].p_POS), constr));
    }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 488 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 500 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_POS), driver.posFactory);
    }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 506 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_POS), driver.posFactory);
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 512 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 519 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.curOp ? driver.curOp : new DefaultGraphPattern(), (yysemantic_stack_[(3) - (3)].p_BindingsClause));
	driver.curOp = NULL;
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 532 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 539 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = NULL;
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 547 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 555 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 563 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 571 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 578 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 581 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 588 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 591 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 594 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 597 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new POSExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 603 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 609 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 612 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 624 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 631 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 635 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 645 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 653 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 656 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 664 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 673 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 680 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 684 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 692 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 700 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 707 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 713 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 726 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POSList) = new POSList;
	(yyval.p_POSList)->push_back((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 730 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSList)->push_back((yysemantic_stack_[(2) - (2)].p_Variable));
	(yyval.p_POSList) = (yysemantic_stack_[(2) - (1)].p_POSList);
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 737 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(1) - (1)].p_POS));
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 740 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(2) - (2)].p_POS));
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 746 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding = new Binding();
      }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 748 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BindingValue) = driver.curBinding;
	  driver.curBinding = NULL;
      }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 755 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BindingValues) = NULL;
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 758 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBindingsClause->push_back((yysemantic_stack_[(2) - (2)].p_BindingValue));
	(yyval.p_BindingValues) = NULL;
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 765 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBindingsClause = new BindingClause((yysemantic_stack_[(3) - (2)].p_POSList));
      }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 767 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BindingsClause) = driver.curBindingsClause;
	  driver.curBindingsClause = NULL;
      }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 774 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BindingsClause) = NULL;
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 780 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 783 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 786 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 789 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 792 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = driver.getNULL();
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 795 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 802 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = NULL;
	driver.curBGP = NULL;
      }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 805 "lib/MapSetParser/MapSetParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 878 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 880 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.curFilter;
      }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 882 "lib/MapSetParser/MapSetParser.ypp"
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

  case 123:

/* Line 678 of lalr1.cc  */
#line 894 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 896 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 898 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_POS) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_POS);
      }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 901 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_POS), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_POS);
      }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 909 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 911 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 913 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(5) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(5) - (4)].p_POS), driver.curOp, driver.posFactory, false));
      }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 920 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 922 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 924 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.curOp));
      }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 932 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 935 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 937 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 945 "lib/MapSetParser/MapSetParser.ypp"
    {
	if (driver.curOp == NULL)
	    driver.ensureBasicGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 950 "lib/MapSetParser/MapSetParser.ypp"
    {
	  if (driver.curOp == NULL)
	      driver.ensureBasicGraphPattern();
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.curOp);
      }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 965 "lib/MapSetParser/MapSetParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    if (driver.curOp == NULL)
		driver.ensureBasicGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 982 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 990 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 994 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 996 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = NULL;
      }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1003 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1006 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1013 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1021 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1028 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_DistExprPair).distinctness = (yysemantic_stack_[(4) - (2)].p_distinctness);
	  (yyval.p_DistExprPair).p_Expression = (yysemantic_stack_[(4) - (3)].p_Expression);
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1039 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1042 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1044 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = NULL;
      }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 1052 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 1054 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1082 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_POS);
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 1085 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_POS);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 1145 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.posFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_POS)));
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 1152 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_POS);
	driver.curPredicate = (yyval.p_POS);
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 1156 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_POS);
    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 1168 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 1172 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_POS) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 1181 "lib/MapSetParser/MapSetParser.ypp"
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

  case 192:

/* Line 678 of lalr1.cc  */
#line 1206 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 1209 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 1212 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 1215 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 1218 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1225 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 1233 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POSs) = new ProductionVector<const POS*>();
	(yyval.p_POSs)->push_back((yysemantic_stack_[(1) - (1)].p_POS));
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 1237 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSs)->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSs) = (yysemantic_stack_[(2) - (1)].p_POSs);
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 1249 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 1256 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 1259 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 1270 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 1273 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 1276 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 1279 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 1283 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 1294 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 1303 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 1310 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 1313 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 1321 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 1330 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 1337 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 1340 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 1352 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_GeneralComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_GeneralComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_GeneralComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 1363 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 1366 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 1369 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 1372 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 1375 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 1378 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 1381 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 1384 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryNotIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 1391 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = NULL;
    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 1403 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 1412 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 1415 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 1422 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 1425 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 1432 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 1440 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 1443 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 1447 "lib/MapSetParser/MapSetParser.ypp"
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

  case 247:

/* Line 678 of lalr1.cc  */
#line 1461 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 1464 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 1472 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 1481 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 1484 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 1491 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 1494 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 1497 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 1507 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 1510 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 1513 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 1516 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 1523 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 1529 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-str"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 1532 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-lang"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 1535 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-langMatches"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 1538 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-datatype"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 1541 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-bound"), new POSExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 1544 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-iri"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 1547 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-iri"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 1551 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-bnode"), (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 1554 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-coalesce"), $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 1558 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-if"), (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 1561 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-strlang"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 1564 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-strdt"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 1567 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-sameTerm"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 1570 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 1573 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 1576 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isBlank"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 1579 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isLiteral"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 1590 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 1593 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 1600 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-regex"), (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 1607 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 1614 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-exists"), driver.curOp, NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 1621 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new BooleanNegation(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-exists"), driver.curOp, NULL, NULL)));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 1628 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-count"), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 1631 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-sum"), (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 1634 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-min"), (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 1637 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-max"), (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 1640 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-avg"), (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 1643 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-sample"), (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 1647 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(4) - (4)].p_Expression));
      }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 1649 "lib/MapSetParser/MapSetParser.ypp"
    {
	  // x = new ArgList($2, driver.curExprList);
	  delete driver.curExprList;
	  driver.curExprList = NULL;
	  w3c_sw_NEED_IMPL("GROUP_CONCAT"); // !!!
	  // $$ = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-group-concat"), $3, $4.p_Expression, $4.separator));
    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 1659 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 1666 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 1672 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 1679 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new POSExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 1689 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 1697 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 1705 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 1712 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 1716 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 1724 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 2459 "lib/MapSetParser/MapSetParser.cpp"
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
  const short int MapSetParser::yypact_ninf_ = -420;
  const short int
  MapSetParser::yypact_[] =
  {
      -420,    73,   100,  -420,     9,  -420,  -420,  -420,  -420,   253,
     110,   -84,    87,    87,    87,    87,    29,    87,   -54,    35,
    -420,  -420,  -420,  -420,    87,  -420,  -420,  -420,  -420,  -420,
     -71,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,
    -420,  -420,  -420,   636,   108,  -420,    39,    87,    29,  -420,
    -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,
    -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,
    -420,  -420,  -420,  -420,    98,  -420,  -420,  -420,  -420,  -420,
      46,   561,     8,  -420,  -420,  -420,  -420,  -420,  -420,  -420,
     129,  -420,   126,  -420,  -420,  -420,  -420,   138,  -420,  -420,
    -420,    -5,  -420,  -420,    89,   144,   -34,  -420,   561,  -420,
    -420,   -34,   683,   -34,    29,  -420,  -420,  -420,  -420,  -420,
     166,  -420,   102,  -420,  -420,   164,  -420,   159,   683,  -420,
    -420,  -420,  -420,  -420,  -420,  -420,  -420,   592,  -420,  -420,
    -420,  -420,   692,   918,   187,  -420,   561,   -84,  -420,  -420,
    -420,  -420,  -420,  -420,  -420,  -420,  -420,   764,   173,   177,
     -25,   -15,   183,   190,   191,   144,   144,   193,   196,   198,
     199,   200,   201,   202,   203,   206,   207,   208,   692,  -420,
    -420,  -420,  -420,  -420,  -420,  -420,    -6,   764,   918,  -420,
    -420,  -420,  -420,  -420,   224,    49,  -420,   219,  -420,  -420,
    -420,   225,   -27,  -420,   221,   227,   841,   841,   841,   233,
     237,   237,   237,   237,   238,   237,  -420,   192,  -420,  -420,
    -420,  -420,   117,  -420,  -420,  -420,  -420,  -420,  -420,  -420,
    -420,  -420,  -420,  -420,    -6,   764,   764,   764,  -420,  -420,
     764,  -420,  -420,  -420,   764,   764,   764,  -420,  -420,   764,
     764,   764,   764,   -84,   764,   764,   764,   764,   764,   764,
    -420,   263,  -420,  -420,   243,  -420,   536,   184,   185,  -420,
    -420,   259,   261,  -420,   121,   561,  -420,  -420,  -420,  -420,
     -34,  -420,   683,  -420,  -420,  -420,  -420,   263,   263,  -420,
    -420,  -420,  -420,   263,  -420,   -84,  -420,   250,   239,   240,
     764,   764,   764,   764,   764,   764,   -15,   -15,  -420,  -420,
     147,     1,  -420,  -420,   255,   256,   257,  -420,   251,   252,
     254,   260,   264,   262,   267,   270,   265,   271,   273,   274,
     276,   272,  -420,   764,  -420,  -420,  -420,   536,  -420,   278,
    -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,
    -420,  -420,  -420,  -420,   918,   279,  -420,  -420,  -420,  -420,
    -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,   683,
    -420,   446,   764,   764,  -420,  -420,   764,  -420,   764,  -420,
    -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,   764,   764,
       1,  -420,  -420,  -420,   764,   764,  -420,  -420,  -420,  -420,
    -420,   764,   764,   764,  -420,  -420,   764,  -420,  -420,   764,
    -420,  -420,  -420,  -420,   764,  -420,  -420,  -420,  -420,  -420,
    -420,  -420,  -420,  -420,   561,   144,    20,  -420,  -420,  -420,
     280,   282,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,
    -420,    -8,   277,   283,   285,   286,   289,   284,  -420,   -48,
     -48,   144,   144,  -420,  -420,  -420,  -420,  -420,  -420,  -420,
    -420,  -420,   764,  -420,   764,  -420,  -420,  -420,  -420,  -420,
     292,    14,  -420,   144,  -420,  -420,   258,   787,    47,  -420,
     293,  -420,  -420,   144,  -420,  -420,  -420,  -420,   863,  -420,
    -420,  -420,  -420,  -420,  -420,   268,  -420,   294,  -420,  -420,
     144,  -420,  -420,   281,  -420,  -420,    87,  -420
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  MapSetParser::yydefact_[] =
  {
         2,     0,    18,     1,     0,     4,    20,    19,    22,    13,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     3,
      23,    21,   207,   208,     0,   328,   330,   329,   331,     6,
     312,     7,     8,     9,   332,   335,   334,    10,   333,    11,
     326,   327,    12,     0,     0,    14,     0,     0,     0,   310,
     311,   313,   308,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   336,   337,   214,    16,   210,   211,   314,   315,
     316,   212,   209,   213,     0,    24,     5,   309,   158,    26,
       0,   160,    39,    25,   192,   193,   194,   195,   196,   189,
       0,   161,   164,   168,   188,   187,   198,     0,   166,   203,
     204,     0,    40,    27,    42,     0,     0,   159,   160,   165,
     162,   178,   197,     0,     0,    32,    33,    34,    35,    37,
       0,    31,    44,    43,    98,    90,   186,     0,   197,   185,
     205,   206,   163,   179,   169,   177,   202,   197,   199,   201,
     167,    36,     0,     0,    46,    45,   102,     0,    38,    91,
      79,   190,   175,   182,   184,   191,   200,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,    51,
      54,    56,    53,   282,   283,   284,     0,     0,    57,    58,
      60,   143,   141,   142,     0,    48,    47,     0,   100,   109,
     103,   113,     0,    80,   170,   180,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   262,    29,   215,   218,
     222,   224,   234,   236,   247,   250,   255,   256,   257,   263,
     258,   259,   260,   261,   306,     0,     0,     0,   286,   272,
       0,   155,   273,   154,     0,     0,     0,   290,   291,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,   148,   145,   144,     0,    59,     0,     0,     0,    41,
      49,    73,    75,    99,   101,   102,   114,   111,    88,    81,
     172,   176,   197,   183,   253,   254,   252,   148,   148,   293,
     294,   295,   296,   148,   297,     0,    30,     0,   216,   220,
       0,     0,     0,     0,     0,     0,     0,     0,   235,   225,
     237,   249,   307,   305,     0,     0,     0,   156,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   149,     0,   264,    66,    67,    61,    62,     0,
      64,    65,    69,    70,    77,    78,    71,    74,    72,    76,
     123,   127,   120,   130,     0,   106,   110,   104,   115,   118,
     119,   116,   117,   134,   105,   112,    86,   173,   174,   197,
     181,     0,     0,     0,    28,    55,     0,   219,     0,   223,
     226,   227,   228,   229,   230,   231,   232,   233,     0,     0,
     242,   248,   238,   239,     0,     0,   251,   270,   271,   285,
     151,     0,     0,     0,   265,   266,     0,   268,   269,     0,
     278,   279,   280,   281,     0,   146,    63,    68,   124,   128,
     121,   131,   140,   107,   102,     0,     0,   171,   300,   301,
       0,     0,   298,   217,   221,   244,   245,   243,   246,   240,
     241,     0,     0,     0,     0,     0,     0,   288,   151,     0,
       0,     0,     0,   108,   138,    89,    84,    87,   292,   153,
     151,   157,     0,   152,     0,   275,   276,   267,   277,   289,
       0,     0,   125,     0,   122,   132,   135,     0,   303,   150,
       0,   287,   147,     0,   129,   136,   139,    96,     0,    82,
      97,    93,    94,    95,    92,     0,   304,     0,   274,   126,
       0,    85,    83,     0,   299,   137,     0,   302
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yypgoto_[] =
  {
      -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,
    -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,
    -420,   220,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,
    -420,   158,  -420,  -420,   128,  -420,  -420,     0,  -420,  -420,
    -420,  -420,  -420,  -420,    70,    72,  -420,  -420,  -420,  -420,
    -420,  -420,  -420,  -420,  -420,  -144,  -148,  -420,  -420,  -420,
    -274,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,
    -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,
    -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -256,
    -133,   111,  -420,  -178,   -99,  -419,  -127,  -177,  -420,  -420,
    -420,  -420,   241,  -420,  -420,  -420,   -57,  -420,  -420,   -51,
    -420,  -420,  -420,  -420,  -420,  -420,   -23,  -420,  -420,    68,
      71,  -101,  -420,  -420,  -420,  -420,  -420,  -420,   -87,   -89,
    -304,   -11,   310,   -33,  -420,  -420,  -420,   -22,  -420,  -420,
     -21,  -420,  -420,  -420,  -118,  -420,  -420,   -35,  -420,  -420,
    -420,  -240,  -420,  -234,    -7,  -108,  -122,  -420,  -420,  -420,
    -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,    -9,
    -420,  -420,  -420,   -41,  -420,    51,    52,    31,  -150,    10,
    -420,  -420
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yydefgoto_[] =
  {
        -1,     1,     2,     9,    19,    44,     5,     6,    10,     7,
      21,    46,    80,    82,   296,   297,    45,   103,   115,   116,
     117,   118,   104,   105,   121,   122,   144,   195,   269,   123,
     178,   179,   145,   188,   189,   196,   337,   338,   339,   340,
     341,   270,   346,   348,   271,   272,   148,   202,   488,   457,
     477,   426,   149,   366,   150,   489,   125,   146,   197,   198,
     199,   355,   424,   356,   274,   200,   276,   277,   357,   358,
     420,   451,   359,   418,   449,   483,   360,   419,   450,   361,
     421,   452,   362,   363,   425,   486,   500,   476,   364,   190,
     191,   263,   448,   333,   463,   441,   289,   242,   243,   400,
      79,    81,    90,    91,   109,   110,   201,   113,   111,   127,
     367,   368,   281,   204,   134,   135,   152,   283,   205,   153,
     128,    93,    94,   106,    95,    96,    97,   137,   154,    98,
     129,   216,   100,   217,   218,   377,   298,   219,   379,   299,
     220,   221,   308,   309,   222,   223,   390,   396,   438,   391,
     310,   224,   311,   225,   226,   227,   228,   239,   183,   470,
     184,   185,   229,   460,   430,   496,   497,   230,   313,   231,
      50,    51,    52,   232,    68,    69,    70,   233,    30,   234,
      38,    73
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int MapSetParser::yytable_ninf_ = -198;
  const short int
  MapSetParser::yytable_[] =
  {
        24,   365,    67,    29,    31,    32,    33,   278,    39,   180,
     342,   136,   237,   126,    48,    47,   114,   247,   248,   394,
     182,   193,   240,   139,    92,   138,    37,   136,   101,   471,
     461,   261,    22,    23,    66,   192,   136,   462,    76,   139,
      67,   478,    40,    41,   102,   180,    43,    49,   139,    42,
     156,    92,   482,    72,   -15,   455,   182,   456,    77,   462,
     133,   395,   140,    34,    35,    36,   193,    67,    22,    23,
      99,    67,    66,     3,    71,   267,   268,    34,    35,    36,
     192,   342,    22,    23,   290,   291,   292,    67,   294,    22,
      23,    72,   462,   495,   238,   130,    67,    99,   422,    66,
     130,    99,   130,    66,   241,    67,    34,    35,    36,   371,
     372,   119,    71,   262,     4,   373,   131,    99,    72,    66,
       8,   131,    72,   131,   119,    20,    99,    74,    66,   386,
     387,   181,    78,   350,   351,    99,   203,    66,    72,    71,
      34,    35,    36,    71,   193,   472,   473,    72,   435,   436,
     453,    75,   186,   186,   264,  -133,    72,    83,   192,    71,
     439,   440,   352,   353,   107,   354,   108,   181,    71,   300,
     301,   302,   303,   304,   305,   112,   120,    71,   124,   306,
     307,   136,   380,   381,   382,   383,   384,   385,   186,   142,
     143,   279,   147,   139,    25,    26,    27,    28,   186,   284,
     285,   286,   314,   315,   316,   388,   389,   317,   151,   194,
     235,   318,   319,   320,   236,   193,   321,   322,   323,   324,
     244,   326,   327,   328,   329,   330,   331,   245,   246,   192,
     249,   417,   193,   250,    67,   251,   252,   253,   254,   255,
     256,    67,   325,   257,   258,   259,   192,   266,    56,    57,
      58,    59,    60,    61,   273,   343,    11,    12,    13,    14,
      15,    16,    17,    18,    99,   275,    66,   280,   136,   130,
     287,    99,   282,    66,   288,   293,   186,   454,   295,   332,
     139,   334,   344,   345,   374,    72,   268,   267,   375,   376,
     131,   378,    72,   397,   398,   399,   401,   402,   404,   403,
     415,   485,   405,   474,   475,   407,    71,   406,   408,   410,
     409,   411,   412,    71,   413,   187,   265,   414,   458,   423,
     459,   465,   464,   466,   467,   484,   343,   468,    67,   462,
     481,   498,   504,   506,   141,   499,   260,   416,   429,   431,
     432,   503,   349,   347,   502,   312,   427,   186,   469,   132,
     370,   369,   505,    65,   433,   437,   507,   434,    99,     0,
      66,   392,   393,     0,   186,     0,     0,     0,   442,   443,
     444,     0,     0,   445,     0,     0,   446,     0,     0,    72,
       0,   447,     0,    67,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    99,     0,    66,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   479,
       0,   480,     0,     0,    72,     0,   492,     0,   130,   130,
       0,     0,     0,     0,     0,     0,     0,   492,     0,     0,
       0,     0,     0,     0,     0,    71,     0,     0,     0,   131,
     131,     0,     0,     0,   428,     0,   490,     0,   491,     0,
       0,     0,     0,     0,     0,     0,     0,   490,     0,   491,
       0,     0,     0,   187,     0,     0,     0,   494,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   494,     0,
       0,     0,     0,     0,   206,   207,     0,   208,   493,     0,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   493,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,     0,     0,     0,     0,   209,   210,   211,   212,   213,
     214,   215,    40,    41,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    25,    26,    27,    28,    34,    35,    36,
     335,   336,    22,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   187,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,    85,    86,    87,    88,     0,     0,     0,  -197,     0,
     158,   159,   160,   161,   162,   163,   164,   165,   166,    89,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,    84,    85,    86,    87,    88,     0,     0,     0,     0,
     155,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,    34,    35,    36,
       0,     0,    22,    23,     0,     0,     0,    40,    41,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    25,    26,
      27,    28,    34,    35,    36,    62,    63,    22,    23,     0,
      64,     0,     0,     0,     0,     0,     0,     0,    40,    41,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    25,
      26,    27,    28,    34,    35,    36,    62,    63,    22,    23,
       0,    64,    84,    85,    86,    87,    88,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   157,
       0,    89,    40,    41,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    25,    26,    27,    28,    34,    35,    36,
      62,    63,     0,     0,     0,    64,   158,   159,   160,   161,
     162,   163,   164,   165,   166,     0,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,     0,     0,    40,
      41,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      25,    26,    27,    28,    34,    35,    36,    62,    63,    22,
      23,   187,    64,    34,    35,    36,     0,     0,    22,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   206,   207,     0,   208,   487,     0,   158,   159,
     160,   161,   162,   163,   164,   165,   166,     0,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,     0,
       0,     0,     0,   209,   210,   211,   212,   213,   214,   215,
      40,    41,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    25,    26,    27,    28,    34,    35,    36,   187,     0,
      22,    23,     0,    40,    41,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    25,    26,    27,    28,    34,    35,
      36,   501,   487,    22,    23,   158,   159,   160,   161,   162,
     163,   164,   165,   166,     0,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,     0,     0,     0,     0,
     209,   210,   211,   212,   213,   214,   215,    40,    41,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    25,    26,
      27,    28,    34,    35,    36,   187,     0,    22,    23,    40,
      41,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      25,    26,    27,    28,    34,    35,    36,     0,     0,    22,
      23,     0,   158,   159,   160,   161,   162,   163,   164,   165,
     166,     0,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
      35,    36
  };

  /* YYCHECK.  */
  const short int
  MapSetParser::yycheck_[] =
  {
        11,   275,    43,    12,    13,    14,    15,    34,    17,   142,
     266,   112,    37,    47,    85,    24,    21,   165,   166,    18,
     142,   143,    37,   112,    81,   112,    16,   128,    20,   448,
      38,    37,   116,   117,    43,   143,   137,    45,    47,   128,
      81,   460,    96,    97,    36,   178,    11,   118,   137,    18,
     137,   108,    38,    43,    19,    35,   178,    37,    48,    45,
     111,    60,   113,   111,   112,   113,   188,   108,   116,   117,
      81,   112,    81,     0,    43,    26,    27,   111,   112,   113,
     188,   337,   116,   117,   211,   212,   213,   128,   215,   116,
     117,    81,    45,    46,   119,   106,   137,   108,   354,   108,
     111,   112,   113,   112,   119,   146,   111,   112,   113,   287,
     288,   101,    81,   119,    14,   293,   106,   128,   108,   128,
     111,   111,   112,   113,   114,    15,   137,    19,   137,   306,
     307,   142,    34,    12,    13,   146,   147,   146,   128,   108,
     111,   112,   113,   112,   266,   449,   450,   137,   388,   389,
     424,   112,   142,   143,   187,    34,   146,   111,   266,   128,
     394,   395,    41,    42,    35,    44,    40,   178,   137,    52,
      53,    54,    55,    56,    57,    37,    87,   146,    34,    62,
      63,   282,   300,   301,   302,   303,   304,   305,   178,    23,
      88,   202,    28,   282,   107,   108,   109,   110,   188,   206,
     207,   208,   235,   236,   237,    58,    59,   240,    49,    22,
      37,   244,   245,   246,    37,   337,   249,   250,   251,   252,
      37,   254,   255,   256,   257,   258,   259,    37,    37,   337,
      37,   339,   354,    37,   275,    37,    37,    37,    37,    37,
      37,   282,   253,    37,    37,    37,   354,    23,   101,   102,
     103,   104,   105,   106,    35,   266,     3,     4,     5,     6,
       7,     8,     9,    10,   275,    40,   275,    46,   369,   280,
      37,   282,    45,   282,    37,    37,   266,   425,    86,    16,
     369,    38,    98,    98,   295,   275,    27,    26,    38,    50,
     280,    51,   282,    38,    38,    38,    45,    45,    38,    45,
     333,    43,    38,   451,   452,    38,   275,    45,    38,    38,
      45,    38,    38,   282,    38,    37,   188,    45,    38,    40,
      38,    38,    45,    38,    38,   473,   337,    38,   369,    45,
      38,    38,    38,    52,   114,   483,   178,   337,   371,   372,
     373,    73,   272,   271,   488,   234,   369,   337,   447,   108,
     282,   280,   500,    43,   376,   390,   506,   378,   369,    -1,
     369,   310,   310,    -1,   354,    -1,    -1,    -1,   401,   402,
     403,    -1,    -1,   406,    -1,    -1,   409,    -1,    -1,   369,
      -1,   414,    -1,   424,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     369,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   424,    -1,   424,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   462,
      -1,   464,    -1,    -1,   424,    -1,   477,    -1,   449,   450,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   488,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   424,    -1,    -1,    -1,   449,
     450,    -1,    -1,    -1,    18,    -1,   477,    -1,   477,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   488,    -1,   488,
      -1,    -1,    -1,    37,    -1,    -1,    -1,   477,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   488,    -1,
      -1,    -1,    -1,    -1,    58,    59,    -1,    61,   477,    -1,
      64,    65,    66,    67,    68,    69,    70,    71,    72,   488,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    -1,    -1,    -1,    -1,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
      24,    25,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    37,    -1,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    48,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
      -1,    -1,   116,   117,    -1,    -1,    -1,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
     119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
      -1,   119,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      -1,    48,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    -1,    -1,    -1,   119,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    -1,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    -1,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    37,   119,   111,   112,   113,    -1,    -1,   116,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    -1,    61,    39,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    -1,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    -1,
      -1,    -1,    -1,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    37,    -1,
     116,   117,    -1,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    38,    39,   116,   117,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    -1,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    -1,    -1,    -1,    -1,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    37,    -1,   116,   117,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,    -1,   116,
     117,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    -1,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,   113
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  MapSetParser::yystos_[] =
  {
         0,   121,   122,     0,    14,   126,   127,   129,   111,   123,
     128,     3,     4,     5,     6,     7,     8,     9,    10,   124,
      15,   130,   116,   117,   251,   107,   108,   109,   110,   289,
     298,   289,   289,   289,   111,   112,   113,   299,   300,   289,
      96,    97,   297,    11,   125,   136,   131,   289,    85,   118,
     290,   291,   292,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   114,   115,   119,   252,   289,   293,   294,   295,
     296,   297,   299,   301,    19,   112,   289,   299,    34,   220,
     132,   221,   133,   111,    29,    30,    31,    32,    33,    48,
     222,   223,   226,   241,   242,   244,   245,   246,   249,   251,
     252,    20,    36,   137,   142,   143,   243,    35,    40,   224,
     225,   228,    37,   227,    21,   138,   139,   140,   141,   299,
      87,   144,   145,   149,    34,   176,    47,   229,   240,   250,
     251,   299,   222,   229,   234,   235,   241,   247,   248,   249,
     229,   141,    23,    88,   146,   152,   177,    28,   166,   172,
     174,    49,   236,   239,   248,    38,   248,    37,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,   150,   151,
     210,   251,   276,   278,   280,   281,   299,    37,   153,   154,
     209,   210,   275,   276,    22,   147,   155,   178,   179,   180,
     185,   226,   167,   251,   233,   238,    58,    59,    61,    89,
      90,    91,    92,    93,    94,    95,   251,   253,   254,   257,
     260,   261,   264,   265,   271,   273,   274,   275,   276,   282,
     287,   289,   293,   297,   299,    37,    37,    37,   119,   277,
      37,   119,   217,   218,    37,    37,    37,   176,   176,    37,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    37,
     151,    37,   119,   211,   253,   154,    23,    26,    27,   148,
     161,   164,   165,    35,   184,    40,   186,   187,    34,   251,
      46,   232,    45,   237,   274,   274,   274,    37,    37,   216,
     216,   216,   216,    37,   216,    86,   134,   135,   256,   259,
      52,    53,    54,    55,    56,    57,    62,    63,   262,   263,
     270,   272,   211,   288,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   251,   253,   253,   253,   253,
     253,   253,    16,   213,    38,    24,    25,   156,   157,   158,
     159,   160,   209,   251,    98,    98,   162,   165,   163,   164,
      12,    13,    41,    42,    44,   181,   183,   188,   189,   192,
     196,   199,   202,   203,   208,   180,   173,   230,   231,   240,
     239,   213,   213,   213,   251,    38,    50,   255,    51,   258,
     264,   264,   264,   264,   264,   264,   217,   217,    58,    59,
     266,   269,   295,   296,    18,    60,   267,    38,    38,    38,
     219,    45,    45,    45,    38,    38,    45,    38,    38,    45,
      38,    38,    38,    38,    45,   253,   157,   275,   193,   197,
     190,   200,   209,    40,   182,   204,   171,   236,    18,   253,
     284,   253,   253,   257,   260,   271,   271,   267,   268,   273,
     273,   215,   253,   253,   253,   253,   253,   253,   212,   194,
     198,   191,   201,   180,   176,    35,    37,   169,    38,    38,
     283,    38,    45,   214,    45,    38,    38,    38,    38,   214,
     279,   215,   250,   250,   176,   176,   207,   170,   215,   253,
     253,    38,    38,   195,   176,    43,   205,    39,   168,   175,
     251,   289,   293,   297,   299,    46,   285,   286,    38,   176,
     206,    38,   175,    73,    38,   176,    52,   298
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
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  MapSetParser::yyr1_[] =
  {
         0,   120,   122,   121,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   124,   124,   125,   125,   126,   127,   127,
     128,   128,   129,   131,   132,   130,   133,   133,   134,   135,
     135,   136,   137,   138,   138,   139,   140,   141,   142,   143,
     143,   144,   145,   145,   146,   146,   147,   147,   148,   148,
     149,   150,   150,   151,   151,   151,   151,   152,   153,   153,
     154,   155,   156,   156,   157,   157,   158,   158,   159,   160,
     160,   161,   161,   162,   162,   163,   163,   164,   165,   166,
     167,   167,   168,   168,   170,   169,   171,   171,   173,   172,
     174,   174,   175,   175,   175,   175,   175,   175,   177,   176,
     178,   179,   180,   180,   181,   181,   182,   182,   183,   184,
     184,   185,   186,   187,   187,   188,   188,   188,   188,   188,
     190,   191,   189,   193,   194,   195,   192,   197,   198,   196,
     200,   201,   199,   203,   204,   202,   206,   205,   207,   207,
     208,   209,   209,   209,   210,   211,   212,   211,   213,   213,
     214,   215,   215,   216,   217,   218,   219,   218,   221,   220,
     222,   222,   223,   224,   225,   225,   227,   226,   228,   226,
     229,   230,   231,   231,   232,   233,   233,   234,   235,   235,
     236,   237,   238,   238,   239,   240,   240,   241,   241,   243,
     242,   244,   245,   245,   245,   245,   245,   246,   246,   247,
     247,   248,   248,   249,   249,   250,   250,   251,   251,   252,
     252,   252,   252,   252,   252,   253,   254,   255,   256,   256,
     257,   258,   259,   259,   260,   261,   262,   262,   262,   262,
     262,   262,   262,   262,   263,   263,   264,   265,   266,   266,
     267,   267,   268,   268,   269,   269,   269,   270,   270,   271,
     272,   272,   273,   273,   273,   273,   274,   274,   274,   274,
     274,   274,   274,   274,   275,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   277,   277,   278,   279,   279,
     280,   281,   282,   282,   282,   282,   282,   282,   283,   282,
     284,   284,   285,   286,   286,   287,   288,   288,   289,   290,
     291,   291,   292,   292,   293,   293,   293,   294,   294,   294,
     295,   295,   295,   296,   296,   296,   297,   297,   298,   298,
     298,   298,   299,   299,   300,   300,   301,   301
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  MapSetParser::yyr2_[] =
  {
         0,     2,     0,     4,     0,     5,     3,     3,     3,     3,
       3,     3,     3,     0,     2,     0,     2,     2,     0,     1,
       0,     2,     2,     0,     0,     5,     0,     2,     2,     0,
       1,     6,     2,     1,     1,     1,     2,     1,     3,     0,
       1,     4,     0,     1,     0,     1,     0,     1,     0,     1,
       3,     1,     2,     1,     1,     4,     1,     2,     1,     2,
       1,     3,     1,     2,     1,     1,     1,     1,     2,     1,
       1,     2,     2,     0,     1,     0,     1,     2,     2,     1,
       1,     2,     1,     2,     0,     4,     0,     2,     0,     6,
       0,     1,     1,     1,     1,     1,     1,     1,     0,     4,
       1,     2,     0,     1,     1,     1,     0,     1,     3,     0,
       2,     2,     2,     0,     1,     1,     1,     1,     1,     1,
       0,     0,     4,     0,     0,     0,     6,     0,     0,     5,
       0,     0,     4,     0,     0,     4,     0,     3,     0,     2,
       2,     1,     1,     1,     2,     1,     0,     6,     0,     1,
       2,     0,     2,     4,     1,     1,     0,     5,     0,     4,
       0,     1,     2,     2,     0,     1,     0,     3,     0,     3,
       3,     2,     0,     1,     2,     0,     2,     1,     0,     1,
       2,     2,     0,     2,     1,     1,     1,     1,     1,     0,
       4,     4,     1,     1,     1,     1,     1,     0,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     0,     2,
       2,     2,     0,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     0,     1,     1,     2,     1,     1,
       2,     2,     0,     1,     2,     2,     2,     0,     2,     2,
       0,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     4,     4,     6,     4,     4,
       4,     4,     2,     2,     8,     6,     6,     6,     4,     4,
       4,     4,     1,     1,     1,     3,     1,     7,     0,     1,
       2,     2,     5,     2,     2,     2,     2,     2,     0,     8,
       1,     1,     4,     0,     1,     2,     0,     1,     2,     2,
       1,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const MapSetParser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "IT_REWRITEVAR", "IT_SERVER",
  "IT_USER", "IT_PASSWORD", "IT_DATABASE", "IT_STEMURI", "IT_PRIMARYKEY",
  "IT_SHAREDVARS", "IT_LABEL", "IT_GRAPH", "IT_SERVICE", "IT_BASE",
  "IT_PREFIX", "IT_DISTINCT", "IT_REDUCED", "GT_TIMES", "IT_CONSTRUCT",
  "IT_FROM", "IT_NAMED", "IT_ORDER", "IT_BY", "IT_ASC", "IT_DESC",
  "IT_LIMIT", "IT_OFFSET", "IT_BINDINGS", "IT_MEMBERS", "IT_STARTS",
  "IT_ENDS", "IT_ANY", "IT_UNORDERED", "GT_LCURLEY", "GT_RCURLEY",
  "IT_WHERE", "GT_LPAREN", "GT_RPAREN", "IT_UNDEF", "GT_DOT",
  "IT_OPTIONAL", "IT_MINUS", "IT_UNION", "IT_FILTER", "GT_COMMA",
  "GT_SEMI", "IT_a", "GT_LBRACKET", "GT_RBRACKET", "GT_OR", "GT_AND",
  "GT_EQUAL", "GT_NEQUAL", "GT_LT", "GT_GT", "GT_LE", "GT_GE", "GT_PLUS",
  "GT_MINUS", "GT_DIVIDE", "GT_NOT", "IT_IN", "GT_NOT_SPACECHAR_IN",
  "IT_IRI", "IT_URI", "IT_BNODE", "IT_COALESCE", "IT_IF", "IT_STRLANG",
  "IT_STRDT", "IT_EXISTS", "GT_NOT_SPACECHAR_EXISTS", "IT_SEPARATOR",
  "IT_STR", "IT_LANG", "IT_LANGMATCHES", "IT_DATATYPE", "IT_BOUND",
  "IT_sameTerm", "IT_isIRI", "IT_isURI", "IT_isBLANK", "IT_isLITERAL",
  "IT_REGEX", "GT_DTYPE", "IT_AS", "IT_GROUP", "IT_HAVING", "IT_COUNT",
  "IT_SUM", "IT_MIN", "IT_MAX", "IT_AVG", "IT_GROUP_CONCAT", "IT_SAMPLE",
  "IT_true", "IT_false", "INTEGER", "DECIMAL", "DOUBLE",
  "INTEGER_POSITIVE", "DECIMAL_POSITIVE", "DOUBLE_POSITIVE",
  "INTEGER_NEGATIVE", "DECIMAL_NEGATIVE", "DOUBLE_NEGATIVE",
  "STRING_LITERAL1", "STRING_LITERAL_LONG1", "STRING_LITERAL2",
  "STRING_LITERAL_LONG2", "IRI_REF", "PNAME_NS", "PNAME_LN",
  "BLANK_NODE_LABEL", "ANON", "VAR1", "VAR2", "LANGTAG", "NIL", "$accept",
  "MapSet", "$@1", "AccessParms_Star", "Map_Star", "_QLabel_E_Opt",
  "Prologue", "_QBaseDecl_E_Opt", "_QPrefixDecl_E_Star", "BaseDecl",
  "PrefixDecl", "$@2", "$@3", "_QDatasetClause_E_Star",
  "_O_QIT_AS_E_S_QVar_E_C", "_Q_O_QIT_AS_E_S_QVar_E_C_E_Opt",
  "ConstructQuery", "DatasetClause",
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
  "OffsetClause", "BindingsClause", "_QVar_E_Plus",
  "_QBindingValue_E_Plus",
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
       121,     0,    -1,    -1,   122,   126,   123,   124,    -1,    -1,
     123,     3,   251,   289,   289,    -1,   123,     4,   289,    -1,
     123,     5,   289,    -1,   123,     6,   289,    -1,   123,     7,
     289,    -1,   123,     8,   299,    -1,   123,     9,   289,    -1,
     123,    10,   297,    -1,    -1,   124,   136,    -1,    -1,    11,
     252,    -1,   127,   128,    -1,    -1,   129,    -1,    -1,   128,
     130,    -1,    14,   111,    -1,    -1,    -1,    15,   131,   112,
     132,   111,    -1,    -1,   133,   137,    -1,    86,   251,    -1,
      -1,   134,    -1,   125,    19,   220,   133,   142,   144,    -1,
      20,   138,    -1,   139,    -1,   140,    -1,   141,    -1,    21,
     141,    -1,   299,    -1,   143,   176,   166,    -1,    -1,    36,
      -1,   145,   146,   147,   148,    -1,    -1,   149,    -1,    -1,
     152,    -1,    -1,   155,    -1,    -1,   161,    -1,    87,    23,
     150,    -1,   151,    -1,   150,   151,    -1,   276,    -1,   210,
      -1,    37,   253,   135,    38,    -1,   251,    -1,    88,   153,
      -1,   154,    -1,   153,   154,    -1,   209,    -1,    22,    23,
     156,    -1,   157,    -1,   156,   157,    -1,   159,    -1,   160,
      -1,    24,    -1,    25,    -1,   158,   275,    -1,   209,    -1,
     251,    -1,   164,   162,    -1,   165,   163,    -1,    -1,   165,
      -1,    -1,   164,    -1,    26,    98,    -1,    27,    98,    -1,
     174,    -1,   251,    -1,   167,   251,    -1,   175,    -1,   168,
     175,    -1,    -1,    37,   170,   168,    38,    -1,    -1,   171,
     169,    -1,    -1,    28,   167,    34,   173,   171,    35,    -1,
      -1,   172,    -1,   299,    -1,   289,    -1,   293,    -1,   297,
      -1,    39,    -1,   251,    -1,    -1,    34,   177,   178,    35,
      -1,   179,    -1,   180,   184,    -1,    -1,   185,    -1,   188,
      -1,   208,    -1,    -1,    40,    -1,   181,   182,   180,    -1,
      -1,   184,   183,    -1,   226,   187,    -1,    40,   180,    -1,
      -1,   186,    -1,   189,    -1,   199,    -1,   202,    -1,   192,
      -1,   196,    -1,    -1,    -1,    41,   190,   191,   176,    -1,
      -1,    -1,    -1,    12,   193,   194,   250,   195,   176,    -1,
      -1,    -1,    13,   197,   198,   250,   176,    -1,    -1,    -1,
      42,   200,   201,   176,    -1,    -1,    -1,   203,   204,   176,
     207,    -1,    -1,    43,   206,   176,    -1,    -1,   207,   205,
      -1,    44,   209,    -1,   275,    -1,   276,    -1,   210,    -1,
     299,   211,    -1,   119,    -1,    -1,    37,   213,   253,   212,
     215,    38,    -1,    -1,    16,    -1,    45,   253,    -1,    -1,
     215,   214,    -1,    37,   213,   253,    38,    -1,   218,    -1,
     119,    -1,    -1,    37,   253,   219,   215,    38,    -1,    -1,
      34,   221,   222,    35,    -1,    -1,   223,    -1,   226,   225,
      -1,    40,   222,    -1,    -1,   224,    -1,    -1,   249,   227,
     229,    -1,    -1,   241,   228,   234,    -1,   240,   236,   233,
      -1,   240,   236,    -1,    -1,   230,    -1,    46,   231,    -1,
      -1,   233,   232,    -1,   235,    -1,    -1,   229,    -1,   239,
     238,    -1,    45,   239,    -1,    -1,   238,   237,    -1,   248,
      -1,   250,    -1,    47,    -1,   244,    -1,   242,    -1,    -1,
      48,   243,   229,    49,    -1,   246,    37,   247,    38,    -1,
      29,    -1,    30,    -1,    31,    -1,    32,    -1,    33,    -1,
      -1,   245,    -1,   248,    -1,   247,   248,    -1,   249,    -1,
     241,    -1,   251,    -1,   252,    -1,   251,    -1,   299,    -1,
     116,    -1,   117,    -1,   299,    -1,   289,    -1,   293,    -1,
     297,    -1,   301,    -1,   119,    -1,   254,    -1,   257,   256,
      -1,    50,   257,    -1,    -1,   256,   255,    -1,   260,   259,
      -1,    51,   260,    -1,    -1,   259,   258,    -1,   261,    -1,
     264,   263,    -1,    52,   264,    -1,    53,   264,    -1,    54,
     264,    -1,    55,   264,    -1,    56,   264,    -1,    57,   264,
      -1,    62,   217,    -1,    63,   217,    -1,    -1,   262,    -1,
     265,    -1,   271,   270,    -1,   295,    -1,   296,    -1,    18,
     273,    -1,    60,   273,    -1,    -1,   267,    -1,    58,   271,
      -1,    59,   271,    -1,   266,   268,    -1,    -1,   270,   269,
      -1,   273,   272,    -1,    -1,   272,   267,    -1,    61,   274,
      -1,    58,   274,    -1,    59,   274,    -1,   274,    -1,   275,
      -1,   276,    -1,   287,    -1,   289,    -1,   293,    -1,   297,
      -1,   251,    -1,   282,    -1,    37,   253,    38,    -1,    74,
      37,   253,    38,    -1,    75,    37,   253,    38,    -1,    76,
      37,   253,    45,   253,    38,    -1,    77,    37,   253,    38,
      -1,    78,    37,   251,    38,    -1,    64,    37,   253,    38,
      -1,    65,    37,   253,    38,    -1,    66,   277,    -1,    67,
     217,    -1,    68,    37,   253,    45,   253,    45,   253,    38,
      -1,    69,    37,   253,    45,   253,    38,    -1,    70,    37,
     253,    45,   253,    38,    -1,    79,    37,   253,    45,   253,
      38,    -1,    80,    37,   253,    38,    -1,    81,    37,   253,
      38,    -1,    82,    37,   253,    38,    -1,    83,    37,   253,
      38,    -1,   278,    -1,   280,    -1,   281,    -1,    37,   253,
      38,    -1,   119,    -1,    84,    37,   253,    45,   253,   279,
      38,    -1,    -1,   214,    -1,    71,   176,    -1,    72,   176,
      -1,    89,    37,   213,   284,    38,    -1,    90,   216,    -1,
      91,   216,    -1,    92,   216,    -1,    93,   216,    -1,    95,
     216,    -1,    -1,    94,    37,   213,   253,   283,   215,   286,
      38,    -1,    18,    -1,   253,    -1,    46,    73,    52,   298,
      -1,    -1,   285,    -1,   299,   288,    -1,    -1,   211,    -1,
     298,   292,    -1,    85,   299,    -1,   118,    -1,   290,    -1,
      -1,   291,    -1,   294,    -1,   295,    -1,   296,    -1,    98,
      -1,    99,    -1,   100,    -1,   101,    -1,   102,    -1,   103,
      -1,   104,    -1,   105,    -1,   106,    -1,    96,    -1,    97,
      -1,   107,    -1,   109,    -1,   108,    -1,   110,    -1,   111,
      -1,   300,    -1,   113,    -1,   112,    -1,   114,    -1,   115,
      -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  MapSetParser::yyprhs_[] =
  {
         0,     0,     3,     4,     9,    10,    16,    20,    24,    28,
      32,    36,    40,    44,    45,    48,    49,    52,    55,    56,
      58,    59,    62,    65,    66,    67,    73,    74,    77,    80,
      81,    83,    90,    93,    95,    97,    99,   102,   104,   108,
     109,   111,   116,   117,   119,   120,   122,   123,   125,   126,
     128,   132,   134,   137,   139,   141,   146,   148,   151,   153,
     156,   158,   162,   164,   167,   169,   171,   173,   175,   178,
     180,   182,   185,   188,   189,   191,   192,   194,   197,   200,
     202,   204,   207,   209,   212,   213,   218,   219,   222,   223,
     230,   231,   233,   235,   237,   239,   241,   243,   245,   246,
     251,   253,   256,   257,   259,   261,   263,   264,   266,   270,
     271,   274,   277,   280,   281,   283,   285,   287,   289,   291,
     293,   294,   295,   300,   301,   302,   303,   310,   311,   312,
     318,   319,   320,   325,   326,   327,   332,   333,   337,   338,
     341,   344,   346,   348,   350,   353,   355,   356,   363,   364,
     366,   369,   370,   373,   378,   380,   382,   383,   389,   390,
     395,   396,   398,   401,   404,   405,   407,   408,   412,   413,
     417,   421,   424,   425,   427,   430,   431,   434,   436,   437,
     439,   442,   445,   446,   449,   451,   453,   455,   457,   459,
     460,   465,   470,   472,   474,   476,   478,   480,   481,   483,
     485,   488,   490,   492,   494,   496,   498,   500,   502,   504,
     506,   508,   510,   512,   514,   516,   518,   521,   524,   525,
     528,   531,   534,   535,   538,   540,   543,   546,   549,   552,
     555,   558,   561,   564,   567,   568,   570,   572,   575,   577,
     579,   582,   585,   586,   588,   591,   594,   597,   598,   601,
     604,   605,   608,   611,   614,   617,   619,   621,   623,   625,
     627,   629,   631,   633,   635,   639,   644,   649,   656,   661,
     666,   671,   676,   679,   682,   691,   698,   705,   712,   717,
     722,   727,   732,   734,   736,   738,   742,   744,   752,   753,
     755,   758,   761,   767,   770,   773,   776,   779,   782,   783,
     792,   794,   796,   801,   802,   804,   807,   808,   810,   813,
     816,   818,   820,   821,   823,   825,   827,   829,   831,   833,
     835,   837,   839,   841,   843,   845,   847,   849,   851,   853,
     855,   857,   859,   861,   863,   865,   867,   869
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  MapSetParser::yyrline_[] =
  {
         0,   362,   362,   362,   367,   369,   378,   381,   384,   387,
     390,   393,   396,   402,   404,   409,   412,   419,   423,   425,
     429,   431,   435,   441,   443,   441,   453,   456,   464,   471,
     474,   479,   488,   495,   496,   500,   506,   512,   519,   526,
     528,   532,   539,   542,   547,   550,   555,   558,   563,   567,
     571,   578,   581,   588,   591,   594,   597,   603,   609,   612,
     619,   624,   631,   635,   643,   645,   653,   656,   664,   672,
     673,   680,   684,   692,   695,   700,   703,   707,   713,   721,
     726,   730,   737,   740,   746,   746,   755,   758,   765,   765,
     774,   777,   780,   783,   786,   789,   792,   795,   802,   802,
     814,   819,   823,   825,   830,   831,   835,   837,   842,   846,
     849,   854,   859,   863,   866,   870,   871,   872,   873,   874,
     878,   880,   878,   894,   896,   898,   894,   909,   911,   909,
     920,   922,   920,   932,   935,   932,   945,   945,   959,   961,
     965,   976,   977,   978,   982,   990,   994,   994,  1003,  1006,
    1013,  1019,  1021,  1028,  1035,  1039,  1042,  1042,  1052,  1052,
    1060,  1062,  1067,  1072,  1076,  1078,  1082,  1082,  1085,  1085,
    1092,  1097,  1101,  1103,  1108,  1112,  1114,  1119,  1123,  1125,
    1130,  1135,  1139,  1141,  1145,  1152,  1156,  1163,  1164,  1168,
    1168,  1181,  1206,  1209,  1212,  1215,  1218,  1225,  1228,  1233,
    1237,  1244,  1245,  1249,  1252,  1256,  1259,  1265,  1266,  1270,
    1273,  1276,  1279,  1282,  1283,  1289,  1294,  1303,  1310,  1313,
    1321,  1330,  1337,  1340,  1347,  1352,  1363,  1366,  1369,  1372,
    1375,  1378,  1381,  1384,  1391,  1394,  1398,  1403,  1412,  1415,
    1422,  1425,  1432,  1435,  1440,  1443,  1447,  1461,  1464,  1472,
    1481,  1484,  1491,  1494,  1497,  1500,  1504,  1505,  1506,  1507,
    1510,  1513,  1516,  1519,  1523,  1529,  1532,  1535,  1538,  1541,
    1544,  1547,  1551,  1554,  1558,  1561,  1564,  1567,  1570,  1573,
    1576,  1579,  1582,  1583,  1584,  1590,  1593,  1600,  1607,  1610,
    1614,  1621,  1628,  1631,  1634,  1637,  1640,  1643,  1647,  1647,
    1659,  1662,  1666,  1672,  1675,  1679,  1689,  1692,  1697,  1705,
    1712,  1716,  1724,  1728,  1732,  1733,  1734,  1738,  1739,  1740,
    1744,  1745,  1746,  1750,  1751,  1752,  1756,  1757,  1761,  1762,
    1763,  1764,  1768,  1769,  1773,  1774,  1778,  1779
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
     115,   116,   117,   118,   119
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int MapSetParser::yyeof_ = 0;
  const int MapSetParser::yylast_ = 1031;
  const int MapSetParser::yynnts_ = 182;
  const int MapSetParser::yyempty_ = -2;
  const int MapSetParser::yyfinal_ = 3;
  const int MapSetParser::yyterror_ = 1;
  const int MapSetParser::yyerrcode_ = 256;
  const int MapSetParser::yyntokens_ = 120;

  const unsigned int MapSetParser::yyuser_token_number_max_ = 374;
  const MapSetParser::token_number_type MapSetParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 3608 "lib/MapSetParser/MapSetParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 1785 "lib/MapSetParser/MapSetParser.ypp"
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


