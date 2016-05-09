// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

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

#line 39 "lib/JSONresultsParser.cpp" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "JSONresultsParser.hpp"

// User implementation prologue.
#line 182 "lib/JSONresultsParser.ypp" // lalr1.cc:412

#include "JSONresultsScanner.hpp"
#line 216 "lib/JSONresultsParser.ypp" // lalr1.cc:412

#include "JSONresultsScanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lexWrapper

#line 65 "lib/JSONresultsParser.cpp" // lalr1.cc:412


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
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace w3c_sw {
#line 151 "lib/JSONresultsParser.cpp" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  JSONresultsParser::yytnamerr_ (const char *yystr)
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
  JSONresultsParser::JSONresultsParser (class JSONresultsDriver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

  JSONresultsParser::~JSONresultsParser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  JSONresultsParser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  JSONresultsParser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  JSONresultsParser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    value = other.value;
  }


  template <typename Base>
  inline
  JSONresultsParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  JSONresultsParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  inline
  JSONresultsParser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  JSONresultsParser::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  JSONresultsParser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  JSONresultsParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  inline
  JSONresultsParser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  JSONresultsParser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  JSONresultsParser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  JSONresultsParser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  JSONresultsParser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  JSONresultsParser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  JSONresultsParser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  JSONresultsParser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  JSONresultsParser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  JSONresultsParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  JSONresultsParser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  JSONresultsParser::symbol_number_type
  JSONresultsParser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  JSONresultsParser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  JSONresultsParser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    value = that.value;
    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  JSONresultsParser::stack_symbol_type&
  JSONresultsParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  JSONresultsParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  JSONresultsParser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  JSONresultsParser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  JSONresultsParser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  JSONresultsParser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  JSONresultsParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  JSONresultsParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  JSONresultsParser::debug_level_type
  JSONresultsParser::debug_level () const
  {
    return yydebug_;
  }

  void
  JSONresultsParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline JSONresultsParser::state_type
  JSONresultsParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  JSONresultsParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  JSONresultsParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  JSONresultsParser::parse ()
  {
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
    #line 43 "lib/JSONresultsParser.ypp" // lalr1.cc:741
{
    // initialize the initial location object
    yyla.location.begin.filename = yyla.location.end.filename = &driver.streamname;
    driver.yylloc = &yyla.location;
}

#line 531 "lib/JSONresultsParser.cpp" // lalr1.cc:741

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
    if (yyla.empty ())
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
#line 230 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	if (driver.root == NULL)
	    driver.startBindingSet();
	else
	    driver.curResultSet = driver.root;
      }
#line 646 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 3:
#line 235 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	  driver.root = driver.endBindingSet();
	  driver.curResultSet = NULL;
      }
#line 655 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 12:
#line 265 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	// throw away link $4
	delete (yystack_[1].value.p_str);
    }
#line 664 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 13:
#line 272 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	driver.addBindingVar(driver.getVariable(*(yystack_[0].value.p_str)));
	delete (yystack_[0].value.p_str);
    }
#line 673 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 15:
#line 279 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	driver.addBindingVar(driver.getVariable(*(yystack_[0].value.p_str)));
	delete (yystack_[0].value.p_str);
    }
#line 682 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 19:
#line 292 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
      driver.curResultSet->resultType = ResultSet::RESULT_Boolean;
      if ((yystack_[0].value.p_bool) == true)
	  driver.curResultSet->clear();
    }
#line 692 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 20:
#line 300 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_bool) = true;
	//	delete $1;
    }
#line 701 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 21:
#line 304 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_bool) = false;
	//	delete $1;
    }
#line 710 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 26:
#line 324 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	driver.startBindingRow(false);
      }
#line 718 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 27:
#line 326 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	  driver.endBindingRow();
      }
#line 726 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 31:
#line 341 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	driver.addBinding(driver.getVariable(*(yystack_[4].value.p_str)), (yystack_[1].value.p_TTerm));
	delete (yystack_[4].value.p_str);
    }
#line 735 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 32:
#line 348 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_URI);
    }
#line 743 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 33:
#line 351 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_BNode);
    }
