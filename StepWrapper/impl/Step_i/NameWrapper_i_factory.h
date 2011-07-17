////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Модуль: "w:/CAD/StepWrapper/impl/Step_i/NameWrapper_i_factory.h"
// генератор заголовочных файлов для фабрик интерфейсов (.h)
// Generated from UML model, root element: <<Servant::Class>> CAD::StepWrapper::Step_i::NameWrapper_i
// Заголовк реализации фабрик интерфеса NameWrapper для серванта NameWrapper_i
//
//
// Все права принадлежат ООО НПП "Гарант-Сервис".
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __CAD_STEPWRAPPER_STEP_I_NAMEWRAPPER_I_FCTR_H__
#define __CAD_STEPWRAPPER_STEP_I_NAMEWRAPPER_I_FCTR_H__

#include "shared/Core/sys/std_inc.h"
#include "CAD/StepWrapper/Step/StepFactories.h"

namespace StepWrapper {
namespace Step_i {

/// Interface-factory implementation for NameWrapper_i
class NameWrapper_i_factory:
	virtual public ::Core::RefCountObjectBase
	, virtual public Step::NameWrapperAbstractFactory
{
public:
	NameWrapper_i_factory ();

	void registrate_me (Core::Root::FactoryPriority priority) /*throw (Core::Root::DuplicatedFactoryKey)*/;

protected:
	const char* key () const;

	Step::NameWrapper* make (const char* data);

};

typedef ::Core::Var<NameWrapper_i_factory> NameWrapper_i_factory_var;

} // namespace Step_i
} // namespace StepWrapper


#endif //__CAD_STEPWRAPPER_STEP_I_NAMEWRAPPER_I_FCTR_H__
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

