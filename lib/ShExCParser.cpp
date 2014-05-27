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
#line 41 "lib/ShExCParser.cpp"


#include "ShExCParser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 138 "lib/ShExCParser.ypp"

#include "ShExCScanner.hpp"

/* Line 299 of lalr1.cc  */
#line 187 "lib/ShExCParser.ypp"

#include "ShExCScanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lexWrapper


/* Line 299 of lalr1.cc  */
#line 66 "lib/ShExCParser.cpp"

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
#line 152 "lib/ShExCParser.cpp"

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  SWSexParser::yytnamerr_ (const char *yystr)
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
  SWSexParser::SWSexParser (class SWSexDriver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {
  }

  SWSexParser::~SWSexParser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  SWSexParser::yy_symbol_value_print_ (int yytype,
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
  SWSexParser::yy_symbol_print_ (int yytype,
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
  SWSexParser::yydestruct_ (const char* yymsg,
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
  SWSexParser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  SWSexParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  SWSexParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  SWSexParser::debug_level_type
  SWSexParser::debug_level () const
  {
    return yydebug_;
  }

  void
  SWSexParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  inline bool
  SWSexParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  SWSexParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  SWSexParser::parse ()
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
#line 31 "lib/ShExCParser.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
    driver.yylloc = &yylloc;
}

/* Line 565 of lalr1.cc  */
#line 347 "lib/ShExCParser.cpp"

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
	  case 9:

/* Line 690 of lalr1.cc  */
#line 218 "lib/ShExCParser.ypp"
    {
	driver.curSchema->start = (yysemantic_stack_[(3) - (3)].p_TTerm);
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 224 "lib/ShExCParser.ypp"
    {
	(yyval.p_ruleActions) = NULL;
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 227 "lib/ShExCParser.ypp"
    {
	(yyval.p_ruleActions) = ((yysemantic_stack_[(2) - (1)].p_ruleActions) == NULL)
	    ? new SWSexSchema::RuleActions(driver.curRulePattern)
	    : (yysemantic_stack_[(2) - (1)].p_ruleActions);
	(yyval.p_ruleActions)->codeMap.insert(std::make_pair(*(yysemantic_stack_[(2) - (2)].p_CODE).label, *(yysemantic_stack_[(2) - (2)].p_CODE).text));
	delete (yysemantic_stack_[(2) - (2)].p_CODE).label;
	delete (yysemantic_stack_[(2) - (2)].p_CODE).text;
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 239 "lib/ShExCParser.ypp"
    {
	driver.curRulePattern = (yysemantic_stack_[(1) - (1)].p_rulePattern);
      }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 241 "lib/ShExCParser.ypp"
    {
	  driver.curRulePattern = NULL;
	  (yyval.p_TTerm) = driver.createBNode();
	  driver.curSchema->ruleMap.insert(std::make_pair((yyval.p_TTerm), (yysemantic_stack_[(3) - (3)].p_ruleActions) == NULL ? (yysemantic_stack_[(3) - (1)].p_rulePattern) : (yysemantic_stack_[(3) - (3)].p_ruleActions)));
      }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 249 "lib/ShExCParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 255 "lib/ShExCParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 257 "lib/ShExCParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 259 "lib/ShExCParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 266 "lib/ShExCParser.ypp"
    {
	driver.curRulePattern = (yysemantic_stack_[(2) - (2)].p_rulePattern);
      }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 268 "lib/ShExCParser.ypp"
    {
	  driver.curRulePattern = NULL;
	  driver.curSchema->ruleMap.insert(std::make_pair((yysemantic_stack_[(4) - (1)].p_TTerm), (yysemantic_stack_[(4) - (4)].p_ruleActions) == NULL ? (yysemantic_stack_[(4) - (2)].p_rulePattern) : (yysemantic_stack_[(4) - (4)].p_ruleActions)));
      }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 275 "lib/ShExCParser.ypp"
    {
	(yyval.p_nameClass) = driver.curNameClass;
	driver.curNameClass = NULL;
      }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 278 "lib/ShExCParser.ypp"
    {
	  (yyval.p_rulePattern) = driver.curRulePattern;
	  driver.curRulePattern = NULL;
      }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 281 "lib/ShExCParser.ypp"
    {
	  driver.curRulePattern = (yysemantic_stack_[(5) - (3)].p_rulePattern);
	  driver.curNameClass = (yysemantic_stack_[(5) - (2)].p_nameClass);
	  (yyval.p_rulePattern) = (yysemantic_stack_[(5) - (4)].p_rulePattern);
      }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 289 "lib/ShExCParser.ypp"
    {
	(yyval.p_setRule) = driver.curSetRule;
	driver.curSetRule = NULL;
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 292 "lib/ShExCParser.ypp"
    {
	if (driver.curSetRule == NULL)
	    (yyval.p_rulePattern) = (yysemantic_stack_[(3) - (2)].p_rulePattern);
	else {
	    driver.curSetRule->rules.insert(driver.curSetRule->rules.begin(), (yysemantic_stack_[(3) - (2)].p_rulePattern));
	    (yyval.p_rulePattern) = driver.curSetRule;
	}
	driver.curSetRule = (yysemantic_stack_[(3) - (1)].p_setRule);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 304 "lib/ShExCParser.ypp"
    {
	(yyval.p_rulePattern) = (yysemantic_stack_[(2) - (2)].p_rulePattern);
    }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 311 "lib/ShExCParser.ypp"
    {
	if (driver.curSetRule == NULL)
	    driver.curSetRule = new SWSexSchema::OrRule();
	driver.curSetRule->rules.push_back((yysemantic_stack_[(2) - (2)].p_rulePattern));
    }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 319 "lib/ShExCParser.ypp"
    {
	(yyval.p_setRule) = driver.curSetRule;
	driver.curSetRule = NULL;
    }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 322 "lib/ShExCParser.ypp"
    {
	if (driver.curSetRule == NULL)
	    (yyval.p_rulePattern) = (yysemantic_stack_[(3) - (2)].p_rulePattern);
	else {
	    driver.curSetRule->rules.insert(driver.curSetRule->rules.begin(), (yysemantic_stack_[(3) - (2)].p_rulePattern));
	    (yyval.p_rulePattern) = driver.curSetRule;
	}
	driver.curSetRule = (yysemantic_stack_[(3) - (1)].p_setRule);
    }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 334 "lib/ShExCParser.ypp"
    {
	(yyval.p_rulePattern) = (yysemantic_stack_[(2) - (2)].p_rulePattern);
    }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 341 "lib/ShExCParser.ypp"
    {
	if (driver.curSetRule == NULL)
	    driver.curSetRule = new SWSexSchema::AndRule();
	driver.curSetRule->rules.push_back((yysemantic_stack_[(2) - (2)].p_rulePattern));
    }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 349 "lib/ShExCParser.ypp"
    {
	// $$ = $1 ? new SWSexSchema::NegatedRule($2) : $2;
	// @@ $1 is a label
	(yyval.p_rulePattern) = (yysemantic_stack_[(2) - (2)].p_rulePattern);
    }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 367 "lib/ShExCParser.ypp"
    {
	(yyval.p_bool) = false;
    }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 370 "lib/ShExCParser.ypp"
    {
        (yyval.p_bool) = true;
    }
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 379 "lib/ShExCParser.ypp"
    {
	driver.curRulePattern = (yysemantic_stack_[(3) - (2)].p_rulePattern);
      }
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 381 "lib/ShExCParser.ypp"
    {
	  // @@ set flag from $5
	  driver.curRulePattern = NULL;
	  (yyval.p_rulePattern) = (yysemantic_stack_[(6) - (6)].p_ruleActions) == NULL ? (yysemantic_stack_[(6) - (2)].p_rulePattern) : (yysemantic_stack_[(6) - (6)].p_ruleActions);
      }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 389 "lib/ShExCParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 392 "lib/ShExCParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 398 "lib/ShExCParser.ypp"
    {
	// pass down the nameClass 'cause we need valueSpec's CODE* to be able
	// to make a AtomicRule and potentially wrap it with RuleActions.
	driver.curNameClass = (yysemantic_stack_[(2) - (2)].p_nameClass);
	(yysemantic_stack_[(2) - (2)].p_nameClass)->reverse = (yysemantic_stack_[(2) - (1)].p_bool);
      }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 403 "lib/ShExCParser.ypp"
    {
	  if ((yysemantic_stack_[(6) - (5)].p_TTerm))
	      w3c_sw_NEED_IMPL("SWSex parser support for default");
	  driver.curRulePattern = new SWSexSchema::AtomicRule(driver.curNameClass, (yysemantic_stack_[(6) - (4)].p_value), (yysemantic_stack_[(6) - (6)].p_RepeatRange).min, (yysemantic_stack_[(6) - (6)].p_RepeatRange).max);
      }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 407 "lib/ShExCParser.ypp"
    {
	  (yyval.p_rulePattern) = (yysemantic_stack_[(9) - (9)].p_ruleActions) == NULL ? driver.curRulePattern : (yysemantic_stack_[(9) - (9)].p_ruleActions);
	  driver.curRulePattern = NULL;
	  driver.curNameClass = NULL;
	}
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 424 "lib/ShExCParser.ypp"
    {
	(yyval.p_bool) = false;
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 427 "lib/ShExCParser.ypp"
    {
	(yyval.p_bool) = true;
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 433 "lib/ShExCParser.ypp"
    {
	(yyval.p_TTerm) = NULL;
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 440 "lib/ShExCParser.ypp"
    {
	(yyval.p_RepeatRange).min = 1;
	(yyval.p_RepeatRange).max = 1;
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 455 "lib/ShExCParser.ypp"
    {
	if ((yysemantic_stack_[(1) - (1)].p_URIstem).opt)
	    (yyval.p_nameClass) = new SWSexSchema::AtomicRule::NamePattern((yysemantic_stack_[(1) - (1)].p_URIstem).uri);
	else
	    (yyval.p_nameClass) = new SWSexSchema::AtomicRule::NameTerm((yysemantic_stack_[(1) - (1)].p_URIstem).uri);
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 461 "lib/ShExCParser.ypp"
    {
	(yyval.p_nameClass) = new SWSexSchema::AtomicRule::NameAll((yysemantic_stack_[(2) - (2)].p_URIstems));
    }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 464 "lib/ShExCParser.ypp"
    {
	(yyval.p_nameClass) = new SWSexSchema::AtomicRule::NameTerm(TTerm::RDF_type);
    }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 470 "lib/ShExCParser.ypp"
    {
	(yyval.p_value) = new SWSexSchema::AtomicRule::ValueReference((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 473 "lib/ShExCParser.ypp"
    {
	const TTerm* b = driver.createBNode();
	driver.curSchema->ruleMap.insert(std::make_pair(b, (yysemantic_stack_[(1) - (1)].p_rulePattern)));
	(yyval.p_value) = new SWSexSchema::AtomicRule::ValueReference(b);
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 478 "lib/ShExCParser.ypp"
    {
	(yyval.p_value) = new SWSexSchema::AtomicRule::ValueType((yysemantic_stack_[(1) - (1)].p_URI));
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 481 "lib/ShExCParser.ypp"
    {
	SWSexSchema::AtomicRule::ValueSet* t = new SWSexSchema::AtomicRule::ValueSet();
	(yyval.p_valueSet)  = t;
	driver.curTTerms = &t->tterms;
      }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 485 "lib/ShExCParser.ypp"
    {
	  (yyval.p_value) = (yysemantic_stack_[(2) - (1)].p_valueSet);
      }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 488 "lib/ShExCParser.ypp"
    {
	(yyval.p_value) = new SWSexSchema::AtomicRule::ValueAny((yysemantic_stack_[(2) - (2)].p_URIstems));
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 491 "lib/ShExCParser.ypp"
    {
        w3c_sw_NEED_IMPL("SPARQL Results Format callout");
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 497 "lib/ShExCParser.ypp"
    {
	(yyval.p_URIstem).uri = (yysemantic_stack_[(2) - (1)].p_URI);
	(yyval.p_URIstem).opt = (yysemantic_stack_[(2) - (2)].p_bool);
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 504 "lib/ShExCParser.ypp"
    {
	(yyval.p_bool) = false;
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 507 "lib/ShExCParser.ypp"
    {
        (yyval.p_bool) = true;
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 513 "lib/ShExCParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(2) - (2)].p_TTerm);
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 519 "lib/ShExCParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 570 "lib/ShExCParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 574 "lib/ShExCParser.ypp"
    {
      (yyval.p_TTerm) = TTerm::RDF_type;
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 581 "lib/ShExCParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 587 "lib/ShExCParser.ypp"
    {
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_URI)));
    }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 590 "lib/ShExCParser.ypp"
    {
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 593 "lib/ShExCParser.ypp"
    {
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 596 "lib/ShExCParser.ypp"
    {
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 599 "lib/ShExCParser.ypp"
    {
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 611 "lib/ShExCParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 615 "lib/ShExCParser.ypp"
    {
	  (yyval.p_TTerm) = (BNode*)driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 624 "lib/ShExCParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
      }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 627 "lib/ShExCParser.ypp"
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

  case 98:

/* Line 690 of lalr1.cc  */
#line 642 "lib/ShExCParser.ypp"
    {
	(yyval.p_TTerm) = NULL;
    }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 645 "lib/ShExCParser.ypp"
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

  case 100:

/* Line 690 of lalr1.cc  */
#line 655 "lib/ShExCParser.ypp"
    {
	  (yyval.p_TTerm) = (yysemantic_stack_[(3) - (2)].p_TTerm);
      }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 665 "lib/ShExCParser.ypp"
    {
	(yyval.p_URIstem) = (yysemantic_stack_[(2) - (2)].p_URIstem);
    }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 671 "lib/ShExCParser.ypp"
    {
	(yyval.p_URIstems) = NULL;
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 674 "lib/ShExCParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (1)].p_URIstems) == NULL)
	    (yysemantic_stack_[(2) - (1)].p_URIstems) = new std::vector<SWSexSchema::URIstem>();
	(yysemantic_stack_[(2) - (1)].p_URIstems)->push_back((yysemantic_stack_[(2) - (2)].p_URIstem));
	(yyval.p_URIstems) = (yysemantic_stack_[(2) - (1)].p_URIstems);
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 685 "lib/ShExCParser.ypp"
    {
	(yyval.p_RepeatRange).min = 0;
	(yyval.p_RepeatRange).max = SWSexSchema::AtomicRule::Unlimited;
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 689 "lib/ShExCParser.ypp"
    {
	(yyval.p_RepeatRange).min = 1;
	(yyval.p_RepeatRange).max = SWSexSchema::AtomicRule::Unlimited;
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 693 "lib/ShExCParser.ypp"
    {
	(yyval.p_RepeatRange).min = 0;
	(yyval.p_RepeatRange).max = 1;
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 697 "lib/ShExCParser.ypp"
    {
	(yyval.p_RepeatRange).min = (yysemantic_stack_[(4) - (2)].p_NumericRDFLiteral)->getInt();
	(yyval.p_RepeatRange).max = (yysemantic_stack_[(4) - (3)].p_int);
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 704 "lib/ShExCParser.ypp"
    {
	(yyval.p_int) = SWSexSchema::AtomicRule::Unlimited;
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 707 "lib/ShExCParser.ypp"
    {
	(yyval.p_int) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)->getInt();
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 713 "lib/ShExCParser.ypp"
    {
	(yyval.p_int) = (yysemantic_stack_[(2) - (2)].p_int);
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 719 "lib/ShExCParser.ypp"
    {
	(yyval.p_int) = SWSexSchema::AtomicRule::Unlimited;
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 730 "lib/ShExCParser.ypp"
    {
	driver.curTTerms->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 733 "lib/ShExCParser.ypp"
    {
	driver.curTTerms->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 739 "lib/ShExCParser.ypp"
    {
	if ((yysemantic_stack_[(1) - (1)].p_URIstem).opt)
	    w3c_sw_NEED_IMPL("SWSex parser support for URIstems in value sets");
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URIstem).uri;
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 749 "lib/ShExCParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 752 "lib/ShExCParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 755 "lib/ShExCParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 762 "lib/ShExCParser.ypp"
    {
	(yyval.p_TTerm) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 770 "lib/ShExCParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 775 "lib/ShExCParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(2) - (2)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 783 "lib/ShExCParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 690 of lalr1.cc  */
#line 1337 "lib/ShExCParser.cpp"
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
  SWSexParser::yysyntax_error_ (int yystate, int yytoken)
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
  const short int SWSexParser::yypact_ninf_ = -142;
  const short int
  SWSexParser::yypact_[] =
  {
      -142,    27,     4,  -142,    44,    -8,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,    45,  -142,  -142,
    -142,     9,  -142,    19,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,    21,  -142,    36,    36,  -142,    57,  -142,
    -142,  -142,  -142,    62,    65,    16,  -142,  -142,    15,  -142,
    -142,  -142,    69,  -142,  -142,  -142,  -142,    26,  -142,    62,
    -142,    61,  -142,  -142,  -142,  -142,    63,  -142,  -142,  -142,
      58,    -3,  -142,  -142,    68,    16,  -142,  -142,    30,    16,
    -142,    79,    71,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
     153,    -1,  -142,   139,  -142,    36,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
     -14,  -142,    52,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
     115,  -142,  -142,    16,  -142,  -142,  -142,    76,    66,  -142,
    -142,  -142,    56,  -142,    83,  -142,  -142,  -142,  -142,  -142,
    -142,    -9,    36,  -142,    70,    77,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,    74,    85,
      82,    -9,  -142,    77,  -142,  -142,    77,  -142,  -142,    77,
    -142,  -142,  -142
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  SWSexParser::yydefact_[] =
  {
         3,     0,     2,     1,     0,     0,    16,   138,   139,   137,
     136,   134,     4,     5,     7,     8,     6,     0,    43,   135,
      44,     0,    15,     0,    21,    19,     9,    13,    12,    17,
      22,    10,    10,     0,    24,    20,    14,    18,     0,    29,
      11,    23,    27,    36,    25,     0,    32,    37,    48,    29,
      28,    35,    30,    24,    49,    34,    40,     0,    26,    36,
      33,     0,   103,    58,    45,    56,    67,    31,    41,    57,
     101,    62,    68,    66,    38,     0,   104,   103,     0,     0,
      60,    50,     0,    61,    39,    10,   102,    64,    59,    65,
       0,    52,    51,     0,    63,    42,   128,   129,   120,   121,
     122,   130,   131,   132,   133,    69,    71,    92,    91,    93,
     126,    70,     0,   107,   105,   106,    46,    53,   117,   119,
       0,   115,   118,     0,   124,   127,   123,   112,    54,   114,
     116,   125,   109,   113,     0,    94,    10,    55,   110,   111,
     108,     0,    47,    84,     0,     0,    83,    85,    95,    96,
      77,    81,    90,    89,    88,    86,    87,    98,    72,    79,
      99,    74,    78,     0,    82,    97,     0,    75,    76,     0,
      80,   100,    73
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SWSexParser::yypgoto_[] =
  {
      -142,  -142,  -142,  -142,  -142,   -31,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,   -16,  -142,  -142,    46,  -142,  -142,
    -142,    48,  -142,  -142,  -142,    41,  -142,  -142,  -142,  -142,
    -142,   -18,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,   -49,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,   -68,  -142,  -142,   -59,  -142,  -141,   -73,   -25,  -142,
    -142,  -142,  -142,  -142,    47,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,     2,  -142,  -142,  -142,  -142,  -142,  -142,
      -2,  -142,     0
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SWSexParser::yydefgoto_[] =
  {
        -1,     1,     2,    12,    13,    35,    26,    32,    14,    15,
      23,    33,    16,    31,    25,    30,    34,    38,    39,    50,
      44,    42,    43,    60,    52,    46,    47,    48,    85,    55,
      74,    17,    56,    71,   128,    57,    91,   116,   136,    64,
      81,    82,   118,    73,    92,   105,   144,   167,   168,   162,
     158,   150,   164,   159,   145,   146,   151,   152,   153,   141,
     154,   157,   160,   166,    69,    76,    70,   117,   139,   133,
     134,    94,   120,   121,   107,   108,   125,   126,   109,   110,
      66,    19,   156
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char SWSexParser::yytable_ninf_ = -1;
  const unsigned char
  SWSexParser::yytable_[] =
  {
        18,    36,    20,    28,    24,    27,   112,     4,    65,     5,
       6,   113,   123,    77,    78,    79,    24,   106,   143,    18,
     119,    20,   170,   114,   115,   171,    86,     3,    53,   124,
      54,     9,    10,    11,    22,     7,     8,     9,    10,    11,
       7,     8,    62,    51,     9,    10,    11,   119,    21,     9,
      10,    11,    24,    63,    95,    80,     9,    10,    11,    29,
      88,     7,     8,    37,    40,    41,     9,    10,    11,    83,
       9,    10,    11,    45,    49,    68,    18,    89,    20,    59,
      84,    75,    72,    90,    93,   127,   132,   135,   111,   138,
     149,   140,   148,   122,   161,   163,   165,    58,   135,    61,
      67,   172,   169,   137,     0,   142,    96,    97,     7,     8,
      98,    99,   100,   101,   102,   103,   104,     9,    10,    11,
     122,   131,   130,     0,    87,     0,     0,     0,     0,   129,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   147,
       0,     0,     0,   155,    96,    97,     7,     8,    98,    99,
     100,   101,   102,   103,   104,     9,    10,    11,     0,   147,
       0,   155,     0,     0,   155,     0,     0,   155,    96,    97,
       7,     8,    98,    99,   100,   101,   102,   103,   104,     9,
      10,    11,    96,    97,     0,     0,    98,    99,   100,   101,
     102,   103,   104,     9,    10,    11
  };

  /* YYCHECK.  */
  const short int
  SWSexParser::yycheck_[] =
  {
         2,    32,     2,    21,     7,    21,     7,     3,    57,     5,
       6,    12,    26,    16,    17,    18,     7,    90,    27,    21,
      93,    21,   163,    24,    25,   166,    75,     0,    13,    43,
      15,    40,    41,    42,    42,    31,    32,    40,    41,    42,
      31,    32,    16,    45,    40,    41,    42,   120,     4,    40,
      41,    42,     7,    27,    85,    71,    40,    41,    42,    40,
      78,    31,    32,    42,    28,     8,    40,    41,    42,    71,
      40,    41,    42,    11,     9,    14,    78,    79,    78,    10,
      12,    23,    19,     4,    13,    33,    10,    21,    90,    33,
      13,     8,    22,    93,    20,    10,    14,    49,    21,    53,
      59,   169,   161,   128,    -1,   136,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
     120,   123,   120,    -1,    77,    -1,    -1,    -1,    -1,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,
      -1,    -1,    -1,   145,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,   161,
      -1,   163,    -1,    -1,   166,    -1,    -1,   169,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    29,    30,    -1,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  SWSexParser::yystos_[] =
  {
         0,    45,    46,     0,     3,     5,     6,    31,    32,    40,
      41,    42,    47,    48,    52,    53,    56,    75,   124,   125,
     126,     4,    42,    54,     7,    58,    50,    58,    75,    40,
      59,    57,    51,    55,    60,    49,    49,    42,    61,    62,
      28,     8,    65,    66,    64,    11,    69,    70,    71,     9,
      63,   124,    68,    13,    15,    73,    76,    79,    65,    10,
      67,    61,    16,    27,    83,    86,   124,    69,    14,   108,
     110,    77,    19,    87,    74,    23,   109,    16,    17,    18,
      58,    84,    85,   124,    12,    72,    86,   108,    75,   124,
       4,    80,    88,    13,   115,    49,    29,    30,    33,    34,
      35,    36,    37,    38,    39,    89,   101,   118,   119,   122,
     123,   124,     7,    12,    24,    25,    81,   111,    86,   101,
     116,   117,   126,    26,    43,   120,   121,    33,    78,    14,
     117,   124,    10,   113,   114,    21,    82,   102,    33,   112,
       8,   103,    49,    27,    90,    98,    99,   124,    22,    13,
      95,   100,   101,   102,   104,   124,   126,   105,    94,    97,
     106,    20,    93,    10,    96,    14,   107,    91,    92,    98,
     100,   100,    95
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  SWSexParser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  SWSexParser::yyr1_[] =
  {
         0,    44,    45,    46,    46,    47,    47,    48,    48,    48,
      49,    49,    50,    51,    50,    52,    54,    55,    53,    57,
      56,    59,    60,    58,    62,    61,    63,    64,    64,    66,
      65,    67,    68,    68,    69,    70,    71,    71,    72,    72,
      73,    74,    73,    75,    75,    77,    78,    76,    79,    79,
      80,    80,    81,    81,    82,    82,    83,    83,    83,    84,
      84,    84,    85,    84,    84,    84,    86,    87,    87,    88,
      89,    89,    90,    91,    92,    92,    93,    94,    94,    95,
      96,    97,    97,    98,    98,    99,   100,   100,   100,   100,
     100,   101,   101,   101,   103,   102,   105,   104,   106,   107,
     106,   108,   109,   110,   110,   111,   111,   111,   111,   112,
     112,   113,   114,   114,   115,   116,   116,   117,   117,   117,
     118,   118,   118,   119,   120,   120,   121,   121,   122,   122,
     123,   123,   123,   123,   124,   124,   125,   125,   126,   126
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  SWSexParser::yyr2_[] =
  {
         0,     2,     1,     0,     2,     1,     1,     1,     1,     3,
       0,     2,     1,     0,     3,     2,     0,     0,     5,     0,
       4,     0,     0,     5,     0,     3,     2,     0,     2,     0,
       3,     2,     0,     2,     2,     2,     0,     1,     0,     1,
       1,     0,     6,     1,     1,     0,     0,     9,     0,     1,
       0,     1,     0,     1,     0,     1,     1,     2,     1,     2,
       1,     1,     0,     2,     2,     2,     2,     0,     1,     2,
       1,     1,     3,     2,     0,     1,     2,     0,     2,     2,
       2,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     4,     0,     4,     0,     0,
       3,     1,     2,     0,     2,     1,     1,     1,     4,     0,
       1,     2,     0,     1,     3,     1,     2,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const SWSexParser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "IT_start", "GT_EQUAL",
  "IT_BASE", "IT_PREFIX", "GT_LCURLEY", "GT_RCURLEY", "GT_PIPE",
  "GT_COMMA", "GT_DOLLAR", "GT_OPT", "GT_LPAREN", "GT_RPAREN", "GT_CARROT",
  "GT_DOT", "GT_AT", "IT_SPARQL_SRX", "GT_KINDA", "GT_SEMI", "GT_LBRACKET",
  "GT_RBRACKET", "GT_MINUS", "GT_TIMES", "GT_PLUS", "GT_DTYPE", "RDF_TYPE",
  "CODE", "IT_true", "IT_false", "BLANK_NODE_LABEL", "ANON", "INTEGER",
  "DECIMAL", "DOUBLE", "STRING_LITERAL1", "STRING_LITERAL2",
  "STRING_LITERAL_LONG1", "STRING_LITERAL_LONG2", "PNAME_NS", "PNAME_LN",
  "IRIREF", "LANGTAG", "$accept", "SWSexDoc", "_Qstatement_E_Star",
  "statement", "directive", "_QCODE_E_Star",
  "_O_Qlabel_E_Or_QtypeSpec_E_S_QCODE_E_Star_C", "$@1", "BaseDecl",
  "PrefixDecl", "$@2", "$@3", "shape", "$@4", "typeSpec", "@5", "@6",
  "OrExpression", "@7", "_O_QGT_PIPE_E_S_QAndExpression_E_C",
  "_Q_O_QGT_PIPE_E_S_QAndExpression_E_C_E_Star", "AndExpression", "@8",
  "_O_QGT_COMMA_E_S_QUnaryExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QUnaryExpression_E_C_E_Star", "UnaryExpression",
  "_O_QGT_DOLLAR_E_S_Qiri_E_C", "_Q_O_QGT_DOLLAR_E_S_Qiri_E_C_E_Opt",
  "_QGT_OPT_E_Opt",
  "_O_Qarc_E_Or_QGT_LPAREN_E_S_QOrExpression_E_S_QGT_RPAREN_E_S_QGT_OPT_E_Opt_S_QCODE_E_Star_C",
  "$@9", "label", "arc", "$@10", "$@11", "_QGT_CARROT_E_Opt",
  "_Qdefahlt_E_Opt", "_QrepeatCount_E_Opt",
  "_QblankNodePropertyList_E_Opt", "nameClass", "valueSpec", "@12",
  "iriStem", "_QGT_KINDA_E_Opt", "defahlt", "_O_Qiri_E_Or_Qliteral_E_C",
  "predicateObjectList", "_O_Qverb_E_S_QobjectList_E_C",
  "_Q_O_Qverb_E_S_QobjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_Qverb_E_S_QobjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_Qverb_E_S_QobjectList_E_Opt_C_E_Star", "objectList",
  "_O_QGT_COMMA_E_S_Qobject_E_C", "_Q_O_QGT_COMMA_E_S_Qobject_E_C_E_Star",
  "verb", "predicate", "object", "literal", "blankNodePropertyList", "@13",
  "collection", "@14", "_Qobject_E_Star", "@15", "exclusions",
  "_O_QGT_MINUS_E_S_QiriStem_E_C",
  "_Q_O_QGT_MINUS_E_S_QiriStem_E_C_E_Star", "repeatCount",
  "_QINTEGER_E_Opt", "_O_QGT_COMMA_E_S_QINTEGER_E_Opt_C",
  "_Q_O_QGT_COMMA_E_S_QINTEGER_E_Opt_C_E_Opt", "valueSet",
  "_Qvalue_E_Plus", "valueChoice", "NumericLiteral", "RDFLiteral",
  "_O_QLANGTAG_E_Or_QGT_DTYPE_E_S_Qiri_E_C",
  "_Q_O_QLANGTAG_E_Or_QGT_DTYPE_E_S_Qiri_E_C_E_Opt", "BooleanLiteral",
  "String", "iri", "PrefixedName", "BlankNode", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const SWSexParser::rhs_number_type
  SWSexParser::yyrhs_[] =
  {
        45,     0,    -1,    46,    -1,    -1,    46,    47,    -1,    48,
      -1,    56,    -1,    52,    -1,    53,    -1,     3,     4,    50,
      -1,    -1,    49,    28,    -1,    75,    -1,    -1,    58,    51,
      49,    -1,     5,    42,    -1,    -1,    -1,     6,    54,    40,
      55,    42,    -1,    -1,    75,    58,    57,    49,    -1,    -1,
      -1,     7,    59,    60,    61,     8,    -1,    -1,    62,    65,
      64,    -1,     9,    65,    -1,    -1,    64,    63,    -1,    -1,
      66,    69,    68,    -1,    10,    69,    -1,    -1,    68,    67,
      -1,    71,    73,    -1,    11,   124,    -1,    -1,    70,    -1,
      -1,    12,    -1,    76,    -1,    -1,    13,    61,    14,    74,
      72,    49,    -1,   124,    -1,   126,    -1,    -1,    -1,    79,
      83,    77,    84,    80,    81,    78,    82,    49,    -1,    -1,
      15,    -1,    -1,    88,    -1,    -1,   111,    -1,    -1,   102,
      -1,    86,    -1,    16,   108,    -1,    27,    -1,    17,    75,
      -1,    58,    -1,   124,    -1,    -1,    85,   115,    -1,    16,
     108,    -1,    18,   124,    -1,   124,    87,    -1,    -1,    19,
      -1,     4,    89,    -1,   124,    -1,   101,    -1,    98,    95,
      94,    -1,    98,    95,    -1,    -1,    91,    -1,    20,    92,
      -1,    -1,    94,    93,    -1,   100,    97,    -1,    10,   100,
      -1,    -1,    97,    96,    -1,    99,    -1,    27,    -1,   124,
      -1,   124,    -1,   126,    -1,   104,    -1,   102,    -1,   101,
      -1,   119,    -1,   118,    -1,   122,    -1,    -1,    21,   103,
      90,    22,    -1,    -1,    13,   105,   106,    14,    -1,    -1,
      -1,   106,   107,   100,    -1,   110,    -1,    23,    86,    -1,
      -1,   110,   109,    -1,    24,    -1,    25,    -1,    12,    -1,
       7,    33,   114,     8,    -1,    -1,    33,    -1,    10,   112,
      -1,    -1,   113,    -1,    13,   116,    14,    -1,   117,    -1,
     116,   117,    -1,    86,    -1,   126,    -1,   101,    -1,    33,
      -1,    34,    -1,    35,    -1,   123,   121,    -1,    43,    -1,
      26,   124,    -1,    -1,   120,    -1,    29,    -1,    30,    -1,
      36,    -1,    37,    -1,    38,    -1,    39,    -1,    42,    -1,
     125,    -1,    41,    -1,    40,    -1,    31,    -1,    32,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  SWSexParser::yyprhs_[] =
  {
         0,     0,     3,     5,     6,     9,    11,    13,    15,    17,
      21,    22,    25,    27,    28,    32,    35,    36,    37,    43,
      44,    49,    50,    51,    57,    58,    62,    65,    66,    69,
      70,    74,    77,    78,    81,    84,    87,    88,    90,    91,
      93,    95,    96,   103,   105,   107,   108,   109,   119,   120,
     122,   123,   125,   126,   128,   129,   131,   133,   136,   138,
     141,   143,   145,   146,   149,   152,   155,   158,   159,   161,
     164,   166,   168,   172,   175,   176,   178,   181,   182,   185,
     188,   191,   192,   195,   197,   199,   201,   203,   205,   207,
     209,   211,   213,   215,   217,   218,   223,   224,   229,   230,
     231,   235,   237,   240,   241,   244,   246,   248,   250,   255,
     256,   258,   261,   262,   264,   268,   270,   273,   275,   277,
     279,   281,   283,   285,   288,   290,   293,   294,   296,   298,
     300,   302,   304,   306,   308,   310,   312,   314,   316,   318
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SWSexParser::yyrline_[] =
  {
         0,   202,   202,   205,   207,   211,   212,   216,   217,   218,
     224,   227,   238,   239,   239,   249,   255,   257,   255,   266,
     266,   275,   278,   275,   289,   289,   304,   309,   311,   319,
     319,   334,   339,   341,   349,   358,   361,   363,   367,   370,
     378,   379,   379,   389,   392,   398,   403,   398,   424,   427,
     433,   436,   440,   444,   448,   450,   455,   461,   464,   470,
     473,   478,   481,   481,   488,   491,   497,   504,   507,   513,
     519,   522,   528,   533,   537,   539,   544,   548,   550,   555,
     560,   564,   566,   570,   574,   581,   587,   590,   593,   596,
     599,   605,   606,   607,   611,   611,   624,   624,   642,   645,
     645,   661,   665,   671,   674,   685,   689,   693,   697,   704,
     707,   713,   719,   722,   726,   730,   733,   739,   744,   745,
     749,   752,   755,   762,   770,   775,   783,   787,   791,   792,
     796,   797,   798,   799,   803,   804,   808,   809,   813,   814
  };

  // Print the state stack on the debug stream.
  void
  SWSexParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  SWSexParser::yy_reduce_print_ (int yyrule)
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
  SWSexParser::token_number_type
  SWSexParser::yytranslate_ (int t)
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int SWSexParser::yyeof_ = 0;
  const int SWSexParser::yylast_ = 195;
  const int SWSexParser::yynnts_ = 83;
  const int SWSexParser::yyempty_ = -2;
  const int SWSexParser::yyfinal_ = 3;
  const int SWSexParser::yyterror_ = 1;
  const int SWSexParser::yyerrcode_ = 256;
  const int SWSexParser::yyntokens_ = 44;

  const unsigned int SWSexParser::yyuser_token_number_max_ = 298;
  const SWSexParser::token_number_type SWSexParser::yyundef_token_ = 2;


} // w3c_sw

/* Line 1136 of lalr1.cc  */
#line 2042 "lib/ShExCParser.cpp"


/* Line 1138 of lalr1.cc  */
#line 819 "lib/ShExCParser.ypp"
 /*** Additional Code ***/

void w3c_sw::SWSexParser::error(const SWSexParser::location_type& l,
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
    _SUBS(s, "BASE", "@base");
    _SUBS(s, "PREFIX", "@prefix");
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

size_t SWSexDriver::DefaultAbortErrorCount = 100;

SWSexSchema* SWSexDriver::parse (IStreamContext& in) {
    reset();
    streamname = in.nameStr;
    // clear prefixes for nth run but keep them around for e.g. serialization.
    clearPrefixes();

    SWSexScanner scanner(this, in.p);
    scanner.set_debug(trace_scanning);
    this->lexer = &scanner;

    SWSexParser parser(*this);
    parser.set_debug_level(trace_parsing);
    parser.parse();
    checkErrors();
    return curSchema;
}

SWSexSchema* SWSexDriver::parse (IStreamContext& in, SWSexSchema* schema) {
    setSchema(schema);
    return parse(in);
}

SWSexSchema* SWSexDriver::parse (std::string swsexStr, SWSexSchema* schema) {
    IStreamContext in(swsexStr.c_str(), IStreamContext::STRING);
    setSchema(schema);
    return parse(in);
}

} // namespace w3c_sw

/* END Driver */


