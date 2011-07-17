////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Модуль: "w:/CAD/StepWrapper/impl/Step_i/Location_i_factory.cpp"
// генератор файлов реализации для фабрик интерфейсов (.cpp)
// Generated from UML model, root element: <<Servant::Class>> CAD::StepWrapper::Step_i::Location_i
//
//
// Все права принадлежат ООО НПП "Гарант-Сервис".
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "shared/Core/sys/std_inc.h"
#include "CAD/StepWrapper/impl/Step_i/Location_i_factory.h"
#include "CAD/StepWrapper/impl/Step_i/Location_i.h"

namespace StepWrapper {
namespace Step_i {

Location_i_factory::Location_i_factory () {
}

void Location_i_factory::registrate_me (
	Core::Root::FactoryPriority priority
) /*throw (
	Core::Root::DuplicatedFactoryKey
)*/ {
	Step::LocationFactoryManager::register_factory (this, priority);
}

const char* Location_i_factory::key () const {
	return "Location_i";
}

Step::Location* Location_i_factory::make (const gp_Trsf& trsf) {
	Location_i_var ret = new Location_i (trsf);
	return ret._retn ();
}

} // namespace Step_i
} // namespace StepWrapper

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

