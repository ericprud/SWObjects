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
#line 216 "lib/JSONresultsParser/JSONresultsParser.ypp"

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
    driver.yylloc = &yylloc;
}

/* Line 565 of lalr1.cc  */
#line 347 "lib/JSONresultsParser/JSONresultsParser.cpp"

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
#line 230 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	if (driver.root == NULL)
	    driver.startBindingSet();
	else
	    driver.curResultSet = driver.root;
      }
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 235 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	  driver.root = driver.endBindingSet();
	  driver.curResultSet = NULL;
      }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 265 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	// throw away link $4
	delete (yysemantic_stack_[(5) - (4)].p_str);
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 272 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	driver.addBindingVar(driver.getVariable(*(yysemantic_stack_[(4) - (4)].p_str)));
	delete (yysemantic_stack_[(4) - (4)].p_str);
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 279 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	driver.addBindingVar(driver.getVariable(*(yysemantic_stack_[(2) - (2)].p_str)));
	delete (yysemantic_stack_[(2) - (2)].p_str);
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 292 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      driver.curResultSet->resultType = ResultSet::RESULT_Boolean;
      if ((yysemantic_stack_[(3) - (3)].p_bool) == true)
	  driver.curResultSet->clear();
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 300 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_bool) = true;
	//	delete $1;
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 304 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_bool) = false;
	//	delete $1;
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 324 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	driver.startBindingRow(false);
      }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 326 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 341 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	driver.addBinding(driver.getVariable(*(yysemantic_stack_[(5) - (1)].p_str)), (yysemantic_stack_[(5) - (4)].p_TTerm));
	delete (yysemantic_stack_[(5) - (1)].p_str);
    }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 348 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 351 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(2) - (2)].p_BNode);
    }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 354 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(2) - (2)].p_literal);
    }
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 357 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(2) - (2)].p_literal);
    }
    break;

  case 36:

/* Line 690 of lalr1.cc  */
#line 360 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	driver.curValue = (yysemantic_stack_[(1) - (1)].p_str);
      }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 362 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	  driver.curValue = NULL;
	  (yyval.p_TTerm) = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 366 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	driver.curDatatype = (yysemantic_stack_[(1) - (1)].p_URI);
      }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 368 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	  driver.curDatatype = NULL;
	  (yyval.p_TTerm) = (yysemantic_stack_[(4) - (4)].p_literal);
      }
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 372 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	driver.curLang = (yysemantic_stack_[(1) - (1)].p_str);
      }
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 374 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	  driver.curLang = NULL;
	  (yyval.p_TTerm) = (yysemantic_stack_[(4) - (4)].p_literal);
      }
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 381 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_URI) = driver.getURI(*(yysemantic_stack_[(3) - (3)].p_str));
	delete (yysemantic_stack_[(3) - (3)].p_str);
    }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 388 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_BNode) = driver.getBNode(*(yysemantic_stack_[(3) - (3)].p_str));
	delete (yysemantic_stack_[(3) - (3)].p_str);
    }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 395 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_literal) = (yysemantic_stack_[(3) - (3)].p_literal);
    }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 401 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_str) = (yysemantic_stack_[(2) - (2)].p_str);
    }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 407 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_str) = NULL;
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 414 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_literal) = driver.getRDFLiteral(*(yysemantic_stack_[(3) - (3)].p_str), NULL, (yysemantic_stack_[(3) - (1)].p_str) ? new LANGTAG(*(yysemantic_stack_[(3) - (1)].p_str)) : NULL);
	delete (yysemantic_stack_[(3) - (3)].p_str);
	delete (yysemantic_stack_[(3) - (1)].p_str);
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 419 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_literal) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_str), NULL, (yysemantic_stack_[(2) - (2)].p_str) ? new LANGTAG(*(yysemantic_stack_[(2) - (2)].p_str)) : NULL);
	delete (yysemantic_stack_[(2) - (1)].p_str);
	delete (yysemantic_stack_[(2) - (2)].p_str);
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 427 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_literal) = (yysemantic_stack_[(3) - (3)].p_literal);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 433 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_literal) = driver.getRDFLiteral(*(yysemantic_stack_[(3) - (3)].p_str), (yysemantic_stack_[(3) - (1)].p_URI), NULL);
	delete (yysemantic_stack_[(3) - (3)].p_str);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 437 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_literal) = driver.getRDFLiteral(*(yysemantic_stack_[(3) - (1)].p_str), (yysemantic_stack_[(3) - (3)].p_URI), NULL);
	delete (yysemantic_stack_[(3) - (1)].p_str);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 444 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(2) - (2)].p_TTerm);
    }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 447 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_TTerm) = driver.getRDFLiteral(*driver.curValue, (yysemantic_stack_[(4) - (1)].p_URI), NULL);
      delete driver.curValue;
      driver.curDatatype = NULL;
    }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 452 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_TTerm) = driver.getRDFLiteral(*driver.curValue, NULL, (yysemantic_stack_[(4) - (1)].p_str) ? new LANGTAG(*(yysemantic_stack_[(4) - (1)].p_str)) : NULL);
      delete driver.curValue;
      delete (yysemantic_stack_[(4) - (1)].p_str);
      driver.curLang = NULL;
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 461 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI(*driver.curValue);
	delete driver.curValue;
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 465 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_TTerm) = driver.getBNode(*driver.curValue);
	delete driver.curValue;
    }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 469 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_TTerm) = driver.getRDFLiteral(*driver.curValue, NULL, (yysemantic_stack_[(2) - (2)].p_str) ? new LANGTAG(*(yysemantic_stack_[(2) - (2)].p_str)) : NULL);
	delete driver.curValue;
	delete (yysemantic_stack_[(2) - (2)].p_str);
    }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 474 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_TTerm) = driver.getRDFLiteral(*driver.curValue, (yysemantic_stack_[(3) - (3)].p_URI), NULL);
	delete driver.curValue;
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 481 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_literal) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_str), driver.curDatatype, NULL);
	delete (yysemantic_stack_[(4) - (4)].p_str);
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 485 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_literal) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (1)].p_str), driver.curDatatype, NULL);
	delete (yysemantic_stack_[(4) - (1)].p_str);
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 492 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_literal) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_str), NULL, driver.curLang ? new LANGTAG(*driver.curLang) : NULL);
	delete (yysemantic_stack_[(4) - (4)].p_str);
	delete driver.curLang;
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 497 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_literal) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (1)].p_str), NULL, driver.curLang ? new LANGTAG(*driver.curLang) : NULL);
	delete (yysemantic_stack_[(4) - (1)].p_str);
	delete driver.curLang;
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 505 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_str) = (yysemantic_stack_[(3) - (3)].p_str);
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 511 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_URI) = driver.getURI(*(yysemantic_stack_[(3) - (3)].p_str));
	delete (yysemantic_stack_[(3) - (3)].p_str);
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 518 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_str) = (yysemantic_stack_[(3) - (3)].p_str);
    }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 608 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_str) = new std::string("head");
    }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 611 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("vars");
    }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 614 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("results");
    }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 617 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("boolean");
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 620 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("true");
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 623 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("false");
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 626 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("bindings");
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 629 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("type");
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 632 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("uri");
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 635 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("bnode");
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 638 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("literal");
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 641 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("typedLiteral");
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 644 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("datatype");
    }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 647 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("lang");
    }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 650 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("value");
    }
    break;



