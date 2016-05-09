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

#line 39 "lib/SPARQLParser.cpp" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "SPARQLParser.hpp"

// User implementation prologue.
#line 371 "lib/SPARQLParser.ypp" // lalr1.cc:412

#include "SPARQLScanner.hpp"
#line 538 "lib/SPARQLParser.ypp" // lalr1.cc:412

#include "SPARQLScanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lexWrapper

template <typename T>
std::string comma_str (const T c) {
    std::stringstream ss;
    for (typename T::const_iterator it = c.begin(); it != c.end(); ++it) {
	if (it != c.begin())
	    ss << ", ";
	ss << (*it)->str();
    }
    return ss.str();
}

#line 76 "lib/SPARQLParser.cpp" // lalr1.cc:412


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
#line 162 "lib/SPARQLParser.cpp" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  SPARQLParser::yytnamerr_ (const char *yystr)
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
  SPARQLParser::SPARQLParser (class SPARQLDriver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

  SPARQLParser::~SPARQLParser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  SPARQLParser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  SPARQLParser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  SPARQLParser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    value = other.value;
  }


  template <typename Base>
  inline
  SPARQLParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  SPARQLParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  inline
  SPARQLParser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  SPARQLParser::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  SPARQLParser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  SPARQLParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  inline
  SPARQLParser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  SPARQLParser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  SPARQLParser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  SPARQLParser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  SPARQLParser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  SPARQLParser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  SPARQLParser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  SPARQLParser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  SPARQLParser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  SPARQLParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  SPARQLParser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  SPARQLParser::symbol_number_type
  SPARQLParser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  SPARQLParser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  SPARQLParser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    value = that.value;
    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  SPARQLParser::stack_symbol_type&
  SPARQLParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  SPARQLParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  SPARQLParser::yy_print_ (std::ostream& yyo,
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
  SPARQLParser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  SPARQLParser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  SPARQLParser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  SPARQLParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  SPARQLParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  SPARQLParser::debug_level_type
  SPARQLParser::debug_level () const
  {
    return yydebug_;
  }

  void
  SPARQLParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline SPARQLParser::state_type
  SPARQLParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  SPARQLParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  SPARQLParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  SPARQLParser::parse ()
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
    #line 38 "lib/SPARQLParser.ypp" // lalr1.cc:741
{
    // initialize the initial location object
    yyla.location.begin.filename = yyla.location.end.filename = &driver.streamname;
    driver.yylloc = &yyla.location;
}

#line 542 "lib/SPARQLParser.cpp" // lalr1.cc:741

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
#line 563 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.root = (yylhs.value.p_Operation) = (yystack_[0].value.p_Operation);
    }
#line 654 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 3:
#line 566 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.root = (yylhs.value.p_Operation) = (yystack_[0].value.p_Operation);
    }
#line 662 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 5:
#line 577 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	assert(driver.lastWhereClause != NULL);
	if ((yystack_[0].value.p_ValuesClause) != NULL) // got a bindings clause
	    driver.lastWhereClause->m_GroupGraphPattern = 
		driver.makeConjunction(driver.lastWhereClause->m_GroupGraphPattern, (yystack_[0].value.p_ValuesClause));
	(yylhs.value.p_Operation) = (yystack_[1].value.p_Operation);
    }
#line 674 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 18:
#line 621 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TableOperation) = driver.curOp;
	driver.startBindingSet();
      }
#line 683 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 19:
#line 624 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  if ((yystack_[2].value.p_RSName) != NULL) {
	      std::string s = (yystack_[2].value.p_RSName)->name;
	      delete (yystack_[2].value.p_RSName);
	      driver.bindingsMap[s] = (yystack_[0].value.p_TableOperation);
	      driver.curOp = (yystack_[1].value.p_TableOperation);
	  } else {
	      // if ($<p_TableOperation>2 != NULL)
	      driver.curOp = driver.makeConjunction((yystack_[1].value.p_TableOperation), (yystack_[0].value.p_TableOperation));
	  }
      }
#line 699 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 20:
#line 638 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_RSName) = (yystack_[1].value.p_RSName);
    }
#line 707 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 21:
#line 644 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_RSName) = NULL;
    }
#line 715 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 23:
#line 651 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TableOperation) = new ValuesClause(driver.endBindingSet());
    }
#line 723 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 24:
#line 654 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TableOperation) = new ValuesClause(driver.endBindingSet());
    }
#line 731 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 25:
#line 657 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TableOperation) = new ValuesClause(driver.endBindingSet());
    }
#line 739 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 26:
#line 660 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	throw std::runtime_error("need to partition out results set part of SimpleEngine::loadDataOrResults");
    }
#line 747 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 27:
#line 663 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.restoreFilter(NULL);
	(yylhs.value.p_TableOperation) = driver.ensureGraphPattern();
	driver.curOp = NULL;
	//throw std::runtime_error("IMPL");
    }
#line 758 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 39:
#line 701 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.startBindingRow();
      }
#line 766 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 40:
#line 703 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  driver.endBindingRow();
      }
#line 774 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 41:
#line 709 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.addBindingVarOrValue((yystack_[1].value.p_TTerm));
    }
#line 782 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 54:
#line 748 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.startBindingRow();
      }
#line 790 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 55:
#line 750 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  driver.endBindingRow();
      }
#line 798 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 56:
#line 756 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.addBindingVarOrValue((yystack_[1].value.p_TTerm));
    }
#line 806 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 61:
#line 775 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.startBindingRow(false);
      }
#line 814 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 62:
#line 777 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  driver.endBindingRow();
      }
#line 822 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 68:
#line 797 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.addBinding((yystack_[2].value.p_TTerm), (yystack_[0].value.p_TTerm)); 
    }
#line 830 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 69:
#line 800 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.addBinding((yystack_[2].value.p_TTerm), (yystack_[0].value.p_TTerm)); 
    }
#line 838 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 70:
#line 803 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.addBinding((yystack_[2].value.p_TTerm), (yystack_[0].value.p_TTerm)); 
    }
#line 846 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 71:
#line 809 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.setBase((yystack_[0].value.p_URI)->getLexicalValue());
    }
#line 854 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 72:
#line 815 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.ignorePrefix(true);
      }
#line 862 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 73:
#line 817 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  driver.ignorePrefix(false);
      }
#line 870 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 74:
#line 819 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  std::string prefix((yystack_[2].value.p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yystack_[0].value.p_URI));
      }
#line 879 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 75:
#line 827 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
#line 888 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 76:
#line 830 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	if (driver.validate & SPARQLDriver::VALIDATE_selectGrouped) {
	    const ExpressionAliasList* e = (yystack_[0].value.p_SolutionModifier)->getGroupedBy();
	    if (e) {
		std::set<const TTerm*> errorSet = (yystack_[3].value.p_Project).varSet->getNonProjectableVars(e, driver.atomFactory);
		if (errorSet.size() != 0)
		    error(*driver.yylloc, "can't select " + comma_str(errorSet) + " because "
			  + (errorSet.size() == 1 ? "it's" : "they're") + "not in a GROUP BY.");
	    }
	}
	if (driver.validate & SPARQLDriver::VALIDATE_noReassign) {
	    struct CreatedVars : public TestExpressor {
		std::set<const TTerm*> vars;
		virtual void variable (const Variable* const self, std::string)
		{ vars.insert(self); }
		virtual void expressionAlias (const ExpressionAlias* const,
					      const Expression*, const Bindable* label)
		{ if (label != NULL) label->express(this); }
	    };
	    CreatedVars cv;
	    (yystack_[3].value.p_Project).varSet->express(&cv);

	    const BindingState& nested = (yystack_[1].value.p_WhereClause)->m_GroupGraphPattern->getBindingState();
	    std::set<const TTerm*> known;
	    std::copy(nested.binds   .begin(), nested.binds   .end(), std::inserter(known, known.begin()));
	    std::copy(nested.optional.begin(), nested.optional.end(), std::inserter(known, known.begin()));

	    std::set<const TTerm*> errorSet;
	    std::set_intersection(cv.vars.begin(), cv.vars.end(), known.begin(), known.end(), std::inserter(errorSet, errorSet.begin()));
	    if (errorSet.size() != 0)
		error(*driver.yylloc, "select can't bind " + comma_str(errorSet) + " because "
		      + (errorSet.size() == 1 ? "it's" : "they're") + " bound in the WHERE clause.");
	}
	driver.lastWhereClause = (yystack_[1].value.p_WhereClause);
	(yylhs.value.p_Operation) = new Select((yystack_[3].value.p_Project).distinctness, (yystack_[3].value.p_Project).varSet, (yystack_[2].value.p_DatasetClauses), (yystack_[1].value.p_WhereClause), (yystack_[0].value.p_SolutionModifier));
	driver.countStar = (yystack_[4].value.p_parentCountStar);
    }
#line 930 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 77:
#line 871 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
#line 938 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 78:
#line 874 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yystack_[1].value.p_DatasetClauses)->push_back((yystack_[0].value.p_DatasetClause));
	(yylhs.value.p_DatasetClauses) = (yystack_[1].value.p_DatasetClauses);
    }
#line 947 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 79:
#line 882 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
      }
#line 956 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 80:
#line 885 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  driver.restoreFilter(NULL);
	  (yylhs.value.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
#line 966 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 81:
#line 889 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  if (!driver.curGraphName || (yystack_[1].value.p_Project).varSet->includes(driver.curGraphName)) {
	      (yylhs.value.p_GraphName) = NULL;
	  } else {
	      (yylhs.value.p_GraphName) = driver.curGraphName;
	      driver.curGraphName = driver.createBNode();
	  }
      }
#line 979 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 82:
#line 896 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  if ((yystack_[3].value.p_GraphName) != NULL)
	      driver.curGraphName = (yystack_[3].value.p_GraphName);
	  if ((yystack_[0].value.p_ValuesClause) != NULL)
	      (yystack_[2].value.p_WhereClause)->m_GroupGraphPattern = driver.makeConjunction((yystack_[2].value.p_WhereClause)->m_GroupGraphPattern, (yystack_[0].value.p_ValuesClause));
	  driver.curOp = driver.makeConjunction((yystack_[4].value.p_TableOperation), new SubSelect(new Select((yystack_[5].value.p_Project).distinctness, (yystack_[5].value.p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yystack_[2].value.p_WhereClause), (yystack_[1].value.p_SolutionModifier))));
	  driver.countStar = (yystack_[6].value.p_parentCountStar);
      }
#line 992 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 83:
#line 908 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Project).distinctness = (yystack_[1].value.p_distinctness);
	(yylhs.value.p_Project).varSet = (yystack_[0].value.p_VarSet);
    }
#line 1001 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 84:
#line 920 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_distinctness) = DIST_distinct;
    }
#line 1009 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 85:
#line 923 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_distinctness) = DIST_reduced;
    }
#line 1017 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 86:
#line 930 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_distinctness) = DIST_all;
    }
#line 1025 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 88:
#line 938 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Variable) = (yystack_[0].value.p_Variable);
    }
#line 1033 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 89:
#line 945 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Variable) = NULL;
    }
#line 1041 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 91:
#line 953 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	if (driver.validate & SPARQLDriver::VALIDATE_namedProjection && (yystack_[1].value.p_Variable) == NULL)
	    error(*driver.yylloc, (yystack_[2].value.p_Expression)->str() + " must be selected AS some variable");
	(yylhs.value.p_ExpressionAlias) = (yystack_[1].value.p_Variable) ? new ExpressionAlias((yystack_[2].value.p_Expression), (yystack_[1].value.p_Variable)) : new ExpressionAlias((yystack_[2].value.p_Expression));
    }
#line 1051 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 92:
#line 967 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	if (driver.validate & SPARQLDriver::VALIDATE_namedProjection)
	    error(*driver.yylloc, (yystack_[0].value.p_Expression)->str() + " must be selected AS some variable");
	(yylhs.value.p_ExpressionAlias) = new ExpressionAlias((yystack_[0].value.p_Expression));
    }
#line 1061 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 93:
#line 972 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	if (driver.validate & SPARQLDriver::VALIDATE_namedProjection)
	    error(*driver.yylloc, (yystack_[0].value.p_RDFLiteral)->str() + " must be selected AS some variable");
	(yylhs.value.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yystack_[0].value.p_RDFLiteral)));
    }
#line 1071 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 94:
#line 977 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	if (driver.validate & SPARQLDriver::VALIDATE_namedProjection)
	    error(*driver.yylloc, (yystack_[0].value.p_NumericRDFLiteral)->str() + " must be selected AS some variable");
	(yylhs.value.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yystack_[0].value.p_NumericRDFLiteral)));
    }
#line 1081 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 95:
#line 982 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	if (driver.validate & SPARQLDriver::VALIDATE_namedProjection)
	    error(*driver.yylloc, (yystack_[0].value.p_BooleanRDFLiteral)->str() + " must be selected AS some variable");
	(yylhs.value.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yystack_[0].value.p_BooleanRDFLiteral)));
    }
#line 1091 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 96:
#line 987 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yystack_[0].value.p_Variable)));
    }
#line 1099 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 97:
#line 990 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	if (driver.validate & SPARQLDriver::VALIDATE_namedProjection)
	    error(*driver.yylloc, (yystack_[0].value.p_Expression)->str() + " must be selected AS some variable");
	(yylhs.value.p_ExpressionAlias) = new ExpressionAlias((yystack_[0].value.p_Expression));
    }
#line 1109 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 98:
#line 995 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	if (driver.validate & SPARQLDriver::VALIDATE_namedProjection)
	    error(*driver.yylloc, (yystack_[0].value.p_Expression)->str() + " must be selected AS some variable");
	(yylhs.value.p_ExpressionAlias) = new ExpressionAlias((yystack_[0].value.p_Expression));
    }
#line 1119 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 100:
#line 1006 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ExpressionAliaseList) = new ExpressionAliasList((yystack_[0].value.p_ExpressionAlias));
    }
#line 1127 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 101:
#line 1009 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
    (yystack_[1].value.p_ExpressionAliaseList)->push_back((yystack_[0].value.p_ExpressionAlias));
    (yylhs.value.p_ExpressionAliaseList) = (yystack_[1].value.p_ExpressionAliaseList);
}
#line 1136 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 102:
#line 1017 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	if (driver.validate & SPARQLDriver::VALIDATE_uniqueProjection) {
	    std::set<const TTerm*> labels;
	    for (std::vector<const ExpressionAlias*>::const_iterator it = (yystack_[0].value.p_ExpressionAliaseList)->begin();
		 it != (yystack_[0].value.p_ExpressionAliaseList)->end(); ++it) {
		const TTerm* label = (*it)->getLabel(driver.atomFactory);
		if (labels.find(label) != labels.end())
		    error(*driver.yylloc, label->str() + " duplicated in select list.");
		labels.insert(label);
	    }
	}
	(yylhs.value.p_VarSet) = (yystack_[0].value.p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
#line 1154 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 103:
#line 1030 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_VarSet) = new StarVarSet();
    }
#line 1162 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 104:
#line 1036 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Operation) = (yystack_[0].value.p_Operation);
    }
#line 1170 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 105:
#line 1042 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	if (driver.validate & SPARQLDriver::VALIDATE_constructNoQuads &&
	    dynamic_cast<const DefaultGraphPattern*>((yystack_[3].value.p_TableOperation)) == NULL) {
	    error(*driver.yylloc, "can't CONSTRUCT quad pattern " + (yystack_[3].value.p_TableOperation)->str() + ".");
	}
	driver.lastWhereClause = (yystack_[1].value.p_WhereClause);
	/* $1 is NO LONGER known to be a DefaultGraphPattern because of grammar restrictions. */
	(yylhs.value.p_Operation) = new Construct((yystack_[3].value.p_TableOperation), (yystack_[2].value.p_DatasetClauses), (yystack_[1].value.p_WhereClause), (yystack_[0].value.p_SolutionModifier));
    }
#line 1184 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 106:
#line 1051 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	if (driver.validate & SPARQLDriver::VALIDATE_constructNoQuads &&
	    dynamic_cast<const DefaultGraphPattern*>((yystack_[1].value.p_TableOperation)) == NULL) {
	    error(*driver.yylloc, "can't re-CONSTRUCT quad pattern " + (yystack_[1].value.p_TableOperation)->str() + ".");
	}
	SWObjectDuplicator dup(driver.atomFactory);
	(yystack_[1].value.p_TableOperation)->express(&dup);
	driver.lastWhereClause = new WhereClause((yystack_[1].value.p_TableOperation));
	(yylhs.value.p_Operation) = new Construct(dup.last.tableOperation, (yystack_[3].value.p_DatasetClauses), driver.lastWhereClause, (yystack_[0].value.p_SolutionModifier));
    }
#line 1199 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 107:
#line 1065 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.restoreFilter(NULL);
	driver.lastWhereClause = (yystack_[1].value.p_WhereClause) ? (yystack_[1].value.p_WhereClause) : new WhereClause(new DefaultGraphPattern());
	(yylhs.value.p_Operation) = new Describe((yystack_[3].value.p_VarSet), (yystack_[2].value.p_DatasetClauses), (yystack_[1].value.p_WhereClause), (yystack_[0].value.p_SolutionModifier));
    }
#line 1209 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 108:
#line 1074 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ExpressionAliaseList) = new ExpressionAliasList(new ExpressionAlias(new TTermExpression((yystack_[0].value.p_TTerm))));
    }
#line 1217 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 109:
#line 1077 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yystack_[1].value.p_ExpressionAliaseList)->push_back(new ExpressionAlias(new TTermExpression((yystack_[0].value.p_TTerm))));
	(yylhs.value.p_ExpressionAliaseList) = (yystack_[1].value.p_ExpressionAliaseList);
    }
#line 1226 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 110:
#line 1085 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_VarSet) = (yystack_[0].value.p_ExpressionAliaseList);
    }
#line 1234 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 111:
#line 1088 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_VarSet) = new StarVarSet();
    }
#line 1242 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 112:
#line 1095 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_WhereClause) = NULL;
    }
#line 1250 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 114:
#line 1103 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.lastWhereClause = (yystack_[1].value.p_WhereClause);
	(yylhs.value.p_Operation) = new Ask((yystack_[2].value.p_DatasetClauses), (yystack_[1].value.p_WhereClause), (yystack_[0].value.p_SolutionModifier));
    }
#line 1259 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 115:
#line 1111 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_DatasetClause) = (yystack_[0].value.p_DatasetClause);
    }
#line 1267 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 118:
#line 1123 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_DatasetClause) = new DefaultGraphClause((yystack_[0].value.p_TTerm), driver.atomFactory);
    }
#line 1275 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 119:
#line 1129 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_DatasetClause) = new NamedGraphClause((yystack_[0].value.p_TTerm), driver.atomFactory);
    }
#line 1283 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 120:
#line 1135 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_URI);
    }
#line 1291 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 121:
#line 1142 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.restoreFilter(NULL);
	(yylhs.value.p_WhereClause) = new WhereClause(driver.ensureGraphPattern());
	driver.curOp = NULL;
    }
#line 1301 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 124:
#line 1156 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_SolutionModifier) = new SolutionModifier((yystack_[3].value.p_ExpressionAliaseList), (yystack_[2].value.p_Expressions), (yystack_[1].value.p_OrderConditions), (yystack_[0].value.p_LimitOffsetPair).limit, (yystack_[0].value.p_LimitOffsetPair).offset); // !!!
    }
#line 1309 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 125:
#line 1163 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
#line 1317 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 127:
#line 1171 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expressions) = NULL;
    }
#line 1325 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 129:
#line 1179 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_OrderConditions) = NULL;
    }
#line 1333 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 131:
#line 1187 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_LimitOffsetPair).limit = LIMIT_None;
	(yylhs.value.p_LimitOffsetPair).offset = OFFSET_None;
    }
#line 1342 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 133:
#line 1195 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ExpressionAliaseList) = (yystack_[0].value.p_ExpressionAliaseList);
    }
#line 1350 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 134:
#line 1202 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ExpressionAliaseList) = new ExpressionAliasList((yystack_[0].value.p_ExpressionAlias));
    }
#line 1358 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 135:
#line 1205 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yystack_[1].value.p_ExpressionAliaseList)->push_back((yystack_[0].value.p_ExpressionAlias));
	(yylhs.value.p_ExpressionAliaseList) = (yystack_[1].value.p_ExpressionAliaseList);
    }
#line 1367 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 136:
#line 1212 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ExpressionAlias) = new ExpressionAlias((yystack_[0].value.p_Expression));
    }
#line 1375 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 137:
#line 1215 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ExpressionAlias) = new ExpressionAlias((yystack_[0].value.p_Expression));
    }
#line 1383 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 138:
#line 1218 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ExpressionAlias) = (yystack_[1].value.p_Variable) ? new ExpressionAlias((yystack_[2].value.p_Expression), (yystack_[1].value.p_Variable)) : new ExpressionAlias((yystack_[2].value.p_Expression));
    }
#line 1391 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 139:
#line 1227 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yystack_[0].value.p_Variable)));
    }
#line 1399 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 140:
#line 1233 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expressions) = (yystack_[0].value.p_Expressions);
}
#line 1407 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 141:
#line 1239 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expressions) = new ProductionVector<const Expression*>((yystack_[0].value.p_Expression));
    }
#line 1415 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 142:
#line 1242 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yystack_[1].value.p_Expressions)->push_back((yystack_[0].value.p_Expression));
	(yylhs.value.p_Expressions) = (yystack_[1].value.p_Expressions);
    }
#line 1424 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 144:
#line 1254 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_OrderConditions) = (yystack_[0].value.p_OrderConditions);
    }
