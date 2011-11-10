
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
#line 203 "lib/SQLParser/SQLParser.ypp"

#include "SQLScanner.hpp"

/* Line 317 of lalr1.cc  */
#line 271 "lib/SQLParser/SQLParser.ypp"

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
#line 287 "lib/SQLParser/SQLParser.ypp"
    {
    driver.root = (yysemantic_stack_[(2) - (1)].p_Select);
}
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 309 "lib/SQLParser/SQLParser.ypp"
    {
    driver.curCreate = new sql::schema::Relation(*(yysemantic_stack_[(3) - (3)].p_NAME));
      }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 311 "lib/SQLParser/SQLParser.ypp"
    {
      driver.tables[*(yysemantic_stack_[(8) - (3)].p_NAME)] = driver.curCreate;
      delete (yysemantic_stack_[(8) - (3)].p_NAME);
      driver.curCreate = NULL;
}
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 328 "lib/SQLParser/SQLParser.ypp"
    {
    sql::schema::Field* f = new sql::schema::Field(*(yysemantic_stack_[(2) - (1)].p_NAME), (yysemantic_stack_[(2) - (2)].p_SchemaDatatype));
    delete (yysemantic_stack_[(2) - (1)].p_NAME);
    driver.curCreate->addField(f);
}
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 334 "lib/SQLParser/SQLParser.ypp"
    {
    driver.curCreate->addForeignKey(new sql::schema::ForeignKey((yysemantic_stack_[(6) - (3)].p_Attributes), *(yysemantic_stack_[(6) - (5)].p_NAME), (yysemantic_stack_[(6) - (6)].p_Attributes)));
    delete (yysemantic_stack_[(6) - (5)].p_NAME);
}
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 339 "lib/SQLParser/SQLParser.ypp"
    {
    driver.curCreate->addPrimaryKey(new sql::schema::PrimaryKey((yysemantic_stack_[(3) - (3)].p_Attributes)));
}
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 345 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_SchemaDatatype) = sql::schema::TYPE_int;
}
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 349 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_SchemaDatatype) = sql::schema::TYPE_double;
}
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 353 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_SchemaDatatype) = sql::schema::TYPE_date;
}
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 357 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_SchemaDatatype) = sql::schema::TYPE_datetime;
}
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 361 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_SchemaDatatype) = sql::schema::TYPE_string;
}
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 367 "lib/SQLParser/SQLParser.ypp"
    {
    (yysemantic_stack_[(4) - (3)].p_Attributes)->insert((yysemantic_stack_[(4) - (3)].p_Attributes)->begin(), *(yysemantic_stack_[(4) - (2)].p_NAME));
    delete (yysemantic_stack_[(4) - (2)].p_NAME);
    (yyval.p_Attributes) = (yysemantic_stack_[(4) - (3)].p_Attributes);
}
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 375 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = (yysemantic_stack_[(2) - (2)].p_NAME);
}
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 381 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Attributes) = new std::vector<std::string>();
}
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 385 "lib/SQLParser/SQLParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_Attributes)->push_back(*(yysemantic_stack_[(2) - (2)].p_NAME));
    delete (yysemantic_stack_[(2) - (2)].p_NAME);
    (yyval.p_Attributes) = (yysemantic_stack_[(2) - (1)].p_Attributes);
}
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 393 "lib/SQLParser/SQLParser.ypp"
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

  case 27:

/* Line 678 of lalr1.cc  */
#line 405 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Select) = (yysemantic_stack_[(2) - (2)].p_Select);
}
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 411 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Selects) = new std::vector<sql::SQLQuery*>();
}
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 415 "lib/SQLParser/SQLParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_Selects)->push_back((yysemantic_stack_[(2) - (2)].p_Select));
    (yyval.p_Selects) = (yysemantic_stack_[(2) - (1)].p_Selects);
}
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 422 "lib/SQLParser/SQLParser.ypp"
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

  case 31:

/* Line 678 of lalr1.cc  */
#line 439 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 445 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = NULL;
}
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 453 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TableList).joins = (yysemantic_stack_[(3) - (2)].p_TableList).joins;
	(yyval.p_TableList).exprs = (yysemantic_stack_[(3) - (2)].p_TableList).exprs;
	if ((yysemantic_stack_[(3) - (3)].p_Expression) != NULL)
	    (yyval.p_TableList).exprs->push_back((yysemantic_stack_[(3) - (3)].p_Expression));
}
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 462 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_TableList).joins = new std::vector<sql::Join*>();;
    (yyval.p_TableList).exprs = new std::vector<const sql::Expression*>();;
}
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 471 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 476 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(3) - (3)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(3) - (3)].p_Expression);
}
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 484 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_int) = -1;
}
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 492 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 500 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_int) = -1;
}
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 508 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (2)].p_AttributeList)->insert((yysemantic_stack_[(2) - (2)].p_AttributeList)->begin(), (yysemantic_stack_[(2) - (1)].p_AliasedSelect));
	(yyval.p_AttributeList) = new std::vector<sql::AliasedSelect*>((yysemantic_stack_[(2) - (2)].p_AttributeList)->begin(), (yysemantic_stack_[(2) - (2)].p_AttributeList)->end());
	delete (yysemantic_stack_[(2) - (2)].p_AttributeList);
}
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 514 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AttributeList) = new std::vector<sql::AliasedSelect*>();
}
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 520 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AliasedSelect) = (yysemantic_stack_[(2) - (2)].p_AliasedSelect);
}
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 526 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AttributeList) = new std::vector<sql::AliasedSelect*>();
}
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 530 "lib/SQLParser/SQLParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_AttributeList)->push_back((yysemantic_stack_[(2) - (2)].p_AliasedSelect));
    (yyval.p_AttributeList) = (yysemantic_stack_[(2) - (1)].p_AttributeList);
}
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 537 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AliasedSelect) = new sql::AliasedSelect((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_NAME) ? *(yysemantic_stack_[(2) - (2)].p_NAME) : (yysemantic_stack_[(2) - (1)].p_Expression)->toString());
	delete (yysemantic_stack_[(2) - (2)].p_NAME);
}
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 544 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = (yysemantic_stack_[(2) - (2)].p_NAME);
}
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 551 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = NULL;
}
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 555 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = (yysemantic_stack_[(1) - (1)].p_NAME);
}
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 561 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::AliasAttrConstraint(sql::AliasAttr(*(yysemantic_stack_[(3) - (1)].p_NAME), *(yysemantic_stack_[(3) - (3)].p_NAME)));
	delete (yysemantic_stack_[(3) - (1)].p_NAME);
	delete (yysemantic_stack_[(3) - (3)].p_NAME);
}
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 577 "lib/SQLParser/SQLParser.ypp"
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

  case 58:

/* Line 678 of lalr1.cc  */
#line 590 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_bool) = false;
}
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 594 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_bool) = false;
}
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 598 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_bool) = true;
}
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 604 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 610 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = NULL;
}
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 614 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(1) - (1)].p_Expression);
}
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 620 "lib/SQLParser/SQLParser.ypp"
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

  case 65:

