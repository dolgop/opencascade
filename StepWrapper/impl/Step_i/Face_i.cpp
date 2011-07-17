////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Модуль: "w:/CAD/StepWrapper/impl/Step_i/Face_i.cpp"
// генератор файлов реализации C++ (.cpp)
// Generated from UML model, root element: <<Servant::Class>> CAD::StepWrapper::Step_i::Face_i
//
//
// Все права принадлежат ООО НПП "Гарант-Сервис".
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "shared/Core/sys/std_inc.h"
#include "CAD/StepWrapper/LibHome.h"
#include "CAD/StepWrapper/impl/Step_i/Face_i.h"

//#UC START# *48AD6B0E03B4_CUSTOM_INCLUDES*
#include <BRep_TFace.hxx>
#include <BRep_Tool.hxx>
#include <BRepAdaptor_Curve.hxx>

#include <BOPTools_Tools3D.hxx>

#include <GCPnts_UniformDeflection.hxx>

#include <Poly.hxx>
#include <Poly_Triangulation.hxx>
#include <Poly_Array1OfTriangle.hxx>

#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfPnt2d.hxx>

#include <TopExp_Explorer.hxx>
#include <TopLoc_Location.hxx>

#include <TopoDS.hxx>
#include <TopoDS_Edge.hxx>

#include <TShort_Array1OfShortReal.hxx>
//#UC END# *48AD6B0E03B4_CUSTOM_INCLUDES*

