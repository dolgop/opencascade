////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Модуль: "w:/CAD/StepWrapper/impl/Step_i/Location_i.cpp"
// генератор файлов реализации C++ (.cpp)
// Generated from UML model, root element: <<Servant::Class>> CAD::StepWrapper::Step_i::Location_i
//
//
// Все права принадлежат ООО НПП "Гарант-Сервис".
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "shared/Core/sys/std_inc.h"
#include "CAD/StepWrapper/LibHome.h"
#include "CAD/StepWrapper/impl/Step_i/Location_i.h"

//#UC START# *48BBADFD0084_CUSTOM_INCLUDES*
//#UC END# *48BBADFD0084_CUSTOM_INCLUDES*

namespace StepWrapper {
namespace Step_i {

//#UC START# *48BBADFD0084*
double Location_i::is_zero (double value) {
	const Standard_Real delta = 0.00000001;

	if (!(value > 0) && !(value < 0))
		return 0;
	if ((value > 0) && (value  < delta))
		return 0;
	if ((value < 0) && (-value < delta))
		return 0;

	return value;
}
//#UC END# *48BBADFD0084*

//////////////////////////////////////////////////////////////////////////////////////////
// constructors and destructor

Location_i::Location_i (const gp_Trsf& trsf)
//#UC START# *48BBAADE00D5_48BBAB650209_48BBADFD0084_BASE_INIT*
//#UC END# *48BBAADE00D5_48BBAB650209_48BBADFD0084_BASE_INIT*
{
	//#UC START# *48BBAADE00D5_48BBAB650209_48BBADFD0084_BODY*
	for (unsigned char row = 1; row <= (rows - 1); ++row) {
		for (unsigned char column = 1; column <= columns; ++column) {
			m_transformation_matrix[row -1][column - 1] = Location_i::is_zero (trsf.Value (row, column));
		}
	}
	m_transformation_matrix[rows - 1][0] = 0;
	m_transformation_matrix[rows - 1][1] = 0;
	m_transformation_matrix[rows - 1][2] = 0;
	m_transformation_matrix[rows - 1][3] = 1;
	//#UC END# *48BBAADE00D5_48BBAB650209_48BBADFD0084_BODY*
}

Location_i::~Location_i () {
	//#UC START# *48BBADFD0084_DESTR_BODY*
	//#UC END# *48BBADFD0084_DESTR_BODY*
}


//////////////////////////////////////////////////////////////////////////////////////////
// implemented interface's methods

// implemented method from Step::Location
float Location_i::get_index (size_t row, size_t column) const /*throw (Step::BadArgument)*/ {
	//#UC START# *48BBAB1202E1_48BBADFD0084*
	if ((row > (rows - 1)) || (column > (columns - 1))) {
		throw Step::BadArgument ();
	}
	return static_cast<float> (m_transformation_matrix[row][column]);
	//#UC END# *48BBAB1202E1_48BBADFD0084*
}
} // namespace Step_i
} // namespace StepWrapper

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

