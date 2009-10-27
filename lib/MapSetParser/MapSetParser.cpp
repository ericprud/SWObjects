/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++

   Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

#include "MapSetParser.hpp"

/* User implementation prologue.  */
#line 194 "lib/MapSetParser/MapSetParser.ypp"

#include "../MapSetScanner.hpp"
#line 303 "lib/MapSetParser/MapSetParser.ypp"

#include "../MapSetScanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc.  */
#line 57 "lib/MapSetParser/MapSetParser.cpp"

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

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG							\
  for (bool yydebugcond_ = yydebug_; yydebugcond_; yydebugcond_ = false)	\
    (*yycdebug_)

/* Enable debugging if requested.  */
#if YYDEBUG

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

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab

namespace w3c_sw
{
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
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
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
#endif /* ! YYDEBUG */

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


  int
  MapSetParser::parse ()
  {
    /// Look-ahead and look-ahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the look-ahead.
    semantic_type yylval;
    /// Location of the look-ahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    #line 31 "lib/MapSetParser/MapSetParser.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}
  /* Line 547 of yacc.c.  */
#line 294 "lib/MapSetParser/MapSetParser.cpp"
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
    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without look-ahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a look-ahead token.  */
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

    /* Accept?  */
    if (yyn == yyfinal_)
      goto yyacceptlab;

    /* Shift the look-ahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted unless it is eof.  */
    if (yychar != yyeof_)
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
#line 318 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root = new MapSet();
      ;}
    break;

  case 5:
#line 326 "lib/MapSetParser/MapSetParser.ypp"
    {
#if REGEX_LIB == SWOb_DISABLED
      throw std::string("not compiled with REGEX_LIB: can't map ") + (yysemantic_stack_[(5) - (3)].p_Variable)->toString() + " from " + (yysemantic_stack_[(5) - (4)].p_RDFLiteral)->toString() + " to " + (yysemantic_stack_[(5) - (5)].p_RDFLiteral)->toString() + ".";
#else /* ! REGEX_LIB == SWOb_DISABLED */
#if NotYet
      driver.root->rewriteVars.push_back(POSmap((yysemantic_stack_[(5) - (3)].p_Variable), (yysemantic_stack_[(5) - (4)].p_RDFLiteral)->getLexicalValue(), (yysemantic_stack_[(5) - (5)].p_RDFLiteral)->getLexicalValue()));
#endif /* NotYet */
#endif /* ! REGEX_LIB == SWOb_DISABLED */
    ;}
    break;

  case 6:
#line 335 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->server = (yysemantic_stack_[(3) - (3)].p_RDFLiteral);
    ;}
    break;

  case 7:
#line 338 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->user = (yysemantic_stack_[(3) - (3)].p_RDFLiteral);
    ;}
    break;

  case 8:
#line 341 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->password = (yysemantic_stack_[(3) - (3)].p_RDFLiteral);
    ;}
    break;

  case 9:
#line 344 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->database = (yysemantic_stack_[(3) - (3)].p_RDFLiteral);
    ;}
    break;

  case 10:
#line 347 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->stemURI = (yysemantic_stack_[(3) - (3)].p_URI);
    ;}
    break;

  case 11:
#line 350 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->primaryKey = (yysemantic_stack_[(3) - (3)].p_RDFLiteral);
    ;}
    break;

  case 14:
#line 363 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    ;}
    break;

  case 15:
#line 366 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    ;}
    break;

  case 21:
#line 389 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI));
    ;}
    break;

  case 22:
#line 395 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ignorePrefix(true);
      ;}
    break;

  case 23:
#line 397 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.ignorePrefix(false);
      ;}
    break;

  case 24:
#line 399 "lib/MapSetParser/MapSetParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      ;}
    break;

  case 25:
#line 407 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POSList) = new POSList;
	(yyval.p_POSList)->push_back((yysemantic_stack_[(1) - (1)].p_Variable));
    ;}
    break;

  case 26:
#line 411 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSList)->push_back((yysemantic_stack_[(2) - (2)].p_Variable));
	(yyval.p_POSList) = (yysemantic_stack_[(2) - (1)].p_POSList);
    ;}
    break;

  case 27:
#line 419 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    ;}
    break;

  case 28:
#line 422 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    ;}
    break;

  case 29:
#line 430 "lib/MapSetParser/MapSetParser.ypp"
    {
	/* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	Construct* constr = new Construct((DefaultGraphPattern*)(yysemantic_stack_[(6) - (3)].p_BasicGraphPattern), (yysemantic_stack_[(6) - (4)].p_DatasetClauses), (yysemantic_stack_[(6) - (5)].p_WhereClause), (yysemantic_stack_[(6) - (6)].p_SolutionModifier));
	static_cast<MapSet*>(driver.root)->maps.push_back(LabeledConstruct((yysemantic_stack_[(6) - (1)].p_RDFLiteral), constr));
    ;}
    break;

  case 30:
#line 439 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    ;}
    break;

  case 33:
#line 451 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_POS), driver.posFactory);
    ;}
    break;

  case 34:
#line 457 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_POS), driver.posFactory);
    ;}
    break;

  case 35:
#line 463 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    ;}
    break;

  case 36:
#line 470 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curFilter = NULL;
      ;}
    break;

  case 37:
#line 472 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_WhereClause) = new WhereClause(driver.curOp, (yysemantic_stack_[(4) - (4)].p_BindingClause));
      ;}
    break;

  case 40:
#line 483 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BindingClause) = NULL;
    ;}
    break;

  case 42:
#line 491 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(2) - (1)].p_OrderConditions), (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit, (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset);
    ;}
    break;

  case 43:
#line 498 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    ;}
    break;

  case 45:
#line 506 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    ;}
    break;

  case 48:
#line 520 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    ;}
    break;

  case 50:
#line 528 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    ;}
    break;

  case 52:
#line 536 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    ;}
    break;

  case 53:
#line 540 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    ;}
    break;

  case 54:
#line 548 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    ;}
    break;

  case 55:
#line 555 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    ;}
    break;

  case 56:
#line 559 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    ;}
    break;

  case 58:
#line 569 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    ;}
    break;

  case 59:
#line 577 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    ;}
    break;

  case 60:
#line 580 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    ;}
    break;

  case 61:
#line 588 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 63:
#line 597 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new VarExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    ;}
    break;

  case 64:
#line 603 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    ;}
    break;

  case 65:
#line 609 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    ;}
    break;

  case 66:
#line 616 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBindingClause = new BindingClause((yysemantic_stack_[(3) - (2)].p_POSList));
      ;}
    break;

  case 67:
#line 618 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BindingClause) = driver.curBindingClause;
	  driver.curBindingClause = NULL;
      ;}
    break;

  case 68:
#line 626 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Bindings) = NULL;
    ;}
    break;

  case 69:
#line 629 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBindingClause->push_back((yysemantic_stack_[(2) - (2)].p_Binding));
	(yyval.p_Bindings) = NULL;
    ;}
    break;

  case 70:
#line 637 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding = new Binding();
      ;}
    break;

  case 71:
#line 639 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_Binding) = driver.curBinding;
	  driver.curBinding = NULL;
      ;}
    break;

  case 73:
#line 648 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = driver.getNULL();
    ;}
    break;

  case 74:
#line 655 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(1) - (1)].p_POS));
	(yyval.p_POSs) = NULL;
    ;}
    break;

  case 75:
#line 659 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSs) = NULL;
    ;}
    break;

  case 76:
#line 667 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = NULL;
	driver.curBGP = NULL;
      ;}
    break;

  case 77:
#line 670 "lib/MapSetParser/MapSetParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
	  driver.curFilter = NULL;
      ;}
    break;

  case 94:
#line 732 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      ;}
    break;

  case 95:
#line 734 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.curFilter;
	  // driver.curFilter = $<p_ParserFilter>$ = new FilterHolder();
      ;}
    break;

  case 96:
#line 737 "lib/MapSetParser/MapSetParser.ypp"
    {
	  OptionalGraphPattern* ret = new OptionalGraphPattern(driver.curOp);
	  // $<p_ParserFilter>3->copyExpressionsTo(ret);
	  if (driver.curFilter) {
	      driver.curFilter->copyExpressionsTo(ret);
	      delete driver.curFilter;
	  }
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), ret);
      ;}
    break;

  case 97:
#line 749 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curFilter = NULL;
      ;}
    break;

  case 98:
#line 752 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = driver.curGraphName;
	driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_POS);
      ;}
    break;

  case 99:
#line 755 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(5) - (3)].p_POS), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(5) - (4)].p_POS);
      ;}
    break;

  case 100:
#line 763 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curFilter = NULL;
      ;}
    break;

  case 101:
#line 766 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(3) - (1)].p_TableOperation), driver.curOp);
      ;}
    break;

  case 102:
#line 773 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	/* driver.curFilter = NULL; -- parallel, but unnecessary. */
      ;}
    break;

  case 103:
