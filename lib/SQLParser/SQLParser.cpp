
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
#line 195 "lib/SQLParser/SQLParser.ypp"

#include "SQLScanner.hpp"

/* Line 317 of lalr1.cc  */
#line 263 "lib/SQLParser/SQLParser.ypp"

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
#line 279 "lib/SQLParser/SQLParser.ypp"
    {
    driver.root = (yysemantic_stack_[(2) - (1)].p_Select);
}
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 301 "lib/SQLParser/SQLParser.ypp"
    {
    driver.curCreate = new sql::schema::Relation(*(yysemantic_stack_[(3) - (3)].p_NAME));
      }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 303 "lib/SQLParser/SQLParser.ypp"
    {
      driver.tables[*(yysemantic_stack_[(8) - (3)].p_NAME)] = driver.curCreate;
      driver.curCreate = NULL;
}
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 319 "lib/SQLParser/SQLParser.ypp"
    {
    std::string s = *(yysemantic_stack_[(2) - (1)].p_NAME);
    sql::schema::Field* f = new sql::schema::Field(s, (yysemantic_stack_[(2) - (2)].p_SchemaDatatype));
    driver.curCreate->addField(f);
}
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 325 "lib/SQLParser/SQLParser.ypp"
    {
    driver.curCreate->addForeignKey(new sql::schema::ForeignKey((yysemantic_stack_[(6) - (3)].p_Attributes), *(yysemantic_stack_[(6) - (5)].p_NAME), (yysemantic_stack_[(6) - (6)].p_Attributes)));
}
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 329 "lib/SQLParser/SQLParser.ypp"
    {
    driver.curCreate->addPrimaryKey(new sql::schema::PrimaryKey((yysemantic_stack_[(3) - (3)].p_Attributes)));
}
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 335 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_SchemaDatatype) = sql::schema::TYPE_int;
}
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 339 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_SchemaDatatype) = sql::schema::TYPE_double;
}
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 343 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_SchemaDatatype) = sql::schema::TYPE_date;
}
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 347 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_SchemaDatatype) = sql::schema::TYPE_datetime;
}
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 351 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_SchemaDatatype) = sql::schema::TYPE_string;
}
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 357 "lib/SQLParser/SQLParser.ypp"
    {
    (yysemantic_stack_[(4) - (3)].p_Attributes)->insert((yysemantic_stack_[(4) - (3)].p_Attributes)->begin(), *(yysemantic_stack_[(4) - (2)].p_NAME));
    delete (yysemantic_stack_[(4) - (2)].p_NAME);
    (yyval.p_Attributes) = (yysemantic_stack_[(4) - (3)].p_Attributes);
}
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 365 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = (yysemantic_stack_[(2) - (2)].p_NAME);
}
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 371 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Attributes) = new std::vector<std::string>();
}
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 375 "lib/SQLParser/SQLParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_Attributes)->push_back(*(yysemantic_stack_[(2) - (2)].p_NAME));
    (yyval.p_Attributes) = (yysemantic_stack_[(2) - (1)].p_Attributes);
}
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 382 "lib/SQLParser/SQLParser.ypp"
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
#line 394 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Select) = (yysemantic_stack_[(2) - (2)].p_Select);
}
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 400 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Selects) = new std::vector<sql::SQLQuery*>();
}
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 404 "lib/SQLParser/SQLParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_Selects)->push_back((yysemantic_stack_[(2) - (2)].p_Select));
    (yyval.p_Selects) = (yysemantic_stack_[(2) - (1)].p_Selects);
}
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 411 "lib/SQLParser/SQLParser.ypp"
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
#line 428 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 434 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = NULL;
}
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 442 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TableList).joins = (yysemantic_stack_[(3) - (2)].p_TableList).joins;
	(yyval.p_TableList).exprs = (yysemantic_stack_[(3) - (2)].p_TableList).exprs;
	if ((yysemantic_stack_[(3) - (3)].p_Expression) != NULL)
	    (yyval.p_TableList).exprs->push_back((yysemantic_stack_[(3) - (3)].p_Expression));
}
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 451 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_TableList).joins = new std::vector<sql::Join*>();;
    (yyval.p_TableList).exprs = new std::vector<const sql::Expression*>();;
}
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 460 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 468 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_int) = -1;
}
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 476 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 484 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_int) = -1;
}
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 492 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (2)].p_AttributeList)->insert((yysemantic_stack_[(2) - (2)].p_AttributeList)->begin(), (yysemantic_stack_[(2) - (1)].p_AliasedSelect));
	(yyval.p_AttributeList) = new std::vector<sql::AliasedSelect*>((yysemantic_stack_[(2) - (2)].p_AttributeList)->begin(), (yysemantic_stack_[(2) - (2)].p_AttributeList)->end());
	delete (yysemantic_stack_[(2) - (2)].p_AttributeList);
}
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 498 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AttributeList) = new std::vector<sql::AliasedSelect*>();
}
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 504 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AliasedSelect) = (yysemantic_stack_[(2) - (2)].p_AliasedSelect);
}
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 510 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AttributeList) = new std::vector<sql::AliasedSelect*>();
}
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 514 "lib/SQLParser/SQLParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_AttributeList)->push_back((yysemantic_stack_[(2) - (2)].p_AliasedSelect));
    (yyval.p_AttributeList) = (yysemantic_stack_[(2) - (1)].p_AttributeList);
}
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 521 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AliasedSelect) = new sql::AliasedSelect((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_NAME) ? *(yysemantic_stack_[(2) - (2)].p_NAME) : (yysemantic_stack_[(2) - (1)].p_Expression)->toString());
	delete (yysemantic_stack_[(2) - (2)].p_NAME);
}
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 528 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = (yysemantic_stack_[(2) - (2)].p_NAME);
}
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 534 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = NULL;
}
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 538 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = (yysemantic_stack_[(1) - (1)].p_NAME);
}
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 544 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::AliasAttrConstraint(sql::AliasAttr(*(yysemantic_stack_[(3) - (1)].p_NAME), *(yysemantic_stack_[(3) - (3)].p_NAME)));
	delete (yysemantic_stack_[(3) - (1)].p_NAME);
	delete (yysemantic_stack_[(3) - (3)].p_NAME);
}
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 560 "lib/SQLParser/SQLParser.ypp"
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

  case 56:

/* Line 678 of lalr1.cc  */
#line 573 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_bool) = false;
}
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 577 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_bool) = false;
}
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 581 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_bool) = true;
}
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 587 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 593 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = NULL;
}
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 597 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(1) - (1)].p_Expression);
}
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 603 "lib/SQLParser/SQLParser.ypp"
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

  case 63:

/* Line 678 of lalr1.cc  */
#line 616 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TableList).joins = new std::vector<sql::Join*>();
	(yyval.p_TableList).exprs = new std::vector<const sql::Expression*>();
}
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 621 "lib/SQLParser/SQLParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_TableList).joins->push_back((yysemantic_stack_[(2) - (2)].p_JoinExpression).join);
    if ((yysemantic_stack_[(2) - (2)].p_JoinExpression).expr != NULL)
	(yysemantic_stack_[(2) - (1)].p_TableList).exprs->push_back((yysemantic_stack_[(2) - (2)].p_JoinExpression).expr);
    (yyval.p_TableList) = (yysemantic_stack_[(2) - (1)].p_TableList);
}
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 630 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_tableAlias).relation = (yysemantic_stack_[(2) - (1)].p_NAME);
	(yyval.p_tableAlias).subselect = NULL;
	(yyval.p_tableAlias).alias = (yysemantic_stack_[(2) - (2)].p_NAME) ? (yysemantic_stack_[(2) - (2)].p_NAME) : new std::string(*(yysemantic_stack_[(2) - (1)].p_NAME));
}
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 635 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_tableAlias).relation = NULL;
	(yyval.p_tableAlias).subselect = (yysemantic_stack_[(5) - (2)].p_Select);
	(yyval.p_tableAlias).alias = (yysemantic_stack_[(5) - (5)].p_NAME);
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 643 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = (yysemantic_stack_[(2) - (2)].p_NAME);
}
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 649 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = NULL;
}
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 653 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = (yysemantic_stack_[(1) - (1)].p_NAME);
}
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 664 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::DisjunctionConstraint((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 676 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 683 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 686 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 694 "lib/SQLParser/SQLParser.ypp"
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
#line 706 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 713 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 716 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 728 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_BooleanComparator)) {
	    if (dynamic_cast<sql::IsNotNullProxy*>((yysemantic_stack_[(2) - (2)].p_BooleanComparator)) != NULL) {
		(yyval.p_Expression) = new sql::NegationConstraint(new sql::NullConstraint(dynamic_cast<const sql::WhereConstraint*>((yysemantic_stack_[(2) - (1)].p_Expression)))); // new sql::ReallyNullConstraint();
	    } else if (dynamic_cast<sql::IsNullProxy*>((yysemantic_stack_[(2) - (2)].p_BooleanComparator)) != NULL) {
		(yyval.p_Expression) = new sql::NullConstraint(dynamic_cast<const sql::WhereConstraint*>((yysemantic_stack_[(2) - (1)].p_Expression)));
	    } else {
		(yysemantic_stack_[(2) - (2)].p_BooleanComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
		(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_BooleanComparator); // !!!
	    }
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 745 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 748 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 751 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 754 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 757 "lib/SQLParser/SQLParser.ypp"
    {
        (yyval.p_BooleanComparator) = new sql::BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 760 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 763 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_BooleanComparator) = new sql::IsNullProxy;
}
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 766 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_BooleanComparator) = new sql::IsNotNullProxy;
}
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 773 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = NULL;
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 786 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::ArithmeticSum((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 798 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 801 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 810 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 813 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 821 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::ArithmeticProduct((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 833 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 836 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 843 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 846 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 853 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 856 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 859 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 875 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
}
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 881 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(5) - (4)].p_Expressions)->insert((yysemantic_stack_[(5) - (4)].p_Expressions)->begin(), (yysemantic_stack_[(5) - (3)].p_Expression));
	(yyval.p_Expression) = new sql::ConcatConstraint((yysemantic_stack_[(5) - (4)].p_Expressions)->begin(), (yysemantic_stack_[(5) - (4)].p_Expressions)->end());
	delete (yysemantic_stack_[(5) - (4)].p_Expressions);
}
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 888 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::RegexConstraint((yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression));
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 894 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 900 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
}
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 904 "lib/SQLParser/SQLParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    (yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
}
    break;



