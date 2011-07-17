////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Модуль: "w:/CAD/StepWrapper/Step/Step_tie.h"
// С++ TIE-обвязка для DLL (_tie.h)
// Generated from UML model, root element: <<Interfaces::Category>> CAD::StepWrapper::Step
//
//
// Все права принадлежат ООО НПП "Гарант-Сервис".
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __CAD_STEPWRAPPER_STEP_TIE_H__
#define __CAD_STEPWRAPPER_STEP_TIE_H__

#include "shared/Core/sys/std_inc.h"
#include "shared/Core/mng/IObject_tie.h"
#include "shared/Core/mng/PoolObjectManager.h"
#include "CAD/StepWrapper/Step/Step.h"

namespace StepWrapper {
namespace Step {

class PointsTable_tie: public Core::TIEBase {
	SET_OBJECT_COUNTER (PointsTable_tie)
protected:
	virtual unsigned long __stdcall query_interface (
		const ::Core::ComIID& iid
		, void*& object
	);

	virtual unsigned long __stdcall addref () const;

public:
	virtual unsigned long __stdcall release () const;

// For ObjectPool's objects initialization and destruction
public:
	void init ();

	void done ();

private:
	PointsTable_tie ();

	typedef ::Core::PoolObjectManager<PointsTable_tie>::PoolObjectManagerSingleton MyPool;
	typedef ::Core::PoolObjectManager<PointsTable_tie> Pool;
	friend class ::Core::PoolObjectManager<PointsTable_tie>;

public:
	static const ::Core::ComIID s_com_iid;
	
	static void make_cpp (const PointsTable_tie* obj, PointsTable*& ret_);

	static void make_tie (PointsTable* obj, PointsTable_tie*& ret_);
	
	static void make_tie (const PointsTable& obj, PointsTable_tie*& ret_);

	static void make_tie (const PointsTable& obj, PointsTable_tie*& ret_, const Core::TIEBase* owner);
	
	static void new_tie (PointsTable* obj, PointsTable_tie*& ret_);

	PointsTable* m_impl;
	bool m_orphan;

protected:
	virtual size_t __stdcall get_count () const;
	virtual void __stdcall set_count (size_t count);
	virtual void __stdcall clear ();
	virtual void __stdcall delete_item (size_t index);
	virtual void __stdcall get_item (size_t index, Point& ret_);
	virtual void __stdcall set_item (size_t index, const Point& item);
	virtual size_t __stdcall add (const Point& item);
	virtual size_t __stdcall insert (size_t index, const Point& item);
};

class TrianglesTable_tie: public Core::TIEBase {
	SET_OBJECT_COUNTER (TrianglesTable_tie)
protected:
	virtual unsigned long __stdcall query_interface (
		const ::Core::ComIID& iid
		, void*& object
	);

	virtual unsigned long __stdcall addref () const;

public:
	virtual unsigned long __stdcall release () const;

// For ObjectPool's objects initialization and destruction
public:
	void init ();

	void done ();

private:
	TrianglesTable_tie ();

	typedef ::Core::PoolObjectManager<TrianglesTable_tie>::PoolObjectManagerSingleton MyPool;
	typedef ::Core::PoolObjectManager<TrianglesTable_tie> Pool;
	friend class ::Core::PoolObjectManager<TrianglesTable_tie>;

public:
	static const ::Core::ComIID s_com_iid;
	
	static void make_cpp (const TrianglesTable_tie* obj, TrianglesTable*& ret_);

	static void make_tie (TrianglesTable* obj, TrianglesTable_tie*& ret_);
	
	static void make_tie (const TrianglesTable& obj, TrianglesTable_tie*& ret_);

	static void make_tie (const TrianglesTable& obj, TrianglesTable_tie*& ret_, const Core::TIEBase* owner);
	
	static void new_tie (TrianglesTable* obj, TrianglesTable_tie*& ret_);

