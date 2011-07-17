////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Модуль: "w:/CAD/StepWrapper/Step/Step.h"
// генератор заголовочных файлов C++ (.h)
// Generated from UML model, root element: <<Interfaces::Category>> CAD::StepWrapper::Step
//
//
// Все права принадлежат ООО НПП "Гарант-Сервис".
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __CAD_STEPWRAPPER_STEP_H__
#define __CAD_STEPWRAPPER_STEP_H__

#include "shared/Core/sys/std_inc.h"
#include <vector>
#include "TDF_Label.hxx"
#include "TopoDS_Face.hxx"
#include "TDocStd_Document.hxx"
#include "gp_Trsf.hxx"

namespace StepWrapper {
namespace Step {

// Ошибка при чтении файла с данными
class CantReadFile : public ::Core::Exception {
public:
	const char* what () const throw ();

private:
	const char* uid () const /*throw ()*/;

};

// Аргумент функции выходит за границы допустимых значений
class BadArgument : public ::Core::Exception {
public:
	const char* what () const throw ();

private:
	const char* uid () const /*throw ()*/;

};

#pragma pack (push, 1)

struct Point {
	float x;
	float y;
	float z;
};

#pragma pack (pop)

// таблица точек, полученная при триангуляции
typedef std::vector < Core::Box<Point> > PointsTable;

#pragma pack (push, 1)

struct TriangleInfo {
	size_t index1;
	size_t index2;
	size_t index3;
};

#pragma pack (pop)

// предсатвление поверхности триангуляцией
typedef std::vector < Core::Box<TriangleInfo> > TrianglesTable;

class Location;
typedef ::Core::Var<Location> Location_var;
typedef ::Core::Var<const Location> Location_cvar;
// получить матрицу трансформации поверхности
class Location
	: virtual public ::Core::IObject
{
public:
	virtual float get_index (size_t row, size_t column) const /*throw (BadArgument)*/ = 0;
};

/// factory interface for Location
class LocationFactory {
public:
	static Location* make (const gp_Trsf& trsf)
		/*throw (Core::Root::NoActiveFactory, Core::Root::FactoryManagerWasDestroyed)*/;
};

class Face;
typedef ::Core::Var<Face> Face_var;
typedef ::Core::Var<const Face> Face_cvar;
// Сетка на фигуре
class Face
	: virtual public ::Core::IObject
{
public:
	virtual PointsTable* get_points_table () const = 0;

	virtual PointsTable* get_normals_table () const = 0;

	virtual TrianglesTable* get_triangles_table () const = 0;

	virtual Location* get_location () const = 0;

	virtual PointsTable* get_wire_points (size_t index) const = 0;

	// Количество wires для данного face
	virtual size_t get_wires_count () const = 0;
};

/// factory interface for Face
class FaceFactory {
public:
	static Face* make (const TopoDS_Face& id)
		/*throw (Core::Root::NoActiveFactory, Core::Root::FactoryManagerWasDestroyed)*/;
};

class NameWrapper;
typedef ::Core::Var<NameWrapper> NameWrapper_var;
typedef ::Core::Var<const NameWrapper> NameWrapper_cvar;
class NameWrapper
	: virtual public ::Core::IObject
{
public:
	virtual const char* get_name () const = 0;
};

/// factory interface for NameWrapper
class NameWrapperFactory {
public:
	static NameWrapper* make (const char* data)
		/*throw (Core::Root::NoActiveFactory, Core::Root::FactoryManagerWasDestroyed)*/;
};

// список поверхностей для данной фигуры
typedef std::vector < Face_var > FaceList;

// - COMPOUND: A group of any of the shapes below.
// - COMPSOLID: A set of solids connected by their
// faces. This expands the notions of WIRE and SHELL to solids.
// - SOLID: A part of 3D space bounded by shells.
// - SHELL: A set of faces connected by some of the
// edges of their wire boundaries. A shell can be open or closed.
// - FACE: Part of a plane (in 2D geometry) or a surface
// (in 3D geometry) bounded by a closed wire. Its
// geometry is constrained (trimmed) by contours.
// - WIRE: A sequence of edges connected by their
// vertices. It can be open or closed depending on
// whether the edges are linked or not.
// - EDGE: A single dimensional shape corresponding
// to a curve, and bound by a vertex at each extremity.
// - VERTEX: A zero-dimensional shape corresponding to a point in geometry.
enum ShapeType {
	ST_COMPOUND
	, ST_COMPSOLID
	, ST_SOLID
	, ST_SHELL
	, ST_FACE
	, ST_WIRE
	, ST_EDGE
	, ST_VERTEX
	, ST_SHAPE
};

class Shape;
typedef ::Core::Var<Shape> Shape_var;
typedef ::Core::Var<const Shape> Shape_cvar;

class Shape;

typedef std::vector < Shape_var > ShapeList;

// фигура
class Shape
	: virtual public ::Core::IObject
{
public:
	// имя топологической фигуры, являющейся базовой для данной
	virtual const NameWrapper& get_main_name () const = 0;

	// параметр, задающий точность триангуляции
	virtual const double get_deflection () const = 0;

	virtual void set_deflection (double deflection) = 0;

	// имя конкретной фигуры
	virtual const NameWrapper& get_local_name () const = 0;

	// Возвращает список дочерних фигур для заданной
	virtual ShapeList* get_children_list () const = 0;

	// возвращает список поверхностей для заданной фигуры
	virtual FaceList* get_face_list () const = 0;

	// координаты текущей фигуры
	virtual Location* get_location () const = 0;

	// замкнута ли поверхность
	virtual bool is_closed () const = 0;

	// сравнивает 2 фигуры на равенство
	virtual bool is_equal (const Shape* to_compare) const = 0;

	// возвращает топологический объект, являющийся отцом заданного
	virtual Shape* get_original_shape () const = 0;

	virtual const TDF_Label& get_label () const = 0;

	// вернуть тип топологического объекта
	virtual ShapeType get_type () const = 0;

	// возвращает список поверхностей для всех фигур, входящих в заданную (включая её саму)
	virtual FaceList* get_all_face_list () const = 0;
};

/// factory interface for Shape
class ShapeFactory {
public:
	static Shape* make (const TDF_Label& id, const Handle_TDocStd_Document& doc, const TDF_Label& location_label)
		/*throw (Core::Root::NoActiveFactory, Core::Root::FactoryManagerWasDestroyed)*/;
};

class StepManager;
typedef ::Core::Var<StepManager> StepManager_var;
typedef ::Core::Var<const StepManager> StepManager_cvar;
// Основной интерфейс для работы с данными, полученными из step-файла
class StepManager
	: virtual public ::Core::IObject
{
public:
	// Количество фигур верхнего уровня (не являющихся частью других фигур)
	virtual size_t get_roots_count () const = 0;

	// Возвращает заданную фигуру верхнего уровня
	virtual Shape* get_root (size_t index) const /*throw (BadArgument)*/ = 0;
};

/// factory interface for StepManager
class StepManagerFactory {
public:
	static StepManager* make (const char* file_name)
		/*throw (Core::Root::NoActiveFactory, Core::Root::FactoryManagerWasDestroyed, CantReadFile)*/;
};

} // namespace Step
} // namespace StepWrapper

// TypeTraits specializations
namespace Core {	
template <>
struct TypeTraits <StepWrapper::Step::Location> {
	typedef StepWrapper::Step::LocationFactory Factory;
};
template <>
struct TypeTraits <StepWrapper::Step::Face> {
	typedef StepWrapper::Step::FaceFactory Factory;
};
template <>
struct TypeTraits <StepWrapper::Step::NameWrapper> {
	typedef StepWrapper::Step::NameWrapperFactory Factory;
};
template <>
struct TypeTraits <StepWrapper::Step::Shape> {
	typedef StepWrapper::Step::ShapeFactory Factory;
};
template <>
struct TypeTraits <StepWrapper::Step::StepManager> {
	typedef StepWrapper::Step::StepManagerFactory Factory;
};
} // namespace Core


#endif //__CAD_STEPWRAPPER_STEP_H__
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
