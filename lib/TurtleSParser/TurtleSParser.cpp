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
#line 41 "lib/TurtleSParser/TurtleSParser.cpp"


#include "TurtleSParser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 122 "lib/TurtleSParser/TurtleSParser.ypp"

#include "../TurtleSScanner.hpp"

/* Line 299 of lalr1.cc  */
#line 155 "lib/TurtleSParser/TurtleSParser.ypp"

#include "../TurtleSScanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lexWrapper


/* Line 299 of lalr1.cc  */
#line 66 "lib/TurtleSParser/TurtleSParser.cpp"

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
#line 152 "lib/TurtleSParser/TurtleSParser.cpp"

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


  /// Build a parser object.
  TurtleSParser::TurtleSParser (class TurtleSDriver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
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
#endif

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

#if YYDEBUG
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
#endif

  inline bool
  TurtleSParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  TurtleSParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  TurtleSParser::parse ()
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
#line 31 "lib/TurtleSParser/TurtleSParser.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 565 of lalr1.cc  */
#line 346 "lib/TurtleSParser/TurtleSParser.cpp"

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
	  case 11:

/* Line 690 of lalr1.cc  */
#line 191 "lib/TurtleSParser/TurtleSParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 193 "lib/TurtleSParser/TurtleSParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 195 "lib/TurtleSParser/TurtleSParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 202 "lib/TurtleSParser/TurtleSParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(3) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 208 "lib/TurtleSParser/TurtleSParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 210 "lib/TurtleSParser/TurtleSParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 212 "lib/TurtleSParser/TurtleSParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 219 "lib/TurtleSParser/TurtleSParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 225 "lib/TurtleSParser/TurtleSParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 228 "lib/TurtleSParser/TurtleSParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_BNode);
    }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 268 "lib/TurtleSParser/TurtleSParser.ypp"
    {
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 275 "lib/TurtleSParser/TurtleSParser.ypp"
    {
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(2) - (2)].p_TTerm)));
    }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 287 "lib/TurtleSParser/TurtleSParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
	driver.curPredicate = (yyval.p_URI);
    }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 291 "lib/TurtleSParser/TurtleSParser.ypp"
    {
	(yyval.p_URI) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_URI);
    }
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 298 "lib/TurtleSParser/TurtleSParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 301 "lib/TurtleSParser/TurtleSParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BNode);
    }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 312 "lib/TurtleSParser/TurtleSParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 315 "lib/TurtleSParser/TurtleSParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BNode);
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 319 "lib/TurtleSParser/TurtleSParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BNode);
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 322 "lib/TurtleSParser/TurtleSParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 329 "lib/TurtleSParser/TurtleSParser.ypp"
    {
	(yyval.p_RDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 332 "lib/TurtleSParser/TurtleSParser.ypp"
    {
	(yyval.p_RDFLiteral) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 338 "lib/TurtleSParser/TurtleSParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 342 "lib/TurtleSParser/TurtleSParser.ypp"
    {
	  (yyval.p_BNode) = (BNode*)driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 351 "lib/TurtleSParser/TurtleSParser.ypp"
    {
	ProductionVector<const TTerm*>* members = (yysemantic_stack_[(3) - (2)].p_TTerms);
	if (members->size() == 0) {
	    (yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil");
	} else {
	    (yyval.p_TTerm) = driver.createBNode();
	    const TTerm* tail = (yyval.p_TTerm);
	    const URI* first = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#first");
	    const URI* rest = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#rest");
	    const TTerm* nil = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil");
	    for (unsigned i = 0; i < members->size(); i++) {
		driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(tail, first, members->at(i)));
		const TTerm* nextTail = i == members->size()-1 ? nil : driver.createBNode();
		driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(tail, rest, nextTail));
		tail = nextTail;
	    }
	    members->clear();
	    delete members;
	}
    }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 375 "lib/TurtleSParser/TurtleSParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 378 "lib/TurtleSParser/TurtleSParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 392 "lib/TurtleSParser/TurtleSParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 400 "lib/TurtleSParser/TurtleSParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 405 "lib/TurtleSParser/TurtleSParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(2) - (2)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 413 "lib/TurtleSParser/TurtleSParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 690 of lalr1.cc  */
#line 774 "lib/TurtleSParser/TurtleSParser.cpp"
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
  TurtleSParser::yysyntax_error_ (int yystate, int yytoken)
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
  const signed char TurtleSParser::yypact_ninf_ = -50;
  const signed char
  TurtleSParser::yypact_[] =
  {
       -50,     9,     7,   -50,   -12,   -50,   -11,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
     -50,     3,   -50,   -50,   -50,   -50,   -50,   -50,    10,   -10,
     -50,    -7,    63,    -4,   -50,    -4,    -4,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -15,   -50,   -50,
     -50,     8,    88,   -50,   -50,   -50,   -50,   -50,    -1,     0,
     -24,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
      17,   -50,    20,    -4,   -50,    21,   -50,   -50,   -50,    88,
      88,   -50,   -50,   -50
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  TurtleSParser::yydefact_[] =
  {
         3,     0,     2,     1,     0,    11,     0,    16,    55,    52,
      71,    74,    73,    75,    76,     4,     5,     7,     8,     9,
      10,     0,    20,    22,    42,    40,    72,    41,     0,     0,
      19,     0,     0,     0,     6,     0,    24,    15,    12,    17,
      54,    65,    66,    57,    58,    59,    67,    68,    69,    70,
      56,    48,    47,    46,    50,    49,    51,    63,    44,    45,
      39,     0,     0,    38,    43,    21,    23,    25,     0,     0,
       0,    61,    64,    60,    53,    31,    33,    13,    18,    62,
      26,    36,     0,    28,    32,    34,    14,    29,    30,     0,
       0,    37,    27,    35
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  TurtleSParser::yypgoto_[] =
  {
       -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -28,   -50,
     -50,   -50,   -50,   -49,   -50,   -50,   -50,   -42,   -50,   -50,
     -31,   -50,    40,   -50,    41,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,    -2,   -50,    42
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  TurtleSParser::yydefgoto_[] =
  {
        -1,     1,     2,    15,    16,    17,    29,    68,    82,    18,
      19,    31,    69,    20,    21,    35,    36,    66,    61,    87,
      88,    84,    80,    75,    81,    91,    85,    62,    22,    63,
      76,    51,    52,    33,    53,    32,    54,    55,    72,    73,
      56,    57,    58,    26,    59
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char TurtleSParser::yytable_ninf_ = -1;
  const unsigned char
  TurtleSParser::yytable_[] =
  {
        25,    50,    60,    70,    10,    11,    12,    65,    67,     3,
       4,     5,     6,    34,     7,     8,    28,    30,    71,    38,
      37,     9,    39,    74,    10,    11,    12,    77,    78,    83,
      86,    64,    90,    64,    64,    10,    11,    12,    13,    14,
      92,    89,    23,    24,    27,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    93,
       0,     0,     0,     0,     0,     0,     0,     0,    79,     0,
       0,     8,    40,     0,     0,     0,     0,     9,     0,     0,
       0,    64,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    10,    11,    12,    13,    14,     8,     0,     0,     0,
       0,     0,     9,     0,     0,     0,     0,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    10,    11,    12,    13,
      14
  };

  /* YYCHECK.  */
  const signed char
  TurtleSParser::yycheck_[] =
  {
         2,    32,     6,    18,    28,    29,    30,    35,    36,     0,
       3,     4,     5,    10,     7,     8,    28,    28,    33,    29,
      10,    14,    29,    15,    28,    29,    30,    28,    28,    12,
      10,    33,    11,    35,    36,    28,    29,    30,    31,    32,
      89,    83,     2,     2,     2,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,     8,     9,    -1,    -1,    -1,    -1,    14,    -1,    -1,
      -1,    83,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,     8,    -1,    -1,    -1,
      -1,    -1,    14,    -1,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  TurtleSParser::yystos_[] =
  {
         0,    35,    36,     0,     3,     4,     5,     7,     8,    14,
      28,    29,    30,    31,    32,    37,    38,    39,    43,    44,
      47,    48,    62,    66,    68,    76,    77,    78,    28,    40,
      28,    45,    69,    67,    10,    49,    50,    10,    29,    29,
       9,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      64,    65,    66,    68,    70,    71,    74,    75,    76,    78,
       6,    52,    61,    63,    76,    52,    51,    52,    41,    46,
      18,    33,    72,    73,    15,    57,    64,    28,    28,    76,
      56,    58,    42,    12,    55,    60,    10,    53,    54,    61,
      11,    59,    57,    64
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
     285,   286,   287,   288
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  TurtleSParser::yyr1_[] =
  {
         0,    34,    35,    36,    36,    37,    37,    38,    38,    38,
      38,    40,    41,    42,    39,    43,    45,    46,    44,    47,
      49,    48,    50,    48,    51,    51,    52,    53,    54,    54,
      55,    56,    56,    58,    57,    59,    60,    60,    61,    61,
      62,    62,    62,    63,    64,    64,    64,    64,    64,    65,
      65,    65,    67,    66,    68,    69,    69,    70,    70,    70,
      71,    72,    72,    73,    73,    74,    74,    75,    75,    75,
      75,    76,    76,    77,    77,    78,    78
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  TurtleSParser::yyr2_[] =
  {
         0,     2,     1,     0,     2,     1,     2,     1,     1,     1,
       1,     0,     0,     0,     7,     3,     0,     0,     5,     2,
       0,     3,     0,     3,     0,     1,     3,     2,     0,     1,
       2,     0,     2,     0,     3,     2,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     3,     0,     2,     1,     1,     1,
       2,     1,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const TurtleSParser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "BASE", "PREFIX",
  "SPARQL_BASE", "RDF_TYPE", "SPARQL_PREFIX", "GT_LPAREN", "GT_RPAREN",
  "GT_DOT", "GT_COMMA", "GT_SEMI", "IT_a", "GT_LBRACKET", "GT_RBRACKET",
  "GT_PLUS", "GT_MINUS", "GT_DTYPE", "IT_true", "IT_false", "INTEGER",
  "DECIMAL", "DOUBLE", "STRING_LITERAL1", "STRING_LITERAL2",
  "STRING_LITERAL_LONG1", "STRING_LITERAL_LONG2", "IRIREF", "PNAME_NS",
  "PNAME_LN", "BLANK_NODE_LABEL", "ANON", "LANGTAG", "$accept",
  "turtleDoc", "_Qstatement_E_Star", "statement", "directive", "prefixID",
  "$@1", "$@2", "$@3", "base", "sparqlPrefix", "$@4", "$@5", "sparqlBase",
  "triples", "$@6", "$@7", "_QpredicateObjectList_E_Opt",
  "predicateObjectList", "_O_Qverb_E_S_QobjectList_E_C",
  "_Q_O_Qverb_E_S_QobjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_Qverb_E_S_QobjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_Qverb_E_S_QobjectList_E_Opt_C_E_Star", "objectList",
  "$@8", "_O_QGT_COMMA_E_S_Qobject_E_C",
  "_Q_O_QGT_COMMA_E_S_Qobject_E_C_E_Star", "verb", "subject", "predicate",
  "object", "literal", "blankNodePropertyList", "@9", "collection",
  "_Qobject_E_Star", "NumericLiteral", "RDFLiteral",
  "_O_QLANGTAG_E_Or_QGT_DTYPE_E_S_Qiri_E_C",
  "_Q_O_QLANGTAG_E_Or_QGT_DTYPE_E_S_Qiri_E_C_E_Opt", "BooleanLiteral",
  "String", "iri", "PrefixedName", "BlankNode", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const TurtleSParser::rhs_number_type
  TurtleSParser::yyrhs_[] =
  {
        35,     0,    -1,    36,    -1,    -1,    36,    37,    -1,    38,
      -1,    48,    10,    -1,    39,    -1,    43,    -1,    44,    -1,
      47,    -1,    -1,    -1,    -1,     4,    40,    29,    41,    28,
      42,    10,    -1,     3,    28,    10,    -1,    -1,    -1,     7,
      45,    29,    46,    28,    -1,     5,    28,    -1,    -1,    62,
      49,    52,    -1,    -1,    66,    50,    51,    -1,    -1,    52,
      -1,    61,    57,    56,    -1,    61,    57,    -1,    -1,    53,
      -1,    12,    54,    -1,    -1,    56,    55,    -1,    -1,    64,
      58,    60,    -1,    11,    64,    -1,    -1,    60,    59,    -1,
      63,    -1,     6,    -1,    76,    -1,    78,    -1,    68,    -1,
      76,    -1,    76,    -1,    78,    -1,    68,    -1,    66,    -1,
      65,    -1,    71,    -1,    70,    -1,    74,    -1,    -1,    14,
      67,    52,    15,    -1,     8,    69,     9,    -1,    -1,    69,
      64,    -1,    21,    -1,    22,    -1,    23,    -1,    75,    73,
      -1,    33,    -1,    18,    76,    -1,    -1,    72,    -1,    19,
      -1,    20,    -1,    24,    -1,    25,    -1,    26,    -1,    27,
      -1,    28,    -1,    77,    -1,    30,    -1,    29,    -1,    31,
      -1,    32,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  TurtleSParser::yyprhs_[] =
  {
         0,     0,     3,     5,     6,     9,    11,    14,    16,    18,
      20,    22,    23,    24,    25,    33,    37,    38,    39,    45,
      48,    49,    53,    54,    58,    59,    61,    65,    68,    69,
      71,    74,    75,    78,    79,    83,    86,    87,    90,    92,
      94,    96,    98,   100,   102,   104,   106,   108,   110,   112,
     114,   116,   118,   119,   124,   128,   129,   132,   134,   136,
     138,   141,   143,   146,   147,   149,   151,   153,   155,   157,
     159,   161,   163,   165,   167,   169,   171
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  TurtleSParser::yyrline_[] =
  {
         0,   170,   170,   173,   175,   179,   180,   184,   185,   186,
     187,   191,   193,   195,   191,   202,   208,   210,   208,   219,
     225,   225,   228,   228,   234,   236,   241,   246,   250,   252,
     257,   261,   263,   268,   268,   275,   281,   283,   287,   291,
     298,   301,   304,   308,   312,   315,   318,   319,   322,   328,
     329,   332,   338,   338,   351,   375,   378,   385,   386,   387,
     392,   400,   405,   413,   417,   421,   422,   426,   427,   428,
     429,   433,   434,   438,   439,   443,   444
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int TurtleSParser::yyeof_ = 0;
  const int TurtleSParser::yylast_ = 120;
  const int TurtleSParser::yynnts_ = 45;
  const int TurtleSParser::yyempty_ = -2;
  const int TurtleSParser::yyfinal_ = 3;
  const int TurtleSParser::yyterror_ = 1;
  const int TurtleSParser::yyerrcode_ = 256;
  const int TurtleSParser::yyntokens_ = 34;

  const unsigned int TurtleSParser::yyuser_token_number_max_ = 288;
  const TurtleSParser::token_number_type TurtleSParser::yyundef_token_ = 2;


} // w3c_sw

/* Line 1136 of lalr1.cc  */
#line 1376 "lib/TurtleSParser/TurtleSParser.cpp"


/* Line 1138 of lalr1.cc  */
#line 449 "lib/TurtleSParser/TurtleSParser.ypp"
 /*** Additional Code ***/

void w3c_sw::TurtleSParser::error(const TurtleSParser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}

/* START Driver (@@ stand-alone would allow it to be shared with other parsers */

namespace w3c_sw {

void TurtleSDriver::parse (IStreamContext& in) {
    streamname = in.nameStr;
    // clear prefixes for nth run but keep them around for e.g. serialization.
    clearPrefixes();
    curSubject = curPredicate = NULL;

    TurtleSScanner scanner(this, in.p);
    scanner.set_debug(trace_scanning);
    this->lexer = &scanner;

    TurtleSParser parser(*this);
    parser.set_debug_level(trace_parsing);
    parser.parse();
}

void TurtleSDriver::parse (IStreamContext& in, BasicGraphPattern* bgp) {
    setGraph(bgp);
    parse(in);
}

void TurtleSDriver::parse (IStreamContext& in, RdfDB* db) {
    setGraph(db->ensureGraph(NULL));
    parse(in);
}

void TurtleSDriver::parse(std::string turtleStr) {
    IStreamContext in(turtleStr.c_str(), IStreamContext::STRING);
    parse(in);
}

void TurtleSDriver::parse (std::string turtleStr, BasicGraphPattern* bgp) {
    IStreamContext in(turtleStr.c_str(), IStreamContext::STRING);
    setGraph(bgp);
    parse(in);
}

void TurtleSDriver::parse (std::string turtleStr, RdfDB* db) {
    IStreamContext in(turtleStr.c_str(), IStreamContext::STRING);
    setGraph(db->ensureGraph(DefaultGraph));
    parse(in);
}

} // namespace w3c_sw

/* END Driver */