	TrianglesTable* m_impl;
	bool m_orphan;

protected:
	virtual size_t __stdcall get_count () const;
	virtual void __stdcall set_count (size_t count);
	virtual void __stdcall clear ();
	virtual void __stdcall delete_item (size_t index);
	virtual void __stdcall get_item (size_t index, TriangleInfo& ret_);
	virtual void __stdcall set_item (size_t index, const TriangleInfo& item);
	virtual size_t __stdcall add (const TriangleInfo& item);
	virtual size_t __stdcall insert (size_t index, const TriangleInfo& item);
};

class ILocation_tie: public ::Core::IIObject_tie {
public:
	virtual float __stdcall get_index_48BBAB1202E1 (
		size_t row
		, size_t column
	) const /*throw (BadArgument_tie)*/ = 0;
};

class __declspec (dllexport) Location_tie: public ILocation_tie {
	SET_OBJECT_COUNTER (Location_tie)
protected:
	virtual unsigned long __stdcall query_interface (
		const ::Core::ComIID& iid
		, void*& object
	);

	virtual unsigned long __stdcall addref () const;

public:
	virtual unsigned long __stdcall release () const;

	virtual ::Core::IObject* get_impl () const;

// For ObjectPool's objects initialization and destruction
public:
	void init ();

	void done ();

private:
	Location_tie ();

	typedef ::Core::PoolObjectManager<Location_tie>::PoolObjectManagerSingleton MyPool;
	typedef ::Core::PoolObjectManager<Location_tie> Pool;
	friend class ::Core::PoolObjectManager<Location_tie>;
	typedef ::Core::IidMapRegistrator<Location_tie> IidRegistrator;
	static IidRegistrator s_iid_registrator;
	
public:
	static const ::Core::ComIID s_com_iid;
	
	static void* cast (::Core::IObject* obj);

	static void make_cpp (const ILocation_tie* obj, Location*& ret_, bool interface_addref = false);

	static void make_tie (const Location* obj, ILocation_tie*& ret_, bool interface_addref = false);
	
	static void make_tie (const Location& obj, ILocation_tie*& ret_, const Core::TIEBase* owner);

	Location* m_impl;

protected:
	virtual float __stdcall get_index_48BBAB1202E1 (
		size_t row
		, size_t column
	) const /*throw (BadArgument_tie)*/;
};

class IFace_tie: public ::Core::IIObject_tie {
public:
	virtual void __stdcall get_location_48C13840023D (
		ILocation_tie*& ret_
	) const = 0;

	virtual void __stdcall get_normals_table_48AD714A0033 (
		PointsTable_tie*& ret_
	) const = 0;

	virtual void __stdcall get_points_table_48AD698402A0 (
		PointsTable_tie*& ret_
	) const = 0;

	virtual void __stdcall get_triangles_table_48AD69A7025D (
		TrianglesTable_tie*& ret_
	) const = 0;

	virtual void __stdcall get_wire_points_48D74E9502C2 (
		size_t index
		, PointsTable_tie*& ret_
	) const = 0;

	virtual size_t __stdcall get_wires_count_48D7507E03D3 () const = 0;
};

class __declspec (dllexport) Face_tie: public IFace_tie {
	SET_OBJECT_COUNTER (Face_tie)
protected:
	virtual unsigned long __stdcall query_interface (
		const ::Core::ComIID& iid
		, void*& object
	);

	virtual unsigned long __stdcall addref () const;

public:
	virtual unsigned long __stdcall release () const;

	virtual ::Core::IObject* get_impl () const;

// For ObjectPool's objects initialization and destruction
public:
	void init ();

	void done ();

private:
	Face_tie ();

	typedef ::Core::PoolObjectManager<Face_tie>::PoolObjectManagerSingleton MyPool;
	typedef ::Core::PoolObjectManager<Face_tie> Pool;
	friend class ::Core::PoolObjectManager<Face_tie>;
	typedef ::Core::IidMapRegistrator<Face_tie> IidRegistrator;
	static IidRegistrator s_iid_registrator;
	
public:
	static const ::Core::ComIID s_com_iid;
	
	static void* cast (::Core::IObject* obj);

	static void make_cpp (const IFace_tie* obj, Face*& ret_, bool interface_addref = false);

