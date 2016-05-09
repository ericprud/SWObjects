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

#line 39 "lib/ShExCParser.cpp" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "ShExCParser.hpp"

// User implementation prologue.
#line 138 "lib/ShExCParser.ypp" // lalr1.cc:412

#include "ShExCScanner.hpp"
#line 187 "lib/ShExCParser.ypp" // lalr1.cc:412

#include "ShExCScanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lexWrapper

#line 65 "lib/ShExCParser.cpp" // lalr1.cc:412


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
#line 151 "lib/ShExCParser.cpp" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  ShExParser::yytnamerr_ (const char *yystr)
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
  ShExParser::ShExParser (class ShExDriver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

  ShExParser::~ShExParser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  ShExParser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  ShExParser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  ShExParser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    value = other.value;
  }


  template <typename Base>
  inline
  ShExParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  ShExParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  inline
  ShExParser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  ShExParser::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  ShExParser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  ShExParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  inline
  ShExParser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  ShExParser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  ShExParser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  ShExParser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  ShExParser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  ShExParser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  ShExParser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  ShExParser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  ShExParser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  ShExParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  ShExParser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  ShExParser::symbol_number_type
  ShExParser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  ShExParser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  ShExParser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    value = that.value;
    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  ShExParser::stack_symbol_type&
  ShExParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  ShExParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  ShExParser::yy_print_ (std::ostream& yyo,
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
  ShExParser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  ShExParser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  ShExParser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  ShExParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  ShExParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  ShExParser::debug_level_type
  ShExParser::debug_level () const
  {
    return yydebug_;
  }

  void
  ShExParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline ShExParser::state_type
  ShExParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  ShExParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  ShExParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  ShExParser::parse ()
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
    #line 31 "lib/ShExCParser.ypp" // lalr1.cc:741
{
    // initialize the initial location object
    yyla.location.begin.filename = yyla.location.end.filename = &driver.streamname;
    driver.yylloc = &yyla.location;
}

#line 531 "lib/ShExCParser.cpp" // lalr1.cc:741

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
  case 9:
#line 218 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	driver.curSchema->start = (yystack_[0].value.p_TTerm);
    }
#line 643 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 10:
#line 224 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ruleActions) = NULL;
    }
#line 651 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 11:
#line 227 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ruleActions) = ((yystack_[1].value.p_ruleActions) == NULL)
	    ? new ShExSchema::RuleActions(driver.curRulePattern)
	    : (yystack_[1].value.p_ruleActions);
	(yylhs.value.p_ruleActions)->codeMap.insert(std::make_pair(*(yystack_[0].value.p_CODE).label, *(yystack_[0].value.p_CODE).text));
	delete (yystack_[0].value.p_CODE).label;
	delete (yystack_[0].value.p_CODE).text;
    }
#line 664 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 13:
#line 239 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	driver.curRulePattern = (yystack_[0].value.p_rulePattern);
      }
#line 672 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 14:
#line 241 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	  driver.curRulePattern = NULL;
	  (yylhs.value.p_TTerm) = driver.createBNode();
	  driver.curSchema->ruleMap.insert(std::make_pair((yylhs.value.p_TTerm), (yystack_[0].value.p_ruleActions) == NULL ? (yystack_[2].value.p_rulePattern) : (yystack_[0].value.p_ruleActions)));
      }
#line 682 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 15:
#line 249 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	driver.setBase((yystack_[0].value.p_URI)->getLexicalValue());
    }
#line 690 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 16:
#line 255 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	driver.ignorePrefix(true);
      }
#line 698 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 17:
#line 257 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	  driver.ignorePrefix(false);
      }
#line 706 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 18:
#line 259 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	  std::string prefix((yystack_[2].value.p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yystack_[0].value.p_URI));
      }
#line 715 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 19:
#line 266 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	driver.curRulePattern = (yystack_[0].value.p_rulePattern);
      }
#line 723 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 20:
#line 268 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	  driver.curRulePattern = NULL;
	  driver.curSchema->ruleMap.insert(std::make_pair((yystack_[3].value.p_TTerm), (yystack_[0].value.p_ruleActions) == NULL ? (yystack_[2].value.p_rulePattern) : (yystack_[0].value.p_ruleActions)));
      }
#line 732 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 21:
#line 275 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_nameClass) = driver.curNameClass;
	driver.curNameClass = NULL;
      }
#line 741 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 22:
#line 278 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_rulePattern) = driver.curRulePattern;
	  driver.curRulePattern = NULL;
      }
