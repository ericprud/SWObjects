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

#line 39 "lib/SQLParser.cpp" // lalr1.cc:399

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "SQLParser.hpp"

// User implementation prologue.
#line 240 "lib/SQLParser.ypp" // lalr1.cc:407

#include "SQLScanner.hpp"
#line 320 "lib/SQLParser.ypp" // lalr1.cc:407

#include <stdarg.h>
#include "SQL.hpp"
#include "SQLScanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex

#line 67 "lib/SQLParser.cpp" // lalr1.cc:407


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
#line 153 "lib/SQLParser.cpp" // lalr1.cc:474

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
  SQLParser::SQLParser (class SQLDriver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

  SQLParser::~SQLParser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  SQLParser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  SQLParser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  SQLParser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    value = other.value;
  }


  template <typename Base>
  inline
  SQLParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  SQLParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  inline
  SQLParser::basic_symbol<Base>::~basic_symbol ()
  {
  }

  template <typename Base>
  inline
  void
  SQLParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  inline
  SQLParser::by_type::by_type ()
     : type (empty)
  {}

  inline
  SQLParser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  SQLParser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  SQLParser::by_type::move (by_type& that)
  {
    type = that.type;
    that.type = empty;
  }

  inline
  int
  SQLParser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  SQLParser::by_state::by_state ()
    : state (empty)
  {}

  inline
  SQLParser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  SQLParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
  SQLParser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  SQLParser::symbol_number_type
  SQLParser::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
  SQLParser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  SQLParser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    value = that.value;
    // that is emptied.
    that.type = empty;
  }

  inline
  SQLParser::stack_symbol_type&
  SQLParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  SQLParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  SQLParser::yy_print_ (std::ostream& yyo,
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
  SQLParser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  SQLParser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  SQLParser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
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
#endif // YYDEBUG

  inline SQLParser::state_type
  SQLParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  SQLParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  SQLParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  SQLParser::parse ()
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
    #line 32 "lib/SQLParser.ypp" // lalr1.cc:725
{
    // initialize the initial location object
    yyla.location.begin.filename = yyla.location.end.filename = &driver.streamname;
}

#line 497 "lib/SQLParser.cpp" // lalr1.cc:725

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
#line 336 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	driver.root = (yystack_[1].value.p_Select);
    }
#line 613 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 14:
#line 365 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	driver.curCreate = driver.tables[*(yystack_[0].value.p_NAME)];
	delete (yystack_[0].value.p_NAME);
      }
#line 622 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 15:
#line 368 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	  driver.curCreate = NULL;
    }
#line 630 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 26:
#line 402 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	driver.curCreate = new sql::schema::Relation(*(yystack_[0].value.p_NAME));
      }
#line 638 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 27:
#line 404 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	  driver.tables[*(yystack_[6].value.p_NAME)] = driver.curCreate;
	  delete (yystack_[6].value.p_NAME);
	  driver.curCreate = NULL;
      }
#line 648 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 33:
#line 426 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	driver.curCreate = new sql::schema::Relation(*(yystack_[2].value.p_NAME));
	driver.inserts.push_back(new sql::Insert(*(yystack_[2].value.p_NAME), (yystack_[1].value.p_Attributes), (yystack_[0].value.p_RValue)));
	delete (yystack_[2].value.p_NAME);
    }
#line 658 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 34:
#line 434 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Attributes) = NULL;
    }
#line 666 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 36:
#line 441 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	w3c_sw_LINEN << "ignoring non-standard inserts\n";
    }
#line 674 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 39:
#line 452 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_RValue) = new sql::RConstants((yystack_[1].value.p_Expressions));
    }
#line 682 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 40:
#line 455 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_RValue) = new sql::RSelection((yystack_[0].value.p_Select));
    }
#line 690 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 41:
#line 461 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	w3c_sw_LINEN << "ignoring parameters\n";
    }
#line 698 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 47:
#line 481 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	driver.curAttributeName = (yystack_[0].value.p_NAME);
    }
#line 706 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 48:
#line 483 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	sql::schema::Field* f = new sql::schema::Field(*(yystack_[2].value.p_NAME), parser::DataTypeProxy((yystack_[0].value.p_TypeSize).type), (yystack_[0].value.p_TypeSize).size);
	driver.curCreate->addField(f);
    }
#line 715 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 49:
#line 486 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	driver.curAttributeName = NULL;
	delete (yystack_[4].value.p_NAME);
    }
#line 724 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 51:
#line 491 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	driver.curCreate->setPrimaryKey(new sql::schema::PrimaryKey((yystack_[0].value.p_Attributes)));
    }
