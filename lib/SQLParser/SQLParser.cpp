
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
#line 212 "lib/SQLParser/SQLParser.ypp"

#include "SQLScanner.hpp"

/* Line 317 of lalr1.cc  */
#line 290 "lib/SQLParser/SQLParser.ypp"

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
#line 306 "lib/SQLParser/SQLParser.ypp"
    {
	driver.root = (yysemantic_stack_[(2) - (1)].p_Select);
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 362 "lib/SQLParser/SQLParser.ypp"
    {
	driver.curCreate = new sql::schema::Relation(*(yysemantic_stack_[(3) - (3)].p_NAME));
      }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 364 "lib/SQLParser/SQLParser.ypp"
    {
	  driver.tables[*(yysemantic_stack_[(9) - (3)].p_NAME)] = driver.curCreate;
	  delete (yysemantic_stack_[(9) - (3)].p_NAME);
	  driver.curCreate = NULL;
      }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 386 "lib/SQLParser/SQLParser.ypp"
    {
	driver.curCreate = new sql::schema::Relation(*(yysemantic_stack_[(5) - (3)].p_NAME));
	driver.inserts.push_back(new sql::Insert(*(yysemantic_stack_[(5) - (3)].p_NAME), (yysemantic_stack_[(5) - (4)].p_Attributes), (yysemantic_stack_[(5) - (5)].p_RValue)));
	delete (yysemantic_stack_[(5) - (3)].p_NAME);
    }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 394 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Attributes) = NULL;
    }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 401 "lib/SQLParser/SQLParser.ypp"
    {
	w3c_sw_LINEN << "ignoring non-standard inserts\n";
    }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 412 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_RValue) = new sql::RConstants((yysemantic_stack_[(3) - (2)].p_Expressions));
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 415 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_RValue) = new sql::RSelection((yysemantic_stack_[(1) - (1)].p_Select));
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 421 "lib/SQLParser/SQLParser.ypp"
    {
	w3c_sw_LINEN << "ignoring parameters\n";
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 441 "lib/SQLParser/SQLParser.ypp"
    {
	sql::schema::Field* f = new sql::schema::Field(*(yysemantic_stack_[(3) - (1)].p_NAME), (yysemantic_stack_[(3) - (2)].p_TypeSize).type, (yysemantic_stack_[(3) - (2)].p_TypeSize).size);
	driver.curCreate->addField(f);
	if (driver.curIsPrimary) {
	    driver.curIsPrimary = false;
	    std::vector<sql::Attribute>* attrs = new std::vector<sql::Attribute>();
	    attrs->push_back(*(yysemantic_stack_[(3) - (1)].p_NAME));
	    driver.curCreate->setPrimaryKey(new sql::schema::PrimaryKey(attrs));
	}
	delete (yysemantic_stack_[(3) - (1)].p_NAME);
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 452 "lib/SQLParser/SQLParser.ypp"
    {
      driver.curCreate->addForeignKey(new sql::schema::ForeignKey((yysemantic_stack_[(7) - (4)].p_Attributes), *(yysemantic_stack_[(7) - (6)].p_NAME), (yysemantic_stack_[(7) - (7)].p_Attributes)));
      delete (yysemantic_stack_[(7) - (6)].p_NAME);
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 456 "lib/SQLParser/SQLParser.ypp"
    {
      driver.curCreate->setPrimaryKey(new sql::schema::PrimaryKey((yysemantic_stack_[(3) - (3)].p_Attributes)));
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 459 "lib/SQLParser/SQLParser.ypp"
    {
	w3c_sw_LINEN << "ignoring UNIQUE KEYs\n";
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 470 "lib/SQLParser/SQLParser.ypp"
    {
	w3c_sw_LINEN << "ignoring constraint name\n";
    }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 486 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TypeSize).type = (yysemantic_stack_[(2) - (1)].p_SchemaDatatype);
	(yyval.p_TypeSize).size = (yysemantic_stack_[(2) - (2)].p_int);
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 493 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(3) - (2)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 501 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_int) = SQL_PRECISION_unspecified;
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 508 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype) = (yysemantic_stack_[(3) - (3)].p_bool) ? sql::TYPE_varchar : sql::TYPE_char;
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 511 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype) = sql::TYPE_varchar;
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 514 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype) = sql::TYPE_binary;
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 517 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype) = sql::TYPE_int;
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 520 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype) = sql::TYPE_int;
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 523 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype) = sql::TYPE_int;
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 526 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype) = sql::TYPE_int;
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 529 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype) = sql::TYPE_int;
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 532 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::TYPE_float;
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 535 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::TYPE_real;
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 538 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::TYPE_double;
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 541 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::TYPE_boolean;
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 544 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::TYPE_date;
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 547 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::TYPE_time;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 550 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::TYPE_timestamp;
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 553 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::TYPE_datetime;
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 556 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::TYPE_interval;
    }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 572 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_bool) = true;
    }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 575 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_bool) = false;
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 581 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_bool) = false;
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 593 "lib/SQLParser/SQLParser.ypp"
    {
	driver.curIsPrimary = true;
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 596 "lib/SQLParser/SQLParser.ypp"
    {
	w3c_sw_LINEN << "ignoring DEFAULT\n";
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 599 "lib/SQLParser/SQLParser.ypp"
    {
	w3c_sw_LINEN << "ignoring NOT NULL\n";
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 605 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::IsNullConstraint();
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 611 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::CastConstraint((yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_TypeSize).type, (yysemantic_stack_[(6) - (5)].p_TypeSize).size);
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 617 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(4) - (3)].p_Attributes)->insert((yysemantic_stack_[(4) - (3)].p_Attributes)->begin(), *(yysemantic_stack_[(4) - (2)].p_NAME));
	delete (yysemantic_stack_[(4) - (2)].p_NAME);
	(yyval.p_Attributes) = (yysemantic_stack_[(4) - (3)].p_Attributes);
}
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 625 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = (yysemantic_stack_[(2) - (2)].p_NAME);
}
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 631 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Attributes) = new std::vector<sql::Attribute>();
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 634 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Attributes)->push_back(*(yysemantic_stack_[(2) - (2)].p_NAME));
	delete (yysemantic_stack_[(2) - (2)].p_NAME);
	(yyval.p_Attributes) = (yysemantic_stack_[(2) - (1)].p_Attributes);
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 642 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(4) - (3)].p_Expressions)->insert((yysemantic_stack_[(4) - (3)].p_Expressions)->begin(), (yysemantic_stack_[(4) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(4) - (3)].p_Expressions);
}
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 649 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 655 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 658 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 665 "lib/SQLParser/SQLParser.ypp"
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

  case 103:

/* Line 678 of lalr1.cc  */
#line 677 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Select) = (yysemantic_stack_[(2) - (2)].p_Select);
}
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 683 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Selects) = new std::vector<sql::SQLQuery*>();
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 686 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Selects)->push_back((yysemantic_stack_[(2) - (2)].p_Select));
	(yyval.p_Selects) = (yysemantic_stack_[(2) - (1)].p_Selects);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 693 "lib/SQLParser/SQLParser.ypp"
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

  case 107:

/* Line 678 of lalr1.cc  */
#line 710 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 716 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 723 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TableList).joins = (yysemantic_stack_[(3) - (2)].p_TableList).joins;
	(yyval.p_TableList).exprs = (yysemantic_stack_[(3) - (2)].p_TableList).exprs;
	if ((yysemantic_stack_[(3) - (3)].p_Expression) != NULL)
	    (yyval.p_TableList).exprs->push_back((yysemantic_stack_[(3) - (3)].p_Expression));
}
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 732 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TableList).joins = new std::vector<sql::Join*>();;
	(yyval.p_TableList).exprs = new std::vector<const sql::Expression*>();;
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 740 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 745 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(3) - (3)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(3) - (3)].p_Expression);
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 753 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_int) = -1;
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 760 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 768 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_int) = -1;
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 775 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (2)].p_AttributeList)->insert((yysemantic_stack_[(2) - (2)].p_AttributeList)->begin(), (yysemantic_stack_[(2) - (1)].p_AliasedSelect));
	(yyval.p_AttributeList) = new std::vector<sql::AliasedSelect*>((yysemantic_stack_[(2) - (2)].p_AttributeList)->begin(), (yysemantic_stack_[(2) - (2)].p_AttributeList)->end());
	delete (yysemantic_stack_[(2) - (2)].p_AttributeList);
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 780 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AttributeList) = new std::vector<sql::AliasedSelect*>();
      }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 786 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AliasedSelect) = (yysemantic_stack_[(2) - (2)].p_AliasedSelect);
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 792 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AttributeList) = new std::vector<sql::AliasedSelect*>();
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 795 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_AttributeList)->push_back((yysemantic_stack_[(2) - (2)].p_AliasedSelect));
	(yyval.p_AttributeList) = (yysemantic_stack_[(2) - (1)].p_AttributeList);
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 802 "lib/SQLParser/SQLParser.ypp"
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

  case 128:

/* Line 678 of lalr1.cc  */
#line 820 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = (yysemantic_stack_[(2) - (2)].p_NAME);
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 826 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = NULL;
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 829 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = (yysemantic_stack_[(1) - (1)].p_NAME);
      }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 835 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::AliasAttrConstraint(sql::AliasAttr(sql::RelVar(*(yysemantic_stack_[(3) - (1)].p_NAME)), sql::Attribute(*(yysemantic_stack_[(3) - (3)].p_NAME))));
	delete (yysemantic_stack_[(3) - (1)].p_NAME);
	delete (yysemantic_stack_[(3) - (3)].p_NAME);
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 840 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_Expression) = new sql::AliasAttrConstraint(sql::AliasAttr(sql::RelVar(""), sql::Attribute(*(yysemantic_stack_[(1) - (1)].p_NAME))));
	delete (yysemantic_stack_[(1) - (1)].p_NAME);
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 857 "lib/SQLParser/SQLParser.ypp"
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

  case 138:

/* Line 678 of lalr1.cc  */
#line 870 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_bool) = false;
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 873 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_bool) = false;
      }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 876 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_bool) = true;
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 882 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 888 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 891 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(1) - (1)].p_Expression);
      }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 897 "lib/SQLParser/SQLParser.ypp"
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

  case 145:

/* Line 678 of lalr1.cc  */
#line 910 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TableList).joins = new std::vector<sql::Join*>();
	(yyval.p_TableList).exprs = new std::vector<const sql::Expression*>();
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 914 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TableList).joins->push_back((yysemantic_stack_[(2) - (2)].p_JoinExpression).join);
	if ((yysemantic_stack_[(2) - (2)].p_JoinExpression).expr != NULL)
	    (yysemantic_stack_[(2) - (1)].p_TableList).exprs->push_back((yysemantic_stack_[(2) - (2)].p_JoinExpression).expr);
	(yyval.p_TableList) = (yysemantic_stack_[(2) - (1)].p_TableList);
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 923 "lib/SQLParser/SQLParser.ypp"
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

  case 148:

/* Line 678 of lalr1.cc  */
#line 934 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_tableAlias).relation = NULL;
	(yyval.p_tableAlias).subselect = (yysemantic_stack_[(5) - (2)].p_Select);
	(yyval.p_tableAlias).alias = new sql::RelVar(*(yysemantic_stack_[(5) - (5)].p_NAME));
	delete (yysemantic_stack_[(5) - (5)].p_NAME);
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 943 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = (yysemantic_stack_[(2) - (2)].p_NAME);
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 949 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = NULL;
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 952 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = (yysemantic_stack_[(1) - (1)].p_NAME);
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 963 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::DisjunctionConstraint((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 975 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 982 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 985 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 993 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::ConjunctionConstraint((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 1005 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 1012 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 1015 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 1027 "lib/SQLParser/SQLParser.ypp"
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

  case 163:

/* Line 678 of lalr1.cc  */
#line 1046 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = NULL;
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 1054 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1057 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 1060 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 1063 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1066 "lib/SQLParser/SQLParser.ypp"
    {
        (yyval.p_BooleanComparator) = new sql::BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 1069 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 1072 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_BooleanComparator) = new sql::IsNullProxy;
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 1075 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_BooleanComparator) = new sql::IsNotNullProxy;
}
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 1086 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::ArithmeticSum((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 1098 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 1101 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 1110 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 1113 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 1121 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::ArithmeticProduct((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 1133 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 1136 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 1143 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 1146 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 1153 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 1156 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 1159 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 1172 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::IsNullConstraint();
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1178 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 1184 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(5) - (4)].p_Expressions)->insert((yysemantic_stack_[(5) - (4)].p_Expressions)->begin(), (yysemantic_stack_[(5) - (3)].p_Expression));
	(yyval.p_Expression) = new sql::HomologConstraint("CONCAT", (yysemantic_stack_[(5) - (4)].p_Expressions)->begin(), (yysemantic_stack_[(5) - (4)].p_Expressions)->end());
	delete (yysemantic_stack_[(5) - (4)].p_Expressions);
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 1189 "lib/SQLParser/SQLParser.ypp"
    {
	std::vector<const sql::Expression*> v;
	v.push_back((yysemantic_stack_[(4) - (3)].p_Expression));
	(yyval.p_Expression) = new sql::HomologConstraint("LCASE", v.begin(), v.end());
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 1194 "lib/SQLParser/SQLParser.ypp"
    {
	std::vector<const sql::Expression*> v;
	v.push_back((yysemantic_stack_[(4) - (3)].p_Expression));
	(yyval.p_Expression) = new sql::HomologConstraint("UCASE", v.begin(), v.end());
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 1199 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::RegexConstraint((yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression));
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 1205 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 1211 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 1214 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 1250 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::LiteralConstraint(*(yysemantic_stack_[(1) - (1)].p_NAME));
	delete (yysemantic_stack_[(1) - (1)].p_NAME);
    }
    break;



/* Line 678 of lalr1.cc  */
#line 1757 "lib/SQLParser/SQLParser.cpp"
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
  const short int SQLParser::yypact_ninf_ = -253;
  const short int
  SQLParser::yypact_[] =
  {
        33,    -1,   -51,   -29,   -60,   -37,    -6,    84,  -253,  -253,
    -253,  -253,  -253,    57,  -253,  -253,  -253,   118,   118,   118,
      74,    92,    94,   119,   102,    34,  -253,   158,  -253,  -253,
    -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,   162,
    -253,  -253,  -253,   160,    17,  -253,  -253,  -253,  -253,    43,
    -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,
    -253,  -253,    41,    41,  -253,    41,    89,  -253,   131,  -253,
    -253,   183,  -253,  -253,  -253,   102,   102,   102,   102,   144,
     -39,  -253,    71,   159,    42,  -253,    42,  -253,  -253,   192,
     205,    37,   102,   102,   102,   102,   102,   102,  -253,  -253,
      27,     8,  -253,  -253,   187,  -253,    -4,   161,  -253,    41,
      -3,  -253,  -253,   229,  -253,  -253,   188,   189,   197,  -253,
     229,    17,   233,  -253,   222,   163,  -253,   232,   102,  -253,
    -253,  -253,  -253,  -253,   102,  -253,   102,  -253,   230,  -253,
    -253,  -253,  -253,  -253,  -253,  -253,   102,   102,  -253,  -253,
    -253,   102,   102,  -253,    42,     6,  -253,   211,  -253,  -253,
    -253,  -253,  -253,  -253,  -253,  -253,    69,  -253,  -253,   102,
     212,    41,  -253,  -253,   102,  -253,  -253,    16,   168,  -253,
     174,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,
    -253,  -253,   220,  -253,  -253,   180,  -253,   102,  -253,   221,
     262,  -253,  -253,  -253,   259,  -253,   258,  -253,  -253,  -253,
      95,    85,  -253,  -253,    42,   223,  -253,  -253,   225,   226,
     185,  -253,  -253,    41,  -253,   -39,  -253,    42,  -253,  -253,
     231,  -253,  -253,  -253,  -253,   224,  -253,   187,    99,   228,
      42,  -253,  -253,  -253,   195,  -253,  -253,  -253,  -253,  -253,
    -253,   -57,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,
     234,   -43,  -253,  -253,   267,  -253,    85,   107,   220,  -253,
    -253,  -253,   180,  -253,   187,   187,  -253,   198,  -253,  -253,
    -253,   121,   193,  -253,  -253,  -253,  -253,   -57,   102,  -253,
    -253,   275,  -253,    85,  -253,  -253,   -31,  -253,   235,  -253,
    -253,   263,    85,   237,  -253,   238,  -253,  -253,   185,  -253,
    -253,  -253,  -253,   266,    41,  -253,  -253,  -253,  -253,   242,
     206,  -253,  -253,   187,  -253,  -253,  -253
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  SQLParser::yydefact_[] =
  {
         0,     0,     0,     0,     0,     0,     0,     0,     7,    11,
      12,     9,    10,     4,   104,   121,   196,     0,     0,     0,
       0,     0,     0,     0,     0,   133,   219,   134,   208,   211,
     214,   209,   212,   215,   210,   213,   216,   217,   218,   111,
     123,   195,   132,     0,   129,   152,   155,   159,   161,   163,
     173,   179,   184,   189,   190,   191,   193,   205,   206,   207,
     194,   192,     0,     0,    18,     0,    15,     1,     4,     5,
       2,   102,   187,   188,   186,     0,     0,     0,     0,     0,
       0,   112,   115,   120,     0,   127,     0,   130,   125,   153,
     157,     0,     0,     0,     0,     0,     0,     0,   162,   164,
     174,   181,   135,   136,    31,    23,    21,     0,    16,     0,
       5,     3,     8,     0,   105,   203,     0,     0,     0,   197,
       0,   150,   108,   145,     0,     0,   116,   118,     0,   124,
     133,   134,   131,   128,     0,   156,     0,   160,     0,   171,
     165,   166,   167,   168,   169,   170,     0,     0,   180,   177,
     178,     0,     0,   185,     0,     0,    32,     0,    20,    19,
      22,    17,    14,    13,     6,   103,     0,   199,   200,     0,
       0,     0,   151,   147,     0,   109,   110,   137,     0,   113,
       0,   119,   106,   122,   154,   158,   172,   175,   176,   182,
     183,    96,     0,    30,    37,    51,   198,     0,   204,     0,
       0,   149,   107,   138,     0,   139,     0,   146,   114,   117,
       0,     0,    34,    54,     0,     0,    26,    52,     0,     0,
      76,   202,   201,     0,   140,     0,    94,     0,    97,    89,
       0,   100,    91,    92,    90,    36,    50,     0,     0,     0,
       0,    84,    60,    85,     0,    67,    68,    71,    74,    73,
      70,    82,    75,    64,    72,    66,    77,    63,    62,    48,
      57,     0,    65,   148,   142,    95,     0,     0,     0,    35,
      46,    28,    51,    27,     0,     0,    69,     0,    80,    83,
      61,    44,     0,    58,    55,    79,    78,    82,     0,   143,
     144,     0,    98,     0,   101,    33,    24,    25,     0,    47,
      81,     0,     0,     0,    49,     0,    59,   141,    76,    99,
      40,    39,    29,    42,     0,    88,    87,    86,    56,     0,
       0,    43,    38,     0,    93,    41,    45
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SQLParser::yypgoto_[] =
  {
      -253,  -253,   227,  -253,  -253,   181,  -253,  -253,  -253,  -253,
    -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,
    -253,  -253,  -253,  -253,  -253,  -253,    21,  -253,  -253,  -253,
    -253,   -14,  -253,  -253,  -253,  -253,  -253,  -253,    10,  -253,
    -253,  -252,  -214,  -253,  -253,    28,  -253,  -253,  -110,  -253,
    -253,   186,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,
    -253,  -253,  -253,   170,   179,  -253,  -253,  -253,   -81,   -61,
    -253,  -253,  -253,  -253,  -253,  -253,    76,  -253,  -253,   -24,
    -253,  -253,  -253,   169,  -253,  -253,   166,  -253,  -253,  -253,
     133,  -253,  -253,  -253,    11,  -253,  -253,     9,    64,  -253,
    -253,  -253,  -253,  -191,  -253,   204,   207,  -189,  -187
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SQLParser::yydefgoto_[] =
  {
        -1,     7,    70,   112,    68,     8,     9,   108,   109,    10,
     160,   161,    11,   157,   273,   238,   296,    12,   155,   269,
     235,   193,   312,   313,   321,   322,   216,   281,   217,   218,
     219,   259,   283,   284,   260,   261,   287,   279,   280,   262,
     304,   231,   156,   228,   210,   212,   294,   267,    13,   114,
      71,    14,   175,   176,    81,    82,   126,   127,   181,   182,
      39,   129,    83,    40,    86,    87,    88,    41,    42,    43,
     122,   206,   289,   290,   207,   177,   123,   172,   173,    44,
      45,   135,    89,    46,   137,    90,    47,    48,    98,    99,
      49,    50,   148,   100,    51,   153,   101,    52,    53,    54,
      55,   198,   166,    56,    57,    58,    59,    60,    61
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int SQLParser::yytable_ninf_ = -137;
  const short int
  SQLParser::yytable_[] =
  {
        79,   104,   105,   132,   106,   133,    15,    64,   120,     1,
     170,   310,   277,    62,   291,   151,   278,    63,   285,   121,
     232,    16,   233,   270,   234,    85,   203,   204,    17,    18,
      65,    19,    20,    21,    22,    23,     1,   286,     2,   152,
      66,   309,     3,  -135,   192,   194,    24,   102,   163,   103,
     316,   115,   116,   117,   118,   311,   146,   147,   138,   139,
     298,   299,   158,    91,   159,   205,    92,    93,    94,    95,
      96,    97,     4,   191,     2,   232,     5,   233,     3,   234,
       6,    72,    73,    74,    67,    25,    26,    27,   124,   125,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    69,   232,  -126,   233,  -126,   234,   229,     4,   326,
     201,   232,     5,   233,   220,   234,     6,   196,   197,    29,
      30,    75,    32,    33,    16,    35,    36,   102,   130,   103,
     131,    17,    18,   236,    19,    20,    21,    22,    23,    76,
      16,    77,   301,   226,   227,   199,   265,   271,   272,    24,
     202,    20,    21,    22,    23,   292,   293,   187,   188,   275,
     189,   190,   263,   302,   121,    24,    78,  -136,    80,    84,
     230,   107,    26,   221,   303,   110,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,   113,    25,    26,
      27,   220,   119,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    25,    26,    27,   134,   128,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
     213,   136,   241,   214,   242,   140,   141,   142,   143,   144,
     145,   -53,     1,   215,   154,   162,   167,   168,   174,   243,
     244,   245,   246,   247,   248,   249,   169,   250,   251,   178,
     252,   180,   186,   323,   179,   253,   254,   255,   195,   208,
     200,   256,   257,   258,   307,   209,   130,   211,   131,   222,
     223,   224,   225,   268,   237,   239,   276,   240,   266,   274,
     288,   282,   300,   308,   305,   315,   318,   314,   317,   320,
     324,   164,   325,   297,   319,   111,   295,   306,   183,   165,
     171,   264,   185,   184,   149,     0,     0,   150
  };

  /* YYCHECK.  */
  const short int
  SQLParser::yycheck_[] =
  {
        24,    62,    63,    84,    65,    86,     7,    67,    47,     3,
     120,    42,    69,    64,   266,     7,    73,    46,    61,    80,
     211,    22,   211,   237,   211,     8,    10,    11,    29,    30,
      67,    32,    33,    34,    35,    36,     3,    80,    41,    31,
      46,   293,    45,     9,    38,   155,    47,    86,   109,    88,
     302,    75,    76,    77,    78,    86,    29,    30,    21,    22,
     274,   275,    66,    20,    68,    49,    23,    24,    25,    26,
      27,    28,    75,   154,    41,   266,    79,   266,    45,   266,
      83,    17,    18,    19,     0,    86,    87,    88,    17,    18,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,    44,   293,    86,   293,    88,   293,    22,    75,   323,
     171,   302,    79,   302,   195,   302,    83,    48,    49,    92,
      93,    47,    95,    96,    22,    98,    99,    86,    86,    88,
      88,    29,    30,   214,    32,    33,    34,    35,    36,    47,
      22,    47,    21,    48,    49,   169,   227,    48,    49,    47,
     174,    33,    34,    35,    36,    48,    49,   146,   147,   240,
     151,   152,   223,    42,   225,    47,    47,     9,     6,     9,
      85,    82,    87,   197,    53,    44,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,     4,    86,    87,
      88,   272,    48,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    86,    87,    88,    15,    49,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
      40,    16,    37,    43,    39,    92,    93,    94,    95,    96,
      97,    51,     3,    53,    47,    74,    48,    48,     5,    54,
      55,    56,    57,    58,    59,    60,    49,    62,    63,    27,
      65,    19,    22,   314,    91,    70,    71,    72,    47,    91,
      48,    76,    77,    78,   288,    91,    86,    47,    88,    48,
       8,    12,    14,    49,    51,    50,    81,    51,    47,    51,
      13,    47,    84,     8,    91,    22,    48,    52,    51,    23,
      48,   110,    86,   272,   308,    68,   268,   287,   128,   113,
     121,   225,   136,   134,   100,    -1,    -1,   100
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  SQLParser::yystos_[] =
  {
         0,     3,    41,    45,    75,    79,    83,   103,   107,   108,
     111,   114,   119,   150,   153,     7,    22,    29,    30,    32,
      33,    34,    35,    36,    47,    86,    87,    88,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   162,
     165,   169,   170,   171,   181,   182,   185,   188,   189,   192,
     193,   196,   199,   200,   201,   202,   205,   206,   207,   208,
     209,   210,    64,    46,    67,    67,    46,     0,   106,    44,
     104,   152,   200,   200,   200,    47,    47,    47,    47,   181,
       6,   156,   157,   164,     9,     8,   166,   167,   168,   184,
     187,    20,    23,    24,    25,    26,    27,    28,   190,   191,
     195,   198,    86,    88,   171,   171,   171,    82,   109,   110,
      44,   104,   105,     4,   151,   181,   181,   181,   181,    48,
      47,   171,   172,   178,    17,    18,   158,   159,    49,   163,
      86,    88,   170,   170,    15,   183,    16,   186,    21,    22,
     192,   192,   192,   192,   192,   192,    29,    30,   194,   207,
     208,     7,    31,   197,    47,   120,   144,   115,    66,    68,
     112,   113,    74,   171,   107,   153,   204,    48,    48,    49,
     150,   166,   179,   180,     5,   154,   155,   177,    27,    91,
      19,   160,   161,   165,   185,   188,    22,   196,   196,   199,
     199,   170,    38,   123,   150,    47,    48,    49,   203,   181,
      48,   171,   181,    10,    11,    49,   173,   176,    91,    91,
     146,    47,   147,    40,    43,    53,   128,   130,   131,   132,
     170,   181,    48,     8,    12,    14,    48,    49,   145,    22,
      85,   143,   205,   209,   210,   122,   170,    51,   117,    50,
      51,    37,    39,    54,    55,    56,    57,    58,    59,    60,
      62,    63,    65,    70,    71,    72,    76,    77,    78,   133,
     136,   137,   141,   171,   178,   170,    47,   149,    49,   121,
     144,    48,    49,   116,    51,   170,    81,    69,    73,   139,
     140,   129,    47,   134,   135,    61,    80,   138,    13,   174,
     175,   143,    48,    49,   148,   147,   118,   128,   144,   144,
      84,    21,    42,    53,   142,    91,   140,   181,     8,   143,
      42,    86,   124,   125,    52,    22,   143,    51,    48,   133,
      23,   126,   127,   171,    48,    86,   144
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
     355,   356
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  SQLParser::yyr1_[] =
  {
         0,   102,   103,   103,   104,   104,   105,   106,   106,   107,
     107,   107,   107,   108,   109,   110,   110,   111,   111,   112,
     112,   113,   113,   115,   114,   116,   117,   117,   118,   118,
     119,   120,   120,   121,   122,   122,   123,   123,   124,   125,
     125,   126,   127,   127,   128,   128,   128,   128,   129,   129,
     130,   131,   131,   132,   132,   133,   134,   135,   135,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   137,   137,   138,   138,
     139,   139,   140,   140,   141,   141,   142,   142,   142,   143,
     143,   143,   143,   143,   144,   145,   146,   146,   147,   148,
     149,   149,   150,   151,   152,   152,   153,   154,   155,   155,
     156,   157,   157,   158,   158,   159,   159,   160,   161,   161,
     162,   162,   163,   164,   164,   165,   166,   166,   167,   168,
     168,   169,   169,   170,   170,   171,   171,   172,   173,   173,
     173,   174,   175,   175,   176,   177,   177,   178,   178,   179,
     180,   180,   181,   182,   183,   184,   184,   185,   186,   187,
     187,   188,   189,   190,   190,   191,   191,   191,   191,   191,
     191,   191,   191,   192,   193,   194,   194,   194,   194,   195,
     195,   196,   197,   197,   198,   198,   199,   199,   199,   199,
     200,   200,   200,   200,   200,   200,   200,   201,   202,   202,
     202,   202,   203,   204,   204,   205,   205,   205,   206,   206,
     206,   207,   207,   207,   208,   208,   208,   209,   209,   210
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  SQLParser::yyr2_[] =
  {
         0,     2,     2,     3,     0,     1,     2,     0,     2,     1,
       1,     1,     1,     4,     2,     0,     1,     4,     2,     1,
       1,     0,     1,     0,     9,     2,     0,     2,     0,     2,
       5,     0,     1,     2,     0,     2,     3,     1,     2,     1,
       1,     2,     0,     1,     3,     7,     3,     4,     0,     2,
       2,     0,     1,     0,     1,     2,     3,     0,     1,     3,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     1,
       1,     2,     0,     1,     1,     1,     2,     2,     2,     1,
       1,     1,     1,     6,     4,     2,     0,     2,     4,     2,
       0,     2,     2,     2,     0,     2,     5,     2,     0,     1,
       3,     0,     1,     2,     3,     0,     1,     2,     0,     1,
       2,     1,     2,     0,     2,     2,     0,     1,     2,     0,
       1,     3,     1,     1,     1,     1,     1,     2,     1,     1,
       2,     2,     0,     1,     4,     0,     2,     2,     5,     2,
       0,     1,     1,     2,     2,     0,     2,     2,     2,     0,
       2,     1,     2,     0,     1,     2,     2,     2,     2,     2,
       2,     2,     3,     1,     2,     2,     2,     1,     1,     0,
       2,     2,     2,     2,     0,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     5,     4,
       4,     6,     2,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const SQLParser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "IT_SELECT", "IT_UNION",
  "IT_WHERE", "IT_FROM", "GT_TIMES", "IT_AS", "GT_DOT", "IT_INNER",
  "IT_LEFT", "IT_OUTER", "IT_ON", "IT_JOIN", "IT_OR", "IT_AND",
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
  "_Q_O_QGT_EQUAL_E_S_QNAME_E_C_E_Opt", "FieldOrKey",
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
       103,     0,    -1,   150,   104,    -1,   107,   106,   104,    -1,
      -1,    44,    -1,    44,   107,    -1,    -1,   106,   105,    -1,
     114,    -1,   119,    -1,   108,    -1,   111,    -1,    83,    46,
     110,   171,    -1,    82,    74,    -1,    -1,   109,    -1,    79,
      67,   171,   113,    -1,    75,    67,    -1,    68,    -1,    66,
      -1,    -1,   112,    -1,    -1,    45,    46,   171,   115,    47,
     128,   117,    48,   118,    -1,    49,   128,    -1,    -1,   117,
     116,    -1,    -1,   118,   124,    -1,    41,    64,   171,   120,
     123,    -1,    -1,   144,    -1,    49,   147,    -1,    -1,   122,
     121,    -1,    38,   147,   122,    -1,   150,    -1,   125,   127,
      -1,    86,    -1,    42,    -1,    23,    86,    -1,    -1,   126,
      -1,   170,   133,   129,    -1,   131,    50,    51,   144,    52,
     171,   144,    -1,    53,    51,   144,    -1,   132,    51,   170,
     144,    -1,    -1,   129,   142,    -1,    43,   170,    -1,    -1,
     130,    -1,    -1,    40,    -1,   136,   135,    -1,    47,    91,
      48,    -1,    -1,   134,    -1,   137,   138,   140,    -1,    39,
      -1,    63,   140,    -1,    78,    -1,    77,    -1,    70,    -1,
     141,    -1,    72,    -1,    56,    -1,    57,    -1,    55,    81,
      -1,    62,    -1,    58,    -1,    71,    -1,    60,    -1,    59,
      -1,    65,    -1,    -1,    76,    -1,    80,    -1,    61,    -1,
      73,    -1,    69,    84,    -1,    -1,   139,    -1,    37,    -1,
      54,    -1,    53,    51,    -1,    42,   143,    -1,    21,    22,
      -1,    22,    -1,   210,    -1,   205,    -1,   209,    -1,    85,
      47,   143,     8,   133,    48,    -1,    47,   170,   146,    48,
      -1,    49,   170,    -1,    -1,   146,   145,    -1,    47,   143,
     149,    48,    -1,    49,   143,    -1,    -1,   149,   148,    -1,
     153,   152,    -1,     4,   153,    -1,    -1,   152,   151,    -1,
       3,   162,   157,   159,   161,    -1,     5,   181,    -1,    -1,
     154,    -1,     6,   172,   155,    -1,    -1,   156,    -1,    18,
      91,    -1,    17,    27,    91,    -1,    -1,   158,    -1,    19,
      91,    -1,    -1,   160,    -1,   165,   164,    -1,     7,    -1,
      49,   165,    -1,    -1,   164,   163,    -1,   181,   168,    -1,
      -1,     8,    -1,   166,   170,    -1,    -1,   167,    -1,   171,
       9,   170,    -1,   170,    -1,    86,    -1,    88,    -1,    86,
      -1,    88,    -1,   178,   177,    -1,    10,    -1,    49,    -1,
      11,    12,    -1,    13,   181,    -1,    -1,   174,    -1,   173,
      14,   178,   175,    -1,    -1,   177,   176,    -1,   171,   180,
      -1,    47,   150,    48,     8,   171,    -1,   166,   171,    -1,
      -1,   179,    -1,   182,    -1,   185,   184,    -1,    15,   185,
      -1,    -1,   184,   183,    -1,   188,   187,    -1,    16,   188,
      -1,    -1,   187,   186,    -1,   189,    -1,   192,   190,    -1,
      -1,   191,    -1,    23,   192,    -1,    24,   192,    -1,    25,
     192,    -1,    26,   192,    -1,    27,   192,    -1,    28,   192,
      -1,    20,    22,    -1,    20,    21,    22,    -1,   193,    -1,
     196,   195,    -1,    29,   196,    -1,    30,   196,    -1,   207,
      -1,   208,    -1,    -1,   195,   194,    -1,   199,   198,    -1,
       7,   199,    -1,    31,   199,    -1,    -1,   198,   197,    -1,
      32,   200,    -1,    29,   200,    -1,    30,   200,    -1,   200,
      -1,   201,    -1,   202,    -1,   210,    -1,   205,    -1,   209,
      -1,   169,    -1,    22,    -1,    47,   181,    48,    -1,    33,
      47,   181,   204,    48,    -1,    34,    47,   181,    48,    -1,
      35,    47,   181,    48,    -1,    36,    47,   181,    49,   181,
      48,    -1,    49,   181,    -1,    -1,   204,   203,    -1,   206,
      -1,   207,    -1,   208,    -1,    91,    -1,    94,    -1,    97,
      -1,    92,    -1,    95,    -1,    98,    -1,    93,    -1,    96,
      -1,    99,    -1,   100,    -1,   101,    -1,    87,    -1
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
     103,   105,   108,   109,   111,   115,   123,   127,   132,   133,
     136,   139,   140,   142,   143,   145,   148,   152,   153,   155,
     159,   161,   164,   166,   168,   170,   172,   174,   176,   178,
     181,   183,   185,   187,   189,   191,   193,   194,   196,   198,
     200,   202,   205,   206,   208,   210,   212,   215,   218,   221,
     223,   225,   227,   229,   236,   241,   244,   245,   248,   253,
     256,   257,   260,   263,   266,   267,   270,   276,   279,   280,
     282,   286,   287,   289,   292,   296,   297,   299,   302,   303,
     305,   308,   310,   313,   314,   317,   320,   321,   323,   326,
     327,   329,   333,   335,   337,   339,   341,   343,   346,   348,
     350,   353,   356,   357,   359,   364,   365,   368,   371,   377,
     380,   381,   383,   385,   388,   391,   392,   395,   398,   401,
     402,   405,   407,   410,   411,   413,   416,   419,   422,   425,
     428,   431,   434,   438,   440,   443,   446,   449,   451,   453,
     454,   457,   460,   463,   466,   467,   470,   473,   476,   479,
     481,   483,   485,   487,   489,   491,   493,   495,   499,   505,
     510,   515,   522,   525,   526,   529,   531,   533,   535,   537,
     539,   541,   543,   545,   547,   549,   551,   553,   555,   557
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SQLParser::yyrline_[] =
  {
         0,   306,   306,   309,   312,   314,   318,   321,   323,   327,
     328,   329,   330,   334,   338,   341,   343,   347,   348,   352,
     353,   356,   358,   362,   362,   372,   375,   377,   380,   382,
     386,   394,   397,   401,   406,   408,   412,   415,   421,   427,
     428,   432,   435,   437,   441,   452,   456,   459,   464,   466,
     470,   475,   477,   480,   482,   486,   493,   501,   504,   508,
     511,   514,   517,   520,   523,   526,   529,   532,   535,   538,
     541,   544,   547,   550,   553,   556,   561,   563,   567,   568,
     572,   575,   581,   584,   588,   589,   593,   596,   599,   605,
     608,   609,   610,   611,   617,   625,   631,   634,   642,   649,
     655,   658,   665,   677,   683,   686,   693,   710,   716,   719,
     723,   732,   736,   740,   745,   753,   756,   760,   768,   771,
     775,   780,   786,   792,   795,   802,   814,   816,   820,   826,
     829,   835,   840,   847,   848,   852,   853,   857,   870,   873,
     876,   882,   888,   891,   897,   910,   914,   923,   934,   943,
     949,   952,   958,   963,   975,   982,   985,   993,  1005,  1012,
    1015,  1022,  1027,  1046,  1049,  1054,  1057,  1060,  1063,  1066,
    1069,  1072,  1075,  1081,  1086,  1098,  1101,  1104,  1105,  1110,
    1113,  1121,  1133,  1136,  1143,  1146,  1153,  1156,  1159,  1162,
    1166,  1167,  1168,  1169,  1170,  1171,  1172,  1178,  1184,  1189,
    1194,  1199,  1205,  1211,  1214,  1221,  1222,  1223,  1227,  1228,
    1229,  1233,  1234,  1235,  1239,  1240,  1241,  1245,  1246,  1250
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
      95,    96,    97,    98,    99,   100,   101
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int SQLParser::yyeof_ = 0;
  const int SQLParser::yylast_ = 307;
  const int SQLParser::yynnts_ = 109;
  const int SQLParser::yyempty_ = -2;
  const int SQLParser::yyfinal_ = 67;
  const int SQLParser::yyterror_ = 1;
  const int SQLParser::yyerrcode_ = 256;
  const int SQLParser::yyntokens_ = 102;

  const unsigned int SQLParser::yyuser_token_number_max_ = 356;
  const SQLParser::token_number_type SQLParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 2577 "lib/SQLParser/SQLParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 1270 "lib/SQLParser/SQLParser.ypp"
 /*** Additional Code ***/

void w3c_sw::SQLParser::error(const SQLParser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}

/* START SQLDriver (@@ stand-alone would allow it to be shared with other parsers */

namespace w3c_sw {

SQLDriver::SQLDriver(class sqlContext& _context)
    : YaccDriver("", NULL), trace_scanning(false),
      trace_parsing(false), context(_context),
      root(NULL), curIsPrimary(false)
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