#line 1432 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 145:
#line 1261 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yylhs.value.p_OrderConditions)->push_back((yystack_[0].value.p_OrderConditionPair));
    }
#line 1441 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 146:
#line 1265 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yystack_[1].value.p_OrderConditions)->push_back((yystack_[0].value.p_OrderConditionPair));
	(yylhs.value.p_OrderConditions) = (yystack_[1].value.p_OrderConditions);
    }
#line 1450 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 148:
#line 1275 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yylhs.value.p_OrderConditionPair).expression = (yystack_[0].value.p_Expression);
    }
#line 1459 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 149:
#line 1283 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_e_ASCorDESC) = ORDER_Asc;
    }
#line 1467 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 150:
#line 1286 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_e_ASCorDESC) = ORDER_Desc;
    }
#line 1475 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 151:
#line 1294 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_OrderConditionPair).ascOrDesc = (yystack_[1].value.p_e_ASCorDESC);
	(yylhs.value.p_OrderConditionPair).expression = (yystack_[0].value.p_Expression);
    }
#line 1484 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 153:
#line 1303 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new TTermExpression((yystack_[0].value.p_Variable));
    }
#line 1492 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 154:
#line 1310 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_LimitOffsetPair).limit = (yystack_[1].value.p_LimitOffsetPair).limit;
	(yylhs.value.p_LimitOffsetPair).offset = (yystack_[0].value.p_LimitOffsetPair).offset;
    }
#line 1501 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 155:
#line 1314 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_LimitOffsetPair).limit = (yystack_[0].value.p_LimitOffsetPair).limit;
	(yylhs.value.p_LimitOffsetPair).offset = (yystack_[1].value.p_LimitOffsetPair).offset;
    }
#line 1510 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 156:
#line 1322 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_LimitOffsetPair).offset = OFFSET_None;
    }
#line 1518 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 158:
#line 1330 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_LimitOffsetPair).limit = LIMIT_None;
    }
#line 1526 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 160:
#line 1337 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yystack_[0].value.p_NumericRDFLiteral))->getValue();
    }
#line 1534 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 161:
#line 1343 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yystack_[0].value.p_NumericRDFLiteral))->getValue();
    }
#line 1542 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 163:
#line 1353 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ValuesClause) = (yystack_[0].value.p_ValuesClause);
    }
#line 1550 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 164:
#line 1359 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ValuesClause) = NULL;
    }
#line 1558 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 166:
#line 1366 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_Operation) = driver.root;
      }
#line 1566 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 170:
#line 1381 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	OperationSet* ret = driver.root ? dynamic_cast<OperationSet*>(driver.root) : new OperationSet();
	ret->push_back((yystack_[0].value.p_Operation));
	driver.root = ret;
	std::copy(driver.bnodesInThisOpperation.begin(), driver.bnodesInThisOpperation.end(),
		  std::inserter(driver.bnodesInOldOpperations, driver.bnodesInOldOpperations.begin()));
      }
#line 1578 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 185:
#line 1410 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Operation) = new Load((yystack_[2].value.p_Silence), (yystack_[1].value.p_URI), (yystack_[0].value.p_URI));
    }
#line 1586 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 186:
#line 1416 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Silence) = SILENT_No;
    }
#line 1594 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 187:
#line 1419 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Silence) = SILENT_Yes;
}
#line 1602 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 188:
#line 1426 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_URI) = (yystack_[0].value.p_URI);
    }
#line 1610 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 189:
#line 1433 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_URI) = NULL;
    }
#line 1618 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 191:
#line 1440 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Operation) = new Clear((yystack_[1].value.p_Silence), (yystack_[0].value.p_URI));
    }
#line 1626 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 192:
#line 1446 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Operation) = new Drop((yystack_[1].value.p_Silence), (yystack_[0].value.p_URI));
}
#line 1634 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 193:
#line 1452 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Operation) = new Create((yystack_[1].value.p_Silence), (yystack_[0].value.p_URI));
    }
#line 1642 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 194:
#line 1458 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Operation) = new Add((yystack_[3].value.p_Silence), (yystack_[2].value.p_URI), (yystack_[0].value.p_URI));
}
#line 1650 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 195:
#line 1464 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Operation) = new Move((yystack_[3].value.p_Silence), (yystack_[2].value.p_URI), (yystack_[0].value.p_URI));
}
#line 1658 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 196:
#line 1470 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Operation) = new Copy((yystack_[3].value.p_Silence), (yystack_[2].value.p_URI), (yystack_[0].value.p_URI));
}
#line 1666 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 197:
#line 1476 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.inINSERTDATA = true;
      }
#line 1674 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 198:
#line 1478 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  driver.inINSERTDATA = false;
	  (yylhs.value.p_Operation) = new Insert((yystack_[0].value.p_TableOperation), NULL);
	  driver.curOp = NULL;
	  driver.curBGP = NULL;
	}
#line 1685 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 199:
#line 1487 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.inDELETEDATA = true;
      }
#line 1693 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 200:
#line 1489 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  driver.inDELETEDATA = false;
	  (yylhs.value.p_Operation) = new Delete(true, (yystack_[0].value.p_TableOperation), NULL);
	  driver.curOp = NULL;
	  driver.curBGP = NULL;
	}
#line 1704 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 201:
#line 1498 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.inDELETEWHERE = true;
      }
#line 1712 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 202:
#line 1500 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  driver.inDELETEWHERE = false;
	  (yylhs.value.p_Operation) = new Delete(true, (yystack_[0].value.p_TableOperation), NULL);
    }
#line 1721 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 203:
#line 1509 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.restoreFilter(NULL);
	(yylhs.value.p_Operation) = new Modify((yystack_[4].value.p_DeleteInsert).del, (yystack_[4].value.p_DeleteInsert).ins, new WhereClause(driver.ensureGraphPattern()), (yystack_[2].value.p_TableOperation), (yystack_[5].value.p_URI), (yystack_[3].value.p_UsingPairs));
	driver.curOp = NULL;
    }
#line 1731 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 204:
#line 1517 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_URI) = (yystack_[0].value.p_URI);
    }
#line 1739 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 205:
#line 1523 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_URI) = NULL;
    }
#line 1747 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 207:
#line 1530 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Insert) = NULL;
    }
#line 1755 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 209:
#line 1537 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_DeleteInsert).del = (yystack_[1].value.p_Delete);
	(yylhs.value.p_DeleteInsert).ins = (yystack_[0].value.p_Insert);
    }
#line 1764 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 210:
#line 1541 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_DeleteInsert).del = NULL;
	(yylhs.value.p_DeleteInsert).ins = (yystack_[0].value.p_Insert);
    }
#line 1773 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 211:
#line 1548 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_UsingPairs) = NULL;
    }
#line 1781 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 212:
#line 1551 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	if ((yystack_[1].value.p_UsingPairs) == NULL)
	    (yystack_[1].value.p_UsingPairs) = new std::vector<s_UsingPair>();
	(yystack_[1].value.p_UsingPairs)->push_back((yystack_[0].value.p_UsingPair));
	(yylhs.value.p_UsingPairs) = (yystack_[1].value.p_UsingPairs);
    }
#line 1792 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 213:
#line 1560 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TableOperation) = (yystack_[0].value.p_TableOperation);
    }
#line 1800 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 214:
#line 1566 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TableOperation) = NULL;
    }
#line 1808 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 216:
#line 1573 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.inDELETECLAUSE = true;
      }
#line 1816 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 217:
#line 1575 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  driver.inDELETECLAUSE = false;
	  (yylhs.value.p_Delete) = new Delete(false, (yystack_[0].value.p_TableOperation), NULL);
      }
#line 1825 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 218:
#line 1582 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.inINSERTQUAD = true;
      }
#line 1833 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 219:
#line 1584 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  driver.inINSERTQUAD = false;
	  (yylhs.value.p_Insert) = new Insert((yystack_[0].value.p_TableOperation), NULL);
      }
#line 1842 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 220:
#line 1591 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_UsingPair) = (yystack_[0].value.p_UsingPair);
    }
#line 1850 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 221:
#line 1597 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_UsingPair).named = false;
	(yylhs.value.p_UsingPair).name = (yystack_[0].value.p_URI);
    }
#line 1859 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 222:
#line 1601 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_UsingPair).named = true;
	(yylhs.value.p_UsingPair).name = (yystack_[0].value.p_URI);
    }
#line 1868 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 223:
#line 1608 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_URI) = NULL;
    }
#line 1876 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 224:
#line 1611 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_URI) = (yystack_[0].value.p_URI);
    }
#line 1884 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 227:
#line 1622 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_URI) = (yystack_[0].value.p_URI);
    }
#line 1892 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 228:
#line 1628 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_URI) = (yystack_[0].value.p_URI);
    }
#line 1900 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 229:
#line 1631 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_URI) = driver.atomFactory->getURI("tag:eric@w3.org,2012-swobjparm/DEFAULT");
    }
#line 1908 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 230:
#line 1634 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_URI) = driver.atomFactory->getURI("tag:eric@w3.org,2012-swobjparm/NAMED");
    }
#line 1916 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 231:
#line 1637 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_URI) = driver.atomFactory->getURI("tag:eric@w3.org,2012-swobjparm/ALL");
    }
#line 1924 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 232:
#line 1644 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TableOperation) = (yystack_[1].value.p_TableOperation);
	driver.curOp = NULL;
    }
#line 1933 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 233:
#line 1651 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TableOperation) = (yystack_[1].value.p_TableOperation);
    }
#line 1941 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 234:
#line 1657 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.curBGP = NULL;
      }
#line 1949 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 235:
#line 1659 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_TableOperation) = driver.ensureGraphPattern();
	  driver.curOp = NULL;
      }
#line 1958 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 244:
#line 1688 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.restoreFilter(NULL);
	(yylhs.value.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
	driver.curFilter = NULL;
      }
#line 1969 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 245:
#line 1693 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yystack_[0].value.p_TTerm);
      }
#line 1978 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 246:
#line 1696 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
#line 1987 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 247:
#line 1699 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  driver.curBGP = NULL;
	  driver.curOp = driver.makeConjunction((yystack_[7].value.p_TableOperation), new GraphGraphPattern((yystack_[5].value.p_TTerm), driver.ensureGraphPattern()));
	  driver.curGraphName = (yystack_[4].value.p_TTerm);
      }
#line 1997 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 253:
#line 1721 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	BindingsMap::const_iterator rs = driver.bindingsMap.find((yystack_[0].value.p_RSName)->name);
	if (rs == driver.bindingsMap.end() || rs->second == NULL) {
	    error(*driver.yylloc, std::string("") + "unknown named result set " + (yystack_[0].value.p_RSName)->name);
	    driver.curOp = new DefaultGraphPattern();
	} else {
	    SWObjectDuplicator dup(driver.atomFactory);
	    rs->second->express(&dup);
	    TableOperation* b = dup.last.tableOperation;
	    driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, b) : b;
	}
      }
#line 2014 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 257:
#line 1744 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.curBGP = NULL;
      }
#line 2022 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 258:
#line 1746 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
#line 2032 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 279:
#line 1820 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, (yystack_[0].value.p_ValuesClause)) : (yystack_[0].value.p_ValuesClause);
    }
#line 2040 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 281:
#line 1827 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.curOp = new Print(driver.ensureGraphPattern());
    }
#line 2048 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 282:
#line 1833 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.restoreFilter(NULL);
	(yylhs.value.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
#line 2058 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 283:
#line 1837 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  OptionalGraphPattern* ret = new OptionalGraphPattern(driver.ensureGraphPattern());
	  if (driver.curFilter) {
	      driver.curFilter->copyExpressionsTo(ret);
	      delete driver.curFilter;
	      driver.curFilter = NULL;
	  }
	  driver.curOp = driver.makeConjunction((yystack_[1].value.p_TableOperation), ret);
      }
#line 2072 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 284:
#line 1849 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.restoreFilter(NULL);
	(yylhs.value.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
#line 2082 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 285:
#line 1853 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_FilterExpressions) = driver.saveFilter();
      }
#line 2090 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 286:
#line 1855 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yystack_[0].value.p_TTerm);
      }
#line 2099 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 287:
#line 1858 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  driver.restoreFilter((yystack_[3].value.p_FilterExpressions));
	  driver.curOp = driver.makeConjunction((yystack_[4].value.p_TableOperation), new GraphGraphPattern((yystack_[2].value.p_TTerm), driver.ensureGraphPattern()));
	  driver.curGraphName = (yystack_[1].value.p_TTerm);
      }
#line 2109 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 288:
#line 1866 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.restoreFilter(NULL);
	(yylhs.value.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
#line 2119 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 289:
#line 1870 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_FilterExpressions) = driver.saveFilter();
      }
#line 2127 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 290:
#line 1872 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  driver.restoreFilter((yystack_[3].value.p_FilterExpressions));
	  driver.curOp = driver.makeConjunction((yystack_[4].value.p_TableOperation), new ServiceGraphPattern((yystack_[1].value.p_TTerm), driver.ensureGraphPattern(), (yystack_[2].value.p_Silence), driver.atomFactory, false));
      }
#line 2136 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 291:
#line 1879 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.restoreFilter(NULL);
	(yylhs.value.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
#line 2146 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 292:
#line 1883 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_FilterExpressions) = driver.saveFilter();
      }
#line 2154 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 293:
#line 1885 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  /*
	    serviceID,
	    from,
	    e_Silence
	    where
	   */
	  driver.lastWhereClause = (yystack_[0].value.p_WhereClause);
	  driver.restoreFilter((yystack_[5].value.p_FilterExpressions));
	  driver.curOp = driver.makeConjunction
	      ((yystack_[6].value.p_TableOperation), new SADIGraphPattern((yystack_[3].value.p_TTerm), (yystack_[4].value.p_Silence), (yystack_[1].value.p_TableOperation), (yystack_[0].value.p_WhereClause)));
    }
#line 2171 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 294:
#line 1900 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	const TableOperation* op = driver.ensureGraphPattern();
	if (driver.validate & SPARQLDriver::VALIDATE_noReassign &&
	    (op->getBindingState().binds   .find((yystack_[1].value.p_Variable)) != op->getBindingState().binds   .end() ||
	     op->getBindingState().optional.find((yystack_[1].value.p_Variable)) != op->getBindingState().optional.end()))
	    error(*driver.yylloc, "Can't bind " + (yystack_[1].value.p_Variable)->str() + " to " + (yystack_[3].value.p_Expression)->str() + " because it's already bound");
	driver.curOp = new Bind(op, (yystack_[3].value.p_Expression), (yystack_[1].value.p_Variable));
	// no more triples go into the current BGP, per
	//   http://www.w3.org/TR/sparql11-query/#sparqlTranslateGraphPatterns
	// test reference:
	//   http://www.sparql.org/query-validator?query=ASK+{+%3Fs+%3Fp+%3Fo+FILTER+%281%29+BIND+%282+AS+%3Fb%29+%3Fs2+%3Fp2+%3Fo2+FILTER+%283%29+BIND+%284+AS+%3Fd%29}&languageSyntax=SPARQL&outputFormat=algebra&linenumbers=false
	driver.curBGP = NULL;
    }
#line 2189 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 295:
#line 1916 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ValuesClause) = (yystack_[0].value.p_ValuesClause);
    }
#line 2197 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 298:
#line 1927 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.startBindingSet();
      }
#line 2205 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 299:
#line 1929 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  driver.addBindingVar((yystack_[0].value.p_Variable));
      }
#line 2213 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 300:
#line 1931 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_ValuesClause) = new ValuesClause(driver.endBindingSet());
      }
#line 2221 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 303:
#line 1942 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.startBindingRow();
	driver.addBindingValue((yystack_[0].value.p_TTerm));
	driver.endBindingRow();
    }
#line 2231 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 304:
#line 1950 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.startBindingSet();
    }
#line 2239 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 305:
#line 1952 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_ValuesClause) = new ValuesClause(driver.endBindingSet());
      }
#line 2247 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 307:
#line 1959 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.addBindingVar((yystack_[0].value.p_Variable));
    }
#line 2255 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 311:
#line 1971 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.addBindingValue((yystack_[0].value.p_TTerm));
    }
#line 2263 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 312:
#line 1977 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.startBindingRow();
      }
#line 2271 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 313:
#line 1979 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  driver.endBindingRow();
      }
#line 2279 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 314:
#line 1982 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.startBindingRow();
	driver.endBindingRow();
    }
#line 2288 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 317:
#line 1994 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_URI);
    }
#line 2296 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 318:
#line 1997 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_RDFLiteral);
    }
#line 2304 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 319:
#line 2000 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_NumericRDFLiteral);
    }
#line 2312 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 320:
#line 2003 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_BooleanRDFLiteral);
    }
#line 2320 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 321:
#line 2006 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = TTerm::Unbound;
    }
#line 2328 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 322:
#line 2009 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = TTerm::Unbound;
    }
#line 2336 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 323:
#line 2012 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_Variable);
    }
#line 2344 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 324:
#line 2018 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.restoreFilter(NULL);
	(yylhs.value.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
#line 2354 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 325:
#line 2022 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_FilterExpressions) = driver.saveFilter();
      }
#line 2362 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 326:
#line 2024 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  driver.restoreFilter((yystack_[1].value.p_FilterExpressions));
	  driver.curOp = driver.makeConjunction((yystack_[2].value.p_TableOperation), new MinusGraphPattern(driver.ensureGraphPattern()));
      }
#line 2371 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 327:
#line 2032 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.restoreFilter(NULL);
	(yylhs.value.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
#line 2381 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 328:
#line 2036 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_FilterExpressions) = driver.saveFilter();
      }
#line 2389 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 329:
#line 2038 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  driver.restoreFilter((yystack_[2].value.p_FilterExpressions));
	  driver.curOp = driver.makeConjunction((yystack_[3].value.p_TableOperation), driver.curOp);
      }
#line 2398 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 330:
#line 2046 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.ensureGraphPattern();
	driver.restoreFilter(NULL);
	(yylhs.value.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
#line 2409 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 331:
#line 2051 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yystack_[1].value.p_TableOperation), driver.ensureGraphPattern());
      }
#line 2418 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 334:
#line 2064 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	if (driver.curFilter == NULL) {
	    driver.ensureGraphPattern();
	    driver.curFilter = new FilterExpressions();
	}
	driver.curFilter->addExpression((yystack_[0].value.p_Expression));
    }
#line 2430 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 338:
#line 2080 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall((yystack_[1].value.p_URI), (yystack_[0].value.p_ArgList)));
    }
#line 2438 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 339:
#line 2088 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ArgList) = NULL;
    }
#line 2446 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 340:
#line 2092 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yystack_[0].value.p_Expression));
      }
#line 2455 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 341:
#line 2095 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = (yystack_[2].value.p_Expressions);
      }
#line 2464 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 342:
#line 2102 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_distinctness) = DIST_all;
    }
#line 2472 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 343:
#line 2105 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_distinctness) = DIST_distinct;
    }
#line 2480 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 344:
#line 2112 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = (yystack_[0].value.p_Expression);
    }
#line 2488 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 346:
#line 2120 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.curExprList->push_back((yystack_[0].value.p_Expression));
    }
#line 2496 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 347:
#line 2135 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expressions) = new ProductionVector<const Expression*>();
    }
#line 2504 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 348:
#line 2138 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yystack_[0].value.p_Expression));
      }
#line 2513 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 349:
#line 2141 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_Expressions) = driver.curExprList;
	  driver.curExprList = (yystack_[2].value.p_Expressions);
      }
#line 2522 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 350:
#line 2148 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.curSubject = (yystack_[0].value.p_TTerm);
    }
#line 2530 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 352:
#line 2151 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.curSubject = (yystack_[0].value.p_TTerm);
    }
#line 2538 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 364:
#line 2193 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_TTerm);
	driver.curPredicate = (yylhs.value.p_TTerm);
    }
#line 2547 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 365:
#line 2197 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = TTerm::RDF_type;
	driver.curPredicate = (yylhs.value.p_TTerm);
    }
#line 2556 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 370:
#line 2220 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yystack_[0].value.p_TTerm)), true);
    }
#line 2565 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 371:
#line 2228 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.curSubject = (yystack_[0].value.p_TTerm);
      }
#line 2573 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 373:
#line 2231 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  driver.curSubject = (yystack_[0].value.p_TTerm);
        }
#line 2581 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 378:
#line 2246 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.curPredicate = (yystack_[0].value.p_TTerm);
      }
#line 2589 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 382:
#line 2257 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.curPredicate = (yystack_[0].value.p_TTerm);
      }
#line 2597 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 389:
#line 2277 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	const URI* t = (yystack_[0].value.p_PropertyPath)->release();
	// if (!t)
	//     w3c_sw_LINEN << "property path: " << $1->str() << "\n";
	(yylhs.value.p_TTerm) = t ? t : (const TTerm*)new PropertyPath((yystack_[0].value.p_PropertyPath));
    }
#line 2608 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 390:
#line 2286 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_Variable);
    }
#line 2616 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 395:
#line 2305 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yystack_[0].value.p_TTerm)), true);
    }
#line 2625 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 397:
#line 2316 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_PropertyPath) = driver.lastPropertyPathAlternative;
	driver.lastPropertyPathAlternative = (yystack_[0].value.p_PropertyPath);
      }
#line 2634 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 398:
#line 2319 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_PropertyPath) = (yystack_[0].value.p_PropertyPath) ? (yystack_[0].value.p_PropertyPath) : (yystack_[2].value.p_PropertyPath);
	  driver.lastPropertyPathAlternative = (yystack_[1].value.p_PropertyPath);
      }
