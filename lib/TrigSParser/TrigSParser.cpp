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
#line 41 "lib/TrigSParser/TrigSParser.cpp"


#include "TrigSParser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 126 "lib/TrigSParser/TrigSParser.ypp"

#include "../TrigSScanner.hpp"

/* Line 299 of lalr1.cc  */
#line 178 "lib/TrigSParser/TrigSParser.ypp"

#include "../TrigSScanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lexWrapper

#include "RdfDB.hpp"


/* Line 299 of lalr1.cc  */
#line 68 "lib/TrigSParser/TrigSParser.cpp"

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
#line 154 "lib/TrigSParser/TrigSParser.cpp"

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  TrigSParser::yytnamerr_ (const char *yystr)
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
  TrigSParser::TrigSParser (class TrigSDriver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {
  }

  TrigSParser::~TrigSParser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  TrigSParser::yy_symbol_value_print_ (int yytype,
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
  TrigSParser::yy_symbol_print_ (int yytype,
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
  TrigSParser::yydestruct_ (const char* yymsg,
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
  TrigSParser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  TrigSParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  TrigSParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  TrigSParser::debug_level_type
  TrigSParser::debug_level () const
  {
    return yydebug_;
  }

  void
  TrigSParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  inline bool
  TrigSParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  TrigSParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  TrigSParser::parse ()
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
#line 31 "lib/TrigSParser/TrigSParser.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 565 of lalr1.cc  */
#line 348 "lib/TrigSParser/TrigSParser.cpp"

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
#line 195 "lib/TrigSParser/TrigSParser.ypp"
    {
	driver.root = (yysemantic_stack_[(2) - (2)].p_DefaultGraphPattern); // last graph -- kinda useless
    }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 218 "lib/TrigSParser/TrigSParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(3) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 224 "lib/TrigSParser/TrigSParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 226 "lib/TrigSParser/TrigSParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 228 "lib/TrigSParser/TrigSParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 236 "lib/TrigSParser/TrigSParser.ypp"
    { (yyval.p_DefaultGraphPattern) = NULL; }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 237 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_DefaultGraphPattern) = (yysemantic_stack_[(2) - (2)].p_DefaultGraphPattern);
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 244 "lib/TrigSParser/TrigSParser.ypp"
    {
	driver.curBGP = (yysemantic_stack_[(2) - (1)].p_TTerm) ? driver.db->ensureGraph((yysemantic_stack_[(2) - (1)].p_TTerm)) : driver.defaultBGP;
	driver.neededBGP = NULL;
      }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 247 "lib/TrigSParser/TrigSParser.ypp"
    {
	  (yyval.p_DefaultGraphPattern) = (yysemantic_stack_[(5) - (4)].p_DefaultGraphPattern);
	  driver.neededBGP = NULL;
	  driver.curBGP = NULL;
      }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 255 "lib/TrigSParser/TrigSParser.ypp"
    { (yyval.p_TTerm) = NULL; }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 256 "lib/TrigSParser/TrigSParser.ypp"
    {
      (yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 259 "lib/TrigSParser/TrigSParser.ypp"
    {
      (yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BNode);
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 266 "lib/TrigSParser/TrigSParser.ypp"
    { (yyval.p_DefaultGraphPattern) = NULL; }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 267 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_DefaultGraphPattern) = (yysemantic_stack_[(1) - (1)].p_DefaultGraphPattern);
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 274 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_DefaultGraphPattern) = driver.neededBGP ? driver.neededBGP : (yysemantic_stack_[(2) - (2)].p_DefaultGraphPattern);
	driver.neededBGP = NULL;
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 282 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_DefaultGraphPattern) = (yysemantic_stack_[(2) - (2)].p_DefaultGraphPattern);
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 289 "lib/TrigSParser/TrigSParser.ypp"
    { (yyval.p_DefaultGraphPattern) = NULL; }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 294 "lib/TrigSParser/TrigSParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 297 "lib/TrigSParser/TrigSParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_BNode);
    }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 357 "lib/TrigSParser/TrigSParser.ypp"
    {
	if (!driver.curBGP)
	    driver.neededBGP = driver.curBGP = new DefaultGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 366 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 370 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 377 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_BNode) = (yysemantic_stack_[(1) - (1)].p_BNode);
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 380 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_BNode) = (yysemantic_stack_[(1) - (1)].p_BNode);
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 386 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 390 "lib/TrigSParser/TrigSParser.ypp"
    {
	  (yyval.p_BNode) = (BNode*)driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 399 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_BNode) = driver.createBNode();
	const TTerm* tail = (yyval.p_BNode);
	ProductionVector<const TTerm*>* members = (yysemantic_stack_[(3) - (2)].p_TTerms);
	const URI* first = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#first");
	const URI* rest = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#rest");
	const TTerm* nil = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil");
	if (!driver.curBGP)
	    driver.neededBGP = driver.curBGP = new DefaultGraphPattern();
	for (unsigned i = 0; i < members->size(); i++) {
	    driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(tail, first, members->at(i)));
	    const TTerm* nextTail = i == members->size()-1 ? nil : driver.createBNode();
	    driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(tail, rest, nextTail));
	    tail = nextTail;
	}
	members->clear();
	delete members;
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 421 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 424 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 431 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 434 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BNode);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 440 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 446 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 452 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 455 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 458 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 461 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 464 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 467 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 474 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 482 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 489 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 493 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 501 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 505 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_uri_or_langtag) = (yysemantic_stack_[(1) - (1)].p_uri_or_langtag);
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 511 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 514 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 517 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 523 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 526 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 529 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 535 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 538 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 541 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 547 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 550 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 553 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 559 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_BooleanRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 562 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_BooleanRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 568 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_string) = (yysemantic_stack_[(1) - (1)].p_string);
    }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 571 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_string) = (yysemantic_stack_[(1) - (1)].p_string);
    }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 574 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_string) = (yysemantic_stack_[(1) - (1)].p_string);
    }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 577 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_string) = (yysemantic_stack_[(1) - (1)].p_string);
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 583 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 586 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 592 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 595 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 601 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BNode);
    }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 604 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BNode);
    }
    break;



