/* A Bison parser, made by GNU Bison 2.5.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2011 Free Software Foundation, Inc.
   
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


/* Line 293 of lalr1.cc  */
#line 41 "lib/TurtleParser.cpp"


#include "TurtleParser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 137 "lib/TurtleParser.ypp"

#include "TurtleScanner.hpp"

/* Line 299 of lalr1.cc  */
#line 175 "lib/TurtleParser.ypp"

#include "TurtleScanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lexWrapper


/* Line 299 of lalr1.cc  */
#line 66 "lib/TurtleParser.cpp"

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                               \
 do                                                                    \
   if (N)                                                              \
     {                                                                 \
       (Current).begin = YYRHSLOC (Rhs, 1).begin;                      \
       (Current).end   = YYRHSLOC (Rhs, N).end;                        \
     }                                                                 \
   else                                                                \
     {                                                                 \
       (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;        \
     }                                                                 \
 while (false)
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


namespace w3c_sw {

/* Line 382 of lalr1.cc  */
#line 152 "lib/TurtleParser.cpp"

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  TurtleParser::yytnamerr_ (const char *yystr)
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


  /// Build a parser object.
  TurtleParser::TurtleParser (class TurtleDriver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {
  }

  TurtleParser::~TurtleParser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  TurtleParser::yy_symbol_value_print_ (int yytype,
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
  TurtleParser::yy_symbol_print_ (int yytype,
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
  TurtleParser::yydestruct_ (const char* yymsg,
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
  TurtleParser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  TurtleParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  TurtleParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  TurtleParser::debug_level_type
  TurtleParser::debug_level () const
  {
    return yydebug_;
  }

  void
  TurtleParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  inline bool
  TurtleParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  TurtleParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  TurtleParser::parse ()
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
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
/* Line 565 of lalr1.cc  */
#line 31 "lib/TurtleParser.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
    driver.yylloc = &yylloc;
}

/* Line 565 of lalr1.cc  */
#line 347 "lib/TurtleParser.cpp"

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
    if (yy_pact_value_is_default_ (yyn))
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
	if (yy_table_value_is_error_ (yyn))
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
	  case 12:

/* Line 690 of lalr1.cc  */
#line 212 "lib/TurtleParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 214 "lib/TurtleParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 216 "lib/TurtleParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 223 "lib/TurtleParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(3) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 229 "lib/TurtleParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 235 "lib/TurtleParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 237 "lib/TurtleParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 239 "lib/TurtleParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 246 "lib/TurtleParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 249 "lib/TurtleParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 309 "lib/TurtleParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 313 "lib/TurtleParser.ypp"
    {
      (yyval.p_TTerm) = TTerm::RDF_type;
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 320 "lib/TurtleParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 328 "lib/TurtleParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 334 "lib/TurtleParser.ypp"
    {
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_URI)));
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 337 "lib/TurtleParser.ypp"
    {
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 340 "lib/TurtleParser.ypp"
    {
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 343 "lib/TurtleParser.ypp"
    {
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 346 "lib/TurtleParser.ypp"
    {
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 358 "lib/TurtleParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 362 "lib/TurtleParser.ypp"
    {
	  (yyval.p_TTerm) = (BNode*)driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 380 "lib/TurtleParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
      }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 383 "lib/TurtleParser.ypp"
    {
	  if ((yysemantic_stack_[(4) - (3)].p_TTerm) == NULL) {
	      (yyval.p_TTerm) = TTerm::RDF_nil;
	  } else {
	      (yyval.p_TTerm) = (yysemantic_stack_[(4) - (3)].p_TTerm);
	      driver.curBGP->addTriplePattern
		  (driver.atomFactory->getTriple
		   (driver.curSubject, TTerm::RDF_rest, TTerm::RDF_nil));
	  }
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 403 "lib/TurtleParser.ypp"
    {
	(yyval.p_TTerm) = NULL;
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 406 "lib/TurtleParser.ypp"
    {
	const TTerm* nextTail = driver.createBNode();
	if ((yysemantic_stack_[(1) - (1)].p_TTerm) == NULL) // on first element
	    (yyval.p_TTerm) = nextTail;
	else		// on later elements
	    driver.curBGP->addTriplePattern
		(driver.atomFactory->getTriple
		 (driver.curSubject, TTerm::RDF_rest, nextTail));
	driver.curSubject = nextTail;
	driver.curPredicate = TTerm::RDF_first;
      }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 416 "lib/TurtleParser.ypp"
    {
	  (yyval.p_TTerm) = (yysemantic_stack_[(3) - (2)].p_TTerm);
      }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 429 "lib/TurtleParser.ypp"
    {
	(yyval.p_TTerm) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 437 "lib/TurtleParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 442 "lib/TurtleParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(2) - (2)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 450 "lib/TurtleParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 690 of lalr1.cc  */
#line 766 "lib/TurtleParser.cpp"
	default:
          break;
      }
    /* User semantic actions sometimes alter yychar, and that requires
       that yytoken be updated with the new translation.  We take the
       approach of translating immediately before every use of yytoken.
       One alternative is translating here after every semantic action,
       but that translation would be missed if the semantic action
       invokes YYABORT, YYACCEPT, or YYERROR immediately after altering
       yychar.  In the case of YYABORT or YYACCEPT, an incorrect
       destructor might then be invoked immediately.  In the case of
       YYERROR, subsequent parser actions might lead to an incorrect
       destructor call or verbose syntax error message before the
       lookahead is translated.  */
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
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = yytranslate_ (yychar);

    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	if (yychar == yyempty_)
	  yytoken = yyempty_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[1] = yylloc;
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

    yyerror_range[1] = yylocation_stack_[yylen - 1];
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
	if (!yy_pact_value_is_default_ (yyn))
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

	yyerror_range[1] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[2] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
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
      {
        /* Make sure we have latest lookahead translation.  See comments
           at user semantic actions for why this is necessary.  */
        yytoken = yytranslate_ (yychar);
        yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval,
                     &yylloc);
      }

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
  TurtleParser::yysyntax_error_ (int yystate, int yytoken)
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yychar.
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            /* Stay within bounds of both yycheck and yytname.  */
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = 0;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char TurtleParser::yypact_ninf_ = -55;
  const signed char
  TurtleParser::yypact_[] =
  {
       -55,     4,     2,   -55,     1,   -13,   -55,   -11,   -55,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,    15,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
      18,    11,   -55,    16,   -55,    13,   -55,    13,     7,   -55,
     -55,   -55,    36,   -55,   -55,    54,    38,   -55,   -55,   -55,
     -55,   -55,    23,    43,   -55,    82,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,   -55,   -55,    -3,   -55,   -55,   -55,   -55,
     -55,    68,    39,    -7,   -55,   -55,   -55,    63,    64,    20,
     -55,    82,   -55,   -55,   -55,    21,   -55,   -55,    82,   -55,
     -55,   -55
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  TurtleParser::yydefact_[] =
  {
         3,     0,     0,     1,     0,     0,    12,     0,    18,    58,
      56,    81,    82,    80,    79,    77,     4,     5,     8,     9,
      11,    10,     0,    21,    23,    46,    44,    78,    45,     7,
       0,     0,    17,     0,    60,     0,     6,     0,     0,    16,
      13,    19,    61,    28,    43,     0,     0,    42,    47,    22,
      24,    26,     0,     0,    59,     0,    57,    29,    71,    72,
      63,    64,    65,    73,    74,    75,    76,    34,    40,    52,
      51,    50,    54,    53,    55,    69,    48,    49,    14,    20,
      62,     0,    38,     0,    67,    70,    66,     0,    37,    31,
      35,     0,    41,    68,    15,     0,    32,    33,     0,    39,
      36,    30
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  TurtleParser::yypgoto_[] =
  {
       -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,    33,   -55,
     -55,   -21,   -55,   -22,   -55,    -9,   -12,   -55,   -55,   -54,
     -55,    81,   -55,    83,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,    -2,   -55,    84
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  TurtleParser::yydefgoto_[] =
  {
        -1,     1,     2,    16,    17,    18,    31,    52,    87,    19,
      20,    21,    33,    53,    22,    37,    38,    50,    45,    96,
      97,    90,    81,    67,    92,    82,    46,    23,    47,    68,
      69,    70,    35,    71,    34,    42,    55,    72,    73,    85,
      86,    74,    75,    48,    27,    77
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char TurtleParser::yytable_ninf_ = -41;
  const signed char
  TurtleParser::yytable_[] =
  {
        26,    80,    -2,     4,     3,     5,     6,     7,    43,     8,
       9,    29,    83,    44,    43,    10,    30,   -25,    32,    44,
      13,    14,    15,    11,    12,    36,    44,    84,    39,    13,
      14,    15,    91,    89,    13,    14,    15,    99,    40,    57,
      13,    14,    15,    41,    76,    54,     9,    13,    14,    15,
      91,    10,    78,    76,    58,    59,    60,    61,    62,    11,
      12,    63,    64,    65,    66,    13,    14,    15,    56,    88,
      49,    51,    79,    94,   100,   -40,   101,    98,   -27,    95,
      89,    93,   -27,    24,     0,    25,    28,     0,     0,    76,
       9,     0,     0,     0,     0,    10,    76,     0,    58,    59,
      60,    61,    62,    11,    12,    63,    64,    65,    66,    13,
      14,    15
  };

  /* YYCHECK.  */
  const signed char
  TurtleParser::yycheck_[] =
  {
         2,    55,     0,     1,     0,     3,     4,     5,     1,     7,
       8,    10,    15,     6,     1,    13,    29,    10,    29,     6,
      27,    28,    29,    21,    22,    10,     6,    30,    10,    27,
      28,    29,    11,    12,    27,    28,    29,    91,    27,     1,
      27,    28,    29,    27,    46,     9,     8,    27,    28,    29,
      11,    13,    29,    55,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    14,     1,
      37,    38,    29,    10,    95,    11,    98,    89,    10,    88,
      12,    83,    14,     2,    -1,     2,     2,    -1,    -1,    91,
       8,    -1,    -1,    -1,    -1,    13,    98,    -1,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  TurtleParser::yystos_[] =
  {
         0,    32,    33,     0,     1,     3,     4,     5,     7,     8,
      13,    21,    22,    27,    28,    29,    34,    35,    36,    40,
      41,    42,    45,    58,    62,    64,    74,    75,    76,    10,
      29,    37,    29,    43,    65,    63,    10,    46,    47,    10,
      27,    27,    66,     1,     6,    49,    57,    59,    74,    49,
      48,    49,    38,    44,     9,    67,    14,     1,    16,    17,
      18,    19,    20,    23,    24,    25,    26,    54,    60,    61,
      62,    64,    68,    69,    72,    73,    74,    76,    29,    29,
      60,    53,    56,    15,    30,    70,    71,    39,     1,    12,
      52,    11,    55,    74,    10,    56,    50,    51,    57,    60,
      52,    54
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  TurtleParser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  TurtleParser::yyr1_[] =
  {
         0,    31,    32,    33,    33,    34,    34,    34,    35,    35,
      35,    35,    37,    38,    39,    36,    40,    41,    43,    44,
      42,    46,    45,    47,    45,    48,    48,    49,    49,    49,
      50,    51,    51,    52,    53,    53,    53,    53,    54,    55,
      56,    56,    57,    57,    58,    58,    58,    59,    60,    60,
      60,    60,    60,    61,    61,    61,    63,    62,    65,    64,
      66,    67,    66,    68,    68,    68,    69,    70,    70,    71,
      71,    72,    72,    73,    73,    73,    73,    74,    74,    75,
      75,    76,    76
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  TurtleParser::yyr2_[] =
  {
         0,     2,     1,     0,     2,     1,     2,     2,     1,     1,
       1,     1,     0,     0,     0,     7,     3,     2,     0,     0,
       5,     0,     3,     0,     3,     0,     1,     3,     1,     2,
       2,     0,     1,     2,     0,     2,     4,     2,     2,     2,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     4,     0,     4,
       0,     0,     3,     1,     1,     1,     2,     1,     2,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const TurtleParser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "GT_AT_base", "GT_AT_prefix",
  "IT_BASE", "RDF_TYPE", "IT_PREFIX", "GT_LPAREN", "GT_RPAREN", "GT_DOT",
  "GT_COMMA", "GT_SEMI", "GT_LBRACKET", "GT_RBRACKET", "GT_DTYPE",
  "IT_true", "IT_false", "INTEGER", "DECIMAL", "DOUBLE",
  "BLANK_NODE_LABEL", "ANON", "STRING_LITERAL1", "STRING_LITERAL2",
  "STRING_LITERAL_LONG1", "STRING_LITERAL_LONG2", "PNAME_NS", "PNAME_LN",
  "IRIREF", "LANGTAG", "$accept", "turtleDoc", "_Qstatement_E_Star",
  "statement", "directive", "prefixID", "$@1", "$@2", "$@3", "base",
  "BaseDecl", "PrefixDecl", "$@4", "$@5", "triples", "$@6", "$@7",
  "_QpredicateObjectList_E_Opt", "predicateObjectList",
  "_O_Qverb_E_S_QobjectList_E_C", "_Q_O_Qverb_E_S_QobjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_Qverb_E_S_QobjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_Qverb_E_S_QobjectList_E_Opt_C_E_Star", "objectList",
  "_O_QGT_COMMA_E_S_Qobject_E_C", "_Q_O_QGT_COMMA_E_S_Qobject_E_C_E_Star",
  "verb", "subject", "predicate", "object", "literal",
  "blankNodePropertyList", "@8", "collection", "@9", "_Qobject_E_Star",
  "@10", "NumericLiteral", "RDFLiteral",
  "_O_QLANGTAG_E_Or_QGT_DTYPE_E_S_Qiri_E_C",
  "_Q_O_QLANGTAG_E_Or_QGT_DTYPE_E_S_Qiri_E_C_E_Opt", "BooleanLiteral",
  "String", "iri", "PrefixedName", "BlankNode", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const TurtleParser::rhs_number_type
  TurtleParser::yyrhs_[] =
  {
        32,     0,    -1,    33,    -1,    -1,    33,    34,    -1,    35,
      -1,    45,    10,    -1,     1,    10,    -1,    36,    -1,    40,
      -1,    42,    -1,    41,    -1,    -1,    -1,    -1,     4,    37,
      27,    38,    29,    39,    10,    -1,     3,    29,    10,    -1,
       5,    29,    -1,    -1,    -1,     7,    43,    27,    44,    29,
      -1,    -1,    58,    46,    49,    -1,    -1,    62,    47,    48,
      -1,    -1,    49,    -1,    57,    54,    53,    -1,     1,    -1,
      57,     1,    -1,    57,    54,    -1,    -1,    50,    -1,    12,
      51,    -1,    -1,    53,    52,    -1,    53,     1,    56,    52,
      -1,    53,     1,    -1,    60,    56,    -1,    11,    60,    -1,
      -1,    56,    55,    -1,    59,    -1,     6,    -1,    74,    -1,
      76,    -1,    64,    -1,    74,    -1,    74,    -1,    76,    -1,
      64,    -1,    62,    -1,    61,    -1,    69,    -1,    68,    -1,
      72,    -1,    -1,    13,    63,    49,    14,    -1,    -1,     8,
      65,    66,     9,    -1,    -1,    -1,    66,    67,    60,    -1,
      18,    -1,    19,    -1,    20,    -1,    73,    71,    -1,    30,
      -1,    15,    74,    -1,    -1,    70,    -1,    16,    -1,    17,
      -1,    23,    -1,    24,    -1,    25,    -1,    26,    -1,    29,
      -1,    75,    -1,    28,    -1,    27,    -1,    21,    -1,    22,
      -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  TurtleParser::yyprhs_[] =
  {
         0,     0,     3,     5,     6,     9,    11,    14,    17,    19,
      21,    23,    25,    26,    27,    28,    36,    40,    43,    44,
      45,    51,    52,    56,    57,    61,    62,    64,    68,    70,
      73,    76,    77,    79,    82,    83,    86,    91,    94,    97,
     100,   101,   104,   106,   108,   110,   112,   114,   116,   118,
     120,   122,   124,   126,   128,   130,   132,   133,   138,   139,
     144,   145,   146,   150,   152,   154,   156,   159,   161,   164,
     165,   167,   169,   171,   173,   175,   177,   179,   181,   183,
     185,   187,   189
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  TurtleParser::yyrline_[] =
  {
         0,   190,   190,   193,   195,   199,   200,   201,   205,   206,
     207,   208,   212,   214,   216,   212,   223,   229,   235,   237,
     235,   246,   246,   249,   249,   255,   257,   262,   263,   264,
     270,   274,   276,   281,   285,   287,   288,   289,   294,   299,
     303,   305,   309,   313,   320,   323,   324,   328,   334,   337,
     340,   343,   346,   352,   353,   354,   358,   358,   380,   380,
     403,   406,   406,   422,   423,   424,   429,   437,   442,   450,
     454,   458,   459,   463,   464,   465,   466,   470,   471,   475,
     476,   480,   481
  };

  // Print the state stack on the debug stream.
  void
  TurtleParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  TurtleParser::yy_reduce_print_ (int yyrule)
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
  TurtleParser::token_number_type
  TurtleParser::yytranslate_ (int t)
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
      25,    26,    27,    28,    29,    30
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int TurtleParser::yyeof_ = 0;
  const int TurtleParser::yylast_ = 111;
  const int TurtleParser::yynnts_ = 46;
  const int TurtleParser::yyempty_ = -2;
  const int TurtleParser::yyfinal_ = 3;
  const int TurtleParser::yyterror_ = 1;
  const int TurtleParser::yyerrcode_ = 256;
  const int TurtleParser::yyntokens_ = 31;

  const unsigned int TurtleParser::yyuser_token_number_max_ = 285;
  const TurtleParser::token_number_type TurtleParser::yyundef_token_ = 2;


} // w3c_sw

/* Line 1136 of lalr1.cc  */
#line 1374 "lib/TurtleParser.cpp"


/* Line 1138 of lalr1.cc  */
#line 486 "lib/TurtleParser.ypp"
 /*** Additional Code ***/

void w3c_sw::TurtleParser::error(const TurtleParser::location_type& l,
			    const std::string& m)
{
    std::string s = m;
    _SUBS(s, "GT_DOT", "'.'");
    _SUBS(s, "GT_SEMI", "';'");
    _SUBS(s, "GT_LBRACKET", "'['");
    _SUBS(s, "GT_RBRACKET", "']'");
    _SUBS(s, "GT_LPAREN", "'('");
    _SUBS(s, "GT_RPAREN", "')'");
    _SUBS(s, "GT_DTYPE", "'^^'");
    _SUBS(s, "IT_true", "boolean true");
    _SUBS(s, "IT_false", "boolean false");
    _SUBS(s, "IT_PREFIX", "PREFIX");
    _SUBS(s, "IT_BASE", "BASE");
    _SUBS(s, "GT_AT_base", "@base");
    _SUBS(s, "GT_AT_prefix", "@prefix");
    _SUBS(s, "RDF_TYPE", "keyword 'a'");
    _SUBS(s, "IRIREF", "IRI");
    _SUBS(s, "PNAME_NS", "namespace prefix");
    _SUBS(s, "PNAME_LN", "local name");
    _SUBS(s, "BLANK_NODE_LABEL", "blank node label");
    _SUBS(s, "LANGTAG", "language tag");
    _SUBS(s, "INTEGER", "integer");
    _SUBS(s, "DECIMAL", "decimal");
    _SUBS(s, "DOUBLE", "double");
    _SUBS(s, "STRING_LITERAL1", "'string'");
    _SUBS(s, "STRING_LITERAL2", "\"string\"");
    _SUBS(s, "STRING_LITERAL_LONG1", "'''string'''");
    _SUBS(s, "STRING_LITERAL_LONG2", "\"\"\"string\"\"\"");
    _SUBS(s, "ANON", "anonymous blank node");
    driver.error(l, s);
}

/* START Driver (@@ stand-alone would allow it to be shared with other parsers */

namespace w3c_sw {

size_t TurtleDriver::DefaultAbortErrorCount = 100;

void TurtleDriver::parse (IStreamContext& in) {
    reset();
    streamname = in.nameStr;
    // clear prefixes for nth run but keep them around for e.g. serialization.
    clearPrefixes();
    curSubject = curPredicate = NULL;

    TurtleScanner scanner(this, in.p);
    scanner.set_debug(trace_scanning);
    this->lexer = &scanner;

    TurtleParser parser(*this);
    parser.set_debug_level(trace_parsing);
    parser.parse();
    checkErrors();
}

void TurtleDriver::parse (IStreamContext& in, BasicGraphPattern* bgp) {
    setGraph(bgp);
    parse(in);
}

void TurtleDriver::parse (IStreamContext& in, RdfDB* db) {
    setGraph(db->ensureGraph(NULL));
    parse(in);
}

void TurtleDriver::parse(std::string turtleStr) {
    IStreamContext in(turtleStr.c_str(), IStreamContext::STRING);
    parse(in);
}

void TurtleDriver::parse (std::string turtleStr, BasicGraphPattern* bgp) {
    IStreamContext in(turtleStr.c_str(), IStreamContext::STRING);
    setGraph(bgp);
    parse(in);
}

void TurtleDriver::parse (std::string turtleStr, RdfDB* db) {
    IStreamContext in(turtleStr.c_str(), IStreamContext::STRING);
    setGraph(db->ensureGraph(DefaultGraph));
    parse(in);
}

} // namespace w3c_sw

/* END Driver */


