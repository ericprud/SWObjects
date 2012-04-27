
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
#line 214 "lib/SQLParser/SQLParser.ypp"

#include "SQLScanner.hpp"

/* Line 317 of lalr1.cc  */
#line 294 "lib/SQLParser/SQLParser.ypp"

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
#line 310 "lib/SQLParser/SQLParser.ypp"
    {
	driver.root = (yysemantic_stack_[(2) - (1)].p_Select);
    }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 339 "lib/SQLParser/SQLParser.ypp"
    {
	driver.curCreate = driver.tables[*(yysemantic_stack_[(3) - (3)].p_NAME)];
	delete (yysemantic_stack_[(3) - (3)].p_NAME);
      }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 342 "lib/SQLParser/SQLParser.ypp"
    {
	  driver.curCreate = NULL;
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 376 "lib/SQLParser/SQLParser.ypp"
    {
	driver.curCreate = new sql::schema::Relation(*(yysemantic_stack_[(3) - (3)].p_NAME));
      }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 378 "lib/SQLParser/SQLParser.ypp"
    {
	  driver.tables[*(yysemantic_stack_[(9) - (3)].p_NAME)] = driver.curCreate;
	  delete (yysemantic_stack_[(9) - (3)].p_NAME);
	  driver.curCreate = NULL;
      }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 400 "lib/SQLParser/SQLParser.ypp"
    {
	driver.curCreate = new sql::schema::Relation(*(yysemantic_stack_[(5) - (3)].p_NAME));
	driver.inserts.push_back(new sql::Insert(*(yysemantic_stack_[(5) - (3)].p_NAME), (yysemantic_stack_[(5) - (4)].p_Attributes), (yysemantic_stack_[(5) - (5)].p_RValue)));
	delete (yysemantic_stack_[(5) - (3)].p_NAME);
    }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 408 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Attributes) = NULL;
    }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 415 "lib/SQLParser/SQLParser.ypp"
    {
	w3c_sw_LINEN << "ignoring non-standard inserts\n";
    }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 426 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_RValue) = new sql::RConstants((yysemantic_stack_[(3) - (2)].p_Expressions));
    }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 429 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_RValue) = new sql::RSelection((yysemantic_stack_[(1) - (1)].p_Select));
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 435 "lib/SQLParser/SQLParser.ypp"
    {
	w3c_sw_LINEN << "ignoring parameters\n";
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 455 "lib/SQLParser/SQLParser.ypp"
    {
	driver.curAttributeName = (yysemantic_stack_[(1) - (1)].p_NAME);
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 457 "lib/SQLParser/SQLParser.ypp"
    {
	sql::schema::Field* f = new sql::schema::Field(*(yysemantic_stack_[(3) - (1)].p_NAME), (yysemantic_stack_[(3) - (3)].p_TypeSize).type, (yysemantic_stack_[(3) - (3)].p_TypeSize).size);
	driver.curCreate->addField(f);
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 460 "lib/SQLParser/SQLParser.ypp"
    {
	driver.curAttributeName = NULL;
	delete (yysemantic_stack_[(5) - (1)].p_NAME);
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 465 "lib/SQLParser/SQLParser.ypp"
    {
	driver.curCreate->setPrimaryKey(new sql::schema::PrimaryKey((yysemantic_stack_[(3) - (3)].p_Attributes)));
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 468 "lib/SQLParser/SQLParser.ypp"
    {
	driver.curCreate->addUniqueKey(new sql::schema::Key((yysemantic_stack_[(4) - (4)].p_Attributes)));
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 489 "lib/SQLParser/SQLParser.ypp"
    {
	driver.curCreate->addForeignKey(new sql::schema::ForeignKey((yysemantic_stack_[(7) - (4)].p_Attributes), *(yysemantic_stack_[(7) - (6)].p_NAME), new sql::schema::Key((yysemantic_stack_[(7) - (7)].p_Attributes))));
	delete (yysemantic_stack_[(7) - (6)].p_NAME);
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 495 "lib/SQLParser/SQLParser.ypp"
    {
	w3c_sw_LINEN << "ignoring constraint name\n";
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 506 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TypeSize).type = (yysemantic_stack_[(2) - (1)].p_SchemaDatatype);
	(yyval.p_TypeSize).size = (yysemantic_stack_[(2) - (2)].p_int);
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 513 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(3) - (2)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 521 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_int) = SQL_PRECISION_unspecified;
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 528 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype).sql::DataType::make(sql::DataType::TYPENAME_char, (yysemantic_stack_[(3) - (1)].p_Nationality), (yysemantic_stack_[(3) - (3)].p_Variability));
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 531 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype).sql::DataType::make(sql::DataType::TYPENAME_char, sql::DataType::VARIABILITY_varying);
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 534 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype).sql::DataType::make(sql::DataType::TYPENAME_binary, (yysemantic_stack_[(2) - (2)].p_Variability));
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 537 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype).sql::DataType::make(sql::DataType::TYPENAME_binary, sql::DataType::VARIABILITY_varying);
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 540 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype).sql::DataType::make(sql::DataType::TYPENAME_int);
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 543 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype).sql::DataType::make(sql::DataType::TYPENAME_int);
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 546 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype).sql::DataType::make(sql::DataType::TYPENAME_int);
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 549 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype).sql::DataType::make(sql::DataType::TYPENAME_int);
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 552 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype).sql::DataType::make(sql::DataType::TYPENAME_int);
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 555 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype).sql::DataType::make(sql::DataType::TYPENAME_float);
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 558 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype).sql::DataType::make(sql::DataType::TYPENAME_real);
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 561 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype).sql::DataType::make(sql::DataType::TYPENAME_double);
    }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 564 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype).sql::DataType::make(sql::DataType::TYPENAME_boolean);
    }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 567 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype).sql::DataType::make(sql::DataType::TYPENAME_date);
    }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 570 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype).sql::DataType::make(sql::DataType::TYPENAME_time);
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 573 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype).sql::DataType::make(sql::DataType::TYPENAME_timestamp);
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 576 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype).sql::DataType::make(sql::DataType::TYPENAME_datetime);
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 579 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype).sql::DataType::make(sql::DataType::TYPENAME_interval);
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 585 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Nationality) = sql::DataType::NATIONALITY_domestic;
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 588 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Nationality) = sql::DataType::NATIONALITY_national;
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 599 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Variability) = sql::DataType::VARIABILITY_varying;
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 602 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Variability) = sql::DataType::VARIABILITY_blob;
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 608 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Variability) = sql::DataType::VARIABILITY_fixed;
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 620 "lib/SQLParser/SQLParser.ypp"
    {
	std::vector<sql::Attribute>* attrs = new std::vector<sql::Attribute>();
	attrs->push_back(*driver.curAttributeName);
	driver.curCreate->setPrimaryKey(new sql::schema::PrimaryKey(attrs));
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 625 "lib/SQLParser/SQLParser.ypp"
    {
	w3c_sw_LINEN << "ignoring DEFAULT\n";
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 628 "lib/SQLParser/SQLParser.ypp"
    {
	w3c_sw_LINEN << "ignoring NOT NULL\n";
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 631 "lib/SQLParser/SQLParser.ypp"
    {
	std::vector<sql::Attribute>* attrs = new std::vector<sql::Attribute>();
	attrs->push_back(*driver.curAttributeName);
	driver.curCreate->addUniqueKey(new sql::schema::Key(attrs));
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 636 "lib/SQLParser/SQLParser.ypp"
    {
	std::vector<sql::Attribute>* attrs = new std::vector<sql::Attribute>();
	attrs->push_back(sql::Attribute(*driver.curAttributeName));
	sql::schema::ForeignKey* fk = new sql::schema::ForeignKey(attrs, *(yysemantic_stack_[(3) - (2)].p_NAME), new sql::schema::Key((yysemantic_stack_[(3) - (3)].p_Attributes)));
	driver.curCreate->addForeignKey(fk);
	delete (yysemantic_stack_[(3) - (2)].p_NAME);
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 646 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::IsNullConstraint();
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 653 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::CastConstraint((yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_TypeSize).type, (yysemantic_stack_[(6) - (5)].p_TypeSize).size);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 659 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(4) - (3)].p_Attributes)->insert((yysemantic_stack_[(4) - (3)].p_Attributes)->begin(), *(yysemantic_stack_[(4) - (2)].p_NAME));
	delete (yysemantic_stack_[(4) - (2)].p_NAME);
	(yyval.p_Attributes) = (yysemantic_stack_[(4) - (3)].p_Attributes);
}
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 667 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = (yysemantic_stack_[(2) - (2)].p_NAME);
}
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 673 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Attributes) = new std::vector<sql::Attribute>();
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 676 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Attributes)->push_back(*(yysemantic_stack_[(2) - (2)].p_NAME));
	delete (yysemantic_stack_[(2) - (2)].p_NAME);
	(yyval.p_Attributes) = (yysemantic_stack_[(2) - (1)].p_Attributes);
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 684 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(4) - (3)].p_Expressions)->insert((yysemantic_stack_[(4) - (3)].p_Expressions)->begin(), (yysemantic_stack_[(4) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(4) - (3)].p_Expressions);
}
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 691 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 697 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 700 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 707 "lib/SQLParser/SQLParser.ypp"
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

  case 115:

