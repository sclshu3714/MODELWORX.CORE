#include <AIS_InteractiveObject.hxx>
#include <Standard_GUID.hxx>
#include <Standard_Type.hxx>
#include <TDF_Label.hxx>
#include <TDocStd_Document.hxx>
#include <XCAFDoc_ShapeTool.hxx>
#include <XCAFPrs_AISObject.hxx>
#include <XCAFPrs_Driver.hxx>
#include "XXCAFPrs_Driver.h"

namespace TKXCAF {
	Standard_Boolean XXCAFPrs_Driver::Update(const TDF_Label& L, Handle(AIS_InteractiveObject)& ais) {
		XCAFDoc_ShapeTool shapes;
		if (!shapes.IsShape(L)) return Standard_False;
		ais = new XCAFPrs_AISObject(L);
		return Standard_True;
	};

	Standard_Boolean XXCAFPrs_Driver::Update(XTDF_Label^ L, XAIS_InteractiveObject^ ais) {
		XCAFDoc_ShapeTool shapes;
		if (!shapes.IsShape(L->GetLabel())) return Standard_False;
		Handle(AIS_InteractiveObject) Handle_Ais = new XCAFPrs_AISObject(L->GetLabel());
		ais = gcnew XAIS_InteractiveObject(Handle_Ais);
		return Standard_True;
	};
	//! returns GUID of the driver
	const XStandard_GUID^ XXCAFPrs_Driver::GetID() {
		return gcnew XStandard_GUID(XCAFPrs_Driver::GetID());
	};
}