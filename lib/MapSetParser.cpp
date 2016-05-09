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

#line 39 "lib/MapSetParser.cpp" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "MapSetParser.hpp"

// User implementation prologue.
#line 305 "lib/MapSetParser.ypp" // lalr1.cc:412

#include "MapSetScanner.hpp"
#line 445 "lib/MapSetParser.ypp" // lalr1.cc:412

#include "MapSetScanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lexWrapper

#line 65 "lib/MapSetParser.cpp" // lalr1.cc:412


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
#line 151 "lib/MapSetParser.cpp" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  MapSetParser::yytnamerr_ (const char *yystr)
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
  MapSetParser::MapSetParser (class MapSetDriver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

  MapSetParser::~MapSetParser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  MapSetParser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  MapSetParser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  MapSetParser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    value = other.value;
  }


  template <typename Base>
  inline
  MapSetParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  MapSetParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  inline
  MapSetParser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  MapSetParser::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  MapSetParser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  MapSetParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  inline
  MapSetParser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  MapSetParser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  MapSetParser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  MapSetParser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  MapSetParser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  MapSetParser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  MapSetParser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  MapSetParser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  MapSetParser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  MapSetParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  MapSetParser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  MapSetParser::symbol_number_type
  MapSetParser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  MapSetParser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  MapSetParser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    value = that.value;
    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  MapSetParser::stack_symbol_type&
  MapSetParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  MapSetParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  MapSetParser::yy_print_ (std::ostream& yyo,
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
  MapSetParser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  MapSetParser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  MapSetParser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  MapSetParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  MapSetParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  MapSetParser::debug_level_type
  MapSetParser::debug_level () const
  {
    return yydebug_;
  }

  void
  MapSetParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline MapSetParser::state_type
  MapSetParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  MapSetParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  MapSetParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  MapSetParser::parse ()
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
    #line 45 "lib/MapSetParser.ypp" // lalr1.cc:741
{
    // initialize the initial location object
    yyla.location.begin.filename = yyla.location.end.filename = &driver.streamname;
    driver.yylloc = &yyla.location;
}

#line 531 "lib/MapSetParser.cpp" // lalr1.cc:741

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
#line 460 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.root = new MapSet();
	driver.root->sharedVars = MapSet::e_PROMISCUOUS;
      }
#line 644 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 8:
#line 478 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
#if REGEX_LIB == SWOb_DISABLED
      throw std::string("not compiled with REGEX_LIB: can't map ") + (yystack_[2].value.p_Variable)->toString() + " from " + (yystack_[1].value.p_RDFLiteral)->toString() + " to " + (yystack_[0].value.p_RDFLiteral)->toString() + ".";
#else /* ! REGEX_LIB == SWOb_DISABLED */
#if NotYet // @@
      driver.root->rewriteVars.push_back(POSmap((yystack_[2].value.p_Variable), (yystack_[1].value.p_RDFLiteral)->getLexicalValue(), (yystack_[0].value.p_RDFLiteral)->getLexicalValue()));
#endif /* NotYet */
#endif /* ! REGEX_LIB == SWOb_DISABLED */
    }
#line 658 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 9:
#line 487 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	static_cast<MapSet*>(driver.root)->driver = (yystack_[0].value.p_RDFLiteral);
    }
#line 666 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 10:
#line 490 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	static_cast<MapSet*>(driver.root)->server = (yystack_[0].value.p_RDFLiteral);
    }
#line 674 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 11:
#line 493 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	static_cast<MapSet*>(driver.root)->user = (yystack_[0].value.p_RDFLiteral);
    }
#line 682 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 12:
#line 496 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	static_cast<MapSet*>(driver.root)->password = (yystack_[0].value.p_RDFLiteral);
    }
#line 690 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 13:
#line 499 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	static_cast<MapSet*>(driver.root)->database = (yystack_[0].value.p_RDFLiteral);
    }
#line 698 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 14:
#line 502 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	static_cast<MapSet*>(driver.root)->stemURI = (yystack_[0].value.p_URI);
    }
#line 706 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 16:
#line 507 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.sharedVarsSet = true;
    }
#line 714 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 17:
#line 511 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.lastRuleTermSet = false;
    }
#line 722 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 18:
#line 517 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.root->sharedVars = MapSet::e_PROMISCUOUS;
    }
#line 730 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 19:
#line 520 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.root->sharedVars = MapSet::e_VARNAMES;
    }
#line 738 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 20:
#line 523 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.root->sharedVars = MapSet::e_DRACONIAN;
    }
#line 746 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 21:
#line 529 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = NULL;
    }
#line 754 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 23:
#line 536 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	RuleTerm nextRuleTerm = RuleTerm((yystack_[2].value.p_TTerm), (yystack_[0].value.p_TTerm));
	if (driver.lastRuleTermSet)
	    static_cast<MapSet*>(driver.root)->nodeShare.addIntersection(driver.lastRuleTerm, nextRuleTerm);
	driver.lastRuleTerm = nextRuleTerm;
	driver.lastRuleTermSet = true;
	if (!driver.sharedVarsSet)
	    driver.root->sharedVars = MapSet::e_DRACONIAN;
    }
#line 768 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 32:
#line 571 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	static_cast<MapSet*>(driver.root)->keyMap[(yystack_[2].value.p_RDFLiteral)->getLexicalValue()] = (yystack_[0].value.p_RDFLiteral)->getLexicalValue();
    }
#line 776 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 35:
#line 582 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	static_cast<MapSet*>(driver.root)->primaryKey = (yystack_[1].value.p_RDFLiteral);
    }
#line 784 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 41:
#line 605 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.setBase((yystack_[0].value.p_URI)->getLexicalValue());
    }
#line 792 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 42:
#line 611 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.ignorePrefix(true);
      }
#line 800 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 43:
#line 613 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	  driver.ignorePrefix(false);
      }
#line 808 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 44:
#line 615 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	  std::string prefix((yystack_[2].value.p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yystack_[0].value.p_URI));
      }
#line 817 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 45:
#line 623 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
#line 826 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 46:
#line 626 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
#line 835 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 47:
#line 629 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.restoreFilter(NULL);
	(yylhs.value.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
#line 845 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 48:
#line 633 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	  if ((yystack_[0].value.p_ValuesClause) != NULL)
	      (yystack_[2].value.p_WhereClause)->m_GroupGraphPattern = driver.makeConjunction((yystack_[0].value.p_ValuesClause), (yystack_[2].value.p_WhereClause)->m_GroupGraphPattern);
	  driver.curOp = driver.makeConjunction((yystack_[3].value.p_TableOperation), new SubSelect(new Select((yystack_[4].value.p_Project).distinctness, (yystack_[4].value.p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yystack_[2].value.p_WhereClause), (yystack_[1].value.p_SolutionModifier))));
	  driver.curGraphName = (yystack_[5].value.p_TTerm);
	  driver.countStar = (yystack_[6].value.p_parentCountStar);
      }
#line 857 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 49:
#line 644 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Project).distinctness = (yystack_[1].value.p_distinctness);
	(yylhs.value.p_Project).varSet = (yystack_[0].value.p_VarSet);
    }
#line 866 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 50:
#line 652 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_distinctness) = DIST_distinct;
    }
#line 874 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 51:
#line 655 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_distinctness) = DIST_reduced;
    }
#line 882 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 52:
#line 662 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_distinctness) = DIST_all;
    }
#line 890 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 54:
#line 670 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Variable) = (yystack_[0].value.p_Variable);
    }
#line 898 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 55:
#line 677 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Variable) = NULL;
    }
#line 906 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 57:
#line 685 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ExpressionAlias) = (yystack_[1].value.p_Variable) ? new ExpressionAlias((yystack_[2].value.p_Expression), (yystack_[1].value.p_Variable)) : new ExpressionAlias((yystack_[2].value.p_Expression));
    }
#line 914 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 58:
#line 692 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ExpressionAlias) = new ExpressionAlias((yystack_[0].value.p_Expression));
    }
#line 922 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 59:
#line 695 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yystack_[0].value.p_RDFLiteral)));
    }
#line 930 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 60:
#line 698 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yystack_[0].value.p_NumericRDFLiteral)));
    }
#line 938 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 61:
#line 701 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yystack_[0].value.p_BooleanRDFLiteral)));
    }
#line 946 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 62:
#line 704 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yystack_[0].value.p_Variable)));
    }
#line 954 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 63:
#line 707 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ExpressionAlias) = new ExpressionAlias((yystack_[0].value.p_Expression));
    }
#line 962 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 64:
#line 710 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ExpressionAlias) = new ExpressionAlias((yystack_[0].value.p_Expression));
    }
#line 970 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 66:
#line 719 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ExpressionAliaseList) = new ExpressionAliasList((yystack_[0].value.p_ExpressionAlias));
    }
#line 978 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 67:
#line 722 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
    (yystack_[1].value.p_ExpressionAliaseList)->push_back((yystack_[0].value.p_ExpressionAlias));
    (yylhs.value.p_ExpressionAliaseList) = (yystack_[1].value.p_ExpressionAliaseList);
}
#line 987 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 68:
#line 730 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_VarSet) = (yystack_[0].value.p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
#line 995 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 69:
#line 733 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_VarSet) = new StarVarSet();
    }
#line 1003 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 70:
#line 740 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.curOp = NULL;
      }
#line 1011 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 71:
#line 742 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	/* $3 is NO LONGER known to be a DefaultGraphPattern because of grammar restrictions. */
	if ((yystack_[0].value.p_ValuesClause) != NULL)
	    (yystack_[2].value.p_WhereClause)->m_GroupGraphPattern = driver.makeConjunction((yystack_[0].value.p_ValuesClause), (yystack_[2].value.p_WhereClause)->m_GroupGraphPattern);
	Construct* constr = new Construct((yystack_[5].value.p_TableOperation), (yystack_[3].value.p_DatasetClauses), (yystack_[2].value.p_WhereClause), (yystack_[1].value.p_SolutionModifier));
	driver.root->maps.push_back(LabeledConstruct((yystack_[7].value.p_TTerm), constr));
    }
#line 1023 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 72:
#line 752 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_TTerm);
    }
#line 1031 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 73:
#line 758 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = NULL;
    }
#line 1039 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 75:
#line 766 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
#line 1047 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 76:
#line 769 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yystack_[1].value.p_DatasetClauses)->push_back((yystack_[0].value.p_DatasetClause));
	(yylhs.value.p_DatasetClauses) = (yystack_[1].value.p_DatasetClauses);
    }
#line 1056 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 77:
#line 777 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_DatasetClause) = (yystack_[0].value.p_DatasetClause);
    }
#line 1064 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 80:
#line 789 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_DatasetClause) = new DefaultGraphClause((yystack_[0].value.p_TTerm), driver.atomFactory);
    }
#line 1072 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 81:
#line 795 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_DatasetClause) = new NamedGraphClause((yystack_[0].value.p_TTerm), driver.atomFactory);
    }
#line 1080 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 82:
#line 801 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_URI);
    }
#line 1088 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 83:
#line 808 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.restoreFilter(NULL);
	(yylhs.value.p_WhereClause) = new WhereClause(driver.ensureGraphPattern());
	driver.curOp = NULL;
    }
#line 1098 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 86:
#line 822 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_SolutionModifier) = new SolutionModifier((yystack_[3].value.p_ExpressionAliaseList), (yystack_[2].value.p_Expressions), (yystack_[1].value.p_OrderConditions), (yystack_[0].value.p_LimitOffsetPair).limit, (yystack_[0].value.p_LimitOffsetPair).offset); // !!!
    }
#line 1106 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 87:
#line 829 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
#line 1114 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 89:
#line 837 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expressions) = NULL;
    }
#line 1122 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 91:
#line 845 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_OrderConditions) = NULL;
    }
#line 1130 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 93:
#line 853 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_LimitOffsetPair).limit = LIMIT_None;
	(yylhs.value.p_LimitOffsetPair).offset = OFFSET_None;
    }
#line 1139 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 95:
#line 861 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ExpressionAliaseList) = (yystack_[0].value.p_ExpressionAliaseList);
    }
#line 1147 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 96:
#line 868 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ExpressionAliaseList) = new ExpressionAliasList((yystack_[0].value.p_ExpressionAlias));
    }
#line 1155 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 97:
#line 871 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yystack_[1].value.p_ExpressionAliaseList)->push_back((yystack_[0].value.p_ExpressionAlias));
	(yylhs.value.p_ExpressionAliaseList) = (yystack_[1].value.p_ExpressionAliaseList);
    }
#line 1164 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 98:
#line 878 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ExpressionAlias) = new ExpressionAlias((yystack_[0].value.p_Expression));
    }
#line 1172 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 99:
#line 881 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ExpressionAlias) = new ExpressionAlias((yystack_[0].value.p_Expression));
    }
#line 1180 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 100:
#line 884 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ExpressionAlias) = (yystack_[1].value.p_Variable) ? new ExpressionAlias((yystack_[2].value.p_Expression), (yystack_[1].value.p_Variable)) : new ExpressionAlias((yystack_[2].value.p_Expression));
    }
#line 1188 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 101:
#line 887 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yystack_[0].value.p_Variable)));
    }
#line 1196 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 102:
#line 893 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expressions) = (yystack_[0].value.p_Expressions);
}
#line 1204 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 103:
#line 899 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expressions) = new ProductionVector<const Expression*>((yystack_[0].value.p_Expression));
    }
#line 1212 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 104:
#line 902 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yystack_[1].value.p_Expressions)->push_back((yystack_[0].value.p_Expression));
	(yylhs.value.p_Expressions) = (yystack_[1].value.p_Expressions);
    }
#line 1221 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 106:
#line 914 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_OrderConditions) = (yystack_[0].value.p_OrderConditions);
    }
#line 1229 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 107:
#line 921 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yylhs.value.p_OrderConditions)->push_back((yystack_[0].value.p_OrderConditionPair));
    }
#line 1238 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 108:
#line 925 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yystack_[1].value.p_OrderConditions)->push_back((yystack_[0].value.p_OrderConditionPair));
	(yylhs.value.p_OrderConditions) = (yystack_[1].value.p_OrderConditions);
    }
