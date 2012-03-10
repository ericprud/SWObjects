
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

  case 57:

/* Line 678 of lalr1.cc  */
#line 491 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TypeSize).type = (yysemantic_stack_[(2) - (1)].p_SchemaDatatype);
	(yyval.p_TypeSize).size = (yysemantic_stack_[(2) - (2)].p_int);
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 498 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(3) - (2)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 506 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_int) = SQL_PRECISION_unspecified;
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 513 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype) = (yysemantic_stack_[(3) - (3)].p_bool) ? sql::TYPE_varchar : sql::TYPE_char;
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 516 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype) = sql::TYPE_varchar;
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 519 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype) = sql::TYPE_binary;
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 522 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype) = sql::TYPE_int;
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 525 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype) = sql::TYPE_int;
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 528 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype) = sql::TYPE_int;
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 531 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype) = sql::TYPE_int;
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 534 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype) = sql::TYPE_int;
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 537 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::TYPE_float;
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 540 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::TYPE_real;
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 543 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::TYPE_double;
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 546 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::TYPE_boolean;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 549 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::TYPE_date;
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 552 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::TYPE_time;
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 555 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::TYPE_timestamp;
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 558 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::TYPE_datetime;
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 561 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::TYPE_interval;
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 577 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_bool) = true;
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 580 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_bool) = false;
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 586 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_bool) = false;
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 598 "lib/SQLParser/SQLParser.ypp"
    {
	driver.curIsPrimary = true;
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 601 "lib/SQLParser/SQLParser.ypp"
    {
	w3c_sw_LINEN << "ignoring DEFAULT\n";
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 604 "lib/SQLParser/SQLParser.ypp"
    {
	w3c_sw_LINEN << "ignoring NOT NULL\n";
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 607 "lib/SQLParser/SQLParser.ypp"
    {
	w3c_sw_LINEN << "ignoring UNIQUE\n";
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 610 "lib/SQLParser/SQLParser.ypp"
    {
	std::vector<sql::Attribute>* attrs = new std::vector<sql::Attribute>();
	attrs->push_back(sql::Attribute(*driver.curAttributeName));
	sql::schema::ForeignKey* fk = new sql::schema::ForeignKey(attrs, *(yysemantic_stack_[(3) - (2)].p_NAME), (yysemantic_stack_[(3) - (3)].p_Attributes));
	driver.curCreate->addForeignKey(fk);
	delete (yysemantic_stack_[(3) - (2)].p_NAME);
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 620 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::IsNullConstraint();
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 626 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::CastConstraint((yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_TypeSize).type, (yysemantic_stack_[(6) - (5)].p_TypeSize).size);
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 632 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(4) - (3)].p_Attributes)->insert((yysemantic_stack_[(4) - (3)].p_Attributes)->begin(), *(yysemantic_stack_[(4) - (2)].p_NAME));
	delete (yysemantic_stack_[(4) - (2)].p_NAME);
	(yyval.p_Attributes) = (yysemantic_stack_[(4) - (3)].p_Attributes);
}
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 640 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = (yysemantic_stack_[(2) - (2)].p_NAME);
}
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 646 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Attributes) = new std::vector<sql::Attribute>();
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 649 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Attributes)->push_back(*(yysemantic_stack_[(2) - (2)].p_NAME));
	delete (yysemantic_stack_[(2) - (2)].p_NAME);
	(yyval.p_Attributes) = (yysemantic_stack_[(2) - (1)].p_Attributes);
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 657 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(4) - (3)].p_Expressions)->insert((yysemantic_stack_[(4) - (3)].p_Expressions)->begin(), (yysemantic_stack_[(4) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(4) - (3)].p_Expressions);
}
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 664 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 670 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 673 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 680 "lib/SQLParser/SQLParser.ypp"
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

  case 107:

/* Line 678 of lalr1.cc  */
#line 692 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Select) = (yysemantic_stack_[(2) - (2)].p_Select);
}
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 698 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Selects) = new std::vector<sql::SQLQuery*>();
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 701 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Selects)->push_back((yysemantic_stack_[(2) - (2)].p_Select));
	(yyval.p_Selects) = (yysemantic_stack_[(2) - (1)].p_Selects);
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 708 "lib/SQLParser/SQLParser.ypp"
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

  case 111:

/* Line 678 of lalr1.cc  */
#line 725 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 731 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 738 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TableList).joins = (yysemantic_stack_[(3) - (2)].p_TableList).joins;
	(yyval.p_TableList).exprs = (yysemantic_stack_[(3) - (2)].p_TableList).exprs;
	if ((yysemantic_stack_[(3) - (3)].p_Expression) != NULL)
	    (yyval.p_TableList).exprs->push_back((yysemantic_stack_[(3) - (3)].p_Expression));
}
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 747 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TableList).joins = new std::vector<sql::Join*>();;
	(yyval.p_TableList).exprs = new std::vector<const sql::Expression*>();;
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 755 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 760 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(3) - (3)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(3) - (3)].p_Expression);
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 768 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_int) = -1;
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 775 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 783 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_int) = -1;
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 790 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (2)].p_AttributeList)->insert((yysemantic_stack_[(2) - (2)].p_AttributeList)->begin(), (yysemantic_stack_[(2) - (1)].p_AliasedSelect));
	(yyval.p_AttributeList) = new std::vector<sql::AliasedSelect*>((yysemantic_stack_[(2) - (2)].p_AttributeList)->begin(), (yysemantic_stack_[(2) - (2)].p_AttributeList)->end());
	delete (yysemantic_stack_[(2) - (2)].p_AttributeList);
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 795 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AttributeList) = new std::vector<sql::AliasedSelect*>();
      }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 801 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AliasedSelect) = (yysemantic_stack_[(2) - (2)].p_AliasedSelect);
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 807 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AttributeList) = new std::vector<sql::AliasedSelect*>();
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 810 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_AttributeList)->push_back((yysemantic_stack_[(2) - (2)].p_AliasedSelect));
	(yyval.p_AttributeList) = (yysemantic_stack_[(2) - (1)].p_AttributeList);
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 817 "lib/SQLParser/SQLParser.ypp"
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

  case 132:

/* Line 678 of lalr1.cc  */
#line 835 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = (yysemantic_stack_[(2) - (2)].p_NAME);
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 841 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = NULL;
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 844 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = (yysemantic_stack_[(1) - (1)].p_NAME);
      }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 850 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::AliasAttrConstraint(sql::AliasAttr(sql::RelVar(*(yysemantic_stack_[(3) - (1)].p_NAME)), sql::Attribute(*(yysemantic_stack_[(3) - (3)].p_NAME))));
	delete (yysemantic_stack_[(3) - (1)].p_NAME);
	delete (yysemantic_stack_[(3) - (3)].p_NAME);
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 855 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_Expression) = new sql::AliasAttrConstraint(sql::AliasAttr(sql::RelVar(""), sql::Attribute(*(yysemantic_stack_[(1) - (1)].p_NAME))));
	delete (yysemantic_stack_[(1) - (1)].p_NAME);
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 872 "lib/SQLParser/SQLParser.ypp"
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

  case 142:

/* Line 678 of lalr1.cc  */
#line 885 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_bool) = false;
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 888 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_bool) = false;
      }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 891 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_bool) = true;
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 897 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 903 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 906 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(1) - (1)].p_Expression);
      }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 912 "lib/SQLParser/SQLParser.ypp"
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

  case 149:

/* Line 678 of lalr1.cc  */
#line 925 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TableList).joins = new std::vector<sql::Join*>();
	(yyval.p_TableList).exprs = new std::vector<const sql::Expression*>();
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 929 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TableList).joins->push_back((yysemantic_stack_[(2) - (2)].p_JoinExpression).join);
	if ((yysemantic_stack_[(2) - (2)].p_JoinExpression).expr != NULL)
	    (yysemantic_stack_[(2) - (1)].p_TableList).exprs->push_back((yysemantic_stack_[(2) - (2)].p_JoinExpression).expr);
	(yyval.p_TableList) = (yysemantic_stack_[(2) - (1)].p_TableList);
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 938 "lib/SQLParser/SQLParser.ypp"
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

  case 152:

/* Line 678 of lalr1.cc  */
#line 949 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_tableAlias).relation = NULL;
	(yyval.p_tableAlias).subselect = (yysemantic_stack_[(5) - (2)].p_Select);
	(yyval.p_tableAlias).alias = new sql::RelVar(*(yysemantic_stack_[(5) - (5)].p_NAME));
	delete (yysemantic_stack_[(5) - (5)].p_NAME);
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 958 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = (yysemantic_stack_[(2) - (2)].p_NAME);
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 964 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = NULL;
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 967 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = (yysemantic_stack_[(1) - (1)].p_NAME);
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 973 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::HomologConstraint("CONCAT", (yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 984 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 990 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 993 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 1001 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::DisjunctionConstraint((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 1013 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 1020 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 1023 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 1031 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::ConjunctionConstraint((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 1043 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1050 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 1053 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1065 "lib/SQLParser/SQLParser.ypp"
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

  case 170:

/* Line 678 of lalr1.cc  */
#line 1084 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = NULL;
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 1092 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 1095 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 1098 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 1101 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 1104 "lib/SQLParser/SQLParser.ypp"
    {
        (yyval.p_BooleanComparator) = new sql::BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 1107 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 1110 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_BooleanComparator) = new sql::IsNullProxy;
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 1113 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_BooleanComparator) = new sql::IsNotNullProxy;
}
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 1124 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::ArithmeticSum((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 1136 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 1139 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 1148 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 1151 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 1159 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::ArithmeticProduct((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 1171 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 1174 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 1181 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 1184 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 1191 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 1194 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 1197 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 1210 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::IsNullConstraint();
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 1216 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 1222 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(5) - (4)].p_Expressions)->insert((yysemantic_stack_[(5) - (4)].p_Expressions)->begin(), (yysemantic_stack_[(5) - (3)].p_Expression));
	(yyval.p_Expression) = new sql::HomologConstraint("CONCAT", (yysemantic_stack_[(5) - (4)].p_Expressions)->begin(), (yysemantic_stack_[(5) - (4)].p_Expressions)->end());
	delete (yysemantic_stack_[(5) - (4)].p_Expressions);
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 1227 "lib/SQLParser/SQLParser.ypp"
    {
	std::vector<const sql::Expression*> v;
	v.push_back((yysemantic_stack_[(4) - (3)].p_Expression));
	(yyval.p_Expression) = new sql::HomologConstraint("LCASE", v.begin(), v.end());
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 1232 "lib/SQLParser/SQLParser.ypp"
    {
	std::vector<const sql::Expression*> v;
	v.push_back((yysemantic_stack_[(4) - (3)].p_Expression));
	(yyval.p_Expression) = new sql::HomologConstraint("UCASE", v.begin(), v.end());
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 1237 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::RegexConstraint((yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression));
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 1243 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 1249 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 1252 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 1288 "lib/SQLParser/SQLParser.ypp"
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
  const short int SQLParser::yypact_ninf_ = -241;
  const short int
  SQLParser::yypact_[] =
  {
        16,    95,   -31,     0,   -19,   -16,    14,    65,  -241,  -241,
    -241,  -241,  -241,    30,  -241,  -241,  -241,   137,   137,   137,
      51,    53,    56,    57,   111,    97,  -241,    98,  -241,  -241,
    -241,  -241,  -241,  -241,  -241,  -241,  -241,  -241,  -241,   103,
    -241,  -241,  -241,   102,     4,  -241,  -241,  -241,  -241,   219,
    -241,  -241,  -241,  -241,  -241,  -241,  -241,  -241,  -241,  -241,
    -241,  -241,   -66,   -66,  -241,   -66,    32,  -241,    68,  -241,
    -241,   118,  -241,  -241,  -241,   111,   111,   111,   111,    74,
     -23,  -241,    25,    77,   -52,  -241,   -52,  -241,  -241,   109,
     117,   119,    46,   111,   111,   111,   111,   111,   111,  -241,
    -241,   122,    13,  -241,  -241,    87,  -241,   -29,    62,  -241,
     -66,   -13,  -241,  -241,   136,  -241,  -241,    91,   100,   104,
    -241,   136,     4,   151,  -241,   129,    66,  -241,   141,   111,
    -241,  -241,  -241,  -241,  -241,   111,  -241,   111,  -241,   111,
    -241,   139,  -241,  -241,  -241,  -241,  -241,  -241,  -241,   111,
     111,  -241,  -241,  -241,   111,   111,  -241,   -52,    12,  -241,
     115,  -241,  -241,  -241,  -241,  -241,  -241,  -241,  -241,    31,
    -241,  -241,   111,   120,   -66,  -241,  -241,   111,  -241,  -241,
      20,    76,  -241,    78,  -241,  -241,  -241,  -241,  -241,  -241,
    -241,  -241,  -241,  -241,  -241,  -241,   128,  -241,  -241,   -30,
    -241,   111,  -241,   131,   169,  -241,  -241,  -241,   154,  -241,
     164,  -241,  -241,  -241,    33,   178,  -241,  -241,   -52,   134,
    -241,  -241,   130,   150,  -241,  -241,  -241,   -66,  -241,   -23,
    -241,   -52,  -241,  -241,   166,  -241,  -241,  -241,  -241,   167,
    -241,    87,    36,   168,   -52,   227,  -241,   210,  -241,   178,
      38,   128,  -241,  -241,  -241,   -30,  -241,    87,    87,  -241,
    -241,  -241,   145,  -241,  -241,  -241,  -241,  -241,  -241,   -42,
    -241,  -241,  -241,  -241,  -241,  -241,  -241,  -241,   180,   -45,
    -241,   111,  -241,  -241,   233,  -241,   178,  -241,  -241,   -27,
    -241,   189,  -241,  -241,   172,  -241,  -241,  -241,  -241,   157,
    -241,  -241,  -241,  -241,   -42,  -241,   227,  -241,  -241,  -241,
    -241,   234,   -66,  -241,    67,   211,  -241,   212,   175,  -241,
    -241,    87,   245,  -241,   178,   -66,   217,  -241,  -241,  -241,
    -241,  -241,  -241,  -241,    87,  -241,  -241
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  SQLParser::yydefact_[] =
  {
         0,     0,     0,     0,     0,     0,     0,     0,     7,    11,
      12,     9,    10,     4,   108,   125,   203,     0,     0,     0,
       0,     0,     0,     0,     0,   137,   226,   138,   215,   218,
     221,   216,   219,   222,   217,   220,   223,   224,   225,   115,
     127,   202,   136,     0,   133,   158,   162,   166,   168,   170,
     180,   186,   191,   196,   197,   198,   200,   212,   213,   214,
     201,   199,     0,     0,    18,     0,    15,     1,     4,     5,
       2,   106,   194,   195,   193,     0,     0,     0,     0,     0,
       0,   116,   119,   124,     0,   131,     0,   134,   129,   156,
     160,   164,     0,     0,     0,     0,     0,     0,     0,   169,
     171,   181,   188,   139,   140,    31,    23,    21,     0,    16,
       0,     5,     3,     8,     0,   109,   210,     0,     0,     0,
     204,     0,   154,   112,   149,     0,     0,   120,   122,     0,
     128,   137,   138,   135,   132,     0,   159,     0,   163,     0,
     167,     0,   178,   172,   173,   174,   175,   176,   177,     0,
       0,   187,   184,   185,     0,     0,   192,     0,     0,    32,
       0,    20,    19,    22,    17,    14,    13,     6,   107,     0,
     206,   207,     0,     0,     0,   155,   151,     0,   113,   114,
     141,     0,   117,     0,   123,   110,   126,   157,   161,   165,
     179,   182,   183,   189,   190,   100,     0,    30,    37,    53,
     205,     0,   211,     0,     0,   153,   111,   142,     0,   143,
       0,   150,   118,   121,     0,     0,    34,    56,     0,     0,
      26,    54,     0,     0,    44,   209,   208,     0,   144,     0,
      98,     0,   101,    93,     0,   104,    95,    96,    94,    36,
      52,     0,     0,     0,     0,    78,   152,   146,    99,     0,
       0,     0,    35,    48,    28,    53,    27,     0,     0,    86,
      62,    87,     0,    69,    70,    73,    76,    75,    72,    84,
      77,    66,    74,    68,    79,    65,    64,    45,    59,     0,
      67,     0,   147,   148,     0,   102,     0,   105,    33,    24,
      25,     0,    49,    71,     0,    82,    85,    63,    50,     0,
      60,    57,    81,    80,    84,   145,    78,   103,    40,    39,
      29,    42,     0,    83,    46,     0,    61,     0,     0,    43,
      38,     0,     0,    91,     0,     0,     0,    51,    58,    97,
      41,    47,    90,    89,     0,    88,    92
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SQLParser::yypgoto_[] =
  {
      -241,  -241,   213,  -241,  -241,   181,  -241,  -241,  -241,  -241,
    -241,  -241,  -241,  -241,  -241,  -241,  -241,  -241,  -241,  -241,
    -241,  -241,  -241,  -241,  -241,  -241,    34,  -241,  -241,  -241,
    -241,  -241,  -241,   -12,  -241,  -241,  -241,  -241,  -241,  -241,
      -9,  -241,  -241,  -240,  -231,  -241,  -241,    45,  -241,  -241,
    -108,  -241,  -241,   183,  -241,  -241,  -241,  -241,  -241,  -241,
    -241,  -241,  -241,  -241,  -241,   173,   179,  -241,  -241,  -241,
     -80,   -62,  -241,  -241,  -241,  -241,  -241,  -241,    79,  -241,
    -241,   -22,  -241,  -241,   174,  -241,  -241,   170,  -241,  -241,
     171,  -241,  -241,  -241,   158,  -241,  -241,  -241,   -55,  -241,
    -241,   -57,    55,  -241,  -241,  -241,  -241,  -210,  -241,   202,
     214,  -208,  -207
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SQLParser::yydefgoto_[] =
  {
        -1,     7,    70,   113,    68,     8,     9,   109,   110,    10,
     163,   164,    11,   160,   256,   242,   289,    12,   158,   252,
     239,   197,   310,   311,   319,   320,   220,   245,   298,   314,
     221,   222,   223,   277,   300,   301,   278,   279,   304,   296,
     297,   280,   327,   235,   159,   232,   214,   216,   287,   250,
      13,   115,    71,    14,   178,   179,    81,    82,   127,   128,
     184,   185,    39,   130,    83,    40,    86,    87,    88,    41,
      42,    43,   123,   210,   282,   283,   211,   180,   124,   175,
     176,    44,   136,    89,    45,   138,    90,    46,   140,    91,
      47,    48,    99,   100,    49,    50,   151,   101,    51,   156,
     102,    52,    53,    54,    55,   202,   169,    56,    57,    58,
      59,    60,    61
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int SQLParser::yytable_ninf_ = -141;
  const short int
  SQLParser::yytable_[] =
  {
       105,   106,    79,   107,   133,   236,   134,   237,   238,   284,
     253,   217,    85,   173,   218,     1,   308,   302,   122,     1,
     154,   103,   -55,   104,   219,   121,   291,   292,   294,     2,
     207,   208,   295,     3,    62,   131,   303,   132,   161,   236,
     162,   237,   238,   125,   126,   155,   307,    63,   166,    64,
     198,   196,    65,   116,   117,   118,   119,   131,     2,   132,
     309,    66,     3,     4,   103,    67,   104,     5,   141,   142,
     209,     6,    72,    73,    74,    69,   236,   195,   237,   238,
     200,   201,   230,   231,   333,   254,   255,   285,   286,   322,
     331,  -130,     4,  -130,   191,   192,     5,   193,   194,    75,
       6,    76,    15,   336,    77,    78,  -139,  -140,   323,    80,
     324,    84,   205,   111,   236,   108,   237,   238,    16,   224,
     325,   326,   114,   120,   135,    17,    18,   129,    19,    20,
      21,    22,    23,   137,    16,   157,   139,   165,   240,     1,
     170,    17,    18,    24,    19,    20,    21,    22,    23,   171,
     203,   248,   149,   150,   172,   206,   177,   181,   182,    24,
      16,   183,   190,   199,   258,   246,   228,   122,   212,   204,
     213,    20,    21,    22,    23,   224,   215,   227,   229,   225,
     226,   243,    25,    26,    27,    24,   241,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    25,    26,
      27,   233,   244,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,   249,    29,    30,   251,    32,    33,
     257,    35,    36,   281,    25,    26,    27,   293,   299,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      92,   306,   312,    93,    94,    95,    96,    97,    98,   315,
     321,   143,   144,   145,   146,   147,   148,   313,   318,   305,
     328,   329,   330,   334,   234,   259,    26,   260,   332,   335,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,   112,   261,   262,   263,   264,   265,   266,   267,   290,
     268,   269,   167,   270,   317,   316,   288,   168,   271,   272,
     273,   174,   186,   152,   274,   275,   276,   188,   247,   187,
     189,     0,     0,     0,     0,   153
  };

  /* YYCHECK.  */
  const short int
  SQLParser::yycheck_[] =
  {
        62,    63,    24,    65,    84,   215,    86,   215,   215,   249,
     241,    41,     8,   121,    44,     3,    43,    62,    80,     3,
       7,    87,    52,    89,    54,    48,   257,   258,    70,    42,
      10,    11,    74,    46,    65,    87,    81,    89,    67,   249,
      69,   249,   249,    18,    19,    32,   286,    47,   110,    68,
     158,    39,    68,    75,    76,    77,    78,    87,    42,    89,
      87,    47,    46,    76,    87,     0,    89,    80,    22,    23,
      50,    84,    17,    18,    19,    45,   286,   157,   286,   286,
      49,    50,    49,    50,   324,    49,    50,    49,    50,    22,
     321,    87,    76,    89,   149,   150,    80,   154,   155,    48,
      84,    48,     7,   334,    48,    48,     9,     9,    41,     6,
      43,     9,   174,    45,   324,    83,   324,   324,    23,   199,
      53,    54,     4,    49,    15,    30,    31,    50,    33,    34,
      35,    36,    37,    16,    23,    48,    17,    75,   218,     3,
      49,    30,    31,    48,    33,    34,    35,    36,    37,    49,
     172,   231,    30,    31,    50,   177,     5,    28,    92,    48,
      23,    20,    23,    48,   244,   227,    12,   229,    92,    49,
      92,    34,    35,    36,    37,   255,    48,     8,    14,   201,
      49,    51,    87,    88,    89,    48,    52,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,    87,    88,
      89,    23,    52,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    48,    93,    94,    50,    96,    97,
      52,    99,   100,    13,    87,    88,    89,    82,    48,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      21,     8,    53,    24,    25,    26,    27,    28,    29,    92,
     312,    93,    94,    95,    96,    97,    98,    85,    24,   281,
      49,    49,    87,   325,    86,    38,    88,    40,    23,    52,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    68,    55,    56,    57,    58,    59,    60,    61,   255,
      63,    64,   111,    66,   306,   304,   251,   114,    71,    72,
      73,   122,   129,   101,    77,    78,    79,   137,   229,   135,
     139,    -1,    -1,    -1,    -1,   101
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  SQLParser::yystos_[] =
  {
         0,     3,    42,    46,    76,    80,    84,   104,   108,   109,
     112,   115,   120,   153,   156,     7,    23,    30,    31,    33,
      34,    35,    36,    37,    48,    87,    88,    89,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   165,
     168,   172,   173,   174,   184,   187,   190,   193,   194,   197,
     198,   201,   204,   205,   206,   207,   210,   211,   212,   213,
     214,   215,    65,    47,    68,    68,    47,     0,   107,    45,
     105,   155,   205,   205,   205,    48,    48,    48,    48,   184,
       6,   159,   160,   167,     9,     8,   169,   170,   171,   186,
     189,   192,    21,    24,    25,    26,    27,    28,    29,   195,
     196,   200,   203,    87,    89,   174,   174,   174,    83,   110,
     111,    45,   105,   106,     4,   154,   184,   184,   184,   184,
      49,    48,   174,   175,   181,    18,    19,   161,   162,    50,
     166,    87,    89,   173,   173,    15,   185,    16,   188,    17,
     191,    22,    23,   197,   197,   197,   197,   197,   197,    30,
      31,   199,   212,   213,     7,    32,   202,    48,   121,   147,
     116,    67,    69,   113,   114,    75,   174,   108,   156,   209,
      49,    49,    50,   153,   169,   182,   183,     5,   157,   158,
     180,    28,    92,    20,   163,   164,   168,   187,   190,   193,
      23,   201,   201,   204,   204,   173,    39,   124,   153,    48,
      49,    50,   208,   184,    49,   174,   184,    10,    11,    50,
     176,   179,    92,    92,   149,    48,   150,    41,    44,    54,
     129,   133,   134,   135,   173,   184,    49,     8,    12,    14,
      49,    50,   148,    23,    86,   146,   210,   214,   215,   123,
     173,    52,   118,    51,    52,   130,   174,   181,   173,    48,
     152,    50,   122,   147,    49,    50,   117,    52,   173,    38,
      40,    55,    56,    57,    58,    59,    60,    61,    63,    64,
      66,    71,    72,    73,    77,    78,    79,   136,   139,   140,
     144,    13,   177,   178,   146,    49,    50,   151,   150,   119,
     129,   147,   147,    82,    70,    74,   142,   143,   131,    48,
     137,   138,    62,    81,   141,   184,     8,   146,    43,    87,
     125,   126,    53,    85,   132,    92,   143,   136,    24,   127,
     128,   174,    22,    41,    43,    53,    54,   145,    49,    49,
      87,   147,    23,   146,   174,    52,   147
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
     132,   132,   133,   134,   134,   135,   135,   136,   137,   138,
     138,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   140,   140,
     141,   141,   142,   142,   143,   143,   144,   144,   145,   145,
     145,   145,   145,   146,   146,   146,   146,   146,   147,   148,
     149,   149,   150,   151,   152,   152,   153,   154,   155,   155,
     156,   157,   158,   158,   159,   160,   160,   161,   161,   162,
     162,   163,   164,   164,   165,   165,   166,   167,   167,   168,
     169,   169,   170,   171,   171,   172,   172,   173,   173,   174,
     174,   175,   176,   176,   176,   177,   178,   178,   179,   180,
     180,   181,   181,   182,   183,   183,   184,   185,   186,   186,
     187,   188,   189,   189,   190,   191,   192,   192,   193,   194,
     195,   195,   196,   196,   196,   196,   196,   196,   196,   196,
     197,   198,   199,   199,   199,   199,   200,   200,   201,   202,
     202,   203,   203,   204,   204,   204,   204,   205,   205,   205,
     205,   205,   205,   205,   206,   207,   207,   207,   207,   208,
     209,   209,   210,   210,   210,   211,   211,   211,   212,   212,
     212,   213,   213,   213,   214,   214,   215
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
       0,     2,     2,     0,     1,     0,     1,     2,     3,     0,
       1,     3,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     0,     1,
       1,     1,     1,     2,     0,     1,     1,     1,     2,     2,
       2,     1,     3,     1,     1,     1,     1,     6,     4,     2,
       0,     2,     4,     2,     0,     2,     2,     2,     0,     2,
       5,     2,     0,     1,     3,     0,     1,     2,     3,     0,
       1,     2,     0,     1,     2,     1,     2,     0,     2,     2,
       0,     1,     2,     0,     1,     3,     1,     1,     1,     1,
       1,     2,     1,     1,     2,     2,     0,     1,     4,     0,
       2,     2,     5,     2,     0,     1,     2,     2,     0,     2,
       2,     2,     0,     2,     2,     2,     0,     2,     1,     2,
       0,     1,     2,     2,     2,     2,     2,     2,     2,     3,
       1,     2,     2,     2,     1,     1,     0,     2,     2,     2,
       2,     0,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     5,     4,     4,     6,     2,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
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
  "_Q_O_QIT_CONSTRAINT_E_S_QAttribute_E_C_E_Opt", "_QIT_UNIQUE_E_Opt",
  "Sized", "_O_QGT_LPAREN_E_S_QINTEGER_E_S_QGT_RPAREN_E_C",
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
       104,     0,    -1,   153,   105,    -1,   108,   107,   105,    -1,
      -1,    45,    -1,    45,   108,    -1,    -1,   107,   106,    -1,
     115,    -1,   120,    -1,   109,    -1,   112,    -1,    84,    47,
     111,   174,    -1,    83,    75,    -1,    -1,   110,    -1,    80,
      68,   174,   114,    -1,    76,    68,    -1,    69,    -1,    67,
      -1,    -1,   113,    -1,    -1,    46,    47,   174,   116,    48,
     129,   118,    49,   119,    -1,    50,   129,    -1,    -1,   118,
     117,    -1,    -1,   119,   125,    -1,    42,    65,   174,   121,
     124,    -1,    -1,   147,    -1,    50,   150,    -1,    -1,   123,
     122,    -1,    39,   150,   123,    -1,   153,    -1,   126,   128,
      -1,    87,    -1,    43,    -1,    24,    87,    -1,    -1,   127,
      -1,    -1,    -1,   173,   130,   136,   131,   132,    -1,   134,
      51,    52,   147,    53,   174,   147,    -1,    54,    52,   147,
      -1,   135,    52,   173,   147,    -1,    -1,   132,   145,    -1,
      44,   173,    -1,    -1,   133,    -1,    -1,    41,    -1,   139,
     138,    -1,    48,    92,    49,    -1,    -1,   137,    -1,   140,
     141,   143,    -1,    40,    -1,    64,   143,    -1,    79,    -1,
      78,    -1,    71,    -1,   144,    -1,    73,    -1,    57,    -1,
      58,    -1,    56,    82,    -1,    63,    -1,    59,    -1,    72,
      -1,    61,    -1,    60,    -1,    66,    -1,    -1,    77,    -1,
      81,    -1,    62,    -1,    74,    -1,    70,    85,    -1,    -1,
     142,    -1,    38,    -1,    55,    -1,    54,    52,    -1,    43,
     146,    -1,    22,    23,    -1,    41,    -1,    53,   174,   147,
      -1,    23,    -1,   215,    -1,   210,    -1,   214,    -1,    86,
      48,   146,     8,   136,    49,    -1,    48,   173,   149,    49,
      -1,    50,   173,    -1,    -1,   149,   148,    -1,    48,   146,
     152,    49,    -1,    50,   146,    -1,    -1,   152,   151,    -1,
     156,   155,    -1,     4,   156,    -1,    -1,   155,   154,    -1,
       3,   165,   160,   162,   164,    -1,     5,   184,    -1,    -1,
     157,    -1,     6,   175,   158,    -1,    -1,   159,    -1,    19,
      92,    -1,    18,    28,    92,    -1,    -1,   161,    -1,    20,
      92,    -1,    -1,   163,    -1,   168,   167,    -1,     7,    -1,
      50,   168,    -1,    -1,   167,   166,    -1,   184,   171,    -1,
      -1,     8,    -1,   169,   173,    -1,    -1,   170,    -1,   174,
       9,   173,    -1,   173,    -1,    87,    -1,    89,    -1,    87,
      -1,    89,    -1,   181,   180,    -1,    10,    -1,    50,    -1,
      11,    12,    -1,    13,   184,    -1,    -1,   177,    -1,   176,
      14,   181,   178,    -1,    -1,   180,   179,    -1,   174,   183,
      -1,    48,   153,    49,     8,   174,    -1,   169,   174,    -1,
      -1,   182,    -1,   187,   186,    -1,    15,   187,    -1,    -1,
     186,   185,    -1,   190,   189,    -1,    16,   190,    -1,    -1,
     189,   188,    -1,   193,   192,    -1,    17,   193,    -1,    -1,
     192,   191,    -1,   194,    -1,   197,   195,    -1,    -1,   196,
      -1,    24,   197,    -1,    25,   197,    -1,    26,   197,    -1,
      27,   197,    -1,    28,   197,    -1,    29,   197,    -1,    21,
      23,    -1,    21,    22,    23,    -1,   198,    -1,   201,   200,
      -1,    30,   201,    -1,    31,   201,    -1,   212,    -1,   213,
      -1,    -1,   200,   199,    -1,   204,   203,    -1,     7,   204,
      -1,    32,   204,    -1,    -1,   203,   202,    -1,    33,   205,
      -1,    30,   205,    -1,    31,   205,    -1,   205,    -1,   206,
      -1,   207,    -1,   215,    -1,   210,    -1,   214,    -1,   172,
      -1,    23,    -1,    48,   184,    49,    -1,    34,    48,   184,
     209,    49,    -1,    35,    48,   184,    49,    -1,    36,    48,
     184,    49,    -1,    37,    48,   184,    50,   184,    49,    -1,
      50,   184,    -1,    -1,   209,   208,    -1,   211,    -1,   212,
      -1,   213,    -1,    92,    -1,    95,    -1,    98,    -1,    93,
      -1,    96,    -1,    99,    -1,    94,    -1,    97,    -1,   100,
      -1,   101,    -1,   102,    -1,    88,    -1
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
     136,   137,   140,   143,   144,   146,   147,   149,   152,   156,
     157,   159,   163,   165,   168,   170,   172,   174,   176,   178,
     180,   182,   185,   187,   189,   191,   193,   195,   197,   198,
     200,   202,   204,   206,   209,   210,   212,   214,   216,   219,
     222,   225,   227,   231,   233,   235,   237,   239,   246,   251,
     254,   255,   258,   263,   266,   267,   270,   273,   276,   277,
     280,   286,   289,   290,   292,   296,   297,   299,   302,   306,
     307,   309,   312,   313,   315,   318,   320,   323,   324,   327,
     330,   331,   333,   336,   337,   339,   343,   345,   347,   349,
     351,   353,   356,   358,   360,   363,   366,   367,   369,   374,
     375,   378,   381,   387,   390,   391,   393,   396,   399,   400,
     403,   406,   409,   410,   413,   416,   419,   420,   423,   425,
     428,   429,   431,   434,   437,   440,   443,   446,   449,   452,
     456,   458,   461,   464,   467,   469,   471,   472,   475,   478,
     481,   484,   485,   488,   491,   494,   497,   499,   501,   503,
     505,   507,   509,   511,   513,   517,   523,   528,   533,   540,
     543,   544,   547,   549,   551,   553,   555,   557,   559,   561,
     563,   565,   567,   569,   571,   573,   575
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
     469,   471,   475,   480,   482,   485,   487,   491,   498,   506,
     509,   513,   516,   519,   522,   525,   528,   531,   534,   537,
     540,   543,   546,   549,   552,   555,   558,   561,   566,   568,
     572,   573,   577,   580,   586,   589,   593,   594,   598,   601,
     604,   607,   610,   620,   623,   624,   625,   626,   632,   640,
     646,   649,   657,   664,   670,   673,   680,   692,   698,   701,
     708,   725,   731,   734,   738,   747,   751,   755,   760,   768,
     771,   775,   783,   786,   790,   795,   801,   807,   810,   817,
     829,   831,   835,   841,   844,   850,   855,   862,   863,   867,
     868,   872,   885,   888,   891,   897,   903,   906,   912,   925,
     929,   938,   949,   958,   964,   967,   973,   984,   990,   993,
    1001,  1013,  1020,  1023,  1031,  1043,  1050,  1053,  1060,  1065,
    1084,  1087,  1092,  1095,  1098,  1101,  1104,  1107,  1110,  1113,
    1119,  1124,  1136,  1139,  1142,  1143,  1148,  1151,  1159,  1171,
    1174,  1181,  1184,  1191,  1194,  1197,  1200,  1204,  1205,  1206,
    1207,  1208,  1209,  1210,  1216,  1222,  1227,  1232,  1237,  1243,
    1249,  1252,  1259,  1260,  1261,  1265,  1266,  1267,  1271,  1272,
    1273,  1277,  1278,  1279,  1283,  1284,  1288
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
  const int SQLParser::yylast_ = 315;
  const int SQLParser::yynnts_ = 113;
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
#line 2674 "lib/SQLParser/SQLParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 1308 "lib/SQLParser/SQLParser.ypp"
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