#line 776 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.curOp);
      ;}
    break;

  case 106:
#line 788 "lib/MapSetParser/MapSetParser.ypp"
    {
	if (driver.curFilter == NULL)
	    driver.curOp = driver.curFilter = new ParserFilter();
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 110:
#line 802 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    ;}
    break;

  case 111:
#line 809 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = new ArgList((yysemantic_stack_[(1) - (1)].p_Expressions));
    ;}
    break;

  case 112:
#line 816 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 114:
#line 824 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 115:
#line 831 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    ;}
    break;

  case 116:
#line 835 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      ;}
    break;

  case 117:
#line 837 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = NULL;
      ;}
    break;

  case 118:
#line 845 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBGP = NULL;
      ;}
    break;

  case 119:
#line 847 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      ;}
    break;

  case 126:
#line 875 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_POS);
    ;}
    break;

  case 128:
#line 878 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_POS);
    ;}
    break;

  case 144:
#line 938 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.posFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_POS)));
    ;}
    break;

  case 145:
#line 945 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_POS);
	driver.curPredicate = (yyval.p_POS);
    ;}
    break;

  case 146:
#line 949 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_POS);
    ;}
    break;

  case 149:
#line 961 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      ;}
    break;

  case 150:
#line 965 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_POS) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      ;}
    break;

  case 151:
#line 974 "lib/MapSetParser/MapSetParser.ypp"
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
    ;}
    break;

  case 152:
#line 999 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    ;}
    break;

  case 153:
#line 1002 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    ;}
    break;

  case 154:
#line 1005 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    ;}
    break;

  case 155:
#line 1008 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    ;}
    break;

  case 156:
#line 1011 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    ;}
    break;

  case 157:
#line 1018 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    ;}
    break;

  case 159:
#line 1026 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POSs) = new ProductionVector<const POS*>();
    ;}
    break;

  case 160:
#line 1029 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSs)->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSs) = (yysemantic_stack_[(2) - (1)].p_POSs);
    ;}
    break;

  case 161:
#line 1037 "lib/MapSetParser/MapSetParser.ypp"
    {
	/* no push_front
	   $2->push_front($1);
	   $$ = $2;
	   so copy the vector. */
	(yyval.p_POSs) = new ProductionVector<const POS*>();
	(yyval.p_POSs)->push_back((yysemantic_stack_[(2) - (1)].p_POS));
	for (std::vector<const POS*>::iterator it = (yysemantic_stack_[(2) - (2)].p_POSs)->begin();
	     it != (yysemantic_stack_[(2) - (2)].p_POSs)->end(); ++it)
	    (yyval.p_POSs)->push_back(*it);
	(yysemantic_stack_[(2) - (2)].p_POSs)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_POSs);
    ;}
    break;

  case 162:
#line 1054 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POSs) = new ProductionVector<const POS*>();
    ;}
    break;

  case 166:
#line 1066 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    ;}
    break;

  case 168:
#line 1073 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    ;}
    break;

  case 169:
#line 1076 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    ;}
    break;

  case 172:
#line 1087 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    ;}
    break;

  case 173:
#line 1090 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    ;}
    break;

  case 174:
#line 1093 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    ;}
    break;

  case 175:
#line 1096 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    ;}
    break;

  case 177:
#line 1100 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    ;}
    break;

  case 179:
#line 1111 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    ;}
    break;

  case 180:
#line 1120 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 181:
#line 1127 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    ;}
    break;

  case 182:
#line 1130 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    ;}
    break;

  case 183:
#line 1138 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    ;}
    break;

  case 184:
#line 1147 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 185:
#line 1154 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    ;}
    break;

  case 186:
#line 1157 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    ;}
    break;

  case 188:
#line 1169 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_BooleanComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_BooleanComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_BooleanComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    ;}
    break;

  case 189:
#line 1180 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 190:
#line 1183 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 191:
#line 1186 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 192:
#line 1189 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 193:
#line 1192 "lib/MapSetParser/MapSetParser.ypp"
    {
    (yyval.p_BooleanComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 194:
#line 1195 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 195:
#line 1202 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BooleanComparator) = NULL;
    ;}
    break;

  case 198:
#line 1215 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    ;}
    break;

  case 199:
#line 1224 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 200:
#line 1227 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 201:
#line 1230 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    ;}
    break;

  case 202:
#line 1233 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    ;}
    break;

  case 203:
#line 1240 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    ;}
    break;

  case 204:
#line 1243 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    ;}
    break;

  case 205:
#line 1251 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    ;}
    break;

  case 206:
#line 1260 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 207:
#line 1263 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 208:
#line 1270 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    ;}
    break;

  case 209:
#line 1273 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    ;}
    break;

  case 210:
#line 1280 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 211:
#line 1283 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 212:
#line 1286 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 217:
#line 1296 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new LiteralExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    ;}
    break;

  case 218:
#line 1299 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    ;}
    break;

  case 219:
#line 1302 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new BooleanExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    ;}
    break;

  case 220:
#line 1305 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new VarExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    ;}
    break;

  case 221:
#line 1311 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    ;}
    break;

  case 222:
#line 1317 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-str"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 223:
#line 1320 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-lang"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 224:
#line 1323 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-langMatches"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    ;}
    break;

  case 225:
#line 1326 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-datatype"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 226:
#line 1329 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-bound"), new VarExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    ;}
    break;

  case 227:
#line 1332 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-sameTerm"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    ;}
    break;

  case 228:
#line 1335 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 229:
#line 1338 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 230:
#line 1341 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isBlank"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 231:
#line 1344 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isLiteral"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 233:
#line 1352 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-regex"), (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    ;}
    break;

  case 234:
#line 1359 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    ;}
    break;

  case 236:
#line 1366 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new URIExpression((yysemantic_stack_[(2) - (1)].p_URI));
    ;}
    break;

  case 237:
#line 1376 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    ;}
    break;

  case 239:
#line 1384 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    ;}
    break;

  case 240:
#line 1392 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    ;}
    break;

  case 241:
#line 1399 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    ;}
    break;

  case 242:
#line 1403 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    ;}
    break;

  case 243:
#line 1411 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    ;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 1598 "lib/MapSetParser/MapSetParser.cpp"
	default: break;
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
	/* If just tried and failed to reuse look-ahead token after an
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

    /* Else will try to reuse look-ahead token after shifting the error
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

    if (yyn == yyfinal_)
      goto yyacceptlab;

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the look-ahead.  YYLOC is available though.
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
    if (yychar != yyeof_ && yychar != yyempty_)
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
  const short int MapSetParser::yypact_ninf_ = -298;
  const short int
  MapSetParser::yypact_[] =
  {
      -298,    24,    21,  -298,   -54,  -298,  -298,  -298,  -298,   181,
      33,   -55,    38,    38,    38,    38,    27,    38,     8,  -298,
    -298,  -298,  -298,    38,  -298,  -298,  -298,  -298,  -298,   -67,
    -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,    38,
      34,  -298,   -32,    38,    27,  -298,  -298,  -298,  -298,  -298,
      30,  -298,  -298,  -298,  -298,  -298,   -12,   357,    -3,  -298,
    -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,
    -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,
      49,  -298,    45,  -298,  -298,  -298,  -298,    59,  -298,  -298,
    -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,   -20,
    -298,  -298,    79,  -298,   -15,  -298,   357,  -298,  -298,   -15,
     381,   -15,    27,  -298,  -298,  -298,  -298,  -298,    80,  -298,
      46,  -298,    76,  -298,    56,   474,  -298,  -298,  -298,  -298,
    -298,  -298,  -298,  -298,  -298,    72,  -298,  -298,  -298,  -298,
     313,    44,    51,  -298,  -298,  -298,    94,   106,  -298,   105,
    -298,  -298,  -298,  -298,  -298,   450,  -298,  -298,   591,    97,
      99,   100,   101,   102,   104,   107,   109,   110,   118,   119,
     313,  -298,   121,  -298,  -298,  -298,  -298,  -298,  -298,  -298,
    -298,   -35,  -298,  -298,  -298,  -298,  -298,  -298,   357,   -55,
    -298,  -298,    98,   115,  -298,   626,   626,   626,  -298,   122,
    -298,  -298,  -298,  -298,   175,  -298,  -298,  -298,  -298,  -298,
    -298,  -298,  -298,  -298,  -298,   -35,   591,   591,   591,   591,
     -55,   591,   591,   591,   591,   591,   591,  -298,  -298,   591,
    -298,  -298,  -298,  -298,  -298,   123,   -29,  -298,   -15,  -298,
     474,  -298,  -298,  -298,  -298,  -298,   113,   114,   591,   591,
     591,   591,   591,   591,  -298,  -298,    71,    -4,  -298,  -298,
     131,   132,   136,   143,   145,   140,   148,   149,   150,   151,
     147,  -298,     6,   357,  -298,  -298,  -298,  -298,  -298,  -298,
     474,  -298,   591,  -298,   591,  -298,  -298,  -298,  -298,  -298,
    -298,  -298,   591,   591,  -298,  -298,  -298,   591,   591,  -298,
    -298,  -298,   591,  -298,  -298,   591,  -298,  -298,  -298,  -298,
     591,  -298,  -298,  -298,  -298,   202,   153,  -298,  -298,  -298,
    -298,  -298,    76,  -298,  -298,  -298,  -298,  -298,  -298,  -298,
    -298,  -298,  -298,   156,   157,   152,   -27,     5,  -298,  -298,
    -298,   357,   155,   -13,  -298,  -298,   591,  -298,   161,  -298,
    -298,  -298,    76,  -298,  -298,   155,  -298,  -298,  -298,  -298,
    -298,  -298,    76,  -298,    76,  -298,   506,  -298,  -298,  -298,
    -298,   533,  -298,  -298,  -298
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  MapSetParser::yydefact_[] =
  {
         2,     0,    17,     1,     0,     4,    19,    18,    21,    12,
      16,     0,     0,     0,     0,     0,     0,     0,     3,    22,
      20,   170,   171,     0,   259,   261,   260,   262,     6,   243,
       7,     8,     9,   263,   266,   265,    10,   264,    11,     0,
       0,    13,     0,     0,     0,   241,   242,   244,   239,    15,
       0,    23,     5,   240,   118,    27,     0,   120,    38,    24,
     152,   153,   154,   155,   156,   149,   257,   258,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   267,   268,   177,
       0,   121,   124,   128,   148,   147,   158,     0,   126,   166,
     167,   173,   174,   245,   246,   247,   175,   172,   176,     0,
      39,    28,    43,    36,     0,   119,   120,   125,   122,   138,
     157,     0,     0,    30,    31,    32,    33,    35,     0,    29,
      45,    44,     0,   146,     0,   157,   145,   168,   169,   123,
     139,   129,   137,   165,   163,     0,   159,   164,   127,    34,
       0,     0,     0,    42,    46,    47,    48,    50,    76,    40,
     150,   135,   142,   144,   151,   157,    59,    60,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,    55,     0,    57,    58,    62,   109,    63,   107,   108,
     232,     0,    64,    65,    52,    49,    53,    51,    78,     0,
      37,    41,   130,   140,   160,     0,     0,     0,   220,     0,
     178,   181,   185,   187,   195,   197,   203,   208,   213,   214,
     215,   216,   217,   218,   219,   237,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    56,    61,     0,
     115,   110,   111,    85,    79,    89,     0,    25,   132,   136,
     157,   143,   211,   212,   210,   221,   179,   183,     0,     0,
       0,     0,     0,     0,   196,   188,   198,   205,   238,   236,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   116,   100,    78,    90,    87,    66,    26,   133,   134,
     157,   141,     0,   182,     0,   186,   189,   190,   191,   192,
     193,   194,     0,     0,   204,   201,   202,     0,     0,   209,
     222,   223,     0,   225,   226,     0,   228,   229,   230,   231,
       0,   113,    97,    77,    94,     0,    82,    86,    80,    91,
      93,    92,     0,    81,    88,    68,   131,   180,   184,   199,
     200,   206,   207,     0,     0,   234,     0,     0,    95,   106,
      83,    78,   104,     0,   224,   227,     0,   235,     0,   117,
     114,    98,     0,    84,   102,   104,   101,    67,    70,    69,
     112,   233,     0,    96,     0,   105,     0,    99,   103,    73,
      74,     0,    72,    71,    75
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yypgoto_[] =
  {
      -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,
    -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,
     103,  -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,
    -298,  -298,  -298,  -298,    52,  -298,  -298,  -298,    81,    77,
    -298,  -298,  -298,  -298,  -298,  -141,  -298,  -297,  -298,  -264,
    -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,
    -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,  -123,  -298,
     -81,  -298,    20,   -92,  -298,  -298,  -298,  -298,  -298,   139,
    -298,  -298,  -298,   -45,  -298,  -298,   -71,  -298,  -298,  -298,
    -298,  -298,  -298,   -34,  -298,  -298,     7,    10,   -84,  -298,
    -298,  -298,  -298,  -298,  -298,  -298,  -298,   -91,  -108,   -88,
     -11,  -298,    -5,  -298,  -298,  -298,   -30,  -298,  -298,   -28,
    -298,  -298,  -298,    39,  -298,  -298,  -298,  -201,  -298,  -298,
    -195,  -143,  -139,  -133,  -298,  -298,  -298,  -298,    -9,  -298,
    -298,  -298,   -47,  -298,    -2,    -1,   -37,  -298,    13,  -298,
    -298
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yydefgoto_[] =
  {
        -1,     1,     2,     9,    18,    40,     5,     6,    10,     7,
      20,    42,    56,   236,    58,    41,   101,   113,   114,   115,
     116,   102,   122,   103,   190,   119,   120,   143,   144,   184,
     186,   145,   121,   170,   171,   172,   173,   174,   146,   147,
     191,   325,   343,   359,   366,   370,   371,   149,   188,   233,
     316,   341,   317,   272,   234,   274,   275,   318,   319,   338,
     352,   320,   337,   362,   321,   322,   355,   364,   356,   323,
     175,   176,   231,   347,   336,   232,   311,    55,    57,    80,
      81,   107,   108,   235,   111,   109,   124,   278,   279,   239,
     192,   131,   132,   151,   241,   193,   152,   125,    83,    84,
     104,    85,    86,    87,   155,   134,   135,   153,    88,   126,
     198,    90,   199,   200,   283,   246,   201,   285,   247,   202,
     203,   254,   255,   204,   205,   294,   256,   206,   299,   257,
     207,   208,   209,   210,   180,   348,   211,   259,   212,    46,
      47,    48,   213,    93,    94,    95,   214,    29,   215,    37,
      98
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int MapSetParser::yytable_ninf_ = -163;
  const short int
  MapSetParser::yytable_[] =
  {
        23,   178,   137,    28,    30,    31,    32,   179,    38,   324,
      92,   112,    82,   229,    43,   276,    44,   137,    39,   136,
      96,   312,   349,   297,     3,   342,   133,    99,   346,    36,
      49,   178,   357,   228,    52,   358,   -14,   179,   130,    45,
     138,   133,   123,     4,   100,     8,    89,   137,    91,    21,
      22,   313,   242,   243,   244,   363,    19,    53,   314,    92,
     315,    82,    50,    92,   194,   367,   298,   368,    51,    96,
      97,   133,   230,    96,    54,    21,    22,   353,    92,    33,
      34,    35,   141,   142,    33,    34,    35,    59,    96,    21,
      22,   329,   330,   127,   105,    89,   106,    91,   127,    89,
     127,    91,   331,   332,    33,    34,    35,   110,    92,    21,
      22,   118,   117,   140,    89,   150,    91,   128,    96,    97,
     148,   154,   128,    97,   128,   117,    33,    34,    35,   177,
     182,   142,   137,    24,    25,    26,    27,   183,    97,   292,
     293,    92,   141,   189,    89,   216,    91,   217,   218,   219,
     220,    96,   221,   181,   238,   222,   133,   223,   224,   177,
      71,    72,    73,    74,    75,    76,   225,   226,    97,   158,
     240,   245,   137,   282,   273,   284,   178,    89,   237,    91,
     300,   301,   179,   181,    11,    12,    13,    14,    15,    16,
      17,   302,   303,    92,   304,   305,   133,   306,   307,   308,
     309,    97,   310,    96,   340,   344,   345,   346,   354,   264,
     361,   260,   261,   262,   263,   139,   265,   266,   267,   268,
     269,   270,   227,   185,   271,   277,    92,   127,   187,    89,
     374,    91,   365,    92,   339,   258,    96,   248,   249,   250,
     251,   252,   253,    96,   350,   129,   326,   281,   280,   351,
     158,   128,   327,    97,   295,   296,   328,     0,   372,     0,
       0,     0,    89,   372,    91,     0,     0,     0,     0,    89,
       0,    91,     0,     0,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,     0,    97,   286,   287,   288,
     289,   290,   291,    97,    92,     0,     0,   333,     0,     0,
     334,    33,    34,    35,    96,   335,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    92,
       0,     0,     0,     0,    92,     0,   127,     0,   181,    96,
      89,     0,    91,     0,    96,     0,     0,     0,     0,     0,
       0,   360,     0,     0,     0,     0,     0,   156,   157,     0,
     128,     0,     0,     0,    97,    89,     0,    91,     0,     0,
      89,   158,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    97,
       0,     0,     0,     0,    97,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,    60,    61,    62,    63,
      64,     0,     0,     0,     0,  -157,     0,     0,     0,     0,
       0,     0,    33,    34,    35,    65,     0,    21,    22,     0,
      60,    61,    62,    63,    64,     0,     0,     0,     0,     0,
    -162,     0,     0,     0,     0,     0,     0,     0,     0,    65,
       0,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    24,    25,    26,    27,    33,    34,    35,    77,
      78,    21,    22,     0,    79,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    24,    25,    26,    27,
      33,    34,    35,    77,    78,    21,    22,     0,    79,    60,
      61,    62,    63,    64,     0,     0,     0,     0,     0,  -161,
       0,     0,     0,     0,     0,     0,     0,     0,    65,     0,
       0,     0,     0,    60,    61,    62,    63,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    65,     0,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    24,    25,    26,    27,    33,
      34,    35,    77,    78,    21,    22,   369,    79,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    24,
      25,    26,    27,    33,    34,    35,    77,    78,    21,    22,
       0,    79,   373,   369,     0,     0,     0,     0,     0,     0,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    24,    25,    26,    27,    33,    34,    35,    77,    78,
      21,    22,     0,    79,     0,     0,     0,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    24,    25,
      26,    27,    33,    34,    35,    77,    78,    21,    22,   158,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   195,
     196,     0,   197,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   158,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    24,    25,    26,    27,
      33,    34,    35,     0,     0,    21,    22,     0,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,     0,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    24,    25,    26,    27,    33,    34,    35,     0,     0,
      21,    22
  };

  /* YYCHECK.  */
  const short int
  MapSetParser::yycheck_[] =
  {
        11,   140,   110,    12,    13,    14,    15,   140,    17,   273,
      57,    31,    57,    48,    23,    44,    83,   125,    10,   110,
      57,    15,    49,    27,     0,   322,   110,    30,    55,    16,
      39,   170,    45,   172,    43,    48,    28,   170,   109,   106,
     111,   125,    57,    22,    47,    99,    57,   155,    57,   104,
     105,    45,   195,   196,   197,   352,    23,    44,    52,   106,
      54,   106,    28,   110,   155,   362,    70,   364,   100,   106,
      57,   155,   107,   110,    44,   104,   105,   341,   125,    99,
     100,   101,    36,    37,    99,   100,   101,    99,   125,   104,
     105,   292,   293,   104,    45,   106,    51,   106,   109,   110,
     111,   110,   297,   298,    99,   100,   101,    48,   155,   104,
     105,    32,    99,    33,   125,    59,   125,   104,   155,   106,
      44,    49,   109,   110,   111,   112,    99,   100,   101,   140,
      86,    37,   240,    95,    96,    97,    98,    86,   125,    68,
      69,   188,    36,    38,   155,    48,   155,    48,    48,    48,
      48,   188,    48,   140,    56,    48,   240,    48,    48,   170,
      89,    90,    91,    92,    93,    94,    48,    48,   155,    48,
      55,    49,   280,    60,    51,    61,   315,   188,   189,   188,
      49,    49,   315,   170,     3,     4,     5,     6,     7,     8,
       9,    55,    49,   240,    49,    55,   280,    49,    49,    49,
      49,   188,    55,   240,    51,    49,    49,    55,    53,   220,
      49,   216,   217,   218,   219,   112,   221,   222,   223,   224,
     225,   226,   170,   146,   229,   236,   273,   238,   147,   240,
     371,   240,   355,   280,   315,   215,   273,    62,    63,    64,
      65,    66,    67,   280,   336,   106,   280,   240,   238,   337,
      48,   238,   282,   240,   256,   256,   284,    -1,   366,    -1,
      -1,    -1,   273,   371,   273,    -1,    -1,    -1,    -1,   280,
      -1,   280,    -1,    -1,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    -1,   273,   248,   249,   250,
     251,   252,   253,   280,   341,    -1,    -1,   302,    -1,    -1,
     305,    99,   100,   101,   341,   310,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   366,
      -1,    -1,    -1,    -1,   371,    -1,   337,    -1,   315,   366,
     341,    -1,   341,    -1,   371,    -1,    -1,    -1,    -1,    -1,
      -1,   346,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,
     337,    -1,    -1,    -1,   341,   366,    -1,   366,    -1,    -1,
     371,    48,   371,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   366,
      -1,    -1,    -1,    -1,   371,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    99,   100,   101,    58,    -1,   104,   105,    -1,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,    -1,   107,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,    -1,   107,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,    50,   107,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
      -1,   107,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,    -1,   107,    -1,    -1,    -1,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,    48,
     107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    48,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,    -1,    -1,   104,   105,    -1,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    -1,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,    -1,
     104,   105
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  MapSetParser::yystos_[] =
  {
         0,   109,   110,     0,    22,   114,   115,   117,    99,   111,
     116,     3,     4,     5,     6,     7,     8,     9,   112,    23,
     118,   104,   105,   218,    95,    96,    97,    98,   246,   255,
     246,   246,   246,    99,   100,   101,   256,   257,   246,    10,
     113,   123,   119,   246,    83,   106,   247,   248,   249,   246,
      28,   100,   246,   256,    44,   185,   120,   186,   122,    99,
      39,    40,    41,    42,    43,    58,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,   102,   103,   107,
     187,   188,   191,   206,   207,   209,   210,   211,   216,   218,
     219,   246,   250,   251,   252,   253,   254,   256,   258,    30,
      47,   124,   129,   131,   208,    45,    51,   189,   190,   193,
      48,   192,    31,   125,   126,   127,   128,   256,    32,   133,
     134,   140,   130,    57,   194,   205,   217,   218,   256,   187,
     194,   199,   200,   206,   213,   214,   215,   216,   194,   128,
      33,    36,    37,   135,   136,   139,   146,   147,    44,   155,
      59,   201,   204,   215,    49,   212,    34,    35,    48,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
     141,   142,   143,   144,   145,   178,   179,   218,   240,   241,
     242,   256,    86,    86,   137,   147,   138,   146,   156,    38,
     132,   148,   198,   203,   215,    68,    69,    71,   218,   220,
     221,   224,   227,   228,   231,   232,   235,   238,   239,   240,
     241,   244,   246,   250,   254,   256,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,   142,   240,    48,
     107,   180,   183,   157,   162,   191,   121,   218,    56,   197,
      55,   202,   239,   239,   239,    49,   223,   226,    62,    63,
      64,    65,    66,    67,   229,   230,   234,   237,   180,   245,
     220,   220,   220,   220,   218,   220,   220,   220,   220,   220,
     220,   220,   161,    51,   163,   164,    44,   218,   195,   196,
     205,   204,    60,   222,    61,   225,   231,   231,   231,   231,
     231,   231,    68,    69,   233,   252,   253,    27,    70,   236,
      49,    49,    55,    49,    49,    55,    49,    49,    49,    49,
      55,   184,    15,    45,    52,    54,   158,   160,   165,   166,
     169,   172,   173,   177,   157,   149,   201,   224,   227,   235,
     235,   238,   238,   220,   220,   220,   182,   170,   167,   178,
      51,   159,   155,   150,    49,    49,    55,   181,   243,    49,
     181,   217,   168,   157,    53,   174,   176,    45,    48,   151,
     220,    49,   171,   155,   175,   176,   152,   155,   155,    50,
     153,   154,   216,    49,   153
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
     355,   356,   357,   358,   359,   360,   361,   362
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  MapSetParser::yyr1_[] =
  {
         0,   108,   110,   109,   111,   111,   111,   111,   111,   111,
     111,   111,   112,   112,   113,   113,   114,   115,   115,   116,
     116,   117,   119,   120,   118,   121,   121,   122,   122,   123,
     124,   125,   125,   126,   127,   128,   130,   129,   131,   131,
     132,   132,   133,   134,   134,   135,   135,   136,   137,   137,
     138,   138,   139,   139,   140,   141,   141,   142,   142,   143,
     143,   144,   145,   145,   146,   147,   149,   148,   150,   150,
     152,   151,   153,   153,   154,   154,   156,   155,   157,   157,
     158,   158,   159,   159,   160,   161,   161,   162,   163,   164,
     164,   165,   165,   165,   167,   168,   166,   170,   171,   169,
     173,   172,   175,   174,   176,   176,   177,   178,   178,   178,
     179,   180,   181,   182,   182,   183,   184,   183,   186,   185,
     187,   187,   188,   189,   190,   190,   192,   191,   193,   191,
     194,   195,   196,   196,   197,   198,   198,   199,   200,   200,
     201,   202,   203,   203,   204,   205,   205,   206,   206,   208,
     207,   209,   210,   210,   210,   210,   210,   211,   211,   212,
     212,   213,   214,   214,   215,   215,   216,   216,   217,   217,
     218,   218,   219,   219,   219,   219,   219,   219,   220,   221,
     222,   223,   223,   224,   225,   226,   226,   227,   228,   229,
     229,   229,   229,   229,   229,   230,   230,   231,   232,   233,
     233,   233,   233,   234,   234,   235,   236,   236,   237,   237,
     238,   238,   238,   238,   239,   239,   239,   239,   239,   239,
     239,   240,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   242,   243,   243,   244,   245,   245,   246,
     247,   248,   248,   249,   249,   250,   250,   250,   251,   251,
     251,   252,   252,   252,   253,   253,   253,   254,   254,   255,
     255,   255,   255,   256,   256,   257,   257,   258,   258
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  MapSetParser::yyr2_[] =
  {
         0,     2,     0,     4,     0,     5,     3,     3,     3,     3,
       3,     3,     0,     2,     0,     2,     2,     0,     1,     0,
       2,     2,     0,     0,     5,     1,     2,     0,     2,     6,
       2,     1,     1,     1,     2,     1,     0,     4,     0,     1,
       0,     1,     2,     0,     1,     0,     1,     1,     0,     1,
       0,     1,     2,     2,     3,     1,     2,     1,     1,     1,
       1,     2,     1,     1,     2,     2,     0,     6,     0,     2,
       0,     4,     1,     1,     1,     2,     0,     5,     0,     1,
       1,     1,     0,     1,     3,     0,     2,     2,     2,     0,
       1,     1,     1,     1,     0,     0,     4,     0,     0,     5,
       0,     3,     0,     3,     0,     2,     2,     1,     1,     1,
       2,     1,     2,     0,     2,     1,     0,     5,     0,     4,
       0,     1,     2,     2,     0,     1,     0,     3,     0,     3,
       3,     2,     0,     1,     2,     0,     2,     1,     0,     1,
       2,     2,     0,     2,     1,     1,     1,     1,     1,     0,
       4,     4,     1,     1,     1,     1,     1,     0,     1,     0,
       2,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     0,     2,     2,     2,     0,     2,     1,     2,     2,
       2,     2,     2,     2,     2,     0,     1,     1,     2,     2,
       2,     1,     1,     0,     2,     2,     2,     2,     0,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     4,     6,     4,     4,     6,     4,     4,
       4,     4,     1,     7,     0,     1,     2,     0,     1,     2,
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
  "IT_LABEL", "IT_REPLACE", "IT_WITH", "IT_DELETE", "IT_INSERT",
  "IT_GRAPH", "IT_LOAD", "IT_INTO", "IT_CLEAR", "IT_CREATE", "IT_SILENT",
  "IT_DROP", "IT_BASE", "IT_PREFIX", "IT_SELECT", "IT_DISTINCT",
  "IT_REDUCED", "GT_TIMES", "IT_CONSTRUCT", "IT_DESCRIBE", "IT_FROM",
  "IT_NAMED", "IT_ORDER", "IT_BY", "IT_ASC", "IT_DESC", "IT_LIMIT",
  "IT_OFFSET", "IT_BINDINGS", "IT_MEMBERS", "IT_STARTS", "IT_ENDS",
  "IT_ANY", "IT_UNORDERED", "GT_LCURLEY", "GT_RCURLEY", "IT_ASK",
  "IT_WHERE", "GT_LPAREN", "GT_RPAREN", "IT_NULL", "GT_DOT", "IT_OPTIONAL",
  "IT_UNION", "IT_FILTER", "GT_COMMA", "GT_SEMI", "IT_a", "GT_LBRACKET",
  "GT_RBRACKET", "GT_OR", "GT_AND", "GT_EQUAL", "GT_NEQUAL", "GT_LT",
  "GT_GT", "GT_LE", "GT_GE", "GT_PLUS", "GT_MINUS", "GT_DIVIDE", "GT_NOT",
  "IT_STR", "IT_LANG", "IT_LANGMATCHES", "IT_DATATYPE", "IT_BOUND",
  "IT_sameTerm", "IT_isIRI", "IT_isURI", "IT_isBLANK", "IT_isLITERAL",
  "IT_REGEX", "GT_DTYPE", "IT_true", "IT_false", "INTEGER", "DECIMAL",
  "DOUBLE", "INTEGER_POSITIVE", "DECIMAL_POSITIVE", "DOUBLE_POSITIVE",
  "INTEGER_NEGATIVE", "DECIMAL_NEGATIVE", "DOUBLE_NEGATIVE",
  "STRING_LITERAL1", "STRING_LITERAL_LONG1", "STRING_LITERAL2",
  "STRING_LITERAL_LONG2", "IRI_REF", "PNAME_NS", "PNAME_LN",
  "BLANK_NODE_LABEL", "ANON", "VAR1", "VAR2", "LANGTAG", "NIL", "$accept",
  "MapSet", "@1", "AccessParms_Star", "Map_Star", "_QLabel_E_Opt",
  "Prologue", "_QBaseDecl_E_Opt", "_QPrefixDecl_E_Star", "BaseDecl",
  "PrefixDecl", "@2", "@3", "_QVar_E_Plus", "_QDatasetClause_E_Star",
  "Construct", "DatasetClause",
  "_O_QDefaultGraphClause_E_Or_QNamedGraphClause_E_C",
  "DefaultGraphClause", "NamedGraphClause", "SourceSelector",
  "WhereClause", "@4", "_QIT_WHERE_E_Opt", "_QBindingClause_E_Opt",
  "SolutionModifier", "_QOrderClause_E_Opt", "_QLimitOffsetClauses_E_Opt",
  "LimitOffsetClauses", "_QOffsetClause_E_Opt", "_QLimitClause_E_Opt",
  "_QLimitClause_E_S_QOffsetClause_E_Opt_Or_QOffsetClause_E_S_QLimitClause_E_Opt",
  "OrderClause", "_QOrderCondition_E_Plus", "OrderCondition",
  "_O_QIT_ASC_E_Or_QIT_DESC_E_C",
  "_O_QIT_ASC_E_Or_QIT_DESC_E_S_QBrackettedExpression_E_C",
  "_O_QConstraint_E_Or_QVar_E_C", "LimitClause", "OffsetClause",
  "BindingClause", "@5", "_QBinding_E_Star", "Binding", "@6",
  "_O_QVarOrTerm_E_Or_QIT_NULL_E_C",
  "_Q_O_QVarOrTerm_E_Or_QIT_NULL_E_C_E_Plus", "GroupGraphPattern", "@7",
  "_QTriplesBlock_E_Opt", "_O_QGraphPatternNotTriples_E_Or_QFilter_E_C",
  "_QGT_DOT_E_Opt",
  "_O_QGraphPatternNotTriples_E_Or_QFilter_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGraphPatternNotTriples_E_Or_QFilter_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "TriplesBlock", "_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C_E_Opt", "GraphPatternNotTriples",
  "OptionalGraphPattern", "@8", "@9", "GraphGraphPattern", "@10", "@11",
  "GroupOrUnionGraphPattern", "@12",
  "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@13",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star",
  "_O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C",
  "@14", "ConstructTemplate", "@15", "_QConstructTriples_E_Opt",
  "ConstructTriples", "_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C_E_Opt", "TriplesSameSubject",
  "@16", "@17", "PropertyListNotEmpty", "_O_QVerb_E_S_QObjectList_E_C",
  "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "ObjectList",
  "_O_QGT_COMMA_E_S_QObject_E_C", "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star",
  "Object", "Verb", "TriplesNode", "BlankNodePropertyList", "@18",
  "Generator",
  "_O_QIT_MEMBERS_E_Or_QIT_STARTS_E_Or_QIT_ENDS_E_Or_QIT_ANY_E_Or_QIT_UNORDERED_E_C",
  "_Q_O_QIT_MEMBERS_E_Or_QIT_STARTS_E_Or_QIT_ENDS_E_Or_QIT_ANY_E_Or_QIT_UNORDERED_E_C_E_Opt",
  "_QGraphNode_E_Star", "_O_QGraphNode_E_S_QGraphNode_E_Star_C",
  "_Q_O_QGraphNode_E_S_QGraphNode_E_Star_C_E_Opt", "GraphNode",
  "VarOrTerm", "VarOrIRIref", "Var", "GraphTerm", "Expression",
  "ConditionalOrExpression", "_O_QGT_OR_E_S_QConditionalAndExpression_E_C",
  "_Q_O_QGT_OR_E_S_QConditionalAndExpression_E_C_E_Star",
  "ConditionalAndExpression", "_O_QGT_AND_E_S_QValueLogical_E_C",
  "_Q_O_QGT_AND_E_S_QValueLogical_E_C_E_Star", "ValueLogical",
  "RelationalExpression",
  "_O_QGT_EQUAL_E_S_QNumericExpression_E_Or_QGT_NEQUAL_E_S_QNumericExpression_E_Or_QGT_LT_E_S_QNumericExpression_E_Or_QGT_GT_E_S_QNumericExpression_E_Or_QGT_LE_E_S_QNumericExpression_E_Or_QGT_GE_E_S_QNumericExpression_E_C",
  "_Q_O_QGT_EQUAL_E_S_QNumericExpression_E_Or_QGT_NEQUAL_E_S_QNumericExpression_E_Or_QGT_LT_E_S_QNumericExpression_E_Or_QGT_GT_E_S_QNumericExpression_E_Or_QGT_LE_E_S_QNumericExpression_E_Or_QGT_GE_E_S_QNumericExpression_E_C_E_Opt",
  "NumericExpression", "AdditiveExpression",
  "_O_QGT_PLUS_E_S_QMultiplicativeExpression_E_Or_QGT_MINUS_E_S_QMultiplicativeExpression_E_Or_QNumericLiteralPositive_E_Or_QNumericLiteralNegative_E_C",
  "_Q_O_QGT_PLUS_E_S_QMultiplicativeExpression_E_Or_QGT_MINUS_E_S_QMultiplicativeExpression_E_Or_QNumericLiteralPositive_E_Or_QNumericLiteralNegative_E_C_E_Star",
  "MultiplicativeExpression",
  "_O_QGT_TIMES_E_S_QUnaryExpression_E_Or_QGT_DIVIDE_E_S_QUnaryExpression_E_C",
  "_Q_O_QGT_TIMES_E_S_QUnaryExpression_E_Or_QGT_DIVIDE_E_S_QUnaryExpression_E_C_E_Star",
  "UnaryExpression", "PrimaryExpression", "BrackettedExpression",
  "BuiltInCall", "RegexExpression",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Opt", "IRIrefOrFunction",
  "_QArgList_E_Opt", "RDFLiteral", "_O_QGT_DTYPE_E_S_QIRIref_E_C",
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
       109,     0,    -1,    -1,   110,   114,   111,   112,    -1,    -1,
     111,     3,   218,   246,   246,    -1,   111,     4,   246,    -1,
     111,     5,   246,    -1,   111,     6,   246,    -1,   111,     7,
     246,    -1,   111,     8,   256,    -1,   111,     9,   246,    -1,
      -1,   112,   123,    -1,    -1,    10,   246,    -1,   115,   116,
      -1,    -1,   117,    -1,    -1,   116,   118,    -1,    22,    99,
      -1,    -1,    -1,    23,   119,   100,   120,    99,    -1,   218,
      -1,   121,   218,    -1,    -1,   122,   124,    -1,   113,    28,
     185,   122,   129,   133,    -1,    30,   125,    -1,   126,    -1,
     127,    -1,   128,    -1,    31,   128,    -1,   256,    -1,    -1,
     131,   130,   155,   132,    -1,    -1,    47,    -1,    -1,   148,
      -1,   134,   135,    -1,    -1,   140,    -1,    -1,   136,    -1,
     139,    -1,    -1,   147,    -1,    -1,   146,    -1,   146,   137,
      -1,   147,   138,    -1,    32,    33,   141,    -1,   142,    -1,
     141,   142,    -1,   144,    -1,   145,    -1,    34,    -1,    35,
      -1,   143,   240,    -1,   178,    -1,   218,    -1,    36,    86,
      -1,    37,    86,    -1,    -1,    38,   121,    44,   149,   150,
      45,    -1,    -1,   150,   151,    -1,    -1,    48,   152,   154,
      49,    -1,   216,    -1,    50,    -1,   153,    -1,   154,   153,
      -1,    -1,    44,   156,   157,   161,    45,    -1,    -1,   162,
      -1,   165,    -1,   177,    -1,    -1,    51,    -1,   158,   159,
     157,    -1,    -1,   161,   160,    -1,   191,   164,    -1,    51,
     157,    -1,    -1,   163,    -1,   166,    -1,   172,    -1,   169,
      -1,    -1,    -1,    52,   167,   168,   155,    -1,    -1,    -1,
      15,   170,   217,   171,   155,    -1,    -1,   173,   155,   176,
      -1,    -1,    53,   175,   155,    -1,    -1,   174,   176,    -1,
      54,   178,    -1,   240,    -1,   241,    -1,   179,    -1,   256,
     180,    -1,   183,    -1,    55,   220,    -1,    -1,   182,   181,
      -1,   107,    -1,    -1,    48,   220,   184,   182,    49,    -1,
      -1,    44,   186,   187,    45,    -1,    -1,   188,    -1,   191,
     190,    -1,    51,   187,    -1,    -1,   189,    -1,    -1,   216,
     192,   194,    -1,    -1,   206,   193,   199,    -1,   205,   201,
     198,    -1,   205,   201,    -1,    -1,   195,    -1,    56,   196,
      -1,    -1,   198,   197,    -1,   200,    -1,    -1,   194,    -1,
     204,   203,    -1,    55,   204,    -1,    -1,   203,   202,    -1,
     215,    -1,   217,    -1,    57,    -1,   209,    -1,   207,    -1,
      -1,    58,   208,   194,    59,    -1,   211,    48,   214,    49,
      -1,    39,    -1,    40,    -1,    41,    -1,    42,    -1,    43,
      -1,    -1,   210,    -1,    -1,   212,   215,    -1,   215,   212,
      -1,    -1,   213,    -1,   216,    -1,   206,    -1,   218,    -1,
     219,    -1,   218,    -1,   256,    -1,   104,    -1,   105,    -1,
     256,    -1,   246,    -1,   250,    -1,   254,    -1,   258,    -1,
     107,    -1,   221,    -1,   224,   223,    -1,    60,   224,    -1,
      -1,   223,   222,    -1,   227,   226,    -1,    61,   227,    -1,
      -1,   226,   225,    -1,   228,    -1,   231,   230,    -1,    62,
     231,    -1,    63,   231,    -1,    64,   231,    -1,    65,   231,
      -1,    66,   231,    -1,    67,   231,    -1,    -1,   229,    -1,
     232,    -1,   235,   234,    -1,    68,   235,    -1,    69,   235,
      -1,   252,    -1,   253,    -1,    -1,   234,   233,    -1,   238,
     237,    -1,    27,   238,    -1,    70,   238,    -1,    -1,   237,
     236,    -1,    71,   239,    -1,    68,   239,    -1,    69,   239,
      -1,   239,    -1,   240,    -1,   241,    -1,   244,    -1,   246,
      -1,   250,    -1,   254,    -1,   218,    -1,    48,   220,    49,
      -1,    72,    48,   220,    49,    -1,    73,    48,   220,    49,
      -1,    74,    48,   220,    55,   220,    49,    -1,    75,    48,
     220,    49,    -1,    76,    48,   218,    49,    -1,    77,    48,
     220,    55,   220,    49,    -1,    78,    48,   220,    49,    -1,
      79,    48,   220,    49,    -1,    80,    48,   220,    49,    -1,
      81,    48,   220,    49,    -1,   242,    -1,    82,    48,   220,
      55,   220,   243,    49,    -1,    -1,   181,    -1,   256,   245,
      -1,    -1,   180,    -1,   255,   249,    -1,    83,   256,    -1,
     106,    -1,   247,    -1,    -1,   248,    -1,   251,    -1,   252,
      -1,   253,    -1,    86,    -1,    87,    -1,    88,    -1,    89,
      -1,    90,    -1,    91,    -1,    92,    -1,    93,    -1,    94,
      -1,    84,    -1,    85,    -1,    95,    -1,    97,    -1,    96,
      -1,    98,    -1,    99,    -1,   257,    -1,   101,    -1,   100,
      -1,   102,    -1,   103,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  MapSetParser::yyprhs_[] =
  {
         0,     0,     3,     4,     9,    10,    16,    20,    24,    28,
      32,    36,    40,    41,    44,    45,    48,    51,    52,    54,
      55,    58,    61,    62,    63,    69,    71,    74,    75,    78,
      85,    88,    90,    92,    94,    97,    99,   100,   105,   106,
     108,   109,   111,   114,   115,   117,   118,   120,   122,   123,
     125,   126,   128,   131,   134,   138,   140,   143,   145,   147,
     149,   151,   154,   156,   158,   161,   164,   165,   172,   173,
     176,   177,   182,   184,   186,   188,   191,   192,   198,   199,
     201,   203,   205,   206,   208,   212,   213,   216,   219,   222,
     223,   225,   227,   229,   231,   232,   233,   238,   239,   240,
     246,   247,   251,   252,   256,   257,   260,   263,   265,   267,
     269,   272,   274,   277,   278,   281,   283,   284,   290,   291,
     296,   297,   299,   302,   305,   306,   308,   309,   313,   314,
     318,   322,   325,   326,   328,   331,   332,   335,   337,   338,
     340,   343,   346,   347,   350,   352,   354,   356,   358,   360,
     361,   366,   371,   373,   375,   377,   379,   381,   382,   384,
     385,   388,   391,   392,   394,   396,   398,   400,   402,   404,
     406,   408,   410,   412,   414,   416,   418,   420,   422,   424,
     427,   430,   431,   434,   437,   440,   441,   444,   446,   449,
     452,   455,   458,   461,   464,   467,   468,   470,   472,   475,
     478,   481,   483,   485,   486,   489,   492,   495,   498,   499,
     502,   505,   508,   511,   513,   515,   517,   519,   521,   523,
     525,   527,   531,   536,   541,   548,   553,   558,   565,   570,
     575,   580,   585,   587,   595,   596,   598,   601,   602,   604,
     607,   610,   612,   614,   615,   617,   619,   621,   623,   625,
     627,   629,   631,   633,   635,   637,   639,   641,   643,   645,
     647,   649,   651,   653,   655,   657,   659,   661,   663
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  MapSetParser::yyrline_[] =
  {
         0,   318,   318,   318,   324,   326,   335,   338,   341,   344,
     347,   350,   356,   358,   363,   366,   373,   377,   379,   383,
     385,   389,   395,   397,   395,   407,   411,   419,   422,   430,
     439,   446,   447,   451,   457,   463,   470,   470,   477,   479,
     483,   486,   491,   498,   501,   506,   510,   515,   520,   523,
     528,   531,   536,   540,   548,   555,   559,   567,   569,   577,
     580,   588,   596,   597,   603,   609,   616,   616,   626,   629,
     637,   637,   647,   648,   655,   659,   667,   667,   679,   681,
     686,   687,   691,   693,   698,   702,   705,   710,   715,   719,
     722,   726,   727,   728,   732,   734,   732,   749,   752,   749,
     763,   763,   773,   773,   782,   784,   788,   796,   797,   798,
     802,   809,   816,   822,   824,   831,   835,   835,   845,   845,
     853,   855,   860,   865,   869,   871,   875,   875,   878,   878,
     885,   890,   894,   896,   901,   905,   907,   912,   916,   918,
     923,   928,   932,   934,   938,   945,   949,   956,   957,   961,
     961,   974,   999,  1002,  1005,  1008,  1011,  1018,  1021,  1026,
    1029,  1037,  1054,  1057,  1061,  1062,  1066,  1069,  1073,  1076,
    1082,  1083,  1087,  1090,  1093,  1096,  1099,  1100,  1106,  1111,
    1120,  1127,  1130,  1138,  1147,  1154,  1157,  1164,  1169,  1180,
    1183,  1186,  1189,  1192,  1195,  1202,  1206,  1210,  1215,  1224,
    1227,  1230,  1233,  1240,  1243,  1251,  1260,  1263,  1270,  1273,
    1280,  1283,  1286,  1289,  1293,  1294,  1295,  1296,  1299,  1302,
    1305,  1311,  1317,  1320,  1323,  1326,  1329,  1332,  1335,  1338,
    1341,  1344,  1347,  1352,  1359,  1362,  1366,  1376,  1379,  1384,
    1392,  1399,  1403,  1411,  1415,  1419,  1420,  1421,  1425,  1426,
    1427,  1431,  1432,  1433,  1437,  1438,  1439,  1443,  1444,  1448,
    1449,  1450,  1451,  1455,  1456,  1460,  1461,  1465,  1466
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
	       << " (line " << yylno << "), ";
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
     105,   106,   107
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int MapSetParser::yyeof_ = 0;
  const int MapSetParser::yylast_ = 731;
  const int MapSetParser::yynnts_ = 151;
  const int MapSetParser::yyempty_ = -2;
  const int MapSetParser::yyfinal_ = 3;
  const int MapSetParser::yyterror_ = 1;
  const int MapSetParser::yyerrcode_ = 256;
  const int MapSetParser::yyntokens_ = 108;

  const unsigned int MapSetParser::yyuser_token_number_max_ = 362;
  const MapSetParser::token_number_type MapSetParser::yyundef_token_ = 2;

} // namespace w3c_sw

#line 1471 "lib/MapSetParser/MapSetParser.ypp"
 /*** Additional Code ***/

void w3c_sw::MapSetParser::error(const MapSetParser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}

/* START Driver (@@ stand-alone would allow it to be shared with other parsers */

namespace w3c_sw {

    MapSetDriver::MapSetDriver (std::string baseURI, POSFactory* posFactory) : 
	Driver(baseURI, posFactory), curSubject(NULL), curPredicate(NULL), 
	curBGP(NULL), 
	curBindingClause(NULL), curBinding(NULL), curExprList(NULL), 
	root(NULL)
{
}

    MapSetDriver::~MapSetDriver ()
{
}

bool MapSetDriver::parse_stream(std::istream& in, const std::string& sname)
{
    streamname = sname;

    MapSetScanner scanner(this, &in);
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


