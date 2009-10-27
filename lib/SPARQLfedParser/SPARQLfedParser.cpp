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
#line 230 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

#include "../SPARQLfedScanner.hpp"
#line 347 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

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
#line 362 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(2) - (2)].p_Operation);
    ;}
    break;

  case 14:
#line 386 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Replace((yysemantic_stack_[(4) - (2)].p_WhereClause), driver.curOp);
	driver.curOp = NULL;
    ;}
    break;

  case 15:
#line 393 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      ;}
    break;

  case 16:
#line 396 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Insert((yysemantic_stack_[(4) - (3)].p_TableOperation), (yysemantic_stack_[(4) - (4)].p_WhereClause));
      ;}
    break;

  case 17:
#line 402 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      ;}
    break;

  case 18:
#line 405 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(4) - (3)].p_TableOperation), (yysemantic_stack_[(4) - (4)].p_WhereClause));
      ;}
    break;

  case 19:
#line 411 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(3) - (2)].p_URIs), (yysemantic_stack_[(3) - (3)].p_URI));
    ;}
    break;

  case 20:
#line 417 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(2) - (2)].p_URI));
    ;}
    break;

  case 21:
#line 424 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URIs) = new ProductionVector<const URI*>((yysemantic_stack_[(1) - (1)].p_URI));
    ;}
    break;

  case 22:
#line 427 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_URIs)->push_back((yysemantic_stack_[(2) - (2)].p_URI));
	(yyval.p_URIs) = (yysemantic_stack_[(2) - (1)].p_URIs);
    ;}
    break;

  case 23:
#line 435 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    ;}
    break;

  case 24:
#line 442 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    ;}
    break;

  case 26:
#line 449 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    ;}
    break;

  case 27:
#line 455 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    ;}
    break;

  case 31:
#line 467 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    ;}
    break;

  case 32:
#line 473 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    ;}
    break;

  case 33:
#line 476 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
;}
    break;

  case 34:
#line 482 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
;}
    break;

  case 40:
#line 505 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI));
    ;}
    break;

  case 41:
#line 511 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ignorePrefix(true);
      ;}
    break;

  case 42:
#line 513 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.ignorePrefix(false);
      ;}
    break;

  case 43:
#line 515 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      ;}
    break;

  case 44:
#line 523 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Select((yysemantic_stack_[(6) - (2)].p_distinctness), (yysemantic_stack_[(6) - (3)].p_VarSet), (yysemantic_stack_[(6) - (4)].p_DatasetClauses), (yysemantic_stack_[(6) - (5)].p_WhereClause), (yysemantic_stack_[(6) - (6)].p_SolutionModifier));
    ;}
    break;

  case 45:
#line 530 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    ;}
    break;

  case 46:
#line 533 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    ;}
    break;

  case 47:
#line 540 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    ;}
    break;

  case 49:
#line 548 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POSList) = new POSList;
	(yyval.p_POSList)->push_back((yysemantic_stack_[(1) - (1)].p_Variable));
    ;}
    break;

  case 50:
#line 552 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSList)->push_back((yysemantic_stack_[(2) - (2)].p_Variable));
	(yyval.p_POSList) = (yysemantic_stack_[(2) - (1)].p_POSList);
    ;}
    break;

  case 51:
#line 560 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_POSList);
    ;}
    break;

  case 52:
#line 563 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    ;}
    break;

  case 53:
#line 570 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    ;}
    break;

  case 54:
#line 573 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    ;}
    break;

  case 55:
#line 581 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	/* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	(yyval.p_Operation) = new Construct((DefaultGraphPattern*)(yysemantic_stack_[(5) - (2)].p_BasicGraphPattern), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    ;}
    break;

  case 56:
#line 589 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    ;}
    break;

  case 57:
#line 596 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POSList) = new POSList;
	(yyval.p_POSList)->push_back((yysemantic_stack_[(1) - (1)].p_POS));
    ;}
    break;

  case 58:
#line 600 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSList)->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSList) = (yysemantic_stack_[(2) - (1)].p_POSList);
    ;}
    break;

  case 59:
#line 608 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_POSList);
    ;}
    break;

  case 60:
#line 611 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    ;}
    break;

  case 61:
#line 618 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    ;}
    break;

  case 63:
#line 626 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(3) - (2)].p_DatasetClauses), (yysemantic_stack_[(3) - (3)].p_WhereClause));
    ;}
    break;

  case 64:
#line 633 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    ;}
    break;

  case 67:
#line 645 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_POS), driver.posFactory);
    ;}
    break;

  case 68:
#line 651 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_POS), driver.posFactory);
    ;}
    break;

  case 69:
#line 657 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    ;}
    break;

  case 70:
#line 664 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.curOp, (yysemantic_stack_[(3) - (3)].p_BindingClause));
	driver.curOp = NULL;
    ;}
    break;

  case 73:
#line 677 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = NULL;
    ;}
    break;

  case 75:
#line 685 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(2) - (1)].p_OrderConditions), (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit, (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset);
    ;}
    break;

  case 76:
#line 692 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    ;}
    break;

  case 78:
#line 700 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    ;}
    break;

  case 81:
#line 714 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    ;}
    break;

  case 83:
#line 722 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    ;}
    break;

  case 85:
#line 730 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    ;}
    break;

  case 86:
#line 734 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    ;}
    break;

  case 87:
#line 742 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    ;}
    break;

  case 88:
#line 749 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    ;}
    break;

  case 89:
#line 753 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    ;}
    break;

  case 91:
#line 763 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    ;}
    break;

  case 92:
#line 771 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    ;}
    break;

  case 93:
#line 774 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    ;}
    break;

  case 94:
#line 782 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 96:
#line 791 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new VarExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    ;}
    break;

  case 97:
#line 797 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    ;}
    break;

  case 98:
#line 803 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    ;}
    break;

  case 99:
#line 810 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBindingClause = new BindingClause((yysemantic_stack_[(3) - (2)].p_POSList));
      ;}
    break;

  case 100:
#line 812 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = driver.curBindingClause;
	  driver.curBindingClause = NULL;
      ;}
    break;

  case 101:
#line 820 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Bindings) = NULL;
    ;}
    break;

  case 102:
#line 823 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBindingClause->push_back((yysemantic_stack_[(2) - (2)].p_Binding));
	(yyval.p_Bindings) = NULL;
    ;}
    break;

  case 103:
#line 831 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding = new Binding();
      ;}
    break;

  case 104:
#line 833 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Binding) = driver.curBinding;
	  driver.curBinding = NULL;
      ;}
    break;

  case 106:
#line 842 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = driver.getNULL();
    ;}
    break;

  case 107:
#line 849 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(1) - (1)].p_POS));
	(yyval.p_POSs) = NULL;
    ;}
    break;

  case 108:
#line 853 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSs) = NULL;
    ;}
    break;

  case 109:
#line 861 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = NULL;
	driver.curBGP = NULL;
      ;}
    break;

  case 110:
#line 864 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      ;}
    break;

  case 120:
#line 903 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      ;}
    break;

  case 121:
#line 906 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
      ;}
    break;

  case 122:
#line 913 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curFilter = NULL;
      ;}
    break;

  case 123:
#line 916 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_POS) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_POS);
      ;}
    break;

  case 124:
#line 919 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(5) - (3)].p_POS), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(5) - (4)].p_POS);
      ;}
    break;

  case 136:
#line 961 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      ;}
    break;

  case 137:
#line 963 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.curFilter;
      ;}
    break;

  case 138:
#line 965 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 139:
#line 977 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      ;}
    break;

  case 140:
#line 979 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      ;}
    break;

  case 141:
#line 981 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_POS) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_POS);
      ;}
    break;

  case 142:
#line 984 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_POS), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_POS);
      ;}
    break;

  case 143:
#line 992 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      ;}
    break;

  case 144:
#line 994 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      ;}
    break;

  case 145:
#line 996 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_POS) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_POS);
      ;}
    break;

  case 146:
#line 999 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(6) - (4)].p_POS), driver.curOp, driver.posFactory, false));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_POS);
      ;}
    break;

  case 147:
#line 1008 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      ;}
    break;

  case 148:
#line 1011 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      ;}
    break;

  case 149:
#line 1013 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      ;}
    break;

  case 150:
#line 1021 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curOp == NULL)
	    driver.ensureBasicGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      ;}
    break;

  case 151:
#line 1026 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  if (driver.curOp == NULL)
	      driver.ensureBasicGraphPattern();
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.curOp);
      ;}
    break;

  case 154:
#line 1041 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    if (driver.curOp == NULL)
		driver.ensureBasicGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 158:
#line 1058 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    ;}
    break;

  case 159:
#line 1065 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = new ArgList((yysemantic_stack_[(1) - (1)].p_Expressions));
    ;}
    break;

  case 160:
#line 1072 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 162:
#line 1080 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 163:
#line 1087 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    ;}
    break;

  case 164:
#line 1091 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      ;}
    break;

  case 165:
#line 1093 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = NULL;
      ;}
    break;

  case 166:
#line 1101 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      ;}
    break;

  case 167:
#line 1103 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      ;}
    break;

  case 174:
#line 1131 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_POS);
    ;}
    break;

  case 176:
#line 1134 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_POS);
    ;}
    break;

  case 192:
#line 1194 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.posFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_POS)));
    ;}
    break;

  case 193:
#line 1201 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_POS);
	driver.curPredicate = (yyval.p_POS);
    ;}
    break;

  case 194:
#line 1205 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_POS);
    ;}
    break;

  case 197:
#line 1217 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      ;}
    break;

  case 198:
#line 1221 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_POS) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      ;}
    break;

  case 199:
#line 1230 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 200:
#line 1255 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    ;}
    break;

  case 201:
#line 1258 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    ;}
    break;

  case 202:
#line 1261 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    ;}
    break;

  case 203:
#line 1264 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    ;}
    break;

  case 204:
#line 1267 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    ;}
    break;

  case 205:
#line 1274 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    ;}
    break;

  case 207:
#line 1282 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POSs) = new ProductionVector<const POS*>();
    ;}
    break;

  case 208:
#line 1285 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSs)->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSs) = (yysemantic_stack_[(2) - (1)].p_POSs);
    ;}
    break;

  case 209:
#line 1293 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 210:
#line 1310 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POSs) = new ProductionVector<const POS*>();
    ;}
    break;

  case 214:
#line 1322 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    ;}
    break;

  case 216:
#line 1329 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    ;}
    break;

  case 217:
#line 1332 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    ;}
    break;

  case 220:
#line 1343 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    ;}
    break;

  case 221:
#line 1346 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    ;}
    break;

  case 222:
#line 1349 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    ;}
    break;

  case 223:
#line 1352 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    ;}
    break;

  case 225:
#line 1356 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    ;}
    break;

  case 227:
#line 1367 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    ;}
    break;

  case 228:
#line 1376 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 229:
#line 1383 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    ;}
    break;

  case 230:
#line 1386 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    ;}
    break;

  case 231:
#line 1394 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    ;}
    break;

  case 232:
#line 1403 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 233:
#line 1410 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    ;}
    break;

  case 234:
#line 1413 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    ;}
    break;

  case 236:
#line 1425 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_BooleanComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_BooleanComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_BooleanComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    ;}
    break;

  case 237:
#line 1436 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 238:
#line 1439 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 239:
#line 1442 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 240:
#line 1445 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 241:
#line 1448 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yyval.p_BooleanComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 242:
#line 1451 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 243:
#line 1458 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = NULL;
    ;}
    break;

  case 246:
#line 1471 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    ;}
    break;

  case 247:
#line 1480 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 248:
#line 1483 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 249:
#line 1486 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    ;}
    break;

  case 250:
#line 1489 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    ;}
    break;

  case 251:
#line 1496 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    ;}
    break;

  case 252:
#line 1499 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    ;}
    break;

  case 253:
#line 1507 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    ;}
    break;

  case 254:
#line 1516 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 255:
#line 1519 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 256:
#line 1526 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    ;}
    break;

  case 257:
#line 1529 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    ;}
    break;

  case 258:
#line 1536 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 259:
#line 1539 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    ;}
    break;

  case 260:
#line 1542 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    ;}
    break;

  case 265:
#line 1552 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new LiteralExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    ;}
    break;

  case 266:
#line 1555 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    ;}
    break;

  case 267:
#line 1558 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    ;}
    break;

  case 268:
#line 1561 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new VarExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    ;}
    break;

  case 269:
#line 1567 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    ;}
    break;

  case 270:
#line 1573 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-str"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 271:
#line 1576 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-lang"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 272:
#line 1579 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-langMatches"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    ;}
    break;

  case 273:
#line 1582 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-datatype"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 274:
#line 1585 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-bound"), new VarExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    ;}
    break;

  case 275:
#line 1588 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-sameTerm"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    ;}
    break;

  case 276:
#line 1591 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 277:
#line 1594 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 278:
#line 1597 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isBlank"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 279:
#line 1600 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isLiteral"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    ;}
    break;

  case 281:
#line 1608 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-regex"), (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    ;}
    break;

  case 282:
#line 1615 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    ;}
    break;

  case 284:
#line 1622 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new URIExpression((yysemantic_stack_[(2) - (1)].p_URI));
    ;}
    break;

  case 285:
#line 1632 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    ;}
    break;

  case 287:
#line 1640 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    ;}
    break;

  case 288:
#line 1648 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    ;}
    break;

  case 289:
#line 1655 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    ;}
    break;

  case 290:
#line 1659 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    ;}
    break;

  case 291:
#line 1667 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    ;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 1830 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -277;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        -3,   -64,    41,   351,  -277,  -277,  -277,  -277,    15,    54,
      54,    55,    95,    60,    60,    29,    69,    36,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,    93,  -277,   107,    77,  -277,  -277,  -277,
    -277,  -277,  -277,    23,  -277,  -277,    55,  -277,  -277,  -277,
      95,    95,  -277,  -277,  -277,   -12,  -277,  -277,  -277,  -277,
    -277,    47,  -277,  -277,  -277,  -277,    -1,  -277,  -277,    54,
    -277,    87,   396,    40,    40,    55,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,   -31,  -277,  -277,   396,    -1,  -277,    28,
      33,  -277,  -277,    27,  -277,   396,   -31,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,    94,  -277,  -277,  -277,  -277,
      90,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
     -63,  -277,  -277,  -277,  -277,  -277,  -277,  -277,    -1,   104,
    -277,   106,   128,   128,    55,  -277,  -277,  -277,  -277,  -277,
    -277,  -277,   -27,    71,   123,   396,  -277,  -277,    71,   420,
      71,    55,  -277,  -277,  -277,  -277,   128,  -277,   396,  -277,
    -277,   140,  -277,    30,  -277,  -277,  -277,    79,   235,  -277,
    -277,   136,   513,  -277,  -277,   145,   183,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,   149,  -277,  -277,  -277,  -277,  -277,
    -277,   352,   113,   117,  -277,  -277,  -277,   169,   172,  -277,
    -277,  -277,  -277,  -277,   152,   145,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
     396,    47,  -277,   489,  -277,  -277,   630,   170,   173,   174,
     190,   194,   195,   197,   198,   200,   213,   214,   352,  -277,
     215,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,   -26,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
     396,    77,    66,   210,   216,  -277,  -277,  -277,   665,   665,
     665,  -277,   219,  -277,  -277,  -277,  -277,   148,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,   -26,   630,
     630,   630,   630,   -31,   630,   630,   630,   630,   630,   630,
    -277,  -277,   630,  -277,  -277,  -277,    47,    47,    77,  -277,
     217,  -277,  -277,  -277,    71,  -277,   513,  -277,    54,  -277,
    -277,  -277,  -277,   209,   211,   630,   630,   630,   630,   630,
     630,  -277,  -277,   251,     0,  -277,  -277,   225,   228,   223,
     230,   232,   229,   234,   236,   239,   241,   237,  -277,  -277,
    -277,  -277,  -277,   217,  -277,   545,  -277,  -277,   513,  -277,
    -277,   630,  -277,   630,  -277,  -277,  -277,  -277,  -277,  -277,
    -277,   630,   630,  -277,  -277,  -277,   630,   630,  -277,  -277,
    -277,   630,  -277,  -277,   630,  -277,  -277,  -277,  -277,   630,
    -277,    77,    77,    77,  -277,  -277,  -277,   572,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,   242,   256,   252,    -5,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,   630,  -277,   259,
    -277,  -277,  -277,  -277
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
     311,   314,   313,    24,    21,   312,     0,    28,    20,    33,
       0,     0,    45,    46,    48,     0,   166,    53,    60,   218,
     219,    59,    53,    57,   216,   217,    71,    41,    39,     0,
     109,    73,   111,    61,    61,     0,    25,    19,    22,    26,
      31,    34,    52,    51,    53,    49,   168,    71,    58,    61,
       0,    54,    63,     0,    14,   111,     0,    70,    74,   200,
     201,   202,   203,   204,   197,   305,   306,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   307,   309,   308,   310,
     315,   316,   225,   126,   112,   130,   176,   196,   195,   206,
       0,   174,   214,   215,   221,   222,   293,   294,   295,   223,
     291,   220,   224,    18,    62,    16,    23,    50,    71,     0,
     169,   172,    76,    76,     0,    64,    65,    66,    67,    69,
      42,   118,     0,     0,   122,   111,   131,   128,   186,   205,
       0,     0,   289,   290,   292,   287,    76,   167,   168,   173,
     170,     0,    55,    78,    77,    56,    68,     0,   147,    99,
     194,     0,   205,   193,   121,   115,     0,   127,   129,   187,
     177,   185,   213,   211,     0,   207,   212,   175,   288,    44,
     171,     0,     0,     0,    75,    79,    80,    81,    83,    43,
     139,   143,   110,   136,     0,   115,   119,   113,   132,   134,
     135,   133,   148,   114,   101,   198,   183,   190,   192,   116,
     111,     0,   199,   205,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    87,    88,
       0,    90,    91,    95,   157,    96,   155,   156,   280,     0,
      97,    98,    85,    82,    86,    84,   140,   144,   137,   154,
     111,     0,     0,   178,   188,   125,   123,   208,     0,     0,
       0,   268,     0,   226,   229,   233,   235,   243,   245,   251,
     256,   261,   262,   263,   264,   265,   266,   267,   285,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      89,    94,     0,   163,   158,   159,     0,     0,     0,   117,
     152,   100,   103,   102,   180,   184,   205,   191,     0,   259,
     260,   258,   269,   227,   231,     0,     0,     0,     0,     0,
       0,   244,   236,   246,   253,   286,   284,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   164,   141,
     145,   138,   150,   152,   149,     0,   181,   182,   205,   189,
     124,     0,   230,     0,   234,   237,   238,   239,   240,   241,
     242,     0,     0,   252,   249,   250,     0,     0,   257,   270,
     271,     0,   273,   274,     0,   276,   277,   278,   279,     0,
     161,     0,     0,     0,   153,   106,   107,     0,   105,   179,
     228,   232,   247,   248,   254,   255,     0,     0,   282,     0,
     142,   146,   151,   104,   108,   272,   275,     0,   283,     0,
     165,   162,   160,   281
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,    32,  -277,  -277,  -277,   288,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
     207,  -277,   -38,  -277,  -277,  -277,  -277,   -51,  -277,  -277,
    -277,  -277,  -277,   150,     3,  -277,  -277,  -132,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,    48,  -277,  -277,  -277,
      91,    97,  -277,  -277,  -277,  -277,  -277,  -106,  -277,  -276,
    -277,   -78,  -277,    92,  -277,  -277,    -7,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,   -53,  -277,    98,  -277,    13,  -105,  -277,
    -277,  -277,  -277,  -277,   161,  -277,  -277,  -277,   -85,  -277,
    -277,   -72,  -277,  -277,  -277,  -277,  -277,  -277,   -52,  -277,
    -277,    -9,    -6,  -162,  -277,  -277,  -277,  -277,  -277,  -277,
    -277,  -277,  -155,  -138,    -8,    17,  -277,   -23,  -277,  -277,
    -277,   -41,  -277,  -277,   -42,  -277,  -277,  -277,   -97,  -277,
    -277,  -277,  -236,  -277,  -277,  -213,  -112,  -166,  -182,  -277,
    -277,  -277,  -277,   -70,  -277,  -277,  -277,   -68,  -277,     2,
       5,   -46,  -277,   -11,  -277,  -277
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
     215,   272,   274,   216,   184,   258,   259,   260,   261,   262,
     217,   218,    98,   234,   282,   333,   375,   416,   417,    71,
      95,   123,   225,   240,   226,   188,    38,    72,   195,   196,
     338,   197,   164,   124,   166,   167,   227,   228,   278,   328,
     229,   276,   326,   411,   230,   277,   327,   412,   231,   232,
     281,   373,   413,   374,   233,   263,   264,   324,   438,   429,
     325,   410,    57,    86,   149,   150,   179,   180,   125,   170,
     168,   191,   376,   377,   335,   283,   200,   201,   236,   337,
     284,   237,   192,   126,   127,   163,   128,   129,   130,   243,
     203,   204,   238,   131,   193,   291,   133,   292,   293,   382,
     343,   294,   384,   344,   295,   296,   351,   352,   297,   298,
     393,   353,   299,   398,   354,   300,   301,   302,   303,   268,
     439,   304,   356,   305,   173,   174,   175,   306,   136,   137,
     138,   307,   140,   308,    45,   142
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int SPARQLfedParser::yytable_ninf_ = -211;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        44,   151,   134,    39,   135,   330,    65,   202,    82,    63,
     189,    35,     1,   171,   205,   322,   134,   161,   135,    87,
     396,   185,    90,   145,    89,   134,   139,   135,     6,   267,
     202,   206,    78,    75,    64,    79,   172,   440,   153,    34,
     139,     7,   267,   437,   209,   266,   148,    52,    53,   139,
      65,    90,   371,    88,   206,    34,    58,   154,   266,   212,
     213,   141,    94,   397,   146,   -71,    59,    60,    34,    92,
      59,    60,    85,    49,   323,   141,   267,   -71,    64,   159,
      34,   202,    80,    81,   141,    59,    60,   198,   287,   132,
     152,    37,   266,   151,   321,   134,   199,   135,   207,   134,
     147,   135,    46,   132,   331,   206,    56,   332,   134,    67,
     135,    69,   132,    85,    70,    40,    41,    42,    96,   139,
     160,   190,   134,   139,   135,    40,    41,    42,    40,    41,
      42,   169,   139,    59,    60,   430,   431,   432,   165,    40,
      41,    42,   177,   159,    59,    60,   139,    40,    41,    42,
     178,   176,    65,   181,   141,   422,   423,    65,   141,    65,
     208,   194,   285,    40,    41,    42,   211,   141,    59,    60,
     134,   219,   135,   134,   202,   135,   339,   340,   341,   147,
      64,   141,   132,   424,   425,    64,   132,    64,   235,   239,
     241,   242,   270,   246,   139,   132,   271,   139,   206,   213,
     269,   212,   329,   345,   346,   347,   348,   349,   350,   132,
     134,   309,   135,   269,   310,   311,   202,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   265,   141,
      65,   312,   141,   286,   139,   313,   314,   418,   315,   316,
     206,   317,   220,   221,    40,    41,    42,   269,   385,   386,
     387,   388,   389,   390,   318,   319,   246,   132,    64,   334,
     132,   342,   381,   372,   336,   383,   134,   399,   135,   141,
     400,   401,   402,   222,   403,   265,   405,   404,   406,   418,
     223,   407,   224,   408,   435,   409,   357,   358,   359,   360,
     139,   362,   363,   364,   365,   366,   367,   132,   436,   368,
     437,   443,    51,   162,   186,   134,   320,   135,   134,   275,
     135,   434,   391,   392,   273,    65,    65,   280,   369,   370,
     414,   355,   279,    65,   441,   141,   419,   379,   378,   139,
     361,   380,   139,   110,   111,   112,   113,   114,   115,   210,
     420,   421,     0,    64,    64,     0,     0,   134,     0,   135,
       0,    64,     0,   132,     8,   394,     9,    10,   395,     0,
      11,     0,    12,    13,   141,    14,     0,   141,    15,     0,
       0,   139,    16,    17,     0,     0,     0,     0,   426,   244,
     245,   427,     0,     0,     0,     0,   428,     0,     0,     0,
      18,     0,   132,   246,     0,   132,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,     0,     0,     0,
       0,     0,     0,     0,   442,     0,     0,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    99,   100,
     101,   102,   103,     0,   132,     0,     0,  -205,     0,     0,
       0,     0,     0,     0,    40,    41,    42,   104,     0,    59,
      60,     0,    99,   100,   101,   102,   103,     0,     0,     0,
       0,     0,  -210,     0,     0,     0,     0,     0,     0,     0,
       0,   104,     0,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,    40,    41,
      42,   120,   121,    59,    60,     0,   122,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,    40,    41,    42,   120,   121,    59,    60,     0,
     122,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,  -209,     0,     0,     0,     0,     0,     0,     0,     0,
     104,     0,     0,     0,     0,    99,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   104,     0,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,    40,    41,    42,   120,   121,    59,    60,   415,   122,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,    40,    41,    42,   120,   121,
      59,    60,     0,   122,   433,   415,     0,     0,     0,     0,
       0,     0,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,    40,    41,    42,
     120,   121,    59,    60,     0,   122,     0,     0,     0,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    40,    41,    42,   120,   121,    59,
      60,   246,   122,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   288,   289,     0,   290,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   246,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,    40,    41,    42,     0,     0,    59,    60,     0,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,     0,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,    40,    41,    42,
       0,     0,    59,    60
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        11,    86,    72,    10,    72,   281,    17,   169,    20,    17,
      37,     8,    15,    76,   169,    41,    86,    95,    86,    57,
      20,   153,    23,    74,    62,    95,    72,    95,    92,   211,
     192,   169,    43,    10,    17,    46,    99,    42,    89,    40,
      86,     0,   224,    48,   176,   211,    84,    18,    19,    95,
      61,    23,   328,    61,   192,    40,    20,    24,   224,    29,
      30,    72,    69,    63,    75,    37,    97,    98,    40,    66,
      97,    98,    55,    13,   100,    86,   258,    37,    61,    90,
      40,   243,    50,    51,    95,    97,    98,   165,   243,    72,
      87,    37,   258,   178,   260,   165,   168,   165,   170,   169,
      83,   169,     7,    86,    38,   243,    37,    41,   178,    16,
     178,     4,    95,    96,    37,    92,    93,    94,    31,   165,
      93,    50,   192,   169,   192,    92,    93,    94,    92,    93,
      94,    41,   178,    97,    98,   411,   412,   413,    44,    92,
      93,    94,    38,   154,    97,    98,   192,    92,    93,    94,
      44,   148,   163,    25,   165,   391,   392,   168,   169,   170,
     171,    38,   240,    92,    93,    94,    26,   178,    97,    98,
     240,    92,   240,   243,   336,   243,   288,   289,   290,   162,
     163,   192,   165,   396,   397,   168,   169,   170,    52,    44,
       7,    42,    79,    41,   240,   178,    79,   243,   336,    30,
     211,    29,   280,    55,    56,    57,    58,    59,    60,   192,
     280,    41,   280,   224,    41,    41,   378,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,   211,   240,
     241,    41,   243,   241,   280,    41,    41,   375,    41,    41,
     378,    41,     7,     8,    92,    93,    94,   258,   345,   346,
     347,   348,   349,   350,    41,    41,    41,   240,   241,    49,
     243,    42,    53,    46,    48,    54,   336,    42,   336,   280,
      42,    48,    42,    38,    42,   258,    42,    48,    42,   417,
      45,    42,    47,    42,    42,    48,   309,   310,   311,   312,
     336,   314,   315,   316,   317,   318,   319,   280,    42,   322,
      48,    42,    14,    96,   154,   375,   258,   375,   378,   218,
     378,   417,    61,    62,   217,   326,   327,   225,   326,   327,
     373,   308,   224,   334,   429,   336,   378,   336,   334,   375,
     313,   338,   378,    82,    83,    84,    85,    86,    87,   178,
     381,   383,    -1,   326,   327,    -1,    -1,   417,    -1,   417,
      -1,   334,    -1,   336,     3,   353,     5,     6,   353,    -1,
       9,    -1,    11,    12,   375,    14,    -1,   378,    17,    -1,
      -1,   417,    21,    22,    -1,    -1,    -1,    -1,   401,    27,
      28,   404,    -1,    -1,    -1,    -1,   409,    -1,    -1,    -1,
      39,    -1,   375,    41,    -1,   378,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   417,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   437,    -1,    -1,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    32,    33,
      34,    35,    36,    -1,   417,    -1,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    51,    -1,    97,
      98,    -1,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    -1,   100,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    -1,
     100,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    43,   100,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    -1,   100,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    -1,   100,    -1,    -1,    -1,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    41,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    62,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    41,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    -1,    97,    98,    -1,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    -1,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    97,    98
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLfedParser::yystos_[] =
  {
         0,    15,   102,   121,   122,   124,    92,     0,     3,     5,
       6,     9,    11,    12,    14,    17,    21,    22,    39,   103,
     104,   105,   106,   108,   110,   111,   117,   118,   120,   128,
     134,   135,   139,   123,    40,   145,   146,    37,   177,   177,
      92,    93,    94,   112,   284,   285,     7,   115,   116,    13,
     119,   119,    18,    19,   129,   130,    37,   213,    20,    97,
      98,   136,   137,   245,   246,   284,   133,    16,   125,     4,
      37,   170,   178,   109,   107,    10,   113,   114,   284,   284,
     115,   115,    20,   131,   132,   246,   214,   133,   245,   133,
      23,   140,   145,   126,   177,   171,    31,   147,   163,    32,
      33,    34,    35,    36,    51,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      95,    96,   100,   172,   184,   219,   234,   235,   237,   238,
     239,   244,   246,   247,   274,   278,   279,   280,   281,   282,
     283,   284,   286,   138,   145,   138,   284,   246,   133,   215,
     216,   219,   145,   138,    24,   141,   142,   143,   144,   284,
      93,   172,   131,   236,   183,    44,   185,   186,   221,    41,
     220,    76,    99,   275,   276,   277,   145,    38,    44,   217,
     218,    25,   148,   149,   155,   148,   144,   127,   176,    37,
      50,   222,   233,   245,    38,   179,   180,   182,   172,   222,
     227,   228,   234,   241,   242,   243,   244,   222,   284,   148,
     215,    26,    29,    30,   150,   151,   154,   161,   162,    92,
       7,     8,    38,    45,    47,   173,   175,   187,   188,   191,
     195,   199,   200,   205,   164,    52,   229,   232,   243,    44,
     174,     7,    42,   240,    27,    28,    41,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,   156,   157,
     158,   159,   160,   206,   207,   246,   268,   269,   270,   284,
      79,    79,   152,   162,   153,   161,   192,   196,   189,   206,
     174,   201,   165,   226,   231,   172,   245,   243,    61,    62,
      64,   246,   248,   249,   252,   255,   256,   259,   260,   263,
     266,   267,   268,   269,   272,   274,   278,   282,   284,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
     157,   268,    41,   100,   208,   211,   193,   197,   190,   172,
     170,    38,    41,   166,    49,   225,    48,   230,   181,   267,
     267,   267,    42,   251,   254,    55,    56,    57,    58,    59,
      60,   257,   258,   262,   265,   208,   273,   248,   248,   248,
     248,   246,   248,   248,   248,   248,   248,   248,   248,   245,
     245,   170,    46,   202,   204,   167,   223,   224,   233,   232,
     177,    53,   250,    54,   253,   259,   259,   259,   259,   259,
     259,    61,    62,   261,   280,   281,    20,    63,   264,    42,
      42,    48,    42,    42,    48,    42,    42,    42,    42,    48,
     212,   194,   198,   203,   204,    43,   168,   169,   244,   229,
     252,   255,   263,   263,   266,   266,   248,   248,   248,   210,
     170,   170,   170,    42,   168,    42,    42,    48,   209,   271,
      42,   209,   248,    42
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
     355
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  SPARQLfedParser::yyr1_[] =
  {
         0,   101,   102,   103,   103,   103,   103,   103,   103,   103,
     104,   104,   104,   104,   105,   107,   106,   109,   108,   110,
     111,   112,   112,   113,   114,   114,   115,   116,   116,   117,
     117,   118,   119,   119,   120,   121,   122,   122,   123,   123,
     124,   126,   127,   125,   128,   129,   129,   130,   130,   131,
     131,   132,   132,   133,   133,   134,   135,   136,   136,   137,
     137,   138,   138,   139,   140,   141,   141,   142,   143,   144,
     145,   146,   146,   147,   147,   148,   149,   149,   150,   150,
     151,   152,   152,   153,   153,   154,   154,   155,   156,   156,
     157,   157,   158,   158,   159,   160,   160,   161,   162,   164,
     163,   165,   165,   167,   166,   168,   168,   169,   169,   171,
     170,   172,   172,   173,   173,   174,   174,   175,   176,   176,
     178,   177,   180,   181,   179,   182,   183,   183,   184,   185,
     186,   186,   187,   187,   187,   187,   189,   190,   188,   192,
     193,   194,   191,   196,   197,   198,   195,   200,   201,   199,
     203,   202,   204,   204,   205,   206,   206,   206,   207,   208,
     209,   210,   210,   211,   212,   211,   214,   213,   215,   215,
     216,   217,   218,   218,   220,   219,   221,   219,   222,   223,
     224,   224,   225,   226,   226,   227,   228,   228,   229,   230,
     231,   231,   232,   233,   233,   234,   234,   236,   235,   237,
     238,   238,   238,   238,   238,   239,   239,   240,   240,   241,
     242,   242,   243,   243,   244,   244,   245,   245,   246,   246,
     247,   247,   247,   247,   247,   247,   248,   249,   250,   251,
     251,   252,   253,   254,   254,   255,   256,   257,   257,   257,
     257,   257,   257,   258,   258,   259,   260,   261,   261,   261,
     261,   262,   262,   263,   264,   264,   265,   265,   266,   266,
     266,   266,   267,   267,   267,   267,   267,   267,   267,   268,
     269,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     269,   270,   271,   271,   272,   273,   273,   274,   275,   276,
     276,   277,   277,   278,   278,   278,   279,   279,   279,   280,
     280,   280,   281,   281,   281,   282,   282,   283,   283,   283,
     283,   284,   284,   285,   285,   286,   286
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
       0,     1,     1,     1,     1,     1,     0,     0,     4,     0,
       0,     0,     6,     0,     0,     0,     6,     0,     0,     4,
       0,     3,     0,     2,     2,     1,     1,     1,     2,     1,
       2,     0,     2,     1,     0,     5,     0,     4,     0,     1,
       2,     2,     0,     1,     0,     3,     0,     3,     3,     2,
       0,     1,     2,     0,     2,     1,     0,     1,     2,     2,
       0,     2,     1,     1,     1,     1,     1,     0,     4,     4,
       1,     1,     1,     1,     1,     0,     1,     0,     2,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     0,
       2,     2,     2,     0,     2,     1,     2,     2,     2,     2,
       2,     2,     2,     0,     1,     1,     2,     2,     2,     1,
       1,     0,     2,     2,     2,     2,     0,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     4,     6,     4,     4,     6,     4,     4,     4,     4,
       1,     7,     0,     1,     2,     0,     1,     2,     2,     1,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const SPARQLfedParser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "IT_REPLACE", "IT_WITH",
  "IT_DELETE", "IT_INSERT", "IT_GRAPH", "IT_SERVICE", "IT_LOAD", "IT_INTO",
  "IT_CLEAR", "IT_CREATE", "IT_SILENT", "IT_DROP", "IT_BASE", "IT_PREFIX",
  "IT_SELECT", "IT_DISTINCT", "IT_REDUCED", "GT_TIMES", "IT_CONSTRUCT",
  "IT_DESCRIBE", "IT_FROM", "IT_NAMED", "IT_ORDER", "IT_BY", "IT_ASC",
  "IT_DESC", "IT_LIMIT", "IT_OFFSET", "IT_BINDINGS", "IT_MEMBERS",
  "IT_STARTS", "IT_ENDS", "IT_ANY", "IT_UNORDERED", "GT_LCURLEY",
  "GT_RCURLEY", "IT_ASK", "IT_WHERE", "GT_LPAREN", "GT_RPAREN", "IT_NULL",
  "GT_DOT", "IT_OPTIONAL", "IT_UNION", "IT_FILTER", "GT_COMMA", "GT_SEMI",
  "IT_a", "GT_LBRACKET", "GT_RBRACKET", "GT_OR", "GT_AND", "GT_EQUAL",
  "GT_NEQUAL", "GT_LT", "GT_GT", "GT_LE", "GT_GE", "GT_PLUS", "GT_MINUS",
  "GT_DIVIDE", "GT_NOT", "IT_STR", "IT_LANG", "IT_LANGMATCHES",
  "IT_DATATYPE", "IT_BOUND", "IT_sameTerm", "IT_isIRI", "IT_isURI",
  "IT_isBLANK", "IT_isLITERAL", "IT_REGEX", "GT_DTYPE", "IT_true",
  "IT_false", "INTEGER", "DECIMAL", "DOUBLE", "INTEGER_POSITIVE",
  "DECIMAL_POSITIVE", "DOUBLE_POSITIVE", "INTEGER_NEGATIVE",
  "DECIMAL_NEGATIVE", "DOUBLE_NEGATIVE", "STRING_LITERAL1",
  "STRING_LITERAL_LONG1", "STRING_LITERAL2", "STRING_LITERAL_LONG2",
  "IRI_REF", "PNAME_NS", "PNAME_LN", "BLANK_NODE_LABEL", "ANON", "VAR1",
  "VAR2", "LANGTAG", "NIL", "$accept", "Query",
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
  "@15", "ServiceGraphPattern", "@16", "@17", "@18",
  "GroupOrUnionGraphPattern", "@19", "@20",
  "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@21",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star",
  "_O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C",
  "@22", "ConstructTemplate", "@23", "_QConstructTriples_E_Opt",
  "ConstructTriples", "_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C_E_Opt", "TriplesSameSubject",
  "@24", "@25", "PropertyListNotEmpty", "_O_QVerb_E_S_QObjectList_E_C",
  "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "ObjectList",
  "_O_QGT_COMMA_E_S_QObject_E_C", "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star",
  "Object", "Verb", "TriplesNode", "BlankNodePropertyList", "@26",
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
       102,     0,    -1,   121,   103,    -1,   128,    -1,   134,    -1,
     135,    -1,   139,    -1,   105,    -1,   104,    -1,   117,    -1,
     106,    -1,   108,    -1,   110,    -1,   111,    -1,     3,   145,
       4,   177,    -1,    -1,     6,   177,   107,   138,    -1,    -1,
       5,   177,   109,   138,    -1,     9,   112,   114,    -1,    11,
     116,    -1,   284,    -1,   112,   284,    -1,    10,   284,    -1,
      -1,   113,    -1,     7,   284,    -1,    -1,   115,    -1,   118,
      -1,   120,    -1,    12,   119,   115,    -1,    -1,    13,    -1,
      14,   119,   115,    -1,   122,   123,    -1,    -1,   124,    -1,
      -1,   123,   125,    -1,    15,    92,    -1,    -1,    -1,    16,
     126,    93,   127,    92,    -1,    17,   130,   132,   133,   145,
     148,    -1,    18,    -1,    19,    -1,    -1,   129,    -1,   246,
      -1,   131,   246,    -1,   131,    -1,    20,    -1,    -1,   133,
     140,    -1,    21,   213,   133,   145,   148,    -1,    22,   137,
     133,   138,   148,    -1,   245,    -1,   136,   245,    -1,   136,
      -1,    20,    -1,    -1,   145,    -1,    39,   133,   145,    -1,
      23,   141,    -1,   142,    -1,   143,    -1,   144,    -1,    24,
     144,    -1,   284,    -1,   146,   170,   147,    -1,    -1,    40,
      -1,    -1,   163,    -1,   149,   150,    -1,    -1,   155,    -1,
      -1,   151,    -1,   154,    -1,    -1,   162,    -1,    -1,   161,
      -1,   161,   152,    -1,   162,   153,    -1,    25,    26,   156,
      -1,   157,    -1,   156,   157,    -1,   159,    -1,   160,    -1,
      27,    -1,    28,    -1,   158,   268,    -1,   206,    -1,   246,
      -1,    29,    79,    -1,    30,    79,    -1,    -1,    31,   131,
      37,   164,   165,    38,    -1,    -1,   165,   166,    -1,    -1,
      41,   167,   169,    42,    -1,   244,    -1,    43,    -1,   168,
      -1,   169,   168,    -1,    -1,    37,   171,   172,   176,    38,
      -1,    -1,   184,    -1,   187,    -1,   205,    -1,    -1,    44,
      -1,   173,   174,   172,    -1,    -1,   176,   175,    -1,    -1,
      37,   178,   172,   183,    38,    -1,    -1,    -1,   180,     7,
     245,   181,   177,    -1,   179,   174,   172,    -1,    -1,   183,
     182,    -1,   219,   186,    -1,    44,   172,    -1,    -1,   185,
      -1,   188,    -1,   199,    -1,   191,    -1,   195,    -1,    -1,
      -1,    45,   189,   190,   170,    -1,    -1,    -1,    -1,     7,
     192,   193,   245,   194,   170,    -1,    -1,    -1,    -1,     8,
     196,   197,   245,   198,   170,    -1,    -1,    -1,   200,   201,
     170,   204,    -1,    -1,    46,   203,   170,    -1,    -1,   202,
     204,    -1,    47,   206,    -1,   268,    -1,   269,    -1,   207,
      -1,   284,   208,    -1,   211,    -1,    48,   248,    -1,    -1,
     210,   209,    -1,   100,    -1,    -1,    41,   248,   212,   210,
      42,    -1,    -1,    37,   214,   215,    38,    -1,    -1,   216,
      -1,   219,   218,    -1,    44,   215,    -1,    -1,   217,    -1,
      -1,   244,   220,   222,    -1,    -1,   234,   221,   227,    -1,
     233,   229,   226,    -1,   233,   229,    -1,    -1,   223,    -1,
      49,   224,    -1,    -1,   226,   225,    -1,   228,    -1,    -1,
     222,    -1,   232,   231,    -1,    48,   232,    -1,    -1,   231,
     230,    -1,   243,    -1,   245,    -1,    50,    -1,   237,    -1,
     235,    -1,    -1,    51,   236,   222,    52,    -1,   239,    41,
     242,    42,    -1,    32,    -1,    33,    -1,    34,    -1,    35,
      -1,    36,    -1,    -1,   238,    -1,    -1,   240,   243,    -1,
     243,   240,    -1,    -1,   241,    -1,   244,    -1,   234,    -1,
     246,    -1,   247,    -1,   246,    -1,   284,    -1,    97,    -1,
      98,    -1,   284,    -1,   274,    -1,   278,    -1,   282,    -1,
     286,    -1,   100,    -1,   249,    -1,   252,   251,    -1,    53,
     252,    -1,    -1,   251,   250,    -1,   255,   254,    -1,    54,
     255,    -1,    -1,   254,   253,    -1,   256,    -1,   259,   258,
      -1,    55,   259,    -1,    56,   259,    -1,    57,   259,    -1,
      58,   259,    -1,    59,   259,    -1,    60,   259,    -1,    -1,
     257,    -1,   260,    -1,   263,   262,    -1,    61,   263,    -1,
      62,   263,    -1,   280,    -1,   281,    -1,    -1,   262,   261,
      -1,   266,   265,    -1,    20,   266,    -1,    63,   266,    -1,
      -1,   265,   264,    -1,    64,   267,    -1,    61,   267,    -1,
      62,   267,    -1,   267,    -1,   268,    -1,   269,    -1,   272,
      -1,   274,    -1,   278,    -1,   282,    -1,   246,    -1,    41,
     248,    42,    -1,    65,    41,   248,    42,    -1,    66,    41,
     248,    42,    -1,    67,    41,   248,    48,   248,    42,    -1,
      68,    41,   248,    42,    -1,    69,    41,   246,    42,    -1,
      70,    41,   248,    48,   248,    42,    -1,    71,    41,   248,
      42,    -1,    72,    41,   248,    42,    -1,    73,    41,   248,
      42,    -1,    74,    41,   248,    42,    -1,   270,    -1,    75,
      41,   248,    48,   248,   271,    42,    -1,    -1,   209,    -1,
     284,   273,    -1,    -1,   208,    -1,   283,   277,    -1,    76,
     284,    -1,    99,    -1,   275,    -1,    -1,   276,    -1,   279,
      -1,   280,    -1,   281,    -1,    79,    -1,    80,    -1,    81,
      -1,    82,    -1,    83,    -1,    84,    -1,    85,    -1,    86,
      -1,    87,    -1,    77,    -1,    78,    -1,    88,    -1,    90,
      -1,    89,    -1,    91,    -1,    92,    -1,   285,    -1,    94,
      -1,    93,    -1,    95,    -1,    96,    -1
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
     318,   319,   321,   323,   325,   327,   329,   330,   331,   336,
     337,   338,   339,   346,   347,   348,   349,   356,   357,   358,
     363,   364,   368,   369,   372,   375,   377,   379,   381,   384,
     386,   389,   390,   393,   395,   396,   402,   403,   408,   409,
     411,   414,   417,   418,   420,   421,   425,   426,   430,   434,
     437,   438,   440,   443,   444,   447,   449,   450,   452,   455,
     458,   459,   462,   464,   466,   468,   470,   472,   473,   478,
     483,   485,   487,   489,   491,   493,   494,   496,   497,   500,
     503,   504,   506,   508,   510,   512,   514,   516,   518,   520,
     522,   524,   526,   528,   530,   532,   534,   536,   539,   542,
     543,   546,   549,   552,   553,   556,   558,   561,   564,   567,
     570,   573,   576,   579,   580,   582,   584,   587,   590,   593,
     595,   597,   598,   601,   604,   607,   610,   611,   614,   617,
     620,   623,   625,   627,   629,   631,   633,   635,   637,   639,
     643,   648,   653,   660,   665,   670,   677,   682,   687,   692,
     697,   699,   707,   708,   710,   713,   714,   716,   719,   722,
     724,   726,   727,   729,   731,   733,   735,   737,   739,   741,
     743,   745,   747,   749,   751,   753,   755,   757,   759,   761,
     763,   765,   767,   769,   771,   773,   775
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLfedParser::yyrline_[] =
  {
         0,   362,   362,   369,   370,   371,   372,   373,   374,   375,
     379,   380,   381,   382,   386,   393,   393,   402,   402,   411,
     417,   424,   427,   435,   442,   445,   449,   455,   458,   462,
     463,   467,   473,   476,   482,   489,   493,   495,   499,   501,
     505,   511,   513,   511,   523,   530,   533,   540,   543,   548,
     552,   560,   563,   570,   573,   581,   589,   596,   600,   608,
     611,   618,   621,   626,   633,   640,   641,   645,   651,   657,
     664,   671,   673,   677,   680,   685,   692,   695,   700,   704,
     709,   714,   717,   722,   725,   730,   734,   742,   749,   753,
     761,   763,   771,   774,   782,   790,   791,   797,   803,   810,
     810,   820,   823,   831,   831,   841,   842,   849,   853,   861,
     861,   872,   874,   879,   880,   884,   886,   891,   895,   898,
     903,   903,   913,   916,   913,   927,   931,   933,   938,   943,
     947,   950,   954,   955,   956,   957,   961,   963,   961,   977,
     979,   981,   977,   992,   994,   996,   992,  1008,  1011,  1008,
    1021,  1021,  1035,  1037,  1041,  1052,  1053,  1054,  1058,  1065,
    1072,  1078,  1080,  1087,  1091,  1091,  1101,  1101,  1109,  1111,
    1116,  1121,  1125,  1127,  1131,  1131,  1134,  1134,  1141,  1146,
    1150,  1152,  1157,  1161,  1163,  1168,  1172,  1174,  1179,  1184,
    1188,  1190,  1194,  1201,  1205,  1212,  1213,  1217,  1217,  1230,
    1255,  1258,  1261,  1264,  1267,  1274,  1277,  1282,  1285,  1293,
    1310,  1313,  1317,  1318,  1322,  1325,  1329,  1332,  1338,  1339,
    1343,  1346,  1349,  1352,  1355,  1356,  1362,  1367,  1376,  1383,
    1386,  1394,  1403,  1410,  1413,  1420,  1425,  1436,  1439,  1442,
    1445,  1448,  1451,  1458,  1462,  1466,  1471,  1480,  1483,  1486,
    1489,  1496,  1499,  1507,  1516,  1519,  1526,  1529,  1536,  1539,
    1542,  1545,  1549,  1550,  1551,  1552,  1555,  1558,  1561,  1567,
    1573,  1576,  1579,  1582,  1585,  1588,  1591,  1594,  1597,  1600,
    1603,  1608,  1615,  1618,  1622,  1632,  1635,  1640,  1648,  1655,
    1659,  1667,  1671,  1675,  1676,  1677,  1681,  1682,  1683,  1687,
    1688,  1689,  1693,  1694,  1695,  1699,  1700,  1704,  1705,  1706,
    1707,  1711,  1712,  1716,  1717,  1721,  1722
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
      95,    96,    97,    98,    99,   100
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int SPARQLfedParser::yyeof_ = 0;
  const int SPARQLfedParser::yylast_ = 763;
  const int SPARQLfedParser::yynnts_ = 186;
  const int SPARQLfedParser::yyempty_ = -2;
  const int SPARQLfedParser::yyfinal_ = 7;
  const int SPARQLfedParser::yyterror_ = 1;
  const int SPARQLfedParser::yyerrcode_ = 256;
  const int SPARQLfedParser::yyntokens_ = 101;

  const unsigned int SPARQLfedParser::yyuser_token_number_max_ = 355;
  const SPARQLfedParser::token_number_type SPARQLfedParser::yyundef_token_ = 2;

} // namespace w3c_sw

#line 1727 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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