#line 732 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 52:
#line 494 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	driver.curCreate->addUniqueKey(new sql::schema::Key((yystack_[0].value.p_Attributes)));
    }
#line 740 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 59:
#line 515 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	driver.curCreate->addForeignKey(new sql::schema::ForeignKey((yystack_[3].value.p_Attributes), *(yystack_[1].value.p_NAME), new sql::schema::Key((yystack_[0].value.p_Attributes))));
	delete (yystack_[1].value.p_NAME);
    }
#line 749 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 60:
#line 521 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	w3c_sw_LINEN << "ignoring constraint name\n";
    }
#line 757 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 63:
#line 532 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_TypeSize).type = (yystack_[1].value.p_SchemaDatatype);
	(yylhs.value.p_TypeSize).size = (yystack_[0].value.p_int);
    }
#line 766 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 64:
#line 539 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yystack_[1].value.p_Expression));
	(yylhs.value.p_int) = i->getValue();
	delete (yystack_[1].value.p_Expression);
    }
#line 776 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 65:
#line 547 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_int) = SQL_PRECISION_unspecified;
    }
#line 784 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 67:
#line 554 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_SchemaDatatype).parser::NoCtorDataType::make(sql::DataType::TYPENAME_char, (yystack_[2].value.p_Nationality), (yystack_[0].value.p_Variability));
    }
#line 792 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 68:
#line 557 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_SchemaDatatype).parser::NoCtorDataType::make(sql::DataType::TYPENAME_char, sql::DataType::VARIABILITY_varying);
    }
#line 800 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 69:
#line 560 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_SchemaDatatype).parser::NoCtorDataType::make(sql::DataType::TYPENAME_binary, (yystack_[0].value.p_Variability));
    }
#line 808 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 70:
#line 563 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_SchemaDatatype).parser::NoCtorDataType::make(sql::DataType::TYPENAME_binary, sql::DataType::VARIABILITY_varying);
    }
#line 816 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 71:
#line 566 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_SchemaDatatype).parser::NoCtorDataType::make(sql::DataType::TYPENAME_int);
    }
#line 824 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 72:
#line 569 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_SchemaDatatype).parser::NoCtorDataType::make(sql::DataType::TYPENAME_int);
    }
#line 832 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 73:
#line 572 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_SchemaDatatype).parser::NoCtorDataType::make(sql::DataType::TYPENAME_int);
    }
#line 840 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 74:
#line 575 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_SchemaDatatype).parser::NoCtorDataType::make(sql::DataType::TYPENAME_int);
    }
#line 848 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 75:
#line 578 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_SchemaDatatype).parser::NoCtorDataType::make(sql::DataType::TYPENAME_int);
    }
#line 856 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 76:
#line 581 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_SchemaDatatype).parser::NoCtorDataType::make(sql::DataType::TYPENAME_float);
    }
#line 864 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 77:
#line 584 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_SchemaDatatype).parser::NoCtorDataType::make(sql::DataType::TYPENAME_real);
    }
#line 872 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 78:
#line 587 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_SchemaDatatype).parser::NoCtorDataType::make(sql::DataType::TYPENAME_double);
    }
#line 880 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 79:
#line 590 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_SchemaDatatype).parser::NoCtorDataType::make(sql::DataType::TYPENAME_boolean);
    }
#line 888 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 80:
#line 593 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_SchemaDatatype).parser::NoCtorDataType::make(sql::DataType::TYPENAME_date);
    }
#line 896 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 81:
#line 596 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_SchemaDatatype).parser::NoCtorDataType::make(sql::DataType::TYPENAME_time);
    }
#line 904 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 82:
#line 599 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_SchemaDatatype).parser::NoCtorDataType::make(sql::DataType::TYPENAME_timestamp);
    }
#line 912 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 83:
#line 602 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_SchemaDatatype).parser::NoCtorDataType::make(sql::DataType::TYPENAME_datetime);
    }
#line 920 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 84:
#line 605 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_SchemaDatatype).parser::NoCtorDataType::make(sql::DataType::TYPENAME_interval);
    }
#line 928 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 85:
#line 611 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Nationality) = sql::DataType::NATIONALITY_domestic;
    }
#line 936 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 86:
#line 614 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Nationality) = sql::DataType::NATIONALITY_national;
    }
#line 944 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 89:
#line 625 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Variability) = sql::DataType::VARIABILITY_varying;
    }
#line 952 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 90:
#line 628 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Variability) = sql::DataType::VARIABILITY_blob;
    }
#line 960 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 91:
#line 634 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Variability) = sql::DataType::VARIABILITY_fixed;
    }
