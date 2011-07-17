////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Модуль: "w:/CAD/StepWrapper/LibHome.cpp"
// генератор файлов реализации C++ (.cpp)
// Generated from UML model, root element: <<Library::Category>> CAD::StepWrapper
//
//
// Все права принадлежат ООО НПП "Гарант-Сервис".
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "CAD/StepWrapper/LibHome.h"
#include "CAD/StepWrapper/impl/Step_i/StepManager_i_factory.h"
#include "CAD/StepWrapper/impl/Step_i/Shape_i_factory.h"
#include "CAD/StepWrapper/impl/Step_i/Face_i_factory.h"
#include "CAD/StepWrapper/impl/Step_i/NameWrapper_i_factory.h"
#include "CAD/StepWrapper/impl/Step_i/Location_i_factory.h"

namespace StepWrapper {

Core::Root::LibHome& LibHomeFactory::get () {
	return LibHomeImpl::Singleton::instance();
}

LibHomeImpl::LibHomeImpl () {
}

void LibHomeImpl::registrate_all_factories () const {
	//#UC START# *489BF29500F3_ENVIRONMENTS_CONFIG*
	//#UC END# *489BF29500F3_ENVIRONMENTS_CONFIG*

	{
		Step_i::StepManager_i_factory_var fctr = new Step_i::StepManager_i_factory ();
		fctr->registrate_me(0);
	}
	
	{
		Step_i::Shape_i_factory_var fctr = new Step_i::Shape_i_factory ();
		fctr->registrate_me(0);
	}
	
	{
		Step_i::Face_i_factory_var fctr = new Step_i::Face_i_factory ();
		fctr->registrate_me(0);
	}
	
	{
		Step_i::NameWrapper_i_factory_var fctr = new Step_i::NameWrapper_i_factory ();
		fctr->registrate_me(0);
	}
	
	{
		Step_i::Location_i_factory_var fctr = new Step_i::Location_i_factory ();
		fctr->registrate_me(0);
	}
	
}
	
void LibHomeImpl::finalize () {
}
} // namespace StepWrapper

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
