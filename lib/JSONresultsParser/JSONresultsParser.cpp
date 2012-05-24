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
#line 41 "lib/JSONresultsParser/JSONresultsParser.cpp"


#include "JSONresultsParser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 182 "lib/JSONresultsParser/JSONresultsParser.ypp"

#include "../JSONresultsScanner.hpp"

/* Line 299 of lalr1.cc  */
#line 214 "lib/JSONresultsParser/JSONresultsParser.ypp"

#include "../JSONresultsScanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lexWrapper


/* Line 299 of lalr1.cc  */
#line 66 "lib/JSONresultsParser/JSONresultsParser.cpp"

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
#line 152 "lib/JSONresultsParser/JSONresultsParser.cpp"

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  JSONresultsParser::yytnamerr_ (const char *yystr)
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
  JSONresultsParser::JSONresultsParser (class JSONresultsDriver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {
  }

  JSONresultsParser::~JSONresultsParser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  JSONresultsParser::yy_symbol_value_print_ (int yytype,
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
  JSONresultsParser::yy_symbol_print_ (int yytype,
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
  JSONresultsParser::yydestruct_ (const char* yymsg,
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
  JSONresultsParser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  JSONresultsParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  JSONresultsParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  JSONresultsParser::debug_level_type
  JSONresultsParser::debug_level () const
  {
    return yydebug_;
  }

  void
  JSONresultsParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  inline bool
  JSONresultsParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  JSONresultsParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  JSONresultsParser::parse ()
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
#line 43 "lib/JSONresultsParser/JSONresultsParser.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 565 of lalr1.cc  */
#line 346 "lib/JSONresultsParser/JSONresultsParser.cpp"

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
#line 228 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	if (driver.root == NULL)
	    driver.startBindingSet();
	else
	    driver.curResultSet = driver.root;
      }
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 233 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	  driver.root = driver.endBindingSet();
	  driver.curResultSet = NULL;
      }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 258 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	// throw away link $4
	delete (yysemantic_stack_[(5) - (4)].p_str);
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 265 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	driver.addBindingVar(driver.getVariable(*(yysemantic_stack_[(4) - (4)].p_str)));
	delete (yysemantic_stack_[(4) - (4)].p_str);
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 272 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	driver.addBindingVar(driver.getVariable(*(yysemantic_stack_[(2) - (2)].p_str)));
	delete (yysemantic_stack_[(2) - (2)].p_str);
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 301 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	driver.startBindingRow(false);
      }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 303 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 318 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	driver.addBinding(driver.getVariable(*(yysemantic_stack_[(5) - (1)].p_str)), (yysemantic_stack_[(5) - (4)].p_TTerm));
	delete (yysemantic_stack_[(5) - (1)].p_str);
    }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 325 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 328 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(2) - (2)].p_BNode);
    }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 331 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(2) - (2)].p_literal);
    }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 334 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(2) - (2)].p_literal);
    }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 337 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	driver.curValue = (yysemantic_stack_[(1) - (1)].p_str);
      }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 339 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	  driver.curValue = NULL;
	  (yyval.p_TTerm) = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 343 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	driver.curDatatype = (yysemantic_stack_[(1) - (1)].p_URI);
      }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 345 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	  driver.curDatatype = NULL;
	  (yyval.p_TTerm) = (yysemantic_stack_[(4) - (4)].p_literal);
      }
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 349 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	driver.curLang = (yysemantic_stack_[(1) - (1)].p_str);
      }
    break;

  case 36:

