// A Bison parser, made by GNU Bison 3.0.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2013 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Take the name prefix into account.
#define yylex   w3c_swlex

// First part of user declarations.

#line 39 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:399

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "SPARQLalgebraParser.hpp"

// User implementation prologue.
#line 260 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:407

#include "SPARQLalgebraScanner.hpp"
#line 318 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:407

#include <stdarg.h>
#include "SPARQLalgebraScanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex

#line 66 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:407


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyempty = true)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace w3c_sw {
#line 152 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:474

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  SPARQLalgebraParser::yytnamerr_ (const char *yystr)
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
              // Fall through.
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


  /// Build a parser object.
  SPARQLalgebraParser::SPARQLalgebraParser (class SPARQLalgebraDriver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

  SPARQLalgebraParser::~SPARQLalgebraParser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  SPARQLalgebraParser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  SPARQLalgebraParser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  SPARQLalgebraParser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    value = other.value;
  }


  template <typename Base>
  inline
  SPARQLalgebraParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  SPARQLalgebraParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  inline
  SPARQLalgebraParser::basic_symbol<Base>::~basic_symbol ()
  {
  }

  template <typename Base>
  inline
  void
  SPARQLalgebraParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  inline
  SPARQLalgebraParser::by_type::by_type ()
     : type (empty)
  {}

  inline
  SPARQLalgebraParser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  SPARQLalgebraParser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  SPARQLalgebraParser::by_type::move (by_type& that)
  {
    type = that.type;
    that.type = empty;
  }

  inline
  int
  SPARQLalgebraParser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  SPARQLalgebraParser::by_state::by_state ()
    : state (empty)
  {}

  inline
  SPARQLalgebraParser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  SPARQLalgebraParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
  SPARQLalgebraParser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  SPARQLalgebraParser::symbol_number_type
  SPARQLalgebraParser::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
  SPARQLalgebraParser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  SPARQLalgebraParser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    value = that.value;
    // that is emptied.
    that.type = empty;
  }

  inline
  SPARQLalgebraParser::stack_symbol_type&
  SPARQLalgebraParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  SPARQLalgebraParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  SPARQLalgebraParser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  SPARQLalgebraParser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  SPARQLalgebraParser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  SPARQLalgebraParser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  SPARQLalgebraParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  SPARQLalgebraParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  SPARQLalgebraParser::debug_level_type
  SPARQLalgebraParser::debug_level () const
  {
    return yydebug_;
  }

  void
  SPARQLalgebraParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline SPARQLalgebraParser::state_type
  SPARQLalgebraParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  SPARQLalgebraParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  SPARQLalgebraParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  SPARQLalgebraParser::parse ()
  {
    /// Whether yyla contains a lookahead.
    bool yyempty = true;

    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    // User initialization code.
    #line 37 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:725
{
    // initialize the initial location object
    yyla.location.begin.filename = yyla.location.end.filename = &driver.streamname;
    driver.yylloc = &yyla.location;
}

#line 497 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:725

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyempty)
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
        yyempty = false;
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Discard the token being shifted.
    yyempty = true;

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 335 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	driver.root = (yylhs.value.p_Operation) = (yystack_[0].value.p_Operation);
    }
#line 613 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 3:
#line 338 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	driver.root = (yylhs.value.p_Operation) = (yystack_[0].value.p_Operation);
    }
#line 621 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 5:
#line 348 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Operation) = (yystack_[1].value.p_Operation);
    }
#line 629 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 7:
#line 355 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Operation) = (yystack_[1].value.p_Operation);
    }
#line 637 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 9:
#line 362 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Operation) = new Select((yystack_[1].value.p_protoSelect).distinctness, (yystack_[1].value.p_protoSelect).varSet, (yystack_[2].value.p_DatasetClauses), (yystack_[1].value.p_protoSelect).p_WhereClause, (yystack_[1].value.p_protoSelect).p_SolutionModifier);
    }
#line 645 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 10:
#line 365 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Operation) = new Ask((yystack_[2].value.p_DatasetClauses), new WhereClause((yystack_[1].value.p_op)), NULL); // !! add SliceOpt?
    }
#line 653 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 11:
#line 368 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Operation) = new Ask(new ProductionVector<const DatasetClause*>(), new WhereClause((yystack_[0].value.p_op)), NULL); // !! add SliceOpt?
    }
#line 661 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 12:
#line 371 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Operation) = new Select((yystack_[0].value.p_protoSelect).distinctness, (yystack_[0].value.p_protoSelect).varSet, new ProductionVector<const DatasetClause*>(), (yystack_[0].value.p_protoSelect).p_WhereClause, (yystack_[0].value.p_protoSelect).p_SolutionModifier);
    }
#line 669 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 13:
#line 377 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_DatasetClauses) = new ProductionVector<const DatasetClause*>((yystack_[0].value.p_DatasetClause));
    }
#line 677 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 14:
#line 380 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yystack_[1].value.p_DatasetClauses)->push_back((yystack_[0].value.p_DatasetClause));
	(yylhs.value.p_DatasetClauses) = (yystack_[1].value.p_DatasetClauses);
    }
#line 686 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 16:
#line 388 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_protoSelect) = (yystack_[0].value.p_protoSelect);
	(yylhs.value.p_protoSelect).p_SolutionModifier = new SolutionModifier(NULL, NULL, NULL, -1, -1);
    }
#line 695 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 18:
#line 396 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_protoSelect) = (yystack_[0].value.p_protoSelect);
	(yylhs.value.p_protoSelect).distinctness = DIST_all;
    }
#line 704 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 20:
#line 404 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_protoSelect) = (yystack_[0].value.p_protoSelect);
	(yylhs.value.p_protoSelect).varSet = new StarVarSet();
    }
#line 713 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 22:
#line 412 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_protoSelect) = (yystack_[0].value.p_protoSelect);
	(yylhs.value.p_protoSelect).p_OrderConditions = NULL;
    }
#line 722 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 24:
#line 420 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_protoSelect) = (yystack_[0].value.p_protoSelect);
	(yylhs.value.p_protoSelect).p_having = NULL;
    }
#line 731 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 25:
#line 427 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	throw std::string("ExtendOpt: not ready to parse aggregates");
	(yylhs.value.p_protoSelect) = (yystack_[1].value.p_protoSelect);
    }
#line 740 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 26:
#line 431 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_protoSelect) = (yystack_[0].value.p_protoSelect);
    }
#line 748 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 28:
#line 438 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_protoSelect).p_WhereClause = new WhereClause((yystack_[0].value.p_op));
    }
#line 756 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 29:
#line 446 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_op) = (yystack_[1].value.p_op);
    }
#line 764 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 30:
#line 452 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	driver.setBase((yystack_[0].value.p_URI)->getLexicalValue());
    }
#line 772 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 32:
#line 462 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	driver.ignorePrefix(true);
      }
#line 780 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 33:
#line 464 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	  driver.ignorePrefix(false);
      }
#line 788 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 34:
#line 466 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	  std::string prefix((yystack_[3].value.p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yystack_[1].value.p_URI));
      }
#line 797 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 37:
#line 478 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_protoSelect) = (yystack_[1].value.p_protoSelect);
	(yylhs.value.p_protoSelect).varSet = (yystack_[3].value.p_ExpressionAliaseList);
    }
#line 806 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 38:
#line 485 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_ExpressionAliaseList) = new ExpressionAliasList();
    }
#line 814 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 39:
#line 488 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yystack_[1].value.p_ExpressionAliaseList)->push_back(new ExpressionAlias(new TTermExpression((yystack_[0].value.p_Variable))));
	(yylhs.value.p_ExpressionAliaseList) = (yystack_[1].value.p_ExpressionAliaseList);
    }
#line 823 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 40:
#line 495 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	throw std::string("Extend: not ready to parse aggregates");
    }
#line 831 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 51:
#line 528 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_protoSelect) = (yystack_[1].value.p_protoSelect);
	(yylhs.value.p_protoSelect).distinctness = DIST_distinct;
    }
#line 840 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 52:
#line 532 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_protoSelect) = (yystack_[1].value.p_protoSelect);
	(yylhs.value.p_protoSelect).distinctness = DIST_reduced;
    }
#line 849 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 54:
#line 568 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	throw std::string("GroupClause: not ready to parse aggregates");
	(yylhs.value.p_protoSelect).p_WhereClause = new WhereClause((yystack_[1].value.p_op));
    }
#line 858 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 59:
#line 587 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_protoSelect) = (yystack_[1].value.p_protoSelect);
	(yylhs.value.p_protoSelect).p_having = new w3c_sw::ProductionVector<const w3c_sw::Expression*>((yystack_[2].value.p_Expression)); // !!!
    }
#line 867 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 60:
#line 596 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_protoSelect) = (yystack_[1].value.p_protoSelect);
	(yylhs.value.p_protoSelect).p_OrderConditions = (yystack_[3].value.p_OrderConditions);
    }
#line 876 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 61:
#line 603 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yylhs.value.p_OrderConditions)->push_back((yystack_[0].value.p_OrderConditionPair));
    }
#line 885 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 62:
#line 607 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yystack_[1].value.p_OrderConditions)->push_back((yystack_[0].value.p_OrderConditionPair));
	(yylhs.value.p_OrderConditions) = (yystack_[1].value.p_OrderConditions);
    }
#line 894 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 64:
#line 615 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yylhs.value.p_OrderConditionPair).expression = (yystack_[0].value.p_Expression);
    }
#line 903 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 65:
#line 622 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_e_ASCorDESC) = ORDER_Asc;
    }
#line 911 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 66:
#line 626 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_e_ASCorDESC) = ORDER_Desc;
    }
#line 919 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 67:
#line 632 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_OrderConditionPair).ascOrDesc = (yystack_[2].value.p_e_ASCorDESC);
	(yylhs.value.p_OrderConditionPair).expression = (yystack_[1].value.p_Expression);
    }
#line 928 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 68:
#line 639 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_protoSelect) = (yystack_[1].value.p_protoSelect); // ($5.p_group, ...)
	(yylhs.value.p_protoSelect).p_SolutionModifier = new SolutionModifier(NULL, (yystack_[1].value.p_protoSelect).p_having, (yystack_[1].value.p_protoSelect).p_OrderConditions, (yystack_[3].value.p_int), (yystack_[2].value.p_int)); // !!!
    }
#line 937 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 69:
#line 646 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_int) = ((IntegerRDFLiteral*)(yystack_[0].value.p_NumericRDFLiteral))->getValue();
    }
#line 945 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 70:
#line 649 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_int) = LIMIT_None;
    }
#line 953 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 72:
#line 673 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Operation) = (yystack_[1].value.p_Operation);
    }
#line 961 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 74:
#line 680 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Operation) = (yystack_[1].value.p_Operation);
    }
#line 969 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 76:
#line 687 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Operation) = (yystack_[1].value. p_OperationSet);
}
#line 977 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 77:
#line 693 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	OperationSet* ret = new OperationSet();
	ret->push_back((yystack_[0].value.p_Operation));
    }
#line 986 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 78:
#line 697 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yystack_[1].value. p_OperationSet)->push_back((yystack_[0].value.p_Operation));
	(yylhs.value. p_OperationSet) = (yystack_[1].value. p_OperationSet);
    }
#line 995 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 90:
#line 720 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Operation) = new Load((yystack_[3].value.p_Silence), (yystack_[2].value.p_URI), (yystack_[1].value.p_URI));
    }
#line 1003 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 91:
#line 726 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_URI) = NULL;
    }
#line 1011 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 93:
#line 735 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Operation) = new Clear((yystack_[2].value.p_Silence), (yystack_[1].value.p_URI));
    }
