
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
#line 43 "lib/JSONresultsParser/JSONresultsParser.cpp"


#include "JSONresultsParser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 182 "lib/JSONresultsParser/JSONresultsParser.ypp"

#include "../JSONresultsScanner.hpp"

/* Line 317 of lalr1.cc  */
#line 214 "lib/JSONresultsParser/JSONresultsParser.ypp"

#include "../JSONresultsScanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lexWrapper


/* Line 317 of lalr1.cc  */
#line 68 "lib/JSONresultsParser/JSONresultsParser.cpp"

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
#line 137 "lib/JSONresultsParser/JSONresultsParser.cpp"
#if YYERROR_VERBOSE

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

#endif

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
    location_type yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
/* Line 553 of lalr1.cc  */
#line 43 "lib/JSONresultsParser/JSONresultsParser.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 553 of lalr1.cc  */
#line 321 "lib/JSONresultsParser/JSONresultsParser.cpp"

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
#line 228 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	if (driver.root == NULL)
	    driver.startBindingSet();
	else
	    driver.curResultSet = driver.root;
      }
    break;

  case 3:

/* Line 678 of lalr1.cc  */
#line 233 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	  driver.root = driver.endBindingSet();
	  driver.curResultSet = NULL;
      }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 258 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	// throw away link $4
	delete (yysemantic_stack_[(5) - (4)].p_str);
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 269 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	driver.addBindingVar(driver.getVariable(*(yysemantic_stack_[(2) - (2)].p_str)));
	delete (yysemantic_stack_[(2) - (2)].p_str);
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 298 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	driver.startBindingRow(false);
      }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 300 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 315 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	driver.addBinding(driver.getVariable(*(yysemantic_stack_[(5) - (1)].p_str)), (yysemantic_stack_[(5) - (4)].p_TTerm));
	delete (yysemantic_stack_[(5) - (1)].p_str);
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 322 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 325 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(2) - (2)].p_BNode);
    }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 328 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(2) - (2)].p_literal);
    }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 331 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(2) - (2)].p_literal);
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 334 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	driver.curValue = (yysemantic_stack_[(1) - (1)].p_str);
      }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 336 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	  driver.curValue = NULL;
	  (yyval.p_TTerm) = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 340 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	driver.curDatatype = (yysemantic_stack_[(1) - (1)].p_URI);
      }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 342 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	  driver.curDatatype = NULL;
	  (yyval.p_TTerm) = (yysemantic_stack_[(4) - (4)].p_literal);
      }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 346 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	driver.curLang = (yysemantic_stack_[(1) - (1)].p_str);
      }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 348 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	  driver.curLang = NULL;
	  (yyval.p_TTerm) = (yysemantic_stack_[(4) - (4)].p_literal);
      }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 355 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_URI) = driver.getURI(*(yysemantic_stack_[(3) - (3)].p_str));
	delete (yysemantic_stack_[(3) - (3)].p_str);
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 362 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_BNode) = driver.getBNode(*(yysemantic_stack_[(3) - (3)].p_str));
	delete (yysemantic_stack_[(3) - (3)].p_str);
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 369 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_literal) = (yysemantic_stack_[(3) - (3)].p_literal);
    }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 375 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_str) = (yysemantic_stack_[(2) - (2)].p_str);
    }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 381 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_str) = NULL;
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 388 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_literal) = driver.getRDFLiteral(*(yysemantic_stack_[(3) - (3)].p_str), NULL, (yysemantic_stack_[(3) - (1)].p_str) ? new LANGTAG(*(yysemantic_stack_[(3) - (1)].p_str)) : NULL);
	delete (yysemantic_stack_[(3) - (3)].p_str);
	delete (yysemantic_stack_[(3) - (1)].p_str);
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 393 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_literal) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_str), NULL, (yysemantic_stack_[(2) - (2)].p_str) ? new LANGTAG(*(yysemantic_stack_[(2) - (2)].p_str)) : NULL);
	delete (yysemantic_stack_[(2) - (1)].p_str);
	delete (yysemantic_stack_[(2) - (2)].p_str);
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 401 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_literal) = (yysemantic_stack_[(3) - (3)].p_literal);
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 407 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_literal) = driver.getRDFLiteral(*(yysemantic_stack_[(3) - (3)].p_str), (yysemantic_stack_[(3) - (1)].p_URI), NULL);
	delete (yysemantic_stack_[(3) - (3)].p_str);
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 411 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_literal) = driver.getRDFLiteral(*(yysemantic_stack_[(3) - (1)].p_str), (yysemantic_stack_[(3) - (3)].p_URI), NULL);
	delete (yysemantic_stack_[(3) - (1)].p_str);
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 418 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(2) - (2)].p_TTerm);
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 421 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_TTerm) = driver.getRDFLiteral(*driver.curValue, (yysemantic_stack_[(4) - (1)].p_URI), NULL);
      delete driver.curValue;
      driver.curDatatype = NULL;
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 426 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_TTerm) = driver.getRDFLiteral(*driver.curValue, NULL, (yysemantic_stack_[(4) - (1)].p_str) ? new LANGTAG(*(yysemantic_stack_[(4) - (1)].p_str)) : NULL);
      delete driver.curValue;
      delete (yysemantic_stack_[(4) - (1)].p_str);
      driver.curLang = NULL;
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 435 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI(*driver.curValue);
	delete driver.curValue;
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 439 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_TTerm) = driver.getBNode(*driver.curValue);
	delete driver.curValue;
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 443 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_TTerm) = driver.getRDFLiteral(*driver.curValue, NULL, (yysemantic_stack_[(2) - (2)].p_str) ? new LANGTAG(*(yysemantic_stack_[(2) - (2)].p_str)) : NULL);
	delete driver.curValue;
	delete (yysemantic_stack_[(2) - (2)].p_str);
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 448 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_TTerm) = driver.getRDFLiteral(*driver.curValue, (yysemantic_stack_[(3) - (3)].p_URI), NULL);
	delete driver.curValue;
    }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 455 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_literal) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_str), driver.curDatatype, NULL);
	delete (yysemantic_stack_[(4) - (4)].p_str);
    }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 459 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_literal) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (1)].p_str), driver.curDatatype, NULL);
	delete (yysemantic_stack_[(4) - (1)].p_str);
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 466 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_literal) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_str), NULL, driver.curLang ? new LANGTAG(*driver.curLang) : NULL);
	delete (yysemantic_stack_[(4) - (4)].p_str);
	delete driver.curLang;
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 471 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_literal) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (1)].p_str), NULL, driver.curLang ? new LANGTAG(*driver.curLang) : NULL);
	delete (yysemantic_stack_[(4) - (1)].p_str);
	delete driver.curLang;
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 479 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_str) = (yysemantic_stack_[(3) - (3)].p_str);
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 485 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_URI) = driver.getURI(*(yysemantic_stack_[(3) - (3)].p_str));
	delete (yysemantic_stack_[(3) - (3)].p_str);
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 492 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_str) = (yysemantic_stack_[(3) - (3)].p_str);
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 569 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
	(yyval.p_str) = new std::string("head");
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 572 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("vars");
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 575 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("results");
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 578 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("bindings");
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 581 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("type");
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 584 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("uri");
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 587 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("bnode");
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 590 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("literal");
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 593 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("typedLiteral");
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 596 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("datatype");
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 599 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("lang");
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 602 "lib/JSONresultsParser/JSONresultsParser.ypp"
    {
      (yyval.p_str) = new std::string("value");
    }
    break;



