////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Модуль: "w:/CAD/StepWrapper/Step/StepFactories.cpp"
// генератор файлов реализации для фабрик интерфейсов (.cpp)
// Generated from UML model, root element: <<Interfaces::Category>> CAD::StepWrapper::Step
//
//
// Все права принадлежат ООО НПП "Гарант-Сервис".
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "shared/Core/sys/std_inc.h"
#include "CAD/StepWrapper/Step/StepFactories.h"

namespace StepWrapper {
namespace Step {

//////////////////////////////////////////////////////////////////////////////////////
// implementation of factory manager methods for Location
bool LocationFactoryManager::s_was_destroyed = false;

LocationFactoryManager::LocationFactoryManager () /*throw (Core::Root::FactoryManagerWasDestroyed)*/
	: m_has_registred_factories(false)
{
	if (s_was_destroyed == true) {
		throw Core::Root::FactoryManagerWasDestroyed ();
	}
}

LocationFactoryManager::~LocationFactoryManager () {
	s_was_destroyed = true;
}

void LocationFactoryManager::register_factory (
	LocationAbstractFactory* factory, Core::Root::FactoryPriority priority
) /*throw (Core::Root::DuplicatedFactoryKey, Core::Root::FactoryManagerWasDestroyed)*/ {
	if (s_was_destroyed == true) {
		throw Core::Root::FactoryManagerWasDestroyed ();
	}
	Singleton::instance()->register_factory_i (factory, priority);
}

void LocationFactoryManager::register_factory_i (
	LocationAbstractFactory* factory, Core::Root::FactoryPriority priority
) /*throw (Core::Root::DuplicatedFactoryKey)*/ {
	m_has_registred_factories = true;
	FactoryMap::iterator f = m_factories_map.find(factory->key());
	if (f != m_factories_map.end() && f->second.priority == priority) {
		throw Core::Root::DuplicatedFactoryKey (
			"StepWrapper::Step::LocationFactory"
			, factory->key()
		);
	}
	if (f == m_factories_map.end() || f->second.priority <= priority) {
		m_factories_map[factory->key()].factory = LocationAbstractFactory::_duplicate(factory);
		m_factories_map[factory->key()].priority = priority;
	}
	
	if (!m_single_active_factory || m_single_active_factory_priority <= priority) {
		m_single_active_factory = LocationAbstractFactory::_duplicate(factory);
		m_single_active_factory_priority = priority;
	}
}

Location* LocationFactoryManager::make (const gp_Trsf& trsf) /*throw (Core::Root::NoActiveFactory)*/ {
	if (m_single_active_factory.is_nil()) {
		throw Core::Root::NoActiveFactory ("StepWrapper::Step::LocationFactory");
	}
	Location* ret_ = m_single_active_factory->make (trsf);
	GDS_ASSERT_MSG (ret_ != 0, ("StepWrapper::Step::LocationFactory impl can't return zerro"));
	return ret_;
}

//////////////////////////////////////////////////////////////////////////////////////
// implementation of factory manager methods for Face
bool FaceFactoryManager::s_was_destroyed = false;

FaceFactoryManager::FaceFactoryManager () /*throw (Core::Root::FactoryManagerWasDestroyed)*/
	: m_has_registred_factories(false)
{
	if (s_was_destroyed == true) {
		throw Core::Root::FactoryManagerWasDestroyed ();
	}
}

FaceFactoryManager::~FaceFactoryManager () {
	s_was_destroyed = true;
}

void FaceFactoryManager::register_factory (
	FaceAbstractFactory* factory, Core::Root::FactoryPriority priority
) /*throw (Core::Root::DuplicatedFactoryKey, Core::Root::FactoryManagerWasDestroyed)*/ {
	if (s_was_destroyed == true) {
		throw Core::Root::FactoryManagerWasDestroyed ();
	}
	Singleton::instance()->register_factory_i (factory, priority);
}

void FaceFactoryManager::register_factory_i (
	FaceAbstractFactory* factory, Core::Root::FactoryPriority priority
) /*throw (Core::Root::DuplicatedFactoryKey)*/ {
	m_has_registred_factories = true;
	FactoryMap::iterator f = m_factories_map.find(factory->key());
	if (f != m_factories_map.end() && f->second.priority == priority) {
		throw Core::Root::DuplicatedFactoryKey (
			"StepWrapper::Step::FaceFactory"
			, factory->key()
		);
	}
	if (f == m_factories_map.end() || f->second.priority <= priority) {
		m_factories_map[factory->key()].factory = FaceAbstractFactory::_duplicate(factory);
		m_factories_map[factory->key()].priority = priority;
	}
	
	if (!m_single_active_factory || m_single_active_factory_priority <= priority) {
		m_single_active_factory = FaceAbstractFactory::_duplicate(factory);
		m_single_active_factory_priority = priority;
	}
}

Face* FaceFactoryManager::make (const TopoDS_Face& id) /*throw (Core::Root::NoActiveFactory)*/ {
	if (m_single_active_factory.is_nil()) {
		throw Core::Root::NoActiveFactory ("StepWrapper::Step::FaceFactory");
	}
	Face* ret_ = m_single_active_factory->make (id);
	GDS_ASSERT_MSG (ret_ != 0, ("StepWrapper::Step::FaceFactory impl can't return zerro"));
	return ret_;
}

//////////////////////////////////////////////////////////////////////////////////////
// implementation of factory manager methods for NameWrapper
bool NameWrapperFactoryManager::s_was_destroyed = false;

NameWrapperFactoryManager::NameWrapperFactoryManager () /*throw (Core::Root::FactoryManagerWasDestroyed)*/
	: m_has_registred_factories(false)
{
	if (s_was_destroyed == true) {
		throw Core::Root::FactoryManagerWasDestroyed ();
	}
}

NameWrapperFactoryManager::~NameWrapperFactoryManager () {
	s_was_destroyed = true;
}

void NameWrapperFactoryManager::register_factory (
	NameWrapperAbstractFactory* factory, Core::Root::FactoryPriority priority
) /*throw (Core::Root::DuplicatedFactoryKey, Core::Root::FactoryManagerWasDestroyed)*/ {
	if (s_was_destroyed == true) {
		throw Core::Root::FactoryManagerWasDestroyed ();
	}
	Singleton::instance()->register_factory_i (factory, priority);
}

void NameWrapperFactoryManager::register_factory_i (
	NameWrapperAbstractFactory* factory, Core::Root::FactoryPriority priority
) /*throw (Core::Root::DuplicatedFactoryKey)*/ {
	m_has_registred_factories = true;
	FactoryMap::iterator f = m_factories_map.find(factory->key());
	if (f != m_factories_map.end() && f->second.priority == priority) {
		throw Core::Root::DuplicatedFactoryKey (
			"StepWrapper::Step::NameWrapperFactory"
			, factory->key()
		);
	}
	if (f == m_factories_map.end() || f->second.priority <= priority) {
		m_factories_map[factory->key()].factory = NameWrapperAbstractFactory::_duplicate(factory);
		m_factories_map[factory->key()].priority = priority;
	}
	
	if (!m_single_active_factory || m_single_active_factory_priority <= priority) {
		m_single_active_factory = NameWrapperAbstractFactory::_duplicate(factory);
		m_single_active_factory_priority = priority;
	}
}

NameWrapper* NameWrapperFactoryManager::make (const char* data) /*throw (Core::Root::NoActiveFactory)*/ {
	if (m_single_active_factory.is_nil()) {
		throw Core::Root::NoActiveFactory ("StepWrapper::Step::NameWrapperFactory");
	}
	NameWrapper* ret_ = m_single_active_factory->make (data);
	GDS_ASSERT_MSG (ret_ != 0, ("StepWrapper::Step::NameWrapperFactory impl can't return zerro"));
	return ret_;
}

//////////////////////////////////////////////////////////////////////////////////////
// implementation of factory manager methods for Shape
bool ShapeFactoryManager::s_was_destroyed = false;

ShapeFactoryManager::ShapeFactoryManager () /*throw (Core::Root::FactoryManagerWasDestroyed)*/
	: m_has_registred_factories(false)
{
	if (s_was_destroyed == true) {
		throw Core::Root::FactoryManagerWasDestroyed ();
	}
}

ShapeFactoryManager::~ShapeFactoryManager () {
	s_was_destroyed = true;
}

void ShapeFactoryManager::register_factory (
	ShapeAbstractFactory* factory, Core::Root::FactoryPriority priority
) /*throw (Core::Root::DuplicatedFactoryKey, Core::Root::FactoryManagerWasDestroyed)*/ {
	if (s_was_destroyed == true) {
		throw Core::Root::FactoryManagerWasDestroyed ();
	}
	Singleton::instance()->register_factory_i (factory, priority);
}

void ShapeFactoryManager::register_factory_i (
	ShapeAbstractFactory* factory, Core::Root::FactoryPriority priority
) /*throw (Core::Root::DuplicatedFactoryKey)*/ {
	m_has_registred_factories = true;
	FactoryMap::iterator f = m_factories_map.find(factory->key());
	if (f != m_factories_map.end() && f->second.priority == priority) {
		throw Core::Root::DuplicatedFactoryKey (
			"StepWrapper::Step::ShapeFactory"
			, factory->key()
		);
	}
	if (f == m_factories_map.end() || f->second.priority <= priority) {
		m_factories_map[factory->key()].factory = ShapeAbstractFactory::_duplicate(factory);
		m_factories_map[factory->key()].priority = priority;
	}
	
	if (!m_single_active_factory || m_single_active_factory_priority <= priority) {
		m_single_active_factory = ShapeAbstractFactory::_duplicate(factory);
		m_single_active_factory_priority = priority;
	}
}

Shape* ShapeFactoryManager::make (const TDF_Label& id, const Handle_TDocStd_Document& doc, const TDF_Label& location_label) /*throw (Core::Root::NoActiveFactory)*/ {
	if (m_single_active_factory.is_nil()) {
		throw Core::Root::NoActiveFactory ("StepWrapper::Step::ShapeFactory");
	}
	Shape* ret_ = m_single_active_factory->make (id, doc, location_label);
	GDS_ASSERT_MSG (ret_ != 0, ("StepWrapper::Step::ShapeFactory impl can't return zerro"));
	return ret_;
}

//////////////////////////////////////////////////////////////////////////////////////
// implementation of factory manager methods for StepManager
bool StepManagerFactoryManager::s_was_destroyed = false;

StepManagerFactoryManager::StepManagerFactoryManager () /*throw (Core::Root::FactoryManagerWasDestroyed)*/
	: m_has_registred_factories(false)
{
	if (s_was_destroyed == true) {
		throw Core::Root::FactoryManagerWasDestroyed ();
	}
}

StepManagerFactoryManager::~StepManagerFactoryManager () {
	s_was_destroyed = true;
}

void StepManagerFactoryManager::register_factory (
	StepManagerAbstractFactory* factory, Core::Root::FactoryPriority priority
) /*throw (Core::Root::DuplicatedFactoryKey, Core::Root::FactoryManagerWasDestroyed)*/ {
	if (s_was_destroyed == true) {
		throw Core::Root::FactoryManagerWasDestroyed ();
	}
	Singleton::instance()->register_factory_i (factory, priority);
}

void StepManagerFactoryManager::register_factory_i (
	StepManagerAbstractFactory* factory, Core::Root::FactoryPriority priority
) /*throw (Core::Root::DuplicatedFactoryKey)*/ {
	m_has_registred_factories = true;
	FactoryMap::iterator f = m_factories_map.find(factory->key());
	if (f != m_factories_map.end() && f->second.priority == priority) {
		throw Core::Root::DuplicatedFactoryKey (
			"StepWrapper::Step::StepManagerFactory"
			, factory->key()
		);
	}
	if (f == m_factories_map.end() || f->second.priority <= priority) {
		m_factories_map[factory->key()].factory = StepManagerAbstractFactory::_duplicate(factory);
		m_factories_map[factory->key()].priority = priority;
	}
	
	if (!m_single_active_factory || m_single_active_factory_priority <= priority) {
		m_single_active_factory = StepManagerAbstractFactory::_duplicate(factory);
		m_single_active_factory_priority = priority;
	}
}

StepManager* StepManagerFactoryManager::make (const char* file_name) /*throw (Core::Root::NoActiveFactory, CantReadFile)*/ {
	if (m_single_active_factory.is_nil()) {
		throw Core::Root::NoActiveFactory ("StepWrapper::Step::StepManagerFactory");
	}
	StepManager* ret_ = m_single_active_factory->make (file_name);
	GDS_ASSERT_MSG (ret_ != 0, ("StepWrapper::Step::StepManagerFactory impl can't return zerro"));
	return ret_;
}
} // namespace Step
} // namespace StepWrapper

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

