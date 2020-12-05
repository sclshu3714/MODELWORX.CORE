#include <XBRepPrim_Cone.h>

namespace TKPrim {
	XBRepPrim_Cone::XBRepPrim_Cone() {
		
	};

	XBRepPrim_Cone::XBRepPrim_Cone(BRepPrim_Cone* handle) {
		NativeHandle = handle;
		SetRevolutionHandle(NativeHandle);
	};

	void XBRepPrim_Cone::SetPrimConeHandle(BRepPrim_Cone* handle) {
		NativeHandle = handle;
		SetRevolutionHandle(NativeHandle);
	};

	BRepPrim_Cone* XBRepPrim_Cone::GetPrimCone() {
		return NativeHandle;
	};

	BRepPrim_Revolution* XBRepPrim_Cone::GetRevolution() {
		return NativeHandle;
	};

	BRepPrim_OneAxis* XBRepPrim_Cone::GetOneAxis() {
		return NativeHandle;
	};

	//! the STEP definition
	//! Angle = semi-angle of the cone
	//! Position : the coordinate system
	//! Height : height of the cone.
	//! Radius : radius of truncated face at z = 0
	//!
	//! The apex is on z < 0
	//!
	//! Errors : Height < Resolution
	//! Angle < Resolution / Height
	//! Angle > PI/2 - Resolution / Height
	//! Radius = 0
	XBRepPrim_Cone::XBRepPrim_Cone(Standard_Real Angle, xgp_Ax2^ Position, Standard_Real Height, Standard_Real Radius) {
		NativeHandle = new BRepPrim_Cone(Angle, *Position->GetAx2(), Height, Radius);
		SetRevolutionHandle(NativeHandle);
	};

	//! infinite cone at origin on Z negative
	XBRepPrim_Cone::XBRepPrim_Cone(Standard_Real Angle) {
		NativeHandle = new BRepPrim_Cone(Angle);
		SetRevolutionHandle(NativeHandle);
	};

	//! infinite cone at Apex on Z negative
	XBRepPrim_Cone::XBRepPrim_Cone(Standard_Real Angle, xgp_Pnt^ Apex) {
		NativeHandle = new BRepPrim_Cone(Angle, *Apex->GetPnt());
		SetRevolutionHandle(NativeHandle);
	};

	//! infinite cone with Axes
	XBRepPrim_Cone::XBRepPrim_Cone(Standard_Real Angle, xgp_Ax2^ Axes) {
		NativeHandle = new BRepPrim_Cone(Angle, *Axes->GetAx2());
		SetRevolutionHandle(NativeHandle);
	};

	//! create a  Cone at origin  on Z axis, of height  H,
	//! radius R1 at Z = 0, R2 at  Z = H, X is  the origin
	//! of angles.  If R1 or  R2 is 0   there is  an apex.
	//! Otherwise, it is a truncated cone.
	//!
	//! Error  : R1 and R2  < Resolution
	//! R1 or R2 negative
	//! Abs(R1-R2) < Resolution
	//! H < Resolution
	//! H negative
	XBRepPrim_Cone::XBRepPrim_Cone(Standard_Real R1, Standard_Real R2, Standard_Real H) {
		NativeHandle = new BRepPrim_Cone(R1, R2, H);
		SetRevolutionHandle(NativeHandle);
	};

	//! same as above but at a given point
	XBRepPrim_Cone::XBRepPrim_Cone(xgp_Pnt^ Center, Standard_Real R1, Standard_Real R2, Standard_Real H) {
		NativeHandle = new BRepPrim_Cone(R1, R2, H);
		SetRevolutionHandle(NativeHandle);
	};

	//! same as above with given axes system.
	XBRepPrim_Cone::XBRepPrim_Cone(xgp_Ax2^ Axes, Standard_Real R1, Standard_Real R2, Standard_Real H) {
		NativeHandle = new BRepPrim_Cone(*Axes->GetAx2(), R1, R2, H);
		SetRevolutionHandle(NativeHandle);
	};

	//! The surface normal should be directed  towards the
	//! outside.
	XTopoDS_Face^ XBRepPrim_Cone::MakeEmptyLateralFace() {
		TopoDS_Face* aFace = new TopoDS_Face(NativeHandle->MakeEmptyLateralFace());
		return gcnew XTopoDS_Face(aFace);
	};
}