/* Line 690 of lalr1.cc  */
#line 1046 "lib/JSONresultsParser/JSONresultsParser.cpp"
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
  const short int JSONresultsParser::yypact_ninf_ = -133;
  const short int
  JSONresultsParser::yypact_[] =
  {
        25,  -133,    32,     2,  -133,  -133,  -133,    34,    30,    38,
      41,  -133,  -133,  -133,  -133,    52,    55,    57,    98,  -133,
      64,    65,  -133,  -133,  -133,  -133,  -133,    69,    72,    81,
      63,    92,   153,  -133,  -133,  -133,  -133,  -133,  -133,   106,
     165,  -133,  -133,    93,    99,  -133,  -133,   110,   107,  -133,
    -133,   108,   108,  -133,   146,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,   148,  -133,
     158,  -133,  -133,  -133,  -133,     9,   108,    23,   108,  -133,
    -133,  -133,   178,   158,  -133,  -133,  -133,   174,   190,  -133,
     108,  -133,  -133,    67,  -133,   189,  -133,  -133,  -133,   126,
     191,   192,   193,   194,  -133,   197,   198,   199,  -133,  -133,
    -133,  -133,   200,   201,   202,   203,  -133,   108,   108,   108,
     127,   141,   141,   151,   151,    -4,   137,  -133,  -133,  -133,
    -133,   204,   205,   126,  -133,   206,   149,  -133,   207,   154,
    -133,  -133,  -133,   208,   209,  -133,   210,   211,   160,   160,
    -133,  -133,  -133,   208,   212,   160,   213,   160,   214,   152,
    -133,  -133,   151,   156,   151,   149,   154,  -133,   156,   149,
     151,   154,   151,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,  -133
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  JSONresultsParser::yydefact_[] =
  {
         0,     2,     0,     0,     1,    67,    68,     0,     0,     0,
       0,    73,    75,    76,    74,     0,     0,     0,    10,     3,
       0,     0,    69,    70,    71,    72,    11,     0,     0,     6,
       0,     0,     0,    78,    77,    19,    20,    21,     4,     0,
       0,     7,     9,     0,     0,    79,    80,     0,     0,     8,
       5,     0,     0,    18,     0,    81,    82,    83,    84,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    99,    98,   100,   101,   102,   103,   104,   105,   106,
     108,   109,   107,   114,   110,   111,   112,   113,     0,    13,
       0,    12,    16,    26,    24,     0,     0,     0,     0,    14,
      17,    29,     0,     0,    22,    25,    15,     0,     0,    23,
       0,    27,    30,     0,    28,     0,    36,    38,    40,     0,
       0,     0,     0,     0,    31,     0,     0,     0,    32,    33,
      34,    35,     0,     0,     0,     0,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    64,    65,    66,
      37,     0,     0,     0,    39,     0,     0,    41,     0,     0,
      42,    43,    44,    46,     0,    50,     0,     0,     0,     0,
      53,    56,    57,    46,     0,     0,     0,     0,     0,     0,
      47,    49,     0,     0,     0,     0,     0,    58,     0,     0,
       0,     0,     0,    45,    48,    52,    51,    54,    55,    59,
      61,    60,    63,    62
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  JSONresultsParser::yypgoto_[] =
  {
      -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,   155,   157,
    -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,   116,  -133,
    -133,  -133,   111,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,    47,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -122,
    -132,  -130,   219,  -133,    -9,   215,   216,   217,   218,   195,
    -112,  -101,   -61,   -76,   -51,  -113,  -114,  -111,   -97,   -48
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  JSONresultsParser::yydefgoto_[] =
  {
        -1,     2,     3,     7,    41,    42,    26,    27,    28,    29,
      92,   100,    95,    15,    35,    47,   105,    97,    94,    96,
     112,   107,   101,   115,   125,   126,   127,   128,   129,   130,
     180,   181,   162,   131,   165,   150,   170,   154,   157,   116,
     117,   118,    73,    30,    74,    75,    76,    77,    78,    79,
      80,    81,   119,    82,   121,    84,    85,    86,    87,   102
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char JSONresultsParser::yytable_ninf_ = -1;
  const unsigned char
  JSONresultsParser::yytable_[] =
  {
        83,    83,   122,    88,    89,   135,   134,   132,   151,    31,
     152,     5,     6,    98,   167,   164,   123,    99,   133,   155,
     158,   160,   161,   163,   166,    61,    62,   103,     1,   122,
      31,   104,     4,    69,    70,   122,    10,   120,     9,   174,
     173,   171,   176,   123,    18,    83,   178,    83,   123,   193,
     106,   195,   172,    11,    12,    13,   199,    19,    14,    83,
     194,    20,   196,    21,   120,   120,   120,    32,   201,    43,
     203,   197,   122,   198,    38,   200,    39,   122,   202,   153,
     156,   159,   123,    33,    34,    40,    83,    83,    83,   147,
     148,   149,   120,   120,    59,    60,    61,    62,    44,   120,
      51,   120,    67,    68,    69,    70,    52,   185,   186,    22,
      23,    24,    25,    54,   189,    53,   191,     5,     6,    24,
      25,    24,    25,    11,    12,    13,    33,    34,    14,    45,
      46,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    55,
      56,    57,    58,    90,    59,    60,    91,    63,    64,    65,
      66,    93,    67,    68,    69,    70,    61,    62,    59,    60,
      61,    62,    67,    68,    45,    46,    22,    23,   110,   111,
      61,    62,    65,    66,   108,    63,    64,    59,    60,    69,
      70,    67,    68,   113,   124,    50,    49,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   168,   169,
     175,   177,   179,   182,   183,   184,   188,   190,   192,   109,
     187,   114,     8,     0,    16,    17,     0,    48,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    36,    37
  };

  /* YYCHECK.  */
  const short int
  JSONresultsParser::yycheck_[] =
  {
        51,    52,   113,    51,    52,   119,   119,   119,   140,    18,
     140,     9,    10,     4,   146,   145,   113,     8,   119,   141,
     142,   143,   144,   145,   146,    29,    30,     4,     3,   140,
      39,     8,     0,    37,    38,   146,     6,   113,     4,   153,
     153,   153,   156,   140,     3,    96,   159,    98,   145,   179,
      98,   183,   153,    15,    16,    17,   188,     5,    20,   110,
     182,     6,   184,     6,   140,   141,   142,     3,   190,     6,
     192,   185,   183,   186,     5,   189,     4,   188,   191,   140,
     141,   142,   179,    18,    19,     4,   137,   138,   139,   137,
     138,   139,   168,   169,    27,    28,    29,    30,     6,   175,
       7,   177,    35,    36,    37,    38,     7,   168,   169,    11,
      12,    13,    14,     6,   175,     5,   177,     9,    10,    13,
      14,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    23,
      24,    25,    26,     7,    27,    28,     8,    31,    32,    33,
      34,     3,    35,    36,    37,    38,    29,    30,    27,    28,
      29,    30,    35,    36,    21,    22,    11,    12,     4,     5,
      29,    30,    33,    34,     6,    31,    32,    27,    28,    37,
      38,    35,    36,     3,     5,    40,    39,     6,     6,     6,
       6,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,   103,
     173,   110,     3,    -1,     9,     9,    -1,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    21
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  JSONresultsParser::yystos_[] =
  {
         0,     3,    42,    43,     0,     9,    10,    44,    83,     4,
       6,    15,    16,    17,    20,    54,    86,    87,     3,     5,
       6,     6,    11,    12,    13,    14,    47,    48,    49,    50,
      84,    85,     3,    18,    19,    55,    88,    89,     5,     4,
       4,    45,    46,     6,     6,    21,    22,    56,    90,    50,
      49,     7,     7,     5,     6,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    83,    85,    86,    87,    88,    89,    90,
      91,    92,    94,    95,    96,    97,    98,    99,   100,   100,
       7,     8,    51,     3,    59,    53,    60,    58,     4,     8,
      52,    63,   100,     4,     8,    57,   100,    62,     6,    59,
       4,     5,    61,     3,    63,    64,    80,    81,    82,    93,
      94,    95,    98,    99,     5,    65,    66,    67,    68,    69,
      70,    74,    91,    92,    96,    97,     6,     6,     6,     6,
       4,     4,     4,     4,     4,     4,     4,   100,   100,   100,
      76,    81,    82,    93,    78,    80,    93,    79,    80,    93,
      80,    80,    73,    80,    82,    75,    80,    81,     4,     4,
      77,    91,    92,    96,    97,     4,    97,     4,    96,     4,
      71,    72,     4,     4,     4,    93,    93,    72,     4,    93,
       4,    93,     4,    82,    80,    81,    80,    97,    96,    81,
      97,    80,    96,    80
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  JSONresultsParser::yyr1_[] =
  {
         0,    41,    43,    42,    44,    45,    46,    46,    47,    47,
      48,    48,    49,    51,    50,    52,    53,    53,    54,    54,
      55,    55,    56,    57,    58,    58,    60,    59,    61,    62,
      62,    63,    64,    64,    64,    64,    65,    64,    66,    64,
      67,    64,    68,    69,    70,    71,    72,    72,    73,    73,
      74,    75,    75,    76,    76,    76,    77,    77,    77,    77,
      78,    78,    79,    79,    80,    81,    82,    83,    83,    84,
      84,    85,    85,    86,    86,    87,    87,    88,    89,    90,
      90,    91,    91,    92,    92,    93,    94,    94,    95,    95,
      96,    96,    97,    97,    98,    98,    99,    99,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  JSONresultsParser::yyr2_[] =
  {
         0,     2,     0,     6,     5,     2,     0,     1,     3,     2,
       0,     1,     5,     0,     7,     2,     0,     2,     5,     3,
       1,     1,     6,     2,     0,     2,     0,     5,     2,     0,
       2,     5,     2,     2,     2,     2,     0,     4,     0,     4,
       0,     4,     3,     3,     3,     2,     0,     1,     3,     2,
       3,     3,     3,     2,     4,     4,     1,     1,     2,     3,
       4,     4,     4,     4,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
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
  "GT_H_22__results_H_22_", "GT_H_22__boolean_H_22_",
  "GT_H_27__boolean_H_27_", "IT_false", "IT_true",
  "GT_H_27__results_H_27_", "GT_H_22__bindings_H_22_",
  "GT_H_27__bindings_H_27_", "GT_H_22__uri_H_22_", "GT_H_27__uri_H_27_",
  "GT_H_22__bnode_H_22_", "GT_H_27__bnode_H_27_", "GT_H_22__type_H_22_",
  "GT_H_27__type_H_27_", "GT_H_22__value_H_22_", "GT_H_27__value_H_27_",
  "GT_H_22__literal_H_22_", "GT_H_27__literal_H_27_",
  "GT_H_22__typed_MINUS_literal_H_22_",
  "GT_H_27__typed_MINUS_literal_H_27_", "GT_H_22__datatype_H_22_",
  "GT_H_27__datatype_H_27_", "GT_H_22__xml_COLON_lang_H_22_",
  "GT_H_27__xml_COLON_lang_H_27_", "STRING_LITERAL2", "STRING_LITERAL1",
  "$accept", "Top", "$@1", "head", "_O_QGT_COMMA_E_S_Q_link_E_C",
  "_Q_O_QGT_COMMA_E_S_Q_link_E_C_E_Opt",
  "_O_Q_link_E_S_QGT_COMMA_E_S_Qvars_E_Or_Qvars_E_S_QGT_COMMA_E_S_Q_link_E_Opt_C",
  "_Q_O_Q_link_E_S_QGT_COMMA_E_S_Qvars_E_Or_Qvars_E_S_QGT_COMMA_E_S_Q_link_E_Opt_C_E_Opt",
  "_link", "vars", "$@2", "_O_QGT_COMMA_E_S_Qword_E_C",
  "_Q_O_QGT_COMMA_E_S_Qword_E_C_E_Star", "results",
  "_O_QtrueWord_E_Or_QfalseWord_E_C", "bindings",
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
  "booleanWord", "trueWord", "falseWord", "bindingsWord", "uriWord",
  "bnodeWord", "typeKey", "typeWord", "valueWord", "literalWord",
  "typedLiteralWord", "datatypeWord", "langWord", "word", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const JSONresultsParser::rhs_number_type
  JSONresultsParser::yyrhs_[] =
  {
        42,     0,    -1,    -1,     3,    43,    44,     4,    54,     5,
      -1,    83,     6,     3,    48,     5,    -1,     4,    49,    -1,
      -1,    45,    -1,    49,     4,    50,    -1,    50,    46,    -1,
      -1,    47,    -1,    84,     6,     7,   100,     8,    -1,    -1,
      85,     6,     7,   100,    51,    53,     8,    -1,     4,   100,
      -1,    -1,    53,    52,    -1,    86,     6,     3,    56,     5,
      -1,    87,     6,    55,    -1,    88,    -1,    89,    -1,    90,
       6,     7,    59,    58,     8,    -1,     4,    59,    -1,    -1,
      58,    57,    -1,    -1,     3,    60,    63,    62,     5,    -1,
       4,    63,    -1,    -1,    62,    61,    -1,   100,     6,     3,
      64,     5,    -1,    93,    68,    -1,    93,    69,    -1,    93,
      70,    -1,    93,    74,    -1,    -1,    80,    65,     4,    76,
      -1,    -1,    81,    66,     4,    78,    -1,    -1,    82,    67,
       4,    79,    -1,    91,     4,    80,    -1,    92,     4,    80,
      -1,    96,     4,    73,    -1,     4,    82,    -1,    -1,    71,
      -1,    82,     4,    80,    -1,    80,    72,    -1,    97,     4,
      75,    -1,    81,     4,    80,    -1,    80,     4,    81,    -1,
      93,    77,    -1,    81,     4,    93,    97,    -1,    82,     4,
      93,    96,    -1,    91,    -1,    92,    -1,    96,    72,    -1,
      97,     4,    81,    -1,    93,    97,     4,    80,    -1,    80,
       4,    93,    97,    -1,    93,    96,     4,    80,    -1,    80,
       4,    93,    96,    -1,    95,     6,   100,    -1,    98,     6,
     100,    -1,    99,     6,   100,    -1,     9,    -1,    10,    -1,
      11,    -1,    12,    -1,    13,    -1,    14,    -1,    15,    -1,
      20,    -1,    16,    -1,    17,    -1,    19,    -1,    18,    -1,
      21,    -1,    22,    -1,    23,    -1,    24,    -1,    25,    -1,
      26,    -1,    94,     6,    -1,    27,    -1,    28,    -1,    29,
      -1,    30,    -1,    31,    -1,    32,    -1,    33,    -1,    34,
      -1,    35,    -1,    36,    -1,    37,    -1,    38,    -1,    40,
      -1,    39,    -1,    83,    -1,    85,    -1,    86,    -1,    87,
      -1,    88,    -1,    89,    -1,    90,    -1,    94,    -1,    91,
      -1,    92,    -1,    96,    -1,    97,    -1,    98,    -1,    99,
      -1,    95,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  JSONresultsParser::yyprhs_[] =
  {
         0,     0,     3,     4,    11,    17,    20,    21,    23,    27,
      30,    31,    33,    39,    40,    48,    51,    52,    55,    61,
      65,    67,    69,    76,    79,    80,    83,    84,    90,    93,
      94,    97,   103,   106,   109,   112,   115,   116,   121,   122,
     127,   128,   133,   137,   141,   145,   148,   149,   151,   155,
     158,   162,   166,   170,   173,   178,   183,   185,   187,   190,
     194,   199,   204,   209,   214,   218,   222,   226,   228,   230,
     232,   234,   236,   238,   240,   242,   244,   246,   248,   250,
     252,   254,   256,   258,   260,   262,   265,   267,   269,   271,
     273,   275,   277,   279,   281,   283,   285,   287,   289,   291,
     293,   295,   297,   299,   301,   303,   305,   307,   309,   311,
     313,   315,   317,   319,   321
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  JSONresultsParser::yyrline_[] =
  {
         0,   230,   230,   230,   242,   246,   249,   251,   255,   256,
     259,   261,   265,   272,   272,   279,   285,   287,   291,   292,
     300,   304,   311,   315,   318,   320,   324,   324,   332,   335,
     337,   341,   348,   351,   354,   357,   360,   360,   366,   366,
     372,   372,   381,   388,   395,   401,   407,   410,   414,   419,
     427,   433,   437,   444,   447,   452,   461,   465,   469,   474,
     481,   485,   492,   497,   505,   511,   518,   524,   525,   529,
     530,   534,   535,   539,   540,   544,   545,   549,   553,   557,
     558,   562,   563,   567,   568,   572,   576,   577,   581,   582,
     586,   587,   591,   592,   596,   597,   601,   602,   606,   607,
     608,   611,   614,   617,   620,   623,   626,   629,   632,   635,
     638,   641,   644,   647,   650
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
      35,    36,    37,    38,    39,    40
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int JSONresultsParser::yyeof_ = 0;
  const int JSONresultsParser::yylast_ = 239;
  const int JSONresultsParser::yynnts_ = 60;
  const int JSONresultsParser::yyempty_ = -2;
  const int JSONresultsParser::yyfinal_ = 4;
  const int JSONresultsParser::yyterror_ = 1;
  const int JSONresultsParser::yyerrcode_ = 256;
  const int JSONresultsParser::yyntokens_ = 41;

  const unsigned int JSONresultsParser::yyuser_token_number_max_ = 295;
  const JSONresultsParser::token_number_type JSONresultsParser::yyundef_token_ = 2;


} // w3c_sw

/* Line 1136 of lalr1.cc  */
#line 1753 "lib/JSONresultsParser/JSONresultsParser.cpp"


/* Line 1138 of lalr1.cc  */
#line 657 "lib/JSONresultsParser/JSONresultsParser.ypp"
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