#line 751 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 34:
#line 354 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_literal);
    }
#line 759 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 35:
#line 357 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_literal);
    }
#line 767 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 36:
#line 360 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	driver.curValue = (yystack_[0].value.p_str);
      }
#line 775 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 37:
#line 362 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	  driver.curValue = NULL;
	  (yylhs.value.p_TTerm) = (yystack_[0].value.p_TTerm);
      }
#line 784 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 38:
#line 366 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	driver.curDatatype = (yystack_[0].value.p_URI);
      }
#line 792 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 39:
#line 368 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	  driver.curDatatype = NULL;
	  (yylhs.value.p_TTerm) = (yystack_[0].value.p_literal);
      }
#line 801 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 40:
#line 372 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	driver.curLang = (yystack_[0].value.p_str);
      }
#line 809 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 41:
#line 374 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	  driver.curLang = NULL;
	  (yylhs.value.p_TTerm) = (yystack_[0].value.p_literal);
      }
#line 818 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 42:
#line 381 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_URI) = driver.getURI(*(yystack_[0].value.p_str));
	delete (yystack_[0].value.p_str);
    }
#line 827 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 43:
#line 388 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_BNode) = driver.getBNode(*(yystack_[0].value.p_str));
	delete (yystack_[0].value.p_str);
    }
#line 836 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 44:
#line 395 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_literal) = (yystack_[0].value.p_literal);
    }
#line 844 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 45:
#line 401 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_str) = (yystack_[0].value.p_str);
    }
#line 852 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 46:
#line 407 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_str) = NULL;
    }
#line 860 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 48:
#line 414 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_literal) = driver.getRDFLiteral(*(yystack_[0].value.p_str), NULL, (yystack_[2].value.p_str) ? new LANGTAG(*(yystack_[2].value.p_str)) : NULL);
	delete (yystack_[0].value.p_str);
	delete (yystack_[2].value.p_str);
    }
#line 870 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 49:
#line 419 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_literal) = driver.getRDFLiteral(*(yystack_[1].value.p_str), NULL, (yystack_[0].value.p_str) ? new LANGTAG(*(yystack_[0].value.p_str)) : NULL);
	delete (yystack_[1].value.p_str);
	delete (yystack_[0].value.p_str);
    }
#line 880 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 50:
#line 427 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_literal) = (yystack_[0].value.p_literal);
    }
#line 888 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 51:
#line 433 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_literal) = driver.getRDFLiteral(*(yystack_[0].value.p_str), (yystack_[2].value.p_URI), NULL);
	delete (yystack_[0].value.p_str);
    }
#line 897 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 52:
#line 437 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_literal) = driver.getRDFLiteral(*(yystack_[2].value.p_str), (yystack_[0].value.p_URI), NULL);
	delete (yystack_[2].value.p_str);
    }
#line 906 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 53:
#line 444 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_TTerm);
    }
#line 914 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 54:
#line 447 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
      (yylhs.value.p_TTerm) = driver.getRDFLiteral(*driver.curValue, (yystack_[3].value.p_URI), NULL);
      delete driver.curValue;
      driver.curDatatype = NULL;
    }
#line 924 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 55:
#line 452 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
      (yylhs.value.p_TTerm) = driver.getRDFLiteral(*driver.curValue, NULL, (yystack_[3].value.p_str) ? new LANGTAG(*(yystack_[3].value.p_str)) : NULL);
      delete driver.curValue;
      delete (yystack_[3].value.p_str);
      driver.curLang = NULL;
    }
#line 935 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 56:
#line 461 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = driver.getURI(*driver.curValue);
	delete driver.curValue;
    }
#line 944 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 57:
#line 465 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = driver.getBNode(*driver.curValue);
	delete driver.curValue;
    }
#line 953 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 58:
#line 469 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = driver.getRDFLiteral(*driver.curValue, NULL, (yystack_[0].value.p_str) ? new LANGTAG(*(yystack_[0].value.p_str)) : NULL);
	delete driver.curValue;
	delete (yystack_[0].value.p_str);
    }
#line 963 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 59:
#line 474 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = driver.getRDFLiteral(*driver.curValue, (yystack_[0].value.p_URI), NULL);
	delete driver.curValue;
    }