#line 1247 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 110:
#line 935 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yylhs.value.p_OrderConditionPair).expression = (yystack_[0].value.p_Expression);
    }
#line 1256 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 111:
#line 943 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_e_ASCorDESC) = ORDER_Asc;
    }
#line 1264 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 112:
#line 946 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_e_ASCorDESC) = ORDER_Desc;
    }
#line 1272 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 113:
#line 954 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_OrderConditionPair).ascOrDesc = (yystack_[1].value.p_e_ASCorDESC);
	(yylhs.value.p_OrderConditionPair).expression = (yystack_[0].value.p_Expression);
    }
#line 1281 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 115:
#line 963 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new TTermExpression((yystack_[0].value.p_Variable));
    }
#line 1289 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 116:
#line 970 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_LimitOffsetPair).limit = (yystack_[1].value.p_LimitOffsetPair).limit;
	(yylhs.value.p_LimitOffsetPair).offset = (yystack_[0].value.p_LimitOffsetPair).offset;
    }
#line 1298 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 117:
#line 974 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_LimitOffsetPair).limit = (yystack_[0].value.p_LimitOffsetPair).limit;
	(yylhs.value.p_LimitOffsetPair).offset = (yystack_[1].value.p_LimitOffsetPair).offset;
    }
#line 1307 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 118:
#line 982 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_LimitOffsetPair).offset = OFFSET_None;
    }
#line 1315 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 120:
#line 990 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_LimitOffsetPair).limit = LIMIT_None;
    }
#line 1323 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 122:
#line 997 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yystack_[0].value.p_NumericRDFLiteral))->getValue();
    }
#line 1331 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 123:
#line 1003 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yystack_[0].value.p_NumericRDFLiteral))->getValue();
    }
#line 1339 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 125:
#line 1013 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ValuesClause) = (yystack_[0].value.p_ValuesClause);
    }
#line 1347 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 126:
#line 1019 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ValuesClause) = NULL;
    }
#line 1355 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 128:
#line 1026 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Silence) = SILENT_No;
    }
#line 1363 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 129:
#line 1029 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Silence) = SILENT_Yes;
}
#line 1371 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 130:
#line 1035 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TableOperation) = (yystack_[1].value.p_TableOperation);
    }
#line 1379 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 131:
#line 1041 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.curBGP = NULL;
      }
#line 1387 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 132:
#line 1043 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_TableOperation) = driver.ensureGraphPattern();
	  driver.curOp = NULL;
      }
#line 1396 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 140:
#line 1071 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.restoreFilter(NULL);
	(yylhs.value.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
	driver.curFilter = NULL;
      }
#line 1407 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 141:
#line 1076 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yystack_[0].value.p_TTerm);
      }
#line 1416 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 142:
#line 1079 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
#line 1425 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 143:
#line 1082 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	  driver.curBGP = NULL;
	  driver.curOp = driver.makeConjunction((yystack_[7].value.p_TableOperation), new GraphGraphPattern((yystack_[5].value.p_TTerm), driver.curOp));
	  driver.curGraphName = (yystack_[4].value.p_TTerm);
      }
#line 1435 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 148:
#line 1104 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.curBGP = NULL;
      }
#line 1443 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 149:
#line 1106 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
#line 1453 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 169:
#line 1183 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, (yystack_[0].value.p_ValuesClause)) : (yystack_[0].value.p_ValuesClause);
    }
#line 1461 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 170:
#line 1189 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.restoreFilter(NULL);
	(yylhs.value.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
#line 1471 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 171:
#line 1193 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	  OptionalGraphPattern* ret = new OptionalGraphPattern(driver.ensureGraphPattern());
	  if (driver.curFilter) {
	      driver.curFilter->copyExpressionsTo(ret);
	      delete driver.curFilter;
	      driver.curFilter = NULL;
	  }
	  driver.curOp = driver.makeConjunction((yystack_[1].value.p_TableOperation), ret);
      }
#line 1485 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 172:
#line 1205 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.restoreFilter(NULL);
	(yylhs.value.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
#line 1495 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 173:
#line 1209 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_FilterExpressions) = driver.saveFilter();
      }
#line 1503 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 174:
#line 1211 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yystack_[0].value.p_TTerm);
      }
#line 1512 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 175:
#line 1214 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	  driver.restoreFilter((yystack_[3].value.p_FilterExpressions));
	  driver.curOp = driver.makeConjunction((yystack_[4].value.p_TableOperation), new GraphGraphPattern((yystack_[2].value.p_TTerm), driver.curOp));
	  driver.curGraphName = (yystack_[1].value.p_TTerm);
      }
#line 1522 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 176:
#line 1222 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.restoreFilter(NULL);
	(yylhs.value.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
#line 1532 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 177:
#line 1226 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_FilterExpressions) = driver.saveFilter();
      }
#line 1540 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 178:
#line 1228 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
#line 1549 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 179:
#line 1231 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	  driver.restoreFilter((yystack_[4].value.p_FilterExpressions));
	  driver.curOp = driver.makeConjunction((yystack_[5].value.p_TableOperation), new ServiceGraphPattern((yystack_[1].value.p_TTerm), driver.curOp, (yystack_[2].value.p_Silence), driver.atomFactory, false));
	  driver.curGraphName = (yystack_[3].value.p_TTerm);
      }
#line 1559 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 180:
#line 1239 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.curOp = new Bind(driver.ensureGraphPattern(), (yystack_[3].value.p_Expression), (yystack_[1].value.p_Variable));
	// no more triples go into the current BGP, per
	//   http://www.w3.org/TR/sparql11-query/#sparqlTranslateGraphPatterns
	// test reference:
	//   http://www.sparql.org/query-validator?query=ASK+{+%3Fs+%3Fp+%3Fo+FILTER+%281%29+BIND+%282+AS+%3Fb%29+%3Fs2+%3Fp2+%3Fo2+FILTER+%283%29+BIND+%284+AS+%3Fd%29}&languageSyntax=SPARQL&outputFormat=algebra&linenumbers=false
	driver.curBGP = NULL;
    }
#line 1572 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 181:
#line 1250 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ValuesClause) = (yystack_[0].value.p_ValuesClause);
    }
#line 1580 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 184:
#line 1261 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.startBindingSet();
      }
#line 1588 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 185:
#line 1263 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	  driver.addBindingVar((yystack_[0].value.p_Variable));
      }
#line 1596 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 186:
#line 1265 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_ValuesClause) = new ValuesClause(driver.endBindingSet());
      }
#line 1604 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 189:
#line 1276 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.startBindingRow();
	driver.addBindingValue((yystack_[0].value.p_TTerm));
	driver.endBindingRow();
    }
#line 1614 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 190:
#line 1284 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.startBindingSet();
    }
#line 1622 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 191:
#line 1286 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_ValuesClause) = new ValuesClause(driver.endBindingSet());
      }
#line 1630 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 193:
#line 1293 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.addBindingVar((yystack_[0].value.p_Variable));
    }
#line 1638 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 197:
#line 1305 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.addBindingValue((yystack_[0].value.p_TTerm));
    }
#line 1646 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 198:
#line 1311 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.startBindingRow();
      }
#line 1654 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 199:
#line 1313 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	  driver.endBindingRow();
      }
#line 1662 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 200:
#line 1316 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.startBindingRow();
	driver.endBindingRow();
    }
#line 1671 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 203:
#line 1328 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_URI);
    }
#line 1679 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 204:
#line 1331 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_RDFLiteral);
    }
#line 1687 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 205:
#line 1334 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_NumericRDFLiteral);
    }
#line 1695 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 206:
#line 1337 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_BooleanRDFLiteral);
    }
#line 1703 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 207:
#line 1340 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = TTerm::Unbound;
    }
#line 1711 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 208:
#line 1343 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = TTerm::Unbound;
    }
#line 1719 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 209:
#line 1346 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_Variable);
    }
#line 1727 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 210:
#line 1352 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.restoreFilter(NULL);
	(yylhs.value.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
#line 1737 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 211:
#line 1356 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_FilterExpressions) = driver.saveFilter();
      }
#line 1745 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 212:
#line 1358 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	  driver.restoreFilter((yystack_[1].value.p_FilterExpressions));
	  driver.curOp = driver.makeConjunction((yystack_[2].value.p_TableOperation), new MinusGraphPattern(driver.ensureGraphPattern()));
      }
#line 1754 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 213:
#line 1366 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.restoreFilter(NULL);
	(yylhs.value.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
#line 1764 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 214:
#line 1370 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_FilterExpressions) = driver.saveFilter();
      }
#line 1772 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 215:
#line 1372 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	  driver.restoreFilter((yystack_[2].value.p_FilterExpressions));
	  driver.curOp = driver.makeConjunction((yystack_[3].value.p_TableOperation), driver.curOp);
      }
#line 1781 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 216:
#line 1380 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.ensureGraphPattern();
	driver.restoreFilter(NULL);
	(yylhs.value.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
#line 1792 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 217:
#line 1385 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yystack_[1].value.p_TableOperation), driver.ensureGraphPattern());
      }
#line 1801 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 220:
#line 1398 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	if (driver.curFilter == NULL) {
	    driver.ensureGraphPattern();
	    driver.curFilter = new FilterExpressions();
	}
	driver.curFilter->addExpression((yystack_[0].value.p_Expression));
    }
#line 1813 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 224:
#line 1414 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall((yystack_[1].value.p_URI), (yystack_[0].value.p_ArgList)));
    }
#line 1821 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 225:
#line 1422 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ArgList) = NULL;
    }
#line 1829 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 226:
#line 1426 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yystack_[0].value.p_Expression));
      }
#line 1838 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 227:
#line 1429 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = (yystack_[2].value.p_Expressions);
      }
#line 1847 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 228:
#line 1436 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_distinctness) = DIST_all;
    }
#line 1855 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 229:
#line 1439 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_distinctness) = DIST_distinct;
    }
#line 1863 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 230:
#line 1446 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = (yystack_[0].value.p_Expression);
    }
#line 1871 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 232:
#line 1454 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.curExprList->push_back((yystack_[0].value.p_Expression));
    }
#line 1879 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 233:
#line 1468 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expressions) = new ProductionVector<const Expression*>();
    }
#line 1887 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 234:
#line 1471 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yystack_[0].value.p_Expression));
      }
#line 1896 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 235:
#line 1474 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_Expressions) = driver.curExprList;
	  driver.curExprList = (yystack_[2].value.p_Expressions);
      }
#line 1905 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 236:
#line 1481 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.curSubject = (yystack_[0].value.p_TTerm);
    }
#line 1913 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 238:
#line 1484 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.curSubject = (yystack_[0].value.p_TTerm);
    }
#line 1921 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 250:
#line 1528 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_TTerm);
	driver.curPredicate = (yylhs.value.p_TTerm);
    }
#line 1930 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 251:
#line 1532 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yylhs.value.p_TTerm);
    }
#line 1939 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 256:
#line 1555 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yystack_[0].value.p_TTerm)), true);
    }
#line 1948 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 257:
#line 1563 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.curSubject = (yystack_[0].value.p_TTerm);
      }
#line 1956 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 259:
#line 1566 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.curSubject = (yystack_[0].value.p_TTerm);
      }
#line 1964 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 261:
#line 1572 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.curPredicate = (yystack_[0].value.p_TTerm);
      }
#line 1972 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 265:
#line 1583 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.curPredicate = (yystack_[0].value.p_TTerm);
      }
#line 1980 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 274:
#line 1611 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_Variable);
    }
#line 1988 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 281:
#line 1638 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	w3c_sw_NEED_IMPL("@@@");
    }
#line 1996 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 283:
#line 1645 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	w3c_sw_NEED_IMPL("@@@");
    }
#line 2004 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 286:
#line 1656 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	w3c_sw_NEED_IMPL("@@@");
    }
#line 2012 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 288:
#line 1663 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	w3c_sw_NEED_IMPL("@@@");
    }
#line 2020 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 301:
#line 1699 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_URI);
    }
#line 2028 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 302:
#line 1702 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
#line 2036 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 303:
#line 1705 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	w3c_sw_NEED_IMPL("@@@");
    }
#line 2044 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 304:
#line 1708 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	w3c_sw_NEED_IMPL("@@@");
    }
#line 2052 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 323:
#line 1766 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_SubjectPredicatePair).subject = driver.curSubject;
	(yylhs.value.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
#line 2062 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 324:
#line 1770 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yystack_[2].value.p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yystack_[2].value.p_SubjectPredicatePair).predicate;
      }
#line 2072 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 325:
#line 1779 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	if ((yystack_[3].value.p_listModifier) == LIST_exact) {
	    (yylhs.value.p_TTerm) = driver.createBNode();
	    const TTerm* tail = (yylhs.value.p_TTerm);
	    ProductionVector<const TTerm*>* members = (yystack_[1].value.p_TTerms);
	    const URI* first = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#first");
	    const URI* rest = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#rest");
	    const TTerm* nil = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil");
	    driver.ensureBasicGraphPattern();
	    for (unsigned i = 0; i < members->size(); i++) {
		driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(tail, first, members->at(i)), true);
		const TTerm* nextTail = i == members->size()-1 ? nil : driver.createBNode();
		driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(tail, rest, nextTail), true);
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
#line 2100 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 326:
#line 1806 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_listModifier) = LIST_members;
    }
#line 2108 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 327:
#line 1809 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_listModifier) = LIST_starts;
    }
#line 2116 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 328:
#line 1812 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_listModifier) = LIST_ends;
    }
#line 2124 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 329:
#line 1815 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_listModifier) = LIST_any;
    }
#line 2132 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 330:
#line 1818 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_listModifier) = LIST_unordered;
    }
#line 2140 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 331:
#line 1825 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_listModifier) = LIST_exact;
    }
#line 2148 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 333:
#line 1833 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerms) = new ProductionVector<const TTerm*>();
	(yylhs.value.p_TTerms)->push_back((yystack_[0].value.p_TTerm));
    }
#line 2157 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 334:
#line 1837 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yystack_[1].value.p_TTerms)->push_back((yystack_[0].value.p_TTerm));
	(yylhs.value.p_TTerms) = (yystack_[1].value.p_TTerms);
    }