#line 2643 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 399:
#line 2326 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_PropertyPath) = (yystack_[0].value.p_PropertyPath);
    }
#line 2651 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 400:
#line 2332 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_PropertyPath) = NULL;
    }
#line 2659 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 401:
#line 2335 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_PropertyPath) = new PropertyPath::Alternative((yystack_[1].value.p_PropertyPath) ? (yystack_[1].value.p_PropertyPath) : driver.lastPropertyPathAlternative, (yystack_[0].value.p_PropertyPath));
    }
#line 2667 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 402:
#line 2341 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_PropertyPath) = driver.lastPropertyPathSequence;
	driver.lastPropertyPathSequence = (yystack_[0].value.p_PropertyPath);
      }
#line 2676 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 403:
#line 2344 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {	
	  (yylhs.value.p_PropertyPath) = (yystack_[0].value.p_PropertyPath) ? (yystack_[0].value.p_PropertyPath) : (yystack_[2].value.p_PropertyPath);
	  driver.lastPropertyPathSequence = (yystack_[1].value.p_PropertyPath);
      }
#line 2685 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 404:
#line 2351 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_PropertyPath) = (yystack_[0].value.p_PropertyPath);
    }
#line 2693 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 405:
#line 2357 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_PropertyPath) = NULL;
    }
#line 2701 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 406:
#line 2360 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_PropertyPath) = new PropertyPath::Sequence((yystack_[1].value.p_PropertyPath) ? (yystack_[1].value.p_PropertyPath) : driver.lastPropertyPathSequence, (yystack_[0].value.p_PropertyPath));
    }
#line 2709 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 407:
#line 2366 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_PropertyPath) = (yystack_[0].value.p_RepeatRange).min == 1 && (yystack_[0].value.p_RepeatRange).max == 1 ? (yystack_[1].value.p_PropertyPath) : new PropertyPath::Repeated((yystack_[1].value.p_PropertyPath), (yystack_[0].value.p_RepeatRange).min, (yystack_[0].value.p_RepeatRange).max);
    }
#line 2717 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 408:
#line 2372 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_RepeatRange).min = 1; (yylhs.value.p_RepeatRange).max = 1;
    }
#line 2725 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 411:
#line 2380 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_PropertyPath) = new PropertyPath::Inverse((yystack_[0].value.p_PropertyPath));
    }
#line 2733 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 412:
#line 2386 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_RepeatRange).min = 0; (yylhs.value.p_RepeatRange).max = 1;
    }
#line 2741 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 413:
#line 2389 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_RepeatRange).min = 0; (yylhs.value.p_RepeatRange).max = PropertyPath::Repeated::Unlimited;
    }
#line 2749 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 414:
#line 2392 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_RepeatRange).min = 1; (yylhs.value.p_RepeatRange).max = PropertyPath::Repeated::Unlimited;
    }
#line 2757 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 415:
#line 2398 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_PropertyPath) = new PropertyPath::Predicate((yystack_[0].value.p_URI));
    }
#line 2765 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 416:
#line 2401 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_PropertyPath) = new PropertyPath::Predicate(TTerm::RDF_type);
    }
#line 2773 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 417:
#line 2404 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_PropertyPath) = new PropertyPath::Negated((yystack_[0].value.p_PropertyPath));
    }
#line 2781 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 418:
#line 2407 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_PropertyPath) = (yystack_[1].value.p_PropertyPath);
    }
#line 2789 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 420:
#line 2417 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_PropertyPath) = (yystack_[1].value.p_PropertyPath);
    }
#line 2797 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 421:
#line 2426 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_PropertyPath) = (yystack_[0].value.p_PropertyPath);
    }
#line 2805 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 422:
#line 2432 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_PropertyPath) = NULL;
    }
#line 2813 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 423:
#line 2435 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_PropertyPath) = new PropertyPath::Alternative((yystack_[1].value.p_PropertyPath) ? (yystack_[1].value.p_PropertyPath) : driver.lastPropertyPathSetAlternative, (yystack_[0].value.p_PropertyPath));
    }
#line 2821 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 424:
#line 2441 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_PropertyPath) = driver.lastPropertyPathSetAlternative;
	driver.lastPropertyPathSetAlternative = (yystack_[0].value.p_PropertyPath);
      }
#line 2830 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 425:
#line 2444 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  driver.lastPropertyPathSetAlternative = (yystack_[1].value.p_PropertyPath);
	  (yylhs.value.p_PropertyPath) = (yystack_[0].value.p_PropertyPath);
      }
#line 2839 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 426:
#line 2451 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_PropertyPath) = NULL;
    }
#line 2847 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 428:
#line 2458 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_PropertyPath) = new PropertyPath::Predicate((yystack_[0].value.p_URI));
    }
#line 2855 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 429:
#line 2461 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_PropertyPath) = new PropertyPath::Predicate(TTerm::RDF_type);
    }
#line 2863 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 430:
#line 2464 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_PropertyPath) = new PropertyPath::Inverse((yystack_[0].value.p_PropertyPath));
    }
#line 2871 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 431:
#line 2470 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_PropertyPath) = new PropertyPath::Predicate((yystack_[0].value.p_URI));
    }
#line 2879 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 432:
#line 2473 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_PropertyPath) = new PropertyPath::Predicate(TTerm::RDF_type);
    }
#line 2887 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 435:
#line 2486 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_SubjectPredicatePair).subject = driver.curSubject;
	(yylhs.value.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
#line 2897 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 436:
#line 2490 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yystack_[2].value.p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yystack_[2].value.p_SubjectPredicatePair).predicate;
      }
#line 2907 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 437:
#line 2499 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	if ((yystack_[3].value.p_listModifier) == LIST_exact) {
	    (yylhs.value.p_TTerm) = driver.createBNode();
	    const TTerm* tail = (yylhs.value.p_TTerm);
	    ProductionVector<const TTerm*>* members = (yystack_[1].value.p_TTerms);
	    driver.ensureBasicGraphPattern();
	    for (unsigned i = 0; i < members->size(); i++) {
		// driver.curBGP->addTriplePattern
		//     (driver.atomFactory->getTriple(tail, TTerm::RDF_type, TTerm::RDF_List), true);
		driver.curBGP->addTriplePattern
		    (driver.atomFactory->getTriple(tail, TTerm::RDF_first, members->at(i)), true);
		const TTerm* nextTail = i == members->size()-1 ? (const TTerm*)TTerm::RDF_nil : driver.createBNode();
		driver.curBGP->addTriplePattern
		    (driver.atomFactory->getTriple(tail, TTerm::RDF_rest, nextTail), true);
		tail = nextTail;
	    }
	    members->clear();
	    delete members;
	} else if ((yystack_[3].value.p_listModifier) == LIST_members) {
	    (yylhs.value.p_TTerm) = new Members((yystack_[1].value.p_TTerms));
	} else {
	    error(yylhs.location, "unsupported function");
	}
    }
#line 2936 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 438:
#line 2527 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_listModifier) = LIST_members;
    }
#line 2944 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 439:
#line 2530 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_listModifier) = LIST_starts;
    }
#line 2952 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 440:
#line 2533 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_listModifier) = LIST_ends;
    }
#line 2960 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 441:
#line 2536 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_listModifier) = LIST_any;
    }
#line 2968 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 442:
#line 2539 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_listModifier) = LIST_unordered;
    }
#line 2976 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 443:
#line 2546 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_listModifier) = LIST_exact;
    }
#line 2984 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 445:
#line 2554 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerms) = new ProductionVector<const TTerm*>();
	(yylhs.value.p_TTerms)->push_back((yystack_[0].value.p_TTerm));
    }
#line 2993 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 446:
#line 2558 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yystack_[1].value.p_TTerms)->push_back((yystack_[0].value.p_TTerm));
	(yylhs.value.p_TTerms) = (yystack_[1].value.p_TTerms);
    }
#line 3002 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 449:
#line 2570 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_SubjectPredicatePair).subject = driver.curSubject;
	(yylhs.value.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
#line 3012 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 450:
#line 2574 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_TTerm) = driver.curSubject;
	  driver.curSubject = (yystack_[2].value.p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yystack_[2].value.p_SubjectPredicatePair).predicate;
      }
#line 3022 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 451:
#line 2582 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	if ((yystack_[3].value.p_listModifier) == LIST_exact) {
	    (yylhs.value.p_TTerm) = driver.createBNode();
	    const TTerm* tail = (yylhs.value.p_TTerm);
	    ProductionVector<const TTerm*>* members = (yystack_[1].value.p_TTerms);
	    driver.ensureBasicGraphPattern();
	    for (unsigned i = 0; i < members->size(); i++) {
		// driver.curBGP->addTriplePattern
		//     (driver.atomFactory->getTriple(tail, TTerm::RDF_type, TTerm::RDF_List), true);
		driver.curBGP->addTriplePattern
		    (driver.atomFactory->getTriple(tail, TTerm::RDF_first, members->at(i)), true);
		const TTerm* nextTail = i == members->size()-1 ? (const TTerm*)TTerm::RDF_nil : driver.createBNode();
		driver.curBGP->addTriplePattern
		    (driver.atomFactory->getTriple(tail, TTerm::RDF_rest, nextTail), true);
		tail = nextTail;
	    }
	    members->clear();
	    delete members;
	} else if ((yystack_[3].value.p_listModifier) == LIST_members) {
	    (yylhs.value.p_TTerm) = new Members((yystack_[1].value.p_TTerms));
	} else {
	    error(yylhs.location, "unsupported function");
	}
    }
#line 3051 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 452:
#line 2609 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerms) = new ProductionVector<const TTerm*>();
	(yylhs.value.p_TTerms)->push_back((yystack_[0].value.p_TTerm));
    }
#line 3060 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 453:
#line 2613 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yystack_[1].value.p_TTerms)->push_back((yystack_[0].value.p_TTerm));
	(yylhs.value.p_TTerms) = (yystack_[1].value.p_TTerms);
    }
#line 3069 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 458:
#line 2630 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_Variable);
    }
#line 3077 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 460:
#line 2637 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_Variable);
    }
#line 3085 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 461:
#line 2640 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_URI);
    }
#line 3093 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 464:
#line 2651 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_URI);
    }
#line 3101 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 465:
#line 2654 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_RDFLiteral);
    }
#line 3109 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 466:
#line 2657 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_NumericRDFLiteral);
    }
#line 3117 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 467:
#line 2660 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_BooleanRDFLiteral);
    }
#line 3125 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 469:
#line 2664 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = TTerm::RDF_nil; // !!! new GraphTerm_rule5($1);
    }
#line 3133 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 471:
#line 2675 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = (yystack_[0].value.p_Expressions)->size() > 0 ? new BooleanDisjunction((yystack_[1].value.p_Expression), (yystack_[0].value.p_Expressions)) : (yystack_[1].value.p_Expression);
	(yystack_[0].value.p_Expressions)->clear();
	delete (yystack_[0].value.p_Expressions);
    }
#line 3143 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 472:
#line 2684 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = (yystack_[0].value.p_Expression);
    }
#line 3151 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 473:
#line 2691 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expressions) = new ProductionVector<const Expression*>();
    }
#line 3159 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 474:
#line 2694 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yystack_[1].value.p_Expressions)->push_back((yystack_[0].value.p_Expression));
	(yylhs.value.p_Expressions) = (yystack_[1].value.p_Expressions);
    }
#line 3168 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 475:
#line 2702 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = (yystack_[0].value.p_Expressions)->size() > 0 ? new BooleanConjunction((yystack_[1].value.p_Expression), (yystack_[0].value.p_Expressions)) : (yystack_[1].value.p_Expression);
	(yystack_[0].value.p_Expressions)->clear();
	delete (yystack_[0].value.p_Expressions);
    }
#line 3178 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 476:
#line 2711 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = (yystack_[0].value.p_Expression);
    }
#line 3186 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 477:
#line 2718 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expressions) = new ProductionVector<const Expression*>();
    }
#line 3194 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 478:
#line 2721 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yystack_[1].value.p_Expressions)->push_back((yystack_[0].value.p_Expression));
	(yylhs.value.p_Expressions) = (yystack_[1].value.p_Expressions);
    }
#line 3203 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 480:
#line 2733 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	if ((yystack_[0].value.p_ComparatorSense).comp) {
	    (yystack_[0].value.p_ComparatorSense).comp->setLeftParm((yystack_[1].value.p_Expression));
	    (yylhs.value.p_Expression) = new ComparatorExpression((yystack_[0].value.p_ComparatorSense).comp); // !!!
	    if ((yystack_[0].value.p_ComparatorSense).neg)
		(yylhs.value.p_Expression) = new BooleanNegation((yylhs.value.p_Expression));
	} else
	    (yylhs.value.p_Expression) = (yystack_[1].value.p_Expression);
    }
#line 3217 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 481:
#line 2746 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ComparatorSense).neg = false;
	(yylhs.value.p_ComparatorSense).comp = NULL;
    }
#line 3226 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 483:
#line 2754 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ComparatorSense).neg = false;
	(yylhs.value.p_ComparatorSense).comp = new BooleanEQ((yystack_[0].value.p_Expression));
    }
#line 3235 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 484:
#line 2758 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ComparatorSense).neg = false;
	(yylhs.value.p_ComparatorSense).comp = new BooleanNE((yystack_[0].value.p_Expression));
    }
#line 3244 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 485:
#line 2762 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ComparatorSense).neg = false;
	(yylhs.value.p_ComparatorSense).comp = new BooleanLT((yystack_[0].value.p_Expression));
    }
#line 3253 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 486:
#line 2766 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ComparatorSense).neg = false;
	(yylhs.value.p_ComparatorSense).comp = new BooleanGT((yystack_[0].value.p_Expression));
    }
#line 3262 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 487:
#line 2770 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ComparatorSense).neg = false;
	(yylhs.value.p_ComparatorSense).comp = new BooleanLE((yystack_[0].value.p_Expression));
    }
#line 3271 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 488:
#line 2774 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ComparatorSense).neg = false;
	(yylhs.value.p_ComparatorSense).comp = new BooleanGE((yystack_[0].value.p_Expression));
    }
#line 3280 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 489:
#line 2778 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ComparatorSense).neg = false;
	(yylhs.value.p_ComparatorSense).comp = new NaryIn((yystack_[0].value.p_Expressions));
    }
#line 3289 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 490:
#line 2782 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ComparatorSense).neg = true;
	(yylhs.value.p_ComparatorSense).comp = new NaryIn((yystack_[0].value.p_Expressions));
    }
#line 3298 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 492:
#line 2794 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = (yystack_[0].value.p_Expressions)->size() > 0 ? new ArithmeticSum((yystack_[1].value.p_Expression), (yystack_[0].value.p_Expressions)) : (yystack_[1].value.p_Expression);
	(yystack_[0].value.p_Expressions)->clear();
	delete (yystack_[0].value.p_Expressions);
    }
#line 3308 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 493:
#line 2803 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new NumberExpression((yystack_[0].value.p_NumericRDFLiteral));
    }
#line 3316 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 494:
#line 2806 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new NumberExpression((yystack_[0].value.p_NumericRDFLiteral));
    }
#line 3324 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 495:
#line 2813 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = (yystack_[0].value.p_Expression);
    }
#line 3332 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 496:
#line 2816 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new ArithmeticInverse((yystack_[0].value.p_Expression));
    }
#line 3340 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 497:
#line 2823 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = NULL;
    }
#line 3348 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 499:
#line 2831 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = (yystack_[0].value.p_Expression);
    }
#line 3356 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 500:
#line 2834 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new ArithmeticNegation((yystack_[0].value.p_Expression));
    }
#line 3364 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 501:
#line 2838 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	if ((yystack_[0].value.p_Expression) == NULL)
	    (yylhs.value.p_Expression) = (yystack_[1].value.p_Expression);
	else {
	    ProductionVector<const Expression*>* v = new ProductionVector<const Expression*>();
	    v->push_back((yystack_[1].value.p_Expression));
	    v->push_back((yystack_[0].value.p_Expression));
	    (yylhs.value.p_Expression) = new BooleanConjunction(v);
	}
    }
#line 3379 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 502:
#line 2852 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expressions) = new ProductionVector<const Expression*>();
    }
#line 3387 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 503:
#line 2855 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yystack_[1].value.p_Expressions)->push_back((yystack_[0].value.p_Expression));
	(yylhs.value.p_Expressions) = (yystack_[1].value.p_Expressions);
    }
#line 3396 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 504:
#line 2863 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = (yystack_[0].value.p_Expressions)->size() > 0 ? new ArithmeticProduct((yystack_[1].value.p_Expression), (yystack_[0].value.p_Expressions)) : (yystack_[1].value.p_Expression);
	(yystack_[0].value.p_Expressions)->clear();
	delete (yystack_[0].value.p_Expressions);
    }
#line 3406 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 505:
#line 2872 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expressions) = new ProductionVector<const Expression*>();
    }
#line 3414 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 506:
#line 2875 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yystack_[1].value.p_Expressions)->push_back((yystack_[0].value.p_Expression));
	(yylhs.value.p_Expressions) = (yystack_[1].value.p_Expressions);
    }
#line 3423 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 507:
#line 2882 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new BooleanNegation((yystack_[0].value.p_Expression));
    }
#line 3431 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 508:
#line 2885 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = (yystack_[0].value.p_Expression);
    }
#line 3439 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 509:
#line 2888 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new ArithmeticNegation((yystack_[0].value.p_Expression));
    }
#line 3447 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 514:
#line 2898 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new TTermExpression((yystack_[0].value.p_RDFLiteral));
    }
#line 3455 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 515:
#line 2901 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new TTermExpression((yystack_[0].value.p_NumericRDFLiteral));
    }
#line 3463 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 516:
#line 2904 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new TTermExpression((yystack_[0].value.p_BooleanRDFLiteral));
    }
#line 3471 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 517:
#line 2907 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new TTermExpression((yystack_[0].value.p_Variable));
    }
#line 3479 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 519:
#line 2914 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = (yystack_[1].value.p_Expression);
    }
#line 3487 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 520:
#line 2926 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 3495 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 521:
#line 2929 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 3503 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 522:
#line 2932 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yystack_[3].value.p_Expression), (yystack_[1].value.p_Expression), NULL));
    }
#line 3511 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 523:
#line 2935 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 3519 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 524:
#line 2938 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yystack_[1].value.p_Variable)), NULL, NULL));
    }
#line 3527 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 525:
#line 2941 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
      (yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yystack_[1].value.p_Expression), new TTermExpression(driver.atomFactory->getURI(driver.getBase())), NULL));
    }
#line 3535 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 526:
#line 2944 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
      (yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yystack_[1].value.p_Expression), new TTermExpression(driver.atomFactory->getURI(driver.getBase())), NULL));
    }
#line 3543 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 527:
#line 2948 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yystack_[0].value.p_Expression), NULL, NULL));
    }
#line 3551 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 528:
#line 2951 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
#line 3559 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 529:
#line 2954 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 3567 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 530:
#line 2957 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ceil, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 3575 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 531:
#line 2960 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 3583 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 532:
#line 2963 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 3591 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 533:
#line 2966 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yystack_[0].value.p_Expressions))));
    }
#line 3599 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 535:
#line 2970 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 3607 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 537:
#line 2974 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 3615 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 538:
#line 2977 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 3623 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 539:
#line 2980 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 3631 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 540:
#line 2983 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yystack_[3].value.p_Expression), (yystack_[1].value.p_Expression), NULL));
    }
#line 3639 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 541:
#line 2986 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yystack_[3].value.p_Expression), (yystack_[1].value.p_Expression), NULL));
    }
#line 3647 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 542:
#line 2989 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yystack_[3].value.p_Expression), (yystack_[1].value.p_Expression), NULL));
    }
#line 3655 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 543:
#line 2992 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_before, (yystack_[3].value.p_Expression), (yystack_[1].value.p_Expression), NULL));
    }
#line 3663 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 544:
#line 2995 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_after, (yystack_[3].value.p_Expression), (yystack_[1].value.p_Expression), NULL));
    }
#line 3671 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 545:
#line 2998 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 3679 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 546:
#line 3001 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 3687 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 547:
#line 3004 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 3695 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 548:
#line 3007 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 3703 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 549:
#line 3010 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 3711 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 550:
#line 3013 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 3719 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 551:
#line 3016 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 3727 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 552:
#line 3019 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_tz, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 3735 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 553:
#line 3022 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
#line 3743 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 554:
#line 3025 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_uuid, NULL, NULL, NULL));
    }
#line 3751 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 555:
#line 3028 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_struuid, NULL, NULL, NULL));
    }
#line 3759 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 556:
#line 3031 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 3767 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 557:
#line 3034 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 3775 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 558:
#line 3037 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 3783 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 559:
#line 3040 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 3791 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 560:
#line 3043 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 3799 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 561:
#line 3046 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, new ArgList((yystack_[0].value.p_Expressions))));
    }
#line 3807 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 562:
#line 3049 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yystack_[5].value.p_Expression), (yystack_[3].value.p_Expression), (yystack_[1].value.p_Expression)));
    }
#line 3815 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 563:
#line 3052 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yystack_[3].value.p_Expression), (yystack_[1].value.p_Expression), NULL));
    }
#line 3823 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 564:
#line 3055 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yystack_[3].value.p_Expression), (yystack_[1].value.p_Expression), NULL));
    }
#line 3831 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 565:
#line 3058 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yystack_[3].value.p_Expression), (yystack_[1].value.p_Expression), NULL));
    }
