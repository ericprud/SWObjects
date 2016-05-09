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

#line 39 "lib/TrigParser.cpp" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "TrigParser.hpp"

// User implementation prologue.
#line 127 "lib/TrigParser.ypp" // lalr1.cc:412

#include "TrigScanner.hpp"
#line 170 "lib/TrigParser.ypp" // lalr1.cc:412

#include "TrigScanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lexWrapper

#include "RdfDB.hpp"

#line 67 "lib/TrigParser.cpp" // lalr1.cc:412


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
#line 153 "lib/TrigParser.cpp" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  TrigParser::yytnamerr_ (const char *yystr)
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
  TrigParser::TrigParser (class TrigDriver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

  TrigParser::~TrigParser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  TrigParser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  TrigParser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  TrigParser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    value = other.value;
  }


  template <typename Base>
  inline
  TrigParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  TrigParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  inline
  TrigParser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  TrigParser::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  TrigParser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  TrigParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  inline
  TrigParser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  TrigParser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  TrigParser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  TrigParser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  TrigParser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  TrigParser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  TrigParser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  TrigParser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  TrigParser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  TrigParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  TrigParser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  TrigParser::symbol_number_type
  TrigParser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  TrigParser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  TrigParser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    value = that.value;
    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  TrigParser::stack_symbol_type&
  TrigParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  TrigParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  TrigParser::yy_print_ (std::ostream& yyo,
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
  TrigParser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  TrigParser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  TrigParser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  TrigParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  TrigParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  TrigParser::debug_level_type
  TrigParser::debug_level () const
  {
    return yydebug_;
  }

  void
  TrigParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline TrigParser::state_type
  TrigParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  TrigParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  TrigParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  TrigParser::parse ()
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
    #line 31 "lib/TrigParser.ypp" // lalr1.cc:741
{
    // initialize the initial location object
    yyla.location.begin.filename = yyla.location.end.filename = &driver.streamname;
    driver.yylloc = &yyla.location;
}

#line 533 "lib/TrigParser.cpp" // lalr1.cc:741

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
#line 187 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	driver.root = driver.defaultBGP;
	// driver.root = $<p_DefaultGraphPattern>1;
    }
#line 646 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 9:
#line 207 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	driver.curBGP = driver.db->ensureGraph(NULL);
	driver.neededBGP = NULL;
    }
#line 655 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 12:
#line 216 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	driver.curSubject = NULL;
      }
#line 663 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 14:
#line 223 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	driver.curBGP = driver.db->ensureGraph(NULL);
	driver.neededBGP = NULL;
      }
#line 672 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 16:
#line 230 "lib/TrigParser.ypp" // lalr1.cc:859
    {
      driver.curSubject = (yystack_[0].value.p_TTerm);
    }
#line 680 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 17:
#line 232 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	driver.curSubject = NULL;
      }
#line 688 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 18:
#line 235 "lib/TrigParser.ypp" // lalr1.cc:859
    {
      driver.curSubject = (yystack_[0].value.p_TTerm);
    }
#line 696 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 19:
#line 237 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	driver.curSubject = NULL;
      }
#line 704 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 22:
#line 249 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	driver.curBGP = driver.db->ensureGraph(driver.curSubject);
	driver.neededBGP = NULL;
      }
#line 713 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 23:
#line 252 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	  driver.curSubject = NULL;
      }
#line 721 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 27:
#line 264 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	driver.neededBGP = NULL;
    }
#line 729 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 31:
#line 279 "lib/TrigParser.ypp" // lalr1.cc:859
    {
      driver.curSubject = (yystack_[0].value.p_URI);
    }
#line 737 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 32:
#line 282 "lib/TrigParser.ypp" // lalr1.cc:859
    {
      driver.curSubject = (yystack_[0].value.p_TTerm);
    }
#line 745 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 37:
#line 297 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	driver.ignorePrefix(true);
      }
#line 753 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 38:
#line 299 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	  driver.ignorePrefix(false);
      }
#line 761 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 39:
#line 301 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	  std::string prefix((yystack_[2].value.p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yystack_[0].value.p_URI));
      }