#line 968 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 95:
#line 646 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	std::vector<sql::Attribute>* attrs = new std::vector<sql::Attribute>();
	attrs->push_back(*driver.curAttributeName);
	driver.curCreate->setPrimaryKey(new sql::schema::PrimaryKey(attrs));
    }
#line 978 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 96:
#line 651 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	w3c_sw_LINEN << "ignoring DEFAULT\n";
    }
#line 986 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 97:
#line 654 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	w3c_sw_LINEN << "ignoring NOT NULL\n";
    }
#line 994 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 98:
#line 657 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	std::vector<sql::Attribute>* attrs = new std::vector<sql::Attribute>();
	attrs->push_back(*driver.curAttributeName);
	driver.curCreate->addUniqueKey(new sql::schema::Key(attrs));
    }
#line 1004 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 99:
#line 662 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	std::vector<sql::Attribute>* attrs = new std::vector<sql::Attribute>();
	attrs->push_back(sql::Attribute(*driver.curAttributeName));
	sql::schema::ForeignKey* fk = new sql::schema::ForeignKey(attrs, *(yystack_[1].value.p_NAME), new sql::schema::Key((yystack_[0].value.p_Attributes)));
	driver.curCreate->addForeignKey(fk);
	delete (yystack_[1].value.p_NAME);
    }
#line 1016 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 100:
#line 672 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new sql::IsNullConstraint();
    }
#line 1024 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 105:
#line 679 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new sql::CastConstraint((yystack_[3].value.p_Expression), parser::DataTypeProxy((yystack_[1].value.p_TypeSize).type), (yystack_[1].value.p_TypeSize).size);
    }
#line 1032 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 106:
#line 685 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yystack_[1].value.p_Attributes)->insert((yystack_[1].value.p_Attributes)->begin(), *(yystack_[2].value.p_NAME));
	delete (yystack_[2].value.p_NAME);
	(yylhs.value.p_Attributes) = (yystack_[1].value.p_Attributes);
}
#line 1042 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 107:
#line 693 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_NAME) = (yystack_[0].value.p_NAME);
}
#line 1050 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 108:
#line 699 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Attributes) = new std::vector<sql::Attribute>();
    }
#line 1058 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 109:
#line 702 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yystack_[1].value.p_Attributes)->push_back(*(yystack_[0].value.p_NAME));
	delete (yystack_[0].value.p_NAME);
	(yylhs.value.p_Attributes) = (yystack_[1].value.p_Attributes);
    }
#line 1068 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 110:
#line 710 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yystack_[1].value.p_Expressions)->insert((yystack_[1].value.p_Expressions)->begin(), (yystack_[2].value.p_Expression));
	(yylhs.value.p_Expressions) = (yystack_[1].value.p_Expressions);
}
#line 1077 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 111:
#line 717 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = (yystack_[0].value.p_Expression);
    }
#line 1085 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 112:
#line 723 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expressions) = new std::vector<const sql::Expression*>();
    }
#line 1093 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 113:
#line 726 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yystack_[1].value.p_Expressions)->push_back((yystack_[0].value.p_Expression));
	(yylhs.value.p_Expressions) = (yystack_[1].value.p_Expressions);
    }
#line 1102 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 114:
#line 733 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	if ((yystack_[0].value.p_Selects)->size() > 0) {
	    (yystack_[0].value.p_Selects)->insert((yystack_[0].value.p_Selects)->begin(), (yystack_[1].value.p_Select));
	    sql::SQLUnion* u = new sql::SQLUnion((yystack_[0].value.p_Selects)->begin(), (yystack_[0].value.p_Selects)->end());
	    (yylhs.value.p_Select) = driver.root = u;
	} else
	    (yylhs.value.p_Select) = driver.root = (yystack_[1].value.p_Select);
	delete (yystack_[0].value.p_Selects);
}
#line 1116 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 115:
#line 745 "lib/SQLParser.ypp" // lalr1.cc:847
    {
    (yylhs.value.p_Select) = (yystack_[0].value.p_Select);
}
#line 1124 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 116:
#line 751 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Selects) = new std::vector<sql::SQLQuery*>();
    }
#line 1132 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 117:
#line 754 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yystack_[1].value.p_Selects)->push_back((yystack_[0].value.p_Select));
	(yylhs.value.p_Selects) = (yystack_[1].value.p_Selects);
    }
