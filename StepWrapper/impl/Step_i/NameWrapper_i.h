////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Модуль: "w:/CAD/StepWrapper/impl/Step_i/NameWrapper_i.h"
// генератор заголовочных файлов C++ (.h)
// Generated from UML model, root element: <<Servant::Class>> CAD::StepWrapper::Step_i::NameWrapper_i
// Заголовок реализации класса серванта для интерфеса NameWrapper
//
//
// Все права принадлежат ООО НПП "Гарант-Сервис".
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __CAD_STEPWRAPPER_STEP_I_NAMEWRAPPER_I_H__
#define __CAD_STEPWRAPPER_STEP_I_NAMEWRAPPER_I_H__

#include "shared/Core/sys/std_inc.h"
#include "CAD/StepWrapper/Step/Step.h"

//#UC START# *48BB90890246_CUSTOM_INCLUDES*
//#UC END# *48BB90890246_CUSTOM_INCLUDES*

namespace StepWrapper {
namespace Step_i {

class NameWrapper_i; // self forward Var
typedef ::Core::Var<NameWrapper_i> NameWrapper_i_var;
typedef ::Core::Var<const NameWrapper_i> NameWrapper_i_cvar;

class NameWrapper_i_factory;

class NameWrapper_i:
	virtual public Step::NameWrapper
	, virtual public ::Core::RefCountObjectBase
{
	SET_OBJECT_COUNTER (NameWrapper_i)
	friend class NameWrapper_i_factory; // self factory
//////////////////////////////////////////////////////////////////////////////////////////
// constructors and destructor
protected:
	NameWrapper_i (const char* data);

	virtual ~NameWrapper_i ();

//////////////////////////////////////////////////////////////////////////////////////////
// implemented interface's methods
protected:

	// implemented method from Step::NameWrapper
	virtual const char* get_name () const;

//#UC START# *48BB90890246*
private:
	std::string m_name;
//#UC END# *48BB90890246*
}; // class NameWrapper_i

} // namespace Step_i
} // namespace StepWrapper


#endif //__CAD_STEPWRAPPER_STEP_I_NAMEWRAPPER_I_H__
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
