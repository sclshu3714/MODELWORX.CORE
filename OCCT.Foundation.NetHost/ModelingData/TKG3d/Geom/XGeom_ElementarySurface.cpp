#include <XGeom_ElementarySurface.h>
namespace TKG3d {

	//!
	XGeom_ElementarySurface::XGeom_ElementarySurface(void) {
		//NativeHandle() = new Geom_ElementarySurface();
	};

	//! 
	XGeom_ElementarySurface::XGeom_ElementarySurface(Handle(Geom_ElementarySurface) pos) {
		NativeHandle() = pos;
		SetGeometryHandle(NativeHandle());
	};

	//!
	XGeom_ElementarySurface::~XGeom_ElementarySurface() {
		NativeHandle() = NULL;
		SetGeometryHandle(NativeHandle());
	};

	void XGeom_ElementarySurface::SetElementarySurfaceHandle(Handle(Geom_ElementarySurface) handle) {
		NativeHandle() = handle;
		SetGeometryHandle(NativeHandle());
	};

	//! 
	Handle(Geom_ElementarySurface) XGeom_ElementarySurface::GetElementarySurface() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Surface) XGeom_ElementarySurface::GetSurface() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Geometry) XGeom_ElementarySurface::GetGeometry() {
		return NativeHandle();
	};

	//! Changes the main axis (ZAxis) of the elementary surface.
	//!
	//! Raised if the direction of A1 is parallel to the XAxis of the
	//! coordinate system of the surface.
	void XGeom_ElementarySurface::SetAxis(xgp_Ax1^ A1) {
		NativeHandle()->SetAxis(*A1->GetAx1());
	};


	//! Changes the location of the local coordinates system of the
	//! surface.
	void XGeom_ElementarySurface::SetLocation(xgp_Pnt^ Loc) {
		NativeHandle()->SetLocation(*Loc->GetPnt());
	};


	//! Changes the local coordinates system of the surface.
	void XGeom_ElementarySurface::SetPosition(xgp_Ax3^ A3) {
		NativeHandle()->SetPosition(*A3->GetAx3());
	};


	//! Returns the main axis of the surface (ZAxis).
	xgp_Ax1^ XGeom_ElementarySurface::Axis() {
		gp_Ax1* temp = new gp_Ax1(NativeHandle()->Axis());
		return gcnew xgp_Ax1(temp);
	};


	//! Returns the location point of the local coordinate system of the
	//! surface.
	xgp_Pnt^ XGeom_ElementarySurface::Location() {
		gp_Pnt* temp = new gp_Pnt(NativeHandle()->Location());
		return gcnew xgp_Pnt(temp);
	};

	//! Returns the local coordinates system of the surface.
	xgp_Ax3^ XGeom_ElementarySurface::Position() {
		gp_Ax3* temp = new gp_Ax3(NativeHandle()->Position());
		return gcnew xgp_Ax3(temp);
	};


	//! Reverses the U parametric direction of the surface.
	void XGeom_ElementarySurface::UReverse() {
		NativeHandle()->UReverse();
	};

	//! Return the  parameter on the  Ureversed surface for
	//! the point of parameter U on <me>.
	//!
	//! me->UReversed()->Value(me->UReversedParameter(U),V)
	//! is the same point as
	//! me->Value(U,V)
	Standard_Real XGeom_ElementarySurface::UReversedParameter(Standard_Real U) {
		return NativeHandle()->UReversedParameter(U);
	};


	//! Reverses the V parametric direction of the surface.
	void XGeom_ElementarySurface::VReverse() {
		NativeHandle()->VReverse();
	};

	//! Return the  parameter on the  Vreversed surface for
	//! the point of parameter V on <me>.
	//!
	//! me->VReversed()->Value(U,me->VReversedParameter(V))
	//! is the same point as
	//! me->Value(U,V)
	Standard_Real XGeom_ElementarySurface::VReversedParameter(Standard_Real V) {
		return NativeHandle()->VReversedParameter(V);
	};

	//! Returns GeomAbs_CN, the global continuity of any elementary surface.
	XGeomAbs_Shape XGeom_ElementarySurface::Continuity() {
		return safe_cast<XGeomAbs_Shape>(NativeHandle()->Continuity());
	};

	//! Returns True.
	Standard_Boolean XGeom_ElementarySurface::IsCNu(Standard_Integer N) {
		return NativeHandle()->IsCNu(N);
	};

	//! Returns True.
	Standard_Boolean XGeom_ElementarySurface::IsCNv(Standard_Integer N) {
		return NativeHandle()->IsCNv(N);
	};
}
