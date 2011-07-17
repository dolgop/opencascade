////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Модуль: "w:/CAD/StepWrapper/impl/Step_i/Face_i_factory.cpp"
// генератор файлов реализации для фабрик интерфейсов (.cpp)
// Generated from UML model, root element: <<Servant::Class>> CAD::StepWrapper::Step_i::Face_i
//
//
// Все права принадлежат ООО НПП "Гарант-Сервис".
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "shared/Core/sys/std_inc.h"
#include "CAD/StepWrapper/impl/Step_i/Face_i_factory.h"
#include "CAD/StepWrapper/impl/Step_i/Face_i.h"

namespace StepWrapper {
namespace Step_i {

Face_i_factory::Face_i_factory () {
}

void Face_i_factory::registrate_me (
	Core::Root::FactoryPriority priority
) /*throw (
	Core::Root::DuplicatedFactoryKey
)*/ {
	Step::FaceFactoryManager::register_factory (this, priority);
}

const char* Face_i_factory::key () const {
	return "Face_i";
}

Step::Face* Face_i_factory::make (const TopoDS_Face& id) {
	Face_i_var ret = new Face_i (id);
	return ret._retn ();
}

} // namespace Step_i
} // namespace StepWrapper

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

