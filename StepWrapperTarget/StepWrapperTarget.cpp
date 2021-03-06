////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ������: "w:/CAD/StepWrapperTarget/StepWrapperTarget.cpp"
// ��������� ������ ���������� C++ (.cpp)
// Generated from UML model, root element: <<AdapterTarget::Category>> CAD::StepWrapperTarget
//
//
// ��� ����� ����������� ��� ��� "������-������".
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "shared/Core/sys/start_stop.h"
#include "shared/Core/sys/std_inc.h"
#include "CAD/StepWrapperTarget/StepWrapperTarget.h"
#include "shared/Core/GDS/MemoryWatcher.h"
#include "shared/Core/GDS/ObjectWatcher.h"	
#include "shared/Core/impl/Root_i/StdLibHomeManager_factory.h"
#include "shared/Core/impl/ParamsImpl/ParamManagerImpl_factory.h"
#include "shared/GCI/I18N/I18N.h"
#include "shared/GCI/impl/I18N_i/Environment.h"
#include "shared/GCI/impl/I18N_i/GarantWinLocaleOperations_factory.h"
#include "shared/GCI/impl/I18N_i/PosixLocaleOperations_factory.h"
#include "CAD/StepWrapper/LibHome.h"

#include "stdlib.h"

namespace StepWrapperTarget {
	Core::Mutex DllInintializator::s_init_mutex;
	unsigned long DllInintializator::s_count = 0;
	
	void DllInintializator::init (unsigned long client_version, const char* locale_string) {
		GUARD (s_init_mutex);
		if (s_count++ != 0) {
			return;
		}
		Core::init ();
		
		//GCI::I18N_i::Environment::set_default_locale (GCI::I18N::SL_RU_CP1251);
		//GCI::I18N::SupportedLocales locale = GCI::I18NHelper::string_to_locale (locale_string);
		//GCI::I18NHelper::set_locale (locale);
		
		if (dll_version () != client_version) {
			throw Core::Root::WrongVersion (client_version, dll_version ());
		}

		{
			Core::Root_i::StdLibHomeManager_factory_var f = new Core::Root_i::StdLibHomeManager_factory ();
			f->registrate_me(0);
		}
		{
			Core::ParamsImpl::ParamManagerImpl_factory_var f = new Core::ParamsImpl::ParamManagerImpl_factory ();
			f->registrate_me(0);
		}
		try {
			Core::ParamManagerInitData init = {"StepWrapperTarget", "Core::RegistryHelper::KEY_LOCAL_MACHINE\\Software\\CAD\\StepWrapperTarget"};
			Core::ParamManagerFactory::get ().init (Core::ParamConvert::make_arg_list (0, 0), init);
		} CATCH_AND_LOG ("while init ParamManager executed")
		Core::Root::LibHomeManager& lhm = Core::Root::LibHomeManagerFactory::get();
	
		lhm.registrate_lib_home (&StepWrapper::LibHomeFactory::get ());

		try {
			lhm.execute ();
		} CATCH_AND_LOG ("while HomeManager processed")
	}
	
	void DllInintializator::done () {
		GUARD (s_init_mutex);
		if (--s_count != 0) {
			return;
		}
		Core::Root::LibHomeManager& lhm = Core::Root::LibHomeManagerFactory::get();
		lhm.finalize ();

		Core::fini ();
	}

} //namespace StepWrapperTarget
extern "C" __declspec (dllexport) void __stdcall dll_init (unsigned long client_version) {
_DLL_TRY
	StepWrapperTarget::DllInintializator::init (client_version, "ru");
_DLL_CATCH
}

extern "C" __declspec (dllexport) void __stdcall dll_init_with_locale (unsigned long client_version, const char* locale_string) {
_DLL_TRY
	StepWrapperTarget::DllInintializator::init (client_version, locale_string);
_DLL_CATCH
}

extern "C" __declspec (dllexport) void __stdcall dll_done () {
_DLL_TRY
	StepWrapperTarget::DllInintializator::done ();
_DLL_CATCH
}

extern "C" __declspec (dllexport) void __stdcall dll_get_root(
	StepWrapperTarget::Root*& root
) {
_DLL_TRY
	root = StepWrapperTarget::Root::Singleton::instance();
	root->addref ();
_DLL_CATCH
}
extern "C" __declspec (dllexport) unsigned long __stdcall dll_version () {
	return 3;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
