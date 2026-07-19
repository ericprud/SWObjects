/* Algae3Scanner.hpp - flex scanner class for Algae 3.
 * Follows the SWObjects scanner family (ShExCScanner.hpp et al.).
 */

#ifndef ALGAE3_SCANNER_HPP
#define ALGAE3_SCANNER_HPP

#ifndef YY_DECL
#define	YY_DECL							\
    w3c_sw::Algae3Parser::token_type				\
    w3c_sw::Algae3Scanner::lex(				\
	w3c_sw::Algae3Parser::semantic_type* yylval,		\
	w3c_sw::Algae3Parser::location_type* yylloc		\
    )
#endif

#ifndef __FLEX_LEXER_H
#define yyFlexLexer Algae3FlexLexer
#include "FlexLexer.h"
#undef yyFlexLexer
#endif

namespace w3c_sw {

class Algae3Scanner : public Algae3FlexLexer {
public:
    Algae3Scanner (class Algae3Driver* driver, std::istream* in = NULL, std::ostream* out = NULL)
	: Algae3FlexLexer(in, out), driver(driver)
    {  }
    virtual ~Algae3Scanner () {  }

    virtual Algae3Parser::token_type lex (Algae3Parser::semantic_type* yylval,
					  Algae3Parser::location_type* yylloc);
    Algae3Parser::token_type lexWrapper (Algae3Parser::semantic_type* yylval,
					 Algae3Parser::location_type* yylloc) {
	try {
	    return lex(yylval, yylloc);
	} catch (const char* e) {
	    throw std::string(e);
	}
    }

    void set_debug (bool b);

protected:
    class Algae3Driver* driver;
};

} // namespace w3c_sw

#endif /* ALGAE3_SCANNER_HPP */
