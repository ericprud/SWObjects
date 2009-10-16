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
#line 234 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

#include "../SPARQLfedScanner.hpp"
#line 351 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

#include "../SPARQLfedScanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc.  */
#line 57 "lib/SPARQLfedParser/SPARQLfedParser.cpp"

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
    #line 37 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}
  /* Line 547 of yacc.c.  */
#line 294 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
#line 366 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(2) - (2)].p_Operation);
    ;}
    break;

  case 14:
#line 390 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Replace((yysemantic_stack_[(4) - (2)].p_WhereClause), driver.curOp);
	driver.curOp = NULL;
    ;}
    break;

  case 15:
#line 397 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      ;}
    break;

  case 16:
#line 400 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Insert((yysemantic_stack_[(4) - (3)].p_TableOperation), (yysemantic_stack_[(4) - (4)].p_WhereClause));
      ;}
    break;

  case 17:
#line 406 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      ;}
    break;

  case 18:
#line 409 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(4) - (3)].p_TableOperation), (yysemantic_stack_[(4) - (4)].p_WhereClause));
      ;}
    break;

  case 19:
#line 415 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(3) - (2)].p_URIs), (yysemantic_stack_[(3) - (3)].p_URI));
    ;}
    break;

  case 20:
#line 421 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(2) - (2)].p_URI));
    ;}
    break;

  case 21:
#line 428 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URIs) = new ProductionVector<const URI*>((yysemantic_stack_[(1) - (1)].p_URI));
    ;}
    break;

  case 22:
#line 431 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_URIs)->push_back((yysemantic_stack_[(2) - (2)].p_URI));
	(yyval.p_URIs) = (yysemantic_stack_[(2) - (1)].p_URIs);
    ;}
    break;

  case 23:
#line 439 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    ;}
    break;

  case 24:
#line 446 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    ;}
    break;

  case 26:
#line 453 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    ;}
    break;

  case 27:
#line 459 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    ;}
    break;

  case 31:
#line 471 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    ;}
    break;

  case 32:
#line 477 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    ;}
    break;

  case 33:
#line 480 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
;}
    break;

  case 34:
#line 486 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
;}
    break;

  case 40:
#line 509 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI));
    ;}
    break;

  case 41:
#line 515 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ignorePrefix(true);
      ;}
    break;

  case 42:
#line 517 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.ignorePrefix(false);
      ;}
    break;

  case 43:
#line 519 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      ;}
    break;

  case 44:
#line 527 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Select((yysemantic_stack_[(6) - (2)].p_distinctness), (yysemantic_stack_[(6) - (3)].p_VarSet), (yysemantic_stack_[(6) - (4)].p_DatasetClauses), (yysemantic_stack_[(6) - (5)].p_WhereClause), (yysemantic_stack_[(6) - (6)].p_SolutionModifier));
    ;}
    break;

  case 45:
#line 534 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    ;}
    break;

  case 46:
#line 537 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    ;}
    break;

  case 47:
#line 544 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    ;}
    break;

  case 49:
#line 552 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POSList) = new POSList;
	(yyval.p_POSList)->push_back((yysemantic_stack_[(1) - (1)].p_Variable));
    ;}
    break;

  case 50:
#line 556 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSList)->push_back((yysemantic_stack_[(2) - (2)].p_Variable));
	(yyval.p_POSList) = (yysemantic_stack_[(2) - (1)].p_POSList);
    ;}
    break;

  case 51:
#line 564 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_POSList);
    ;}
    break;

  case 52:
#line 567 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    ;}
    break;

  case 53:
#line 574 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    ;}
    break;

  case 54:
#line 577 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    ;}
    break;

  case 55:
#line 585 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	/* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	(yyval.p_Operation) = new Construct((DefaultGraphPattern*)(yysemantic_stack_[(5) - (2)].p_BasicGraphPattern), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    ;}
    break;

  case 56:
#line 593 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    ;}
    break;

  case 57:
#line 600 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POSList) = new POSList;
	(yyval.p_POSList)->push_back((yysemantic_stack_[(1) - (1)].p_POS));
    ;}
    break;

  case 58:
#line 604 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSList)->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSList) = (yysemantic_stack_[(2) - (1)].p_POSList);
    ;}
    break;

  case 59:
#line 612 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_POSList);
    ;}
    break;

  case 60:
#line 615 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    ;}
    break;

  case 61:
#line 622 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    ;}
    break;

  case 63:
#line 630 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(3) - (2)].p_DatasetClauses), (yysemantic_stack_[(3) - (3)].p_WhereClause));
    ;}
    break;

  case 64:
#line 637 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    ;}
    break;

  case 67:
#line 649 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_POS), driver.posFactory);
    ;}
    break;

  case 68:
#line 655 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_POS), driver.posFactory);
    ;}
    break;

  case 69:
#line 661 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    ;}
    break;

  case 70:
#line 668 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.curOp, (yysemantic_stack_[(3) - (3)].p_BindingClause));
	driver.curOp = NULL;
    ;}
    break;

  case 73:
#line 681 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = NULL;
    ;}
    break;

  case 75:
#line 689 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(2) - (1)].p_OrderConditions), (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit, (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset);
    ;}
    break;

  case 76:
#line 696 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    ;}
    break;

  case 78:
#line 704 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    ;}
    break;

  case 81:
#line 718 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    ;}
    break;

  case 83:
#line 726 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    ;}
    break;

  case 85:
#line 734 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    ;}
    break;

  case 86:
#line 738 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    ;}
    break;

  case 87:
#line 746 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    ;}
    break;

  case 88:
#line 753 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    ;}
    break;

  case 89:
#line 757 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    ;}
    break;

  case 91:
#line 767 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    ;}
    break;

  case 92:
#line 775 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    ;}
    break;

  case 93:
#line 778 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    ;}
    break;

  case 94:
#line 786 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 96:
#line 795 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new VarExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    ;}
    break;

  case 97:
#line 801 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    ;}
    break;

  case 98:
#line 807 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    ;}
    break;

  case 99:
#line 814 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBindingClause = new BindingClause((yysemantic_stack_[(3) - (2)].p_POSList));
      ;}
    break;

  case 100:
#line 816 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = driver.curBindingClause;
	  driver.curBindingClause = NULL;
      ;}
    break;

  case 101:
#line 824 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Bindings) = NULL;
    ;}
    break;

  case 102:
#line 827 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBindingClause->push_back((yysemantic_stack_[(2) - (2)].p_Binding));
	(yyval.p_Bindings) = NULL;
    ;}
    break;

  case 103:
#line 835 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding = new Binding();
      ;}
    break;

  case 104:
#line 837 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Binding) = driver.curBinding;
	  driver.curBinding = NULL;
      ;}
    break;

  case 106:
#line 846 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = driver.getNULL();
    ;}
    break;

  case 107:
#line 853 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(1) - (1)].p_POS));
	(yyval.p_POSs) = NULL;
    ;}
    break;

  case 108:
#line 857 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSs) = NULL;
    ;}
    break;

  case 109:
#line 865 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = NULL;
	driver.curBGP = NULL;
      ;}
    break;

  case 110:
#line 868 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      ;}
    break;

  case 120:
#line 907 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      ;}
    break;

  case 121:
#line 910 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
      ;}
    break;

  case 122:
#line 917 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curFilter = NULL;
      ;}
    break;

  case 123:
#line 920 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_POS) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_POS);
      ;}
    break;

  case 124:
#line 923 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(5) - (3)].p_POS), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(5) - (4)].p_POS);
      ;}
    break;

  case 135:
#line 964 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      ;}
    break;

  case 136:
#line 966 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_FilterHolder) = driver.curFilter;
	  driver.curFilter = new FilterHolder();
      ;}
    break;

  case 137:
#line 969 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  OptionalGraphPattern* ret = new OptionalGraphPattern(driver.curOp);
	  ((FilterHolder*)driver.curFilter)->copyExpressionsTo(ret); // @@ nasty cast
	  delete driver.curFilter;
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), ret);
	  driver.curFilter = (yysemantic_stack_[(4) - (3)].p_FilterHolder);
      ;}
    break;

  case 138:
#line 979 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      ;}
    break;

  case 139:
#line 981 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_FilterHolder) = driver.saveFilter();
      ;}
    break;

  case 140:
#line 983 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_POS) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_POS);
      ;}
    break;

  case 141:
#line 986 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_FilterHolder));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_POS), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_POS);
      ;}
    break;

  case 142:
#line 995 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      ;}
    break;

  case 143:
#line 997 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_FilterHolder) = driver.saveFilter();
      ;}
    break;

  case 144:
#line 999 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_FilterHolder));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      ;}
    break;

  case 145:
#line 1007 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      ;}
    break;

  case 146:
#line 1009 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.curOp);
      ;}
    break;

  case 149:
#line 1021 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    if (driver.curOp == NULL)
		driver.ensureBasicGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 153:
#line 1038 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    ;}
    break;

  case 154:
#line 1045 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = new ArgList((yysemantic_stack_[(1) - (1)].p_Expressions));
    ;}
    break;

  case 155:
#line 1052 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 157:
#line 1060 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 158:
#line 1067 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    ;}
    break;

  case 159:
#line 1071 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      ;}
    break;

  case 160:
#line 1073 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = NULL;
      ;}
    break;

  case 161:
#line 1081 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      ;}
    break;

  case 162:
#line 1083 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      ;}
    break;

  case 169:
#line 1111 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_POS);
    ;}
    break;

  case 171:
#line 1114 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_POS);
    ;}
    break;

  case 187:
#line 1174 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.posFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_POS)));
    ;}
    break;

  case 188:
#line 1181 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_POS);
	driver.curPredicate = (yyval.p_POS);
    ;}
    break;

  case 189:
#line 1185 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_POS);
    ;}
    break;

  case 192:
#line 1197 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      ;}
    break;

  case 193:
#line 1201 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_POS) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      ;}
    break;

  case 194:
#line 1210 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 195:
#line 1235 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    ;}
    break;

  case 196:
#line 1238 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    ;}
    break;

  case 197:
#line 1241 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    ;}
    break;

  case 198:
#line 1244 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    ;}
    break;

  case 199:
#line 1247 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    ;}
    break;

  case 200:
#line 1254 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    ;}
    break;

  case 202:
#line 1262 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POSs) = new ProductionVector<const POS*>();
    ;}
    break;

  case 203:
#line 1265 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSs)->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSs) = (yysemantic_stack_[(2) - (1)].p_POSs);
    ;}
    break;

  case 204:
#line 1273 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 205:
#line 1290 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POSs) = new ProductionVector<const POS*>();
    ;}
    break;

  case 209:
#line 1302 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    ;}
    break;

  case 211:
#line 1309 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    ;}
    break;

  case 212:
#line 1312 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    ;}
    break;

  case 215:
#line 1323 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    ;}
    break;

  case 216:
#line 1326 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    ;}
    break;

  case 217:
#line 1329 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    ;}
    break;

  case 218:
#line 1332 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    ;}
    break;

  case 220:
#line 1336 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    ;}
    break;

  case 222:
#line 1347 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    ;}
    break;

  case 223:
#line 1356 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 224:
#line 1363 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    ;}
    break;

  case 225:
#line 1366 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    ;}
    break;

  case 226:
#line 1374 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    ;}
    break;

  case 227:
#line 1383 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 228:
#line 1390 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    ;}
    break;

  case 229:
#line 1393 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    ;}
    break;

  case 231:
#line 1405 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_BooleanComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_BooleanComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_BooleanComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    ;}
    break;

  case 232:
#line 1416 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 233:
#line 1419 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 234:
#line 1422 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 235:
#line 1425 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 236:
#line 1428 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yyval.p_BooleanComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 237:
#line 1431 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 238:
#line 1438 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = NULL;
    ;}
    break;

  case 241:
#line 1451 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    ;}
    break;

  case 242:
#line 1460 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 243:
#line 1463 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 244:
#line 1466 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    ;}
    break;

  case 245:
#line 1469 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    ;}
    break;

  case 246:
#line 1476 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    ;}
    break;

  case 247:
#line 1479 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    ;}
    break;

  case 248:
#line 1487 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    ;}
    break;

  case 249:
#line 1496 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 250:
#line 1499 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 251:
#line 1506 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    ;}
    break;

  case 252:
#line 1509 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    ;}
    break;

  case 253:
#line 1516 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 254:
#line 1519 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 255:
#line 1522 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 260:
#line 1532 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new LiteralExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    ;}
    break;

  case 261:
#line 1535 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    ;}
    break;

  case 262:
#line 1538 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    ;}
    break;

  case 263:
#line 1541 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new VarExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    ;}
    break;

  case 264:
#line 1547 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    ;}
    break;

  case 265:
#line 1553 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-str"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 266:
#line 1556 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-lang"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 267:
#line 1559 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-langMatches"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    ;}
    break;

  case 268:
#line 1562 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-datatype"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 269:
#line 1565 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-bound"), new VarExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    ;}
    break;

  case 270:
#line 1568 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-sameTerm"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    ;}
    break;

  case 271:
#line 1571 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 272:
#line 1574 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 273:
#line 1577 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isBlank"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 274:
#line 1580 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isLiteral"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 276:
#line 1588 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-regex"), (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    ;}
    break;

  case 277:
#line 1595 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    ;}
    break;

  case 279:
#line 1602 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new URIExpression((yysemantic_stack_[(2) - (1)].p_URI));
    ;}
    break;

  case 280:
#line 1612 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    ;}
    break;

  case 282:
#line 1620 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    ;}
    break;

  case 283:
#line 1628 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    ;}
    break;

  case 284:
#line 1635 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    ;}
    break;

  case 285:
#line 1639 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    ;}
    break;

  case 286:
#line 1647 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    ;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 1791 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -271;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        16,   -39,    69,   262,  -271,  -271,  -271,  -271,    24,    54,
      54,    38,    64,    93,    93,     5,    84,    22,  -271,  -271,
    -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,
    -271,  -271,  -271,   120,  -271,   118,   103,  -271,  -271,  -271,
    -271,  -271,  -271,    -4,  -271,  -271,    38,  -271,  -271,  -271,
      64,    64,  -271,  -271,  -271,    -5,  -271,  -271,  -271,  -271,
    -271,   110,  -271,  -271,  -271,  -271,     9,  -271,  -271,    54,
    -271,   114,   364,    63,    63,    38,  -271,  -271,  -271,  -271,
    -271,  -271,  -271,   -19,  -271,  -271,   364,     9,  -271,    17,
      35,  -271,  -271,    79,  -271,   364,   -19,  -271,  -271,  -271,
    -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,
    -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,
    -271,  -271,  -271,  -271,  -271,   135,  -271,  -271,  -271,  -271,
     139,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,
     -55,  -271,  -271,  -271,  -271,  -271,  -271,  -271,     9,   143,
    -271,   142,   158,   158,    38,  -271,  -271,  -271,  -271,  -271,
    -271,  -271,   -24,    49,   150,   364,  -271,  -271,    49,   388,
      49,    38,  -271,  -271,  -271,  -271,   158,  -271,   364,  -271,
    -271,   163,  -271,    83,  -271,  -271,  -271,   102,   131,  -271,
    -271,   144,   481,  -271,  -271,   153,   191,  -271,  -271,  -271,
    -271,  -271,  -271,  -271,   164,  -271,  -271,  -271,  -271,  -271,
    -271,   310,   126,   132,  -271,  -271,  -271,   182,   188,  -271,
    -271,  -271,  -271,   668,   153,  -271,  -271,  -271,  -271,  -271,
    -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,   364,   110,
    -271,   457,  -271,  -271,   598,   185,   186,   189,   198,   206,
     208,   209,   210,   211,   212,   213,   310,  -271,   214,  -271,
    -271,  -271,  -271,  -271,  -271,  -271,  -271,   -25,  -271,  -271,
    -271,  -271,  -271,  -271,  -271,  -271,  -271,   364,   103,    66,
     183,   222,  -271,  -271,  -271,   633,   633,   633,  -271,   215,
    -271,  -271,  -271,  -271,   107,  -271,  -271,  -271,  -271,  -271,
    -271,  -271,  -271,  -271,  -271,   -25,   598,   598,   598,   598,
     -19,   598,   598,   598,   598,   598,   598,  -271,  -271,   598,
    -271,  -271,  -271,   110,   103,  -271,   216,  -271,  -271,  -271,
      49,  -271,   481,  -271,    54,  -271,  -271,  -271,  -271,   205,
     218,   598,   598,   598,   598,   598,   598,  -271,  -271,   232,
       0,  -271,  -271,   217,   233,   229,   238,   239,   234,   243,
     244,   245,   246,   242,  -271,  -271,  -271,  -271,   216,  -271,
     513,  -271,  -271,   481,  -271,  -271,   598,  -271,   598,  -271,
    -271,  -271,  -271,  -271,  -271,  -271,   598,   598,  -271,  -271,
    -271,   598,   598,  -271,  -271,  -271,   598,  -271,  -271,   598,
    -271,  -271,  -271,  -271,   598,  -271,   103,   103,  -271,  -271,
    -271,   540,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,
     249,   250,   247,     8,  -271,  -271,  -271,  -271,  -271,  -271,
     598,  -271,   254,  -271,  -271,  -271,  -271
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  SPARQLfedParser::yydefact_[] =
  {
        36,     0,     0,     0,    38,    37,    40,     1,    71,     0,
       0,     0,    27,    32,    32,    47,     0,     0,    53,     2,
       8,     7,    10,    11,    12,    13,     9,    29,    30,     3,
       4,     5,     6,    35,    72,     0,     0,   120,    17,    15,
     306,   309,   308,    24,    21,   307,     0,    28,    20,    33,
       0,     0,    45,    46,    48,     0,   161,    53,    60,   213,
     214,    59,    53,    57,   211,   212,    71,    41,    39,     0,
     109,    73,   111,    61,    61,     0,    25,    19,    22,    26,
      31,    34,    52,    51,    53,    49,   163,    71,    58,    61,
       0,    54,    63,     0,    14,   111,     0,    70,    74,   195,
     196,   197,   198,   199,   192,   300,   301,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   302,   304,   303,   305,
     310,   311,   220,   126,   112,   130,   171,   191,   190,   201,
       0,   169,   209,   210,   216,   217,   288,   289,   290,   218,
     286,   215,   219,    18,    62,    16,    23,    50,    71,     0,
     164,   167,    76,    76,     0,    64,    65,    66,    67,    69,
      42,   118,     0,     0,   122,   111,   131,   128,   181,   200,
       0,     0,   284,   285,   287,   282,    76,   162,   163,   168,
     165,     0,    55,    78,    77,    56,    68,     0,   142,    99,
     189,     0,   200,   188,   121,   115,     0,   127,   129,   182,
     172,   180,   208,   206,     0,   202,   207,   170,   283,    44,
     166,     0,     0,     0,    75,    79,    80,    81,    83,    43,
     138,   110,   135,     0,   115,   119,   113,   132,   134,   133,
     143,   114,   101,   193,   178,   185,   187,   116,   111,     0,
     194,   200,    92,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    87,    88,     0,    90,
      91,    95,   152,    96,   150,   151,   275,     0,    97,    98,
      85,    82,    86,    84,   139,   136,   149,   111,     0,     0,
     173,   183,   125,   123,   203,     0,     0,     0,   263,     0,
     221,   224,   228,   230,   238,   240,   246,   251,   256,   257,
     258,   259,   260,   261,   262,   280,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    89,    94,     0,
     158,   153,   154,     0,     0,   117,   147,   100,   103,   102,
     175,   179,   200,   186,     0,   254,   255,   253,   264,   222,
     226,     0,     0,     0,     0,     0,     0,   239,   231,   241,
     248,   281,   279,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   159,   140,   137,   145,   147,   144,
       0,   176,   177,   200,   184,   124,     0,   225,     0,   229,
     232,   233,   234,   235,   236,   237,     0,     0,   247,   244,
     245,     0,     0,   252,   265,   266,     0,   268,   269,     0,
     271,   272,   273,   274,     0,   156,     0,     0,   148,   106,
     107,     0,   105,   174,   223,   227,   242,   243,   249,   250,
       0,     0,   277,     0,   141,   146,   104,   108,   267,   270,
       0,   278,     0,   160,   157,   155,   276
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,
    -271,  -271,  -271,  -271,    44,  -271,  -271,  -271,   282,  -271,
    -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,
     201,  -271,   -17,  -271,  -271,  -271,  -271,   -45,  -271,  -271,
    -271,  -271,  -271,   145,    -1,  -271,  -271,  -129,  -271,  -271,
    -271,  -271,  -271,  -271,  -271,  -271,    47,  -271,  -271,  -271,
      88,    90,  -271,  -271,  -271,  -271,  -271,  -102,  -271,  -270,
    -271,   -85,  -271,    86,  -271,  -271,    -9,  -271,  -271,  -271,
    -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,
    -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,   -57,
    -271,    97,  -271,    18,  -101,  -271,  -271,  -271,  -271,  -271,
     152,  -271,  -271,  -271,   -70,  -271,  -271,  -111,  -271,  -271,
    -271,  -271,  -271,  -271,   -40,  -271,  -271,     2,    -2,  -158,
    -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -160,  -156,
     -15,    21,  -271,   -72,  -271,  -271,  -271,   -41,  -271,  -271,
     -38,  -271,  -271,  -271,  -123,  -271,  -271,  -271,  -254,  -271,
    -271,  -236,  -136,  -190,  -186,  -271,  -271,  -271,  -271,   -69,
    -271,  -271,  -271,   -68,  -271,   -10,    -8,   -44,  -271,   -11,
    -271,  -271
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,    19,    20,    21,    22,    74,    23,    73,    24,
      25,    43,    76,    77,    47,    48,    26,    27,    50,    28,
       3,     4,    33,     5,    68,    93,   187,    29,    54,    55,
      83,    84,    66,    30,    31,    61,    62,   143,    32,    91,
     155,   156,   157,   158,   144,    36,    97,   182,   183,   214,
     215,   270,   272,   216,   184,   256,   257,   258,   259,   260,
     217,   218,    98,   232,   279,   329,   370,   410,   411,    71,
      95,   123,   224,   238,   225,   188,    38,    72,   195,   196,
     334,   197,   164,   124,   166,   167,   226,   227,   275,   324,
     228,   274,   323,   406,   229,   230,   278,   368,   407,   369,
     231,   261,   262,   321,   431,   423,   322,   405,    57,    86,
     149,   150,   179,   180,   125,   170,   168,   191,   371,   372,
     331,   280,   200,   201,   234,   333,   281,   235,   192,   126,
     127,   163,   128,   129,   130,   241,   203,   204,   236,   131,
     193,   288,   133,   289,   290,   377,   339,   291,   379,   340,
     292,   293,   347,   348,   294,   295,   388,   349,   296,   393,
     350,   297,   298,   299,   300,   266,   432,   301,   352,   302,
     173,   174,   175,   303,   136,   137,   138,   304,   140,   305,
      45,   142
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int SPARQLfedParser::yytable_ninf_ = -206;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        44,    39,    63,   134,   135,    75,    65,    35,   326,   205,
     161,   202,   189,   206,    82,   319,   151,   134,   135,   391,
     171,   264,    52,    53,   185,   265,   134,   135,   139,   145,
       1,    90,    78,   264,   202,    79,   206,   265,    64,    90,
      87,    58,   139,   172,   153,    89,    88,   209,    34,   433,
      65,   139,     6,   -71,   366,   430,    34,   199,   154,   207,
      94,   141,   392,    34,   146,    92,   264,   148,   318,     7,
     265,    46,    59,    60,   320,   141,    85,    59,    60,   159,
     198,   284,    64,   202,   141,   206,   152,    40,    41,    42,
      37,    59,    60,   132,    80,    81,   134,   135,   190,   -71,
     134,   135,    34,   327,   147,    49,   328,   132,   151,   134,
     135,   212,   213,    40,    41,    42,   132,    85,    59,    60,
      56,   139,    69,   134,   135,   139,    40,    41,    42,    40,
      41,    42,   416,   417,   139,    67,   424,   425,   220,    70,
      40,    41,    42,   159,    96,    59,    60,   176,   139,   335,
     336,   337,    65,   282,   141,   418,   419,    65,   141,    65,
     208,   341,   342,   343,   344,   345,   346,   141,   221,   134,
     135,   160,   134,   135,   202,   222,   206,   223,   165,   169,
     177,   141,   181,   147,    64,   178,   132,   194,   211,    64,
     132,    64,   325,   219,   139,   233,   237,   139,   239,   132,
     267,    40,    41,    42,   268,   240,    59,    60,   134,   135,
     269,   213,   267,   132,   412,   202,   212,   206,   380,   381,
     382,   383,   384,   385,   283,   306,   307,   141,    65,   308,
     141,   330,   263,   139,   353,   354,   355,   356,   309,   358,
     359,   360,   361,   362,   363,   267,   310,   364,   311,   312,
     313,   314,   315,   316,   244,   412,   338,   376,   394,   132,
      64,   367,   132,   134,   135,     8,   141,     9,    10,   332,
      11,   378,    12,    13,   395,    14,   396,   263,    15,   397,
     398,   399,    16,    17,   400,   401,   402,   403,   139,   404,
     428,   429,   386,   387,   430,   436,    51,   162,   132,   186,
      18,   134,   135,   317,   134,   135,   273,   271,   365,   427,
     277,   408,    65,   110,   111,   112,   113,   114,   115,    65,
     276,   141,   434,   351,   420,   375,   139,   421,   373,   139,
     210,   357,   422,   413,   374,   414,   242,   243,     0,   389,
     415,   390,   134,   135,    64,     0,     0,     0,     0,     0,
     244,    64,     0,   132,     0,     0,     0,     0,   435,   141,
       0,     0,   141,     0,     0,     0,     0,   139,     0,     0,
       0,     0,     0,     0,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,     0,     0,     0,     0,     0,
       0,   132,     0,     0,   132,    99,   100,   101,   102,   103,
     141,    40,    41,    42,  -200,     0,    59,    60,     0,     0,
       0,     0,     0,     0,   104,     0,     0,     0,     0,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,  -205,
       0,     0,   132,     0,     0,     0,     0,     0,   104,     0,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,    40,    41,    42,   120,   121,
      59,    60,     0,   122,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,    40,
      41,    42,   120,   121,    59,    60,     0,   122,    99,   100,
     101,   102,   103,     0,     0,     0,     0,     0,  -204,     0,
       0,     0,     0,     0,     0,     0,     0,   104,     0,     0,
       0,     0,    99,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   104,     0,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,    40,    41,
      42,   120,   121,    59,    60,   409,   122,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,    40,    41,    42,   120,   121,    59,    60,     0,
     122,   426,   409,     0,     0,     0,     0,     0,     0,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    40,    41,    42,   120,   121,    59,
      60,     0,   122,     0,     0,     0,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,    40,    41,    42,   120,   121,    59,    60,   244,   122,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   285,   286,
       0,   287,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   244,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,    40,
      41,    42,     0,     0,    59,    60,     0,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   244,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    40,    41,    42,     0,     0,    59,
      60,     0,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    40,
      41,    42
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        11,    10,    17,    72,    72,     9,    17,     8,   278,   169,
      95,   169,    36,   169,    19,    40,    86,    86,    86,    19,
      75,   211,    17,    18,   153,   211,    95,    95,    72,    74,
      14,    22,    43,   223,   192,    46,   192,   223,    17,    22,
      57,    19,    86,    98,    89,    62,    61,   176,    39,    41,
      61,    95,    91,    36,   324,    47,    39,   168,    23,   170,
      69,    72,    62,    39,    75,    66,   256,    84,   258,     0,
     256,     7,    96,    97,    99,    86,    55,    96,    97,    90,
     165,   241,    61,   241,    95,   241,    87,    91,    92,    93,
      36,    96,    97,    72,    50,    51,   165,   165,    49,    36,
     169,   169,    39,    37,    83,    12,    40,    86,   178,   178,
     178,    28,    29,    91,    92,    93,    95,    96,    96,    97,
      36,   165,     4,   192,   192,   169,    91,    92,    93,    91,
      92,    93,   386,   387,   178,    15,   406,   407,     7,    36,
      91,    92,    93,   154,    30,    96,    97,   148,   192,   285,
     286,   287,   163,   238,   165,   391,   392,   168,   169,   170,
     171,    54,    55,    56,    57,    58,    59,   178,    37,   238,
     238,    92,   241,   241,   332,    44,   332,    46,    43,    40,
      37,   192,    24,   162,   163,    43,   165,    37,    25,   168,
     169,   170,   277,    91,   238,    51,    43,   241,     7,   178,
     211,    91,    92,    93,    78,    41,    96,    97,   277,   277,
      78,    29,   223,   192,   370,   373,    28,   373,   341,   342,
     343,   344,   345,   346,   239,    40,    40,   238,   239,    40,
     241,    48,   211,   277,   306,   307,   308,   309,    40,   311,
     312,   313,   314,   315,   316,   256,    40,   319,    40,    40,
      40,    40,    40,    40,    40,   411,    41,    52,    41,   238,
     239,    45,   241,   332,   332,     3,   277,     5,     6,    47,
       8,    53,    10,    11,    41,    13,    47,   256,    16,    41,
      41,    47,    20,    21,    41,    41,    41,    41,   332,    47,
      41,    41,    60,    61,    47,    41,    14,    96,   277,   154,
      38,   370,   370,   256,   373,   373,   218,   217,   323,   411,
     224,   368,   323,    81,    82,    83,    84,    85,    86,   330,
     223,   332,   423,   305,   396,   334,   370,   399,   330,   373,
     178,   310,   404,   373,   332,   376,    26,    27,    -1,   349,
     378,   349,   411,   411,   323,    -1,    -1,    -1,    -1,    -1,
      40,   330,    -1,   332,    -1,    -1,    -1,    -1,   430,   370,
      -1,    -1,   373,    -1,    -1,    -1,    -1,   411,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      -1,   370,    -1,    -1,   373,    31,    32,    33,    34,    35,
     411,    91,    92,    93,    40,    -1,    96,    97,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    41,
      -1,    -1,   411,    -1,    -1,    -1,    -1,    -1,    50,    -1,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    -1,    99,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    -1,    99,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    42,    99,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    -1,
      99,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    -1,    99,    -1,    -1,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    40,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,
      -1,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    40,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    -1,    96,    97,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    40,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    -1,    96,
      97,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      92,    93
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLfedParser::yystos_[] =
  {
         0,    14,   101,   120,   121,   123,    91,     0,     3,     5,
       6,     8,    10,    11,    13,    16,    20,    21,    38,   102,
     103,   104,   105,   107,   109,   110,   116,   117,   119,   127,
     133,   134,   138,   122,    39,   144,   145,    36,   176,   176,
      91,    92,    93,   111,   279,   280,     7,   114,   115,    12,
     118,   118,    17,    18,   128,   129,    36,   208,    19,    96,
      97,   135,   136,   240,   241,   279,   132,    15,   124,     4,
      36,   169,   177,   108,   106,     9,   112,   113,   279,   279,
     114,   114,    19,   130,   131,   241,   209,   132,   240,   132,
      22,   139,   144,   125,   176,   170,    30,   146,   162,    31,
      32,    33,    34,    35,    50,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      94,    95,    99,   171,   183,   214,   229,   230,   232,   233,
     234,   239,   241,   242,   269,   273,   274,   275,   276,   277,
     278,   279,   281,   137,   144,   137,   279,   241,   132,   210,
     211,   214,   144,   137,    23,   140,   141,   142,   143,   279,
      92,   171,   130,   231,   182,    43,   184,   185,   216,    40,
     215,    75,    98,   270,   271,   272,   144,    37,    43,   212,
     213,    24,   147,   148,   154,   147,   143,   126,   175,    36,
      49,   217,   228,   240,    37,   178,   179,   181,   171,   217,
     222,   223,   229,   236,   237,   238,   239,   217,   279,   147,
     210,    25,    28,    29,   149,   150,   153,   160,   161,    91,
       7,    37,    44,    46,   172,   174,   186,   187,   190,   194,
     195,   200,   163,    51,   224,   227,   238,    43,   173,     7,
      41,   235,    26,    27,    40,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,   155,   156,   157,   158,
     159,   201,   202,   241,   263,   264,   265,   279,    78,    78,
     151,   161,   152,   160,   191,   188,   201,   173,   196,   164,
     221,   226,   171,   240,   238,    60,    61,    63,   241,   243,
     244,   247,   250,   251,   254,   255,   258,   261,   262,   263,
     264,   267,   269,   273,   277,   279,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,   156,   263,    40,
      99,   203,   206,   192,   189,   171,   169,    37,    40,   165,
      48,   220,    47,   225,   180,   262,   262,   262,    41,   246,
     249,    54,    55,    56,    57,    58,    59,   252,   253,   257,
     260,   203,   268,   243,   243,   243,   243,   241,   243,   243,
     243,   243,   243,   243,   243,   240,   169,    45,   197,   199,
     166,   218,   219,   228,   227,   176,    52,   245,    53,   248,
     254,   254,   254,   254,   254,   254,    60,    61,   256,   275,
     276,    19,    62,   259,    41,    41,    47,    41,    41,    47,
      41,    41,    41,    41,    47,   207,   193,   198,   199,    42,
     167,   168,   239,   224,   247,   250,   258,   258,   261,   261,
     243,   243,   243,   205,   169,   169,    41,   167,    41,    41,
      47,   204,   266,    41,   204,   243,    41
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
     103,   103,   103,   103,   104,   106,   105,   108,   107,   109,
     110,   111,   111,   112,   113,   113,   114,   115,   115,   116,
     116,   117,   118,   118,   119,   120,   121,   121,   122,   122,
     123,   125,   126,   124,   127,   128,   128,   129,   129,   130,
     130,   131,   131,   132,   132,   133,   134,   135,   135,   136,
     136,   137,   137,   138,   139,   140,   140,   141,   142,   143,
     144,   145,   145,   146,   146,   147,   148,   148,   149,   149,
     150,   151,   151,   152,   152,   153,   153,   154,   155,   155,
     156,   156,   157,   157,   158,   159,   159,   160,   161,   163,
     162,   164,   164,   166,   165,   167,   167,   168,   168,   170,
     169,   171,   171,   172,   172,   173,   173,   174,   175,   175,
     177,   176,   179,   180,   178,   181,   182,   182,   183,   184,
     185,   185,   186,   186,   186,   188,   189,   187,   191,   192,
     193,   190,   195,   196,   194,   198,   197,   199,   199,   200,
     201,   201,   201,   202,   203,   204,   205,   205,   206,   207,
     206,   209,   208,   210,   210,   211,   212,   213,   213,   215,
     214,   216,   214,   217,   218,   219,   219,   220,   221,   221,
     222,   223,   223,   224,   225,   226,   226,   227,   228,   228,
     229,   229,   231,   230,   232,   233,   233,   233,   233,   233,
     234,   234,   235,   235,   236,   237,   237,   238,   238,   239,
     239,   240,   240,   241,   241,   242,   242,   242,   242,   242,
     242,   243,   244,   245,   246,   246,   247,   248,   249,   249,
     250,   251,   252,   252,   252,   252,   252,   252,   253,   253,
     254,   255,   256,   256,   256,   256,   257,   257,   258,   259,
     259,   260,   260,   261,   261,   261,   261,   262,   262,   262,
     262,   262,   262,   262,   263,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   265,   266,   266,   267,
     268,   268,   269,   270,   271,   271,   272,   272,   273,   273,
     273,   274,   274,   274,   275,   275,   275,   276,   276,   276,
     277,   277,   278,   278,   278,   278,   279,   279,   280,   280,
     281,   281
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  SPARQLfedParser::yyr2_[] =
  {
         0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     0,     4,     0,     4,     3,
       2,     1,     2,     2,     0,     1,     2,     0,     1,     1,
       1,     3,     0,     1,     3,     2,     0,     1,     0,     2,
       2,     0,     0,     5,     6,     1,     1,     0,     1,     1,
       2,     1,     1,     0,     2,     5,     5,     1,     2,     1,
       1,     0,     1,     3,     2,     1,     1,     1,     2,     1,
       3,     0,     1,     0,     1,     2,     0,     1,     0,     1,
       1,     0,     1,     0,     1,     2,     2,     3,     1,     2,
       1,     1,     1,     1,     2,     1,     1,     2,     2,     0,
       6,     0,     2,     0,     4,     1,     1,     1,     2,     0,
       5,     0,     1,     1,     1,     0,     1,     3,     0,     2,
       0,     5,     0,     0,     5,     3,     0,     2,     2,     2,
       0,     1,     1,     1,     1,     0,     0,     4,     0,     0,
       0,     6,     0,     0,     4,     0,     3,     0,     2,     2,
       1,     1,     1,     2,     1,     2,     0,     2,     1,     0,
       5,     0,     4,     0,     1,     2,     2,     0,     1,     0,
       3,     0,     3,     3,     2,     0,     1,     2,     0,     2,
       1,     0,     1,     2,     2,     0,     2,     1,     1,     1,
       1,     1,     0,     4,     4,     1,     1,     1,     1,     1,
       0,     1,     0,     2,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     0,     2,     2,     2,     0,     2,
       1,     2,     2,     2,     2,     2,     2,     2,     0,     1,
       1,     2,     2,     2,     1,     1,     0,     2,     2,     2,
       2,     0,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     4,     4,     6,     4,     4,
       6,     4,     4,     4,     4,     1,     7,     0,     1,     2,
       0,     1,     2,     2,     1,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
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
  "Update", "Replace", "Insert", "@1", "Delete", "@2", "Load", "Clear",
  "_QIRIref_E_Plus", "_O_QIT_INTO_E_S_QIRIref_E_C",
  "_Q_O_QIT_INTO_E_S_QIRIref_E_C_E_Opt", "GraphIRI", "_QGraphIRI_E_Opt",
  "Manage", "Create", "_QIT_SILENT_E_Opt", "Drop", "Prologue",
  "_QBaseDecl_E_Opt", "_QPrefixDecl_E_Star", "BaseDecl", "PrefixDecl",
  "@3", "@4", "Select", "_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C",
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
  "BindingClause", "@5", "_QBinding_E_Star", "Binding", "@6",
  "_O_QVarOrTerm_E_Or_QIT_NULL_E_C",
  "_Q_O_QVarOrTerm_E_Or_QIT_NULL_E_C_E_Plus", "GroupGraphPattern", "@7",
  "_QTriplesBlock_E_Opt", "_O_QGraphPatternNotTriples_E_Or_QFilter_E_C",
  "_QGT_DOT_E_Opt",
  "_O_QGraphPatternNotTriples_E_Or_QFilter_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGraphPatternNotTriples_E_Or_QFilter_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "GraphTemplate", "@8",
  "_O_QIT_GRAPH_E_S_QVarOrIRIref_E_S_QGraphTemplate_E_C", "@9", "@10",
  "_O_QIT_GRAPH_E_S_QVarOrIRIref_E_S_QGraphTemplate_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QIT_GRAPH_E_S_QVarOrIRIref_E_S_QGraphTemplate_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "TriplesBlock", "_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C_E_Opt", "GraphPatternNotTriples",
  "OptionalGraphPattern", "@11", "@12", "GraphGraphPattern", "@13", "@14",
  "@15", "GroupOrUnionGraphPattern", "@16", "@17",
  "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@18",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star",
  "_O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C",
  "@19", "ConstructTemplate", "@20", "_QConstructTriples_E_Opt",
  "ConstructTriples", "_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C_E_Opt", "TriplesSameSubject",
  "@21", "@22", "PropertyListNotEmpty", "_O_QVerb_E_S_QObjectList_E_C",
  "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "ObjectList",
  "_O_QGT_COMMA_E_S_QObject_E_C", "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star",
  "Object", "Verb", "TriplesNode", "BlankNodePropertyList", "@23",
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
       101,     0,    -1,   120,   102,    -1,   127,    -1,   133,    -1,
     134,    -1,   138,    -1,   104,    -1,   103,    -1,   116,    -1,
     105,    -1,   107,    -1,   109,    -1,   110,    -1,     3,   144,
       4,   176,    -1,    -1,     6,   176,   106,   137,    -1,    -1,
       5,   176,   108,   137,    -1,     8,   111,   113,    -1,    10,
     115,    -1,   279,    -1,   111,   279,    -1,     9,   279,    -1,
      -1,   112,    -1,     7,   279,    -1,    -1,   114,    -1,   117,
      -1,   119,    -1,    11,   118,   114,    -1,    -1,    12,    -1,
      13,   118,   114,    -1,   121,   122,    -1,    -1,   123,    -1,
      -1,   122,   124,    -1,    14,    91,    -1,    -1,    -1,    15,
     125,    92,   126,    91,    -1,    16,   129,   131,   132,   144,
     147,    -1,    17,    -1,    18,    -1,    -1,   128,    -1,   241,
      -1,   130,   241,    -1,   130,    -1,    19,    -1,    -1,   132,
     139,    -1,    20,   208,   132,   144,   147,    -1,    21,   136,
     132,   137,   147,    -1,   240,    -1,   135,   240,    -1,   135,
      -1,    19,    -1,    -1,   144,    -1,    38,   132,   144,    -1,
      22,   140,    -1,   141,    -1,   142,    -1,   143,    -1,    23,
     143,    -1,   279,    -1,   145,   169,   146,    -1,    -1,    39,
      -1,    -1,   162,    -1,   148,   149,    -1,    -1,   154,    -1,
      -1,   150,    -1,   153,    -1,    -1,   161,    -1,    -1,   160,
      -1,   160,   151,    -1,   161,   152,    -1,    24,    25,   155,
      -1,   156,    -1,   155,   156,    -1,   158,    -1,   159,    -1,
      26,    -1,    27,    -1,   157,   263,    -1,   201,    -1,   241,
      -1,    28,    78,    -1,    29,    78,    -1,    -1,    30,   130,
      36,   163,   164,    37,    -1,    -1,   164,   165,    -1,    -1,
      40,   166,   168,    41,    -1,   239,    -1,    42,    -1,   167,
      -1,   168,   167,    -1,    -1,    36,   170,   171,   175,    37,
      -1,    -1,   183,    -1,   186,    -1,   200,    -1,    -1,    43,
      -1,   172,   173,   171,    -1,    -1,   175,   174,    -1,    -1,
      36,   177,   171,   182,    37,    -1,    -1,    -1,   179,     7,
     240,   180,   176,    -1,   178,   173,   171,    -1,    -1,   182,
     181,    -1,   214,   185,    -1,    43,   171,    -1,    -1,   184,
      -1,   187,    -1,   194,    -1,   190,    -1,    -1,    -1,    44,
     188,   189,   169,    -1,    -1,    -1,    -1,     7,   191,   192,
     240,   193,   169,    -1,    -1,    -1,   195,   196,   169,   199,
      -1,    -1,    45,   198,   169,    -1,    -1,   197,   199,    -1,
      46,   201,    -1,   263,    -1,   264,    -1,   202,    -1,   279,
     203,    -1,   206,    -1,    47,   243,    -1,    -1,   205,   204,
      -1,    99,    -1,    -1,    40,   243,   207,   205,    41,    -1,
      -1,    36,   209,   210,    37,    -1,    -1,   211,    -1,   214,
     213,    -1,    43,   210,    -1,    -1,   212,    -1,    -1,   239,
     215,   217,    -1,    -1,   229,   216,   222,    -1,   228,   224,
     221,    -1,   228,   224,    -1,    -1,   218,    -1,    48,   219,
      -1,    -1,   221,   220,    -1,   223,    -1,    -1,   217,    -1,
     227,   226,    -1,    47,   227,    -1,    -1,   226,   225,    -1,
     238,    -1,   240,    -1,    49,    -1,   232,    -1,   230,    -1,
      -1,    50,   231,   217,    51,    -1,   234,    40,   237,    41,
      -1,    31,    -1,    32,    -1,    33,    -1,    34,    -1,    35,
      -1,    -1,   233,    -1,    -1,   235,   238,    -1,   238,   235,
      -1,    -1,   236,    -1,   239,    -1,   229,    -1,   241,    -1,
     242,    -1,   241,    -1,   279,    -1,    96,    -1,    97,    -1,
     279,    -1,   269,    -1,   273,    -1,   277,    -1,   281,    -1,
      99,    -1,   244,    -1,   247,   246,    -1,    52,   247,    -1,
      -1,   246,   245,    -1,   250,   249,    -1,    53,   250,    -1,
      -1,   249,   248,    -1,   251,    -1,   254,   253,    -1,    54,
     254,    -1,    55,   254,    -1,    56,   254,    -1,    57,   254,
      -1,    58,   254,    -1,    59,   254,    -1,    -1,   252,    -1,
     255,    -1,   258,   257,    -1,    60,   258,    -1,    61,   258,
      -1,   275,    -1,   276,    -1,    -1,   257,   256,    -1,   261,
     260,    -1,    19,   261,    -1,    62,   261,    -1,    -1,   260,
     259,    -1,    63,   262,    -1,    60,   262,    -1,    61,   262,
      -1,   262,    -1,   263,    -1,   264,    -1,   267,    -1,   269,
      -1,   273,    -1,   277,    -1,   241,    -1,    40,   243,    41,
      -1,    64,    40,   243,    41,    -1,    65,    40,   243,    41,
      -1,    66,    40,   243,    47,   243,    41,    -1,    67,    40,
     243,    41,    -1,    68,    40,   241,    41,    -1,    69,    40,
     243,    47,   243,    41,    -1,    70,    40,   243,    41,    -1,
      71,    40,   243,    41,    -1,    72,    40,   243,    41,    -1,
      73,    40,   243,    41,    -1,   265,    -1,    74,    40,   243,
      47,   243,   266,    41,    -1,    -1,   204,    -1,   279,   268,
      -1,    -1,   203,    -1,   278,   272,    -1,    75,   279,    -1,
      98,    -1,   270,    -1,    -1,   271,    -1,   274,    -1,   275,
      -1,   276,    -1,    78,    -1,    79,    -1,    80,    -1,    81,
      -1,    82,    -1,    83,    -1,    84,    -1,    85,    -1,    86,
      -1,    76,    -1,    77,    -1,    87,    -1,    89,    -1,    88,
      -1,    90,    -1,    91,    -1,   280,    -1,    93,    -1,    92,
      -1,    94,    -1,    95,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  SPARQLfedParser::yyprhs_[] =
  {
         0,     0,     3,     6,     8,    10,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    33,    34,    39,    40,    45,
      49,    52,    54,    57,    60,    61,    63,    66,    67,    69,
      71,    73,    77,    78,    80,    84,    87,    88,    90,    91,
      94,    97,    98,    99,   105,   112,   114,   116,   117,   119,
     121,   124,   126,   128,   129,   132,   138,   144,   146,   149,
     151,   153,   154,   156,   160,   163,   165,   167,   169,   172,
     174,   178,   179,   181,   182,   184,   187,   188,   190,   191,
     193,   195,   196,   198,   199,   201,   204,   207,   211,   213,
     216,   218,   220,   222,   224,   227,   229,   231,   234,   237,
     238,   245,   246,   249,   250,   255,   257,   259,   261,   264,
     265,   271,   272,   274,   276,   278,   279,   281,   285,   286,
     289,   290,   296,   297,   298,   304,   308,   309,   312,   315,
     318,   319,   321,   323,   325,   327,   328,   329,   334,   335,
     336,   337,   344,   345,   346,   351,   352,   356,   357,   360,
     363,   365,   367,   369,   372,   374,   377,   378,   381,   383,
     384,   390,   391,   396,   397,   399,   402,   405,   406,   408,
     409,   413,   414,   418,   422,   425,   426,   428,   431,   432,
     435,   437,   438,   440,   443,   446,   447,   450,   452,   454,
     456,   458,   460,   461,   466,   471,   473,   475,   477,   479,
     481,   482,   484,   485,   488,   491,   492,   494,   496,   498,
     500,   502,   504,   506,   508,   510,   512,   514,   516,   518,
     520,   522,   524,   527,   530,   531,   534,   537,   540,   541,
     544,   546,   549,   552,   555,   558,   561,   564,   567,   568,
     570,   572,   575,   578,   581,   583,   585,   586,   589,   592,
     595,   598,   599,   602,   605,   608,   611,   613,   615,   617,
     619,   621,   623,   625,   627,   631,   636,   641,   648,   653,
     658,   665,   670,   675,   680,   685,   687,   695,   696,   698,
     701,   702,   704,   707,   710,   712,   714,   715,   717,   719,
     721,   723,   725,   727,   729,   731,   733,   735,   737,   739,
     741,   743,   745,   747,   749,   751,   753,   755,   757,   759,
     761,   763
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLfedParser::yyrline_[] =
  {
         0,   366,   366,   373,   374,   375,   376,   377,   378,   379,
     383,   384,   385,   386,   390,   397,   397,   406,   406,   415,
     421,   428,   431,   439,   446,   449,   453,   459,   462,   466,
     467,   471,   477,   480,   486,   493,   497,   499,   503,   505,
     509,   515,   517,   515,   527,   534,   537,   544,   547,   552,
     556,   564,   567,   574,   577,   585,   593,   600,   604,   612,
     615,   622,   625,   630,   637,   644,   645,   649,   655,   661,
     668,   675,   677,   681,   684,   689,   696,   699,   704,   708,
     713,   718,   721,   726,   729,   734,   738,   746,   753,   757,
     765,   767,   775,   778,   786,   794,   795,   801,   807,   814,
     814,   824,   827,   835,   835,   845,   846,   853,   857,   865,
     865,   876,   878,   883,   884,   888,   890,   895,   899,   902,
     907,   907,   917,   920,   917,   931,   935,   937,   942,   947,
     951,   954,   958,   959,   960,   964,   966,   964,   979,   981,
     983,   979,   995,   997,   995,  1007,  1007,  1015,  1017,  1021,
    1032,  1033,  1034,  1038,  1045,  1052,  1058,  1060,  1067,  1071,
    1071,  1081,  1081,  1089,  1091,  1096,  1101,  1105,  1107,  1111,
    1111,  1114,  1114,  1121,  1126,  1130,  1132,  1137,  1141,  1143,
    1148,  1152,  1154,  1159,  1164,  1168,  1170,  1174,  1181,  1185,
    1192,  1193,  1197,  1197,  1210,  1235,  1238,  1241,  1244,  1247,
    1254,  1257,  1262,  1265,  1273,  1290,  1293,  1297,  1298,  1302,
    1305,  1309,  1312,  1318,  1319,  1323,  1326,  1329,  1332,  1335,
    1336,  1342,  1347,  1356,  1363,  1366,  1374,  1383,  1390,  1393,
    1400,  1405,  1416,  1419,  1422,  1425,  1428,  1431,  1438,  1442,
    1446,  1451,  1460,  1463,  1466,  1469,  1476,  1479,  1487,  1496,
    1499,  1506,  1509,  1516,  1519,  1522,  1525,  1529,  1530,  1531,
    1532,  1535,  1538,  1541,  1547,  1553,  1556,  1559,  1562,  1565,
    1568,  1571,  1574,  1577,  1580,  1583,  1588,  1595,  1598,  1602,
    1612,  1615,  1620,  1628,  1635,  1639,  1647,  1651,  1655,  1656,
    1657,  1661,  1662,  1663,  1667,  1668,  1669,  1673,  1674,  1675,
    1679,  1680,  1684,  1685,  1686,  1687,  1691,  1692,  1696,  1697,
    1701,  1702
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
  const int SPARQLfedParser::yylast_ = 761;
  const int SPARQLfedParser::yynnts_ = 182;
  const int SPARQLfedParser::yyempty_ = -2;
  const int SPARQLfedParser::yyfinal_ = 7;
  const int SPARQLfedParser::yyterror_ = 1;
  const int SPARQLfedParser::yyerrcode_ = 256;
  const int SPARQLfedParser::yyntokens_ = 100;

  const unsigned int SPARQLfedParser::yyuser_token_number_max_ = 354;
  const SPARQLfedParser::token_number_type SPARQLfedParser::yyundef_token_ = 2;

} // namespace w3c_sw

#line 1707 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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


