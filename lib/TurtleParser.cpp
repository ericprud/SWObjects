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

#line 39 "lib/TurtleParser.cpp" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "TurtleParser.hpp"

// User implementation prologue.
#line 126 "lib/TurtleParser.ypp" // lalr1.cc:412

#include "TurtleScanner.hpp"
#line 164 "lib/TurtleParser.ypp" // lalr1.cc:412

#include "TurtleScanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lexWrapper

#line 65 "lib/TurtleParser.cpp" // lalr1.cc:412


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
#line 151 "lib/TurtleParser.cpp" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  TurtleParser::yytnamerr_ (const char *yystr)
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
  TurtleParser::TurtleParser (class TurtleDriver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

  TurtleParser::~TurtleParser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  TurtleParser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  TurtleParser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  TurtleParser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    value = other.value;
  }


  template <typename Base>
  inline
  TurtleParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  TurtleParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  inline
  TurtleParser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  TurtleParser::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  TurtleParser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  TurtleParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  inline
  TurtleParser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  TurtleParser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  TurtleParser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  TurtleParser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  TurtleParser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  TurtleParser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  TurtleParser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  TurtleParser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  TurtleParser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  TurtleParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  TurtleParser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  TurtleParser::symbol_number_type
  TurtleParser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  TurtleParser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  TurtleParser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    value = that.value;
    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  TurtleParser::stack_symbol_type&
  TurtleParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  TurtleParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  TurtleParser::yy_print_ (std::ostream& yyo,
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
  TurtleParser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  TurtleParser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  TurtleParser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  TurtleParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  TurtleParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  TurtleParser::debug_level_type
  TurtleParser::debug_level () const
  {
    return yydebug_;
  }

  void
  TurtleParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline TurtleParser::state_type
  TurtleParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  TurtleParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  TurtleParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  TurtleParser::parse ()
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
    #line 31 "lib/TurtleParser.ypp" // lalr1.cc:741
{
    // initialize the initial location object
    yyla.location.begin.filename = yyla.location.end.filename = &driver.streamname;
    driver.yylloc = &yyla.location;
}

#line 531 "lib/TurtleParser.cpp" // lalr1.cc:741

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
  case 12:
#line 201 "lib/TurtleParser.ypp" // lalr1.cc:859
    {
	driver.ignorePrefix(true);
      }
#line 643 "lib/TurtleParser.cpp" // lalr1.cc:859
    break;

  case 13:
#line 203 "lib/TurtleParser.ypp" // lalr1.cc:859
    {
	  driver.ignorePrefix(false);
      }
#line 651 "lib/TurtleParser.cpp" // lalr1.cc:859
    break;

  case 14:
#line 205 "lib/TurtleParser.ypp" // lalr1.cc:859
    {
	  std::string prefix((yystack_[2].value.p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yystack_[0].value.p_URI));
      }
#line 660 "lib/TurtleParser.cpp" // lalr1.cc:859
    break;

  case 16:
#line 212 "lib/TurtleParser.ypp" // lalr1.cc:859
    {
	driver.setBase((yystack_[1].value.p_URI)->getLexicalValue());
    }
#line 668 "lib/TurtleParser.cpp" // lalr1.cc:859
    break;

  case 17:
#line 218 "lib/TurtleParser.ypp" // lalr1.cc:859
    {
	driver.setBase((yystack_[0].value.p_URI)->getLexicalValue());
    }
#line 676 "lib/TurtleParser.cpp" // lalr1.cc:859
    break;

  case 18:
#line 224 "lib/TurtleParser.ypp" // lalr1.cc:859
    {
	driver.ignorePrefix(true);
      }
#line 684 "lib/TurtleParser.cpp" // lalr1.cc:859
    break;

  case 19:
#line 226 "lib/TurtleParser.ypp" // lalr1.cc:859
    {
	  driver.ignorePrefix(false);
      }
#line 692 "lib/TurtleParser.cpp" // lalr1.cc:859
    break;

  case 20:
#line 228 "lib/TurtleParser.ypp" // lalr1.cc:859
    {
	  std::string prefix((yystack_[2].value.p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yystack_[0].value.p_URI));
      }
#line 701 "lib/TurtleParser.cpp" // lalr1.cc:859
    break;

  case 21:
#line 235 "lib/TurtleParser.ypp" // lalr1.cc:859
    {
	driver.curSubject = (yystack_[0].value.p_TTerm);
    }
#line 709 "lib/TurtleParser.cpp" // lalr1.cc:859
    break;

  case 23:
#line 238 "lib/TurtleParser.ypp" // lalr1.cc:859
    {
	driver.curSubject = (yystack_[0].value.p_TTerm);
    }
#line 717 "lib/TurtleParser.cpp" // lalr1.cc:859
    break;

  case 42:
#line 298 "lib/TurtleParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_TTerm);
	driver.curPredicate = (yylhs.value.p_TTerm);
    }
