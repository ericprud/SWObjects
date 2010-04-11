
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
#line 168 "lib/SQLParser/SQLParser.ypp"

#include "SQLScanner.hpp"

/* Line 317 of lalr1.cc  */
#line 228 "lib/SQLParser/SQLParser.ypp"

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
#line 31 "lib/SQLParser/SQLParser.ypp"
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
#line 244 "lib/SQLParser/SQLParser.ypp"
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
#line 259 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Select) = (yysemantic_stack_[(2) - (2)].p_Select);
}
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 265 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Selects) = new std::vector<sql::SQLQuery*>();
}
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 269 "lib/SQLParser/SQLParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_Selects)->push_back((yysemantic_stack_[(2) - (2)].p_Select));
    (yyval.p_Selects) = (yysemantic_stack_[(2) - (1)].p_Selects);
}
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 276 "lib/SQLParser/SQLParser.ypp"
    {
	driver.root = (yyval.p_Select) = new sql::SQLQuery((yysemantic_stack_[(3) - (3)].p_TableList).joins);
	delete (yysemantic_stack_[(3) - (3)].p_TableList).joins;
	for (std::vector<sql::AliasedSelect*>::const_iterator it = (yysemantic_stack_[(3) - (2)].p_AttributeList)->begin(); it != (yysemantic_stack_[(3) - (2)].p_AttributeList)->end(); ++it)
	    driver.root->selects.push_back(*it);
	delete (yysemantic_stack_[(3) - (2)].p_AttributeList);
	for (std::vector<const w3c_sw::sql::Expression*>::const_iterator it = (yysemantic_stack_[(3) - (3)].p_TableList).exprs->begin();
	     it != (yysemantic_stack_[(3) - (3)].p_TableList).exprs->end(); ++it)
	    driver.root->constraints.push_back(*it);
	    // LINE << "exprs: " << (*it)->toString();
	delete (yysemantic_stack_[(3) - (3)].p_TableList).exprs;
}
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 291 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 297 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = NULL;
}
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 305 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TableList).joins = (yysemantic_stack_[(3) - (2)].p_TableList).joins;
	(yyval.p_TableList).exprs = (yysemantic_stack_[(3) - (2)].p_TableList).exprs;
	if ((yysemantic_stack_[(3) - (3)].p_Expression) != NULL)
	    (yyval.p_TableList).exprs->push_back((yysemantic_stack_[(3) - (3)].p_Expression));
}
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 314 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_TableList).joins = new std::vector<sql::Join*>();;
    (yyval.p_TableList).exprs = new std::vector<const sql::Expression*>();;
}
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 323 "lib/SQLParser/SQLParser.ypp"
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

  case 14:

