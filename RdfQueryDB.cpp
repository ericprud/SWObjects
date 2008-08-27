/* RdfQueryDB - sets of variable bindings and their proofs.
 * $Id: RdfQueryDB.cpp,v 1.2 2008-08-27 02:21:41 eric Exp $
 */

#include "RdfQueryDB.hpp"

namespace w3c_sw {

    RdfQueryDB::RdfQueryDB (Operation* p_op) : RdfDB(), op(p_op) {
	DBExpressor ex(this);
	p_op->express(&ex);
    }

    RdfQueryDB::RdfQueryDB (TableOperation* p_op) : RdfDB(), top(p_op) {
	DBExpressor ex(this);
	p_op->express(&ex);
    }

} // namespace w3c_sw