/* Line 678 of lalr1.cc  */
#line 633 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TableList).joins = new std::vector<sql::Join*>();
	(yyval.p_TableList).exprs = new std::vector<const sql::Expression*>();
}
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 638 "lib/SQLParser/SQLParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_TableList).joins->push_back((yysemantic_stack_[(2) - (2)].p_JoinExpression).join);
    if ((yysemantic_stack_[(2) - (2)].p_JoinExpression).expr != NULL)
	(yysemantic_stack_[(2) - (1)].p_TableList).exprs->push_back((yysemantic_stack_[(2) - (2)].p_JoinExpression).expr);
    (yyval.p_TableList) = (yysemantic_stack_[(2) - (1)].p_TableList);
}
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 647 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_tableAlias).relation = (yysemantic_stack_[(2) - (1)].p_NAME);
	(yyval.p_tableAlias).subselect = NULL;
	(yyval.p_tableAlias).alias = (yysemantic_stack_[(2) - (2)].p_NAME) ? (yysemantic_stack_[(2) - (2)].p_NAME) : new std::string(*(yysemantic_stack_[(2) - (1)].p_NAME));
}
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 652 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_tableAlias).relation = NULL;
	(yyval.p_tableAlias).subselect = (yysemantic_stack_[(4) - (2)].p_Select);
	(yyval.p_tableAlias).alias = (yysemantic_stack_[(4) - (4)].p_NAME);
}
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 657 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_tableAlias).relation = NULL;
	(yyval.p_tableAlias).subselect = (yysemantic_stack_[(5) - (2)].p_Select);
	(yyval.p_tableAlias).alias = (yysemantic_stack_[(5) - (5)].p_NAME);
}
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 665 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = (yysemantic_stack_[(2) - (2)].p_NAME);
}
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 672 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = NULL;
}
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 676 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = (yysemantic_stack_[(1) - (1)].p_NAME);
}
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 687 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::DisjunctionConstraint((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 699 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 706 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 709 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 717 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::DisjunctionConstraint((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 729 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 736 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 739 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 751 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_BooleanComparator)) {
	    if (dynamic_cast<sql::IsNotNullProxy*>((yysemantic_stack_[(2) - (2)].p_BooleanComparator)) != NULL) {
		delete (yysemantic_stack_[(2) - (2)].p_BooleanComparator);
		(yyval.p_Expression) = new sql::NegationConstraint(new sql::NullConstraint(dynamic_cast<const sql::Expression*>((yysemantic_stack_[(2) - (1)].p_Expression)))); // new sql::ReallyNullConstraint();
	    } else if (dynamic_cast<sql::IsNullProxy*>((yysemantic_stack_[(2) - (2)].p_BooleanComparator)) != NULL) {
		delete (yysemantic_stack_[(2) - (2)].p_BooleanComparator);
		(yyval.p_Expression) = new sql::NullConstraint(dynamic_cast<const sql::Expression*>((yysemantic_stack_[(2) - (1)].p_Expression)));
	    } else {
		(yysemantic_stack_[(2) - (2)].p_BooleanComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
		(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_BooleanComparator); // !!!
	    }
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 770 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 773 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 776 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 779 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 782 "lib/SQLParser/SQLParser.ypp"
    {
        (yyval.p_BooleanComparator) = new sql::BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 785 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 788 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_BooleanComparator) = new sql::IsNullProxy;
}
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 791 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_BooleanComparator) = new sql::IsNotNullProxy;
}
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 798 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = NULL;
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 811 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::ArithmeticSum((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 823 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 826 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 835 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 838 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 846 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::ArithmeticProduct((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 858 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 861 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 868 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 871 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 878 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 881 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 884 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 897 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::ReallyNullConstraint();
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 903 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
}
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 909 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(5) - (4)].p_Expressions)->insert((yysemantic_stack_[(5) - (4)].p_Expressions)->begin(), (yysemantic_stack_[(5) - (3)].p_Expression));
	(yyval.p_Expression) = new sql::HomologConstraint("CONCAT", (yysemantic_stack_[(5) - (4)].p_Expressions)->begin(), (yysemantic_stack_[(5) - (4)].p_Expressions)->end());
	delete (yysemantic_stack_[(5) - (4)].p_Expressions);
}
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 916 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::RegexConstraint((yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression));
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 922 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 928 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
}
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 932 "lib/SQLParser/SQLParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    (yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
}
    break;



