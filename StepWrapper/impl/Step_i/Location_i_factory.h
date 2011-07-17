////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Модуль: "w:/CAD/StepWrapper/impl/Step_i/Location_i_factory.h"
// генератор заголовочных файлов для фабрик интерфейсов (.h)
// Generated from UML model, root element: <<Servant::Class>> CAD::StepWrapper::Step_i::Location_i
// Заголовк реализации фабрик интерфеса Location для серванта Location_i
//
//
// Все права принадлежат ООО НПП "Гарант-Сервис".
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __CAD_STEPWRAPPER_STEP_I_LOCATION_I_FCTR_H__
#define __CAD_STEPWRAPPER_STEP_I_LOCATION_I_FCTR_H__

#include "shared/Core/sys/std_inc.h"
#include "CAD/StepWrapper/Step/StepFactories.h"

namespace StepWrapper {
namespace Step_i {

/// Interface-factory implementation for Location_i
class Location_i_factory: virtual public ::Core::RefCountObjectBase, virtual public Step::LocationAbstractFactory {
public:
	Location_i_factory ();

	void registrate_me (Core::Root::FactoryPriority priority) /*throw (Core::Root::DuplicatedFactoryKey)*/;

protected:
	const char* key () const;

	Step::Location* make (const gp_Trsf& trsf);

};

typedef ::Core::Var<Location_i_factory> Location_i_factory_var;

} // namespace Step_i
} // namespace StepWrapper


#endif //__CAD_STEPWRAPPER_STEP_I_LOCATION_I_FCTR_H__
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

