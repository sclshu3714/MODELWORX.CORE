#include <XBRepPrim_Revolution.h>

namespace TKPrim {
	XBRepPrim_Revolution::XBRepPrim_Revolution() {

	};

	XBRepPrim_Revolution::XBRepPrim_Revolution(BRepPrim_Revolution* handle) {
		NativeHandle = handle;
		SetOneAxisHandle(NativeHandle);
	};

	void XBRepPrim_Revolution::SetRevolutionHandle(BRepPrim_Revolution* handle) {
		NativeHandle = handle;
		SetOneAxisHandle(NativeHandle);
	};

	BRepPrim_Revolution* XBRepPrim_Revolution::GetRevolution() {
		return NativeHandle;
	};

	BRepPrim_OneAxis* XBRepPrim_Revolution::GetOneAxis() {
		return NativeHandle;
	};
	//! Create a  revolution body <M>  is the  meridian nd
	//! must   be in the XZ  plane   of <A>. <PM>  is  the
	//! meridian in the XZ plane.
	XBRepPrim_Revolution::XBRepPrim_Revolution(xgp_Ax2^ A, Standard_Real VMin, Standard_Real VMax, XGeom_Curve^ M, XGeom2d_Curve^ PM) {
		NativeHandle = new BRepPrim_Revolution(*A->GetAx2(), VMin, VMax, M->GetCurve(), PM->GetCurve());
		SetOneAxisHandle(NativeHandle);
	};

	//! The surface normal should be directed  towards the
	//! outside.
	XTopoDS_Face^ XBRepPrim_Revolution::MakeEmptyLateralFace() {
		TopoDS_Face* aFace = new TopoDS_Face(NativeHandle->MakeEmptyLateralFace());
		return gcnew XTopoDS_Face(aFace);
	};

	//! Returns  an  edge with  a 3D curve   made from the
	//! meridian  in the XZ  plane rotated by <Ang> around
	//! the Z-axis. Ang may be 0 or myAngle.
	XTopoDS_Edge^ XBRepPrim_Revolution::MakeEmptyMeridianEdge(Standard_Real Ang) {
		TopoDS_Edge* aEdge = new TopoDS_Edge(NativeHandle->MakeEmptyMeridianEdge(Ang));
		return gcnew XTopoDS_Edge(aEdge);
	};

	//! Returns the meridian point at parameter <V> in the
	//! plane XZ.
	xgp_Pnt2d^ XBRepPrim_Revolution::MeridianValue(Standard_Real V) {
		gp_Pnt2d* aPnt2d = new gp_Pnt2d(NativeHandle->MeridianValue(V));
		return gcnew xgp_Pnt2d(aPnt2d);
	};

	//! Sets the  parametric urve of  the edge <E>  in the
	//! face <F>   to be  the  2d  representation  of  the
	//! meridian.
	void XBRepPrim_Revolution::SetMeridianPCurve(XTopoDS_Edge^ E, XTopoDS_Face^ F) {
		NativeHandle->SetMeridianPCurve(*E->GetEdge(), *F->GetFace());
		SetOneAxisHandle(NativeHandle);
	};
}