/* Line 678 of lalr1.cc  */
#line 719 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Select) = (yysemantic_stack_[(2) - (2)].p_Select);
}
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 725 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Selects) = new std::vector<sql::SQLQuery*>();
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 728 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Selects)->push_back((yysemantic_stack_[(2) - (2)].p_Select));
	(yyval.p_Selects) = (yysemantic_stack_[(2) - (1)].p_Selects);
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 735 "lib/SQLParser/SQLParser.ypp"
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

  case 119:

/* Line 678 of lalr1.cc  */
#line 752 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 758 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 765 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TableList).joins = (yysemantic_stack_[(3) - (2)].p_TableList).joins;
	(yyval.p_TableList).exprs = (yysemantic_stack_[(3) - (2)].p_TableList).exprs;
	if ((yysemantic_stack_[(3) - (3)].p_Expression) != NULL)
	    (yyval.p_TableList).exprs->push_back((yysemantic_stack_[(3) - (3)].p_Expression));
}
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 774 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TableList).joins = new std::vector<sql::Join*>();;
	(yyval.p_TableList).exprs = new std::vector<const sql::Expression*>();;
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 782 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 787 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(3) - (3)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(3) - (3)].p_Expression);
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 795 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_int) = -1;
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 802 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 810 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_int) = -1;
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 817 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (2)].p_AttributeList)->insert((yysemantic_stack_[(2) - (2)].p_AttributeList)->begin(), (yysemantic_stack_[(2) - (1)].p_AliasedSelect));
	(yyval.p_AttributeList) = new std::vector<sql::AliasedSelect*>((yysemantic_stack_[(2) - (2)].p_AttributeList)->begin(), (yysemantic_stack_[(2) - (2)].p_AttributeList)->end());
	delete (yysemantic_stack_[(2) - (2)].p_AttributeList);
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 822 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AttributeList) = new std::vector<sql::AliasedSelect*>();
      }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 828 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AliasedSelect) = (yysemantic_stack_[(2) - (2)].p_AliasedSelect);
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 834 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AttributeList) = new std::vector<sql::AliasedSelect*>();
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 837 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_AttributeList)->push_back((yysemantic_stack_[(2) - (2)].p_AliasedSelect));
	(yyval.p_AttributeList) = (yysemantic_stack_[(2) - (1)].p_AttributeList);
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 844 "lib/SQLParser/SQLParser.ypp"
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

  case 140:

/* Line 678 of lalr1.cc  */
#line 862 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = (yysemantic_stack_[(2) - (2)].p_NAME);
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 868 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = NULL;
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 871 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = (yysemantic_stack_[(1) - (1)].p_NAME);
      }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 877 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::AliasAttrConstraint(sql::AliasAttr(sql::RelVar(*(yysemantic_stack_[(3) - (1)].p_NAME)), sql::Attribute(*(yysemantic_stack_[(3) - (3)].p_NAME))));
	delete (yysemantic_stack_[(3) - (1)].p_NAME);
	delete (yysemantic_stack_[(3) - (3)].p_NAME);
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 882 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_Expression) = new sql::AliasAttrConstraint(sql::AliasAttr(sql::RelVar(""), sql::Attribute(*(yysemantic_stack_[(1) - (1)].p_NAME))));
	delete (yysemantic_stack_[(1) - (1)].p_NAME);
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 899 "lib/SQLParser/SQLParser.ypp"
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

  case 150:

/* Line 678 of lalr1.cc  */
#line 912 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_bool) = false;
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 915 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_bool) = false;
      }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 918 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_bool) = true;
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 924 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 930 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 933 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(1) - (1)].p_Expression);
      }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 939 "lib/SQLParser/SQLParser.ypp"
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

  case 157:

/* Line 678 of lalr1.cc  */
#line 952 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TableList).joins = new std::vector<sql::Join*>();
	(yyval.p_TableList).exprs = new std::vector<const sql::Expression*>();
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 956 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TableList).joins->push_back((yysemantic_stack_[(2) - (2)].p_JoinExpression).join);
	if ((yysemantic_stack_[(2) - (2)].p_JoinExpression).expr != NULL)
	    (yysemantic_stack_[(2) - (1)].p_TableList).exprs->push_back((yysemantic_stack_[(2) - (2)].p_JoinExpression).expr);
	(yyval.p_TableList) = (yysemantic_stack_[(2) - (1)].p_TableList);
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 965 "lib/SQLParser/SQLParser.ypp"
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

  case 160:

/* Line 678 of lalr1.cc  */
#line 976 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_tableAlias).relation = NULL;
	(yyval.p_tableAlias).subselect = (yysemantic_stack_[(5) - (2)].p_Select);
	(yyval.p_tableAlias).alias = new sql::RelVar(*(yysemantic_stack_[(5) - (5)].p_NAME));
	delete (yysemantic_stack_[(5) - (5)].p_NAME);
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 985 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = (yysemantic_stack_[(2) - (2)].p_NAME);
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 991 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = NULL;
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 994 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = (yysemantic_stack_[(1) - (1)].p_NAME);
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 1000 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::HomologConstraint("CONCAT", (yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 1011 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1017 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 1020 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 1028 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::DisjunctionConstraint((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1040 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 1047 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 1050 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 1058 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::ConjunctionConstraint((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 1070 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 1077 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 1080 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 1092 "lib/SQLParser/SQLParser.ypp"
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

  case 178:

/* Line 678 of lalr1.cc  */
#line 1111 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = NULL;
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 1119 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 1122 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 1125 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 1128 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 1131 "lib/SQLParser/SQLParser.ypp"
    {
        (yyval.p_BooleanComparator) = new sql::BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 1134 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 1137 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_BooleanComparator) = new sql::IsNullProxy;
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 1140 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_BooleanComparator) = new sql::IsNotNullProxy;
}
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 1151 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::ArithmeticSum((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 1163 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 1166 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 1175 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 1178 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 1186 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::ArithmeticProduct((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1198 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 1201 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 1208 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 1211 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 1218 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 1221 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 1224 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 1238 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 1244 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(5) - (4)].p_Expressions)->insert((yysemantic_stack_[(5) - (4)].p_Expressions)->begin(), (yysemantic_stack_[(5) - (3)].p_Expression));
	(yyval.p_Expression) = new sql::HomologConstraint("CONCAT", (yysemantic_stack_[(5) - (4)].p_Expressions)->begin(), (yysemantic_stack_[(5) - (4)].p_Expressions)->end());
	delete (yysemantic_stack_[(5) - (4)].p_Expressions);
    }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 1249 "lib/SQLParser/SQLParser.ypp"
    {
	std::vector<const sql::Expression*> v;
	v.push_back((yysemantic_stack_[(4) - (3)].p_Expression));
	(yyval.p_Expression) = new sql::HomologConstraint("LCASE", v.begin(), v.end());
    }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 1254 "lib/SQLParser/SQLParser.ypp"
    {
	std::vector<const sql::Expression*> v;
	v.push_back((yysemantic_stack_[(4) - (3)].p_Expression));
	(yyval.p_Expression) = new sql::HomologConstraint("UCASE", v.begin(), v.end());
    }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 1259 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::RegexConstraint((yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression));
    }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 1265 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 1271 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 1274 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 1310 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::LiteralConstraint(*(yysemantic_stack_[(1) - (1)].p_NAME));
	delete (yysemantic_stack_[(1) - (1)].p_NAME);
    }
    break;



/* Line 678 of lalr1.cc  */
#line 1874 "lib/SQLParser/SQLParser.cpp"
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
  const short int SQLParser::yypact_ninf_ = -260;
  const short int
  SQLParser::yypact_[] =
  {
        29,     0,   -55,   -18,   -27,   -25,    21,    40,   105,  -260,
    -260,  -260,  -260,  -260,  -260,    63,  -260,  -260,  -260,   227,
     227,   227,    65,    67,    74,    76,   141,    81,   118,  -260,
     136,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,   153,  -260,  -260,  -260,   154,    17,
    -260,  -260,  -260,  -260,   122,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,   -68,   -68,  -260,
     -68,   -68,    82,  -260,   120,  -260,  -260,   169,  -260,  -260,
    -260,   141,   141,   141,   141,   137,    37,   -29,  -260,    66,
     135,   -51,  -260,   -51,  -260,  -260,   173,   174,   175,    89,
     141,   141,   141,   141,   141,   141,  -260,  -260,   -21,    13,
    -260,  -260,   143,  -260,    -1,  -260,   117,  -260,   -68,     1,
    -260,  -260,   192,  -260,  -260,   147,   148,   150,  -260,   190,
     192,    17,   196,  -260,   176,   109,  -260,   183,   141,  -260,
    -260,  -260,  -260,  -260,   141,  -260,   141,  -260,   141,  -260,
     182,  -260,  -260,  -260,  -260,  -260,  -260,  -260,   141,   141,
    -260,  -260,  -260,   141,   141,  -260,   -51,    14,  -260,   158,
    -260,  -260,  -260,  -260,   121,  -260,  -260,  -260,  -260,    68,
    -260,  -260,   141,   228,   159,   -68,  -260,  -260,   141,  -260,
    -260,     4,   119,  -260,   123,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,   162,  -260,  -260,
     -28,   170,  -260,   141,  -260,   164,  -260,  -260,  -260,   132,
    -260,  -260,  -260,  -260,  -260,  -260,    -5,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,   168,   171,   -44,  -260,   212,
    -260,  -260,  -260,   209,  -260,   208,  -260,  -260,  -260,    71,
      37,  -260,   172,   -51,   194,  -260,  -260,  -260,   177,  -260,
    -260,  -260,  -260,  -260,   138,  -260,  -260,  -260,  -260,   130,
    -260,  -260,  -260,  -260,    -5,   -68,  -260,   -29,  -260,   -51,
    -260,  -260,   197,  -260,   -51,  -260,   143,   103,   200,   228,
    -260,   178,  -260,  -260,   235,  -260,   108,   162,  -260,   143,
    -260,  -260,  -260,   -28,  -260,   143,  -260,  -260,   141,  -260,
    -260,  -260,    37,  -260,  -260,  -260,   -31,  -260,   201,  -260,
    -260,  -260,  -260,  -260,  -260,   225,   -68,   101,   163,  -260,
    -260,   143,   202,  -260,    37,   -68,   203,  -260,  -260,  -260,
    -260,  -260,   143,  -260,  -260
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  SQLParser::yydefact_[] =
  {
         0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
      13,    11,    12,     9,    10,     4,   116,   133,   100,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   145,   231,
     146,   220,   223,   226,   221,   224,   227,   222,   225,   228,
     102,   229,   230,   208,   123,   135,   207,   144,     0,   141,
     166,   170,   174,   176,   178,   188,   194,   199,   204,   205,
     206,   103,   217,   218,   219,   104,   101,     0,     0,    21,
       0,     0,    18,     1,     4,     5,     2,   114,   202,   203,
     201,     0,     0,     0,     0,     0,     0,     0,   124,   127,
     132,     0,   139,     0,   142,   137,   164,   168,   172,     0,
       0,     0,     0,     0,     0,     0,   177,   179,   189,   196,
     147,   148,    34,    26,    24,    14,     0,    19,     0,     5,
       3,     8,     0,   117,   215,     0,     0,     0,   209,     0,
       0,   162,   120,   157,     0,     0,   128,   130,     0,   136,
     145,   146,   143,   140,     0,   167,     0,   171,     0,   175,
       0,   186,   180,   181,   182,   183,   184,   185,     0,     0,
     195,   192,   193,     0,     0,   200,     0,     0,    35,     0,
      23,    22,    25,    20,     0,    17,    16,     6,   115,     0,
     211,   212,     0,    85,     0,     0,   163,   159,     0,   121,
     122,   149,     0,   125,     0,   131,   118,   134,   165,   169,
     173,   187,   190,   191,   197,   198,   108,     0,    33,    40,
      61,    61,   210,     0,   216,     0,    93,    68,    94,     0,
      76,    77,    80,    83,    82,    79,    91,    70,    84,    73,
      81,    75,    86,    72,    71,     0,    65,     0,    74,     0,
     161,   119,   150,     0,   151,     0,   158,   126,   129,     0,
       0,    37,    55,     0,     0,    29,    50,    62,     0,    47,
      15,   214,   213,    78,     0,    89,    92,    69,   105,     0,
      66,    63,    88,    87,    91,     0,   152,     0,   106,     0,
     109,   112,    39,    56,    57,    60,     0,     0,     0,    85,
      90,     0,    67,   160,   154,   107,     0,     0,    38,     0,
      58,    51,    31,    61,    30,     0,    48,    64,     0,   155,
     156,   110,     0,   113,    36,    52,    27,    28,     0,    53,
     153,   111,    43,    42,    32,    45,     0,    49,     0,    46,
      41,     0,     0,    98,     0,     0,     0,    54,    44,    59,
      97,    96,     0,    95,    99
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SQLParser::yypgoto_[] =
  {
      -260,  -260,   184,  -260,  -260,   140,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,   -47,  -260,
    -260,  -260,  -260,  -260,    46,  -260,  -260,   -24,  -260,  -260,
    -260,  -260,  -260,  -260,    -7,  -260,  -260,   -83,  -259,  -260,
    -260,   -23,  -260,  -260,  -102,  -260,  -260,   149,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,   134,
     139,  -260,  -260,  -260,   -85,   -66,  -260,  -260,  -260,  -260,
    -260,  -260,    -4,  -260,  -260,   -26,  -260,  -260,   133,  -260,
    -260,   144,  -260,  -260,   128,  -260,  -260,  -260,    79,  -260,
    -260,  -260,     2,  -260,  -260,     6,    30,  -260,  -260,  -260,
    -260,  -260,  -260,   186,   188,  -260,  -260
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SQLParser::yydefgoto_[] =
  {
        -1,     8,    76,   121,    74,     9,    10,   174,    11,   117,
     118,    12,   172,   173,    13,   169,   304,   287,   316,    14,
     167,   298,   282,   208,   324,   325,   329,   330,   255,   289,
     319,   327,   284,   299,   256,   257,   258,   235,   270,   271,
     236,   237,   274,   266,   267,   238,   337,    43,   168,   280,
     249,   251,   313,   296,    15,   123,    77,    16,   189,   190,
      88,    89,   136,   137,   195,   196,    44,   139,    90,    45,
      93,    94,    95,    46,    47,    48,   132,   245,   309,   310,
     246,   191,   133,   186,   187,    49,   145,    96,    50,   147,
      97,    51,   149,    98,    52,    53,   106,   107,    54,    55,
     160,   108,    56,   165,   109,    57,    58,    59,    60,   214,
     179,    61,    62,    63,    64,    65,    66
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int SQLParser::yytable_ninf_ = -149;
  const short int
  SQLParser::yytable_[] =
  {
        85,   112,   113,   129,   114,   115,   142,    17,   143,   158,
     159,    67,   322,   252,   242,   243,   253,     1,   272,   130,
     163,   131,   110,    18,   111,    92,   254,   301,   184,    68,
      19,    20,     1,    21,    22,    23,    24,    25,   273,   140,
     315,   141,    69,     2,    70,   164,   318,     3,    26,    78,
      79,    80,   176,   207,   244,   124,   125,   126,   127,   323,
      18,   110,   140,   111,   141,   209,   264,   170,    71,   171,
     265,     2,   339,    32,    33,     3,    35,    36,     4,    38,
      39,   206,     5,   344,   134,   135,     6,    72,     7,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    73,     4,  -138,    75,  -138,
       5,   150,   151,    81,     6,    82,     7,   212,   213,   240,
     278,   279,    83,   332,    84,   259,    27,  -147,    29,    86,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,   333,    99,   334,  -148,   100,   101,   102,   103,
     104,   105,   302,   303,   335,   336,   215,   311,   312,    87,
     202,   203,   241,    91,    18,   119,   116,   281,   285,   204,
     205,    19,    20,   122,    21,    22,    23,    24,    25,   152,
     153,   154,   155,   156,   157,   138,   128,   261,   144,    26,
     146,   166,   148,   175,   295,     1,   180,   181,   183,   300,
     182,   188,   193,   194,   192,   201,   210,   211,   239,   293,
     250,   131,   247,   262,   253,   263,   248,   268,   259,   269,
     275,   276,   277,   291,   283,   340,   290,   307,   288,   321,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,   286,   297,   308,   328,
      18,   341,   305,   338,   326,   343,   317,   260,   120,   177,
     331,    22,    23,    24,    25,   306,   216,   292,   217,   342,
     185,   178,   197,   294,   314,    26,   200,   198,     0,     0,
       0,     0,   320,   218,   219,   220,   221,   222,   223,   224,
     199,   225,   226,   227,   161,   228,   162,     0,     0,     0,
     229,   230,   231,     0,     0,     0,   232,   233,   234,     0,
       0,     0,     0,     0,     0,     0,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42
  };

  /* YYCHECK.  */
  const short int
  SQLParser::yycheck_[] =
  {
        26,    67,    68,    86,    70,    71,    91,     7,    93,    30,
      31,    66,    43,    41,    10,    11,    44,     3,    62,    48,
       7,    87,    90,    23,    92,     8,    54,   286,   130,    47,
      30,    31,     3,    33,    34,    35,    36,    37,    82,    90,
     299,    92,    69,    42,    69,    32,   305,    46,    48,    19,
      20,    21,   118,    39,    50,    81,    82,    83,    84,    90,
      23,    90,    90,    92,    92,   167,    71,    68,    47,    70,
      75,    42,   331,    94,    95,    46,    97,    98,    77,   100,
     101,   166,    81,   342,    18,    19,    85,    47,    87,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,     0,    77,    90,    45,    92,
      81,    22,    23,    48,    85,    48,    87,    49,    50,   185,
      49,    50,    48,    22,    48,   210,    89,     9,    91,    48,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    41,    21,    43,     9,    24,    25,    26,    27,
      28,    29,    49,    50,    53,    54,   182,    49,    50,     6,
     158,   159,   188,     9,    23,    45,    84,   250,   253,   163,
     164,    30,    31,     4,    33,    34,    35,    36,    37,   100,
     101,   102,   103,   104,   105,    50,    49,   213,    15,    48,
      16,    48,    17,    76,   279,     3,    49,    49,     8,   284,
      50,     5,    93,    20,    28,    23,    48,    86,    49,   275,
      48,   277,    93,    49,    44,    83,    93,    49,   303,    48,
       8,    12,    14,    93,    52,    23,    88,    49,    51,   312,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,    52,    50,    13,    24,
      23,   334,    52,    90,    53,    52,   303,   211,    74,   119,
     326,    34,    35,    36,    37,   289,    38,   274,    40,   335,
     131,   122,   138,   277,   297,    48,   148,   144,    -1,    -1,
      -1,    -1,   308,    55,    56,    57,    58,    59,    60,    61,
     146,    63,    64,    65,   108,    67,   108,    -1,    -1,    -1,
      72,    73,    74,    -1,    -1,    -1,    78,    79,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  SQLParser::yystos_[] =
  {
         0,     3,    42,    46,    77,    81,    85,    87,   106,   110,
     111,   113,   116,   119,   124,   159,   162,     7,    23,    30,
      31,    33,    34,    35,    36,    37,    48,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   152,   171,   174,   178,   179,   180,   190,
     193,   196,   199,   200,   203,   204,   207,   210,   211,   212,
     213,   216,   217,   218,   219,   220,   221,    66,    47,    69,
      69,    47,    47,     0,   109,    45,   107,   161,   211,   211,
     211,    48,    48,    48,    48,   190,    48,     6,   165,   166,
     173,     9,     8,   175,   176,   177,   192,   195,   198,    21,
      24,    25,    26,    27,    28,    29,   201,   202,   206,   209,
      90,    92,   180,   180,   180,   180,    84,   114,   115,    45,
     107,   108,     4,   160,   190,   190,   190,   190,    49,   152,
      48,   180,   181,   187,    18,    19,   167,   168,    50,   172,
      90,    92,   179,   179,    15,   191,    16,   194,    17,   197,
      22,    23,   203,   203,   203,   203,   203,   203,    30,    31,
     205,   218,   219,     7,    32,   208,    48,   125,   153,   120,
      68,    70,   117,   118,   112,    76,   180,   110,   162,   215,
      49,    49,    50,     8,   159,   175,   188,   189,     5,   163,
     164,   186,    28,    93,    20,   169,   170,   174,   193,   196,
     199,    23,   207,   207,   210,   210,   179,    39,   128,   159,
      48,    86,    49,    50,   214,   190,    38,    40,    55,    56,
      57,    58,    59,    60,    61,    63,    64,    65,    67,    72,
      73,    74,    78,    79,    80,   142,   145,   146,   150,    49,
     180,   190,    10,    11,    50,   182,   185,    93,    93,   155,
      48,   156,    41,    44,    54,   133,   139,   140,   141,   179,
     139,   190,    49,    83,    71,    75,   148,   149,    49,    48,
     143,   144,    62,    82,   147,     8,    12,    14,    49,    50,
     154,   152,   127,    52,   137,   179,    52,   122,    51,   134,
      88,    93,   149,   180,   187,   179,   158,    50,   126,   138,
     179,   153,    49,    50,   121,    52,   142,    49,    13,   183,
     184,    49,    50,   157,   156,   153,   123,   133,   153,   135,
     190,   152,    43,    90,   129,   130,    53,   136,    24,   131,
     132,   180,    22,    41,    43,    53,    54,   151,    90,   153,
      23,   152,   180,    52,   153
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
     355,   356,   357,   358,   359
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  SQLParser::yyr1_[] =
  {
         0,   105,   106,   106,   107,   107,   108,   109,   109,   110,
     110,   110,   110,   110,   112,   111,   113,   114,   115,   115,
     116,   116,   117,   117,   118,   118,   120,   119,   121,   122,
     122,   123,   123,   124,   125,   125,   126,   127,   127,   128,
     128,   129,   130,   130,   131,   132,   132,   134,   135,   133,
     133,   133,   133,   136,   136,   137,   137,   138,   138,   139,
     140,   141,   141,   142,   143,   144,   144,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   146,   146,   147,   147,   148,
     148,   149,   149,   150,   150,   151,   151,   151,   151,   151,
     152,   152,   152,   152,   152,   152,   153,   154,   155,   155,
     156,   157,   158,   158,   159,   160,   161,   161,   162,   163,
     164,   164,   165,   166,   166,   167,   167,   168,   168,   169,
     170,   170,   171,   171,   172,   173,   173,   174,   175,   175,
     176,   177,   177,   178,   178,   179,   179,   180,   180,   181,
     182,   182,   182,   183,   184,   184,   185,   186,   186,   187,
     187,   188,   189,   189,   190,   191,   192,   192,   193,   194,
     195,   195,   196,   197,   198,   198,   199,   200,   201,   201,
     202,   202,   202,   202,   202,   202,   202,   202,   203,   204,
     205,   205,   205,   205,   206,   206,   207,   208,   208,   209,
     209,   210,   210,   210,   210,   211,   211,   211,   211,   212,
     213,   213,   213,   213,   214,   215,   215,   216,   216,   216,
     217,   217,   217,   218,   218,   218,   219,   219,   219,   220,
     220,   221
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  SQLParser::yyr2_[] =
  {
         0,     2,     2,     3,     0,     1,     2,     0,     2,     1,
       1,     1,     1,     1,     0,     6,     4,     2,     0,     1,
       4,     2,     1,     1,     0,     1,     0,     9,     2,     0,
       2,     0,     2,     5,     0,     1,     2,     0,     2,     3,
       1,     2,     1,     1,     2,     0,     1,     0,     0,     5,
       1,     3,     4,     0,     2,     0,     1,     0,     1,     7,
       2,     0,     1,     2,     3,     0,     1,     3,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     0,     1,     1,     1,     1,
       2,     0,     1,     1,     1,     2,     2,     2,     1,     3,
       1,     1,     1,     1,     1,     6,     4,     2,     0,     2,
       4,     2,     0,     2,     2,     2,     0,     2,     5,     2,
       0,     1,     3,     0,     1,     2,     3,     0,     1,     2,
       0,     1,     2,     1,     2,     0,     2,     2,     0,     1,
       2,     0,     1,     3,     1,     1,     1,     1,     1,     2,
       1,     1,     2,     2,     0,     1,     4,     0,     2,     2,
       5,     2,     0,     1,     2,     2,     0,     2,     2,     2,
       0,     2,     2,     2,     0,     2,     1,     2,     0,     1,
       2,     2,     2,     2,     2,     2,     2,     3,     1,     2,
       2,     2,     1,     1,     0,     2,     2,     2,     2,     0,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     3,
       5,     4,     4,     6,     2,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
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
  "IT_BOOLEAN", "IT_BINARY", "IT_VARBINARY", "IT_INTO", "IT_INTERVAL",
  "IT_WRITE", "IT_TABLES", "IT_READ", "IT_LARGE", "IT_SMALLINT", "IT_TIME",
  "IT_BIGINT", "IT_VARYING", "IT_EXISTS", "IT_UNLOCK", "IT_NATIONAL",
  "IT_DECIMAL", "IT_NUMERIC", "IT_LOCK", "IT_CHARACTER", "IT_PRECISION",
  "IT_IF", "IT_ALTER", "IT_ADD", "IT_DROP", "IT_OBJECT", "IT_CAST", "NAME",
  "STRING_LITERAL1", "STRING_LITERAL2", "INTEGER", "INTEGER_POSITIVE",
  "INTEGER_NEGATIVE", "DECIMAL", "DECIMAL_POSITIVE", "DECIMAL_NEGATIVE",
  "DOUBLE", "DOUBLE_POSITIVE", "DOUBLE_NEGATIVE", "HEX_LITERAL", "IT_TRUE",
  "IT_FALSE", "$accept", "Statement", "_QGT_SEMI_E_Opt",
  "_O_QGT_SEMI_E_S_QChange_E_C", "_Q_O_QGT_SEMI_E_S_QChange_E_C_E_Star",
  "Change", "Alter", "$@1", "Drop", "_O_QIT_IF_E_S_QIT_EXISTS_E_C",
  "_Q_O_QIT_IF_E_S_QIT_EXISTS_E_C_E_Opt", "Lock",
  "_O_QIT_READ_E_Or_QIT_WRITE_E_C",
  "_Q_O_QIT_READ_E_Or_QIT_WRITE_E_C_E_Opt", "Create", "$@2",
  "_O_QGT_COMMA_E_S_QFieldOrKey_E_C",
  "_Q_O_QGT_COMMA_E_S_QFieldOrKey_E_C_E_Star", "_QParam_E_Star", "Insert",
  "_QAttrList_E_Opt", "_O_QGT_COMMA_E_S_QConstList_E_C",
  "_Q_O_QGT_COMMA_E_S_QConstList_E_C_E_Star",
  "_O_QIT_VALUES_E_S_QConstList_E_S_QGT_COMMA_E_S_QConstList_E_Star_Or_QSelectUnion_E_C",
  "Param", "_O_QNAME_E_Or_QIT_DEFAULT_E_C", "_O_QGT_EQUAL_E_S_QNAME_E_C",
  "_Q_O_QGT_EQUAL_E_S_QNAME_E_C_E_Opt", "FieldOrKey", "$@3", "$@4",
  "_QLinkDetails_E_Star", "_QIT_KEY_E_Opt", "_QAttribute_E_Opt",
  "ForeignKey", "_O_QIT_CONSTRAINT_E_S_QAttribute_E_C",
  "_Q_O_QIT_CONSTRAINT_E_S_QAttribute_E_C_E_Opt", "Sized",
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
       106,     0,    -1,   159,   107,    -1,   110,   109,   107,    -1,
      -1,    45,    -1,    45,   110,    -1,    -1,   109,   108,    -1,
     119,    -1,   124,    -1,   113,    -1,   116,    -1,   111,    -1,
      -1,    85,    47,   180,   112,    86,   139,    -1,    87,    47,
     115,   180,    -1,    84,    76,    -1,    -1,   114,    -1,    81,
      69,   180,   118,    -1,    77,    69,    -1,    70,    -1,    68,
      -1,    -1,   117,    -1,    -1,    46,    47,   180,   120,    48,
     133,   122,    49,   123,    -1,    50,   133,    -1,    -1,   122,
     121,    -1,    -1,   123,   129,    -1,    42,    66,   180,   125,
     128,    -1,    -1,   153,    -1,    50,   156,    -1,    -1,   127,
     126,    -1,    39,   156,   127,    -1,   159,    -1,   130,   132,
      -1,    90,    -1,    43,    -1,    24,    90,    -1,    -1,   131,
      -1,    -1,    -1,   179,   134,   142,   135,   136,    -1,   139,
      -1,    54,    52,   153,    -1,    41,   137,   138,   153,    -1,
      -1,   136,   151,    -1,    -1,    52,    -1,    -1,   179,    -1,
     141,    51,    52,   153,    53,   180,   153,    -1,    44,   179,
      -1,    -1,   140,    -1,   145,   144,    -1,    48,    93,    49,
      -1,    -1,   143,    -1,   146,   147,   149,    -1,    40,    -1,
      64,   149,    -1,    65,    -1,    80,    -1,    79,    -1,    72,
      -1,   150,    -1,    74,    -1,    57,    -1,    58,    -1,    56,
      83,    -1,    63,    -1,    59,    -1,    73,    -1,    61,    -1,
      60,    -1,    67,    -1,    -1,    78,    -1,    82,    -1,    62,
      -1,    75,    -1,    71,    88,    -1,    -1,   148,    -1,    38,
      -1,    55,    -1,    54,    52,    -1,    43,   152,    -1,    22,
      23,    -1,    41,    -1,    53,   180,   153,    -1,    23,    -1,
     221,    -1,   102,    -1,   216,    -1,   220,    -1,    89,    48,
     152,     8,   142,    49,    -1,    48,   179,   155,    49,    -1,
      50,   179,    -1,    -1,   155,   154,    -1,    48,   152,   158,
      49,    -1,    50,   152,    -1,    -1,   158,   157,    -1,   162,
     161,    -1,     4,   162,    -1,    -1,   161,   160,    -1,     3,
     171,   166,   168,   170,    -1,     5,   190,    -1,    -1,   163,
      -1,     6,   181,   164,    -1,    -1,   165,    -1,    19,    93,
      -1,    18,    28,    93,    -1,    -1,   167,    -1,    20,    93,
      -1,    -1,   169,    -1,   174,   173,    -1,     7,    -1,    50,
     174,    -1,    -1,   173,   172,    -1,   190,   177,    -1,    -1,
       8,    -1,   175,   179,    -1,    -1,   176,    -1,   180,     9,
     179,    -1,   179,    -1,    90,    -1,    92,    -1,    90,    -1,
      92,    -1,   187,   186,    -1,    10,    -1,    50,    -1,    11,
      12,    -1,    13,   190,    -1,    -1,   183,    -1,   182,    14,
     187,   184,    -1,    -1,   186,   185,    -1,   180,   189,    -1,
      48,   159,    49,     8,   180,    -1,   175,   180,    -1,    -1,
     188,    -1,   193,   192,    -1,    15,   193,    -1,    -1,   192,
     191,    -1,   196,   195,    -1,    16,   196,    -1,    -1,   195,
     194,    -1,   199,   198,    -1,    17,   199,    -1,    -1,   198,
     197,    -1,   200,    -1,   203,   201,    -1,    -1,   202,    -1,
      24,   203,    -1,    25,   203,    -1,    26,   203,    -1,    27,
     203,    -1,    28,   203,    -1,    29,   203,    -1,    21,    23,
      -1,    21,    22,    23,    -1,   204,    -1,   207,   206,    -1,
      30,   207,    -1,    31,   207,    -1,   218,    -1,   219,    -1,
      -1,   206,   205,    -1,   210,   209,    -1,     7,   210,    -1,
      32,   210,    -1,    -1,   209,   208,    -1,    33,   211,    -1,
      30,   211,    -1,    31,   211,    -1,   211,    -1,   212,    -1,
     213,    -1,   178,    -1,   152,    -1,    48,   190,    49,    -1,
      34,    48,   190,   215,    49,    -1,    35,    48,   190,    49,
      -1,    36,    48,   190,    49,    -1,    37,    48,   190,    50,
     190,    49,    -1,    50,   190,    -1,    -1,   215,   214,    -1,
     217,    -1,   218,    -1,   219,    -1,    93,    -1,    96,    -1,
      99,    -1,    94,    -1,    97,    -1,   100,    -1,    95,    -1,
      98,    -1,   101,    -1,   103,    -1,   104,    -1,    91,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  SQLParser::yyprhs_[] =
  {
         0,     0,     3,     6,    10,    11,    13,    16,    17,    20,
      22,    24,    26,    28,    30,    31,    38,    43,    46,    47,
      49,    54,    57,    59,    61,    62,    64,    65,    75,    78,
      79,    82,    83,    86,    92,    93,    95,    98,    99,   102,
     106,   108,   111,   113,   115,   118,   119,   121,   122,   123,
     129,   131,   135,   140,   141,   144,   145,   147,   148,   150,
     158,   161,   162,   164,   167,   171,   172,   174,   178,   180,
     183,   185,   187,   189,   191,   193,   195,   197,   199,   202,
     204,   206,   208,   210,   212,   214,   215,   217,   219,   221,
     223,   226,   227,   229,   231,   233,   236,   239,   242,   244,
     248,   250,   252,   254,   256,   258,   265,   270,   273,   274,
     277,   282,   285,   286,   289,   292,   295,   296,   299,   305,
     308,   309,   311,   315,   316,   318,   321,   325,   326,   328,
     331,   332,   334,   337,   339,   342,   343,   346,   349,   350,
     352,   355,   356,   358,   362,   364,   366,   368,   370,   372,
     375,   377,   379,   382,   385,   386,   388,   393,   394,   397,
     400,   406,   409,   410,   412,   415,   418,   419,   422,   425,
     428,   429,   432,   435,   438,   439,   442,   444,   447,   448,
     450,   453,   456,   459,   462,   465,   468,   471,   475,   477,
     480,   483,   486,   488,   490,   491,   494,   497,   500,   503,
     504,   507,   510,   513,   516,   518,   520,   522,   524,   526,
     530,   536,   541,   546,   553,   556,   557,   560,   562,   564,
     566,   568,   570,   572,   574,   576,   578,   580,   582,   584,
     586,   588
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SQLParser::yyrline_[] =
  {
         0,   310,   310,   313,   316,   318,   322,   325,   327,   331,
     332,   333,   334,   335,   339,   339,   348,   352,   355,   357,
     361,   362,   366,   367,   370,   372,   376,   376,   386,   389,
     391,   394,   396,   400,   408,   411,   415,   420,   422,   426,
     429,   435,   441,   442,   446,   449,   451,   455,   457,   455,
     464,   465,   468,   473,   475,   478,   480,   483,   485,   489,
     495,   500,   502,   506,   513,   521,   524,   528,   531,   534,
     537,   540,   543,   546,   549,   552,   555,   558,   561,   564,
     567,   570,   573,   576,   579,   585,   588,   594,   595,   599,
     602,   608,   611,   615,   616,   620,   625,   628,   631,   636,
     646,   649,   650,   651,   652,   653,   659,   667,   673,   676,
     684,   691,   697,   700,   707,   719,   725,   728,   735,   752,
     758,   761,   765,   774,   778,   782,   787,   795,   798,   802,
     810,   813,   817,   822,   828,   834,   837,   844,   856,   858,
     862,   868,   871,   877,   882,   889,   890,   894,   895,   899,
     912,   915,   918,   924,   930,   933,   939,   952,   956,   965,
     976,   985,   991,   994,  1000,  1011,  1017,  1020,  1028,  1040,
    1047,  1050,  1058,  1070,  1077,  1080,  1087,  1092,  1111,  1114,
    1119,  1122,  1125,  1128,  1131,  1134,  1137,  1140,  1146,  1151,
    1163,  1166,  1169,  1170,  1175,  1178,  1186,  1198,  1201,  1208,
    1211,  1218,  1221,  1224,  1227,  1231,  1232,  1233,  1234,  1238,
    1244,  1249,  1254,  1259,  1265,  1271,  1274,  1281,  1282,  1283,
    1287,  1288,  1289,  1293,  1294,  1295,  1299,  1300,  1301,  1305,
    1306,  1310
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
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int SQLParser::yyeof_ = 0;
  const int SQLParser::yylast_ = 331;
  const int SQLParser::yynnts_ = 117;
  const int SQLParser::yyempty_ = -2;
  const int SQLParser::yyfinal_ = 73;
  const int SQLParser::yyterror_ = 1;
  const int SQLParser::yyerrcode_ = 256;
  const int SQLParser::yyntokens_ = 105;

  const unsigned int SQLParser::yyuser_token_number_max_ = 359;
  const SQLParser::token_number_type SQLParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 2722 "lib/SQLParser/SQLParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 1330 "lib/SQLParser/SQLParser.ypp"
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
      curAttributeName(NULL)
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

