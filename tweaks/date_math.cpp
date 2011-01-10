#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

struct TypeError {
    std::string val;
    std::string prob;
    TypeError (std::string val, std::string prob) : val(val), prob(prob) {  }
};

struct CanonicalRDFLiteral {
    std::string terminal;
    CanonicalRDFLiteral (std::string lexicalValue) : terminal(lexicalValue) {  }
    std::string getLexicalValue () const { return terminal; }
};

struct DateTimeRDFLiteral : public CanonicalRDFLiteral {
    long m_value;
    DateTimeRDFLiteral (std::string lexicalValue) : CanonicalRDFLiteral(lexicalValue), m_value(-1) {  }
    virtual void validate () const { parseDT(getLexicalValue()); }
    static long parseDT (std::string s) {
	/* '-'? yyyy '-' mm '-' dd 'T' hh ':' mm ':' ss ('.' s+)? (zzzzzz)?
	 * per <http://www.w3.org/TR/2004/REC-xmlschema-2-20041028/#dateTime-lexical-representation>
	 */
	const char* ptr = s.c_str();
	char* end;
	long int l;
	if (*ptr == '-')
	    ++ptr;

	l = strtol(ptr, &end, 10);
	if (l == 0 || end != ptr+4)
		throw TypeError(s, "xsd:datetime year");
	ptr += 4;
	if (*ptr++ != '-')
	    throw TypeError(s, "xsd:datetime year-month separator");

	l = strtol(ptr, &end, 10);
	if (l < 1 || l > 12 || end != ptr+2)
		throw TypeError(s, "xsd:datetime month");
	ptr += 2;
	if (*ptr++ != '-')
	    throw TypeError(s, "xsd:datetime year-month separator");

	l = strtol(ptr, &end, 10);
	if (l < 1 || l > 31 || end != ptr+2)
		throw TypeError(s, "xsd:datetime date");
	ptr += 2;
	if (*ptr++ != 'T')
	    throw TypeError(s, "xsd:datetime date-hour separator");

	l = strtol(ptr, &end, 10);
	if (l < 0 || l > 23 || end != ptr+2)
		throw TypeError(s, "xsd:datetime hour");
	ptr += 2;
	if (*ptr++ != ':')
	    throw TypeError(s, "xsd:datetime hour-minute separator");

	l = strtol(ptr, &end, 10);
	if (l < 0 || l > 59 || end != ptr+2)
		throw TypeError(s, "xsd:datetime minute");
	ptr += 2;
	if (*ptr++ != ':')
	    throw TypeError(s, "xsd:datetime minute-second separator");

	l = strtol(ptr, &end, 10);
	if (l < 0 || l > 59 || end != ptr+2)
		throw TypeError(s, "xsd:datetime second");
	ptr += 2;

	if (*ptr == '.') {
	    ++ptr;
	    l = strtol(ptr, &end, 10);
	    if (l < 0 || end == ptr)
		throw TypeError(s, "xsd:datetime decimal seconds");
	    ptr = end;
	}

	if (*ptr == '+' || *ptr == '-') {
	    l = strtol(ptr, &end, 10);
	    if (l < 0 || l > 23 || end != ptr+2)
		throw TypeError(s, "xsd:datetime timezone hour");
	    ptr += 2;
	    if (*ptr++ != ':')
		throw TypeError(s, "xsd:datetime timezone hour-minute separator");

	    l = strtol(ptr, &end, 10);
	    if (l < 0 || l > 59 || end != ptr+2)
		throw TypeError(s, "xsd:datetime timezone minute");
	    ptr += 2;
	} else if (*ptr == 'Z') {
	    ptr++;
	}

	if (*ptr)
	    throw TypeError(s, "xsd:datetime (garbage at end)");
    }
};

int main () {

    DateTimeRDFLiteral d1("2010-09-17T10:29:01-4:00");
}

#if 0
  #include "boost/date_time/gregorian/gregorian.hpp"

  int boost() {

    namespace dt = boost::gregorian;

    try {
      // The following date is in ISO 8601 extended format (CCYY-MM-DD)
      std::string s("2001-10-9 asdf"); //2001-October-09
      dt::date d(dt::from_simple_string(s));
      std::cout << dt::to_simple_string(d) << std::endl;
      
      //Read ISO Standard(CCYYMMDD) and output ISO Extended
      std::string ud("20011009"); //2001-Oct-09
      dt::date d1(dt::from_undelimited_string(ud));
      std::cout << dt::to_iso_extended_string(d1) << std::endl;
      
      //Output the parts of the date - Tuesday October 9, 2001
      dt::date::ymd_type ymd = d1.year_month_day();
      dt::greg_weekday wd = d1.day_of_week();
      std::cout << wd.as_long_string() << " "
                << ymd.month.as_long_string() << " "
                << ymd.day << ", " << ymd.year
                << std::endl;

      //Let's send in month 25 by accident and create an exception
      std::string bad_date("20012509"); //2001-??-09
      std::cout << "An expected exception is next: " << std::endl;
      dt::date wont_construct(dt::from_undelimited_string(bad_date));
      //use wont_construct so compiler doesn't complain, but you wont get here!
      std::cout << "oh oh, you shouldn't reach this line: " 
                << dt::to_iso_string(wont_construct) << std::endl;
    }
    catch(std::exception& e) {
      std::cout << "  Exception: " <<  e.what() << std::endl;
    }


    return 0;
  }
#endif

