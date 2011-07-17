////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Модуль: "w:/CAD/StepWrapper/impl/Step_i/Shape_i_factory.h"
// генератор заголовочных файлов для фабрик интерфейсов (.h)
// Generated from UML model, root element: <<Servant::Class>> CAD::StepWrapper::Step_i::Shape_i
// Заголовк реализации фабрик интерфеса Shape для серванта Shape_i
//
//
// Все права принадлежат ООО НПП "Гарант-Сервис".
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __CAD_STEPWRAPPER_STEP_I_SHAPE_I_FCTR_H__
#define __CAD_STEPWRAPPER_STEP_I_SHAPE_I_FCTR_H__

#include "shared/Core/sys/std_inc.h"
#include "CAD/StepWrapper/Step/StepFactories.h"

namespace StepWrapper {
namespace Step_i {

/// Interface-factory implementation for Shape_i
class Shape_i_factory: virtual public ::Core::RefCountObjectBase, virtual public Step::ShapeAbstractFactory {
public:
	Shape_i_factory ();

	void registrate_me (Core::Root::FactoryPriority priority) /*throw (Core::Root::DuplicatedFactoryKey)*/;

protected:
	const char* key () const;

	Step::Shape* make (const TDF_Label& id, const Handle_TDocStd_Document& doc, const TDF_Label& location_label);

};

typedef ::Core::Var<Shape_i_factory> Shape_i_factory_var;

} // namespace Step_i
} // namespace StepWrapper


#endif //__CAD_STEPWRAPPER_STEP_I_SHAPE_I_FCTR_H__
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