/* Line 678 of lalr1.cc  */
#line 1349 "lib/SQLParser/SQLParser.cpp"
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
  const short int SQLParser::yypact_ninf_ = -175;
  const short int
  SQLParser::yypact_[] =
  {
         2,     1,   -24,    31,  -175,     7,  -175,  -175,    97,    97,
      97,    10,    35,    38,  -175,  -175,  -175,  -175,  -175,  -175,
    -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,
      62,  -175,  -175,   107,    36,  -175,  -175,  -175,  -175,    54,
    -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,
    -175,  -175,    25,  -175,    84,  -175,  -175,   115,  -175,  -175,
    -175,    38,    38,    86,   -28,  -175,   108,    87,    78,    78,
    -175,  -175,   113,   116,   -10,    38,    38,    38,    38,    38,
      38,  -175,  -175,   -12,     6,  -175,    96,  -175,  -175,   130,
    -175,  -175,    98,  -175,   130,   127,   133,  -175,    89,  -175,
     123,    38,  -175,  -175,  -175,  -175,    38,  -175,    38,  -175,
     121,  -175,  -175,  -175,  -175,  -175,  -175,  -175,    38,    38,
    -175,  -175,  -175,    38,    38,  -175,   106,  -175,  -175,   -19,
      38,   124,    25,  -175,  -175,    38,  -175,  -175,    -4,  -175,
      94,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,
    -175,   -25,  -175,    38,  -175,   125,   156,  -175,  -175,  -175,
     153,  -175,   152,  -175,  -175,   126,   128,  -175,    65,  -175,
    -175,    25,  -175,   -28,   131,   131,   -16,  -175,  -175,  -175,
    -175,  -175,  -175,  -175,   157,    78,   129,  -175,  -175,   -25,
    -175,    38,  -175,  -175,  -175,    25,  -175,  -175,    45,   131,
    -175,    78,  -175,  -175,  -175
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  SQLParser::yydefact_[] =
  {
         0,     0,     0,     0,     7,     4,    28,    44,     0,     0,
       0,     0,     0,     0,    54,   123,   126,   129,   124,   127,
     130,   125,   128,   131,   134,   135,   136,   137,   132,   133,
      35,    46,   113,     0,    50,    70,    73,    77,    79,    89,
      91,    97,   102,   107,   108,   109,   111,   120,   121,   122,
     112,   110,     0,     1,     4,     5,     2,    26,   105,   106,
     104,     0,     0,     0,     0,    36,    38,    43,     0,     0,
      51,    48,    71,    75,     0,     0,     0,     0,     0,     0,
       0,    90,    80,    92,    99,     9,     5,     3,     8,     0,
      29,   118,     0,   114,     0,    68,    32,    63,     0,    39,
      41,     0,    47,    53,    52,    49,     0,    74,     0,    78,
       0,    87,    81,    82,    83,    84,    85,    86,     0,     0,
      98,    95,    96,     0,     0,   103,     0,     6,    27,     0,
       0,     0,     0,    69,    65,     0,    33,    34,    55,    37,
       0,    42,    30,    45,    72,    76,    88,    93,    94,   100,
     101,     0,   115,     0,   119,     0,     0,    67,    31,    56,
       0,    57,     0,    64,    40,     0,     0,    12,     0,   117,
     116,     0,    58,     0,     0,     0,     0,    17,    18,    19,
      20,    21,    14,    66,    60,     0,     0,    16,    10,     0,
      13,     0,    61,    62,    24,     0,    11,    59,     0,     0,
      22,     0,    25,    15,    23
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SQLParser::yypgoto_[] =
  {
      -175,  -175,   118,  -175,  -175,    88,  -175,  -175,  -175,   -14,
    -175,  -174,  -175,  -175,    79,  -175,  -175,    90,  -175,  -175,
    -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,    75,
    -175,  -175,  -175,   -65,   -50,  -175,  -175,  -175,  -175,  -175,
    -175,     4,  -175,  -175,   -13,  -175,  -175,  -175,    74,  -175,
    -175,    73,  -175,  -175,  -175,    28,  -175,  -175,  -175,   -33,
    -175,  -175,    -9,    18,  -175,  -175,  -175,  -175,  -175,  -175,
      99,   100,  -175,  -175
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SQLParser::yydefgoto_[] =
  {
        -1,     3,    56,    88,    54,     4,   126,   190,   176,   167,
     182,   186,   202,   198,     5,    90,    57,     6,   136,   137,
      65,    66,    99,   100,   141,   142,    30,   102,    67,    31,
      70,    71,    32,   168,    33,    96,   162,   192,   193,   163,
     138,    97,   133,   134,    34,    35,   107,    72,    36,   109,
      73,    37,    38,    81,    82,    39,    40,   120,    83,    41,
     125,    84,    42,    43,    44,    45,   154,   129,    46,    47,
      48,    49,    50,    51
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char SQLParser::yytable_ninf_ = -1;
  const unsigned char
  SQLParser::yytable_[] =
  {
        63,   187,    85,   104,   105,     1,   159,   160,     7,    94,
     110,   111,    52,   123,    95,   165,   118,   119,   166,   152,
     153,    14,   188,   189,   103,   203,    58,    59,    60,     8,
       9,    53,    10,    11,    12,   161,   124,     2,    13,    16,
      17,    55,    19,    20,    69,    22,    23,    61,    91,    92,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,     8,     9,    64,    10,
      11,    12,    62,    74,    14,    13,    75,    76,    77,    78,
      79,    80,   157,   200,   201,   147,   148,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,   112,   113,   114,   115,   116,   117,   177,
     178,   179,   180,   181,   149,   150,    68,   155,    86,    89,
     194,   183,   158,    95,    93,    98,   101,   103,   106,    11,
      12,     2,   108,     1,    13,   132,   204,   130,   135,   139,
     169,   140,   146,   151,   164,   199,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,   156,   170,   171,   172,   173,   174,   185,   175,
     191,   195,    87,   131,   127,   196,   143,   184,   197,   128,
     144,   145,   121,   122
  };

  /* YYCHECK.  */
  const unsigned char
  SQLParser::yycheck_[] =
  {
        13,   175,    52,    68,    69,     3,    10,    11,     7,    37,
      20,    21,    36,     7,    64,    40,    28,    29,    43,    38,
      39,    49,    38,    39,    49,   199,     8,     9,    10,    28,
      29,     0,    31,    32,    33,    39,    30,    35,    37,    51,
      52,    34,    54,    55,     8,    57,    58,    37,    61,    62,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    28,    29,     6,    31,
      32,    33,    37,    19,    49,    37,    22,    23,    24,    25,
      26,    27,   132,    38,    39,   118,   119,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    75,    76,    77,    78,    79,    80,    44,
      45,    46,    47,    48,   123,   124,     9,   130,    34,     4,
     185,   171,   135,   173,    38,    17,    39,    49,    15,    32,
      33,    35,    16,     3,    37,     8,   201,    39,     5,    50,
     153,    18,    21,    37,    50,   195,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    38,    38,     8,    12,    14,    41,    37,    41,
      13,    42,    54,    94,    86,   189,   101,   173,   191,    89,
     106,   108,    83,    83
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  SQLParser::yystos_[] =
  {
         0,     3,    35,    66,    70,    79,    82,     7,    28,    29,
      31,    32,    33,    37,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      91,    94,    97,    99,   109,   110,   113,   116,   117,   120,
     121,   124,   127,   128,   129,   130,   133,   134,   135,   136,
     137,   138,    36,     0,    69,    34,    67,    81,   128,   128,
     128,    37,    37,   109,     6,    85,    86,    93,     9,     8,
      95,    96,   112,   115,    19,    22,    23,    24,    25,    26,
      27,   118,   119,   123,   126,    99,    34,    67,    68,     4,
      80,   109,   109,    38,    37,    99,   100,   106,    17,    87,
      88,    39,    92,    49,    98,    98,    15,   111,    16,   114,
      20,    21,   120,   120,   120,   120,   120,   120,    28,    29,
     122,   135,   136,     7,    30,   125,    71,    70,    82,   132,
      39,    79,     8,   107,   108,     5,    83,    84,   105,    50,
      18,    89,    90,    94,   113,   116,    21,   124,   124,   127,
     127,    37,    38,    39,   131,   109,    38,    99,   109,    10,
      11,    39,   101,   104,    50,    40,    43,    74,    98,   109,
      38,     8,    12,    14,    41,    41,    73,    44,    45,    46,
      47,    48,    75,    99,   106,    37,    76,    76,    38,    39,
      72,    13,   102,   103,    98,    42,    74,   109,    78,    99,
      38,    39,    77,    76,    98
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
     315,   316,   317,   318,   319
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  SQLParser::yyr1_[] =
  {
         0,    65,    66,    66,    67,    67,    68,    69,    69,    71,
      70,    72,    73,    73,    74,    74,    74,    75,    75,    75,
      75,    75,    76,    77,    78,    78,    79,    80,    81,    81,
      82,    83,    84,    84,    85,    86,    86,    87,    88,    88,
      89,    90,    90,    91,    91,    92,    93,    93,    94,    95,
      96,    96,    97,    98,    99,   100,   101,   101,   101,   102,
     103,   103,   104,   105,   105,   106,   106,   107,   108,   108,
     109,   110,   111,   112,   112,   113,   114,   115,   115,   116,
     117,   118,   118,   118,   118,   118,   118,   118,   118,   119,
     119,   120,   121,   122,   122,   122,   122,   123,   123,   124,
     125,   125,   126,   126,   127,   127,   127,   127,   128,   128,
     128,   128,   128,   128,   129,   130,   130,   131,   132,   132,
     133,   133,   133,   134,   134,   134,   135,   135,   135,   136,
     136,   136,   137,   137,   138,   138,   138,   138
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  SQLParser::yyr2_[] =
  {
         0,     2,     2,     3,     0,     1,     2,     0,     2,     0,
       8,     2,     0,     2,     2,     6,     3,     1,     1,     1,
       1,     1,     4,     2,     0,     2,     2,     2,     0,     2,
       5,     2,     0,     1,     3,     0,     1,     2,     0,     1,
       2,     0,     1,     2,     1,     2,     0,     2,     2,     2,
       0,     1,     3,     1,     1,     2,     1,     1,     2,     2,
       0,     1,     4,     0,     2,     2,     5,     2,     0,     1,
       1,     2,     2,     0,     2,     2,     2,     0,     2,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     3,     0,
       1,     1,     2,     2,     2,     1,     1,     0,     2,     2,
       2,     2,     0,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     5,     6,     2,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
  "IT_LEFT", "IT_OUTER", "IT_ON", "IT_JOIN", "IT_OR", "IT_AND", "IT_LIMIT",
  "IT_OFFSET", "IT_IS", "IT_NOT", "IT_NULL", "GT_EQUAL", "GT_NEQUAL",
  "GT_LT", "GT_GT", "GT_LE", "GT_GE", "GT_PLUS", "GT_MINUS", "GT_DIVIDE",
  "GT_NOT", "IT_CONCAT", "IT_REGEX", "GT_SEMI", "IT_CREATE", "IT_TABLE",
  "GT_LPAREN", "GT_RPAREN", "GT_COMMA", "IT_FOREIGN", "IT_KEY",
  "IT_REFERENCES", "IT_PRIMARY", "IT_INT", "IT_DOUBLE", "IT_DATE",
  "IT_DATETIME", "IT_STRING", "NAME", "INTEGER", "INTEGER_POSITIVE",
  "INTEGER_NEGATIVE", "DECIMAL", "DECIMAL_POSITIVE", "DECIMAL_NEGATIVE",
  "DOUBLE", "DOUBLE_POSITIVE", "DOUBLE_NEGATIVE", "STRING_LITERAL1",
  "STRING_LITERAL2", "STRING_LITERAL_LONG1", "STRING_LITERAL_LONG2",
  "IT_true", "IT_false", "$accept", "Statement", "_QGT_SEMI_E_Opt",
  "_O_QGT_SEMI_E_S_QCreate_E_C", "_Q_O_QGT_SEMI_E_S_QCreate_E_C_E_Star",
  "Create", "$@1", "_O_QGT_COMMA_E_S_QFieldOrKey_E_C",
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
        66,     0,    -1,    79,    67,    -1,    70,    69,    67,    -1,
      -1,    34,    -1,    34,    70,    -1,    -1,    69,    68,    -1,
      -1,    35,    36,    99,    71,    37,    74,    73,    38,    -1,
      39,    74,    -1,    -1,    73,    72,    -1,    98,    75,    -1,
      40,    41,    76,    42,    99,    76,    -1,    43,    41,    76,
      -1,    44,    -1,    45,    -1,    46,    -1,    47,    -1,    48,
      -1,    37,    98,    78,    38,    -1,    39,    98,    -1,    -1,
      78,    77,    -1,    82,    81,    -1,     4,    82,    -1,    -1,
      81,    80,    -1,     3,    91,    86,    88,    90,    -1,     5,
     109,    -1,    -1,    83,    -1,     6,   100,    84,    -1,    -1,
      85,    -1,    17,    50,    -1,    -1,    87,    -1,    18,    50,
      -1,    -1,    89,    -1,    94,    93,    -1,     7,    -1,    39,
      94,    -1,    -1,    93,    92,    -1,   109,    96,    -1,     8,
      98,    -1,    -1,    95,    -1,    99,     9,    98,    -1,    49,
      -1,    49,    -1,   106,   105,    -1,    10,    -1,    39,    -1,
      11,    12,    -1,    13,   109,    -1,    -1,   102,    -1,   101,
      14,   106,   103,    -1,    -1,   105,   104,    -1,    99,   108,
      -1,    37,    79,    38,     8,    99,    -1,     8,    99,    -1,
      -1,   107,    -1,   110,    -1,   113,   112,    -1,    15,   113,
      -1,    -1,   112,   111,    -1,   116,   115,    -1,    16,   116,
      -1,    -1,   115,   114,    -1,   117,    -1,   120,   119,    -1,
      22,   120,    -1,    23,   120,    -1,    24,   120,    -1,    25,
     120,    -1,    26,   120,    -1,    27,   120,    -1,    19,    21,
      -1,    19,    20,    21,    -1,    -1,   118,    -1,   121,    -1,
     124,   123,    -1,    28,   124,    -1,    29,   124,    -1,   135,
      -1,   136,    -1,    -1,   123,   122,    -1,   127,   126,    -1,
       7,   127,    -1,    30,   127,    -1,    -1,   126,   125,    -1,
      31,   128,    -1,    28,   128,    -1,    29,   128,    -1,   128,
      -1,   129,    -1,   130,    -1,   138,    -1,   133,    -1,   137,
      -1,    97,    -1,    37,   109,    38,    -1,    32,    37,   109,
     132,    38,    -1,    33,    37,   109,    39,   109,    38,    -1,
      39,   109,    -1,    -1,   132,   131,    -1,   134,    -1,   135,
      -1,   136,    -1,    50,    -1,    53,    -1,    56,    -1,    51,
      -1,    54,    -1,    57,    -1,    52,    -1,    55,    -1,    58,
      -1,    63,    -1,    64,    -1,    59,    -1,    60,    -1,    61,
      -1,    62,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  SQLParser::yyprhs_[] =
  {
         0,     0,     3,     6,    10,    11,    13,    16,    17,    20,
      21,    30,    33,    34,    37,    40,    47,    51,    53,    55,
      57,    59,    61,    66,    69,    70,    73,    76,    79,    80,
      83,    89,    92,    93,    95,    99,   100,   102,   105,   106,
     108,   111,   112,   114,   117,   119,   122,   123,   126,   129,
     132,   133,   135,   139,   141,   143,   146,   148,   150,   153,
     156,   157,   159,   164,   165,   168,   171,   177,   180,   181,
     183,   185,   188,   191,   192,   195,   198,   201,   202,   205,
     207,   210,   213,   216,   219,   222,   225,   228,   231,   235,
     236,   238,   240,   243,   246,   249,   251,   253,   254,   257,
     260,   263,   266,   267,   270,   273,   276,   279,   281,   283,
     285,   287,   289,   291,   293,   297,   303,   310,   313,   314,
     317,   319,   321,   323,   325,   327,   329,   331,   333,   335,
     337,   339,   341,   343,   345,   347,   349,   351
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SQLParser::yyrline_[] =
  {
         0,   279,   279,   283,   286,   288,   292,   295,   297,   301,
     301,   310,   313,   315,   319,   325,   329,   335,   339,   343,
     347,   351,   357,   365,   371,   375,   382,   394,   400,   404,
     411,   428,   434,   438,   442,   451,   456,   460,   468,   472,
     476,   484,   488,   492,   498,   504,   510,   514,   521,   528,
     534,   538,   544,   552,   556,   560,   573,   577,   581,   587,
     593,   597,   603,   616,   621,   630,   635,   643,   649,   653,
     659,   664,   676,   683,   686,   694,   706,   713,   716,   723,
     728,   745,   748,   751,   754,   757,   760,   763,   766,   773,
     777,   781,   786,   798,   801,   804,   805,   810,   813,   821,
     833,   836,   843,   846,   853,   856,   859,   862,   866,   867,
     868,   869,   870,   871,   875,   881,   888,   894,   900,   904,
     911,   912,   913,   917,   918,   919,   923,   924,   925,   929,
     930,   931,   935,   936,   940,   941,   942,   943
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int SQLParser::yyeof_ = 0;
  const int SQLParser::yylast_ = 183;
  const int SQLParser::yynnts_ = 74;
  const int SQLParser::yyempty_ = -2;
  const int SQLParser::yyfinal_ = 53;
  const int SQLParser::yyterror_ = 1;
  const int SQLParser::yyerrcode_ = 256;
  const int SQLParser::yyntokens_ = 65;

  const unsigned int SQLParser::yyuser_token_number_max_ = 319;
  const SQLParser::token_number_type SQLParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 2017 "lib/SQLParser/SQLParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 948 "lib/SQLParser/SQLParser.ypp"
 /*** Additional Code ***/

void w3c_sw::SQLParser::error(const SQLParser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}

/* START SQLDriver (@@ stand-alone would allow it to be shared with other parsers */

namespace w3c_sw {

SQLDriver::SQLDriver(class sqlContext& _context)
    : trace_scanning(false),
      trace_parsing(false),
      context(_context)
{
}

bool SQLDriver::parse (IStreamContext& in)
{
    streamname = in.nameStr;

    SQLScanner scanner(this, in.p);
    scanner.set_debug(trace_scanning);
    lexer = &scanner;

    SQLParser parser(*this);
    parser.set_debug_level(trace_parsing);
    return (parser.parse());
}

void SQLDriver::error (const class location& l,
		   const std::string& m)
{
    std::stringstream s;
    s << l << ": " << m;
    throw s.str();
}

void SQLDriver::error (const std::string& m)
{
    throw m;
}

} // namespace w3c_sw

/* END SQLDriver */

