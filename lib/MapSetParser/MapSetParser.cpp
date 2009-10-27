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
#line 212 "lib/MapSetParser/MapSetParser.ypp"

#include "../MapSetScanner.hpp"
#line 321 "lib/MapSetParser/MapSetParser.ypp"

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
#line 336 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root = new MapSet();
      ;}
    break;

  case 5:
#line 344 "lib/MapSetParser/MapSetParser.ypp"
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
#line 353 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->server = (yysemantic_stack_[(3) - (3)].p_RDFLiteral);
    ;}
    break;

  case 7:
#line 356 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->user = (yysemantic_stack_[(3) - (3)].p_RDFLiteral);
    ;}
    break;

  case 8:
#line 359 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->password = (yysemantic_stack_[(3) - (3)].p_RDFLiteral);
    ;}
    break;

  case 9:
#line 362 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->database = (yysemantic_stack_[(3) - (3)].p_RDFLiteral);
    ;}
    break;

  case 10:
#line 365 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->stemURI = (yysemantic_stack_[(3) - (3)].p_URI);
    ;}
    break;

  case 11:
#line 368 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->primaryKey = (yysemantic_stack_[(3) - (3)].p_RDFLiteral);
    ;}
    break;

  case 14:
#line 381 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    ;}
    break;

  case 15:
#line 384 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    ;}
    break;

  case 21:
#line 407 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI));
    ;}
    break;

  case 22:
#line 413 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ignorePrefix(true);
      ;}
    break;

  case 23:
#line 415 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.ignorePrefix(false);
      ;}
    break;

  case 24:
#line 417 "lib/MapSetParser/MapSetParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      ;}
    break;

  case 25:
#line 425 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POSList) = new POSList;
	(yyval.p_POSList)->push_back((yysemantic_stack_[(1) - (1)].p_Variable));
    ;}
    break;

  case 26:
#line 429 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSList)->push_back((yysemantic_stack_[(2) - (2)].p_Variable));
	(yyval.p_POSList) = (yysemantic_stack_[(2) - (1)].p_POSList);
    ;}
    break;

  case 27:
#line 437 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    ;}
    break;

  case 28:
#line 440 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    ;}
    break;

  case 29:
