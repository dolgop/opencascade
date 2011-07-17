////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Модуль: "w:/CAD/StepWrapper/impl/Step_i/StepManager_i_factory.h"
// генератор заголовочных файлов для фабрик интерфейсов (.h)
// Generated from UML model, root element: <<Servant::Class>> CAD::StepWrapper::Step_i::StepManager_i
// Заголовк реализации фабрик интерфеса StepManager для серванта StepManager_i
//
//
// Все права принадлежат ООО НПП "Гарант-Сервис".
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __CAD_STEPWRAPPER_STEP_I_STEPMANAGER_I_FCTR_H__
#define __CAD_STEPWRAPPER_STEP_I_STEPMANAGER_I_FCTR_H__

#include "shared/Core/sys/std_inc.h"
#include "CAD/StepWrapper/Step/StepFactories.h"

namespace StepWrapper {
namespace Step_i {

/// Interface-factory implementation for StepManager_i
class StepManager_i_factory:
	virtual public ::Core::RefCountObjectBase
	, virtual public Step::StepManagerAbstractFactory
{
public:
	StepManager_i_factory ();

	void registrate_me (Core::Root::FactoryPriority priority) /*throw (Core::Root::DuplicatedFactoryKey)*/;

protected:
	const char* key () const;

	Step::StepManager* make (const char* file_name) /*throw (Step::CantReadFile)*/;

};

typedef ::Core::Var<StepManager_i_factory> StepManager_i_factory_var;

} // namespace Step_i
} // namespace StepWrapper


#endif //__CAD_STEPWRAPPER_STEP_I_STEPMANAGER_I_FCTR_H__
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

