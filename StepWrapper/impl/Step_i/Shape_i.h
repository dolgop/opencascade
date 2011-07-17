////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Модуль: "w:/CAD/StepWrapper/impl/Step_i/Shape_i.h"
// генератор заголовочных файлов C++ (.h)
// Generated from UML model, root element: <<Servant::Class>> CAD::StepWrapper::Step_i::Shape_i
// Заголовок реализации класса серванта для интерфеса Shape
//
//
// Все права принадлежат ООО НПП "Гарант-Сервис".
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __CAD_STEPWRAPPER_STEP_I_SHAPE_I_H__
#define __CAD_STEPWRAPPER_STEP_I_SHAPE_I_H__

#include "shared/Core/sys/std_inc.h"
#include "CAD/StepWrapper/Step/Step.h"

//#UC START# *48AD6AED0331_CUSTOM_INCLUDES*
#include <TDataStd_Name.hxx>
#include <TDF_Label.hxx>
#include <TDocStd_Document.hxx>
#include <TopoDS_Face.hxx>
//#UC END# *48AD6AED0331_CUSTOM_INCLUDES*

namespace StepWrapper {
namespace Step_i {

class Shape_i; // self forward Var
typedef ::Core::Var<Shape_i> Shape_i_var;
typedef ::Core::Var<const Shape_i> Shape_i_cvar;

class Shape_i_factory;

class Shape_i:
	virtual public Step::Shape
	, virtual public ::Core::RefCountObjectBase
{
	SET_OBJECT_COUNTER (Shape_i)
	friend class Shape_i_factory; // self factory
//////////////////////////////////////////////////////////////////////////////////////////
// constructors and destructor
protected:
	Shape_i (const TDF_Label& id, const Handle_TDocStd_Document& doc, const TDF_Label& location_label);

	virtual ~Shape_i ();

//////////////////////////////////////////////////////////////////////////////////////////
// implemented interface's methods
protected:

	// implemented method from Step::Shape
	// параметр, задающий точность триангуляции
	virtual const double get_deflection () const;

	virtual void set_deflection (double deflection);

	// implemented method from Step::Shape
	// возвращает список поверхностей для всех фигур, входящих в заданную (включая её саму)
	virtual Step::FaceList* get_all_face_list () const;

	// implemented method from Step::Shape
	// Возвращает список дочерних фигур для заданной
	virtual Step::ShapeList* get_children_list () const;

	// implemented method from Step::Shape
	// возвращает список поверхностей для заданной фигуры
	virtual Step::FaceList* get_face_list () const;

	// implemented method from Step::Shape
	virtual const TDF_Label& get_label () const;

	// implemented method from Step::Shape
	// координаты текущей фигуры
	virtual Step::Location* get_location () const;

	// implemented method from Step::Shape
	// возвращает топологический объект, являющийся отцом заданного
	virtual Step::Shape* get_original_shape () const;

	// implemented method from Step::Shape
	// вернуть тип топологического объекта
	virtual Step::ShapeType get_type () const;

	// implemented method from Step::Shape
	// замкнута ли поверхность
	virtual bool is_closed () const;

	// implemented method from Step::Shape
	// сравнивает 2 фигуры на равенство
	virtual bool is_equal (const Step::Shape* to_compare) const;

	// implemented method from Step::Shape
	// имя конкретной фигуры
	virtual const Step::NameWrapper& get_local_name () const;

	// implemented method from Step::Shape
	// имя топологической фигуры, являющейся базовой для данной
	virtual const Step::NameWrapper& get_main_name () const;

//#UC START# *48AD6AED0331*
private:
	size_t get_children_face_count () const;
	size_t get_face_count () const;

	typedef std::vector<TopoDS_Face> MyFaceList;
	typedef std::pair<TopoDS_Face, TopLoc_Location> FaceWithParentLocation;
	typedef std::vector<FaceWithParentLocation> MyFaceWithParentLocationList;
	void get_children_face_list (MyFaceWithParentLocationList&) const;

	Step::ShapeType cascade_enum_to_adapter_enum (TopAbs_ShapeEnum value) const;

	static bool is_equal_transformation (const gp_Trsf& trnsf1, const gp_Trsf& trnsf2);

private:
	TDF_Label m_label;
	TDF_Label m_location_label;
	Handle(TDocStd_Document) m_doc;

	Step::NameWrapper_var m_main_name;
	Step::NameWrapper_var m_local_name;
	double m_deflection;
//#UC END# *48AD6AED0331*
}; // class Shape_i

} // namespace Step_i
} // namespace StepWrapper


#endif //__CAD_STEPWRAPPER_STEP_I_SHAPE_I_H__
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
