////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Модуль: "w:/CAD/StepWrapper/impl/Step_i/Face_i.h"
// генератор заголовочных файлов C++ (.h)
// Generated from UML model, root element: <<Servant::Class>> CAD::StepWrapper::Step_i::Face_i
// Заголовок реализации класса серванта для интерфеса Face
//
//
// Все права принадлежат ООО НПП "Гарант-Сервис".
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __CAD_STEPWRAPPER_STEP_I_FACE_I_H__
#define __CAD_STEPWRAPPER_STEP_I_FACE_I_H__

#include "shared/Core/sys/std_inc.h"
#include "CAD/StepWrapper/Step/Step.h"

//#UC START# *48AD6B0E03B4_CUSTOM_INCLUDES*
#include <TopoDS_Face.hxx>
//#UC END# *48AD6B0E03B4_CUSTOM_INCLUDES*

namespace StepWrapper {
namespace Step_i {

class Face_i; // self forward Var
typedef ::Core::Var<Face_i> Face_i_var;
typedef ::Core::Var<const Face_i> Face_i_cvar;

class Face_i_factory;

class Face_i:
	virtual public Step::Face
	, virtual public ::Core::RefCountObjectBase
{
	SET_OBJECT_COUNTER (Face_i)
	friend class Face_i_factory; // self factory
//////////////////////////////////////////////////////////////////////////////////////////
// constructors and destructor
protected:
	Face_i (const TopoDS_Face& id);

	virtual ~Face_i ();

//////////////////////////////////////////////////////////////////////////////////////////
// implemented interface's methods
protected:

	// implemented method from Step::Face
	virtual Step::Location* get_location () const;

	// implemented method from Step::Face
	virtual Step::PointsTable* get_normals_table () const;

	// implemented method from Step::Face
	virtual Step::PointsTable* get_points_table () const;

	// implemented method from Step::Face
	virtual Step::TrianglesTable* get_triangles_table () const;

	// implemented method from Step::Face
	virtual Step::PointsTable* get_wire_points (size_t index) const;

	// implemented method from Step::Face
	// Количество wires для данного face
	virtual size_t get_wires_count () const;

//#UC START# *48AD6B0E03B4*
private:
	TopoDS_Face m_face;
//#UC END# *48AD6B0E03B4*
}; // class Face_i

} // namespace Step_i
} // namespace StepWrapper


#endif //__CAD_STEPWRAPPER_STEP_I_FACE_I_H__
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
