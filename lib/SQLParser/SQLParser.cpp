
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
#line 190 "lib/SQLParser/SQLParser.ypp"

#include "SQLScanner.hpp"

/* Line 317 of lalr1.cc  */
#line 252 "lib/SQLParser/SQLParser.ypp"

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
#line 268 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Selects)->size() > 0) {
	    sql::SQLUnion* u = new sql::SQLUnion();
	    u->disjoints.push_back((yysemantic_stack_[(2) - (1)].p_Select));
	    for (std::vector<sql::SQLQuery*>::const_iterator it = (yysemantic_stack_[(2) - (2)].p_Selects)->begin();
		 it != (yysemantic_stack_[(2) - (2)].p_Selects)->end(); ++it)
		u->disjoints.push_back(*it);
	    (yyval.p_Select) = driver.root = u;
	} else
	    (yyval.p_Select) = driver.root = (yysemantic_stack_[(2) - (1)].p_Select);
	delete (yysemantic_stack_[(2) - (2)].p_Selects);
}
    break;

  case 3:

/* Line 678 of lalr1.cc  */
#line 283 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Select) = (yysemantic_stack_[(2) - (2)].p_Select);
}
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 289 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Selects) = new std::vector<sql::SQLQuery*>();
}
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 293 "lib/SQLParser/SQLParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_Selects)->push_back((yysemantic_stack_[(2) - (2)].p_Select));
    (yyval.p_Selects) = (yysemantic_stack_[(2) - (1)].p_Selects);
}
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 300 "lib/SQLParser/SQLParser.ypp"
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

  case 7:

/* Line 678 of lalr1.cc  */
#line 317 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 323 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = NULL;
}
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 331 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TableList).joins = (yysemantic_stack_[(3) - (2)].p_TableList).joins;
	(yyval.p_TableList).exprs = (yysemantic_stack_[(3) - (2)].p_TableList).exprs;
	if ((yysemantic_stack_[(3) - (3)].p_Expression) != NULL)
	    (yyval.p_TableList).exprs->push_back((yysemantic_stack_[(3) - (3)].p_Expression));
}
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 340 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_TableList).joins = new std::vector<sql::Join*>();;
    (yyval.p_TableList).exprs = new std::vector<const sql::Expression*>();;
}
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 349 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 357 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_int) = -1;
}
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 365 "lib/SQLParser/SQLParser.ypp"
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_int) = i->getValue();
	delete (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 373 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_int) = -1;
}
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 381 "lib/SQLParser/SQLParser.ypp"
    {
	// no $2->push_front($1);
	(yyval.p_AttributeList) = new std::vector<sql::AliasedSelect*>();
	(yyval.p_AttributeList)->push_back((yysemantic_stack_[(2) - (1)].p_AliasedSelect));
	for (std::vector<sql::AliasedSelect*>::iterator it = (yysemantic_stack_[(2) - (2)].p_AttributeList)->begin();
	     it != (yysemantic_stack_[(2) - (2)].p_AttributeList)->end(); ++it)
	    (yyval.p_AttributeList)->push_back(*it);
	(yysemantic_stack_[(2) - (2)].p_AttributeList)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_AttributeList);
}
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 392 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AttributeList) = new std::vector<sql::AliasedSelect*>();
}
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 398 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AliasedSelect) = (yysemantic_stack_[(2) - (2)].p_AliasedSelect);
}
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 404 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AttributeList) = new std::vector<sql::AliasedSelect*>();
}
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 408 "lib/SQLParser/SQLParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_AttributeList)->push_back((yysemantic_stack_[(2) - (2)].p_AliasedSelect));
    (yyval.p_AttributeList) = (yysemantic_stack_[(2) - (1)].p_AttributeList);
}
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 415 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AliasedSelect) = new sql::AliasedSelect((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_NAME) ? *(yysemantic_stack_[(2) - (2)].p_NAME) : (yysemantic_stack_[(2) - (1)].p_Expression)->toString());
	delete (yysemantic_stack_[(2) - (2)].p_NAME);
}
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 422 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = (yysemantic_stack_[(2) - (2)].p_NAME);
}
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 428 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = NULL;
}
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 432 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = (yysemantic_stack_[(1) - (1)].p_NAME);
}
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 438 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::AliasAttrConstraint(sql::AliasAttr(*(yysemantic_stack_[(3) - (1)].p_NAME), *(yysemantic_stack_[(3) - (3)].p_NAME)));
	delete (yysemantic_stack_[(3) - (1)].p_NAME);
	delete (yysemantic_stack_[(3) - (3)].p_NAME);
}
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 454 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TableList).joins = new std::vector<sql::Join*>();
	(yyval.p_TableList).joins->push_back((yysemantic_stack_[(2) - (1)].p_tableAlias).relation != NULL
			    ? (sql::Join*)new sql::TableJoin(*(yysemantic_stack_[(2) - (1)].p_tableAlias).relation, *(yysemantic_stack_[(2) - (1)].p_tableAlias).alias, (yysemantic_stack_[(2) - (1)].p_tableAlias).optional)
			    : (sql::Join*)new sql::SubqueryJoin((yysemantic_stack_[(2) - (1)].p_tableAlias).subselect, *(yysemantic_stack_[(2) - (1)].p_tableAlias).alias, (yysemantic_stack_[(2) - (1)].p_tableAlias).optional));
	delete (yysemantic_stack_[(2) - (1)].p_tableAlias).relation;
	delete (yysemantic_stack_[(2) - (1)].p_tableAlias).alias;
	for (std::vector<sql::Join*>::iterator it = (yysemantic_stack_[(2) - (2)].p_TableList).joins->begin();
	     it != (yysemantic_stack_[(2) - (2)].p_TableList).joins->end(); ++it)
	    (yyval.p_TableList).joins->push_back(*it);
	(yyval.p_TableList).exprs = (yysemantic_stack_[(2) - (2)].p_TableList).exprs;
	delete (yysemantic_stack_[(2) - (2)].p_TableList).joins;
}
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 470 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_bool) = false;
}
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 474 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_bool) = false;
}
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 478 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_bool) = true;
}
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 484 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 490 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = NULL;
}
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 494 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(1) - (1)].p_Expression);
}
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 500 "lib/SQLParser/SQLParser.ypp"
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

  case 39:

/* Line 678 of lalr1.cc  */
#line 513 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TableList).joins = new std::vector<sql::Join*>();
	(yyval.p_TableList).exprs = new std::vector<const sql::Expression*>();
}
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 518 "lib/SQLParser/SQLParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_TableList).joins->push_back((yysemantic_stack_[(2) - (2)].p_JoinExpression).join);
    if ((yysemantic_stack_[(2) - (2)].p_JoinExpression).expr != NULL)
	(yysemantic_stack_[(2) - (1)].p_TableList).exprs->push_back((yysemantic_stack_[(2) - (2)].p_JoinExpression).expr);
    (yyval.p_TableList) = (yysemantic_stack_[(2) - (1)].p_TableList);
}
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 527 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_tableAlias).relation = (yysemantic_stack_[(2) - (1)].p_NAME);
	(yyval.p_tableAlias).subselect = NULL;
	(yyval.p_tableAlias).alias = (yysemantic_stack_[(2) - (2)].p_NAME) ? (yysemantic_stack_[(2) - (2)].p_NAME) : new std::string(*(yysemantic_stack_[(2) - (1)].p_NAME));
}
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 532 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_tableAlias).relation = NULL;
	(yyval.p_tableAlias).subselect = (yysemantic_stack_[(5) - (2)].p_Select);
	(yyval.p_tableAlias).alias = (yysemantic_stack_[(5) - (5)].p_NAME);
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 540 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = (yysemantic_stack_[(2) - (2)].p_NAME);
}
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 546 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = NULL;
}
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 550 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = (yysemantic_stack_[(1) - (1)].p_NAME);
}
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 561 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    sql::JunctionConstraint* t = new sql::DisjunctionConstraint();
	    t->constraints.push_back((yysemantic_stack_[(2) - (1)].p_Expression));
	    for (std::vector<const sql::Expression*>::const_iterator it = (yysemantic_stack_[(2) - (2)].p_Expressions)->begin();
		 it != (yysemantic_stack_[(2) - (2)].p_Expressions)->end(); ++it)
		t->constraints.push_back(*it);
	    (yyval.p_Expression) = t;
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 577 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 584 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 587 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 595 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    sql::JunctionConstraint* t = new sql::ConjunctionConstraint();
	    t->constraints.push_back((yysemantic_stack_[(2) - (1)].p_Expression));
	    for (std::vector<const sql::Expression*>::const_iterator it = (yysemantic_stack_[(2) - (2)].p_Expressions)->begin();
		 it != (yysemantic_stack_[(2) - (2)].p_Expressions)->end(); ++it)
		t->constraints.push_back(*it);
	    (yyval.p_Expression) = t;
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 611 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 618 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 621 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 633 "lib/SQLParser/SQLParser.ypp"
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

  case 57:

/* Line 678 of lalr1.cc  */
#line 650 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 653 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 656 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 659 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 662 "lib/SQLParser/SQLParser.ypp"
    {
        (yyval.p_BooleanComparator) = new sql::BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 665 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 668 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_BooleanComparator) = new sql::IsNullProxy;
}
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 671 "lib/SQLParser/SQLParser.ypp"
    {
      (yyval.p_BooleanComparator) = new sql::IsNotNullProxy;
}
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 678 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = NULL;
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 691 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    std::vector<const sql::Expression*> v;
	    v.push_back((yysemantic_stack_[(2) - (1)].p_Expression));
	    for (std::vector<const sql::Expression*>::const_iterator it = (yysemantic_stack_[(2) - (2)].p_Expressions)->begin();
		 it != (yysemantic_stack_[(2) - (2)].p_Expressions)->end(); ++it)
		v.push_back(*it);
	    (yyval.p_Expression) = new sql::ArithmeticSum(&v);
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 706 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 709 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 718 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 721 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 729 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0) {
	    std::vector<const sql::Expression*> v;
	    v.push_back((yysemantic_stack_[(2) - (1)].p_Expression));
	    for (std::vector<const sql::Expression*>::const_iterator it = (yysemantic_stack_[(2) - (2)].p_Expressions)->begin();
		 it != (yysemantic_stack_[(2) - (2)].p_Expressions)->end(); ++it)
		v.push_back(*it);
	    (yyval.p_Expression) = new sql::ArithmeticProduct(&v);
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 745 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 748 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 755 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 758 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 765 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 768 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 771 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 787 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
}
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 793 "lib/SQLParser/SQLParser.ypp"
    {
	std::vector<const sql::Expression*> args;
	args.push_back((yysemantic_stack_[(5) - (3)].p_Expression));
	for (std::vector<const sql::Expression*>::const_iterator it = (yysemantic_stack_[(5) - (4)].p_Expressions)->begin();
	     it != (yysemantic_stack_[(5) - (4)].p_Expressions)->end(); ++it)
	    args.push_back(*it);
	(yyval.p_Expression) = new sql::ConcatConstraint(&args);
	delete (yysemantic_stack_[(5) - (4)].p_Expressions);
}
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 804 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::RegexConstraint((yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression));
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 810 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 816 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
}
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 820 "lib/SQLParser/SQLParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    (yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
}
    break;



