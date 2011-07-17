////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Модуль: "w:/CAD/StepWrapperTarget/StepWrapperTarget.h"
// генератор заголовочных файлов C++ (.h)
// Generated from UML model, root element: <<AdapterTarget::Category>> CAD::StepWrapperTarget
//
//
// Все права принадлежат ООО НПП "Гарант-Сервис".
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __CAD_STEPWRAPPERTARGET_H__
#define __CAD_STEPWRAPPERTARGET_H__

#include "shared/Core/sys/std_inc.h"
#include "CAD/StepWrapper/Step/StepFactories.h"

namespace StepWrapperTarget {

class Root : virtual public Core::RefCountObjectBase {
public:
	virtual StepWrapper::Step::StepManager* make_step_manager (
		const char* file_name
	
	) {
		return StepWrapper::Step::StepManagerFactory::make(file_name);
	}


	
	typedef ACE_Singleton <Root, ACE_SYNCH_RECURSIVE_MUTEX> Singleton;
	friend class ACE_Singleton <Root, ACE_SYNCH_RECURSIVE_MUTEX>;
};

class DllInintializator {
public:
	static void init (unsigned long client_version, const char* locale_string);
	static void done ();

private:
	static Core::Mutex s_init_mutex;
	static unsigned long s_count;
};
} //namespace StepWrapperTarget


extern "C" __declspec (dllexport) void __stdcall dll_init (unsigned long client_version);

extern "C" __declspec (dllexport) void __stdcall dll_init_with_locale (unsigned long client_version, const char* locale_string);

extern "C" __declspec (dllexport) void __stdcall dll_done ();

extern "C" __declspec (dllexport) void __stdcall dll_get_root (
	StepWrapperTarget::Root*& root
);
extern "C" __declspec (dllexport) unsigned long __stdcall dll_version ();


#endif //__CAD_STEPWRAPPERTARGET_H__
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
