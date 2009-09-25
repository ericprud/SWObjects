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

#include "SPARQLfedParser.hpp"

/* User implementation prologue.  */
#line 234 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"

#include "../SPARQLfedScanner.hpp"
#line 351 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"

#include "../SPARQLfedScanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc.  */
#line 57 "\\\\vboxsvr\\sparul\\lib\\SPARQLfedParser\\SPARQLfedParser.cpp"

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
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
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
#endif /* ! YYDEBUG */

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


  int
  SPARQLfedParser::parse ()
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
    #line 37 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}
  /* Line 547 of yacc.c.  */
#line 294 "\\\\vboxsvr\\sparul\\lib\\SPARQLfedParser\\SPARQLfedParser.cpp"
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
#line 366 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(2) - (2)].p_Operation);
    ;}
    break;

  case 14:
#line 390 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Replace((yysemantic_stack_[(4) - (2)].p_WhereClause), driver.curOp);
    ;}
    break;

  case 15:
#line 396 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Insert(driver.curOp, (yysemantic_stack_[(3) - (3)].p_WhereClause));
;}
    break;

  case 16:
#line 402 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete(driver.curOp, (yysemantic_stack_[(3) - (3)].p_WhereClause));
    ;}
    break;

  case 17:
#line 408 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(3) - (2)].p_URIs), (yysemantic_stack_[(3) - (3)].p_URI));
    ;}
    break;

  case 18:
#line 414 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(2) - (2)].p_URI));
    ;}
    break;

  case 19:
#line 421 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_URIs) = new ProductionVector<const URI*>((yysemantic_stack_[(1) - (1)].p_URI));
    ;}
    break;

  case 20:
#line 424 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_URIs)->push_back((yysemantic_stack_[(2) - (2)].p_URI));
	(yyval.p_URIs) = (yysemantic_stack_[(2) - (1)].p_URIs);
    ;}
    break;

  case 21:
#line 432 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    ;}
    break;

  case 22:
#line 439 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    ;}
    break;

  case 24:
#line 446 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    ;}
    break;

  case 25:
#line 452 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    ;}
    break;

  case 29:
#line 464 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    ;}
    break;

  case 30:
#line 470 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    ;}
    break;

  case 31:
#line 473 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
;}
    break;

  case 32:
#line 479 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
;}
    break;

  case 38:
#line 502 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI));
    ;}
    break;

  case 39:
#line 508 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	driver.ignorePrefix(true);
      ;}
    break;

  case 40:
#line 510 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	  driver.ignorePrefix(false);
      ;}
    break;

  case 41:
#line 512 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      ;}
    break;

  case 42:
#line 520 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Select((yysemantic_stack_[(6) - (2)].p_distinctness), (yysemantic_stack_[(6) - (3)].p_VarSet), (yysemantic_stack_[(6) - (4)].p_DatasetClauses), (yysemantic_stack_[(6) - (5)].p_WhereClause), (yysemantic_stack_[(6) - (6)].p_SolutionModifier));
    ;}
    break;

  case 43:
#line 527 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    ;}
    break;

  case 44:
#line 530 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    ;}
    break;

  case 45:
#line 537 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    ;}
    break;

  case 47:
#line 545 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_POSList) = new POSList;
	(yyval.p_POSList)->push_back((yysemantic_stack_[(1) - (1)].p_Variable));
    ;}
    break;

  case 48:
#line 549 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSList)->push_back((yysemantic_stack_[(2) - (2)].p_Variable));
	(yyval.p_POSList) = (yysemantic_stack_[(2) - (1)].p_POSList);
    ;}
    break;

  case 49:
#line 557 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_POSList);
    ;}
    break;

  case 50:
#line 560 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    ;}
    break;

  case 51:
#line 567 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    ;}
    break;

  case 52:
#line 570 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    ;}
    break;

  case 53:
#line 578 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	/* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	(yyval.p_Operation) = new Construct((DefaultGraphPattern*)(yysemantic_stack_[(5) - (2)].p_BasicGraphPattern), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    ;}
    break;

  case 54:
#line 586 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    ;}
    break;

  case 55:
#line 593 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_POSList) = new POSList;
	(yyval.p_POSList)->push_back((yysemantic_stack_[(1) - (1)].p_POS));
    ;}
    break;

  case 56:
#line 597 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSList)->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSList) = (yysemantic_stack_[(2) - (1)].p_POSList);
    ;}
    break;

  case 57:
#line 605 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_POSList);
    ;}
    break;

  case 58:
#line 608 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    ;}
    break;

  case 59:
#line 615 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    ;}
    break;

  case 61:
#line 623 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(3) - (2)].p_DatasetClauses), (yysemantic_stack_[(3) - (3)].p_WhereClause));
    ;}
    break;

  case 62:
#line 630 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    ;}
    break;

  case 65:
#line 642 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_POS), driver.posFactory);
    ;}
    break;

  case 66:
#line 648 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_POS), driver.posFactory);
    ;}
    break;

  case 67:
#line 654 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    ;}
    break;

  case 68:
#line 661 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.curOp, (yysemantic_stack_[(3) - (3)].p_BindingClause));
    ;}
    break;

  case 71:
#line 673 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = NULL;
    ;}
    break;

  case 73:
#line 681 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(2) - (1)].p_OrderConditions), (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit, (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset);
    ;}
    break;

  case 74:
#line 688 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    ;}
    break;

  case 76:
#line 696 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    ;}
    break;

  case 79:
#line 710 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    ;}
    break;

  case 81:
#line 718 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    ;}
    break;

  case 83:
#line 726 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    ;}
    break;

  case 84:
#line 730 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    ;}
    break;

  case 85:
#line 738 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    ;}
    break;

  case 86:
#line 745 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    ;}
    break;

  case 87:
#line 749 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    ;}
    break;

  case 89:
#line 759 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    ;}
    break;

  case 90:
#line 767 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    ;}
    break;

  case 91:
#line 770 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    ;}
    break;

  case 92:
#line 778 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 94:
#line 787 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new VarExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    ;}
    break;

  case 95:
#line 793 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    ;}
    break;

  case 96:
#line 799 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    ;}
    break;

  case 97:
#line 806 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	driver.curBindingClause = new BindingClause((yysemantic_stack_[(3) - (2)].p_POSList));
      ;}
    break;

  case 98:
#line 808 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = driver.curBindingClause;
	  driver.curBindingClause = NULL;
      ;}
    break;

  case 99:
#line 816 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Bindings) = NULL;
    ;}
    break;

  case 100:
#line 819 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	driver.curBindingClause->push_back((yysemantic_stack_[(2) - (2)].p_Binding));
	(yyval.p_Bindings) = NULL;
    ;}
    break;

  case 101:
#line 827 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	driver.curBinding = new Binding();
      ;}
    break;

  case 102:
#line 829 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	  (yyval.p_Binding) = driver.curBinding;
	  driver.curBinding = NULL;
      ;}
    break;

  case 104:
#line 838 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = driver.getNULL();
    ;}
    break;

  case 105:
#line 845 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(1) - (1)].p_POS));
	(yyval.p_POSs) = NULL;
    ;}
    break;

  case 106:
#line 849 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSs) = NULL;
    ;}
    break;

  case 107:
#line 857 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	driver.curOp = NULL;
	driver.curBGP = NULL;
      ;}
    break;

  case 108:
#line 860 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      ;}
    break;

  case 118:
#line 899 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      ;}
    break;

  case 119:
#line 902 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
      ;}
    break;

  case 120:
#line 909 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curFilter = NULL;
      ;}
    break;

  case 121:
#line 912 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	  (yyval.p_POS) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_POS);
      ;}
    break;

  case 122:
#line 915 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(5) - (3)].p_POS), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(5) - (4)].p_POS);
      ;}
    break;

  case 133:
#line 956 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      ;}
    break;

  case 134:
#line 958 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	  (yyval.p_FilterHolder) = driver.curFilter;
	  driver.curFilter = new FilterHolder();
      ;}
    break;

  case 135:
#line 961 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	  OptionalGraphPattern* ret = new OptionalGraphPattern(driver.curOp);
	  ((FilterHolder*)driver.curFilter)->copyExpressionsTo(ret); // @@ nasty cast
	  delete driver.curFilter;
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), ret);
	  driver.curFilter = (yysemantic_stack_[(4) - (3)].p_FilterHolder);
      ;}
    break;

  case 136:
#line 971 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      ;}
    break;

  case 137:
#line 973 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	  (yyval.p_FilterHolder) = driver.saveFilter();
      ;}
    break;

  case 138:
#line 975 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	  (yyval.p_POS) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_POS);
      ;}
    break;

  case 139:
#line 978 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_FilterHolder));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_POS), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_POS);
      ;}
    break;

  case 140:
#line 987 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      ;}
    break;

  case 141:
#line 989 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	  (yyval.p_FilterHolder) = driver.saveFilter();
      ;}
    break;

  case 142:
#line 991 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_FilterHolder));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      ;}
    break;

  case 143:
#line 999 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      ;}
    break;

  case 144:
#line 1001 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.curOp);
      ;}
    break;

  case 147:
#line 1013 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    if (driver.curOp == NULL)
		driver.ensureBasicGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 151:
#line 1030 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    ;}
    break;

  case 152:
#line 1037 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = new ArgList((yysemantic_stack_[(1) - (1)].p_Expressions));
    ;}
    break;

  case 153:
#line 1044 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 155:
#line 1052 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 156:
#line 1059 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    ;}
    break;

  case 157:
#line 1063 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      ;}
    break;

  case 158:
#line 1065 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = NULL;
      ;}
    break;

  case 159:
#line 1073 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      ;}
    break;

  case 160:
#line 1075 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      ;}
    break;

  case 167:
#line 1103 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_POS);
    ;}
    break;

  case 169:
#line 1106 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_POS);
    ;}
    break;

  case 185:
#line 1166 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.posFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_POS)));
    ;}
    break;

  case 186:
#line 1173 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_POS);
	driver.curPredicate = (yyval.p_POS);
    ;}
    break;

  case 187:
#line 1177 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_POS);
    ;}
    break;

  case 190:
#line 1189 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      ;}
    break;

  case 191:
#line 1193 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	  (yyval.p_POS) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      ;}
    break;

  case 192:
#line 1202 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
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

  case 193:
#line 1227 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    ;}
    break;

  case 194:
#line 1230 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    ;}
    break;

  case 195:
#line 1233 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    ;}
    break;

  case 196:
#line 1236 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    ;}
    break;

  case 197:
#line 1239 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    ;}
    break;

  case 198:
#line 1246 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    ;}
    break;

  case 200:
#line 1254 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_POSs) = new ProductionVector<const POS*>();
    ;}
    break;

  case 201:
#line 1257 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSs)->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSs) = (yysemantic_stack_[(2) - (1)].p_POSs);
    ;}
    break;

  case 202:
#line 1265 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
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

  case 203:
#line 1282 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_POSs) = new ProductionVector<const POS*>();
    ;}
    break;

  case 207:
#line 1294 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    ;}
    break;

  case 209:
#line 1301 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    ;}
    break;

  case 210:
#line 1304 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    ;}
    break;

  case 213:
#line 1315 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    ;}
    break;

  case 214:
#line 1318 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    ;}
    break;

  case 215:
#line 1321 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    ;}
    break;

  case 216:
#line 1324 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    ;}
    break;

  case 218:
#line 1328 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    ;}
    break;

  case 220:
#line 1339 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    ;}
    break;

  case 221:
#line 1348 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 222:
#line 1355 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    ;}
    break;

  case 223:
#line 1358 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    ;}
    break;

  case 224:
#line 1366 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    ;}
    break;

  case 225:
#line 1375 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 226:
#line 1382 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    ;}
    break;

  case 227:
#line 1385 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    ;}
    break;

  case 229:
#line 1397 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_BooleanComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_BooleanComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_BooleanComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    ;}
    break;

  case 230:
#line 1408 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 231:
#line 1411 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 232:
#line 1414 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 233:
#line 1417 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 234:
#line 1420 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
    (yyval.p_BooleanComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 235:
#line 1423 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 236:
#line 1430 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = NULL;
    ;}
    break;

  case 239:
#line 1443 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    ;}
    break;

  case 240:
#line 1452 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 241:
#line 1455 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 242:
#line 1458 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    ;}
    break;

  case 243:
#line 1461 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    ;}
    break;

  case 244:
#line 1468 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    ;}
    break;

  case 245:
#line 1471 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    ;}
    break;

  case 246:
#line 1479 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    ;}
    break;

  case 247:
#line 1488 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 248:
#line 1491 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 249:
#line 1498 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    ;}
    break;

  case 250:
#line 1501 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    ;}
    break;

  case 251:
#line 1508 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 252:
#line 1511 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 253:
#line 1514 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 258:
#line 1524 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new LiteralExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    ;}
    break;

  case 259:
#line 1527 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    ;}
    break;

  case 260:
#line 1530 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    ;}
    break;

  case 261:
#line 1533 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new VarExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    ;}
    break;

  case 262:
#line 1539 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    ;}
    break;

  case 263:
#line 1545 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-str"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 264:
#line 1548 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-lang"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 265:
#line 1551 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-langMatches"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    ;}
    break;

  case 266:
#line 1554 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-datatype"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 267:
#line 1557 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-bound"), new VarExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    ;}
    break;

  case 268:
#line 1560 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-sameTerm"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    ;}
    break;

  case 269:
#line 1563 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 270:
#line 1566 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 271:
#line 1569 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isBlank"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 272:
#line 1572 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isLiteral"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 274:
#line 1580 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-regex"), (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    ;}
    break;

  case 275:
#line 1587 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    ;}
    break;

  case 277:
#line 1594 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new URIExpression((yysemantic_stack_[(2) - (1)].p_URI));
    ;}
    break;

  case 278:
#line 1604 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    ;}
    break;

  case 280:
#line 1612 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    ;}
    break;

  case 281:
#line 1620 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    ;}
    break;

  case 282:
#line 1627 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    ;}
    break;

  case 283:
#line 1631 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    ;}
    break;

  case 284:
