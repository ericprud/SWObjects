
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
#line 43 "lib/SQLParser/SQLParser.cpp"


#include "SQLParser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 213 "lib/SQLParser/SQLParser.ypp"

#include "SQLScanner.hpp"

/* Line 317 of lalr1.cc  */
#line 291 "lib/SQLParser/SQLParser.ypp"

#include <stdarg.h>
#include "SQL.hpp"
#include "SQLScanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc  */
#line 70 "lib/SQLParser/SQLParser.cpp"

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
#line 139 "lib/SQLParser/SQLParser.cpp"
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  SQLParser::yytnamerr_ (const char *yystr)
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
  SQLParser::SQLParser (class SQLDriver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {
  }

  SQLParser::~SQLParser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  SQLParser::yy_symbol_value_print_ (int yytype,
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
  SQLParser::yy_symbol_print_ (int yytype,
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
  SQLParser::yydestruct_ (const char* yymsg,
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
  SQLParser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  SQLParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  SQLParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  SQLParser::debug_level_type
  SQLParser::debug_level () const
  {
    return yydebug_;
  }

  void
  SQLParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  int
  SQLParser::parse ()
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
#line 32 "lib/SQLParser/SQLParser.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 553 of lalr1.cc  */
#line 323 "lib/SQLParser/SQLParser.cpp"

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
#line 307 "lib/SQLParser/SQLParser.ypp"
    {
	driver.root = (yysemantic_stack_[(2) - (1)].p_Select);
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 363 "lib/SQLParser/SQLParser.ypp"
    {
	driver.curCreate = new sql::schema::Relation(*(yysemantic_stack_[(3) - (3)].p_NAME));
      }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 365 "lib/SQLParser/SQLParser.ypp"
    {
	  driver.tables[*(yysemantic_stack_[(9) - (3)].p_NAME)] = driver.curCreate;
	  delete (yysemantic_stack_[(9) - (3)].p_NAME);
	  driver.curCreate = NULL;
      }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 387 "lib/SQLParser/SQLParser.ypp"
    {
	driver.curCreate = new sql::schema::Relation(*(yysemantic_stack_[(5) - (3)].p_NAME));
	driver.inserts.push_back(new sql::Insert(*(yysemantic_stack_[(5) - (3)].p_NAME), (yysemantic_stack_[(5) - (4)].p_Attributes), (yysemantic_stack_[(5) - (5)].p_RValue)));
	delete (yysemantic_stack_[(5) - (3)].p_NAME);
    }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 395 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Attributes) = NULL;
    }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 402 "lib/SQLParser/SQLParser.ypp"
    {
	w3c_sw_LINEN << "ignoring non-standard inserts\n";
    }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 413 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_RValue) = new sql::RConstants((yysemantic_stack_[(3) - (2)].p_Expressions));
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 416 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_RValue) = new sql::RSelection((yysemantic_stack_[(1) - (1)].p_Select));
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 422 "lib/SQLParser/SQLParser.ypp"
    {
	w3c_sw_LINEN << "ignoring parameters\n";
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 442 "lib/SQLParser/SQLParser.ypp"
    {
	driver.curAttributeName = (yysemantic_stack_[(1) - (1)].p_NAME);
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 444 "lib/SQLParser/SQLParser.ypp"
    {
	sql::schema::Field* f = new sql::schema::Field(*(yysemantic_stack_[(3) - (1)].p_NAME), (yysemantic_stack_[(3) - (3)].p_TypeSize).type, (yysemantic_stack_[(3) - (3)].p_TypeSize).size);
	driver.curCreate->addField(f);
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 447 "lib/SQLParser/SQLParser.ypp"
    {
	driver.curAttributeName = NULL;
	if (driver.curIsPrimary) {
	    driver.curIsPrimary = false;
	    std::vector<sql::Attribute>* attrs = new std::vector<sql::Attribute>();
	    attrs->push_back(*(yysemantic_stack_[(5) - (1)].p_NAME));
	    driver.curCreate->setPrimaryKey(new sql::schema::PrimaryKey(attrs));
	}
	delete (yysemantic_stack_[(5) - (1)].p_NAME);
      }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 457 "lib/SQLParser/SQLParser.ypp"
    {
      driver.curCreate->addForeignKey(new sql::schema::ForeignKey((yysemantic_stack_[(7) - (4)].p_Attributes), *(yysemantic_stack_[(7) - (6)].p_NAME), (yysemantic_stack_[(7) - (7)].p_Attributes)));
      delete (yysemantic_stack_[(7) - (6)].p_NAME);
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 461 "lib/SQLParser/SQLParser.ypp"
    {
      driver.curCreate->setPrimaryKey(new sql::schema::PrimaryKey((yysemantic_stack_[(3) - (3)].p_Attributes)));
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 464 "lib/SQLParser/SQLParser.ypp"
    {
	w3c_sw_LINEN << "ignoring UNIQUE KEYs\n";
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 475 "lib/SQLParser/SQLParser.ypp"
    {
	w3c_sw_LINEN << "ignoring constraint name\n";
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 496 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TypeSize).type = (yysemantic_stack_[(2) - (1)].p_SchemaDatatype);
	(yyval.p_TypeSize).size = (yysemantic_stack_[(2) - (2)].p_int);
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 503 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(3) - (2)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 511 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_int) = SQL_PRECISION_unspecified;
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 518 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype) = (yysemantic_stack_[(3) - (3)].p_bool) ? sql::TYPE_varchar : sql::TYPE_char;
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 521 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype) = sql::TYPE_varchar;
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 524 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype) = sql::TYPE_binary;
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 527 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype) = sql::TYPE_int;
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 530 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype) = sql::TYPE_int;
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 533 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype) = sql::TYPE_int;
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 536 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype) = sql::TYPE_int;
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 539 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype) = sql::TYPE_int;
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 542 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::TYPE_float;
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 545 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::TYPE_real;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 548 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::TYPE_double;
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 551 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::TYPE_boolean;
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 554 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::TYPE_date;
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 557 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::TYPE_time;
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 560 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::TYPE_timestamp;
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 563 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::TYPE_datetime;
    }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 566 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::TYPE_interval;
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 582 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_bool) = true;
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 585 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_bool) = false;
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 591 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_bool) = false;
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 603 "lib/SQLParser/SQLParser.ypp"
    {
	driver.curIsPrimary = true;
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 606 "lib/SQLParser/SQLParser.ypp"
    {
	w3c_sw_LINEN << "ignoring DEFAULT\n";
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 609 "lib/SQLParser/SQLParser.ypp"
    {
	w3c_sw_LINEN << "ignoring NOT NULL\n";
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 612 "lib/SQLParser/SQLParser.ypp"
    {
	w3c_sw_LINEN << "ignoring UNIQUE\n";
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 615 "lib/SQLParser/SQLParser.ypp"
    {
	std::vector<sql::Attribute>* attrs = new std::vector<sql::Attribute>();
	attrs->push_back(sql::Attribute(*driver.curAttributeName));
	sql::schema::ForeignKey* fk = new sql::schema::ForeignKey(attrs, *(yysemantic_stack_[(3) - (2)].p_NAME), (yysemantic_stack_[(3) - (3)].p_Attributes));
	driver.curCreate->addForeignKey(fk);
	delete (yysemantic_stack_[(3) - (2)].p_NAME);
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 625 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::IsNullConstraint();
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 631 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::CastConstraint((yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_TypeSize).type, (yysemantic_stack_[(6) - (5)].p_TypeSize).size);
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 637 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(4) - (3)].p_Attributes)->insert((yysemantic_stack_[(4) - (3)].p_Attributes)->begin(), *(yysemantic_stack_[(4) - (2)].p_NAME));
	delete (yysemantic_stack_[(4) - (2)].p_NAME);
	(yyval.p_Attributes) = (yysemantic_stack_[(4) - (3)].p_Attributes);
}
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 645 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = (yysemantic_stack_[(2) - (2)].p_NAME);
}
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 651 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Attributes) = new std::vector<sql::Attribute>();
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 654 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Attributes)->push_back(*(yysemantic_stack_[(2) - (2)].p_NAME));
	delete (yysemantic_stack_[(2) - (2)].p_NAME);
	(yyval.p_Attributes) = (yysemantic_stack_[(2) - (1)].p_Attributes);
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 662 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(4) - (3)].p_Expressions)->insert((yysemantic_stack_[(4) - (3)].p_Expressions)->begin(), (yysemantic_stack_[(4) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(4) - (3)].p_Expressions);
}
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 669 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 675 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 678 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 685 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Selects)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Selects)->insert((yysemantic_stack_[(2) - (2)].p_Selects)->begin(), (yysemantic_stack_[(2) - (1)].p_Select));
	    sql::SQLUnion* u = new sql::SQLUnion((yysemantic_stack_[(2) - (2)].p_Selects)->begin(), (yysemantic_stack_[(2) - (2)].p_Selects)->end());
	    (yyval.p_Select) = driver.root = u;
	} else
	    (yyval.p_Select) = driver.root = (yysemantic_stack_[(2) - (1)].p_Select);
	delete (yysemantic_stack_[(2) - (2)].p_Selects);
}
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 697 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Select) = (yysemantic_stack_[(2) - (2)].p_Select);
}
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 703 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Selects) = new std::vector<sql::SQLQuery*>();
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 706 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Selects)->push_back((yysemantic_stack_[(2) - (2)].p_Select));
	(yyval.p_Selects) = (yysemantic_stack_[(2) - (1)].p_Selects);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 713 "lib/SQLParser/SQLParser.ypp"
    {
	driver.root = (yyval.p_Select) = new sql::SQLQuery((yysemantic_stack_[(5) - (3)].p_TableList).joins);
	delete (yysemantic_stack_[(5) - (3)].p_TableList).joins;
	for (std::vector<sql::AliasedSelect*>::const_iterator it = (yysemantic_stack_[(5) - (2)].p_AttributeList)->begin(); it != (yysemantic_stack_[(5) - (2)].p_AttributeList)->end(); ++it)
	    driver.root->selects.push_back(*it);
	delete (yysemantic_stack_[(5) - (2)].p_AttributeList);
	for (std::vector<const w3c_sw::sql::Expression*>::const_iterator it = (yysemantic_stack_[(5) - (3)].p_TableList).exprs->begin();
	     it != (yysemantic_stack_[(5) - (3)].p_TableList).exprs->end(); ++it)
	    driver.root->constraints.push_back(*it);
	    // LINE << "exprs: " << (*it)->toString();
	delete (yysemantic_stack_[(5) - (3)].p_TableList).exprs;
	driver.root->limit = (yysemantic_stack_[(5) - (4)].p_int);
	driver.root->offset = (yysemantic_stack_[(5) - (5)].p_int);
}
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 730 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 736 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 743 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TableList).joins = (yysemantic_stack_[(3) - (2)].p_TableList).joins;
	(yyval.p_TableList).exprs = (yysemantic_stack_[(3) - (2)].p_TableList).exprs;
	if ((yysemantic_stack_[(3) - (3)].p_Expression) != NULL)
	    (yyval.p_TableList).exprs->push_back((yysemantic_stack_[(3) - (3)].p_Expression));
}
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 752 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TableList).joins = new std::vector<sql::Join*>();;
	(yyval.p_TableList).exprs = new std::vector<const sql::Expression*>();;
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 760 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 765 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(3) - (3)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(3) - (3)].p_Expression);
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 773 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_int) = -1;
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 780 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 788 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_int) = -1;
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 795 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (2)].p_AttributeList)->insert((yysemantic_stack_[(2) - (2)].p_AttributeList)->begin(), (yysemantic_stack_[(2) - (1)].p_AliasedSelect));
	(yyval.p_AttributeList) = new std::vector<sql::AliasedSelect*>((yysemantic_stack_[(2) - (2)].p_AttributeList)->begin(), (yysemantic_stack_[(2) - (2)].p_AttributeList)->end());
	delete (yysemantic_stack_[(2) - (2)].p_AttributeList);
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 800 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AttributeList) = new std::vector<sql::AliasedSelect*>();
      }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 806 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AliasedSelect) = (yysemantic_stack_[(2) - (2)].p_AliasedSelect);
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 812 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AttributeList) = new std::vector<sql::AliasedSelect*>();
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 815 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_AttributeList)->push_back((yysemantic_stack_[(2) - (2)].p_AliasedSelect));
	(yyval.p_AttributeList) = (yysemantic_stack_[(2) - (1)].p_AttributeList);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 822 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_NAME) == NULL) {
	    // "SELECT a.dname FROM DEPT AS a" yields a field calld `dname` (i.e. elides the alias).
	    const sql::AliasAttrConstraint* a = dynamic_cast<const sql::AliasAttrConstraint*>((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_AliasedSelect) = new sql::AliasedSelect((yysemantic_stack_[(2) - (1)].p_Expression), a ? a->getAliasAttr().attr : (yysemantic_stack_[(2) - (1)].p_Expression)->toString());
	} else {
	    (yyval.p_AliasedSelect) = new sql::AliasedSelect((yysemantic_stack_[(2) - (1)].p_Expression), *(yysemantic_stack_[(2) - (2)].p_NAME));
	    delete (yysemantic_stack_[(2) - (2)].p_NAME);
	}
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 840 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = (yysemantic_stack_[(2) - (2)].p_NAME);
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 846 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = NULL;
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 849 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = (yysemantic_stack_[(1) - (1)].p_NAME);
      }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 855 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::AliasAttrConstraint(sql::AliasAttr(sql::RelVar(*(yysemantic_stack_[(3) - (1)].p_NAME)), sql::Attribute(*(yysemantic_stack_[(3) - (3)].p_NAME))));
	delete (yysemantic_stack_[(3) - (1)].p_NAME);
	delete (yysemantic_stack_[(3) - (3)].p_NAME);
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 860 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_Expression) = new sql::AliasAttrConstraint(sql::AliasAttr(sql::RelVar(""), sql::Attribute(*(yysemantic_stack_[(1) - (1)].p_NAME))));
	delete (yysemantic_stack_[(1) - (1)].p_NAME);
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 877 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (2)].p_TableList).joins->insert((yysemantic_stack_[(2) - (2)].p_TableList).joins->begin(), (yysemantic_stack_[(2) - (1)].p_tableAlias).relation != NULL
		   ? (sql::Join*)new sql::TableJoin(*(yysemantic_stack_[(2) - (1)].p_tableAlias).relation, *(yysemantic_stack_[(2) - (1)].p_tableAlias).alias, false)
		   : (sql::Join*)new sql::SubqueryJoin((yysemantic_stack_[(2) - (1)].p_tableAlias).subselect, *(yysemantic_stack_[(2) - (1)].p_tableAlias).alias, false));
	delete (yysemantic_stack_[(2) - (1)].p_tableAlias).relation;
	delete (yysemantic_stack_[(2) - (1)].p_tableAlias).alias;
	(yyval.p_TableList).joins = new std::vector<sql::Join*>((yysemantic_stack_[(2) - (2)].p_TableList).joins->begin(), (yysemantic_stack_[(2) - (2)].p_TableList).joins->end());
	(yyval.p_TableList).exprs = (yysemantic_stack_[(2) - (2)].p_TableList).exprs;
	delete (yysemantic_stack_[(2) - (2)].p_TableList).joins;
}
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 890 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_bool) = false;
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 893 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_bool) = false;
      }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 896 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_bool) = true;
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 902 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 908 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 911 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(1) - (1)].p_Expression);
      }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 917 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(4) - (3)].p_tableAlias).relation != NULL) {
	    (yyval.p_JoinExpression).join = new sql::TableJoin(*(yysemantic_stack_[(4) - (3)].p_tableAlias).relation, *(yysemantic_stack_[(4) - (3)].p_tableAlias).alias, (yysemantic_stack_[(4) - (1)].p_bool));
	    delete (yysemantic_stack_[(4) - (3)].p_tableAlias).relation;
	} else {
	    (yyval.p_JoinExpression).join = new sql::SubqueryJoin((yysemantic_stack_[(4) - (3)].p_tableAlias).subselect, *(yysemantic_stack_[(4) - (3)].p_tableAlias).alias, (yysemantic_stack_[(4) - (1)].p_bool));
	}
	delete (yysemantic_stack_[(4) - (3)].p_tableAlias).alias;
	(yyval.p_JoinExpression).expr = (yysemantic_stack_[(4) - (4)].p_Expression);
}
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 930 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TableList).joins = new std::vector<sql::Join*>();
	(yyval.p_TableList).exprs = new std::vector<const sql::Expression*>();
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 934 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TableList).joins->push_back((yysemantic_stack_[(2) - (2)].p_JoinExpression).join);
	if ((yysemantic_stack_[(2) - (2)].p_JoinExpression).expr != NULL)
	    (yysemantic_stack_[(2) - (1)].p_TableList).exprs->push_back((yysemantic_stack_[(2) - (2)].p_JoinExpression).expr);
	(yyval.p_TableList) = (yysemantic_stack_[(2) - (1)].p_TableList);
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 943 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_tableAlias).relation = new sql::RelationName(*(yysemantic_stack_[(2) - (1)].p_NAME));
	(yyval.p_tableAlias).subselect = NULL;
	if ((yysemantic_stack_[(2) - (2)].p_NAME)) {
	    (yyval.p_tableAlias).alias = new sql::RelVar(*(yysemantic_stack_[(2) - (2)].p_NAME));
	    delete (yysemantic_stack_[(2) - (2)].p_NAME);
	} else {
	    (yyval.p_tableAlias).alias = new sql::RelVar(*(yysemantic_stack_[(2) - (1)].p_NAME));
	}
	delete (yysemantic_stack_[(2) - (1)].p_NAME);
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 954 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_tableAlias).relation = NULL;
	(yyval.p_tableAlias).subselect = (yysemantic_stack_[(5) - (2)].p_Select);
	(yyval.p_tableAlias).alias = new sql::RelVar(*(yysemantic_stack_[(5) - (5)].p_NAME));
	delete (yysemantic_stack_[(5) - (5)].p_NAME);
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 963 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = (yysemantic_stack_[(2) - (2)].p_NAME);
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 969 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = NULL;
    }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 972 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = (yysemantic_stack_[(1) - (1)].p_NAME);
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 978 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::HomologConstraint("CONCAT", (yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 989 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 995 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 998 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 1006 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::DisjunctionConstraint((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 1018 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 1025 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 1028 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1036 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::ConjunctionConstraint((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 1048 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 1055 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1058 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 1070 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_BooleanComparator)) {
	    if (dynamic_cast<sql::IsNotNullProxy*>((yysemantic_stack_[(2) - (2)].p_BooleanComparator)) != NULL) {
		delete (yysemantic_stack_[(2) - (2)].p_BooleanComparator);
		(yyval.p_Expression) = new sql::NegationConstraint(new sql::NotNullConstraint(dynamic_cast<const sql::Expression*>((yysemantic_stack_[(2) - (1)].p_Expression)))); // new sql::IsNullConstraint();
	    } else if (dynamic_cast<sql::IsNullProxy*>((yysemantic_stack_[(2) - (2)].p_BooleanComparator)) != NULL) {
		delete (yysemantic_stack_[(2) - (2)].p_BooleanComparator);
		(yyval.p_Expression) = new sql::NotNullConstraint(dynamic_cast<const sql::Expression*>((yysemantic_stack_[(2) - (1)].p_Expression)));
	    } else {
		(yysemantic_stack_[(2) - (2)].p_BooleanComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
		(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_BooleanComparator); // !!!
	    }
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 1089 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = NULL;
    }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 1097 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 1100 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 1103 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 1106 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 1109 "lib/SQLParser/SQLParser.ypp"
    {
        (yyval.p_BooleanComparator) = new sql::BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 1112 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 1115 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_BooleanComparator) = new sql::IsNullProxy;
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 1118 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_BooleanComparator) = new sql::IsNotNullProxy;
}
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 1129 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::ArithmeticSum((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 1141 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 1144 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 1153 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 1156 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 1164 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::ArithmeticProduct((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 1176 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 1179 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 1186 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 1189 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 1196 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 1199 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1202 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 1215 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::IsNullConstraint();
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 1221 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 1227 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(5) - (4)].p_Expressions)->insert((yysemantic_stack_[(5) - (4)].p_Expressions)->begin(), (yysemantic_stack_[(5) - (3)].p_Expression));
	(yyval.p_Expression) = new sql::HomologConstraint("CONCAT", (yysemantic_stack_[(5) - (4)].p_Expressions)->begin(), (yysemantic_stack_[(5) - (4)].p_Expressions)->end());
	delete (yysemantic_stack_[(5) - (4)].p_Expressions);
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 1232 "lib/SQLParser/SQLParser.ypp"
    {
	std::vector<const sql::Expression*> v;
	v.push_back((yysemantic_stack_[(4) - (3)].p_Expression));
	(yyval.p_Expression) = new sql::HomologConstraint("LCASE", v.begin(), v.end());
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 1237 "lib/SQLParser/SQLParser.ypp"
    {
	std::vector<const sql::Expression*> v;
	v.push_back((yysemantic_stack_[(4) - (3)].p_Expression));
	(yyval.p_Expression) = new sql::HomologConstraint("UCASE", v.begin(), v.end());
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 1242 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::RegexConstraint((yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression));
    }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 1248 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 1254 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 1257 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 1293 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::LiteralConstraint(*(yysemantic_stack_[(1) - (1)].p_NAME));
	delete (yysemantic_stack_[(1) - (1)].p_NAME);
    }
    break;



/* Line 678 of lalr1.cc  */
#line 1839 "lib/SQLParser/SQLParser.cpp"
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
  SQLParser::yysyntax_error_ (int yystate, int tok)
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
  const short int SQLParser::yypact_ninf_ = -237;
  const short int
  SQLParser::yypact_[] =
  {
        37,    -1,   -49,   -28,   -31,   -27,   -16,    49,  -237,  -237,
    -237,  -237,  -237,    29,  -237,  -237,  -237,   122,   122,   122,
      20,    34,    94,   104,    36,    96,  -237,   137,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,   154,
    -237,  -237,  -237,   162,    15,  -237,  -237,  -237,  -237,   170,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,   -12,   -12,  -237,   -12,    92,  -237,   163,  -237,
    -237,   173,  -237,  -237,  -237,    36,    36,    36,    36,   178,
     -37,  -237,    46,   180,    60,  -237,    60,  -237,  -237,   218,
     219,   217,    93,    36,    36,    36,    36,    36,    36,  -237,
    -237,   132,     7,  -237,  -237,   188,  -237,    98,   164,  -237,
     -12,    64,  -237,  -237,   234,  -237,  -237,   189,   191,   192,
    -237,   234,    15,   236,  -237,   215,   152,  -237,   225,    36,
    -237,  -237,  -237,  -237,  -237,    36,  -237,    36,  -237,    36,
    -237,   223,  -237,  -237,  -237,  -237,  -237,  -237,  -237,    36,
      36,  -237,  -237,  -237,    36,    36,  -237,    60,    23,  -237,
     199,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,    77,
    -237,  -237,    36,   200,   -12,  -237,  -237,    36,  -237,  -237,
      35,   160,  -237,   161,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,   206,  -237,  -237,   -29,
    -237,    36,  -237,   207,   247,  -237,  -237,  -237,   245,  -237,
     244,  -237,  -237,  -237,   119,    88,  -237,   209,    60,   211,
    -237,  -237,   208,  -237,  -237,  -237,   -12,  -237,   -37,  -237,
      60,  -237,  -237,   214,  -237,  -237,  -237,  -237,   222,  -237,
      60,  -237,   188,   123,   226,   210,  -237,   262,  -237,    88,
     143,   206,  -237,   188,  -237,  -237,  -237,   -29,  -237,   188,
    -237,  -237,  -237,   195,  -237,  -237,  -237,  -237,  -237,  -237,
     -46,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,   231,
     -18,  -237,    36,  -237,  -237,   272,  -237,    88,  -237,  -237,
    -237,   -26,  -237,   232,  -237,   201,  -237,  -237,  -237,  -237,
     198,  -237,  -237,  -237,  -237,   -46,  -237,   210,  -237,  -237,
    -237,  -237,   260,   -12,  -237,   100,   242,  -237,   243,   212,
    -237,  -237,   188,   270,  -237,    88,   -12,   246,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,   188,  -237,  -237
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  SQLParser::yydefact_[] =
  {
         0,     0,     0,     0,     0,     0,     0,     0,     7,    11,
      12,     9,    10,     4,   110,   127,   205,     0,     0,     0,
       0,     0,     0,     0,     0,   139,   228,   140,   217,   220,
     223,   218,   221,   224,   219,   222,   225,   226,   227,   117,
     129,   204,   138,     0,   135,   160,   164,   168,   170,   172,
     182,   188,   193,   198,   199,   200,   202,   214,   215,   216,
     203,   201,     0,     0,    18,     0,    15,     1,     4,     5,
       2,   108,   196,   197,   195,     0,     0,     0,     0,     0,
       0,   118,   121,   126,     0,   133,     0,   136,   131,   158,
     162,   166,     0,     0,     0,     0,     0,     0,     0,   171,
     173,   183,   190,   141,   142,    31,    23,    21,     0,    16,
       0,     5,     3,     8,     0,   111,   212,     0,     0,     0,
     206,     0,   156,   114,   151,     0,     0,   122,   124,     0,
     130,   139,   140,   137,   134,     0,   161,     0,   165,     0,
     169,     0,   180,   174,   175,   176,   177,   178,   179,     0,
       0,   189,   186,   187,     0,     0,   194,     0,     0,    32,
       0,    20,    19,    22,    17,    14,    13,     6,   109,     0,
     208,   209,     0,     0,     0,   157,   153,     0,   115,   116,
     143,     0,   119,     0,   125,   112,   128,   159,   163,   167,
     181,   184,   185,   191,   192,   102,     0,    30,    37,    53,
     207,     0,   213,     0,     0,   155,   113,   144,     0,   145,
       0,   152,   120,   123,     0,     0,    34,    55,     0,     0,
      26,    54,     0,    44,   211,   210,     0,   146,     0,   100,
       0,   103,    95,     0,   106,    97,    98,    96,    36,    56,
      57,    52,     0,     0,     0,    80,   154,   148,   101,     0,
       0,     0,    35,     0,    58,    48,    28,    53,    27,     0,
      88,    64,    89,     0,    71,    72,    75,    78,    77,    74,
      86,    79,    68,    76,    70,    81,    67,    66,    45,    61,
       0,    69,     0,   149,   150,     0,   104,     0,   107,    33,
      49,    24,    25,     0,    73,     0,    84,    87,    65,    50,
       0,    62,    59,    83,    82,    86,   147,    80,   105,    40,
      39,    29,    42,     0,    85,    46,     0,    63,     0,     0,
      43,    38,     0,     0,    93,     0,     0,     0,    51,    60,
      99,    41,    47,    92,    91,     0,    90,    94
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SQLParser::yypgoto_[] =
  {
      -237,  -237,   227,  -237,  -237,   183,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,    39,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,   -10,  -237,  -237,  -237,  -237,  -237,
    -237,    -5,  -237,  -237,  -236,  -232,  -237,  -237,    50,  -237,
    -237,  -101,  -237,  -237,   190,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,   174,   184,  -237,  -237,
    -237,   -79,   -62,  -237,  -237,  -237,  -237,  -237,  -237,    74,
    -237,  -237,   -22,  -237,  -237,   172,  -237,  -237,   168,  -237,
    -237,   169,  -237,  -237,  -237,   107,  -237,  -237,  -237,    57,
    -237,  -237,    58,    90,  -237,  -237,  -237,  -237,  -211,  -237,
     213,   216,  -207,  -206
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SQLParser::yydefgoto_[] =
  {
        -1,     7,    70,   113,    68,     8,     9,   109,   110,    10,
     163,   164,    11,   160,   258,   243,   291,    12,   158,   252,
     238,   197,   311,   312,   320,   321,   220,   245,   299,   315,
     221,   222,   240,   253,   278,   301,   302,   279,   280,   305,
     297,   298,   281,   328,   234,   159,   231,   214,   216,   288,
     250,    13,   115,    71,    14,   178,   179,    81,    82,   127,
     128,   184,   185,    39,   130,    83,    40,    86,    87,    88,
      41,    42,    43,   123,   210,   283,   284,   211,   180,   124,
     175,   176,    44,   136,    89,    45,   138,    90,    46,   140,
      91,    47,    48,    99,   100,    49,    50,   151,   101,    51,
     156,   102,    52,    53,    54,    55,   202,   169,    56,    57,
      58,    59,    60,    61
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int SQLParser::yytable_ninf_ = -143;
  const short int
  SQLParser::yytable_[] =
  {
       105,   106,    79,   107,   235,   133,    15,   134,   236,   237,
     255,   121,   217,   285,   154,   218,    62,   309,   122,    63,
     173,   290,    16,    85,   295,   219,     1,   293,   296,    17,
      18,    66,    19,    20,    21,    22,    23,    64,   235,   155,
       1,    65,   236,   237,   303,   207,   208,    24,   166,    67,
     103,   308,   104,   116,   117,   118,   119,   198,   131,    16,
     132,   310,   196,   304,   125,   126,    17,    18,    75,    19,
      20,    21,    22,    23,    69,   103,   235,   104,   195,     2,
     236,   237,    76,     3,    24,   209,    25,    26,    27,   334,
     332,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,  -132,   337,  -132,  -141,     2,    72,    73,    74,
       3,   232,   205,     4,   235,   141,   142,     5,   236,   237,
     223,     6,   323,    25,    26,    27,   200,   201,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,   241,
       4,   324,    77,   325,     5,    16,  -142,   131,     6,   132,
     203,   248,    78,   326,   327,   206,    20,    21,    22,    23,
      80,   254,   149,   150,   246,   161,   122,   162,   229,   230,
      24,    84,   256,   257,   233,   108,    26,   114,   223,   224,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    92,   286,   287,    93,    94,    95,    96,    97,    98,
     143,   144,   145,   146,   147,   148,   191,   192,   111,    25,
      26,    27,   193,   194,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    29,    30,   120,    32,    33,
     129,    35,    36,   135,   139,   137,   157,     1,   170,   165,
     171,   177,   172,   181,   182,   183,   190,   199,   260,   204,
     261,   322,   212,   213,   215,   226,   225,   227,   228,   244,
     306,   239,   249,   242,   335,   262,   263,   264,   265,   266,
     267,   268,   251,   269,   270,   282,   271,   294,   259,   300,
     307,   272,   273,   274,   319,   313,   314,   275,   276,   277,
     316,   329,   330,   333,   167,   112,   292,   318,   336,   331,
     317,   289,   247,   186,   168,   188,   174,   187,   189,     0,
       0,     0,     0,     0,   152,     0,     0,   153
  };

  /* YYCHECK.  */
  const short int
  SQLParser::yycheck_[] =
  {
        62,    63,    24,    65,   215,    84,     7,    86,   215,   215,
     242,    48,    41,   249,     7,    44,    65,    43,    80,    47,
     121,   253,    23,     8,    70,    54,     3,   259,    74,    30,
      31,    47,    33,    34,    35,    36,    37,    68,   249,    32,
       3,    68,   249,   249,    62,    10,    11,    48,   110,     0,
      87,   287,    89,    75,    76,    77,    78,   158,    87,    23,
      89,    87,    39,    81,    18,    19,    30,    31,    48,    33,
      34,    35,    36,    37,    45,    87,   287,    89,   157,    42,
     287,   287,    48,    46,    48,    50,    87,    88,    89,   325,
     322,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    87,   335,    89,     9,    42,    17,    18,    19,
      46,    23,   174,    76,   325,    22,    23,    80,   325,   325,
     199,    84,    22,    87,    88,    89,    49,    50,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   218,
      76,    41,    48,    43,    80,    23,     9,    87,    84,    89,
     172,   230,    48,    53,    54,   177,    34,    35,    36,    37,
       6,   240,    30,    31,   226,    67,   228,    69,    49,    50,
      48,     9,    49,    50,    86,    83,    88,     4,   257,   201,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    21,    49,    50,    24,    25,    26,    27,    28,    29,
      93,    94,    95,    96,    97,    98,   149,   150,    45,    87,
      88,    89,   154,   155,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,    93,    94,    49,    96,    97,
      50,    99,   100,    15,    17,    16,    48,     3,    49,    75,
      49,     5,    50,    28,    92,    20,    23,    48,    38,    49,
      40,   313,    92,    92,    48,     8,    49,    12,    14,    51,
     282,    52,    48,    52,   326,    55,    56,    57,    58,    59,
      60,    61,    50,    63,    64,    13,    66,    82,    52,    48,
       8,    71,    72,    73,    24,    53,    85,    77,    78,    79,
      92,    49,    49,    23,   111,    68,   257,   307,    52,    87,
     305,   251,   228,   129,   114,   137,   122,   135,   139,    -1,
      -1,    -1,    -1,    -1,   101,    -1,    -1,   101
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  SQLParser::yystos_[] =
  {
         0,     3,    42,    46,    76,    80,    84,   104,   108,   109,
     112,   115,   120,   154,   157,     7,    23,    30,    31,    33,
      34,    35,    36,    37,    48,    87,    88,    89,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   166,
     169,   173,   174,   175,   185,   188,   191,   194,   195,   198,
     199,   202,   205,   206,   207,   208,   211,   212,   213,   214,
     215,   216,    65,    47,    68,    68,    47,     0,   107,    45,
     105,   156,   206,   206,   206,    48,    48,    48,    48,   185,
       6,   160,   161,   168,     9,     8,   170,   171,   172,   187,
     190,   193,    21,    24,    25,    26,    27,    28,    29,   196,
     197,   201,   204,    87,    89,   175,   175,   175,    83,   110,
     111,    45,   105,   106,     4,   155,   185,   185,   185,   185,
      49,    48,   175,   176,   182,    18,    19,   162,   163,    50,
     167,    87,    89,   174,   174,    15,   186,    16,   189,    17,
     192,    22,    23,   198,   198,   198,   198,   198,   198,    30,
      31,   200,   213,   214,     7,    32,   203,    48,   121,   148,
     116,    67,    69,   113,   114,    75,   175,   108,   157,   210,
      49,    49,    50,   154,   170,   183,   184,     5,   158,   159,
     181,    28,    92,    20,   164,   165,   169,   188,   191,   194,
      23,   202,   202,   205,   205,   174,    39,   124,   154,    48,
      49,    50,   209,   185,    49,   175,   185,    10,    11,    50,
     177,   180,    92,    92,   150,    48,   151,    41,    44,    54,
     129,   133,   134,   174,   185,    49,     8,    12,    14,    49,
      50,   149,    23,    86,   147,   211,   215,   216,   123,    52,
     135,   174,    52,   118,    51,   130,   175,   182,   174,    48,
     153,    50,   122,   136,   174,   148,    49,    50,   117,    52,
      38,    40,    55,    56,    57,    58,    59,    60,    61,    63,
      64,    66,    71,    72,    73,    77,    78,    79,   137,   140,
     141,   145,    13,   178,   179,   147,    49,    50,   152,   151,
     148,   119,   129,   148,    82,    70,    74,   143,   144,   131,
      48,   138,   139,    62,    81,   142,   185,     8,   147,    43,
      87,   125,   126,    53,    85,   132,    92,   144,   137,    24,
     127,   128,   175,    22,    41,    43,    53,    54,   146,    49,
      49,    87,   148,    23,   147,   175,    52,   148
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  SQLParser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  SQLParser::yyr1_[] =
  {
         0,   103,   104,   104,   105,   105,   106,   107,   107,   108,
     108,   108,   108,   109,   110,   111,   111,   112,   112,   113,
     113,   114,   114,   116,   115,   117,   118,   118,   119,   119,
     120,   121,   121,   122,   123,   123,   124,   124,   125,   126,
     126,   127,   128,   128,   130,   131,   129,   129,   129,   129,
     132,   132,   133,   134,   134,   135,   135,   136,   136,   137,
     138,   139,   139,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     141,   141,   142,   142,   143,   143,   144,   144,   145,   145,
     146,   146,   146,   146,   146,   147,   147,   147,   147,   147,
     148,   149,   150,   150,   151,   152,   153,   153,   154,   155,
     156,   156,   157,   158,   159,   159,   160,   161,   161,   162,
     162,   163,   163,   164,   165,   165,   166,   166,   167,   168,
     168,   169,   170,   170,   171,   172,   172,   173,   173,   174,
     174,   175,   175,   176,   177,   177,   177,   178,   179,   179,
     180,   181,   181,   182,   182,   183,   184,   184,   185,   186,
     187,   187,   188,   189,   190,   190,   191,   192,   193,   193,
     194,   195,   196,   196,   197,   197,   197,   197,   197,   197,
     197,   197,   198,   199,   200,   200,   200,   200,   201,   201,
     202,   203,   203,   204,   204,   205,   205,   205,   205,   206,
     206,   206,   206,   206,   206,   206,   207,   208,   208,   208,
     208,   209,   210,   210,   211,   211,   211,   212,   212,   212,
     213,   213,   213,   214,   214,   214,   215,   215,   216
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  SQLParser::yyr2_[] =
  {
         0,     2,     2,     3,     0,     1,     2,     0,     2,     1,
       1,     1,     1,     4,     2,     0,     1,     4,     2,     1,
       1,     0,     1,     0,     9,     2,     0,     2,     0,     2,
       5,     0,     1,     2,     0,     2,     3,     1,     2,     1,
       1,     2,     0,     1,     0,     0,     5,     7,     3,     4,
       0,     2,     2,     0,     1,     0,     1,     0,     1,     2,
       3,     0,     1,     3,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       0,     1,     1,     1,     1,     2,     0,     1,     1,     1,
       2,     2,     2,     1,     3,     1,     1,     1,     1,     6,
       4,     2,     0,     2,     4,     2,     0,     2,     2,     2,
       0,     2,     5,     2,     0,     1,     3,     0,     1,     2,
       3,     0,     1,     2,     0,     1,     2,     1,     2,     0,
       2,     2,     0,     1,     2,     0,     1,     3,     1,     1,
       1,     1,     1,     2,     1,     1,     2,     2,     0,     1,
       4,     0,     2,     2,     5,     2,     0,     1,     2,     2,
       0,     2,     2,     2,     0,     2,     2,     2,     0,     2,
       1,     2,     0,     1,     2,     2,     2,     2,     2,     2,
       2,     3,     1,     2,     2,     2,     1,     1,     0,     2,
       2,     2,     2,     0,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     5,     4,     4,
       6,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const SQLParser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "IT_SELECT", "IT_UNION",
  "IT_WHERE", "IT_FROM", "GT_TIMES", "IT_AS", "GT_DOT", "IT_INNER",
  "IT_LEFT", "IT_OUTER", "IT_ON", "IT_JOIN", "GT_OR", "IT_OR", "IT_AND",
  "IT_ROWNUM", "IT_LIMIT", "IT_OFFSET", "IT_IS", "IT_NOT", "IT_NULL",
  "GT_EQUAL", "GT_NEQUAL", "GT_LT", "GT_GT", "GT_LE", "GT_GE", "GT_PLUS",
  "GT_MINUS", "GT_DIVIDE", "GT_NOT", "IT_CONCAT", "IT_LCASE", "IT_UCASE",
  "IT_REGEX", "IT_INTEGER", "IT_VALUES", "IT_VARCHAR", "IT_UNIQUE",
  "IT_INSERT", "IT_DEFAULT", "IT_CONSTRAINT", "GT_SEMI", "IT_CREATE",
  "IT_TABLE", "GT_LPAREN", "GT_RPAREN", "GT_COMMA", "IT_FOREIGN", "IT_KEY",
  "IT_REFERENCES", "IT_PRIMARY", "IT_INT", "IT_DOUBLE", "IT_FLOAT",
  "IT_REAL", "IT_DATE", "IT_DATETIME", "IT_TIMESTAMP", "IT_CHAR",
  "IT_BOOLEAN", "IT_BINARY", "IT_INTO", "IT_INTERVAL", "IT_WRITE",
  "IT_TABLES", "IT_READ", "IT_LARGE", "IT_SMALLINT", "IT_TIME",
  "IT_BIGINT", "IT_VARYING", "IT_EXISTS", "IT_UNLOCK", "IT_NATIONAL",
  "IT_DECIMAL", "IT_NUMERIC", "IT_LOCK", "IT_CHARACTER", "IT_PRECISION",
  "IT_IF", "IT_DROP", "IT_OBJECT", "IT_CAST", "NAME", "STRING_LITERAL1",
  "STRING_LITERAL2", "STRING_LITERAL_LONG1", "STRING_LITERAL_LONG2",
  "INTEGER", "INTEGER_POSITIVE", "INTEGER_NEGATIVE", "DECIMAL",
  "DECIMAL_POSITIVE", "DECIMAL_NEGATIVE", "DOUBLE", "DOUBLE_POSITIVE",
  "DOUBLE_NEGATIVE", "IT_TRUE", "IT_FALSE", "$accept", "Statement",
  "_QGT_SEMI_E_Opt", "_O_QGT_SEMI_E_S_QChange_E_C",
  "_Q_O_QGT_SEMI_E_S_QChange_E_C_E_Star", "Change", "Drop",
  "_O_QIT_IF_E_S_QIT_EXISTS_E_C", "_Q_O_QIT_IF_E_S_QIT_EXISTS_E_C_E_Opt",
  "Lock", "_O_QIT_READ_E_Or_QIT_WRITE_E_C",
  "_Q_O_QIT_READ_E_Or_QIT_WRITE_E_C_E_Opt", "Create", "$@1",
  "_O_QGT_COMMA_E_S_QFieldOrKey_E_C",
  "_Q_O_QGT_COMMA_E_S_QFieldOrKey_E_C_E_Star", "_QParam_E_Star", "Insert",
  "_QAttrList_E_Opt", "_O_QGT_COMMA_E_S_QConstList_E_C",
  "_Q_O_QGT_COMMA_E_S_QConstList_E_C_E_Star",
  "_O_QIT_VALUES_E_S_QConstList_E_S_QGT_COMMA_E_S_QConstList_E_Star_Or_QSelectUnion_E_C",
  "Param", "_O_QNAME_E_Or_QIT_DEFAULT_E_C", "_O_QGT_EQUAL_E_S_QNAME_E_C",
  "_Q_O_QGT_EQUAL_E_S_QNAME_E_C_E_Opt", "FieldOrKey", "$@2", "$@3",
  "_QLinkDetails_E_Star", "_O_QIT_CONSTRAINT_E_S_QAttribute_E_C",
  "_Q_O_QIT_CONSTRAINT_E_S_QAttribute_E_C_E_Opt", "_QIT_KEY_E_Opt",
  "_QAttribute_E_Opt", "Sized",
  "_O_QGT_LPAREN_E_S_QINTEGER_E_S_QGT_RPAREN_E_C",
  "_Q_O_QGT_LPAREN_E_S_QINTEGER_E_S_QGT_RPAREN_E_C_E_Opt", "Type",
  "_QIT_NATIONAL_E_Opt", "_O_QIT_CHARACTER_E_Or_QIT_CHAR_E_C",
  "_O_QIT_VARYING_E_Or_QIT_LARGE_E_S_QIT_OBJECT_E_C",
  "_Q_O_QIT_VARYING_E_Or_QIT_LARGE_E_S_QIT_OBJECT_E_C_E_Opt",
  "_O_QIT_INTEGER_E_Or_QIT_INT_E_C", "LinkDetails", "Constant", "AttrList",
  "_O_QGT_COMMA_E_S_QAttribute_E_C",
  "_Q_O_QGT_COMMA_E_S_QAttribute_E_C_E_Star", "ConstList",
  "_O_QGT_COMMA_E_S_QConstant_E_C",
  "_Q_O_QGT_COMMA_E_S_QConstant_E_C_E_Star", "SelectUnion",
  "_O_QIT_UNION_E_S_QSelect_E_C", "_Q_O_QIT_UNION_E_S_QSelect_E_C_E_Star",
  "Select", "_O_QIT_WHERE_E_S_QExpression_E_C",
  "_Q_O_QIT_WHERE_E_S_QExpression_E_C_E_Opt",
  "_O_QIT_FROM_E_S_QTableList_E_S_QIT_WHERE_E_S_QExpression_E_Opt_C",
  "_Q_O_QIT_FROM_E_S_QTableList_E_S_QIT_WHERE_E_S_QExpression_E_Opt_C_E_Opt",
  "_O_QIT_LIMIT_E_S_QINTEGER_E_Or_QIT_ROWNUM_E_S_QGT_LE_E_S_QINTEGER_E_C",
  "_Q_O_QIT_LIMIT_E_S_QINTEGER_E_Or_QIT_ROWNUM_E_S_QGT_LE_E_S_QINTEGER_E_C_E_Opt",
  "_O_QIT_OFFSET_E_S_QINTEGER_E_C",
  "_Q_O_QIT_OFFSET_E_S_QINTEGER_E_C_E_Opt", "AttributeList",
  "_O_QGT_COMMA_E_S_QNamedAttribute_E_C",
  "_Q_O_QGT_COMMA_E_S_QNamedAttribute_E_C_E_Star", "NamedAttribute",
  "_QIT_AS_E_Opt", "_O_QIT_AS_E_Opt_S_QAttribute_E_C",
  "_Q_O_QIT_AS_E_Opt_S_QAttribute_E_C_E_Opt", "FQAttribute", "Attribute",
  "Relation", "TableList",
  "_O_QIT_INNER_E_Or_QGT_COMMA_E_Or_QIT_LEFT_E_S_QIT_OUTER_E_C",
  "_O_QIT_ON_E_S_QExpression_E_C", "_Q_O_QIT_ON_E_S_QExpression_E_C_E_Opt",
  "_O_QIT_INNER_E_Or_QGT_COMMA_E_Or_QIT_LEFT_E_S_QIT_OUTER_E_S_QIT_JOIN_E_S_QTableAlias_E_S_QIT_ON_E_S_QExpression_E_Opt_C",
  "_Q_O_QIT_INNER_E_Or_QGT_COMMA_E_Or_QIT_LEFT_E_S_QIT_OUTER_E_S_QIT_JOIN_E_S_QTableAlias_E_S_QIT_ON_E_S_QExpression_E_Opt_C_E_Star",
  "TableAlias", "_O_QIT_AS_E_Opt_S_QRelation_E_C",
  "_Q_O_QIT_AS_E_Opt_S_QRelation_E_C_E_Opt", "Expression",
  "_O_QGT_OR_E_S_QConditionalOrExpression_E_C",
  "_Q_O_QGT_OR_E_S_QConditionalOrExpression_E_C_E_Star",
  "ConditionalOrExpression", "_O_QIT_OR_E_S_QConditionalAndExpression_E_C",
  "_Q_O_QIT_OR_E_S_QConditionalAndExpression_E_C_E_Star",
  "ConditionalAndExpression", "_O_QIT_AND_E_S_QValueLogical_E_C",
  "_Q_O_QIT_AND_E_S_QValueLogical_E_C_E_Star", "ValueLogical",
  "RelationalExpression", "_QRightRelationalExpression_E_Opt",
  "RightRelationalExpression", "NumericExpression", "AdditiveExpression",
  "_O_QGT_PLUS_E_S_QMultiplicativeExpression_E_Or_QGT_MINUS_E_S_QMultiplicativeExpression_E_Or_QNumericLiteralPositive_E_Or_QNumericLiteralNegative_E_C",
  "_Q_O_QGT_PLUS_E_S_QMultiplicativeExpression_E_Or_QGT_MINUS_E_S_QMultiplicativeExpression_E_Or_QNumericLiteralPositive_E_Or_QNumericLiteralNegative_E_C_E_Star",
  "MultiplicativeExpression",
  "_O_QGT_TIMES_E_S_QUnaryExpression_E_Or_QGT_DIVIDE_E_S_QUnaryExpression_E_C",
  "_Q_O_QGT_TIMES_E_S_QUnaryExpression_E_Or_QGT_DIVIDE_E_S_QUnaryExpression_E_C_E_Star",
  "UnaryExpression", "PrimaryExpression", "BrackettedExpression",
  "BuiltInCall", "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "NumericLiteral",
  "NumericLiteralUnsigned", "NumericLiteralPositive",
  "NumericLiteralNegative", "BooleanLiteral", "String", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const SQLParser::rhs_number_type
  SQLParser::yyrhs_[] =
  {
       104,     0,    -1,   154,   105,    -1,   108,   107,   105,    -1,
      -1,    45,    -1,    45,   108,    -1,    -1,   107,   106,    -1,
     115,    -1,   120,    -1,   109,    -1,   112,    -1,    84,    47,
     111,   175,    -1,    83,    75,    -1,    -1,   110,    -1,    80,
      68,   175,   114,    -1,    76,    68,    -1,    69,    -1,    67,
      -1,    -1,   113,    -1,    -1,    46,    47,   175,   116,    48,
     129,   118,    49,   119,    -1,    50,   129,    -1,    -1,   118,
     117,    -1,    -1,   119,   125,    -1,    42,    65,   175,   121,
     124,    -1,    -1,   148,    -1,    50,   151,    -1,    -1,   123,
     122,    -1,    39,   151,   123,    -1,   154,    -1,   126,   128,
      -1,    87,    -1,    43,    -1,    24,    87,    -1,    -1,   127,
      -1,    -1,    -1,   174,   130,   137,   131,   132,    -1,   134,
      51,    52,   148,    53,   175,   148,    -1,    54,    52,   148,
      -1,    41,   135,   136,   148,    -1,    -1,   132,   146,    -1,
      44,   174,    -1,    -1,   133,    -1,    -1,    52,    -1,    -1,
     174,    -1,   140,   139,    -1,    48,    92,    49,    -1,    -1,
     138,    -1,   141,   142,   144,    -1,    40,    -1,    64,   144,
      -1,    79,    -1,    78,    -1,    71,    -1,   145,    -1,    73,
      -1,    57,    -1,    58,    -1,    56,    82,    -1,    63,    -1,
      59,    -1,    72,    -1,    61,    -1,    60,    -1,    66,    -1,
      -1,    77,    -1,    81,    -1,    62,    -1,    74,    -1,    70,
      85,    -1,    -1,   143,    -1,    38,    -1,    55,    -1,    54,
      52,    -1,    43,   147,    -1,    22,    23,    -1,    41,    -1,
      53,   175,   148,    -1,    23,    -1,   216,    -1,   211,    -1,
     215,    -1,    86,    48,   147,     8,   137,    49,    -1,    48,
     174,   150,    49,    -1,    50,   174,    -1,    -1,   150,   149,
      -1,    48,   147,   153,    49,    -1,    50,   147,    -1,    -1,
     153,   152,    -1,   157,   156,    -1,     4,   157,    -1,    -1,
     156,   155,    -1,     3,   166,   161,   163,   165,    -1,     5,
     185,    -1,    -1,   158,    -1,     6,   176,   159,    -1,    -1,
     160,    -1,    19,    92,    -1,    18,    28,    92,    -1,    -1,
     162,    -1,    20,    92,    -1,    -1,   164,    -1,   169,   168,
      -1,     7,    -1,    50,   169,    -1,    -1,   168,   167,    -1,
     185,   172,    -1,    -1,     8,    -1,   170,   174,    -1,    -1,
     171,    -1,   175,     9,   174,    -1,   174,    -1,    87,    -1,
      89,    -1,    87,    -1,    89,    -1,   182,   181,    -1,    10,
      -1,    50,    -1,    11,    12,    -1,    13,   185,    -1,    -1,
     178,    -1,   177,    14,   182,   179,    -1,    -1,   181,   180,
      -1,   175,   184,    -1,    48,   154,    49,     8,   175,    -1,
     170,   175,    -1,    -1,   183,    -1,   188,   187,    -1,    15,
     188,    -1,    -1,   187,   186,    -1,   191,   190,    -1,    16,
     191,    -1,    -1,   190,   189,    -1,   194,   193,    -1,    17,
     194,    -1,    -1,   193,   192,    -1,   195,    -1,   198,   196,
      -1,    -1,   197,    -1,    24,   198,    -1,    25,   198,    -1,
      26,   198,    -1,    27,   198,    -1,    28,   198,    -1,    29,
     198,    -1,    21,    23,    -1,    21,    22,    23,    -1,   199,
      -1,   202,   201,    -1,    30,   202,    -1,    31,   202,    -1,
     213,    -1,   214,    -1,    -1,   201,   200,    -1,   205,   204,
      -1,     7,   205,    -1,    32,   205,    -1,    -1,   204,   203,
      -1,    33,   206,    -1,    30,   206,    -1,    31,   206,    -1,
     206,    -1,   207,    -1,   208,    -1,   216,    -1,   211,    -1,
     215,    -1,   173,    -1,    23,    -1,    48,   185,    49,    -1,
      34,    48,   185,   210,    49,    -1,    35,    48,   185,    49,
      -1,    36,    48,   185,    49,    -1,    37,    48,   185,    50,
     185,    49,    -1,    50,   185,    -1,    -1,   210,   209,    -1,
     212,    -1,   213,    -1,   214,    -1,    92,    -1,    95,    -1,
      98,    -1,    93,    -1,    96,    -1,    99,    -1,    94,    -1,
      97,    -1,   100,    -1,   101,    -1,   102,    -1,    88,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  SQLParser::yyprhs_[] =
  {
         0,     0,     3,     6,    10,    11,    13,    16,    17,    20,
      22,    24,    26,    28,    33,    36,    37,    39,    44,    47,
      49,    51,    52,    54,    55,    65,    68,    69,    72,    73,
      76,    82,    83,    85,    88,    89,    92,    96,    98,   101,
     103,   105,   108,   109,   111,   112,   113,   119,   127,   131,
     136,   137,   140,   143,   144,   146,   147,   149,   150,   152,
     155,   159,   160,   162,   166,   168,   171,   173,   175,   177,
     179,   181,   183,   185,   188,   190,   192,   194,   196,   198,
     200,   201,   203,   205,   207,   209,   212,   213,   215,   217,
     219,   222,   225,   228,   230,   234,   236,   238,   240,   242,
     249,   254,   257,   258,   261,   266,   269,   270,   273,   276,
     279,   280,   283,   289,   292,   293,   295,   299,   300,   302,
     305,   309,   310,   312,   315,   316,   318,   321,   323,   326,
     327,   330,   333,   334,   336,   339,   340,   342,   346,   348,
     350,   352,   354,   356,   359,   361,   363,   366,   369,   370,
     372,   377,   378,   381,   384,   390,   393,   394,   396,   399,
     402,   403,   406,   409,   412,   413,   416,   419,   422,   423,
     426,   428,   431,   432,   434,   437,   440,   443,   446,   449,
     452,   455,   459,   461,   464,   467,   470,   472,   474,   475,
     478,   481,   484,   487,   488,   491,   494,   497,   500,   502,
     504,   506,   508,   510,   512,   514,   516,   520,   526,   531,
     536,   543,   546,   547,   550,   552,   554,   556,   558,   560,
     562,   564,   566,   568,   570,   572,   574,   576,   578
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SQLParser::yyrline_[] =
  {
         0,   307,   307,   310,   313,   315,   319,   322,   324,   328,
     329,   330,   331,   335,   339,   342,   344,   348,   349,   353,
     354,   357,   359,   363,   363,   373,   376,   378,   381,   383,
     387,   395,   398,   402,   407,   409,   413,   416,   422,   428,
     429,   433,   436,   438,   442,   444,   442,   457,   461,   464,
     469,   471,   475,   480,   482,   485,   487,   490,   492,   496,
     503,   511,   514,   518,   521,   524,   527,   530,   533,   536,
     539,   542,   545,   548,   551,   554,   557,   560,   563,   566,
     571,   573,   577,   578,   582,   585,   591,   594,   598,   599,
     603,   606,   609,   612,   615,   625,   628,   629,   630,   631,
     637,   645,   651,   654,   662,   669,   675,   678,   685,   697,
     703,   706,   713,   730,   736,   739,   743,   752,   756,   760,
     765,   773,   776,   780,   788,   791,   795,   800,   806,   812,
     815,   822,   834,   836,   840,   846,   849,   855,   860,   867,
     868,   872,   873,   877,   890,   893,   896,   902,   908,   911,
     917,   930,   934,   943,   954,   963,   969,   972,   978,   989,
     995,   998,  1006,  1018,  1025,  1028,  1036,  1048,  1055,  1058,
    1065,  1070,  1089,  1092,  1097,  1100,  1103,  1106,  1109,  1112,
    1115,  1118,  1124,  1129,  1141,  1144,  1147,  1148,  1153,  1156,
    1164,  1176,  1179,  1186,  1189,  1196,  1199,  1202,  1205,  1209,
    1210,  1211,  1212,  1213,  1214,  1215,  1221,  1227,  1232,  1237,
    1242,  1248,  1254,  1257,  1264,  1265,  1266,  1270,  1271,  1272,
    1276,  1277,  1278,  1282,  1283,  1284,  1288,  1289,  1293
  };

  // Print the state stack on the debug stream.
  void
  SQLParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  SQLParser::yy_reduce_print_ (int yyrule)
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
  SQLParser::token_number_type
  SQLParser::yytranslate_ (int t)
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int SQLParser::yyeof_ = 0;
  const int SQLParser::yylast_ = 317;
  const int SQLParser::yynnts_ = 114;
  const int SQLParser::yyempty_ = -2;
  const int SQLParser::yyfinal_ = 67;
  const int SQLParser::yyterror_ = 1;
  const int SQLParser::yyerrcode_ = 256;
  const int SQLParser::yyntokens_ = 103;

  const unsigned int SQLParser::yyuser_token_number_max_ = 357;
  const SQLParser::token_number_type SQLParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 2675 "lib/SQLParser/SQLParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 1313 "lib/SQLParser/SQLParser.ypp"
 /*** Additional Code ***/

void w3c_sw::SQLParser::error(const SQLParser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}

/* START SQLDriver (@@ stand-alone would allow it to be shared with other parsers */

namespace w3c_sw {

SQLDriver::SQLDriver(class sqlContext& _context)
    : YaccDriver("", NULL), trace_scanning(false), trace_parsing(false),
      context(_context), root(NULL), curCreate(NULL),
      curAttributeName(NULL), curIsPrimary(false)
{
}

sql::SQLQuery* SQLDriver::parse (IStreamContext& in)
{
    streamname = in.nameStr;

    SQLScanner scanner(this, in.p);
    scanner.set_debug(trace_scanning);
    lexer = &scanner;

    SQLParser parser(*this);
    parser.set_debug_level(trace_parsing);
    parser.parse();
    return root;
}

sql::SQLQuery* SQLDriver::parse (std::string queryStr)
{
    IStreamContext in(queryStr.c_str(), IStreamContext::STRING);
    return parse(in);
}

void SQLDriver::error (const class location& l,
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
    YaccDriver::error(l, m);
}

void SQLDriver::error (const std::string& m)
{
    throw m;
}

} // namespace w3c_sw

/* END SQLDriver */