/* Line 678 of lalr1.cc  */
#line 952 "lib/JSONresultsParser/JSONresultsParser.cpp"
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
  JSONresultsParser::yysyntax_error_ (int yystate, int tok)
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
  const signed char JSONresultsParser::yypact_ninf_ = -119;
  const short int
  JSONresultsParser::yypact_[] =
  {
         7,  -119,    13,    52,  -119,  -119,  -119,    24,    20,    74,
      27,  -119,  -119,    54,    51,    97,  -119,    64,  -119,  -119,
    -119,  -119,    66,    65,    72,    68,    91,   101,  -119,   152,
     156,  -119,  -119,    92,    98,  -119,  -119,   109,   106,  -119,
    -119,   107,   107,  -119,   141,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,   143,  -119,   153,  -119,    23,
    -119,  -119,   107,  -119,  -119,   107,    34,  -119,  -119,   173,
     153,  -119,  -119,   165,   181,  -119,   107,  -119,  -119,    70,
    -119,   180,  -119,  -119,  -119,   125,   182,   183,   184,   185,
    -119,   188,   189,   190,  -119,  -119,  -119,  -119,   191,   192,
     193,   194,  -119,   107,   107,   107,   126,   138,   138,   146,
     146,    -1,    22,  -119,  -119,  -119,  -119,   195,   196,   125,
    -119,   197,   144,  -119,   198,   148,  -119,  -119,  -119,   199,
     200,  -119,   201,   202,   154,   154,  -119,  -119,  -119,   199,
     203,   154,   204,   154,   205,   147,  -119,  -119,   146,   151,
     146,   144,   148,  -119,   151,   144,   146,   148,   146,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  JSONresultsParser::yydefact_[] =
  {
         0,     2,     0,     0,     1,    61,    62,     0,     0,     0,
       0,    67,    68,     0,     0,     0,     3,     0,    63,    64,
      65,    66,     0,     0,     6,     0,     0,     0,     4,     0,
       0,     7,     9,     0,     0,    69,    70,     0,     0,     8,
       5,     0,     0,    15,     0,    71,    72,    73,    74,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    89,    88,    90,    91,    92,    93,    95,    96,    94,
     101,    97,    98,    99,   100,     0,    13,     0,    10,     0,
      20,    18,     0,    11,    14,     0,     0,    12,    23,     0,
       0,    16,    19,     0,     0,    17,     0,    21,    24,     0,
      22,     0,    30,    32,    34,     0,     0,     0,     0,     0,
      25,     0,     0,     0,    26,    27,    28,    29,     0,     0,
       0,     0,    75,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    58,    59,    60,    31,     0,     0,     0,
      33,     0,     0,    35,     0,     0,    36,    37,    38,    40,
       0,    44,     0,     0,     0,     0,    47,    50,    51,    40,
       0,     0,     0,     0,     0,     0,    41,    43,     0,     0,
       0,     0,     0,    52,     0,     0,     0,     0,     0,    39,
      42,    46,    45,    48,    49,    53,    55,    54,    57,    56
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  JSONresultsParser::yypgoto_[] =
  {
      -119,  -119,  -119,  -119,  -119,  -119,  -119,   157,   186,  -119,
    -119,  -119,  -119,  -119,  -119,    96,  -119,  -119,  -119,   114,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,    53,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -110,  -118,  -115,   208,
    -119,    -6,   207,   187,   -99,   -93,   -48,   -63,   -41,  -102,
     -90,   -97,   -92,   -37
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  JSONresultsParser::yydefgoto_[] =
  {
        -1,     2,     3,     7,    31,    32,    22,    23,    24,    84,
      79,    13,    37,    92,    86,    81,    85,    98,    93,    88,
     101,   111,   112,   113,   114,   115,   116,   166,   167,   148,
     117,   151,   136,   156,   140,   143,   102,   103,   104,    63,
      25,    64,    65,    66,    67,    68,   105,    69,   107,    71,
      72,    73,    74,    89
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char JSONresultsParser::yytable_ninf_ = -1;
  const unsigned char
  JSONresultsParser::yytable_[] =
  {
        70,    70,   108,   120,    75,    76,   118,   109,   137,    26,
       1,   138,   119,     4,   153,   121,   150,   141,   144,   146,
     147,   149,   152,    26,    51,    52,    10,    82,     9,   108,
      15,    83,    59,    60,   109,   108,   106,   159,    90,   109,
     157,    70,    91,   164,    70,    87,   158,    51,    52,   160,
     179,   181,   162,    57,    58,    70,   185,    17,   180,    16,
     182,     5,     6,   106,   106,   106,   187,    27,   189,    29,
     184,    28,   108,   109,    33,   188,    30,   108,   139,   142,
     145,   183,    70,    70,    70,   186,   133,   134,   135,    11,
      12,   106,   106,    49,    50,    51,    52,    34,   106,    41,
     106,    57,    58,    59,    60,    42,   171,   172,    18,    19,
      20,    21,    44,   175,    43,   177,     5,     6,    35,    36,
      20,    21,    11,    12,    35,    36,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    45,    46,    47,    48,    77,    49,
      50,    78,    53,    54,    55,    56,    80,    57,    58,    59,
      60,    49,    50,    51,    52,    20,    21,    18,    19,    96,
      97,    51,    52,    55,    56,    53,    54,    49,    50,    94,
      59,    60,    57,    58,    99,   110,    95,    40,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   154,
     155,   161,   163,   165,   168,   169,   170,   174,   176,   178,
     100,     8,   173,     0,    38,    39,    14
  };

  /* YYCHECK.  */
  const short int
  JSONresultsParser::yycheck_[] =
  {
        41,    42,    99,   105,    41,    42,   105,    99,   126,    15,
       3,   126,   105,     0,   132,   105,   131,   127,   128,   129,
     130,   131,   132,    29,    25,    26,     6,     4,     4,   126,
       3,     8,    33,    34,   126,   132,    99,   139,     4,   131,
     139,    82,     8,   145,    85,    82,   139,    25,    26,   139,
     165,   169,   142,    31,    32,    96,   174,     6,   168,     5,
     170,     9,    10,   126,   127,   128,   176,     3,   178,     4,
     172,     5,   169,   165,     6,   177,     4,   174,   126,   127,
     128,   171,   123,   124,   125,   175,   123,   124,   125,    15,
      16,   154,   155,    23,    24,    25,    26,     6,   161,     7,
     163,    31,    32,    33,    34,     7,   154,   155,    11,    12,
      13,    14,     6,   161,     5,   163,     9,    10,    17,    18,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    19,    20,    21,    22,     7,    23,
      24,     8,    27,    28,    29,    30,     3,    31,    32,    33,
      34,    23,    24,    25,    26,    13,    14,    11,    12,     4,
       5,    25,    26,    29,    30,    27,    28,    23,    24,     6,
      33,    34,    31,    32,     3,     5,    90,    30,     6,     6,
       6,     6,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
      96,     3,   159,    -1,    27,    29,     9
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  JSONresultsParser::yystos_[] =
  {
         0,     3,    38,    39,     0,     9,    10,    40,    76,     4,
       6,    15,    16,    48,    79,     3,     5,     6,    11,    12,
      13,    14,    43,    44,    45,    77,    78,     3,     5,     4,
       4,    41,    42,     6,     6,    17,    18,    49,    80,    45,
      44,     7,     7,     5,     6,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    76,    78,    79,    80,    81,    82,    84,
      85,    86,    87,    88,    89,    90,    90,     7,     8,    47,
       3,    52,     4,     8,    46,    53,    51,    90,    56,    90,
       4,     8,    50,    55,     6,    52,     4,     5,    54,     3,
      56,    57,    73,    74,    75,    83,    84,    85,    88,    89,
       5,    58,    59,    60,    61,    62,    63,    67,    81,    82,
      86,    87,     6,     6,     6,     6,     4,     4,     4,     4,
       4,     4,     4,    90,    90,    90,    69,    74,    75,    83,
      71,    73,    83,    72,    73,    83,    73,    73,    66,    73,
      75,    68,    73,    74,     4,     4,    70,    81,    82,    86,
      87,     4,    87,     4,    86,     4,    64,    65,     4,     4,
       4,    83,    83,    65,     4,    83,     4,    83,     4,    75,
      73,    74,    73,    87,    86,    74,    87,    73,    86,    73
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
      44,    45,    46,    47,    47,    48,    49,    50,    51,    51,
      53,    52,    54,    55,    55,    56,    57,    57,    57,    57,
      58,    57,    59,    57,    60,    57,    61,    62,    63,    64,
      65,    65,    66,    66,    67,    68,    68,    69,    69,    69,
      70,    70,    70,    70,    71,    71,    72,    72,    73,    74,
      75,    76,    76,    77,    77,    78,    78,    79,    79,    80,
      80,    81,    81,    82,    82,    83,    84,    84,    85,    85,
      86,    86,    87,    87,    88,    88,    89,    89,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  JSONresultsParser::yyr2_[] =
  {
         0,     2,     0,     6,     5,     2,     0,     1,     3,     2,
       5,     6,     2,     0,     2,     5,     6,     2,     0,     2,
       0,     5,     2,     0,     2,     5,     2,     2,     2,     2,
       0,     4,     0,     4,     0,     4,     3,     3,     3,     2,
       0,     1,     3,     2,     3,     3,     3,     2,     4,     4,
       1,     1,     2,     3,     4,     4,     4,     4,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
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
  "_link", "vars", "_O_QGT_COMMA_E_S_Qword_E_C",
  "_Q_O_QGT_COMMA_E_S_Qword_E_C_E_Star", "results", "bindings",
  "_O_QGT_COMMA_E_S_Qsolution_E_C",
  "_Q_O_QGT_COMMA_E_S_Qsolution_E_C_E_Star", "solution", "$@2",
  "_O_QGT_COMMA_E_S_Qbinding_E_C",
  "_Q_O_QGT_COMMA_E_S_Qbinding_E_C_E_Star", "binding", "RDFterm", "$@3",
  "$@4", "$@5", "t_uri", "t_bnode", "t_plainLiteral",
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
        38,     0,    -1,    -1,     3,    39,    40,     4,    48,     5,
      -1,    76,     6,     3,    43,     5,    -1,     4,    44,    -1,
      -1,    41,    -1,    44,     4,    45,    -1,    45,    42,    -1,
      77,     6,     7,    90,     8,    -1,    78,     6,     7,    90,
      47,     8,    -1,     4,    90,    -1,    -1,    47,    46,    -1,
      79,     6,     3,    49,     5,    -1,    80,     6,     7,    52,
      51,     8,    -1,     4,    52,    -1,    -1,    51,    50,    -1,
      -1,     3,    53,    56,    55,     5,    -1,     4,    56,    -1,
      -1,    55,    54,    -1,    90,     6,     3,    57,     5,    -1,
      83,    61,    -1,    83,    62,    -1,    83,    63,    -1,    83,
      67,    -1,    -1,    73,    58,     4,    69,    -1,    -1,    74,
      59,     4,    71,    -1,    -1,    75,    60,     4,    72,    -1,
      81,     4,    73,    -1,    82,     4,    73,    -1,    86,     4,
      66,    -1,     4,    75,    -1,    -1,    64,    -1,    75,     4,
      73,    -1,    73,    65,    -1,    87,     4,    68,    -1,    74,
       4,    73,    -1,    73,     4,    74,    -1,    83,    70,    -1,
      74,     4,    83,    87,    -1,    75,     4,    83,    86,    -1,
      81,    -1,    82,    -1,    86,    65,    -1,    87,     4,    74,
      -1,    83,    87,     4,    73,    -1,    73,     4,    83,    87,
      -1,    83,    86,     4,    73,    -1,    73,     4,    83,    86,
      -1,    85,     6,    90,    -1,    88,     6,    90,    -1,    89,
       6,    90,    -1,     9,    -1,    10,    -1,    11,    -1,    12,
      -1,    13,    -1,    14,    -1,    15,    -1,    16,    -1,    17,
      -1,    18,    -1,    19,    -1,    20,    -1,    21,    -1,    22,
      -1,    84,     6,    -1,    23,    -1,    24,    -1,    25,    -1,
      26,    -1,    27,    -1,    28,    -1,    29,    -1,    30,    -1,
      31,    -1,    32,    -1,    33,    -1,    34,    -1,    36,    -1,
      35,    -1,    76,    -1,    78,    -1,    79,    -1,    80,    -1,
      84,    -1,    81,    -1,    82,    -1,    86,    -1,    87,    -1,
      88,    -1,    89,    -1,    85,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  JSONresultsParser::yyprhs_[] =
  {
         0,     0,     3,     4,    11,    17,    20,    21,    23,    27,
      30,    36,    43,    46,    47,    50,    56,    63,    66,    67,
      70,    71,    77,    80,    81,    84,    90,    93,    96,    99,
     102,   103,   108,   109,   114,   115,   120,   124,   128,   132,
     135,   136,   138,   142,   145,   149,   153,   157,   160,   165,
     170,   172,   174,   177,   181,   186,   191,   196,   201,   205,
     209,   213,   215,   217,   219,   221,   223,   225,   227,   229,
     231,   233,   235,   237,   239,   241,   244,   246,   248,   250,
     252,   254,   256,   258,   260,   262,   264,   266,   268,   270,
     272,   274,   276,   278,   280,   282,   284,   286,   288,   290,
     292,   294
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  JSONresultsParser::yyrline_[] =
  {
         0,   228,   228,   228,   240,   244,   247,   249,   253,   254,
     258,   265,   269,   275,   277,   281,   285,   289,   292,   294,
     298,   298,   306,   309,   311,   315,   322,   325,   328,   331,
     334,   334,   340,   340,   346,   346,   355,   362,   369,   375,
     381,   384,   388,   393,   401,   407,   411,   418,   421,   426,
     435,   439,   443,   448,   455,   459,   466,   471,   479,   485,
     492,   498,   499,   503,   504,   508,   509,   513,   514,   518,
     519,   523,   524,   528,   529,   533,   537,   538,   542,   543,
     547,   548,   552,   553,   557,   558,   562,   563,   567,   568,
     569,   572,   575,   578,   581,   584,   587,   590,   593,   596,
     599,   602
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
  const int JSONresultsParser::yylast_ = 216;
  const int JSONresultsParser::yynnts_ = 54;
  const int JSONresultsParser::yyempty_ = -2;
  const int JSONresultsParser::yyfinal_ = 4;
  const int JSONresultsParser::yyterror_ = 1;
  const int JSONresultsParser::yyerrcode_ = 256;
  const int JSONresultsParser::yyntokens_ = 37;

  const unsigned int JSONresultsParser::yyuser_token_number_max_ = 291;
  const JSONresultsParser::token_number_type JSONresultsParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 1571 "lib/JSONresultsParser/JSONresultsParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 609 "lib/JSONresultsParser/JSONresultsParser.ypp"
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