#line 1141 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 118:
#line 761 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	driver.root = (yylhs.value.p_Select) = new sql::SQLQuery((yystack_[2].value.p_TableList).joins);
	delete (yystack_[2].value.p_TableList).joins;
	for (std::vector<sql::AliasedSelect*>::const_iterator it = (yystack_[3].value.p_AttributeList)->begin(); it != (yystack_[3].value.p_AttributeList)->end(); ++it)
	    driver.root->selects.push_back(*it);
	delete (yystack_[3].value.p_AttributeList);
	for (std::vector<const w3c_sw::sql::Expression*>::const_iterator it = (yystack_[2].value.p_TableList).exprs->begin();
	     it != (yystack_[2].value.p_TableList).exprs->end(); ++it)
	    driver.root->constraints.push_back(*it);
	    // LINE << "exprs: " << (*it)->toString();
	delete (yystack_[2].value.p_TableList).exprs;
	driver.root->limit = (yystack_[1].value.p_int);
	driver.root->offset = (yystack_[0].value.p_int);
}
#line 1160 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 119:
#line 778 "lib/SQLParser.ypp" // lalr1.cc:847
    {
    (yylhs.value.p_Expression) = (yystack_[0].value.p_Expression);
}
#line 1168 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 120:
#line 784 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = NULL;
    }
#line 1176 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 122:
#line 791 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_TableList).joins = (yystack_[1].value.p_TableList).joins;
	(yylhs.value.p_TableList).exprs = (yystack_[1].value.p_TableList).exprs;
	if ((yystack_[0].value.p_Expression) != NULL)
	    (yylhs.value.p_TableList).exprs->push_back((yystack_[0].value.p_Expression));
}
#line 1187 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 123:
#line 800 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_TableList).joins = new std::vector<sql::Join*>();;
	(yylhs.value.p_TableList).exprs = new std::vector<const sql::Expression*>();;
    }
#line 1196 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 125:
#line 808 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yystack_[0].value.p_Expression));
	(yylhs.value.p_int) = i->getValue();
	delete (yystack_[0].value.p_Expression);
    }
#line 1206 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 126:
#line 813 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yystack_[0].value.p_Expression));
	(yylhs.value.p_int) = i->getValue();
	delete (yystack_[0].value.p_Expression);
    }
#line 1216 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 127:
#line 821 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_int) = -1;
    }
#line 1224 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 129:
#line 828 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	const sql::IntConstraint* i = dynamic_cast<const sql::IntConstraint*>((yystack_[0].value.p_Expression));
	(yylhs.value.p_int) = i->getValue();
	delete (yystack_[0].value.p_Expression);
}
#line 1234 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 130:
#line 836 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_int) = -1;
    }
#line 1242 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 132:
#line 843 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yystack_[0].value.p_AttributeList)->insert((yystack_[0].value.p_AttributeList)->begin(), (yystack_[1].value.p_AliasedSelect));
	(yylhs.value.p_AttributeList) = new std::vector<sql::AliasedSelect*>((yystack_[0].value.p_AttributeList)->begin(), (yystack_[0].value.p_AttributeList)->end());
	delete (yystack_[0].value.p_AttributeList);
    }
#line 1252 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 133:
#line 848 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_AttributeList) = new std::vector<sql::AliasedSelect*>();
      }
#line 1260 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 134:
#line 854 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_AliasedSelect) = (yystack_[0].value.p_AliasedSelect);
    }
#line 1268 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 135:
#line 860 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_AttributeList) = new std::vector<sql::AliasedSelect*>();
    }
#line 1276 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 136:
#line 863 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yystack_[1].value.p_AttributeList)->push_back((yystack_[0].value.p_AliasedSelect));
	(yylhs.value.p_AttributeList) = (yystack_[1].value.p_AttributeList);
    }
#line 1285 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 137:
#line 870 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	if ((yystack_[0].value.p_NAME) == NULL) {
	    // "SELECT a.dname FROM DEPT AS a" yields a field calld `dname` (i.e. elides the alias).
	    const sql::AliasAttrConstraint* a = dynamic_cast<const sql::AliasAttrConstraint*>((yystack_[1].value.p_Expression));
	    (yylhs.value.p_AliasedSelect) = new sql::AliasedSelect((yystack_[1].value.p_Expression), a ? a->getAliasAttr().attr : (yystack_[1].value.p_Expression)->toString());
	} else {
	    (yylhs.value.p_AliasedSelect) = new sql::AliasedSelect((yystack_[1].value.p_Expression), *(yystack_[0].value.p_NAME));
	    delete (yystack_[0].value.p_NAME);
	}
    }
#line 1300 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 140:
#line 888 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_NAME) = (yystack_[0].value.p_NAME);
    }
#line 1308 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 141:
#line 894 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_NAME) = NULL;
    }
#line 1316 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 142:
#line 897 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_NAME) = (yystack_[0].value.p_NAME);
      }
