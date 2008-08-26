/* RdfQueryDB - sets of variable bindings and their proofs.
 * $Id: RdfQueryDB.cpp,v 1.1 2008-08-26 05:30:47 jnorthru Exp $
 */

#include "RdfQueryDB.hpp"

namespace SPARQLfedNS {

    RdfQueryDB::RdfQueryDB (Operation* p_op) : RdfDB(), op(p_op) {
	DBExpressor ex(this);
	p_op->express(&ex);
    }

    RdfQueryDB::RdfQueryDB (TableOperation* p_op) : RdfDB(), top(p_op) {
	DBExpressor ex(this);
	p_op->express(&ex);
    }

} // namespace SPARQLfedNS

