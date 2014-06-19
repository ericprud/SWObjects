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
#line 41 "lib/TrigParser.cpp"


#include "TrigParser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 131 "lib/TrigParser.ypp"

#include "TrigScanner.hpp"

/* Line 299 of lalr1.cc  */
#line 164 "lib/TrigParser.ypp"

#include "TrigScanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lexWrapper

#include "RdfDB.hpp"


/* Line 299 of lalr1.cc  */
#line 68 "lib/TrigParser.cpp"

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
#line 154 "lib/TrigParser.cpp"

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  TrigParser::yytnamerr_ (const char *yystr)
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
  TrigParser::TrigParser (class TrigDriver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {
  }

  TrigParser::~TrigParser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  TrigParser::yy_symbol_value_print_ (int yytype,
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
  TrigParser::yy_symbol_print_ (int yytype,
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
  TrigParser::yydestruct_ (const char* yymsg,
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
  TrigParser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  TrigParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  TrigParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  TrigParser::debug_level_type
  TrigParser::debug_level () const
  {
    return yydebug_;
  }

  void
  TrigParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  inline bool
  TrigParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  TrigParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  TrigParser::parse ()
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
#line 31 "lib/TrigParser.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
    driver.yylloc = &yylloc;
}

/* Line 565 of lalr1.cc  */
#line 349 "lib/TrigParser.cpp"

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
	  case 2:

/* Line 690 of lalr1.cc  */
#line 181 "lib/TrigParser.ypp"
    {
	driver.root = driver.defaultBGP;
	// driver.root = $<p_DefaultGraphPattern>1;
    }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 201 "lib/TrigParser.ypp"
    {
	driver.curBGP = driver.db->ensureGraph(NULL);
	driver.neededBGP = NULL;
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 210 "lib/TrigParser.ypp"
    {
	driver.curSubject = NULL;
      }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 217 "lib/TrigParser.ypp"
    {
	driver.curBGP = driver.db->ensureGraph(NULL);
	driver.neededBGP = NULL;
      }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 224 "lib/TrigParser.ypp"
    {
      driver.curSubject = (yysemantic_stack_[(1) - (1)].p_BNode);
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 226 "lib/TrigParser.ypp"
    {
	driver.curSubject = NULL;
      }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 229 "lib/TrigParser.ypp"
    {
      driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 231 "lib/TrigParser.ypp"
    {
	driver.curSubject = NULL;
      }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 243 "lib/TrigParser.ypp"
    {
	driver.curBGP = driver.db->ensureGraph(driver.curSubject);
	driver.neededBGP = NULL;
      }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 246 "lib/TrigParser.ypp"
    {
	  driver.curSubject = NULL;
      }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 258 "lib/TrigParser.ypp"
    {
	driver.neededBGP = NULL;
    }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 273 "lib/TrigParser.ypp"
    {
      driver.curSubject = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 276 "lib/TrigParser.ypp"
    {
      driver.curSubject = (yysemantic_stack_[(1) - (1)].p_BNode);
    }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 291 "lib/TrigParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 293 "lib/TrigParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 295 "lib/TrigParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 303 "lib/TrigParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(3) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 310 "lib/TrigParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 317 "lib/TrigParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 319 "lib/TrigParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 321 "lib/TrigParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 329 "lib/TrigParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 332 "lib/TrigParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_BNode);
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 377 "lib/TrigParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 381 "lib/TrigParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 388 "lib/TrigParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 391 "lib/TrigParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 397 "lib/TrigParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 403 "lib/TrigParser.ypp"
    {
	if (!driver.curBGP)
	    driver.neededBGP = driver.curBGP = new DefaultGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 412 "lib/TrigParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 415 "lib/TrigParser.ypp"
    {
      (yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 418 "lib/TrigParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BNode);
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 421 "lib/TrigParser.ypp"
    {
      (yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 427 "lib/TrigParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 430 "lib/TrigParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 433 "lib/TrigParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 439 "lib/TrigParser.ypp"
    {
      (yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BNode);
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 442 "lib/TrigParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 448 "lib/TrigParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 452 "lib/TrigParser.ypp"
    {
	  (yyval.p_BNode) = (BNode*)driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 461 "lib/TrigParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
      }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 464 "lib/TrigParser.ypp"
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

  case 80:

/* Line 690 of lalr1.cc  */
#line 484 "lib/TrigParser.ypp"
    {
	(yyval.p_TTerm) = NULL;
    }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 487 "lib/TrigParser.ypp"
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

  case 82:

/* Line 690 of lalr1.cc  */
#line 497 "lib/TrigParser.ypp"
    {
	  (yyval.p_TTerm) = (yysemantic_stack_[(3) - (2)].p_TTerm);
      }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 503 "lib/TrigParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 506 "lib/TrigParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 509 "lib/TrigParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 516 "lib/TrigParser.ypp"
    {
	(yyval.p_TTerm) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 524 "lib/TrigParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 528 "lib/TrigParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(2) - (2)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 536 "lib/TrigParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 540 "lib/TrigParser.ypp"
    {
	(yyval.p_uri_or_langtag) = (yysemantic_stack_[(1) - (1)].p_uri_or_langtag);
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 546 "lib/TrigParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 549 "lib/TrigParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 555 "lib/TrigParser.ypp"
    {
	(yyval.p_string) = (yysemantic_stack_[(1) - (1)].p_string);
    }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 558 "lib/TrigParser.ypp"
    {
	(yyval.p_string) = (yysemantic_stack_[(1) - (1)].p_string);
    }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 561 "lib/TrigParser.ypp"
    {
	(yyval.p_string) = (yysemantic_stack_[(1) - (1)].p_string);
    }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 564 "lib/TrigParser.ypp"
    {
	(yyval.p_string) = (yysemantic_stack_[(1) - (1)].p_string);
    }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 570 "lib/TrigParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 573 "lib/TrigParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 579 "lib/TrigParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 582 "lib/TrigParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 588 "lib/TrigParser.ypp"
    {
	(yyval.p_BNode) = (yysemantic_stack_[(1) - (1)].p_BNode);
    }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 591 "lib/TrigParser.ypp"
    {
	(yyval.p_BNode) = (yysemantic_stack_[(1) - (1)].p_BNode);
    }
    break;



/* Line 690 of lalr1.cc  */
#line 1090 "lib/TrigParser.cpp"
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
  TrigParser::yysyntax_error_ (int yystate, int yytoken)
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
  const signed char TrigParser::yypact_ninf_ = -97;
  const signed char
  TrigParser::yypact_[] =
  {
       -97,     4,     9,   -97,   -22,   -97,   -19,   -97,    53,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,    41,   -97,   -97,
       0,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,    10,
       6,   -97,     7,     0,    14,   -97,   -97,   -97,   -97,   -97,
     -97,     1,   -97,   -97,   -97,   -97,   -97,   -97,   -97,    38,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,     1,     1,     1,
     -97,    40,    48,   -97,   -97,    21,    25,    44,    14,   -97,
     -97,     1,     1,    54,    50,    55,   -97,    76,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -10,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,    48,   -97,   -97,   -97,
      75,    77,    29,   -97,   -97,   -97,    79,   -97,     1,   -97,
      48,   -97,   -97,   -97,   -97,   -97,    48,   -97,   -97
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  TrigParser::yydefact_[] =
  {
         5,     0,     9,     1,     0,    37,     0,    43,     0,    22,
     100,    99,    97,   101,   102,     6,     4,     0,     7,     8,
      14,     3,    33,    34,    36,    35,    31,    98,    32,     0,
       0,    42,     0,     0,    25,    78,    76,    10,    16,    18,
      12,     0,    13,    41,    38,    44,    11,    23,    26,    29,
      46,    64,    48,    75,    63,    74,    80,     0,    20,     0,
      62,     0,     0,    61,    65,     0,     0,     0,    25,    30,
      27,     0,    20,    81,     0,     0,    21,     0,    15,    91,
      92,    83,    84,    85,    93,    94,    95,    96,    55,    59,
      66,    70,    68,    69,    72,    71,    73,    89,    67,    39,
      45,    24,    28,    47,    49,    79,     0,    77,    17,    19,
      50,    57,     0,    87,    90,    86,     0,    82,    52,    56,
       0,    60,    88,    40,    53,    54,     0,    58,    51
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  TrigParser::yypgoto_[] =
  {
       -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,    18,    -5,   -97,   -97,    23,   -97,   -97,   -97,
      84,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,   -38,   -97,   -97,   -97,   -97,   -33,
     -97,   -97,   -24,   -97,   -97,   -96,   -97,   -97,   -32,   -16,
     -97,    78,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,    -2,   -97,    45
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  TrigParser::yydefgoto_[] =
  {
        -1,     1,    15,     2,    16,    17,    18,    40,    41,    37,
      58,    59,    75,    19,    34,    67,    47,    48,    69,    70,
      20,    21,    22,    30,    65,   116,    23,    24,    25,    32,
      66,    49,    71,    72,    76,   124,   125,   119,   110,    88,
     121,   111,    62,    50,    63,    89,    90,    91,    92,    93,
      57,    53,    56,    73,   106,    94,    95,   114,   115,    96,
      97,    64,    27,    55
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char TrigParser::yytable_ninf_ = -3;
  const short int
  TrigParser::yytable_[] =
  {
        26,    38,    51,    61,     3,   112,    26,    60,    29,    -2,
     117,    31,     4,     5,     6,    42,     7,     9,    52,    74,
      43,    77,    35,   113,   127,     8,     9,    36,    46,    10,
      11,    12,    54,   103,    44,    45,    51,    10,    11,    12,
      13,    14,    10,    11,    12,    13,    14,    28,    68,    35,
      78,    99,    52,    28,    36,   100,    35,    10,    11,    12,
      98,    36,   101,   105,   107,   108,    54,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    10,    11,    12,    13,
      14,    10,    11,    12,    13,    14,   109,   118,   120,   123,
     104,   102,    33,   128,   126,    39,     0,     0,     0,     0,
       0,     0,     0,     0,    98,     0,     0,     0,     0,     0,
     122,     0,     0,     0,     0,     0,     0,     0,    98,     0,
       0,     0,     0,     0,    98
  };

  /* YYCHECK.  */
  const signed char
  TrigParser::yycheck_[] =
  {
         2,    17,    34,    41,     0,    15,     8,     6,    30,     0,
     106,    30,     3,     4,     5,    20,     7,    17,    34,    57,
      10,    59,     8,    33,   120,    16,    17,    13,    33,    28,
      29,    30,    34,    71,    28,    28,    68,    28,    29,    30,
      31,    32,    28,    29,    30,    31,    32,     2,    10,     8,
      10,    30,    68,     8,    13,    30,     8,    28,    29,    30,
      62,    13,    18,     9,    14,    10,    68,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    28,    29,    30,    31,    32,    10,    12,    11,    10,
      72,    68,     8,   126,   118,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,
      -1,    -1,    -1,    -1,   126
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  TrigParser::yystos_[] =
  {
         0,    35,    37,     0,     3,     4,     5,     7,    16,    17,
      28,    29,    30,    31,    32,    36,    38,    39,    40,    47,
      54,    55,    56,    60,    61,    62,    95,    96,    97,    30,
      57,    30,    63,    54,    48,     8,    13,    43,    83,    85,
      41,    42,    47,    10,    28,    28,    47,    50,    51,    65,
      77,    82,    83,    85,    95,    97,    86,    84,    44,    45,
       6,    68,    76,    78,    95,    58,    64,    49,    10,    52,
      53,    66,    67,    87,    68,    46,    68,    68,    10,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    73,    79,
      80,    81,    82,    83,    89,    90,    93,    94,    95,    30,
      30,    18,    50,    68,    46,     9,    88,    14,    10,    10,
      72,    75,    15,    33,    91,    92,    59,    79,    12,    71,
      11,    74,    95,    10,    69,    70,    76,    79,    73
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  TrigParser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  TrigParser::yyr1_[] =
  {
         0,    34,    35,    36,    36,    37,    37,    38,    38,    39,
      38,    38,    40,    41,    42,    41,    44,    43,    45,    43,
      46,    46,    48,    49,    47,    50,    50,    51,    52,    53,
      53,    54,    54,    55,    55,    55,    55,    57,    58,    59,
      56,    60,    61,    63,    64,    62,    66,    65,    67,    65,
      68,    69,    70,    70,    71,    72,    72,    73,    74,    75,
      75,    76,    76,    77,    77,    78,    79,    80,    80,    80,
      80,    81,    81,    81,    82,    82,    84,    83,    86,    85,
      87,    88,    87,    89,    89,    89,    90,    91,    91,    92,
      92,    93,    93,    94,    94,    94,    94,    95,    95,    96,
      96,    97,    97
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  TrigParser::yyr2_[] =
  {
         0,     2,     1,     1,     1,     0,     2,     1,     1,     0,
       2,     3,     2,     1,     0,     3,     0,     4,     0,     4,
       0,     1,     0,     0,     5,     0,     1,     2,     2,     0,
       1,     1,     1,     1,     1,     1,     1,     0,     0,     0,
       7,     3,     2,     0,     0,     5,     0,     3,     0,     3,
       3,     2,     0,     1,     2,     0,     2,     2,     2,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     4,     0,     4,
       0,     0,     3,     1,     1,     1,     2,     1,     2,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const TrigParser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "AT_BASE", "AT_PREFIX",
  "IT_BASE", "RDF_TYPE", "IT_PREFIX", "GT_LPAREN", "GT_RPAREN", "GT_DOT",
  "GT_COMMA", "GT_SEMI", "GT_LBRACKET", "GT_RBRACKET", "GT_DTYPE",
  "IT_GRAPH", "GT_LCURLEY", "GT_RCURLEY", "IT_true", "IT_false", "INTEGER",
  "DECIMAL", "DOUBLE", "STRING_LITERAL1", "STRING_LITERAL2",
  "STRING_LITERAL_LONG1", "STRING_LITERAL_LONG2", "PNAME_NS", "PNAME_LN",
  "IRIREF", "BLANK_NODE_LABEL", "ANON", "LANGTAG", "$accept", "trigDoc",
  "_O_Qdirective_E_Or_Qblock_E_C",
  "_Q_O_Qdirective_E_Or_Qblock_E_C_E_Star", "block", "$@1",
  "triplesOrGraph",
  "_O_QwrappedGraph_E_Or_QpredicateObjectList_E_S_QGT_DOT_E_C", "$@2",
  "triples2", "$@3", "$@4", "_QpredicateObjectList_E_Opt", "wrappedGraph",
  "$@5", "$@6", "_QtriplesBlock_E_Opt", "triplesBlock",
  "_O_QGT_DOT_E_S_QtriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QtriplesBlock_E_Opt_C_E_Opt", "labelOrSubject",
  "directive", "prefixID", "$@7", "$@8", "$@9", "base", "sparqlBase",
  "sparqlPrefix", "$@10", "$@11", "triples", "$@12", "$@13",
  "predicateObjectList", "_O_Qverb_E_S_QobjectList_E_C",
  "_Q_O_Qverb_E_S_QobjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_Qverb_E_S_QobjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_Qverb_E_S_QobjectList_E_Opt_C_E_Star", "objectList",
  "_O_QGT_COMMA_E_S_Qobject_E_C", "_Q_O_QGT_COMMA_E_S_Qobject_E_C_E_Star",
  "verb", "subject", "predicate", "object", "_object1", "literal", "blank",
  "blankNodePropertyList", "@14", "collection", "@15", "_Qobject_E_Star",
  "@16", "NumericLiteral", "RDFLiteral",
  "_O_QLANGTAG_E_Or_QGT_DTYPE_E_S_Qiri_E_C",
  "_Q_O_QLANGTAG_E_Or_QGT_DTYPE_E_S_Qiri_E_C_E_Opt", "BooleanLiteral",
  "String", "iri", "PrefixedName", "BlankNode", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const TrigParser::rhs_number_type
  TrigParser::yyrhs_[] =
  {
        35,     0,    -1,    37,    -1,    55,    -1,    38,    -1,    -1,
      37,    36,    -1,    40,    -1,    47,    -1,    -1,    39,    43,
      -1,    16,    54,    47,    -1,    54,    41,    -1,    47,    -1,
      -1,    42,    68,    10,    -1,    -1,    83,    44,    46,    10,
      -1,    -1,    85,    45,    68,    10,    -1,    -1,    68,    -1,
      -1,    -1,    17,    48,    50,    49,    18,    -1,    -1,    51,
      -1,    65,    53,    -1,    10,    50,    -1,    -1,    52,    -1,
      95,    -1,    97,    -1,    56,    -1,    60,    -1,    62,    -1,
      61,    -1,    -1,    -1,    -1,     4,    57,    28,    58,    30,
      59,    10,    -1,     3,    30,    10,    -1,     5,    30,    -1,
      -1,    -1,     7,    63,    28,    64,    30,    -1,    -1,    77,
      66,    68,    -1,    -1,    83,    67,    46,    -1,    76,    73,
      72,    -1,    76,    73,    -1,    -1,    69,    -1,    12,    70,
      -1,    -1,    72,    71,    -1,    79,    75,    -1,    11,    79,
      -1,    -1,    75,    74,    -1,    78,    -1,     6,    -1,    95,
      -1,    82,    -1,    95,    -1,    80,    -1,    95,    -1,    82,
      -1,    83,    -1,    81,    -1,    90,    -1,    89,    -1,    93,
      -1,    97,    -1,    85,    -1,    -1,    13,    84,    68,    14,
      -1,    -1,     8,    86,    87,     9,    -1,    -1,    -1,    87,
      88,    79,    -1,    21,    -1,    22,    -1,    23,    -1,    94,
      92,    -1,    33,    -1,    15,    95,    -1,    -1,    91,    -1,
      19,    -1,    20,    -1,    24,    -1,    25,    -1,    26,    -1,
      27,    -1,    30,    -1,    96,    -1,    29,    -1,    28,    -1,
      31,    -1,    32,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  TrigParser::yyprhs_[] =
  {
         0,     0,     3,     5,     7,     9,    10,    13,    15,    17,
      18,    21,    25,    28,    30,    31,    35,    36,    41,    42,
      47,    48,    50,    51,    52,    58,    59,    61,    64,    67,
      68,    70,    72,    74,    76,    78,    80,    82,    83,    84,
      85,    93,    97,   100,   101,   102,   108,   109,   113,   114,
     118,   122,   125,   126,   128,   131,   132,   135,   138,   141,
     142,   145,   147,   149,   151,   153,   155,   157,   159,   161,
     163,   165,   167,   169,   171,   173,   175,   176,   181,   182,
     187,   188,   189,   193,   195,   197,   199,   202,   204,   207,
     208,   210,   212,   214,   216,   218,   220,   222,   224,   226,
     228,   230,   232
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  TrigParser::yyrline_[] =
  {
         0,   181,   181,   188,   189,   192,   194,   199,   200,   201,
     201,   205,   210,   216,   217,   217,   224,   224,   229,   229,
     236,   238,   243,   246,   243,   251,   253,   258,   264,   267,
     269,   273,   276,   283,   284,   285,   286,   291,   293,   295,
     291,   303,   310,   317,   319,   317,   329,   329,   332,   332,
     339,   343,   346,   348,   352,   355,   357,   362,   367,   371,
     373,   377,   381,   388,   391,   397,   403,   412,   415,   418,
     421,   427,   430,   433,   439,   442,   448,   448,   461,   461,
     484,   487,   487,   503,   506,   509,   516,   524,   528,   536,
     540,   546,   549,   555,   558,   561,   564,   570,   573,   579,
     582,   588,   591
  };

  // Print the state stack on the debug stream.
  void
  TrigParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  TrigParser::yy_reduce_print_ (int yyrule)
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
  TrigParser::token_number_type
  TrigParser::yytranslate_ (int t)
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

  const int TrigParser::yyeof_ = 0;
  const int TrigParser::yylast_ = 124;
  const int TrigParser::yynnts_ = 64;
  const int TrigParser::yyempty_ = -2;
  const int TrigParser::yyfinal_ = 3;
  const int TrigParser::yyterror_ = 1;
  const int TrigParser::yyerrcode_ = 256;
  const int TrigParser::yyntokens_ = 34;

  const unsigned int TrigParser::yyuser_token_number_max_ = 288;
  const TrigParser::token_number_type TrigParser::yyundef_token_ = 2;


} // w3c_sw

/* Line 1136 of lalr1.cc  */
#line 1730 "lib/TrigParser.cpp"


/* Line 1138 of lalr1.cc  */
#line 598 "lib/TrigParser.ypp"
 /*** Additional Code ***/

void w3c_sw::TrigParser::error(const TrigParser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}

/* START Driver (@@ stand-alone would allow it to be shared with other parsers */

namespace w3c_sw {

void TrigDriver::parse (IStreamContext& in, RdfDB* db, BasicGraphPattern* bgp)
{
    // clear prefixes for nth run but keep them around for e.g. serialization.
    clearPrefixes();
    curSubject = curPredicate = NULL;

    if (db != NULL)
	setDB(db);
    if (bgp != NULL)
	setGraph(bgp);

    streamname = in.nameStr;

    TrigScanner scanner(this, in.p);
    scanner.set_debug(trace_scanning);
    this->lexer = &scanner;

    TrigParser parser(*this);
    parser.set_debug_level(trace_parsing);
    defaultBGP = curBGP ? curBGP : this->db->ensureGraph(NULL);
    parser.parse();
}

void TrigDriver::parse (IStreamContext& in, BasicGraphPattern* bgp) {
    parse(in, NULL, bgp);
}

void TrigDriver::parse (std::string turtleStr, RdfDB* db, BasicGraphPattern* bgp) {
    IStreamContext in(turtleStr.c_str(), IStreamContext::STRING);
    parse(in, db, bgp);
}

void TrigDriver::parse (std::string turtleStr, BasicGraphPattern* bgp) {
    IStreamContext in(turtleStr.c_str(), IStreamContext::STRING);
    parse(in, NULL, bgp);
}

} // namespace w3c_sw

/* END Driver */