#line 750 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 23:
#line 281 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	  driver.curRulePattern = (yystack_[2].value.p_rulePattern);
	  driver.curNameClass = (yystack_[3].value.p_nameClass);
	  (yylhs.value.p_rulePattern) = (yystack_[1].value.p_rulePattern);
      }
#line 760 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 24:
#line 289 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_setRule) = driver.curSetRule;
	driver.curSetRule = NULL;
    }
#line 769 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 25:
#line 292 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	if (driver.curSetRule == NULL)
	    (yylhs.value.p_rulePattern) = (yystack_[1].value.p_rulePattern);
	else {
	    driver.curSetRule->rules.insert(driver.curSetRule->rules.begin(), (yystack_[1].value.p_rulePattern));
	    (yylhs.value.p_rulePattern) = driver.curSetRule;
	}
	driver.curSetRule = (yystack_[2].value.p_setRule);
    }
#line 783 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 26:
#line 304 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_rulePattern) = (yystack_[0].value.p_rulePattern);
    }
#line 791 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 28:
#line 311 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	if (driver.curSetRule == NULL)
	    driver.curSetRule = new ShExSchema::OrRule();
	driver.curSetRule->rules.push_back((yystack_[0].value.p_rulePattern));
    }
#line 801 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 29:
#line 319 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_setRule) = driver.curSetRule;
	driver.curSetRule = NULL;
    }
#line 810 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 30:
#line 322 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	if (driver.curSetRule == NULL)
	    (yylhs.value.p_rulePattern) = (yystack_[1].value.p_rulePattern);
	else {
	    driver.curSetRule->rules.insert(driver.curSetRule->rules.begin(), (yystack_[1].value.p_rulePattern));
	    (yylhs.value.p_rulePattern) = driver.curSetRule;
	}
	driver.curSetRule = (yystack_[2].value.p_setRule);
    }
#line 824 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 31:
#line 334 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_rulePattern) = (yystack_[0].value.p_rulePattern);
    }
#line 832 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 33:
#line 341 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	if (driver.curSetRule == NULL)
	    driver.curSetRule = new ShExSchema::AndRule();
	driver.curSetRule->rules.push_back((yystack_[0].value.p_rulePattern));
    }
#line 842 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 34:
#line 349 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	// $$ = $1 ? new ShExSchema::NegatedRule($2) : $2;
	// @@ $1 is a label
	(yylhs.value.p_rulePattern) = (yystack_[0].value.p_rulePattern);
    }
#line 852 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 38:
#line 367 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_bool) = false;
    }
#line 860 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 39:
#line 370 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
        (yylhs.value.p_bool) = true;
    }
#line 868 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 41:
#line 379 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	driver.curRulePattern = (yystack_[1].value.p_rulePattern);
      }
#line 876 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 42:
#line 381 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	  // @@ set flag from $5
	  driver.curRulePattern = NULL;
	  (yylhs.value.p_rulePattern) = (yystack_[0].value.p_ruleActions) == NULL ? (yystack_[4].value.p_rulePattern) : (yystack_[0].value.p_ruleActions);
      }
#line 886 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 43:
#line 389 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_URI);
    }
#line 894 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 44:
#line 392 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_TTerm);
    }
#line 902 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 45:
#line 398 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	// pass down the nameClass 'cause we need valueSpec's CODE* to be able
	// to make a AtomicRule and potentially wrap it with RuleActions.
	driver.curNameClass = (yystack_[0].value.p_nameClass);
	(yystack_[0].value.p_nameClass)->reverse = (yystack_[1].value.p_bool);
      }
#line 913 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 46:
#line 403 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	  if ((yystack_[1].value.p_TTerm))
	      w3c_sw_NEED_IMPL("ShEx parser support for default");
	  driver.curRulePattern = new ShExSchema::AtomicRule(driver.curNameClass, (yystack_[2].value.p_value), (yystack_[0].value.p_RepeatRange).min, (yystack_[0].value.p_RepeatRange).max);
      }
#line 923 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 47:
#line 407 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_rulePattern) = (yystack_[0].value.p_ruleActions) == NULL ? driver.curRulePattern : (yystack_[0].value.p_ruleActions);
	  driver.curRulePattern = NULL;
	  driver.curNameClass = NULL;
	}
#line 933 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 48:
#line 424 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_bool) = false;
    }
#line 941 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 49:
#line 427 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_bool) = true;
    }
#line 949 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 50:
#line 433 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = NULL;
    }
#line 957 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 52:
#line 440 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_RepeatRange).min = 1;
	(yylhs.value.p_RepeatRange).max = 1;
    }