#line 1324 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 143:
#line 903 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new sql::AliasAttrConstraint(sql::AliasAttr(sql::RelVar(*(yystack_[2].value.p_NAME)), sql::Attribute(*(yystack_[0].value.p_NAME))));
	delete (yystack_[2].value.p_NAME);
	delete (yystack_[0].value.p_NAME);
    }
#line 1334 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 144:
#line 908 "lib/SQLParser.ypp" // lalr1.cc:847
    {
      (yylhs.value.p_Expression) = new sql::AliasAttrConstraint(sql::AliasAttr(sql::RelVar(""), sql::Attribute(*(yystack_[0].value.p_NAME))));
	delete (yystack_[0].value.p_NAME);
    }
#line 1343 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 149:
#line 925 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yystack_[0].value.p_TableList).joins->insert((yystack_[0].value.p_TableList).joins->begin(), (yystack_[1].value.p_tableAlias).relation != NULL
		   ? (sql::Join*)new sql::TableJoin(*(yystack_[1].value.p_tableAlias).relation, *(yystack_[1].value.p_tableAlias).alias, false)
		   : (sql::Join*)new sql::SubqueryJoin((yystack_[1].value.p_tableAlias).subselect, *(yystack_[1].value.p_tableAlias).alias, false));
	delete (yystack_[1].value.p_tableAlias).relation;
	delete (yystack_[1].value.p_tableAlias).alias;
	(yylhs.value.p_TableList).joins = new std::vector<sql::Join*>((yystack_[0].value.p_TableList).joins->begin(), (yystack_[0].value.p_TableList).joins->end());
	(yylhs.value.p_TableList).exprs = (yystack_[0].value.p_TableList).exprs;
	delete (yystack_[0].value.p_TableList).joins;
}
#line 1358 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 150:
#line 938 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_bool) = false;
    }
#line 1366 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 151:
#line 941 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_bool) = false;
      }
#line 1374 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 152:
#line 944 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_bool) = true;
    }
#line 1382 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 153:
#line 950 "lib/SQLParser.ypp" // lalr1.cc:847
    {
    (yylhs.value.p_Expression) = (yystack_[0].value.p_Expression);
}
#line 1390 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 154:
#line 956 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = NULL;
    }
#line 1398 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 155:
#line 959 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = (yystack_[0].value.p_Expression);
      }
#line 1406 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 156:
#line 965 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	if ((yystack_[1].value.p_tableAlias).relation != NULL) {
	    (yylhs.value.p_JoinExpression).join = new sql::TableJoin(*(yystack_[1].value.p_tableAlias).relation, *(yystack_[1].value.p_tableAlias).alias, (yystack_[3].value.p_bool));
	    delete (yystack_[1].value.p_tableAlias).relation;
	} else {
	    (yylhs.value.p_JoinExpression).join = new sql::SubqueryJoin((yystack_[1].value.p_tableAlias).subselect, *(yystack_[1].value.p_tableAlias).alias, (yystack_[3].value.p_bool));
	}
	delete (yystack_[1].value.p_tableAlias).alias;
	(yylhs.value.p_JoinExpression).expr = (yystack_[0].value.p_Expression);
}
#line 1421 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 157:
#line 978 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_TableList).joins = new std::vector<sql::Join*>();
	(yylhs.value.p_TableList).exprs = new std::vector<const sql::Expression*>();
    }
#line 1430 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 158:
#line 982 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yystack_[1].value.p_TableList).joins->push_back((yystack_[0].value.p_JoinExpression).join);
	if ((yystack_[0].value.p_JoinExpression).expr != NULL)
	    (yystack_[1].value.p_TableList).exprs->push_back((yystack_[0].value.p_JoinExpression).expr);
	(yylhs.value.p_TableList) = (yystack_[1].value.p_TableList);
    }
#line 1441 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 159:
#line 991 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_tableAlias).relation = new sql::RelationName(*(yystack_[1].value.p_NAME));
	(yylhs.value.p_tableAlias).subselect = NULL;
	if ((yystack_[0].value.p_NAME)) {
	    (yylhs.value.p_tableAlias).alias = new sql::RelVar(*(yystack_[0].value.p_NAME));
	    delete (yystack_[0].value.p_NAME);
	} else {
	    (yylhs.value.p_tableAlias).alias = new sql::RelVar(*(yystack_[1].value.p_NAME));
	}
	delete (yystack_[1].value.p_NAME);
    }
#line 1457 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 160:
#line 1002 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_tableAlias).relation = NULL;
	(yylhs.value.p_tableAlias).subselect = (yystack_[3].value.p_Select);
	(yylhs.value.p_tableAlias).alias = new sql::RelVar(*(yystack_[0].value.p_NAME));
	delete (yystack_[0].value.p_NAME);
    }
#line 1468 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 161:
#line 1011 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_NAME) = (yystack_[0].value.p_NAME);
    }
