////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Модуль: "w:/CAD/StepWrapper/impl/Step_i/NameWrapper_i.cpp"
// генератор файлов реализации C++ (.cpp)
// Generated from UML model, root element: <<Servant::Class>> CAD::StepWrapper::Step_i::NameWrapper_i
//
//
// Все права принадлежат ООО НПП "Гарант-Сервис".
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "shared/Core/sys/std_inc.h"
#include "CAD/StepWrapper/LibHome.h"
#include "CAD/StepWrapper/impl/Step_i/NameWrapper_i.h"

//#UC START# *48BB90890246_CUSTOM_INCLUDES*
//#UC END# *48BB90890246_CUSTOM_INCLUDES*

namespace StepWrapper {
namespace Step_i {

//#UC START# *48BB90890246*
//#UC END# *48BB90890246*

//////////////////////////////////////////////////////////////////////////////////////////
// constructors and destructor

NameWrapper_i::NameWrapper_i (const char* data)
//#UC START# *48BB9026001B_48BB906C01DC_48BB90890246_BASE_INIT*
: m_name (data)
//#UC END# *48BB9026001B_48BB906C01DC_48BB90890246_BASE_INIT*
{
	//#UC START# *48BB9026001B_48BB906C01DC_48BB90890246_BODY*
	//#UC END# *48BB9026001B_48BB906C01DC_48BB90890246_BODY*
}

NameWrapper_i::~NameWrapper_i () {
	//#UC START# *48BB90890246_DESTR_BODY*
	//#UC END# *48BB90890246_DESTR_BODY*
}


//////////////////////////////////////////////////////////////////////////////////////////
// implemented interface's methods

// implemented method from Step::NameWrapper
const char* NameWrapper_i::get_name () const {
	//#UC START# *48BB91480179_48BB90890246*
	return m_name.c_str ();
	//#UC END# *48BB91480179_48BB90890246*
}
} // namespace Step_i
} // namespace StepWrapper

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