#line 972 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 60:
#line 481 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_literal) = driver.getRDFLiteral(*(yystack_[0].value.p_str), driver.curDatatype, NULL);
	delete (yystack_[0].value.p_str);
    }
#line 981 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 61:
#line 485 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_literal) = driver.getRDFLiteral(*(yystack_[3].value.p_str), driver.curDatatype, NULL);
	delete (yystack_[3].value.p_str);
    }
#line 990 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 62:
#line 492 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_literal) = driver.getRDFLiteral(*(yystack_[0].value.p_str), NULL, driver.curLang ? new LANGTAG(*driver.curLang) : NULL);
	delete (yystack_[0].value.p_str);
	delete driver.curLang;
    }
#line 1000 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 63:
#line 497 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_literal) = driver.getRDFLiteral(*(yystack_[3].value.p_str), NULL, driver.curLang ? new LANGTAG(*driver.curLang) : NULL);
	delete (yystack_[3].value.p_str);
	delete driver.curLang;
    }
#line 1010 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 64:
#line 505 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_str) = (yystack_[0].value.p_str);
    }
#line 1018 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 65:
#line 511 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_URI) = driver.getURI(*(yystack_[0].value.p_str));
	delete (yystack_[0].value.p_str);
    }
#line 1027 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 66:
#line 518 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_str) = (yystack_[0].value.p_str);
    }
#line 1035 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 100:
#line 608 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_str) = new std::string("head");
    }
#line 1043 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 101:
#line 611 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
      (yylhs.value.p_str) = new std::string("vars");
    }
#line 1051 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 102:
#line 614 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
      (yylhs.value.p_str) = new std::string("results");
    }
#line 1059 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 103:
#line 617 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
      (yylhs.value.p_str) = new std::string("boolean");
    }
#line 1067 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 104:
#line 620 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
      (yylhs.value.p_str) = new std::string("true");
    }
#line 1075 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 105:
#line 623 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
      (yylhs.value.p_str) = new std::string("false");
    }
#line 1083 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 106:
#line 626 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
      (yylhs.value.p_str) = new std::string("bindings");
    }
#line 1091 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 107:
#line 629 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
      (yylhs.value.p_str) = new std::string("type");
    }
#line 1099 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 108:
#line 632 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
      (yylhs.value.p_str) = new std::string("uri");
    }
#line 1107 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 109:
#line 635 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
      (yylhs.value.p_str) = new std::string("bnode");
    }
#line 1115 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 110:
#line 638 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
      (yylhs.value.p_str) = new std::string("literal");
    }
#line 1123 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 111:
#line 641 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
      (yylhs.value.p_str) = new std::string("typedLiteral");
    }
#line 1131 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 112:
#line 644 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
      (yylhs.value.p_str) = new std::string("datatype");
    }
#line 1139 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 113:
#line 647 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
      (yylhs.value.p_str) = new std::string("lang");
    }
#line 1147 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;

  case 114:
#line 650 "lib/JSONresultsParser.ypp" // lalr1.cc:859
    {
      (yylhs.value.p_str) = new std::string("value");
    }
#line 1155 "lib/JSONresultsParser.cpp" // lalr1.cc:859
    break;


