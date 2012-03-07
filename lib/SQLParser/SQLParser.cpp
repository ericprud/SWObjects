
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

  case 78:

/* Line 678 of lalr1.cc  */
#line 567 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_bool) = true;
    }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 570 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_bool) = false;
    }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 576 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_bool) = false;
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 588 "lib/SQLParser/SQLParser.ypp"
    {
	driver.curIsPrimary = true;
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 591 "lib/SQLParser/SQLParser.ypp"
    {
	w3c_sw_LINEN << "ignoring DEFAULT\n";
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 594 "lib/SQLParser/SQLParser.ypp"
    {
	w3c_sw_LINEN << "ignoring NOT NULL\n";
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 600 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::IsNullConstraint();
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 606 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::CastConstraint((yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_TypeSize).type, (yysemantic_stack_[(6) - (5)].p_TypeSize).size);
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 612 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(4) - (3)].p_Attributes)->insert((yysemantic_stack_[(4) - (3)].p_Attributes)->begin(), *(yysemantic_stack_[(4) - (2)].p_NAME));
	delete (yysemantic_stack_[(4) - (2)].p_NAME);
	(yyval.p_Attributes) = (yysemantic_stack_[(4) - (3)].p_Attributes);
}
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 620 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = (yysemantic_stack_[(2) - (2)].p_NAME);
}
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 626 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Attributes) = new std::vector<sql::Attribute>();
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 629 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Attributes)->push_back(*(yysemantic_stack_[(2) - (2)].p_NAME));
	delete (yysemantic_stack_[(2) - (2)].p_NAME);
	(yyval.p_Attributes) = (yysemantic_stack_[(2) - (1)].p_Attributes);
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 637 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(4) - (3)].p_Expressions)->insert((yysemantic_stack_[(4) - (3)].p_Expressions)->begin(), (yysemantic_stack_[(4) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(4) - (3)].p_Expressions);
}
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 644 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 650 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 653 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 660 "lib/SQLParser/SQLParser.ypp"
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

  case 101:

/* Line 678 of lalr1.cc  */
#line 672 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Select) = (yysemantic_stack_[(2) - (2)].p_Select);
}
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 678 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Selects) = new std::vector<sql::SQLQuery*>();
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 681 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Selects)->push_back((yysemantic_stack_[(2) - (2)].p_Select));
	(yyval.p_Selects) = (yysemantic_stack_[(2) - (1)].p_Selects);
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 688 "lib/SQLParser/SQLParser.ypp"
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

  case 105:

/* Line 678 of lalr1.cc  */
#line 705 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 711 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 718 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TableList).joins = (yysemantic_stack_[(3) - (2)].p_TableList).joins;
	(yyval.p_TableList).exprs = (yysemantic_stack_[(3) - (2)].p_TableList).exprs;
	if ((yysemantic_stack_[(3) - (3)].p_Expression) != NULL)
	    (yyval.p_TableList).exprs->push_back((yysemantic_stack_[(3) - (3)].p_Expression));
}
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 727 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TableList).joins = new std::vector<sql::Join*>();;
	(yyval.p_TableList).exprs = new std::vector<const sql::Expression*>();;
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 735 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 740 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(3) - (3)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(3) - (3)].p_Expression);
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 748 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_int) = -1;
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 755 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 763 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_int) = -1;
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 770 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (2)].p_AttributeList)->insert((yysemantic_stack_[(2) - (2)].p_AttributeList)->begin(), (yysemantic_stack_[(2) - (1)].p_AliasedSelect));
	(yyval.p_AttributeList) = new std::vector<sql::AliasedSelect*>((yysemantic_stack_[(2) - (2)].p_AttributeList)->begin(), (yysemantic_stack_[(2) - (2)].p_AttributeList)->end());
	delete (yysemantic_stack_[(2) - (2)].p_AttributeList);
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 775 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AttributeList) = new std::vector<sql::AliasedSelect*>();
      }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 781 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AliasedSelect) = (yysemantic_stack_[(2) - (2)].p_AliasedSelect);
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 787 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AttributeList) = new std::vector<sql::AliasedSelect*>();
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 790 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_AttributeList)->push_back((yysemantic_stack_[(2) - (2)].p_AliasedSelect));
	(yyval.p_AttributeList) = (yysemantic_stack_[(2) - (1)].p_AttributeList);
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 797 "lib/SQLParser/SQLParser.ypp"
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

  case 126:

/* Line 678 of lalr1.cc  */
#line 815 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = (yysemantic_stack_[(2) - (2)].p_NAME);
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 821 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = NULL;
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 824 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = (yysemantic_stack_[(1) - (1)].p_NAME);
      }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 830 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::AliasAttrConstraint(sql::AliasAttr(sql::RelVar(*(yysemantic_stack_[(3) - (1)].p_NAME)), sql::Attribute(*(yysemantic_stack_[(3) - (3)].p_NAME))));
	delete (yysemantic_stack_[(3) - (1)].p_NAME);
	delete (yysemantic_stack_[(3) - (3)].p_NAME);
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 835 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_Expression) = new sql::AliasAttrConstraint(sql::AliasAttr(sql::RelVar(""), sql::Attribute(*(yysemantic_stack_[(1) - (1)].p_NAME))));
	delete (yysemantic_stack_[(1) - (1)].p_NAME);
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 852 "lib/SQLParser/SQLParser.ypp"
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

  case 136:

/* Line 678 of lalr1.cc  */
#line 865 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_bool) = false;
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 868 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_bool) = false;
      }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 871 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_bool) = true;
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 877 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 883 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 886 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(1) - (1)].p_Expression);
      }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 892 "lib/SQLParser/SQLParser.ypp"
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

  case 143:

/* Line 678 of lalr1.cc  */
#line 905 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TableList).joins = new std::vector<sql::Join*>();
	(yyval.p_TableList).exprs = new std::vector<const sql::Expression*>();
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 909 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TableList).joins->push_back((yysemantic_stack_[(2) - (2)].p_JoinExpression).join);
	if ((yysemantic_stack_[(2) - (2)].p_JoinExpression).expr != NULL)
	    (yysemantic_stack_[(2) - (1)].p_TableList).exprs->push_back((yysemantic_stack_[(2) - (2)].p_JoinExpression).expr);
	(yyval.p_TableList) = (yysemantic_stack_[(2) - (1)].p_TableList);
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 918 "lib/SQLParser/SQLParser.ypp"
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

  case 146:

/* Line 678 of lalr1.cc  */
#line 929 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_tableAlias).relation = NULL;
	(yyval.p_tableAlias).subselect = (yysemantic_stack_[(5) - (2)].p_Select);
	(yyval.p_tableAlias).alias = new sql::RelVar(*(yysemantic_stack_[(5) - (5)].p_NAME));
	delete (yysemantic_stack_[(5) - (5)].p_NAME);
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 938 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = (yysemantic_stack_[(2) - (2)].p_NAME);
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 944 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = NULL;
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 947 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = (yysemantic_stack_[(1) - (1)].p_NAME);
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 958 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::DisjunctionConstraint((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 970 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 977 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 980 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 988 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::ConjunctionConstraint((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1000 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1007 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 1010 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 1022 "lib/SQLParser/SQLParser.ypp"
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

  case 161:

/* Line 678 of lalr1.cc  */
#line 1041 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = NULL;
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 1049 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 1052 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 1055 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1058 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 1061 "lib/SQLParser/SQLParser.ypp"
    {
        (yyval.p_BooleanComparator) = new sql::BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 1064 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1067 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_BooleanComparator) = new sql::IsNullProxy;
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 1070 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_BooleanComparator) = new sql::IsNotNullProxy;
}
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 1081 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::ArithmeticSum((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 1093 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 1096 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 1105 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 1108 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 1116 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::ArithmeticProduct((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 1128 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 1131 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 1138 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 1141 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 1148 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 1151 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 1154 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 1167 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::IsNullConstraint();
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 1173 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 1179 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(5) - (4)].p_Expressions)->insert((yysemantic_stack_[(5) - (4)].p_Expressions)->begin(), (yysemantic_stack_[(5) - (3)].p_Expression));
	(yyval.p_Expression) = new sql::HomologConstraint("CONCAT", (yysemantic_stack_[(5) - (4)].p_Expressions)->begin(), (yysemantic_stack_[(5) - (4)].p_Expressions)->end());
	delete (yysemantic_stack_[(5) - (4)].p_Expressions);
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1184 "lib/SQLParser/SQLParser.ypp"
    {
	std::vector<const sql::Expression*> v;
	v.push_back((yysemantic_stack_[(4) - (3)].p_Expression));
	(yyval.p_Expression) = new sql::HomologConstraint("LCASE", v.begin(), v.end());
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 1189 "lib/SQLParser/SQLParser.ypp"
    {
	std::vector<const sql::Expression*> v;
	v.push_back((yysemantic_stack_[(4) - (3)].p_Expression));
	(yyval.p_Expression) = new sql::HomologConstraint("UCASE", v.begin(), v.end());
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 1194 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::RegexConstraint((yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression));
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 1200 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 1206 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 1209 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 1245 "lib/SQLParser/SQLParser.ypp"
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
  const short int SQLParser::yypact_ninf_ = -251;
  const short int
  SQLParser::yypact_[] =
  {
        77,    -1,   -46,    -6,   -22,     5,    15,    70,  -251,  -251,
    -251,  -251,  -251,    37,  -251,  -251,  -251,   132,   132,   132,
      36,    54,    59,    74,   102,   108,  -251,   114,  -251,  -251,
    -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,   119,
    -251,  -251,  -251,   121,    19,  -251,  -251,  -251,  -251,   157,
    -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,
    -251,  -251,   -76,   -76,  -251,   -76,    46,  -251,    95,  -251,
    -251,   147,  -251,  -251,  -251,   102,   102,   102,   102,   105,
     -30,  -251,    -3,   106,   -29,  -251,   -29,  -251,  -251,   142,
     145,    53,   102,   102,   102,   102,   102,   102,  -251,  -251,
     112,    13,  -251,  -251,   111,  -251,     3,    89,  -251,   -76,
     -15,  -251,  -251,   166,  -251,  -251,   122,   124,   125,  -251,
     166,    19,   170,  -251,   151,    85,  -251,   167,   102,  -251,
    -251,  -251,  -251,  -251,   102,  -251,   102,  -251,   165,  -251,
    -251,  -251,  -251,  -251,  -251,  -251,   102,   102,  -251,  -251,
    -251,   102,   102,  -251,   -29,     4,  -251,   159,  -251,  -251,
    -251,  -251,  -251,  -251,  -251,  -251,    40,  -251,  -251,   102,
     144,   -76,  -251,  -251,   102,  -251,  -251,    27,   118,  -251,
     130,  -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,
    -251,  -251,   175,  -251,  -251,    -4,  -251,   102,  -251,   190,
     231,  -251,  -251,  -251,   247,  -251,   250,  -251,  -251,  -251,
      67,   149,  -251,  -251,   -29,   214,  -251,  -251,   216,   220,
     198,  -251,  -251,   -76,  -251,   -30,  -251,   -29,  -251,  -251,
     225,  -251,  -251,  -251,  -251,   218,  -251,   111,    71,   222,
     -29,  -251,  -251,  -251,   196,  -251,  -251,  -251,  -251,  -251,
    -251,   -60,  -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,
     232,   200,  -251,  -251,   265,  -251,   149,    78,   175,  -251,
    -251,  -251,    -4,  -251,   111,   111,  -251,   197,  -251,  -251,
    -251,    87,   191,  -251,  -251,   -60,   102,  -251,  -251,   275,
    -251,   149,  -251,  -251,   -31,  -251,   233,  -251,  -251,   262,
     149,   235,  -251,   239,  -251,  -251,   198,  -251,  -251,  -251,
    -251,   266,   -76,  -251,  -251,  -251,  -251,   240,   204,  -251,
    -251,   111,  -251,  -251,  -251
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  SQLParser::yydefact_[] =
  {
         0,     0,     0,     0,     0,     0,     0,     0,     7,    11,
      12,     9,    10,     4,   102,   119,   194,     0,     0,     0,
       0,     0,     0,     0,     0,   131,   217,   132,   206,   209,
     212,   207,   210,   213,   208,   211,   214,   215,   216,   109,
     121,   193,   130,     0,   127,   150,   153,   157,   159,   161,
     171,   177,   182,   187,   188,   189,   191,   203,   204,   205,
     192,   190,     0,     0,    18,     0,    15,     1,     4,     5,
       2,   100,   185,   186,   184,     0,     0,     0,     0,     0,
       0,   110,   113,   118,     0,   125,     0,   128,   123,   151,
     155,     0,     0,     0,     0,     0,     0,     0,   160,   162,
     172,   179,   133,   134,    31,    23,    21,     0,    16,     0,
       5,     3,     8,     0,   103,   201,     0,     0,     0,   195,
       0,   148,   106,   143,     0,     0,   114,   116,     0,   122,
     131,   132,   129,   126,     0,   154,     0,   158,     0,   169,
     163,   164,   165,   166,   167,   168,     0,     0,   178,   175,
     176,     0,     0,   183,     0,     0,    32,     0,    20,    19,
      22,    17,    14,    13,     6,   101,     0,   197,   198,     0,
       0,     0,   149,   145,     0,   107,   108,   135,     0,   111,
       0,   117,   104,   120,   152,   156,   170,   173,   174,   180,
     181,    94,     0,    30,    37,    51,   196,     0,   202,     0,
       0,   147,   105,   136,     0,   137,     0,   144,   112,   115,
       0,     0,    34,    54,     0,     0,    26,    52,     0,     0,
      76,   200,   199,     0,   138,     0,    92,     0,    95,    87,
       0,    98,    89,    90,    88,    36,    50,     0,     0,     0,
       0,    82,    60,    83,     0,    67,    68,    71,    74,    73,
      70,    80,    75,    64,    72,    66,    77,    63,    62,    48,
      57,     0,    65,   146,   140,    93,     0,     0,     0,    35,
      46,    28,    51,    27,     0,     0,    69,     0,    78,    81,
      61,    44,     0,    58,    55,    80,     0,   141,   142,     0,
      96,     0,    99,    33,    24,    25,     0,    47,    79,     0,
       0,     0,    49,     0,    59,   139,    76,    97,    40,    39,
      29,    42,     0,    86,    85,    84,    56,     0,     0,    43,
      38,     0,    91,    41,    45
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SQLParser::yypgoto_[] =
  {
      -251,  -251,   223,  -251,  -251,   182,  -251,  -251,  -251,  -251,
    -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,
    -251,  -251,  -251,  -251,  -251,  -251,    21,  -251,  -251,  -251,
    -251,   -12,  -251,  -251,  -251,  -251,  -251,    10,  -251,  -251,
    -250,  -212,  -251,  -251,    28,  -251,  -251,  -112,  -251,  -251,
     184,  -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,
    -251,  -251,   171,   177,  -251,  -251,  -251,   -81,   -61,  -251,
    -251,  -251,  -251,  -251,  -251,    75,  -251,  -251,   -24,  -251,
    -251,  -251,   168,  -251,  -251,   169,  -251,  -251,  -251,   120,
    -251,  -251,  -251,     1,  -251,  -251,    -8,    48,  -251,  -251,
    -251,  -251,  -189,  -251,   201,   203,  -188,  -187
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SQLParser::yydefgoto_[] =
  {
        -1,     7,    70,   112,    68,     8,     9,   108,   109,    10,
     160,   161,    11,   157,   273,   238,   294,    12,   155,   269,
     235,   193,   310,   311,   319,   320,   216,   281,   217,   218,
     219,   259,   283,   284,   260,   261,   279,   280,   262,   302,
     231,   156,   228,   210,   212,   292,   267,    13,   114,    71,
      14,   175,   176,    81,    82,   126,   127,   181,   182,    39,
     129,    83,    40,    86,    87,    88,    41,    42,    43,   122,
     206,   287,   288,   207,   177,   123,   172,   173,    44,    45,
     135,    89,    46,   137,    90,    47,    48,    98,    99,    49,
      50,   148,   100,    51,   153,   101,    52,    53,    54,    55,
     198,   166,    56,    57,    58,    59,    60,    61
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int SQLParser::yytable_ninf_ = -135;
  const short int
  SQLParser::yytable_[] =
  {
        79,   104,   105,   132,   106,   133,    15,     1,   170,   277,
     102,   308,   103,   278,   124,   125,   289,   120,    62,   121,
     151,    16,   232,   233,   234,   270,     2,    85,    17,    18,
       3,    19,    20,    21,    22,    23,   213,   203,   204,   214,
      63,   307,   192,   194,   152,    64,    24,   -53,   163,   215,
     314,   115,   116,   117,   118,   309,   102,   130,   103,   131,
       4,    66,   296,   297,     5,    72,    73,    74,     6,   158,
      67,   159,    65,   191,   138,   139,   205,   232,   233,   234,
       1,    69,   130,    75,   131,    25,    26,    27,   196,   197,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    76,   232,   233,   234,  -124,    77,  -124,   299,   324,
     201,   232,   233,   234,   220,   226,   227,  -133,     2,   271,
     272,    78,     3,  -134,    16,    80,   290,   291,   107,   300,
      84,    17,    18,   236,    19,    20,    21,    22,    23,   110,
     301,   146,   147,   189,   190,   199,   265,   187,   188,    24,
     202,   113,     4,   119,    16,   128,     5,   134,   154,   275,
       6,   136,   263,   162,   121,    20,    21,    22,    23,     1,
     167,   229,   168,   221,   169,   174,   179,    91,   178,    24,
      92,    93,    94,    95,    96,    97,   180,   186,    25,    26,
      27,   220,   200,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    29,    30,   195,    32,    33,   208,
      35,    36,   140,   141,   142,   143,   144,   145,    25,    26,
      27,   209,   211,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,   230,   241,    26,   242,   222,   223,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,   321,   243,   244,   245,   246,   247,   248,   249,   224,
     250,   251,   305,   252,   225,   237,   239,   268,   253,   254,
     255,   240,   266,   274,   256,   257,   258,   276,   286,   282,
     285,   298,   303,   306,   313,   312,   315,   316,   322,   318,
     323,   111,   164,   295,   317,   304,   293,   165,   171,   183,
     264,   149,   184,   150,     0,   185
  };

  /* YYCHECK.  */
  const short int
  SQLParser::yycheck_[] =
  {
        24,    62,    63,    84,    65,    86,     7,     3,   120,    69,
      86,    42,    88,    73,    17,    18,   266,    47,    64,    80,
       7,    22,   211,   211,   211,   237,    41,     8,    29,    30,
      45,    32,    33,    34,    35,    36,    40,    10,    11,    43,
      46,   291,    38,   155,    31,    67,    47,    51,   109,    53,
     300,    75,    76,    77,    78,    86,    86,    86,    88,    88,
      75,    46,   274,   275,    79,    17,    18,    19,    83,    66,
       0,    68,    67,   154,    21,    22,    49,   266,   266,   266,
       3,    44,    86,    47,    88,    86,    87,    88,    48,    49,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,    47,   291,   291,   291,    86,    47,    88,    21,   321,
     171,   300,   300,   300,   195,    48,    49,     9,    41,    48,
      49,    47,    45,     9,    22,     6,    48,    49,    82,    42,
       9,    29,    30,   214,    32,    33,    34,    35,    36,    44,
      53,    29,    30,   151,   152,   169,   227,   146,   147,    47,
     174,     4,    75,    48,    22,    49,    79,    15,    47,   240,
      83,    16,   223,    74,   225,    33,    34,    35,    36,     3,
      48,    22,    48,   197,    49,     5,    91,    20,    27,    47,
      23,    24,    25,    26,    27,    28,    19,    22,    86,    87,
      88,   272,    48,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    92,    93,    47,    95,    96,    91,
      98,    99,    92,    93,    94,    95,    96,    97,    86,    87,
      88,    91,    47,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    85,    37,    87,    39,    48,     8,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   312,    54,    55,    56,    57,    58,    59,    60,    12,
      62,    63,   286,    65,    14,    51,    50,    49,    70,    71,
      72,    51,    47,    51,    76,    77,    78,    81,    13,    47,
      80,    84,    91,     8,    22,    52,    51,    48,    48,    23,
      86,    68,   110,   272,   306,   285,   268,   113,   121,   128,
     225,   100,   134,   100,    -1,   136
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  SQLParser::yystos_[] =
  {
         0,     3,    41,    45,    75,    79,    83,   103,   107,   108,
     111,   114,   119,   149,   152,     7,    22,    29,    30,    32,
      33,    34,    35,    36,    47,    86,    87,    88,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   161,
     164,   168,   169,   170,   180,   181,   184,   187,   188,   191,
     192,   195,   198,   199,   200,   201,   204,   205,   206,   207,
     208,   209,    64,    46,    67,    67,    46,     0,   106,    44,
     104,   151,   199,   199,   199,    47,    47,    47,    47,   180,
       6,   155,   156,   163,     9,     8,   165,   166,   167,   183,
     186,    20,    23,    24,    25,    26,    27,    28,   189,   190,
     194,   197,    86,    88,   170,   170,   170,    82,   109,   110,
      44,   104,   105,     4,   150,   180,   180,   180,   180,    48,
      47,   170,   171,   177,    17,    18,   157,   158,    49,   162,
      86,    88,   169,   169,    15,   182,    16,   185,    21,    22,
     191,   191,   191,   191,   191,   191,    29,    30,   193,   206,
     207,     7,    31,   196,    47,   120,   143,   115,    66,    68,
     112,   113,    74,   170,   107,   152,   203,    48,    48,    49,
     149,   165,   178,   179,     5,   153,   154,   176,    27,    91,
      19,   159,   160,   164,   184,   187,    22,   195,   195,   198,
     198,   169,    38,   123,   149,    47,    48,    49,   202,   180,
      48,   170,   180,    10,    11,    49,   172,   175,    91,    91,
     145,    47,   146,    40,    43,    53,   128,   130,   131,   132,
     169,   180,    48,     8,    12,    14,    48,    49,   144,    22,
      85,   142,   204,   208,   209,   122,   169,    51,   117,    50,
      51,    37,    39,    54,    55,    56,    57,    58,    59,    60,
      62,    63,    65,    70,    71,    72,    76,    77,    78,   133,
     136,   137,   140,   170,   177,   169,    47,   148,    49,   121,
     143,    48,    49,   116,    51,   169,    81,    69,    73,   138,
     139,   129,    47,   134,   135,    80,    13,   173,   174,   142,
      48,    49,   147,   146,   118,   128,   143,   143,    84,    21,
      42,    53,   141,    91,   139,   180,     8,   142,    42,    86,
     124,   125,    52,    22,   142,    51,    48,   133,    23,   126,
     127,   170,    48,    86,   143
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
     139,   139,   140,   140,   141,   141,   141,   142,   142,   142,
     142,   142,   143,   144,   145,   145,   146,   147,   148,   148,
     149,   150,   151,   151,   152,   153,   154,   154,   155,   156,
     156,   157,   157,   158,   158,   159,   160,   160,   161,   161,
     162,   163,   163,   164,   165,   165,   166,   167,   167,   168,
     168,   169,   169,   170,   170,   171,   172,   172,   172,   173,
     174,   174,   175,   176,   176,   177,   177,   178,   179,   179,
     180,   181,   182,   183,   183,   184,   185,   186,   186,   187,
     188,   189,   189,   190,   190,   190,   190,   190,   190,   190,
     190,   191,   192,   193,   193,   193,   193,   194,   194,   195,
     196,   196,   197,   197,   198,   198,   198,   198,   199,   199,
     199,   199,   199,   199,   199,   200,   201,   201,   201,   201,
     202,   203,   203,   204,   204,   204,   205,   205,   205,   206,
     206,   206,   207,   207,   207,   208,   208,   209
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
       1,     1,     1,     1,     1,     1,     0,     1,     1,     2,
       0,     1,     1,     1,     2,     2,     2,     1,     1,     1,
       1,     6,     4,     2,     0,     2,     4,     2,     0,     2,
       2,     2,     0,     2,     5,     2,     0,     1,     3,     0,
       1,     2,     3,     0,     1,     2,     0,     1,     2,     1,
       2,     0,     2,     2,     0,     1,     2,     0,     1,     3,
       1,     1,     1,     1,     1,     2,     1,     1,     2,     2,
       0,     1,     4,     0,     2,     2,     5,     2,     0,     1,
       1,     2,     2,     0,     2,     2,     2,     0,     2,     1,
       2,     0,     1,     2,     2,     2,     2,     2,     2,     2,
       3,     1,     2,     2,     2,     1,     1,     0,     2,     2,
       2,     2,     0,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     5,     4,     4,     6,
       2,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
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
  "_QIT_NATIONAL_E_Opt",
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
       103,     0,    -1,   149,   104,    -1,   107,   106,   104,    -1,
      -1,    44,    -1,    44,   107,    -1,    -1,   106,   105,    -1,
     114,    -1,   119,    -1,   108,    -1,   111,    -1,    83,    46,
     110,   170,    -1,    82,    74,    -1,    -1,   109,    -1,    79,
      67,   170,   113,    -1,    75,    67,    -1,    68,    -1,    66,
      -1,    -1,   112,    -1,    -1,    45,    46,   170,   115,    47,
     128,   117,    48,   118,    -1,    49,   128,    -1,    -1,   117,
     116,    -1,    -1,   118,   124,    -1,    41,    64,   170,   120,
     123,    -1,    -1,   143,    -1,    49,   146,    -1,    -1,   122,
     121,    -1,    38,   146,   122,    -1,   149,    -1,   125,   127,
      -1,    86,    -1,    42,    -1,    23,    86,    -1,    -1,   126,
      -1,   169,   133,   129,    -1,   131,    50,    51,   143,    52,
     170,   143,    -1,    53,    51,   143,    -1,   132,    51,   169,
     143,    -1,    -1,   129,   141,    -1,    43,   169,    -1,    -1,
     130,    -1,    -1,    40,    -1,   136,   135,    -1,    47,    91,
      48,    -1,    -1,   134,    -1,   137,    80,   139,    -1,    39,
      -1,    63,   139,    -1,    78,    -1,    77,    -1,    70,    -1,
     140,    -1,    72,    -1,    56,    -1,    57,    -1,    55,    81,
      -1,    62,    -1,    58,    -1,    71,    -1,    60,    -1,    59,
      -1,    65,    -1,    -1,    76,    -1,    73,    -1,    69,    84,
      -1,    -1,   138,    -1,    37,    -1,    54,    -1,    53,    51,
      -1,    42,   142,    -1,    21,    22,    -1,    22,    -1,   209,
      -1,   204,    -1,   208,    -1,    85,    47,   142,     8,   133,
      48,    -1,    47,   169,   145,    48,    -1,    49,   169,    -1,
      -1,   145,   144,    -1,    47,   142,   148,    48,    -1,    49,
     142,    -1,    -1,   148,   147,    -1,   152,   151,    -1,     4,
     152,    -1,    -1,   151,   150,    -1,     3,   161,   156,   158,
     160,    -1,     5,   180,    -1,    -1,   153,    -1,     6,   171,
     154,    -1,    -1,   155,    -1,    18,    91,    -1,    17,    27,
      91,    -1,    -1,   157,    -1,    19,    91,    -1,    -1,   159,
      -1,   164,   163,    -1,     7,    -1,    49,   164,    -1,    -1,
     163,   162,    -1,   180,   167,    -1,    -1,     8,    -1,   165,
     169,    -1,    -1,   166,    -1,   170,     9,   169,    -1,   169,
      -1,    86,    -1,    88,    -1,    86,    -1,    88,    -1,   177,
     176,    -1,    10,    -1,    49,    -1,    11,    12,    -1,    13,
     180,    -1,    -1,   173,    -1,   172,    14,   177,   174,    -1,
      -1,   176,   175,    -1,   170,   179,    -1,    47,   149,    48,
       8,   170,    -1,   165,   170,    -1,    -1,   178,    -1,   181,
      -1,   184,   183,    -1,    15,   184,    -1,    -1,   183,   182,
      -1,   187,   186,    -1,    16,   187,    -1,    -1,   186,   185,
      -1,   188,    -1,   191,   189,    -1,    -1,   190,    -1,    23,
     191,    -1,    24,   191,    -1,    25,   191,    -1,    26,   191,
      -1,    27,   191,    -1,    28,   191,    -1,    20,    22,    -1,
      20,    21,    22,    -1,   192,    -1,   195,   194,    -1,    29,
     195,    -1,    30,   195,    -1,   206,    -1,   207,    -1,    -1,
     194,   193,    -1,   198,   197,    -1,     7,   198,    -1,    31,
     198,    -1,    -1,   197,   196,    -1,    32,   199,    -1,    29,
     199,    -1,    30,   199,    -1,   199,    -1,   200,    -1,   201,
      -1,   209,    -1,   204,    -1,   208,    -1,   168,    -1,    22,
      -1,    47,   180,    48,    -1,    33,    47,   180,   203,    48,
      -1,    34,    47,   180,    48,    -1,    35,    47,   180,    48,
      -1,    36,    47,   180,    49,   180,    48,    -1,    49,   180,
      -1,    -1,   203,   202,    -1,   205,    -1,   206,    -1,   207,
      -1,    91,    -1,    94,    -1,    97,    -1,    92,    -1,    95,
      -1,    98,    -1,    93,    -1,    96,    -1,    99,    -1,   100,
      -1,   101,    -1,    87,    -1
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
     201,   202,   204,   206,   208,   211,   214,   217,   219,   221,
     223,   225,   232,   237,   240,   241,   244,   249,   252,   253,
     256,   259,   262,   263,   266,   272,   275,   276,   278,   282,
     283,   285,   288,   292,   293,   295,   298,   299,   301,   304,
     306,   309,   310,   313,   316,   317,   319,   322,   323,   325,
     329,   331,   333,   335,   337,   339,   342,   344,   346,   349,
     352,   353,   355,   360,   361,   364,   367,   373,   376,   377,
     379,   381,   384,   387,   388,   391,   394,   397,   398,   401,
     403,   406,   407,   409,   412,   415,   418,   421,   424,   427,
     430,   434,   436,   439,   442,   445,   447,   449,   450,   453,
     456,   459,   462,   463,   466,   469,   472,   475,   477,   479,
     481,   483,   485,   487,   489,   491,   495,   501,   506,   511,
     518,   521,   522,   525,   527,   529,   531,   533,   535,   537,
     539,   541,   543,   545,   547,   549,   551,   553
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
     541,   544,   547,   550,   553,   556,   561,   563,   567,   570,
     576,   579,   583,   584,   588,   591,   594,   600,   603,   604,
     605,   606,   612,   620,   626,   629,   637,   644,   650,   653,
     660,   672,   678,   681,   688,   705,   711,   714,   718,   727,
     731,   735,   740,   748,   751,   755,   763,   766,   770,   775,
     781,   787,   790,   797,   809,   811,   815,   821,   824,   830,
     835,   842,   843,   847,   848,   852,   865,   868,   871,   877,
     883,   886,   892,   905,   909,   918,   929,   938,   944,   947,
     953,   958,   970,   977,   980,   988,  1000,  1007,  1010,  1017,
    1022,  1041,  1044,  1049,  1052,  1055,  1058,  1061,  1064,  1067,
    1070,  1076,  1081,  1093,  1096,  1099,  1100,  1105,  1108,  1116,
    1128,  1131,  1138,  1141,  1148,  1151,  1154,  1157,  1161,  1162,
    1163,  1164,  1165,  1166,  1167,  1173,  1179,  1184,  1189,  1194,
    1200,  1206,  1209,  1216,  1217,  1218,  1222,  1223,  1224,  1228,
    1229,  1230,  1234,  1235,  1236,  1240,  1241,  1245
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
  const int SQLParser::yylast_ = 305;
  const int SQLParser::yynnts_ = 108;
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
#line 1265 "lib/SQLParser/SQLParser.ypp"
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

