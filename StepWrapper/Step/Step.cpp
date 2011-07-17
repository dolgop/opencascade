////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Модуль: "w:/CAD/StepWrapper/Step/Step.cpp"
// генератор файлов реализации C++ (.cpp)
// Generated from UML model, root element: <<Interfaces::Category>> CAD::StepWrapper::Step
//
//
// Все права принадлежат ООО НПП "Гарант-Сервис".
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "shared/Core/sys/std_inc.h"
#include "CAD/StepWrapper/Step/Step.h"
#include "CAD/StepWrapper/Step/StepFactories.h"

namespace StepWrapper {
namespace Step {


const char* CantReadFile::uid () const /*throw ()*/ {
	return "9DA313BD-767C-479D-8003-6EA2E11712E6";
}

const char* CantReadFile::what () const throw () {
	//#UC START# *48AA868803AF_WHAT_IMPL*
	return "CantReadFile (Ошибка при чтении файла с данными)";
	//#UC END# *48AA868803AF_WHAT_IMPL*
}


const char* BadArgument::uid () const /*throw ()*/ {
	return "723AEF3B-D02F-4E18-B314-DD71CB48031C";
}

const char* BadArgument::what () const throw () {
	//#UC START# *48AA87A101F7_WHAT_IMPL*
	return "BadArgument (Аргумент функции выходит за границы допустимых значений)";
	//#UC END# *48AA87A101F7_WHAT_IMPL*
}

// factory interface wrapper for Location
Location* LocationFactory::make (
	const gp_Trsf& trsf
) /*throw (Core::Root::NoActiveFactory, Core::Root::FactoryManagerWasDestroyed)*/ {
	return LocationFactoryManager::Singleton::instance ()->make (trsf);
}

// factory interface wrapper for Face
Face* FaceFactory::make (
	const TopoDS_Face& id
) /*throw (Core::Root::NoActiveFactory, Core::Root::FactoryManagerWasDestroyed)*/ {
	return FaceFactoryManager::Singleton::instance ()->make (id);
}

// factory interface wrapper for NameWrapper
NameWrapper* NameWrapperFactory::make (
	const char* data
) /*throw (Core::Root::NoActiveFactory, Core::Root::FactoryManagerWasDestroyed)*/ {
	return NameWrapperFactoryManager::Singleton::instance ()->make (data);
}

// factory interface wrapper for Shape
Shape* ShapeFactory::make (
	const TDF_Label& id
	, const Handle_TDocStd_Document& doc
	, const TDF_Label& location_label
) /*throw (Core::Root::NoActiveFactory, Core::Root::FactoryManagerWasDestroyed)*/ {
	return ShapeFactoryManager::Singleton::instance ()->make (id, doc, location_label);
}

// factory interface wrapper for StepManager
StepManager* StepManagerFactory::make (
	const char* file_name
) /*throw (Core::Root::NoActiveFactory, Core::Root::FactoryManagerWasDestroyed, CantReadFile)*/ {
	return StepManagerFactoryManager::Singleton::instance ()->make (file_name);
}

} // namespace Step
} // namespace StepWrapper

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

