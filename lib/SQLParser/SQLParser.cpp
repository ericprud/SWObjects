
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
#line 206 "lib/SQLParser/SQLParser.ypp"

#include "SQLScanner.hpp"

/* Line 317 of lalr1.cc  */
#line 274 "lib/SQLParser/SQLParser.ypp"

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
#line 290 "lib/SQLParser/SQLParser.ypp"
    {
    driver.root = (yysemantic_stack_[(2) - (1)].p_Select);
}
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 312 "lib/SQLParser/SQLParser.ypp"
    {
	driver.curCreate = new sql::schema::Relation(*(yysemantic_stack_[(3) - (3)].p_NAME));
      }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 314 "lib/SQLParser/SQLParser.ypp"
    {
	  driver.tables[*(yysemantic_stack_[(8) - (3)].p_NAME)] = driver.curCreate;
	  delete (yysemantic_stack_[(8) - (3)].p_NAME);
	  driver.curCreate = NULL;
      }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 331 "lib/SQLParser/SQLParser.ypp"
    {
    sql::schema::Field* f = new sql::schema::Field(*(yysemantic_stack_[(2) - (1)].p_NAME), (yysemantic_stack_[(2) - (2)].p_SchemaDatatype));
    delete (yysemantic_stack_[(2) - (1)].p_NAME);
    driver.curCreate->addField(f);
}
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 337 "lib/SQLParser/SQLParser.ypp"
    {
    driver.curCreate->addForeignKey(new sql::schema::ForeignKey((yysemantic_stack_[(6) - (3)].p_Attributes), *(yysemantic_stack_[(6) - (5)].p_NAME), (yysemantic_stack_[(6) - (6)].p_Attributes)));
    delete (yysemantic_stack_[(6) - (5)].p_NAME);
}
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 342 "lib/SQLParser/SQLParser.ypp"
    {
    driver.curCreate->addPrimaryKey(new sql::schema::PrimaryKey((yysemantic_stack_[(3) - (3)].p_Attributes)));
}
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 348 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_SchemaDatatype) = sql::schema::TYPE_int;
}
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 352 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_SchemaDatatype) = sql::schema::TYPE_double;
}
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 356 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_SchemaDatatype) = sql::schema::TYPE_date;
}
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 360 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_SchemaDatatype) = sql::schema::TYPE_datetime;
}
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 364 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_SchemaDatatype) = sql::schema::TYPE_string;
}
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 370 "lib/SQLParser/SQLParser.ypp"
    {
    (yysemantic_stack_[(4) - (3)].p_Attributes)->insert((yysemantic_stack_[(4) - (3)].p_Attributes)->begin(), *(yysemantic_stack_[(4) - (2)].p_NAME));
    delete (yysemantic_stack_[(4) - (2)].p_NAME);
    (yyval.p_Attributes) = (yysemantic_stack_[(4) - (3)].p_Attributes);
}
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 378 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = (yysemantic_stack_[(2) - (2)].p_NAME);
}
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 384 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Attributes) = new std::vector<sql::Attribute>();
    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 387 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Attributes)->push_back(*(yysemantic_stack_[(2) - (2)].p_NAME));
	delete (yysemantic_stack_[(2) - (2)].p_NAME);
	(yyval.p_Attributes) = (yysemantic_stack_[(2) - (1)].p_Attributes);
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 395 "lib/SQLParser/SQLParser.ypp"
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
#line 407 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Select) = (yysemantic_stack_[(2) - (2)].p_Select);
}
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 413 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Selects) = new std::vector<sql::SQLQuery*>();
}
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 417 "lib/SQLParser/SQLParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_Selects)->push_back((yysemantic_stack_[(2) - (2)].p_Select));
    (yyval.p_Selects) = (yysemantic_stack_[(2) - (1)].p_Selects);
}
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 424 "lib/SQLParser/SQLParser.ypp"
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
#line 441 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 447 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = NULL;
}
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 455 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TableList).joins = (yysemantic_stack_[(3) - (2)].p_TableList).joins;
	(yyval.p_TableList).exprs = (yysemantic_stack_[(3) - (2)].p_TableList).exprs;
	if ((yysemantic_stack_[(3) - (3)].p_Expression) != NULL)
	    (yyval.p_TableList).exprs->push_back((yysemantic_stack_[(3) - (3)].p_Expression));
}
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 464 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_TableList).joins = new std::vector<sql::Join*>();;
    (yyval.p_TableList).exprs = new std::vector<const sql::Expression*>();;
}
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 473 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 478 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(3) - (3)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(3) - (3)].p_Expression);
}
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 486 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_int) = -1;
}
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 494 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 502 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_int) = -1;
}
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 510 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (2)].p_AttributeList)->insert((yysemantic_stack_[(2) - (2)].p_AttributeList)->begin(), (yysemantic_stack_[(2) - (1)].p_AliasedSelect));
	(yyval.p_AttributeList) = new std::vector<sql::AliasedSelect*>((yysemantic_stack_[(2) - (2)].p_AttributeList)->begin(), (yysemantic_stack_[(2) - (2)].p_AttributeList)->end());
	delete (yysemantic_stack_[(2) - (2)].p_AttributeList);
}
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 516 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AttributeList) = new std::vector<sql::AliasedSelect*>();
}
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 522 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AliasedSelect) = (yysemantic_stack_[(2) - (2)].p_AliasedSelect);
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 528 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AttributeList) = new std::vector<sql::AliasedSelect*>();
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 531 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_AttributeList)->push_back((yysemantic_stack_[(2) - (2)].p_AliasedSelect));
	(yyval.p_AttributeList) = (yysemantic_stack_[(2) - (1)].p_AttributeList);
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 538 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AliasedSelect) = new sql::AliasedSelect((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_NAME) ? *(yysemantic_stack_[(2) - (2)].p_NAME) : (yysemantic_stack_[(2) - (1)].p_Expression)->toString());
	delete (yysemantic_stack_[(2) - (2)].p_NAME);
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 545 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_NAME) = (yysemantic_stack_[(2) - (2)].p_NAME);
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 552 "lib/SQLParser/SQLParser.ypp"
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
	(yyval.p_Expression) = new sql::AliasAttrConstraint(sql::AliasAttr(sql::RelVar(*(yysemantic_stack_[(3) - (1)].p_NAME)), sql::Attribute(*(yysemantic_stack_[(3) - (3)].p_NAME))));
	delete (yysemantic_stack_[(3) - (1)].p_NAME);
	delete (yysemantic_stack_[(3) - (3)].p_NAME);
    }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 566 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_Expression) = new sql::AliasAttrConstraint(sql::AliasAttr(sql::RelVar(""), sql::Attribute(*(yysemantic_stack_[(1) - (1)].p_NAME))));
	delete (yysemantic_stack_[(1) - (1)].p_NAME);
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 581 "lib/SQLParser/SQLParser.ypp"
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
    (yyval.p_bool) = false;
}
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 602 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_bool) = true;
}
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 608 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 614 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = NULL;
}
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 618 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(1) - (1)].p_Expression);
}
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 624 "lib/SQLParser/SQLParser.ypp"
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

  case 66:

