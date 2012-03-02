
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
#line 210 "lib/SQLParser/SQLParser.ypp"

#include "SQLScanner.hpp"

/* Line 317 of lalr1.cc  */
#line 284 "lib/SQLParser/SQLParser.ypp"

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
#line 300 "lib/SQLParser/SQLParser.ypp"
    {
	driver.root = (yysemantic_stack_[(2) - (1)].p_Select);
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 326 "lib/SQLParser/SQLParser.ypp"
    {
	driver.curCreate = new sql::schema::Relation(*(yysemantic_stack_[(3) - (3)].p_NAME));
      }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 328 "lib/SQLParser/SQLParser.ypp"
    {
	  driver.tables[*(yysemantic_stack_[(9) - (3)].p_NAME)] = driver.curCreate;
	  delete (yysemantic_stack_[(9) - (3)].p_NAME);
	  driver.curCreate = NULL;
      }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 350 "lib/SQLParser/SQLParser.ypp"
    {
	driver.curCreate = new sql::schema::Relation(*(yysemantic_stack_[(5) - (3)].p_NAME));
	driver.inserts.push_back(new sql::Insert(*(yysemantic_stack_[(5) - (3)].p_NAME), (yysemantic_stack_[(5) - (4)].p_Attributes), (yysemantic_stack_[(5) - (5)].p_RValue)));
	delete (yysemantic_stack_[(5) - (3)].p_NAME);
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 358 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Attributes) = NULL;
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 365 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_RValue) = new sql::RConstants((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 368 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_RValue) = new sql::RSelection((yysemantic_stack_[(1) - (1)].p_Select));
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 374 "lib/SQLParser/SQLParser.ypp"
    {
	w3c_sw_LINEN << "ignoring parameters\n";
    }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 394 "lib/SQLParser/SQLParser.ypp"
    {
	sql::schema::Field* f = new sql::schema::Field(*(yysemantic_stack_[(4) - (1)].p_NAME), (yysemantic_stack_[(4) - (2)].p_SchemaDatatype), (yysemantic_stack_[(4) - (3)].p_int));
	driver.curCreate->addField(f);
	if (driver.curIsPrimary) {
	    driver.curIsPrimary = false;
	    std::vector<sql::Attribute>* attrs = new std::vector<sql::Attribute>();
	    attrs->push_back(*(yysemantic_stack_[(4) - (1)].p_NAME));
	    driver.curCreate->setPrimaryKey(new sql::schema::PrimaryKey(attrs));
	}
	delete (yysemantic_stack_[(4) - (1)].p_NAME);
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 405 "lib/SQLParser/SQLParser.ypp"
    {
      driver.curCreate->addForeignKey(new sql::schema::ForeignKey((yysemantic_stack_[(7) - (4)].p_Attributes), *(yysemantic_stack_[(7) - (6)].p_NAME), (yysemantic_stack_[(7) - (7)].p_Attributes)));
      delete (yysemantic_stack_[(7) - (6)].p_NAME);
    }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 409 "lib/SQLParser/SQLParser.ypp"
    {
      driver.curCreate->setPrimaryKey(new sql::schema::PrimaryKey((yysemantic_stack_[(3) - (3)].p_Attributes)));
    }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 412 "lib/SQLParser/SQLParser.ypp"
    {
	w3c_sw_LINEN << "ignoring UNIQUE KEYs\n";
    }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 418 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_SchemaDatatype) = sql::schema::TYPE_int;
    }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 421 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::schema::TYPE_int;
    }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 424 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::schema::TYPE_double;
    }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 427 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::schema::TYPE_date;
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 430 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::schema::TYPE_datetime;
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 433 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::schema::TYPE_char; // !!! need char type
    }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 436 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_SchemaDatatype) = sql::schema::TYPE_varchar;
    }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 442 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(3) - (2)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 450 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_int) = SQL_PRECISION_unspecified;
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 462 "lib/SQLParser/SQLParser.ypp"
    {
	w3c_sw_LINEN << "ignoring constraint name\n";
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 478 "lib/SQLParser/SQLParser.ypp"
    {
	driver.curIsPrimary = true;
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 481 "lib/SQLParser/SQLParser.ypp"
    {
	w3c_sw_LINEN << "ignoring DEFAULT\n";
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 484 "lib/SQLParser/SQLParser.ypp"
    {
	w3c_sw_LINEN << "ignoring NOT NULL\n";
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 490 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::IsNullConstraint();
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 499 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(4) - (3)].p_Attributes)->insert((yysemantic_stack_[(4) - (3)].p_Attributes)->begin(), *(yysemantic_stack_[(4) - (2)].p_NAME));
	delete (yysemantic_stack_[(4) - (2)].p_NAME);
	(yyval.p_Attributes) = (yysemantic_stack_[(4) - (3)].p_Attributes);
}
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 507 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = (yysemantic_stack_[(2) - (2)].p_NAME);
}
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 513 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Attributes) = new std::vector<sql::Attribute>();
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 516 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Attributes)->push_back(*(yysemantic_stack_[(2) - (2)].p_NAME));
	delete (yysemantic_stack_[(2) - (2)].p_NAME);
	(yyval.p_Attributes) = (yysemantic_stack_[(2) - (1)].p_Attributes);
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 524 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(4) - (3)].p_Expressions)->insert((yysemantic_stack_[(4) - (3)].p_Expressions)->begin(), (yysemantic_stack_[(4) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(4) - (3)].p_Expressions);
}
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 531 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 537 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 540 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 547 "lib/SQLParser/SQLParser.ypp"
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

  case 66:

/* Line 678 of lalr1.cc  */
#line 559 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Select) = (yysemantic_stack_[(2) - (2)].p_Select);
}
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 565 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Selects) = new std::vector<sql::SQLQuery*>();
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 568 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Selects)->push_back((yysemantic_stack_[(2) - (2)].p_Select));
	(yyval.p_Selects) = (yysemantic_stack_[(2) - (1)].p_Selects);
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 575 "lib/SQLParser/SQLParser.ypp"
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

  case 70:

/* Line 678 of lalr1.cc  */
#line 592 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 598 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 605 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TableList).joins = (yysemantic_stack_[(3) - (2)].p_TableList).joins;
	(yyval.p_TableList).exprs = (yysemantic_stack_[(3) - (2)].p_TableList).exprs;
	if ((yysemantic_stack_[(3) - (3)].p_Expression) != NULL)
	    (yyval.p_TableList).exprs->push_back((yysemantic_stack_[(3) - (3)].p_Expression));
}
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 614 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TableList).joins = new std::vector<sql::Join*>();;
	(yyval.p_TableList).exprs = new std::vector<const sql::Expression*>();;
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 622 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 627 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(3) - (3)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(3) - (3)].p_Expression);
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 635 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_int) = -1;
    }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 642 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 650 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_int) = -1;
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 657 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (2)].p_AttributeList)->insert((yysemantic_stack_[(2) - (2)].p_AttributeList)->begin(), (yysemantic_stack_[(2) - (1)].p_AliasedSelect));
	(yyval.p_AttributeList) = new std::vector<sql::AliasedSelect*>((yysemantic_stack_[(2) - (2)].p_AttributeList)->begin(), (yysemantic_stack_[(2) - (2)].p_AttributeList)->end());
	delete (yysemantic_stack_[(2) - (2)].p_AttributeList);
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 662 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AttributeList) = new std::vector<sql::AliasedSelect*>();
      }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 668 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AliasedSelect) = (yysemantic_stack_[(2) - (2)].p_AliasedSelect);
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 674 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AttributeList) = new std::vector<sql::AliasedSelect*>();
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 677 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_AttributeList)->push_back((yysemantic_stack_[(2) - (2)].p_AliasedSelect));
	(yyval.p_AttributeList) = (yysemantic_stack_[(2) - (1)].p_AttributeList);
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 684 "lib/SQLParser/SQLParser.ypp"
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

  case 91:

/* Line 678 of lalr1.cc  */
#line 702 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = (yysemantic_stack_[(2) - (2)].p_NAME);
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 708 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = NULL;
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 711 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = (yysemantic_stack_[(1) - (1)].p_NAME);
      }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 717 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::AliasAttrConstraint(sql::AliasAttr(sql::RelVar(*(yysemantic_stack_[(3) - (1)].p_NAME)), sql::Attribute(*(yysemantic_stack_[(3) - (3)].p_NAME))));
	delete (yysemantic_stack_[(3) - (1)].p_NAME);
	delete (yysemantic_stack_[(3) - (3)].p_NAME);
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 722 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_Expression) = new sql::AliasAttrConstraint(sql::AliasAttr(sql::RelVar(""), sql::Attribute(*(yysemantic_stack_[(1) - (1)].p_NAME))));
	delete (yysemantic_stack_[(1) - (1)].p_NAME);
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 739 "lib/SQLParser/SQLParser.ypp"
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

  case 101:

/* Line 678 of lalr1.cc  */
#line 752 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_bool) = false;
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 755 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_bool) = false;
      }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 758 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_bool) = true;
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 764 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 770 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 773 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(1) - (1)].p_Expression);
      }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 779 "lib/SQLParser/SQLParser.ypp"
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

  case 108:

/* Line 678 of lalr1.cc  */
#line 792 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TableList).joins = new std::vector<sql::Join*>();
	(yyval.p_TableList).exprs = new std::vector<const sql::Expression*>();
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 796 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TableList).joins->push_back((yysemantic_stack_[(2) - (2)].p_JoinExpression).join);
	if ((yysemantic_stack_[(2) - (2)].p_JoinExpression).expr != NULL)
	    (yysemantic_stack_[(2) - (1)].p_TableList).exprs->push_back((yysemantic_stack_[(2) - (2)].p_JoinExpression).expr);
	(yyval.p_TableList) = (yysemantic_stack_[(2) - (1)].p_TableList);
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 805 "lib/SQLParser/SQLParser.ypp"
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

  case 111:

