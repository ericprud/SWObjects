
/* RdfQueryDB - sets of variable bindings and their proofs.
 * $Id: RdfQueryDB.cpp,v 1.3 2008-10-24 10:57:30 eric Exp $
 */

#include "RdfQueryDB.hpp"

namespace w3c_sw {

    RdfQueryDB::RdfQueryDB (TableOperation* p_op, POSFactory* posFactory) : RdfDB(), top(p_op) {
	DBExpressor ex(this, posFactory);
	p_op->express(&ex);
    }

} // namespace w3c_sw