#line 966 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 56:
#line 455 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	if ((yystack_[0].value.p_URIstem).opt)
	    (yylhs.value.p_nameClass) = new ShExSchema::AtomicRule::NamePattern((yystack_[0].value.p_URIstem).uri);
	else
	    (yylhs.value.p_nameClass) = new ShExSchema::AtomicRule::NameTerm((yystack_[0].value.p_URIstem).uri);
    }
#line 977 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 57:
#line 461 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_nameClass) = new ShExSchema::AtomicRule::NameAll((yystack_[0].value.p_URIstems));
    }
#line 985 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 58:
#line 464 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_nameClass) = new ShExSchema::AtomicRule::NameTerm(TTerm::RDF_type);
    }
#line 993 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 59:
#line 470 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_value) = new ShExSchema::AtomicRule::ValueReference((yystack_[0].value.p_TTerm));
    }
#line 1001 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 60:
#line 473 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	const TTerm* b = driver.createBNode();
	driver.curSchema->ruleMap.insert(std::make_pair(b, (yystack_[0].value.p_rulePattern)));
	(yylhs.value.p_value) = new ShExSchema::AtomicRule::ValueReference(b);
    }
#line 1011 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 61:
#line 478 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_value) = new ShExSchema::AtomicRule::ValueType((yystack_[0].value.p_URI));
    }
#line 1019 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 62:
#line 481 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	ShExSchema::AtomicRule::ValueSet* t = new ShExSchema::AtomicRule::ValueSet();
	(yylhs.value.p_valueSet)  = t;
	driver.curTTerms = &t->tterms;
      }
#line 1029 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 63:
#line 485 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_value) = (yystack_[1].value.p_valueSet);
      }
#line 1037 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 64:
#line 488 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_value) = new ShExSchema::AtomicRule::ValueAny((yystack_[0].value.p_URIstems));
    }
#line 1045 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 65:
#line 491 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
        w3c_sw_NEED_IMPL("SPARQL Results Format callout");
    }
#line 1053 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 66:
#line 497 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_URIstem).uri = (yystack_[1].value.p_URI);
	(yylhs.value.p_URIstem).opt = (yystack_[0].value.p_bool);
    }
#line 1062 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 67:
#line 504 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_bool) = false;
    }
#line 1070 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 68:
#line 507 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
        (yylhs.value.p_bool) = true;
    }
#line 1078 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 69:
#line 513 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_TTerm);
    }
#line 1086 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 70:
#line 519 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_URI);
    }
#line 1094 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 83:
#line 570 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_TTerm);
	driver.curPredicate = (yylhs.value.p_TTerm);
    }
#line 1103 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 84:
#line 574 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
      (yylhs.value.p_TTerm) = TTerm::RDF_type;
	driver.curPredicate = (yylhs.value.p_TTerm);
    }
#line 1112 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 85:
#line 581 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_URI);
    }
#line 1120 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 86:
#line 587 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yystack_[0].value.p_URI)));
    }
#line 1128 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 87:
#line 590 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yystack_[0].value.p_TTerm)));
    }
#line 1136 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 88:
#line 593 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yystack_[0].value.p_TTerm)));
    }
#line 1144 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 89:
#line 596 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yystack_[0].value.p_TTerm)));
    }
#line 1152 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 90:
#line 599 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yystack_[0].value.p_TTerm)));
    }
#line 1160 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 94:
#line 611 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_SubjectPredicatePair).subject = driver.curSubject;
	(yylhs.value.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
#line 1170 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 95:
#line 615 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_TTerm) = (BNode*)driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yystack_[2].value.p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yystack_[2].value.p_SubjectPredicatePair).predicate;
      }
#line 1180 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 96:
#line 624 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_SubjectPredicatePair).subject = driver.curSubject;
	(yylhs.value.p_SubjectPredicatePair).predicate = driver.curPredicate;
      }
#line 1189 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 97:
#line 627 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	  if ((yystack_[1].value.p_TTerm) == NULL) {
	      (yylhs.value.p_TTerm) = TTerm::RDF_nil;
	  } else {
	      (yylhs.value.p_TTerm) = (yystack_[1].value.p_TTerm);
	      driver.curBGP->addTriplePattern
		  (driver.atomFactory->getTriple
		   (driver.curSubject, TTerm::RDF_rest, TTerm::RDF_nil));
	  }
	  driver.curSubject = (yystack_[2].value.p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yystack_[2].value.p_SubjectPredicatePair).predicate;
      }
#line 1206 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 98:
#line 642 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = NULL;
    }