	static void make_tie (const Face* obj, IFace_tie*& ret_, bool interface_addref = false);
	
	static void make_tie (const Face& obj, IFace_tie*& ret_, const Core::TIEBase* owner);

	Face* m_impl;

protected:
	virtual void __stdcall get_location_48C13840023D (
		ILocation_tie*& ret_
	) const;

	virtual void __stdcall get_normals_table_48AD714A0033 (
		PointsTable_tie*& ret_
	) const;

	virtual void __stdcall get_points_table_48AD698402A0 (
		PointsTable_tie*& ret_
	) const;

	virtual void __stdcall get_triangles_table_48AD69A7025D (
		TrianglesTable_tie*& ret_
	) const;

	virtual void __stdcall get_wire_points_48D74E9502C2 (
		size_t index
		, PointsTable_tie*& ret_
	) const;

	virtual size_t __stdcall get_wires_count_48D7507E03D3 () const;
};

class INameWrapper_tie: public ::Core::IIObject_tie {
public:
	virtual const char* __stdcall get_name_48BB91480179 () const = 0;
};

class __declspec (dllexport) NameWrapper_tie: public INameWrapper_tie {
	SET_OBJECT_COUNTER (NameWrapper_tie)
protected:
	virtual unsigned long __stdcall query_interface (
		const ::Core::ComIID& iid
		, void*& object
	);

	virtual unsigned long __stdcall addref () const;

public:
	virtual unsigned long __stdcall release () const;

	virtual ::Core::IObject* get_impl () const;

// For ObjectPool's objects initialization and destruction
public:
	void init ();

	void done ();

private:
	NameWrapper_tie ();

	typedef ::Core::PoolObjectManager<NameWrapper_tie>::PoolObjectManagerSingleton MyPool;
	typedef ::Core::PoolObjectManager<NameWrapper_tie> Pool;
	friend class ::Core::PoolObjectManager<NameWrapper_tie>;
	typedef ::Core::IidMapRegistrator<NameWrapper_tie> IidRegistrator;
	static IidRegistrator s_iid_registrator;
	
public:
	static const ::Core::ComIID s_com_iid;
	
	static void* cast (::Core::IObject* obj);

	static void make_cpp (const INameWrapper_tie* obj, NameWrapper*& ret_, bool interface_addref = false);

	static void make_tie (const NameWrapper* obj, INameWrapper_tie*& ret_, bool interface_addref = false);
	
	static void make_tie (const NameWrapper& obj, INameWrapper_tie*& ret_, const Core::TIEBase* owner);

	NameWrapper* m_impl;

protected:
	virtual const char* __stdcall get_name_48BB91480179 () const;
};

class FaceList_tie: public Core::TIEBase {
	SET_OBJECT_COUNTER (FaceList_tie)
protected:
	virtual unsigned long __stdcall query_interface (
		const ::Core::ComIID& iid
		, void*& object
	);

	virtual unsigned long __stdcall addref () const;

public:
	virtual unsigned long __stdcall release () const;

// For ObjectPool's objects initialization and destruction
public:
	void init ();

	void done ();

private:
	FaceList_tie ();

	typedef ::Core::PoolObjectManager<FaceList_tie>::PoolObjectManagerSingleton MyPool;
	typedef ::Core::PoolObjectManager<FaceList_tie> Pool;
	friend class ::Core::PoolObjectManager<FaceList_tie>;

public:
	static const ::Core::ComIID s_com_iid;
	
	static void make_cpp (const FaceList_tie* obj, FaceList*& ret_);

	static void make_tie (FaceList* obj, FaceList_tie*& ret_);
	
	static void make_tie (const FaceList& obj, FaceList_tie*& ret_);

	static void make_tie (const FaceList& obj, FaceList_tie*& ret_, const Core::TIEBase* owner);
	
	static void new_tie (FaceList* obj, FaceList_tie*& ret_);