/* Line 678 of lalr1.cc  */
#line 637 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TableList).joins = new std::vector<sql::Join*>();
	(yyval.p_TableList).exprs = new std::vector<const sql::Expression*>();
}
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 642 "lib/SQLParser/SQLParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_TableList).joins->push_back((yysemantic_stack_[(2) - (2)].p_JoinExpression).join);
    if ((yysemantic_stack_[(2) - (2)].p_JoinExpression).expr != NULL)
	(yysemantic_stack_[(2) - (1)].p_TableList).exprs->push_back((yysemantic_stack_[(2) - (2)].p_JoinExpression).expr);
    (yyval.p_TableList) = (yysemantic_stack_[(2) - (1)].p_TableList);
}
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 651 "lib/SQLParser/SQLParser.ypp"
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

  case 69:

/* Line 678 of lalr1.cc  */
#line 662 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_tableAlias).relation = NULL;
	(yyval.p_tableAlias).subselect = (yysemantic_stack_[(4) - (2)].p_Select);
	(yyval.p_tableAlias).alias = new sql::RelVar(*(yysemantic_stack_[(4) - (4)].p_NAME));
	delete (yysemantic_stack_[(4) - (4)].p_NAME);
}
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 668 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_tableAlias).relation = NULL;
	(yyval.p_tableAlias).subselect = (yysemantic_stack_[(5) - (2)].p_Select);
	(yyval.p_tableAlias).alias = new sql::RelVar(*(yysemantic_stack_[(5) - (5)].p_NAME));
	delete (yysemantic_stack_[(5) - (5)].p_NAME);
}
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 677 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = (yysemantic_stack_[(2) - (2)].p_NAME);
}
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 684 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = NULL;
}
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 688 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = (yysemantic_stack_[(1) - (1)].p_NAME);
}
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 699 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::DisjunctionConstraint((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 711 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 718 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 721 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 729 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::DisjunctionConstraint((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 741 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 748 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 751 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 763 "lib/SQLParser/SQLParser.ypp"
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

  case 86:

/* Line 678 of lalr1.cc  */
#line 782 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 785 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 788 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 791 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 794 "lib/SQLParser/SQLParser.ypp"
    {
        (yyval.p_BooleanComparator) = new sql::BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 797 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 800 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_BooleanComparator) = new sql::IsNullProxy;
}
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 803 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_BooleanComparator) = new sql::IsNotNullProxy;
}
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 810 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = NULL;
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 823 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::ArithmeticSum((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 835 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 838 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 847 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 850 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 858 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    (yysemantic_stack_[(2) - (2)].p_Expressions)->insert((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new sql::ArithmeticProduct((yysemantic_stack_[(2) - (2)].p_Expressions)->begin(), (yysemantic_stack_[(2) - (2)].p_Expressions)->end());
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 870 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 873 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 880 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 883 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 890 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 893 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 896 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 909 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::IsNullConstraint();
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 915 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
}
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 921 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(5) - (4)].p_Expressions)->insert((yysemantic_stack_[(5) - (4)].p_Expressions)->begin(), (yysemantic_stack_[(5) - (3)].p_Expression));
	(yyval.p_Expression) = new sql::HomologConstraint("CONCAT", (yysemantic_stack_[(5) - (4)].p_Expressions)->begin(), (yysemantic_stack_[(5) - (4)].p_Expressions)->end());
	delete (yysemantic_stack_[(5) - (4)].p_Expressions);
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 926 "lib/SQLParser/SQLParser.ypp"
    {
	std::vector<const sql::Expression*> v;
	v.push_back((yysemantic_stack_[(4) - (3)].p_Expression));
	(yyval.p_Expression) = new sql::HomologConstraint("LCASE", v.begin(), v.end());
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 931 "lib/SQLParser/SQLParser.ypp"
    {
	std::vector<const sql::Expression*> v;
	v.push_back((yysemantic_stack_[(4) - (3)].p_Expression));
	(yyval.p_Expression) = new sql::HomologConstraint("UCASE", v.begin(), v.end());
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 936 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::RegexConstraint((yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression));
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 942 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 948 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
}
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 952 "lib/SQLParser/SQLParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    (yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
}
    break;



/* Line 678 of lalr1.cc  */
#line 1425 "lib/SQLParser/SQLParser.cpp"
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
  const short int SQLParser::yypact_ninf_ = -188;
  const short int
  SQLParser::yypact_[] =
  {
         1,    41,   -23,    18,  -188,   -15,  -188,  -188,  -188,   188,
     188,   188,     7,    20,    38,    39,   142,    63,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,    74,  -188,  -188,  -188,    78,    -6,  -188,
    -188,  -188,  -188,     0,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,    36,  -188,    52,  -188,
    -188,    86,  -188,  -188,  -188,   142,   142,   142,   142,    50,
     -33,  -188,    -4,    73,    64,    64,  -188,  -188,  -188,  -188,
     102,   103,    10,   142,   142,   142,   142,   142,   142,  -188,
    -188,     4,    -1,  -188,  -188,    82,  -188,  -188,   118,  -188,
    -188,    81,    83,    84,  -188,   118,     2,   120,  -188,    96,
      75,  -188,   111,   142,  -188,  -188,  -188,   142,  -188,   142,
    -188,   109,  -188,  -188,  -188,  -188,  -188,  -188,  -188,   142,
     142,  -188,  -188,  -188,   142,   142,  -188,    92,  -188,  -188,
      15,  -188,  -188,   142,    94,    36,  -188,  -188,  -188,   142,
    -188,  -188,    -2,    85,  -188,    87,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,   -31,  -188,   142,  -188,
      95,     3,  -188,  -188,  -188,   127,  -188,   128,  -188,  -188,
    -188,    97,    99,  -188,    35,  -188,  -188,    36,  -188,  -188,
     -33,   104,   104,    25,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,   132,    64,   101,  -188,  -188,   -31,  -188,   142,  -188,
    -188,  -188,    36,  -188,  -188,    27,   104,  -188,    64,  -188,
    -188,  -188
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  SQLParser::yydefact_[] =
  {
         0,     0,     0,     0,     7,     4,    28,    45,   119,     0,
       0,     0,     0,     0,     0,     0,     0,    56,   131,   134,
     137,   132,   135,   138,   133,   136,   139,   142,   143,   144,
     145,   140,   141,    35,    47,   118,    55,     0,    52,    75,
      78,    82,    84,    94,    96,   102,   107,   112,   113,   114,
     116,   128,   129,   130,   117,   115,     0,     1,     4,     5,
       2,    26,   110,   111,   109,     0,     0,     0,     0,     0,
       0,    36,    39,    44,     0,     0,    56,    53,    49,    51,
      76,    80,     0,     0,     0,     0,     0,     0,     0,    95,
      85,    97,   104,    57,     9,     5,     3,     8,     0,    29,
     126,     0,     0,     0,   120,     0,    73,    32,    66,     0,
       0,    40,    42,     0,    48,    54,    50,     0,    79,     0,
      83,     0,    92,    86,    87,    88,    89,    90,    91,     0,
       0,   103,   100,   101,     0,     0,   108,     0,     6,    27,
       0,   122,   123,     0,     0,     0,    72,    74,    68,     0,
      33,    34,    58,     0,    37,     0,    43,    30,    46,    77,
      81,    93,    98,    99,   105,   106,     0,   121,     0,   127,
       0,     0,    71,    31,    59,     0,    60,     0,    67,    38,
      41,     0,     0,    12,     0,   125,   124,     0,    69,    61,
       0,     0,     0,     0,    17,    18,    19,    20,    21,    14,
      70,    63,     0,     0,    16,    10,     0,    13,     0,    64,
      65,    24,     0,    11,    62,     0,     0,    22,     0,    25,
      15,    23
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SQLParser::yypgoto_[] =
  {
      -188,  -188,    89,  -188,  -188,    53,  -188,  -188,  -188,   -57,
    -188,  -187,  -188,  -188,    45,  -188,  -188,    55,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,    42,
    -188,  -188,  -188,   -37,   -53,  -188,  -188,  -188,  -188,  -188,
    -188,   -39,  -188,  -188,   -16,  -188,  -188,  -188,    37,  -188,
    -188,    43,  -188,  -188,  -188,    26,  -188,  -188,  -188,   -94,
    -188,  -188,   -90,    32,  -188,  -188,  -188,  -188,  -188,  -188,
      65,    66,  -188,  -188
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SQLParser::yydefgoto_[] =
  {
        -1,     3,    60,    97,    58,     4,   137,   207,   193,   183,
     199,   203,   219,   215,     5,    99,    61,     6,   150,   151,
      71,    72,   111,   112,   156,   157,    33,   114,    73,    34,
      77,    78,    35,    36,    37,   107,   177,   209,   210,   178,
     152,   108,   147,   148,    38,    39,   118,    80,    40,   120,
      81,    41,    42,    89,    90,    43,    44,   131,    91,    45,
     136,    92,    46,    47,    48,    49,   169,   140,    50,    51,
      52,    53,    54,    55
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char SQLParser::yytable_ninf_ = -58;
  const short int
  SQLParser::yytable_[] =
  {
        69,    79,    75,    94,     1,   204,   134,   105,   174,   175,
     145,   187,   181,   109,   110,   182,    56,   106,    57,    93,
      82,    76,    59,    83,    84,    85,    86,    87,    88,   220,
     135,   121,   122,   129,   130,   162,   163,   115,   116,     2,
     176,    62,    63,    64,   164,   165,    76,    65,     7,   100,
     101,   102,   103,   146,    93,    93,   167,   168,    19,    20,
      66,    22,    23,     8,    25,    26,   205,   206,   217,   218,
       9,    10,   -57,    11,    12,    13,    14,    15,    67,    68,
      70,    16,   194,   195,   196,   197,   198,    74,    93,    95,
      98,   104,   172,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,   123,
     124,   125,   126,   127,   128,   113,    76,   117,   188,   119,
       2,     1,   141,   153,   142,   149,   143,   170,   154,   184,
     155,   161,   166,   173,   200,   171,   186,   106,   179,   189,
     180,   191,   190,   192,   202,   208,   212,    96,   138,   213,
     144,   201,   185,   139,   159,   158,   132,   133,     0,   216,
       0,     0,   160,     0,     8,   211,     0,     0,     0,   184,
       0,     9,    10,     0,    11,    12,    13,    14,    15,     0,
       0,   221,    16,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   214,     0,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    12,    13,    14,    15,     0,     0,     0,    16,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32
  };

  /* YYCHECK.  */
  const short int
  SQLParser::yycheck_[] =
  {
        16,    38,     8,    56,     3,   192,     7,    40,    10,    11,
       8,     8,    43,    17,    18,    46,    39,    70,     0,    52,
      20,    52,    37,    23,    24,    25,    26,    27,    28,   216,
      31,    21,    22,    29,    30,   129,   130,    74,    75,    38,
      42,     9,    10,    11,   134,   135,    52,    40,     7,    65,
      66,    67,    68,   106,    52,    52,    41,    42,    54,    55,
      40,    57,    58,    22,    60,    61,    41,    42,    41,    42,
      29,    30,     9,    32,    33,    34,    35,    36,    40,    40,
       6,    40,    47,    48,    49,    50,    51,     9,    52,    37,
       4,    41,   145,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    83,
      84,    85,    86,    87,    88,    42,    52,    15,   171,    16,
      38,     3,    41,    27,    41,     5,    42,   143,    53,   166,
      19,    22,    40,   149,   187,    41,    41,   190,    53,    12,
      53,    44,    14,    44,    40,    13,    45,    58,    95,   206,
     105,   190,   168,    98,   117,   113,    91,    91,    -1,   212,
      -1,    -1,   119,    -1,    22,   202,    -1,    -1,    -1,   206,
      -1,    29,    30,    -1,    32,    33,    34,    35,    36,    -1,
      -1,   218,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   208,    -1,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    35,    36,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  SQLParser::yystos_[] =
  {
         0,     3,    38,    69,    73,    82,    85,     7,    22,    29,
      30,    32,    33,    34,    35,    36,    40,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    94,    97,   100,   101,   102,   112,   113,
     116,   119,   120,   123,   124,   127,   130,   131,   132,   133,
     136,   137,   138,   139,   140,   141,    39,     0,    72,    37,
      70,    84,   131,   131,   131,    40,    40,    40,    40,   112,
       6,    88,    89,    96,     9,     8,    52,    98,    99,   101,
     115,   118,    20,    23,    24,    25,    26,    27,    28,   121,
     122,   126,   129,    52,   102,    37,    70,    71,     4,    83,
     112,   112,   112,   112,    41,    40,   102,   103,   109,    17,
      18,    90,    91,    42,    95,   101,   101,    15,   114,    16,
     117,    21,    22,   123,   123,   123,   123,   123,   123,    29,
      30,   125,   138,   139,     7,    31,   128,    74,    73,    85,
     135,    41,    41,    42,    82,     8,   102,   110,   111,     5,
      86,    87,   108,    27,    53,    19,    92,    93,    97,   116,
     119,    22,   127,   127,   130,   130,    40,    41,    42,   134,
     112,    41,   102,   112,    10,    11,    42,   104,   107,    53,
      53,    43,    46,    77,   101,   112,    41,     8,   102,    12,
      14,    44,    44,    76,    47,    48,    49,    50,    51,    78,
     102,   109,    40,    79,    79,    41,    42,    75,    13,   105,
     106,   101,    45,    77,   112,    81,   102,    41,    42,    80,
      79,   101
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
     315,   316,   317,   318,   319,   320,   321,   322
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  SQLParser::yyr1_[] =
  {
         0,    68,    69,    69,    70,    70,    71,    72,    72,    74,
      73,    75,    76,    76,    77,    77,    77,    78,    78,    78,
      78,    78,    79,    80,    81,    81,    82,    83,    84,    84,
      85,    86,    87,    87,    88,    89,    89,    90,    90,    91,
      91,    92,    93,    93,    94,    94,    95,    96,    96,    97,
      98,    98,    99,    99,   100,   100,   101,   102,   103,   104,
     104,   104,   105,   106,   106,   107,   108,   108,   109,   109,
     109,   110,   110,   111,   111,   112,   113,   114,   115,   115,
     116,   117,   118,   118,   119,   120,   121,   121,   121,   121,
     121,   121,   121,   121,   122,   122,   123,   124,   125,   125,
     125,   125,   126,   126,   127,   128,   128,   129,   129,   130,
     130,   130,   130,   131,   131,   131,   131,   131,   131,   131,
     132,   133,   133,   133,   133,   134,   135,   135,   136,   136,
     136,   137,   137,   137,   138,   138,   138,   139,   139,   139,
     140,   140,   141,   141,   141,   141
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
       2,     1,     0,     1,     3,     1,     1,     1,     2,     1,
       1,     2,     2,     0,     1,     4,     0,     2,     2,     4,
       5,     2,     1,     0,     1,     1,     2,     2,     0,     2,
       2,     2,     0,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     3,     0,     1,     1,     2,     2,     2,
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
  "IT_REGEX", "GT_SEMI", "IT_CREATE", "IT_TABLE", "GT_LPAREN", "GT_RPAREN",
  "GT_COMMA", "IT_FOREIGN", "IT_KEY", "IT_REFERENCES", "IT_PRIMARY",
  "IT_INT", "IT_DOUBLE", "IT_DATE", "IT_DATETIME", "IT_STRING", "NAME",
  "INTEGER", "INTEGER_POSITIVE", "INTEGER_NEGATIVE", "DECIMAL",
  "DECIMAL_POSITIVE", "DECIMAL_NEGATIVE", "DOUBLE", "DOUBLE_POSITIVE",
  "DOUBLE_NEGATIVE", "STRING_LITERAL1", "STRING_LITERAL2",
  "STRING_LITERAL_LONG1", "STRING_LITERAL_LONG2", "IT_true", "IT_false",
  "$accept", "Statement", "_QGT_SEMI_E_Opt", "_O_QGT_SEMI_E_S_QCreate_E_C",
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
        69,     0,    -1,    82,    70,    -1,    73,    72,    70,    -1,
      -1,    37,    -1,    37,    73,    -1,    -1,    72,    71,    -1,
      -1,    38,    39,   102,    74,    40,    77,    76,    41,    -1,
      42,    77,    -1,    -1,    76,    75,    -1,   101,    78,    -1,
      43,    44,    79,    45,   102,    79,    -1,    46,    44,    79,
      -1,    47,    -1,    48,    -1,    49,    -1,    50,    -1,    51,
      -1,    40,   101,    81,    41,    -1,    42,   101,    -1,    -1,
      81,    80,    -1,    85,    84,    -1,     4,    85,    -1,    -1,
      84,    83,    -1,     3,    94,    89,    91,    93,    -1,     5,
     112,    -1,    -1,    86,    -1,     6,   103,    87,    -1,    -1,
      88,    -1,    18,    53,    -1,    17,    27,    53,    -1,    -1,
      90,    -1,    19,    53,    -1,    -1,    92,    -1,    97,    96,
      -1,     7,    -1,    42,    97,    -1,    -1,    96,    95,    -1,
     112,    99,    -1,     8,   101,    -1,   101,    -1,    -1,    98,
      -1,   102,     9,   101,    -1,   101,    -1,    52,    -1,    52,
      -1,   109,   108,    -1,    10,    -1,    42,    -1,    11,    12,
      -1,    13,   112,    -1,    -1,   105,    -1,   104,    14,   109,
     106,    -1,    -1,   108,   107,    -1,   102,   111,    -1,    40,
      82,    41,   102,    -1,    40,    82,    41,     8,   102,    -1,
       8,   102,    -1,   102,    -1,    -1,   110,    -1,   113,    -1,
     116,   115,    -1,    15,   116,    -1,    -1,   115,   114,    -1,
     119,   118,    -1,    16,   119,    -1,    -1,   118,   117,    -1,
     120,    -1,   123,   122,    -1,    23,   123,    -1,    24,   123,
      -1,    25,   123,    -1,    26,   123,    -1,    27,   123,    -1,
      28,   123,    -1,    20,    22,    -1,    20,    21,    22,    -1,
      -1,   121,    -1,   124,    -1,   127,   126,    -1,    29,   127,
      -1,    30,   127,    -1,   138,    -1,   139,    -1,    -1,   126,
     125,    -1,   130,   129,    -1,     7,   130,    -1,    31,   130,
      -1,    -1,   129,   128,    -1,    32,   131,    -1,    29,   131,
      -1,    30,   131,    -1,   131,    -1,   132,    -1,   133,    -1,
     141,    -1,   136,    -1,   140,    -1,   100,    -1,    22,    -1,
      40,   112,    41,    -1,    33,    40,   112,   135,    41,    -1,
      34,    40,   112,    41,    -1,    35,    40,   112,    41,    -1,
      36,    40,   112,    42,   112,    41,    -1,    42,   112,    -1,
      -1,   135,   134,    -1,   137,    -1,   138,    -1,   139,    -1,
      53,    -1,    56,    -1,    59,    -1,    54,    -1,    57,    -1,
      60,    -1,    55,    -1,    58,    -1,    61,    -1,    66,    -1,
      67,    -1,    62,    -1,    63,    -1,    64,    -1,    65,    -1
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
     133,   136,   138,   139,   141,   145,   147,   149,   151,   154,
     156,   158,   161,   164,   165,   167,   172,   173,   176,   179,
     184,   190,   193,   195,   196,   198,   200,   203,   206,   207,
     210,   213,   216,   217,   220,   222,   225,   228,   231,   234,
     237,   240,   243,   246,   250,   251,   253,   255,   258,   261,
     264,   266,   268,   269,   272,   275,   278,   281,   282,   285,
     288,   291,   294,   296,   298,   300,   302,   304,   306,   308,
     310,   314,   320,   325,   330,   337,   340,   341,   344,   346,
     348,   350,   352,   354,   356,   358,   360,   362,   364,   366,
     368,   370,   372,   374,   376,   378
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SQLParser::yyrline_[] =
  {
         0,   290,   290,   294,   297,   299,   303,   306,   308,   312,
     312,   322,   325,   327,   331,   337,   342,   348,   352,   356,
     360,   364,   370,   378,   384,   387,   395,   407,   413,   417,
     424,   441,   447,   451,   455,   464,   469,   473,   478,   486,
     490,   494,   502,   506,   510,   516,   522,   528,   531,   538,
     545,   548,   552,   555,   561,   566,   573,   577,   581,   594,
     598,   602,   608,   614,   618,   624,   637,   642,   651,   662,
     668,   677,   680,   684,   688,   694,   699,   711,   718,   721,
     729,   741,   748,   751,   758,   763,   782,   785,   788,   791,
     794,   797,   800,   803,   810,   814,   818,   823,   835,   838,
     841,   842,   847,   850,   858,   870,   873,   880,   883,   890,
     893,   896,   899,   903,   904,   905,   906,   907,   908,   909,
     915,   921,   926,   931,   936,   942,   948,   952,   959,   960,
     961,   965,   966,   967,   971,   972,   973,   977,   978,   979,
     983,   984,   988,   989,   990,   991
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
      65,    66,    67
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int SQLParser::yyeof_ = 0;
  const int SQLParser::yylast_ = 255;
  const int SQLParser::yynnts_ = 74;
  const int SQLParser::yyempty_ = -2;
  const int SQLParser::yyfinal_ = 57;
  const int SQLParser::yyterror_ = 1;
  const int SQLParser::yyerrcode_ = 256;
  const int SQLParser::yyntokens_ = 68;

  const unsigned int SQLParser::yyuser_token_number_max_ = 322;
  const SQLParser::token_number_type SQLParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 2121 "lib/SQLParser/SQLParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 996 "lib/SQLParser/SQLParser.ypp"
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
      context(_context), root(NULL)
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