#line 3839 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 566:
#line 3061 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 3847 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 567:
#line 3064 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 3855 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 568:
#line 3067 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 3863 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 569:
#line 3070 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 3871 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 570:
#line 3073 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 3879 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 574:
#line 3084 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = (yystack_[1].value.p_Expression);
    }
#line 3887 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 575:
#line 3093 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = NULL;
    }
#line 3895 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 576:
#line 3100 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yystack_[4].value.p_Expression), (yystack_[2].value.p_Expression), (yystack_[1].value.p_Expression)));
    }
#line 3903 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 577:
#line 3107 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = NULL;
    }
#line 3911 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 579:
#line 3114 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yystack_[4].value.p_Expression), (yystack_[2].value.p_Expression), (yystack_[1].value.p_Expression)));
    }
#line 3919 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 580:
#line 3120 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_replace, (yystack_[6].value.p_Expression), (yystack_[4].value.p_Expression), (yystack_[2].value.p_Expression))); // !! , $8
    }
#line 3927 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 581:
#line 3126 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
#line 3936 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 582:
#line 3129 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  driver.restoreFilter(NULL);
	  (yylhs.value.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
#line 3946 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 583:
#line 3133 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_Expression) = new ExistsExpression(driver.ensureGraphPattern());
	  driver.curOp = (yystack_[1].value.p_TableOperation);
	  driver.countStar = (yystack_[2].value.p_parentCountStar);
      }
#line 3956 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 584:
#line 3141 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
      }
#line 3965 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 585:
#line 3144 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  driver.restoreFilter(NULL);
	  (yylhs.value.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
#line 3975 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 586:
#line 3148 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  // $$ = new ExistsExpression(false, driver.ensureGraphPattern());
	  (yylhs.value.p_Expression) = new BooleanNegation(new ExistsExpression(driver.ensureGraphPattern()));
	  driver.curOp = (yystack_[1].value.p_TableOperation);
	  driver.countStar = (yystack_[2].value.p_parentCountStar);
      }
#line 3986 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 587:
#line 3157 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.countStar = true;
	(yylhs.value.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yystack_[2].value.p_distinctness), (yystack_[1].value.p_Expression), AggregateCall::ScalarVals()));
    }
#line 3995 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 588:
#line 3165 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	driver.countStar = true;
	(yylhs.value.p_Expression) = new FunctionCallExpression(new AggregateCall((yystack_[4].value.p_URI), (yystack_[2].value.p_distinctness), (yystack_[1].value.p_Expression), AggregateCall::ScalarVals()));
    }
#line 4004 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 589:
#line 3174 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	  AggregateCall::ScalarVals svals;
	  if ((yystack_[1].value.p_RDFLiteral) != NULL)
	      svals["separator"] = (yystack_[1].value.p_RDFLiteral)->getLexicalValue();
	  (yylhs.value.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group_concat, (yystack_[3].value.p_distinctness), (yystack_[2].value.p_Expression), svals));
    }
#line 4015 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 590:
#line 3190 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = NULL;
    }
#line 4023 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 592:
#line 3197 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_URI) = TTerm::FUNC_sum;
    }
#line 4031 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 593:
#line 3200 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_URI) = TTerm::FUNC_min;
    }
#line 4039 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 594:
#line 3203 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_URI) = TTerm::FUNC_max;
    }
#line 4047 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 595:
#line 3206 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_URI) = TTerm::FUNC_avg;
    }
#line 4055 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 596:
#line 3209 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_URI) = TTerm::FUNC_sample;
    }
#line 4063 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 597:
#line 3215 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_RDFLiteral) = driver.getRDFLiteral(*(yystack_[0].value.p_string), NULL, NULL);
    }
#line 4071 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 598:
#line 3221 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_RDFLiteral) = NULL;
    }
#line 4079 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 600:
#line 3228 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	if ((yystack_[0].value.p_ArgList))
	    (yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall((yystack_[1].value.p_URI), (yystack_[0].value.p_ArgList)));
	else
	    (yylhs.value.p_Expression) = new TTermExpression((yystack_[1].value.p_URI));
    }
#line 4090 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 601:
#line 3238 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ArgList) = NULL;
    }
#line 4098 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 603:
#line 3246 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_RDFLiteral) = driver.getRDFLiteral(*(yystack_[1].value.p_string), (yystack_[0].value.p_uri_or_langtag).uri, (yystack_[0].value.p_uri_or_langtag).langtag);
	delete (yystack_[1].value.p_string);
    }
#line 4107 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 604:
#line 3254 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_URI) = (yystack_[0].value.p_URI);
    }
#line 4115 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 605:
#line 3261 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_uri_or_langtag).uri = NULL;
	(yylhs.value.p_uri_or_langtag).langtag = (yystack_[0].value.p_LANGTAG);
    }
#line 4124 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 606:
#line 3265 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_uri_or_langtag).uri = (yystack_[0].value.p_URI);
	(yylhs.value.p_uri_or_langtag).langtag = NULL;
    }
#line 4133 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 607:
#line 3273 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_uri_or_langtag).uri = NULL;
	(yylhs.value.p_uri_or_langtag).langtag = NULL;
    }
#line 4142 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;

  case 631:
#line 3327 "lib/SPARQLParser.ypp" // lalr1.cc:859
    {
	if (driver.validate & SPARQLDriver::VALIDATE_bnodeScope) {
	    driver.ensureBasicGraphPattern();

	    // prohibit e.g. ASK WHERE { {_:x :a :b } {_:x :c :d } }
	    // but not:
	    //   INSERT { _:b :a :b } WHERE {}; INSERT { _:b :c :d } WHERE {};
	    //   INSERT DATA { _:b :a :b }; INSERT DATA { _:b :c :d };
	    //   INSERT DATA { GRAPH <g1>{_:b :a :b } GRAPH <g2>{ _:b :c :d } }
	    if (!driver.inINSERTQUAD && !driver.inINSERTDATA) {
		std::map<const TTerm*, BasicGraphPattern*>::const_iterator lastUse
		    = driver.bnode2bgp.find((yystack_[0].value.p_TTerm));
		if (lastUse != driver.bnode2bgp.end() &&
		    lastUse->second != driver.curBGP)
		    error(yylhs.location, "bnode " + (yystack_[0].value.p_TTerm)->str() +
			  " already scoped to " + lastUse->second->str());
		else
		    driver.bnode2bgp.insert(std::make_pair((yystack_[0].value.p_TTerm), driver.curBGP));
	    }

	    // prohibit INSERT DATA { _:b1 :a :b };INSERT DATA { _:b1 :c :c }
	    // but not:
	    //   INSERT { _:b :a :b } WHERE { {_:b :a :b} }; INSERT { _:b :c :d } WHERE { {_:b :a :b} }
	    if (!driver.inINSERTQUAD) {
		if (driver.bnodesInOldOpperations.find((yystack_[0].value.p_TTerm))
		    != driver.bnodesInOldOpperations.end())
		    error(yylhs.location, "bnode " + (yystack_[0].value.p_TTerm)->str() +
			  " already scoped to an earlier opperation");
		else
		    driver.bnodesInThisOpperation.insert((yystack_[0].value.p_TTerm));
	    }
	}
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_TTerm);
    }
#line 4181 "lib/SPARQLParser.cpp" // lalr1.cc:859
    break;