#line 1019 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 94:
#line 741 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Silence) = SILENT_No;
    }
#line 1027 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 95:
#line 744 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Silence) = SILENT_Yes;
    }
#line 1035 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 96:
#line 752 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Operation) = new Drop((yystack_[2].value.p_Silence), (yystack_[1].value.p_URI));
    }
#line 1043 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 97:
#line 760 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Operation) = new Create((yystack_[2].value.p_Silence), (yystack_[1].value.p_URI));
    }
#line 1051 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 98:
#line 768 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Operation) = new Add((yystack_[3].value.p_Silence), (yystack_[2].value.p_URI), (yystack_[1].value.p_URI));
    }
#line 1059 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 99:
#line 776 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Operation) = new Move((yystack_[3].value.p_Silence), (yystack_[2].value.p_URI), (yystack_[1].value.p_URI));
    }
#line 1067 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 100:
#line 784 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Operation) = new Copy((yystack_[3].value.p_Silence), (yystack_[2].value.p_URI), (yystack_[1].value.p_URI));
    }
#line 1075 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 101:
#line 792 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Operation) = new Insert((yystack_[1].value.p_op), NULL);
    }
#line 1083 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 102:
#line 800 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Operation) = new Delete(false, (yystack_[1].value.p_op), NULL);
    }
#line 1091 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 103:
#line 808 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Operation) = new Delete(true, (yystack_[1].value.p_op), NULL);
    }
#line 1099 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 104:
#line 816 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Operation) = new Modify((yystack_[1].value.p_DeleteInsert).del, (yystack_[1].value.p_DeleteInsert).ins, new WhereClause((yystack_[2].value.p_op)), NULL, NULL, NULL); // !! synch with SPARQLParser
    }
#line 1107 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 105:
#line 822 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
#line 1115 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 106:
#line 825 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yystack_[1].value.p_DatasetClauses)->push_back((yystack_[0].value.p_DatasetClause));
	(yylhs.value.p_DatasetClauses) = (yystack_[1].value.p_DatasetClauses);
    }
#line 1124 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 107:
#line 832 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Insert) = NULL;
    }
#line 1132 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 109:
#line 839 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_DeleteInsert).del = (yystack_[1].value.p_Delete);
	(yylhs.value.p_DeleteInsert).ins = (yystack_[0].value.p_Insert);
    }
#line 1141 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 110:
#line 843 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_DeleteInsert).del = NULL;
	(yylhs.value.p_DeleteInsert).ins = (yystack_[0].value.p_Insert);
    }
#line 1150 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 111:
#line 852 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Delete) = new Delete(true, (yystack_[1].value.p_op), NULL);
    }
#line 1158 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 112:
#line 860 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Insert) = new Insert((yystack_[1].value.p_op), NULL);
    }
#line 1166 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 113:
#line 868 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_DatasetClause) = new DefaultGraphClause((yystack_[1].value.p_URI), driver.atomFactory);
    }
#line 1174 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 114:
#line 871 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_DatasetClause) = new NamedGraphClause((yystack_[2].value.p_URI), driver.atomFactory);
    }
#line 1182 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 115:
#line 879 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_URI) = NULL;
    }
#line 1190 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 119:
#line 895 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	w3c_sw_NEED_IMPL("DEFAULT");
    }
#line 1198 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 120:
#line 898 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	w3c_sw_NEED_IMPL("NAMED");
    }
#line 1206 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 121:
#line 901 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	w3c_sw_NEED_IMPL("ALL");
    }
#line 1214 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 124:
#line 917 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_op) = (yystack_[0].value.p_conj);
    }
#line 1222 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 127:
#line 928 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_conj) = new ParserTableConjunction();
    }
#line 1230 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 128:
#line 931 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yystack_[1].value.p_conj)->addTableOperation((yystack_[0].value.p_op), false);
	(yylhs.value.p_conj) = (yystack_[1].value.p_conj);
    }
#line 1239 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 129:
#line 938 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_TTerm) = driver.curGraphName;
	driver.curGraphName = (yystack_[0].value.p_TTerm);
      }
#line 1248 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 130:
#line 941 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	  (yylhs.value.p_op) = (yystack_[0].value.p_op);
	  driver.curGraphName = (yystack_[1].value.p_TTerm);
      }
#line 1257 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 131:
#line 948 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_op) = (yystack_[1].value.p_BasicGraphPattern);
    }
#line 1265 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 132:
#line 951 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_op) = driver.ensureGraphPattern();
    }
#line 1273 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 133:
#line 957 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_BasicGraphPattern) = driver.ensureGraphPattern();
	(yylhs.value.p_BasicGraphPattern)->addTriplePattern((yystack_[0].value.p_TriplePattern), true);
    }
#line 1282 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 134:
#line 961 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
      (yystack_[1].value.p_BasicGraphPattern)->addTriplePattern((yystack_[0].value.p_TriplePattern), true);
	(yylhs.value.p_BasicGraphPattern) = (yystack_[1].value.p_BasicGraphPattern);
    }
#line 1291 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 137:
#line 970 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yystack_[1].value.p_conj)->insertTableOperation((yystack_[2].value.p_op));
	(yylhs.value.p_op) = (yystack_[1].value.p_conj);
    }
#line 1300 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 143:
#line 979 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	throw new std::string("GroupGraphPatternNoSub: GT_LPAREN IT_path VarOrTerm Path VarOrTerm GT_RPAREN not implemented");
	(yylhs.value.p_op) = driver.ensureGraphPattern();
    }
#line 1309 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 146:
#line 991 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_conj) = new ParserTableConjunction();
	(yylhs.value.p_conj)->addTableOperation((yystack_[0].value.p_op), driver.unnestTree);
    }
#line 1318 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 147:
#line 995 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yystack_[1].value.p_conj)->addTableOperation((yystack_[0].value.p_op), driver.unnestTree);
	(yylhs.value.p_conj) = (yystack_[1].value.p_conj);
    }
#line 1327 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 150:
#line 1004 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yystack_[1].value.p_conj)->addTableOperation((yystack_[2].value.p_op), driver.unnestTree);
	(yylhs.value.p_op) = (yystack_[1].value.p_conj);
    }
#line 1336 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 156:
#line 1013 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	throw new std::string("GroupGraphPatternSub: GT_LPAREN IT_path VarOrTerm Path VarOrTerm GT_RPAREN not implemented");
	(yylhs.value.p_op) = driver.ensureGraphPattern();
    }
#line 1345 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 157:
#line 1017 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_op) = new SubSelect(new Select((yystack_[0].value.p_protoSelect).distinctness, (yystack_[0].value.p_protoSelect).varSet, NULL, (yystack_[0].value.p_protoSelect).p_WhereClause, (yystack_[0].value.p_protoSelect).p_SolutionModifier));
    }
#line 1353 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 158:
#line 1023 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_conj) = new ParserTableConjunction();
	(yylhs.value.p_conj)->addTableOperation((yystack_[0].value.p_op), driver.unnestTree);
    }
#line 1362 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 159:
#line 1027 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yystack_[1].value.p_conj)->addTableOperation((yystack_[0].value.p_op), driver.unnestTree);
	(yylhs.value.p_conj) = (yystack_[1].value.p_conj);
    }
#line 1371 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 160:
#line 1034 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expressions) = (yystack_[1].value.p_Expressions);
    }
#line 1379 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 161:
#line 1040 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expressions) = new ProductionVector<const Expression*>((yystack_[0].value.p_Expression));
    }
#line 1387 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 162:
#line 1043 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yystack_[1].value.p_Expressions)->push_back((yystack_[0].value.p_Expression));
	(yylhs.value.p_Expressions) = (yystack_[1].value.p_Expressions);
    }
#line 1396 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 163:
#line 1050 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_TriplePattern) = driver.atomFactory->getTriple((yystack_[3].value.p_TTerm), (yystack_[2].value.p_TTerm), (yystack_[1].value.p_TTerm));
    }
#line 1404 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 164:
#line 1064 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	OptionalGraphPattern* opt = new OptionalGraphPattern((yystack_[2].value.p_op));
	TableConjunction* conj = new TableConjunction();
	conj->addTableOperation((yystack_[3].value.p_op), driver.unnestTree);
	conj->addTableOperation(opt, driver.unnestTree);
	if ((yystack_[1].value.p_Expressions) != NULL) {
	    for (std::vector<const Expression*>::const_iterator it = (yystack_[1].value.p_Expressions)->begin();
		 it != (yystack_[1].value.p_Expressions)->end(); ++it)
		opt->addExpression(*it);
	    (yystack_[1].value.p_Expressions)->clear();
	    delete (yystack_[1].value.p_Expressions);
	}
	(yylhs.value.p_op) = conj;
    }
#line 1423 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 165:
#line 1078 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	OptionalGraphPattern* opt = new OptionalGraphPattern((yystack_[2].value.p_op));
	if ((yystack_[1].value.p_Expressions) != NULL) {
	    for (std::vector<const Expression*>::const_iterator it = (yystack_[1].value.p_Expressions)->begin();
		 it != (yystack_[1].value.p_Expressions)->end(); ++it)
		opt->addExpression(*it);
	    (yystack_[1].value.p_Expressions)->clear();
	    delete (yystack_[1].value.p_Expressions);
	}
	(yylhs.value.p_op) = opt;
    }
#line 1439 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 166:
#line 1092 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expressions) = NULL;
    }
#line 1447 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 168:
#line 1099 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_TTerm) = driver.curGraphName;
	driver.curGraphName = (yystack_[0].value.p_TTerm);
      }
#line 1456 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 169:
#line 1102 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	  (yylhs.value.p_op) = (yystack_[1].value.p_op);
	  driver.curGraphName = (yystack_[2].value.p_TTerm);
      }
#line 1465 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 170:
#line 1109 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_op) = new ServiceGraphPattern((yystack_[2].value.p_TTerm), (yystack_[1].value.p_op), (yystack_[3].value.p_Silence), driver.atomFactory, false);
    }
#line 1473 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 171:
#line 1117 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	TableConjunction* ret = new TableConjunction();
	ret->addTableOperation((yystack_[2].value.p_op), driver.unnestTree);
	ret->addTableOperation(new MinusGraphPattern((yystack_[1].value.p_op)), driver.unnestTree);
	(yylhs.value.p_op) = ret;
    }
#line 1484 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 172:
#line 1126 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	TableDisjunction* ret = new TableDisjunction();
	ret->addTableOperation((yystack_[2].value.p_op), driver.unnestTree);
	ret->addTableOperation((yystack_[1].value.p_op), driver.unnestTree);
	(yylhs.value.p_op) = ret;
    }
#line 1495 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 173:
#line 1135 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_op) = new Filter((yystack_[1].value.p_op), (yystack_[2].value.p_Expressions)->begin(), (yystack_[2].value.p_Expressions)->end());
	(yystack_[2].value.p_Expressions)->clear();
	delete (yystack_[2].value.p_Expressions);
    }
#line 1505 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 174:
#line 1151 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expressions) = NULL;
    }
#line 1513 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 175:
#line 1154 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yystack_[1].value.p_Expressions)->push_front((yystack_[2].value.p_Expression));
	(yylhs.value.p_Expressions) = (yystack_[1].value.p_Expressions);
    }
#line 1522 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 176:
#line 1161 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = (yystack_[0].value.p_Expression);
    }
#line 1530 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 177:
#line 1167 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expressions) = new ProductionVector<const Expression*>();
    }
#line 1538 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 178:
#line 1170 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yystack_[1].value.p_Expressions)->push_back((yystack_[0].value.p_Expression));
	(yylhs.value.p_Expressions) = (yystack_[1].value.p_Expressions);
    }