#line 1159 "lib/JSONresultsParser.cpp" // lalr1.cc:859
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
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
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
    if (!yyla.empty ())
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
        if (!yyla.empty ())
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
  JSONresultsParser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  JSONresultsParser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
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
       - The only way there can be no lookahead present (in yyla) is
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
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
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

    std::string yyres;
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


  const short int JSONresultsParser::yypact_ninf_ = -133;

  const signed char JSONresultsParser::yytable_ninf_ = -1;

  const short int
  JSONresultsParser::yypact_[] =
  {
      25,  -133,    32,     2,  -133,  -133,  -133,    34,    30,    38,
      41,  -133,  -133,  -133,  -133,    52,    55,    57,    98,  -133,
      64,    65,  -133,  -133,  -133,  -133,  -133,    69,    72,    81,
      63,    92,   153,  -133,  -133,  -133,  -133,  -133,  -133,   106,
     165,  -133,  -133,    93,    99,  -133,  -133,   110,   107,  -133,
    -133,   108,   108,  -133,   146,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,   148,  -133,
     158,  -133,  -133,  -133,  -133,     9,   108,    23,   108,  -133,
    -133,  -133,   178,   158,  -133,  -133,  -133,   174,   190,  -133,
     108,  -133,  -133,    67,  -133,   189,  -133,  -133,  -133,   126,
     191,   192,   193,   194,  -133,   197,   198,   199,  -133,  -133,
    -133,  -133,   200,   201,   202,   203,  -133,   108,   108,   108,
     127,   141,   141,   151,   151,    -4,   137,  -133,  -133,  -133,
    -133,   204,   205,   126,  -133,   206,   149,  -133,   207,   154,
    -133,  -133,  -133,   208,   209,  -133,   210,   211,   160,   160,
    -133,  -133,  -133,   208,   212,   160,   213,   160,   214,   152,
    -133,  -133,   151,   156,   151,   149,   154,  -133,   156,   149,
     151,   154,   151,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,  -133
  };

  const unsigned char
  JSONresultsParser::yydefact_[] =
  {
       0,     2,     0,     0,     1,    67,    68,     0,     0,     0,
       0,    73,    75,    76,    74,     0,     0,     0,    10,     3,
       0,     0,    69,    70,    71,    72,    11,     0,     0,     6,
       0,     0,     0,    78,    77,    19,    20,    21,     4,     0,
       0,     7,     9,     0,     0,    79,    80,     0,     0,     8,
       5,     0,     0,    18,     0,    81,    82,    83,    84,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    99,    98,   100,   101,   102,   103,   104,   105,   106,
     108,   109,   107,   114,   110,   111,   112,   113,     0,    13,
       0,    12,    16,    26,    24,     0,     0,     0,     0,    14,
      17,    29,     0,     0,    22,    25,    15,     0,     0,    23,
       0,    27,    30,     0,    28,     0,    36,    38,    40,     0,
       0,     0,     0,     0,    31,     0,     0,     0,    32,    33,
      34,    35,     0,     0,     0,     0,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    64,    65,    66,
      37,     0,     0,     0,    39,     0,     0,    41,     0,     0,
      42,    43,    44,    46,     0,    50,     0,     0,     0,     0,
      53,    56,    57,    46,     0,     0,     0,     0,     0,     0,
      47,    49,     0,     0,     0,     0,     0,    58,     0,     0,
       0,     0,     0,    45,    48,    52,    51,    54,    55,    59,
      61,    60,    63,    62
  };

  const short int
  JSONresultsParser::yypgoto_[] =
  {
    -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,   155,   157,
    -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,   116,  -133,
    -133,  -133,   111,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,    47,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -122,
    -132,  -130,   219,  -133,    -9,   215,   216,   217,   218,   195,
    -112,  -101,   -61,   -76,   -51,  -113,  -114,  -111,   -97,   -48
  };

  const short int
  JSONresultsParser::yydefgoto_[] =
  {
      -1,     2,     3,     7,    41,    42,    26,    27,    28,    29,
      92,   100,    95,    15,    35,    47,   105,    97,    94,    96,
     112,   107,   101,   115,   125,   126,   127,   128,   129,   130,
     180,   181,   162,   131,   165,   150,   170,   154,   157,   116,
     117,   118,    73,    30,    74,    75,    76,    77,    78,    79,
      80,    81,   119,    82,   121,    84,    85,    86,    87,   102
  };

  const unsigned char
  JSONresultsParser::yytable_[] =
  {
      83,    83,   122,    88,    89,   135,   134,   132,   151,    31,
     152,     5,     6,    98,   167,   164,   123,    99,   133,   155,
     158,   160,   161,   163,   166,    61,    62,   103,     1,   122,
      31,   104,     4,    69,    70,   122,    10,   120,     9,   174,
     173,   171,   176,   123,    18,    83,   178,    83,   123,   193,
     106,   195,   172,    11,    12,    13,   199,    19,    14,    83,
     194,    20,   196,    21,   120,   120,   120,    32,   201,    43,
     203,   197,   122,   198,    38,   200,    39,   122,   202,   153,
     156,   159,   123,    33,    34,    40,    83,    83,    83,   147,
     148,   149,   120,   120,    59,    60,    61,    62,    44,   120,
      51,   120,    67,    68,    69,    70,    52,   185,   186,    22,
      23,    24,    25,    54,   189,    53,   191,     5,     6,    24,
      25,    24,    25,    11,    12,    13,    33,    34,    14,    45,
      46,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    55,
      56,    57,    58,    90,    59,    60,    91,    63,    64,    65,
      66,    93,    67,    68,    69,    70,    61,    62,    59,    60,
      61,    62,    67,    68,    45,    46,    22,    23,   110,   111,
      61,    62,    65,    66,   108,    63,    64,    59,    60,    69,
      70,    67,    68,   113,   124,    50,    49,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   168,   169,
     175,   177,   179,   182,   183,   184,   188,   190,   192,   109,
     187,   114,     8,     0,    16,    17,     0,    48,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    36,    37
  };

  const short int
  JSONresultsParser::yycheck_[] =
  {
      51,    52,   113,    51,    52,   119,   119,   119,   140,    18,
     140,     9,    10,     4,   146,   145,   113,     8,   119,   141,
     142,   143,   144,   145,   146,    29,    30,     4,     3,   140,
      39,     8,     0,    37,    38,   146,     6,   113,     4,   153,
     153,   153,   156,   140,     3,    96,   159,    98,   145,   179,
      98,   183,   153,    15,    16,    17,   188,     5,    20,   110,
     182,     6,   184,     6,   140,   141,   142,     3,   190,     6,
     192,   185,   183,   186,     5,   189,     4,   188,   191,   140,
     141,   142,   179,    18,    19,     4,   137,   138,   139,   137,
     138,   139,   168,   169,    27,    28,    29,    30,     6,   175,
       7,   177,    35,    36,    37,    38,     7,   168,   169,    11,
      12,    13,    14,     6,   175,     5,   177,     9,    10,    13,
      14,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    23,
      24,    25,    26,     7,    27,    28,     8,    31,    32,    33,
      34,     3,    35,    36,    37,    38,    29,    30,    27,    28,
      29,    30,    35,    36,    21,    22,    11,    12,     4,     5,
      29,    30,    33,    34,     6,    31,    32,    27,    28,    37,
      38,    35,    36,     3,     5,    40,    39,     6,     6,     6,
       6,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,   103,
     173,   110,     3,    -1,     9,     9,    -1,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    21
  };

  const unsigned char
  JSONresultsParser::yystos_[] =
  {
       0,     3,    42,    43,     0,     9,    10,    44,    83,     4,
       6,    15,    16,    17,    20,    54,    86,    87,     3,     5,
       6,     6,    11,    12,    13,    14,    47,    48,    49,    50,
      84,    85,     3,    18,    19,    55,    88,    89,     5,     4,
       4,    45,    46,     6,     6,    21,    22,    56,    90,    50,
      49,     7,     7,     5,     6,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    83,    85,    86,    87,    88,    89,    90,
      91,    92,    94,    95,    96,    97,    98,    99,   100,   100,
       7,     8,    51,     3,    59,    53,    60,    58,     4,     8,
      52,    63,   100,     4,     8,    57,   100,    62,     6,    59,
       4,     5,    61,     3,    63,    64,    80,    81,    82,    93,
      94,    95,    98,    99,     5,    65,    66,    67,    68,    69,
      70,    74,    91,    92,    96,    97,     6,     6,     6,     6,
       4,     4,     4,     4,     4,     4,     4,   100,   100,   100,
      76,    81,    82,    93,    78,    80,    93,    79,    80,    93,
      80,    80,    73,    80,    82,    75,    80,    81,     4,     4,
      77,    91,    92,    96,    97,     4,    97,     4,    96,     4,
      71,    72,     4,     4,     4,    93,    93,    72,     4,    93,
       4,    93,     4,    82,    80,    81,    80,    97,    96,    81,
      97,    80,    96,    80
  };

  const unsigned char
  JSONresultsParser::yyr1_[] =
  {
       0,    41,    43,    42,    44,    45,    46,    46,    47,    47,
      48,    48,    49,    51,    50,    52,    53,    53,    54,    54,
      55,    55,    56,    57,    58,    58,    60,    59,    61,    62,
      62,    63,    64,    64,    64,    64,    65,    64,    66,    64,
      67,    64,    68,    69,    70,    71,    72,    72,    73,    73,
      74,    75,    75,    76,    76,    76,    77,    77,    77,    77,
      78,    78,    79,    79,    80,    81,    82,    83,    83,    84,
      84,    85,    85,    86,    86,    87,    87,    88,    89,    90,
      90,    91,    91,    92,    92,    93,    94,    94,    95,    95,
      96,    96,    97,    97,    98,    98,    99,    99,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100
  };

  const unsigned char
  JSONresultsParser::yyr2_[] =
  {
       0,     2,     0,     6,     5,     2,     0,     1,     3,     2,
       0,     1,     5,     0,     7,     2,     0,     2,     5,     3,
       1,     1,     6,     2,     0,     2,     0,     5,     2,     0,
       2,     5,     2,     2,     2,     2,     0,     4,     0,     4,
       0,     4,     3,     3,     3,     2,     0,     1,     3,     2,
       3,     3,     3,     2,     4,     4,     1,     1,     2,     3,
       4,     4,     4,     4,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const JSONresultsParser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "GT_LCURLEY", "GT_COMMA",
  "GT_RCURLEY", "GT_COLON", "GT_LBRACKET", "GT_RBRACKET",
  "GT_H_22__head_H_22_", "GT_H_27__head_H_27_", "GT_H_22__link_H_22_",
  "GT_H_27__link_H_27_", "GT_H_22__vars_H_22_", "GT_H_27__vars_H_27_",
  "GT_H_22__results_H_22_", "GT_H_22__boolean_H_22_",
  "GT_H_27__boolean_H_27_", "IT_false", "IT_true",
  "GT_H_27__results_H_27_", "GT_H_22__bindings_H_22_",
  "GT_H_27__bindings_H_27_", "GT_H_22__uri_H_22_", "GT_H_27__uri_H_27_",
  "GT_H_22__bnode_H_22_", "GT_H_27__bnode_H_27_", "GT_H_22__type_H_22_",
  "GT_H_27__type_H_27_", "GT_H_22__value_H_22_", "GT_H_27__value_H_27_",
  "GT_H_22__literal_H_22_", "GT_H_27__literal_H_27_",
  "GT_H_22__typed_MINUS_literal_H_22_",
  "GT_H_27__typed_MINUS_literal_H_27_", "GT_H_22__datatype_H_22_",
  "GT_H_27__datatype_H_27_", "GT_H_22__xml_COLON_lang_H_22_",
  "GT_H_27__xml_COLON_lang_H_27_", "STRING_LITERAL2", "STRING_LITERAL1",
  "$accept", "Top", "$@1", "head", "_O_QGT_COMMA_E_S_Q_link_E_C",
  "_Q_O_QGT_COMMA_E_S_Q_link_E_C_E_Opt",
  "_O_Q_link_E_S_QGT_COMMA_E_S_Qvars_E_Or_Qvars_E_S_QGT_COMMA_E_S_Q_link_E_Opt_C",
  "_Q_O_Q_link_E_S_QGT_COMMA_E_S_Qvars_E_Or_Qvars_E_S_QGT_COMMA_E_S_Q_link_E_Opt_C_E_Opt",
  "_link", "vars", "$@2", "_O_QGT_COMMA_E_S_Qword_E_C",
  "_Q_O_QGT_COMMA_E_S_Qword_E_C_E_Star", "results",
  "_O_QtrueWord_E_Or_QfalseWord_E_C", "bindings",
  "_O_QGT_COMMA_E_S_Qsolution_E_C",
  "_Q_O_QGT_COMMA_E_S_Qsolution_E_C_E_Star", "solution", "$@3",
  "_O_QGT_COMMA_E_S_Qbinding_E_C",
  "_Q_O_QGT_COMMA_E_S_Qbinding_E_C_E_Star", "binding", "RDFterm", "$@4",
  "$@5", "$@6", "t_uri", "t_bnode", "t_plainLiteral",
  "_O_QGT_COMMA_E_S_Qlang_E_C", "_Q_O_QGT_COMMA_E_S_Qlang_E_C_E_Opt",
  "_O_Qlang_E_S_QGT_COMMA_E_S_Qvalue_E_Or_Qvalue_E_S_QGT_COMMA_E_S_Qlang_E_Opt_C",
  "t_typedLiteral",
  "_O_Qdatatype_E_S_QGT_COMMA_E_S_Qvalue_E_Or_Qvalue_E_S_QGT_COMMA_E_S_Qdatatype_E_C",
  "v_all", "vt_all", "d_typedLiteral", "l_plainLiteral", "value",
  "datatype", "lang", "headWord", "linkWord", "varsWord", "resultsWord",
  "booleanWord", "trueWord", "falseWord", "bindingsWord", "uriWord",
  "bnodeWord", "typeKey", "typeWord", "valueWord", "literalWord",
  "typedLiteralWord", "datatypeWord", "langWord", "word", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  JSONresultsParser::yyrline_[] =
  {
       0,   230,   230,   230,   242,   246,   249,   251,   255,   256,
     259,   261,   265,   272,   272,   279,   285,   287,   291,   292,
     300,   304,   311,   315,   318,   320,   324,   324,   332,   335,
     337,   341,   348,   351,   354,   357,   360,   360,   366,   366,
     372,   372,   381,   388,   395,   401,   407,   410,   414,   419,
     427,   433,   437,   444,   447,   452,   461,   465,   469,   474,
     481,   485,   492,   497,   505,   511,   518,   524,   525,   529,
     530,   534,   535,   539,   540,   544,   545,   549,   553,   557,
     558,   562,   563,   567,   568,   572,   576,   577,   581,   582,
     586,   587,   591,   592,   596,   597,   601,   602,   606,   607,
     608,   611,   614,   617,   620,   623,   626,   629,   632,   635,
     638,   641,   644,   647,   650
  };

  // Print the state stack on the debug stream.
  void
  JSONresultsParser::yystack_print_ ()
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
  JSONresultsParser::yy_reduce_print_ (int yyrule)
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
  JSONresultsParser::token_number_type
  JSONresultsParser::yytranslate_ (int t)
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
      35,    36,    37,    38,    39,    40
    };
    const unsigned int user_token_number_max_ = 295;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // w3c_sw