#line 726 "lib/TurtleParser.cpp" // lalr1.cc:859
    break;

  case 43:
#line 302 "lib/TurtleParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = TTerm::RDF_type;
	driver.curPredicate = (yylhs.value.p_TTerm);
    }
#line 735 "lib/TurtleParser.cpp" // lalr1.cc:859
    break;

  case 44:
#line 309 "lib/TurtleParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_URI);
    }
#line 743 "lib/TurtleParser.cpp" // lalr1.cc:859
    break;

  case 47:
#line 317 "lib/TurtleParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_URI);
    }
#line 751 "lib/TurtleParser.cpp" // lalr1.cc:859
    break;

  case 48:
#line 323 "lib/TurtleParser.ypp" // lalr1.cc:859
    {
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yystack_[0].value.p_TTerm)));
    }
#line 759 "lib/TurtleParser.cpp" // lalr1.cc:859
    break;

  case 49:
#line 329 "lib/TurtleParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_URI);
    }
#line 767 "lib/TurtleParser.cpp" // lalr1.cc:859
    break;

  case 57:
#line 345 "lib/TurtleParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_SubjectPredicatePair).subject = driver.curSubject;
	(yylhs.value.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
#line 777 "lib/TurtleParser.cpp" // lalr1.cc:859
    break;

  case 58:
#line 349 "lib/TurtleParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_TTerm) = (BNode*)driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yystack_[2].value.p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yystack_[2].value.p_SubjectPredicatePair).predicate;
      }
#line 787 "lib/TurtleParser.cpp" // lalr1.cc:859
    break;

  case 59:
#line 367 "lib/TurtleParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_SubjectPredicatePair).subject = driver.curSubject;
	(yylhs.value.p_SubjectPredicatePair).predicate = driver.curPredicate;
      }
#line 796 "lib/TurtleParser.cpp" // lalr1.cc:859
    break;

  case 60:
#line 370 "lib/TurtleParser.ypp" // lalr1.cc:859
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
#line 813 "lib/TurtleParser.cpp" // lalr1.cc:859
    break;

  case 61:
#line 390 "lib/TurtleParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = NULL;
    }
#line 821 "lib/TurtleParser.cpp" // lalr1.cc:859
    break;

  case 62:
#line 393 "lib/TurtleParser.ypp" // lalr1.cc:859
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
#line 837 "lib/TurtleParser.cpp" // lalr1.cc:859
    break;

  case 63:
#line 403 "lib/TurtleParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_TTerm) = (yystack_[1].value.p_TTerm);
      }
#line 845 "lib/TurtleParser.cpp" // lalr1.cc:859
    break;

  case 67:
#line 416 "lib/TurtleParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = driver.getRDFLiteral(*(yystack_[1].value.p_string), (yystack_[0].value.p_uri_or_langtag).uri, (yystack_[0].value.p_uri_or_langtag).langtag);
	delete (yystack_[1].value.p_string);
    }
#line 854 "lib/TurtleParser.cpp" // lalr1.cc:859
    break;

  case 68:
#line 424 "lib/TurtleParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_uri_or_langtag).uri = NULL;
	(yylhs.value.p_uri_or_langtag).langtag = (yystack_[0].value.p_LANGTAG);
    }
