////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Модуль: "w:/CAD/StepWrapper/impl/Step_i/StepManager_i_factory.cpp"
// генератор файлов реализации для фабрик интерфейсов (.cpp)
// Generated from UML model, root element: <<Servant::Class>> CAD::StepWrapper::Step_i::StepManager_i
//
//
// Все права принадлежат ООО НПП "Гарант-Сервис".
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "shared/Core/sys/std_inc.h"
#include "CAD/StepWrapper/impl/Step_i/StepManager_i_factory.h"
#include "CAD/StepWrapper/impl/Step_i/StepManager_i.h"

namespace StepWrapper {
namespace Step_i {

StepManager_i_factory::StepManager_i_factory () {
}

void StepManager_i_factory::registrate_me (
	Core::Root::FactoryPriority priority
) /*throw (
	Core::Root::DuplicatedFactoryKey
)*/ {
	Step::StepManagerFactoryManager::register_factory (this, priority);
}

const char* StepManager_i_factory::key () const {
	return "StepManager_i";
}

Step::StepManager* StepManager_i_factory::make (const char* file_name) /*throw (Step::CantReadFile)*/ {
	StepManager_i_var ret = new StepManager_i (file_name);
	return ret._retn ();
}

} // namespace Step_i
} // namespace StepWrapper

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

