#include <XBRepAlgoAPI_Cut.h>

namespace TKBO {

	//! Empty constructor
	XBRepAlgoAPI_Cut::XBRepAlgoAPI_Cut() {
		NativeHandle = new BRepAlgoAPI_Cut();
	};
	//! 
	XBRepAlgoAPI_Cut::~XBRepAlgoAPI_Cut() {
		NativeHandle = NULL;
	};

	//! Empty constructor
	//! <PF> - PaveFiller object that is carried out
	XBRepAlgoAPI_Cut::XBRepAlgoAPI_Cut(BOPAlgo_PaveFiller PF) {
		NativeHandle = new BRepAlgoAPI_Cut(PF);
	};

	//! Constructor with two shapes
	//! <S1>  -argument
	//! <S2>  -tool
	//! <anOperation> - the type of the operation
	//! Obsolete
	XBRepAlgoAPI_Cut::XBRepAlgoAPI_Cut(XTopoDS_Shape^ XS1, XTopoDS_Shape^ XS2) {
		TopoDS_Shape* S1 = new TopoDS_Shape(*XS1->GetShape());
		TopoDS_Shape* S2 = new TopoDS_Shape(*XS2->GetShape());
		NativeHandle = new BRepAlgoAPI_Cut(*S1, *S2);
	};

	//! Constructor with two shapes
	//! <S1>  -argument
	//! <S2>  -tool
	//! <anOperation> - the type of the operation
	//! <PF> - PaveFiller object that is carried out
	//! Obsolete
	//! const Standard_Boolean bFWD = Standard_True
	XBRepAlgoAPI_Cut::XBRepAlgoAPI_Cut(XTopoDS_Shape^ XS1, XTopoDS_Shape^ XS2, BOPAlgo_PaveFiller aDSF, Standard_Boolean bFWD) {
		TopoDS_Shape* S1 = new TopoDS_Shape(*XS1->GetShape());
		TopoDS_Shape* S2 = new TopoDS_Shape(*XS2->GetShape());
		NativeHandle = new BRepAlgoAPI_Cut(*S1, *S2, aDSF, bFWD);
	};

	XTopoDS_Shape^ XBRepAlgoAPI_Cut::Shape() {
		TopoDS_Shape* S1 = new TopoDS_Shape(NativeHandle->Shape());
		return gcnew XTopoDS_Shape(*S1);
	};
}