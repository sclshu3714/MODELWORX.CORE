#include <XBRepAlgoAPI_Common.h>
namespace TKBO {
	//! Empty constructor
	XBRepAlgoAPI_Common::XBRepAlgoAPI_Common() {
		NativeHandle = new BRepAlgoAPI_Common();
	};
	XBRepAlgoAPI_Common::~XBRepAlgoAPI_Common() {
		NativeHandle->~BRepAlgoAPI_Common();
		NativeHandle = NULL;
	};

	//! Empty constructor
	//! <PF> - PaveFiller object that is carried out
	XBRepAlgoAPI_Common::XBRepAlgoAPI_Common(const BOPAlgo_PaveFiller& PF) {
		NativeHandle = new BRepAlgoAPI_Common(PF);
	};

	//! Constructor with two shapes
	//! <S1>  -argument
	//! <S2>  -tool
	//! <anOperation> - the type of the operation
	//! Obsolete
	XBRepAlgoAPI_Common::XBRepAlgoAPI_Common(XTopoDS_Shape^ S1, XTopoDS_Shape^ S2) {
		NativeHandle = new BRepAlgoAPI_Common(*S1->GetShape(), *S2->GetShape());
	};

	//! Constructor with two shapes
	//! <S1>  -argument
	//! <S2>  -tool
	//! <anOperation> - the type of the operation
	//! <PF> - PaveFiller object that is carried out
	//! Obsolete
	XBRepAlgoAPI_Common::XBRepAlgoAPI_Common(XTopoDS_Shape^ S1, XTopoDS_Shape^ S2, const BOPAlgo_PaveFiller& PF) {
		NativeHandle = new BRepAlgoAPI_Common(*S1->GetShape(), *S2->GetShape(), PF);
	};

	//! »ñÈ¡Í¼ÐÎ
	XTopoDS_Shape^ XBRepAlgoAPI_Common::Shape() {
		TopoDS_Shape* S1 = new TopoDS_Shape(NativeHandle->Shape());
		return gcnew XTopoDS_Shape(S1);
	};// Standard_OVERRIDE;
}