#line 1755 "lib/JSONresultsParser.cpp" // lalr1.cc:1167
#line 657 "lib/JSONresultsParser.ypp" // lalr1.cc:1168
 /*** Additional Code ***/

void w3c_sw::JSONresultsParser::error(const JSONresultsParser::location_type& l,
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
    driver.error(l, m);
}

/* START Driver (@@ stand-alone would allow it to be shared with other parsers */

namespace w3c_sw {

    JSONresultsDriver::JSONresultsDriver (AtomFactory* atomFactory) : 
	YaccDriver("", atomFactory), 
	curResultSet(NULL), curResult(NULL), curValue(NULL), 
	curDatatype(NULL), curLang(NULL), root(NULL)
{
}

    JSONresultsDriver::~JSONresultsDriver ()
{
}

const ResultSet* JSONresultsDriver::parse (IStreamContext& in, ResultSet* rs)
{
    root = curResultSet = rs;
    curResult = NULL;
    curValue = NULL;
    curDatatype = NULL;
    curLang = NULL;
    streamname = in.nameStr;

    JSONresultsScanner scanner(this, in.p);
    scanner.set_debug(trace_scanning);
    lexer = &scanner;

    JSONresultsParser parser(*this);
    parser.set_debug_level(trace_parsing);
    // !!! Clear out namespaces!
    ignorePrefixFlag = false;
    parser.parse();
    return root;
}

const ResultSet* JSONresultsDriver::parse (std::string queryStr, ResultSet* rs)
{
    IStreamContext in(queryStr.c_str(), IStreamContext::STRING);
    return parse(in, rs);
}


} // namespace w3c_sw

/* END Driver */