#line 2166 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 337:
#line 1849 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_Variable);
    }
#line 2174 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 339:
#line 1856 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_Variable);
    }
#line 2182 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 340:
#line 1859 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_URI);
    }
#line 2190 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 343:
#line 1870 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_URI);
    }
#line 2198 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 344:
#line 1873 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_RDFLiteral);
    }
#line 2206 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 345:
#line 1876 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_NumericRDFLiteral);
    }
#line 2214 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 346:
#line 1879 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = (yystack_[0].value.p_BooleanRDFLiteral);
    }
#line 2222 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 348:
#line 1883 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
#line 2230 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 350:
#line 1894 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = (yystack_[0].value.p_Expressions)->size() > 0 ? new BooleanDisjunction((yystack_[1].value.p_Expression), (yystack_[0].value.p_Expressions)) : (yystack_[1].value.p_Expression);
	(yystack_[0].value.p_Expressions)->clear();
	delete (yystack_[0].value.p_Expressions);
    }
#line 2240 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 351:
#line 1903 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = (yystack_[0].value.p_Expression);
    }
#line 2248 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 352:
#line 1910 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expressions) = new ProductionVector<const Expression*>();
    }
#line 2256 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 353:
#line 1913 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yystack_[1].value.p_Expressions)->push_back((yystack_[0].value.p_Expression));
	(yylhs.value.p_Expressions) = (yystack_[1].value.p_Expressions);
    }
#line 2265 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 354:
#line 1921 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = (yystack_[0].value.p_Expressions)->size() > 0 ? new BooleanConjunction((yystack_[1].value.p_Expression), (yystack_[0].value.p_Expressions)) : (yystack_[1].value.p_Expression);
	(yystack_[0].value.p_Expressions)->clear();
	delete (yystack_[0].value.p_Expressions);
    }
#line 2275 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 355:
#line 1930 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = (yystack_[0].value.p_Expression);
    }
#line 2283 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 356:
#line 1937 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expressions) = new ProductionVector<const Expression*>();
    }
#line 2291 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 357:
#line 1940 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yystack_[1].value.p_Expressions)->push_back((yystack_[0].value.p_Expression));
	(yylhs.value.p_Expressions) = (yystack_[1].value.p_Expressions);
    }
#line 2300 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 359:
#line 1952 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	if ((yystack_[0].value.p_ComparatorSense).comp) {
	    (yystack_[0].value.p_ComparatorSense).comp->setLeftParm((yystack_[1].value.p_Expression));
	    (yylhs.value.p_Expression) = new ComparatorExpression((yystack_[0].value.p_ComparatorSense).comp); // !!!
	    if ((yystack_[0].value.p_ComparatorSense).neg)
		(yylhs.value.p_Expression) = new BooleanNegation((yylhs.value.p_Expression));
	} else
	    (yylhs.value.p_Expression) = (yystack_[1].value.p_Expression);
    }
#line 2314 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 360:
#line 1965 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ComparatorSense).neg = false;
	(yylhs.value.p_ComparatorSense).comp = NULL;
    }
#line 2323 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 362:
#line 1973 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ComparatorSense).neg = false;
	(yylhs.value.p_ComparatorSense).comp = new BooleanEQ((yystack_[0].value.p_Expression));
    }
#line 2332 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 363:
#line 1977 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ComparatorSense).neg = false;
	(yylhs.value.p_ComparatorSense).comp = new BooleanNE((yystack_[0].value.p_Expression));
    }
#line 2341 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 364:
#line 1981 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ComparatorSense).neg = false;
	(yylhs.value.p_ComparatorSense).comp = new BooleanLT((yystack_[0].value.p_Expression));
    }
#line 2350 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 365:
#line 1985 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ComparatorSense).neg = false;
	(yylhs.value.p_ComparatorSense).comp = new BooleanGT((yystack_[0].value.p_Expression));
    }
#line 2359 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 366:
#line 1989 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ComparatorSense).neg = false;
	(yylhs.value.p_ComparatorSense).comp = new BooleanLE((yystack_[0].value.p_Expression));
    }
#line 2368 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 367:
#line 1993 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ComparatorSense).neg = false;
	(yylhs.value.p_ComparatorSense).comp = new BooleanGE((yystack_[0].value.p_Expression));
    }
#line 2377 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 368:
#line 1997 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ComparatorSense).neg = false;
	(yylhs.value.p_ComparatorSense).comp = new NaryIn((yystack_[0].value.p_Expressions));
    }
#line 2386 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 369:
#line 2001 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ComparatorSense).neg = true;
	(yylhs.value.p_ComparatorSense).comp = new NaryIn((yystack_[0].value.p_Expressions));
    }
#line 2395 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 371:
#line 2013 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = (yystack_[0].value.p_Expressions)->size() > 0 ? new ArithmeticSum((yystack_[1].value.p_Expression), (yystack_[0].value.p_Expressions)) : (yystack_[1].value.p_Expression);
	(yystack_[0].value.p_Expressions)->clear();
	delete (yystack_[0].value.p_Expressions);
    }
#line 2405 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 372:
#line 2022 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new NumberExpression((yystack_[0].value.p_NumericRDFLiteral));
    }
#line 2413 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 373:
#line 2025 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new NumberExpression((yystack_[0].value.p_NumericRDFLiteral));
    }
#line 2421 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 374:
#line 2032 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = (yystack_[0].value.p_Expression);
    }
#line 2429 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 375:
#line 2035 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new ArithmeticInverse((yystack_[0].value.p_Expression));
    }
#line 2437 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 376:
#line 2042 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = NULL;
    }
#line 2445 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 378:
#line 2050 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = (yystack_[0].value.p_Expression);
    }
#line 2453 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 379:
#line 2053 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new ArithmeticNegation((yystack_[0].value.p_Expression));
    }
#line 2461 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 380:
#line 2057 "lib/MapSetParser.ypp" // lalr1.cc:859
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
#line 2476 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 381:
#line 2071 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expressions) = new ProductionVector<const Expression*>();
    }
#line 2484 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 382:
#line 2074 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yystack_[1].value.p_Expressions)->push_back((yystack_[0].value.p_Expression));
	(yylhs.value.p_Expressions) = (yystack_[1].value.p_Expressions);
    }
#line 2493 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 383:
#line 2082 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = (yystack_[0].value.p_Expressions)->size() > 0 ? new ArithmeticProduct((yystack_[1].value.p_Expression), (yystack_[0].value.p_Expressions)) : (yystack_[1].value.p_Expression);
	(yystack_[0].value.p_Expressions)->clear();
	delete (yystack_[0].value.p_Expressions);
    }
#line 2503 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 384:
#line 2091 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expressions) = new ProductionVector<const Expression*>();
    }
#line 2511 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 385:
#line 2094 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yystack_[1].value.p_Expressions)->push_back((yystack_[0].value.p_Expression));
	(yylhs.value.p_Expressions) = (yystack_[1].value.p_Expressions);
    }
#line 2520 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 386:
#line 2101 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new BooleanNegation((yystack_[0].value.p_Expression));
    }
#line 2528 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 387:
#line 2104 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = (yystack_[0].value.p_Expression);
    }
#line 2536 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 388:
#line 2107 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new ArithmeticNegation((yystack_[0].value.p_Expression));
    }
#line 2544 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 393:
#line 2117 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new TTermExpression((yystack_[0].value.p_RDFLiteral));
    }
#line 2552 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 394:
#line 2120 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new TTermExpression((yystack_[0].value.p_NumericRDFLiteral));
    }
#line 2560 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 395:
#line 2123 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new TTermExpression((yystack_[0].value.p_BooleanRDFLiteral));
    }
#line 2568 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 396:
#line 2126 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new TTermExpression((yystack_[0].value.p_Variable));
    }
#line 2576 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 398:
#line 2133 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = (yystack_[1].value.p_Expression);
    }
#line 2584 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 399:
#line 2139 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2592 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 400:
#line 2142 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2600 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 401:
#line 2145 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yystack_[3].value.p_Expression), (yystack_[1].value.p_Expression), NULL));
    }
#line 2608 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 402:
#line 2148 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2616 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 403:
#line 2151 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yystack_[1].value.p_Variable)), NULL, NULL));
    }
#line 2624 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 404:
#line 2154 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2632 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 405:
#line 2157 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2640 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 406:
#line 2161 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yystack_[0].value.p_Expression), NULL, NULL));
    }
#line 2648 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 407:
#line 2164 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
#line 2656 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 408:
#line 2167 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2664 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 409:
#line 2170 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ceil, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2672 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 410:
#line 2173 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2680 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 411:
#line 2176 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2688 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 412:
#line 2179 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yystack_[0].value.p_Expressions))));
    }
#line 2696 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 414:
#line 2183 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2704 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 415:
#line 2186 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2712 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 416:
#line 2189 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2720 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 417:
#line 2192 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2728 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 418:
#line 2195 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yystack_[3].value.p_Expression), (yystack_[1].value.p_Expression), NULL));
    }
#line 2736 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 419:
#line 2198 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yystack_[3].value.p_Expression), (yystack_[1].value.p_Expression), NULL));
    }
#line 2744 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 420:
#line 2201 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yystack_[3].value.p_Expression), (yystack_[1].value.p_Expression), NULL));
    }
#line 2752 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 421:
#line 2204 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_before, (yystack_[3].value.p_Expression), (yystack_[1].value.p_Expression), NULL));
    }
#line 2760 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 422:
#line 2207 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_after, (yystack_[3].value.p_Expression), (yystack_[1].value.p_Expression), NULL));
    }
#line 2768 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 423:
#line 2210 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2776 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 424:
#line 2213 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2784 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 425:
#line 2216 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2792 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 426:
#line 2219 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2800 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 427:
#line 2222 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2808 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 428:
#line 2225 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2816 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 429:
#line 2228 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2824 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 430:
#line 2231 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2832 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 431:
#line 2234 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
#line 2840 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 432:
#line 2237 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_uuid, NULL, NULL, NULL));
    }
#line 2848 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 433:
#line 2240 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_struuid, NULL, NULL, NULL));
    }
#line 2856 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 434:
#line 2243 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2864 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 435:
#line 2246 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2872 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 436:
#line 2249 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2880 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 437:
#line 2252 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2888 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 438:
#line 2255 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2896 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 439:
#line 2258 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, new ArgList((yystack_[0].value.p_Expressions))));
    }
#line 2904 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 440:
#line 2261 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yystack_[5].value.p_Expression), (yystack_[3].value.p_Expression), (yystack_[1].value.p_Expression)));
    }
#line 2912 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 441:
#line 2264 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yystack_[3].value.p_Expression), (yystack_[1].value.p_Expression), NULL));
    }
#line 2920 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 442:
#line 2267 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yystack_[3].value.p_Expression), (yystack_[1].value.p_Expression), NULL));
    }
#line 2928 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 443:
#line 2270 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yystack_[3].value.p_Expression), (yystack_[1].value.p_Expression), NULL));
    }
#line 2936 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 444:
#line 2273 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2944 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 445:
#line 2276 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2952 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 446:
#line 2279 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2960 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 447:
#line 2282 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2968 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 448:
#line 2285 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yystack_[1].value.p_Expression), NULL, NULL));
    }
#line 2976 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 452:
#line 2296 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = (yystack_[1].value.p_Expression);
    }
#line 2984 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 453:
#line 2299 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = NULL;
    }
#line 2992 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 454:
#line 2306 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yystack_[4].value.p_Expression), (yystack_[2].value.p_Expression), (yystack_[1].value.p_Expression)));
    }
#line 3000 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 455:
#line 2313 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = NULL;
    }
#line 3008 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 457:
#line 2320 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yystack_[4].value.p_Expression), (yystack_[2].value.p_Expression), (yystack_[1].value.p_Expression)));
    }
#line 3016 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 458:
#line 2326 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
      }
#line 3025 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 459:
#line 2329 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	  driver.restoreFilter(NULL);
	  (yylhs.value.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
#line 3035 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 460:
#line 2333 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	  (yylhs.value.p_Expression) = new ExistsExpression(driver.ensureGraphPattern());
	  driver.curOp = (yystack_[1].value.p_TableOperation);
	  driver.countStar = (yystack_[2].value.p_parentCountStar);
      }
#line 3045 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 461:
#line 2341 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
      }
#line 3054 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 462:
#line 2344 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	  driver.restoreFilter(NULL);
	  (yylhs.value.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
#line 3064 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 463:
#line 2348 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	  // $$ = new ExistsExpression(false, driver.ensureGraphPattern());
	  (yylhs.value.p_Expression) = new BooleanNegation(new ExistsExpression(driver.ensureGraphPattern()));
	  driver.curOp = (yystack_[1].value.p_TableOperation);
	  driver.countStar = (yystack_[2].value.p_parentCountStar);
      }
#line 3075 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 464:
#line 2357 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.countStar = true;
	(yylhs.value.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yystack_[2].value.p_distinctness), (yystack_[1].value.p_Expression), AggregateCall::ScalarVals()));
    }
#line 3084 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 465:
#line 2361 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	driver.countStar = true;
	(yylhs.value.p_Expression) = new FunctionCallExpression(new AggregateCall((yystack_[4].value.p_URI), (yystack_[2].value.p_distinctness), (yystack_[1].value.p_Expression), AggregateCall::ScalarVals()));
    }
#line 3093 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 466:
#line 2366 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	  AggregateCall::ScalarVals svals;
	  if ((yystack_[1].value.p_RDFLiteral) != NULL)
	      svals["separator"] = (yystack_[1].value.p_RDFLiteral)->getLexicalValue();
	  (yylhs.value.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group_concat, (yystack_[3].value.p_distinctness), (yystack_[2].value.p_Expression), svals));
    }
#line 3104 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 467:
#line 2375 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_Expression) = NULL;
    }
#line 3112 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 469:
#line 2382 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_URI) = TTerm::FUNC_sum;
    }
#line 3120 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 470:
#line 2385 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_URI) = TTerm::FUNC_min;
    }
#line 3128 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 471:
#line 2388 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_URI) = TTerm::FUNC_max;
    }
#line 3136 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 472:
#line 2391 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_URI) = TTerm::FUNC_avg;
    }