/* Line 690 of lalr1.cc  */
#line 351 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	  driver.curLang = NULL;
	  (yyval.p_TTerm) = (yysemantic_stack_[(4) - (4)].p_literal);
      }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 358 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_URI) = driver.getURI(*(yysemantic_stack_[(3) - (3)].p_str));
	delete (yysemantic_stack_[(3) - (3)].p_str);
    }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 365 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_BNode) = driver.getBNode(*(yysemantic_stack_[(3) - (3)].p_str));
	delete (yysemantic_stack_[(3) - (3)].p_str);
    }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 372 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_literal) = (yysemantic_stack_[(3) - (3)].p_literal);
    }
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 378 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_str) = (yysemantic_stack_[(2) - (2)].p_str);
    }
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 384 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_str) = NULL;
    }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 391 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_literal) = driver.getRDFLiteral(*(yysemantic_stack_[(3) - (3)].p_str), NULL, (yysemantic_stack_[(3) - (1)].p_str) ? new LANGTAG(*(yysemantic_stack_[(3) - (1)].p_str)) : NULL);
	delete (yysemantic_stack_[(3) - (3)].p_str);
	delete (yysemantic_stack_[(3) - (1)].p_str);
    }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 396 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_literal) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_str), NULL, (yysemantic_stack_[(2) - (2)].p_str) ? new LANGTAG(*(yysemantic_stack_[(2) - (2)].p_str)) : NULL);
	delete (yysemantic_stack_[(2) - (1)].p_str);
	delete (yysemantic_stack_[(2) - (2)].p_str);
    }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 404 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_literal) = (yysemantic_stack_[(3) - (3)].p_literal);
    }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 410 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_literal) = driver.getRDFLiteral(*(yysemantic_stack_[(3) - (3)].p_str), (yysemantic_stack_[(3) - (1)].p_URI), NULL);
	delete (yysemantic_stack_[(3) - (3)].p_str);
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 414 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_literal) = driver.getRDFLiteral(*(yysemantic_stack_[(3) - (1)].p_str), (yysemantic_stack_[(3) - (3)].p_URI), NULL);
	delete (yysemantic_stack_[(3) - (1)].p_str);
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 421 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(2) - (2)].p_TTerm);
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 424 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_TTerm) = driver.getRDFLiteral(*driver.curValue, (yysemantic_stack_[(4) - (1)].p_URI), NULL);
      delete driver.curValue;
      driver.curDatatype = NULL;
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 429 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_TTerm) = driver.getRDFLiteral(*driver.curValue, NULL, (yysemantic_stack_[(4) - (1)].p_str) ? new LANGTAG(*(yysemantic_stack_[(4) - (1)].p_str)) : NULL);
      delete driver.curValue;
      delete (yysemantic_stack_[(4) - (1)].p_str);
      driver.curLang = NULL;
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 438 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI(*driver.curValue);
	delete driver.curValue;
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 442 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_TTerm) = driver.getBNode(*driver.curValue);
	delete driver.curValue;
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 446 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_TTerm) = driver.getRDFLiteral(*driver.curValue, NULL, (yysemantic_stack_[(2) - (2)].p_str) ? new LANGTAG(*(yysemantic_stack_[(2) - (2)].p_str)) : NULL);
	delete driver.curValue;
	delete (yysemantic_stack_[(2) - (2)].p_str);
    }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 451 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_TTerm) = driver.getRDFLiteral(*driver.curValue, (yysemantic_stack_[(3) - (3)].p_URI), NULL);
	delete driver.curValue;
    }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 458 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_literal) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_str), driver.curDatatype, NULL);
	delete (yysemantic_stack_[(4) - (4)].p_str);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 462 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_literal) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (1)].p_str), driver.curDatatype, NULL);
	delete (yysemantic_stack_[(4) - (1)].p_str);
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 469 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_literal) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_str), NULL, driver.curLang ? new LANGTAG(*driver.curLang) : NULL);
	delete (yysemantic_stack_[(4) - (4)].p_str);
	delete driver.curLang;
    }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 474 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_literal) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (1)].p_str), NULL, driver.curLang ? new LANGTAG(*driver.curLang) : NULL);
	delete (yysemantic_stack_[(4) - (1)].p_str);
	delete driver.curLang;
    }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 482 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_str) = (yysemantic_stack_[(3) - (3)].p_str);
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 488 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_URI) = driver.getURI(*(yysemantic_stack_[(3) - (3)].p_str));
	delete (yysemantic_stack_[(3) - (3)].p_str);
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 495 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_str) = (yysemantic_stack_[(3) - (3)].p_str);
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 572 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_str) = new std::string("head");
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 575 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("vars");
    }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 578 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("results");
    }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 581 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("bindings");
    }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 584 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("type");
    }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 587 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("uri");
    }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 590 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("bnode");
    }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 593 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("literal");
    }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 596 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("typedLiteral");
    }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 599 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("datatype");
    }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 602 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("lang");
    }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 605 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("value");
    }
    break;



