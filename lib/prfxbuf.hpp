//----------------------------------------------------------------------------
// The constructor of the prfxbuf initializes its pointer to the streambuf
// with the argument sb: It is assumed that this streambuf is initialized
// correctly.  In addition no ownership is assumed for this streambuf. It
// is not deleted in the destructor.  Then the length of the prefix string
// is cached and the prefix string is copied into a private version: This
// is done to avoid problems when the user modifies or deletes the string
// passed as constructor argument. The member i_newline is set to indicate
// that the processing it at the beginning of a new line: in either case
// (reading or writing) it starts with a new line. When reading a file a
// prefix has to be skipped and when writing a file a prefix has to be
// added. EOF is used to indicate that the cache does not contain any
// valid character.
// <BR>
// In the body of the constructor the put area and the get area are

// initialized to be empty: no buffering is done by this streambuf. All
// buffering is deferred to the actually used streambuf. This makes sure
// that the function overflow() is called whenever a character is written
// to this streambuf and that the function underflow() is called whenever
// a character is read from this streambuf. The put buffer is specified
// using streambuf::setp() and the get buffer is specified using
// streambuf::setg().
// <PRE>
// </PRE>

// The destructor of prfxbuf has to release the copy of the prefix.
// <PRE>
// </PRE>
//----------------------------------------------------------------------------
// <HR>
// Please send comments, suggestions, problem reports, bug fixes etc. to
// <BR>
// <A HREF="http://www.informatik.uni-konstanz.de/~kuehl"><I>Dietmar Kühl</I></A>:
// <A HREF="mailto:dietmar.kuehl@claas-solutions.de">Dietmar.Kuehl@claas-solutions.de</A>

#ifndef prfxbuf_H
#define prfxbuf_H

#include <cstdio>
#include <cstring>
#include <streambuf>
#include <ios>
#include <ostream>

#include <istream>
#include <vector>

class prfxbuf: public std::streambuf {

protected:
    std::streambuf	*i_sbuf;	// the actual streambuf used to read and write chars
    std::streamsize	i_len;		// the length of the prefix
    char		*i_prfx;	// the prefix
    bool		i_newline;	// remember whether we are at a new line
    int		i_cache;	// may cache a read character

    std::vector<char> i_buf; 
    bool skip_prefix () {

	if (i_sbuf->sgetn(&i_buf[0], i_len) != i_len)
	    return false;
	if (std::strncmp(&i_buf[0], i_prfx, i_len)) {
	    // an expection could be thrown here...
	    return false;
	}

	i_newline = false;
	return true;
    } 

    int overflow (int c) {
	if (c != EOF) {
	    if (i_newline) {
		if (i_sbuf->sputn(i_prfx, i_len) != i_len)
		    return EOF;
		else
		    i_newline = false; 
	    }
	    char cc = traits_type::to_char_type(c);
	    int rc = i_sbuf->sputc(cc);

	    if (cc == '\n')
		i_newline = true;
	    return rc;
	}
	return 0;
    } 
    int underflow () {
	if (i_cache == EOF) {
	    if (i_newline)

		if (!skip_prefix())
		    return EOF; 
	    i_cache = i_sbuf->sbumpc();
	    if (i_cache == traits_type::to_int_type('\n'))
		i_newline = true;
	    return i_cache;
	}
	else

	    return i_cache;
    } 
    int uflow () {
	if (i_cache == EOF) {
	    if (i_newline)
		if (!skip_prefix())

		    return EOF; 
	    int rc = i_sbuf->sbumpc();
	    if (rc == traits_type::to_int_type('\n'))
		i_newline = true;
	    return rc;
	} else {

	    int rc = i_cache;
	    i_cache = EOF;
	    return rc;
	}
    }

    int sync () {
	return i_sbuf->pubsync();
    } 
public:
    prfxbuf (std::streambuf *sb, const char *prfx):
	std::streambuf(), i_sbuf(sb), i_len(0), 
	i_prfx(NULL), i_newline(true), i_cache(EOF), i_buf(1)
    {
	prefix(prfx);
	setp(0, 0);
	setg(0, 0, 0);
    }
    ~prfxbuf () {
	delete[] i_prfx;
    }
    void prefix (const char* prfx) {
	i_len = std::strlen(prfx);
	if (i_prfx)
	    delete[] i_prfx;
	i_prfx = std::strcpy(new char[i_len + 1], prfx);
	i_buf.resize(i_len);
    }
};  
class iprfxstream: public std::istream
{
    prfxbuf* b;
public:
    iprfxstream (std::streambuf *sb, const char *prfx):
	std::istream(new prfxbuf(sb, prfx)), b((prfxbuf*)rdbuf())
    {  } 
    ~iprfxstream () {
	delete rdbuf();
    } 
    void prefix (const char* prfx) {
	b->prefix(prfx);
    }
}; 
class oprfxstream: public std::ostream
{
    prfxbuf* b;
public:
    oprfxstream (std::streambuf *sb, const char *prfx = ""):
	std::ostream(new prfxbuf(sb, prfx)), b((prfxbuf*)rdbuf())
    {  } 
    ~oprfxstream () {
	delete rdbuf();
    }
    void prefix (const char* prfx) {
	b->prefix(prfx);
    }
}; 

#endif /* !prfxbuf_H */

#ifdef TEST_PRFXBUF

#include <iostream>
#include <sstream>

int main () {
    std::ostream* debugStreamP = &std::cout;
    std::ostream** debugStream = &debugStreamP;


    oprfxstream coutstream((*debugStream)->rdbuf(), "Test prefix: ");
    std::ostream* debugStreamQ = &coutstream;
    std::ostream** oldDebugStream = debugStream;
    debugStream = &debugStreamQ;
    (**debugStream) << "This should have been prefixed.\nAlong with this.";
    coutstream.prefix("Prefix two: ");
    (**debugStream) << "\n" << 10 << std::endl;
    coutstream.prefix("Prefix three: ");
    (**debugStream) << "\n" << 3.14 << std::endl;
    debugStream = oldDebugStream;

    coutstream.flush();

    std::stringstream ss;
    oprfxstream strstream(ss.rdbuf());
    strstream.prefix("Test prefix: ");
    strstream << "This should have been prefixed.\nAlong with this.";
    strstream.prefix("Prefix two: ");
    strstream << "\n" << 10 << std::endl;
    strstream.prefix("Prefix three: ");
    strstream << "\n" << 3.14 << std::endl;
    std::cout << "begin [[" << std::endl;
    std::cout << ss.str();
    std::cout << "]] end" << std::endl;
    return 0;
}

#endif /* TEST_PRFXBUF */