#line 1476 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 162:
#line 1017 "lib/SQLParser.ypp" // lalr1.cc:847
    {
    (yylhs.value.p_NAME) = NULL;
    }
#line 1484 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 163:
#line 1020 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_NAME) = (yystack_[0].value.p_NAME);
    }
#line 1492 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 164:
#line 1026 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	if ((yystack_[0].value.p_Expressions)->size() > 0) {
	    (yystack_[0].value.p_Expressions)->insert((yystack_[0].value.p_Expressions)->begin(), (yystack_[1].value.p_Expression));
	    (yylhs.value.p_Expression) = new sql::HomologConstraint("CONCAT", (yystack_[0].value.p_Expressions)->begin(), (yystack_[0].value.p_Expressions)->end());
	} else
	    (yylhs.value.p_Expression) = (yystack_[1].value.p_Expression);
	delete (yystack_[0].value.p_Expressions);
    }
#line 1505 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 165:
#line 1037 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = (yystack_[0].value.p_Expression);
    }
#line 1513 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 166:
#line 1043 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expressions) = new std::vector<const sql::Expression*>();
    }
#line 1521 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 167:
#line 1046 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yystack_[1].value.p_Expressions)->push_back((yystack_[0].value.p_Expression));
	(yylhs.value.p_Expressions) = (yystack_[1].value.p_Expressions);
    }
#line 1530 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 168:
#line 1054 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	if ((yystack_[0].value.p_Expressions)->size() > 0) {
	    (yystack_[0].value.p_Expressions)->insert((yystack_[0].value.p_Expressions)->begin(), (yystack_[1].value.p_Expression));
	    (yylhs.value.p_Expression) = new sql::DisjunctionConstraint((yystack_[0].value.p_Expressions)->begin(), (yystack_[0].value.p_Expressions)->end());
	} else
	    (yylhs.value.p_Expression) = (yystack_[1].value.p_Expression);
	delete (yystack_[0].value.p_Expressions);
    }
#line 1543 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 169:
#line 1066 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = (yystack_[0].value.p_Expression);
    }
#line 1551 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 170:
#line 1073 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expressions) = new std::vector<const sql::Expression*>();
    }
#line 1559 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 171:
#line 1076 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yystack_[1].value.p_Expressions)->push_back((yystack_[0].value.p_Expression));
	(yylhs.value.p_Expressions) = (yystack_[1].value.p_Expressions);
    }
#line 1568 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 172:
#line 1084 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	if ((yystack_[0].value.p_Expressions)->size() > 0) {
	    (yystack_[0].value.p_Expressions)->insert((yystack_[0].value.p_Expressions)->begin(), (yystack_[1].value.p_Expression));
	    (yylhs.value.p_Expression) = new sql::ConjunctionConstraint((yystack_[0].value.p_Expressions)->begin(), (yystack_[0].value.p_Expressions)->end());
	} else
	    (yylhs.value.p_Expression) = (yystack_[1].value.p_Expression);
	delete (yystack_[0].value.p_Expressions);
    }
#line 1581 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 173:
#line 1096 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = (yystack_[0].value.p_Expression);
    }
#line 1589 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 174:
#line 1103 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expressions) = new std::vector<const sql::Expression*>();
    }
#line 1597 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 175:
#line 1106 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yystack_[1].value.p_Expressions)->push_back((yystack_[0].value.p_Expression));
	(yylhs.value.p_Expressions) = (yystack_[1].value.p_Expressions);
    }
#line 1606 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 177:
#line 1118 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	if ((yystack_[0].value.p_BooleanComparator)) {
	    if (dynamic_cast<parser::IsNotNullProxy*>((yystack_[0].value.p_BooleanComparator)) != NULL) {
		delete (yystack_[0].value.p_BooleanComparator);
		(yylhs.value.p_Expression) = new sql::NegationConstraint(new sql::NotNullConstraint(dynamic_cast<const sql::Expression*>((yystack_[1].value.p_Expression)))); // new sql::IsNullConstraint();
	    } else if (dynamic_cast<parser::IsNullProxy*>((yystack_[0].value.p_BooleanComparator)) != NULL) {
		delete (yystack_[0].value.p_BooleanComparator);
		(yylhs.value.p_Expression) = new sql::NotNullConstraint(dynamic_cast<const sql::Expression*>((yystack_[1].value.p_Expression)));
	    } else {
		(yystack_[0].value.p_BooleanComparator)->setLeftParm((yystack_[1].value.p_Expression));
		(yylhs.value.p_Expression) = (yystack_[0].value.p_BooleanComparator); // !!!
	    }
	} else
	    (yylhs.value.p_Expression) = (yystack_[1].value.p_Expression);
    }