#line 4185 "lib/SPARQLParser.cpp" // lalr1.cc:859
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
  SPARQLParser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  SPARQLParser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
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


  const short int SPARQLParser::yypact_ninf_ = -853;

  const short int SPARQLParser::yytable_ninf_ = -444;

  const short int
  SPARQLParser::yypact_[] =
  {
      73,  -116,    91,  -853,  -853,  -853,   683,  -853,  -853,  -853,
    -853,  -853,    98,    98,    98,    98,    60,    20,  -853,    77,
      98,    98,    98,  -853,  -853,  -853,    85,  -853,   108,  -853,
    -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,  -853,  -853,    99,   120,  -853,
      77,    46,   137,    46,  -853,    75,  -853,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,   276,  -853,  -853,  -853,  -853,  -853,
      95,  -853,    50,    50,    50,   110,   110,    60,    22,  -853,
    -853,  -853,   163,  -853,   100,  -853,  -853,  -853,   154,  -853,
    -853,    64,  -853,   177,    77,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,   175,  1172,    13,    60,  -853,    95,  -853,    70,
    -853,   125,    11,  -853,  -853,   121,    77,   153,   159,  -853,
    -853,  -853,  -853,  -853,  -853,    57,  -853,    23,  -853,  -853,
    -853,  1836,    95,    73,  -853,  -853,    60,    60,    55,  -853,
    -853,    58,   222,  -853,  -853,  -853,   137,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,  -853,  -853,   247,  -853,  -853,
    -853,  -853,   241,  -853,  -853,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,   -30,  -853,  -853,    77,  -853,  -853,  -853,  -853,
    -853,   125,   125,   125,  -853,   273,  -853,   208,  -853,  -853,
    -853,  -853,  -853,    50,  -853,    50,    50,   278,  -853,  -853,
    -853,   282,  -853,  2316,   253,   287,   289,    24,    28,   290,
     293,   295,   298,  -853,   301,   302,   308,   311,   313,   314,
     317,   322,   325,   326,   329,    28,   330,  -853,  -853,  -853,
    -853,   332,  -853,   333,   199,   203,   369,   370,   373,   374,
     242,   386,   245,   389,   392,   393,   394,   396,   398,   399,
     401,   402,   403,   404,   407,   409,   411,   417,   425,   426,
     427,   429,   433,   440,   441,  -853,  -853,  2435,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,   442,  -853,
    -853,  -853,    34,   125,   348,  -853,  -853,  -853,    60,    27,
    -853,   444,  -853,  -853,  -853,    84,  -853,    97,   479,  1172,
    -853,  -853,    97,  2121,    97,    77,  -853,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  2673,  2757,   462,  -853,  1277,  -853,
    -853,  -853,  -853,   452,    66,  -853,  2316,  2554,  2554,  2554,
    -853,   400,  -853,  -853,  -853,  -853,   321,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,    34,  -853,
    2316,  2316,  2316,  -853,  -853,  2316,  -853,  -853,  2316,  2316,
    2316,  2316,  -853,  2316,  2316,  2316,  2316,    57,  2316,  2316,
    2316,  2316,  2316,  2316,  -853,   472,   472,  2316,  -853,  -853,
    2316,  2316,  2316,  2316,  -853,  2316,  -853,  2316,  2316,  2316,
    2316,  2316,  2316,  2316,  2316,  2316,  2316,  2316,  2316,  2316,
    2316,  2316,  2316,  2316,  2316,  2316,  2316,  2316,  2316,  -853,
     472,   472,  -853,  -853,  -853,  -853,    77,  -853,  -853,    11,
     315,    11,  -853,  1427,  -853,  -853,  1243,  -853,  -853,   388,
    -853,  -853,   341,  -853,  -853,  -853,  -853,   443,  2121,  -853,
    -853,  1529,   491,  -853,  -853,  -853,  -853,  -853,  2017,  -853,
    -853,  -853,  -853,  2316,  2673,  -853,  -853,  -853,  -853,  2757,
    -853,  -853,  -853,  -853,  -853,   474,   244,  -853,  -853,  -853,
    -853,   108,   463,  -853,  -853,  -853,    35,   465,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,    16,   461,  -853,  -853,  -853,
      57,  -853,   467,   450,   455,  2316,  2316,  2316,  2316,  2316,
    2316,   445,    28,  -853,  -853,   252,    65,  -853,  -853,  -853,
     469,   473,   476,  -853,   458,   470,   477,   478,    11,   481,
     486,   480,   489,   490,   484,   492,   494,   495,   496,   493,
    -853,  1696,  2316,   498,   501,   497,   499,   503,   508,   509,
     510,   513,   514,   512,   527,   528,   529,   524,   533,   536,
     537,   531,   539,   540,   541,   543,   544,   538,   546,   547,
     549,  2316,  2316,  -853,  -853,  -853,  -853,    54,  -853,  -853,
    -853,  1490,  -853,  -853,   410,  -853,  -853,  -853,  -853,  -853,
    -853,  1490,  -853,  -853,   362,  -853,    45,  -853,    30,  -853,
    -853,  -853,  -853,   548,  -853,  1172,   276,  -853,  -853,   400,
    -853,  -853,  1957,   356,   428,  -853,  -853,   565,   567,    68,
    -853,  -853,   338,   556,  2073,  -853,  -853,  2172,    68,    68,
     229,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  2316,  -853,
    2316,  -853,  -853,  -853,  -853,  -853,  -853,  -853,    28,  -853,
    2316,  2316,    65,  -853,  -853,  -853,  2316,  2316,  -853,    11,
    -853,  -853,  -853,  -853,  2316,  2316,  2316,  2316,  -853,  -853,
    -853,  2316,  -853,  -853,  2316,  -853,  -853,  -853,  -853,  2316,
    -853,  -853,   559,   553,  -853,  -853,  2316,  2316,  -853,  -853,
    -853,  -853,  -853,  -853,  2316,  -853,  -853,  -853,  2316,  -853,
    -853,  -853,  2316,  -853,  -853,  -853,  -853,  -853,  2316,  -853,
    -853,  -853,   564,  -853,  -853,  -853,  -853,  -853,  -853,  -853,
    -853,   -46,   563,  -853,  -853,  -853,   134,   566,  -853,  -853,
    -853,   558,   560,  -853,  -853,  -853,   569,  -853,  -853,  1957,
    -853,   572,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,   238,  -853,    49,    81,   561,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,    76,  -853,  -853,  -853,  -853,
    -853,  -853,    22,  -853,  -853,  2757,   574,    11,  -853,  1461,
    -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,
    -853,  2073,  -853,  -853,  2097,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,    82,   575,   585,   586,   580,
     588,   589,   584,  -853,   557,  -853,   593,   594,   596,   597,
     584,   603,   604,  -853,  -853,  -853,  -853,  -853,  -853,  1427,
    -853,  -853,  -853,  1243,    97,  -853,  2121,  -853,   579,  -853,
    -853,  -853,   606,    43,  -853,   106,  -853,  -853,  -853,  -853,
    -853,  2172,  -853,  -853,  -853,  -853,  -853,  -853,  -853,   609,
    -853,  -853,  -853,  -853,    11,  -853,  -853,  2316,  -853,  2073,
      11,  -853,  -853,  -853,   964,  -853,  2316,  -853,  2316,  -853,
    -853,  2316,  -853,  -853,  -853,   608,   595,  -853,  -853,  -853,
    -853,   610,  -853,  -853,    88,  1200,  -853,  -853,  -853,  -853,
    2121,  -853,  -853,  -853,  -853,   612,  -853,  -853,  -853,  -853,
    -853,  -853,  -853,   551,   592,   125,   276,    98,    98,  -853,
      11,   570,  -853,  -853,  -853,  -853,  -853,   615,   584,  -853,
     -35,  -853,  -853,  -853,  -853,   611,    26,  -853,  1172,  -853,
    -853,   613,   616,   238,  -853,   238,  -853,    85,  -853,   276,
     276,  -853,    57,   617,  -853,   624,  -853,  -853,  -853,  1490,
    1490,  1490,   620,   568,    68,  -853,  2172,  -853,  -853,  -853,
    -853,    11,    11,   644,   626,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,    43,  -853,  -853,  -853,  -853,  -853,  -853,  -853,
      60,  -853,    11,  -853,  2121,   609,  -853,  -853,  -853
  };

  const unsigned short int
  SPARQLParser::yydefact_[] =
  {
      12,     0,     0,     2,     4,     3,   205,    14,    13,    10,
      71,     1,   186,   186,   186,   186,    77,     0,    77,     0,
     186,   186,   186,   197,   199,   201,   164,     6,     0,     7,
       8,     9,   173,   166,   170,   174,   175,   176,   180,   177,
     178,   179,   181,   182,   183,   184,   206,     0,    16,   187,
       0,     0,     0,     0,   234,     0,   104,    77,   111,   627,
     630,   629,   462,   463,   110,    77,   108,   460,   461,   628,
     122,   204,   225,   225,   225,     0,     0,     0,   298,     5,
     165,   162,    86,    77,   168,   216,   218,   211,   207,   210,
      72,    11,    15,   189,     0,   230,   229,   231,   228,   191,
     193,   192,     0,   236,     0,     0,    78,   122,   109,   112,
     123,   125,     0,   226,   223,     0,     0,     0,     0,   234,
     198,   200,   202,   163,   296,     0,   297,     0,    84,    85,
      87,     0,   122,    12,   169,   171,     0,     0,   214,   209,
     208,     0,     0,    17,    22,    18,     0,   190,   185,   227,
     232,   438,   439,   440,   441,   442,   435,   621,   622,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   623,   625,
     624,   626,   631,   632,   469,   242,   237,   250,   352,   434,
     433,   444,     0,   350,   458,   459,   465,   466,   609,   610,
     611,   467,   607,   464,   468,     0,   115,   116,   117,   118,
     120,   125,   125,   125,   113,     0,   114,   127,   126,   257,
     253,   121,   252,   225,   224,   225,   225,     0,   299,   306,
     308,     0,   103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   581,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   592,   593,   594,
     595,     0,   596,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,   100,   102,    83,    98,
      96,    92,   571,   534,   536,   572,   573,    97,     0,    93,
      94,    95,     0,   125,   205,   167,   217,   219,     0,     0,
     215,     0,   212,    73,    20,     0,   188,     0,   235,   236,
     251,   248,   355,   443,     0,     0,   605,   606,   608,   603,
     119,   106,   105,   107,     0,     0,   129,   128,     0,   194,
     196,   195,   233,     0,     0,   315,     0,     0,     0,     0,
     517,    89,   470,   473,   477,   479,   481,   491,   502,   505,
     510,   511,   512,   518,   513,   514,   515,   516,   601,   584,
       0,     0,     0,   575,   527,     0,   347,   561,     0,     0,
       0,     0,   582,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   533,   342,   342,     0,   554,   555,
       0,     0,     0,     0,   528,     0,   553,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   101,
     342,   342,   339,   338,    76,   213,     0,   220,   221,     0,
       0,     0,    59,     0,    33,    48,     0,    19,    23,     0,
      31,    24,     0,    46,    25,    26,   365,     0,   443,   364,
     243,     0,     0,   249,   353,   354,   356,   455,   443,   445,
     454,   351,   604,     0,   133,   134,   137,   139,   136,   140,
     141,   143,   337,   335,   336,     0,   131,   130,   256,   449,
     254,     0,     0,   255,   263,   261,     0,     0,   373,   448,
     447,   371,   301,   309,   307,     0,     0,   508,   509,   507,
       0,    90,     0,   471,   475,     0,     0,     0,     0,     0,
       0,     0,     0,   480,   482,   492,   504,   602,   600,   585,
       0,     0,     0,   348,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     343,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   222,   203,    74,    27,     0,   321,    37,
     322,    38,    34,    35,     0,   323,   318,   319,   320,   317,
      52,    53,    49,    50,     0,    31,     0,    46,     0,   436,
     362,   368,   370,     0,   239,   236,     0,   437,   446,    89,
     135,   142,     0,     0,     0,   124,   132,   156,   158,     0,
      80,   258,   327,   270,   260,   269,   265,   443,   376,     0,
       0,   305,   312,   314,   316,   519,    88,    91,     0,   474,
       0,   478,   483,   484,   485,   486,   487,   488,     0,   489,
       0,     0,   497,   503,   493,   494,     0,     0,   506,     0,
     525,   526,   574,   345,     0,     0,     0,     0,   583,   520,
     521,     0,   523,   524,     0,   566,   567,   568,   569,     0,
     590,   591,     0,   598,   570,   556,     0,     0,   545,   560,
     552,   551,   532,   559,     0,   550,   531,   549,     0,   558,
     548,   539,     0,   530,   547,   538,   529,   537,     0,   535,
     557,   546,     0,   340,    58,    61,    60,    36,    41,    51,
      56,     0,     0,    29,    39,    32,     0,     0,    44,    54,
      47,   357,   366,   240,   241,   245,     0,   149,   150,   144,
     145,     0,   147,   148,   152,   153,   160,   161,   154,   157,
     155,   159,     0,   416,     0,     0,     0,   378,   380,   381,
     389,   396,   397,   410,   402,   408,   390,   415,    81,   284,
     288,   291,   298,   282,   324,     0,     0,     0,   264,     0,
     280,   272,   274,   275,   276,   278,   279,   273,   271,   328,
     277,   260,   266,   457,   443,   452,   456,   374,   375,   377,
     372,   300,   302,   303,   310,   472,   476,   490,   499,   500,
     498,   501,   495,   496,   586,     0,     0,     0,     0,     0,
       0,     0,   577,   587,     0,   599,     0,     0,     0,     0,
     577,     0,     0,   588,   345,    66,    42,    28,    30,     0,
      57,    43,    45,     0,   359,   363,   443,   369,     0,   138,
     146,   151,     0,   426,   429,     0,   417,   419,   428,   411,
     450,   443,   400,   405,   413,   414,   412,   407,   409,   122,
     285,   289,   292,   295,     0,   325,   334,     0,   281,   260,
       0,   267,   451,   453,     0,   349,     0,   346,     0,   563,
     564,     0,   522,   565,   578,     0,     0,   589,   543,   544,
     540,     0,   541,   542,     0,     0,    40,    55,   360,   361,
     443,   367,   246,   418,   427,     0,   424,   432,   430,   431,
     387,   393,   395,   398,   403,   125,     0,   186,   186,   283,
       0,     0,   262,   332,   313,   311,   344,     0,   577,   576,
       0,   579,   341,    62,    67,    63,     0,   358,   236,   420,
     422,   379,   391,     0,   401,     0,   406,   164,   286,     0,
       0,   326,     0,   329,   562,     0,   597,    64,    65,     0,
       0,     0,     0,   425,   384,   388,   443,   394,   399,   404,
      82,     0,     0,     0,     0,   330,   333,   580,    70,    69,
      68,   247,     0,   423,   382,   385,   386,   392,   287,   290,
       0,   294,     0,   421,   443,   122,   331,   383,   293
  };

  const short int
  SPARQLParser::yypgoto_[] =
  {
    -853,  -853,  -853,  -853,  -853,  -853,   542,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,  -853,    69,  -853,   221,  -853,
    -178,  -853,  -853,    86,  -853,  -853,    71,  -853,   227,  -853,
    -173,  -853,  -853,    80,  -853,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,   102,
    -853,  -853,  -853,  -853,   191,  -853,  -853,  -853,    67,  -853,
     397,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  -146,  -100,  -853,  -186,  -853,  -853,
    -853,  -853,  -853,  -853,   211,  -853,  -853,   210,  -853,  -853,
     -59,  -853,  -853,  -853,  -853,  -853,  -853,    63,    72,  -274,
    -853,  -853,   573,  -853,  -853,  -853,  -853,  -853,  -853,  -853,
      -9,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,   614,  -853,  -853,  -853,    53,
    -853,    19,   643,   -76,   625,   590,  -853,  -305,   -82,  -853,
    -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -415,  -853,
    -853,  -853,  -853,  -606,  -853,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,   -79,  -853,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -421,
    -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,
    -595,  -110,   342,  -853,  -318,  -770,  -132,  -211,  -853,  -853,
    -853,  -853,  -853,  -853,  -151,  -853,  -853,  -853,  -853,  -141,
    -852,  -853,  -853,  -142,  -853,  -853,  -853,  -853,  -853,  -342,
    -853,  -269,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,  -270,   -45,  -853,  -853,  -853,  -853,  -245,  -853,
    -853,  -853,   -42,  -853,  -246,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,  -853,  -828,  -853,   -85,  -853,  -853,  -853,  -853,
    -299,  -853,  -618,  -853,  -853,  -853,  -853,  -279,  -607,   -80,
     -14,     3,  -853,   848,  -853,  -853,  -853,    78,  -853,  -853,
      79,  -853,  -853,  -853,    47,  -853,  -853,    74,  -853,  -853,
    -853,  -348,  -853,  -343,   -54,  -313,  -123,  -853,  -853,  -787,
    -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,   -86,  -853,
    -853,  -853,  -853,  -853,  -853,   -93,  -853,  -853,  -853,   201,
    -853,   195,   200,   230,  -223,   -17,  -853,  -853
  };

  const short int
  SPARQLParser::yydefgoto_[] =
  {
      -1,     2,     3,     4,    26,     5,     6,     7,    48,    91,
     143,   315,   144,   145,   447,   448,   606,   449,   450,   591,
     592,   735,   849,   593,   847,   451,   608,   452,   453,   601,
     602,   740,   853,   603,   851,   454,   587,   726,   845,   978,
     954,   915,   955,     8,    92,   141,   440,    27,    28,    55,
     490,   491,   778,   879,    83,   130,   131,   511,   512,   285,
     286,   287,   288,    29,    56,    30,    64,    65,   203,    31,
     106,   196,   197,   198,   199,   111,   112,   206,   207,   336,
     486,   625,   208,   474,   475,   337,   479,   480,   487,   749,
     750,   751,   752,   753,   626,   758,   760,   627,   628,    79,
      80,    81,     9,   134,   135,    32,    84,    33,    34,    35,
      50,   147,   148,    36,    37,    38,    39,    40,    41,    42,
      75,    43,    76,    44,    77,    45,    46,    47,   139,    87,
     138,   310,   311,    88,   136,    89,   137,   312,   437,   115,
     116,    98,    99,    57,   120,   102,   103,   175,   615,   460,
     318,   461,   462,   858,   958,   176,   320,   321,   211,   492,
     212,   338,   493,   494,   788,   632,   495,   635,   636,   789,
     790,   791,   884,   792,   880,   936,   991,   793,   881,   937,
     794,   882,   938,   795,   796,   123,   124,   125,   343,   640,
     812,   126,   127,   344,   221,   894,   644,   814,   505,   594,
     797,   885,   940,   798,   799,   890,   996,  1012,   973,   800,
     481,   482,   433,   844,   551,   904,   825,   377,   673,   177,
     324,   322,   464,   465,   457,   918,   919,   855,   741,   458,
     610,   857,   742,   611,   496,   639,   638,   807,   808,   766,
     871,   767,  1005,  1014,  1006,   985,   961,   768,   769,   930,
     987,   962,   931,   770,   771,   872,   964,   933,   772,   873,
     966,   934,   773,   877,   774,   878,   775,   866,  1003,   983,
     924,   960,   925,   867,   928,   467,   179,   317,   180,   181,
     182,   468,   498,   499,   629,   500,   804,   612,   932,   470,
     459,   350,   185,   351,   352,   649,   513,   353,   651,   514,
     354,   355,   523,   524,   356,   357,   662,   668,   821,   663,
     525,   358,   526,   359,   360,   361,   362,   374,   292,   905,
     293,   294,   295,   382,   538,   296,   529,   669,   363,   692,
     298,   835,   836,   364,   528,   365,   327,   328,   329,   366,
     188,   189,   190,   367,   192,   368,    69,   194
  };

  const short int
  SPARQLParser::yytable_[] =
  {
      68,   122,    71,    66,    51,    52,    53,   202,   291,   204,
     186,    72,    73,    74,   463,   331,   332,   333,   178,   803,
      67,   289,   483,   183,   584,   604,   586,   754,   802,   201,
     805,   737,   303,    93,   394,   926,   633,   195,   299,   497,
      58,  -268,  -268,  -268,   469,   297,   732,    68,   209,   330,
     108,   436,    94,   911,   641,   897,   113,   642,   734,   325,
     306,   307,    10,  -304,   219,   372,  -268,    67,   957,   375,
      95,   100,  -268,  -268,   738,   431,   308,   149,   552,   634,
    -268,  -268,   979,  -268,   -21,   666,   193,   200,     1,   733,
     863,    11,   724,   104,   864,   725,   874,    54,   104,   214,
     864,   -21,    85,    86,   441,   846,   184,  -122,   503,   762,
     110,    49,   581,   582,   302,   105,    78,   434,   104,   763,
      70,   442,   762,   678,   895,    82,   117,   118,   218,   667,
     952,   896,   763,   764,   290,   110,    90,   896,   875,   168,
     169,   170,   171,    94,   897,   865,   764,   119,   456,   734,
     133,   865,    96,    97,   754,   326,   114,   927,    86,   107,
    -268,   975,  1017,   309,   291,   316,   483,   109,   -21,   455,
     765,   466,   210,   471,  1013,   980,   981,   289,   200,   876,
     604,   128,   129,  -268,   739,   132,   803,   146,   443,   618,
     886,    59,    60,    61,   299,   891,  -268,   893,    59,    60,
      61,   297,   643,    62,    63,    59,    60,    61,  -304,   220,
     373,   478,   484,   150,   376,   -21,   -21,   205,   -21,   813,
     432,    59,    60,    61,   476,   142,   186,    59,    60,    61,
     186,  -122,   435,   213,   178,   444,   445,   313,   446,   183,
      62,    63,   -21,   -21,   -21,   186,    59,    60,    61,    62,
      63,    62,    63,   803,   824,    59,    60,    61,   501,    59,
      60,    61,    59,    60,    61,   215,   339,   811,   340,   341,
     302,   216,   588,   623,   624,    59,    60,    61,   314,   762,
      62,    63,   323,   942,    59,    60,    61,   850,   739,   763,
     290,   319,   438,   507,   508,   509,   809,   810,   200,   334,
      68,   335,   193,   764,   187,    68,   193,    68,   472,   483,
     744,   659,   818,   819,   660,   661,   342,   302,   302,   345,
      67,   193,   184,   822,   823,    67,   184,    67,   370,   369,
     371,   378,   300,   191,   379,   497,   380,   477,   497,   381,
     765,   184,   383,   384,   779,   780,   781,   504,  -172,   385,
     596,   478,   386,   596,   387,   388,   484,    12,   389,    13,
      14,   301,    15,   390,   476,   186,   391,   392,   803,   782,
     393,   395,   888,   396,   397,   186,  -259,   515,   516,   517,
     518,   519,   520,   783,   784,   398,   785,   521,   522,   399,
     543,   590,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,    59,    60,    61,
     400,   401,    62,    63,   402,   403,    59,    60,    61,   583,
     162,   163,   164,   165,   166,   167,   599,   405,   404,   599,
     407,   406,   604,   408,   409,   410,   483,   411,   861,   412,
     413,   193,   414,   415,   416,   417,   595,   817,   418,   595,
     419,   193,   420,    19,    59,    60,    61,   302,   421,    62,
      63,   184,   302,   786,    20,    21,   422,   423,   424,   939,
     425,   184,   483,   945,   426,   943,    22,   477,    23,    24,
      25,   427,   428,   430,   439,  -244,   787,   485,   300,   502,
     550,   510,   443,   585,   956,   446,   609,   616,   596,   484,
     622,   631,   497,   645,   648,   497,   637,   674,   596,   647,
     650,   670,   658,   646,   728,   671,   730,   301,   672,   675,
     187,   756,   186,   679,   187,   971,   676,   677,   680,   681,
     178,   682,   683,   684,   685,   183,   686,   687,   688,   187,
     694,   186,   689,   695,   186,   698,   696,   596,   697,   191,
     699,   700,   701,   191,   501,   702,   703,   806,   998,   999,
    1000,   704,   652,   653,   654,   655,   656,   657,   191,   705,
     706,   707,   497,   708,   599,   709,  1008,  1009,   710,   711,
     712,   713,   714,   715,   599,   716,   717,   718,   719,   720,
     497,   721,   743,   757,   595,   624,   623,  1016,   193,    68,
     801,   833,   745,   834,   595,   302,   843,   848,   854,   856,
     852,   859,   777,   346,   870,   887,   922,   193,   184,    67,
     193,   777,   777,   599,   898,   755,   484,   899,   900,   901,
     902,   903,   776,   896,   906,   907,   908,   184,   909,   910,
     184,   776,   776,   595,   597,   912,   913,   597,   923,   110,
     949,   950,   951,   982,   959,   963,   965,   974,  1001,   187,
     977,   972,   484,   984,   995,   986,   997,  1010,  1011,   187,
     605,   916,  1002,   598,   731,   304,   598,   727,   736,   607,
     917,   729,   630,  -172,   429,   620,   746,   497,   191,   621,
     860,   761,    12,   990,    13,    14,   101,    15,   191,   759,
     -75,   121,   140,   883,    16,    17,   305,   889,   186,   217,
     527,   186,   914,   920,   921,  1004,  1007,   862,   988,   989,
     664,   501,    18,   869,   806,   665,   815,   976,     0,   816,
       0,     0,   302,     0,     0,     0,   820,     0,     0,     0,
       0,     0,     0,     0,     0,   777,     0,   868,   777,   967,
       0,     0,   755,     0,     0,     0,   596,     0,     0,     0,
     596,     0,     0,   186,     0,     0,     0,     0,   302,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   186,   935,
       0,     0,     0,     0,   193,     0,     0,   193,    19,     0,
       0,   806,   597,     0,     0,     0,   186,     0,     0,    20,
      21,   596,   597,     0,   184,     0,     0,   184,     0,   501,
       0,    22,     0,    23,    24,    25,   187,     0,     0,     0,
       0,   598,   596,     0,     0,     0,     0,   186,     0,     0,
       0,   598,   599,     0,     0,   187,   599,    68,   187,   193,
       0,   597,     0,     0,     0,   191,   868,     0,   929,     0,
       0,     0,   595,     0,   193,     0,   595,    67,     0,   184,
       0,     0,     0,     0,   191,   186,     0,   191,     0,     0,
     598,     0,   193,   178,   184,     0,     0,   599,   183,     0,
       0,     0,     0,     0,     0,     0,   596,   596,   596,     0,
       0,     0,   184,   186,     0,     0,     0,   595,   599,     0,
       0,     0,     0,   193,     0,     0,   806,     0,     0,     0,
       0,     0,     0,     0,     0,  1018,     0,     0,   595,    68,
       0,   186,   968,   184,     0,     0,     0,     0,   969,   970,
       0,     0,     0,     0,  1015,     0,     0,     0,     0,    67,
       0,   193,     0,     0,     0,     0,   777,     0,   777,     0,
       0,     0,    68,    68,     0,   992,   993,     0,     0,     0,
       0,   184,   599,   599,   599,     0,     0,   777,     0,   193,
       0,     0,    67,    67,     0,   994,     0,     0,     0,     0,
       0,     0,   595,   595,   595,   868,     0,   776,     0,   184,
       0,     0,     0,     0,     0,     0,     0,   193,     0,     0,
       0,     0,   187,     0,     0,   187,   944,   588,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   184,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   191,     0,     0,   191,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     597,     0,     0,     0,   597,     0,     0,   187,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   187,     0,     0,     0,     0,     0,     0,   598,
       0,     0,     0,   598,     0,     0,   191,     0,     0,     0,
     187,     0,     0,     0,     0,   597,     0,     0,     0,     0,
       0,   191,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   597,     0,     0,   191,
       0,   187,     0,     0,   598,     0,   590,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,    59,    60,    61,   598,     0,    62,    63,     0,
     191,     0,     0,     0,     0,     0,     0,     0,     0,   187,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     597,   597,   597,     0,     0,     0,     0,   187,   191,     0,
       0,     0,     0,     0,   506,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   151,   152,   153,   154,   155,   598,
     598,   598,     0,  -443,     0,   187,   191,     0,   530,   531,
     532,     0,     0,   533,   156,     0,   534,   535,   536,   537,
       0,   539,   540,   541,   542,     0,   544,   545,   546,   547,
     548,   549,   953,   588,   191,   553,     0,     0,   554,   555,
     556,   557,     0,   558,     0,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,     0,   488,     0,
       0,     0,     0,  -260,  -260,  -260,   588,     0,     0,     0,
       0,     0,     0,     0,   -79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -260,   151,
     152,   153,   154,   155,  -260,  -260,     0,     0,  -443,     0,
       0,   619,  -260,  -260,     0,  -260,     0,     0,     0,   489,
       0,     0,     0,     0,     0,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      59,    60,    61,   172,   173,    62,    63,     0,   174,     0,
       0,     0,   590,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,    59,    60,
      61,     0,     0,    62,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   600,     0,   691,
     693,     0,  -260,     0,     0,   590,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,    59,    60,    61,     0,  -260,    62,    63,     0,   722,
     723,     0,     0,     0,     0,     0,     0,     0,  -260,     0,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,    59,    60,    61,   172,   173,
      62,    63,   613,   174,     0,     0,     0,  -238,  -238,  -238,
     588,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,
       0,     0,  -238,     0,     0,   614,  -238,  -238,     0,  -238,
       0,     0,     0,  -238,     0,     0,     0,     0,     0,     0,
       0,     0,   826,   827,   828,   829,     0,     0,     0,   830,
     613,   589,   831,   588,     0,  -238,     0,   832,     0,     0,
       0,     0,     0,     0,   837,   838,     0,     0,     0,     0,
       0,     0,   839,     0,     0,     0,   840,     0,     0,     0,
     841,  -238,  -238,  -238,  -238,  -238,   842,  -238,     0,     0,
    -238,     0,     0,   614,     0,     0,     0,     0,     0,     0,
       0,  -238,     0,     0,     0,     0,  -238,     0,     0,   590,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,    59,    60,    61,     0,  -238,
      62,    63,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -238,     0,  -238,  -238,  -238,  -238,  -238,  -238,
    -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,
    -238,  -238,  -238,  -238,  -238,  -238,     0,  -238,     0,     0,
       0,     0,   590,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,    59,    60,
      61,     0,     0,    62,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,
    -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,
    -238,  -238,  -238,  -238,     0,  -238,   690,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   941,     0,   346,     0,     0,
       0,     0,     0,     0,   946,     0,   947,     0,     0,   948,
       0,     0,     0,     0,     0,     0,     0,     0,   347,   348,
       0,   349,   224,     0,   225,   226,   227,   228,   229,   230,
     231,   232,   233,     0,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,     0,   245,     0,     0,     0,
     246,   247,   248,   249,   250,   251,   252,   253,     0,     0,
       0,     0,     0,     0,     0,   254,   255,   256,     0,   257,
     258,   259,     0,     0,   260,   261,   262,   263,   264,   265,
     266,     0,   267,   268,     0,   269,     0,     0,     0,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   222,     0,     0,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    59,    60,    61,   223,     0,    62,
      63,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   224,     0,   225,   226,   227,   228,   229,   230,
     231,   232,   233,     0,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,     0,   245,     0,     0,     0,
     246,   247,   248,   249,   250,   251,   252,   253,     0,     0,
       0,     0,     0,     0,     0,   254,   255,   256,     0,   257,
     258,   259,     0,     0,   260,   261,   262,   263,   264,   265,
     266,     0,   267,   268,     0,   269,     0,     0,     0,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   747,   748,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   346,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    59,    60,    61,     0,     0,    62,
      63,     0,     0,   224,     0,   225,   226,   227,   228,   229,
     230,   231,   232,   233,     0,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,     0,   245,     0,   151,
     152,   153,   154,   155,     0,     0,     0,     0,   253,   617,
       0,     0,     0,     0,     0,     0,   254,   255,   256,   156,
     257,   258,   259,     0,     0,   260,   261,   262,   263,   264,
     265,   266,     0,   267,   268,     0,   269,     0,     0,     0,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   151,   152,   153,   154,   155,
       0,     0,     0,     0,  -443,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   489,     0,     0,     0,   151,
     152,   153,   154,   155,     0,    59,    60,    61,     0,   892,
      62,    63,     0,     0,     0,     0,     0,     0,     0,   489,
       0,     0,     0,   151,   152,   153,   154,   155,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   156,     0,     0,     0,     0,     0,     0,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,    59,    60,    61,   172,   173,
      62,    63,     0,   174,   151,   152,   153,   154,   155,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   489,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,    59,    60,    61,   172,   173,    62,    63,     0,   174,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,    59,    60,    61,   172,   173,
      62,    63,     0,   174,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,    59,
      60,    61,   172,   173,    62,    63,     0,   174,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      59,    60,    61,   172,   173,    62,    63,   346,   174,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   347,   348,
       0,   349,   224,     0,   225,   226,   227,   228,   229,   230,
     231,   232,   233,     0,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,     0,   245,     0,     0,     0,
     246,   247,   248,   249,   250,   251,   252,   253,     0,     0,
       0,     0,     0,     0,     0,   254,   255,   256,     0,   257,
     258,   259,     0,     0,   260,   261,   262,   263,   264,   265,
     266,     0,   267,   268,     0,   269,     0,     0,     0,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   223,     0,     0,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    59,    60,    61,     0,     0,    62,
      63,   224,     0,   225,   226,   227,   228,   229,   230,   231,
     232,   233,     0,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,     0,   245,     0,     0,     0,   246,
     247,   248,   249,   250,   251,   252,   253,     0,     0,     0,
       0,     0,     0,     0,   254,   255,   256,     0,   257,   258,
     259,     0,     0,   260,   261,   262,   263,   264,   265,   266,
       0,   267,   268,     0,   269,     0,     0,     0,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   346,     0,     0,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,    59,    60,    61,     0,     0,    62,    63,
     224,     0,   225,   226,   227,   228,   229,   230,   231,   232,
     233,     0,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,     0,   245,     0,     0,     0,   246,   247,
     248,   249,   250,   251,   252,   253,     0,     0,     0,     0,
       0,     0,     0,   254,   255,   256,     0,   257,   258,   259,
       0,     0,   260,   261,   262,   263,   264,   265,   266,     0,
     267,   268,     0,   269,     0,     0,     0,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   473,     0,     0,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,    59,    60,    61,     0,     0,    62,    63,   224,
       0,   225,   226,   227,   228,   229,   230,   231,   232,   233,
       0,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,     0,   245,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   253,     0,     0,     0,     0,     0,
       0,     0,   254,   255,   256,     0,   257,   258,   259,     0,
       0,   260,   261,   262,   263,   264,   265,   266,   346,   267,
     268,     0,   269,     0,     0,     0,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,     0,     0,   224,     0,   225,   226,   227,   228,   229,
     230,   231,   232,   233,     0,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,     0,   245,     0,     0,
       0,    59,    60,    61,     0,     0,    62,    63,   253,     0,
       0,     0,     0,     0,     0,     0,   254,   255,   256,     0,
     257,   258,   259,     0,     0,   260,   261,   262,   263,   264,
     265,   266,     0,   267,   268,     0,   269,     0,     0,     0,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    59,    60,    61
  };

  const short int
  SPARQLParser::yycheck_[] =
  {
      17,    77,    19,    17,    13,    14,    15,   107,   131,   109,
     103,    20,    21,    22,   319,   201,   202,   203,   103,   637,
      17,   131,   335,   103,   439,   446,   441,   622,   634,   105,
     637,     1,   132,    50,   245,   863,     1,    24,   131,   338,
      20,     6,     7,     8,   323,   131,     1,    64,    37,   195,
      64,    24,     6,   840,    38,   825,     6,    41,   104,    89,
     136,   137,   178,    41,    41,    41,    31,    64,   920,    41,
      24,    52,    37,    38,    44,    41,    21,    94,   396,    44,
      45,    46,    56,    48,    20,    20,   103,   104,    15,    44,
      41,     0,    38,    23,    51,    41,    20,    37,    23,   116,
      51,    37,     3,     4,    20,   151,   103,    37,    42,    41,
      40,    13,   430,   431,   131,    40,    31,   303,    23,    51,
      18,    37,    41,   538,    42,    17,    73,    74,   125,    64,
      42,    49,    51,    65,   131,    40,    16,    49,    62,   174,
     175,   176,   177,     6,   914,   102,    65,    37,    51,   104,
      50,   102,   106,   107,   749,   185,   106,    51,     4,    57,
     125,   948,  1014,   108,   287,   146,   479,    65,   104,   315,
     102,   322,   161,   324,  1002,   149,   150,   287,   195,   103,
     601,    18,    19,   148,   154,    83,   804,    10,   104,   468,
     785,   178,   179,   180,   287,   801,   161,   804,   178,   179,
     180,   287,   186,   183,   184,   178,   179,   180,   186,   186,
     186,   334,   335,    38,   186,   151,   152,    92,   154,   640,
     186,   178,   179,   180,   334,   161,   319,   178,   179,   180,
     323,   161,   308,   112,   319,   151,   152,   179,   154,   319,
     183,   184,   178,   179,   180,   338,   178,   179,   180,   183,
     184,   183,   184,   871,   669,   178,   179,   180,   338,   178,
     179,   180,   178,   179,   180,   112,   213,    38,   215,   216,
     287,   112,    43,    29,    30,   178,   179,   180,    56,    41,
     183,   184,    41,   889,   178,   179,   180,   153,   154,    51,
     287,    44,   309,   347,   348,   349,   638,   639,   315,    26,
     317,    93,   319,    65,   103,   322,   323,   324,   325,   622,
     615,   522,   660,   661,    62,    63,    38,   334,   335,    37,
     317,   338,   319,   666,   667,   322,   323,   324,    41,    76,
      41,    41,   131,   103,    41,   634,    41,   334,   637,    41,
     102,   338,    41,    41,     6,     7,     8,   344,     0,    41,
     443,   474,    41,   446,    41,    41,   479,     9,    41,    11,
      12,   131,    14,    41,   474,   458,    41,    41,   986,    31,
      41,    41,   787,    41,    41,   468,    38,    56,    57,    58,
      59,    60,    61,    45,    46,   186,    48,    66,    67,   186,
     387,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      41,    41,   183,   184,    41,    41,   178,   179,   180,   436,
     168,   169,   170,   171,   172,   173,   443,    41,   186,   446,
      41,   186,   853,    41,    41,    41,   749,    41,   751,    41,
      41,   458,    41,    41,    41,    41,   443,   658,    41,   446,
      41,   468,    41,   105,   178,   179,   180,   474,    41,   183,
     184,   458,   479,   125,   116,   117,    41,    41,    41,   884,
      41,   468,   785,   894,    41,   890,   128,   474,   130,   131,
     132,    41,    41,    41,    40,     6,   148,    25,   287,    37,
      18,    91,   104,   178,   915,   154,    53,     6,   591,   622,
      26,    38,   801,    42,    54,   804,    41,    49,   601,    42,
      55,    42,    67,   510,   104,    42,   154,   287,    42,    49,
     319,   165,   615,    42,   323,   940,    49,    49,    42,    49,
     615,    42,    42,    49,    42,   615,    42,    42,    42,   338,
      42,   634,    49,    42,   637,    42,    49,   640,    49,   319,
      42,    42,    42,   323,   634,    42,    42,   637,   979,   980,
     981,    49,   515,   516,   517,   518,   519,   520,   338,    42,
      42,    42,   871,    49,   591,    42,   991,   992,    42,    42,
      49,    42,    42,    42,   601,    42,    42,    49,    42,    42,
     889,    42,    44,   165,   591,    30,    29,  1012,   615,   616,
      44,    42,   616,    50,   601,   622,    42,    44,    50,    49,
      44,    42,   629,    41,    53,    41,    37,   634,   615,   616,
     637,   638,   639,   640,    49,   622,   749,    42,    42,    49,
      42,    42,   629,    49,    77,    42,    42,   634,    42,    42,
     637,   638,   639,   640,   443,    42,    42,   446,    42,    40,
      42,    56,    42,   958,    42,   104,    64,    42,    38,   458,
      49,    91,   785,    50,    47,    49,    42,    23,    42,   468,
     449,   849,   104,   443,   605,   133,   446,   591,   607,   452,
     853,   601,   491,     0,   287,   474,   619,   986,   458,   479,
     749,   628,     9,   967,    11,    12,    53,    14,   468,   627,
      17,    76,    88,   782,    21,    22,   133,   789,   801,   119,
     368,   804,   844,   854,   856,   984,   986,   762,   963,   965,
     525,   801,    39,   765,   804,   525,   648,   950,    -1,   650,
      -1,    -1,   749,    -1,    -1,    -1,   662,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   762,    -1,   764,   765,   935,
      -1,    -1,   749,    -1,    -1,    -1,   849,    -1,    -1,    -1,
     853,    -1,    -1,   856,    -1,    -1,    -1,    -1,   785,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   871,   879,
      -1,    -1,    -1,    -1,   801,    -1,    -1,   804,   105,    -1,
      -1,   871,   591,    -1,    -1,    -1,   889,    -1,    -1,   116,
     117,   894,   601,    -1,   801,    -1,    -1,   804,    -1,   889,
      -1,   128,    -1,   130,   131,   132,   615,    -1,    -1,    -1,
      -1,   591,   915,    -1,    -1,    -1,    -1,   920,    -1,    -1,
      -1,   601,   849,    -1,    -1,   634,   853,   854,   637,   856,
      -1,   640,    -1,    -1,    -1,   615,   863,    -1,   865,    -1,
      -1,    -1,   849,    -1,   871,    -1,   853,   854,    -1,   856,
      -1,    -1,    -1,    -1,   634,   958,    -1,   637,    -1,    -1,
     640,    -1,   889,   958,   871,    -1,    -1,   894,   958,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   979,   980,   981,    -1,
      -1,    -1,   889,   986,    -1,    -1,    -1,   894,   915,    -1,
      -1,    -1,    -1,   920,    -1,    -1,   986,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1015,    -1,    -1,   915,   936,
      -1,  1014,   936,   920,    -1,    -1,    -1,    -1,   937,   938,
      -1,    -1,    -1,    -1,  1010,    -1,    -1,    -1,    -1,   936,
      -1,   958,    -1,    -1,    -1,    -1,   963,    -1,   965,    -1,
      -1,    -1,   969,   970,    -1,   969,   970,    -1,    -1,    -1,
      -1,   958,   979,   980,   981,    -1,    -1,   984,    -1,   986,
      -1,    -1,   969,   970,    -1,   972,    -1,    -1,    -1,    -1,
      -1,    -1,   979,   980,   981,  1002,    -1,   984,    -1,   986,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1014,    -1,    -1,
      -1,    -1,   801,    -1,    -1,   804,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1014,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   801,    -1,    -1,   804,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     849,    -1,    -1,    -1,   853,    -1,    -1,   856,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   871,    -1,    -1,    -1,    -1,    -1,    -1,   849,
      -1,    -1,    -1,   853,    -1,    -1,   856,    -1,    -1,    -1,
     889,    -1,    -1,    -1,    -1,   894,    -1,    -1,    -1,    -1,
      -1,   871,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   915,    -1,    -1,   889,
      -1,   920,    -1,    -1,   894,    -1,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   915,    -1,   183,   184,    -1,
     920,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   958,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     979,   980,   981,    -1,    -1,    -1,    -1,   986,   958,    -1,
      -1,    -1,    -1,    -1,   346,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,   979,
     980,   981,    -1,    41,    -1,  1014,   986,    -1,   370,   371,
     372,    -1,    -1,   375,    52,    -1,   378,   379,   380,   381,
      -1,   383,   384,   385,   386,    -1,   388,   389,   390,   391,
     392,   393,    42,    43,  1014,   397,    -1,    -1,   400,   401,
     402,   403,    -1,   405,    -1,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,    -1,     1,    -1,
      -1,    -1,    -1,     6,     7,     8,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    41,    -1,
      -1,   473,    45,    46,    -1,    48,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,    -1,   186,    -1,
      -1,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,    -1,    -1,   183,   184,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,   551,
     552,    -1,   125,    -1,    -1,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,    -1,   148,   183,   184,    -1,   581,
     582,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,     1,   186,    -1,    -1,    -1,     6,     7,     8,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    41,    -1,    -1,    44,    45,    46,    -1,    48,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   674,   675,   676,   677,    -1,    -1,    -1,   681,
       1,   104,   684,    43,    -1,     6,    -1,   689,    -1,    -1,
      -1,    -1,    -1,    -1,   696,   697,    -1,    -1,    -1,    -1,
      -1,    -1,   704,    -1,    -1,    -1,   708,    -1,    -1,    -1,
     712,    32,    33,    34,    35,    36,   718,    38,    -1,    -1,
      41,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,   125,    -1,    -1,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,    -1,   148,
     183,   184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   161,    -1,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,    -1,   186,    -1,    -1,
      -1,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,    -1,    -1,   183,   184,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,    -1,   186,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   887,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    -1,   896,    -1,   898,    -1,    -1,   901,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      -1,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    90,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   109,   110,   111,    -1,   113,
     114,   115,    -1,    -1,   118,   119,   120,   121,   122,   123,
     124,    -1,   126,   127,    -1,   129,    -1,    -1,    -1,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,    41,    -1,   183,
     184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    90,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   109,   110,   111,    -1,   113,
     114,   115,    -1,    -1,   118,   119,   120,   121,   122,   123,
     124,    -1,   126,   127,    -1,   129,    -1,    -1,    -1,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,    -1,    -1,   183,
     184,    -1,    -1,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    -1,    90,    -1,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,   101,    42,
      -1,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,    52,
     113,   114,   115,    -1,    -1,   118,   119,   120,   121,   122,
     123,   124,    -1,   126,   127,    -1,   129,    -1,    -1,    -1,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    -1,   178,   179,   180,    -1,    42,
     183,   184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,    -1,   186,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,    -1,   186,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,    -1,   186,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,    -1,   186,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,    41,   186,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      -1,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    90,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   109,   110,   111,    -1,   113,
     114,   115,    -1,    -1,   118,   119,   120,   121,   122,   123,
     124,    -1,   126,   127,    -1,   129,    -1,    -1,    -1,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,    -1,    -1,   183,
     184,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    90,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,   110,   111,    -1,   113,   114,
     115,    -1,    -1,   118,   119,   120,   121,   122,   123,   124,
      -1,   126,   127,    -1,   129,    -1,    -1,    -1,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    -1,    -1,   183,   184,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    -1,    90,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,   110,   111,    -1,   113,   114,   115,
      -1,    -1,   118,   119,   120,   121,   122,   123,   124,    -1,
     126,   127,    -1,   129,    -1,    -1,    -1,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    -1,    -1,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,    -1,    -1,   183,   184,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    -1,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   109,   110,   111,    -1,   113,   114,   115,    -1,
      -1,   118,   119,   120,   121,   122,   123,   124,    41,   126,
     127,    -1,   129,    -1,    -1,    -1,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,    -1,    -1,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    -1,    90,    -1,    -1,
      -1,   178,   179,   180,    -1,    -1,   183,   184,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,    -1,
     113,   114,   115,    -1,    -1,   118,   119,   120,   121,   122,
     123,   124,    -1,   126,   127,    -1,   129,    -1,    -1,    -1,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   178,   179,   180
  };

  const unsigned short int
  SPARQLParser::yystos_[] =
  {
       0,    15,   188,   189,   190,   192,   193,   194,   230,   289,
     178,     0,     9,    11,    12,    14,    21,    22,    39,   105,
     116,   117,   128,   130,   131,   132,   191,   234,   235,   250,
     252,   256,   292,   294,   295,   296,   300,   301,   302,   303,
     304,   305,   306,   308,   310,   312,   313,   314,   195,    13,
     297,   297,   297,   297,    37,   236,   251,   330,    20,   178,
     179,   180,   183,   184,   253,   254,   477,   478,   532,   533,
     236,   532,   297,   297,   297,   307,   309,   311,    31,   286,
     287,   288,    17,   241,   293,     3,     4,   316,   320,   322,
      16,   196,   231,   532,     6,    24,   106,   107,   328,   329,
     328,   329,   332,   333,    23,    40,   257,   236,   477,   236,
      40,   262,   263,     6,   106,   326,   327,   326,   326,    37,
     331,   331,   330,   372,   373,   374,   378,   379,    18,    19,
     242,   243,   236,    50,   290,   291,   321,   323,   317,   315,
     322,   232,   161,   197,   199,   200,    10,   298,   299,   532,
      38,    32,    33,    34,    35,    36,    52,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   181,   182,   186,   334,   342,   406,   462,   463,
     465,   466,   467,   476,   478,   479,   522,   526,   527,   528,
     529,   530,   531,   532,   534,    24,   258,   259,   260,   261,
     532,   330,   262,   255,   262,    92,   264,   265,   269,    37,
     161,   345,   347,   112,   532,   112,   112,   332,   478,    41,
     186,   381,    20,    41,    66,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    90,    94,    95,    96,    97,
      98,    99,   100,   101,   109,   110,   111,   113,   114,   115,
     118,   119,   120,   121,   122,   123,   124,   126,   127,   129,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   246,   247,   248,   249,   398,
     478,   503,   505,   507,   508,   509,   512,   515,   517,   522,
     526,   530,   532,   262,   193,   289,   330,   330,    21,   108,
     318,   319,   324,   179,    56,   198,   328,   464,   337,    44,
     343,   344,   408,    41,   407,    89,   185,   523,   524,   525,
     261,   264,   264,   264,    26,    93,   266,   272,   348,   326,
     326,   326,    38,   375,   380,    37,    41,    62,    63,    65,
     478,   480,   481,   484,   487,   488,   491,   492,   498,   500,
     501,   502,   503,   515,   520,   522,   526,   530,   532,    76,
      41,    41,    41,   186,   504,    41,   186,   404,    41,    41,
      41,    41,   510,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,   404,    41,    41,    41,   186,   186,
      41,    41,    41,    41,   186,    41,   186,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,   247,
      41,    41,   186,   399,   264,   330,    24,   325,   532,    40,
     233,    20,    37,   104,   151,   152,   154,   201,   202,   204,
     205,   212,   214,   215,   222,   261,    51,   411,   416,   477,
     336,   338,   339,   334,   409,   410,   411,   462,   468,   474,
     476,   411,   532,    41,   270,   271,   398,   478,   503,   273,
     274,   397,   398,   502,   503,    25,   267,   275,     1,    52,
     237,   238,   346,   349,   350,   353,   421,   467,   469,   470,
     472,   476,    37,    42,   478,   385,   480,   501,   501,   501,
      91,   244,   245,   483,   486,    56,    57,    58,    59,    60,
      61,    66,    67,   489,   490,   497,   499,   399,   521,   513,
     480,   480,   480,   480,   480,   480,   480,   480,   511,   480,
     480,   480,   480,   478,   480,   480,   480,   480,   480,   480,
      18,   401,   401,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   401,   401,   532,   345,   178,   345,   223,    43,   104,
     162,   206,   207,   210,   386,   478,   522,   526,   530,   532,
     154,   216,   217,   220,   386,   205,   203,   215,   213,    53,
     417,   420,   474,     1,    44,   335,     6,    42,   474,   480,
     271,   274,    26,    29,    30,   268,   281,   284,   285,   471,
     241,    38,   352,     1,    44,   354,   355,    41,   423,   422,
     376,    38,    41,   186,   383,    42,   478,    42,    54,   482,
      55,   485,   491,   491,   491,   491,   491,   491,    67,   404,
      62,    63,   493,   496,   528,   529,    20,    64,   494,   514,
      42,    42,    42,   405,    49,    49,    49,    49,   345,    42,
      42,    49,    42,    42,    49,    42,    42,    42,    42,    49,
      20,   480,   516,   480,    42,    42,    49,    49,    42,    42,
      42,    42,    42,    42,    49,    42,    42,    42,    49,    42,
      42,    42,    49,    42,    42,    42,    42,    42,    49,    42,
      42,    42,   480,   480,    38,    41,   224,   210,   104,   220,
     154,   203,     1,    44,   104,   208,   213,     1,    44,   154,
     218,   415,   419,    44,   334,   477,   245,    27,    28,   276,
     277,   278,   279,   280,   397,   478,   165,   165,   282,   285,
     283,   284,    41,    51,    65,   102,   426,   428,   434,   435,
     440,   441,   445,   449,   451,   453,   478,   532,   239,     6,
       7,     8,    31,    45,    46,    48,   125,   148,   351,   356,
     357,   358,   360,   364,   367,   370,   371,   387,   390,   391,
     396,    44,   350,   469,   473,   475,   476,   424,   425,   426,
     426,    38,   377,   386,   384,   484,   487,   404,   498,   498,
     494,   495,   500,   500,   345,   403,   480,   480,   480,   480,
     480,   480,   480,    42,    50,   518,   519,   480,   480,   480,
     480,   480,   480,    42,   400,   225,   151,   211,    44,   209,
     153,   221,    44,   219,    50,   414,    49,   418,   340,    42,
     277,   502,   440,    41,    51,   102,   454,   460,   532,   449,
      53,   427,   442,   446,    20,    62,   103,   450,   452,   240,
     361,   365,   368,   372,   359,   388,   397,    41,   345,   335,
     392,   350,    42,   475,   382,    42,    49,   402,    49,    42,
      42,    49,    42,    42,   402,   506,    77,    42,    42,    42,
      42,   506,    42,    42,   403,   228,   207,   217,   412,   413,
     416,   420,    37,    42,   457,   459,   460,    51,   461,   532,
     436,   439,   475,   444,   448,   262,   362,   366,   369,   345,
     389,   480,   350,   345,    42,   386,   480,   480,   480,    42,
      56,    42,    42,    42,   227,   229,   386,   417,   341,    42,
     458,   433,   438,   104,   443,    64,   447,   264,   477,   297,
     297,   345,    91,   395,    42,   506,   531,    49,   226,    56,
     149,   150,   334,   456,    50,   432,    49,   437,   445,   451,
     286,   363,   477,   477,   478,    47,   393,    42,   386,   386,
     386,    38,   104,   455,   428,   429,   431,   439,   345,   345,
      23,    42,   394,   460,   430,   330,   345,   417,   262
  };

  const unsigned short int
  SPARQLParser::yyr1_[] =
  {
       0,   187,   188,   188,   189,   190,   191,   191,   191,   191,
     192,   193,   194,   194,   195,   195,   196,   196,   198,   197,
     199,   200,   200,   201,   201,   201,   201,   201,   202,   202,
     202,   203,   203,   204,   205,   206,   206,   207,   207,   209,
     208,   210,   211,   212,   212,   212,   213,   213,   214,   215,
     216,   216,   217,   217,   219,   218,   220,   221,   222,   223,
     223,   225,   224,   226,   226,   227,   228,   228,   229,   229,
     229,   230,   232,   233,   231,   235,   234,   236,   236,   238,
     239,   240,   237,   241,   242,   242,   243,   243,   244,   245,
     245,   246,   247,   247,   247,   247,   247,   247,   247,   247,
     248,   248,   249,   249,   250,   251,   251,   252,   253,   253,
     254,   254,   255,   255,   256,   257,   258,   258,   259,   260,
     261,   262,   263,   263,   264,   265,   265,   266,   266,   267,
     267,   268,   268,   269,   270,   270,   271,   271,   271,   271,
     272,   273,   273,   274,   275,   276,   276,   277,   277,   278,
     278,   279,   280,   280,   281,   281,   282,   282,   283,   283,
     284,   285,   286,   287,   288,   288,   289,   290,   291,   291,
     293,   292,   294,   294,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   296,   297,   297,   298,   299,
     299,   300,   301,   302,   303,   304,   305,   307,   306,   309,
     308,   311,   310,   312,   313,   314,   314,   315,   315,   316,
     316,   317,   317,   318,   319,   319,   321,   320,   323,   322,
     324,   325,   325,   326,   326,   327,   327,   328,   329,   329,
     329,   329,   330,   331,   333,   332,   334,   334,   335,   335,
     335,   336,   337,   337,   339,   340,   341,   338,   342,   343,
     344,   344,   345,   345,   346,   346,   346,   348,   347,   349,
     350,   350,   351,   352,   352,   353,   354,   354,   355,   355,
     355,   356,   356,   356,   356,   356,   356,   356,   356,   356,
     356,   357,   359,   358,   361,   362,   363,   360,   365,   366,
     364,   368,   369,   367,   370,   371,   372,   372,   374,   375,
     373,   376,   376,   377,   379,   378,   380,   380,   381,   381,
     382,   382,   384,   383,   383,   385,   385,   386,   386,   386,
     386,   386,   386,   386,   388,   389,   387,   391,   392,   390,
     394,   393,   395,   395,   396,   397,   397,   397,   398,   399,
     400,   399,   401,   401,   402,   403,   403,   404,   405,   404,
     407,   406,   408,   406,   409,   410,   410,   411,   412,   413,
     413,   414,   415,   415,   416,   416,   417,   418,   419,   419,
     420,   422,   421,   423,   421,   424,   425,   425,   427,   426,
     428,   428,   430,   429,   431,   431,   432,   433,   433,   434,
     435,   436,   437,   438,   438,   439,   440,   442,   441,   443,
     444,   444,   446,   445,   447,   448,   448,   449,   450,   450,
     451,   451,   452,   452,   452,   453,   453,   453,   453,   454,
     454,   455,   456,   456,   458,   457,   459,   459,   460,   460,
     460,   461,   461,   462,   462,   464,   463,   465,   466,   466,
     466,   466,   466,   467,   467,   468,   468,   469,   469,   471,
     470,   472,   473,   473,   474,   474,   475,   475,   476,   476,
     477,   477,   478,   478,   479,   479,   479,   479,   479,   479,
     480,   481,   482,   483,   483,   484,   485,   486,   486,   487,
     488,   489,   489,   490,   490,   490,   490,   490,   490,   490,
     490,   491,   492,   493,   493,   494,   494,   495,   495,   496,
     496,   496,   497,   497,   498,   499,   499,   500,   500,   500,
     500,   501,   501,   501,   501,   501,   501,   501,   501,   502,
     503,   503,   503,   503,   503,   503,   503,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   503,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   503,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   503,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   503,   503,   503,   503,
     503,   503,   503,   503,   504,   504,   505,   506,   506,   507,
     508,   510,   511,   509,   513,   514,   512,   515,   515,   515,
     516,   516,   517,   517,   517,   517,   517,   518,   519,   519,
     520,   521,   521,   522,   523,   524,   524,   525,   525,   526,
     526,   526,   527,   527,   527,   528,   528,   528,   529,   529,
     529,   530,   530,   531,   531,   531,   531,   532,   532,   533,
     533,   534,   534
  };

  const unsigned char
  SPARQLParser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     3,     0,     1,     0,     2,     0,     2,     0,     3,
       2,     0,     1,     1,     1,     1,     1,     2,     4,     3,
       4,     0,     2,     1,     2,     1,     2,     1,     1,     0,
       3,     2,     1,     4,     3,     4,     0,     2,     1,     2,
       1,     2,     1,     1,     0,     3,     2,     1,     3,     0,
       2,     0,     4,     0,     1,     2,     0,     2,     3,     3,
       3,     2,     0,     0,     5,     0,     5,     0,     2,     0,
       0,     0,     7,     3,     1,     1,     0,     1,     2,     0,
       1,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     2,     4,     4,     5,     1,     2,
       1,     1,     0,     1,     4,     2,     1,     1,     1,     2,
       1,     2,     0,     1,     4,     0,     1,     0,     1,     0,
       1,     0,     1,     3,     1,     2,     1,     1,     4,     1,
       2,     1,     2,     1,     3,     1,     2,     1,     1,     1,
       1,     2,     1,     1,     2,     2,     0,     1,     0,     1,
       2,     2,     1,     2,     0,     1,     2,     2,     0,     1,
       0,     3,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     0,     1,     2,     0,
       1,     3,     3,     3,     5,     5,     5,     0,     3,     0,
       3,     0,     3,     6,     2,     0,     1,     0,     1,     2,
       1,     0,     2,     2,     0,     1,     0,     3,     0,     3,
       2,     1,     2,     1,     2,     0,     1,     2,     1,     1,
       1,     1,     3,     3,     0,     3,     0,     1,     0,     1,
       2,     3,     0,     2,     0,     0,     0,     8,     2,     2,
       0,     1,     1,     1,     1,     1,     1,     0,     4,     2,
       0,     1,     3,     0,     2,     2,     2,     3,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     0,     3,     0,     0,     0,     6,     0,     0,
       6,     0,     0,     8,     6,     2,     1,     1,     0,     0,
       6,     0,     2,     1,     0,     5,     0,     2,     1,     3,
       0,     2,     0,     4,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     0,     0,     4,     0,     0,     4,
       0,     3,     0,     2,     2,     1,     1,     1,     2,     1,
       0,     6,     0,     1,     2,     0,     2,     1,     0,     5,
       0,     3,     0,     3,     1,     0,     1,     3,     2,     0,
       1,     2,     0,     2,     1,     1,     2,     2,     0,     2,
       1,     0,     3,     0,     3,     1,     0,     1,     0,     4,
       1,     1,     0,     3,     0,     1,     2,     0,     2,     1,
       1,     2,     2,     0,     2,     1,     1,     0,     3,     2,
       0,     2,     0,     3,     2,     0,     2,     2,     0,     1,
       1,     2,     1,     1,     1,     1,     1,     2,     3,     1,
       3,     2,     0,     2,     0,     3,     0,     1,     1,     1,
       2,     1,     1,     1,     1,     0,     4,     4,     1,     1,
       1,     1,     1,     0,     1,     1,     2,     1,     1,     0,
       4,     4,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     0,     2,     2,     2,     0,     2,     1,
       2,     0,     1,     2,     2,     2,     2,     2,     2,     2,
       3,     1,     2,     1,     1,     2,     2,     0,     1,     2,
       2,     2,     0,     2,     2,     0,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     4,     6,     4,     4,     4,     4,     2,     2,     4,
       4,     4,     4,     2,     1,     4,     1,     4,     4,     4,
       6,     6,     6,     6,     6,     4,     4,     4,     4,     4,
       4,     4,     4,     2,     2,     2,     4,     4,     4,     4,
       4,     2,     8,     6,     6,     6,     4,     4,     4,     4,
       4,     1,     1,     1,     3,     1,     7,     0,     1,     7,
       9,     0,     0,     4,     0,     0,     5,     5,     5,     6,
       1,     1,     1,     1,     1,     1,     1,     4,     0,     1,
       2,     0,     1,     2,     2,     1,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const SPARQLParser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "IT_DELETE", "IT_INSERT",
  "IT_DATA", "IT_GRAPH", "IT_SERVICE", "IT_SADI", "IT_LOAD", "IT_INTO",
  "IT_CLEAR", "IT_CREATE", "IT_SILENT", "IT_DROP", "IT_BASE", "IT_PREFIX",
  "IT_SELECT", "IT_DISTINCT", "IT_REDUCED", "GT_TIMES", "IT_CONSTRUCT",
  "IT_DESCRIBE", "IT_FROM", "IT_NAMED", "IT_ORDER", "IT_BY", "IT_ASC",
  "IT_DESC", "IT_LIMIT", "IT_OFFSET", "IT_VALUES", "IT_MEMBERS",
  "IT_STARTS", "IT_ENDS", "IT_ANY", "IT_UNORDERED", "GT_LCURLEY",
  "GT_RCURLEY", "IT_ASK", "IT_WHERE", "GT_LPAREN", "GT_RPAREN", "IT_UNDEF",
  "GT_DOT", "IT_OPTIONAL", "IT_MINUS", "IT_UNION", "IT_FILTER", "GT_COMMA",
  "GT_SEMI", "IT_a", "GT_LBRACKET", "GT_RBRACKET", "GT_OR", "GT_AND",
  "GT_EQUAL", "GT_NEQUAL", "GT_LT", "GT_GT", "GT_LE", "GT_GE", "GT_PLUS",
  "GT_MINUS", "GT_DIVIDE", "GT_NOT", "IT_NOT", "IT_IN", "IT_IRI", "IT_URI",
  "IT_BNODE", "IT_COALESCE", "IT_IF", "IT_STRLANG", "IT_STRDT",
  "IT_REPLACE", "IT_EXISTS", "IT_SEPARATOR", "IT_STR", "IT_LANG",
  "IT_LANGMATCHES", "IT_DATATYPE", "IT_BOUND", "IT_sameTerm", "IT_isIRI",
  "IT_isURI", "IT_isBLANK", "IT_isLITERAL", "IT_REGEX", "GT_DTYPE",
  "IT_CONCAT", "IT_AS", "IT_GROUP", "IT_HAVING", "IT_COUNT", "IT_SUM",
  "IT_MIN", "IT_MAX", "IT_AVG", "IT_GROUP_CONCAT", "IT_SAMPLE",
  "IT_isNUMERIC", "GT_CARROT", "GT_OPT", "GT_PIPE", "IT_WITH",
  "IT_DEFAULT", "IT_ALL", "IT_USING", "IT_UUID", "IT_STRUUID", "IT_MD5",
  "IT_TO", "IT_STRBEFORE", "IT_STRAFTER", "IT_YEAR", "IT_ADD", "IT_COPY",
  "IT_RAND", "IT_SHA512", "IT_NOW", "IT_TZ", "IT_TIMEZONE", "IT_ROUND",
  "IT_SHA384", "IT_BIND", "IT_CONTAINS", "IT_SECONDS", "IT_MOVE",
  "IT_FLOOR", "INSERTDATA", "DELETEDATA", "DELETEWHERE", "IT_MINUTES",
  "IT_SUBSTR", "IT_SHA256", "IT_HOURS", "IT_ENCODE_FOR_URI",
  "IT_STRSTARTS", "IT_CEIL", "IT_DAY", "IT_LCASE", "IT_ABS", "IT_UCASE",
  "IT_STRENDS", "IT_STRLEN", "IT_SHA1", "IT_MONTH", "IT_PRINT",
  "GT_H_2192_", "GT_MINUS_GT", "ABOX_HR", "UBOX_UHR", "UBOX_LHR",
  "GT_H_2502_", "UBOX_UL", "UBOX_U", "UBOX_UR", "UBOX_LL", "UBOX_L",
  "UBOX_LR", "RSREF", "GT_MINUS_MINUS", "IT_true", "IT_false", "INTEGER",
  "DECIMAL", "DOUBLE", "INTEGER_POSITIVE", "DECIMAL_POSITIVE",
  "DOUBLE_POSITIVE", "INTEGER_NEGATIVE", "DECIMAL_NEGATIVE",
  "DOUBLE_NEGATIVE", "STRING_LITERAL1", "STRING_LITERAL_LONG1",
  "STRING_LITERAL2", "STRING_LITERAL_LONG2", "IRIREF", "PNAME_NS",
  "PNAME_LN", "BLANK_NODE_LABEL", "ANON", "VAR1", "VAR2", "LANGTAG", "NIL",
  "$accept", "Top", "QueryUnit", "Query",
  "_O_QSelectQuery_E_Or_QConstructQuery_E_Or_QDescribeQuery_E_Or_QAskQuery_E_C",
  "UpdateUnit", "Prologue", "_QBaseDecl_E_Opt", "_QPrefixDecl_E_Star",
  "_QLoadResults_E_Star", "LoadResults", "@1",
  "_O_QRSREF_E_S_QGT_EQUAL_E_C", "_Q_O_QRSREF_E_S_QGT_EQUAL_E_C_E_Opt",
  "Result", "ABox", "_QABoxRow_E_Star", "ABoxTop", "ABoxHeader",
  "_QABoxCell_E_Plus", "_O_QGT_PIPE_E_Or_QABoxCell_E_Plus_C", "ABoxRow",
  "$@2", "ABoxCell", "ABoxBottom", "UBox", "_QUBoxRow_E_Star", "UBoxTop",
  "UBoxHeader", "_QUBoxCell_E_Plus",
  "_O_QGT_H_2502__E_Or_QUBoxCell_E_Plus_C", "UBoxRow", "$@3", "UBoxCell",
  "UBoxBottom", "CurlySet", "_QMap_E_Star", "Map", "$@4",
  "_QGT_COMMA_E_Opt", "_O_QBinding_E_S_QGT_COMMA_E_Opt_C",
  "_Q_O_QBinding_E_S_QGT_COMMA_E_Opt_C_E_Star", "Binding", "BaseDecl",
  "PrefixDecl", "$@5", "$@6", "SelectQuery", "@7",
  "_QDatasetClause_E_Star", "SubSelect", "@8", "@9", "@10", "SelectClause",
  "_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C",
  "_Q_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C_E_Opt", "_O_QIT_AS_E_S_QVar_E_C",
  "_Q_O_QIT_AS_E_S_QVar_E_C_E_Opt",
  "_O_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C",
  "_O_QBuiltInCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QVar_E_Or_QAggregate_E_Or_QFunctionCall_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C",
  "_Q_O_QBuiltInCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QVar_E_Or_QAggregate_E_Or_QFunctionCall_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C_E_Plus",
  "_O_QBuiltInCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QVar_E_Or_QAggregate_E_Or_QFunctionCall_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_Plus_Or_QGT_TIMES_E_C",
  "ConstructQuery",
  "_O_QQuadPattern_E_S_QDatasetClause_E_Star_S_QWhereClause_E_S_QSolutionModifier_E_Or_QDatasetClause_E_Star_S_QIT_WHERE_E_S_QQuadPattern_E_S_QSolutionModifier_E_C",
  "DescribeQuery", "_QVarOrIri_E_Plus",
  "_O_QVarOrIri_E_Plus_Or_QGT_TIMES_E_C", "_QWhereClause_E_Opt",
  "AskQuery", "DatasetClause",
  "_O_QDefaultGraphClause_E_Or_QNamedGraphClause_E_C",
  "DefaultGraphClause", "NamedGraphClause", "SourceSelector",
  "WhereClause", "_QIT_WHERE_E_Opt", "SolutionModifier",
  "_QGroupClause_E_Opt", "_QHavingClause_E_Opt", "_QOrderClause_E_Opt",
  "_QLimitOffsetClauses_E_Opt", "GroupClause", "_QGroupCondition_E_Plus",
  "GroupCondition", "HavingClause", "_QHavingCondition_E_Plus",
  "HavingCondition", "OrderClause", "_QOrderCondition_E_Plus",
  "OrderCondition", "_O_QIT_ASC_E_Or_QIT_DESC_E_C",
  "_O_QIT_ASC_E_Or_QIT_DESC_E_S_QBrackettedExpression_E_C",
  "_O_QConstraint_E_Or_QVar_E_C", "LimitOffsetClauses",
  "_QOffsetClause_E_Opt", "_QLimitClause_E_Opt", "LimitClause",
  "OffsetClause", "ValuesClause", "_O_QIT_VALUES_E_S_QDataBlock_E_C",
  "_Q_O_QIT_VALUES_E_S_QDataBlock_E_C_E_Opt", "Update",
  "_O_QGT_SEMI_E_S_QUpdate_E_C", "_Q_O_QGT_SEMI_E_S_QUpdate_E_C_E_Opt",
  "_O_QUpdate1_E_S_QGT_SEMI_E_S_QUpdate_E_Opt_C", "$@11",
  "_Q_O_QUpdate1_E_S_QGT_SEMI_E_S_QUpdate_E_Opt_C_E_Opt", "Update1",
  "Load", "_QIT_SILENT_E_Opt", "_O_QIT_INTO_E_S_QGraphRef_E_C",
  "_Q_O_QIT_INTO_E_S_QGraphRef_E_C_E_Opt", "Clear", "Drop", "Create",
  "Add", "Move", "Copy", "InsertData", "$@12", "DeleteData", "$@13",
  "DeleteWhere", "$@14", "Modify", "_O_QIT_WITH_E_S_Qiri_E_C",
  "_Q_O_QIT_WITH_E_S_Qiri_E_C_E_Opt", "_QInsertClause_E_Opt",
  "_O_QDeleteClause_E_S_QInsertClause_E_Opt_Or_QInsertClause_E_C",
  "_QUsingClause_E_Star", "_O_QIT_CONSTRUCT_E_S_QQuadPattern_E_C",
  "_Q_O_QIT_CONSTRUCT_E_S_QQuadPattern_E_C_E_Opt", "DeleteClause", "$@15",
  "InsertClause", "$@16", "UsingClause",
  "_O_Qiri_E_Or_QIT_NAMED_E_S_Qiri_E_C", "GraphOrDefault",
  "_QIT_GRAPH_E_Opt", "GraphRef", "GraphRefAll", "QuadPattern", "QuadData",
  "Quads", "$@17", "_QTriplesTemplate_E_Opt", "_QGT_DOT_E_Opt",
  "_O_QQuadsNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesTemplate_E_Opt_C",
  "_Q_O_QQuadsNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesTemplate_E_Opt_C_E_Star",
  "QuadsNotTriples", "@18", "@19", "$@20", "TriplesTemplate",
  "_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C_E_Opt", "GroupGraphPattern",
  "_O_QSubSelect_E_Or_QGroupGraphPatternSub_E_C",
  "_O_QGT_LCURLEY_E_S_QSubSelect_E_Or_QGroupGraphPatternSub_E_S_QGT_RCURLEY_E_C",
  "$@21", "GroupGraphPatternSub", "_QTriplesBlock_E_Opt",
  "_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "TriplesBlock", "_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C_E_Opt", "GraphPatternNotTriples",
  "Print", "OptionalGraphPattern", "@22", "GraphGraphPattern", "@23",
  "@24", "@25", "ServiceGraphPattern", "@26", "@27", "SADIinvocation",
  "@28", "@29", "Bind", "InlineData", "DataBlock", "InlineDataOneVar",
  "$@30", "$@31", "_QSingleValueRow_E_Star", "SingleValueRow",
  "InlineDataFull", "$@32", "_QVar_E_Star",
  "_O_QNIL_E_Or_QGT_LPAREN_E_S_QVar_E_Star_S_QGT_RPAREN_E_C",
  "_QDataBlockValue_E_Star",
  "_O_QGT_LPAREN_E_S_QDataBlockValue_E_Star_S_QGT_RPAREN_E_Or_QNIL_E_C",
  "$@33",
  "_Q_O_QGT_LPAREN_E_S_QDataBlockValue_E_Star_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star",
  "DataBlockValue", "MinusGraphPattern", "@34", "@35",
  "GroupOrUnionGraphPattern", "@36", "@37",
  "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@38",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList", "@39", "_QIT_DISTINCT_E_Opt",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "ExpressionList", "@40",
  "TriplesSameSubject", "$@41", "$@42", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "PropertyListNotEmpty",
  "_O_QVerb_E_S_QObjectList_E_C", "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "Verb",
  "ObjectList", "_O_QGT_COMMA_E_S_QObject_E_C",
  "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star", "Object",
  "TriplesSameSubjectPath", "$@43", "$@44", "PropertyListPath",
  "_QPropertyListPathNotEmpty_E_Opt", "PropertyListPathNotEmpty", "$@45",
  "_O_QVerbPath_E_Or_QVerbSimple_E_C",
  "_O_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_C", "$@46",
  "_Q_O_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_Opt_C_E_Star",
  "VerbPath", "VerbSimple", "ObjectListPath",
  "_O_QGT_COMMA_E_S_QObjectPath_E_C",
  "_Q_O_QGT_COMMA_E_S_QObjectPath_E_C_E_Star", "ObjectPath", "Path",
  "PathAlternative", "@47", "_O_QGT_PIPE_E_S_QPathSequence_E_C",
  "_Q_O_QGT_PIPE_E_S_QPathSequence_E_C_E_Star", "PathSequence", "@48",
  "_O_QGT_DIVIDE_E_S_QPathEltOrInverse_E_C",
  "_Q_O_QGT_DIVIDE_E_S_QPathEltOrInverse_E_C_E_Star", "PathElt",
  "_QPathMod_E_Opt", "PathEltOrInverse", "PathMod", "PathPrimary",
  "PathNegatedPropertySet", "_O_QGT_PIPE_E_S_QPathOneInPropertySet_E_C",
  "_Q_O_QGT_PIPE_E_S_QPathOneInPropertySet_E_C_E_Star",
  "_O_QPathOneInPropertySet_E_S_QGT_PIPE_E_S_QPathOneInPropertySet_E_Star_C",
  "@49",
  "_Q_O_QPathOneInPropertySet_E_S_QGT_PIPE_E_S_QPathOneInPropertySet_E_Star_C_E_Opt",
  "PathOneInPropertySet", "_O_Qiri_E_Or_QIT_a_E_C", "TriplesNode",
  "BlankNodePropertyList", "@50", "Generator",
  "_O_QIT_MEMBERS_E_Or_QIT_STARTS_E_Or_QIT_ENDS_E_Or_QIT_ANY_E_Or_QIT_UNORDERED_E_C",
  "_Q_O_QIT_MEMBERS_E_Or_QIT_STARTS_E_Or_QIT_ENDS_E_Or_QIT_ANY_E_Or_QIT_UNORDERED_E_C_E_Opt",
  "_QGraphNode_E_Plus", "TriplesNodePath", "BlankNodePropertyListPath",
  "@51", "GeneratorPath", "_QGraphNodePath_E_Plus", "GraphNode",
  "GraphNodePath", "VarOrTerm", "VarOrIri", "Var", "GraphTerm",
  "Expression", "ConditionalOrExpression",
  "_O_QGT_OR_E_S_QConditionalAndExpression_E_C",
  "_Q_O_QGT_OR_E_S_QConditionalAndExpression_E_C_E_Star",
  "ConditionalAndExpression", "_O_QGT_AND_E_S_QValueLogical_E_C",
  "_Q_O_QGT_AND_E_S_QValueLogical_E_C_E_Star", "ValueLogical",
  "RelationalExpression", "_QRelativeExpression_E_Opt",
  "RelativeExpression", "NumericExpression", "AdditiveExpression",
  "_O_QNumericLiteralPositive_E_Or_QNumericLiteralNegative_E_C",
  "_O_QGT_TIMES_E_S_QUnaryExpression_E_Or_QGT_DIVIDE_E_S_QUnaryExpression_E_C",
  "_Q_O_QGT_TIMES_E_S_QUnaryExpression_E_Or_QGT_DIVIDE_E_S_QUnaryExpression_E_C_E_Opt",
  "_O_QGT_PLUS_E_S_QMultiplicativeExpression_E_Or_QGT_MINUS_E_S_QMultiplicativeExpression_E_Or_QNumericLiteralPositive_E_Or_QNumericLiteralNegative_E_S_QGT_TIMES_E_S_QUnaryExpression_E_Or_QGT_DIVIDE_E_S_QUnaryExpression_E_Opt_C",
  "_Q_O_QGT_PLUS_E_S_QMultiplicativeExpression_E_Or_QGT_MINUS_E_S_QMultiplicativeExpression_E_Or_QNumericLiteralPositive_E_Or_QNumericLiteralNegative_E_S_QGT_TIMES_E_S_QUnaryExpression_E_Or_QGT_DIVIDE_E_S_QUnaryExpression_E_Opt_C_E_Star",
  "MultiplicativeExpression",
  "_Q_O_QGT_TIMES_E_S_QUnaryExpression_E_Or_QGT_DIVIDE_E_S_QUnaryExpression_E_C_E_Star",
  "UnaryExpression", "PrimaryExpression", "BrackettedExpression",
  "BuiltInCall",
  "_O_QGT_LPAREN_E_S_QExpression_E_S_QGT_RPAREN_E_Or_QNIL_E_C",
  "RegexExpression", "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Opt",
  "SubstringExpression", "StrReplaceExpression", "ExistsFunc", "@52",
  "@53", "NotExistsFunc", "@54", "@55", "Aggregate",
  "_O_QGT_TIMES_E_Or_QExpression_E_C",
  "_O_QIT_SUM_E_Or_QIT_MIN_E_Or_QIT_MAX_E_Or_QIT_AVG_E_Or_QIT_SAMPLE_E_C",
  "_O_QGT_SEMI_E_S_QIT_SEPARATOR_E_S_QGT_EQUAL_E_S_QString_E_C",
  "_Q_O_QGT_SEMI_E_S_QIT_SEPARATOR_E_S_QGT_EQUAL_E_S_QString_E_C_E_Opt",
  "iriOrFunction", "_QArgList_E_Opt", "RDFLiteral",
  "_O_QGT_DTYPE_E_S_Qiri_E_C", "_O_QLANGTAG_E_Or_QGT_DTYPE_E_S_Qiri_E_C",
  "_Q_O_QLANGTAG_E_Or_QGT_DTYPE_E_S_Qiri_E_C_E_Opt", "NumericLiteral",
  "NumericLiteralUnsigned", "NumericLiteralPositive",
  "NumericLiteralNegative", "BooleanLiteral", "String", "iri",
  "PrefixedName", "BlankNode", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  SPARQLParser::yyrline_[] =
  {
       0,   563,   563,   566,   572,   577,   588,   589,   590,   591,
     595,   600,   604,   606,   610,   612,   615,   617,   621,   621,
     638,   644,   647,   651,   654,   657,   660,   663,   672,   673,
     674,   677,   679,   683,   687,   691,   692,   696,   697,   701,
     701,   709,   715,   719,   720,   721,   724,   726,   730,   734,
     738,   739,   743,   744,   748,   748,   756,   762,   766,   769,
     771,   775,   775,   782,   784,   788,   791,   793,   797,   800,
     803,   809,   815,   817,   815,   827,   827,   871,   874,   882,
     885,   889,   882,   908,   920,   923,   930,   933,   938,   945,
     948,   953,   967,   972,   977,   982,   987,   990,   995,  1001,
    1006,  1009,  1017,  1030,  1036,  1042,  1051,  1065,  1074,  1077,
    1085,  1088,  1095,  1098,  1103,  1111,  1118,  1119,  1123,  1129,
    1135,  1142,  1149,  1151,  1156,  1163,  1166,  1171,  1174,  1179,
    1182,  1187,  1191,  1195,  1202,  1205,  1212,  1215,  1218,  1227,
    1233,  1239,  1242,  1249,  1254,  1261,  1265,  1273,  1275,  1283,
    1286,  1294,  1302,  1303,  1310,  1314,  1322,  1325,  1330,  1333,
    1337,  1343,  1349,  1353,  1359,  1362,  1366,  1372,  1375,  1377,
    1381,  1381,  1390,  1392,  1396,  1397,  1398,  1399,  1400,  1401,
    1402,  1403,  1404,  1405,  1406,  1410,  1416,  1419,  1426,  1433,
    1436,  1440,  1446,  1452,  1458,  1464,  1470,  1476,  1476,  1487,
    1487,  1498,  1498,  1509,  1517,  1523,  1526,  1530,  1533,  1537,
    1541,  1548,  1551,  1560,  1566,  1569,  1573,  1573,  1582,  1582,
    1591,  1597,  1601,  1608,  1611,  1616,  1618,  1622,  1628,  1631,
    1634,  1637,  1644,  1651,  1657,  1657,  1665,  1667,  1671,  1673,
    1674,  1678,  1681,  1683,  1688,  1693,  1696,  1688,  1707,  1711,
    1714,  1716,  1720,  1721,  1737,  1738,  1739,  1744,  1744,  1755,
    1759,  1761,  1771,  1775,  1778,  1794,  1799,  1800,  1804,  1807,
    1808,  1812,  1813,  1814,  1815,  1816,  1817,  1818,  1819,  1820,
    1823,  1827,  1833,  1833,  1849,  1853,  1855,  1849,  1866,  1870,
    1866,  1879,  1883,  1879,  1900,  1916,  1922,  1923,  1927,  1929,
    1927,  1936,  1938,  1942,  1950,  1950,  1957,  1959,  1965,  1966,
    1969,  1971,  1977,  1977,  1982,  1988,  1990,  1994,  1997,  2000,
    2003,  2006,  2009,  2012,  2018,  2022,  2018,  2032,  2036,  2032,
    2046,  2046,  2058,  2060,  2064,  2074,  2075,  2076,  2080,  2088,
    2092,  2092,  2102,  2105,  2112,  2118,  2120,  2135,  2138,  2138,
    2148,  2148,  2151,  2151,  2157,  2160,  2162,  2167,  2172,  2176,
    2178,  2183,  2187,  2189,  2193,  2197,  2205,  2210,  2214,  2216,
    2220,  2228,  2228,  2231,  2231,  2237,  2240,  2242,  2246,  2246,
    2252,  2253,  2257,  2257,  2262,  2264,  2268,  2271,  2273,  2277,
    2286,  2292,  2296,  2299,  2301,  2305,  2312,  2316,  2316,  2326,
    2332,  2335,  2341,  2341,  2351,  2357,  2360,  2366,  2372,  2375,
    2379,  2380,  2386,  2389,  2392,  2398,  2401,  2404,  2407,  2416,
    2417,  2426,  2432,  2435,  2441,  2441,  2451,  2454,  2458,  2461,
    2464,  2470,  2473,  2481,  2482,  2486,  2486,  2499,  2527,  2530,
    2533,  2536,  2539,  2546,  2549,  2554,  2558,  2565,  2566,  2570,
    2570,  2582,  2609,  2613,  2620,  2621,  2625,  2626,  2630,  2633,
    2637,  2640,  2646,  2647,  2651,  2654,  2657,  2660,  2663,  2664,
    2670,  2675,  2684,  2691,  2694,  2702,  2711,  2718,  2721,  2728,
    2733,  2746,  2750,  2754,  2758,  2762,  2766,  2770,  2774,  2778,
    2782,  2789,  2794,  2803,  2806,  2813,  2816,  2823,  2826,  2831,
    2834,  2838,  2852,  2855,  2863,  2872,  2875,  2882,  2885,  2888,
    2891,  2895,  2896,  2897,  2898,  2901,  2904,  2907,  2910,  2914,
    2926,  2929,  2932,  2935,  2938,  2941,  2944,  2948,  2951,  2954,
    2957,  2960,  2963,  2966,  2969,  2970,  2973,  2974,  2977,  2980,
    2983,  2986,  2989,  2992,  2995,  2998,  3001,  3004,  3007,  3010,
    3013,  3016,  3019,  3022,  3025,  3028,  3031,  3034,  3037,  3040,
    3043,  3046,  3049,  3052,  3055,  3058,  3061,  3064,  3067,  3070,
    3073,  3076,  3077,  3078,  3084,  3093,  3100,  3107,  3110,  3114,
    3120,  3126,  3129,  3126,  3141,  3144,  3141,  3157,  3165,  3174,
    3190,  3193,  3197,  3200,  3203,  3206,  3209,  3215,  3221,  3224,
    3228,  3238,  3241,  3246,  3254,  3261,  3265,  3273,  3277,  3281,
    3282,  3283,  3287,  3288,  3289,  3293,  3294,  3295,  3299,  3300,
    3301,  3305,  3306,  3310,  3311,  3312,  3313,  3317,  3318,  3322,
    3323,  3327,  3361
  };

  // Print the state stack on the debug stream.
  void
  SPARQLParser::yystack_print_ ()
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
  SPARQLParser::yy_reduce_print_ (int yyrule)
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
  SPARQLParser::token_number_type
  SPARQLParser::yytranslate_ (int t)
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
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186
    };
    const unsigned int user_token_number_max_ = 441;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // w3c_sw