#line 863 "lib/TurtleParser.cpp" // lalr1.cc:859
    break;

  case 69:
#line 429 "lib/TurtleParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_uri_or_langtag).uri = (yystack_[0].value.p_URI);
	(yylhs.value.p_uri_or_langtag).langtag = NULL;
    }
#line 872 "lib/TurtleParser.cpp" // lalr1.cc:859
    break;

  case 70:
#line 437 "lib/TurtleParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_uri_or_langtag).uri = NULL;
	(yylhs.value.p_uri_or_langtag).langtag = NULL;
    }
#line 881 "lib/TurtleParser.cpp" // lalr1.cc:859
    break;


#line 885 "lib/TurtleParser.cpp" // lalr1.cc:859
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
  TurtleParser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  TurtleParser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
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


  const signed char TurtleParser::yypact_ninf_ = -55;

  const signed char TurtleParser::yytable_ninf_ = -41;

  const signed char
  TurtleParser::yypact_[] =
  {
     -55,     4,     2,   -55,     1,   -13,   -55,   -11,   -55,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,    15,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
      18,    10,   -55,    16,   -55,    13,   -55,    13,     7,   -55,
     -55,   -55,    36,   -55,   -55,    57,    38,   -55,   -55,   -55,
     -55,   -55,    23,    43,   -55,    83,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,    -3,   -55,   -55,   -55,
     -55,   -55,    67,    39,    -7,   -55,   -55,   -55,    63,    64,
      20,   -55,    83,   -55,   -55,   -55,    21,   -55,   -55,    83,
     -55,   -55,   -55
  };

  const unsigned char
  TurtleParser::yydefact_[] =
  {
       3,     0,     0,     1,     0,     0,    12,     0,    18,    59,
      57,    82,    83,    81,    80,    78,     4,     5,     8,     9,
      11,    10,     0,    21,    23,    46,    44,    79,    45,     7,
       0,     0,    17,     0,    61,     0,     6,     0,     0,    16,
      13,    19,    62,    28,    43,     0,     0,    42,    47,    22,
      24,    26,     0,     0,    60,     0,    58,    29,    72,    73,
      64,    65,    66,    74,    75,    76,    77,    34,    40,    48,
      53,    52,    51,    55,    54,    56,    70,    49,    50,    14,
      20,    63,     0,    38,     0,    68,    71,    67,     0,    37,
      31,    35,     0,    41,    69,    15,     0,    32,    33,     0,
      39,    36,    30
  };

  const signed char
  TurtleParser::yypgoto_[] =
  {
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,    32,   -55,
     -55,   -22,   -55,   -23,   -55,    -9,   -12,   -55,   -55,   -54,
     -55,   -55,    81,   -55,    82,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,   -55,    -2,   -55,    84
  };

  const signed char
  TurtleParser::yydefgoto_[] =
  {
      -1,     1,     2,    16,    17,    18,    31,    52,    88,    19,
      20,    21,    33,    53,    22,    37,    38,    50,    45,    97,
      98,    91,    82,    67,    93,    83,    46,    23,    47,    68,
      69,    70,    71,    35,    72,    34,    42,    55,    73,    74,
      86,    87,    75,    76,    48,    27,    78
  };

  const signed char
  TurtleParser::yytable_[] =
  {
      26,    81,    -2,     4,     3,     5,     6,     7,    43,     8,
       9,    29,    84,    44,    43,    10,    30,   -25,    32,    44,
      13,    14,    15,    11,    12,    36,    44,    85,    39,    13,
      14,    15,    92,    90,    13,    14,    15,    40,   100,    57,
      13,    14,    15,    41,    77,    54,     9,    13,    14,    15,
      92,    10,    79,    77,    58,    59,    60,    61,    62,    11,
      12,    63,    64,    65,    66,    13,    14,    15,    89,    49,
      51,    56,    80,    95,   101,   -40,   102,   -27,    99,    90,
      96,   -27,    94,    24,    25,     0,    28,     0,     0,     0,
      77,     9,     0,     0,     0,     0,    10,    77,     0,    58,
      59,    60,    61,    62,    11,    12,    63,    64,    65,    66,
      13,    14,    15
  };

  const signed char
  TurtleParser::yycheck_[] =
  {
       2,    55,     0,     1,     0,     3,     4,     5,     1,     7,
       8,    10,    15,     6,     1,    13,    29,    10,    29,     6,
      27,    28,    29,    21,    22,    10,     6,    30,    10,    27,
      28,    29,    11,    12,    27,    28,    29,    27,    92,     1,
      27,    28,    29,    27,    46,     9,     8,    27,    28,    29,
      11,    13,    29,    55,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,     1,    37,
      38,    14,    29,    10,    96,    11,    99,    10,    90,    12,
      89,    14,    84,     2,     2,    -1,     2,    -1,    -1,    -1,
      92,     8,    -1,    -1,    -1,    -1,    13,    99,    -1,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29
  };

  const unsigned char
  TurtleParser::yystos_[] =
  {
       0,    32,    33,     0,     1,     3,     4,     5,     7,     8,
      13,    21,    22,    27,    28,    29,    34,    35,    36,    40,
      41,    42,    45,    58,    63,    65,    75,    76,    77,    10,
      29,    37,    29,    43,    66,    64,    10,    46,    47,    10,
      27,    27,    67,     1,     6,    49,    57,    59,    75,    49,
      48,    49,    38,    44,     9,    68,    14,     1,    16,    17,
      18,    19,    20,    23,    24,    25,    26,    54,    60,    61,
      62,    63,    65,    69,    70,    73,    74,    75,    77,    29,
      29,    60,    53,    56,    15,    30,    71,    72,    39,     1,
      12,    52,    11,    55,    75,    10,    56,    50,    51,    57,
      60,    52,    54
  };

  const unsigned char
  TurtleParser::yyr1_[] =
  {
       0,    31,    32,    33,    33,    34,    34,    34,    35,    35,
      35,    35,    37,    38,    39,    36,    40,    41,    43,    44,
      42,    46,    45,    47,    45,    48,    48,    49,    49,    49,
      50,    51,    51,    52,    53,    53,    53,    53,    54,    55,
      56,    56,    57,    57,    58,    58,    58,    59,    60,    61,
      61,    61,    61,    61,    62,    62,    62,    64,    63,    66,
      65,    67,    68,    67,    69,    69,    69,    70,    71,    71,
      72,    72,    73,    73,    74,    74,    74,    74,    75,    75,
      76,    76,    77,    77
  };

  const unsigned char
  TurtleParser::yyr2_[] =
  {
       0,     2,     1,     0,     2,     1,     2,     2,     1,     1,
       1,     1,     0,     0,     0,     7,     3,     2,     0,     0,
       5,     0,     3,     0,     3,     0,     1,     3,     1,     2,
       2,     0,     1,     2,     0,     2,     4,     2,     2,     2,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     4,     0,
       4,     0,     0,     3,     1,     1,     1,     2,     1,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const TurtleParser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "GT_AT_base", "GT_AT_prefix",
  "IT_BASE", "RDF_TYPE", "IT_PREFIX", "GT_LPAREN", "GT_RPAREN", "GT_DOT",
  "GT_COMMA", "GT_SEMI", "GT_LBRACKET", "GT_RBRACKET", "GT_DTYPE",
  "IT_true", "IT_false", "INTEGER", "DECIMAL", "DOUBLE",
  "BLANK_NODE_LABEL", "ANON", "STRING_LITERAL1", "STRING_LITERAL2",
  "STRING_LITERAL_LONG1", "STRING_LITERAL_LONG2", "PNAME_NS", "PNAME_LN",
  "IRIREF", "LANGTAG", "$accept", "turtleDoc", "_Qstatement_E_Star",
  "statement", "directive", "prefixID", "$@1", "$@2", "$@3", "base",
  "BaseDecl", "PrefixDecl", "$@4", "$@5", "triples", "$@6", "$@7",
  "_QpredicateObjectList_E_Opt", "predicateObjectList",
  "_O_Qverb_E_S_QobjectList_E_C", "_Q_O_Qverb_E_S_QobjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_Qverb_E_S_QobjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_Qverb_E_S_QobjectList_E_Opt_C_E_Star", "objectList",
  "_O_QGT_COMMA_E_S_Qobject_E_C", "_Q_O_QGT_COMMA_E_S_Qobject_E_C_E_Star",
  "verb", "subject", "predicate", "object", "_object1", "literal",
  "blankNodePropertyList", "@8", "collection", "@9", "_Qobject_E_Star",
  "@10", "NumericLiteral", "RDFLiteral",
  "_O_QLANGTAG_E_Or_QGT_DTYPE_E_S_Qiri_E_C",
  "_Q_O_QLANGTAG_E_Or_QGT_DTYPE_E_S_Qiri_E_C_E_Opt", "BooleanLiteral",
  "String", "iri", "PrefixedName", "BlankNode", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  TurtleParser::yyrline_[] =
  {
       0,   179,   179,   182,   184,   188,   189,   190,   194,   195,
     196,   197,   201,   203,   205,   201,   212,   218,   224,   226,
     224,   235,   235,   238,   238,   244,   246,   251,   252,   253,
     259,   263,   265,   270,   274,   276,   277,   278,   283,   288,
     292,   294,   298,   302,   309,   312,   313,   317,   323,   329,
     332,   333,   334,   335,   339,   340,   341,   345,   345,   367,
     367,   390,   393,   393,   409,   410,   411,   416,   424,   429,
     437,   441,   445,   446,   450,   451,   452,   453,   457,   458,
     462,   463,   467,   468
  };

  // Print the state stack on the debug stream.
  void
  TurtleParser::yystack_print_ ()
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
  TurtleParser::yy_reduce_print_ (int yyrule)
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
  TurtleParser::token_number_type
  TurtleParser::yytranslate_ (int t)
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
      25,    26,    27,    28,    29,    30
    };
    const unsigned int user_token_number_max_ = 285;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // w3c_sw