/* Line 678 of lalr1.cc  */
#line 334 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AttributeList) = new std::vector<sql::AliasedSelect*>();
}
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 340 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AliasedSelect) = (yysemantic_stack_[(2) - (2)].p_AliasedSelect);
}
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 346 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AttributeList) = new std::vector<sql::AliasedSelect*>();
}
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 350 "lib/SQLParser/SQLParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_AttributeList)->push_back((yysemantic_stack_[(2) - (2)].p_AliasedSelect));
    (yyval.p_AttributeList) = (yysemantic_stack_[(2) - (1)].p_AttributeList);
}
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 357 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_AliasedSelect) = new sql::AliasedSelect((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_NAME) ? *(yysemantic_stack_[(2) - (2)].p_NAME) : (yysemantic_stack_[(2) - (1)].p_Expression)->toString());
	delete (yysemantic_stack_[(2) - (2)].p_NAME);
}
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 364 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = (yysemantic_stack_[(2) - (2)].p_NAME);
}
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 370 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = NULL;
}
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 374 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = (yysemantic_stack_[(1) - (1)].p_NAME);
}
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 380 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::AliasAttrConstraint(sql::AliasAttr(*(yysemantic_stack_[(3) - (1)].p_NAME), *(yysemantic_stack_[(3) - (3)].p_NAME)));
	delete (yysemantic_stack_[(3) - (1)].p_NAME);
	delete (yysemantic_stack_[(3) - (3)].p_NAME);
}
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 396 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TableList).joins = new std::vector<sql::Join*>();
	(yyval.p_TableList).joins->push_back((yysemantic_stack_[(2) - (1)].p_tableAlias).relation != NULL
			    ? (sql::Join*)new sql::TableJoin(*(yysemantic_stack_[(2) - (1)].p_tableAlias).relation, *(yysemantic_stack_[(2) - (1)].p_tableAlias).alias, false)
			    : (sql::Join*)new sql::SubqueryJoin((yysemantic_stack_[(2) - (1)].p_tableAlias).subselect, *(yysemantic_stack_[(2) - (1)].p_tableAlias).alias, false));
	delete (yysemantic_stack_[(2) - (1)].p_tableAlias).relation;
	delete (yysemantic_stack_[(2) - (1)].p_tableAlias).alias;
	for (std::vector<sql::Join*>::iterator it = (yysemantic_stack_[(2) - (2)].p_TableList).joins->begin();
	     it != (yysemantic_stack_[(2) - (2)].p_TableList).joins->end(); ++it)
	    (yyval.p_TableList).joins->push_back(*it);
	(yyval.p_TableList).exprs = (yysemantic_stack_[(2) - (2)].p_TableList).exprs;
	delete (yysemantic_stack_[(2) - (2)].p_TableList).joins;
}
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 412 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 418 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = NULL;
}
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 422 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(1) - (1)].p_Expression);
}
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 428 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(4) - (3)].p_tableAlias).relation != NULL) {
	    (yyval.p_JoinExpression).join = new sql::TableJoin(*(yysemantic_stack_[(4) - (3)].p_tableAlias).relation, *(yysemantic_stack_[(4) - (3)].p_tableAlias).alias, false);
	    delete (yysemantic_stack_[(4) - (3)].p_tableAlias).relation;
	} else {
	    (yyval.p_JoinExpression).join = new sql::SubqueryJoin((yysemantic_stack_[(4) - (3)].p_tableAlias).subselect, *(yysemantic_stack_[(4) - (3)].p_tableAlias).alias, false);
	}
	delete (yysemantic_stack_[(4) - (3)].p_tableAlias).alias;
	(yyval.p_JoinExpression).expr = (yysemantic_stack_[(4) - (4)].p_Expression);
}
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 441 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_TableList).joins = new std::vector<sql::Join*>();
	(yyval.p_TableList).exprs = new std::vector<const sql::Expression*>();
}
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 446 "lib/SQLParser/SQLParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_TableList).joins->push_back((yysemantic_stack_[(2) - (2)].p_JoinExpression).join);
    if ((yysemantic_stack_[(2) - (2)].p_JoinExpression).expr != NULL)
	(yysemantic_stack_[(2) - (1)].p_TableList).exprs->push_back((yysemantic_stack_[(2) - (2)].p_JoinExpression).expr);
    (yyval.p_TableList) = (yysemantic_stack_[(2) - (1)].p_TableList);
}
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 455 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_tableAlias).relation = (yysemantic_stack_[(2) - (1)].p_NAME);
	(yyval.p_tableAlias).subselect = NULL;
	(yyval.p_tableAlias).alias = (yysemantic_stack_[(2) - (2)].p_NAME) ? (yysemantic_stack_[(2) - (2)].p_NAME) : new std::string(*(yysemantic_stack_[(2) - (1)].p_NAME));
}
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 460 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_tableAlias).relation = NULL;
	(yyval.p_tableAlias).subselect = (yysemantic_stack_[(5) - (2)].p_Select);
	(yyval.p_tableAlias).alias = (yysemantic_stack_[(5) - (5)].p_NAME);
    }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 468 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = (yysemantic_stack_[(2) - (2)].p_NAME);
}
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 474 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = NULL;
}
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 478 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_NAME) = (yysemantic_stack_[(1) - (1)].p_NAME);
}
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 489 "lib/SQLParser/SQLParser.ypp"
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

  case 39:

/* Line 678 of lalr1.cc  */
#line 505 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 512 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 515 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 523 "lib/SQLParser/SQLParser.ypp"
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

  case 43:

