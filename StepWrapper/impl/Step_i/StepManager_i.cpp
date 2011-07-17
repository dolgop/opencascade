////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Модуль: "w:/CAD/StepWrapper/impl/Step_i/StepManager_i.cpp"
// генератор файлов реализации C++ (.cpp)
// Generated from UML model, root element: <<Servant::Class>> CAD::StepWrapper::Step_i::StepManager_i
//
//
// Все права принадлежат ООО НПП "Гарант-Сервис".
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "shared/Core/sys/std_inc.h"
#include "CAD/StepWrapper/LibHome.h"
#include "CAD/StepWrapper/impl/Step_i/StepManager_i.h"

//#UC START# *489BF3290347_CUSTOM_INCLUDES*
#include <iostream>

#include <Interface_Static.hxx>

#include <STEPControl_Reader.hxx>
#include <STEPCAFControl_Reader.hxx>

#include <TDF_LabelSequence.hxx>
#include <TDF_ChildIterator.hxx>

#include <TDocStd_Document.hxx>

#include <XCAFDoc_ShapeTool.hxx>
#include <XCAFDoc_DocumentTool.hxx>
//#UC END# *489BF3290347_CUSTOM_INCLUDES*

namespace StepWrapper {
namespace Step_i {

//#UC START# *489BF3290347*
//#UC END# *489BF3290347*

//////////////////////////////////////////////////////////////////////////////////////////
// constructors and destructor

StepManager_i::StepManager_i (const char* file_name)
//#UC START# *489BF2EC0354_489BF346036A_489BF3290347_BASE_INIT*
//#UC END# *489BF2EC0354_489BF346036A_489BF3290347_BASE_INIT*
{
	//#UC START# *489BF2EC0354_489BF346036A_489BF3290347_BODY*
	STEPControl_Reader reader;
	STEPCAFControl_Reader caf_reader (reader.WS (), Standard_False);
	if(!Interface_Static::SetIVal("read.step.shape.repr", 2)) {
		std::cout << "can't set read.step.shape.repr";
	}

	IFSelect_ReturnStatus status = caf_reader.ReadFile (const_cast<char*> (file_name));
	if (status != IFSelect_RetDone) {
		std::cerr << "Bad status returned while reading step file: " << file_name << "(" << status << ")\n";

		throw Step::CantReadFile ();
	}

	Handle(XCAFApp_Application) app = XCAFApp_Application::GetApplication ();
	app->NewDocument ("MDTV-XCAF", m_doc);
	Standard_Boolean ok = caf_reader.Transfer (m_doc);
	if (!ok) {
		std::cerr << "Can't transfer step document to xde\n";

		throw Step::CantReadFile ();
	}
	//#UC END# *489BF2EC0354_489BF346036A_489BF3290347_BODY*
}

StepManager_i::~StepManager_i () {
	//#UC START# *489BF3290347_DESTR_BODY*
	//#UC END# *489BF3290347_DESTR_BODY*
}


//////////////////////////////////////////////////////////////////////////////////////////
// implemented interface's methods

// implemented method from Step::StepManager
// Возвращает заданную фигуру верхнего уровня
Step::Shape* StepManager_i::get_root (size_t index) const /*throw (Step::BadArgument)*/ {
	//#UC START# *48AA87DA00F8_489BF3290347*
	TDF_Label main_label = m_doc->Main ();
	Handle(XCAFDoc_ShapeTool) assembly = XCAFDoc_DocumentTool::ShapeTool (main_label);
	TDF_LabelSequence labels;
	assembly->GetFreeShapes (labels);

	if (static_cast<size_t> (labels.Length ()) <= index) {
		throw Step::BadArgument ();
	}
	TDF_Label root = labels.Value (index + 1);

	return Step::ShapeFactory::make (root, m_doc, root);
	//#UC END# *48AA87DA00F8_489BF3290347*
}

// implemented method from Step::StepManager
// Количество фигур верхнего уровня (не являющихся частью других фигур)
size_t StepManager_i::get_roots_count () const {
	//#UC START# *48AA874200FA_489BF3290347*
	TDF_Label main_label = m_doc->Main ();
	Handle(XCAFDoc_ShapeTool) assembly = XCAFDoc_DocumentTool::ShapeTool (main_label);
	TDF_LabelSequence labels;
	assembly->GetFreeShapes (labels);

	return labels.Length ();
	//#UC END# *48AA874200FA_489BF3290347*
}
} // namespace Step_i
} // namespace StepWrapper

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

