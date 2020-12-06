#include <XBRepAlgoAPI_Section.h>

namespace TKBO {

	//! Empty constructor
	XBRepAlgoAPI_Section::XBRepAlgoAPI_Section() {
		NativeHandle = new BRepAlgoAPI_Section();
	};
	XBRepAlgoAPI_Section::~XBRepAlgoAPI_Section() {
		NativeHandle->~BRepAlgoAPI_Section();
	};

	//! Empty constructor
	//! <PF> - PaveFiller object that is carried out
	XBRepAlgoAPI_Section::XBRepAlgoAPI_Section(const BOPAlgo_PaveFiller& PF) {
		NativeHandle = new BRepAlgoAPI_Section(PF);
	};

	//! Constructor with two shapes
	//! <S1>  -argument
	//! <S2>  -tool
	//! <PerformNow> - the flag:
	//! if <PerformNow>=True - the algorithm is performed immediatly
	//! Obsolete
	//! const Standard_Boolean PerformNow = Standard_True
	XBRepAlgoAPI_Section::XBRepAlgoAPI_Section(XTopoDS_Shape^ S1, XTopoDS_Shape^ S2, Standard_Boolean PerformNow) {
		NativeHandle = new BRepAlgoAPI_Section(*S1->GetShape(), *S2->GetShape(), PerformNow);
	};

	//! Constructor with two shapes
	//! <S1>  -argument
	//! <S2>  -tool
	//! <PF> - PaveFiller object that is carried out
	//! <PerformNow> - the flag:
	//! if <PerformNow>=True - the algorithm is performed immediatly
	//! Obsolete
	//! const Standard_Boolean PerformNow = Standard_True
	XBRepAlgoAPI_Section::XBRepAlgoAPI_Section(XTopoDS_Shape^ S1, XTopoDS_Shape^ S2, const BOPAlgo_PaveFiller& aDSF, Standard_Boolean PerformNow) {
		NativeHandle = new BRepAlgoAPI_Section(*S1->GetShape(), *S2->GetShape(), aDSF, PerformNow);
	};

	//! Constructor with two shapes
	//! <S1>  - argument
	//! <Pl>  - tool
	//! <PerformNow> - the flag:
	//! if <PerformNow>=True - the algorithm is performed immediatly
	//! Obsolete
	//! const Standard_Boolean PerformNow = Standard_True
	XBRepAlgoAPI_Section::XBRepAlgoAPI_Section(XTopoDS_Shape^ S1, xgp_Pln^ Pl, Standard_Boolean PerformNow) {
		NativeHandle = new BRepAlgoAPI_Section(*S1->GetShape(), *Pl->GetPln(), PerformNow);
	};

	//! Constructor with two shapes
	//! <S1>  - argument
	//! <Sf>  - tool
	//! <PerformNow> - the flag:
	//! if <PerformNow>=True - the algorithm is performed immediatly
	//! Obsolete
	//! const Standard_Boolean PerformNow = Standard_True
	XBRepAlgoAPI_Section::XBRepAlgoAPI_Section(XTopoDS_Shape^ S1, XGeom_Surface^ Sf, Standard_Boolean PerformNow) {
		NativeHandle = new BRepAlgoAPI_Section(*S1->GetShape(), Sf->GetSurface(), PerformNow);
	};

	//! Constructor with two shapes
	//! <Sf>  - argument
	//! <S2>  - tool
	//! <PerformNow> - the flag:
	//! if <PerformNow>=True - the algorithm is performed immediatly
	//! Obsolete
	//! const Standard_Boolean PerformNow = Standard_True
	XBRepAlgoAPI_Section::XBRepAlgoAPI_Section(XGeom_Surface^ Sf, XTopoDS_Shape^ S2, Standard_Boolean PerformNow) {
		NativeHandle = new BRepAlgoAPI_Section(Sf->GetSurface(), *S2->GetShape(), PerformNow);
	};

	//! Constructor with two shapes
	//! <Sf1>  - argument
	//! <Sf2>  - tool
	//! <PerformNow> - the flag:
	//! if <PerformNow>=True - the algorithm is performed immediatly
	//! Obsolete
	//! const Standard_Boolean PerformNow = Standard_True
	XBRepAlgoAPI_Section::XBRepAlgoAPI_Section(XGeom_Surface^ Sf1, XGeom_Surface^ Sf2, Standard_Boolean PerformNow) {
		NativeHandle = new BRepAlgoAPI_Section(Sf1->GetSurface(), Sf2->GetSurface(), PerformNow);
	};

	//! initialize the argument
	//! <S1>  - argument
	//! Obsolete
	void XBRepAlgoAPI_Section::Init1(XTopoDS_Shape^ S1) {
		NativeHandle->Init1(*S1->GetShape());
	};