/* Line 678 of lalr1.cc  */
#line 539 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 546 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 549 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 561 "lib/SQLParser/SQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_BooleanComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_BooleanComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_BooleanComparator); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 572 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 575 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 578 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 581 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 584 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_BooleanComparator) = new sql::BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 587 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = new sql::BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 594 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_BooleanComparator) = NULL;
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 607 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0
	    ? NULL // !!! new sql::ArithmeticSum($1, $2)
	    : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 618 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 621 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = NULL; // !! new sql::ArithmeticNegation($2);
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 624 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = NULL; // !! new sql::NumberExpression($1);
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 627 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = NULL; // !! new sql::NumberExpression($1);
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 634 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 637 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 645 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? NULL : (yysemantic_stack_[(2) - (1)].p_Expression); // !!! new sql::ArithmeticProduct($1, $2) : $1;
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 654 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 657 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = NULL; // !! new sql::ArithmeticInverse($2);
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 664 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 667 "lib/SQLParser/SQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 674 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = NULL; // !! new sql::BooleanNegation($2);
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 677 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 680 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = NULL; // !! new sql::ArithmeticNegation($2);
    }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 696 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
}
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 702 "lib/SQLParser/SQLParser.ypp"
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

  case 81:

/* Line 678 of lalr1.cc  */
#line 713 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expression) = new sql::RegexConstraint((yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression));
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 719 "lib/SQLParser/SQLParser.ypp"
    {
    (yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
}
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 725 "lib/SQLParser/SQLParser.ypp"
    {
	(yyval.p_Expressions) = new std::vector<const sql::Expression*>();
}
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 729 "lib/SQLParser/SQLParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    (yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
}
    break;



