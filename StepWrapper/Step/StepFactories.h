////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Модуль: "w:/CAD/StepWrapper/Step/StepFactories.h"
// генератор заголовочных файлов для фабрик интерфейсов (.h)
// Generated from UML model, root element: <<Interfaces::Category>> CAD::StepWrapper::Step
//
//
// Все права принадлежат ООО НПП "Гарант-Сервис".
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __CAD_STEPWRAPPER_STEP_FCTR_H__
#define __CAD_STEPWRAPPER_STEP_FCTR_H__

#include "shared/Core/sys/std_inc.h"
#include <map>
#include <string>
#include "ace/Singleton.h"
#include "CAD/StepWrapper/Step/Step.h"

namespace StepWrapper {
namespace Step {

////////////////////////////////////////////////////////////////////////////////////
// factories definition for Location

class LocationAbstractFactory;

/// factory manager for Location
class LocationFactoryManager {
public:
	static void register_factory (LocationAbstractFactory* factory, Core::Root::FactoryPriority priority)
		/*throw (Core::Root::DuplicatedFactoryKey, Core::Root::FactoryManagerWasDestroyed)*/;

protected:
	LocationFactoryManager ();
	
	~LocationFactoryManager ();
	
	void register_factory_i (LocationAbstractFactory* factory, Core::Root::FactoryPriority priority)
		/*throw (Core::Root::DuplicatedFactoryKey)*/;

protected:
	Location* make (const gp_Trsf& trsf) /*throw (Core::Root::NoActiveFactory)*/;

	friend class LocationFactory;
	typedef ACE_Singleton <LocationFactoryManager, ACE_SYNCH_RECURSIVE_MUTEX> Singleton;
	friend class ACE_Singleton <LocationFactoryManager, ACE_SYNCH_RECURSIVE_MUTEX>;

private:
	static bool s_was_destroyed;
	
	bool m_has_registred_factories;
	
	struct FactoryData {
		Core::Var<LocationAbstractFactory> factory;
		short priority;
	};
	
	typedef std::map <std::string, FactoryData> FactoryMap;
	
	FactoryMap m_factories_map;
	
	Core::Var<LocationAbstractFactory> m_single_active_factory;
	
	short m_single_active_factory_priority;
};

/// abstract factory for Location
class LocationAbstractFactory : virtual public Core::IObject {
	friend class LocationFactoryManager;
protected:
	virtual const char* key () const = 0;

	virtual Location* make (const gp_Trsf& trsf) = 0;
};


////////////////////////////////////////////////////////////////////////////////////
// factories definition for Face

class FaceAbstractFactory;

/// factory manager for Face
class FaceFactoryManager {
public:
	static void register_factory (FaceAbstractFactory* factory, Core::Root::FactoryPriority priority)
		/*throw (Core::Root::DuplicatedFactoryKey, Core::Root::FactoryManagerWasDestroyed)*/;

protected:
	FaceFactoryManager ();
	
	~FaceFactoryManager ();
	
	void register_factory_i (FaceAbstractFactory* factory, Core::Root::FactoryPriority priority)
		/*throw (Core::Root::DuplicatedFactoryKey)*/;

protected:
	Face* make (const TopoDS_Face& id) /*throw (Core::Root::NoActiveFactory)*/;

	friend class FaceFactory;
	typedef ACE_Singleton <FaceFactoryManager, ACE_SYNCH_RECURSIVE_MUTEX> Singleton;
	friend class ACE_Singleton <FaceFactoryManager, ACE_SYNCH_RECURSIVE_MUTEX>;

private:
	static bool s_was_destroyed;
	
	bool m_has_registred_factories;
	
	struct FactoryData {
		Core::Var<FaceAbstractFactory> factory;
		short priority;
	};
	
	typedef std::map <std::string, FactoryData> FactoryMap;
	
	FactoryMap m_factories_map;
	
	Core::Var<FaceAbstractFactory> m_single_active_factory;
	
	short m_single_active_factory_priority;
};

/// abstract factory for Face
class FaceAbstractFactory : virtual public Core::IObject {
	friend class FaceFactoryManager;
protected:
	virtual const char* key () const = 0;

	virtual Face* make (const TopoDS_Face& id) = 0;
};


////////////////////////////////////////////////////////////////////////////////////
// factories definition for NameWrapper

class NameWrapperAbstractFactory;

/// factory manager for NameWrapper
class NameWrapperFactoryManager {
public:
	static void register_factory (NameWrapperAbstractFactory* factory, Core::Root::FactoryPriority priority)
		/*throw (Core::Root::DuplicatedFactoryKey, Core::Root::FactoryManagerWasDestroyed)*/;

protected:
	NameWrapperFactoryManager ();
	
	~NameWrapperFactoryManager ();
	
	void register_factory_i (NameWrapperAbstractFactory* factory, Core::Root::FactoryPriority priority)
		/*throw (Core::Root::DuplicatedFactoryKey)*/;

protected:
	NameWrapper* make (const char* data) /*throw (Core::Root::NoActiveFactory)*/;