#line 1626 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 178:
#line 1137 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_BooleanComparator) = NULL;
    }
#line 1634 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 180:
#line 1145 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_BooleanComparator) = new sql::BooleanEQ((yystack_[0].value.p_Expression));
    }
#line 1642 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 181:
#line 1148 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_BooleanComparator) = new sql::BooleanNE((yystack_[0].value.p_Expression));
    }
#line 1650 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 182:
#line 1151 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_BooleanComparator) = new sql::BooleanLT((yystack_[0].value.p_Expression));
    }
#line 1658 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 183:
#line 1154 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_BooleanComparator) = new sql::BooleanGT((yystack_[0].value.p_Expression));
    }
#line 1666 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 184:
#line 1157 "lib/SQLParser.ypp" // lalr1.cc:847
    {
        (yylhs.value.p_BooleanComparator) = new sql::BooleanLE((yystack_[0].value.p_Expression));
    }
#line 1674 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 185:
#line 1160 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_BooleanComparator) = new sql::BooleanGE((yystack_[0].value.p_Expression));
    }
#line 1682 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 186:
#line 1163 "lib/SQLParser.ypp" // lalr1.cc:847
    {
      (yylhs.value.p_BooleanComparator) = new parser::IsNullProxy;
    }
#line 1690 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 187:
#line 1166 "lib/SQLParser.ypp" // lalr1.cc:847
    {
      (yylhs.value.p_BooleanComparator) = new parser::IsNotNullProxy;
}
#line 1698 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 189:
#line 1177 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	if ((yystack_[0].value.p_Expressions)->size() > 0) {
	    (yystack_[0].value.p_Expressions)->insert((yystack_[0].value.p_Expressions)->begin(), (yystack_[1].value.p_Expression));
	    (yylhs.value.p_Expression) = new sql::ArithmeticSum((yystack_[0].value.p_Expressions)->begin(), (yystack_[0].value.p_Expressions)->end());
	} else
	    (yylhs.value.p_Expression) = (yystack_[1].value.p_Expression);
	delete (yystack_[0].value.p_Expressions);
    }
#line 1711 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 190:
#line 1189 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = (yystack_[0].value.p_Expression);
    }
#line 1719 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 191:
#line 1192 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new sql::ArithmeticNegation((yystack_[0].value.p_Expression));
    }
#line 1727 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 194:
#line 1201 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expressions) = new std::vector<const sql::Expression*>();
    }
#line 1735 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 195:
#line 1204 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yystack_[1].value.p_Expressions)->push_back((yystack_[0].value.p_Expression));
	(yylhs.value.p_Expressions) = (yystack_[1].value.p_Expressions);
    }
#line 1744 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 196:
#line 1212 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	if ((yystack_[0].value.p_Expressions)->size() > 0) {
	    (yystack_[0].value.p_Expressions)->insert((yystack_[0].value.p_Expressions)->begin(), (yystack_[1].value.p_Expression));
	    (yylhs.value.p_Expression) = new sql::ArithmeticProduct((yystack_[0].value.p_Expressions)->begin(), (yystack_[0].value.p_Expressions)->end());
	} else
	    (yylhs.value.p_Expression) = (yystack_[1].value.p_Expression);
	delete (yystack_[0].value.p_Expressions);
    }
#line 1757 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 197:
#line 1224 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = (yystack_[0].value.p_Expression);
    }
#line 1765 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 198:
#line 1227 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new sql::ArithmeticInverse((yystack_[0].value.p_Expression));
    }
#line 1773 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 199:
#line 1234 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expressions) = new std::vector<const sql::Expression*>();
    }
#line 1781 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 200:
#line 1237 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yystack_[1].value.p_Expressions)->push_back((yystack_[0].value.p_Expression));
	(yylhs.value.p_Expressions) = (yystack_[1].value.p_Expressions);
    }
#line 1790 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 201:
#line 1244 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new sql::BooleanNegation((yystack_[0].value.p_Expression));
    }
#line 1798 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 202:
#line 1247 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = (yystack_[0].value.p_Expression);
    }
#line 1806 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 203:
#line 1250 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new sql::ArithmeticNegation((yystack_[0].value.p_Expression));
    }
#line 1814 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 209:
#line 1264 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = (yystack_[1].value.p_Expression);
    }
#line 1822 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 210:
#line 1270 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yystack_[1].value.p_Expressions)->insert((yystack_[1].value.p_Expressions)->begin(), (yystack_[2].value.p_Expression));
	(yylhs.value.p_Expression) = new sql::HomologConstraint("CONCAT", (yystack_[1].value.p_Expressions)->begin(), (yystack_[1].value.p_Expressions)->end());
	delete (yystack_[1].value.p_Expressions);
    }