#line 3144 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 473:
#line 2394 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_URI) = TTerm::FUNC_sample;
    }
#line 3152 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 474:
#line 2400 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_RDFLiteral) = driver.getRDFLiteral(*(yystack_[0].value.p_string), NULL, NULL);
    }
#line 3160 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 475:
#line 2406 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_RDFLiteral) = NULL;
    }
#line 3168 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 477:
#line 2413 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	if ((yystack_[0].value.p_ArgList))
	    (yylhs.value.p_Expression) = new FunctionCallExpression(new FunctionCall((yystack_[1].value.p_URI), (yystack_[0].value.p_ArgList)));
	else
	    (yylhs.value.p_Expression) = new TTermExpression((yystack_[1].value.p_URI));
    }
#line 3179 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 478:
#line 2423 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_ArgList) = NULL;
    }
#line 3187 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 480:
#line 2431 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_RDFLiteral) = driver.getRDFLiteral(*(yystack_[1].value.p_string), (yystack_[0].value.p_uri_or_langtag).uri, (yystack_[0].value.p_uri_or_langtag).langtag);
	delete (yystack_[1].value.p_string);
    }
#line 3196 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 481:
#line 2439 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_URI) = (yystack_[0].value.p_URI);
    }
#line 3204 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 482:
#line 2446 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_uri_or_langtag).uri = NULL;
	(yylhs.value.p_uri_or_langtag).langtag = (yystack_[0].value.p_LANGTAG);
    }
#line 3213 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 483:
#line 2450 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_uri_or_langtag).uri = (yystack_[0].value.p_URI);
	(yylhs.value.p_uri_or_langtag).langtag = NULL;
    }
#line 3222 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;

  case 484:
#line 2458 "lib/MapSetParser.ypp" // lalr1.cc:859
    {
	(yylhs.value.p_uri_or_langtag).uri = NULL;
	(yylhs.value.p_uri_or_langtag).langtag = NULL;
    }
#line 3231 "lib/MapSetParser.cpp" // lalr1.cc:859
    break;