#line 1547 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 185:
#line 1227 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	// $$ = new PathAlternative($3, $4);
    }
#line 1555 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 186:
#line 1233 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	// $$ = new PathSequence($3, $4);
    }
#line 1563 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 187:
#line 1241 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	// $$ = new PathEltOrInverse($3);
    }
#line 1571 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 188:
#line 1247 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	// $$ = $3;
    }
#line 1579 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 189:
#line 1250 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	// $$ = $5;
      }
#line 1587 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 193:
#line 1262 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_URI);
    }
#line 1595 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 194:
#line 1265 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
#line 1603 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 195:
#line 1273 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_TTerm) = (yystack_[1].value.p_TTerm);
    }
#line 1611 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 197:
#line 1280 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	// $1->push_back($2);
	(yylhs.value.p_TTerm) = (yystack_[1].value.p_TTerm);
    }
#line 1620 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 198:
#line 1287 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_NumericRDFLiteral) = (yystack_[0].value.p_NumericRDFLiteral);
    }
#line 1628 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 199:
#line 1304 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_Variable);
    }
#line 1636 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 201:
#line 1311 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_Variable);
    }
#line 1644 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 202:
#line 1314 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_URI);
    }
#line 1652 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 205:
#line 1325 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_URI);
    }
#line 1660 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 207:
#line 1329 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_NumericRDFLiteral);
    }
#line 1668 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 208:
#line 1332 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_BooleanRDFLiteral);
    }
#line 1676 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 210:
#line 1336 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil");
    }
#line 1684 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 217:
#line 1351 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	ProductionVector<const Expression*>* t = new ProductionVector<const Expression*>();
	t->push_back((yystack_[2].value.p_Expression));
	t->push_back((yystack_[1].value.p_Expression));
	(yylhs.value.p_Expression) = new BooleanDisjunction(t);
    }
#line 1695 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 218:
#line 1360 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	ProductionVector<const Expression*>* t = new ProductionVector<const Expression*>();
	t->push_back((yystack_[2].value.p_Expression));
	t->push_back((yystack_[1].value.p_Expression));
	(yylhs.value.p_Expression) = new BooleanConjunction(t);
    }
#line 1706 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 222:
#line 1378 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new BooleanEQ((yystack_[2].value.p_Expression), (yystack_[1].value.p_Expression));
    }
#line 1714 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 223:
#line 1381 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new BooleanNE((yystack_[2].value.p_Expression), (yystack_[1].value.p_Expression));
    }
#line 1722 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 224:
#line 1384 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new BooleanLT((yystack_[2].value.p_Expression), (yystack_[1].value.p_Expression));
    }
#line 1730 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 225:
#line 1387 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new BooleanGT((yystack_[2].value.p_Expression), (yystack_[1].value.p_Expression));
    }
#line 1738 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 226:
#line 1390 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new BooleanLE((yystack_[2].value.p_Expression), (yystack_[1].value.p_Expression));
    }
#line 1746 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 227:
#line 1393 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new BooleanGE((yystack_[2].value.p_Expression), (yystack_[1].value.p_Expression));
    }
#line 1754 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 228:
#line 1396 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new NaryIn((yystack_[1].value.p_Expressions));
    }
#line 1762 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 230:
#line 1408 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	ProductionVector<const Expression*>* t = new ProductionVector<const Expression*>();
	t->push_back((yystack_[2].value.p_Expression));
	t->push_back((yystack_[1].value.p_Expression));
	(yylhs.value.p_Expression) = new ArithmeticSum(t);
    }
#line 1773 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 231:
#line 1414 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	ProductionVector<const Expression*>* t = new ProductionVector<const Expression*>();
	t->push_back((yystack_[2].value.p_Expression));
	t->push_back(new ArithmeticNegation((yystack_[1].value.p_Expression)));
	(yylhs.value.p_Expression) = new ArithmeticSum(t);
    }
#line 1784 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 232:
#line 1428 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	ProductionVector<const Expression*>* t = new ProductionVector<const Expression*>();
	t->push_back((yystack_[2].value.p_Expression));
	t->push_back(new ArithmeticNegation((yystack_[1].value.p_Expression)));
	(yylhs.value.p_Expression) = new ArithmeticProduct(t);
    }
#line 1795 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 233:
#line 1434 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	ProductionVector<const Expression*>* t = new ProductionVector<const Expression*>();
	t->push_back((yystack_[2].value.p_Expression));
	t->push_back(new ArithmeticInverse((yystack_[1].value.p_Expression)));
	(yylhs.value.p_Expression) = new ArithmeticProduct(t);
    }
#line 1806 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 234:
#line 1443 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new BooleanNegation((yystack_[1].value.p_Expression));
    }
#line 1814 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 235:
#line 1446 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = (yystack_[1].value.p_Expression);
    }
#line 1822 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 236:
#line 1449 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new ArithmeticNegation((yystack_[1].value.p_Expression));
    }
#line 1830 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 239:
#line 1457 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new TTermExpression((yystack_[0].value.p_TTerm));
    }
#line 1838 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 240:
#line 1460 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new TTermExpression((yystack_[0].value.p_NumericRDFLiteral));
    }
#line 1846 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 241:
#line 1463 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new TTermExpression((yystack_[0].value.p_BooleanRDFLiteral));
    }
#line 1854 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 242:
#line 1466 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new TTermExpression((yystack_[0].value.p_Variable));
    }
#line 1862 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 243:
#line 1469 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new TTermExpression((yystack_[0].value.p_TTerm));
    }
#line 1870 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 244:
#line 1480 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 1878 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 245:
#line 1483 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 1886 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 246:
#line 1486 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yystack_[3].value.p_Expression), (yystack_[1].value.p_Expression), NULL));
    }
#line 1894 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 247:
#line 1489 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 1902 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 248:
#line 1492 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yystack_[1].value.p_Variable)), NULL, NULL));
    }
#line 1910 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 249:
#line 1495 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 1918 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 250:
#line 1498 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 1926 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 251:
#line 1501 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 1934 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 252:
#line 1504 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
#line 1942 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 253:
#line 1507 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 1950 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 254:
#line 1510 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ceil, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 1958 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 255:
#line 1513 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 1966 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 256:
#line 1516 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 1974 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 257:
#line 1519 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yystack_[1].value.p_Expressions))));
    }
#line 1982 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 259:
#line 1523 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 1990 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 260:
#line 1526 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 1998 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 261:
#line 1529 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2006 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 262:
#line 1532 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2014 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 263:
#line 1535 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yystack_[3].value.p_Expression), (yystack_[1].value.p_Expression), NULL));
    }
#line 2022 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 264:
#line 1538 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yystack_[3].value.p_Expression), (yystack_[1].value.p_Expression), NULL));
    }
#line 2030 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 265:
#line 1541 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yystack_[3].value.p_Expression), (yystack_[1].value.p_Expression), NULL));
    }
#line 2038 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 266:
#line 1544 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_before, (yystack_[3].value.p_Expression), (yystack_[1].value.p_Expression), NULL));
    }
#line 2046 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 267:
#line 1547 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_after, (yystack_[3].value.p_Expression), (yystack_[1].value.p_Expression), NULL));
    }
#line 2054 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 268:
#line 1550 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2062 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 269:
#line 1553 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2070 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 270:
#line 1556 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2078 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 271:
#line 1559 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2086 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 272:
#line 1562 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2094 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 273:
#line 1565 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2102 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 274:
#line 1568 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2110 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 275:
#line 1571 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2118 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 276:
#line 1574 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
#line 2126 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 277:
#line 1577 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2134 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 278:
#line 1580 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2142 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 279:
#line 1583 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2150 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 280:
#line 1586 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2158 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 281:
#line 1589 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2166 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 282:
#line 1592 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
#line 2175 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 283:
#line 1596 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yystack_[5].value.p_Expression), (yystack_[3].value.p_Expression), (yystack_[1].value.p_Expression)));
    }
#line 2183 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 284:
#line 1599 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yystack_[3].value.p_Expression), (yystack_[1].value.p_Expression), NULL));
    }
#line 2191 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 285:
#line 1602 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yystack_[3].value.p_Expression), (yystack_[1].value.p_Expression), NULL));
    }
#line 2199 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 286:
#line 1605 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yystack_[3].value.p_Expression), (yystack_[1].value.p_Expression), NULL));
    }
#line 2207 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 287:
#line 1608 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2215 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 288:
#line 1611 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2223 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 289:
#line 1614 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2231 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 290:
#line 1617 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2239 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 291:
#line 1620 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2247 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 294:
#line 1628 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = NULL;
    }
#line 2255 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 296:
#line 1637 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yystack_[4].value.p_Expression), (yystack_[2].value.p_Expression), (yystack_[1].value.p_Expression)));
    }
#line 2263 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 297:
#line 1643 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = NULL;
    }
#line 2271 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 299:
#line 1650 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yystack_[4].value.p_Expression), (yystack_[2].value.p_Expression), (yystack_[1].value.p_Expression)));
    }
#line 2279 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 300:
#line 1656 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_exists, driver.ensureGraphPattern(), NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
#line 2288 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 305:
#line 1678 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
 	(yylhs.value.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yystack_[1].value.p_distinctness), (yystack_[0].value.p_Expression), AggregateCall::ScalarVals()));
    }
#line 2296 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 306:
#line 1684 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_distinctness) = DIST_all;
    }
#line 2304 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 307:
#line 1687 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_distinctness) = DIST_distinct;
}
#line 2312 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 308:
#line 1693 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = NULL;
    }
#line 2320 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 310:
#line 1700 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new AggregateCall((yystack_[2].value.p_URI), (yystack_[1].value.p_distinctness), (yystack_[0].value.p_Expression), AggregateCall::ScalarVals()));
    }
#line 2328 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 311:
#line 1706 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_URI) = TTerm::FUNC_sum;
    }
#line 2336 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 312:
#line 1709 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_URI) = TTerm::FUNC_min;
    }
#line 2344 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 313:
#line 1712 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_URI) = TTerm::FUNC_max;
    }
#line 2352 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 314:
#line 1715 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_URI) = TTerm::FUNC_avg;
    }
#line 2360 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 315:
#line 1718 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_URI) = TTerm::FUNC_sample;
    }
#line 2368 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 316:
#line 1724 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group_concat, (yystack_[1].value.p_distinctness), (yystack_[0].value.p_Expression), AggregateCall::ScalarVals()));
    }
#line 2376 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 317:
#line 1727 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
      (yylhs.value.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group_concat, (yystack_[2].value.p_distinctness), (yystack_[0].value.p_Expression), AggregateCall::ScalarVals()));
    }
#line 2384 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 319:
#line 1737 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new TTermExpression((yystack_[0].value.p_URI));
    }
#line 2392 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 320:
#line 1740 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall((yystack_[2].value.p_URI), new ArgList((yystack_[1].value.p_Expressions))));
    }
#line 2400 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 321:
#line 1746 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_TTerm) = driver.getRDFLiteral(*(yystack_[1].value.p_string), (yystack_[0].value.p_uri_or_langtag).uri, (yystack_[0].value.p_uri_or_langtag).langtag);
	delete (yystack_[1].value.p_string);
    }
#line 2409 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 322:
#line 1753 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_URI) = (yystack_[0].value.p_URI);
    }
#line 2417 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 323:
#line 1759 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_uri_or_langtag).uri = NULL;
	(yylhs.value.p_uri_or_langtag).langtag = (yystack_[0].value.p_LANGTAG);
    }