	FaceList* m_impl;
	bool m_orphan;

protected:
	virtual size_t __stdcall get_count () const;
	virtual void __stdcall set_count (size_t count);
	virtual void __stdcall clear ();
	virtual void __stdcall delete_item (size_t index);
	virtual void __stdcall get_item (size_t index, IFace_tie*& ret_);
	virtual void __stdcall set_item (size_t index, const IFace_tie* item);
	virtual size_t __stdcall add (const IFace_tie* item);
	virtual size_t __stdcall insert (size_t index, const IFace_tie* item);
};

class ShapeList_tie;

class IShape_tie: public ::Core::IIObject_tie {
public:

	virtual const double __stdcall get_deflection () const = 0;
	virtual void __stdcall set_deflection (double deflection) = 0;

	virtual void __stdcall get_all_face_list_48EA1BB50078 (
		FaceList_tie*& ret_
	) const = 0;

	virtual void __stdcall get_children_list_48AD65540010 (
		ShapeList_tie*& ret_
	) const = 0;

	virtual void __stdcall get_face_list_48AD66190301 (
		FaceList_tie*& ret_
	) const = 0;

	virtual void __stdcall get_location_48BE89F901CC (
		ILocation_tie*& ret_
	) const = 0;

	virtual void __stdcall get_original_shape_48D900230195 (
		IShape_tie*& ret_
	) const = 0;

	virtual ShapeType __stdcall get_type_48E329810091 () const = 0;

	virtual bool __stdcall is_closed_48D749D80113 () const = 0;

	virtual bool __stdcall is_equal_48D9001B029F (
		const IShape_tie* to_compare
	) const = 0;


	virtual void __stdcall get_local_name (INameWrapper_tie*& ret_) = 0;


	virtual void __stdcall get_main_name (INameWrapper_tie*& ret_) = 0;
};

class __declspec (dllexport) Shape_tie: public IShape_tie {
	SET_OBJECT_COUNTER (Shape_tie)
protected:
	virtual unsigned long __stdcall query_interface (
		const ::Core::ComIID& iid
		, void*& object
	);

	virtual unsigned long __stdcall addref () const;

public:
	virtual unsigned long __stdcall release () const;

	virtual ::Core::IObject* get_impl () const;

// For ObjectPool's objects initialization and destruction
public:
	void init ();

	void done ();

private:
	Shape_tie ();

	typedef ::Core::PoolObjectManager<Shape_tie>::PoolObjectManagerSingleton MyPool;
	typedef ::Core::PoolObjectManager<Shape_tie> Pool;
	friend class ::Core::PoolObjectManager<Shape_tie>;
	typedef ::Core::IidMapRegistrator<Shape_tie> IidRegistrator;
	static IidRegistrator s_iid_registrator;
	
public:
	static const ::Core::ComIID s_com_iid;
	
	static void* cast (::Core::IObject* obj);

	static void make_cpp (const IShape_tie* obj, Shape*& ret_, bool interface_addref = false);

	static void make_tie (const Shape* obj, IShape_tie*& ret_, bool interface_addref = false);
	
	static void make_tie (const Shape& obj, IShape_tie*& ret_, const Core::TIEBase* owner);

	Shape* m_impl;

protected:

	virtual const double __stdcall get_deflection () const;
	virtual void __stdcall set_deflection (double deflection);

	virtual void __stdcall get_all_face_list_48EA1BB50078 (
		FaceList_tie*& ret_
	) const;

	virtual void __stdcall get_children_list_48AD65540010 (
		ShapeList_tie*& ret_
	) const;

	virtual void __stdcall get_face_list_48AD66190301 (
		FaceList_tie*& ret_
	) const;

	virtual void __stdcall get_location_48BE89F901CC (
		ILocation_tie*& ret_
	) const;

	virtual void __stdcall get_original_shape_48D900230195 (
		IShape_tie*& ret_
	) const;

	virtual ShapeType __stdcall get_type_48E329810091 () const;

	virtual bool __stdcall is_closed_48D749D80113 () const;

	virtual bool __stdcall is_equal_48D9001B029F (
		const IShape_tie* to_compare
	) const;


	virtual void __stdcall get_local_name (INameWrapper_tie*& ret_);


