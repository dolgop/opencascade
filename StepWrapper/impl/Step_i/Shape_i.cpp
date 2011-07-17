////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Модуль: "w:/CAD/StepWrapper/impl/Step_i/Shape_i.cpp"
// генератор файлов реализации C++ (.cpp)
// Generated from UML model, root element: <<Servant::Class>> CAD::StepWrapper::Step_i::Shape_i
//
//
// Все права принадлежат ООО НПП "Гарант-Сервис".
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "shared/Core/sys/std_inc.h"
#include "CAD/StepWrapper/LibHome.h"
#include "CAD/StepWrapper/impl/Step_i/Shape_i.h"

//#UC START# *48AD6AED0331_CUSTOM_INCLUDES*
#include <BRepMesh.hxx>
#include <BRep_Tool.hxx>

#include <BRepAdaptor_Curve.hxx>
#include <GCPnts_UniformDeflection.hxx>

#include <ShapeFix_Shape.hxx>

#include <TDF_Tool.hxx>
#include <TDF_ChildIterator.hxx>

#include <TopExp_Explorer.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Shape.hxx>

#include <XCAFDoc_ShapeTool.hxx>
#include <XCAFDoc_DocumentTool.hxx>
#include "TDF_LabelSequence.hxx"

//#UC END# *48AD6AED0331_CUSTOM_INCLUDES*
#include "Location_i.h"

