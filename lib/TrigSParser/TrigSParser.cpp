
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software
   Foundation, Inc.
   
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


/* Line 311 of lalr1.cc  */
#line 43 "lib/TrigSParser/TrigSParser.cpp"


#include "TrigSParser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 121 "lib/TrigSParser/TrigSParser.ypp"

#include "../TrigSScanner.hpp"

/* Line 317 of lalr1.cc  */
#line 173 "lib/TrigSParser/TrigSParser.ypp"

#include "../TrigSScanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lexWrapper

#include "RdfDB.hpp"


/* Line 317 of lalr1.cc  */
#line 70 "lib/TrigSParser/TrigSParser.cpp"

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


/* Line 380 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

namespace w3c_sw {

/* Line 380 of lalr1.cc  */
#line 139 "lib/TrigSParser/TrigSParser.cpp"
#if YYERROR_VERBOSE

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

#endif

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
    location_type yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
/* Line 553 of lalr1.cc  */
#line 31 "lib/TrigSParser/TrigSParser.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 553 of lalr1.cc  */
#line 323 "lib/TrigSParser/TrigSParser.cpp"

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
    if (yyn == yypact_ninf_)
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
	if (yyn == 0 || yyn == yytable_ninf_)
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

/* Line 678 of lalr1.cc  */
#line 190 "lib/TrigSParser/TrigSParser.ypp"
    {
	driver.root = (yysemantic_stack_[(2) - (2)].p_DefaultGraphPattern); // last graph -- kinda useless
    }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 213 "lib/TrigSParser/TrigSParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 219 "lib/TrigSParser/TrigSParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 221 "lib/TrigSParser/TrigSParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 223 "lib/TrigSParser/TrigSParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 231 "lib/TrigSParser/TrigSParser.ypp"
    { (yyval.p_DefaultGraphPattern) = NULL; }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 232 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_DefaultGraphPattern) = (yysemantic_stack_[(2) - (2)].p_DefaultGraphPattern);
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 239 "lib/TrigSParser/TrigSParser.ypp"
    {
	driver.curBGP = driver.db->ensureGraph((yysemantic_stack_[(2) - (1)].p_URI));
	driver.neededBGP = NULL;
      }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 242 "lib/TrigSParser/TrigSParser.ypp"
    {
	  (yyval.p_DefaultGraphPattern) = (yysemantic_stack_[(5) - (4)].p_DefaultGraphPattern);
	  driver.neededBGP = NULL;
	  driver.curBGP = NULL;
      }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 250 "lib/TrigSParser/TrigSParser.ypp"
    { (yyval.p_URI) = NULL; }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 256 "lib/TrigSParser/TrigSParser.ypp"
    { (yyval.p_DefaultGraphPattern) = NULL; }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 257 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_DefaultGraphPattern) = (yysemantic_stack_[(1) - (1)].p_DefaultGraphPattern);
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 264 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_DefaultGraphPattern) = driver.neededBGP ? driver.neededBGP : (yysemantic_stack_[(2) - (2)].p_DefaultGraphPattern);
	driver.neededBGP = NULL;
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 272 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_DefaultGraphPattern) = (yysemantic_stack_[(2) - (2)].p_DefaultGraphPattern);
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 279 "lib/TrigSParser/TrigSParser.ypp"
    { (yyval.p_DefaultGraphPattern) = NULL; }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 284 "lib/TrigSParser/TrigSParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 287 "lib/TrigSParser/TrigSParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_BNode);
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 347 "lib/TrigSParser/TrigSParser.ypp"
    {
	if (!driver.curBGP)
	    driver.neededBGP = driver.curBGP = new DefaultGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 356 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 360 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 367 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_BNode) = (yysemantic_stack_[(1) - (1)].p_BNode);
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 370 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_BNode) = (yysemantic_stack_[(1) - (1)].p_BNode);
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 376 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 380 "lib/TrigSParser/TrigSParser.ypp"
    {
	  (yyval.p_BNode) = (BNode*)driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 389 "lib/TrigSParser/TrigSParser.ypp"
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

  case 51:

/* Line 678 of lalr1.cc  */
#line 411 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 414 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 421 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 424 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BNode);
    }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 430 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 436 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 442 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 445 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 448 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 451 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 454 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 457 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 464 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 472 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 479 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 483 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 491 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 495 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_uri_or_langtag) = (yysemantic_stack_[(1) - (1)].p_uri_or_langtag);
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 501 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 504 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 507 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 513 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 516 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 519 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 525 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 528 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 531 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 537 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 540 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 543 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 549 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_BooleanRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 552 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_BooleanRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 558 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_string) = (yysemantic_stack_[(1) - (1)].p_string);
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 561 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_string) = (yysemantic_stack_[(1) - (1)].p_string);
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 564 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_string) = (yysemantic_stack_[(1) - (1)].p_string);
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 567 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_string) = (yysemantic_stack_[(1) - (1)].p_string);
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 573 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 576 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 582 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 585 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 591 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BNode);
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 594 "lib/TrigSParser/TrigSParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BNode);
    }
    break;