	virtual void __stdcall get_main_name (INameWrapper_tie*& ret_);
};

class ShapeList_tie: public Core::TIEBase {
	SET_OBJECT_COUNTER (ShapeList_tie)
protected:
	virtual unsigned long __stdcall query_interface (
		const ::Core::ComIID& iid
		, void*& object
	);

	virtual unsigned long __stdcall addref () const;

public:
	virtual unsigned long __stdcall release () const;

// For ObjectPool's objects initialization and destruction
public:
	void init ();

	void done ();

private:
	ShapeList_tie ();

	typedef ::Core::PoolObjectManager<ShapeList_tie>::PoolObjectManagerSingleton MyPool;
	typedef ::Core::PoolObjectManager<ShapeList_tie> Pool;
	friend class ::Core::PoolObjectManager<ShapeList_tie>;

public:
	static const ::Core::ComIID s_com_iid;
	
	static void make_cpp (const ShapeList_tie* obj, ShapeList*& ret_);

	static void make_tie (ShapeList* obj, ShapeList_tie*& ret_);
	
	static void make_tie (const ShapeList& obj, ShapeList_tie*& ret_);

	static void make_tie (const ShapeList& obj, ShapeList_tie*& ret_, const Core::TIEBase* owner);
	
	static void new_tie (ShapeList* obj, ShapeList_tie*& ret_);

	ShapeList* m_impl;
	bool m_orphan;

protected:
	virtual size_t __stdcall get_count () const;
	virtual void __stdcall set_count (size_t count);
	virtual void __stdcall clear ();
	virtual void __stdcall delete_item (size_t index);
	virtual void __stdcall get_item (size_t index, IShape_tie*& ret_);
	virtual void __stdcall set_item (size_t index, const IShape_tie* item);
	virtual size_t __stdcall add (const IShape_tie* item);
	virtual size_t __stdcall insert (size_t index, const IShape_tie* item);
};

class IStepManager_tie: public ::Core::IIObject_tie {
public:
	virtual void __stdcall get_root_48AA87DA00F8 (
		size_t index
		, IShape_tie*& ret_
	) const /*throw (BadArgument_tie)*/ = 0;

	virtual size_t __stdcall get_roots_count_48AA874200FA () const = 0;
};

class __declspec (dllexport) StepManager_tie: public IStepManager_tie {
	SET_OBJECT_COUNTER (StepManager_tie)
protected:
	virtual unsigned long __stdcall query_interface (
		const ::Core::ComIID& iid
		, void*& object
	);

	virtual unsigned long __stdcall addref () const;

public:
	virtual unsigned long __stdcall release () const;

	virtual ::Core::IObject* get_impl () const;

// For ObjectPool's objects initialization and destruction
public:
	void init ();

	void done ();

private:
	StepManager_tie ();

	typedef ::Core::PoolObjectManager<StepManager_tie>::PoolObjectManagerSingleton MyPool;
	typedef ::Core::PoolObjectManager<StepManager_tie> Pool;
	friend class ::Core::PoolObjectManager<StepManager_tie>;
	typedef ::Core::IidMapRegistrator<StepManager_tie> IidRegistrator;
	static IidRegistrator s_iid_registrator;
	
public:
	static const ::Core::ComIID s_com_iid;
	
	static void* cast (::Core::IObject* obj);

	static void make_cpp (const IStepManager_tie* obj, StepManager*& ret_, bool interface_addref = false);

	static void make_tie (const StepManager* obj, IStepManager_tie*& ret_, bool interface_addref = false);
	
	static void make_tie (const StepManager& obj, IStepManager_tie*& ret_, const Core::TIEBase* owner);

	StepManager* m_impl;

protected:
	virtual void __stdcall get_root_48AA87DA00F8 (
		size_t index
		, IShape_tie*& ret_
	) const /*throw (BadArgument_tie)*/;

	virtual size_t __stdcall get_roots_count_48AA874200FA () const;
};

} // namespace Step
} // namespace StepWrapper
	

#endif //__CAD_STEPWRAPPER_STEP_TIE_H__
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