/* Line 678 of lalr1.cc  */
#line 816 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_tableAlias).relation = NULL;
	(yyval.p_tableAlias).subselect = (yysemantic_stack_[(5) - (2)].p_Select);
	(yyval.p_tableAlias).alias = new sql::RelVar(*(yysemantic_stack_[(5) - (5)].p_NAME));
	delete (yysemantic_stack_[(5) - (5)].p_NAME);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 825 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = (yysemantic_stack_[(2) - (2)].p_NAME);
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 831 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = NULL;
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 834 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = (yysemantic_stack_[(1) - (1)].p_NAME);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 845 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::DisjunctionConstraint((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 857 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 864 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 867 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 875 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::ConjunctionConstraint((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 887 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 894 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 897 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 909 "lib/SQLParser/SQLParser.ypp"
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

  case 126:

/* Line 678 of lalr1.cc  */
#line 928 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = NULL;
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 936 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 939 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 942 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 945 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 948 "lib/SQLParser/SQLParser.ypp"
    {
        (yyval.p_BooleanComparator) = new sql::BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 951 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 954 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_BooleanComparator) = new sql::IsNullProxy;
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 957 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_BooleanComparator) = new sql::IsNotNullProxy;
}
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 968 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::ArithmeticSum((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 980 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 983 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 992 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 995 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1003 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::ArithmeticProduct((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1015 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1018 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1025 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1028 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1035 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1038 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1041 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 1054 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::IsNullConstraint();
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 1060 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 1066 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(5) - (4)].p_Expressions)->insert((yysemantic_stack_[(5) - (4)].p_Expressions)->begin(), (yysemantic_stack_[(5) - (3)].p_Expression));
	(yyval.p_Expression) = new sql::HomologConstraint("CONCAT", (yysemantic_stack_[(5) - (4)].p_Expressions)->begin(), (yysemantic_stack_[(5) - (4)].p_Expressions)->end());
	delete (yysemantic_stack_[(5) - (4)].p_Expressions);
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 1071 "lib/SQLParser/SQLParser.ypp"
    {
	std::vector<const sql::Expression*> v;
	v.push_back((yysemantic_stack_[(4) - (3)].p_Expression));
	(yyval.p_Expression) = new sql::HomologConstraint("LCASE", v.begin(), v.end());
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 1076 "lib/SQLParser/SQLParser.ypp"
    {
	std::vector<const sql::Expression*> v;
	v.push_back((yysemantic_stack_[(4) - (3)].p_Expression));
	(yyval.p_Expression) = new sql::HomologConstraint("UCASE", v.begin(), v.end());
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 1081 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::RegexConstraint((yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression));
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 1087 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1093 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 1096 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 1132 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::LiteralConstraint(*(yysemantic_stack_[(1) - (1)].p_NAME));
	delete (yysemantic_stack_[(1) - (1)].p_NAME);
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 1136 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::LiteralConstraint(*(yysemantic_stack_[(1) - (1)].p_NAME));
	delete (yysemantic_stack_[(1) - (1)].p_NAME);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 1140 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::LiteralConstraint(*(yysemantic_stack_[(1) - (1)].p_NAME));
	delete (yysemantic_stack_[(1) - (1)].p_NAME);
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 1144 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::LiteralConstraint(*(yysemantic_stack_[(1) - (1)].p_NAME));
	delete (yysemantic_stack_[(1) - (1)].p_NAME);
    }
    break;



/* Line 678 of lalr1.cc  */
#line 1642 "lib/SQLParser/SQLParser.cpp"
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
  const short int SQLParser::yypact_ninf_ = -227;
  const short int
  SQLParser::yypact_[] =
  {
        26,   108,    11,    -5,    73,  -227,  -227,  -227,    32,  -227,
    -227,  -227,    21,    21,    21,    52,    54,    72,    79,   167,
     119,  -227,   122,  -227,  -227,  -227,  -227,  -227,  -227,  -227,
    -227,  -227,  -227,  -227,  -227,  -227,   126,  -227,  -227,  -227,
     124,     2,  -227,  -227,  -227,  -227,   133,  -227,  -227,  -227,
    -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,   -32,
     -32,  -227,    91,  -227,  -227,   141,  -227,  -227,  -227,   167,
     167,   167,   167,    98,    12,  -227,     3,   101,    38,  -227,
      38,  -227,  -227,   132,   136,    24,   167,   167,   167,   167,
     167,   167,  -227,  -227,    36,     8,  -227,  -227,   107,  -227,
     -23,  -227,  -227,   161,  -227,  -227,   117,   118,   135,  -227,
     161,     2,   162,  -227,   158,   121,  -227,   168,   167,  -227,
    -227,  -227,  -227,  -227,   167,  -227,   167,  -227,   166,  -227,
    -227,  -227,  -227,  -227,  -227,  -227,   167,   167,  -227,  -227,
    -227,   167,   167,  -227,    38,    10,  -227,   151,  -227,  -227,
      31,  -227,  -227,   167,   159,   -32,  -227,  -227,   167,  -227,
    -227,    -2,   143,  -227,   144,  -227,  -227,  -227,  -227,  -227,
    -227,  -227,  -227,  -227,  -227,  -227,   163,  -227,  -227,    67,
    -227,   167,  -227,   164,   198,  -227,  -227,  -227,   199,  -227,
     201,  -227,  -227,  -227,    63,   182,  -227,  -227,    38,   165,
    -227,  -227,   169,   170,   -20,  -227,  -227,   -32,  -227,    12,
    -227,    38,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,
     107,    65,   171,    38,  -227,  -227,  -227,  -227,  -227,  -227,
    -227,   173,  -227,   200,  -227,    68,  -227,  -227,    67,  -227,
     107,   107,   152,  -227,  -227,   167,  -227,  -227,  -227,   182,
    -227,   -18,  -227,   172,  -227,   175,    -9,  -227,  -227,  -227,
    -227,  -227,   195,   -32,  -227,   203,   182,   207,  -227,   202,
    -227,  -227,   107,  -227,  -227,  -227,  -227,  -227
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  SQLParser::yydefact_[] =
  {
         0,     0,     0,     0,     0,     7,     9,    10,     4,    67,
      84,   159,     0,     0,     0,     0,     0,     0,     0,     0,
      96,   182,    97,   184,   185,   171,   174,   177,   172,   175,
     178,   173,   176,   179,   180,   181,    74,    86,   158,    95,
       0,    92,   115,   118,   122,   124,   126,   136,   142,   147,
     152,   153,   154,   156,   168,   169,   170,   157,   155,     0,
       0,     1,     4,     5,     2,    65,   150,   151,   149,     0,
       0,     0,     0,     0,     0,    75,    78,    83,     0,    90,
       0,    93,    88,   116,   120,     0,     0,     0,     0,     0,
       0,     0,   125,   127,   137,   144,    98,    99,    19,    11,
       5,     3,     8,     0,    68,   166,     0,     0,     0,   160,
       0,   113,    71,   108,     0,     0,    79,    81,     0,    87,
      96,    97,    94,    91,     0,   119,     0,   123,     0,   134,
     128,   129,   130,   131,   132,   133,     0,     0,   143,   140,
     141,     0,     0,   148,     0,     0,    20,     0,     6,    66,
       0,   162,   163,     0,     0,     0,   114,   110,     0,    72,
      73,   100,     0,    76,     0,    82,    69,    85,   117,   121,
     135,   138,   139,   145,   146,    59,     0,    18,    22,    46,
     161,     0,   167,     0,     0,   112,    70,   101,     0,   102,
       0,   109,    77,    80,     0,     0,    21,    49,     0,     0,
      14,    47,     0,     0,     0,   165,   164,     0,   103,     0,
      57,     0,    60,    53,   183,    63,    55,    56,    54,    45,
       0,     0,     0,     0,    34,    39,    33,    35,    36,    37,
      38,    41,   111,   105,    58,     0,    31,    16,    46,    15,
       0,     0,     0,    42,    43,     0,   106,   107,    61,     0,
      64,    12,    13,     0,    32,     0,    29,   104,    62,    25,
      24,    17,    27,     0,    40,     0,     0,     0,    44,     0,
      28,    23,     0,    52,    51,    50,    26,    30
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SQLParser::yypgoto_[] =
  {
      -227,  -227,   197,  -227,  -227,   160,  -227,  -227,  -227,  -227,
    -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,    23,  -227,
    -227,  -227,  -227,  -227,  -227,  -227,  -227,  -226,  -209,  -227,
    -227,  -227,  -227,  -227,   -96,  -227,  -227,   174,  -227,  -227,
    -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,   145,
     153,  -227,  -227,  -227,   -75,   -58,  -227,  -227,  -227,  -227,
    -227,  -227,    56,  -227,  -227,   -19,  -227,  -227,  -227,   142,
    -227,  -227,   146,  -227,  -227,  -227,   104,  -227,  -227,  -227,
     -15,  -227,  -227,   -17,    13,  -227,  -227,  -227,  -227,  -191,
    -227,   176,   177,  -189,  -188
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SQLParser::yydefgoto_[] =
  {
        -1,     4,    64,   102,    62,     5,     6,   147,   239,   221,
     251,     7,   145,   177,   261,   262,   270,   271,   200,   231,
     243,   244,   256,   201,   202,   203,   268,   215,   146,   212,
     194,   196,   250,   235,     8,   104,    65,     9,   159,   160,
      75,    76,   116,   117,   165,   166,    36,   119,    77,    37,
      80,    81,    82,    38,    39,    40,   112,   190,   246,   247,
     191,   161,   113,   156,   157,    41,    42,   125,    83,    43,
     127,    84,    44,    45,    92,    93,    46,    47,   138,    94,
      48,   143,    95,    49,    50,    51,    52,   182,   150,    53,
      54,    55,    56,    57,    58
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char SQLParser::yytable_ninf_ = -100;
  const short int
  SQLParser::yytable_[] =
  {
        73,    98,    99,   122,   216,   123,   217,   218,   187,   188,
      79,   236,   265,     1,   154,   141,   111,   224,     2,   225,
     114,   115,     3,   258,   259,    66,    67,    68,    96,     1,
      97,   253,   254,   266,   226,   227,   228,   229,   230,   142,
     274,    60,   260,    11,   267,   128,   129,   189,   176,   178,
     105,   106,   107,   108,    15,    16,    17,    18,   216,   110,
     217,   218,   -89,   277,   -89,   136,   137,     2,    19,   175,
      59,     3,    96,    61,    97,   216,    63,   217,   218,   180,
     181,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,   185,   120,    69,
     121,    70,    26,    27,   204,    29,    30,   197,    32,    33,
     198,   210,   211,   237,   238,    10,   248,   249,   -48,    71,
     199,   171,   172,   219,   173,   174,    72,   120,   -98,   121,
      11,   -99,    74,    78,   183,   100,   234,    12,    13,   186,
      14,    15,    16,    17,    18,   103,   109,   124,   241,   232,
     118,   111,   126,    85,   144,    19,    86,    87,    88,    89,
      90,    91,   205,   204,     1,   151,   152,   158,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,   153,   162,   163,   164,   170,    11,
     130,   131,   132,   133,   134,   135,    12,    13,   179,    14,
      15,    16,    17,    18,   213,   272,   207,   184,   192,   193,
     195,   208,   206,   245,    19,   209,   220,   255,   269,   222,
     242,   223,   240,   264,   263,   273,   257,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    21,   214,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,   275,   101,
     148,   252,   276,   167,   155,   233,   168,     0,     0,     0,
     139,   140,   169,     0,     0,     0,     0,   149
  };

  /* YYCHECK.  */
  const short int
  SQLParser::yycheck_[] =
  {
        19,    59,    60,    78,   195,    80,   195,   195,    10,    11,
       8,   220,    21,     3,   110,     7,    74,    37,    41,    39,
      17,    18,    45,   249,    42,    12,    13,    14,    60,     3,
      62,   240,   241,    42,    54,    55,    56,    57,    58,    31,
     266,    46,    60,    22,    53,    21,    22,    49,    38,   145,
      69,    70,    71,    72,    33,    34,    35,    36,   249,    47,
     249,   249,    60,   272,    62,    29,    30,    41,    47,   144,
      59,    45,    60,     0,    62,   266,    44,   266,   266,    48,
      49,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,   155,    60,    47,
      62,    47,    66,    67,   179,    69,    70,    40,    72,    73,
      43,    48,    49,    48,    49,     7,    48,    49,    51,    47,
      53,   136,   137,   198,   141,   142,    47,    60,     9,    62,
      22,     9,     6,     9,   153,    44,   211,    29,    30,   158,
      32,    33,    34,    35,    36,     4,    48,    15,   223,   207,
      49,   209,    16,    20,    47,    47,    23,    24,    25,    26,
      27,    28,   181,   238,     3,    48,    48,     5,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    49,    27,    65,    19,    22,    22,
      86,    87,    88,    89,    90,    91,    29,    30,    47,    32,
      33,    34,    35,    36,    22,   263,     8,    48,    65,    65,
      47,    12,    48,    13,    47,    14,    51,    65,    23,    50,
      47,    51,    51,    48,    52,    22,   245,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    51,    62,
     100,   238,    60,   118,   111,   209,   124,    -1,    -1,    -1,
      94,    94,   126,    -1,    -1,    -1,    -1,   103
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  SQLParser::yystos_[] =
  {
         0,     3,    41,    45,    77,    81,    82,    87,   110,   113,
       7,    22,    29,    30,    32,    33,    34,    35,    36,    47,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,   122,   125,   129,   130,
     131,   141,   142,   145,   148,   149,   152,   153,   156,   159,
     160,   161,   162,   165,   166,   167,   168,   169,   170,    59,
      46,     0,    80,    44,    78,   112,   160,   160,   160,    47,
      47,    47,    47,   141,     6,   116,   117,   124,     9,     8,
     126,   127,   128,   144,   147,    20,    23,    24,    25,    26,
      27,    28,   150,   151,   155,   158,    60,    62,   131,   131,
      44,    78,    79,     4,   111,   141,   141,   141,   141,    48,
      47,   131,   132,   138,    17,    18,   118,   119,    49,   123,
      60,    62,   130,   130,    15,   143,    16,   146,    21,    22,
     152,   152,   152,   152,   152,   152,    29,    30,   154,   167,
     168,     7,    31,   157,    47,    88,   104,    83,    81,   113,
     164,    48,    48,    49,   110,   126,   139,   140,     5,   114,
     115,   137,    27,    65,    19,   120,   121,   125,   145,   148,
      22,   156,   156,   159,   159,   130,    38,    89,   110,    47,
      48,    49,   163,   141,    48,   131,   141,    10,    11,    49,
     133,   136,    65,    65,   106,    47,   107,    40,    43,    53,
      94,    99,   100,   101,   130,   141,    48,     8,    12,    14,
      48,    49,   105,    22,    62,   103,   165,   169,   170,   130,
      51,    85,    50,    51,    37,    39,    54,    55,    56,    57,
      58,    95,   131,   138,   130,   109,   104,    48,    49,    84,
      51,   130,    47,    96,    97,    13,   134,   135,    48,    49,
     108,    86,    94,   104,   104,    65,    98,   141,   103,    42,
      60,    90,    91,    52,    48,    21,    42,    53,   102,    23,
      92,    93,   131,    22,   103,    51,    60,   104
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
     325,   326,   327,   328,   329,   330
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  SQLParser::yyr1_[] =
  {
         0,    76,    77,    77,    78,    78,    79,    80,    80,    81,
      81,    83,    82,    84,    85,    85,    86,    86,    87,    88,
      88,    89,    89,    90,    91,    91,    92,    93,    93,    94,
      94,    94,    94,    95,    95,    95,    95,    95,    95,    95,
      96,    97,    97,    98,    98,    99,   100,   100,   101,   101,
     102,   102,   102,   103,   103,   103,   103,   104,   105,   106,
     106,   107,   108,   109,   109,   110,   111,   112,   112,   113,
     114,   115,   115,   116,   117,   117,   118,   118,   119,   119,
     120,   121,   121,   122,   122,   123,   124,   124,   125,   126,
     126,   127,   128,   128,   129,   129,   130,   130,   131,   131,
     132,   133,   133,   133,   134,   135,   135,   136,   137,   137,
     138,   138,   139,   140,   140,   141,   142,   143,   144,   144,
     145,   146,   147,   147,   148,   149,   150,   150,   151,   151,
     151,   151,   151,   151,   151,   151,   152,   153,   154,   154,
     154,   154,   155,   155,   156,   157,   157,   158,   158,   159,
     159,   159,   159,   160,   160,   160,   160,   160,   160,   160,
     161,   162,   162,   162,   162,   163,   164,   164,   165,   165,
     165,   166,   166,   166,   167,   167,   167,   168,   168,   168,
     169,   169,   170,   170,   170,   170
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  SQLParser::yyr2_[] =
  {
         0,     2,     2,     3,     0,     1,     2,     0,     2,     1,
       1,     0,     9,     2,     0,     2,     0,     2,     5,     0,
       1,     2,     1,     2,     1,     1,     2,     0,     1,     4,
       7,     3,     4,     1,     1,     1,     1,     1,     1,     1,
       3,     0,     1,     0,     2,     2,     0,     1,     0,     1,
       2,     2,     2,     1,     1,     1,     1,     4,     2,     0,
       2,     4,     2,     0,     2,     2,     2,     0,     2,     5,
       2,     0,     1,     3,     0,     1,     2,     3,     0,     1,
       2,     0,     1,     2,     1,     2,     0,     2,     2,     0,
       1,     2,     0,     1,     3,     1,     1,     1,     1,     1,
       2,     1,     1,     2,     2,     0,     1,     4,     0,     2,
       2,     5,     2,     0,     1,     1,     2,     2,     0,     2,
       2,     2,     0,     2,     1,     2,     0,     1,     2,     2,
       2,     2,     2,     2,     2,     3,     1,     2,     2,     2,
       1,     1,     0,     2,     2,     2,     2,     0,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     5,     4,     4,     6,     2,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
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
  "IT_REFERENCES", "IT_PRIMARY", "IT_INT", "IT_DOUBLE", "IT_DATE",
  "IT_DATETIME", "IT_STRING", "IT_INTO", "NAME", "STRING_LITERAL1",
  "STRING_LITERAL2", "STRING_LITERAL_LONG1", "STRING_LITERAL_LONG2",
  "INTEGER", "INTEGER_POSITIVE", "INTEGER_NEGATIVE", "DECIMAL",
  "DECIMAL_POSITIVE", "DECIMAL_NEGATIVE", "DOUBLE", "DOUBLE_POSITIVE",
  "DOUBLE_NEGATIVE", "IT_true", "IT_false", "$accept", "Statement",
  "_QGT_SEMI_E_Opt", "_O_QGT_SEMI_E_S_QUpdate_E_C",
  "_Q_O_QGT_SEMI_E_S_QUpdate_E_C_E_Star", "Update", "Create", "$@1",
  "_O_QGT_COMMA_E_S_QFieldOrKey_E_C",
  "_Q_O_QGT_COMMA_E_S_QFieldOrKey_E_C_E_Star", "_QParam_E_Star", "Insert",
  "_QAttrList_E_Opt", "_O_QIT_VALUES_E_S_QConstList_E_Or_QSelectUnion_E_C",
  "Param", "_O_QNAME_E_Or_QIT_DEFAULT_E_C", "_O_QGT_EQUAL_E_S_QNAME_E_C",
  "_Q_O_QGT_EQUAL_E_S_QNAME_E_C_E_Opt", "FieldOrKey",
  "_O_QIT_INT_E_Or_QIT_INTEGER_E_Or_QIT_DOUBLE_E_Or_QIT_DATE_E_Or_QIT_DATETIME_E_Or_QIT_STRING_E_Or_QIT_VARCHAR_E_C",
  "_O_QGT_LPAREN_E_S_QINTEGER_E_S_QGT_RPAREN_E_C",
  "_Q_O_QGT_LPAREN_E_S_QINTEGER_E_S_QGT_RPAREN_E_C_E_Opt",
  "_QLinkDetails_E_Star", "_O_QIT_CONSTRAINT_E_S_QAttribute_E_C",
  "_Q_O_QIT_CONSTRAINT_E_S_QAttribute_E_C_E_Opt", "_QIT_UNIQUE_E_Opt",
  "LinkDetails", "Constant", "AttrList", "_O_QGT_COMMA_E_S_QAttribute_E_C",
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
        77,     0,    -1,   110,    78,    -1,    81,    80,    78,    -1,
      -1,    44,    -1,    44,    81,    -1,    -1,    80,    79,    -1,
      82,    -1,    87,    -1,    -1,    45,    46,   131,    83,    47,
      94,    85,    48,    86,    -1,    49,    94,    -1,    -1,    85,
      84,    -1,    -1,    86,    90,    -1,    41,    59,   131,    88,
      89,    -1,    -1,   104,    -1,    38,   107,    -1,   110,    -1,
      91,    93,    -1,    60,    -1,    42,    -1,    23,    60,    -1,
      -1,    92,    -1,   130,    95,    97,    98,    -1,   100,    50,
      51,   104,    52,   131,   104,    -1,    53,    51,   104,    -1,
     101,    51,   130,   104,    -1,    54,    -1,    37,    -1,    55,
      -1,    56,    -1,    57,    -1,    58,    -1,    39,    -1,    47,
      65,    48,    -1,    -1,    96,    -1,    -1,    98,   102,    -1,
      43,   130,    -1,    -1,    99,    -1,    -1,    40,    -1,    53,
      51,    -1,    42,   103,    -1,    21,    22,    -1,    22,    -1,
     170,    -1,   165,    -1,   169,    -1,    47,   130,   106,    48,
      -1,    49,   130,    -1,    -1,   106,   105,    -1,    47,   103,
     109,    48,    -1,    49,   103,    -1,    -1,   109,   108,    -1,
     113,   112,    -1,     4,   113,    -1,    -1,   112,   111,    -1,
       3,   122,   117,   119,   121,    -1,     5,   141,    -1,    -1,
     114,    -1,     6,   132,   115,    -1,    -1,   116,    -1,    18,
      65,    -1,    17,    27,    65,    -1,    -1,   118,    -1,    19,
      65,    -1,    -1,   120,    -1,   125,   124,    -1,     7,    -1,
      49,   125,    -1,    -1,   124,   123,    -1,   141,   128,    -1,
      -1,     8,    -1,   126,   130,    -1,    -1,   127,    -1,   131,
       9,   130,    -1,   130,    -1,    60,    -1,    62,    -1,    60,
      -1,    62,    -1,   138,   137,    -1,    10,    -1,    49,    -1,
      11,    12,    -1,    13,   141,    -1,    -1,   134,    -1,   133,
      14,   138,   135,    -1,    -1,   137,   136,    -1,   131,   140,
      -1,    47,   110,    48,     8,   131,    -1,   126,   131,    -1,
      -1,   139,    -1,   142,    -1,   145,   144,    -1,    15,   145,
      -1,    -1,   144,   143,    -1,   148,   147,    -1,    16,   148,
      -1,    -1,   147,   146,    -1,   149,    -1,   152,   150,    -1,
      -1,   151,    -1,    23,   152,    -1,    24,   152,    -1,    25,
     152,    -1,    26,   152,    -1,    27,   152,    -1,    28,   152,
      -1,    20,    22,    -1,    20,    21,    22,    -1,   153,    -1,
     156,   155,    -1,    29,   156,    -1,    30,   156,    -1,   167,
      -1,   168,    -1,    -1,   155,   154,    -1,   159,   158,    -1,
       7,   159,    -1,    31,   159,    -1,    -1,   158,   157,    -1,
      32,   160,    -1,    29,   160,    -1,    30,   160,    -1,   160,
      -1,   161,    -1,   162,    -1,   170,    -1,   165,    -1,   169,
      -1,   129,    -1,    22,    -1,    47,   141,    48,    -1,    33,
      47,   141,   164,    48,    -1,    34,    47,   141,    48,    -1,
      35,    47,   141,    48,    -1,    36,    47,   141,    49,   141,
      48,    -1,    49,   141,    -1,    -1,   164,   163,    -1,   166,
      -1,   167,    -1,   168,    -1,    65,    -1,    68,    -1,    71,
      -1,    66,    -1,    69,    -1,    72,    -1,    67,    -1,    70,
      -1,    73,    -1,    74,    -1,    75,    -1,    61,    -1,    62,
      -1,    63,    -1,    64,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  SQLParser::yyprhs_[] =
  {
         0,     0,     3,     6,    10,    11,    13,    16,    17,    20,
      22,    24,    25,    35,    38,    39,    42,    43,    46,    52,
      53,    55,    58,    60,    63,    65,    67,    70,    71,    73,
      78,    86,    90,    95,    97,    99,   101,   103,   105,   107,
     109,   113,   114,   116,   117,   120,   123,   124,   126,   127,
     129,   132,   135,   138,   140,   142,   144,   146,   151,   154,
     155,   158,   163,   166,   167,   170,   173,   176,   177,   180,
     186,   189,   190,   192,   196,   197,   199,   202,   206,   207,
     209,   212,   213,   215,   218,   220,   223,   224,   227,   230,
     231,   233,   236,   237,   239,   243,   245,   247,   249,   251,
     253,   256,   258,   260,   263,   266,   267,   269,   274,   275,
     278,   281,   287,   290,   291,   293,   295,   298,   301,   302,
     305,   308,   311,   312,   315,   317,   320,   321,   323,   326,
     329,   332,   335,   338,   341,   344,   348,   350,   353,   356,
     359,   361,   363,   364,   367,   370,   373,   376,   377,   380,
     383,   386,   389,   391,   393,   395,   397,   399,   401,   403,
     405,   409,   415,   420,   425,   432,   435,   436,   439,   441,
     443,   445,   447,   449,   451,   453,   455,   457,   459,   461,
     463,   465,   467,   469,   471,   473
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SQLParser::yyrline_[] =
  {
         0,   300,   300,   303,   306,   308,   312,   315,   317,   321,
     322,   326,   326,   336,   339,   341,   344,   346,   350,   358,
     361,   365,   368,   374,   380,   381,   385,   388,   390,   394,
     405,   409,   412,   418,   421,   424,   427,   430,   433,   436,
     442,   450,   453,   456,   458,   462,   467,   469,   472,   474,
     478,   481,   484,   490,   493,   494,   495,   499,   507,   513,
     516,   524,   531,   537,   540,   547,   559,   565,   568,   575,
     592,   598,   601,   605,   614,   618,   622,   627,   635,   638,
     642,   650,   653,   657,   662,   668,   674,   677,   684,   696,
     698,   702,   708,   711,   717,   722,   729,   730,   734,   735,
     739,   752,   755,   758,   764,   770,   773,   779,   792,   796,
     805,   816,   825,   831,   834,   840,   845,   857,   864,   867,
     875,   887,   894,   897,   904,   909,   928,   931,   936,   939,
     942,   945,   948,   951,   954,   957,   963,   968,   980,   983,
     986,   987,   992,   995,  1003,  1015,  1018,  1025,  1028,  1035,
    1038,  1041,  1044,  1048,  1049,  1050,  1051,  1052,  1053,  1054,
    1060,  1066,  1071,  1076,  1081,  1087,  1093,  1096,  1103,  1104,
    1105,  1109,  1110,  1111,  1115,  1116,  1117,  1121,  1122,  1123,
    1127,  1128,  1132,  1136,  1140,  1144
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
      75
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int SQLParser::yyeof_ = 0;
  const int SQLParser::yylast_ = 277;
  const int SQLParser::yynnts_ = 95;
  const int SQLParser::yyempty_ = -2;
  const int SQLParser::yyfinal_ = 61;
  const int SQLParser::yyterror_ = 1;
  const int SQLParser::yyerrcode_ = 256;
  const int SQLParser::yyntokens_ = 76;

  const unsigned int SQLParser::yyuser_token_number_max_ = 330;
  const SQLParser::token_number_type SQLParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 2401 "lib/SQLParser/SQLParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 1152 "lib/SQLParser/SQLParser.ypp"
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