/* Line 678 of lalr1.cc  */
#line 1071 "lib/TrigSParser/TrigSParser.cpp"
	default:
          break;
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

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
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
    if (yychar != yyempty_)
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
  TrigSParser::yysyntax_error_ (int yystate, int tok)
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
  const signed char TrigSParser::yypact_ninf_ = -65;
  const signed char
  TrigSParser::yypact_[] =
  {
        10,     6,    40,   -65,   -65,   -65,   -65,   -65,     3,    37,
     -65,   -65,   -65,   -65,    38,   -65,   -65,   -65,   -65,   -65,
       8,    47,   -65,    47,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -65,    39,   -65,    41,   -65,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,    17,   -65,   -65,
      13,   -65,    -4,   -65,   -65,    73,   -65,    47,   -65,   -65,
      73,    73,   -23,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,    35,    47,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,    42,   -65,   -65,   -65,   -65,   -65,    45,    43,    73,
     -65,    47,   -65,   -65,   -65,    47,   -65,   -65
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  TrigSParser::yydefact_[] =
  {
         4,     0,     0,    13,     6,     5,     8,     1,     2,     3,
      87,    90,    89,    14,     0,    18,    88,     9,     7,    15,
       0,    19,    10,     0,    48,    81,    82,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    83,    84,    85,    86,
      91,    92,    62,     0,    20,    23,    27,    47,    46,    25,
      55,    58,    59,    69,    70,    71,    60,    67,    57,    61,
       0,    54,     0,    51,    53,     0,    16,    19,    24,    21,
      37,     0,     0,    65,    66,    68,    63,    11,    50,    52,
      45,     0,     0,    44,    56,    22,    38,    28,    36,    26,
      64,     0,    49,    34,    41,    43,    12,    29,    39,    31,
      35,     0,    42,    32,    33,     0,    40,    30
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  TrigSParser::yypgoto_[] =
  {
       -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,   -15,   -65,   -65,   -65,   -65,   -65,
     -65,   -64,   -65,   -65,   -65,   -65,   -65,   -65,   -47,   -65,
     -65,   -42,   -38,   -20,   -65,   -65,   -65,   -65,   -18,   -19,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,    -8,   -65,   -65
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  TrigSParser::yydefgoto_[] =
  {
        -1,     2,     3,     4,     9,     5,    18,    20,    60,    91,
       8,    13,    21,    14,    43,    44,    68,    69,    45,    71,
      70,    81,   103,   104,   100,    97,    87,    88,    93,   102,
      98,    94,    82,    61,    47,    65,    48,    62,    95,    64,
      83,    50,    51,    74,    75,    76,    52,    53,    54,    55,
      56,    57,    58,    16,    59
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char TrigSParser::yytable_ninf_ = -18;
  const signed char
  TrigSParser::yytable_[] =
  {
        15,    46,    49,    23,    78,    63,    86,    89,   -17,    24,
      10,    11,    12,     1,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    10,
      11,    12,    40,    41,    72,    42,    10,    11,    12,     6,
       7,    17,    22,    19,    79,    66,    77,    46,    49,    92,
      67,    96,    85,   101,    23,    73,    99,    84,   107,   106,
      24,   105,    84,    84,    90,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      10,    11,    12,    40,    41,    80,    42,     0,     0,     0,
       0,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,    12
  };

  /* YYCHECK.  */
  const signed char
  TrigSParser::yycheck_[] =
  {
         8,    21,    21,     7,     8,    23,    70,    71,     5,    13,
      33,    34,    35,     3,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    17,    39,    33,    34,    35,    33,
       0,     4,    34,     5,    62,     6,    33,    67,    67,    14,
       9,     9,    67,    10,     7,    38,    11,    65,   105,   101,
      13,    99,    70,    71,    72,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    12,    39,    -1,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    35
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  TrigSParser::yystos_[] =
  {
         0,     3,    41,    42,    43,    45,    33,     0,    50,    44,
      33,    34,    35,    51,    53,    92,    93,     4,    46,     5,
      47,    52,    34,     7,    13,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      36,    37,    39,    54,    55,    58,    73,    74,    76,    79,
      81,    82,    86,    87,    88,    89,    90,    91,    92,    94,
      48,    73,    77,    78,    79,    75,     6,     9,    56,    57,
      60,    59,    17,    38,    83,    84,    85,    33,     8,    78,
      12,    61,    72,    80,    92,    54,    61,    66,    67,    61,
      92,    49,    14,    68,    71,    78,     9,    65,    70,    11,
      64,    10,    69,    62,    63,    72,    71,    68
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
      48,    49,    46,    50,    50,    52,    51,    53,    53,    54,
      54,    55,    56,    57,    57,    59,    58,    60,    58,    61,
      62,    63,    63,    64,    65,    65,    66,    67,    67,    68,
      69,    70,    70,    71,    72,    72,    73,    73,    75,    74,
      76,    77,    77,    78,    78,    79,    80,    81,    81,    81,
      81,    81,    81,    82,    83,    84,    84,    85,    85,    86,
      86,    86,    87,    87,    87,    88,    88,    88,    89,    89,
      89,    90,    90,    91,    91,    91,    91,    92,    92,    93,
      93,    94,    94
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  TrigSParser::yyr2_[] =
  {
         0,     2,     2,     2,     0,     1,     0,     2,     2,     0,
       0,     0,     7,     0,     2,     0,     5,     0,     1,     0,
       1,     2,     2,     0,     1,     0,     3,     0,     3,     3,
       2,     0,     1,     2,     0,     2,     1,     0,     1,     2,
       2,     0,     2,     1,     1,     1,     1,     1,     0,     4,
       3,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
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
      45,    -1,    -1,    44,    46,    -1,     3,    33,    -1,    -1,
      -1,    -1,     4,    47,    34,    48,    33,    49,     9,    -1,
      -1,    50,    51,    -1,    -1,    53,     5,    52,    54,     6,
      -1,    -1,    92,    -1,    -1,    55,    -1,    58,    57,    -1,
       9,    54,    -1,    -1,    56,    -1,    -1,    79,    59,    61,
      -1,    -1,    73,    60,    66,    -1,    72,    68,    65,    -1,
      72,    68,    -1,    -1,    62,    -1,    11,    63,    -1,    -1,
      65,    64,    -1,    67,    -1,    -1,    61,    -1,    71,    70,
      -1,    10,    71,    -1,    -1,    70,    69,    -1,    78,    -1,
      80,    -1,    12,    -1,    76,    -1,    74,    -1,    -1,    13,
      75,    61,    14,    -1,     7,    77,     8,    -1,    78,    -1,
      77,    78,    -1,    79,    -1,    73,    -1,    81,    -1,    92,
      -1,    92,    -1,    82,    -1,    86,    -1,    90,    -1,    94,
      -1,    39,    -1,    91,    85,    -1,    17,    92,    -1,    38,
      -1,    83,    -1,    -1,    84,    -1,    87,    -1,    88,    -1,
      89,    -1,    20,    -1,    21,    -1,    22,    -1,    23,    -1,
      24,    -1,    25,    -1,    26,    -1,    27,    -1,    28,    -1,
      18,    -1,    19,    -1,    29,    -1,    30,    -1,    31,    -1,
      32,    -1,    33,    -1,    93,    -1,    35,    -1,    34,    -1,
      36,    -1,    37,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  TrigSParser::yyprhs_[] =
  {
         0,     0,     3,     6,     9,    10,    12,    13,    16,    19,
      20,    21,    22,    30,    31,    34,    35,    41,    42,    44,
      45,    47,    50,    53,    54,    56,    57,    61,    62,    66,
      70,    73,    74,    76,    79,    80,    83,    85,    86,    88,
      91,    94,    95,    98,   100,   102,   104,   106,   108,   109,
     114,   118,   120,   123,   125,   127,   129,   131,   133,   135,
     137,   139,   141,   143,   146,   149,   151,   153,   154,   156,
     158,   160,   162,   164,   166,   168,   170,   172,   174,   176,
     178,   180,   182,   184,   186,   188,   190,   192,   194,   196,
     198,   200,   202
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  TrigSParser::yyrline_[] =
  {
         0,   190,   190,   197,   201,   203,   207,   209,   213,   219,
     221,   223,   219,   231,   232,   239,   239,   250,   251,   256,
     257,   264,   272,   279,   280,   284,   284,   287,   287,   294,
     299,   303,   305,   310,   314,   316,   321,   325,   327,   332,
     337,   341,   343,   347,   356,   360,   367,   370,   376,   376,
     389,   411,   414,   421,   424,   430,   436,   442,   445,   448,
     451,   454,   457,   464,   472,   479,   483,   491,   495,   501,
     504,   507,   513,   516,   519,   525,   528,   531,   537,   540,
     543,   549,   552,   558,   561,   564,   567,   573,   576,   582,
     585,   591,   594
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
  const int TrigSParser::yylast_ = 108;
  const int TrigSParser::yynnts_ = 55;
  const int TrigSParser::yyempty_ = -2;
  const int TrigSParser::yyfinal_ = 7;
  const int TrigSParser::yyterror_ = 1;
  const int TrigSParser::yyerrcode_ = 256;
  const int TrigSParser::yyntokens_ = 40;

  const unsigned int TrigSParser::yyuser_token_number_max_ = 294;
  const TrigSParser::token_number_type TrigSParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 1627 "lib/TrigSParser/TrigSParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 601 "lib/TrigSParser/TrigSParser.ypp"
 /*** Additional Code ***/

void w3c_sw::TrigSParser::error(const TrigSParser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}

/* START Driver (@@ stand-alone would allow it to be shared with other parsers */

namespace w3c_sw {

bool TrigSDriver::parse(IStreamContext& in)
{
    streamname = in.nameStr;

    TrigSScanner scanner(this, in.p);
    scanner.set_debug(trace_scanning);
    this->lexer = &scanner;

    TrigSParser parser(*this);
    parser.set_debug_level(trace_parsing);
    return (parser.parse());
}

} // namespace w3c_sw

/* END Driver */