namespace StepWrapper {
namespace Step_i {

//#UC START# *48AD6AED0331*
size_t Shape_i::get_face_count () const {
	TDF_Label main_label = m_doc->Main ();
	Handle(XCAFDoc_ShapeTool) assembly = XCAFDoc_DocumentTool::ShapeTool (main_label);

	size_t counter = 0;
	TopoDS_Shape shape;
	if (assembly->GetShape (m_label, shape)) {
		for (TopExp_Explorer ex (shape, TopAbs_FACE); ex.More(); ex.Next()) {
			const TopoDS_Face& face = TopoDS::Face (ex.Current ());
			if (!face.IsNull ()) {
				++counter;
			}
		}
	}

	return counter;
}

size_t Shape_i::get_children_face_count () const {
	TDF_Label main_label = m_doc->Main ();
	Handle(XCAFDoc_ShapeTool) assembly = XCAFDoc_DocumentTool::ShapeTool (main_label);
	size_t counter = 0;

	TDF_ChildIterator it (m_label);
	for (; it.More(); it.Next ()) {
		TDF_Label child = it.Value();

		TopoDS_Shape shape = assembly->GetShape (child);
		if (!shape.IsNull () && (shape.ShapeType () <= TopAbs_SOLID)) {
			TDF_Label child_label = assembly->FindShape (shape);
			if (!child_label.IsNull ()) {
				if (assembly->GetShape (child_label, shape)) {
					for (TopExp_Explorer ex (shape, TopAbs_FACE); ex.More(); ex.Next()) {
						const TopoDS_Face& face = TopoDS::Face (ex.Current ());
						if (!face.IsNull ()) {
							++counter;
						}
					}
				}
			}
		}
	}

	return counter;
}

void Shape_i::get_children_face_list (MyFaceWithParentLocationList& face_list) const {
	TDF_Label main_label = m_doc->Main ();
	Handle(XCAFDoc_ShapeTool) assembly = XCAFDoc_DocumentTool::ShapeTool (main_label);

	TDF_ChildIterator it (m_label);
	face_list.clear ();
	for (; it.More(); it.Next ()) {
		TDF_Label child = it.Value();

		TopoDS_Shape shape_with_location = assembly->GetShape (child);
		if (!shape_with_location.IsNull () && (shape_with_location.ShapeType () <= TopAbs_SOLID)) {
			TopoDS_Shape shape;
			TDF_Label child_label = assembly->FindShape (shape_with_location);
			if (!child_label.IsNull ()) {
				if (assembly->GetShape (child_label, shape)) {
					for (TopExp_Explorer ex (shape, TopAbs_FACE); ex.More(); ex.Next()) {
						const TopoDS_Face& face = TopoDS::Face (ex.Current ());
						if (!face.IsNull ()) {
							face_list.push_back (std::make_pair (face, shape_with_location.Location ()));
						}
					}
				}
			}
		}
	}
}

Step::ShapeType Shape_i::cascade_enum_to_adapter_enum (TopAbs_ShapeEnum value) const {
	switch (value) {
		case TopAbs_COMPOUND:
			return Step::ST_COMPOUND;
		case TopAbs_COMPSOLID:
			return Step::ST_COMPSOLID;
		case TopAbs_SOLID:
			return Step::ST_SOLID;
		case TopAbs_SHELL:
			return Step::ST_SHELL;
		case TopAbs_FACE:
			return Step::ST_FACE;
		case TopAbs_WIRE:
			return Step::ST_WIRE;
		case TopAbs_EDGE:
			return Step::ST_EDGE;
		case TopAbs_VERTEX:
			return Step::ST_VERTEX;
		case TopAbs_SHAPE:
			std::cout << "unknown type of shape\n";
			return Step::ST_SHAPE;
	}
}

bool Shape_i::is_equal_transformation (const gp_Trsf& trsf1, const gp_Trsf& trsf2) {
	for (unsigned char row = 1; row <= 3; ++row) {
		for (unsigned char column = 1; column <= 4; ++column) {
			if (Location_i::is_zero (trsf1.Value (row, column) - trsf2.Value (row, column)) != 0) {
				return false;
			}
		}
	}

	return true;
}
//#UC END# *48AD6AED0331*

//////////////////////////////////////////////////////////////////////////////////////////
// constructors and destructor

Shape_i::Shape_i (const TDF_Label& id, const Handle_TDocStd_Document& doc, const TDF_Label& location_label)
//#UC START# *48AD64DB01CB_48AD65C300AE_48AD6AED0331_BASE_INIT*
: m_label (id), m_doc (doc), m_location_label (location_label), m_deflection (1)
//#UC END# *48AD64DB01CB_48AD65C300AE_48AD6AED0331_BASE_INIT*
{
	//#UC START# *48AD64DB01CB_48AD65C300AE_48AD6AED0331_BODY*
	Handle(TDataStd_Name) name;
	if (m_label.FindAttribute(TDataStd_Name::GetID(), name)) {
		TCollection_ExtendedString ext_string = name->Get ();
		TCollection_AsciiString ascii_string (ext_string, '?');

		m_main_name = Step::NameWrapperFactory::make (ascii_string.ToCString ());
	} else {
		m_main_name = Step::NameWrapperFactory::make ("");
	}

	if (m_location_label.FindAttribute(TDataStd_Name::GetID(), name)) {
		TCollection_ExtendedString ext_string = name->Get ();
		TCollection_AsciiString ascii_string (ext_string, '?');

		m_local_name = Step::NameWrapperFactory::make (ascii_string.ToCString ());
	} else {
		m_local_name = Step::NameWrapperFactory::make ("");
	}
	//#UC END# *48AD64DB01CB_48AD65C300AE_48AD6AED0331_BODY*
}

Shape_i::~Shape_i () {
	//#UC START# *48AD6AED0331_DESTR_BODY*
	//#UC END# *48AD6AED0331_DESTR_BODY*
}


//////////////////////////////////////////////////////////////////////////////////////////
// implemented interface's methods

// implemented method from Step::Shape
// параметр, задающий точность триангуляции
const double Shape_i::get_deflection () const {
	//#UC START# *48F33C1D00D5_48AD6AED0331_GET*
	return m_deflection;
	//#UC END# *48F33C1D00D5_48AD6AED0331_GET*
}

void Shape_i::set_deflection (double deflection) {
	//#UC START# *48F33C1D00D5_48AD6AED0331_SET*
	m_deflection = deflection;
	//#UC END# *48F33C1D00D5_48AD6AED0331_SET*
}

// implemented method from Step::Shape
// возвращает список поверхностей для всех фигур, входящих в заданную (включая её саму)
Step::FaceList* Shape_i::get_all_face_list () const {
	//#UC START# *48EA1BB50078_48AD6AED0331*
	TopoDS_Shape shape;

	std::auto_ptr<Step::FaceList> children_list (new Step::FaceList ());
	TDF_Label main_label = m_doc->Main ();
	Handle(XCAFDoc_ShapeTool) assembly = XCAFDoc_DocumentTool::ShapeTool (main_label);

	if (assembly->GetShape (m_label, shape)) {
		for (TopExp_Explorer ex (shape, TopAbs_FACE); ex.More(); ex.Next()) {
			const TopoDS_Face& face = TopoDS::Face (ex.Current ());
			children_list->push_back (Step::FaceFactory::make (face));
		}
	}
	if (children_list->size ()) {
		BRepMesh::Mesh (shape, m_deflection);
	}

	return children_list.release ();
	//#UC END# *48EA1BB50078_48AD6AED0331*
}

// implemented method from Step::Shape
// Возвращает список дочерних фигур для заданной
Step::ShapeList* Shape_i::get_children_list () const {
	//#UC START# *48AD65540010_48AD6AED0331*
	std::auto_ptr<Step::ShapeList> children_list (new Step::ShapeList ());
	TDF_Label main_label = m_doc->Main ();
	Handle(XCAFDoc_ShapeTool) assembly = XCAFDoc_DocumentTool::ShapeTool (main_label);
	size_t i = 0;

	TDF_ChildIterator it (m_label);
	for (; it.More(); it.Next ()) {
		TDF_Label child = it.Value();
		TopoDS_Shape shape = assembly->GetShape (child);
		
		if (!shape.IsNull () && (shape.ShapeType () <= TopAbs_SOLID)) {
			TDF_Label child_label = assembly->FindShape (shape);
			if (!child_label.IsNull ()) {
				Step::Shape* ch = Step::ShapeFactory::make (child_label, m_doc, child);
				children_list->push_back (ch);
			}
			//shape_label = assembly->FindShape (shape);
			//if (!shape_label.IsNull ()) {
		}
	}

	return children_list.release ();
	//#UC END# *48AD65540010_48AD6AED0331*
}

// implemented method from Step::Shape
// возвращает список поверхностей для заданной фигуры
Step::FaceList* Shape_i::get_face_list () const {
	//#UC START# *48AD66190301_48AD6AED0331*
	TopoDS_Shape shape;

	std::auto_ptr<Step::FaceList> children_list (new Step::FaceList ());
	TDF_Label main_label = m_doc->Main ();
	Handle(XCAFDoc_ShapeTool) assembly = XCAFDoc_DocumentTool::ShapeTool (main_label);

	if (assembly->GetShape (m_label, shape)) {
		if (get_children_face_count () == get_face_count ()) {
			return children_list.release ();
		}
		MyFaceWithParentLocationList children_faces;
		get_children_face_list (children_faces);
		MyFaceList my_faces;
		for (TopExp_Explorer ex (shape, TopAbs_FACE); ex.More(); ex.Next()) {
			const TopoDS_Face& face = TopoDS::Face (ex.Current ());
			my_faces.push_back (face);
		}

		// find only my faces
		for (size_t i = 0; i < my_faces.size (); ++i) {
			bool face_found = false;
			for (size_t j = 0; j < children_faces.size (); ++j) {
				if (my_faces[i].IsPartner (children_faces[j].first)) {
					TopLoc_Location location = children_faces[j].second*children_faces[j].first.Location ();
					if (
						Shape_i::is_equal_transformation (
							location.Transformation ()
							, my_faces[i].Location ().Transformation ()
						)
					) {
						face_found = true;
						break;
					}
				}
			}
			if (!face_found) {
				//BRepMesh::Mesh (my_faces[i], 1);
				children_list->push_back (Step::FaceFactory::make (my_faces[i]));
			}
		}
	}
	if (children_list->size ()) {
		BRepMesh::Mesh (shape, m_deflection);
	}

	return children_list.release ();
	//#UC END# *48AD66190301_48AD6AED0331*
}

// implemented method from Step::Shape
const TDF_Label& Shape_i::get_label () const {
	//#UC START# *48D9F23C02D8_48AD6AED0331*
	return m_label;
	//#UC END# *48D9F23C02D8_48AD6AED0331*
}

// implemented method from Step::Shape
// координаты текущей фигуры
Step::Location* Shape_i::get_location () const {
	//#UC START# *48BE89F901CC_48AD6AED0331*
	TDF_Label main_label = m_doc->Main ();
	Handle(XCAFDoc_ShapeTool) assembly = XCAFDoc_DocumentTool::ShapeTool (main_label);

	const TopLoc_Location& location = assembly->GetLocation (m_location_label);
	if (!location.IsIdentity ()) {
		const gp_Trsf& trsf = location.Transformation ();
		return Step::LocationFactory::make (trsf);
	}

	return 0;
	//#UC END# *48BE89F901CC_48AD6AED0331*
}

// implemented method from Step::Shape
// возвращает топологический объект, являющийся отцом заданного
Step::Shape* Shape_i::get_original_shape () const {
	//#UC START# *48D900230195_48AD6AED0331*
	return Step::ShapeFactory::make (m_label, m_doc, m_label);
	//#UC END# *48D900230195_48AD6AED0331*
}

// implemented method from Step::Shape
// вернуть тип топологического объекта
Step::ShapeType Shape_i::get_type () const {
	//#UC START# *48E329810091_48AD6AED0331*
	TDF_Label main_label = m_doc->Main ();
	Handle(XCAFDoc_ShapeTool) assembly = XCAFDoc_DocumentTool::ShapeTool (main_label);
	TopoDS_Shape shape = assembly->GetShape (m_label);

	return this->cascade_enum_to_adapter_enum (shape.ShapeType ());
	//#UC END# *48E329810091_48AD6AED0331*
}

// implemented method from Step::Shape
// замкнута ли поверхность
bool Shape_i::is_closed () const {
	//#UC START# *48D749D80113_48AD6AED0331*
	TDF_Label main_label = m_doc->Main ();
	Handle(XCAFDoc_ShapeTool) assembly = XCAFDoc_DocumentTool::ShapeTool (main_label);
	TopoDS_Shape shape;
	if (assembly->GetShape (m_label, shape)) {
		return BRep_Tool::IsClosed (shape) != 0;
	}

	GDS_ASSERT (false);
	return true;
	//#UC END# *48D749D80113_48AD6AED0331*
}

// implemented method from Step::Shape
// сравнивает 2 фигуры на равенство
bool Shape_i::is_equal (const Step::Shape* to_compare) const {
	//#UC START# *48D9001B029F_48AD6AED0331*
	return this->m_label.IsEqual (to_compare->get_label ());
	//#UC END# *48D9001B029F_48AD6AED0331*
}

// implemented method from Step::Shape
// имя конкретной фигуры
const Step::NameWrapper& Shape_i::get_local_name () const {
	//#UC START# *48F6D9A703BB_48AD6AED0331_GET*
	return *m_local_name.ptr ();
	//#UC END# *48F6D9A703BB_48AD6AED0331_GET*
}

// implemented method from Step::Shape
// имя топологической фигуры, являющейся базовой для данной
const Step::NameWrapper& Shape_i::get_main_name () const {
	//#UC START# *48AD711101F6_48AD6AED0331_GET*
	return *m_main_name.ptr ();
	//#UC END# *48AD711101F6_48AD6AED0331_GET*
}
} // namespace Step_i
} // namespace StepWrapper

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

