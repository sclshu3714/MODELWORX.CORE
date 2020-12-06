#include <XBRepAlgoAPI_Fuse.h>

namespace TKBO {
	//! Empty constructor
	XBRepAlgoAPI_Fuse::XBRepAlgoAPI_Fuse() {
		NativeHandle = new BRepAlgoAPI_Fuse();
	};
	XBRepAlgoAPI_Fuse::~XBRepAlgoAPI_Fuse() {
		NativeHandle->~BRepAlgoAPI_Fuse();
	};

	//! Empty constructor
	//! <PF> - PaveFiller object that is carried out
	XBRepAlgoAPI_Fuse::XBRepAlgoAPI_Fuse(const BOPAlgo_PaveFiller& PF) {
		NativeHandle = new BRepAlgoAPI_Fuse(PF);
	};

	//! Constructor with two shapes
	//! <S1>  -argument
	//! <S2>  -tool
	//! <anOperation> - the type of the operation
	//! Obsolete
	XBRepAlgoAPI_Fuse::XBRepAlgoAPI_Fuse(XTopoDS_Shape^ S1, XTopoDS_Shape^ S2) {
		NativeHandle = new BRepAlgoAPI_Fuse(*S1->GetShape(), *S2->GetShape());
	};

	//! Constructor with two shapes
	//! <S1>  -argument
	//! <S2>  -tool
	//! <anOperation> - the type of the operation
	//! <PF> - PaveFiller object that is carried out
	//! Obsolete
	XBRepAlgoAPI_Fuse::XBRepAlgoAPI_Fuse(XTopoDS_Shape^ S1, XTopoDS_Shape^ S2, const BOPAlgo_PaveFiller& aDSF) {
		NativeHandle = new BRepAlgoAPI_Fuse(*S1->GetShape(), *S2->GetShape(), aDSF);
	};

	//! »ñÈ¡Í¼ÐÎ
	XTopoDS_Shape^ XBRepAlgoAPI_Fuse::Shape() {
		TopoDS_Shape* S1 = new TopoDS_Shape(NativeHandle->Shape());
		return gcnew XTopoDS_Shape(S1);
	};// Standard_OVERRIDE;
}