#line 1214 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 99:
#line 645 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	const TTerm* nextTail = driver.createBNode();
	if ((yystack_[0].value.p_TTerm) == NULL) // on first element
	    (yylhs.value.p_TTerm) = nextTail;
	else		// on later elements
	    driver.curBGP->addTriplePattern
		(driver.atomFactory->getTriple
		 (driver.curSubject, TTerm::RDF_rest, nextTail));
	driver.curSubject = nextTail;
	driver.curPredicate = TTerm::RDF_first;
      }
#line 1230 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 100:
#line 655 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_TTerm) = (yystack_[1].value.p_TTerm);
      }
#line 1238 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 102:
#line 665 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_URIstem) = (yystack_[0].value.p_URIstem);
    }
#line 1246 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 103:
#line 671 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_URIstems) = NULL;
    }
#line 1254 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 104:
#line 674 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	if ((yystack_[1].value.p_URIstems) == NULL)
	    (yystack_[1].value.p_URIstems) = new std::vector<ShExSchema::URIstem>();
	(yystack_[1].value.p_URIstems)->push_back((yystack_[0].value.p_URIstem));
	(yylhs.value.p_URIstems) = (yystack_[1].value.p_URIstems);
    }
#line 1265 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 105:
#line 685 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_RepeatRange).min = 0;
	(yylhs.value.p_RepeatRange).max = ShExSchema::AtomicRule::Unlimited;
    }
#line 1274 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 106:
#line 689 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_RepeatRange).min = 1;
	(yylhs.value.p_RepeatRange).max = ShExSchema::AtomicRule::Unlimited;
    }
#line 1283 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 107:
#line 693 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_RepeatRange).min = 0;
	(yylhs.value.p_RepeatRange).max = 1;
    }
#line 1292 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 108:
#line 697 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_RepeatRange).min = (yystack_[2].value.p_NumericRDFLiteral)->getInt();
	(yylhs.value.p_RepeatRange).max = (yystack_[1].value.p_int);
    }
#line 1301 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 109:
#line 704 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_int) = ShExSchema::AtomicRule::Unlimited;
    }
#line 1309 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 110:
#line 707 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_int) = (yystack_[0].value.p_NumericRDFLiteral)->getInt();
    }
#line 1317 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 111:
#line 713 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_int) = (yystack_[0].value.p_int);
    }
#line 1325 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 112:
#line 719 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_int) = ShExSchema::AtomicRule::Unlimited;
    }
#line 1333 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 115:
#line 730 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	driver.curTTerms->push_back((yystack_[0].value.p_TTerm));
    }
#line 1341 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 116:
#line 733 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	driver.curTTerms->push_back((yystack_[0].value.p_TTerm));
    }
#line 1349 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 117:
#line 739 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	if ((yystack_[0].value.p_URIstem).opt)
	    w3c_sw_NEED_IMPL("ShEx parser support for URIstems in value sets");
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_URIstem).uri;
    }
#line 1359 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 120:
#line 749 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_NumericRDFLiteral);
    }
#line 1367 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 121:
#line 752 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_NumericRDFLiteral);
    }
#line 1375 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 122:
#line 755 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_NumericRDFLiteral);
    }
#line 1383 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 123:
#line 762 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = driver.getRDFLiteral(*(yystack_[1].value.p_string), (yystack_[0].value.p_uri_or_langtag).uri, (yystack_[0].value.p_uri_or_langtag).langtag);
	delete (yystack_[1].value.p_string);
    }
#line 1392 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 124:
#line 770 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_uri_or_langtag).uri = NULL;
	(yylhs.value.p_uri_or_langtag).langtag = (yystack_[0].value.p_LANGTAG);
    }
#line 1401 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 125:
#line 775 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_uri_or_langtag).uri = (yystack_[0].value.p_URI);
	(yylhs.value.p_uri_or_langtag).langtag = NULL;
    }
#line 1410 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;

  case 126:
#line 783 "lib/ShExCParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_uri_or_langtag).uri = NULL;
	(yylhs.value.p_uri_or_langtag).langtag = NULL;
    }
#line 1419 "lib/ShExCParser.cpp" // lalr1.cc:859
    break;