#line 2426 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 324:
#line 1763 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_uri_or_langtag).uri = (yystack_[0].value.p_URI);
	(yylhs.value.p_uri_or_langtag).langtag = NULL;
    }
#line 2435 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;

  case 325:
#line 1770 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_uri_or_langtag).uri = NULL;
	(yylhs.value.p_uri_or_langtag).langtag = NULL;
    }
#line 2444 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
    break;


#line 2448 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:847
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state,
                                           yyempty ? yyempty_ : yyla.type_get ()));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyempty)
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyempty = true;
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
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
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyempty)
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyempty)
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  SPARQLalgebraParser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  SPARQLalgebraParser::yysyntax_error_ (state_type yystate, symbol_number_type yytoken) const
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short int SPARQLalgebraParser::yypact_ninf_ = -648;

  const signed char SPARQLalgebraParser::yytable_ninf_ = -1;

  const short int
  SPARQLalgebraParser::yypact_[] =
  {
     -29,   591,    52,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -102,   -26,   -12,    -6,    15,    15,
      22,  1764,    31,    42,    45,  -648,  -648,    42,    42,    42,
     154,  1455,    42,   -61,   -83,   116,  1187,    50,    56,    57,
      61,   -35,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,    63,  -648,  -648,  -648,  -648,
    -648,  1385,    40,    60,    66,   786,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,    42,  -648,    68,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,   -93,  -648,  -648,  1787,  1508,    87,   170,   -19,  -648,
      42,    81,    42,  -648,  -648,  -648,  -648,  -648,  -648,   -24,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,    42,  -648,   154,
    -648,  -648,   -83,  -648,    99,   109,  -648,   -61,   109,   -61,
     -61,   -61,   -61,  -648,   -61,  -648,  -648,   -61,   631,   114,
     125,  -648,  1188,   141,   142,  1241,   157,   158,    86,   160,
    -648,   293,  -648,  1351,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,    42,  -648,  -648,  -648,  -648,  -648,  -648,   -15,   -55,
      -9,  -648,  -648,   100,  -648,    -8,  1818,  1818,  1818,  1818,
    1818,  1818,  1818,  1818,  1818,  -105,  1818,  1818,  1818,  1818,
    1818,  1818,  1818,  1818,  1818,  1818,  1818,  1818,   -46,  1818,
    1818,  1818,  1818,  1818,  1818,  1818,  1818,  1818,  1818,  1818,
    1818,  1818,  1818,   163,  1818,  1818,  1818,  1818,  1818,  1818,
    1818,  1818,  1818,  1818,    42,  1818,  1818,  1818,  1818,  1818,
    1818,  1818,  1818,  1818,  1818,  1818,  1818,  1818,  1818,  1818,
     166,  1818,   171,  1433,   172,   109,  -648,  -648,  -648,  -648,
     663,  1478,  -648,  -648,  -648,    81,  -648,  1455,  -648,  -648,
      81,   168,  -648,   177,   178,    42,  -648,    30,  1455,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,   180,    42,   188,  -648,
     109,   193,   109,   203,   -84,   109,     7,   -84,   204,  -648,
     -59,   -84,   209,  -648,   211,     7,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  1455,    63,  -648,    13,  -648,  -648,  -648,
     216,  -648,  -648,  -105,  -648,  1818,   217,  -648,  1032,   198,
     227,   228,   231,   232,   235,   236,   238,   240,   241,  1540,
    -648,   242,  1563,  1818,   229,   230,  1818,   246,  1818,   248,
    -648,   249,   251,  -648,  1818,   254,   255,   244,   256,   259,
     260,  1818,  1625,   261,   262,   250,  1818,   252,   263,   265,
    -648,   268,   269,   270,   274,   275,  1648,   264,   266,   279,
    1818,   283,  1818,   271,   284,  1818,  1818,   272,   290,   292,
    1710,  1818,   297,   299,   300,   291,   294,  -648,  1733,  -648,
    -648,  -648,  -648,  -648,  1818,   302,  -648,  1455,   311,  -648,
    -648,   312,   -24,   -24,  -648,  -648,  -648,   -24,   -24,   -83,
     -24,   314,  -648,   317,  1324,   320,   324,   464,  -648,   318,
     327,  -648,  -648,  -648,   -84,  -648,   109,  -648,  -648,  -648,
    -648,   330,   -84,  -648,     1,   154,  -648,  -648,  -648,   -84,
    -648,  -648,   336,   -24,    63,  -648,  -648,   277,  1404,   340,
    1818,   341,   335,  1818,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,   344,  1818,  1818,
     345,  -648,   352,  -648,  -648,  -648,  -648,  -648,  -648,  1818,
    -648,  -648,  -648,   353,  -648,   355,  -648,  -648,  1818,   356,
    1818,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  1818,
    1818,  -648,   357,  -648,   358,  1818,  -648,   359,   360,  1818,
    -648,  -648,  -648,   361,   362,  -648,  -648,  -648,  1818,  1818,
    -648,   363,  1469,   364,  1455,  -648,  -648,   365,   -24,  -648,
     -28,   -24,   -83,   366,  -648,  -648,  -648,  -648,   -21,   367,
     370,  -648,  -648,   368,   371,  -648,  -648,   375,  -648,   386,
    -648,  1455,  -648,    14,  -648,  -648,   387,  -648,   328,  -648,
      41,   379,  -648,   380,   379,  -648,  -648,   -50,   395,  -648,
    -648,   396,  -648,   398,   399,   402,  -648,  -648,   403,  -648,
    -648,   404,  -648,  -648,   405,   408,  -648,  -648,   409,  -648,
     411,  -648,  -648,   413,   -24,  -648,  -648,  -648,  -648,   453,
    -648,  -648,  -648,  -648,  -648,   407,  -648,   416,  -648,  -648,
     369,  -648,   417,    42,  -648,  1818,  -648,   426,  1818,   434,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,   435,   436,   440,  -648,  -648,   446,
      32,   447,   449,  -648,  -648,   451,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,   484,  -648,  -648,   484,   454,  -648,
    -648,   484,  -648,  -648,  -648,  -648,  -648,  1416,  1841,  -648,
    1818,  -648,  -648,  -648,   909,  -648,  1818,  -648,   -13,  -648,
     458,  -648
  };

  const unsigned short int
  SPARQLalgebraParser::yydefact_[] =
  {
       0,     0,     0,     2,     4,     6,     8,    12,    16,    18,
      20,    22,    24,    26,    11,    19,    17,    28,    27,    23,
      21,    15,     3,    71,    73,    75,   135,    53,   138,   139,
     140,   141,   142,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   144,   145,     0,     0,     0,
       0,     0,     0,    94,     0,     0,     0,     0,     0,     0,
       0,     0,    77,    79,    80,    81,    85,    82,    83,    84,
      86,    87,    88,    89,    13,     0,     1,    30,    35,    38,
      41,     0,     0,     0,     0,     0,   339,   340,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   341,   343,   342,
     344,   345,   348,   347,   243,   203,   204,     0,   242,     0,
     211,   212,   213,   219,   221,   220,   229,   214,   215,   216,
     237,   292,   258,   293,   238,   239,   240,   327,   328,   329,
     241,   325,   319,   346,     0,     0,     0,     0,     0,   133,
       0,   166,     0,   168,   201,   202,   210,   349,   350,     0,
     199,   200,   206,   207,   208,   205,   209,     0,    95,     0,
      70,   198,     0,    69,     0,     0,   105,    94,     0,    94,
      94,    94,    94,   127,    94,   127,   127,    94,     0,     0,
       0,    14,     0,     0,     0,     0,     0,     0,     0,     0,
      76,     0,    78,     0,    48,   157,    47,    50,    49,    46,
     148,     0,   151,   152,   153,   154,   155,   149,     0,     0,
       0,    51,    52,     0,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   294,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   323,   324,   326,   321,
       0,     0,    61,    63,    64,     0,    29,     0,   131,   134,
     166,     0,   167,     0,     0,     0,   194,     0,     0,   179,
     180,   181,   182,   184,   183,   193,     0,     0,     0,   132,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   122,
     124,     0,     0,   123,     0,     0,     9,    10,     5,    72,
       7,    74,    25,     0,     0,   146,     0,    31,    32,    36,
       0,    39,    40,     0,    42,     0,     0,    56,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     161,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     295,     0,     0,   174,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     276,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   252,     0,   173,
      59,   322,    65,    66,     0,     0,    62,     0,     0,   165,
     172,     0,     0,     0,   192,   191,   190,     0,     0,     0,
       0,     0,   171,     0,     0,     0,     0,     0,   106,     0,
       0,   117,   113,   115,     0,   116,    91,   120,   121,   119,
     118,     0,     0,   103,     0,     0,   128,   125,   126,     0,
     102,   101,     0,     0,     0,   137,   147,     0,     0,     0,
       0,     0,     0,     0,   261,   260,   279,   256,   273,   244,
     255,   272,   248,   228,   162,   271,   257,     0,     0,     0,
       0,   254,     0,   291,   251,   253,   177,   282,   259,     0,
     234,   290,   250,     0,   235,     0,   289,   281,     0,     0,
       0,   249,   280,   270,   288,   262,   275,   274,   160,     0,
       0,   269,     0,   300,     0,     0,   268,     0,     0,     0,
     287,   247,   236,     0,     0,   245,   278,   277,     0,     0,
     320,     0,     0,     0,     0,   164,   169,     0,     0,   196,
       0,     0,     0,     0,   143,   170,    68,   114,     0,     0,
     107,   110,    97,     0,     0,    92,    96,     0,   129,     0,
      93,     0,   158,     0,    33,    37,     0,    44,     0,    57,
       0,   297,   218,     0,   297,   227,   225,     0,     0,   223,
     230,     0,   232,     0,     0,     0,   217,   226,     0,   222,
     224,     0,   231,   233,     0,     0,    67,    60,     0,   187,
       0,   195,   197,     0,     0,   188,   127,   127,   104,     0,
     109,   108,    98,    90,    99,     0,   100,     0,   150,   159,
       0,    43,     0,     0,    58,     0,   298,     0,     0,     0,
     175,   178,   263,   284,   264,   285,   265,   286,   246,   266,
     267,   163,   185,   186,     0,     0,     0,   130,   156,     0,
       0,     0,     0,   176,   299,     0,   296,   189,   112,   111,
      34,   312,   313,   311,   306,   314,   315,   306,     0,   302,
     303,   306,   304,    45,    54,   283,   307,     0,     0,   301,
       0,   308,   309,   305,     0,   316,     0,   310,     0,   317,
       0,   318
  };

  const short int
  SPARQLalgebraParser::yypgoto_[] =
  {
    -648,  -648,  -648,  -648,   457,   499,  -648,   502,   243,    26,
     210,   127,   455,   506,   510,  -648,  -648,  -648,  -648,  -648,
    -648,   -71,  -648,  -648,  -648,  -648,   372,   -30,  -648,   -64,
     -42,  -648,  -648,  -648,   -58,   -57,  -648,   280,  -648,  -648,
     -54,  -153,  -648,  -648,   515,   516,  -648,   513,  -648,  -648,
    -648,    74,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,    -4,   -32,  -311,  -309,   247,
    -552,   401,   -52,  -648,  -648,  -648,  -648,   -73,  -648,   423,
     385,  -648,  -334,  -648,  -129,  -213,   441,   -53,   281,   -51,
    -648,   -40,   -39,   -38,   -36,  -648,   -22,  -648,  -416,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -267,  -154,
      94,  -648,   -41,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,   -20,  -648,  -648,  -648,
    -648,  -648,  -647,  -648,  -648,  -648,  -648,  -648,  -648,   -48,
    -648,  -648,  -648,   -45,  -648,  -648,  -648,   -23,  -135,   -43,
    -648,  -648
  };

  const short int
  SPARQLalgebraParser::yydefgoto_[] =
  {
      -1,     2,     3,     4,     5,     6,    57,     7,     8,     9,
      10,    11,    12,    13,    14,    58,    59,   349,   487,   650,
     208,    15,   209,    60,   210,   354,   214,   599,   195,    16,
      17,    18,   215,   600,    19,    20,   291,   292,   434,   293,
      21,   162,    22,    23,    24,    25,    61,    62,    63,   584,
      64,   159,    65,    66,    67,    68,    69,    70,    71,    72,
      73,   321,   640,   579,   580,   581,    74,   464,   470,   471,
     328,   332,   329,   476,   330,   477,   645,    26,   138,    27,
      75,   346,   201,   593,   107,   369,   139,    28,   303,    29,
     305,    30,    31,    32,    33,   385,   656,   607,   308,   309,
     310,   311,   312,   450,   313,   314,   570,   163,   149,   143,
     108,   151,   370,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   381,   121,   657,   122,   123,   681,
     698,   699,   707,   713,   700,   701,   702,   716,   124,   125,
     287,   288,   289,   126,   127,   128,   129,   130,   131,   132,
     133,   156
  };

  const unsigned short int
  SPARQLalgebraParser::yytable_[] =
  {
     109,   136,   200,   152,   194,   317,   153,   145,   155,   318,
     484,   196,   302,   460,    44,   372,   472,   197,   198,   306,
     479,   199,   202,   306,   203,   181,   567,   568,   154,   467,
     437,   569,   571,   468,   573,   204,   205,   206,   636,   207,
     285,   451,   281,   350,   463,   160,   406,   474,   660,   383,
     708,   442,    76,   469,   710,    77,   475,   637,   105,   106,
     384,   161,   655,   190,    82,    83,   158,   591,   428,   443,
     631,   191,   286,   101,   102,   103,   483,     1,   307,   298,
      78,   444,   307,   347,   675,   676,   445,   137,    55,   352,
     356,   348,   446,   294,    79,    40,   295,   353,   213,    44,
      80,    45,    46,    47,    48,    49,   315,   691,   105,   106,
      50,   485,   648,   692,   693,   694,   145,    51,   695,   135,
     193,    81,   320,   333,   333,   323,   696,    52,    84,   101,
     102,   103,   697,   101,   102,   103,   164,   134,   211,   653,
      97,    98,    99,   100,   144,   150,   447,   598,   135,   448,
     592,   137,   630,   583,   632,   633,   178,   585,   212,    53,
     449,   587,   182,   185,   101,   102,   103,   188,   589,   193,
     564,   302,   213,    55,   283,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   297,   296,   371,   301,   373,   374,
     375,   376,   377,   378,   379,   380,   382,   319,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   336,   401,   402,   403,   404,   405,   674,   407,
     408,   409,   410,   337,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   338,
     339,   322,   431,   324,   325,   326,   327,   281,   331,   152,
     294,   335,   153,   144,   155,   340,   341,   478,   342,   649,
     152,   400,   355,   153,   427,   155,   101,   102,   103,   429,
     430,   200,   259,   194,   154,   439,   440,   456,   452,   461,
     196,   465,   466,   461,   465,   154,   197,   198,   465,   458,
     199,   202,   461,   203,   454,   152,   572,   628,   153,   457,
     155,   462,   473,   351,   204,   205,   206,   480,   207,   481,
     493,   101,   102,   103,   491,   281,   166,   105,   106,   368,
     154,   588,   488,   492,   647,   494,   495,   167,   504,   496,
     497,   504,   507,   498,   499,   510,   500,   512,   501,   502,
     505,   508,   509,   516,   511,   169,   513,   514,   170,   515,
     523,   525,   517,   518,   520,   529,   519,   521,   522,   526,
     527,   531,   528,   532,   530,   504,   533,   534,   535,   542,
     171,   544,   536,   537,   547,   548,   539,   541,   540,   553,
     554,   543,   546,   545,   549,   172,   173,   504,   550,   152,
     551,   150,   153,   561,   155,   555,   174,   556,   557,   315,
     315,   175,   150,   558,   315,   315,   559,   315,   562,   565,
     566,   200,   574,   194,   154,   575,   176,   177,   576,   634,
     196,   465,   577,   461,   578,   582,   197,   198,   586,   465,
     199,   202,   145,   203,   590,   594,   465,   150,   595,   597,
     315,   598,   602,   605,   204,   205,   206,   490,   207,   596,
     606,   609,   601,   610,   612,   616,   617,   619,   620,   622,
     623,   626,   627,   629,   635,   638,   642,   603,   604,   643,
     140,   141,   142,   644,   295,   157,   639,    44,   608,    45,
      46,    47,    48,    49,   646,   651,   165,   611,    50,   613,
     652,   655,   658,   662,   663,    51,   664,   665,   614,   615,
     666,   667,   668,   669,   618,    52,   670,   671,   621,   672,
     168,   673,   636,   474,   678,   183,   152,   624,   625,   153,
     200,   155,   194,   680,   684,   315,   679,   315,   315,   196,
     282,   150,   686,   687,   688,   197,   198,    53,   689,   199,
     202,   154,   203,   152,   690,   703,   153,   704,   155,   705,
     706,    55,   709,   204,   205,   206,   721,   207,   186,   179,
     489,   455,   563,   300,   284,   304,   189,   180,   154,   144,
     654,   436,   677,   184,   192,   187,   641,   334,   344,   299,
     316,   438,   482,   720,   659,   661,     0,   357,     0,     0,
       0,   315,     0,     0,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,    48,
      49,   682,     0,     0,   683,    50,     0,   685,     0,     0,
       0,     0,    51,     0,   345,     0,     0,     0,     0,     0,
       0,     0,    52,     0,     0,     0,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,    48,
      49,     0,     0,   165,     0,    50,     0,     0,   150,     0,
       0,     0,    51,     0,    53,     0,   712,   715,     0,   717,
      54,   281,    52,     0,     0,   719,     0,   168,    55,     0,
       0,     0,     0,     0,     0,   150,     0,   411,   216,     0,
     217,   218,   219,   220,     0,   221,   222,    56,   432,   433,
     223,   224,     0,   225,    53,   226,   227,   228,   229,     0,
      54,     0,   230,   231,     0,     0,   232,   233,    55,     0,
       0,   234,     0,   235,   236,     0,   237,   238,   441,     0,
     239,   240,   241,   242,   243,   244,     0,   245,     0,   246,
     453,     0,     0,   247,   459,     0,     0,   248,   249,     0,
       0,   250,   251,   252,   253,     0,     0,     0,     0,   254,
     255,     0,   256,     0,   257,   258,     0,     0,   260,   486,
     261,     0,   262,   263,   264,     0,   265,   266,     0,     0,
     267,   268,     0,   269,     0,   270,     0,     0,     0,   271,
       0,     0,   272,     0,   273,   274,     0,   275,   276,     0,
       0,   277,   278,   279,   280,     0,     0,     0,     0,     0,
       0,   216,     0,   217,   218,   219,   220,     0,   221,   222,
     101,   102,   103,   223,   224,     0,   225,     0,   226,   227,
     228,   229,     0,     0,     0,   230,   231,     0,     0,   232,
     233,     0,     0,     0,   234,     0,   235,   236,     0,   237,
     238,     0,     0,   239,   240,   241,   242,   243,   244,     0,
     245,     0,   246,     0,     0,     0,   247,     0,     0,     0,
     248,   249,     0,     0,   250,   251,   252,   253,     0,     0,
       0,     0,   254,   255,     0,   256,     0,   257,   258,     0,
     259,   260,     0,   261,     0,   262,   263,   264,     0,   265,
     266,     0,     0,   267,   268,     0,   269,     0,   270,     0,
       0,     0,   271,     0,     0,   272,     0,   273,   274,     0,
     275,   276,     0,     0,   277,   278,   279,   280,     0,     0,
       0,     0,     0,     0,   216,     0,   217,   218,   219,   220,
       0,   221,   222,   101,   102,   103,   223,   224,     0,   225,
       0,   226,   227,   228,   229,     0,     0,     0,   230,   231,
       0,     0,   232,   233,     0,     0,   718,   234,     0,   235,
     236,     0,   237,   238,     0,     0,   239,   240,   241,   242,
     243,   244,     0,   245,     0,   246,     0,     0,     0,   247,
       0,     0,     0,   248,   249,     0,     0,   250,   251,   252,
     253,     0,     0,     0,     0,   254,   255,     0,   256,     0,
     257,   258,     0,     0,   260,     0,   261,     0,   262,   263,
     264,     0,   265,   266,     0,     0,   267,   268,     0,   269,
       0,   270,     0,     0,     0,   271,     0,     0,   272,     0,
     273,   274,     0,   275,   276,     0,     0,   277,   278,   279,
     280,     0,     0,     0,     0,     0,     0,   216,     0,   217,
     218,   219,   220,     0,   221,   222,   101,   102,   103,   223,
     224,     0,   225,     0,   226,   227,   228,   229,     0,     0,
       0,   230,   231,     0,     0,   232,   233,     0,     0,     0,
     234,     0,   235,   236,     0,   237,   238,     0,     0,   239,
     240,   241,   242,   243,   244,     0,   245,     0,   246,     0,
       0,     0,   247,     0,     0,     0,   248,   249,     0,     0,
     250,   251,   252,   253,     0,     0,     0,     0,   254,   255,
       0,   256,     0,   257,   258,     0,     0,   260,     0,   261,
       0,   262,   263,   264,     0,   265,   266,     0,     0,   267,
     268,     0,   269,     0,   270,     0,     0,     0,   271,     0,
       0,   272,     0,   273,   274,     0,   275,   276,     0,     0,
     277,   278,   279,   280,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   101,
     102,   103,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,    48,    49,     0,   165,
     166,     0,    50,     0,     0,     0,     0,     0,     0,    51,
       0,   167,     0,     0,     0,     0,     0,     0,     0,    52,
       0,     0,     0,   168,     0,     0,     0,     0,     0,   169,
       0,     0,   170,     0,     0,     0,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,    48,
      49,    53,     0,     0,   171,    50,     0,    54,     0,     0,
       0,     0,    51,     0,     0,    55,     0,     0,     0,   172,
     173,     0,    52,     0,     0,     0,     0,     0,     0,     0,
     174,     0,     0,     0,    56,   175,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     176,   177,     0,     0,    53,     0,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,    55,    36,
      37,    38,    39,    40,    41,    42,     0,    44,     0,    45,
      46,    47,    48,    49,     0,     0,     0,    56,    50,     0,
       0,     0,     0,     0,     0,    51,    36,     0,    38,    39,
       0,    41,    42,     0,    44,    52,    45,    46,    47,    48,
      49,     0,     0,     0,     0,    50,     0,     0,     0,     0,
       0,     0,   343,     0,     0,     0,     0,     0,     0,     0,
      36,    37,    52,     0,    40,    41,    42,    53,    44,     0,
      45,    46,    47,    48,    49,     0,     0,     0,     0,    50,
      37,    55,     0,    40,    41,    42,    51,    44,     0,    45,
      46,    47,    48,    49,    53,     0,    52,     0,    50,     0,
      54,     0,     0,     0,     0,    51,     0,     0,    55,    37,
       0,     0,    40,   295,     0,    52,    44,     0,    45,    46,
      47,    48,    49,     0,     0,     0,     0,    50,    53,     0,
       0,     0,     0,     0,    51,     0,     0,     0,     0,     0,
       0,     0,    55,     0,    52,    37,     0,    53,    40,    41,
       0,     0,    44,     0,    45,    46,    47,    48,    49,     0,
       0,    55,     0,    50,     0,     0,     0,     0,     0,     0,
      51,   711,     0,     0,     0,     0,    53,     0,     0,     0,
      52,     0,     0,     0,     0,     0,     0,     0,   295,     0,
      55,    44,   358,    45,    46,    47,    48,    49,     0,     0,
       0,     0,    50,     0,     0,     0,     0,     0,     0,    51,
       0,     0,    53,     0,     0,     0,     0,     0,     0,    52,
     146,     0,     0,     0,     0,     0,    55,     0,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   435,     0,   104,   105,
     106,    53,     0,     0,   290,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   147,   148,     0,   105,   106,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   503,     0,
     104,   105,   106,     0,     0,     0,   358,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   506,     0,     0,     0,     0,     0,     0,     0,   358,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
       0,     0,   104,   105,   106,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   524,     0,   104,   105,   106,     0,     0,
       0,   358,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   538,     0,     0,     0,
       0,     0,     0,     0,   358,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,     0,     0,   104,   105,   106,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   552,     0,
     104,   105,   106,     0,     0,     0,   358,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   560,     0,     0,     0,     0,     0,     0,     0,   358,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
      85,     0,   104,   105,   106,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   290,     0,   104,   105,   106,     0,     0,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   358,     0,   104,   105,   106,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   714,     0,   104,
     105,   106,     0,     0,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,     0,     0,
     104,   105,   106,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,     0,     0,   104,   105,   106
  };

  const short int
  SPARQLalgebraParser::yycheck_[] =
  {
      41,    43,    75,    51,    75,   159,    51,    50,    51,   162,
     344,    75,   141,   322,    13,   228,   327,    75,    75,    47,
     331,    75,    75,    47,    75,    57,   442,   443,    51,    22,
     297,   447,   448,    26,   450,    75,    75,    75,    59,    75,
     133,   308,    85,    98,   128,   128,   259,   106,    98,    95,
     697,    21,     0,    46,   701,   157,   115,    78,   163,   164,
     106,   144,   112,    98,    38,    39,   127,   483,   281,    39,
      98,   106,   165,   157,   158,   159,   343,   106,   106,    98,
     106,    51,   106,    98,   636,   637,    56,   106,    87,    98,
      98,   106,    62,   134,   106,     9,    10,   106,   106,    13,
     106,    15,    16,    17,    18,    19,   149,    75,   163,   164,
      24,    98,    98,    81,    82,    83,   159,    31,    86,   106,
     106,   106,   165,   175,   176,   168,    94,    41,   106,   157,
     158,   159,   100,   157,   158,   159,    20,   106,    98,    98,
     153,   154,   155,   156,    50,    51,   116,   106,   106,   119,
     484,   106,   568,   464,   570,   571,   106,   466,    98,    73,
     130,   472,   106,   106,   157,   158,   159,   106,   479,   106,
     437,   300,   106,    87,   106,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    14,    98,   227,   106,   229,   230,
     231,   232,   233,   234,   235,   236,   237,    98,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,    98,   254,   255,   256,   257,   258,   634,   260,
     261,   262,   263,    98,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,    98,
      98,   167,   285,   169,   170,   171,   172,   290,   174,   297,
     291,   177,   297,   159,   297,    98,    98,   330,    98,   593,
     308,    98,   162,   308,    98,   308,   157,   158,   159,    98,
      98,   344,   104,   344,   297,    98,    98,   320,    98,   322,
     344,   324,   325,   326,   327,   308,   344,   344,   331,   321,
     344,   344,   335,   344,   106,   343,   449,   564,   343,   106,
     343,    98,    98,   209,   344,   344,   344,    98,   344,    98,
     112,   157,   158,   159,   355,   358,    23,   163,   164,   225,
     343,   475,   106,   106,   591,    98,    98,    34,   369,    98,
      98,   372,   373,    98,    98,   376,    98,   378,    98,    98,
      98,   112,   112,   384,    98,    52,    98,    98,    55,    98,
     391,   392,    98,    98,    98,   396,   112,    98,    98,    98,
      98,    98,   112,    98,   112,   406,    98,    98,    98,   410,
      77,   412,    98,    98,   415,   416,   112,    98,   112,   420,
     421,    98,    98,   112,   112,    92,    93,   428,    98,   437,
      98,   297,   437,   434,   437,    98,   103,    98,    98,   442,
     443,   108,   308,   112,   447,   448,   112,   450,   106,    98,
      98,   484,    98,   484,   437,    98,   123,   124,    98,   572,
     484,   464,    98,   466,   106,    98,   484,   484,    98,   472,
     484,   484,   475,   484,    98,   158,   479,   343,    98,    98,
     483,   106,    98,    98,   484,   484,   484,   353,   484,   490,
      98,    98,   493,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,   508,   509,    98,
      47,    48,    49,    98,    10,    52,   106,    13,   519,    15,
      16,    17,    18,    19,    98,    98,    22,   528,    24,   530,
     162,   112,   112,    98,    98,    31,    98,    98,   539,   540,
      98,    98,    98,    98,   545,    41,    98,    98,   549,    98,
      46,    98,    59,   106,    98,    58,   564,   558,   559,   564,
     593,   564,   593,   106,    98,   568,   157,   570,   571,   593,
     107,   437,    98,    98,    98,   593,   593,    73,    98,   593,
     593,   564,   593,   591,    98,    98,   591,    98,   591,    98,
      66,    87,    98,   593,   593,   593,    98,   593,    59,    57,
     350,   318,   435,   140,   109,   142,    60,    57,   591,   475,
     600,   291,   645,    58,    61,    59,   580,   176,   193,   138,
     157,   300,   335,   718,   604,   607,    -1,   215,    -1,    -1,
      -1,   634,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      19,   653,    -1,    -1,   655,    24,    -1,   658,    -1,    -1,
      -1,    -1,    31,    -1,   201,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    -1,    -1,    -1,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      19,    -1,    -1,    22,    -1,    24,    -1,    -1,   564,    -1,
      -1,    -1,    31,    -1,    73,    -1,   707,   708,    -1,   710,
      79,   714,    41,    -1,    -1,   716,    -1,    46,    87,    -1,
      -1,    -1,    -1,    -1,    -1,   591,    -1,   264,    25,    -1,
      27,    28,    29,    30,    -1,    32,    33,   106,    35,    36,
      37,    38,    -1,    40,    73,    42,    43,    44,    45,    -1,
      79,    -1,    49,    50,    -1,    -1,    53,    54,    87,    -1,
      -1,    58,    -1,    60,    61,    -1,    63,    64,   305,    -1,
      67,    68,    69,    70,    71,    72,    -1,    74,    -1,    76,
     317,    -1,    -1,    80,   321,    -1,    -1,    84,    85,    -1,
      -1,    88,    89,    90,    91,    -1,    -1,    -1,    -1,    96,
      97,    -1,    99,    -1,   101,   102,    -1,    -1,   105,   346,
     107,    -1,   109,   110,   111,    -1,   113,   114,    -1,    -1,
     117,   118,    -1,   120,    -1,   122,    -1,    -1,    -1,   126,
      -1,    -1,   129,    -1,   131,   132,    -1,   134,   135,    -1,
      -1,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    -1,    27,    28,    29,    30,    -1,    32,    33,
     157,   158,   159,    37,    38,    -1,    40,    -1,    42,    43,
      44,    45,    -1,    -1,    -1,    49,    50,    -1,    -1,    53,
      54,    -1,    -1,    -1,    58,    -1,    60,    61,    -1,    63,
      64,    -1,    -1,    67,    68,    69,    70,    71,    72,    -1,
      74,    -1,    76,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    85,    -1,    -1,    88,    89,    90,    91,    -1,    -1,
      -1,    -1,    96,    97,    -1,    99,    -1,   101,   102,    -1,
     104,   105,    -1,   107,    -1,   109,   110,   111,    -1,   113,
     114,    -1,    -1,   117,   118,    -1,   120,    -1,   122,    -1,
      -1,    -1,   126,    -1,    -1,   129,    -1,   131,   132,    -1,
     134,   135,    -1,    -1,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    -1,    27,    28,    29,    30,
      -1,    32,    33,   157,   158,   159,    37,    38,    -1,    40,
      -1,    42,    43,    44,    45,    -1,    -1,    -1,    49,    50,
      -1,    -1,    53,    54,    -1,    -1,    57,    58,    -1,    60,
      61,    -1,    63,    64,    -1,    -1,    67,    68,    69,    70,
      71,    72,    -1,    74,    -1,    76,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    84,    85,    -1,    -1,    88,    89,    90,
      91,    -1,    -1,    -1,    -1,    96,    97,    -1,    99,    -1,
     101,   102,    -1,    -1,   105,    -1,   107,    -1,   109,   110,
     111,    -1,   113,   114,    -1,    -1,   117,   118,    -1,   120,
      -1,   122,    -1,    -1,    -1,   126,    -1,    -1,   129,    -1,
     131,   132,    -1,   134,   135,    -1,    -1,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,    27,
      28,    29,    30,    -1,    32,    33,   157,   158,   159,    37,
      38,    -1,    40,    -1,    42,    43,    44,    45,    -1,    -1,
      -1,    49,    50,    -1,    -1,    53,    54,    -1,    -1,    -1,
      58,    -1,    60,    61,    -1,    63,    64,    -1,    -1,    67,
      68,    69,    70,    71,    72,    -1,    74,    -1,    76,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    84,    85,    -1,    -1,
      88,    89,    90,    91,    -1,    -1,    -1,    -1,    96,    97,
      -1,    99,    -1,   101,   102,    -1,    -1,   105,    -1,   107,
      -1,   109,   110,   111,    -1,   113,   114,    -1,    -1,   117,
     118,    -1,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,
      -1,   129,    -1,   131,   132,    -1,   134,   135,    -1,    -1,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,
     158,   159,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    15,    16,    17,    18,    19,    -1,    22,
      23,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    55,    -1,    -1,    -1,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      19,    73,    -1,    -1,    77,    24,    -1,    79,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    87,    -1,    -1,    -1,    92,
      93,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     103,    -1,    -1,    -1,   106,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     123,   124,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,     5,
       6,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    19,    -1,    -1,    -1,   106,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    31,     5,    -1,     7,     8,
      -1,    10,    11,    -1,    13,    41,    15,    16,    17,    18,
      19,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       5,     6,    41,    -1,     9,    10,    11,    73,    13,    -1,
      15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    24,
       6,    87,    -1,     9,    10,    11,    31,    13,    -1,    15,
      16,    17,    18,    19,    73,    -1,    41,    -1,    24,    -1,
      79,    -1,    -1,    -1,    -1,    31,    -1,    -1,    87,     6,
      -1,    -1,     9,    10,    -1,    41,    13,    -1,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,    24,    73,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    -1,    41,     6,    -1,    73,     9,    10,
      -1,    -1,    13,    -1,    15,    16,    17,    18,    19,    -1,
      -1,    87,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    85,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,
      87,    13,   106,    15,    16,    17,    18,    19,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      95,    -1,    -1,    -1,    -1,    -1,    87,    -1,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,    98,    -1,   162,   163,
     164,    73,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    -1,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,    -1,   163,   164,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,    98,    -1,
     162,   163,   164,    -1,    -1,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
      -1,    -1,   162,   163,   164,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,    98,    -1,   162,   163,   164,    -1,    -1,
      -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,    -1,    -1,   162,   163,   164,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,    98,    -1,
     162,   163,   164,    -1,    -1,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     106,    -1,   162,   163,   164,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   106,    -1,   162,   163,   164,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   106,    -1,   162,   163,   164,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   106,    -1,   162,
     163,   164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,    -1,    -1,
     162,   163,   164,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,    -1,    -1,   162,   163,   164
  };

  const unsigned short int
  SPARQLalgebraParser::yystos_[] =
  {
       0,   106,   167,   168,   169,   170,   171,   173,   174,   175,
     176,   177,   178,   179,   180,   187,   195,   196,   197,   200,
     201,   206,   208,   209,   210,   211,   243,   245,   253,   255,
     257,   258,   259,   260,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    15,    16,    17,    18,    19,
      24,    31,    41,    73,    79,    87,   106,   172,   181,   182,
     189,   212,   213,   214,   216,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   232,   246,     0,   157,   106,   106,
     106,   106,   175,   175,   106,   106,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   162,   163,   164,   250,   276,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   291,   293,   294,   304,   305,   309,   310,   311,   312,
     313,   314,   315,   316,   106,   106,   196,   106,   244,   252,
     245,   245,   245,   275,   276,   315,    95,   160,   161,   274,
     276,   277,   305,   309,   313,   315,   317,   245,   127,   217,
     128,   144,   207,   273,    20,    22,    23,    34,    46,    52,
      55,    77,    92,    93,   103,   108,   123,   124,   106,   173,
     180,   232,   106,   170,   210,   106,   171,   211,   106,   179,
      98,   106,   213,   106,   187,   194,   195,   200,   201,   206,
     243,   248,   253,   255,   257,   258,   259,   260,   186,   188,
     190,    98,    98,   106,   192,   198,    25,    27,    28,    29,
      30,    32,    33,    37,    38,    40,    42,    43,    44,    45,
      49,    50,    53,    54,    58,    60,    61,    63,    64,    67,
      68,    69,    70,    71,    72,    74,    76,    80,    84,    85,
      88,    89,    90,    91,    96,    97,    99,   101,   102,   104,
     105,   107,   109,   110,   111,   113,   114,   117,   118,   120,
     122,   126,   129,   131,   132,   134,   135,   138,   139,   140,
     141,   315,   245,   106,   178,   133,   165,   306,   307,   308,
     106,   202,   203,   205,   278,    10,    98,    14,    98,   252,
     245,   106,   250,   254,   245,   256,    47,   106,   264,   265,
     266,   267,   268,   270,   271,   315,   245,   275,   207,    98,
     315,   227,   217,   315,   217,   217,   217,   217,   236,   238,
     240,   217,   237,   238,   237,   217,    98,    98,    98,    98,
      98,    98,    98,    31,   246,   245,   247,    98,   106,   183,
      98,   276,    98,   106,   191,   162,    98,   192,   106,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   276,   251,
     278,   278,   251,   278,   278,   278,   278,   278,   278,   278,
     278,   290,   278,    95,   106,   261,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
      98,   278,   278,   278,   278,   278,   251,   278,   278,   278,
     278,   245,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,    98,   251,    98,
      98,   315,    35,    36,   204,    98,   203,   274,   254,    98,
      98,   245,    21,    39,    51,    56,    62,   116,   119,   130,
     269,   274,    98,   245,   106,   174,   315,   106,   232,   245,
     234,   315,    98,   128,   233,   315,   315,    22,    26,    46,
     234,   235,   233,    98,   106,   115,   239,   241,   243,   233,
      98,    98,   235,   274,   248,    98,   245,   184,   106,   176,
     276,   278,   106,   112,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,   278,    98,    98,   278,   112,   112,
     278,    98,   278,    98,    98,    98,   278,    98,    98,   112,
      98,    98,    98,   278,    98,   278,    98,    98,   112,   278,
     112,    98,    98,    98,    98,    98,    98,    98,    98,   112,
     112,    98,   278,    98,   278,   112,    98,   278,   278,   112,
      98,    98,    98,   278,   278,    98,    98,    98,   112,   112,
      98,   278,   106,   177,   274,    98,    98,   264,   264,   264,
     272,   264,   207,   264,    98,    98,    98,    98,   106,   229,
     230,   231,    98,   233,   215,   234,    98,   233,   275,   233,
      98,   264,   248,   249,   158,    98,   278,    98,   106,   193,
     199,   278,    98,   278,   278,    98,    98,   263,   278,    98,
      98,   278,    98,   278,   278,   278,    98,    98,   278,    98,
      98,   278,    98,    98,   278,   278,    98,    98,   274,    98,
     264,    98,   264,   264,   207,    98,    59,    78,    98,   106,
     228,   231,    98,    98,    98,   242,    98,   274,    98,   248,
     185,    98,   162,    98,   193,   112,   262,   292,   112,   292,
      98,   262,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,   264,   236,   236,   243,    98,   157,
     106,   295,   196,   278,    98,   278,    98,    98,    98,    98,
      98,    75,    81,    82,    83,    86,    94,   100,   296,   297,
     300,   301,   302,    98,    98,    98,    66,   298,   298,    98,
     298,    85,   278,   299,   106,   278,   303,   278,    57,   278,
     314,    98
  };

  const unsigned short int
  SPARQLalgebraParser::yyr1_[] =
  {
       0,   166,   167,   167,   168,   169,   169,   170,   170,   171,
     171,   171,   171,   172,   172,   173,   173,   174,   174,   175,
     175,   176,   176,   177,   177,   178,   178,   179,   179,   180,
     181,   182,   184,   185,   183,   186,   186,   187,   188,   188,
     189,   190,   190,   191,   192,   193,   194,   194,   194,   194,
     194,   195,   195,   196,   197,   198,   198,   199,   199,   200,
     201,   202,   202,   203,   203,   204,   204,   205,   206,   207,
     207,   208,   209,   209,   210,   210,   211,   212,   212,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     214,   215,   215,   216,   217,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   227,   228,   228,   229,
     229,   230,   231,   232,   232,   233,   233,   234,   235,   235,
     235,   235,   236,   237,   238,   239,   239,   240,   240,   242,
     241,   243,   243,   244,   244,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   246,   246,   247,   247,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   249,   249,
     250,   251,   251,   252,   253,   253,   254,   254,   256,   255,
     257,   258,   259,   260,   261,   261,   262,   263,   263,   264,
     264,   264,   264,   264,   264,   265,   266,   267,   268,   268,
     269,   269,   269,   270,   270,   271,   272,   272,   273,   274,
     274,   275,   275,   276,   276,   277,   277,   277,   277,   277,
     277,   278,   278,   278,   278,   278,   278,   279,   280,   281,
     282,   282,   283,   283,   283,   283,   283,   283,   283,   284,
     285,   285,   286,   286,   287,   287,   287,   288,   288,   288,
     288,   288,   288,   288,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   290,   290,   291,   292,   292,   293,
     294,   295,   296,   296,   296,   297,   298,   298,   299,   299,
     300,   301,   301,   301,   301,   301,   302,   302,   303,   304,
     304,   305,   306,   307,   307,   308,   308,   309,   309,   309,
     310,   310,   310,   311,   311,   311,   312,   312,   312,   313,
     313,   314,   314,   314,   314,   315,   315,   316,   316,   317,
     317
  };

  const unsigned char
  SPARQLalgebraParser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     4,     1,     4,     1,     4,
       4,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     1,     1,     4,
       2,     4,     0,     0,     6,     0,     2,     7,     0,     2,
       4,     0,     2,     4,     4,     4,     1,     1,     1,     1,
       1,     4,     4,     1,    10,     1,     2,     1,     2,     5,
       7,     1,     2,     1,     1,     1,     1,     4,     6,     1,
       1,     1,     4,     1,     4,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       6,     0,     1,     5,     0,     1,     5,     5,     6,     6,
       6,     4,     4,     4,     6,     0,     2,     0,     1,     2,
       1,     4,     4,     4,     5,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     2,     0,
       4,     4,     4,     1,     2,     1,     1,     5,     1,     1,
       1,     1,     1,     6,     1,     1,     1,     2,     1,     1,
       5,     1,     1,     1,     1,     1,     6,     1,     1,     2,
       4,     1,     2,     6,     6,     5,     0,     1,     0,     6,
       6,     5,     5,     5,     1,     4,     2,     0,     2,     1,
       1,     1,     1,     1,     1,     5,     5,     4,     4,     6,
       1,     1,     1,     1,     1,     4,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     5,     1,
       1,     1,     5,     5,     5,     5,     5,     5,     4,     1,
       5,     5,     5,     5,     4,     4,     4,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     6,     4,     4,     4,
       4,     4,     3,     4,     4,     4,     4,     4,     1,     4,
       4,     4,     4,     6,     6,     6,     6,     6,     4,     4,
       4,     4,     4,     4,     4,     4,     3,     4,     4,     4,
       4,     4,     4,     8,     6,     6,     6,     4,     4,     4,
       4,     4,     1,     1,     0,     1,     7,     0,     1,     7,
       4,     3,     1,     1,     1,     3,     0,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     3,     4,     4,     1,
       4,     2,     2,     1,     1,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const SPARQLalgebraParser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "IT_base", "IT_prefix",
  "IT_project", "IT_extend", "IT_distinct", "IT_reduced", "IT_group",
  "IT_filter", "IT_order", "IT_ask", "IT_bgp", "IT_triple", "IT_join",
  "IT_sequence", "IT_leftjoin", "IT_optional", "IT_union", "IT_unit",
  "IT_reverse", "IT_named", "IT_modify", "IT_graph", "IT_substr", "IT_all",
  "IT_lcase", "IT_ucase", "IT_sha256", "IT_round", "IT_path", "IT_seconds",
  "IT_str", "IT_create", "IT_asc", "IT_desc", "IT_floor", "IT_minutes",
  "IT_alt", "IT_bound", "IT_minus", "IT_in", "IT_hours", "IT_concat",
  "GT_AND", "IT_default", "IT_a", "TriplesSameSubject", "IT_if",
  "IT_regex", "GT_path_PLUS", "IT_add", "GT_GE", "IT_ceil", "IT_load",
  "GT_path_TIMES", "IT_separator", "GT_GT", "IT_insert", "IT_isnumeric",
  "IT_bnode", "GT_path_OPT", "IT_abs", "IT_coalesce", "GT_RCURLEY",
  "IT_DISTINCT", "IT_strlen", "IT_contains", "GT_NOT", "IT_isliteral",
  "IT_uri", "GT_NEQUAL", "IT_service", "GT_PLUS", "IT_MIN", "IT_isblank",
  "IT_drop", "IT_delete", "IT_slice", "IT_sha512", "IT_MAX", "IT_SUM",
  "IT_COUNT", "IT_strlang", "GT_TIMES", "IT_AVG", "IT_table",
  "IT_strstarts", "IT_iri", "IT_sha384", "IT_now", "IT_move",
  "IT_deletewhere", "IT_SAMPLE", "NIL", "IT_day", "IT_isuri", "GT_RPAREN",
  "IT_encode_for_uri", "IT_GROUP_CONCAT", "IT_tz", "IT_timezone",
  "IT_copy", "IT_exprlist", "IT_strdt", "GT_LPAREN", "IT_strends",
  "IT_deletedata", "IT_month", "GT_OR", "IT_exists", "GT_COMMA", "GT_LE",
  "IT_sameterm", "IT_quads", "IT_notoneof", "IT_year", "GT_EQUAL",
  "IT_seq", "GT_LT", "GT_LCURLEY", "IT_langmatches", "IT_insertdata",
  "IT_clear", "GT_DOT", "IT_isiri", "IT_silent", "IT__", "IT_datatype",
  "IT_mod", "GT_MINUS", "GT_DIVIDE", "GT_DTYPE", "IT_lang", "IT_sha1",
  "IT_uuid", "IT_struuid", "IT_md5", "IT_strbefore", "IT_strafter",
  "IT_rand", "IT_true", "IT_false", "INTEGER", "DECIMAL", "DOUBLE",
  "INTEGER_POSITIVE", "DECIMAL_POSITIVE", "DOUBLE_POSITIVE",
  "INTEGER_NEGATIVE", "DECIMAL_NEGATIVE", "DOUBLE_NEGATIVE",
  "STRING_LITERAL1", "STRING_LITERAL_LONG1", "STRING_LITERAL2",
  "STRING_LITERAL_LONG2", "IRI_REF", "PNAME_NS", "PNAME_LN",
  "BLANK_NODE_LABEL", "ANON", "POSITION", "VAR1", "VAR2", "LANGTAG",
  "$accept", "Top", "QueryUnit", "Query", "PrefixOpt", "UsingOpt",
  "_QUsingClause_E_Plus", "SliceOpt", "DistinctOpt", "ProjectOpt",
  "OrderOpt", "HavingOpt", "ExtendOpt", "GroupOpt", "AskQuery", "BaseDecl",
  "PrefixDecl",
  "_O_QGT_LPAREN_E_S_QPNAME_NS_E_S_QIRI_REF_E_S_QGT_RPAREN_E_C", "$@1",
  "$@2",
  "_Q_O_QGT_LPAREN_E_S_QPNAME_NS_E_S_QIRI_REF_E_S_QGT_RPAREN_E_C_E_Star",
  "Project", "_QVar_E_Star", "Extend", "_QBinding_E_Star", "Binding",
  "GroupExpression", "ProjectExpression", "SubSelect", "DistinctReduced",
  "WhereClause", "GroupClause", "_QGroupExpression_E_Plus",
  "_QProjectExpression_E_Plus", "HavingClause", "OrderClause",
  "_QOrderCondition_E_Plus", "OrderCondition",
  "_O_QIT_asc_E_Or_QIT_desc_E_C",
  "_O_QGT_LPAREN_E_S_QIT_asc_E_Or_QIT_desc_E_S_QExpression_E_S_QGT_RPAREN_E_C",
  "Slice", "_O_QInteger_E_Or_QIT___E_C", "UpdateUnit", "Update_Base",
  "Update_Prefix", "Updates", "_QUpdate1_E_Plus", "Update1", "Load",
  "_QGraphRef_E_Opt", "Clear", "_QIT_silent_E_Opt", "Drop", "Create",
  "Add", "Move", "Copy", "InsertData", "DeleteData", "DeleteWhere",
  "Modify", "_QUsingClause_E_Star", "_QInsertClause_E_Opt",
  "_O_QDeleteClause_E_S_QInsertClause_E_Opt_Or_QInsertClause_E_C",
  "DeleteClause", "InsertClause", "UsingClause", "GraphOrDefault",
  "GraphRef", "GraphRefAll", "QuadPattern", "QuadData", "Quads",
  "_O_QQuadsNotTriples_E_Or_QTriplesTemplate_E_C",
  "_Q_O_QQuadsNotTriples_E_Or_QTriplesTemplate_E_C_E_Star",
  "QuadsNotTriples", "@3", "TriplesTemplate", "_QMyTriple_E_Plus",
  "GroupGraphPatternNoSub", "_O_QIT_join_E_Or_QIT_sequence_E_C",
  "_QGroupGraphPatternNoSub_E_Plus", "GroupGraphPatternSub",
  "_QGroupGraphPatternSub_E_Plus", "ExprList", "_QExpression_E_Plus",
  "MyTriple", "OptionalGraphPattern", "_QExprList_E_Opt",
  "GraphGraphPattern", "@4", "ServiceGraphPattern", "MinusGraphPattern",
  "GroupOrUnionGraphPattern", "Filter", "ExpressionList",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "Path", "PathAlternative",
  "PathSequence", "PathEltOrInverse", "PathMod",
  "_O_QGT_path_OPT_E_Or_QGT_path_TIMES_E_Or_QGT_path_PLUS_E_C",
  "PathPrimary", "PathOneInPropertySet", "_QPath_E_Plus", "Integer",
  "VarOrTerm", "VarOrIRIref", "Var", "GraphTerm", "Expression",
  "ConditionalOrExpression", "ConditionalAndExpression", "ValueLogical",
  "RelationalExpression", "RelativeExpression", "NumericExpression",
  "AdditiveExpression", "MultiplicativeExpression", "UnaryExpression",
  "PrimaryExpression", "BuiltInCall", "_QExpression_E_Opt",
  "RegexExpression", "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Opt",
  "SubstringExpression", "ExistsFunc", "Aggregate",
  "_O_QCount_E_Or_QMiscAgg_E_Or_QGroupConcat_E_C", "Count",
  "_QIT_DISTINCT_E_Opt", "_O_QGT_TIMES_E_Or_QExpression_E_C", "MiscAgg",
  "_O_QIT_SUM_E_Or_QIT_MIN_E_Or_QIT_MAX_E_Or_QIT_AVG_E_Or_QIT_SAMPLE_E_C",
  "GroupConcat", "Separator", "IRIrefOrFunction", "RDFLiteral",
  "_O_QGT_DTYPE_E_S_QIRIref_E_C",
  "_O_QLANGTAG_E_Or_QGT_DTYPE_E_S_QIRIref_E_C",
  "_Q_O_QLANGTAG_E_Or_QGT_DTYPE_E_S_QIRIref_E_C_E_Opt", "NumericLiteral",
  "NumericLiteralUnsigned", "NumericLiteralPositive",
  "NumericLiteralNegative", "BooleanLiteral", "String", "IRIref",
  "PrefixedName", "BlankNode", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  SPARQLalgebraParser::yyrline_[] =
  {
       0,   335,   335,   338,   344,   348,   351,   355,   358,   362,
     365,   368,   371,   377,   380,   387,   388,   395,   396,   403,
     404,   411,   412,   419,   420,   427,   431,   437,   438,   446,
     452,   458,   462,   464,   462,   472,   474,   478,   485,   488,
     495,   500,   502,   506,   510,   514,   520,   521,   522,   523,
     524,   528,   532,   562,   568,   575,   576,   580,   581,   587,
     596,   603,   607,   614,   615,   622,   626,   632,   639,   646,
     649,   669,   673,   676,   680,   683,   687,   693,   697,   706,
     707,   708,   709,   710,   711,   712,   713,   714,   715,   716,
     720,   726,   729,   735,   741,   744,   752,   760,   768,   776,
     784,   792,   800,   808,   816,   822,   825,   832,   835,   839,
     843,   852,   860,   868,   871,   879,   882,   888,   894,   895,
     898,   901,   909,   913,   917,   923,   924,   928,   931,   938,
     938,   948,   951,   957,   961,   968,   969,   970,   974,   975,
     976,   977,   978,   979,   986,   987,   991,   995,  1002,  1003,
    1004,  1008,  1009,  1010,  1011,  1012,  1013,  1017,  1023,  1027,
    1034,  1040,  1043,  1050,  1064,  1078,  1092,  1095,  1099,  1099,
    1109,  1117,  1126,  1135,  1151,  1154,  1161,  1167,  1170,  1218,
    1219,  1220,  1221,  1222,  1223,  1227,  1233,  1241,  1247,  1250,
    1256,  1257,  1258,  1262,  1265,  1273,  1279,  1280,  1287,  1304,
    1307,  1311,  1314,  1320,  1321,  1325,  1328,  1329,  1332,  1335,
    1336,  1342,  1343,  1344,  1345,  1346,  1347,  1351,  1360,  1369,
    1373,  1374,  1378,  1381,  1384,  1387,  1390,  1393,  1396,  1404,
    1408,  1414,  1428,  1434,  1443,  1446,  1449,  1455,  1456,  1457,
    1460,  1463,  1466,  1469,  1480,  1483,  1486,  1489,  1492,  1495,
    1498,  1501,  1504,  1507,  1510,  1513,  1516,  1519,  1522,  1523,
    1526,  1529,  1532,  1535,  1538,  1541,  1544,  1547,  1550,  1553,
    1556,  1559,  1562,  1565,  1568,  1571,  1574,  1577,  1580,  1583,
    1586,  1589,  1592,  1596,  1599,  1602,  1605,  1608,  1611,  1614,
    1617,  1620,  1623,  1624,  1628,  1631,  1637,  1643,  1646,  1650,
    1656,  1668,  1672,  1673,  1674,  1678,  1684,  1687,  1693,  1696,
    1700,  1706,  1709,  1712,  1715,  1718,  1724,  1727,  1733,  1737,
    1740,  1746,  1753,  1759,  1763,  1770,  1774,  1778,  1779,  1780,
    1784,  1785,  1786,  1790,  1791,  1792,  1796,  1797,  1798,  1802,
    1803,  1807,  1808,  1809,  1810,  1814,  1815,  1819,  1820,  1824,
    1825
  };

  // Print the state stack on the debug stream.
  void
  SPARQLalgebraParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  SPARQLalgebraParser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  SPARQLalgebraParser::token_number_type
  SPARQLalgebraParser::yytranslate_ (int t)
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
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165
    };
    const unsigned int user_token_number_max_ = 420;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // w3c_sw