#line 3235 "lib/MapSetParser.cpp" // lalr1.cc:859
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
  MapSetParser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  MapSetParser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
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


  const short int MapSetParser::yypact_ninf_ = -684;

  const short int MapSetParser::yytable_ninf_ = -332;

  const short int
  MapSetParser::yypact_[] =
  {
    -684,    56,    48,  -684,   -92,  -684,  -684,  -684,  -684,   408,
      59,   -59,   120,   120,   120,   120,   120,    50,    29,    95,
      47,    38,  -684,  -684,  -684,  -684,  -684,   120,  -684,  -684,
    -684,  -684,  -684,   -57,  -684,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,   120,  -684,    76,  -684,  -684,  -684,  -684,
    -684,   746,  -684,    47,   746,  -684,  -684,    75,   -41,   120,
      50,  -684,  -684,  -684,  -684,    78,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,    99,  -684,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,    96,  -684,  -684,  -684,  -684,
      62,  1252,  -684,  -684,   -19,  -684,  -684,    97,  -684,  -684,
    -684,   114,  1189,  -684,  -684,   120,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,   127,  -684,  -684,  -684,  -684,
     141,  -684,    17,  -684,    63,   170,  1189,  -684,  -684,    63,
    1282,    63,    -7,  -684,  -684,    94,   150,  -684,   153,  1282,
    -684,  -684,  -684,  -684,   159,   195,  -684,  -684,  -684,  -684,
    -684,  1228,  -684,  -684,  -684,    50,  -684,  -684,  -684,  -684,
    -684,   191,   197,   137,  -684,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  1189,   144,  -684,  -684,  -684,  1786,   -21,  -684,
    -684,  -684,  1893,   211,  -684,  1021,   188,   192,  -684,  -684,
    1411,   165,   203,   210,   -16,    -6,   213,   216,   217,  -684,
     219,   220,   224,   228,   230,   231,   232,   234,   236,   242,
     248,    -6,   252,   124,   125,   258,   259,   260,   261,   133,
     265,   139,   273,   275,   276,   277,   278,   282,   283,   284,
     286,   287,   288,   289,   291,   292,   293,   294,   296,   297,
     310,   311,   325,   326,  1786,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,    -5,  -684,  -684,   -59,  -684,     3,  1411,
    1893,  -684,  -684,  -684,  -684,  -684,   341,    88,  -684,  -684,
    -684,   332,  -684,  -684,  -684,   328,  -684,  -684,    63,  -684,
    1282,  -684,   336,  1536,  1536,  1536,   334,  -684,  -684,  -684,
    -684,   337,  -684,  -684,   290,  -684,  -684,  -684,  -684,   302,
    -684,  -684,  -684,  -684,  -684,  -684,  -684,   339,  -684,  -684,
    -684,  -684,    -5,  -684,  1411,  1411,  1411,  -684,  -684,  1411,
    -684,  -684,  1411,  1411,  1411,  -684,  1411,  1411,  1411,  1411,
     -59,  1411,  1411,  1411,  1411,  1411,  1411,  -684,  1411,  -684,
    -684,  1411,  1411,  1411,  1411,  -684,  1411,  -684,  1411,  1411,
    1411,  1411,  1411,  1411,  1411,  1411,  1411,  1411,  1411,  1411,
    1411,  1411,  1411,  1411,  1411,  1411,  1411,  1411,  1411,  1411,
    -684,   358,  -684,  -684,  -684,  -684,  -684,   344,   342,  -684,
    1165,   233,   241,  -684,  -684,   361,   364,   373,  -684,   221,
    1189,  -684,  -684,    63,   123,  -684,  -684,  1282,  -684,  -684,
    -684,  -684,  -684,   358,   358,   -59,  -684,   355,   343,   346,
    1411,  1411,  1411,  1411,  1411,  1411,   331,    -6,  -684,  -684,
     200,     1,   358,  -684,  -684,  -684,   362,   363,   365,  -684,
     350,   353,   369,   150,   378,   379,   372,   381,   383,   376,
     385,   386,   387,   388,   382,   389,   391,   384,   390,   393,
     394,   395,   396,   397,   403,   399,   404,   405,   410,   406,
     411,   415,   417,   414,   418,   423,   425,   426,   442,   436,
     445,   450,   452,  -684,  1411,   481,   -23,  -684,  -684,  -684,
    -684,  1165,  -684,   480,  -684,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,   110,  -684,  -684,  -684,   -21,  -684,
    -684,  1893,   482,  -684,   159,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,  -684,  -684,    15,  -684,    34,
      -3,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,
     182,  -684,  -684,  -684,  -684,  1189,   852,  1411,  -684,  -684,
    1411,  -684,  1411,  -684,  -684,  -684,  -684,  -684,  -684,  -684,
      -6,  -684,  1411,  1411,     1,  -684,  -684,  -684,  1411,  1411,
    -684,  1411,   150,  -684,  -684,  -684,  -684,  1411,  1411,  1411,
    -684,  -684,  -684,  1411,  -684,  -684,  1411,  -684,  -684,  -684,
    -684,  1411,  -684,  -684,  1411,  1411,  -684,  -684,  -684,  -684,
    -684,  -684,  1411,  -684,  -684,  -684,  1411,  -684,  -684,  -684,
    1411,  -684,  -684,  -684,  -684,  -684,  1411,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,   -12,  -684,  -684,  -684,  -684,  -684,
     997,   484,  -684,  -684,  -684,   150,  -684,  -684,  1411,  1189,
     150,   483,   -24,  -684,    31,  -684,  -684,  -684,  -684,  -684,
    -684,  1282,   424,   457,  -684,   -34,  -684,  -684,  -684,  -684,
    -684,   488,  -684,  -684,   487,   479,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,   490,  -684,     8,   491,   492,
     501,   502,   503,   497,   504,   506,   507,   497,   508,   509,
    -684,   496,  -684,  -684,  -684,  -684,  -684,  1411,  -684,  -684,
    1661,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,    94,
     144,  -684,  -684,   150,   447,  -684,  -684,  -684,  -684,   510,
    -684,  -684,  -684,  -684,  -684,    15,  -684,    15,  -684,   407,
    -684,  -684,     9,  -684,  -684,   476,  -684,   513,  -684,  -684,
    1411,  -684,  1411,  -684,  -684,  -684,  -684,  -684,   514,  -684,
    -684,  -684,   516,  -684,  -684,    20,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,  -684,  -684,   290,  -684,   197,
    -684,   543,  -684,   -59,   512,  -684,   459,   515,  -684,  -684,
     525,  -684,    -2,  -684,   511,  -684,  -684,   523,  -684,  -684,
    -684,   667,   527,  -684,   150,  -684,   144,   528,  -684,  -684,
     -24,  -684,   123,  -684,  -684,  -684,  -684,   532,   120,  -684,
    -684,  -684,  -684,  -684,   150,  -684,   150,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,  1282,  -684
  };

  const unsigned short int
  MapSetParser::yydefact_[] =
  {
       2,     0,    37,     1,     0,     4,    39,    38,    41,     6,
      36,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     3,     5,    42,    40,   341,   342,     0,   500,   502,
     501,   503,     9,   484,    10,    11,    12,    13,   504,   507,
     506,    14,   505,     0,    15,    29,    28,    18,    20,    19,
      16,    21,    24,    17,     0,     7,    74,     0,     0,     0,
       0,   482,   483,   485,   480,     0,    33,    26,    30,   498,
     499,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     508,   509,   348,     0,    22,   344,   345,   486,   487,   488,
     346,   343,   347,    25,    72,     0,    43,     8,   481,    35,
       0,     0,   131,    70,     0,    31,    34,     0,    23,   337,
     338,     0,   133,    75,    44,     0,   130,   326,   327,   328,
     329,   330,   323,   138,   134,   146,   238,   322,   321,   332,
       0,   236,    84,    32,     0,   132,   133,   147,   144,   248,
     331,     0,     0,    85,    76,    87,     0,   251,     0,   331,
     250,   339,   340,   139,   135,     0,   145,   249,   239,   247,
     336,   331,   333,   335,   237,     0,    77,    78,    79,    80,
      82,     0,   126,    89,    88,   148,    83,   324,   245,   254,
     256,   136,   133,     0,   325,   334,    81,     0,   184,    71,
     127,   124,     0,    91,    90,   153,   240,   252,   137,   141,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   458,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    95,    96,    99,   101,    98,   449,
     413,   450,   451,     0,   125,   182,     0,   183,     0,     0,
     102,   103,   105,   223,   221,   222,     0,    93,    92,   150,
      46,     0,   151,   156,   154,   160,   259,   257,   242,   246,
     331,   255,     0,     0,     0,     0,     0,   469,   470,   471,
     472,     0,   473,   396,    55,   349,   352,   356,   358,   360,
     370,   381,   384,   389,   390,   391,   397,     0,   392,   393,
     394,   395,   478,   461,     0,     0,     0,   453,   406,     0,
     233,   439,     0,     0,     0,   459,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   412,     0,   432,
     433,     0,     0,     0,     0,   407,     0,   431,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      97,   228,   225,   224,   185,   192,   194,     0,     0,   104,
       0,     0,     0,    86,    94,   118,   120,     0,   149,   152,
     153,   161,   158,   248,     0,   243,   244,   331,   253,   142,
     387,   388,   386,   228,   228,     0,    56,     0,   350,   354,
       0,     0,     0,     0,     0,     0,     0,     0,   359,   361,
     371,   383,   228,   479,   477,   462,     0,     0,     0,   234,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   229,     0,     0,     0,   201,   398,   111,
     112,   106,   107,     0,   109,   110,   114,   115,   122,   123,
     116,   119,   117,   121,    52,    47,   172,   176,   184,   170,
     210,     0,     0,   157,   135,   163,   165,   166,   168,   169,
     164,   162,   214,   167,   159,   272,   260,     0,   302,     0,
       0,   258,   261,   263,   264,   273,   275,   278,   287,   282,
     285,   300,   274,   301,   241,   133,     0,     0,    54,   100,
       0,   353,     0,   357,   362,   363,   364,   365,   366,   367,
       0,   368,     0,     0,   376,   382,   372,   373,     0,     0,
     385,     0,     0,   404,   405,   452,   231,     0,     0,     0,
     460,   399,   400,     0,   402,   403,     0,   444,   445,   446,
     447,     0,   448,   434,     0,     0,   423,   438,   430,   429,
     411,   437,     0,   428,   410,   427,     0,   436,   426,   417,
       0,   409,   425,   416,   408,   415,     0,   414,   435,   424,
     226,   187,   195,   193,     0,   108,   113,    50,    51,    53,
       0,    84,   173,   177,   181,     0,   211,   220,     0,   153,
       0,     0,   310,   318,     0,   303,   305,   312,   314,   317,
     288,   331,   276,   280,   296,     0,   298,   297,   284,   286,
     289,     0,   467,   468,     0,   475,   351,   355,   369,   378,
     379,   377,   380,   374,   375,     0,   463,     0,     0,     0,
       0,     0,     0,   455,     0,     0,     0,   455,     0,     0,
     231,     0,   191,   198,   200,   202,    69,     0,    65,    66,
      68,    49,    64,    62,    58,    63,    59,    60,    61,    87,
       0,   178,   171,     0,     0,   155,   218,   304,   311,     0,
     307,   316,   319,   315,   270,     0,   279,     0,   283,     0,
     320,   299,     0,   143,   464,     0,   476,     0,   465,   235,
       0,   232,     0,   441,   442,   401,   443,   456,     0,   421,
     422,   418,     0,   419,   420,     0,   186,   207,   208,   188,
     189,   209,   204,   205,   206,   203,   196,    55,    67,   126,
     174,   128,   212,     0,   215,   313,   309,   262,   277,   281,
       0,   293,     0,   294,     0,   466,   230,     0,   454,   457,
     227,     0,     0,    48,     0,   129,     0,     0,   216,   219,
       0,   308,   267,   271,   295,   290,   292,     0,     0,   440,
     199,   197,    57,   175,     0,   180,     0,   306,   265,   268,
     269,   291,   474,   179,   217,   331,   266
  };

  const short int
  MapSetParser::yypgoto_[] =
  {
    -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,   517,  -684,
    -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -192,  -684,  -124,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,  -684,   412,   -53,  -684,  -130,
    -684,  -684,  -684,  -684,  -684,  -684,   333,  -684,  -684,   312,
    -684,  -684,    89,  -684,  -684,  -684,  -684,  -684,  -684,   189,
     193,  -183,  -684,  -684,  -684,  -684,  -684,  -684,  -125,    77,
    -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -426,
    -684,  -684,  -684,  -380,  -684,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,    81,  -684,  -684,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,  -684,  -201,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,  -684,  -684,  -357,  -179,   270,
    -684,  -365,  -589,   -96,  -207,  -684,  -684,  -684,  -684,   -62,
    -684,  -684,  -684,  -684,  -684,   190,   307,  -398,  -684,  -684,
     306,  -684,  -684,  -684,  -684,  -684,  -205,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,    71,  -684,  -684,  -684,  -123,
    -684,  -684,    70,  -684,  -126,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -626,  -684,
    -684,  -683,   -99,  -684,  -684,  -684,  -684,  -684,  -684,   -97,
    -100,  -181,   -11,     4,   140,  -684,  -684,  -684,    53,  -684,
    -684,    52,  -684,  -684,  -684,   -75,  -684,  -684,    42,  -684,
    -684,  -684,  -383,  -684,  -364,   -43,  -168,  -177,  -684,  -684,
     -80,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -603,  -684,
    -684,  -684,  -684,  -684,  -684,    -9,  -684,  -684,  -684,   -25,
    -684,   178,   179,   157,  -198,    54,  -684,  -684
  };

  const short int
  MapSetParser::yydefgoto_[] =
  {
      -1,     1,     2,     9,    21,    22,    50,    83,    52,    53,
      44,    45,    67,    68,   106,   100,    46,     5,     6,    10,
       7,    24,    58,   104,   279,   280,   397,   631,   505,   629,
     630,   416,   417,   698,   699,   700,   701,    55,   113,    56,
      57,   132,   144,   166,   167,   168,   169,   145,   146,   172,
     173,   193,   277,   393,   174,   254,   255,   194,   270,   271,
     278,   491,   492,   493,   494,   495,   394,   500,   502,   395,
     396,   189,   190,   191,   796,   103,   111,   112,   123,   182,
     153,   135,   154,   155,   292,   545,   124,   137,   138,   176,
     195,   281,   282,   283,   513,   399,   284,   401,   402,   514,
     515,   635,   516,   632,   710,   794,   517,   633,   711,   771,
     518,   519,   264,   265,   266,   485,   691,   759,   267,   268,
     486,   387,   791,   695,   766,   624,   760,   520,   636,   713,
     521,   522,   640,   799,   816,   774,   523,   272,   273,   383,
     690,   484,   741,   677,   331,   576,   125,   141,   139,   157,
     405,   406,   289,   196,   158,   159,   149,   178,   291,   197,
     179,   285,   404,   403,   531,   651,   532,   819,   825,   820,
     803,   777,   526,   533,   534,   535,   536,   726,   652,   537,
     728,   653,   538,   658,   539,   659,   806,   783,   731,   660,
     540,   541,   645,   801,   776,   718,   719,   646,   647,   722,
     648,   732,   160,   127,   134,   128,   129,   130,   161,   180,
     163,   150,   303,   110,   304,   305,   551,   418,   306,   553,
     419,   307,   308,   428,   429,   309,   310,   564,   570,   672,
     565,   430,   311,   431,   312,   313,   314,   315,   328,   259,
     748,   260,   261,   335,   443,   262,   435,   572,   316,   664,
     317,   736,   737,   318,   434,   319,    62,    63,    64,   320,
      87,    88,    89,   321,    33,   322,    42,    92
  };

  const short int
  MapSetParser::yytable_[] =
  {
      27,   108,   199,    32,    34,    35,    36,    37,   256,   544,
     258,   156,   131,   126,   347,   275,   720,   580,    59,   729,
     524,   165,   622,  -190,   274,   568,    86,   705,   326,    86,
     692,   643,   693,   496,    65,    60,   131,   126,   329,   381,
     805,   527,    85,   162,   142,    85,   780,   385,   546,   547,
      97,   781,   528,   739,    54,    84,     3,   198,    94,   527,
     143,   740,   782,   -73,   185,   790,   529,   571,     4,   569,
     528,    41,   148,   740,     8,   256,    86,   258,   642,   164,
      23,   644,   131,   126,   529,    43,   721,    86,    51,   643,
     109,   107,    85,   275,   747,   287,   286,   705,   747,   807,
      95,   109,   274,    85,   105,    91,   133,    47,    91,    48,
      49,    86,    25,    26,    98,    86,    61,    66,   147,   730,
     530,   391,   392,   151,    86,   109,    96,    85,   151,   109,
     151,    85,   627,   628,   496,    99,    86,   102,   109,   644,
      85,   101,    38,    39,    40,   115,   676,   114,    25,    26,
     109,   730,    85,  -190,   637,    91,   116,    86,   327,    38,
      39,    40,   694,    38,    39,    40,    91,   527,   330,   382,
      86,   109,   151,    85,   817,   136,   257,   386,   528,   669,
     670,    38,    39,    40,   109,   140,    85,  -140,   152,   171,
      91,   175,   529,   152,    91,   152,   170,    38,    39,    40,
      38,    39,    40,    91,   673,   674,   654,   181,    90,   712,
     177,    90,   183,   275,   716,    91,    38,    39,    40,   170,
     561,   187,   274,   655,    28,    29,    30,    31,   530,    38,
      39,    40,   188,   192,    25,    26,    91,   152,   506,   507,
     276,   263,   288,   257,   323,   290,   263,   324,   656,    91,
     410,   411,   412,   724,   325,   384,   508,   332,    90,   715,
     333,   334,  -213,   336,   337,    86,   562,   563,   338,    90,
     509,   510,   339,   511,   340,   341,   342,   151,   343,   109,
     344,    85,    28,    29,    30,    31,   345,   772,   657,    38,
      39,    40,   346,    90,    25,    26,   348,    90,   349,   350,
     287,   286,   351,   352,   353,   354,    90,   355,   263,   356,
      38,    39,    40,   357,   275,    25,    26,   358,    90,   359,
     360,   361,   362,   274,   263,   626,   363,   364,   365,   448,
     366,   367,   368,   369,   275,   370,   371,   372,   373,    90,
     374,   375,   152,   274,    91,   554,   555,   556,   557,   558,
     559,   512,    90,   668,   376,   377,    74,    75,    76,    77,
      78,    79,   420,   421,   422,   423,   424,   425,   813,   378,
     379,   390,   426,   427,   398,    86,   400,   409,   413,   497,
     483,   414,    86,   432,   415,   487,   498,   488,   823,   109,
     824,    85,   151,   542,   499,   392,   109,   391,    85,   504,
     549,   550,   560,   577,   548,   552,   578,   573,   574,   388,
     575,    11,    12,    13,    14,    15,    16,    17,    18,    19,
     661,    20,   579,   581,   582,   583,   584,   826,   585,   586,
     587,   588,   589,   590,   592,   591,   593,   594,   596,   597,
     598,   599,   600,   595,   263,   131,   126,    90,   601,   603,
     604,   702,   602,   704,    91,   605,   607,   152,   543,   606,
     608,    91,   609,   611,   436,   437,   438,   610,   612,   439,
     613,   614,   440,   441,   442,   623,   444,   445,   446,   447,
     497,   449,   450,   451,   452,   453,   454,   615,   455,   616,
     617,   456,   457,   458,   459,   618,   460,   619,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
      86,   702,   621,   704,   269,   727,   638,   143,   717,   770,
     733,   725,   734,   735,   109,   738,    85,   743,   756,   287,
     286,   773,   757,   758,   742,   263,   744,   745,   746,   749,
     740,   750,   751,   753,   754,   775,   784,    90,   785,   788,
     730,   789,   795,   798,    90,   263,   800,   804,   809,   802,
      93,   808,   812,   815,   821,   792,   768,   186,   709,   769,
     625,   543,   389,   649,   543,   503,   793,   380,   501,   634,
     811,   639,   433,   525,   755,   407,   408,   818,   641,    91,
     650,   779,   778,   666,   667,   707,   671,   752,   566,   567,
     822,     0,     0,     0,    86,   814,     0,     0,     0,   703,
       0,   706,     0,     0,   620,     0,    86,     0,   109,     0,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,     0,    85,     0,     0,     0,     0,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    28,    29,
      30,    31,    38,    39,    40,     0,   763,    25,    26,     0,
       0,     0,     0,     0,     0,   707,     0,     0,     0,     0,
     761,     0,   762,     0,   263,     0,   663,   665,     0,   703,
       0,   706,     0,    91,     0,     0,   649,     0,   723,   151,
       0,     0,    90,     0,     0,    91,     0,     0,     0,     0,
       0,   675,   810,   757,   758,     0,     0,   678,   679,   680,
       0,     0,     0,   681,     0,     0,   682,     0,     0,     0,
       0,   683,     0,     0,   684,   685,     0,     0,     0,     0,
       0,     0,   686,     0,     0,   765,   687,     0,     0,     0,
     688,     0,     0,     0,   263,     0,   689,     0,     0,     0,
       0,     0,   797,     0,   152,     0,   763,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   714,   543,
     761,   543,   762,     0,     0,   151,     0,   708,     0,     0,
       0,   542,     0,     0,     0,     0,    90,     0,     0,     0,
      86,     0,     0,     0,     0,     0,     0,     0,    90,     0,
       0,     0,     0,     0,   109,     0,    85,     0,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    28,
      29,    30,    31,    38,    39,    40,     0,   767,    25,    26,
       0,     0,     0,     0,     0,   765,     0,     0,   764,     0,
     152,     0,     0,     0,   649,     0,   543,   708,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   662,     0,     0,    91,
     786,     0,   787,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   269,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    28,    29,
      30,    31,    38,    39,    40,    80,    81,     0,   293,   294,
      82,   295,   201,     0,   202,   203,   204,   205,   206,   207,
     208,   209,     0,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,     0,   221,     0,     0,   764,   296,
     297,   298,   299,   300,   301,   302,   222,     0,     0,     0,
       0,     0,     0,     0,   223,   224,   225,     0,   226,   227,
     228,     0,     0,   229,   230,     0,   231,     0,   232,   233,
     234,   235,    90,   236,   237,     0,   238,     0,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    28,    29,    30,    31,    38,    39,
      40,   696,     0,    25,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   697,     0,     0,     0,     0,     0,   -45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   117,   118,   119,
     120,   121,     0,     0,     0,  -331,     0,   201,     0,   202,
     203,   204,   205,   206,   207,   208,   209,   122,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,     0,
     221,     0,     0,     0,   296,   297,   298,   299,   300,   301,
     302,   222,     0,     0,     0,     0,     0,     0,     0,   223,
     224,   225,     0,   226,   227,   228,     0,     0,   229,   230,
       0,   231,     0,   232,   233,   234,   235,     0,   236,   237,
       0,   238,     0,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    28,
      29,    30,    31,    38,    39,    40,     0,     0,    25,    26,
       0,     0,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    28,    29,    30,    31,    38,    39,    40,
      80,    81,    25,    26,     0,    82,   489,   490,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   269,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   117,   118,   119,   120,   121,
       0,     0,     0,  -331,     0,   201,     0,   202,   203,   204,
     205,   206,   207,   208,   209,   122,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,     0,   221,     0,
       0,     0,     0,     0,   117,   118,   119,   120,   121,   222,
       0,     0,     0,   184,     0,     0,     0,   223,   224,   225,
       0,   226,   227,   228,   122,     0,   229,   230,     0,   231,
       0,   232,   233,   234,   235,     0,   236,   237,     0,   238,
       0,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,     0,     0,   117,   118,
     119,   120,   121,     0,     0,     0,     0,     0,     0,     0,
       0,    38,    39,    40,     0,     0,    25,    26,   122,     0,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    28,    29,    30,    31,    38,    39,    40,    80,    81,
      25,    26,     0,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      28,    29,    30,    31,    38,    39,    40,    80,    81,    25,
      26,     0,    82,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    28,    29,    30,    31,    38,    39,
      40,    80,    81,    25,    26,     0,    82,     0,     0,     0,
       0,     0,     0,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    28,    29,    30,    31,    38,    39,
      40,    80,    81,    25,    26,   269,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   293,   294,     0,
     295,   201,     0,   202,   203,   204,   205,   206,   207,   208,
     209,     0,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,     0,   221,     0,     0,     0,   296,   297,
     298,   299,   300,   301,   302,   222,     0,     0,     0,     0,
       0,     0,     0,   223,   224,   225,     0,   226,   227,   228,
       0,     0,   229,   230,     0,   231,     0,   232,   233,   234,
     235,     0,   236,   237,     0,   238,     0,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    28,    29,    30,    31,    38,    39,    40,
     269,     0,    25,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   201,     0,   202,   203,
     204,   205,   206,   207,   208,   209,     0,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,     0,   221,
       0,     0,     0,   296,   297,   298,   299,   300,   301,   302,
     222,     0,     0,     0,     0,     0,     0,     0,   223,   224,
     225,     0,   226,   227,   228,     0,     0,   229,   230,     0,
     231,     0,   232,   233,   234,   235,     0,   236,   237,     0,
     238,     0,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    28,    29,
      30,    31,    38,    39,    40,   697,     0,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   201,     0,   202,   203,   204,   205,   206,   207,   208,
     209,     0,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,     0,   221,     0,     0,     0,   296,   297,
     298,   299,   300,   301,   302,   222,     0,     0,     0,     0,
       0,     0,     0,   223,   224,   225,     0,   226,   227,   228,
       0,     0,   229,   230,     0,   231,     0,   232,   233,   234,
     235,     0,   236,   237,     0,   238,     0,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    28,    29,    30,    31,    38,    39,    40,
     200,     0,    25,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   201,     0,   202,   203,
     204,   205,   206,   207,   208,   209,     0,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,     0,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     222,     0,     0,     0,     0,     0,     0,     0,   223,   224,
     225,     0,   226,   227,   228,     0,     0,   229,   230,     0,
     231,     0,   232,   233,   234,   235,     0,   236,   237,     0,
     238,     0,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   269,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,    39,    40,     0,     0,    25,    26,     0,
       0,     0,     0,   201,     0,   202,   203,   204,   205,   206,
     207,   208,   209,     0,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,     0,   221,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   222,     0,     0,
       0,     0,     0,     0,     0,   223,   224,   225,     0,   226,
     227,   228,     0,     0,   229,   230,     0,   231,     0,   232,
     233,   234,   235,     0,   236,   237,     0,   238,     0,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
      39,    40
  };

  const short int
  MapSetParser::yycheck_[] =
  {
      11,   101,   183,    12,    13,    14,    15,    16,   187,   407,
     187,   136,   112,   112,   221,   192,   642,   443,    27,    53,
     400,    28,    45,    44,   192,    24,    51,   630,    44,    54,
      42,    55,    44,   390,    43,    92,   136,   136,    44,    44,
      42,    44,    51,   140,    27,    54,   729,    44,   413,   414,
      59,    42,    55,    45,    16,    51,     0,   182,    54,    44,
      43,    53,    53,    25,   161,    45,    69,   432,    20,    68,
      55,    17,   134,    53,   166,   254,   101,   254,    44,   141,
      21,   105,   182,   182,    69,    56,    55,   112,    41,    55,
     101,   100,   101,   270,   683,   195,   195,   700,   687,   782,
      25,   112,   270,   112,    42,    51,   115,    12,    54,    14,
      15,   136,   171,   172,    60,   140,   173,    41,    55,   153,
     105,    33,    34,   134,   149,   136,   167,   136,   139,   140,
     141,   140,    22,    23,   491,    57,   161,    41,   149,   105,
     149,    42,   166,   167,   168,    48,   572,   166,   171,   172,
     161,   153,   161,   174,   511,   101,    42,   182,   174,   166,
     167,   168,   174,   166,   167,   168,   112,    44,   174,   174,
     195,   182,   183,   182,   800,    48,   187,   174,    55,   562,
     563,   166,   167,   168,   195,    44,   195,    17,   134,    95,
     136,    41,    69,   139,   140,   141,   142,   166,   167,   168,
     166,   167,   168,   149,   568,   569,    24,    48,    51,   635,
      57,    54,    17,   390,   640,   161,   166,   167,   168,   165,
     427,    30,   390,    41,   162,   163,   164,   165,   105,   166,
     167,   168,    35,    96,   171,   172,   182,   183,    17,    18,
      29,   187,    54,   254,    79,    53,   192,    44,    66,   195,
     293,   294,   295,   651,    44,   266,    35,    44,   101,   639,
      44,    44,    41,    44,    44,   290,    66,    67,    44,   112,
      49,    50,    44,    52,    44,    44,    44,   288,    44,   290,
      44,   290,   162,   163,   164,   165,    44,   713,   106,   166,
     167,   168,    44,   136,   171,   172,    44,   140,   174,   174,
     400,   400,    44,    44,    44,    44,   149,   174,   254,    44,
     166,   167,   168,   174,   491,   171,   172,    44,   161,    44,
      44,    44,    44,   491,   270,   493,    44,    44,    44,   340,
      44,    44,    44,    44,   511,    44,    44,    44,    44,   182,
      44,    44,   288,   511,   290,   420,   421,   422,   423,   424,
     425,   130,   195,   560,    44,    44,   156,   157,   158,   159,
     160,   161,    60,    61,    62,    63,    64,    65,   794,    44,
      44,    30,    70,    71,    42,   400,    48,    41,    44,   390,
      22,    44,   407,    44,    94,    41,   153,    45,   814,   400,
     816,   400,   403,   404,   153,    34,   407,    33,   407,    26,
      45,    58,    71,    53,   415,    59,    53,    45,    45,   269,
      45,     3,     4,     5,     6,     7,     8,     9,    10,    11,
     545,    13,    53,    45,    45,    53,    45,   825,    45,    53,
      45,    45,    45,    45,    45,    53,    45,    53,    45,    45,
      45,    45,    45,    53,   390,   545,   545,   290,    45,    45,
      45,   630,    53,   630,   400,    45,    45,   403,   404,    53,
      45,   407,    45,    45,   324,   325,   326,    53,    45,   329,
      45,    45,   332,   333,   334,   486,   336,   337,   338,   339,
     491,   341,   342,   343,   344,   345,   346,    45,   348,    53,
      45,   351,   352,   353,   354,    45,   356,    45,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     545,   700,    41,   700,    44,    68,    44,    43,    45,   710,
      42,   107,    45,    54,   545,    45,   545,    45,    42,   639,
     639,    94,    46,    47,    53,   491,    45,    45,    45,    45,
      53,    45,    45,    45,    45,    45,    80,   400,    45,    45,
     153,    45,    19,    51,   407,   511,   107,    42,    45,    54,
      53,    60,    45,    45,    42,   767,   700,   165,   631,   709,
     491,   527,   270,   529,   530,   396,   769,   254,   395,   508,
     791,   514,   322,   403,   690,   288,   290,   802,   527,   545,
     530,   727,   725,   550,   552,   630,   564,   687,   430,   430,
     808,    -1,    -1,    -1,   639,   796,    -1,    -1,    -1,   630,
      -1,   630,    -1,    -1,   484,    -1,   651,    -1,   639,    -1,
     639,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     651,    -1,   651,    -1,    -1,    -1,    -1,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,    -1,   691,   171,   172,    -1,
      -1,    -1,    -1,    -1,    -1,   700,    -1,    -1,    -1,    -1,
     691,    -1,   691,    -1,   630,    -1,   546,   547,    -1,   700,
      -1,   700,    -1,   639,    -1,    -1,   642,    -1,   644,   710,
      -1,    -1,   545,    -1,    -1,   651,    -1,    -1,    -1,    -1,
      -1,   571,    45,    46,    47,    -1,    -1,   577,   578,   579,
      -1,    -1,    -1,   583,    -1,    -1,   586,    -1,    -1,    -1,
      -1,   591,    -1,    -1,   594,   595,    -1,    -1,    -1,    -1,
      -1,    -1,   602,    -1,    -1,   691,   606,    -1,    -1,    -1,
     610,    -1,    -1,    -1,   700,    -1,   616,    -1,    -1,    -1,
      -1,    -1,   773,    -1,   710,    -1,   791,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   638,   725,
     791,   727,   791,    -1,    -1,   796,    -1,   630,    -1,    -1,
      -1,   802,    -1,    -1,    -1,    -1,   639,    -1,    -1,    -1,
     825,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   651,    -1,
      -1,    -1,    -1,    -1,   825,    -1,   825,    -1,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,   697,   171,   172,
      -1,    -1,    -1,    -1,    -1,   791,    -1,    -1,   691,    -1,
     796,    -1,    -1,    -1,   800,    -1,   802,   700,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,   825,
     740,    -1,   742,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,    -1,    66,    67,
     174,    69,    70,    -1,    72,    73,    74,    75,    76,    77,
      78,    79,    -1,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    -1,    93,    -1,    -1,   791,    97,
      98,    99,   100,   101,   102,   103,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   112,   113,   114,    -1,   116,   117,
     118,    -1,    -1,   121,   122,    -1,   124,    -1,   126,   127,
     128,   129,   825,   131,   132,    -1,   134,    -1,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,    24,    -1,   171,   172,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    44,    -1,    70,    -1,    72,
      73,    74,    75,    76,    77,    78,    79,    56,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
     103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,
     113,   114,    -1,   116,   117,   118,    -1,    -1,   121,   122,
      -1,   124,    -1,   126,   127,   128,   129,    -1,   131,   132,
      -1,   134,    -1,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,   171,   172,
      -1,    -1,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,   174,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    44,    -1,    70,    -1,    72,    73,    74,
      75,    76,    77,    78,    79,    56,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,   104,
      -1,    -1,    -1,    45,    -1,    -1,    -1,   112,   113,   114,
      -1,   116,   117,   118,    56,    -1,   121,   122,    -1,   124,
      -1,   126,   127,   128,   129,    -1,   131,   132,    -1,   134,
      -1,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,    -1,    -1,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   166,   167,   168,    -1,    -1,   171,   172,    56,    -1,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,   174,    -1,    -1,    -1,
      -1,    -1,    -1,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    44,   174,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    -1,
      69,    70,    -1,    72,    73,    74,    75,    76,    77,    78,
      79,    -1,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    93,    -1,    -1,    -1,    97,    98,
      99,   100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   112,   113,   114,    -1,   116,   117,   118,
      -1,    -1,   121,   122,    -1,   124,    -1,   126,   127,   128,
     129,    -1,   131,   132,    -1,   134,    -1,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      44,    -1,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    -1,    93,
      -1,    -1,    -1,    97,    98,    99,   100,   101,   102,   103,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,
     114,    -1,   116,   117,   118,    -1,    -1,   121,   122,    -1,
     124,    -1,   126,   127,   128,   129,    -1,   131,   132,    -1,
     134,    -1,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,    44,    -1,   171,   172,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    72,    73,    74,    75,    76,    77,    78,
      79,    -1,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    93,    -1,    -1,    -1,    97,    98,
      99,   100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   112,   113,   114,    -1,   116,   117,   118,
      -1,    -1,   121,   122,    -1,   124,    -1,   126,   127,   128,
     129,    -1,   131,   132,    -1,   134,    -1,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      44,    -1,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    -1,    93,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,
     114,    -1,   116,   117,   118,    -1,    -1,   121,   122,    -1,
     124,    -1,   126,   127,   128,   129,    -1,   131,   132,    -1,
     134,    -1,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   166,   167,   168,    -1,    -1,   171,   172,    -1,
      -1,    -1,    -1,    70,    -1,    72,    73,    74,    75,    76,
      77,    78,    79,    -1,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   112,   113,   114,    -1,   116,
     117,   118,    -1,    -1,   121,   122,    -1,   124,    -1,   126,
     127,   128,   129,    -1,   131,   132,    -1,   134,    -1,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,
     167,   168
  };

  const unsigned short int
  MapSetParser::yystos_[] =
  {
       0,   176,   177,     0,    20,   192,   193,   195,   166,   178,
     194,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      13,   179,   180,    21,   196,   171,   172,   387,   162,   163,
     164,   165,   430,   439,   430,   430,   430,   430,   166,   167,
     168,   440,   441,    56,   185,   186,   191,    12,    14,    15,
     181,    41,   183,   184,    16,   212,   214,   215,   197,   430,
      92,   173,   431,   432,   433,   430,    41,   187,   188,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     169,   170,   174,   182,   388,   430,   434,   435,   436,   437,
     438,   440,   442,   183,   388,    25,   167,   430,   440,    57,
     190,    42,    41,   250,   198,    42,   189,   430,   385,   387,
     388,   251,   252,   213,   166,    48,    42,    36,    37,    38,
      39,    40,    56,   253,   261,   321,   377,   378,   380,   381,
     382,   385,   216,   430,   379,   256,    48,   262,   263,   323,
      44,   322,    27,    43,   217,   222,   223,    55,   324,   331,
     386,   387,   440,   255,   257,   258,   253,   324,   329,   330,
     377,   383,   384,   385,   324,    28,   218,   219,   220,   221,
     440,    95,   224,   225,   229,    41,   264,    57,   332,   335,
     384,    48,   254,    17,    45,   384,   221,    30,    35,   246,
     247,   248,    96,   226,   232,   265,   328,   334,   253,   386,
      44,    70,    72,    73,    74,    75,    76,    77,    78,    79,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    93,   104,   112,   113,   114,   116,   117,   118,   121,
     122,   124,   126,   127,   128,   129,   131,   132,   134,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   230,   231,   313,   387,   412,   414,
     416,   417,   420,   440,   287,   288,   289,   293,   294,    44,
     233,   234,   312,   313,   411,   412,    29,   227,   235,   199,
     200,   266,   267,   268,   271,   336,   377,   385,    54,   327,
      53,   333,   259,    66,    67,    69,    97,    98,    99,   100,
     101,   102,   103,   387,   389,   390,   393,   396,   397,   400,
     401,   407,   409,   410,   411,   412,   423,   425,   428,   430,
     434,   438,   440,    79,    44,    44,    44,   174,   413,    44,
     174,   319,    44,    44,    44,   418,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,   319,    44,   174,
     174,    44,    44,    44,    44,   174,    44,   174,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
     231,    44,   174,   314,   387,    44,   174,   296,   389,   234,
      30,    33,    34,   228,   241,   244,   245,   201,    42,   270,
      48,   272,   273,   338,   337,   325,   326,   331,   335,    41,
     410,   410,   410,    44,    44,    94,   206,   207,   392,   395,
      60,    61,    62,    63,    64,    65,    70,    71,   398,   399,
     406,   408,    44,   314,   429,   421,   389,   389,   389,   389,
     389,   389,   389,   419,   389,   389,   389,   389,   387,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     389,   389,   389,    22,   316,   290,   295,    41,    45,    31,
      32,   236,   237,   238,   239,   240,   312,   387,   153,   153,
     242,   245,   243,   244,    26,   203,    17,    18,    35,    49,
      50,    52,   130,   269,   274,   275,   277,   281,   285,   286,
     302,   305,   306,   311,   268,   330,   347,    44,    55,    69,
     105,   339,   341,   348,   349,   350,   351,   354,   357,   359,
     365,   366,   387,   440,   332,   260,   316,   316,   387,    45,
      58,   391,    59,   394,   400,   400,   400,   400,   400,   400,
      71,   319,    66,    67,   402,   405,   436,   437,    24,    68,
     403,   316,   422,    45,    45,    45,   320,    53,    53,    53,
     264,    45,    45,    53,    45,    45,    53,    45,    45,    45,
      45,    53,    45,    45,    53,    53,    45,    45,    45,    45,
      45,    45,    53,    45,    45,    45,    53,    45,    45,    45,
      53,    45,    45,    45,    45,    45,    53,    45,    45,    45,
     389,    41,    45,   387,   300,   237,   411,    22,    23,   204,
     205,   202,   278,   282,   287,   276,   303,   312,    44,   254,
     307,   350,    44,    55,   105,   367,   372,   373,   375,   440,
     357,   340,   353,   356,    24,    41,    66,   106,   358,   360,
     364,   253,    24,   389,   424,   389,   393,   396,   319,   407,
     407,   403,   404,   409,   409,   389,   264,   318,   389,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     315,   291,    42,    44,   174,   298,    24,    44,   208,   209,
     210,   211,   313,   387,   412,   423,   430,   434,   438,   222,
     279,   283,   264,   304,   389,   268,   264,    45,   370,   371,
     373,    55,   374,   440,   332,   107,   352,    68,   355,    53,
     153,   363,   376,    42,    45,    54,   426,   427,    45,    45,
      53,   317,    53,    45,    45,    45,    45,   317,   415,    45,
      45,    45,   415,    45,    45,   318,    42,    46,    47,   292,
     301,   387,   430,   434,   438,   440,   299,   389,   209,   224,
     386,   284,   264,    94,   310,    45,   369,   346,   354,   359,
     376,    42,    53,   362,    80,    45,   389,   389,    45,    45,
      45,   297,   207,   246,   280,    19,   249,   387,    51,   308,
     107,   368,    54,   345,    42,    42,   361,   376,    60,    45,
      45,   301,    45,   264,   386,    45,   309,   373,   341,   342,
     344,    42,   439,   264,   264,   343,   332
  };

  const unsigned short int
  MapSetParser::yyr1_[] =
  {
       0,   175,   177,   176,   178,   178,   179,   179,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   181,   181,
     181,   182,   182,   183,   184,   184,   185,   186,   186,   187,
     187,   188,   189,   190,   190,   191,   192,   193,   193,   194,
     194,   195,   197,   198,   196,   200,   201,   202,   199,   203,
     204,   204,   205,   205,   206,   207,   207,   208,   209,   209,
     209,   209,   209,   209,   209,   209,   210,   210,   211,   211,
     213,   212,   214,   215,   215,   216,   216,   217,   218,   218,
     219,   220,   221,   222,   223,   223,   224,   225,   225,   226,
     226,   227,   227,   228,   228,   229,   230,   230,   231,   231,
     231,   231,   232,   233,   233,   234,   235,   236,   236,   237,
     237,   238,   238,   239,   240,   240,   241,   241,   242,   242,
     243,   243,   244,   245,   246,   247,   248,   248,   249,   249,
     250,   252,   251,   253,   253,   254,   254,   255,   256,   256,
     258,   259,   260,   257,   261,   262,   263,   263,   265,   264,
     266,   266,   267,   268,   268,   269,   270,   270,   271,   272,
     273,   273,   274,   274,   274,   274,   274,   274,   274,   274,
     276,   275,   278,   279,   280,   277,   282,   283,   284,   281,
     285,   286,   287,   287,   289,   290,   288,   291,   291,   292,
     294,   293,   295,   295,   296,   296,   297,   297,   299,   298,
     298,   300,   300,   301,   301,   301,   301,   301,   301,   301,
     303,   304,   302,   306,   307,   305,   309,   308,   310,   310,
     311,   312,   312,   312,   313,   314,   315,   314,   316,   316,
     317,   318,   318,   319,   320,   319,   322,   321,   323,   321,
     324,   325,   326,   326,   327,   328,   328,   329,   330,   330,
     331,   331,   332,   333,   334,   334,   335,   337,   336,   338,
     336,   340,   339,   341,   341,   343,   342,   344,   344,   345,
     346,   346,   347,   348,   349,   350,   351,   352,   353,   353,
     354,   355,   356,   356,   357,   358,   358,   359,   359,   360,
     361,   361,   362,   362,   363,   363,   364,   364,   364,   364,
     365,   366,   366,   366,   366,   367,   368,   369,   369,   370,
     371,   371,   372,   372,   373,   374,   374,   375,   375,   375,
     376,   377,   377,   379,   378,   380,   381,   381,   381,   381,
     381,   382,   382,   383,   383,   384,   384,   385,   385,   386,
     386,   387,   387,   388,   388,   388,   388,   388,   388,   389,
     390,   391,   392,   392,   393,   394,   395,   395,   396,   397,
     398,   398,   399,   399,   399,   399,   399,   399,   399,   399,
     400,   401,   402,   402,   403,   403,   404,   404,   405,   405,
     405,   406,   406,   407,   408,   408,   409,   409,   409,   409,
     410,   410,   410,   410,   410,   410,   410,   410,   411,   412,
     412,   412,   412,   412,   412,   412,   412,   412,   412,   412,
     412,   412,   412,   412,   412,   412,   412,   412,   412,   412,
     412,   412,   412,   412,   412,   412,   412,   412,   412,   412,
     412,   412,   412,   412,   412,   412,   412,   412,   412,   412,
     412,   412,   412,   412,   412,   412,   412,   412,   412,   412,
     412,   412,   413,   413,   414,   415,   415,   416,   418,   419,
     417,   421,   422,   420,   423,   423,   423,   424,   424,   425,
     425,   425,   425,   425,   426,   427,   427,   428,   429,   429,
     430,   431,   432,   432,   433,   433,   434,   434,   434,   435,
     435,   435,   436,   436,   436,   437,   437,   437,   438,   438,
     439,   439,   439,   439,   440,   440,   441,   441,   442,   442
  };

  const unsigned char
  MapSetParser::yyr2_[] =
  {
       0,     2,     0,     4,     0,     2,     0,     2,     4,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     0,     1,     4,     1,     2,     2,     0,     1,     0,
       1,     3,     3,     0,     2,     3,     2,     0,     1,     0,
       2,     2,     0,     0,     5,     0,     0,     0,     7,     3,
       1,     1,     0,     1,     2,     0,     1,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       0,     8,     2,     0,     1,     0,     2,     2,     1,     1,
       1,     2,     1,     2,     0,     1,     4,     0,     1,     0,
       1,     0,     1,     0,     1,     3,     1,     2,     1,     1,
       4,     1,     2,     1,     2,     1,     3,     1,     2,     1,
       1,     1,     1,     2,     1,     1,     2,     2,     0,     1,
       0,     1,     2,     2,     1,     2,     0,     1,     0,     1,
       3,     0,     3,     0,     1,     0,     1,     3,     0,     2,
       0,     0,     0,     8,     2,     2,     0,     1,     0,     4,
       1,     1,     2,     0,     1,     3,     0,     2,     2,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     3,     0,     0,     0,     6,     0,     0,     0,     7,
       6,     2,     1,     1,     0,     0,     6,     0,     2,     1,
       0,     5,     0,     2,     1,     3,     0,     2,     0,     4,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       0,     0,     4,     0,     0,     4,     0,     3,     0,     2,
       2,     1,     1,     1,     2,     1,     0,     6,     0,     1,
       2,     0,     2,     1,     0,     5,     0,     3,     0,     3,
       3,     2,     0,     1,     2,     0,     2,     1,     0,     1,
       1,     1,     2,     2,     0,     2,     1,     0,     3,     0,
       3,     0,     4,     1,     1,     0,     3,     0,     1,     2,
       0,     2,     1,     1,     1,     1,     2,     2,     0,     2,
       2,     2,     0,     2,     2,     0,     1,     1,     2,     1,
       1,     2,     2,     1,     2,     3,     1,     1,     1,     2,
       1,     1,     1,     2,     3,     1,     2,     0,     2,     2,
       0,     1,     1,     3,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     0,     4,     4,     1,     1,     1,     1,
       1,     0,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     0,     2,     2,     2,     0,     2,     1,     2,
       0,     1,     2,     2,     2,     2,     2,     2,     2,     3,
       1,     2,     1,     1,     2,     2,     0,     1,     2,     2,
       2,     0,     2,     2,     0,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     4,
       4,     6,     4,     4,     4,     4,     2,     2,     4,     4,
       4,     4,     2,     1,     4,     4,     4,     4,     6,     6,
       6,     6,     6,     4,     4,     4,     4,     4,     4,     4,
       4,     2,     2,     2,     4,     4,     4,     4,     4,     2,
       8,     6,     6,     6,     4,     4,     4,     4,     4,     1,
       1,     1,     3,     1,     7,     0,     1,     7,     0,     0,
       4,     0,     0,     5,     5,     5,     6,     1,     1,     1,
       1,     1,     1,     1,     4,     0,     1,     2,     0,     1,
       2,     2,     1,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const MapSetParser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "IT_REWRITEVAR", "IT_DRIVER",
  "IT_SERVER", "IT_USER", "IT_PASSWORD", "IT_DATABASE", "IT_STEMURI",
  "IT_PRIMARYKEY", "IT_SHAREDVARS", "IT_PROMISCUOUS", "IT_INTERSECTION",
  "IT_DRACONIAN", "IT_VARNAMES", "IT_LABEL", "IT_GRAPH", "IT_SERVICE",
  "IT_SILENT", "IT_BASE", "IT_PREFIX", "IT_DISTINCT", "IT_REDUCED",
  "GT_TIMES", "IT_CONSTRUCT", "IT_SELECT", "IT_FROM", "IT_NAMED",
  "IT_ORDER", "IT_BY", "IT_ASC", "IT_DESC", "IT_LIMIT", "IT_OFFSET",
  "IT_VALUES", "IT_MEMBERS", "IT_STARTS", "IT_ENDS", "IT_ANY",
  "IT_UNORDERED", "GT_LCURLEY", "GT_RCURLEY", "IT_WHERE", "GT_LPAREN",
  "GT_RPAREN", "IT_UNDEF", "GT_MINUS_MINUS", "GT_DOT", "IT_OPTIONAL",
  "IT_MINUS", "IT_UNION", "IT_FILTER", "GT_COMMA", "GT_SEMI", "IT_a",
  "GT_LBRACKET", "GT_RBRACKET", "GT_OR", "GT_AND", "GT_EQUAL", "GT_NEQUAL",
  "GT_LT", "GT_GT", "GT_LE", "GT_GE", "GT_PLUS", "GT_MINUS", "GT_DIVIDE",
  "GT_NOT", "IT_NOT", "IT_IN", "IT_IRI", "IT_URI", "IT_BNODE",
  "IT_COALESCE", "IT_IF", "IT_STRLANG", "IT_STRDT", "IT_EXISTS",
  "IT_SEPARATOR", "IT_STR", "IT_LANG", "IT_LANGMATCHES", "IT_DATATYPE",
  "IT_BOUND", "IT_sameTerm", "IT_isIRI", "IT_isURI", "IT_isBLANK",
  "IT_isLITERAL", "IT_REGEX", "GT_DTYPE", "IT_CONCAT", "IT_AS", "IT_GROUP",
  "IT_HAVING", "IT_COUNT", "IT_SUM", "IT_MIN", "IT_MAX", "IT_AVG",
  "IT_GROUP_CONCAT", "IT_SAMPLE", "IT_isNUMERIC", "GT_CARROT", "GT_OPT",
  "GT_PIPE", "IT_WITH", "IT_DEFAULT", "IT_ALL", "IT_USING", "IT_UUID",
  "IT_STRUUID", "IT_MD5", "IT_TO", "IT_STRBEFORE", "IT_STRAFTER",
  "IT_YEAR", "IT_ADD", "IT_COPY", "IT_RAND", "IT_SHA512",
  "GT_DELETE_LBRACKET_SPACECHAR_TAB_RETURN_LINEFEED_RBRACKET_PLUS_WHERE",
  "IT_NOW",
  "GT_DELETE_LBRACKET_SPACECHAR_TAB_RETURN_LINEFEED_RBRACKET_PLUS_DATA",
  "IT_TZ", "IT_TIMEZONE", "IT_ROUND", "IT_SHA384", "IT_BIND",
  "IT_CONTAINS", "IT_SECONDS", "IT_MOVE", "IT_FLOOR",
  "GT_INSERT_LBRACKET_SPACECHAR_TAB_RETURN_LINEFEED_RBRACKET_PLUS_DATA",
  "IT_MINUTES", "IT_SUBSTR", "IT_SHA256", "IT_HOURS", "IT_ENCODE_FOR_URI",
  "IT_STRSTARTS", "IT_CEIL", "IT_DAY", "IT_LCASE", "IT_ABS", "IT_UCASE",
  "IT_STRENDS", "IT_STRLEN", "IT_SHA1", "IT_MONTH", "IT_true", "IT_false",
  "INTEGER", "DECIMAL", "DOUBLE", "INTEGER_POSITIVE", "DECIMAL_POSITIVE",
  "DOUBLE_POSITIVE", "INTEGER_NEGATIVE", "DECIMAL_NEGATIVE",
  "DOUBLE_NEGATIVE", "STRING_LITERAL1", "STRING_LITERAL_LONG1",
  "STRING_LITERAL2", "STRING_LITERAL_LONG2", "IRIREF", "PNAME_NS",
  "PNAME_LN", "BLANK_NODE_LABEL", "ANON", "VAR1", "VAR2", "LANGTAG", "NIL",
  "$accept", "MapSet", "$@1", "_QAccessParm_E_Star",
  "_QConstructQuery_E_Star", "AccessParm",
  "_O_QIT_PROMISCUOUS_E_Or_QIT_VARNAMES_E_Or_QIT_DRACONIAN_E_C",
  "_QGraphTerm_E_Opt",
  "_O_QGT_LCURLEY_E_S_QGraphTerm_E_Opt_S_QGT_RCURLEY_E_S_QVarOrTerm_E_C",
  "_Q_O_QGT_LCURLEY_E_S_QGraphTerm_E_Opt_S_QGT_RCURLEY_E_S_QVarOrTerm_E_C_E_Plus",
  "PrimaryKeySpec", "_QDefaultPrimaryKey_E_Opt", "_QPrimaryKeySet_E_Opt",
  "PrimaryKeySet", "_O_QRDFLiteral_E_S_QGT_DOT_E_S_QRDFLiteral_E_C",
  "_Q_O_QRDFLiteral_E_S_QGT_DOT_E_S_QRDFLiteral_E_C_E_Star",
  "DefaultPrimaryKey", "Prologue", "_QBaseDecl_E_Opt",
  "_QPrefixDecl_E_Star", "BaseDecl", "PrefixDecl", "$@2", "$@3",
  "SubSelect", "@4", "@5", "@6", "SelectClause",
  "_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C",
  "_Q_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C_E_Opt", "_O_QIT_AS_E_S_QVar_E_C",
  "_Q_O_QIT_AS_E_S_QVar_E_C_E_Opt",
  "_O_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C",
  "_O_QBuiltInCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QVar_E_Or_QAggregate_E_Or_QFunctionCall_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C",
  "_Q_O_QBuiltInCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QVar_E_Or_QAggregate_E_Or_QFunctionCall_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C_E_Plus",
  "_O_QBuiltInCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QVar_E_Or_QAggregate_E_Or_QFunctionCall_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_Plus_Or_QGT_TIMES_E_C",
  "ConstructQuery", "$@7", "_O_QIT_LABEL_E_S_QGraphTerm_E_C",
  "_Q_O_QIT_LABEL_E_S_QGraphTerm_E_C_E_Opt", "_QDatasetClause_E_Star",
  "DatasetClause", "_O_QDefaultGraphClause_E_Or_QNamedGraphClause_E_C",
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
  "_Q_O_QIT_VALUES_E_S_QDataBlock_E_C_E_Opt", "_QIT_SILENT_E_Opt",
  "QuadPattern", "Quads", "$@8", "_QTriplesTemplate_E_Opt",
  "_QGT_DOT_E_Opt",
  "_O_QQuadsNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesTemplate_E_Opt_C",
  "_Q_O_QQuadsNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesTemplate_E_Opt_C_E_Star",
  "QuadsNotTriples", "@9", "@10", "$@11", "TriplesTemplate",
  "_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C_E_Opt", "GroupGraphPattern",
  "$@12", "_O_QSubSelect_E_Or_QGroupGraphPatternSub_E_C",
  "GroupGraphPatternSub", "_QTriplesBlock_E_Opt",
  "_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "TriplesBlock", "_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C_E_Opt", "GraphPatternNotTriples",
  "OptionalGraphPattern", "@13", "GraphGraphPattern", "@14", "@15", "@16",
  "ServiceGraphPattern", "@17", "@18", "@19", "Bind", "InlineData",
  "DataBlock", "InlineDataOneVar", "$@20", "$@21",
  "_QSingleValueRow_E_Star", "SingleValueRow", "InlineDataFull", "$@22",
  "_QVar_E_Star",
  "_O_QNIL_E_Or_QGT_LPAREN_E_S_QVar_E_Star_S_QGT_RPAREN_E_C",
  "_QDataBlockValue_E_Star",
  "_O_QGT_LPAREN_E_S_QDataBlockValue_E_Star_S_QGT_RPAREN_E_Or_QNIL_E_C",
  "$@23",
  "_Q_O_QGT_LPAREN_E_S_QDataBlockValue_E_Star_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star",
  "DataBlockValue", "MinusGraphPattern", "@24", "@25",
  "GroupOrUnionGraphPattern", "@26", "@27",
  "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@28",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList", "@29", "_QIT_DISTINCT_E_Opt",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "ExpressionList", "@30",
  "TriplesSameSubject", "$@31", "$@32", "PropertyListNotEmpty",
  "_O_QVerb_E_S_QObjectList_E_C", "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "Verb", "ObjectList",
  "_O_QGT_COMMA_E_S_QObject_E_C", "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star",
  "Object", "TriplesSameSubjectPath", "$@33", "$@34",
  "PropertyListNotEmptyPath", "$@35", "_O_QVerbPath_E_Or_QVerbSimple_E_C",
  "_O_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_C", "$@36",
  "_Q_O_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_Opt_C_E_Star",
  "PropertyListPath", "VerbPath", "VerbSimple", "Path", "PathAlternative",
  "_O_QGT_PIPE_E_S_QPathSequence_E_C",
  "_Q_O_QGT_PIPE_E_S_QPathSequence_E_C_E_Star", "PathSequence",
  "_O_QGT_DIVIDE_E_S_QPathEltOrInverse_E_C",
  "_Q_O_QGT_DIVIDE_E_S_QPathEltOrInverse_E_C_E_Star", "PathElt",
  "_QPathMod_E_Opt", "PathEltOrInverse", "PathMod",
  "_O_QGT_RCURLEY_E_Or_QInteger_E_S_QGT_RCURLEY_E_C",
  "_O_QGT_COMMA_E_S_QGT_RCURLEY_E_Or_QInteger_E_S_QGT_RCURLEY_E_Or_QGT_RCURLEY_E_C",
  "_O_QInteger_E_S_QGT_COMMA_E_S_QGT_RCURLEY_E_Or_QInteger_E_S_QGT_RCURLEY_E_Or_QGT_RCURLEY_E_Or_QGT_COMMA_E_S_QInteger_E_S_QGT_RCURLEY_E_C",
  "_O_QGT_TIMES_E_Or_QGT_OPT_E_Or_QGT_PLUS_E_Or_QGT_LCURLEY_E_S_QInteger_E_S_QGT_COMMA_E_S_QGT_RCURLEY_E_Or_QInteger_E_S_QGT_RCURLEY_E_Or_QGT_RCURLEY_E_Or_QGT_COMMA_E_S_QInteger_E_S_QGT_RCURLEY_E_C",
  "PathPrimary",
  "_O_Qiri_E_Or_QIT_a_E_Or_QGT_NOT_E_S_QPathNegatedPropertySet_E_Or_QGT_LPAREN_E_S_QPath_E_S_QGT_RPAREN_E_C",
  "PathNegatedPropertySet", "_O_QGT_PIPE_E_S_QPathOneInPropertySet_E_C",
  "_Q_O_QGT_PIPE_E_S_QPathOneInPropertySet_E_C_E_Star",
  "_O_QPathOneInPropertySet_E_S_QGT_PIPE_E_S_QPathOneInPropertySet_E_Star_C",
  "_Q_O_QPathOneInPropertySet_E_S_QGT_PIPE_E_S_QPathOneInPropertySet_E_Star_C_E_Opt",
  "_O_QPathOneInPropertySet_E_Or_QGT_LPAREN_E_S_QPathOneInPropertySet_E_S_QGT_PIPE_E_S_QPathOneInPropertySet_E_Star_Opt_S_QGT_RPAREN_E_C",
  "PathOneInPropertySet", "_O_Qiri_E_Or_QIT_a_E_C",
  "_O_Qiri_E_Or_QIT_a_E_Or_QGT_CARROT_E_S_Qiri_E_Or_QIT_a_E_C", "Integer",
  "TriplesNode", "BlankNodePropertyList", "@37", "Generator",
  "_O_QIT_MEMBERS_E_Or_QIT_STARTS_E_Or_QIT_ENDS_E_Or_QIT_ANY_E_Or_QIT_UNORDERED_E_C",
  "_Q_O_QIT_MEMBERS_E_Or_QIT_STARTS_E_Or_QIT_ENDS_E_Or_QIT_ANY_E_Or_QIT_UNORDERED_E_C_E_Opt",
  "_QGraphNode_E_Plus", "GraphNode", "VarOrTerm", "VarOrIri", "Var",
  "GraphTerm", "Expression", "ConditionalOrExpression",
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
  "SubstringExpression", "ExistsFunc", "@38", "@39", "NotExistsFunc",
  "@40", "@41", "Aggregate", "_O_QGT_TIMES_E_Or_QExpression_E_C",
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
  MapSetParser::yyrline_[] =
  {
       0,   460,   460,   460,   466,   468,   472,   474,   478,   487,
     490,   493,   496,   499,   502,   505,   507,   511,   517,   520,
     523,   529,   532,   536,   548,   549,   553,   556,   558,   561,
     563,   567,   571,   576,   578,   582,   589,   593,   595,   599,
     601,   605,   611,   613,   611,   623,   626,   629,   623,   644,
     652,   655,   662,   665,   670,   677,   680,   685,   692,   695,
     698,   701,   704,   707,   710,   714,   719,   722,   730,   733,
     740,   740,   752,   758,   761,   766,   769,   777,   784,   785,
     789,   795,   801,   808,   815,   817,   822,   829,   832,   837,
     840,   845,   848,   853,   857,   861,   868,   871,   878,   881,
     884,   887,   893,   899,   902,   909,   914,   921,   925,   933,
     935,   943,   946,   954,   962,   963,   970,   974,   982,   985,
     990,   993,   997,  1003,  1009,  1013,  1019,  1022,  1026,  1029,
    1035,  1041,  1041,  1049,  1051,  1055,  1057,  1061,  1064,  1066,
    1071,  1076,  1079,  1071,  1090,  1094,  1097,  1099,  1104,  1104,
    1115,  1116,  1121,  1125,  1127,  1137,  1141,  1144,  1160,  1165,
    1169,  1172,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,
    1189,  1189,  1205,  1209,  1211,  1205,  1222,  1226,  1228,  1222,
    1239,  1250,  1256,  1257,  1261,  1263,  1261,  1270,  1272,  1276,
    1284,  1284,  1291,  1293,  1299,  1300,  1303,  1305,  1311,  1311,
    1316,  1322,  1324,  1328,  1331,  1334,  1337,  1340,  1343,  1346,
    1352,  1356,  1352,  1366,  1370,  1366,  1380,  1380,  1392,  1394,
    1398,  1408,  1409,  1410,  1414,  1422,  1426,  1426,  1436,  1439,
    1446,  1452,  1454,  1468,  1471,  1471,  1481,  1481,  1484,  1484,
    1491,  1496,  1500,  1502,  1507,  1511,  1513,  1518,  1522,  1524,
    1528,  1532,  1540,  1545,  1549,  1551,  1555,  1563,  1563,  1566,
    1566,  1572,  1572,  1578,  1579,  1583,  1583,  1588,  1590,  1594,
    1597,  1599,  1603,  1607,  1611,  1617,  1621,  1625,  1628,  1630,
    1634,  1638,  1643,  1645,  1651,  1654,  1656,  1662,  1663,  1669,
    1673,  1674,  1678,  1679,  1683,  1684,  1688,  1689,  1690,  1691,
    1695,  1699,  1702,  1705,  1708,  1714,  1718,  1721,  1723,  1727,
    1730,  1732,  1736,  1737,  1741,  1745,  1746,  1750,  1751,  1752,
    1756,  1761,  1762,  1766,  1766,  1779,  1806,  1809,  1812,  1815,
    1818,  1825,  1828,  1833,  1837,  1844,  1845,  1849,  1852,  1856,
    1859,  1865,  1866,  1870,  1873,  1876,  1879,  1882,  1883,  1889,
    1894,  1903,  1910,  1913,  1921,  1930,  1937,  1940,  1947,  1952,
    1965,  1969,  1973,  1977,  1981,  1985,  1989,  1993,  1997,  2001,
    2008,  2013,  2022,  2025,  2032,  2035,  2042,  2045,  2050,  2053,
    2057,  2071,  2074,  2082,  2091,  2094,  2101,  2104,  2107,  2110,
    2114,  2115,  2116,  2117,  2120,  2123,  2126,  2129,  2133,  2139,
    2142,  2145,  2148,  2151,  2154,  2157,  2161,  2164,  2167,  2170,
    2173,  2176,  2179,  2182,  2183,  2186,  2189,  2192,  2195,  2198,
    2201,  2204,  2207,  2210,  2213,  2216,  2219,  2222,  2225,  2228,
    2231,  2234,  2237,  2240,  2243,  2246,  2249,  2252,  2255,  2258,
    2261,  2264,  2267,  2270,  2273,  2276,  2279,  2282,  2285,  2288,
    2289,  2290,  2296,  2299,  2306,  2313,  2316,  2320,  2326,  2329,
    2326,  2341,  2344,  2341,  2357,  2361,  2366,  2375,  2378,  2382,
    2385,  2388,  2391,  2394,  2400,  2406,  2409,  2413,  2423,  2426,
    2431,  2439,  2446,  2450,  2458,  2462,  2466,  2467,  2468,  2472,
    2473,  2474,  2478,  2479,  2480,  2484,  2485,  2486,  2490,  2491,
    2495,  2496,  2497,  2498,  2502,  2503,  2507,  2508,  2512,  2513
  };

  // Print the state stack on the debug stream.
  void
  MapSetParser::yystack_print_ ()
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
  MapSetParser::yy_reduce_print_ (int yyrule)
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
  MapSetParser::token_number_type
  MapSetParser::yytranslate_ (int t)
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
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174
    };
    const unsigned int user_token_number_max_ = 429;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // w3c_sw