#line 5940 "lib/SPARQLParser.cpp" // lalr1.cc:1167
#line 3367 "lib/SPARQLParser.ypp" // lalr1.cc:1168
 /*** Additional Code ***/

void w3c_sw::SPARQLParser::error(const SPARQLParser::location_type& l,
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
    _SUBS(s, "IT_BASE", "@base");
    _SUBS(s, "IT_PREFIX", "@prefix");
    _SUBS(s, "IT_a", "keyword 'a'");
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

    _SUBS(s, "GT_TIMES", "'*'");
    _SUBS(s, "GT_LCURLEY", "'{'");
    _SUBS(s, "GT_RCURLEY", "'}'");
    _SUBS(s, "GT_COMMA", "','");
    _SUBS(s, "GT_OR", "'||'");
    _SUBS(s, "GT_AND", "'&&'");
    _SUBS(s, "GT_EQUAL", "'='");
    _SUBS(s, "GT_NEQUAL", "'!='");
    _SUBS(s, "GT_LT", "'<'");
    _SUBS(s, "GT_GT", "'>'");
    _SUBS(s, "GT_LE", "'<='");
    _SUBS(s, "GT_GE", "'>='");
    _SUBS(s, "GT_DIVIDE", "'/'");
    _SUBS(s, "GT_PLUS", "'+'");
    _SUBS(s, "GT_MINUS", "'-'");
    _SUBS(s, "GT_NOT", "'!'");

    _SUBS(s, "GT_CARROT", "'^'");
    _SUBS(s, "GT_OPT", "'?'");
    _SUBS(s, "GT_PIPE", "'|'");
    _SUBS(s, "GT_MINUS_GT", "'->'");
    _SUBS(s, "GT_MINUS_MINUS", "'--'");

    _SUBS(s, "INTEGER_POSITIVE", "+integer");
    _SUBS(s, "DECIMAL_POSITIVE", "+decimal");
    _SUBS(s, "DOUBLE_POSITIVE", "+double");
    _SUBS(s, "INTEGER_NEGATIVE", "-integer");
    _SUBS(s, "DECIMAL_NEGATIVE", "-decimal");
    _SUBS(s, "DOUBLE_NEGATIVE", "-double");

    _SUBS(s, "GT_H_2192_", "→");



    _SUBS(s, "ABOX_HR", "'-'");
    _SUBS(s, "UBOX_UHR", "'┌─┬┐'");
    _SUBS(s, "UBOX_LHR", "'└─┴┘'");
    _SUBS(s, "GT_H_2502_", "'│'");
    _SUBS(s, "UBOX_UL", "'┌'");
    _SUBS(s, "UBOX_U", "'─'");
    _SUBS(s, "UBOX_UR", "'┐'");
    _SUBS(s, "UBOX_LL", "'└'");
    _SUBS(s, "UBOX_L", "'─'");
    _SUBS(s, "UBOX_LR", "'┘'");
    _SUBS(s, "RSREF", "*<name>");

    _SUBS(s, "INSERTDATA", "'INSERT DATA'");
    _SUBS(s, "DELETEDATA", "'DELETE DATA'");
    _SUBS(s, "DELETEWHERE", "'DELETE WHERE'");

    _SUBS(s, "IT_DELETE", "'DELETE'");
    _SUBS(s, "IT_INSERT", "'INSERT'");
    _SUBS(s, "IT_DATA", "'DATA'");
    _SUBS(s, "IT_GRAPH", "'GRAPH'");
    _SUBS(s, "IT_SERVICE", "'SERVICE'");
    _SUBS(s, "IT_SADI", "'SADI'");
    _SUBS(s, "IT_LOAD", "'LOAD'");
    _SUBS(s, "IT_INTO", "'INTO'");
    _SUBS(s, "IT_CLEAR", "'CLEAR'");
    _SUBS(s, "IT_CREATE", "'CREATE'");
    _SUBS(s, "IT_SILENT", "'SILENT'");
    _SUBS(s, "IT_DROP", "'DROP'");
    _SUBS(s, "IT_SELECT", "'SELECT'");
    _SUBS(s, "IT_DISTINCT", "'DISTINCT'");
    _SUBS(s, "IT_REDUCED", "'REDUCED'");
    _SUBS(s, "IT_CONSTRUCT", "'CONSTRUCT'");
    _SUBS(s, "IT_DESCRIBE", "'DESCRIBE'");
    _SUBS(s, "IT_FROM", "'FROM'");
    _SUBS(s, "IT_NAMED", "'NAMED'");
    _SUBS(s, "IT_ORDER", "'ORDER'");
    _SUBS(s, "IT_BY", "'BY'");
    _SUBS(s, "IT_ASC", "'ASC'");
    _SUBS(s, "IT_DESC", "'DESC'");
    _SUBS(s, "IT_LIMIT", "'LIMIT'");
    _SUBS(s, "IT_OFFSET", "'OFFSET'");
    _SUBS(s, "IT_VALUES", "'VALUES'");
    _SUBS(s, "IT_MEMBERS", "'MEMBERS'");
    _SUBS(s, "IT_STARTS", "'STARTS'");
    _SUBS(s, "IT_ENDS", "'ENDS'");
    _SUBS(s, "IT_ANY", "'ANY'");
    _SUBS(s, "IT_UNORDERED", "'UNORDERED'");
    _SUBS(s, "IT_ASK", "'ASK'");
    _SUBS(s, "IT_WHERE", "'WHERE'");
    _SUBS(s, "IT_UNDEF", "'UNDEF'");
    _SUBS(s, "IT_OPTIONAL", "'OPTIONAL'");
    _SUBS(s, "IT_MINUS", "'MINUS'");
    _SUBS(s, "IT_UNION", "'UNION'");
    _SUBS(s, "IT_FILTER", "'FILTER'");
    _SUBS(s, "IT_NOT", "'NOT'");
    _SUBS(s, "IT_IN", "'IN'");
    _SUBS(s, "IT_IRI", "'IRI'");
    _SUBS(s, "IT_URI", "'URI'");
    _SUBS(s, "IT_BNODE", "'BNODE'");
    _SUBS(s, "IT_COALESCE", "'COALESCE'");
    _SUBS(s, "IT_IF", "'IF'");
    _SUBS(s, "IT_STRLANG", "'STRLANG'");
    _SUBS(s, "IT_STRDT", "'STRDT'");
    _SUBS(s, "IT_REPLACE", "'REPLACE'");
    _SUBS(s, "IT_EXISTS", "'EXISTS'");
    _SUBS(s, "IT_SEPARATOR", "'SEPARATOR'");
    _SUBS(s, "IT_STR", "'STR'");
    _SUBS(s, "IT_LANG", "'LANG'");
    _SUBS(s, "IT_LANGMATCHES", "'LANGMATCHES'");
    _SUBS(s, "IT_DATATYPE", "'DATATYPE'");
    _SUBS(s, "IT_BOUND", "'BOUND'");
    _SUBS(s, "IT_sameTerm", "'sameTerm'");
    _SUBS(s, "IT_isIRI", "'isIRI'");
    _SUBS(s, "IT_isURI", "'isURI'");
    _SUBS(s, "IT_isBLANK", "'isBLANK'");
    _SUBS(s, "IT_isLITERAL", "'isLITERAL'");
    _SUBS(s, "IT_REGEX", "'REGEX'");
    _SUBS(s, "IT_CONCAT", "'CONCAT'");
    _SUBS(s, "IT_AS", "'AS'");
    _SUBS(s, "IT_GROUP", "'GROUP'");
    _SUBS(s, "IT_HAVING", "'HAVING'");
    _SUBS(s, "IT_COUNT", "'COUNT'");
    _SUBS(s, "IT_SUM", "'SUM'");
    _SUBS(s, "IT_MIN", "'MIN'");
    _SUBS(s, "IT_MAX", "'MAX'");
    _SUBS(s, "IT_AVG", "'AVG'");
    _SUBS(s, "IT_GROUP_CONCAT", "'GROUP_CONCAT'");
    _SUBS(s, "IT_SAMPLE", "'SAMPLE'");
    _SUBS(s, "IT_isNUMERIC", "'isNUMERIC'");
    _SUBS(s, "IT_WITH", "'WITH'");
    _SUBS(s, "IT_DEFAULT", "'DEFAULT'");
    _SUBS(s, "IT_ALL", "'ALL'");
    _SUBS(s, "IT_USING", "'USING'");
    _SUBS(s, "IT_UUID", "'UUID'");
    _SUBS(s, "IT_STRUUID", "'STRUUID'");
    _SUBS(s, "IT_MD5", "'MD5'");
    _SUBS(s, "IT_TO", "'TO'");
    _SUBS(s, "IT_STRBEFORE", "'STRBEFORE'");
    _SUBS(s, "IT_STRAFTER", "'STRAFTER'");
    _SUBS(s, "IT_YEAR", "'YEAR'");
    _SUBS(s, "IT_ADD", "'ADD'");
    _SUBS(s, "IT_COPY", "'COPY'");
    _SUBS(s, "IT_RAND", "'RAND'");
    _SUBS(s, "IT_SHA512", "'SHA512'");
    _SUBS(s, "IT_NOW ", "'NOW '");
    _SUBS(s, "IT_TZ", "'TZ'");
    _SUBS(s, "IT_TIMEZONE", "'TIMEZONE'");
    _SUBS(s, "IT_ROUND", "'ROUND'");
    _SUBS(s, "IT_SHA384", "'SHA384'");
    _SUBS(s, "IT_BIND", "'BIND'");
    _SUBS(s, "IT_CONTAINS", "'CONTAINS'");
    _SUBS(s, "IT_SECONDS", "'SECONDS'");
    _SUBS(s, "IT_MOVE", "'MOVE'");
    _SUBS(s, "IT_FLOOR", "'FLOOR'");
    _SUBS(s, "IT_MINUTES", "'MINUTES'");
    _SUBS(s, "IT_SUBSTR", "'SUBSTR'");
    _SUBS(s, "IT_SHA256", "'SHA256'");
    _SUBS(s, "IT_HOURS", "'HOURS'");
    _SUBS(s, "IT_ENCODE_FOR_URI", "'ENCODE_FOR_URI'");
    _SUBS(s, "IT_STRSTARTS", "'STRSTARTS'");
    _SUBS(s, "IT_CEIL", "'CEIL'");
    _SUBS(s, "IT_DAY", "'DAY'");
    _SUBS(s, "IT_LCASE", "'LCASE'");
    _SUBS(s, "IT_ABS", "'ABS'");
    _SUBS(s, "IT_UCASE", "'UCASE'");
    _SUBS(s, "IT_STRENDS", "'STRENDS'");
    _SUBS(s, "IT_STRLEN", "'STRLEN'");
    _SUBS(s, "IT_SHA1", "'SHA1'");
    _SUBS(s, "IT_MONTH", "'MONTH'");
    _SUBS(s, "IT_PRINT", "'PRINT'");

    _SUBS(s, "VAR1", "?VAR");
    _SUBS(s, "VAR2", "$VAR");
    _SUBS(s, "NIL", "'()'");
    driver.error(l, s);
}