#line 1399 "lib/TurtleParser.cpp" // lalr1.cc:1167
#line 473 "lib/TurtleParser.ypp" // lalr1.cc:1168
 /*** Additional Code ***/

void w3c_sw::TurtleParser::error(const TurtleParser::location_type& l,
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
    _SUBS(s, "GT_AT_base", "@base");
    _SUBS(s, "GT_AT_prefix", "@prefix");
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

size_t TurtleDriver::DefaultAbortErrorCount = 100;

void TurtleDriver::parse (IStreamContext& in) {
    reset();
    streamname = in.nameStr;
    // clear prefixes for nth run but keep them around for e.g. serialization.
    clearPrefixes();
    curSubject = curPredicate = NULL;

    TurtleScanner scanner(this, in.p);
    scanner.set_debug(trace_scanning);
    this->lexer = &scanner;

    TurtleParser parser(*this);
    parser.set_debug_level(trace_parsing);
    parser.parse();
    checkErrors();
}

void TurtleDriver::parse (IStreamContext& in, BasicGraphPattern* bgp) {
    setGraph(bgp);
    parse(in);
}

void TurtleDriver::parse (IStreamContext& in, RdfDB* db) {
    setGraph(db->ensureGraph(NULL));
    parse(in);
}

void TurtleDriver::parse(std::string turtleStr) {
    IStreamContext in(turtleStr.c_str(), IStreamContext::STRING);
    parse(in);
}

void TurtleDriver::parse (std::string turtleStr, BasicGraphPattern* bgp) {
    IStreamContext in(turtleStr.c_str(), IStreamContext::STRING);
    setGraph(bgp);
    parse(in);
}

void TurtleDriver::parse (std::string turtleStr, RdfDB* db) {
    IStreamContext in(turtleStr.c_str(), IStreamContext::STRING);
    setGraph(db->ensureGraph(DefaultGraph));
    parse(in);
}

} // namespace w3c_sw

// FIXME: dirty workaround to make sure linking errors do not occur
int TurtleFlexLexer::w3c_swlex() {
	return 0;
}
/* END Driver */