#line 1423 "lib/ShExCParser.cpp" // lalr1.cc:859
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
  ShExParser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  ShExParser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
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


  const short int ShExParser::yypact_ninf_ = -142;

  const signed char ShExParser::yytable_ninf_ = -1;

  const short int
  ShExParser::yypact_[] =
  {
    -142,    27,     4,  -142,    44,    -8,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,    45,  -142,  -142,
    -142,     9,  -142,    19,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,    21,  -142,    36,    36,  -142,    57,  -142,
    -142,  -142,  -142,    62,    65,    16,  -142,  -142,    15,  -142,
    -142,  -142,    69,  -142,  -142,  -142,  -142,    26,  -142,    62,
    -142,    61,  -142,  -142,  -142,  -142,    63,  -142,  -142,  -142,
      58,    -3,  -142,  -142,    68,    16,  -142,  -142,    30,    16,
    -142,    79,    71,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
     153,    -1,  -142,   139,  -142,    36,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
     -14,  -142,    52,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
     115,  -142,  -142,    16,  -142,  -142,  -142,    76,    66,  -142,
    -142,  -142,    56,  -142,    83,  -142,  -142,  -142,  -142,  -142,
    -142,    -9,    36,  -142,    70,    77,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,    74,    85,
      82,    -9,  -142,    77,  -142,  -142,    77,  -142,  -142,    77,
    -142,  -142,  -142
  };

  const unsigned char
  ShExParser::yydefact_[] =
  {
       3,     0,     2,     1,     0,     0,    16,   138,   139,   137,
     136,   134,     4,     5,     7,     8,     6,     0,    43,   135,
      44,     0,    15,     0,    21,    19,     9,    13,    12,    17,
      22,    10,    10,     0,    24,    20,    14,    18,     0,    29,
      11,    23,    27,    36,    25,     0,    32,    37,    48,    29,
      28,    35,    30,    24,    49,    34,    40,     0,    26,    36,
      33,     0,   103,    58,    45,    56,    67,    31,    41,    57,
     101,    62,    68,    66,    38,     0,   104,   103,     0,     0,
      60,    50,     0,    61,    39,    10,   102,    64,    59,    65,
       0,    52,    51,     0,    63,    42,   128,   129,   120,   121,
     122,   130,   131,   132,   133,    69,    71,    92,    91,    93,
     126,    70,     0,   107,   105,   106,    46,    53,   117,   119,
       0,   115,   118,     0,   124,   127,   123,   112,    54,   114,
     116,   125,   109,   113,     0,    94,    10,    55,   110,   111,
     108,     0,    47,    84,     0,     0,    83,    85,    95,    96,
      77,    81,    90,    89,    88,    86,    87,    98,    72,    79,
      99,    74,    78,     0,    82,    97,     0,    75,    76,     0,
      80,   100,    73
  };

  const short int
  ShExParser::yypgoto_[] =
  {
    -142,  -142,  -142,  -142,  -142,   -31,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,   -16,  -142,  -142,    46,  -142,  -142,
    -142,    48,  -142,  -142,  -142,    41,  -142,  -142,  -142,  -142,
    -142,   -18,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,   -49,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,   -68,  -142,  -142,   -59,  -142,  -141,   -73,   -25,  -142,
    -142,  -142,  -142,  -142,    47,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,     2,  -142,  -142,  -142,  -142,  -142,  -142,
      -2,  -142,     0
  };

  const short int
  ShExParser::yydefgoto_[] =
  {
      -1,     1,     2,    12,    13,    35,    26,    32,    14,    15,
      23,    33,    16,    31,    25,    30,    34,    38,    39,    50,
      44,    42,    43,    60,    52,    46,    47,    48,    85,    55,
      74,    17,    56,    71,   128,    57,    91,   116,   136,    64,
      81,    82,   118,    73,    92,   105,   144,   167,   168,   162,
     158,   150,   164,   159,   145,   146,   151,   152,   153,   141,
     154,   157,   160,   166,    69,    76,    70,   117,   139,   133,
     134,    94,   120,   121,   107,   108,   125,   126,   109,   110,
      66,    19,   156
  };

  const unsigned char
  ShExParser::yytable_[] =
  {
      18,    36,    20,    28,    24,    27,   112,     4,    65,     5,
       6,   113,   123,    77,    78,    79,    24,   106,   143,    18,
     119,    20,   170,   114,   115,   171,    86,     3,    53,   124,
      54,     9,    10,    11,    22,     7,     8,     9,    10,    11,
       7,     8,    62,    51,     9,    10,    11,   119,    21,     9,
      10,    11,    24,    63,    95,    80,     9,    10,    11,    29,
      88,     7,     8,    37,    40,    41,     9,    10,    11,    83,
       9,    10,    11,    45,    49,    68,    18,    89,    20,    59,
      84,    75,    72,    90,    93,   127,   132,   135,   111,   138,
     149,   140,   148,   122,   161,   163,   165,    58,   135,    61,
      67,   172,   169,   137,     0,   142,    96,    97,     7,     8,
      98,    99,   100,   101,   102,   103,   104,     9,    10,    11,
     122,   131,   130,     0,    87,     0,     0,     0,     0,   129,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   147,
       0,     0,     0,   155,    96,    97,     7,     8,    98,    99,
     100,   101,   102,   103,   104,     9,    10,    11,     0,   147,
       0,   155,     0,     0,   155,     0,     0,   155,    96,    97,
       7,     8,    98,    99,   100,   101,   102,   103,   104,     9,
      10,    11,    96,    97,     0,     0,    98,    99,   100,   101,
     102,   103,   104,     9,    10,    11
  };

  const short int
  ShExParser::yycheck_[] =
  {
       2,    32,     2,    21,     7,    21,     7,     3,    57,     5,
       6,    12,    26,    16,    17,    18,     7,    90,    27,    21,
      93,    21,   163,    24,    25,   166,    75,     0,    13,    43,
      15,    40,    41,    42,    42,    31,    32,    40,    41,    42,
      31,    32,    16,    45,    40,    41,    42,   120,     4,    40,
      41,    42,     7,    27,    85,    71,    40,    41,    42,    40,
      78,    31,    32,    42,    28,     8,    40,    41,    42,    71,
      40,    41,    42,    11,     9,    14,    78,    79,    78,    10,
      12,    23,    19,     4,    13,    33,    10,    21,    90,    33,
      13,     8,    22,    93,    20,    10,    14,    49,    21,    53,
      59,   169,   161,   128,    -1,   136,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
     120,   123,   120,    -1,    77,    -1,    -1,    -1,    -1,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,
      -1,    -1,    -1,   145,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,   161,
      -1,   163,    -1,    -1,   166,    -1,    -1,   169,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    29,    30,    -1,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42
  };

  const unsigned char
  ShExParser::yystos_[] =
  {
       0,    45,    46,     0,     3,     5,     6,    31,    32,    40,
      41,    42,    47,    48,    52,    53,    56,    75,   124,   125,
     126,     4,    42,    54,     7,    58,    50,    58,    75,    40,
      59,    57,    51,    55,    60,    49,    49,    42,    61,    62,
      28,     8,    65,    66,    64,    11,    69,    70,    71,     9,
      63,   124,    68,    13,    15,    73,    76,    79,    65,    10,
      67,    61,    16,    27,    83,    86,   124,    69,    14,   108,
     110,    77,    19,    87,    74,    23,   109,    16,    17,    18,
      58,    84,    85,   124,    12,    72,    86,   108,    75,   124,
       4,    80,    88,    13,   115,    49,    29,    30,    33,    34,
      35,    36,    37,    38,    39,    89,   101,   118,   119,   122,
     123,   124,     7,    12,    24,    25,    81,   111,    86,   101,
     116,   117,   126,    26,    43,   120,   121,    33,    78,    14,
     117,   124,    10,   113,   114,    21,    82,   102,    33,   112,
       8,   103,    49,    27,    90,    98,    99,   124,    22,    13,
      95,   100,   101,   102,   104,   124,   126,   105,    94,    97,
     106,    20,    93,    10,    96,    14,   107,    91,    92,    98,
     100,   100,    95
  };

  const unsigned char
  ShExParser::yyr1_[] =
  {
       0,    44,    45,    46,    46,    47,    47,    48,    48,    48,
      49,    49,    50,    51,    50,    52,    54,    55,    53,    57,
      56,    59,    60,    58,    62,    61,    63,    64,    64,    66,
      65,    67,    68,    68,    69,    70,    71,    71,    72,    72,
      73,    74,    73,    75,    75,    77,    78,    76,    79,    79,
      80,    80,    81,    81,    82,    82,    83,    83,    83,    84,
      84,    84,    85,    84,    84,    84,    86,    87,    87,    88,
      89,    89,    90,    91,    92,    92,    93,    94,    94,    95,
      96,    97,    97,    98,    98,    99,   100,   100,   100,   100,
     100,   101,   101,   101,   103,   102,   105,   104,   106,   107,
     106,   108,   109,   110,   110,   111,   111,   111,   111,   112,
     112,   113,   114,   114,   115,   116,   116,   117,   117,   117,
     118,   118,   118,   119,   120,   120,   121,   121,   122,   122,
     123,   123,   123,   123,   124,   124,   125,   125,   126,   126
  };

  const unsigned char
  ShExParser::yyr2_[] =
  {
       0,     2,     1,     0,     2,     1,     1,     1,     1,     3,
       0,     2,     1,     0,     3,     2,     0,     0,     5,     0,
       4,     0,     0,     5,     0,     3,     2,     0,     2,     0,
       3,     2,     0,     2,     2,     2,     0,     1,     0,     1,
       1,     0,     6,     1,     1,     0,     0,     9,     0,     1,
       0,     1,     0,     1,     0,     1,     1,     2,     1,     2,
       1,     1,     0,     2,     2,     2,     2,     0,     1,     2,
       1,     1,     3,     2,     0,     1,     2,     0,     2,     2,
       2,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     4,     0,     4,     0,     0,
       3,     1,     2,     0,     2,     1,     1,     1,     4,     0,
       1,     2,     0,     1,     3,     1,     2,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const ShExParser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "IT_start", "GT_EQUAL",
  "IT_BASE", "IT_PREFIX", "GT_LCURLEY", "GT_RCURLEY", "GT_PIPE",
  "GT_COMMA", "GT_DOLLAR", "GT_OPT", "GT_LPAREN", "GT_RPAREN", "GT_CARROT",
  "GT_DOT", "GT_AT", "IT_SPARQL_SRX", "GT_KINDA", "GT_SEMI", "GT_LBRACKET",
  "GT_RBRACKET", "GT_MINUS", "GT_TIMES", "GT_PLUS", "GT_DTYPE", "RDF_TYPE",
  "CODE", "IT_true", "IT_false", "BLANK_NODE_LABEL", "ANON", "INTEGER",
  "DECIMAL", "DOUBLE", "STRING_LITERAL1", "STRING_LITERAL2",
  "STRING_LITERAL_LONG1", "STRING_LITERAL_LONG2", "PNAME_NS", "PNAME_LN",
  "IRIREF", "LANGTAG", "$accept", "ShExDoc", "_Qstatement_E_Star",
  "statement", "directive", "_QCODE_E_Star",
  "_O_Qlabel_E_Or_QtypeSpec_E_S_QCODE_E_Star_C", "$@1", "BaseDecl",
  "PrefixDecl", "$@2", "$@3", "shape", "$@4", "typeSpec", "@5", "@6",
  "OrExpression", "@7", "_O_QGT_PIPE_E_S_QAndExpression_E_C",
  "_Q_O_QGT_PIPE_E_S_QAndExpression_E_C_E_Star", "AndExpression", "@8",
  "_O_QGT_COMMA_E_S_QUnaryExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QUnaryExpression_E_C_E_Star", "UnaryExpression",
  "_O_QGT_DOLLAR_E_S_Qiri_E_C", "_Q_O_QGT_DOLLAR_E_S_Qiri_E_C_E_Opt",
  "_QGT_OPT_E_Opt",
  "_O_Qarc_E_Or_QGT_LPAREN_E_S_QOrExpression_E_S_QGT_RPAREN_E_S_QGT_OPT_E_Opt_S_QCODE_E_Star_C",
  "$@9", "label", "arc", "$@10", "$@11", "_QGT_CARROT_E_Opt",
  "_Qdefahlt_E_Opt", "_QrepeatCount_E_Opt",
  "_QblankNodePropertyList_E_Opt", "nameClass", "valueSpec", "@12",
  "iriStem", "_QGT_KINDA_E_Opt", "defahlt", "_O_Qiri_E_Or_Qliteral_E_C",
  "predicateObjectList", "_O_Qverb_E_S_QobjectList_E_C",
  "_Q_O_Qverb_E_S_QobjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_Qverb_E_S_QobjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_Qverb_E_S_QobjectList_E_Opt_C_E_Star", "objectList",
  "_O_QGT_COMMA_E_S_Qobject_E_C", "_Q_O_QGT_COMMA_E_S_Qobject_E_C_E_Star",
  "verb", "predicate", "object", "literal", "blankNodePropertyList", "@13",
  "collection", "@14", "_Qobject_E_Star", "@15", "exclusions",
  "_O_QGT_MINUS_E_S_QiriStem_E_C",
  "_Q_O_QGT_MINUS_E_S_QiriStem_E_C_E_Star", "repeatCount",
  "_QINTEGER_E_Opt", "_O_QGT_COMMA_E_S_QINTEGER_E_Opt_C",
  "_Q_O_QGT_COMMA_E_S_QINTEGER_E_Opt_C_E_Opt", "valueSet",
  "_Qvalue_E_Plus", "valueChoice", "NumericLiteral", "RDFLiteral",
  "_O_QLANGTAG_E_Or_QGT_DTYPE_E_S_Qiri_E_C",
  "_Q_O_QLANGTAG_E_Or_QGT_DTYPE_E_S_Qiri_E_C_E_Opt", "BooleanLiteral",
  "String", "iri", "PrefixedName", "BlankNode", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  ShExParser::yyrline_[] =
  {
       0,   202,   202,   205,   207,   211,   212,   216,   217,   218,
     224,   227,   238,   239,   239,   249,   255,   257,   255,   266,
     266,   275,   278,   275,   289,   289,   304,   309,   311,   319,
     319,   334,   339,   341,   349,   358,   361,   363,   367,   370,
     378,   379,   379,   389,   392,   398,   403,   398,   424,   427,
     433,   436,   440,   444,   448,   450,   455,   461,   464,   470,
     473,   478,   481,   481,   488,   491,   497,   504,   507,   513,
     519,   522,   528,   533,   537,   539,   544,   548,   550,   555,
     560,   564,   566,   570,   574,   581,   587,   590,   593,   596,
     599,   605,   606,   607,   611,   611,   624,   624,   642,   645,
     645,   661,   665,   671,   674,   685,   689,   693,   697,   704,
     707,   713,   719,   722,   726,   730,   733,   739,   744,   745,
     749,   752,   755,   762,   770,   775,   783,   787,   791,   792,
     796,   797,   798,   799,   803,   804,   808,   809,   813,   814
  };

  // Print the state stack on the debug stream.
  void
  ShExParser::yystack_print_ ()
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
  ShExParser::yy_reduce_print_ (int yyrule)
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
  ShExParser::token_number_type
  ShExParser::yytranslate_ (int t)
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
    };
    const unsigned int user_token_number_max_ = 298;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // w3c_sw