#line 1832 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 211:
#line 1275 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	std::vector<const sql::Expression*> v;
	v.push_back((yystack_[1].value.p_Expression));
	(yylhs.value.p_Expression) = new sql::HomologConstraint("LCASE", v.begin(), v.end());
    }
#line 1842 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 212:
#line 1280 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	std::vector<const sql::Expression*> v;
	v.push_back((yystack_[1].value.p_Expression));
	(yylhs.value.p_Expression) = new sql::HomologConstraint("UCASE", v.begin(), v.end());
    }
#line 1852 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 213:
#line 1285 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new sql::RegexConstraint((yystack_[3].value.p_Expression), (yystack_[1].value.p_Expression));
    }
#line 1860 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 214:
#line 1291 "lib/SQLParser.ypp" // lalr1.cc:847
    {
    (yylhs.value.p_Expression) = (yystack_[0].value.p_Expression);
}
#line 1868 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 215:
#line 1297 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expressions) = new std::vector<const sql::Expression*>();
    }
#line 1876 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 216:
#line 1300 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yystack_[1].value.p_Expressions)->push_back((yystack_[0].value.p_Expression));
	(yylhs.value.p_Expressions) = (yystack_[1].value.p_Expressions);
    }
#line 1885 "lib/SQLParser.cpp" // lalr1.cc:847
    break;

  case 231:
#line 1336 "lib/SQLParser.ypp" // lalr1.cc:847
    {
	(yylhs.value.p_Expression) = new sql::LiteralConstraint(*(yystack_[0].value.p_NAME));
	delete (yystack_[0].value.p_NAME);
    }
#line 1894 "lib/SQLParser.cpp" // lalr1.cc:847
    break;


#line 1898 "lib/SQLParser.cpp" // lalr1.cc:847
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
  SQLParser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  SQLParser::yysyntax_error_ (state_type yystate, symbol_number_type yytoken) const
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


  const short int SQLParser::yypact_ninf_ = -260;

  const short int SQLParser::yytable_ninf_ = -149;

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



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
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
  "NumericLiteralNegative", "BooleanLiteral", "String", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  SQLParser::yyrline_[] =
  {
       0,   336,   336,   339,   342,   344,   348,   351,   353,   357,
     358,   359,   360,   361,   365,   365,   374,   378,   381,   383,
     387,   388,   392,   393,   396,   398,   402,   402,   412,   415,
     417,   420,   422,   426,   434,   437,   441,   446,   448,   452,
     455,   461,   467,   468,   472,   475,   477,   481,   483,   481,
     490,   491,   494,   499,   501,   504,   506,   509,   511,   515,
     521,   526,   528,   532,   539,   547,   550,   554,   557,   560,
     563,   566,   569,   572,   575,   578,   581,   584,   587,   590,
     593,   596,   599,   602,   605,   611,   614,   620,   621,   625,
     628,   634,   637,   641,   642,   646,   651,   654,   657,   662,
     672,   675,   676,   677,   678,   679,   685,   693,   699,   702,
     710,   717,   723,   726,   733,   745,   751,   754,   761,   778,
     784,   787,   791,   800,   804,   808,   813,   821,   824,   828,
     836,   839,   843,   848,   854,   860,   863,   870,   882,   884,
     888,   894,   897,   903,   908,   915,   916,   920,   921,   925,
     938,   941,   944,   950,   956,   959,   965,   978,   982,   991,
    1002,  1011,  1017,  1020,  1026,  1037,  1043,  1046,  1054,  1066,
    1073,  1076,  1084,  1096,  1103,  1106,  1113,  1118,  1137,  1140,
    1145,  1148,  1151,  1154,  1157,  1160,  1163,  1166,  1172,  1177,
    1189,  1192,  1195,  1196,  1201,  1204,  1212,  1224,  1227,  1234,
    1237,  1244,  1247,  1250,  1253,  1257,  1258,  1259,  1260,  1264,
    1270,  1275,  1280,  1285,  1291,  1297,  1300,  1307,  1308,  1309,
    1313,  1314,  1315,  1319,  1320,  1321,  1325,  1326,  1327,  1331,
    1332,  1336
  };

  // Print the state stack on the debug stream.
  void
  SQLParser::yystack_print_ ()
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
  SQLParser::yy_reduce_print_ (int yyrule)
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
    const unsigned int user_token_number_max_ = 359;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // w3c_sw
#line 2657 "lib/SQLParser.cpp" // lalr1.cc:1155
#line 1356 "lib/SQLParser.ypp" // lalr1.cc:1156
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