/* Line 690 of lalr1.cc  */
#line 1114 "lib/TrigSParser/TrigSParser.cpp"
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
  TrigSParser::yysyntax_error_ (int yystate, int yytoken)
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
  const signed char TrigSParser::yypact_ninf_ = -67;
  const signed char
  TrigSParser::yypact_[] =
  {
        10,     7,    41,   -67,   -67,   -67,    33,   -67,     3,    39,
     -67,   -67,   -67,   -67,   -67,   -67,    40,   -67,   -67,   -67,
     -67,   -67,    12,    49,   -67,    49,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,    43,   -67,    42,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,    17,
     -67,   -67,    19,   -67,    -4,   -67,   -67,    75,   -67,    49,
     -67,   -67,    75,    75,   -23,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,    36,    49,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,    44,   -67,   -67,   -67,   -67,   -67,    46,
      48,    75,   -67,    49,   -67,   -67,   -67,    49,   -67,   -67
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  TrigSParser::yydefact_[] =
  {
         4,     0,     0,    13,     6,     5,     0,     1,     2,     3,
       8,    88,    91,    90,    19,    14,     0,    18,    89,     9,
       7,    15,     0,    20,    10,     0,    49,    82,    83,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    84,    85,
      86,    87,    92,    93,    63,     0,    21,    24,    28,    48,
      47,    26,    56,    59,    60,    70,    71,    72,    61,    68,
      58,    62,     0,    55,     0,    52,    54,     0,    16,    20,
      25,    22,    38,     0,     0,    66,    67,    69,    64,    11,
      51,    53,    46,     0,     0,    45,    57,    23,    39,    29,
      37,    27,    65,     0,    50,    35,    42,    44,    12,    30,
      40,    32,    36,     0,    43,    33,    34,     0,    41,    31
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  TrigSParser::yypgoto_[] =
  {
       -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -15,   -67,   -67,   -67,   -67,   -67,
     -67,   -66,   -67,   -67,   -67,   -67,   -67,   -67,   -47,   -67,
     -67,   -42,   -38,   -22,   -67,   -67,   -67,   -67,   -20,   -21,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,    -8,   -67,   -67
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  TrigSParser::yydefgoto_[] =
  {
        -1,     2,     3,     4,     9,     5,    20,    22,    62,    93,
       8,    15,    23,    16,    45,    46,    70,    71,    47,    73,
      72,    83,   105,   106,   102,    99,    89,    90,    95,   104,
     100,    96,    84,    63,    49,    67,    50,    64,    97,    66,
      85,    52,    53,    76,    77,    78,    54,    55,    56,    57,
      58,    59,    60,    18,    61
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char TrigSParser::yytable_ninf_ = -18;
  const signed char
  TrigSParser::yytable_[] =
  {
        17,    48,    51,    25,    80,    65,    88,    91,   -17,    26,
      11,    12,    13,     1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    11,
      12,    13,    42,    43,    74,    44,    11,    12,    13,    14,
       6,     7,    10,    19,    81,    21,    24,    48,    51,    68,
      94,    69,    79,    98,    87,    75,    25,   101,   103,    86,
     109,   108,    26,   107,    86,    86,    92,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    11,    12,    13,    42,    43,    82,    44,     0,
       0,     0,     0,    86,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,    12,
      13
  };

  /* YYCHECK.  */
  const signed char
  TrigSParser::yycheck_[] =
  {
         8,    23,    23,     7,     8,    25,    72,    73,     5,    13,
      33,    34,    35,     3,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    17,    39,    33,    34,    35,    36,
      33,     0,     9,     4,    64,     5,    34,    69,    69,     6,
      14,     9,    33,     9,    69,    38,     7,    11,    10,    67,
     107,   103,    13,   101,    72,    73,    74,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    12,    39,    -1,
      -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
      35
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  TrigSParser::yystos_[] =
  {
         0,     3,    41,    42,    43,    45,    33,     0,    50,    44,
       9,    33,    34,    35,    36,    51,    53,    92,    93,     4,
      46,     5,    47,    52,    34,     7,    13,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    36,    37,    39,    54,    55,    58,    73,    74,
      76,    79,    81,    82,    86,    87,    88,    89,    90,    91,
      92,    94,    48,    73,    77,    78,    79,    75,     6,     9,
      56,    57,    60,    59,    17,    38,    83,    84,    85,    33,
       8,    78,    12,    61,    72,    80,    92,    54,    61,    66,
      67,    61,    92,    49,    14,    68,    71,    78,     9,    65,
      70,    11,    64,    10,    69,    62,    63,    72,    71,    68
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  TrigSParser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  TrigSParser::yyr1_[] =
  {
         0,    40,    41,    42,    43,    43,    44,    44,    45,    47,
      48,    49,    46,    50,    50,    52,    51,    53,    53,    53,
      54,    54,    55,    56,    57,    57,    59,    58,    60,    58,
      61,    62,    63,    63,    64,    65,    65,    66,    67,    67,
      68,    69,    70,    70,    71,    72,    72,    73,    73,    75,
      74,    76,    77,    77,    78,    78,    79,    80,    81,    81,
      81,    81,    81,    81,    82,    83,    84,    84,    85,    85,
      86,    86,    86,    87,    87,    87,    88,    88,    88,    89,
      89,    89,    90,    90,    91,    91,    91,    91,    92,    92,
      93,    93,    94,    94
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  TrigSParser::yyr2_[] =
  {
         0,     2,     2,     2,     0,     1,     0,     2,     3,     0,
       0,     0,     7,     0,     2,     0,     5,     0,     1,     1,
       0,     1,     2,     2,     0,     1,     0,     3,     0,     3,
       3,     2,     0,     1,     2,     0,     2,     1,     0,     1,
       2,     2,     0,     2,     1,     1,     1,     1,     1,     0,
       4,     3,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const TrigSParser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "IT_BASE", "IT_PREFIX",
  "GT_LCURLEY", "GT_RCURLEY", "GT_LPAREN", "GT_RPAREN", "GT_DOT",
  "GT_COMMA", "GT_SEMI", "IT_a", "GT_LBRACKET", "GT_RBRACKET", "GT_PLUS",
  "GT_MINUS", "GT_DTYPE", "IT_true", "IT_false", "INTEGER", "DECIMAL",
  "DOUBLE", "INTEGER_POSITIVE", "DECIMAL_POSITIVE", "DOUBLE_POSITIVE",
  "INTEGER_NEGATIVE", "DECIMAL_NEGATIVE", "DOUBLE_NEGATIVE",
  "STRING_LITERAL1", "STRING_LITERAL2", "STRING_LITERAL_LONG1",
  "STRING_LITERAL_LONG2", "IRI_REF", "PNAME_NS", "PNAME_LN",
  "BLANK_NODE_LABEL", "ANON", "LANGTAG", "NIL", "$accept", "Query",
  "Prologue", "_QBaseDecl_E_Opt", "_QPrefixDecl_E_Star", "BaseDecl",
  "PrefixDecl", "$@1", "$@2", "$@3", "_QTrigTemplate_E_Star",
  "TrigTemplate", "$@4", "GraphName_Opt", "_QConstructTriples_E_Opt",
  "ConstructTriples", "_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C_E_Opt", "TriplesSameSubject",
  "$@5", "$@6", "PropertyListNotEmpty", "_O_QVerb_E_S_QObjectList_E_C",
  "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "ObjectList",
  "_O_QGT_COMMA_E_S_QObject_E_C", "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star",
  "Object", "Verb", "TriplesNode", "BlankNodePropertyList", "@7",
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
  const TrigSParser::rhs_number_type
  TrigSParser::yyrhs_[] =
  {
        41,     0,    -1,    42,    50,    -1,    43,    44,    -1,    -1,
      45,    -1,    -1,    44,    46,    -1,     3,    33,     9,    -1,
      -1,    -1,    -1,     4,    47,    34,    48,    33,    49,     9,
      -1,    -1,    50,    51,    -1,    -1,    53,     5,    52,    54,
       6,    -1,    -1,    92,    -1,    36,    -1,    -1,    55,    -1,
      58,    57,    -1,     9,    54,    -1,    -1,    56,    -1,    -1,
      79,    59,    61,    -1,    -1,    73,    60,    66,    -1,    72,
      68,    65,    -1,    72,    68,    -1,    -1,    62,    -1,    11,
      63,    -1,    -1,    65,    64,    -1,    67,    -1,    -1,    61,
      -1,    71,    70,    -1,    10,    71,    -1,    -1,    70,    69,
      -1,    78,    -1,    80,    -1,    12,    -1,    76,    -1,    74,
      -1,    -1,    13,    75,    61,    14,    -1,     7,    77,     8,
      -1,    78,    -1,    77,    78,    -1,    79,    -1,    73,    -1,
      81,    -1,    92,    -1,    92,    -1,    82,    -1,    86,    -1,
      90,    -1,    94,    -1,    39,    -1,    91,    85,    -1,    17,
      92,    -1,    38,    -1,    83,    -1,    -1,    84,    -1,    87,
      -1,    88,    -1,    89,    -1,    20,    -1,    21,    -1,    22,
      -1,    23,    -1,    24,    -1,    25,    -1,    26,    -1,    27,
      -1,    28,    -1,    18,    -1,    19,    -1,    29,    -1,    30,
      -1,    31,    -1,    32,    -1,    33,    -1,    93,    -1,    35,
      -1,    34,    -1,    36,    -1,    37,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  TrigSParser::yyprhs_[] =
  {
         0,     0,     3,     6,     9,    10,    12,    13,    16,    20,
      21,    22,    23,    31,    32,    35,    36,    42,    43,    45,
      47,    48,    50,    53,    56,    57,    59,    60,    64,    65,
      69,    73,    76,    77,    79,    82,    83,    86,    88,    89,
      91,    94,    97,    98,   101,   103,   105,   107,   109,   111,
     112,   117,   121,   123,   126,   128,   130,   132,   134,   136,
     138,   140,   142,   144,   146,   149,   152,   154,   156,   157,
     159,   161,   163,   165,   167,   169,   171,   173,   175,   177,
     179,   181,   183,   185,   187,   189,   191,   193,   195,   197,
     199,   201,   203,   205
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  TrigSParser::yyrline_[] =
  {
         0,   195,   195,   202,   206,   208,   212,   214,   218,   224,
     226,   228,   224,   236,   237,   244,   244,   255,   256,   259,
     266,   267,   274,   282,   289,   290,   294,   294,   297,   297,
     304,   309,   313,   315,   320,   324,   326,   331,   335,   337,
     342,   347,   351,   353,   357,   366,   370,   377,   380,   386,
     386,   399,   421,   424,   431,   434,   440,   446,   452,   455,
     458,   461,   464,   467,   474,   482,   489,   493,   501,   505,
     511,   514,   517,   523,   526,   529,   535,   538,   541,   547,
     550,   553,   559,   562,   568,   571,   574,   577,   583,   586,
     592,   595,   601,   604
  };

  // Print the state stack on the debug stream.
  void
  TrigSParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  TrigSParser::yy_reduce_print_ (int yyrule)
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
  TrigSParser::token_number_type
  TrigSParser::yytranslate_ (int t)
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
      35,    36,    37,    38,    39
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int TrigSParser::yyeof_ = 0;
  const int TrigSParser::yylast_ = 110;
  const int TrigSParser::yynnts_ = 55;
  const int TrigSParser::yyempty_ = -2;
  const int TrigSParser::yyfinal_ = 7;
  const int TrigSParser::yyterror_ = 1;
  const int TrigSParser::yyerrcode_ = 256;
  const int TrigSParser::yyntokens_ = 40;

  const unsigned int TrigSParser::yyuser_token_number_max_ = 294;
  const TrigSParser::token_number_type TrigSParser::yyundef_token_ = 2;


} // w3c_sw

/* Line 1136 of lalr1.cc  */
#line 1738 "lib/TrigSParser/TrigSParser.cpp"


/* Line 1138 of lalr1.cc  */
#line 611 "lib/TrigSParser/TrigSParser.ypp"
 /*** Additional Code ***/

void w3c_sw::TrigSParser::error(const TrigSParser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}

/* START Driver (@@ stand-alone would allow it to be shared with other parsers */

namespace w3c_sw {

void TrigSDriver::parse (IStreamContext& in, RdfDB* db, BasicGraphPattern* bgp)
{
    // clear prefixes for nth run but keep them around for e.g. serialization.
    clearPrefixes();

    if (db != NULL)
	setDB(db);
    if (bgp != NULL)
	setGraph(bgp);

    streamname = in.nameStr;

    TrigSScanner scanner(this, in.p);
    scanner.set_debug(trace_scanning);
    this->lexer = &scanner;

    TrigSParser parser(*this);
    parser.set_debug_level(trace_parsing);
    defaultBGP = curBGP ? curBGP : this->db->ensureGraph(NULL);
    parser.parse();
}

void TrigSDriver::parse (IStreamContext& in, BasicGraphPattern* bgp) {
    parse(in, NULL, bgp);
}

void TrigSDriver::parse (std::string turtleStr, RdfDB* db, BasicGraphPattern* bgp) {
    IStreamContext in(turtleStr.c_str(), IStreamContext::STRING);
    parse(in, db, bgp);
}

void TrigSDriver::parse (std::string turtleStr, BasicGraphPattern* bgp) {
    IStreamContext in(turtleStr.c_str(), IStreamContext::STRING);
    parse(in, NULL, bgp);
}

} // namespace w3c_sw

/* END Driver */