/* Line 690 of lalr1.cc  */
#line 987 "lib/JSONresultsParser/JSONresultsParser.cpp"
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
  JSONresultsParser::yysyntax_error_ (int yystate, int yytoken)
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
  const signed char JSONresultsParser::yypact_ninf_ = -119;
  const short int
  JSONresultsParser::yypact_[] =
  {
        23,  -119,    48,     8,  -119,  -119,  -119,    46,    52,    59,
      49,  -119,  -119,    61,    70,    68,  -119,    51,  -119,  -119,
    -119,  -119,    85,    95,   100,   162,   169,    77,  -119,    88,
     145,  -119,  -119,   170,   171,  -119,  -119,   174,   175,  -119,
    -119,    97,    97,  -119,   173,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,   168,  -119,   179,  -119,  -119,
    -119,  -119,    16,    97,    41,    97,  -119,  -119,  -119,   177,
     179,  -119,  -119,  -119,   104,   181,  -119,    97,  -119,  -119,
     111,  -119,   180,  -119,  -119,  -119,   119,   182,   183,   184,
     185,  -119,   188,   189,   190,  -119,  -119,  -119,  -119,   191,
     192,   193,   194,  -119,    97,    97,    97,   127,   129,   129,
     137,   137,     5,     2,  -119,  -119,  -119,  -119,   195,   196,
     119,  -119,   197,   135,  -119,   198,   139,  -119,  -119,  -119,
     199,   200,  -119,   201,   202,   146,   146,  -119,  -119,  -119,
     199,   203,   146,   204,   146,   205,   138,  -119,  -119,   137,
     142,   137,   135,   139,  -119,   142,   135,   137,   139,   137,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  JSONresultsParser::yydefact_[] =
  {
         0,     2,     0,     0,     1,    62,    63,     0,     0,     0,
       0,    68,    69,     0,     0,     0,     3,     0,    64,    65,
      66,    67,     0,     0,     6,     0,     0,     0,     4,     0,
       0,     7,     9,     0,     0,    70,    71,     0,     0,     8,
       5,     0,     0,    16,     0,    72,    73,    74,    75,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    90,    89,    91,    92,    93,    94,    96,    97,    95,
     102,    98,    99,   100,   101,     0,    11,     0,    10,    14,
      21,    19,     0,     0,     0,     0,    12,    15,    24,     0,
       0,    17,    20,    13,     0,     0,    18,     0,    22,    25,
       0,    23,     0,    31,    33,    35,     0,     0,     0,     0,
       0,    26,     0,     0,     0,    27,    28,    29,    30,     0,
       0,     0,     0,    76,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    59,    60,    61,    32,     0,     0,
       0,    34,     0,     0,    36,     0,     0,    37,    38,    39,
      41,     0,    45,     0,     0,     0,     0,    48,    51,    52,
      41,     0,     0,     0,     0,     0,     0,    42,    44,     0,
       0,     0,     0,     0,    53,     0,     0,     0,     0,     0,
      40,    43,    47,    46,    49,    50,    54,    56,    55,    58,
      57
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  JSONresultsParser::yypgoto_[] =
  {
      -119,  -119,  -119,  -119,  -119,  -119,  -119,   156,   158,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,   120,  -119,  -119,  -119,
     114,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,    53,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -118,  -108,  -111,
     209,  -119,    -7,   206,   187,   -99,   -97,   -59,   -64,   -41,
    -100,   -83,   -98,   -95,   -38
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  JSONresultsParser::yydefgoto_[] =
  {
        -1,     2,     3,     7,    31,    32,    22,    23,    24,    79,
      87,    82,    13,    37,    92,    84,    81,    83,    99,    94,
      88,   102,   112,   113,   114,   115,   116,   117,   167,   168,
     149,   118,   152,   137,   157,   141,   144,   103,   104,   105,
      63,    25,    64,    65,    66,    67,    68,   106,    69,   108,
      71,    72,    73,    74,    89
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char JSONresultsParser::yytable_ninf_ = -1;
  const unsigned char
  JSONresultsParser::yytable_[] =
  {
        70,    70,   109,    75,    76,   110,   121,   119,    26,   120,
     142,   145,   147,   148,   150,   153,   139,     5,     6,   138,
      85,   151,    26,   122,    86,   154,     1,    51,    52,   109,
      51,    52,   110,    57,    58,   109,   107,   110,    59,    60,
     160,   158,    70,   159,    70,    90,   165,    93,     4,    91,
       9,   181,    15,   183,    27,   180,    70,   161,    10,   188,
     163,   190,   182,   107,   107,   107,    16,   186,   140,   143,
     146,   110,   109,   185,    11,    12,    17,   109,   189,    18,
      19,    20,    21,    70,    70,    70,   134,   135,   136,   184,
      28,   107,   107,   187,    35,    36,   172,   173,   107,    29,
     107,    20,    21,   176,    30,   178,     5,     6,    97,    98,
      20,    21,    11,    12,    35,    36,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    49,    50,    51,    52,    45,    46,
      47,    48,    57,    58,    59,    60,    53,    54,    55,    56,
      49,    50,    49,    50,    51,    52,    18,    19,    57,    58,
      59,    60,    51,    52,    55,    56,    53,    54,    33,    49,
      50,    59,    60,    57,    58,    34,    78,    41,    42,    43,
      77,    44,    80,    95,   100,   111,    40,    39,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   155,
     156,   162,   164,   166,   169,   170,   171,   175,   177,   179,
      96,   101,     8,   174,    38,    14
  };

  /* YYCHECK.  */
  const unsigned char
  JSONresultsParser::yycheck_[] =
  {
        41,    42,   100,    41,    42,   100,   106,   106,    15,   106,
     128,   129,   130,   131,   132,   133,   127,     9,    10,   127,
       4,   132,    29,   106,     8,   133,     3,    25,    26,   127,
      25,    26,   127,    31,    32,   133,   100,   132,    33,    34,
     140,   140,    83,   140,    85,     4,   146,    85,     0,     8,
       4,   169,     3,   171,     3,   166,    97,   140,     6,   177,
     143,   179,   170,   127,   128,   129,     5,   175,   127,   128,
     129,   166,   170,   173,    15,    16,     6,   175,   178,    11,
      12,    13,    14,   124,   125,   126,   124,   125,   126,   172,
       5,   155,   156,   176,    17,    18,   155,   156,   162,     4,
     164,    13,    14,   162,     4,   164,     9,    10,     4,     5,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    23,    24,    25,    26,    19,    20,
      21,    22,    31,    32,    33,    34,    27,    28,    29,    30,
      23,    24,    23,    24,    25,    26,    11,    12,    31,    32,
      33,    34,    25,    26,    29,    30,    27,    28,     6,    23,
      24,    33,    34,    31,    32,     6,     8,     7,     7,     5,
       7,     6,     3,     6,     3,     5,    30,    29,     6,     6,
       6,     6,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
      90,    97,     3,   160,    27,     9
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  JSONresultsParser::yystos_[] =
  {
         0,     3,    38,    39,     0,     9,    10,    40,    77,     4,
       6,    15,    16,    49,    80,     3,     5,     6,    11,    12,
      13,    14,    43,    44,    45,    78,    79,     3,     5,     4,
       4,    41,    42,     6,     6,    17,    18,    50,    81,    45,
      44,     7,     7,     5,     6,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    77,    79,    80,    81,    82,    83,    85,
      86,    87,    88,    89,    90,    91,    91,     7,     8,    46,
       3,    53,    48,    54,    52,     4,     8,    47,    57,    91,
       4,     8,    51,    91,    56,     6,    53,     4,     5,    55,
       3,    57,    58,    74,    75,    76,    84,    85,    86,    89,
      90,     5,    59,    60,    61,    62,    63,    64,    68,    82,
      83,    87,    88,     6,     6,     6,     6,     4,     4,     4,
       4,     4,     4,     4,    91,    91,    91,    70,    75,    76,
      84,    72,    74,    84,    73,    74,    84,    74,    74,    67,
      74,    76,    69,    74,    75,     4,     4,    71,    82,    83,
      87,    88,     4,    88,     4,    87,     4,    65,    66,     4,
       4,     4,    84,    84,    66,     4,    84,     4,    84,     4,
      76,    74,    75,    74,    88,    87,    75,    88,    74,    87,
      74
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  JSONresultsParser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  JSONresultsParser::yyr1_[] =
  {
         0,    37,    39,    38,    40,    41,    42,    42,    43,    43,
      44,    46,    45,    47,    48,    48,    49,    50,    51,    52,
      52,    54,    53,    55,    56,    56,    57,    58,    58,    58,
      58,    59,    58,    60,    58,    61,    58,    62,    63,    64,
      65,    66,    66,    67,    67,    68,    69,    69,    70,    70,
      70,    71,    71,    71,    71,    72,    72,    73,    73,    74,
      75,    76,    77,    77,    78,    78,    79,    79,    80,    80,
      81,    81,    82,    82,    83,    83,    84,    85,    85,    86,
      86,    87,    87,    88,    88,    89,    89,    90,    90,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  JSONresultsParser::yyr2_[] =
  {
         0,     2,     0,     6,     5,     2,     0,     1,     3,     2,
       5,     0,     7,     2,     0,     2,     5,     6,     2,     0,
       2,     0,     5,     2,     0,     2,     5,     2,     2,     2,
       2,     0,     4,     0,     4,     0,     4,     3,     3,     3,
       2,     0,     1,     3,     2,     3,     3,     3,     2,     4,
       4,     1,     1,     2,     3,     4,     4,     4,     4,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const JSONresultsParser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "GT_LCURLEY", "GT_COMMA",
  "GT_RCURLEY", "GT_COLON", "GT_LBRACKET", "GT_RBRACKET",
  "GT_H_22__head_H_22_", "GT_H_27__head_H_27_", "GT_H_22__link_H_22_",
  "GT_H_27__link_H_27_", "GT_H_22__vars_H_22_", "GT_H_27__vars_H_27_",
  "GT_H_22__results_H_22_", "GT_H_27__results_H_27_",
  "GT_H_22__bindings_H_22_", "GT_H_27__bindings_H_27_",
  "GT_H_22__uri_H_22_", "GT_H_27__uri_H_27_", "GT_H_22__bnode_H_22_",
  "GT_H_27__bnode_H_27_", "GT_H_22__type_H_22_", "GT_H_27__type_H_27_",
  "GT_H_22__value_H_22_", "GT_H_27__value_H_27_", "GT_H_22__literal_H_22_",
  "GT_H_27__literal_H_27_", "GT_H_22__typed_MINUS_literal_H_22_",
  "GT_H_27__typed_MINUS_literal_H_27_", "GT_H_22__datatype_H_22_",
  "GT_H_27__datatype_H_27_", "GT_H_22__xml_COLON_lang_H_22_",
  "GT_H_27__xml_COLON_lang_H_27_", "STRING_LITERAL2", "STRING_LITERAL1",
  "$accept", "Top", "$@1", "head", "_O_QGT_COMMA_E_S_Q_link_E_C",
  "_Q_O_QGT_COMMA_E_S_Q_link_E_C_E_Opt",
  "_O_Q_link_E_S_QGT_COMMA_E_S_Qvars_E_Or_Qvars_E_S_QGT_COMMA_E_S_Q_link_E_Opt_C",
  "_link", "vars", "$@2", "_O_QGT_COMMA_E_S_Qword_E_C",
  "_Q_O_QGT_COMMA_E_S_Qword_E_C_E_Star", "results", "bindings",
  "_O_QGT_COMMA_E_S_Qsolution_E_C",
  "_Q_O_QGT_COMMA_E_S_Qsolution_E_C_E_Star", "solution", "$@3",
  "_O_QGT_COMMA_E_S_Qbinding_E_C",
  "_Q_O_QGT_COMMA_E_S_Qbinding_E_C_E_Star", "binding", "RDFterm", "$@4",
  "$@5", "$@6", "t_uri", "t_bnode", "t_plainLiteral",
  "_O_QGT_COMMA_E_S_Qlang_E_C", "_Q_O_QGT_COMMA_E_S_Qlang_E_C_E_Opt",
  "_O_Qlang_E_S_QGT_COMMA_E_S_Qvalue_E_Or_Qvalue_E_S_QGT_COMMA_E_S_Qlang_E_Opt_C",
  "t_typedLiteral",
  "_O_Qdatatype_E_S_QGT_COMMA_E_S_Qvalue_E_Or_Qvalue_E_S_QGT_COMMA_E_S_Qdatatype_E_C",
  "v_all", "vt_all", "d_typedLiteral", "l_plainLiteral", "value",
  "datatype", "lang", "headWord", "linkWord", "varsWord", "resultsWord",
  "bindingsWord", "uriWord", "bnodeWord", "typeKey", "typeWord",
  "valueWord", "literalWord", "typedLiteralWord", "datatypeWord",
  "langWord", "word", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const JSONresultsParser::rhs_number_type
  JSONresultsParser::yyrhs_[] =
  {
        38,     0,    -1,    -1,     3,    39,    40,     4,    49,     5,
      -1,    77,     6,     3,    43,     5,    -1,     4,    44,    -1,
      -1,    41,    -1,    44,     4,    45,    -1,    45,    42,    -1,
      78,     6,     7,    91,     8,    -1,    -1,    79,     6,     7,
      91,    46,    48,     8,    -1,     4,    91,    -1,    -1,    48,
      47,    -1,    80,     6,     3,    50,     5,    -1,    81,     6,
       7,    53,    52,     8,    -1,     4,    53,    -1,    -1,    52,
      51,    -1,    -1,     3,    54,    57,    56,     5,    -1,     4,
      57,    -1,    -1,    56,    55,    -1,    91,     6,     3,    58,
       5,    -1,    84,    62,    -1,    84,    63,    -1,    84,    64,
      -1,    84,    68,    -1,    -1,    74,    59,     4,    70,    -1,
      -1,    75,    60,     4,    72,    -1,    -1,    76,    61,     4,
      73,    -1,    82,     4,    74,    -1,    83,     4,    74,    -1,
      87,     4,    67,    -1,     4,    76,    -1,    -1,    65,    -1,
      76,     4,    74,    -1,    74,    66,    -1,    88,     4,    69,
      -1,    75,     4,    74,    -1,    74,     4,    75,    -1,    84,
      71,    -1,    75,     4,    84,    88,    -1,    76,     4,    84,
      87,    -1,    82,    -1,    83,    -1,    87,    66,    -1,    88,
       4,    75,    -1,    84,    88,     4,    74,    -1,    74,     4,
      84,    88,    -1,    84,    87,     4,    74,    -1,    74,     4,
      84,    87,    -1,    86,     6,    91,    -1,    89,     6,    91,
      -1,    90,     6,    91,    -1,     9,    -1,    10,    -1,    11,
      -1,    12,    -1,    13,    -1,    14,    -1,    15,    -1,    16,
      -1,    17,    -1,    18,    -1,    19,    -1,    20,    -1,    21,
      -1,    22,    -1,    85,     6,    -1,    23,    -1,    24,    -1,
      25,    -1,    26,    -1,    27,    -1,    28,    -1,    29,    -1,
      30,    -1,    31,    -1,    32,    -1,    33,    -1,    34,    -1,
      36,    -1,    35,    -1,    77,    -1,    79,    -1,    80,    -1,
      81,    -1,    85,    -1,    82,    -1,    83,    -1,    87,    -1,
      88,    -1,    89,    -1,    90,    -1,    86,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  JSONresultsParser::yyprhs_[] =
  {
         0,     0,     3,     4,    11,    17,    20,    21,    23,    27,
      30,    36,    37,    45,    48,    49,    52,    58,    65,    68,
      69,    72,    73,    79,    82,    83,    86,    92,    95,    98,
     101,   104,   105,   110,   111,   116,   117,   122,   126,   130,
     134,   137,   138,   140,   144,   147,   151,   155,   159,   162,
     167,   172,   174,   176,   179,   183,   188,   193,   198,   203,
     207,   211,   215,   217,   219,   221,   223,   225,   227,   229,
     231,   233,   235,   237,   239,   241,   243,   246,   248,   250,
     252,   254,   256,   258,   260,   262,   264,   266,   268,   270,
     272,   274,   276,   278,   280,   282,   284,   286,   288,   290,
     292,   294,   296
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  JSONresultsParser::yyrline_[] =
  {
         0,   228,   228,   228,   240,   244,   247,   249,   253,   254,
     258,   265,   265,   272,   278,   280,   284,   288,   292,   295,
     297,   301,   301,   309,   312,   314,   318,   325,   328,   331,
     334,   337,   337,   343,   343,   349,   349,   358,   365,   372,
     378,   384,   387,   391,   396,   404,   410,   414,   421,   424,
     429,   438,   442,   446,   451,   458,   462,   469,   474,   482,
     488,   495,   501,   502,   506,   507,   511,   512,   516,   517,
     521,   522,   526,   527,   531,   532,   536,   540,   541,   545,
     546,   550,   551,   555,   556,   560,   561,   565,   566,   570,
     571,   572,   575,   578,   581,   584,   587,   590,   593,   596,
     599,   602,   605
  };

  // Print the state stack on the debug stream.
  void
  JSONresultsParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  JSONresultsParser::yy_reduce_print_ (int yyrule)
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
  JSONresultsParser::token_number_type
  JSONresultsParser::yytranslate_ (int t)
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
      35,    36
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int JSONresultsParser::yyeof_ = 0;
  const int JSONresultsParser::yylast_ = 215;
  const int JSONresultsParser::yynnts_ = 55;
  const int JSONresultsParser::yyempty_ = -2;
  const int JSONresultsParser::yyfinal_ = 4;
  const int JSONresultsParser::yyterror_ = 1;
  const int JSONresultsParser::yyerrcode_ = 256;
  const int JSONresultsParser::yyntokens_ = 37;

  const unsigned int JSONresultsParser::yyuser_token_number_max_ = 291;
  const JSONresultsParser::token_number_type JSONresultsParser::yyundef_token_ = 2;


} // w3c_sw

/* Line 1136 of lalr1.cc  */
#line 1675 "lib/JSONresultsParser/JSONresultsParser.cpp"


/* Line 1138 of lalr1.cc  */
#line 612 "lib/JSONresultsParser/JSONresultsParser.ypp"
 /*** Additional Code ***/

void w3c_sw::JSONresultsParser::error(const JSONresultsParser::location_type& l,
				    const std::string& constM)
{
    std::string m = constM;
    static struct { const char* from; const char* to; } tokens[] = {
	{ "GT_LPAREN",		"'('" },
	{ "GT_RPAREN",		"')'" },
	{ "GT_TIMES",		"'*'" },
	{ "GT_LCURLEY",		"'{'" },
	{ "GT_RCURLEY",		"'}'" },
	{ "GT_SEMI",		"';'" },
	{ "GT_DOT",		"'.'" },
	{ "GT_COMMA",		"','" },
	{ "GT_LBRACKET",	"'['" },
	{ "GT_RBRACKET",	"']'" },
	{ "GT_OR",		"'||'" },
	{ "GT_AND",		"'&&'" },
	{ "GT_EQUAL",		"'='" },
	{ "GT_NEQUAL",		"'!='" },
	{ "GT_LT",		"'<'" },
	{ "GT_GT",		"'>'" },
	{ "GT_LE",		"'<='" },
	{ "GT_GE",		"'>='" },
	{ "GT_DIVIDE",		"'/'" },
	{ "GT_PLUS",		"'+'" },
	{ "GT_MINUS",		"'-'" },
	{ "GT_NOT",		"'!'" },
	{ "GT_DTYPE",		"'^^'" },
	{ "GT_", "" }
    };
    for (size_t i = 0; i < sizeof(tokens)/sizeof(tokens[0]); ++i) {
	size_t p = m.find(tokens[i].from);
	if (p != std::string::npos) {
	    m.replace(p, strlen(tokens[i].from) + 1, tokens[i].to);
	    break;
	}
    }
    driver.error(l, m);
}

/* START Driver (@@ stand-alone would allow it to be shared with other parsers */

namespace w3c_sw {

    JSONresultsDriver::JSONresultsDriver (AtomFactory* atomFactory) : 
	YaccDriver("", atomFactory), 
	curResultSet(NULL), curResult(NULL), curValue(NULL), 
	curDatatype(NULL), curLang(NULL), root(NULL)
{
}

    JSONresultsDriver::~JSONresultsDriver ()
{
}

const ResultSet* JSONresultsDriver::parse (IStreamContext& in, ResultSet* rs)
{
    root = curResultSet = rs;
    curResult = NULL;
    curValue = NULL;
    curDatatype = NULL;
    curLang = NULL;
    streamname = in.nameStr;

    JSONresultsScanner scanner(this, in.p);
    scanner.set_debug(trace_scanning);
    lexer = &scanner;

    JSONresultsParser parser(*this);
    parser.set_debug_level(trace_parsing);
    // !!! Clear out namespaces!
    ignorePrefixFlag = false;
    parser.parse();
    return root;
}

const ResultSet* JSONresultsDriver::parse (std::string queryStr, ResultSet* rs)
{
    IStreamContext in(queryStr.c_str(), IStreamContext::STRING);
    return parse(in, rs);
}


} // namespace w3c_sw

/* END Driver */


