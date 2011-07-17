////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Модуль: "w:/CAD/StepWrapper/impl/Step_i/Shape_i_factory.cpp"
// генератор файлов реализации для фабрик интерфейсов (.cpp)
// Generated from UML model, root element: <<Servant::Class>> CAD::StepWrapper::Step_i::Shape_i
//
//
// Все права принадлежат ООО НПП "Гарант-Сервис".
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "shared/Core/sys/std_inc.h"
#include "CAD/StepWrapper/impl/Step_i/Shape_i_factory.h"
#include "CAD/StepWrapper/impl/Step_i/Shape_i.h"

namespace StepWrapper {
namespace Step_i {

Shape_i_factory::Shape_i_factory () {
}

void Shape_i_factory::registrate_me (
	Core::Root::FactoryPriority priority
) /*throw (
	Core::Root::DuplicatedFactoryKey
)*/ {
	Step::ShapeFactoryManager::register_factory (this, priority);
}

const char* Shape_i_factory::key () const {
	return "Shape_i";
}

Step::Shape* Shape_i_factory::make (
	const TDF_Label& id
	, const Handle_TDocStd_Document& doc
	, const TDF_Label& location_label
) {
	Shape_i_var ret = new Shape_i (id, doc, location_label);
	return ret._retn ();
}

} // namespace Step_i
} // namespace StepWrapper

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