#line 770 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 41:
#line 309 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	driver.setBase((yystack_[1].value.p_URI)->getLexicalValue());
    }
#line 778 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 42:
#line 316 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	driver.setBase((yystack_[0].value.p_URI)->getLexicalValue());
    }
#line 786 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 43:
#line 323 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	driver.ignorePrefix(true);
      }
#line 794 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 44:
#line 325 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	  driver.ignorePrefix(false);
      }
#line 802 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 45:
#line 327 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	  std::string prefix((yystack_[2].value.p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yystack_[0].value.p_URI));
      }
#line 811 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 46:
#line 335 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	driver.curSubject = (yystack_[0].value.p_TTerm);
    }
#line 819 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 48:
#line 338 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	driver.curSubject = (yystack_[0].value.p_TTerm);
    }
#line 827 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 61:
#line 383 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_TTerm);
	driver.curPredicate = (yylhs.value.p_TTerm);
    }
#line 836 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 62:
#line 387 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = TTerm::RDF_type;
	driver.curPredicate = (yylhs.value.p_TTerm);
    }
#line 845 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 63:
#line 394 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_URI);
    }
#line 853 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 65:
#line 401 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_URI);
    }
#line 861 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 66:
#line 407 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	if (!driver.curBGP)
	    driver.neededBGP = driver.curBGP = new DefaultGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yystack_[0].value.p_TTerm)));
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_TTerm);
    }
#line 872 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 67:
#line 416 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_URI);
    }
#line 880 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 76:
#line 436 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_SubjectPredicatePair).subject = driver.curSubject;
	(yylhs.value.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
#line 890 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 77:
#line 440 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_TTerm) = (BNode*)driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yystack_[2].value.p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yystack_[2].value.p_SubjectPredicatePair).predicate;
      }
#line 900 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 78:
#line 449 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_SubjectPredicatePair).subject = driver.curSubject;
	(yylhs.value.p_SubjectPredicatePair).predicate = driver.curPredicate;
      }
#line 909 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 79:
#line 452 "lib/TrigParser.ypp" // lalr1.cc:859
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
#line 926 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 80:
#line 472 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = NULL;
    }
#line 934 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 81:
#line 475 "lib/TrigParser.ypp" // lalr1.cc:859
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
#line 950 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 82:
#line 485 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_TTerm) = (yystack_[1].value.p_TTerm);
      }
#line 958 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 86:
#line 498 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = driver.getRDFLiteral(*(yystack_[1].value.p_string), (yystack_[0].value.p_uri_or_langtag).uri, (yystack_[0].value.p_uri_or_langtag).langtag);
	delete (yystack_[1].value.p_string);
    }
#line 967 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 87:
#line 506 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_uri_or_langtag).uri = NULL;
	(yylhs.value.p_uri_or_langtag).langtag = (yystack_[0].value.p_LANGTAG);
    }
#line 976 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 88:
#line 510 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_uri_or_langtag).uri = (yystack_[0].value.p_URI);
	(yylhs.value.p_uri_or_langtag).langtag = NULL;
    }
#line 985 "lib/TrigParser.cpp" // lalr1.cc:859
    break;

  case 89:
#line 518 "lib/TrigParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_uri_or_langtag).uri = NULL;
	(yylhs.value.p_uri_or_langtag).langtag = NULL;
    }
#line 994 "lib/TrigParser.cpp" // lalr1.cc:859
    break;