/* Line 678 of lalr1.cc  */
#line 1385 "lib/SQLParser/SQLParser.cpp"
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
  const short int SQLParser::yypact_ninf_ = -167;
  const short int
  SQLParser::yypact_[] =
  {
         3,     0,   -16,    28,  -167,   -12,  -167,  -167,  -167,   135,
     135,   135,    -7,    37,    44,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,    36,  -167,  -167,    72,    -5,  -167,  -167,  -167,  -167,
     107,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,    33,  -167,    52,  -167,  -167,    88,  -167,
    -167,  -167,    44,    44,    54,   -33,  -167,     2,    73,    66,
      66,  -167,  -167,  -167,  -167,   108,   106,     5,    44,    44,
      44,    44,    44,    44,  -167,  -167,    59,     6,  -167,    92,
    -167,  -167,   121,  -167,  -167,   102,  -167,   121,    -4,   138,
    -167,   118,    95,  -167,   128,    44,  -167,  -167,  -167,    44,
    -167,    44,  -167,   126,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,    44,    44,  -167,  -167,  -167,    44,    44,  -167,   111,
    -167,  -167,     4,    44,   113,    33,  -167,  -167,  -167,    44,
    -167,  -167,     1,    99,  -167,   103,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,   -26,  -167,    44,  -167,
     114,    17,  -167,  -167,  -167,   143,  -167,   142,  -167,  -167,
    -167,   117,   119,  -167,    23,  -167,  -167,    33,  -167,  -167,
     -33,   122,   122,    40,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,   149,    66,   120,  -167,  -167,   -26,  -167,    44,  -167,
    -167,  -167,    33,  -167,  -167,    46,   122,  -167,    66,  -167,
    -167,  -167
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  SQLParser::yydefact_[] =
  {
         0,     0,     0,     0,     7,     4,    28,    45,   118,     0,
       0,     0,     0,     0,     0,    56,   128,   131,   134,   129,
     132,   135,   130,   133,   136,   139,   140,   141,   142,   137,
     138,    35,    47,   117,     0,    52,    74,    77,    81,    83,
      93,    95,   101,   106,   111,   112,   113,   115,   125,   126,
     127,   116,   114,     0,     1,     4,     5,     2,    26,   109,
     110,   108,     0,     0,     0,     0,    36,    39,    44,     0,
       0,    55,    53,    49,    51,    75,    79,     0,     0,     0,
       0,     0,     0,     0,    94,    84,    96,   103,     9,     5,
       3,     8,     0,    29,   123,     0,   119,     0,    72,    32,
      65,     0,     0,    40,    42,     0,    48,    54,    50,     0,
      78,     0,    82,     0,    91,    85,    86,    87,    88,    89,
      90,     0,     0,   102,    99,   100,     0,     0,   107,     0,
       6,    27,     0,     0,     0,     0,    71,    73,    67,     0,
      33,    34,    57,     0,    37,     0,    43,    30,    46,    76,
      80,    92,    97,    98,   104,   105,     0,   120,     0,   124,
       0,     0,    70,    31,    58,     0,    59,     0,    66,    38,
      41,     0,     0,    12,     0,   122,   121,     0,    68,    60,
       0,     0,     0,     0,    17,    18,    19,    20,    21,    14,
      69,    62,     0,     0,    16,    10,     0,    13,     0,    63,
      64,    24,     0,    11,    61,     0,     0,    22,     0,    25,
      15,    23
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SQLParser::yypgoto_[] =
  {
      -167,  -167,   109,  -167,  -167,    76,  -167,  -167,  -167,   -30,
    -167,  -166,  -167,  -167,    70,  -167,  -167,    78,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,    67,
    -167,  -167,  -167,   -34,   -51,  -167,  -167,  -167,  -167,  -167,
    -167,    -9,  -167,  -167,   -14,  -167,  -167,  -167,    68,  -167,
    -167,    64,  -167,  -167,  -167,    58,  -167,  -167,  -167,   -31,
    -167,  -167,    -6,    -1,  -167,  -167,  -167,  -167,  -167,  -167,
      90,    93,  -167,  -167
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SQLParser::yydefgoto_[] =
  {
        -1,     3,    57,    91,    55,     4,   129,   197,   183,   173,
     189,   193,   209,   205,     5,    93,    58,     6,   140,   141,
      66,    67,   103,   104,   146,   147,    31,   106,    68,    32,
      72,    73,    33,   174,    34,    99,   167,   199,   200,   168,
     142,   100,   137,   138,    35,    36,   110,    75,    37,   112,
      76,    38,    39,    84,    85,    40,    41,   123,    86,    42,
     128,    87,    43,    44,    45,    46,   159,   132,    47,    48,
      49,    50,    51,    52
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char SQLParser::yytable_ninf_ = -1;
  const unsigned char
  SQLParser::yytable_[] =
  {
        64,    74,    88,    70,   135,    97,     1,     7,    59,    60,
      61,   164,   165,   126,    98,   171,   194,    15,   172,   101,
     102,    53,     8,    56,    71,   177,   113,   114,    54,     9,
      10,    62,    11,    12,    13,   107,   108,   127,    14,     2,
     210,   166,    65,   157,   158,    71,    15,   136,    94,    95,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,     8,    15,   184,   185,
     186,   187,   188,     9,    10,    63,    11,    12,    13,   195,
     196,    69,    14,    15,   162,   207,   208,    89,   121,   122,
     152,   153,    92,    96,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
     178,    17,    18,   105,    20,    21,    71,    23,    24,   160,
     154,   155,   111,   109,     1,   163,   190,    77,     2,    98,
      78,    79,    80,    81,    82,    83,   115,   116,   117,   118,
     119,   120,   133,   139,   175,   143,   144,   145,   151,   156,
     169,   206,   161,   176,   170,   179,   180,     8,   201,   181,
     192,   182,   198,   202,    90,   130,   203,   134,    12,    13,
     131,   191,   148,    14,   211,   150,   124,   149,     0,   125,
       0,     0,     0,     0,   204,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30
  };

  /* YYCHECK.  */
  const short int
  SQLParser::yycheck_[] =
  {
        14,    35,    53,     8,     8,    38,     3,     7,     9,    10,
      11,    10,    11,     7,    65,    41,   182,    50,    44,    17,
      18,    37,    22,    35,    50,     8,    21,    22,     0,    29,
      30,    38,    32,    33,    34,    69,    70,    31,    38,    36,
     206,    40,     6,    39,    40,    50,    50,    98,    62,    63,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    22,    50,    45,    46,
      47,    48,    49,    29,    30,    38,    32,    33,    34,    39,
      40,     9,    38,    50,   135,    39,    40,    35,    29,    30,
     121,   122,     4,    39,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     161,    52,    53,    40,    55,    56,    50,    58,    59,   133,
     126,   127,    16,    15,     3,   139,   177,    20,    36,   180,
      23,    24,    25,    26,    27,    28,    78,    79,    80,    81,
      82,    83,    40,     5,   158,    27,    51,    19,    22,    38,
      51,   202,    39,    39,    51,    12,    14,    22,   192,    42,
      38,    42,    13,    43,    55,    89,   196,    97,    33,    34,
      92,   180,   105,    38,   208,   111,    86,   109,    -1,    86,
      -1,    -1,    -1,    -1,   198,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  SQLParser::yystos_[] =
  {
         0,     3,    36,    67,    71,    80,    83,     7,    22,    29,
      30,    32,    33,    34,    38,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    92,    95,    98,   100,   110,   111,   114,   117,   118,
     121,   122,   125,   128,   129,   130,   131,   134,   135,   136,
     137,   138,   139,    37,     0,    70,    35,    68,    82,   129,
     129,   129,    38,    38,   110,     6,    86,    87,    94,     9,
       8,    50,    96,    97,    99,   113,   116,    20,    23,    24,
      25,    26,    27,    28,   119,   120,   124,   127,   100,    35,
      68,    69,     4,    81,   110,   110,    39,    38,   100,   101,
     107,    17,    18,    88,    89,    40,    93,    99,    99,    15,
     112,    16,   115,    21,    22,   121,   121,   121,   121,   121,
     121,    29,    30,   123,   136,   137,     7,    31,   126,    72,
      71,    83,   133,    40,    80,     8,   100,   108,   109,     5,
      84,    85,   106,    27,    51,    19,    90,    91,    95,   114,
     117,    22,   125,   125,   128,   128,    38,    39,    40,   132,
     110,    39,   100,   110,    10,    11,    40,   102,   105,    51,
      51,    41,    44,    75,    99,   110,    39,     8,   100,    12,
      14,    42,    42,    74,    45,    46,    47,    48,    49,    76,
     100,   107,    38,    77,    77,    39,    40,    73,    13,   103,
     104,    99,    43,    75,   110,    79,   100,    39,    40,    78,
      77,    99
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
     315,   316,   317,   318,   319,   320
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  SQLParser::yyr1_[] =
  {
         0,    66,    67,    67,    68,    68,    69,    70,    70,    72,
      71,    73,    74,    74,    75,    75,    75,    76,    76,    76,
      76,    76,    77,    78,    79,    79,    80,    81,    82,    82,
      83,    84,    85,    85,    86,    87,    87,    88,    88,    89,
      89,    90,    91,    91,    92,    92,    93,    94,    94,    95,
      96,    96,    97,    97,    98,    99,   100,   101,   102,   102,
     102,   103,   104,   104,   105,   106,   106,   107,   107,   107,
     108,   108,   109,   109,   110,   111,   112,   113,   113,   114,
     115,   116,   116,   117,   118,   119,   119,   119,   119,   119,
     119,   119,   119,   120,   120,   121,   122,   123,   123,   123,
     123,   124,   124,   125,   126,   126,   127,   127,   128,   128,
     128,   128,   129,   129,   129,   129,   129,   129,   129,   130,
     131,   131,   132,   133,   133,   134,   134,   134,   135,   135,
     135,   136,   136,   136,   137,   137,   137,   138,   138,   139,
     139,   139,   139
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  SQLParser::yyr2_[] =
  {
         0,     2,     2,     3,     0,     1,     2,     0,     2,     0,
       8,     2,     0,     2,     2,     6,     3,     1,     1,     1,
       1,     1,     4,     2,     0,     2,     2,     2,     0,     2,
       5,     2,     0,     1,     3,     0,     1,     2,     3,     0,
       1,     2,     0,     1,     2,     1,     2,     0,     2,     2,
       2,     1,     0,     1,     3,     1,     1,     2,     1,     1,
       2,     2,     0,     1,     4,     0,     2,     2,     4,     5,
       2,     1,     0,     1,     1,     2,     2,     0,     2,     2,
       2,     0,     2,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     3,     0,     1,     1,     2,     2,     2,     1,
       1,     0,     2,     2,     2,     2,     0,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       5,     6,     2,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
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
  "GT_MINUS", "GT_DIVIDE", "GT_NOT", "IT_CONCAT", "IT_REGEX", "GT_SEMI",
  "IT_CREATE", "IT_TABLE", "GT_LPAREN", "GT_RPAREN", "GT_COMMA",
  "IT_FOREIGN", "IT_KEY", "IT_REFERENCES", "IT_PRIMARY", "IT_INT",
  "IT_DOUBLE", "IT_DATE", "IT_DATETIME", "IT_STRING", "NAME", "INTEGER",
  "INTEGER_POSITIVE", "INTEGER_NEGATIVE", "DECIMAL", "DECIMAL_POSITIVE",
  "DECIMAL_NEGATIVE", "DOUBLE", "DOUBLE_POSITIVE", "DOUBLE_NEGATIVE",
  "STRING_LITERAL1", "STRING_LITERAL2", "STRING_LITERAL_LONG1",
  "STRING_LITERAL_LONG2", "IT_true", "IT_false", "$accept", "Statement",
  "_QGT_SEMI_E_Opt", "_O_QGT_SEMI_E_S_QCreate_E_C",
  "_Q_O_QGT_SEMI_E_S_QCreate_E_C_E_Star", "Create", "$@1",
  "_O_QGT_COMMA_E_S_QFieldOrKey_E_C",
  "_Q_O_QGT_COMMA_E_S_QFieldOrKey_E_C_E_Star", "FieldOrKey",
  "_O_QIT_INT_E_Or_QIT_DOUBLE_E_Or_QIT_DATE_E_Or_QIT_DATETIME_E_Or_QIT_STRING_E_C",
  "AttrList", "_O_QGT_COMMA_E_S_QAttribute_E_C",
  "_Q_O_QGT_COMMA_E_S_QAttribute_E_C_E_Star", "SelectUnion",
  "_O_QIT_UNION_E_S_QSelect_E_C", "_Q_O_QIT_UNION_E_S_QSelect_E_C_E_Star",
  "Select", "_O_QIT_WHERE_E_S_QExpression_E_C",
  "_Q_O_QIT_WHERE_E_S_QExpression_E_C_E_Opt",
  "_O_QIT_FROM_E_S_QTableList_E_S_QIT_WHERE_E_S_QExpression_E_Opt_C",
  "_Q_O_QIT_FROM_E_S_QTableList_E_S_QIT_WHERE_E_S_QExpression_E_Opt_C_E_Opt",
  "_O_QIT_LIMIT_E_S_QINTEGER_E_C", "_Q_O_QIT_LIMIT_E_S_QINTEGER_E_C_E_Opt",
  "_O_QIT_OFFSET_E_S_QINTEGER_E_C",
  "_Q_O_QIT_OFFSET_E_S_QINTEGER_E_C_E_Opt", "AttributeList",
  "_O_QGT_COMMA_E_S_QNamedAttribute_E_C",
  "_Q_O_QGT_COMMA_E_S_QNamedAttribute_E_C_E_Star", "NamedAttribute",
  "_O_QIT_AS_E_S_QAttribute_E_C", "_Q_O_QIT_AS_E_S_QAttribute_E_C_E_Opt",
  "FQAttribute", "Attribute", "Relation", "TableList",
  "_O_QIT_INNER_E_Or_QGT_COMMA_E_Or_QIT_LEFT_E_S_QIT_OUTER_E_C",
  "_O_QIT_ON_E_S_QExpression_E_C", "_Q_O_QIT_ON_E_S_QExpression_E_C_E_Opt",
  "_O_QIT_INNER_E_Or_QGT_COMMA_E_Or_QIT_LEFT_E_S_QIT_OUTER_E_S_QIT_JOIN_E_S_QTableAlias_E_S_QIT_ON_E_S_QExpression_E_Opt_C",
  "_Q_O_QIT_INNER_E_Or_QGT_COMMA_E_Or_QIT_LEFT_E_S_QIT_OUTER_E_S_QIT_JOIN_E_S_QTableAlias_E_S_QIT_ON_E_S_QExpression_E_Opt_C_E_Star",
  "TableAlias", "_O_QIT_AS_E_S_QRelation_E_C",
  "_Q_O_QIT_AS_E_S_QRelation_E_C_E_Opt", "Expression",
  "ConditionalOrExpression", "_O_QIT_OR_E_S_QConditionalAndExpression_E_C",
  "_Q_O_QIT_OR_E_S_QConditionalAndExpression_E_C_E_Star",
  "ConditionalAndExpression", "_O_QIT_AND_E_S_QValueLogical_E_C",
  "_Q_O_QIT_AND_E_S_QValueLogical_E_C_E_Star", "ValueLogical",
  "RelationalExpression", "RightRelationalExpression",
  "_QRightRelationalExpression_E_Opt", "NumericExpression",
  "AdditiveExpression",
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
        67,     0,    -1,    80,    68,    -1,    71,    70,    68,    -1,
      -1,    35,    -1,    35,    71,    -1,    -1,    70,    69,    -1,
      -1,    36,    37,   100,    72,    38,    75,    74,    39,    -1,
      40,    75,    -1,    -1,    74,    73,    -1,    99,    76,    -1,
      41,    42,    77,    43,   100,    77,    -1,    44,    42,    77,
      -1,    45,    -1,    46,    -1,    47,    -1,    48,    -1,    49,
      -1,    38,    99,    79,    39,    -1,    40,    99,    -1,    -1,
      79,    78,    -1,    83,    82,    -1,     4,    83,    -1,    -1,
      82,    81,    -1,     3,    92,    87,    89,    91,    -1,     5,
     110,    -1,    -1,    84,    -1,     6,   101,    85,    -1,    -1,
      86,    -1,    18,    51,    -1,    17,    27,    51,    -1,    -1,
      88,    -1,    19,    51,    -1,    -1,    90,    -1,    95,    94,
      -1,     7,    -1,    40,    95,    -1,    -1,    94,    93,    -1,
     110,    97,    -1,     8,    99,    -1,    99,    -1,    -1,    96,
      -1,   100,     9,    99,    -1,    50,    -1,    50,    -1,   107,
     106,    -1,    10,    -1,    40,    -1,    11,    12,    -1,    13,
     110,    -1,    -1,   103,    -1,   102,    14,   107,   104,    -1,
      -1,   106,   105,    -1,   100,   109,    -1,    38,    80,    39,
     100,    -1,    38,    80,    39,     8,   100,    -1,     8,   100,
      -1,   100,    -1,    -1,   108,    -1,   111,    -1,   114,   113,
      -1,    15,   114,    -1,    -1,   113,   112,    -1,   117,   116,
      -1,    16,   117,    -1,    -1,   116,   115,    -1,   118,    -1,
     121,   120,    -1,    23,   121,    -1,    24,   121,    -1,    25,
     121,    -1,    26,   121,    -1,    27,   121,    -1,    28,   121,
      -1,    20,    22,    -1,    20,    21,    22,    -1,    -1,   119,
      -1,   122,    -1,   125,   124,    -1,    29,   125,    -1,    30,
     125,    -1,   136,    -1,   137,    -1,    -1,   124,   123,    -1,
     128,   127,    -1,     7,   128,    -1,    31,   128,    -1,    -1,
     127,   126,    -1,    32,   129,    -1,    29,   129,    -1,    30,
     129,    -1,   129,    -1,   130,    -1,   131,    -1,   139,    -1,
     134,    -1,   138,    -1,    98,    -1,    22,    -1,    38,   110,
      39,    -1,    33,    38,   110,   133,    39,    -1,    34,    38,
     110,    40,   110,    39,    -1,    40,   110,    -1,    -1,   133,
     132,    -1,   135,    -1,   136,    -1,   137,    -1,    51,    -1,
      54,    -1,    57,    -1,    52,    -1,    55,    -1,    58,    -1,
      53,    -1,    56,    -1,    59,    -1,    64,    -1,    65,    -1,
      60,    -1,    61,    -1,    62,    -1,    63,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  SQLParser::yyprhs_[] =
  {
         0,     0,     3,     6,    10,    11,    13,    16,    17,    20,
      21,    30,    33,    34,    37,    40,    47,    51,    53,    55,
      57,    59,    61,    66,    69,    70,    73,    76,    79,    80,
      83,    89,    92,    93,    95,    99,   100,   102,   105,   109,
     110,   112,   115,   116,   118,   121,   123,   126,   127,   130,
     133,   136,   138,   139,   141,   145,   147,   149,   152,   154,
     156,   159,   162,   163,   165,   170,   171,   174,   177,   182,
     188,   191,   193,   194,   196,   198,   201,   204,   205,   208,
     211,   214,   215,   218,   220,   223,   226,   229,   232,   235,
     238,   241,   244,   248,   249,   251,   253,   256,   259,   262,
     264,   266,   267,   270,   273,   276,   279,   280,   283,   286,
     289,   292,   294,   296,   298,   300,   302,   304,   306,   308,
     312,   318,   325,   328,   329,   332,   334,   336,   338,   340,
     342,   344,   346,   348,   350,   352,   354,   356,   358,   360,
     362,   364,   366
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SQLParser::yyrline_[] =
  {
         0,   287,   287,   291,   294,   296,   300,   303,   305,   309,
     309,   319,   322,   324,   328,   334,   339,   345,   349,   353,
     357,   361,   367,   375,   381,   385,   393,   405,   411,   415,
     422,   439,   445,   449,   453,   462,   467,   471,   476,   484,
     488,   492,   500,   504,   508,   514,   520,   526,   530,   537,
     544,   547,   551,   555,   561,   569,   573,   577,   590,   594,
     598,   604,   610,   614,   620,   633,   638,   647,   652,   657,
     665,   668,   672,   676,   682,   687,   699,   706,   709,   717,
     729,   736,   739,   746,   751,   770,   773,   776,   779,   782,
     785,   788,   791,   798,   802,   806,   811,   823,   826,   829,
     830,   835,   838,   846,   858,   861,   868,   871,   878,   881,
     884,   887,   891,   892,   893,   894,   895,   896,   897,   903,
     909,   916,   922,   928,   932,   939,   940,   941,   945,   946,
     947,   951,   952,   953,   957,   958,   959,   963,   964,   968,
     969,   970,   971
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
      65
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int SQLParser::yyeof_ = 0;
  const int SQLParser::yylast_ = 200;
  const int SQLParser::yynnts_ = 74;
  const int SQLParser::yyempty_ = -2;
  const int SQLParser::yyfinal_ = 54;
  const int SQLParser::yyterror_ = 1;
  const int SQLParser::yyerrcode_ = 256;
  const int SQLParser::yyntokens_ = 66;

  const unsigned int SQLParser::yyuser_token_number_max_ = 320;
  const SQLParser::token_number_type SQLParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 2067 "lib/SQLParser/SQLParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 976 "lib/SQLParser/SQLParser.ypp"
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
      trace_parsing(false),
      context(_context)
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

