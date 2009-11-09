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

#include "TurtleSParser.hpp"

/* User implementation prologue.  */
#line 120 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"

#include "../TurtleSScanner.hpp"
#line 171 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"

#include "../TurtleSScanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc.  */
#line 57 "\\\\vboxsvr\\sparul\\lib\\TurtleSParser\\TurtleSParser.cpp"

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
  TurtleSParser::yytnamerr_ (const char *yystr)
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
  TurtleSParser::TurtleSParser (class TurtleSDriver& driver_yyarg)
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
      driver (driver_yyarg)
  {
  }

  TurtleSParser::~TurtleSParser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  TurtleSParser::yy_symbol_value_print_ (int yytype,
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
  TurtleSParser::yy_symbol_print_ (int yytype,
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
  TurtleSParser::yydestruct_ (const char* yymsg,
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
  TurtleSParser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

  std::ostream&
  TurtleSParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  TurtleSParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  TurtleSParser::debug_level_type
  TurtleSParser::debug_level () const
  {
    return yydebug_;
  }

  void
  TurtleSParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }


  int
  TurtleSParser::parse ()
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
    #line 31 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}
  /* Line 547 of yacc.c.  */
#line 294 "\\\\vboxsvr\\sparul\\lib\\TurtleSParser\\TurtleSParser.cpp"
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
#line 186 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	driver.root = (yysemantic_stack_[(2) - (2)].p_DefaultGraphPattern);
    ;}
    break;

  case 8:
#line 209 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI));
    ;}
    break;

  case 9:
#line 215 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	driver.ignorePrefix(true);
      ;}
    break;

  case 10:
#line 217 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	  driver.ignorePrefix(false);
      ;}
    break;

  case 11:
#line 219 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      ;}
    break;

  case 13:
#line 227 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    { (yyval.p_DefaultGraphPattern) = NULL; ;}
    break;

  case 14:
#line 228 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_DefaultGraphPattern) = (yysemantic_stack_[(1) - (1)].p_DefaultGraphPattern);
    ;}
    break;

  case 15:
#line 235 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_DefaultGraphPattern) = driver.neededBGP ? driver.neededBGP : (yysemantic_stack_[(2) - (2)].p_DefaultGraphPattern);
	driver.neededBGP = NULL;
    ;}
    break;

  case 16:
#line 243 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_DefaultGraphPattern) = (yysemantic_stack_[(2) - (2)].p_DefaultGraphPattern);
    ;}
    break;

  case 17:
#line 250 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    { (yyval.p_DefaultGraphPattern) = NULL; ;}
    break;

  case 19:
#line 255 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_POS);
    ;}
    break;

  case 21:
#line 258 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_BNode);
    ;}
    break;

  case 37:
#line 318 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	if (!driver.curBGP)
	    driver.neededBGP = driver.curBGP = new DefaultGraphPattern();
	driver.curBGP->addTriplePattern(driver.posFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_POS)));
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_POS);
    ;}
    break;

  case 38:
#line 327 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_POS);
	driver.curPredicate = (yyval.p_POS);
    ;}
    break;

  case 39:
#line 331 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_POS) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_POS);
    ;}
    break;

  case 40:
#line 338 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_BNode) = (yysemantic_stack_[(1) - (1)].p_BNode);
    ;}
    break;

  case 41:
#line 341 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_BNode) = (yysemantic_stack_[(1) - (1)].p_BNode);
    ;}
    break;

  case 42:
#line 347 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      ;}
    break;

  case 43:
#line 351 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	  (yyval.p_BNode) = (BNode*)driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      ;}
    break;

  case 44:
#line 360 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_BNode) = driver.createBNode();
	const POS* tail = (yyval.p_BNode);
	ProductionVector<const POS*>* members = (yysemantic_stack_[(3) - (2)].p_POSs);
	const URI* first = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#first");
	const URI* rest = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#rest");
	const POS* nil = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil");
	if (!driver.curBGP)
	    driver.neededBGP = driver.curBGP = new DefaultGraphPattern();
	for (unsigned i = 0; i < members->size(); i++) {
	    driver.curBGP->addTriplePattern(driver.posFactory->getTriple(tail, first, members->at(i)));
	    const POS* nextTail = i == members->size()-1 ? nil : driver.createBNode();
	    driver.curBGP->addTriplePattern(driver.posFactory->getTriple(tail, rest, nextTail));
	    tail = nextTail;
	}
	members->clear();
	delete members;
    ;}
    break;

  case 45:
#line 382 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_POSs) = new ProductionVector<const POS*>((yysemantic_stack_[(1) - (1)].p_POS));
    ;}
    break;

  case 46:
#line 385 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSs)->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSs) = (yysemantic_stack_[(2) - (1)].p_POSs);
    ;}
    break;

  case 47:
#line 392 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_POS);
    ;}
    break;

  case 48:
#line 395 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_BNode);
    ;}
    break;

  case 49:
#line 401 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_POS);
    ;}
    break;

  case 50:
#line 407 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    ;}
    break;

  case 51:
#line 413 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    ;}
    break;

  case 52:
#line 416 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    ;}
    break;

  case 53:
#line 419 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    ;}
    break;

  case 54:
#line 422 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    ;}
    break;

  case 55:
#line 425 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_POS);
    ;}
    break;

  case 56:
#line 428 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_POS) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    ;}
    break;

  case 57:
#line 435 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    ;}
    break;

  case 58:
#line 443 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    ;}
    break;

  case 59:
#line 450 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    ;}
    break;

  case 60:
#line 454 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    ;}
    break;

  case 61:
#line 462 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    ;}
    break;

  case 62:
#line 466 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_uri_or_langtag) = (yysemantic_stack_[(1) - (1)].p_uri_or_langtag);
    ;}
    break;

  case 63:
#line 472 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    ;}
    break;

  case 64:
#line 475 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    ;}
    break;

  case 65:
#line 478 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    ;}
    break;

  case 66:
#line 484 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    ;}
    break;

  case 67:
#line 487 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    ;}
    break;

  case 68:
#line 490 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    ;}
    break;

  case 69:
#line 496 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    ;}
    break;

  case 70:
#line 499 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    ;}
    break;

  case 71:
#line 502 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    ;}
    break;

  case 72:
#line 508 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    ;}
    break;

  case 73:
#line 511 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    ;}
    break;

  case 74:
#line 514 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    ;}
    break;

  case 75:
#line 520 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_BooleanRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    ;}
    break;

  case 76:
#line 523 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_BooleanRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    ;}
    break;

  case 77:
#line 529 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_string) = (yysemantic_stack_[(1) - (1)].p_string);
    ;}
    break;

  case 78:
#line 532 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_string) = (yysemantic_stack_[(1) - (1)].p_string);
    ;}
    break;

  case 79:
#line 535 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_string) = (yysemantic_stack_[(1) - (1)].p_string);
    ;}
    break;

  case 80:
#line 538 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_string) = (yysemantic_stack_[(1) - (1)].p_string);
    ;}
    break;

  case 81:
#line 544 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    ;}
    break;

  case 82:
#line 547 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    ;}
    break;

  case 83:
#line 553 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    ;}
    break;

  case 84:
#line 556 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    ;}
    break;

  case 85:
#line 562 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_BNode);
    ;}
    break;

  case 86:
#line 565 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_BNode);
    ;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 872 "\\\\vboxsvr\\sparul\\lib\\TurtleSParser\\TurtleSParser.cpp"
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
  TurtleSParser::yysyntax_error_ (int yystate, int tok)
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
  const signed char TurtleSParser::yypact_ninf_ = -52;
  const signed char
  TurtleSParser::yypact_[] =
  {
         3,   -17,    35,    38,   -52,   -52,   -52,   -52,    38,   -52,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
     -52,   -52,   -52,    30,   -52,   -52,   -52,   -52,   -52,   -52,
     -52,   -52,   -52,   -52,   -52,    62,   -52,   -52,   -52,    37,
     -52,    -1,   -52,   -52,    64,    38,   -52,   -52,    64,    64,
     -20,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
      32,    38,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
      10,   -52,   -52,   -52,   -52,   -52,    39,    42,    15,    64,
     -52,    38,   -52,   -52,   -52,   -52,    38,   -52,    40,   -52,
     -52
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  TurtleSParser::yydefact_[] =
  {
         4,     0,     0,    13,     6,     5,     8,     1,     0,    42,
      75,    76,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    77,    78,    79,    80,    81,    84,    83,    85,    86,
      56,     2,    14,    17,    21,    41,    40,    19,    49,    52,
      53,    63,    64,    65,    54,    61,    51,    82,    55,     3,
      48,     0,    45,    47,     0,    13,    18,    15,    31,     0,
       0,    59,    60,    62,    57,     9,     7,    44,    46,    39,
       0,     0,    38,    50,    16,    32,    22,    30,    20,    58,
       0,    43,    28,    35,    37,    10,    23,    33,     0,    25,
      29,     0,    36,    11,    26,    27,     0,    34,     0,    24,
      12
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  TurtleSParser::yypgoto_[] =
  {
       -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
      -4,   -52,   -52,   -52,   -52,   -52,   -52,   -19,   -52,   -52,
     -52,   -52,   -52,   -52,   -18,   -52,   -52,   -15,   -10,    -3,
     -52,   -52,   -52,   -52,    -6,    -2,   -52,   -52,   -52,   -52,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -51,   -52,
     -52
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  TurtleSParser::yydefgoto_[] =
  {
        -1,     2,     3,     4,    49,     5,    66,    80,    88,    98,
      31,    32,    56,    57,    33,    59,    58,    70,    94,    95,
      90,    86,    76,    77,    82,    92,    87,    83,    71,    50,
      35,    54,    36,    51,    84,    53,    72,    38,    39,    62,
      63,    64,    40,    41,    42,    43,    44,    45,    46,    47,
      48
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char TurtleSParser::yytable_ninf_ = -1;
  const unsigned char
  TurtleSParser::yytable_[] =
  {
        34,    37,    52,    73,     8,    67,     1,    73,    73,    79,
       9,    25,    26,    27,     6,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     7,    30,    55,    73,    75,
      78,    65,    85,     8,    81,    68,    93,   100,    89,     9,
      91,    74,    34,    37,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    69,    30,    97,    60,    99,    96,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    25,    26,    27,    61
  };

  /* YYCHECK.  */
  const signed char
  TurtleSParser::yycheck_[] =
  {
         3,     3,     8,    54,     5,     6,     3,    58,    59,    60,
      11,    31,    32,    33,    31,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,    37,     7,    89,    58,
      59,     4,    32,     5,    12,    51,    31,     7,     9,    11,
       8,    55,    55,    55,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    10,    37,    91,    15,    96,    89,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    33,    36
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  TurtleSParser::yystos_[] =
  {
         0,     3,    39,    40,    41,    43,    31,     0,     5,    11,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      37,    48,    49,    52,    67,    68,    70,    73,    75,    76,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    42,
      67,    71,    72,    73,    69,     7,    50,    51,    54,    53,
      15,    36,    77,    78,    79,     4,    44,     6,    72,    10,
      55,    66,    74,    86,    48,    55,    60,    61,    55,    86,
      45,    12,    62,    65,    72,    32,    59,    64,    46,     9,
      58,     8,    63,    31,    56,    57,    66,    65,    47,    62,
       7
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  TurtleSParser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  TurtleSParser::yyr1_[] =
  {
         0,    38,    39,    40,    41,    41,    42,    42,    43,    45,
      46,    47,    44,    48,    48,    49,    50,    51,    51,    53,
      52,    54,    52,    55,    56,    57,    57,    58,    59,    59,
      60,    61,    61,    62,    63,    64,    64,    65,    66,    66,
      67,    67,    69,    68,    70,    71,    71,    72,    72,    73,
      74,    75,    75,    75,    75,    75,    75,    76,    77,    78,
      78,    79,    79,    80,    80,    80,    81,    81,    81,    82,
      82,    82,    83,    83,    83,    84,    84,    85,    85,    85,
      85,    86,    86,    87,    87,    88,    88
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  TurtleSParser::yyr2_[] =
  {
         0,     2,     2,     2,     0,     1,     0,     2,     2,     0,
       0,     0,     7,     0,     1,     2,     2,     0,     1,     0,
       3,     0,     3,     3,     2,     0,     1,     2,     0,     2,
       1,     0,     1,     2,     2,     0,     2,     1,     1,     1,
       1,     1,     0,     4,     3,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const TurtleSParser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "IT_BASE", "IT_PREFIX",
  "GT_LPAREN", "GT_RPAREN", "GT_DOT", "GT_COMMA", "GT_SEMI", "IT_a",
  "GT_LBRACKET", "GT_RBRACKET", "GT_PLUS", "GT_MINUS", "GT_DTYPE",
  "IT_true", "IT_false", "INTEGER", "DECIMAL", "DOUBLE",
  "INTEGER_POSITIVE", "DECIMAL_POSITIVE", "DOUBLE_POSITIVE",
  "INTEGER_NEGATIVE", "DECIMAL_NEGATIVE", "DOUBLE_NEGATIVE",
  "STRING_LITERAL1", "STRING_LITERAL2", "STRING_LITERAL_LONG1",
  "STRING_LITERAL_LONG2", "IRI_REF", "PNAME_NS", "PNAME_LN",
  "BLANK_NODE_LABEL", "ANON", "LANGTAG", "NIL", "$accept", "Query",
  "Prologue", "_QBaseDecl_E_Opt", "_QPrefixDecl_E_Star", "BaseDecl",
  "PrefixDecl", "@1", "@2", "@3", "_QConstructTriples_E_Opt",
  "ConstructTriples", "_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C_E_Opt", "TriplesSameSubject",
  "@4", "@5", "PropertyListNotEmpty", "_O_QVerb_E_S_QObjectList_E_C",
  "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "ObjectList",
  "_O_QGT_COMMA_E_S_QObject_E_C", "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star",
  "Object", "Verb", "TriplesNode", "BlankNodePropertyList", "@6",
  "Collection", "_QGraphNode_E_Plus", "GraphNode", "VarOrTerm",
  "VarOrIRIref", "GraphTerm", "RDFLiteral", "_O_QGT_DTYPE_E_S_QIRIref_E_C",
  "_O_QLANGTAG_E_Or_QGT_DTYPE_E_S_QIRIref_E_C",
  "_Q_O_QLANGTAG_E_Or_QGT_DTYPE_E_S_QIRIref_E_C_E_Opt", "NumericLiteral",
  "NumericLiteralUnsigned", "NumericLiteralPositive",
  "NumericLiteralNegative", "BooleanLiteral", "String", "IRIref",
  "PrefixedName", "BlankNode", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const TurtleSParser::rhs_number_type
  TurtleSParser::yyrhs_[] =
  {
        39,     0,    -1,    40,    48,    -1,    41,    42,    -1,    -1,
      43,    -1,    -1,    42,    44,    -1,     3,    31,    -1,    -1,
      -1,    -1,     4,    45,    32,    46,    31,    47,     7,    -1,
      -1,    49,    -1,    52,    51,    -1,     7,    48,    -1,    -1,
      50,    -1,    -1,    73,    53,    55,    -1,    -1,    67,    54,
      60,    -1,    66,    62,    59,    -1,    66,    62,    -1,    -1,
      56,    -1,     9,    57,    -1,    -1,    59,    58,    -1,    61,
      -1,    -1,    55,    -1,    65,    64,    -1,     8,    65,    -1,
      -1,    64,    63,    -1,    72,    -1,    74,    -1,    10,    -1,
      70,    -1,    68,    -1,    -1,    11,    69,    55,    12,    -1,
       5,    71,     6,    -1,    72,    -1,    71,    72,    -1,    73,
      -1,    67,    -1,    75,    -1,    86,    -1,    86,    -1,    76,
      -1,    80,    -1,    84,    -1,    88,    -1,    37,    -1,    85,
      79,    -1,    15,    86,    -1,    36,    -1,    77,    -1,    -1,
      78,    -1,    81,    -1,    82,    -1,    83,    -1,    18,    -1,
      19,    -1,    20,    -1,    21,    -1,    22,    -1,    23,    -1,
      24,    -1,    25,    -1,    26,    -1,    16,    -1,    17,    -1,
      27,    -1,    28,    -1,    29,    -1,    30,    -1,    31,    -1,
      87,    -1,    33,    -1,    32,    -1,    34,    -1,    35,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  TurtleSParser::yyprhs_[] =
  {
         0,     0,     3,     6,     9,    10,    12,    13,    16,    19,
      20,    21,    22,    30,    31,    33,    36,    39,    40,    42,
      43,    47,    48,    52,    56,    59,    60,    62,    65,    66,
      69,    71,    72,    74,    77,    80,    81,    84,    86,    88,
      90,    92,    94,    95,   100,   104,   106,   109,   111,   113,
     115,   117,   119,   121,   123,   125,   127,   129,   132,   135,
     137,   139,   140,   142,   144,   146,   148,   150,   152,   154,
     156,   158,   160,   162,   164,   166,   168,   170,   172,   174,
     176,   178,   180,   182,   184,   186,   188
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  TurtleSParser::yyrline_[] =
  {
         0,   186,   186,   193,   197,   199,   203,   205,   209,   215,
     217,   219,   215,   227,   228,   235,   243,   250,   251,   255,
     255,   258,   258,   265,   270,   274,   276,   281,   285,   287,
     292,   296,   298,   303,   308,   312,   314,   318,   327,   331,
     338,   341,   347,   347,   360,   382,   385,   392,   395,   401,
     407,   413,   416,   419,   422,   425,   428,   435,   443,   450,
     454,   462,   466,   472,   475,   478,   484,   487,   490,   496,
     499,   502,   508,   511,   514,   520,   523,   529,   532,   535,
     538,   544,   547,   553,   556,   562,   565
  };

  // Print the state stack on the debug stream.
  void
  TurtleSParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  TurtleSParser::yy_reduce_print_ (int yyrule)
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
  TurtleSParser::token_number_type
  TurtleSParser::yytranslate_ (int t)
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
      35,    36,    37
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int TurtleSParser::yyeof_ = 0;
  const int TurtleSParser::yylast_ = 98;
  const int TurtleSParser::yynnts_ = 51;
  const int TurtleSParser::yyempty_ = -2;
  const int TurtleSParser::yyfinal_ = 7;
  const int TurtleSParser::yyterror_ = 1;
  const int TurtleSParser::yyerrcode_ = 256;
  const int TurtleSParser::yyntokens_ = 38;

  const unsigned int TurtleSParser::yyuser_token_number_max_ = 292;
  const TurtleSParser::token_number_type TurtleSParser::yyundef_token_ = 2;

} // namespace w3c_sw

#line 572 "..\\lib\\TurtleSParser\\TurtleSParser.ypp"
 /*** Additional Code ***/

void w3c_sw::TurtleSParser::error(const TurtleSParser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}

/* START YaccDriver (@@ stand-alone would allow it to be shared with other parsers */

namespace w3c_sw {

bool TurtleSDriver::parse_stream(std::istream& in, const std::string& sname)
{
    streamname = sname;

    TurtleSScanner scanner(this, &in);
    scanner.set_debug(trace_scanning);
    this->lexer = &scanner;

    TurtleSParser parser(*this);
    parser.set_debug_level(trace_parsing);
    return (parser.parse());
}

} // namespace w3c_sw

/* END YaccDriver */