/* START Driver (@@ stand-alone would allow it to be shared with other parsers */

namespace w3c_sw {

size_t SPARQLDriver::DefaultAbortErrorCount = 100;

    SPARQLDriver::e_Validation SPARQLDriver::DefaultValidation = SPARQLDriver::VALIDATE_all;

Operation* SPARQLDriver::parse (IStreamContext& in)
{
    reset();
    root = NULL;
    curBGP = NULL;
    curOp = NULL;
    bnode2bgp.clear();
    bnodesInOldOpperations.clear();
    bnodesInThisOpperation.clear();
    inINSERTQUAD   = false;
    inINSERTDATA   = false;
    inDELETEDATA   = false;
    inDELETEWHERE  = false;
    inDELETECLAUSE = false;
    curGraphName = NULL;
    streamname = in.nameStr;
    // clear prefixes for nth run but keep them around for e.g. serialization.
    clearPrefixes();

    SPARQLScanner scanner(this, in.p);
    scanner.set_debug(trace_scanning);
    lexer = &scanner;

    SPARQLParser parser(*this);
    parser.set_debug_level(trace_parsing);
    // !!! Clear out namespaces!
    ignorePrefixFlag = false;
    parser.parse();
    bnode2bgp.clear();
    bnodesInOldOpperations.clear();
    bnodesInThisOpperation.clear();
    checkErrors();
    return root;
}

Operation* SPARQLDriver::parse (std::string queryStr)
{
    IStreamContext in(queryStr.c_str(), IStreamContext::STRING);
    return parse(in);
}

void SPARQLDriver::executeSelect (IStreamContext& in, RdfDB* db, ResultSet* rs) {
    parse(in);
    root->execute(db, rs);
    delete root;
    root = NULL;
}
void SPARQLDriver::executeSelect (std::string queryStr, RdfDB* db, ResultSet* rs) {
    parse(queryStr);
    root->execute(db, rs);
    delete root;
    root = NULL;
}


} // namespace w3c_sw

/* END Driver */

