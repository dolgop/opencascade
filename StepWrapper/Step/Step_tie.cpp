////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Модуль: "w:/CAD/StepWrapper/Step/Step_tie.cpp"
// С++ TIE-обвязка для DLL (_tie.cpp)
// Generated from UML model, root element: <<Interfaces::Category>> CAD::StepWrapper::Step
//
//
// Все права принадлежат ООО НПП "Гарант-Сервис".
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "shared/Core/sys/std_inc.h"
#include "CAD/StepWrapper/Step/Step_tie.h"

namespace StepWrapper {
namespace Step {

const ::Core::ComIID PointsTable_tie::s_com_iid = {0xE9B9F2F6, 0xBD5D, 0x45E2, {0x94, 0x0E, 0x9F, 0xA6, 0x0A, 0x3B, 0xC8, 0x12}};

unsigned long __stdcall PointsTable_tie::query_interface (
	const ::Core::ComIID& iid
	, void*& object
) {
	if (iid == s_com_iid) {
		this->addref();
		object = this;
		return 0x00000000UL;
	} else {
		return 0x80004002UL;
	}
}

unsigned long __stdcall PointsTable_tie::addref () const {
	return ++m_counter;
}

unsigned long __stdcall PointsTable_tie::release () const {
	long const counter = --m_counter;
	if (counter == 0) {
		MyPool::instance()->release_obj(const_cast<PointsTable_tie* const>(this));
	}
	return counter;
}

void PointsTable_tie::init () {
	m_counter = 1;
}

void PointsTable_tie::done () {
	if (m_orphan && m_impl) {
		delete m_impl;
	}
	m_impl = NULL;
	
	m_tie_owner.release ();
}

PointsTable_tie::PointsTable_tie () : m_impl(NULL), m_orphan(true) {
}

void PointsTable_tie::make_cpp (const PointsTable_tie* obj, PointsTable*& ret_) {
	if (!obj) {
		ret_ = 0;
	} else {
		ret_ = obj->m_impl;
	}
}

void PointsTable_tie::new_tie (PointsTable* obj, PointsTable_tie*& ret_) {
	Core::Aptr<PointsTable> obj_aptr (obj);
	if (obj_aptr.is_nil ()) {
		ret_ = NULL;
	} else {
		if (ret_) {
			ret_->release();
		}
		ret_ = MyPool::instance()->new_obj();
		ret_->m_impl = obj_aptr.forget ();
	}
}

void PointsTable_tie::make_tie (PointsTable* obj, PointsTable_tie*& ret_) {
	Core::Aptr<PointsTable> obj_aptr (obj);
	if (obj_aptr.is_nil () || obj_aptr->empty ()) {
		ret_ = NULL;
	} else {
		if (ret_) {
			ret_->release();
		}
		ret_ = MyPool::instance()->new_obj();
		ret_->m_impl = obj_aptr.forget ();
	}
}
	
void PointsTable_tie::make_tie (const PointsTable& obj, PointsTable_tie*& ret_) {
	if (ret_) {
		ret_->release();
	}
	if (obj.empty () == false) {
		ret_ = MyPool::instance()->new_obj();
		ret_->m_impl = new PointsTable (obj);
	} else {
		ret_ = NULL;
	}
}

void PointsTable_tie::make_tie (const PointsTable& obj, PointsTable_tie*& ret_, const Core::TIEBase* owner) {
	GDS_ASSERT(owner);
	if (ret_) {
		ret_->release();
	}
	
	if (obj.empty () == false) {
		ret_ = MyPool::instance()->new_obj();
		ret_->m_impl = const_cast<PointsTable*>(&obj);
		owner->addref ();
		ret_->m_tie_owner = owner;
		if (owner) {
			ret_->m_orphan = false;
		}
	} else {
		ret_ = NULL;
	}
}


size_t __stdcall PointsTable_tie::get_count () const {
	return m_impl->size();
}

void __stdcall PointsTable_tie::set_count (size_t count) {
	m_impl->resize(count);
}

void __stdcall PointsTable_tie::clear () {
	m_impl->clear();
}

void __stdcall PointsTable_tie::delete_item (size_t index) {
	if ((size_t)index < m_impl->size()) {
		m_impl->erase(m_impl->begin() + index);
	} else {
		throw Core::IndexOutOfBounds_tie ();
	}
}

void __stdcall PointsTable_tie::get_item (size_t index, Point& ret_) {
	if ((size_t)index < m_impl->size()) {
		ret_ = *(*m_impl)[index];
	} else {
		throw Core::IndexOutOfBounds_tie ();
	}
}

void __stdcall PointsTable_tie::set_item (size_t index, const Point& item) {
	if ((size_t)index < m_impl->size()) {
		(*m_impl)[index] = item;
	} else {
		throw Core::IndexOutOfBounds_tie ();
	}
}

size_t __stdcall PointsTable_tie::add (const Point& item) {
	m_impl->push_back (item);
	return m_impl->size() - 1;
}

size_t __stdcall PointsTable_tie::insert (size_t index, const Point& item) {
	if ((size_t)index < m_impl->size()) {
		return std::distance (m_impl->begin(), m_impl->insert (m_impl->begin() + index, item));
	} else {
		throw Core::IndexOutOfBounds_tie ();
	}
}

const ::Core::ComIID TrianglesTable_tie::s_com_iid = {0x61DF71CB, 0x2C82, 0x4AEC, {0x89, 0x7D, 0x70, 0x83, 0x24, 0x80, 0xE8, 0xE0}};

unsigned long __stdcall TrianglesTable_tie::query_interface (
	const ::Core::ComIID& iid
	, void*& object
) {
	if (iid == s_com_iid) {
		this->addref();
		object = this;
		return 0x00000000UL;
	} else {
		return 0x80004002UL;
	}
}

unsigned long __stdcall TrianglesTable_tie::addref () const {
	return ++m_counter;
}

unsigned long __stdcall TrianglesTable_tie::release () const {
	long const counter = --m_counter;
	if (counter == 0) {
		MyPool::instance()->release_obj(const_cast<TrianglesTable_tie* const>(this));
	}
	return counter;
}

void TrianglesTable_tie::init () {
	m_counter = 1;
}

void TrianglesTable_tie::done () {
	if (m_orphan && m_impl) {
		delete m_impl;
	}
	m_impl = NULL;
	
	m_tie_owner.release ();
}

TrianglesTable_tie::TrianglesTable_tie () : m_impl(NULL), m_orphan(true) {
}

void TrianglesTable_tie::make_cpp (const TrianglesTable_tie* obj, TrianglesTable*& ret_) {
	if (!obj) {
		ret_ = 0;
	} else {
		ret_ = obj->m_impl;
	}
}

void TrianglesTable_tie::new_tie (TrianglesTable* obj, TrianglesTable_tie*& ret_) {
	Core::Aptr<TrianglesTable> obj_aptr (obj);
	if (obj_aptr.is_nil ()) {
		ret_ = NULL;
	} else {
		if (ret_) {
			ret_->release();
		}
		ret_ = MyPool::instance()->new_obj();
		ret_->m_impl = obj_aptr.forget ();
	}
}

void TrianglesTable_tie::make_tie (TrianglesTable* obj, TrianglesTable_tie*& ret_) {
	Core::Aptr<TrianglesTable> obj_aptr (obj);
	if (obj_aptr.is_nil () || obj_aptr->empty ()) {
		ret_ = NULL;
	} else {
		if (ret_) {
			ret_->release();
		}
		ret_ = MyPool::instance()->new_obj();
		ret_->m_impl = obj_aptr.forget ();
	}
}
	
void TrianglesTable_tie::make_tie (const TrianglesTable& obj, TrianglesTable_tie*& ret_) {
	if (ret_) {
		ret_->release();
	}
	if (obj.empty () == false) {
		ret_ = MyPool::instance()->new_obj();
		ret_->m_impl = new TrianglesTable (obj);
	} else {
		ret_ = NULL;
	}
}

void TrianglesTable_tie::make_tie (const TrianglesTable& obj, TrianglesTable_tie*& ret_, const Core::TIEBase* owner) {
	GDS_ASSERT(owner);
	if (ret_) {
		ret_->release();
	}
	
	if (obj.empty () == false) {
		ret_ = MyPool::instance()->new_obj();
		ret_->m_impl = const_cast<TrianglesTable*>(&obj);
		owner->addref ();
		ret_->m_tie_owner = owner;
		if (owner) {
			ret_->m_orphan = false;
		}
	} else {
		ret_ = NULL;
	}
}


size_t __stdcall TrianglesTable_tie::get_count () const {
	return m_impl->size();
}

void __stdcall TrianglesTable_tie::set_count (size_t count) {
	m_impl->resize(count);
}

void __stdcall TrianglesTable_tie::clear () {
	m_impl->clear();
}

void __stdcall TrianglesTable_tie::delete_item (size_t index) {
	if ((size_t)index < m_impl->size()) {
		m_impl->erase(m_impl->begin() + index);
	} else {
		throw Core::IndexOutOfBounds_tie ();
	}
}

void __stdcall TrianglesTable_tie::get_item (size_t index, TriangleInfo& ret_) {
	if ((size_t)index < m_impl->size()) {
		ret_ = *(*m_impl)[index];
	} else {
		throw Core::IndexOutOfBounds_tie ();
	}
}

void __stdcall TrianglesTable_tie::set_item (size_t index, const TriangleInfo& item) {
	if ((size_t)index < m_impl->size()) {
		(*m_impl)[index] = item;
	} else {
		throw Core::IndexOutOfBounds_tie ();
	}
}

size_t __stdcall TrianglesTable_tie::add (const TriangleInfo& item) {
	m_impl->push_back (item);
	return m_impl->size() - 1;
}

size_t __stdcall TrianglesTable_tie::insert (size_t index, const TriangleInfo& item) {
	if ((size_t)index < m_impl->size()) {
		return std::distance (m_impl->begin(), m_impl->insert (m_impl->begin() + index, item));
	} else {
		throw Core::IndexOutOfBounds_tie ();
	}
}

const ::Core::ComIID Location_tie::s_com_iid = {0x5FA812D9, 0xDAEF, 0x417B, {0xB4, 0x76, 0x86, 0x7D, 0x82, 0x3D, 0x62, 0xFC}};

Location_tie::IidRegistrator Location_tie::s_iid_registrator;

Location_tie::Location_tie () : m_impl(NULL) {
}

unsigned long __stdcall Location_tie::query_interface (
	const ::Core::ComIID& iid
	, void*& object
) {
	if (iid == s_com_iid) {
		this->addref();
		object = this;
		return 0x00000000UL;
	} else {
		return ::Core::IidMapManagerSgl::instance()->tie_query_interface (iid, m_impl, object);
	}
}
unsigned long __stdcall Location_tie::addref () const {
	return ++m_counter;
}

unsigned long __stdcall Location_tie::release () const {
	long const counter = --m_counter;
	if (counter == 0) {
		MyPool::instance()->release_obj(const_cast<Location_tie* const>(this));
	}
	return counter;
}

void Location_tie::init () {
		m_counter = 1;
	}

void Location_tie::done () {
	m_impl->release();
	m_impl = NULL;
	
	m_tie_owner.release ();
}

void* Location_tie::cast (::Core::IObject* obj) {
	Location* ret = dynamic_cast<Location*>(obj);
	if (ret) {
		ret->addref();
	}
	ILocation_tie* ret_ = NULL;
	Location_tie::make_tie (ret, ret_);
	return ret_;
}

void Location_tie::make_cpp (const ILocation_tie* obj, Location*& ret_, bool interface_addref) {
	if (!obj) {
		ret_ = 0;
	} else {
		ret_ = dynamic_cast<Location*> (obj->get_impl ());
		if (interface_addref) {
			ret_->addref();
		}
	}
}

void Location_tie::make_tie (const Location* obj, ILocation_tie*& ret_, bool interface_addref) {
	if (!obj) {
		ret_ = NULL;
	} else {
		if (ret_) {
			ret_->release();
		}
		Location_tie* ret = MyPool::instance()->new_obj();
		ret->m_impl = const_cast<Location*>(obj);
		if (interface_addref) {
			ret->m_impl->addref();
		}
		ret_ = ret;
	}
}

void Location_tie::make_tie (const Location& obj, ILocation_tie*& ret_, const Core::TIEBase* owner) {
	if (ret_) {
		ret_->release();
	}
	Location_tie* ret = MyPool::instance()->new_obj();
	ret->m_impl = const_cast<Location*>(&obj);

	ret->m_impl->addref();
	owner->addref ();
	ret->m_tie_owner = owner;
	
	ret_ = ret;
}

::Core::IObject* Location_tie::get_impl () const {
	return m_impl;
}

float __stdcall Location_tie::get_index_48BBAB1202E1 (
	size_t row
	, size_t column
) const /*throw (BadArgument_tie)*/ {
_DLL_TRY
	return m_impl->get_index (row, column);
_DLL_CATCH
}



const ::Core::ComIID Face_tie::s_com_iid = {0x1DABC3CF, 0x750E, 0x49B8, {0x81, 0x11, 0x08, 0xEE, 0x3D, 0xD7, 0x73, 0xD8}};

Face_tie::IidRegistrator Face_tie::s_iid_registrator;

Face_tie::Face_tie () : m_impl(NULL) {
}

unsigned long __stdcall Face_tie::query_interface (
	const ::Core::ComIID& iid
	, void*& object
) {
	if (iid == s_com_iid) {
		this->addref();
		object = this;
		return 0x00000000UL;
	} else {
		return ::Core::IidMapManagerSgl::instance()->tie_query_interface (iid, m_impl, object);
	}
}
unsigned long __stdcall Face_tie::addref () const {
	return ++m_counter;
}

unsigned long __stdcall Face_tie::release () const {
	long const counter = --m_counter;
	if (counter == 0) {
		MyPool::instance()->release_obj(const_cast<Face_tie* const>(this));
	}
	return counter;
}

void Face_tie::init () {
		m_counter = 1;
	}

void Face_tie::done () {
	m_impl->release();
	m_impl = NULL;
	
	m_tie_owner.release ();
}

void* Face_tie::cast (::Core::IObject* obj) {
	Face* ret = dynamic_cast<Face*>(obj);
	if (ret) {
		ret->addref();
	}
	IFace_tie* ret_ = NULL;
	Face_tie::make_tie (ret, ret_);
	return ret_;
}

void Face_tie::make_cpp (const IFace_tie* obj, Face*& ret_, bool interface_addref) {
	if (!obj) {
		ret_ = 0;
	} else {
		ret_ = dynamic_cast<Face*> (obj->get_impl ());
		if (interface_addref) {
			ret_->addref();
		}
	}
}

void Face_tie::make_tie (const Face* obj, IFace_tie*& ret_, bool interface_addref) {
	if (!obj) {
		ret_ = NULL;
	} else {
		if (ret_) {
			ret_->release();
		}
		Face_tie* ret = MyPool::instance()->new_obj();
		ret->m_impl = const_cast<Face*>(obj);
		if (interface_addref) {
			ret->m_impl->addref();
		}
		ret_ = ret;
	}
}

void Face_tie::make_tie (const Face& obj, IFace_tie*& ret_, const Core::TIEBase* owner) {
	if (ret_) {
		ret_->release();
	}
	Face_tie* ret = MyPool::instance()->new_obj();
	ret->m_impl = const_cast<Face*>(&obj);

	ret->m_impl->addref();
	owner->addref ();
	ret->m_tie_owner = owner;
	
	ret_ = ret;
}

::Core::IObject* Face_tie::get_impl () const {
	return m_impl;
}

void __stdcall Face_tie::get_location_48C13840023D (
	ILocation_tie*& ret_
) const {
_DLL_TRY

	Location* ret = m_impl->get_location();
	Location_tie::make_tie(ret, ret_);
_DLL_CATCH
}

void __stdcall Face_tie::get_normals_table_48AD714A0033 (
	PointsTable_tie*& ret_
) const {
_DLL_TRY

	::Core::Aptr<PointsTable> ret = m_impl->get_normals_table();
	PointsTable_tie::make_tie(ret._retn(), ret_);
_DLL_CATCH
}

void __stdcall Face_tie::get_points_table_48AD698402A0 (
	PointsTable_tie*& ret_
) const {
_DLL_TRY

	::Core::Aptr<PointsTable> ret = m_impl->get_points_table();
	PointsTable_tie::make_tie(ret._retn(), ret_);
_DLL_CATCH
}

void __stdcall Face_tie::get_triangles_table_48AD69A7025D (
	TrianglesTable_tie*& ret_
) const {
_DLL_TRY

	::Core::Aptr<TrianglesTable> ret = m_impl->get_triangles_table();
	TrianglesTable_tie::make_tie(ret._retn(), ret_);
_DLL_CATCH
}

void __stdcall Face_tie::get_wire_points_48D74E9502C2 (
	size_t index
	, PointsTable_tie*& ret_
) const {
_DLL_TRY

	::Core::Aptr<PointsTable> ret = m_impl->get_wire_points(index);
	PointsTable_tie::make_tie(ret._retn(), ret_);
_DLL_CATCH
}

size_t __stdcall Face_tie::get_wires_count_48D7507E03D3 () const {
_DLL_TRY
	return m_impl->get_wires_count ();
_DLL_CATCH
}



const ::Core::ComIID NameWrapper_tie::s_com_iid = {0xCF85555E, 0x0F2C, 0x4310, {0x8D, 0x1C, 0x65, 0xC6, 0xDA, 0x73, 0xA3, 0xAE}};

NameWrapper_tie::IidRegistrator NameWrapper_tie::s_iid_registrator;

NameWrapper_tie::NameWrapper_tie () : m_impl(NULL) {
}

unsigned long __stdcall NameWrapper_tie::query_interface (
	const ::Core::ComIID& iid
	, void*& object
) {
	if (iid == s_com_iid) {
		this->addref();
		object = this;
		return 0x00000000UL;
	} else {
		return ::Core::IidMapManagerSgl::instance()->tie_query_interface (iid, m_impl, object);
	}
}
unsigned long __stdcall NameWrapper_tie::addref () const {
	return ++m_counter;
}

unsigned long __stdcall NameWrapper_tie::release () const {
	long const counter = --m_counter;
	if (counter == 0) {
		MyPool::instance()->release_obj(const_cast<NameWrapper_tie* const>(this));
	}
	return counter;
}

void NameWrapper_tie::init () {
		m_counter = 1;
	}

void NameWrapper_tie::done () {
	m_impl->release();
	m_impl = NULL;
	
	m_tie_owner.release ();
}

void* NameWrapper_tie::cast (::Core::IObject* obj) {
	NameWrapper* ret = dynamic_cast<NameWrapper*>(obj);
	if (ret) {
		ret->addref();
	}
	INameWrapper_tie* ret_ = NULL;
	NameWrapper_tie::make_tie (ret, ret_);
	return ret_;
}

void NameWrapper_tie::make_cpp (const INameWrapper_tie* obj, NameWrapper*& ret_, bool interface_addref) {
	if (!obj) {
		ret_ = 0;
	} else {
		ret_ = dynamic_cast<NameWrapper*> (obj->get_impl ());
		if (interface_addref) {
			ret_->addref();
		}
	}
}

void NameWrapper_tie::make_tie (const NameWrapper* obj, INameWrapper_tie*& ret_, bool interface_addref) {
	if (!obj) {
		ret_ = NULL;
	} else {
		if (ret_) {
			ret_->release();
		}
		NameWrapper_tie* ret = MyPool::instance()->new_obj();
		ret->m_impl = const_cast<NameWrapper*>(obj);
		if (interface_addref) {
			ret->m_impl->addref();
		}
		ret_ = ret;
	}
}

void NameWrapper_tie::make_tie (const NameWrapper& obj, INameWrapper_tie*& ret_, const Core::TIEBase* owner) {
	if (ret_) {
		ret_->release();
	}
	NameWrapper_tie* ret = MyPool::instance()->new_obj();
	ret->m_impl = const_cast<NameWrapper*>(&obj);

	ret->m_impl->addref();
	owner->addref ();
	ret->m_tie_owner = owner;
	
	ret_ = ret;
}

::Core::IObject* NameWrapper_tie::get_impl () const {
	return m_impl;
}

const char* __stdcall NameWrapper_tie::get_name_48BB91480179 () const {
_DLL_TRY
	return m_impl->get_name ();
_DLL_CATCH
}



const ::Core::ComIID FaceList_tie::s_com_iid = {0x0D7A3091, 0x18B8, 0x4D93, {0xA6, 0x0E, 0xCC, 0x8A, 0x93, 0xBA, 0xDE, 0x84}};

unsigned long __stdcall FaceList_tie::query_interface (
	const ::Core::ComIID& iid
	, void*& object
) {
	if (iid == s_com_iid) {
		this->addref();
		object = this;
		return 0x00000000UL;
	} else {
		return 0x80004002UL;
	}
}

unsigned long __stdcall FaceList_tie::addref () const {
	return ++m_counter;
}

unsigned long __stdcall FaceList_tie::release () const {
	long const counter = --m_counter;
	if (counter == 0) {
		MyPool::instance()->release_obj(const_cast<FaceList_tie* const>(this));
	}
	return counter;
}

void FaceList_tie::init () {
	m_counter = 1;
}

void FaceList_tie::done () {
	if (m_orphan && m_impl) {
		delete m_impl;
	}
	m_impl = NULL;
	
	m_tie_owner.release ();
}

FaceList_tie::FaceList_tie () : m_impl(NULL), m_orphan(true) {
}

void FaceList_tie::make_cpp (const FaceList_tie* obj, FaceList*& ret_) {
	if (!obj) {
		ret_ = 0;
	} else {
		ret_ = obj->m_impl;
	}
}

void FaceList_tie::new_tie (FaceList* obj, FaceList_tie*& ret_) {
	Core::Aptr<FaceList> obj_aptr (obj);
	if (obj_aptr.is_nil ()) {
		ret_ = NULL;
	} else {
		if (ret_) {
			ret_->release();
		}
		ret_ = MyPool::instance()->new_obj();
		ret_->m_impl = obj_aptr.forget ();
	}
}

void FaceList_tie::make_tie (FaceList* obj, FaceList_tie*& ret_) {
	Core::Aptr<FaceList> obj_aptr (obj);
	if (obj_aptr.is_nil () || obj_aptr->empty ()) {
		ret_ = NULL;
	} else {
		if (ret_) {
			ret_->release();
		}
		ret_ = MyPool::instance()->new_obj();
		ret_->m_impl = obj_aptr.forget ();
	}
}
	
void FaceList_tie::make_tie (const FaceList& obj, FaceList_tie*& ret_) {
	if (ret_) {
		ret_->release();
	}
	if (obj.empty () == false) {
		ret_ = MyPool::instance()->new_obj();
		ret_->m_impl = new FaceList (obj);
	} else {
		ret_ = NULL;
	}
}

void FaceList_tie::make_tie (const FaceList& obj, FaceList_tie*& ret_, const Core::TIEBase* owner) {
	GDS_ASSERT(owner);
	if (ret_) {
		ret_->release();
	}
	
	if (obj.empty () == false) {
		ret_ = MyPool::instance()->new_obj();
		ret_->m_impl = const_cast<FaceList*>(&obj);
		owner->addref ();
		ret_->m_tie_owner = owner;
		if (owner) {
			ret_->m_orphan = false;
		}
	} else {
		ret_ = NULL;
	}
}


size_t __stdcall FaceList_tie::get_count () const {
	return m_impl->size();
}

void __stdcall FaceList_tie::set_count (size_t count) {
	m_impl->resize(count);
}

void __stdcall FaceList_tie::clear () {
	m_impl->clear();
}

void __stdcall FaceList_tie::delete_item (size_t index) {
	if ((size_t)index < m_impl->size()) {
		m_impl->erase(m_impl->begin() + index);
	} else {
		throw Core::IndexOutOfBounds_tie ();
	}
}

void __stdcall FaceList_tie::get_item (size_t index, IFace_tie*& ret_) {
	if ((size_t)index < m_impl->size()) {
		Face_tie::make_tie ((*m_impl)[index].in(), ret_, true);
	} else {
		throw Core::IndexOutOfBounds_tie ();
	}
}

void __stdcall FaceList_tie::set_item (size_t index, const IFace_tie* item) {
	if ((size_t)index < m_impl->size()) {
		Face* item_;
		Face_tie::make_cpp (item, item_, true);
		(*m_impl)[index] = item_;
	} else {
		throw Core::IndexOutOfBounds_tie ();
	}
}

size_t __stdcall FaceList_tie::add (const IFace_tie* item) {
	Face* item_;
	Face_tie::make_cpp (item, item_, true);
	m_impl->push_back (item_);
	return m_impl->size() - 1;
}

size_t __stdcall FaceList_tie::insert (size_t index, const IFace_tie* item) {
	if ((size_t)index < m_impl->size()) {
		Face* item_;
		Face_tie::make_cpp (item, item_, true);
		return std::distance (m_impl->begin(), m_impl->insert (m_impl->begin() + index, item_));
	} else {
		throw Core::IndexOutOfBounds_tie ();
	}
}

const ::Core::ComIID Shape_tie::s_com_iid = {0x6AC53346, 0x3C79, 0x459B, {0xB7, 0x98, 0x98, 0xAD, 0x10, 0x78, 0xC8, 0xB5}};

Shape_tie::IidRegistrator Shape_tie::s_iid_registrator;

Shape_tie::Shape_tie () : m_impl(NULL) {
}

unsigned long __stdcall Shape_tie::query_interface (
	const ::Core::ComIID& iid
	, void*& object
) {
	if (iid == s_com_iid) {
		this->addref();
		object = this;
		return 0x00000000UL;
	} else {
		return ::Core::IidMapManagerSgl::instance()->tie_query_interface (iid, m_impl, object);
	}
}
unsigned long __stdcall Shape_tie::addref () const {
	return ++m_counter;
}

unsigned long __stdcall Shape_tie::release () const {
	long const counter = --m_counter;
	if (counter == 0) {
		MyPool::instance()->release_obj(const_cast<Shape_tie* const>(this));
	}
	return counter;
}

void Shape_tie::init () {
		m_counter = 1;
	}

void Shape_tie::done () {
	m_impl->release();
	m_impl = NULL;
	
	m_tie_owner.release ();
}

void* Shape_tie::cast (::Core::IObject* obj) {
	Shape* ret = dynamic_cast<Shape*>(obj);
	if (ret) {
		ret->addref();
	}
	IShape_tie* ret_ = NULL;
	Shape_tie::make_tie (ret, ret_);
	return ret_;
}

void Shape_tie::make_cpp (const IShape_tie* obj, Shape*& ret_, bool interface_addref) {
	if (!obj) {
		ret_ = 0;
	} else {
		ret_ = dynamic_cast<Shape*> (obj->get_impl ());
		if (interface_addref) {
			ret_->addref();
		}
	}
}

void Shape_tie::make_tie (const Shape* obj, IShape_tie*& ret_, bool interface_addref) {
	if (!obj) {
		ret_ = NULL;
	} else {
		if (ret_) {
			ret_->release();
		}
		Shape_tie* ret = MyPool::instance()->new_obj();
		ret->m_impl = const_cast<Shape*>(obj);
		if (interface_addref) {
			ret->m_impl->addref();
		}
		ret_ = ret;
	}
}

void Shape_tie::make_tie (const Shape& obj, IShape_tie*& ret_, const Core::TIEBase* owner) {
	if (ret_) {
		ret_->release();
	}
	Shape_tie* ret = MyPool::instance()->new_obj();
	ret->m_impl = const_cast<Shape*>(&obj);

	ret->m_impl->addref();
	owner->addref ();
	ret->m_tie_owner = owner;
	
	ret_ = ret;
}

::Core::IObject* Shape_tie::get_impl () const {
	return m_impl;
}


const double __stdcall Shape_tie::get_deflection () const {
_DLL_TRY
	return m_impl->get_deflection();
_DLL_CATCH
}
void __stdcall Shape_tie::set_deflection (double deflection) {
_DLL_TRY
	m_impl->set_deflection(deflection);
_DLL_CATCH
}

void __stdcall Shape_tie::get_all_face_list_48EA1BB50078 (
	FaceList_tie*& ret_
) const {
_DLL_TRY

	::Core::Aptr<FaceList> ret = m_impl->get_all_face_list();
	FaceList_tie::make_tie(ret._retn(), ret_);
_DLL_CATCH
}

void __stdcall Shape_tie::get_children_list_48AD65540010 (
	ShapeList_tie*& ret_
) const {
_DLL_TRY

	::Core::Aptr<ShapeList> ret = m_impl->get_children_list();
	ShapeList_tie::make_tie(ret._retn(), ret_);
_DLL_CATCH
}

void __stdcall Shape_tie::get_face_list_48AD66190301 (
	FaceList_tie*& ret_
) const {
_DLL_TRY

	::Core::Aptr<FaceList> ret = m_impl->get_face_list();
	FaceList_tie::make_tie(ret._retn(), ret_);
_DLL_CATCH
}

void __stdcall Shape_tie::get_location_48BE89F901CC (
	ILocation_tie*& ret_
) const {
_DLL_TRY

	Location* ret = m_impl->get_location();
	Location_tie::make_tie(ret, ret_);
_DLL_CATCH
}

void __stdcall Shape_tie::get_original_shape_48D900230195 (
	IShape_tie*& ret_
) const {
_DLL_TRY

	Shape* ret = m_impl->get_original_shape();
	Shape_tie::make_tie(ret, ret_);
_DLL_CATCH
}

ShapeType __stdcall Shape_tie::get_type_48E329810091 () const {
_DLL_TRY
	return m_impl->get_type ();
_DLL_CATCH
}

bool __stdcall Shape_tie::is_closed_48D749D80113 () const {
_DLL_TRY
	return m_impl->is_closed ();
_DLL_CATCH
}

bool __stdcall Shape_tie::is_equal_48D9001B029F (
	const IShape_tie* to_compare
) const {
_DLL_TRY
	Shape* to_compare_;
	Shape_tie::make_cpp(to_compare, to_compare_);

	bool ret = m_impl->is_equal(to_compare_);
	return ret;
_DLL_CATCH
}


void __stdcall Shape_tie::get_local_name (INameWrapper_tie*& ret_) {
_DLL_TRY
	NameWrapper_tie::make_tie (m_impl->get_local_name(), ret_, this);
_DLL_CATCH
}


void __stdcall Shape_tie::get_main_name (INameWrapper_tie*& ret_) {
_DLL_TRY
	NameWrapper_tie::make_tie (m_impl->get_main_name(), ret_, this);
_DLL_CATCH
}



const ::Core::ComIID ShapeList_tie::s_com_iid = {0x3CD99711, 0x71E6, 0x4C6F, {0x8A, 0x8D, 0x3E, 0xBA, 0xF6, 0xD0, 0x83, 0x0C}};

unsigned long __stdcall ShapeList_tie::query_interface (
	const ::Core::ComIID& iid
	, void*& object
) {
	if (iid == s_com_iid) {
		this->addref();
		object = this;
		return 0x00000000UL;
	} else {
		return 0x80004002UL;
	}
}

unsigned long __stdcall ShapeList_tie::addref () const {
	return ++m_counter;
}

unsigned long __stdcall ShapeList_tie::release () const {
	long const counter = --m_counter;
	if (counter == 0) {
		MyPool::instance()->release_obj(const_cast<ShapeList_tie* const>(this));
	}
	return counter;
}

void ShapeList_tie::init () {
	m_counter = 1;
}

void ShapeList_tie::done () {
	if (m_orphan && m_impl) {
		delete m_impl;
	}
	m_impl = NULL;
	
	m_tie_owner.release ();
}

ShapeList_tie::ShapeList_tie () : m_impl(NULL), m_orphan(true) {
}

void ShapeList_tie::make_cpp (const ShapeList_tie* obj, ShapeList*& ret_) {
	if (!obj) {
		ret_ = 0;
	} else {
		ret_ = obj->m_impl;
	}
}

void ShapeList_tie::new_tie (ShapeList* obj, ShapeList_tie*& ret_) {
	Core::Aptr<ShapeList> obj_aptr (obj);
	if (obj_aptr.is_nil ()) {
		ret_ = NULL;
	} else {
		if (ret_) {
			ret_->release();
		}
		ret_ = MyPool::instance()->new_obj();
		ret_->m_impl = obj_aptr.forget ();
	}
}

void ShapeList_tie::make_tie (ShapeList* obj, ShapeList_tie*& ret_) {
	Core::Aptr<ShapeList> obj_aptr (obj);
	if (obj_aptr.is_nil () || obj_aptr->empty ()) {
		ret_ = NULL;
	} else {
		if (ret_) {
			ret_->release();
		}
		ret_ = MyPool::instance()->new_obj();
		ret_->m_impl = obj_aptr.forget ();
	}
}
	
void ShapeList_tie::make_tie (const ShapeList& obj, ShapeList_tie*& ret_) {
	if (ret_) {
		ret_->release();
	}
	if (obj.empty () == false) {
		ret_ = MyPool::instance()->new_obj();
		ret_->m_impl = new ShapeList (obj);
	} else {
		ret_ = NULL;
	}
}

void ShapeList_tie::make_tie (const ShapeList& obj, ShapeList_tie*& ret_, const Core::TIEBase* owner) {
	GDS_ASSERT(owner);
	if (ret_) {
		ret_->release();
	}
	
	if (obj.empty () == false) {
		ret_ = MyPool::instance()->new_obj();
		ret_->m_impl = const_cast<ShapeList*>(&obj);
		owner->addref ();
		ret_->m_tie_owner = owner;
		if (owner) {
			ret_->m_orphan = false;
		}
	} else {
		ret_ = NULL;
	}
}


size_t __stdcall ShapeList_tie::get_count () const {
	return m_impl->size();
}

void __stdcall ShapeList_tie::set_count (size_t count) {
	m_impl->resize(count);
}

void __stdcall ShapeList_tie::clear () {
	m_impl->clear();
}

void __stdcall ShapeList_tie::delete_item (size_t index) {
	if ((size_t)index < m_impl->size()) {
		m_impl->erase(m_impl->begin() + index);
	} else {
		throw Core::IndexOutOfBounds_tie ();
	}
}

void __stdcall ShapeList_tie::get_item (size_t index, IShape_tie*& ret_) {
	if ((size_t)index < m_impl->size()) {
		Shape_tie::make_tie ((*m_impl)[index].in(), ret_, true);
	} else {
		throw Core::IndexOutOfBounds_tie ();
	}
}

void __stdcall ShapeList_tie::set_item (size_t index, const IShape_tie* item) {
	if ((size_t)index < m_impl->size()) {
		Shape* item_;
		Shape_tie::make_cpp (item, item_, true);
		(*m_impl)[index] = item_;
	} else {
		throw Core::IndexOutOfBounds_tie ();
	}
}

size_t __stdcall ShapeList_tie::add (const IShape_tie* item) {
	Shape* item_;
	Shape_tie::make_cpp (item, item_, true);
	m_impl->push_back (item_);
	return m_impl->size() - 1;
}

size_t __stdcall ShapeList_tie::insert (size_t index, const IShape_tie* item) {
	if ((size_t)index < m_impl->size()) {
		Shape* item_;
		Shape_tie::make_cpp (item, item_, true);
		return std::distance (m_impl->begin(), m_impl->insert (m_impl->begin() + index, item_));
	} else {
		throw Core::IndexOutOfBounds_tie ();
	}
}

const ::Core::ComIID StepManager_tie::s_com_iid = {0xBD33C6C6, 0x3616, 0x4411, {0xAB, 0x73, 0xDF, 0xF8, 0xD5, 0xAA, 0xC7, 0x31}};

StepManager_tie::IidRegistrator StepManager_tie::s_iid_registrator;

StepManager_tie::StepManager_tie () : m_impl(NULL) {
}

unsigned long __stdcall StepManager_tie::query_interface (
	const ::Core::ComIID& iid
	, void*& object
) {
	if (iid == s_com_iid) {
		this->addref();
		object = this;
		return 0x00000000UL;
	} else {
		return ::Core::IidMapManagerSgl::instance()->tie_query_interface (iid, m_impl, object);
	}
}
unsigned long __stdcall StepManager_tie::addref () const {
	return ++m_counter;
}

unsigned long __stdcall StepManager_tie::release () const {
	long const counter = --m_counter;
	if (counter == 0) {
		MyPool::instance()->release_obj(const_cast<StepManager_tie* const>(this));
	}
	return counter;
}

void StepManager_tie::init () {
		m_counter = 1;
	}

void StepManager_tie::done () {
	m_impl->release();
	m_impl = NULL;
	
	m_tie_owner.release ();
}

void* StepManager_tie::cast (::Core::IObject* obj) {
	StepManager* ret = dynamic_cast<StepManager*>(obj);
	if (ret) {
		ret->addref();
	}
	IStepManager_tie* ret_ = NULL;
	StepManager_tie::make_tie (ret, ret_);
	return ret_;
}

void StepManager_tie::make_cpp (const IStepManager_tie* obj, StepManager*& ret_, bool interface_addref) {
	if (!obj) {
		ret_ = 0;
	} else {
		ret_ = dynamic_cast<StepManager*> (obj->get_impl ());
		if (interface_addref) {
			ret_->addref();
		}
	}
}

void StepManager_tie::make_tie (const StepManager* obj, IStepManager_tie*& ret_, bool interface_addref) {
	if (!obj) {
		ret_ = NULL;
	} else {
		if (ret_) {
			ret_->release();
		}
		StepManager_tie* ret = MyPool::instance()->new_obj();
		ret->m_impl = const_cast<StepManager*>(obj);
		if (interface_addref) {
			ret->m_impl->addref();
		}
		ret_ = ret;
	}
}

void StepManager_tie::make_tie (const StepManager& obj, IStepManager_tie*& ret_, const Core::TIEBase* owner) {
	if (ret_) {
		ret_->release();
	}
	StepManager_tie* ret = MyPool::instance()->new_obj();
	ret->m_impl = const_cast<StepManager*>(&obj);

	ret->m_impl->addref();
	owner->addref ();
	ret->m_tie_owner = owner;
	
	ret_ = ret;
}

::Core::IObject* StepManager_tie::get_impl () const {
	return m_impl;
}

void __stdcall StepManager_tie::get_root_48AA87DA00F8 (
	size_t index
	, IShape_tie*& ret_
) const /*throw (BadArgument_tie)*/ {
_DLL_TRY

	Shape* ret = m_impl->get_root(index);
	Shape_tie::make_tie(ret, ret_);
_DLL_CATCH
}

size_t __stdcall StepManager_tie::get_roots_count_48AA874200FA () const {
_DLL_TRY
	return m_impl->get_roots_count ();
_DLL_CATCH
}



} // namespace Step
} // namespace StepWrapper

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