namespace StepWrapper {
namespace Step_i {

//#UC START# *48AD6B0E03B4*
//#UC END# *48AD6B0E03B4*

//////////////////////////////////////////////////////////////////////////////////////////
// constructors and destructor

Face_i::Face_i (const TopoDS_Face& id)
//#UC START# *48AD6649034F_48AD6A660119_48AD6B0E03B4_BASE_INIT*
: m_face (id)
//#UC END# *48AD6649034F_48AD6A660119_48AD6B0E03B4_BASE_INIT*
{
	//#UC START# *48AD6649034F_48AD6A660119_48AD6B0E03B4_BODY*
	//#UC END# *48AD6649034F_48AD6A660119_48AD6B0E03B4_BODY*
}

Face_i::~Face_i () {
	//#UC START# *48AD6B0E03B4_DESTR_BODY*
	//#UC END# *48AD6B0E03B4_DESTR_BODY*
}


//////////////////////////////////////////////////////////////////////////////////////////
// implemented interface's methods

// implemented method from Step::Face
Step::Location* Face_i::get_location () const {
	//#UC START# *48C13840023D_48AD6B0E03B4*
	const TopLoc_Location& location = m_face.Location ();
	if (!location.IsIdentity ()) {
		const gp_Trsf& trsf = location.Transformation ();
		return Step::LocationFactory::make (trsf);
	}

	return 0;
	//#UC END# *48C13840023D_48AD6B0E03B4*
}

// implemented method from Step::Face
Step::PointsTable* Face_i::get_normals_table () const {
	//#UC START# *48AD714A0033_48AD6B0E03B4*
	std::auto_ptr<Step::PointsTable> children_list (new Step::PointsTable ());

	//Handle(Poly_Triangulation) facing = tface->Triangulation();
	//if (facing.IsNull()) {
	//	std::cout << "NULL Triangulation\n";
	//	return children_list.release ();
	//}
	TopLoc_Location loc = m_face.Location ();
	Handle(Poly_Triangulation) facing = BRep_Tool::Triangulation (m_face, loc);

	if (!facing->HasUVNodes ()) {
		std::cout << "triangulation hasn't 2d array\n";
		return children_list.release ();
	}

#if 1
	Standard_Boolean forward = true;
	switch (m_face.Orientation ()) {
		case TopAbs_REVERSED:
			forward = false;
			break;
		case TopAbs_FORWARD:
			break;
		default:
			GDS_ASSERT (false && "unknown direction");
			break;
	}
#endif
	const TColgp_Array1OfPnt2d& tab2d = facing->UVNodes ();
	children_list->reserve (facing->NbNodes ());
	Handle(BRep_TFace) tface = Handle(BRep_TFace)::DownCast (m_face.TShape ());
	if (tface->Surface ().IsNull ())  {
		std::cout << "NULL FACE\n";
		return children_list.release ();
	}
	Handle(Geom_Surface) surface = tface->Surface ();
	gp_Dir vec;
	Standard_Boolean dir;
	Step::Point pt;
	for (Standard_Integer i=1; i<= (facing->NbNodes ()); ++i) {
		const gp_Pnt2d& uv = tab2d.Value (i);
		dir = BOPTools_Tools3D::GetNormalToSurface (
			surface
			, uv.X ()
			, uv.Y ()
			, vec
		);
#if 1
		if (forward) {
			pt.x = static_cast<float> (vec.X ());
			pt.y = static_cast<float> (vec.Y ());
			pt.z = static_cast<float> (vec.Z ());
		} else {
			pt.x = static_cast<float> (-vec.X ());
			pt.y = static_cast<float> (-vec.Y ());
			pt.z = static_cast<float> (-vec.Z ());
		}
#else
		pt.x = static_cast<float> (vec.X ());
		pt.y = static_cast<float> (vec.Y ());
		pt.z = static_cast<float> (vec.Z ());
#endif
		children_list->push_back (pt);
	}
	return children_list.release ();
	//#UC END# *48AD714A0033_48AD6B0E03B4*
}

// implemented method from Step::Face
Step::PointsTable* Face_i::get_points_table () const {
	//#UC START# *48AD698402A0_48AD6B0E03B4*
	std::auto_ptr<Step::PointsTable> children_list (new Step::PointsTable ());

	TopLoc_Location loc = m_face.Location ();
	Handle(Poly_Triangulation) facing = BRep_Tool::Triangulation (m_face, loc);
	if (facing.IsNull()) {
		std::cout << "NULL Triangulation\n";
		return children_list.release ();
	}

	const TColgp_Array1OfPnt& tab = facing->Nodes ();
	children_list->reserve (facing->NbNodes ());
	Step::Point pt;
	for (Standard_Integer i=1; i<= (facing->NbNodes ()); ++i) {
		const gp_Pnt& point = tab.Value (i);
		pt.x = static_cast<float> (point.X ());
		pt.y = static_cast<float> (point.Y ());
		pt.z = static_cast<float> (point.Z ());
		children_list->push_back (pt);
	}
	return children_list.release ();
	//#UC END# *48AD698402A0_48AD6B0E03B4*
}

// implemented method from Step::Face
Step::TrianglesTable* Face_i::get_triangles_table () const {
	//#UC START# *48AD69A7025D_48AD6B0E03B4*
	std::auto_ptr<Step::TrianglesTable> children_list (new Step::TrianglesTable ());

	TopLoc_Location loc = m_face.Location ();
	Handle(Poly_Triangulation) facing = BRep_Tool::Triangulation (m_face, loc);
	if (facing.IsNull()) {
		std::cout << "NULL Triangulation\n";
		return children_list.release ();
	}

	const Poly_Array1OfTriangle& tri = facing->Triangles ();
	children_list->reserve (facing->NbTriangles ());
	Step::TriangleInfo info;
	Standard_Integer index1, index2, index3;

#if 1
	Standard_Boolean forward = true;
	switch (m_face.Orientation ()) {
		case TopAbs_REVERSED:
			forward = false;
			break;
		case TopAbs_FORWARD:
			break;
		default:
			GDS_ASSERT (false && "unknown direction");
			break;
	}
#endif
	for (Standard_Integer i = 1; i<= facing->NbTriangles (); ++i) {	
		const Poly_Triangle& trian = tri.Value (i);
		trian.Get (index1, index2, index3);
		info.index1 = index1 - 1;
#if 1
		if (forward) {
			info.index2 = index2 - 1;
			info.index3 = index3 - 1;
		} else {
			info.index2 = index3 - 1;
			info.index3 = index2 - 1;
		}
#else
		info.index2 = index2 - 1;
		info.index3 = index3 - 1;
#endif
		children_list->push_back (info);
	}

	return children_list.release ();
	//#UC END# *48AD69A7025D_48AD6B0E03B4*
}

// implemented method from Step::Face
Step::PointsTable* Face_i::get_wire_points (size_t index) const {
	//#UC START# *48D74E9502C2_48AD6B0E03B4*
	std::auto_ptr<Step::PointsTable> children_list (new Step::PointsTable ());

	for (TopExp_Explorer ex (m_face, TopAbs_EDGE); ex.More(); ex.Next()) {
		const TopoDS_Edge& edge = TopoDS::Edge (ex.Current ());
		if (!edge.IsNull ()) {
			if (index) {
				--index;
			} else {
				BRepAdaptor_Curve adaptor (edge);
				GCPnts_UniformDeflection deflection (adaptor, 1);
				if (deflection.IsDone ()) {
					size_t count = deflection.NbPoints ();
					children_list->reserve (count);
					for (size_t i = 1; i <= count; ++i) {
						gp_Pnt point = deflection.Value (i);
						Step::Point pt;
						pt.x = static_cast<float> (point.X ());
						pt.y = static_cast<float> (point.Y ());
						pt.z = static_cast<float> (point.Z ());
						children_list->push_back (pt);
					}
				}
				return children_list.release ();
			}
		}
	}

	GDS_ASSERT (false);
	return children_list.release ();
	//#UC END# *48D74E9502C2_48AD6B0E03B4*
}

// implemented method from Step::Face
// Количество wires для данного face
size_t Face_i::get_wires_count () const {
	//#UC START# *48D7507E03D3_48AD6B0E03B4*
	size_t counter  = 0;
	for (TopExp_Explorer ex (m_face, TopAbs_EDGE); ex.More(); ex.Next()) {
		const TopoDS_Edge& edge = TopoDS::Edge (ex.Current ());
		if (!edge.IsNull ()) {
			++counter;
		}
	}

	return counter;
	//#UC END# *48D7507E03D3_48AD6B0E03B4*
}
} // namespace Step_i
} // namespace StepWrapper

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

