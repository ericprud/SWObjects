#include "SWObjects.hpp"

w3c_sw::AtomicFunction::FPtr my_chatty_concat;
const w3c_sw::TTerm* my_chatty_concat (const w3c_sw::URI* name, std::vector<const w3c_sw::TTerm*>& args, w3c_sw::AtomFactory* atomFactory) {
    std::stringstream ss;
    ss << "CONCAT(";
    for (std::vector<const w3c_sw::TTerm*>::const_iterator sub = args.begin();
	 sub != args.end(); ++sub) {
	if (sub != args.begin())
	    ss << ", ";
	const w3c_sw::RDFLiteral* s = dynamic_cast<const w3c_sw::RDFLiteral*>(*sub);
	if (s == NULL || (s->getDatatype() != NULL && s->getDatatype() != w3c_sw::TTerm::URI_xsd_string) || s->getLangtag() != NULL)
	    throw w3c_sw::TypeError(std::string("unexpected ") + (s ? s->toString() : std::string("NULL")), "concat");
	else
	    ss << s->toString();
    }
    ss << ") yields " << w3c_sw::AtomicFunction::BuiltIn::concat(name, args, atomFactory)->toString();
    return atomFactory->getRDFLiteral(ss.str(), NULL, NULL, false);
}

#ifdef  __cplusplus
extern "C" {
#endif

    w3c_sw::AtomicFunction::Library::Initialize initialize;
    void initialize (w3c_sw::AtomicFunction::Map* map, w3c_sw::AtomFactory* atomFactory) {
	map->add(atomFactory->getURI("tag:eric@w3.org,2012-swobjfunc/chatty_concat"), 1, 999, &my_chatty_concat);
    }

#ifdef  __cplusplus
}
#endif
