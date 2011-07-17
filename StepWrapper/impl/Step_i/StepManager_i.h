////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Модуль: "w:/CAD/StepWrapper/impl/Step_i/StepManager_i.h"
// генератор заголовочных файлов C++ (.h)
// Generated from UML model, root element: <<Servant::Class>> CAD::StepWrapper::Step_i::StepManager_i
// Заголовок реализации класса серванта для интерфеса StepManager
//
//
// Все права принадлежат ООО НПП "Гарант-Сервис".
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __CAD_STEPWRAPPER_STEP_I_STEPMANAGER_I_H__
#define __CAD_STEPWRAPPER_STEP_I_STEPMANAGER_I_H__

#include "shared/Core/sys/std_inc.h"
#include "CAD/StepWrapper/Step/Step.h"

//#UC START# *489BF3290347_CUSTOM_INCLUDES*
#include <map>

#include <TDF_Label.hxx>

#include <XCAFApp_Application.hxx>
//#UC END# *489BF3290347_CUSTOM_INCLUDES*

namespace StepWrapper {
namespace Step_i {

class StepManager_i; // self forward Var
typedef ::Core::Var<StepManager_i> StepManager_i_var;
typedef ::Core::Var<const StepManager_i> StepManager_i_cvar;

class StepManager_i_factory;

class StepManager_i:
	virtual public Step::StepManager
	, virtual public ::Core::RefCountObjectBase
{
	SET_OBJECT_COUNTER (StepManager_i)
	friend class StepManager_i_factory; // self factory
//////////////////////////////////////////////////////////////////////////////////////////
// constructors and destructor
protected:
	StepManager_i (const char* file_name);

	virtual ~StepManager_i ();

//////////////////////////////////////////////////////////////////////////////////////////
// implemented interface's methods
protected:

	// implemented method from Step::StepManager
	// Возвращает заданную фигуру верхнего уровня
	virtual Step::Shape* get_root (size_t index) const /*throw (Step::BadArgument)*/;

	// implemented method from Step::StepManager
	// Количество фигур верхнего уровня (не являющихся частью других фигур)
	virtual size_t get_roots_count () const;

//#UC START# *489BF3290347*
private:
	Handle(TDocStd_Document) m_doc;
//#UC END# *489BF3290347*
}; // class StepManager_i

} // namespace Step_i
} // namespace StepWrapper


#endif //__CAD_STEPWRAPPER_STEP_I_STEPMANAGER_I_H__
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
