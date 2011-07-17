////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Модуль: "w:/CAD/StepWrapperTarget/StepWrapperTarget_tie.h"
// С++ TIE-обвязка для DLL (_tie.h)
// Generated from UML model, root element: <<AdapterTarget::Category>> CAD::StepWrapperTarget
//
//
// Все права принадлежат ООО НПП "Гарант-Сервис".
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __CAD_STEPWRAPPERTARGET_TIE_H__
#define __CAD_STEPWRAPPERTARGET_TIE_H__

#include "shared/Core/sys/std_inc.h"
#include "CAD/StepWrapper/Step/Step_tie.h"
#include "CAD/StepWrapper/Step/StepFactories.h"

namespace StepWrapperTarget {

class Root_tie {
	SET_OBJECT_COUNTER (Root_tie)
protected:
	virtual unsigned long __stdcall query_interface (
		const ::Core::ComIID& iid
		, void*& object
	) {
		static ::Core::ComIID my_iid = {0xF98207B3, 0xF212, 0x4528, {0x85, 0xF0, 0xE5, 0x6F, 0x34, 0x3C, 0x39, 0xBF}};
		if (my_iid == iid) {
			this->addref();
			object = this;
			return 0x00000000UL;
		} else {
			object = 0;
			return 0x80004002UL;
		}
	}

public:
	virtual unsigned long __stdcall addref () const {
		return ++m_counter;
	}

	virtual unsigned long __stdcall release () const {
		if (m_counter == 1) {
			delete this;
			return 0;
		}
		return --m_counter;
	}
	
private:
	typedef ACE_Singleton<Root_tie, ACE_SYNCH_RECURSIVE_MUTEX> Singleton;

	mutable ACE_Atomic_Op <ACE_Thread_Mutex, long> m_counter;

public:
	Root_tie () : m_counter (1) {
	}

	static Root_tie* instance() {
		return Singleton::instance();
	}

	// exported factories

	virtual void _stdcall make_face_list_48AD67E00266 (StepWrapper::Step::FaceList_tie*& ret_) {
		_DLL_TRY
		StepWrapper::Step::FaceList_tie::new_tie (new StepWrapper::Step::FaceList (), ret_);
		_DLL_CATCH
	}

	virtual void _stdcall make_points_table_48AD68CB00CB (StepWrapper::Step::PointsTable_tie*& ret_) {
		_DLL_TRY
		StepWrapper::Step::PointsTable_tie::new_tie (new StepWrapper::Step::PointsTable (), ret_);
		_DLL_CATCH
	}

	virtual void _stdcall make_shape_list_48AA886301C8 (StepWrapper::Step::ShapeList_tie*& ret_) {
		_DLL_TRY
		StepWrapper::Step::ShapeList_tie::new_tie (new StepWrapper::Step::ShapeList (), ret_);
		_DLL_CATCH
	}

	virtual void _stdcall make_step_manager_489BF346036A (
		const char* file_name
		, StepWrapper::Step::IStepManager_tie*& ret_
	) {
		_DLL_TRY
		StepWrapper::Step::StepManager_tie::make_tie (StepWrapper::Step::StepManagerFactory::make(file_name), ret_);
		_DLL_CATCH
	}

	virtual void _stdcall make_triangles_table_48AD694903A6 (StepWrapper::Step::TrianglesTable_tie*& ret_) {
		_DLL_TRY
		StepWrapper::Step::TrianglesTable_tie::new_tie (new StepWrapper::Step::TrianglesTable (), ret_);
		_DLL_CATCH
	}


};

} //namespace StepWrapperTarget

extern "C" __declspec (dllexport) unsigned long __stdcall tie_dll_version ();

extern "C" __declspec (dllexport) void __stdcall tie_dll_init_with_locale (unsigned long client_version, const char* locale_string);

extern "C" __declspec (dllexport) void __stdcall tie_dll_init (unsigned long client_version);

extern "C" __declspec (dllexport) void __stdcall tie_dll_done ();

extern "C" __declspec (dllexport) void __stdcall tie_dll_get_root (
	StepWrapperTarget::Root_tie*& root
);


#endif //__CAD_STEPWRAPPERTARGET_TIE_H__
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