/* Line 678 of lalr1.cc  */
#line 1152 "lib/SQLParser/SQLParser.cpp"
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
  const signed char SQLParser::yypact_ninf_ = -62;
  const signed char
  SQLParser::yypact_[] =
  {
        13,    -5,    51,   -62,   -62,   107,   107,   107,    30,    28,
      53,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,    74,   -62,   -62,
      75,    72,   -62,   -62,   -62,   -62,   -13,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
      80,   -62,   -62,   -62,    61,    30,    30,   -11,   -62,   -62,
      83,    64,    64,   -62,   -62,    82,    84,    30,    30,    30,
      30,    30,    30,   -62,   -62,    54,    71,    13,   -62,   -62,
     -62,    89,    13,    91,    93,   -62,    30,   -62,   -62,   -62,
     -62,    30,   -62,    30,   -62,   -62,   -62,   -62,   -62,   -62,
     -62,    30,    30,   -62,   -62,   -62,    30,    30,   -62,   -62,
      14,    30,    77,    76,   -62,   -62,    30,   -62,   -62,    90,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,    30,   -62,   -62,
      78,    98,   -62,   -62,    97,   -62,   -62,   -62,    76,   -11,
     -62,    99,    30,   -62,   -62,   -62
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  SQLParser::yydefact_[] =
  {
         0,     0,     0,     4,    14,     0,     0,     0,     0,     0,
       0,    24,    88,    91,    94,    89,    92,    95,    90,    93,
      96,    99,   100,   101,   102,    97,    98,    11,    16,    78,
       0,    20,    37,    40,    44,    46,    54,    56,    62,    67,
      72,    73,    74,    76,    85,    86,    87,    77,    75,     1,
       2,    70,    71,    69,     0,     0,     0,     0,    12,     6,
      13,     0,     0,    21,    18,    38,    42,     0,     0,     0,
       0,     0,     0,    55,    47,    57,    64,     0,     5,    79,
      83,     0,     0,    35,     8,    30,     0,    17,    23,    22,
      19,     0,    41,     0,    45,    48,    49,    50,    51,    52,
      53,     0,     0,    63,    60,    61,     0,     0,    68,     3,
       0,     0,     0,     0,    36,    32,     0,     9,    10,    25,
      15,    39,    43,    58,    59,    65,    66,     0,    80,    84,
       0,     0,    34,     7,     0,    31,    82,    81,     0,     0,
      33,    27,     0,    28,    29,    26
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  SQLParser::yypgoto_[] =
  {
       -62,    20,   -62,   -62,    33,   -62,   -62,   -62,   -62,   -62,
     -62,   -62,    25,   -62,   -62,   -62,    52,   -56,   -62,   -62,
     -62,   -62,   -62,   -26,   -62,   -62,    -8,   -62,   -62,   -62,
      24,   -62,   -62,    23,   -62,   -62,   -62,   -58,   -62,   -62,
     -62,   -52,   -62,   -62,   -61,    37,   -62,   -62,   -62,   -62,
     -62,   -62,    42,    43,   -62,   -62
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SQLParser::yydefgoto_[] =
  {
        -1,     2,    78,    50,     3,   117,   118,    58,    59,    27,
      87,    60,    28,    63,    64,    29,    89,    30,    84,   143,
     144,   135,   119,    85,   114,   115,    31,    32,    92,    65,
      33,    94,    66,    34,    35,    73,    74,    36,    37,   103,
      75,    38,   108,    76,    39,    40,    41,    42,   129,   110,
      43,    44,    45,    46,    47,    48
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char SQLParser::yytable_ninf_ = -1;
  const unsigned char
  SQLParser::yytable_[] =
  {
        54,    83,     4,    67,    68,    69,    70,    71,    72,    95,
      96,    97,    98,    99,   100,    82,     1,     5,     6,    11,
       7,     8,   127,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   128,    51,    52,    53,   125,   126,    80,    81,   123,
     124,    49,     5,     6,    55,     7,     8,   132,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,   101,   102,   106,    56,
      57,    62,   140,    83,    77,    61,    13,    14,    79,    16,
      17,    86,    19,    20,    88,   107,    91,   111,   116,    93,
     113,   134,   112,   130,   131,   137,    11,   138,   133,   139,
     109,   120,   142,   141,    90,   121,   122,   104,   105,   136,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     8,   145,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26
  };

  /* YYCHECK.  */
  const short int
  SQLParser::yycheck_[] =
  {
         8,    57,     7,    16,    17,    18,    19,    20,    21,    67,
      68,    69,    70,    71,    72,    26,     3,    22,    23,    30,
      25,    26,     8,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    27,     5,     6,     7,   106,   107,    55,    56,   101,
     102,     0,    22,    23,    26,    25,    26,   113,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    22,    23,     7,    26,
       6,     9,   138,   139,     4,    10,    32,    33,    27,    35,
      36,     8,    38,    39,    30,    24,    14,     8,     5,    15,
       9,    11,    82,   111,    27,    27,    30,     9,   116,    12,
      77,    86,    13,   139,    62,    91,    93,    75,    75,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,   142,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  SQLParser::yystos_[] =
  {
         0,     3,    47,    50,     7,    22,    23,    25,    26,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    55,    58,    61,
      63,    72,    73,    76,    79,    80,    83,    84,    87,    90,
      91,    92,    93,    96,    97,    98,    99,   100,   101,     0,
      49,    91,    91,    91,    72,    26,    26,     6,    53,    54,
      57,    10,     9,    59,    60,    75,    78,    16,    17,    18,
      19,    20,    21,    81,    82,    86,    89,     4,    48,    27,
      72,    72,    26,    63,    64,    69,     8,    56,    30,    62,
      62,    14,    74,    15,    77,    83,    83,    83,    83,    83,
      83,    22,    23,    85,    98,    99,     7,    24,    88,    50,
      95,     8,    47,     9,    70,    71,     5,    51,    52,    68,
      58,    76,    79,    87,    87,    90,    90,     8,    27,    94,
      72,    27,    63,    72,    11,    67,    72,    27,     9,    12,
      63,    69,    13,    65,    66,    72
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
     295,   296,   297,   298,   299,   300
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  SQLParser::yyr1_[] =
  {
         0,    46,    47,    48,    49,    49,    50,    51,    52,    52,
      53,    54,    54,    55,    55,    56,    57,    57,    58,    59,
      60,    60,    61,    62,    63,    64,    65,    66,    66,    67,
      68,    68,    69,    69,    70,    71,    71,    72,    73,    74,
      75,    75,    76,    77,    78,    78,    79,    80,    81,    81,
      81,    81,    81,    81,    82,    82,    83,    84,    85,    85,
      85,    85,    86,    86,    87,    88,    88,    89,    89,    90,
      90,    90,    90,    91,    91,    91,    91,    91,    91,    92,
      93,    93,    94,    95,    95,    96,    96,    96,    97,    97,
      97,    98,    98,    98,    99,    99,    99,   100,   100,   101,
     101,   101,   101
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  SQLParser::yyr2_[] =
  {
         0,     2,     2,     2,     0,     2,     3,     2,     0,     1,
       3,     0,     1,     2,     1,     2,     0,     2,     2,     2,
       0,     1,     3,     1,     1,     2,     2,     0,     1,     4,
       0,     2,     2,     5,     2,     0,     1,     1,     2,     2,
       0,     2,     2,     2,     0,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     0,     1,     1,     2,     2,     2,
       1,     1,     0,     2,     2,     2,     2,     0,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     3,
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
  "IT_WHERE", "IT_FROM", "GT_TIMES", "GT_COMMA", "IT_AS", "GT_DOT",
  "IT_INNER", "IT_JOIN", "IT_ON", "GT_OR", "GT_AND", "GT_EQUAL",
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
  "AttributeList", "_O_QGT_COMMA_E_S_QNamedAttribute_E_C",
  "_Q_O_QGT_COMMA_E_S_QNamedAttribute_E_C_E_Star", "NamedAttribute",
  "_O_QIT_AS_E_S_QAttribute_E_C", "_Q_O_QIT_AS_E_S_QAttribute_E_C_E_Opt",
  "FQAttribute", "Attribute", "Relation", "TableList",
  "_O_QIT_ON_E_S_QExpression_E_C", "_Q_O_QIT_ON_E_S_QExpression_E_C_E_Opt",
  "_O_QIT_INNER_E_S_QIT_JOIN_E_S_QTableAlias_E_S_QIT_ON_E_S_QExpression_E_Opt_C",
  "_Q_O_QIT_INNER_E_S_QIT_JOIN_E_S_QTableAlias_E_S_QIT_ON_E_S_QExpression_E_Opt_C_E_Star",
  "TableAlias", "_O_QIT_AS_E_S_QRelation_E_C",
  "_Q_O_QIT_AS_E_S_QRelation_E_C_E_Opt", "Expression",
  "ConditionalOrExpression", "_O_QGT_OR_E_S_QConditionalAndExpression_E_C",
  "_Q_O_QGT_OR_E_S_QConditionalAndExpression_E_C_E_Star",
  "ConditionalAndExpression", "_O_QGT_AND_E_S_QValueLogical_E_C",
  "_Q_O_QGT_AND_E_S_QValueLogical_E_C_E_Star", "ValueLogical",
  "RelationalExpression",
  "_O_QGT_EQUAL_E_S_QNumericExpression_E_Or_QGT_NEQUAL_E_S_QNumericExpression_E_Or_QGT_LT_E_S_QNumericExpression_E_Or_QGT_GT_E_S_QNumericExpression_E_Or_QGT_LE_E_S_QNumericExpression_E_Or_QGT_GE_E_S_QNumericExpression_E_C",
  "_Q_O_QGT_EQUAL_E_S_QNumericExpression_E_Or_QGT_NEQUAL_E_S_QNumericExpression_E_Or_QGT_LT_E_S_QNumericExpression_E_Or_QGT_GT_E_S_QNumericExpression_E_Or_QGT_LE_E_S_QNumericExpression_E_Or_QGT_GE_E_S_QNumericExpression_E_C_E_Opt",
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
        47,     0,    -1,    50,    49,    -1,     4,    50,    -1,    -1,
      49,    48,    -1,     3,    55,    54,    -1,     5,    72,    -1,
      -1,    51,    -1,     6,    64,    52,    -1,    -1,    53,    -1,
      58,    57,    -1,     7,    -1,     8,    58,    -1,    -1,    57,
      56,    -1,    72,    60,    -1,     9,    62,    -1,    -1,    59,
      -1,    63,    10,    62,    -1,    30,    -1,    30,    -1,    69,
      68,    -1,    13,    72,    -1,    -1,    65,    -1,    11,    12,
      69,    66,    -1,    -1,    68,    67,    -1,    63,    71,    -1,
      26,    47,    27,     9,    63,    -1,     9,    63,    -1,    -1,
      70,    -1,    73,    -1,    76,    75,    -1,    14,    76,    -1,
      -1,    75,    74,    -1,    79,    78,    -1,    15,    79,    -1,
      -1,    78,    77,    -1,    80,    -1,    83,    82,    -1,    16,
      83,    -1,    17,    83,    -1,    18,    83,    -1,    19,    83,
      -1,    20,    83,    -1,    21,    83,    -1,    -1,    81,    -1,
      84,    -1,    87,    86,    -1,    22,    87,    -1,    23,    87,
      -1,    98,    -1,    99,    -1,    -1,    86,    85,    -1,    90,
      89,    -1,     7,    90,    -1,    24,    90,    -1,    -1,    89,
      88,    -1,    25,    91,    -1,    22,    91,    -1,    23,    91,
      -1,    91,    -1,    92,    -1,    93,    -1,   101,    -1,    96,
      -1,   100,    -1,    61,    -1,    26,    72,    27,    -1,    28,
      26,    72,    95,    27,    -1,    29,    26,    72,     8,    72,
      27,    -1,     8,    72,    -1,    -1,    95,    94,    -1,    97,
      -1,    98,    -1,    99,    -1,    31,    -1,    34,    -1,    37,
      -1,    32,    -1,    35,    -1,    38,    -1,    33,    -1,    36,
      -1,    39,    -1,    44,    -1,    45,    -1,    40,    -1,    41,
      -1,    42,    -1,    43,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  SQLParser::yyprhs_[] =
  {
         0,     0,     3,     6,     9,    10,    13,    17,    20,    21,
      23,    27,    28,    30,    33,    35,    38,    39,    42,    45,
      48,    49,    51,    55,    57,    59,    62,    65,    66,    68,
      73,    74,    77,    80,    86,    89,    90,    92,    94,    97,
     100,   101,   104,   107,   110,   111,   114,   116,   119,   122,
     125,   128,   131,   134,   137,   138,   140,   142,   145,   148,
     151,   153,   155,   156,   159,   162,   165,   168,   169,   172,
     175,   178,   181,   183,   185,   187,   189,   191,   193,   195,
     199,   205,   212,   215,   216,   219,   221,   223,   225,   227,
     229,   231,   233,   235,   237,   239,   241,   243,   245,   247,
     249,   251,   253
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SQLParser::yyrline_[] =
  {
         0,   244,   244,   259,   265,   269,   276,   291,   297,   301,
     305,   314,   319,   323,   334,   340,   346,   350,   357,   364,
     370,   374,   380,   388,   392,   396,   412,   418,   422,   428,
     441,   446,   455,   460,   468,   474,   478,   484,   489,   505,
     512,   515,   523,   539,   546,   549,   556,   561,   572,   575,
     578,   581,   584,   587,   594,   598,   602,   607,   618,   621,
     624,   627,   634,   637,   645,   654,   657,   664,   667,   674,
     677,   680,   683,   687,   688,   689,   690,   691,   692,   696,
     702,   713,   719,   725,   729,   736,   737,   738,   742,   743,
     744,   748,   749,   750,   754,   755,   756,   760,   761,   765,
     766,   767,   768
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
      45
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int SQLParser::yyeof_ = 0;
  const int SQLParser::yylast_ = 152;
  const int SQLParser::yynnts_ = 56;
  const int SQLParser::yyempty_ = -2;
  const int SQLParser::yyfinal_ = 49;
  const int SQLParser::yyterror_ = 1;
  const int SQLParser::yyerrcode_ = 256;
  const int SQLParser::yyntokens_ = 46;

  const unsigned int SQLParser::yyuser_token_number_max_ = 300;
  const SQLParser::token_number_type SQLParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 1755 "lib/SQLParser/SQLParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 773 "lib/SQLParser/SQLParser.ypp"
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