#line 3708 "lib/SPARQLalgebraParser.cpp" // lalr1.cc:1155
#line 1830 "lib/SPARQLalgebraParser.ypp" // lalr1.cc:1156
 /*** Additional Code ***/

void w3c_sw::SPARQLalgebraParser::error(const SPARQLalgebraParser::location_type& l,
				    const std::string& constM)
{
    driver.error(l, constM);
}

/* START Driver (@@ stand-alone would allow it to be shared with other parsers */

namespace w3c_sw {

    SPARQLalgebraDriver::SPARQLalgebraDriver (std::string baseURI, AtomFactory* atomFactory) : 
	YaccDriver(baseURI, atomFactory), curSubject(NULL), curPredicate(NULL), 
	curFilter(NULL), 
	curResultSet(NULL), curResult(NULL), curExprList(NULL), 
	root(NULL), unnestTree(false)
{
}

    SPARQLalgebraDriver::~SPARQLalgebraDriver ()
{
}

const Operation* SPARQLalgebraDriver::parse (IStreamContext& in)
{
    root = NULL;
    curGraphName = NULL;
    streamname = in.nameStr;
    // clear prefixes for nth run but keep them around for e.g. serialization.
    clearPrefixes();

    SPARQLalgebraScanner scanner(this, in.p);
    scanner.set_debug(trace_scanning);
    lexer = &scanner;

    SPARQLalgebraParser parser(*this);
    parser.set_debug_level(trace_parsing);
    // !!! Clear out namespaces!
    ignorePrefixFlag = false;
    parser.parse();
    return root;
}

const Operation* SPARQLalgebraDriver::parse (std::string queryStr)
{
    IStreamContext in(queryStr.c_str(), IStreamContext::STRING);
    return parse(in);
}

void SPARQLalgebraDriver::executeSelect (IStreamContext& in, RdfDB* db, ResultSet* rs) {
    parse(in);
    root->execute(db, rs);
    delete root;
    root = NULL;
}
void SPARQLalgebraDriver::executeSelect (std::string queryStr, RdfDB* db, ResultSet* rs) {
    parse(queryStr);
    root->execute(db, rs);
    delete root;
    root = NULL;
}


} // namespace w3c_sw

/* END Driver */