/* Line 678 of lalr1.cc  */
#line 1238 "lib/SQLParser/SQLParser.cpp"
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
  const signed char SQLParser::yypact_ninf_ = -64;
  const signed char
  SQLParser::yypact_[] =
  {
         2,    29,    33,   -64,   -64,   -29,   -29,   -29,    96,     9,
      27,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,    84,   -64,   -64,
      81,    83,   -64,   -64,   -64,   -64,    26,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
      89,   -64,   -64,   -64,    60,    96,    96,     6,   -64,    77,
      88,    61,    61,   -64,   -64,    85,    86,    10,    96,    96,
      96,    96,    96,    96,   -64,   -64,    -5,    -4,     2,   -64,
     -64,   -64,    92,     2,    93,    99,   -64,    67,   -64,    87,
      96,   -64,   -64,   -64,   -64,    96,   -64,    96,   -64,    90,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,    96,    96,   -64,
     -64,   -64,    96,    96,   -64,   -64,    -6,    96,    73,    71,
     -64,   -64,    96,   -64,   -64,    18,   -64,    72,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,    96,   -64,
     -64,    79,   102,   -64,   -64,   -64,   -64,   103,   100,   -64,
     -64,   -64,   -64,    71,   -64,     6,   -64,   104,    96,   -64,
     -64,   -64
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  SQLParser::yydefact_[] =
  {
         0,     0,     0,     4,    20,     0,     0,     0,     0,     0,
       0,    30,    99,   102,   105,   100,   103,   106,   101,   104,
     107,   110,   111,   112,   113,   108,   109,    11,    22,    89,
       0,    26,    46,    49,    53,    55,    65,    67,    73,    78,
      83,    84,    85,    87,    96,    97,    98,    88,    86,     1,
       2,    81,    82,    80,     0,     0,     0,     0,    12,    14,
      19,     0,     0,    27,    24,    47,    51,     0,     0,     0,
       0,     0,     0,     0,    66,    56,    68,    75,     0,     5,
      90,    94,     0,     0,    44,     8,    39,     0,    15,    17,
       0,    23,    29,    28,    25,     0,    50,     0,    54,     0,
      63,    57,    58,    59,    60,    61,    62,     0,     0,    74,
      71,    72,     0,     0,    79,     3,     0,     0,     0,     0,
      45,    41,     0,     9,    10,    31,    13,     0,    18,     6,
      21,    48,    52,    64,    69,    70,    76,    77,     0,    91,
      95,     0,     0,    43,     7,    33,    32,     0,     0,    40,
      16,    93,    92,     0,    34,     0,    42,    36,     0,    37,
      38,    35
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  SQLParser::yypgoto_[] =
  {
       -64,    34,   -64,   -64,    41,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,    30,   -64,   -64,   -64,
      59,   -56,   -64,   -64,   -64,   -64,   -64,   -64,   -33,   -64,
     -64,    -8,   -64,   -64,   -64,    28,   -64,   -64,    52,   -64,
     -64,   -64,    14,   -64,   -64,   -64,   -63,   -64,   -64,   -24,
      50,   -64,   -64,   -64,   -64,   -64,   -64,    48,    51,   -64,
     -64
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SQLParser::yydefgoto_[] =
  {
        -1,     2,    79,    50,     3,   123,   124,    58,    59,    88,
      89,   128,   129,    27,    91,    60,    28,    63,    64,    29,
      93,    30,    85,   148,   159,   160,   149,   125,    86,   120,
     121,    31,    32,    96,    65,    33,    98,    66,    34,    35,
      74,    75,    36,    37,   109,    76,    38,   114,    77,    39,
      40,    41,    42,   140,   116,    43,    44,    45,    46,    47,
      48
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char SQLParser::yytable_ninf_ = -1;
  const unsigned char
  SQLParser::yytable_[] =
  {
        54,    84,   138,   112,     8,     1,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,   107,   108,   145,   113,   139,   146,
     147,    99,   100,    49,    13,    14,     4,    16,    17,    83,
      19,    20,    55,    11,   134,   135,    67,    81,    82,    68,
      69,    70,    71,    72,    73,    51,    52,    53,     5,     6,
      56,     7,     8,   143,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,   101,   102,   103,   104,   105,   106,   136,   137,
      57,    61,    62,    78,    80,    87,    90,   156,    92,    84,
     117,    95,   119,    97,   122,   126,   127,   142,    11,   141,
     150,   153,   133,   152,   144,   155,   154,   118,   158,   115,
     130,    94,   157,   131,   110,     5,     6,   111,     7,     8,
     151,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,   132,
     161
  };

  /* YYCHECK.  */
  const unsigned char
  SQLParser::yycheck_[] =
  {
         8,    57,     8,     7,    33,     3,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    29,    30,     8,    31,    34,    11,
      12,    21,    22,     0,    39,    40,     7,    42,    43,    33,
      45,    46,    33,    37,   107,   108,    20,    55,    56,    23,
      24,    25,    26,    27,    28,     5,     6,     7,    29,    30,
      33,    32,    33,   119,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    68,    69,    70,    71,    72,    73,   112,   113,
       6,    10,     9,     4,    34,    18,     8,   153,    37,   155,
       8,    16,     9,    17,     5,    38,    19,    34,    37,   117,
      38,     9,    22,    34,   122,    15,    13,    83,    14,    78,
      90,    62,   155,    95,    76,    29,    30,    76,    32,    33,
     138,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    97,
     158
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  SQLParser::yystos_[] =
  {
         0,     3,    54,    57,     7,    29,    30,    32,    33,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    66,    69,    72,
      74,    84,    85,    88,    91,    92,    95,    96,    99,   102,
     103,   104,   105,   108,   109,   110,   111,   112,   113,     0,
      56,   103,   103,   103,    84,    33,    33,     6,    60,    61,
      68,    10,     9,    70,    71,    87,    90,    20,    23,    24,
      25,    26,    27,    28,    93,    94,    98,   101,     4,    55,
      34,    84,    84,    33,    74,    75,    81,    18,    62,    63,
       8,    67,    37,    73,    73,    16,    86,    17,    89,    21,
      22,    95,    95,    95,    95,    95,    95,    29,    30,    97,
     110,   111,     7,    31,   100,    57,   107,     8,    54,     9,
      82,    83,     5,    58,    59,    80,    38,    19,    64,    65,
      69,    88,    91,    22,    99,    99,   102,   102,     8,    34,
     106,    84,    34,    74,    84,     8,    11,    12,    76,    79,
      38,    84,    34,     9,    13,    15,    74,    81,    14,    77,
      78,    84
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
     305,   306,   307
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  SQLParser::yyr1_[] =
  {
         0,    53,    54,    55,    56,    56,    57,    58,    59,    59,
      60,    61,    61,    62,    63,    63,    64,    65,    65,    66,
      66,    67,    68,    68,    69,    70,    71,    71,    72,    73,
      74,    75,    76,    76,    76,    77,    78,    78,    79,    80,
      80,    81,    81,    82,    83,    83,    84,    85,    86,    87,
      87,    88,    89,    90,    90,    91,    92,    93,    93,    93,
      93,    93,    93,    93,    93,    94,    94,    95,    96,    97,
      97,    97,    97,    98,    98,    99,   100,   100,   101,   101,
     102,   102,   102,   102,   103,   103,   103,   103,   103,   103,
     104,   105,   105,   106,   107,   107,   108,   108,   108,   109,
     109,   109,   110,   110,   110,   111,   111,   111,   112,   112,
     113,   113,   113,   113
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  SQLParser::yyr2_[] =
  {
         0,     2,     2,     2,     0,     2,     5,     2,     0,     1,
       3,     0,     1,     2,     0,     1,     2,     0,     1,     2,
       1,     2,     0,     2,     2,     2,     0,     1,     3,     1,
       1,     2,     1,     1,     2,     2,     0,     1,     4,     0,
       2,     2,     5,     2,     0,     1,     1,     2,     2,     0,
       2,     2,     2,     0,     2,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     0,     1,     1,     2,     2,
       2,     1,     1,     0,     2,     2,     2,     2,     0,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     5,     6,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const SQLParser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "IT_SELECT", "IT_UNION",
  "IT_WHERE", "IT_FROM", "GT_TIMES", "GT_COMMA", "IT_AS", "GT_DOT",
  "IT_INNER", "IT_LEFT", "IT_OUTER", "IT_ON", "IT_JOIN", "IT_OR", "IT_AND",
  "IT_LIMIT", "IT_OFFSET", "IT_IS", "IT_NOT", "IT_NULL", "GT_EQUAL",
  "GT_NEQUAL", "GT_LT", "GT_GT", "GT_LE", "GT_GE", "GT_PLUS", "GT_MINUS",
  "GT_DIVIDE", "GT_NOT", "GT_LPAREN", "GT_RPAREN", "IT_CONCAT", "IT_REGEX",
  "NAME", "INTEGER", "INTEGER_POSITIVE", "INTEGER_NEGATIVE", "DECIMAL",
  "DECIMAL_POSITIVE", "DECIMAL_NEGATIVE", "DOUBLE", "DOUBLE_POSITIVE",
  "DOUBLE_NEGATIVE", "STRING_LITERAL1", "STRING_LITERAL2",
  "STRING_LITERAL_LONG1", "STRING_LITERAL_LONG2", "IT_true", "IT_false",
  "$accept", "SelectUnion", "_O_QIT_UNION_E_S_QSelect_E_C",
  "_Q_O_QIT_UNION_E_S_QSelect_E_C_E_Star", "Select",
  "_O_QIT_WHERE_E_S_QExpression_E_C",
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
  "RelationalExpression",
  "_O_QGT_EQUAL_E_S_QNumericExpression_E_Or_QGT_NEQUAL_E_S_QNumericExpression_E_Or_QGT_LT_E_S_QNumericExpression_E_Or_QGT_GT_E_S_QNumericExpression_E_Or_QGT_LE_E_S_QNumericExpression_E_Or_QGT_GE_E_S_QNumericExpression_E_Or_QIT_IS_E_S_QIT_NULL_E_Or_QIT_IS_E_S_QIT_NOT_E_S_QIT_NULL_E_C",
  "_Q_O_QGT_EQUAL_E_S_QNumericExpression_E_Or_QGT_NEQUAL_E_S_QNumericExpression_E_Or_QGT_LT_E_S_QNumericExpression_E_Or_QGT_GT_E_S_QNumericExpression_E_Or_QGT_LE_E_S_QNumericExpression_E_Or_QGT_GE_E_S_QNumericExpression_E_Or_QIT_IS_E_S_QIT_NULL_E_Or_QIT_IS_E_S_QIT_NOT_E_S_QIT_NULL_E_C_E_Opt",
  "NumericExpression", "AdditiveExpression",
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
        54,     0,    -1,    57,    56,    -1,     4,    57,    -1,    -1,
      56,    55,    -1,     3,    66,    61,    63,    65,    -1,     5,
      84,    -1,    -1,    58,    -1,     6,    75,    59,    -1,    -1,
      60,    -1,    18,    38,    -1,    -1,    62,    -1,    19,    38,
      -1,    -1,    64,    -1,    69,    68,    -1,     7,    -1,     8,
      69,    -1,    -1,    68,    67,    -1,    84,    71,    -1,     9,
      73,    -1,    -1,    70,    -1,    74,    10,    73,    -1,    37,
      -1,    37,    -1,    81,    80,    -1,    11,    -1,     8,    -1,
      12,    13,    -1,    14,    84,    -1,    -1,    77,    -1,    76,
      15,    81,    78,    -1,    -1,    80,    79,    -1,    74,    83,
      -1,    33,    54,    34,     9,    74,    -1,     9,    74,    -1,
      -1,    82,    -1,    85,    -1,    88,    87,    -1,    16,    88,
      -1,    -1,    87,    86,    -1,    91,    90,    -1,    17,    91,
      -1,    -1,    90,    89,    -1,    92,    -1,    95,    94,    -1,
      23,    95,    -1,    24,    95,    -1,    25,    95,    -1,    26,
      95,    -1,    27,    95,    -1,    28,    95,    -1,    20,    22,
      -1,    20,    21,    22,    -1,    -1,    93,    -1,    96,    -1,
      99,    98,    -1,    29,    99,    -1,    30,    99,    -1,   110,
      -1,   111,    -1,    -1,    98,    97,    -1,   102,   101,    -1,
       7,   102,    -1,    31,   102,    -1,    -1,   101,   100,    -1,
      32,   103,    -1,    29,   103,    -1,    30,   103,    -1,   103,
      -1,   104,    -1,   105,    -1,   113,    -1,   108,    -1,   112,
      -1,    72,    -1,    33,    84,    34,    -1,    35,    33,    84,
     107,    34,    -1,    36,    33,    84,     8,    84,    34,    -1,
       8,    84,    -1,    -1,   107,   106,    -1,   109,    -1,   110,
      -1,   111,    -1,    38,    -1,    41,    -1,    44,    -1,    39,
      -1,    42,    -1,    45,    -1,    40,    -1,    43,    -1,    46,
      -1,    51,    -1,    52,    -1,    47,    -1,    48,    -1,    49,
      -1,    50,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  SQLParser::yyprhs_[] =
  {
         0,     0,     3,     6,     9,    10,    13,    19,    22,    23,
      25,    29,    30,    32,    35,    36,    38,    41,    42,    44,
      47,    49,    52,    53,    56,    59,    62,    63,    65,    69,
      71,    73,    76,    78,    80,    83,    86,    87,    89,    94,
      95,    98,   101,   107,   110,   111,   113,   115,   118,   121,
     122,   125,   128,   131,   132,   135,   137,   140,   143,   146,
     149,   152,   155,   158,   161,   165,   166,   168,   170,   173,
     176,   179,   181,   183,   184,   187,   190,   193,   196,   197,
     200,   203,   206,   209,   211,   213,   215,   217,   219,   221,
     223,   227,   233,   240,   243,   244,   247,   249,   251,   253,
     255,   257,   259,   261,   263,   265,   267,   269,   271,   273,
     275,   277,   279,   281
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SQLParser::yyrline_[] =
  {
         0,   268,   268,   283,   289,   293,   300,   317,   323,   327,
     331,   340,   345,   349,   357,   361,   365,   373,   377,   381,
     392,   398,   404,   408,   415,   422,   428,   432,   438,   446,
     450,   454,   470,   474,   478,   484,   490,   494,   500,   513,
     518,   527,   532,   540,   546,   550,   556,   561,   577,   584,
     587,   595,   611,   618,   621,   628,   633,   650,   653,   656,
     659,   662,   665,   668,   671,   678,   682,   686,   691,   706,
     709,   712,   713,   718,   721,   729,   745,   748,   755,   758,
     765,   768,   771,   774,   778,   779,   780,   781,   782,   783,
     787,   793,   804,   810,   816,   820,   827,   828,   829,   833,
     834,   835,   839,   840,   841,   845,   846,   847,   851,   852,
     856,   857,   858,   859
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
      45,    46,    47,    48,    49,    50,    51,    52
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int SQLParser::yyeof_ = 0;
  const int SQLParser::yylast_ = 150;
  const int SQLParser::yynnts_ = 61;
  const int SQLParser::yyempty_ = -2;
  const int SQLParser::yyfinal_ = 49;
  const int SQLParser::yyterror_ = 1;
  const int SQLParser::yyerrcode_ = 256;
  const int SQLParser::yyntokens_ = 53;

  const unsigned int SQLParser::yyuser_token_number_max_ = 307;
  const SQLParser::token_number_type SQLParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 1862 "lib/SQLParser/SQLParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 864 "lib/SQLParser/SQLParser.ypp"
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