#line 998 "lib/TrigParser.cpp" // lalr1.cc:859
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
  TrigParser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  TrigParser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
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


  const signed char TrigParser::yypact_ninf_ = -97;

  const signed char TrigParser::yytable_ninf_ = -3;

  const signed char
  TrigParser::yypact_[] =
  {
     -97,     8,     9,   -97,   -21,   -97,   -17,   -97,    13,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,    38,   -97,   -97,
       0,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,    20,
       1,   -97,    17,     0,    75,   -97,   -97,   -97,   -97,   -97,
     -97,    -3,   -97,   -97,   -97,   -97,   -97,   -97,   -97,    39,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,    -3,    -3,    -3,
     -97,    47,    48,   -97,   -97,    18,    26,    41,    75,   -97,
     -97,    -3,    -3,    10,    49,    52,   -97,    54,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -11,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,    48,   -97,   -97,   -97,
      53,    70,    23,   -97,   -97,   -97,    72,   -97,    -3,   -97,
      48,   -97,   -97,   -97,   -97,   -97,    48,   -97,   -97
  };

  const unsigned char
  TrigParser::yydefact_[] =
  {
       5,     0,     9,     1,     0,    37,     0,    43,     0,    22,
     101,   102,   100,    99,    97,     6,     4,     0,     7,     8,
      14,     3,    33,    34,    36,    35,    31,    98,    32,     0,
       0,    42,     0,     0,    25,    78,    76,    10,    16,    18,
      12,     0,    13,    41,    38,    44,    11,    23,    26,    29,
      46,    64,    48,    75,    63,    74,    80,     0,    20,     0,
      62,     0,     0,    61,    65,     0,     0,     0,    25,    30,
      27,     0,    20,    81,     0,     0,    21,     0,    15,    91,
      92,    83,    84,    85,    93,    94,    95,    96,    55,    59,
      66,    70,    68,    69,    72,    71,    73,    89,    67,    39,
      45,    24,    28,    47,    49,    79,     0,    77,    17,    19,
      50,    57,     0,    87,    90,    86,     0,    82,    52,    56,
       0,    60,    88,    40,    53,    54,     0,    58,    51
  };

  const signed char
  TrigParser::yypgoto_[] =
  {
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,    12,   -13,   -97,   -97,    19,   -97,   -97,   -97,
      77,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,   -36,   -97,   -97,   -97,   -97,   -40,
     -97,   -97,   -29,   -97,   -97,   -96,   -97,   -97,   -32,   -16,
     -97,    73,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,    -2,   -97,    40
  };

  const signed char
  TrigParser::yydefgoto_[] =
  {
      -1,     1,    15,     2,    16,    17,    18,    40,    41,    37,
      58,    59,    75,    19,    34,    67,    47,    48,    69,    70,
      20,    21,    22,    30,    65,   116,    23,    24,    25,    32,
      66,    49,    71,    72,    76,   124,   125,   119,   110,    88,
     121,   111,    62,    50,    63,    89,    90,    91,    92,    93,
      57,    53,    56,    73,   106,    94,    95,   114,   115,    96,
      97,    64,    27,    55
  };

  const short int
  TrigParser::yytable_[] =
  {
      26,    38,    51,    60,   112,    61,    26,    42,     3,    -2,
     117,    29,     4,     5,     6,    31,     7,     9,    52,   105,
      46,    74,   113,    77,   127,     8,     9,    12,    13,    14,
      43,    44,    54,    10,    11,   103,    51,    10,    11,    12,
      13,    14,    28,    12,    13,    14,    35,    45,    28,    68,
      99,    36,    52,    12,    13,    14,    35,    78,   100,   101,
      98,    36,   108,   107,   109,   118,    54,    79,    80,    81,
      82,    83,    10,    11,    84,    85,    86,    87,    12,    13,
      14,   120,   123,    35,   104,    33,   128,   102,    36,   126,
      39,     0,     0,     0,     0,     0,     0,     0,     0,    10,
      11,     0,     0,     0,    98,    12,    13,    14,     0,     0,
     122,     0,     0,     0,     0,     0,     0,     0,    98,     0,
       0,     0,     0,     0,    98
  };

  const signed char
  TrigParser::yycheck_[] =
  {
       2,    17,    34,     6,    15,    41,     8,    20,     0,     0,
     106,    32,     3,     4,     5,    32,     7,    17,    34,     9,
      33,    57,    33,    59,   120,    16,    17,    30,    31,    32,
      10,    30,    34,    24,    25,    71,    68,    24,    25,    30,
      31,    32,     2,    30,    31,    32,     8,    30,     8,    10,
      32,    13,    68,    30,    31,    32,     8,    10,    32,    18,
      62,    13,    10,    14,    10,    12,    68,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    11,    10,     8,    72,     8,   126,    68,    13,   118,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      25,    -1,    -1,    -1,   106,    30,    31,    32,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,
      -1,    -1,    -1,    -1,   126
  };

  const unsigned char
  TrigParser::yystos_[] =
  {
       0,    35,    37,     0,     3,     4,     5,     7,    16,    17,
      24,    25,    30,    31,    32,    36,    38,    39,    40,    47,
      54,    55,    56,    60,    61,    62,    95,    96,    97,    32,
      57,    32,    63,    54,    48,     8,    13,    43,    83,    85,
      41,    42,    47,    10,    30,    30,    47,    50,    51,    65,
      77,    82,    83,    85,    95,    97,    86,    84,    44,    45,
       6,    68,    76,    78,    95,    58,    64,    49,    10,    52,
      53,    66,    67,    87,    68,    46,    68,    68,    10,    19,
      20,    21,    22,    23,    26,    27,    28,    29,    73,    79,
      80,    81,    82,    83,    89,    90,    93,    94,    95,    32,
      32,    18,    50,    68,    46,     9,    88,    14,    10,    10,
      72,    75,    15,    33,    91,    92,    59,    79,    12,    71,
      11,    74,    95,    10,    69,    70,    76,    79,    73
  };

  const unsigned char
  TrigParser::yyr1_[] =
  {
       0,    34,    35,    36,    36,    37,    37,    38,    38,    39,
      38,    38,    40,    41,    42,    41,    44,    43,    45,    43,
      46,    46,    48,    49,    47,    50,    50,    51,    52,    53,
      53,    54,    54,    55,    55,    55,    55,    57,    58,    59,
      56,    60,    61,    63,    64,    62,    66,    65,    67,    65,
      68,    69,    70,    70,    71,    72,    72,    73,    74,    75,
      75,    76,    76,    77,    77,    78,    79,    80,    80,    80,
      80,    81,    81,    81,    82,    82,    84,    83,    86,    85,
      87,    88,    87,    89,    89,    89,    90,    91,    91,    92,
      92,    93,    93,    94,    94,    94,    94,    95,    95,    96,
      96,    97,    97
  };

  const unsigned char
  TrigParser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     0,     2,     1,     1,     0,
       2,     3,     2,     1,     0,     3,     0,     4,     0,     4,
       0,     1,     0,     0,     5,     0,     1,     2,     2,     0,
       1,     1,     1,     1,     1,     1,     1,     0,     0,     0,
       7,     3,     2,     0,     0,     5,     0,     3,     0,     3,
       3,     2,     0,     1,     2,     0,     2,     2,     2,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     4,     0,     4,
       0,     0,     3,     1,     1,     1,     2,     1,     2,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const TrigParser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "AT_BASE", "AT_PREFIX",
  "IT_BASE", "RDF_TYPE", "IT_PREFIX", "GT_LPAREN", "GT_RPAREN", "GT_DOT",
  "GT_COMMA", "GT_SEMI", "GT_LBRACKET", "GT_RBRACKET", "GT_DTYPE",
  "IT_GRAPH", "GT_LCURLEY", "GT_RCURLEY", "IT_true", "IT_false", "INTEGER",
  "DECIMAL", "DOUBLE", "BLANK_NODE_LABEL", "ANON", "STRING_LITERAL1",
  "STRING_LITERAL2", "STRING_LITERAL_LONG1", "STRING_LITERAL_LONG2",
  "PNAME_NS", "PNAME_LN", "IRIREF", "LANGTAG", "$accept", "trigDoc",
  "_O_Qdirective_E_Or_Qblock_E_C",
  "_Q_O_Qdirective_E_Or_Qblock_E_C_E_Star", "block", "$@1",
  "triplesOrGraph",
  "_O_QwrappedGraph_E_Or_QpredicateObjectList_E_S_QGT_DOT_E_C", "$@2",
  "triples2", "$@3", "$@4", "_QpredicateObjectList_E_Opt", "wrappedGraph",
  "$@5", "$@6", "_QtriplesBlock_E_Opt", "triplesBlock",
  "_O_QGT_DOT_E_S_QtriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QtriplesBlock_E_Opt_C_E_Opt", "labelOrSubject",
  "directive", "prefixID", "$@7", "$@8", "$@9", "base", "sparqlBase",
  "sparqlPrefix", "$@10", "$@11", "triples", "$@12", "$@13",
  "predicateObjectList", "_O_Qverb_E_S_QobjectList_E_C",
  "_Q_O_Qverb_E_S_QobjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_Qverb_E_S_QobjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_Qverb_E_S_QobjectList_E_Opt_C_E_Star", "objectList",
  "_O_QGT_COMMA_E_S_Qobject_E_C", "_Q_O_QGT_COMMA_E_S_Qobject_E_C_E_Star",
  "verb", "subject", "predicate", "object", "_object1", "literal", "blank",
  "blankNodePropertyList", "@14", "collection", "@15", "_Qobject_E_Star",
  "@16", "NumericLiteral", "RDFLiteral",
  "_O_QLANGTAG_E_Or_QGT_DTYPE_E_S_Qiri_E_C",
  "_Q_O_QLANGTAG_E_Or_QGT_DTYPE_E_S_Qiri_E_C_E_Opt", "BooleanLiteral",
  "String", "iri", "PrefixedName", "BlankNode", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  TrigParser::yyrline_[] =
  {
       0,   187,   187,   194,   195,   198,   200,   205,   206,   207,
     207,   211,   216,   222,   223,   223,   230,   230,   235,   235,
     242,   244,   249,   252,   249,   257,   259,   264,   270,   273,
     275,   279,   282,   289,   290,   291,   292,   297,   299,   301,
     297,   309,   316,   323,   325,   323,   335,   335,   338,   338,
     345,   349,   352,   354,   358,   361,   363,   368,   373,   377,
     379,   383,   387,   394,   397,   401,   407,   416,   419,   420,
     421,   425,   426,   427,   431,   432,   436,   436,   449,   449,
     472,   475,   475,   491,   492,   493,   498,   506,   510,   518,
     522,   526,   527,   531,   532,   533,   534,   538,   539,   543,
     544,   548,   549
  };

  // Print the state stack on the debug stream.
  void
  TrigParser::yystack_print_ ()
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
  TrigParser::yy_reduce_print_ (int yyrule)
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
  TrigParser::token_number_type
  TrigParser::yytranslate_ (int t)
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
    };
    const unsigned int user_token_number_max_ = 288;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // w3c_sw