#line 448 "lib/MapSetParser/MapSetParser.ypp"
    {
	/* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	Construct* constr = new Construct((DefaultGraphPattern*)(yysemantic_stack_[(6) - (3)].p_BasicGraphPattern), (yysemantic_stack_[(6) - (4)].p_DatasetClauses), (yysemantic_stack_[(6) - (5)].p_WhereClause), (yysemantic_stack_[(6) - (6)].p_SolutionModifier));
	static_cast<MapSet*>(driver.root)->maps.push_back(LabeledConstruct((yysemantic_stack_[(6) - (1)].p_RDFLiteral), constr));
    ;}
    break;

  case 30:
#line 457 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    ;}
    break;

  case 33:
#line 469 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_POS), driver.posFactory);
    ;}
    break;

  case 34:
#line 475 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_POS), driver.posFactory);
    ;}
    break;

  case 35:
#line 481 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    ;}
    break;

  case 36:
#line 488 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.curOp, (yysemantic_stack_[(3) - (3)].p_BindingClause));
	driver.curOp = NULL;
    ;}
    break;

  case 39:
#line 501 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BindingClause) = NULL;
    ;}
    break;

  case 41:
#line 509 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(2) - (1)].p_OrderConditions), (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit, (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset);
    ;}
    break;

  case 42:
#line 516 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    ;}
    break;

  case 44:
#line 524 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    ;}
    break;

  case 47:
#line 538 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    ;}
    break;

  case 49:
#line 546 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    ;}
    break;

  case 51:
#line 554 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    ;}
    break;

  case 52:
#line 558 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    ;}
    break;

  case 53:
#line 566 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    ;}
    break;

  case 54:
#line 573 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    ;}
    break;

  case 55:
#line 577 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    ;}
    break;

  case 57:
#line 587 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    ;}
    break;

  case 58:
#line 595 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    ;}
    break;

  case 59:
#line 598 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    ;}
    break;

  case 60:
#line 606 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 62:
#line 615 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new VarExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    ;}
    break;

  case 63:
#line 621 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    ;}
    break;

  case 64:
#line 627 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    ;}
    break;

  case 65:
#line 634 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBindingClause = new BindingClause((yysemantic_stack_[(3) - (2)].p_POSList));
      ;}
    break;

  case 66:
#line 636 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BindingClause) = driver.curBindingClause;
	  driver.curBindingClause = NULL;
      ;}
    break;

  case 67:
#line 644 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Bindings) = NULL;
    ;}
    break;

  case 68:
#line 647 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBindingClause->push_back((yysemantic_stack_[(2) - (2)].p_Binding));
	(yyval.p_Bindings) = NULL;
    ;}
    break;

  case 69:
#line 655 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding = new Binding();
      ;}
    break;

  case 70:
#line 657 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_Binding) = driver.curBinding;
	  driver.curBinding = NULL;
      ;}
    break;

  case 72:
#line 666 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = driver.getNULL();
    ;}
    break;

  case 73:
#line 673 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(1) - (1)].p_POS));
	(yyval.p_POSs) = NULL;
    ;}
    break;

  case 74:
#line 677 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSs) = NULL;
    ;}
    break;

  case 75:
#line 685 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = NULL;
	driver.curBGP = NULL;
      ;}
    break;

  case 76:
#line 688 "lib/MapSetParser/MapSetParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      ;}
    break;

  case 93:
#line 749 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      ;}
    break;

  case 94:
#line 751 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.curFilter;
      ;}
    break;

  case 95:
#line 753 "lib/MapSetParser/MapSetParser.ypp"
    {
	  OptionalGraphPattern* ret = new OptionalGraphPattern(driver.curOp);
	  if (driver.curFilter) {
	      driver.curFilter->copyExpressionsTo(ret);
	      delete driver.curFilter;
	  }
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), ret);
	  driver.curFilter = (yysemantic_stack_[(4) - (3)].p_ParserFilter);
      ;}
    break;

  case 96:
#line 765 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      ;}
    break;

  case 97:
#line 767 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      ;}
    break;

  case 98:
#line 769 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_POS) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_POS);
      ;}
    break;

  case 99:
#line 772 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_POS), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_POS);
      ;}
    break;

  case 100:
#line 781 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      ;}
    break;

  case 101:
#line 784 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      ;}
    break;

  case 102:
#line 786 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      ;}
    break;

  case 103:
#line 794 "lib/MapSetParser/MapSetParser.ypp"
    {
	if (driver.curOp == NULL)
	    driver.ensureBasicGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      ;}
    break;

  case 104:
#line 799 "lib/MapSetParser/MapSetParser.ypp"
    {
	  if (driver.curOp == NULL)
	      driver.ensureBasicGraphPattern();
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.curOp);
      ;}
    break;

  case 107:
#line 814 "lib/MapSetParser/MapSetParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    if (driver.curOp == NULL)
		driver.ensureBasicGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 111:
#line 831 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    ;}
    break;

  case 112:
#line 838 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = new ArgList((yysemantic_stack_[(1) - (1)].p_Expressions));
    ;}
    break;

  case 113:
#line 845 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 115:
#line 853 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 116:
#line 860 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    ;}
    break;

  case 117:
#line 864 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      ;}
    break;

  case 118:
#line 866 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = NULL;
      ;}
    break;

  case 119:
#line 874 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBGP = NULL;
      ;}
    break;

  case 120:
#line 876 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      ;}
    break;

  case 127:
#line 904 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_POS);
    ;}
    break;

  case 129:
#line 907 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_POS);
    ;}
    break;

  case 145:
#line 967 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.posFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_POS)));
    ;}
    break;

  case 146:
#line 974 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_POS);
	driver.curPredicate = (yyval.p_POS);
    ;}
    break;

  case 147:
#line 978 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_POS);
    ;}
    break;

  case 150:
#line 990 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      ;}
    break;

  case 151:
#line 994 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_POS) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      ;}
    break;

  case 152:
#line 1003 "lib/MapSetParser/MapSetParser.ypp"
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

  case 153:
#line 1028 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    ;}
    break;

  case 154:
#line 1031 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    ;}
    break;

  case 155:
#line 1034 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    ;}
    break;

  case 156:
#line 1037 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    ;}
    break;

  case 157:
#line 1040 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    ;}
    break;

  case 158:
#line 1047 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    ;}
    break;

  case 160:
#line 1055 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POSs) = new ProductionVector<const POS*>();
    ;}
    break;

  case 161:
#line 1058 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSs)->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSs) = (yysemantic_stack_[(2) - (1)].p_POSs);
    ;}
    break;

  case 162:
#line 1066 "lib/MapSetParser/MapSetParser.ypp"
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

  case 163:
#line 1083 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POSs) = new ProductionVector<const POS*>();
    ;}
    break;

  case 167:
#line 1095 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    ;}
    break;

  case 169:
#line 1102 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    ;}
    break;

  case 170:
#line 1105 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    ;}
    break;

  case 173:
#line 1116 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    ;}
    break;

  case 174:
#line 1119 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    ;}
    break;

  case 175:
#line 1122 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    ;}
    break;

  case 176:
#line 1125 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    ;}
    break;

  case 178:
#line 1129 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    ;}
    break;

  case 180:
#line 1140 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    ;}
    break;

  case 181:
#line 1149 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 182:
#line 1156 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    ;}
    break;

  case 183:
#line 1159 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    ;}
    break;

  case 184:
#line 1167 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    ;}
    break;

  case 185:
#line 1176 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 186:
#line 1183 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    ;}
    break;

  case 187:
#line 1186 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    ;}
    break;

  case 189:
#line 1198 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_BooleanComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_BooleanComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_BooleanComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    ;}
    break;

  case 190:
#line 1209 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 191:
#line 1212 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 192:
#line 1215 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 193:
#line 1218 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 194:
#line 1221 "lib/MapSetParser/MapSetParser.ypp"
    {
    (yyval.p_BooleanComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 195:
#line 1224 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 196:
#line 1231 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BooleanComparator) = NULL;
    ;}
    break;

  case 199:
#line 1244 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    ;}
    break;

  case 200:
#line 1253 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 201:
#line 1256 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 202:
#line 1259 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    ;}
    break;

  case 203:
#line 1262 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    ;}
    break;

  case 204:
#line 1269 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    ;}
    break;

  case 205:
#line 1272 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    ;}
    break;

  case 206:
#line 1280 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    ;}
    break;

  case 207:
#line 1289 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 208:
#line 1292 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 209:
#line 1299 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    ;}
    break;

  case 210:
#line 1302 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    ;}
    break;

  case 211:
#line 1309 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 212:
#line 1312 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 213:
#line 1315 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 218:
#line 1325 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new LiteralExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    ;}
    break;

  case 219:
#line 1328 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    ;}
    break;

  case 220:
#line 1331 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new BooleanExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    ;}
    break;

  case 221:
#line 1334 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new VarExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    ;}
    break;

  case 222:
#line 1340 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    ;}
    break;

  case 223:
#line 1346 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-str"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 224:
#line 1349 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-lang"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 225:
#line 1352 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-langMatches"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    ;}
    break;

  case 226:
#line 1355 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-datatype"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 227:
#line 1358 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-bound"), new VarExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    ;}
    break;

  case 228:
#line 1361 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-sameTerm"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    ;}
    break;

  case 229:
#line 1364 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 230:
#line 1367 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 231:
#line 1370 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isBlank"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 232:
#line 1373 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isLiteral"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 234:
#line 1381 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-regex"), (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    ;}
    break;

  case 235:
#line 1388 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    ;}
    break;

  case 237:
#line 1395 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new URIExpression((yysemantic_stack_[(2) - (1)].p_URI));
    ;}
    break;

  case 238:
#line 1405 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    ;}
    break;

  case 240:
#line 1413 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    ;}
    break;

  case 241:
#line 1421 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    ;}
    break;

  case 242:
#line 1428 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    ;}
    break;

  case 243:
#line 1432 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    ;}
    break;

  case 244:
#line 1440 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    ;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 1614 "lib/MapSetParser/MapSetParser.cpp"
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
  const short int MapSetParser::yypact_ninf_ = -235;
  const short int
  MapSetParser::yypact_[] =
  {
      -235,    28,    11,  -235,   -61,  -235,  -235,  -235,  -235,   260,
      22,   -49,    80,    80,    80,    80,    34,    80,    12,  -235,
    -235,  -235,  -235,    80,  -235,  -235,  -235,  -235,  -235,   -63,
    -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,    80,
      19,  -235,   -33,    80,    34,  -235,  -235,  -235,  -235,  -235,
       7,  -235,  -235,  -235,  -235,  -235,   -38,   341,    -5,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,
      24,  -235,    20,  -235,  -235,  -235,  -235,    46,  -235,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,     6,
    -235,  -235,    70,    67,   -47,  -235,   341,  -235,  -235,   -47,
     365,   -47,    34,  -235,  -235,  -235,  -235,  -235,    83,  -235,
      55,  -235,  -235,    82,  -235,    59,   458,  -235,  -235,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,    74,  -235,  -235,  -235,
    -235,   293,    56,    57,  -235,  -235,  -235,   111,   114,   341,
     -49,  -235,  -235,  -235,  -235,  -235,  -235,  -235,   434,  -235,
    -235,   575,   107,   115,   124,   132,   133,   134,   138,   139,
     141,   143,   152,   293,  -235,   153,  -235,  -235,  -235,  -235,
    -235,  -235,  -235,  -235,   -39,  -235,  -235,  -235,  -235,  -235,
    -235,  -235,  -235,   154,   -17,  -235,   147,   149,  -235,   610,
     610,   610,  -235,   157,  -235,  -235,  -235,  -235,   131,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,   -39,
     575,   575,   575,   575,   -49,   575,   575,   575,   575,   575,
     575,  -235,  -235,   575,  -235,  -235,  -235,    21,   341,  -235,
    -235,  -235,  -235,   -47,  -235,   458,  -235,  -235,  -235,  -235,
    -235,   150,   146,   575,   575,   575,   575,   575,   575,  -235,
    -235,    76,    -8,  -235,  -235,   162,   163,   170,   177,   179,
     175,   182,   184,   186,   188,   183,  -235,  -235,  -235,  -235,
     142,   189,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,
    -235,  -235,  -235,   458,  -235,   575,  -235,   575,  -235,  -235,
    -235,  -235,  -235,  -235,  -235,   575,   575,  -235,  -235,  -235,
     575,   575,  -235,  -235,  -235,   575,  -235,  -235,   575,  -235,
    -235,  -235,  -235,   575,  -235,  -235,  -235,  -235,  -235,   341,
      67,   -13,  -235,  -235,  -235,  -235,  -235,  -235,  -235,   190,
     195,   191,   -26,    53,    67,  -235,   192,  -235,  -235,  -235,
    -235,  -235,   575,  -235,   199,  -235,  -235,  -235,  -235,  -235,
     192,  -235,   490,  -235,  -235,    67,    67,  -235,  -235,  -235,
     517,  -235,  -235,  -235,  -235,  -235
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  MapSetParser::yydefact_[] =
  {
         2,     0,    17,     1,     0,     4,    19,    18,    21,    12,
      16,     0,     0,     0,     0,     0,     0,     0,     3,    22,
      20,   171,   172,     0,   260,   262,   261,   263,     6,   244,
       7,     8,     9,   264,   267,   266,    10,   265,    11,     0,
       0,    13,     0,     0,     0,   242,   243,   245,   240,    15,
       0,    23,     5,   241,   119,    27,     0,   121,    37,    24,
     153,   154,   155,   156,   157,   150,   258,   259,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   268,   269,   178,
       0,   122,   125,   129,   149,   148,   159,     0,   127,   167,
     168,   174,   175,   246,   247,   248,   176,   173,   177,     0,
      38,    28,    42,     0,     0,   120,   121,   126,   123,   139,
     158,     0,     0,    30,    31,    32,    33,    35,     0,    29,
      44,    43,    75,    39,   147,     0,   158,   146,   169,   170,
     124,   140,   130,   138,   166,   164,     0,   160,   165,   128,
      34,     0,     0,     0,    41,    45,    46,    47,    49,    77,
       0,    36,    40,   151,   136,   143,   145,   152,   158,    58,
      59,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,     0,    56,    57,    61,   110,
      62,   108,   109,   233,     0,    63,    64,    51,    48,    52,
      50,    84,    78,    88,     0,    25,   131,   141,   161,     0,
       0,     0,   221,     0,   179,   182,   186,   188,   196,   198,
     204,   209,   214,   215,   216,   217,   218,   219,   220,   238,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,    60,     0,   116,   111,   112,   100,    77,    89,
      86,    65,    26,   133,   137,   158,   144,   212,   213,   211,
     222,   180,   184,     0,     0,     0,     0,     0,     0,   197,
     189,   199,   206,   239,   237,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   117,    96,    76,    93,
       0,    81,    85,    79,    90,    92,    91,   101,    80,    87,
      67,   134,   135,   158,   142,     0,   183,     0,   187,   190,
     191,   192,   193,   194,   195,     0,     0,   205,   202,   203,
       0,     0,   210,   223,   224,     0,   226,   227,     0,   229,
     230,   231,   232,     0,   114,    97,    94,   107,    82,    77,
       0,     0,   132,   181,   185,   200,   201,   207,   208,     0,
       0,   235,     0,     0,     0,    83,   105,    66,    69,    68,
     225,   228,     0,   236,     0,   118,   115,    98,    95,   103,
     105,   102,     0,   113,   234,     0,     0,   106,    72,    73,
       0,    71,    99,   104,    70,    74
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yypgoto_[] =
  {
      -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,
     137,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,
    -235,  -235,  -235,    77,  -235,  -235,  -235,   103,   105,  -235,
    -235,  -235,  -235,  -235,  -115,  -235,  -234,  -235,  -225,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -104,
    -235,   -21,  -235,    42,   -66,  -235,  -235,  -235,  -235,  -235,
     171,  -235,  -235,  -235,   -41,  -235,  -235,   -85,  -235,  -235,
    -235,  -235,  -235,  -235,   -15,  -235,  -235,    35,    36,  -109,
    -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,   -95,  -108,
     -62,   -11,  -235,  -144,  -235,  -235,  -235,   -10,  -235,  -235,
      -7,  -235,  -235,  -235,    17,  -235,  -235,  -235,  -197,  -235,
    -235,  -182,   -40,  -134,  -129,  -235,  -235,  -235,  -235,    -9,
    -235,  -235,  -235,   -46,  -235,    25,    26,   -36,  -235,    15,
    -235,  -235
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yydefgoto_[] =
  {
        -1,     1,     2,     9,    18,    40,     5,     6,    10,     7,
      20,    42,    56,   194,    58,    41,   101,   113,   114,   115,
     116,   102,   103,   151,   119,   120,   144,   145,   187,   189,
     146,   121,   173,   174,   175,   176,   177,   147,   148,   152,
     290,   331,   349,   362,   369,   370,   123,   149,   191,   281,
     329,   282,   237,   192,   239,   240,   283,   284,   326,   344,
     285,   325,   343,   365,   286,   287,   330,   360,   366,   361,
     288,   178,   179,   235,   353,   342,   236,   324,    55,    57,
      80,    81,   107,   108,   193,   111,   109,   125,   291,   292,
     244,   196,   132,   133,   154,   246,   197,   155,   126,    83,
      84,   104,    85,    86,    87,   158,   135,   136,   156,    88,
     127,   202,    90,   203,   204,   296,   251,   205,   298,   252,
     206,   207,   259,   260,   208,   209,   307,   261,   210,   312,
     262,   211,   212,   213,   214,   183,   354,   215,   264,   216,
      46,    47,    48,   217,    93,    94,    95,   218,    29,   219,
      37,    98
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int MapSetParser::yytable_ninf_ = -164;
  const short int
  MapSetParser::yytable_[] =
  {
        23,   134,   138,    28,    30,    31,    32,   181,    38,   233,
     124,    92,   182,   289,    43,   137,    82,   134,   138,   310,
      44,    96,    39,   355,   131,    99,   139,   241,     3,   352,
      49,    36,   347,     4,    52,   348,   277,   112,     8,   181,
     -14,   232,   100,    45,   182,    19,    89,    50,    91,   134,
     138,    54,    33,    34,    35,    21,    22,    21,    22,    53,
      92,    59,   311,   198,    92,    82,   278,    51,   234,   105,
      96,   106,    97,   279,    96,   280,   265,   266,   267,   268,
      92,   270,   271,   272,   273,   274,   275,    21,    22,   276,
      96,   142,   143,   128,   110,    89,   346,    91,   128,    89,
     128,    91,   118,    92,   345,    33,    34,    35,   335,   336,
     358,   122,    92,    96,   117,    89,   141,    91,   153,   129,
     150,    97,    96,   157,   129,    97,   129,   117,   337,   338,
     180,   372,   373,    33,    34,    35,   134,   138,    89,   195,
      91,    97,   185,   186,   305,   306,   181,    89,   143,    91,
     142,   182,    33,    34,    35,   220,   184,    21,    22,   247,
     248,   249,   180,   221,    97,    71,    72,    73,    74,    75,
      76,   339,   222,    97,   340,    24,    25,    26,    27,   341,
     223,   224,   225,   242,   134,   138,   226,   227,   184,   228,
     161,   229,    92,   253,   254,   255,   256,   257,   258,    92,
     230,   161,    96,   243,   245,   238,   250,   297,   363,    96,
     295,   313,   314,   269,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   315,   316,    89,   317,    91,
     318,   319,   128,   320,    89,   321,    91,   322,   323,   350,
     328,    33,    34,    35,   351,   359,   352,    92,   364,   140,
     231,   190,   188,    97,   371,   375,   367,    96,   129,   327,
      97,   263,   371,    11,    12,    13,    14,    15,    16,    17,
     299,   300,   301,   302,   303,   304,   356,   130,   332,   293,
     294,   357,    89,    92,    91,   333,   308,   309,     0,     0,
     334,     0,     0,    96,     0,   184,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    97,     0,
       0,     0,     0,     0,     0,     0,    92,     0,    89,     0,
      91,     0,     0,     0,    92,     0,    96,   159,   160,     0,
       0,     0,   128,     0,    96,     0,     0,     0,     0,     0,
       0,   161,     0,     0,    97,     0,     0,     0,     0,     0,
       0,    89,     0,    91,     0,     0,     0,     0,   129,    89,
       0,    91,     0,     0,     0,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,     0,    97,     0,     0,
      60,    61,    62,    63,    64,    97,     0,     0,     0,  -158,
       0,     0,    33,    34,    35,     0,     0,    21,    22,    65,
       0,     0,     0,     0,    60,    61,    62,    63,    64,     0,
       0,     0,     0,     0,  -163,     0,     0,     0,     0,     0,
       0,     0,     0,    65,     0,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    24,    25,    26,    27,
      33,    34,    35,    77,    78,    21,    22,     0,    79,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      24,    25,    26,    27,    33,    34,    35,    77,    78,    21,
      22,     0,    79,    60,    61,    62,    63,    64,     0,     0,
       0,     0,     0,  -162,     0,     0,     0,     0,     0,     0,
       0,     0,    65,     0,     0,     0,     0,    60,    61,    62,
      63,    64,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65,     0,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    24,
      25,    26,    27,    33,    34,    35,    77,    78,    21,    22,
     368,    79,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    24,    25,    26,    27,    33,    34,    35,
      77,    78,    21,    22,     0,    79,   374,   368,     0,     0,
       0,     0,     0,     0,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    24,    25,    26,    27,    33,
      34,    35,    77,    78,    21,    22,     0,    79,     0,     0,
       0,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    24,    25,    26,    27,    33,    34,    35,    77,
      78,    21,    22,   161,    79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   199,   200,     0,   201,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   161,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      24,    25,    26,    27,    33,    34,    35,     0,     0,    21,
      22,     0,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,     0,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    24,    25,    26,    27,    33,
      34,    35,     0,     0,    21,    22
  };

  /* YYCHECK.  */
  const short int
  MapSetParser::yycheck_[] =
  {
        11,   110,   110,    12,    13,    14,    15,   141,    17,    48,
      57,    57,   141,   238,    23,   110,    57,   126,   126,    27,
      83,    57,    10,    49,   109,    30,   111,    44,     0,    55,
      39,    16,    45,    22,    43,    48,    15,    31,    99,   173,
      28,   175,    47,   106,   173,    23,    57,    28,    57,   158,
     158,    44,    99,   100,   101,   104,   105,   104,   105,    44,
     106,    99,    70,   158,   110,   106,    45,   100,   107,    45,
     106,    51,    57,    52,   110,    54,   220,   221,   222,   223,
     126,   225,   226,   227,   228,   229,   230,   104,   105,   233,
     126,    36,    37,   104,    48,   106,   330,   106,   109,   110,
     111,   110,    32,   149,   329,    99,   100,   101,   305,   306,
     344,    44,   158,   149,    99,   126,    33,   126,    59,   104,
      38,   106,   158,    49,   109,   110,   111,   112,   310,   311,
     141,   365,   366,    99,   100,   101,   245,   245,   149,   150,
     149,   126,    86,    86,    68,    69,   280,   158,    37,   158,
      36,   280,    99,   100,   101,    48,   141,   104,   105,   199,
     200,   201,   173,    48,   149,    89,    90,    91,    92,    93,
      94,   315,    48,   158,   318,    95,    96,    97,    98,   323,
      48,    48,    48,   194,   293,   293,    48,    48,   173,    48,
      48,    48,   238,    62,    63,    64,    65,    66,    67,   245,
      48,    48,   238,    56,    55,    51,    49,    61,   352,   245,
      60,    49,    49,   224,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    55,    49,   238,    49,   238,
      55,    49,   243,    49,   245,    49,   245,    49,    55,    49,
      51,    99,   100,   101,    49,    53,    55,   293,    49,   112,
     173,   148,   147,   238,   362,   370,   360,   293,   243,   280,
     245,   219,   370,     3,     4,     5,     6,     7,     8,     9,
     253,   254,   255,   256,   257,   258,   342,   106,   293,   243,
     245,   343,   293,   329,   293,   295,   261,   261,    -1,    -1,
     297,    -1,    -1,   329,    -1,   280,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   293,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   362,    -1,   329,    -1,
     329,    -1,    -1,    -1,   370,    -1,   362,    34,    35,    -1,
      -1,    -1,   343,    -1,   370,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    -1,   329,    -1,    -1,    -1,    -1,    -1,
      -1,   362,    -1,   362,    -1,    -1,    -1,    -1,   343,   370,
      -1,   370,    -1,    -1,    -1,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    -1,   362,    -1,    -1,
      39,    40,    41,    42,    43,   370,    -1,    -1,    -1,    48,
      -1,    -1,    99,   100,   101,    -1,    -1,   104,   105,    58,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,    -1,   107,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,    -1,   107,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
      50,   107,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,    -1,   107,    49,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,    -1,   107,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,    48,   107,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    69,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    48,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,    -1,   104,
     105,    -1,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,    -1,   104,   105
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  MapSetParser::yystos_[] =
  {
         0,   109,   110,     0,    22,   114,   115,   117,    99,   111,
     116,     3,     4,     5,     6,     7,     8,     9,   112,    23,
     118,   104,   105,   219,    95,    96,    97,    98,   247,   256,
     247,   247,   247,    99,   100,   101,   257,   258,   247,    10,
     113,   123,   119,   247,    83,   106,   248,   249,   250,   247,
      28,   100,   247,   257,    44,   186,   120,   187,   122,    99,
      39,    40,    41,    42,    43,    58,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,   102,   103,   107,
     188,   189,   192,   207,   208,   210,   211,   212,   217,   219,
     220,   247,   251,   252,   253,   254,   255,   257,   259,    30,
      47,   124,   129,   130,   209,    45,    51,   190,   191,   194,
      48,   193,    31,   125,   126,   127,   128,   257,    32,   132,
     133,   139,    44,   154,    57,   195,   206,   218,   219,   257,
     188,   195,   200,   201,   207,   214,   215,   216,   217,   195,
     128,    33,    36,    37,   134,   135,   138,   145,   146,   155,
      38,   131,   147,    59,   202,   205,   216,    49,   213,    34,
      35,    48,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,   140,   141,   142,   143,   144,   179,   180,
     219,   241,   242,   243,   257,    86,    86,   136,   146,   137,
     145,   156,   161,   192,   121,   219,   199,   204,   216,    68,
      69,    71,   219,   221,   222,   225,   228,   229,   232,   233,
     236,   239,   240,   241,   242,   245,   247,   251,   255,   257,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,   141,   241,    48,   107,   181,   184,   160,    51,   162,
     163,    44,   219,    56,   198,    55,   203,   240,   240,   240,
      49,   224,   227,    62,    63,    64,    65,    66,    67,   230,
     231,   235,   238,   181,   246,   221,   221,   221,   221,   219,
     221,   221,   221,   221,   221,   221,   221,    15,    45,    52,
      54,   157,   159,   164,   165,   168,   172,   173,   178,   156,
     148,   196,   197,   206,   205,    60,   223,    61,   226,   232,
     232,   232,   232,   232,   232,    68,    69,   234,   253,   254,
      27,    70,   237,    49,    49,    55,    49,    49,    55,    49,
      49,    49,    49,    55,   185,   169,   166,   179,    51,   158,
     174,   149,   202,   225,   228,   236,   236,   239,   239,   221,
     221,   221,   183,   170,   167,   156,   154,    45,    48,   150,
      49,    49,    55,   182,   244,    49,   182,   218,   154,    53,
     175,   177,   151,   221,    49,   171,   176,   177,    50,   152,
     153,   217,   154,   154,    49,   152
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
     124,   125,   125,   126,   127,   128,   129,   130,   130,   131,
     131,   132,   133,   133,   134,   134,   135,   136,   136,   137,
     137,   138,   138,   139,   140,   140,   141,   141,   142,   142,
     143,   144,   144,   145,   146,   148,   147,   149,   149,   151,
     150,   152,   152,   153,   153,   155,   154,   156,   156,   157,
     157,   158,   158,   159,   160,   160,   161,   162,   163,   163,
     164,   164,   164,   166,   167,   165,   169,   170,   171,   168,
     173,   174,   172,   176,   175,   177,   177,   178,   179,   179,
     179,   180,   181,   182,   183,   183,   184,   185,   184,   187,
     186,   188,   188,   189,   190,   191,   191,   193,   192,   194,
     192,   195,   196,   197,   197,   198,   199,   199,   200,   201,
     201,   202,   203,   204,   204,   205,   206,   206,   207,   207,
     209,   208,   210,   211,   211,   211,   211,   211,   212,   212,
     213,   213,   214,   215,   215,   216,   216,   217,   217,   218,
     218,   219,   219,   220,   220,   220,   220,   220,   220,   221,
     222,   223,   224,   224,   225,   226,   227,   227,   228,   229,
     230,   230,   230,   230,   230,   230,   231,   231,   232,   233,
     234,   234,   234,   234,   235,   235,   236,   237,   237,   238,
     238,   239,   239,   239,   239,   240,   240,   240,   240,   240,
     240,   240,   241,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   243,   244,   244,   245,   246,   246,
     247,   248,   249,   249,   250,   250,   251,   251,   251,   252,
     252,   252,   253,   253,   253,   254,   254,   254,   255,   255,
     256,   256,   256,   256,   257,   257,   258,   258,   259,   259
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  MapSetParser::yyr2_[] =
  {
         0,     2,     0,     4,     0,     5,     3,     3,     3,     3,
       3,     3,     0,     2,     0,     2,     2,     0,     1,     0,
       2,     2,     0,     0,     5,     1,     2,     0,     2,     6,
       2,     1,     1,     1,     2,     1,     3,     0,     1,     0,
       1,     2,     0,     1,     0,     1,     1,     0,     1,     0,
       1,     2,     2,     3,     1,     2,     1,     1,     1,     1,
       2,     1,     1,     2,     2,     0,     6,     0,     2,     0,
       4,     1,     1,     1,     2,     0,     5,     0,     1,     1,
       1,     0,     1,     3,     0,     2,     2,     2,     0,     1,
       1,     1,     1,     0,     0,     4,     0,     0,     0,     6,
       0,     0,     4,     0,     3,     0,     2,     2,     1,     1,
       1,     2,     1,     2,     0,     2,     1,     0,     5,     0,
       4,     0,     1,     2,     2,     0,     1,     0,     3,     0,
       3,     3,     2,     0,     1,     2,     0,     2,     1,     0,
       1,     2,     2,     0,     2,     1,     1,     1,     1,     1,
       0,     4,     4,     1,     1,     1,     1,     1,     0,     1,
       0,     2,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     0,     2,     2,     2,     0,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     0,     1,     1,     2,
       2,     2,     1,     1,     0,     2,     2,     2,     2,     0,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     4,     4,     6,     4,     4,     6,     4,
       4,     4,     4,     1,     7,     0,     1,     2,     0,     1,
       2,     2,     1,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
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
  "WhereClause", "_QIT_WHERE_E_Opt", "_QBindingClause_E_Opt",
  "SolutionModifier", "_QOrderClause_E_Opt", "_QLimitOffsetClauses_E_Opt",
  "LimitOffsetClauses", "_QOffsetClause_E_Opt", "_QLimitClause_E_Opt",
  "_QLimitClause_E_S_QOffsetClause_E_Opt_Or_QOffsetClause_E_S_QLimitClause_E_Opt",
  "OrderClause", "_QOrderCondition_E_Plus", "OrderCondition",
  "_O_QIT_ASC_E_Or_QIT_DESC_E_C",
  "_O_QIT_ASC_E_Or_QIT_DESC_E_S_QBrackettedExpression_E_C",
  "_O_QConstraint_E_Or_QVar_E_C", "LimitClause", "OffsetClause",
  "BindingClause", "@4", "_QBinding_E_Star", "Binding", "@5",
  "_O_QVarOrTerm_E_Or_QIT_NULL_E_C",
  "_Q_O_QVarOrTerm_E_Or_QIT_NULL_E_C_E_Plus", "GroupGraphPattern", "@6",
  "_QTriplesBlock_E_Opt", "_O_QGraphPatternNotTriples_E_Or_QFilter_E_C",
  "_QGT_DOT_E_Opt",
  "_O_QGraphPatternNotTriples_E_Or_QFilter_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGraphPatternNotTriples_E_Or_QFilter_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "TriplesBlock", "_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C_E_Opt", "GraphPatternNotTriples",
  "OptionalGraphPattern", "@7", "@8", "GraphGraphPattern", "@9", "@10",
  "@11", "GroupOrUnionGraphPattern", "@12", "@13",
  "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@14",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star",
  "_O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C",
  "@15", "ConstructTemplate", "@16", "_QConstructTriples_E_Opt",
  "ConstructTriples", "_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C_E_Opt", "TriplesSameSubject",
  "@17", "@18", "PropertyListNotEmpty", "_O_QVerb_E_S_QObjectList_E_C",
  "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "ObjectList",
  "_O_QGT_COMMA_E_S_QObject_E_C", "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star",
  "Object", "Verb", "TriplesNode", "BlankNodePropertyList", "@19",
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
     111,     3,   219,   247,   247,    -1,   111,     4,   247,    -1,
     111,     5,   247,    -1,   111,     6,   247,    -1,   111,     7,
     247,    -1,   111,     8,   257,    -1,   111,     9,   247,    -1,
      -1,   112,   123,    -1,    -1,    10,   247,    -1,   115,   116,
      -1,    -1,   117,    -1,    -1,   116,   118,    -1,    22,    99,
      -1,    -1,    -1,    23,   119,   100,   120,    99,    -1,   219,
      -1,   121,   219,    -1,    -1,   122,   124,    -1,   113,    28,
     186,   122,   129,   132,    -1,    30,   125,    -1,   126,    -1,
     127,    -1,   128,    -1,    31,   128,    -1,   257,    -1,   130,
     154,   131,    -1,    -1,    47,    -1,    -1,   147,    -1,   133,
     134,    -1,    -1,   139,    -1,    -1,   135,    -1,   138,    -1,
      -1,   146,    -1,    -1,   145,    -1,   145,   136,    -1,   146,
     137,    -1,    32,    33,   140,    -1,   141,    -1,   140,   141,
      -1,   143,    -1,   144,    -1,    34,    -1,    35,    -1,   142,
     241,    -1,   179,    -1,   219,    -1,    36,    86,    -1,    37,
      86,    -1,    -1,    38,   121,    44,   148,   149,    45,    -1,
      -1,   149,   150,    -1,    -1,    48,   151,   153,    49,    -1,
     217,    -1,    50,    -1,   152,    -1,   153,   152,    -1,    -1,
      44,   155,   156,   160,    45,    -1,    -1,   161,    -1,   164,
      -1,   178,    -1,    -1,    51,    -1,   157,   158,   156,    -1,
      -1,   160,   159,    -1,   192,   163,    -1,    51,   156,    -1,
      -1,   162,    -1,   165,    -1,   172,    -1,   168,    -1,    -1,
      -1,    52,   166,   167,   154,    -1,    -1,    -1,    -1,    15,
     169,   170,   218,   171,   154,    -1,    -1,    -1,   173,   174,
     154,   177,    -1,    -1,    53,   176,   154,    -1,    -1,   175,
     177,    -1,    54,   179,    -1,   241,    -1,   242,    -1,   180,
      -1,   257,   181,    -1,   184,    -1,    55,   221,    -1,    -1,
     183,   182,    -1,   107,    -1,    -1,    48,   221,   185,   183,
      49,    -1,    -1,    44,   187,   188,    45,    -1,    -1,   189,
      -1,   192,   191,    -1,    51,   188,    -1,    -1,   190,    -1,
      -1,   217,   193,   195,    -1,    -1,   207,   194,   200,    -1,
     206,   202,   199,    -1,   206,   202,    -1,    -1,   196,    -1,
      56,   197,    -1,    -1,   199,   198,    -1,   201,    -1,    -1,
     195,    -1,   205,   204,    -1,    55,   205,    -1,    -1,   204,
     203,    -1,   216,    -1,   218,    -1,    57,    -1,   210,    -1,
     208,    -1,    -1,    58,   209,   195,    59,    -1,   212,    48,
     215,    49,    -1,    39,    -1,    40,    -1,    41,    -1,    42,
      -1,    43,    -1,    -1,   211,    -1,    -1,   213,   216,    -1,
     216,   213,    -1,    -1,   214,    -1,   217,    -1,   207,    -1,
     219,    -1,   220,    -1,   219,    -1,   257,    -1,   104,    -1,
     105,    -1,   257,    -1,   247,    -1,   251,    -1,   255,    -1,
     259,    -1,   107,    -1,   222,    -1,   225,   224,    -1,    60,
     225,    -1,    -1,   224,   223,    -1,   228,   227,    -1,    61,
     228,    -1,    -1,   227,   226,    -1,   229,    -1,   232,   231,
      -1,    62,   232,    -1,    63,   232,    -1,    64,   232,    -1,
      65,   232,    -1,    66,   232,    -1,    67,   232,    -1,    -1,
     230,    -1,   233,    -1,   236,   235,    -1,    68,   236,    -1,
      69,   236,    -1,   253,    -1,   254,    -1,    -1,   235,   234,
      -1,   239,   238,    -1,    27,   239,    -1,    70,   239,    -1,
      -1,   238,   237,    -1,    71,   240,    -1,    68,   240,    -1,
      69,   240,    -1,   240,    -1,   241,    -1,   242,    -1,   245,
      -1,   247,    -1,   251,    -1,   255,    -1,   219,    -1,    48,
     221,    49,    -1,    72,    48,   221,    49,    -1,    73,    48,
     221,    49,    -1,    74,    48,   221,    55,   221,    49,    -1,
      75,    48,   221,    49,    -1,    76,    48,   219,    49,    -1,
      77,    48,   221,    55,   221,    49,    -1,    78,    48,   221,
      49,    -1,    79,    48,   221,    49,    -1,    80,    48,   221,
      49,    -1,    81,    48,   221,    49,    -1,   243,    -1,    82,
      48,   221,    55,   221,   244,    49,    -1,    -1,   182,    -1,
     257,   246,    -1,    -1,   181,    -1,   256,   250,    -1,    83,
     257,    -1,   106,    -1,   248,    -1,    -1,   249,    -1,   252,
      -1,   253,    -1,   254,    -1,    86,    -1,    87,    -1,    88,
      -1,    89,    -1,    90,    -1,    91,    -1,    92,    -1,    93,
      -1,    94,    -1,    84,    -1,    85,    -1,    95,    -1,    97,
      -1,    96,    -1,    98,    -1,    99,    -1,   258,    -1,   101,
      -1,   100,    -1,   102,    -1,   103,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  MapSetParser::yyprhs_[] =
  {
         0,     0,     3,     4,     9,    10,    16,    20,    24,    28,
      32,    36,    40,    41,    44,    45,    48,    51,    52,    54,
      55,    58,    61,    62,    63,    69,    71,    74,    75,    78,
      85,    88,    90,    92,    94,    97,    99,   103,   104,   106,
     107,   109,   112,   113,   115,   116,   118,   120,   121,   123,
     124,   126,   129,   132,   136,   138,   141,   143,   145,   147,
     149,   152,   154,   156,   159,   162,   163,   170,   171,   174,
     175,   180,   182,   184,   186,   189,   190,   196,   197,   199,
     201,   203,   204,   206,   210,   211,   214,   217,   220,   221,
     223,   225,   227,   229,   230,   231,   236,   237,   238,   239,
     246,   247,   248,   253,   254,   258,   259,   262,   265,   267,
     269,   271,   274,   276,   279,   280,   283,   285,   286,   292,
     293,   298,   299,   301,   304,   307,   308,   310,   311,   315,
     316,   320,   324,   327,   328,   330,   333,   334,   337,   339,
     340,   342,   345,   348,   349,   352,   354,   356,   358,   360,
     362,   363,   368,   373,   375,   377,   379,   381,   383,   384,
     386,   387,   390,   393,   394,   396,   398,   400,   402,   404,
     406,   408,   410,   412,   414,   416,   418,   420,   422,   424,
     426,   429,   432,   433,   436,   439,   442,   443,   446,   448,
     451,   454,   457,   460,   463,   466,   469,   470,   472,   474,
     477,   480,   483,   485,   487,   488,   491,   494,   497,   500,
     501,   504,   507,   510,   513,   515,   517,   519,   521,   523,
     525,   527,   529,   533,   538,   543,   550,   555,   560,   567,
     572,   577,   582,   587,   589,   597,   598,   600,   603,   604,
     606,   609,   612,   614,   616,   617,   619,   621,   623,   625,
     627,   629,   631,   633,   635,   637,   639,   641,   643,   645,
     647,   649,   651,   653,   655,   657,   659,   661,   663,   665
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  MapSetParser::yyrline_[] =
  {
         0,   336,   336,   336,   342,   344,   353,   356,   359,   362,
     365,   368,   374,   376,   381,   384,   391,   395,   397,   401,
     403,   407,   413,   415,   413,   425,   429,   437,   440,   448,
     457,   464,   465,   469,   475,   481,   488,   495,   497,   501,
     504,   509,   516,   519,   524,   528,   533,   538,   541,   546,
     549,   554,   558,   566,   573,   577,   585,   587,   595,   598,
     606,   614,   615,   621,   627,   634,   634,   644,   647,   655,
     655,   665,   666,   673,   677,   685,   685,   696,   698,   703,
     704,   708,   710,   715,   719,   722,   727,   732,   736,   739,
     743,   744,   745,   749,   751,   749,   765,   767,   769,   765,
     781,   784,   781,   794,   794,   808,   810,   814,   825,   826,
     827,   831,   838,   845,   851,   853,   860,   864,   864,   874,
     874,   882,   884,   889,   894,   898,   900,   904,   904,   907,
     907,   914,   919,   923,   925,   930,   934,   936,   941,   945,
     947,   952,   957,   961,   963,   967,   974,   978,   985,   986,
     990,   990,  1003,  1028,  1031,  1034,  1037,  1040,  1047,  1050,
    1055,  1058,  1066,  1083,  1086,  1090,  1091,  1095,  1098,  1102,
    1105,  1111,  1112,  1116,  1119,  1122,  1125,  1128,  1129,  1135,
    1140,  1149,  1156,  1159,  1167,  1176,  1183,  1186,  1193,  1198,
    1209,  1212,  1215,  1218,  1221,  1224,  1231,  1235,  1239,  1244,
    1253,  1256,  1259,  1262,  1269,  1272,  1280,  1289,  1292,  1299,
    1302,  1309,  1312,  1315,  1318,  1322,  1323,  1324,  1325,  1328,
    1331,  1334,  1340,  1346,  1349,  1352,  1355,  1358,  1361,  1364,
    1367,  1370,  1373,  1376,  1381,  1388,  1391,  1395,  1405,  1408,
    1413,  1421,  1428,  1432,  1440,  1444,  1448,  1449,  1450,  1454,
    1455,  1456,  1460,  1461,  1462,  1466,  1467,  1468,  1472,  1473,
    1477,  1478,  1479,  1480,  1484,  1485,  1489,  1490,  1494,  1495
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
  const int MapSetParser::yylast_ = 715;
  const int MapSetParser::yynnts_ = 152;
  const int MapSetParser::yyempty_ = -2;
  const int MapSetParser::yyfinal_ = 3;
  const int MapSetParser::yyterror_ = 1;
  const int MapSetParser::yyerrcode_ = 256;
  const int MapSetParser::yyntokens_ = 108;

  const unsigned int MapSetParser::yyuser_token_number_max_ = 362;
  const MapSetParser::token_number_type MapSetParser::yyundef_token_ = 2;

} // namespace w3c_sw

#line 1500 "lib/MapSetParser/MapSetParser.ypp"
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
	curBGP(NULL), curFilter(NULL), 
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