	//! initialize the argument
	//! <Pl>  - argument
	//! Obsolete
	void XBRepAlgoAPI_Section::Init1(xgp_Pln^ Pl) {
		NativeHandle->Init1(*Pl->GetPln());
	};

	//! initialize the argument
	//! <Sf>  - argument
	//! Obsolete
	void XBRepAlgoAPI_Section::Init1(XGeom_Surface^ Sf) {
		NativeHandle->Init1(Sf->GetSurface());
	};

	//! initialize the tool
	//! <S2>  - tool
	//! Obsolete
	void XBRepAlgoAPI_Section::Init2(XTopoDS_Shape^ S2) {
		NativeHandle->Init2(*S2->GetShape());
	};

	//! initialize the tool
	//! <Pl>  - tool
	//! Obsolete
	void XBRepAlgoAPI_Section::Init2(xgp_Pln^ Pl) {
		NativeHandle->Init2(*Pl->GetPln());
	};

	//! initialize the tool
	//! <Sf>  - tool
	//! Obsolete
	void XBRepAlgoAPI_Section::Init2(XGeom_Surface^ Sf) {
		NativeHandle->Init2(Sf->GetSurface());
	};

	void XBRepAlgoAPI_Section::Approximation(Standard_Boolean B) {
		NativeHandle->Approximation(B);
	};


	//! Indicates whether the P-Curve should be (or not)
	//! performed on the argument.
	//! By default, no parametric 2D curve (pcurve) is defined for the
	//! edges of the result.
	//! If ComputePCurve1 equals true, further computations performed
	//! to attach an P-Curve in the parametric space of the argument
	//! to the constructed edges.
	//! Obsolete
	void XBRepAlgoAPI_Section::ComputePCurveOn1(Standard_Boolean B) {
		NativeHandle->ComputePCurveOn1(B);
	};


	//! Indicates whether the P-Curve should be (or not)
	//! performed on the tool.
	//! By default, no parametric 2D curve (pcurve) is defined for the
	//! edges of the result.
	//! If ComputePCurve1 equals true, further computations performed
	//! to attach an P-Curve in the parametric space of the tool
	//! to the constructed edges.
	//! Obsolete
	void XBRepAlgoAPI_Section::ComputePCurveOn2(Standard_Boolean B) {
		NativeHandle->ComputePCurveOn2(B);
	};

	//! Performs the algorithm
	//! Filling interference Data Structure (if it is necessary)
	//! Building the result of the operation.
	void XBRepAlgoAPI_Section::Build() {
		NativeHandle->Build();
	};


	//! get the face of the first part giving section edge <E>.
	//! Returns True on the 3 following conditions :
	//! 1/ <E> is an edge returned by the Shape() metwod.
	//! 2/ First part of section performed is a shape.
	//! 3/ <E> is built on a intersection curve (i.e <E>
	//! is not the result of common edges)
	//! When False, F remains untouched.
	//! Obsolete
	Standard_Boolean XBRepAlgoAPI_Section::HasAncestorFaceOn1(XTopoDS_Shape^ E, XTopoDS_Shape^ F) {
		return NativeHandle->HasAncestorFaceOn1(*E->GetShape(), *F->GetShape());
	};

	//! Identifies the ancestor faces of
	//! the intersection edge E resulting from the last
	//! computation performed in this framework, that is, the faces of
	//! the two original shapes on which the edge E lies:
	//! -      HasAncestorFaceOn1 gives the ancestor face in the first shape, and
	//! -      HasAncestorFaceOn2 gives the ancestor face in the second shape.
	//! These functions return true if an ancestor face F is found, or false if not.
	//! An ancestor face is identifiable for the edge E if the following
	//! conditions are satisfied:
	//! -  the first part on which this algorithm performed its
	//! last computation is a shape, that is, it was not given as
	//! a surface or a plane at the time of construction of this
	//! algorithm or at a later time by the Init1 function,
	//! - E is one of the elementary edges built by the
	//! last computation of this section algorithm.
	//! To use these functions properly, you have to test the returned
	//! Boolean value before using the ancestor face: F is significant
	//! only if the returned Boolean value equals true.
	//! Obsolete
	Standard_Boolean XBRepAlgoAPI_Section::HasAncestorFaceOn2(XTopoDS_Shape^ E, XTopoDS_Shape^ F) {
		return NativeHandle->HasAncestorFaceOn2(*E->GetShape(), *F->GetShape());
	};

	//! »ñÈ¡Í¼ÐÎ
	XTopoDS_Shape^ XBRepAlgoAPI_Section::Shape() {
		TopoDS_Shape* S1 = new TopoDS_Shape(NativeHandle->Shape());
		return gcnew XTopoDS_Shape(S1);
	};// Standard_OVERRIDE;
}