#line 1639 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    ;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 1773 "\\\\vboxsvr\\sparul\\lib\\SPARQLfedParser\\SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -274;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        13,   -61,    54,   266,  -274,  -274,  -274,  -274,    32,    41,
      41,    56,    77,    82,    82,    97,    67,    33,  -274,  -274,
    -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,
    -274,  -274,  -274,    90,  -274,   103,    83,  -274,    20,    20,
    -274,  -274,  -274,    25,  -274,  -274,    56,  -274,  -274,  -274,
      77,    77,  -274,  -274,  -274,    -7,  -274,  -274,  -274,  -274,
    -274,    95,  -274,  -274,  -274,  -274,     3,  -274,  -274,    41,
    -274,    91,   355,  -274,  -274,  -274,    56,  -274,  -274,  -274,
    -274,  -274,  -274,  -274,    37,  -274,  -274,   355,     3,  -274,
       1,    44,  -274,  -274,    31,  -274,   355,    37,  -274,  -274,
    -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,
    -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,
    -274,  -274,  -274,  -274,  -274,  -274,    85,  -274,  -274,  -274,
    -274,   102,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,
    -274,   -54,  -274,  -274,  -274,  -274,     3,   114,  -274,   124,
     148,   148,    56,  -274,  -274,  -274,  -274,  -274,  -274,  -274,
     -18,    47,   133,   355,  -274,  -274,    47,   379,    47,    56,
    -274,  -274,  -274,  -274,   148,  -274,   355,  -274,  -274,   160,
    -274,   125,  -274,  -274,  -274,    98,     9,  -274,  -274,   152,
     472,  -274,  -274,   163,   201,  -274,  -274,  -274,  -274,  -274,
    -274,  -274,   168,  -274,  -274,  -274,  -274,  -274,  -274,   300,
     135,   136,  -274,  -274,  -274,   182,   187,  -274,  -274,  -274,
    -274,   659,   163,  -274,  -274,  -274,  -274,  -274,  -274,  -274,
    -274,  -274,  -274,  -274,  -274,  -274,   355,    95,  -274,   448,
    -274,  -274,   589,   177,   178,   180,   181,   189,   190,   195,
     202,   205,   206,   207,   300,  -274,   208,  -274,  -274,  -274,
    -274,  -274,  -274,  -274,  -274,   -29,  -274,  -274,  -274,  -274,
    -274,  -274,  -274,  -274,  -274,   355,    83,    72,   174,   209,
    -274,  -274,  -274,   624,   624,   624,  -274,   211,  -274,  -274,
    -274,  -274,   105,  -274,  -274,  -274,  -274,  -274,  -274,  -274,
    -274,  -274,  -274,   -29,   589,   589,   589,   589,    37,   589,
     589,   589,   589,   589,   589,  -274,  -274,   589,  -274,  -274,
    -274,    95,    83,  -274,   204,  -274,  -274,  -274,    47,  -274,
     472,  -274,    41,  -274,  -274,  -274,  -274,   203,   210,   589,
     589,   589,   589,   589,   589,  -274,  -274,   318,    -5,  -274,
    -274,   213,   217,   212,   220,   224,   219,   229,   232,   234,
     237,   233,  -274,  -274,  -274,  -274,   204,  -274,   504,  -274,
    -274,   472,  -274,  -274,   589,  -274,   589,  -274,  -274,  -274,
    -274,  -274,  -274,  -274,   589,   589,  -274,  -274,  -274,   589,
     589,  -274,  -274,  -274,   589,  -274,  -274,   589,  -274,  -274,
    -274,  -274,   589,  -274,    83,    83,  -274,  -274,  -274,   531,
    -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,   240,   242,
     238,    17,  -274,  -274,  -274,  -274,  -274,  -274,   589,  -274,
     243,  -274,  -274,  -274,  -274
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  SPARQLfedParser::yydefact_[] =
  {
        34,     0,     0,     0,    36,    35,    38,     1,    69,     0,
       0,     0,    25,    30,    30,    45,     0,     0,    51,     2,
       8,     7,    10,    11,    12,    13,     9,    27,    28,     3,
       4,     5,     6,    33,    70,     0,     0,   118,    59,    59,
     304,   307,   306,    22,    19,   305,     0,    26,    18,    31,
       0,     0,    43,    44,    46,     0,   159,    51,    58,   211,
     212,    57,    51,    55,   209,   210,    69,    39,    37,     0,
     107,    71,   109,    16,    60,    15,     0,    23,    17,    20,
      24,    29,    32,    50,    49,    51,    47,   161,    69,    56,
      59,     0,    52,    61,     0,    14,   109,     0,    68,    72,
     193,   194,   195,   196,   197,   190,   298,   299,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   300,   302,   301,
     303,   308,   309,   218,   124,   110,   128,   169,   189,   188,
     199,     0,   167,   207,   208,   214,   215,   286,   287,   288,
     216,   284,   213,   217,    21,    48,    69,     0,   162,   165,
      74,    74,     0,    62,    63,    64,    65,    67,    40,   116,
       0,     0,   120,   109,   129,   126,   179,   198,     0,     0,
     282,   283,   285,   280,    74,   160,   161,   166,   163,     0,
      53,    76,    75,    54,    66,     0,   140,    97,   187,     0,
     198,   186,   119,   113,     0,   125,   127,   180,   170,   178,
     206,   204,     0,   200,   205,   168,   281,    42,   164,     0,
       0,     0,    73,    77,    78,    79,    81,    41,   136,   108,
     133,     0,   113,   117,   111,   130,   132,   131,   141,   112,
      99,   191,   176,   183,   185,   114,   109,     0,   192,   198,
      90,    91,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    85,    86,     0,    88,    89,    93,
     150,    94,   148,   149,   273,     0,    95,    96,    83,    80,
      84,    82,   137,   134,   147,   109,     0,     0,   171,   181,
     123,   121,   201,     0,     0,     0,   261,     0,   219,   222,
     226,   228,   236,   238,   244,   249,   254,   255,   256,   257,
     258,   259,   260,   278,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,    92,     0,   156,   151,
     152,     0,     0,   115,   145,    98,   101,   100,   173,   177,
     198,   184,     0,   252,   253,   251,   262,   220,   224,     0,
       0,     0,     0,     0,     0,   237,   229,   239,   246,   279,
     277,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   157,   138,   135,   143,   145,   142,     0,   174,
     175,   198,   182,   122,     0,   223,     0,   227,   230,   231,
     232,   233,   234,   235,     0,     0,   245,   242,   243,     0,
       0,   250,   263,   264,     0,   266,   267,     0,   269,   270,
     271,   272,     0,   154,     0,     0,   146,   104,   105,     0,
     103,   172,   221,   225,   240,   241,   247,   248,     0,     0,
     275,     0,   139,   144,   102,   106,   265,   268,     0,   276,
       0,   158,   155,   153,   274
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,
    -274,  -274,   146,  -274,  -274,  -274,   274,  -274,  -274,  -274,
    -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,   199,  -274,
       6,  -274,  -274,  -274,  -274,   -17,  -274,  -274,  -274,  -274,
    -274,   145,     0,  -274,  -274,  -112,  -274,  -274,  -274,  -274,
    -274,  -274,  -274,  -274,    45,  -274,  -274,  -274,    86,    92,
    -274,  -274,  -274,  -274,  -274,  -103,  -274,  -273,  -274,   -91,
    -274,    87,  -274,  -274,    -9,  -274,  -274,  -274,  -274,  -274,
    -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,
    -274,  -274,  -274,  -274,  -274,  -274,  -274,   -53,  -274,    93,
    -274,    12,  -109,  -274,  -274,  -274,  -274,  -274,   140,  -274,
    -274,  -274,   -74,  -274,  -274,  -121,  -274,  -274,  -274,  -274,
    -274,  -274,   -51,  -274,  -274,   -12,    -3,  -147,  -274,  -274,
    -274,  -274,  -274,  -274,  -274,  -274,  -157,  -152,   -10,    14,
    -274,   -73,  -274,  -274,  -274,   -46,  -274,  -274,   -45,  -274,
    -274,  -274,   -49,  -274,  -274,  -274,  -185,  -274,  -274,  -188,
     -90,  -173,  -180,  -274,  -274,  -274,  -274,   -70,  -274,  -274,
    -274,   -68,  -274,   -15,   -14,   -63,  -274,   -11,  -274,  -274
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,    19,    20,    21,    22,    23,    24,    25,    43,
      77,    78,    47,    48,    26,    27,    50,    28,     3,     4,
      33,     5,    68,    94,   185,    29,    54,    55,    84,    85,
      66,    30,    31,    61,    62,    73,    32,    92,   153,   154,
     155,   156,    74,    36,    98,   180,   181,   212,   213,   268,
     270,   214,   182,   254,   255,   256,   257,   258,   215,   216,
      99,   230,   277,   327,   368,   408,   409,    71,    96,   124,
     222,   236,   223,   186,    38,    72,   193,   194,   332,   195,
     162,   125,   164,   165,   224,   225,   273,   322,   226,   272,
     321,   404,   227,   228,   276,   366,   405,   367,   229,   259,
     260,   319,   429,   421,   320,   403,    57,    87,   147,   148,
     177,   178,   126,   168,   166,   189,   369,   370,   329,   278,
     198,   199,   232,   331,   279,   233,   190,   127,   128,   161,
     129,   130,   131,   239,   201,   202,   234,   132,   191,   286,
     134,   287,   288,   375,   337,   289,   377,   338,   290,   291,
     345,   346,   292,   293,   386,   347,   294,   391,   348,   295,
     296,   297,   298,   264,   430,   299,   350,   300,   171,   172,
     173,   301,   137,   138,   139,   302,   141,   303,    45,   143
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int SPARQLfedParser::yytable_ninf_ = -204;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        44,    39,   135,   324,   136,   159,    65,    63,    35,   140,
     203,   317,    83,   149,   389,   204,   218,   135,   187,   136,
     200,   169,    75,    91,   140,    91,   135,     1,   136,   263,
       6,    64,    79,   140,    76,    80,   262,   -69,   204,   183,
      34,   263,    34,   200,   170,   197,   219,   205,   262,   364,
      65,    89,    58,   220,     7,   221,   -69,   390,   431,    34,
      95,   142,   207,    88,   428,   144,    93,   152,    90,    86,
     318,    34,   196,   151,   263,    64,   142,    37,    59,    60,
     157,   262,   282,   316,    46,   142,   133,   204,   150,    59,
      60,   146,   200,   135,    49,   136,   188,   135,   145,   136,
     140,   133,   149,    56,   140,    67,   135,    69,   136,   325,
     133,    86,   326,   140,    52,    53,    40,    41,    42,    70,
     135,    97,   136,   158,    40,    41,    42,   140,   163,    59,
      60,   422,   423,    59,    60,    40,    41,    42,    40,    41,
      42,   157,   167,    59,    60,   280,   174,    40,    41,    42,
      65,   175,   142,   210,   211,    65,   142,    65,   206,   339,
     340,   341,   342,   343,   344,   142,   135,   176,   136,   135,
     192,   136,   179,   140,   145,    64,   140,   133,   204,   142,
      64,   133,    64,   200,   323,   209,    40,    41,    42,   217,
     133,    59,    60,   333,   334,   335,    81,    82,   265,   414,
     415,   416,   417,   231,   133,   135,   235,   136,   237,   238,
     265,   211,   140,   266,   267,   210,   410,   304,   305,   204,
     306,   307,   328,   261,   200,   142,    65,   281,   142,   308,
     309,   351,   352,   353,   354,   310,   356,   357,   358,   359,
     360,   361,   311,   265,   362,   312,   313,   314,   242,   365,
     133,    64,   336,   133,   392,   374,   330,   410,   393,   394,
     135,   395,   136,   376,   142,   396,   397,   140,   261,     8,
     398,     9,    10,   399,    11,   400,    12,    13,   401,    14,
     402,   426,    15,   427,   434,   428,    16,    17,    51,   133,
     378,   379,   380,   381,   382,   383,   160,   184,   135,   315,
     136,   135,   271,   136,    18,   140,   425,   269,   140,   275,
      65,   363,   432,   406,   274,   349,   208,    65,   372,   142,
     411,   418,   355,   373,   419,   371,   240,   241,   412,   420,
       0,   413,   387,   388,     0,    64,     0,     0,     0,   135,
     242,   136,    64,     0,   133,     0,   140,     0,     0,     0,
       0,     0,     0,     0,     0,   433,     0,   142,     0,     0,
     142,     0,     0,     0,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,     0,     0,     0,   384,   385,
       0,     0,   133,     0,     0,   133,   100,   101,   102,   103,
     104,    40,    41,    42,     0,  -198,    59,    60,   142,   111,
     112,   113,   114,   115,   116,   105,     0,     0,     0,     0,
     100,   101,   102,   103,   104,     0,     0,     0,     0,     0,
    -203,     0,     0,   133,     0,     0,     0,     0,     0,   105,
       0,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    40,    41,    42,   121,
     122,    59,    60,     0,   123,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      40,    41,    42,   121,   122,    59,    60,     0,   123,   100,
     101,   102,   103,   104,     0,     0,     0,     0,     0,  -202,
       0,     0,     0,     0,     0,     0,     0,     0,   105,     0,
       0,     0,     0,   100,   101,   102,   103,   104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   105,     0,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    40,
      41,    42,   121,   122,    59,    60,   407,   123,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    40,    41,    42,   121,   122,    59,    60,
       0,   123,   424,   407,     0,     0,     0,     0,     0,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    40,    41,    42,   121,   122,
      59,    60,     0,   123,     0,     0,     0,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    40,    41,    42,   121,   122,    59,    60,   242,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   283,
     284,     0,   285,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   242,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      40,    41,    42,     0,     0,    59,    60,     0,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   242,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    40,    41,    42,     0,     0,
      59,    60,     0,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      40,    41,    42
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        11,    10,    72,   276,    72,    96,    17,    17,     8,    72,
     167,    40,    19,    87,    19,   167,     7,    87,    36,    87,
     167,    75,    39,    22,    87,    22,    96,    14,    96,   209,
      91,    17,    43,    96,     9,    46,   209,    36,   190,   151,
      39,   221,    39,   190,    98,   166,    37,   168,   221,   322,
      61,    61,    19,    44,     0,    46,    36,    62,    41,    39,
      69,    72,   174,    57,    47,    76,    66,    23,    62,    55,
      99,    39,   163,    90,   254,    61,    87,    36,    96,    97,
      91,   254,   239,   256,     7,    96,    72,   239,    88,    96,
      97,    85,   239,   163,    12,   163,    49,   167,    84,   167,
     163,    87,   176,    36,   167,    15,   176,     4,   176,    37,
      96,    97,    40,   176,    17,    18,    91,    92,    93,    36,
     190,    30,   190,    92,    91,    92,    93,   190,    43,    96,
      97,   404,   405,    96,    97,    91,    92,    93,    91,    92,
      93,   152,    40,    96,    97,   236,   146,    91,    92,    93,
     161,    37,   163,    28,    29,   166,   167,   168,   169,    54,
      55,    56,    57,    58,    59,   176,   236,    43,   236,   239,
      37,   239,    24,   236,   160,   161,   239,   163,   330,   190,
     166,   167,   168,   330,   275,    25,    91,    92,    93,    91,
     176,    96,    97,   283,   284,   285,    50,    51,   209,   384,
     385,   389,   390,    51,   190,   275,    43,   275,     7,    41,
     221,    29,   275,    78,    78,    28,   368,    40,    40,   371,
      40,    40,    48,   209,   371,   236,   237,   237,   239,    40,
      40,   304,   305,   306,   307,    40,   309,   310,   311,   312,
     313,   314,    40,   254,   317,    40,    40,    40,    40,    45,
     236,   237,    41,   239,    41,    52,    47,   409,    41,    47,
     330,    41,   330,    53,   275,    41,    47,   330,   254,     3,
      41,     5,     6,    41,     8,    41,    10,    11,    41,    13,
      47,    41,    16,    41,    41,    47,    20,    21,    14,   275,
     339,   340,   341,   342,   343,   344,    97,   152,   368,   254,
     368,   371,   216,   371,    38,   368,   409,   215,   371,   222,
     321,   321,   421,   366,   221,   303,   176,   328,   330,   330,
     371,   394,   308,   332,   397,   328,    26,    27,   374,   402,
      -1,   376,   347,   347,    -1,   321,    -1,    -1,    -1,   409,
      40,   409,   328,    -1,   330,    -1,   409,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   428,    -1,   368,    -1,    -1,
     371,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    -1,    -1,    -1,    60,    61,
      -1,    -1,   368,    -1,    -1,   371,    31,    32,    33,    34,
      35,    91,    92,    93,    -1,    40,    96,    97,   409,    81,
      82,    83,    84,    85,    86,    50,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      41,    -1,    -1,   409,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    -1,    99,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    -1,    99,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    42,    99,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      -1,    99,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    -1,    99,    -1,    -1,    -1,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    40,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    -1,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    40,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    -1,    96,    97,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    40,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    -1,
      96,    97,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    92,    93
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLfedParser::yystos_[] =
  {
         0,    14,   101,   118,   119,   121,    91,     0,     3,     5,
       6,     8,    10,    11,    13,    16,    20,    21,    38,   102,
     103,   104,   105,   106,   107,   108,   114,   115,   117,   125,
     131,   132,   136,   120,    39,   142,   143,    36,   174,   174,
      91,    92,    93,   109,   277,   278,     7,   112,   113,    12,
     116,   116,    17,    18,   126,   127,    36,   206,    19,    96,
      97,   133,   134,   238,   239,   277,   130,    15,   122,     4,
      36,   167,   175,   135,   142,   135,     9,   110,   111,   277,
     277,   112,   112,    19,   128,   129,   239,   207,   130,   238,
     130,    22,   137,   142,   123,   174,   168,    30,   144,   160,
      31,    32,    33,    34,    35,    50,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    94,    95,    99,   169,   181,   212,   227,   228,   230,
     231,   232,   237,   239,   240,   267,   271,   272,   273,   274,
     275,   276,   277,   279,   277,   239,   130,   208,   209,   212,
     142,   135,    23,   138,   139,   140,   141,   277,    92,   169,
     128,   229,   180,    43,   182,   183,   214,    40,   213,    75,
      98,   268,   269,   270,   142,    37,    43,   210,   211,    24,
     145,   146,   152,   145,   141,   124,   173,    36,    49,   215,
     226,   238,    37,   176,   177,   179,   169,   215,   220,   221,
     227,   234,   235,   236,   237,   215,   277,   145,   208,    25,
      28,    29,   147,   148,   151,   158,   159,    91,     7,    37,
      44,    46,   170,   172,   184,   185,   188,   192,   193,   198,
     161,    51,   222,   225,   236,    43,   171,     7,    41,   233,
      26,    27,    40,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,   153,   154,   155,   156,   157,   199,
     200,   239,   261,   262,   263,   277,    78,    78,   149,   159,
     150,   158,   189,   186,   199,   171,   194,   162,   219,   224,
     169,   238,   236,    60,    61,    63,   239,   241,   242,   245,
     248,   249,   252,   253,   256,   259,   260,   261,   262,   265,
     267,   271,   275,   277,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,   154,   261,    40,    99,   201,
     204,   190,   187,   169,   167,    37,    40,   163,    48,   218,
      47,   223,   178,   260,   260,   260,    41,   244,   247,    54,
      55,    56,    57,    58,    59,   250,   251,   255,   258,   201,
     266,   241,   241,   241,   241,   239,   241,   241,   241,   241,
     241,   241,   241,   238,   167,    45,   195,   197,   164,   216,
     217,   226,   225,   174,    52,   243,    53,   246,   252,   252,
     252,   252,   252,   252,    60,    61,   254,   273,   274,    19,
      62,   257,    41,    41,    47,    41,    41,    47,    41,    41,
      41,    41,    47,   205,   191,   196,   197,    42,   165,   166,
     237,   222,   245,   248,   256,   256,   259,   259,   241,   241,
     241,   203,   167,   167,    41,   165,    41,    41,    47,   202,
     264,    41,   202,   241,    41
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
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  SPARQLfedParser::yyr1_[] =
  {
         0,   100,   101,   102,   102,   102,   102,   102,   102,   102,
     103,   103,   103,   103,   104,   105,   106,   107,   108,   109,
     109,   110,   111,   111,   112,   113,   113,   114,   114,   115,
     116,   116,   117,   118,   119,   119,   120,   120,   121,   123,
     124,   122,   125,   126,   126,   127,   127,   128,   128,   129,
     129,   130,   130,   131,   132,   133,   133,   134,   134,   135,
     135,   136,   137,   138,   138,   139,   140,   141,   142,   143,
     143,   144,   144,   145,   146,   146,   147,   147,   148,   149,
     149,   150,   150,   151,   151,   152,   153,   153,   154,   154,
     155,   155,   156,   157,   157,   158,   159,   161,   160,   162,
     162,   164,   163,   165,   165,   166,   166,   168,   167,   169,
     169,   170,   170,   171,   171,   172,   173,   173,   175,   174,
     177,   178,   176,   179,   180,   180,   181,   182,   183,   183,
     184,   184,   184,   186,   187,   185,   189,   190,   191,   188,
     193,   194,   192,   196,   195,   197,   197,   198,   199,   199,
     199,   200,   201,   202,   203,   203,   204,   205,   204,   207,
     206,   208,   208,   209,   210,   211,   211,   213,   212,   214,
     212,   215,   216,   217,   217,   218,   219,   219,   220,   221,
     221,   222,   223,   224,   224,   225,   226,   226,   227,   227,
     229,   228,   230,   231,   231,   231,   231,   231,   232,   232,
     233,   233,   234,   235,   235,   236,   236,   237,   237,   238,
     238,   239,   239,   240,   240,   240,   240,   240,   240,   241,
     242,   243,   244,   244,   245,   246,   247,   247,   248,   249,
     250,   250,   250,   250,   250,   250,   251,   251,   252,   253,
     254,   254,   254,   254,   255,   255,   256,   257,   257,   258,
     258,   259,   259,   259,   259,   260,   260,   260,   260,   260,
     260,   260,   261,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   263,   264,   264,   265,   266,   266,
     267,   268,   269,   269,   270,   270,   271,   271,   271,   272,
     272,   272,   273,   273,   273,   274,   274,   274,   275,   275,
     276,   276,   276,   276,   277,   277,   278,   278,   279,   279
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  SPARQLfedParser::yyr2_[] =
  {
         0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     3,     3,     3,     2,     1,
       2,     2,     0,     1,     2,     0,     1,     1,     1,     3,
       0,     1,     3,     2,     0,     1,     0,     2,     2,     0,
       0,     5,     6,     1,     1,     0,     1,     1,     2,     1,
       1,     0,     2,     5,     5,     1,     2,     1,     1,     0,
       1,     3,     2,     1,     1,     1,     2,     1,     3,     0,
       1,     0,     1,     2,     0,     1,     0,     1,     1,     0,
       1,     0,     1,     2,     2,     3,     1,     2,     1,     1,
       1,     1,     2,     1,     1,     2,     2,     0,     6,     0,
       2,     0,     4,     1,     1,     1,     2,     0,     5,     0,
       1,     1,     1,     0,     1,     3,     0,     2,     0,     5,
       0,     0,     5,     3,     0,     2,     2,     2,     0,     1,
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
  const SPARQLfedParser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "IT_REPLACE", "IT_WITH",
  "IT_DELETE", "IT_INSERT", "IT_GRAPH", "IT_LOAD", "IT_INTO", "IT_CLEAR",
  "IT_CREATE", "IT_SILENT", "IT_DROP", "IT_BASE", "IT_PREFIX", "IT_SELECT",
  "IT_DISTINCT", "IT_REDUCED", "GT_TIMES", "IT_CONSTRUCT", "IT_DESCRIBE",
  "IT_FROM", "IT_NAMED", "IT_ORDER", "IT_BY", "IT_ASC", "IT_DESC",
  "IT_LIMIT", "IT_OFFSET", "IT_BINDINGS", "IT_MEMBERS", "IT_STARTS",
  "IT_ENDS", "IT_ANY", "IT_UNORDERED", "GT_LCURLEY", "GT_RCURLEY",
  "IT_ASK", "IT_WHERE", "GT_LPAREN", "GT_RPAREN", "IT_NULL", "GT_DOT",
  "IT_OPTIONAL", "IT_UNION", "IT_FILTER", "GT_COMMA", "GT_SEMI", "IT_a",
  "GT_LBRACKET", "GT_RBRACKET", "GT_OR", "GT_AND", "GT_EQUAL", "GT_NEQUAL",
  "GT_LT", "GT_GT", "GT_LE", "GT_GE", "GT_PLUS", "GT_MINUS", "GT_DIVIDE",
  "GT_NOT", "IT_STR", "IT_LANG", "IT_LANGMATCHES", "IT_DATATYPE",
  "IT_BOUND", "IT_sameTerm", "IT_isIRI", "IT_isURI", "IT_isBLANK",
  "IT_isLITERAL", "IT_REGEX", "GT_DTYPE", "IT_true", "IT_false", "INTEGER",
  "DECIMAL", "DOUBLE", "INTEGER_POSITIVE", "DECIMAL_POSITIVE",
  "DOUBLE_POSITIVE", "INTEGER_NEGATIVE", "DECIMAL_NEGATIVE",
  "DOUBLE_NEGATIVE", "STRING_LITERAL1", "STRING_LITERAL_LONG1",
  "STRING_LITERAL2", "STRING_LITERAL_LONG2", "IRI_REF", "PNAME_NS",
  "PNAME_LN", "BLANK_NODE_LABEL", "ANON", "VAR1", "VAR2", "LANGTAG", "NIL",
  "$accept", "Query",
  "_O_QSelect_E_Or_QConstruct_E_Or_QDescribe_E_Or_QAsk_E_Or_QReplace_E_Or_QUpdate_E_Or_QManage_E_C",
  "Update", "Replace", "Insert", "Delete", "Load", "Clear",
  "_QIRIref_E_Plus", "_O_QIT_INTO_E_S_QIRIref_E_C",
  "_Q_O_QIT_INTO_E_S_QIRIref_E_C_E_Opt", "GraphIRI", "_QGraphIRI_E_Opt",
  "Manage", "Create", "_QIT_SILENT_E_Opt", "Drop", "Prologue",
  "_QBaseDecl_E_Opt", "_QPrefixDecl_E_Star", "BaseDecl", "PrefixDecl",
  "@1", "@2", "Select", "_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C",
  "_Q_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C_E_Opt", "_QVar_E_Plus",
  "_O_QVar_E_Plus_Or_QGT_TIMES_E_C", "_QDatasetClause_E_Star", "Construct",
  "Describe", "_QVarOrIRIref_E_Plus",
  "_O_QVarOrIRIref_E_Plus_Or_QGT_TIMES_E_C", "_QWhereClause_E_Opt", "Ask",
  "DatasetClause", "_O_QDefaultGraphClause_E_Or_QNamedGraphClause_E_C",
  "DefaultGraphClause", "NamedGraphClause", "SourceSelector",
  "WhereClause", "_QIT_WHERE_E_Opt", "_QBindingClause_E_Opt",
  "SolutionModifier", "_QOrderClause_E_Opt", "_QLimitOffsetClauses_E_Opt",
  "LimitOffsetClauses", "_QOffsetClause_E_Opt", "_QLimitClause_E_Opt",
  "_QLimitClause_E_S_QOffsetClause_E_Opt_Or_QOffsetClause_E_S_QLimitClause_E_Opt",
  "OrderClause", "_QOrderCondition_E_Plus", "OrderCondition",
  "_O_QIT_ASC_E_Or_QIT_DESC_E_C",
  "_O_QIT_ASC_E_Or_QIT_DESC_E_S_QBrackettedExpression_E_C",
  "_O_QConstraint_E_Or_QVar_E_C", "LimitClause", "OffsetClause",
  "BindingClause", "@3", "_QBinding_E_Star", "Binding", "@4",
  "_O_QVarOrTerm_E_Or_QIT_NULL_E_C",
  "_Q_O_QVarOrTerm_E_Or_QIT_NULL_E_C_E_Plus", "GroupGraphPattern", "@5",
  "_QTriplesBlock_E_Opt", "_O_QGraphPatternNotTriples_E_Or_QFilter_E_C",
  "_QGT_DOT_E_Opt",
  "_O_QGraphPatternNotTriples_E_Or_QFilter_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGraphPatternNotTriples_E_Or_QFilter_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "GraphTemplate", "@6",
  "_O_QIT_GRAPH_E_S_QVarOrIRIref_E_S_QGraphTemplate_E_C", "@7", "@8",
  "_O_QIT_GRAPH_E_S_QVarOrIRIref_E_S_QGraphTemplate_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QIT_GRAPH_E_S_QVarOrIRIref_E_S_QGraphTemplate_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "TriplesBlock", "_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C_E_Opt", "GraphPatternNotTriples",
  "OptionalGraphPattern", "@9", "@10", "GraphGraphPattern", "@11", "@12",
  "@13", "GroupOrUnionGraphPattern", "@14", "@15",
  "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@16",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star",
  "_O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C",
  "@17", "ConstructTemplate", "@18", "_QConstructTriples_E_Opt",
  "ConstructTriples", "_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C_E_Opt", "TriplesSameSubject",
  "@19", "@20", "PropertyListNotEmpty", "_O_QVerb_E_S_QObjectList_E_C",
  "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "ObjectList",
  "_O_QGT_COMMA_E_S_QObject_E_C", "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star",
  "Object", "Verb", "TriplesNode", "BlankNodePropertyList", "@21",
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
  const SPARQLfedParser::rhs_number_type
  SPARQLfedParser::yyrhs_[] =
  {
       101,     0,    -1,   118,   102,    -1,   125,    -1,   131,    -1,
     132,    -1,   136,    -1,   104,    -1,   103,    -1,   114,    -1,
     105,    -1,   106,    -1,   107,    -1,   108,    -1,     3,   142,
       4,   174,    -1,     6,   174,   135,    -1,     5,   174,   135,
      -1,     8,   109,   111,    -1,    10,   113,    -1,   277,    -1,
     109,   277,    -1,     9,   277,    -1,    -1,   110,    -1,     7,
     277,    -1,    -1,   112,    -1,   115,    -1,   117,    -1,    11,
     116,   112,    -1,    -1,    12,    -1,    13,   116,   112,    -1,
     119,   120,    -1,    -1,   121,    -1,    -1,   120,   122,    -1,
      14,    91,    -1,    -1,    -1,    15,   123,    92,   124,    91,
      -1,    16,   127,   129,   130,   142,   145,    -1,    17,    -1,
      18,    -1,    -1,   126,    -1,   239,    -1,   128,   239,    -1,
     128,    -1,    19,    -1,    -1,   130,   137,    -1,    20,   206,
     130,   142,   145,    -1,    21,   134,   130,   135,   145,    -1,
     238,    -1,   133,   238,    -1,   133,    -1,    19,    -1,    -1,
     142,    -1,    38,   130,   142,    -1,    22,   138,    -1,   139,
      -1,   140,    -1,   141,    -1,    23,   141,    -1,   277,    -1,
     143,   167,   144,    -1,    -1,    39,    -1,    -1,   160,    -1,
     146,   147,    -1,    -1,   152,    -1,    -1,   148,    -1,   151,
      -1,    -1,   159,    -1,    -1,   158,    -1,   158,   149,    -1,
     159,   150,    -1,    24,    25,   153,    -1,   154,    -1,   153,
     154,    -1,   156,    -1,   157,    -1,    26,    -1,    27,    -1,
     155,   261,    -1,   199,    -1,   239,    -1,    28,    78,    -1,
      29,    78,    -1,    -1,    30,   128,    36,   161,   162,    37,
      -1,    -1,   162,   163,    -1,    -1,    40,   164,   166,    41,
      -1,   237,    -1,    42,    -1,   165,    -1,   166,   165,    -1,
      -1,    36,   168,   169,   173,    37,    -1,    -1,   181,    -1,
     184,    -1,   198,    -1,    -1,    43,    -1,   170,   171,   169,
      -1,    -1,   173,   172,    -1,    -1,    36,   175,   169,   180,
      37,    -1,    -1,    -1,   177,     7,   238,   178,   174,    -1,
     176,   171,   169,    -1,    -1,   180,   179,    -1,   212,   183,
      -1,    43,   169,    -1,    -1,   182,    -1,   185,    -1,   192,
      -1,   188,    -1,    -1,    -1,    44,   186,   187,   167,    -1,
      -1,    -1,    -1,     7,   189,   190,   238,   191,   167,    -1,
      -1,    -1,   193,   194,   167,   197,    -1,    -1,    45,   196,
     167,    -1,    -1,   195,   197,    -1,    46,   199,    -1,   261,
      -1,   262,    -1,   200,    -1,   277,   201,    -1,   204,    -1,
      47,   241,    -1,    -1,   203,   202,    -1,    99,    -1,    -1,
      40,   241,   205,   203,    41,    -1,    -1,    36,   207,   208,
      37,    -1,    -1,   209,    -1,   212,   211,    -1,    43,   208,
      -1,    -1,   210,    -1,    -1,   237,   213,   215,    -1,    -1,
     227,   214,   220,    -1,   226,   222,   219,    -1,   226,   222,
      -1,    -1,   216,    -1,    48,   217,    -1,    -1,   219,   218,
      -1,   221,    -1,    -1,   215,    -1,   225,   224,    -1,    47,
     225,    -1,    -1,   224,   223,    -1,   236,    -1,   238,    -1,
      49,    -1,   230,    -1,   228,    -1,    -1,    50,   229,   215,
      51,    -1,   232,    40,   235,    41,    -1,    31,    -1,    32,
      -1,    33,    -1,    34,    -1,    35,    -1,    -1,   231,    -1,
      -1,   233,   236,    -1,   236,   233,    -1,    -1,   234,    -1,
     237,    -1,   227,    -1,   239,    -1,   240,    -1,   239,    -1,
     277,    -1,    96,    -1,    97,    -1,   277,    -1,   267,    -1,
     271,    -1,   275,    -1,   279,    -1,    99,    -1,   242,    -1,
     245,   244,    -1,    52,   245,    -1,    -1,   244,   243,    -1,
     248,   247,    -1,    53,   248,    -1,    -1,   247,   246,    -1,
     249,    -1,   252,   251,    -1,    54,   252,    -1,    55,   252,
      -1,    56,   252,    -1,    57,   252,    -1,    58,   252,    -1,
      59,   252,    -1,    -1,   250,    -1,   253,    -1,   256,   255,
      -1,    60,   256,    -1,    61,   256,    -1,   273,    -1,   274,
      -1,    -1,   255,   254,    -1,   259,   258,    -1,    19,   259,
      -1,    62,   259,    -1,    -1,   258,   257,    -1,    63,   260,
      -1,    60,   260,    -1,    61,   260,    -1,   260,    -1,   261,
      -1,   262,    -1,   265,    -1,   267,    -1,   271,    -1,   275,
      -1,   239,    -1,    40,   241,    41,    -1,    64,    40,   241,
      41,    -1,    65,    40,   241,    41,    -1,    66,    40,   241,
      47,   241,    41,    -1,    67,    40,   241,    41,    -1,    68,
      40,   239,    41,    -1,    69,    40,   241,    47,   241,    41,
      -1,    70,    40,   241,    41,    -1,    71,    40,   241,    41,
      -1,    72,    40,   241,    41,    -1,    73,    40,   241,    41,
      -1,   263,    -1,    74,    40,   241,    47,   241,   264,    41,
      -1,    -1,   202,    -1,   277,   266,    -1,    -1,   201,    -1,
     276,   270,    -1,    75,   277,    -1,    98,    -1,   268,    -1,
      -1,   269,    -1,   272,    -1,   273,    -1,   274,    -1,    78,
      -1,    79,    -1,    80,    -1,    81,    -1,    82,    -1,    83,
      -1,    84,    -1,    85,    -1,    86,    -1,    76,    -1,    77,
      -1,    87,    -1,    89,    -1,    88,    -1,    90,    -1,    91,
      -1,   278,    -1,    93,    -1,    92,    -1,    94,    -1,    95,
      -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  SPARQLfedParser::yyprhs_[] =
  {
         0,     0,     3,     6,     8,    10,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    33,    37,    41,    45,    48,
      50,    53,    56,    57,    59,    62,    63,    65,    67,    69,
      73,    74,    76,    80,    83,    84,    86,    87,    90,    93,
      94,    95,   101,   108,   110,   112,   113,   115,   117,   120,
     122,   124,   125,   128,   134,   140,   142,   145,   147,   149,
     150,   152,   156,   159,   161,   163,   165,   168,   170,   174,
     175,   177,   178,   180,   183,   184,   186,   187,   189,   191,
     192,   194,   195,   197,   200,   203,   207,   209,   212,   214,
     216,   218,   220,   223,   225,   227,   230,   233,   234,   241,
     242,   245,   246,   251,   253,   255,   257,   260,   261,   267,
     268,   270,   272,   274,   275,   277,   281,   282,   285,   286,
     292,   293,   294,   300,   304,   305,   308,   311,   314,   315,
     317,   319,   321,   323,   324,   325,   330,   331,   332,   333,
     340,   341,   342,   347,   348,   352,   353,   356,   359,   361,
     363,   365,   368,   370,   373,   374,   377,   379,   380,   386,
     387,   392,   393,   395,   398,   401,   402,   404,   405,   409,
     410,   414,   418,   421,   422,   424,   427,   428,   431,   433,
     434,   436,   439,   442,   443,   446,   448,   450,   452,   454,
     456,   457,   462,   467,   469,   471,   473,   475,   477,   478,
     480,   481,   484,   487,   488,   490,   492,   494,   496,   498,
     500,   502,   504,   506,   508,   510,   512,   514,   516,   518,
     520,   523,   526,   527,   530,   533,   536,   537,   540,   542,
     545,   548,   551,   554,   557,   560,   563,   564,   566,   568,
     571,   574,   577,   579,   581,   582,   585,   588,   591,   594,
     595,   598,   601,   604,   607,   609,   611,   613,   615,   617,
     619,   621,   623,   627,   632,   637,   644,   649,   654,   661,
     666,   671,   676,   681,   683,   691,   692,   694,   697,   698,
     700,   703,   706,   708,   710,   711,   713,   715,   717,   719,
     721,   723,   725,   727,   729,   731,   733,   735,   737,   739,
     741,   743,   745,   747,   749,   751,   753,   755,   757,   759
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLfedParser::yyrline_[] =
  {
         0,   366,   366,   373,   374,   375,   376,   377,   378,   379,
     383,   384,   385,   386,   390,   396,   402,   408,   414,   421,
     424,   432,   439,   442,   446,   452,   455,   459,   460,   464,
     470,   473,   479,   486,   490,   492,   496,   498,   502,   508,
     510,   508,   520,   527,   530,   537,   540,   545,   549,   557,
     560,   567,   570,   578,   586,   593,   597,   605,   608,   615,
     618,   623,   630,   637,   638,   642,   648,   654,   661,   667,
     669,   673,   676,   681,   688,   691,   696,   700,   705,   710,
     713,   718,   721,   726,   730,   738,   745,   749,   757,   759,
     767,   770,   778,   786,   787,   793,   799,   806,   806,   816,
     819,   827,   827,   837,   838,   845,   849,   857,   857,   868,
     870,   875,   876,   880,   882,   887,   891,   894,   899,   899,
     909,   912,   909,   923,   927,   929,   934,   939,   943,   946,
     950,   951,   952,   956,   958,   956,   971,   973,   975,   971,
     987,   989,   987,   999,   999,  1007,  1009,  1013,  1024,  1025,
    1026,  1030,  1037,  1044,  1050,  1052,  1059,  1063,  1063,  1073,
    1073,  1081,  1083,  1088,  1093,  1097,  1099,  1103,  1103,  1106,
    1106,  1113,  1118,  1122,  1124,  1129,  1133,  1135,  1140,  1144,
    1146,  1151,  1156,  1160,  1162,  1166,  1173,  1177,  1184,  1185,
    1189,  1189,  1202,  1227,  1230,  1233,  1236,  1239,  1246,  1249,
    1254,  1257,  1265,  1282,  1285,  1289,  1290,  1294,  1297,  1301,
    1304,  1310,  1311,  1315,  1318,  1321,  1324,  1327,  1328,  1334,
    1339,  1348,  1355,  1358,  1366,  1375,  1382,  1385,  1392,  1397,
    1408,  1411,  1414,  1417,  1420,  1423,  1430,  1434,  1438,  1443,
    1452,  1455,  1458,  1461,  1468,  1471,  1479,  1488,  1491,  1498,
    1501,  1508,  1511,  1514,  1517,  1521,  1522,  1523,  1524,  1527,
    1530,  1533,  1539,  1545,  1548,  1551,  1554,  1557,  1560,  1563,
    1566,  1569,  1572,  1575,  1580,  1587,  1590,  1594,  1604,  1607,
    1612,  1620,  1627,  1631,  1639,  1643,  1647,  1648,  1649,  1653,
    1654,  1655,  1659,  1660,  1661,  1665,  1666,  1667,  1671,  1672,
    1676,  1677,  1678,  1679,  1683,  1684,  1688,  1689,  1693,  1694
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
      95,    96,    97,    98,    99
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int SPARQLfedParser::yyeof_ = 0;
  const int SPARQLfedParser::yylast_ = 752;
  const int SPARQLfedParser::yynnts_ = 180;
  const int SPARQLfedParser::yyempty_ = -2;
  const int SPARQLfedParser::yyfinal_ = 7;
  const int SPARQLfedParser::yyterror_ = 1;
  const int SPARQLfedParser::yyerrcode_ = 256;
  const int SPARQLfedParser::yyntokens_ = 100;

  const unsigned int SPARQLfedParser::yyuser_token_number_max_ = 354;
  const SPARQLfedParser::token_number_type SPARQLfedParser::yyundef_token_ = 2;

} // namespace w3c_sw

#line 1699 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
 /*** Additional Code ***/

void w3c_sw::SPARQLfedParser::error(const SPARQLfedParser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}

/* START Driver (@@ stand-alone would allow it to be shared with other parsers */

namespace w3c_sw {

    SPARQLfedDriver::SPARQLfedDriver (std::string baseURI, POSFactory* posFactory) : 
	Driver(baseURI, posFactory), curSubject(NULL), curPredicate(NULL), 
	curBGP(NULL), curFilter(NULL), 
	curBindingClause(NULL), curBinding(NULL), curExprList(NULL), 
	curGraphName(NULL), root(NULL),  unnestTree(false)
{
}

    SPARQLfedDriver::~SPARQLfedDriver ()
{
}

bool SPARQLfedDriver::parse_stream(std::istream& in, const std::string& sname)
{
    streamname = sname;

    SPARQLfedScanner scanner(this, &in);
    scanner.set_debug(trace_scanning);
    lexer = &scanner;

    SPARQLfedParser parser(*this);
    parser.set_debug_level(trace_parsing);
    // !!! Clear out namespaces!
    ignorePrefixFlag = false;
    return (parser.parse());
}

} // namespace w3c_sw

/* END Driver */