	friend class NameWrapperFactory;
	typedef ACE_Singleton <NameWrapperFactoryManager, ACE_SYNCH_RECURSIVE_MUTEX> Singleton;
	friend class ACE_Singleton <NameWrapperFactoryManager, ACE_SYNCH_RECURSIVE_MUTEX>;

private:
	static bool s_was_destroyed;
	
	bool m_has_registred_factories;
	
	struct FactoryData {
		Core::Var<NameWrapperAbstractFactory> factory;
		short priority;
	};
	
	typedef std::map <std::string, FactoryData> FactoryMap;
	
	FactoryMap m_factories_map;
	
	Core::Var<NameWrapperAbstractFactory> m_single_active_factory;
	
	short m_single_active_factory_priority;
};

/// abstract factory for NameWrapper
class NameWrapperAbstractFactory : virtual public Core::IObject {
	friend class NameWrapperFactoryManager;
protected:
	virtual const char* key () const = 0;

	virtual NameWrapper* make (const char* data) = 0;
};


////////////////////////////////////////////////////////////////////////////////////
// factories definition for Shape

class ShapeAbstractFactory;

/// factory manager for Shape
class ShapeFactoryManager {
public:
	static void register_factory (ShapeAbstractFactory* factory, Core::Root::FactoryPriority priority)
		/*throw (Core::Root::DuplicatedFactoryKey, Core::Root::FactoryManagerWasDestroyed)*/;

protected:
	ShapeFactoryManager ();
	
	~ShapeFactoryManager ();
	
	void register_factory_i (ShapeAbstractFactory* factory, Core::Root::FactoryPriority priority)
		/*throw (Core::Root::DuplicatedFactoryKey)*/;

protected:
	Shape* make (
		const TDF_Label& id
		, const Handle_TDocStd_Document& doc
		, const TDF_Label& location_label
	) /*throw (Core::Root::NoActiveFactory)*/;

	friend class ShapeFactory;
	typedef ACE_Singleton <ShapeFactoryManager, ACE_SYNCH_RECURSIVE_MUTEX> Singleton;
	friend class ACE_Singleton <ShapeFactoryManager, ACE_SYNCH_RECURSIVE_MUTEX>;

private:
	static bool s_was_destroyed;
	
	bool m_has_registred_factories;
	
	struct FactoryData {
		Core::Var<ShapeAbstractFactory> factory;
		short priority;
	};
	
	typedef std::map <std::string, FactoryData> FactoryMap;
	
	FactoryMap m_factories_map;
	
	Core::Var<ShapeAbstractFactory> m_single_active_factory;
	
	short m_single_active_factory_priority;
};

/// abstract factory for Shape
class ShapeAbstractFactory : virtual public Core::IObject {
	friend class ShapeFactoryManager;
protected:
	virtual const char* key () const = 0;

	virtual Shape* make (const TDF_Label& id, const Handle_TDocStd_Document& doc, const TDF_Label& location_label) = 0;
};


////////////////////////////////////////////////////////////////////////////////////
// factories definition for StepManager

class StepManagerAbstractFactory;

/// factory manager for StepManager
class StepManagerFactoryManager {
public:
	static void register_factory (StepManagerAbstractFactory* factory, Core::Root::FactoryPriority priority)
		/*throw (Core::Root::DuplicatedFactoryKey, Core::Root::FactoryManagerWasDestroyed)*/;

protected:
	StepManagerFactoryManager ();
	
	~StepManagerFactoryManager ();
	
	void register_factory_i (StepManagerAbstractFactory* factory, Core::Root::FactoryPriority priority)
		/*throw (Core::Root::DuplicatedFactoryKey)*/;

protected:
	StepManager* make (const char* file_name) /*throw (Core::Root::NoActiveFactory, CantReadFile)*/;

	friend class StepManagerFactory;
	typedef ACE_Singleton <StepManagerFactoryManager, ACE_SYNCH_RECURSIVE_MUTEX> Singleton;
	friend class ACE_Singleton <StepManagerFactoryManager, ACE_SYNCH_RECURSIVE_MUTEX>;

private:
	static bool s_was_destroyed;
	
	bool m_has_registred_factories;
	
	struct FactoryData {
		Core::Var<StepManagerAbstractFactory> factory;
		short priority;
	};
	
	typedef std::map <std::string, FactoryData> FactoryMap;
	
	FactoryMap m_factories_map;
	
	Core::Var<StepManagerAbstractFactory> m_single_active_factory;
	
	short m_single_active_factory_priority;
};

/// abstract factory for StepManager
class StepManagerAbstractFactory : virtual public Core::IObject {
	friend class StepManagerFactoryManager;
protected:
	virtual const char* key () const = 0;

	virtual StepManager* make (const char* file_name) /*throw (CantReadFile)*/ = 0;
};

} // namespace Step
} // namespace StepWrapper


#endif //__CAD_STEPWRAPPER_STEP_FCTR_H__
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

