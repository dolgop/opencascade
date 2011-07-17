////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Модуль: "w:/CAD/StepWrapper/impl/Step_i/Location_i.h"
// генератор заголовочных файлов C++ (.h)
// Generated from UML model, root element: <<Servant::Class>> CAD::StepWrapper::Step_i::Location_i
// Заголовок реализации класса серванта для интерфеса Location
//
//
// Все права принадлежат ООО НПП "Гарант-Сервис".
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __CAD_STEPWRAPPER_STEP_I_LOCATION_I_H__
#define __CAD_STEPWRAPPER_STEP_I_LOCATION_I_H__

#include "shared/Core/sys/std_inc.h"
#include "CAD/StepWrapper/Step/Step.h"

//#UC START# *48BBADFD0084_CUSTOM_INCLUDES*
//#UC END# *48BBADFD0084_CUSTOM_INCLUDES*

namespace StepWrapper {
namespace Step_i {

class Location_i; // self forward Var
typedef ::Core::Var<Location_i> Location_i_var;
typedef ::Core::Var<const Location_i> Location_i_cvar;

class Location_i_factory;

class Location_i:
	virtual public Step::Location
	, virtual public ::Core::RefCountObjectBase
{
	SET_OBJECT_COUNTER (Location_i)
	friend class Location_i_factory; // self factory
//////////////////////////////////////////////////////////////////////////////////////////
// constructors and destructor
protected:
	Location_i (const gp_Trsf& trsf);

	virtual ~Location_i ();

//////////////////////////////////////////////////////////////////////////////////////////
// implemented interface's methods
protected:

	// implemented method from Step::Location
	virtual float get_index (size_t row, size_t column) const /*throw (Step::BadArgument)*/;

//#UC START# *48BBADFD0084*
public:
	static double is_zero (double value);

private:
	static const size_t rows= 4;
	static const size_t columns = 4;

	double m_transformation_matrix[rows][columns];
//#UC END# *48BBADFD0084*
}; // class Location_i

} // namespace Step_i
} // namespace StepWrapper


#endif //__CAD_STEPWRAPPER_STEP_I_LOCATION_I_H__
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