#line 4684 "lib/MapSetParser.cpp" // lalr1.cc:1167
#line 2519 "lib/MapSetParser.ypp" // lalr1.cc:1168
 /*** Additional Code ***/

void w3c_sw::MapSetParser::error(const MapSetParser::location_type& l,
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

    MapSetDriver::MapSetDriver (std::string baseURI, AtomFactory* atomFactory) : 
	YaccDriver(baseURI, atomFactory), curSubject(NULL), curPredicate(NULL), 
	curBGP(NULL), curFilter(NULL), 
	curResultSet(NULL), curResult(NULL), curExprList(NULL), 
	root(NULL), unnestTree(false), 
	lastRuleTerm(TTerm::Unbound, TTerm::Unbound),
	lastRuleTermSet(false)
{
}

    MapSetDriver::~MapSetDriver ()
{
}

MapSet* MapSetDriver::parse (IStreamContext& in)
{
    sharedVarsSet = false;
    root = NULL;
    curBGP = NULL;
    curOp = NULL;
    curGraphName = NULL;
    streamname = in.nameStr;
    // clear prefixes for nth run but keep them around for e.g. serialization.
    clearPrefixes();

    MapSetScanner scanner(this, in.p);
    scanner.set_debug(trace_scanning);
    lexer = &scanner;

    MapSetParser parser(*this);
    parser.set_debug_level(trace_parsing);
    // !!! Clear out namespaces!
    ignorePrefixFlag = false;
    parser.parse();
    return root;
}

MapSet* MapSetDriver::parse (std::string queryStr)
{
    IStreamContext in(queryStr.c_str(), IStreamContext::STRING);
    return parse(in);
}

} // namespace w3c_sw

/* END Driver */