#line 1538 "lib/TrigParser.cpp" // lalr1.cc:1167
#line 554 "lib/TrigParser.ypp" // lalr1.cc:1168
 /*** Additional Code ***/

void w3c_sw::TrigParser::error(const TrigParser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}

/* START Driver (@@ stand-alone would allow it to be shared with other parsers */

namespace w3c_sw {

void TrigDriver::parse (IStreamContext& in, RdfDB* db, BasicGraphPattern* bgp)
{
    // clear prefixes for nth run but keep them around for e.g. serialization.
    clearPrefixes();
    curSubject = curPredicate = NULL;

    if (db != NULL)
	setDB(db);
    if (bgp != NULL)
	setGraph(bgp);

    streamname = in.nameStr;

    TrigScanner scanner(this, in.p);
    scanner.set_debug(trace_scanning);
    this->lexer = &scanner;

    TrigParser parser(*this);
    parser.set_debug_level(trace_parsing);
    defaultBGP = curBGP ? curBGP : this->db->ensureGraph(NULL);
    parser.parse();
}

void TrigDriver::parse (IStreamContext& in, BasicGraphPattern* bgp) {
    parse(in, NULL, bgp);
}

void TrigDriver::parse (std::string turtleStr, RdfDB* db, BasicGraphPattern* bgp) {
    IStreamContext in(turtleStr.c_str(), IStreamContext::STRING);
    parse(in, db, bgp);
}

void TrigDriver::parse (std::string turtleStr, BasicGraphPattern* bgp) {
    IStreamContext in(turtleStr.c_str(), IStreamContext::STRING);
    parse(in, NULL, bgp);
}

} // namespace w3c_sw

/* END Driver */