#line 2016 "lib/ShExCParser.cpp" // lalr1.cc:1167
#line 819 "lib/ShExCParser.ypp" // lalr1.cc:1168
 /*** Additional Code ***/

void w3c_sw::ShExParser::error(const ShExParser::location_type& l,
			    const std::string& m)
{
    std::string s = m;
    _SUBS(s, "GT_DOT", "'.'");
    _SUBS(s, "GT_SEMI", "';'");
    _SUBS(s, "GT_LBRACKET", "'['");
    _SUBS(s, "GT_RBRACKET", "']'");
    _SUBS(s, "GT_LPAREN", "'('");
    _SUBS(s, "GT_RPAREN", "')'");
    _SUBS(s, "GT_DTYPE", "'^^'");
    _SUBS(s, "IT_true", "boolean true");
    _SUBS(s, "IT_false", "boolean false");
    _SUBS(s, "IT_PREFIX", "PREFIX");
    _SUBS(s, "IT_BASE", "BASE");
    _SUBS(s, "BASE", "@base");
    _SUBS(s, "PREFIX", "@prefix");
    _SUBS(s, "RDF_TYPE", "keyword 'a'");
    _SUBS(s, "IRIREF", "IRI");
    _SUBS(s, "PNAME_NS", "namespace prefix");
    _SUBS(s, "PNAME_LN", "local name");
    _SUBS(s, "BLANK_NODE_LABEL", "blank node label");
    _SUBS(s, "LANGTAG", "language tag");
    _SUBS(s, "INTEGER", "integer");
    _SUBS(s, "DECIMAL", "decimal");
    _SUBS(s, "DOUBLE", "double");
    _SUBS(s, "STRING_LITERAL1", "'string'");
    _SUBS(s, "STRING_LITERAL2", "\"string\"");
    _SUBS(s, "STRING_LITERAL_LONG1", "'''string'''");
    _SUBS(s, "STRING_LITERAL_LONG2", "\"\"\"string\"\"\"");
    _SUBS(s, "ANON", "anonymous blank node");
    driver.error(l, s);
}

/* START Driver (@@ stand-alone would allow it to be shared with other parsers */

namespace w3c_sw {

size_t ShExDriver::DefaultAbortErrorCount = 100;

ShExSchema* ShExDriver::parse (IStreamContext& in) {
    reset();
    streamname = in.nameStr;
    // clear prefixes for nth run but keep them around for e.g. serialization.
    clearPrefixes();

    ShExScanner scanner(this, in.p);
    scanner.set_debug(trace_scanning);
    this->lexer = &scanner;

    ShExParser parser(*this);
    parser.set_debug_level(trace_parsing);
    parser.parse();
    checkErrors();
    return curSchema;
}

ShExSchema* ShExDriver::parse (IStreamContext& in, ShExSchema* schema) {
    setSchema(schema);
    return parse(in);
}

ShExSchema* ShExDriver::parse (std::string swsexStr, ShExSchema* schema) {
    IStreamContext in(swsexStr.c_str(), IStreamContext::STRING);
    setSchema(schema);
    return parse(in);
}

} // namespace w3c_sw

/* END Driver */

