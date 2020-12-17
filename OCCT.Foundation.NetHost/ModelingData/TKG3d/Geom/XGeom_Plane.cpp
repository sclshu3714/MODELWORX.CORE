#include <XGeom_Plane.h>
namespace TKG3d {
	//!
	XGeom_Plane::XGeom_Plane(void) {
		/*NativeHandle() = new Geom_Plane();
		SetSurfaceHandle(NativeHandle());*/
	};

	//! 
	XGeom_Plane::XGeom_Plane(Handle(Geom_Plane) pos) {
		NativeHandle() = pos;
		SetElementarySurfaceHandle(NativeHandle());
	};

	//!
	XGeom_Plane::~XGeom_Plane() {
		NativeHandle() = NULL;
		SetElementarySurfaceHandle(NativeHandle());
	};

	void XGeom_Plane::SetPlaneHandle(Handle(Geom_Plane) handle) {
		NativeHandle() = handle;
		SetElementarySurfaceHandle(NativeHandle());
	};

	//! 
	Handle(Geom_Plane) XGeom_Plane::GetPlane() {
		return NativeHandle();
	};

	//! 
	Handle(Geom_ElementarySurface) XGeom_Plane::GetElementarySurface() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Surface) XGeom_Plane::GetSurface() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Geometry) XGeom_Plane::GetGeometry() {
		return NativeHandle();
	};

	//! Creates a plane located in 3D space with an axis placement
	//! three axis.  The "ZDirection" of "A3" is the direction normal
	//! to the plane.  The "Location" point of "A3" is the origin of
	//! the plane. The "XDirection" and "YDirection" of "A3" define
	//! the directions of the U isoparametric and V isoparametric
	//! curves.
	XGeom_Plane::XGeom_Plane(xgp_Ax3^ A3) {
		NativeHandle() = new Geom_Plane(*A3->GetAx3());
		SetElementarySurfaceHandle(NativeHandle());
	};


	//! Creates a plane from a non transient plane from package gp.
	XGeom_Plane::XGeom_Plane(xgp_Pln^ Pl) {
		NativeHandle() = new Geom_Plane(*Pl->GetPln());
		SetElementarySurfaceHandle(NativeHandle());
	};


	//! P is the "Location" point or origin of the plane.
	//! V is the direction normal to the plane.
	XGeom_Plane::XGeom_Plane(xgp_Pnt^ P, xgp_Dir^ V) {
		NativeHandle() = new Geom_Plane(*P->GetPnt(), *V->GetDir());
		SetElementarySurfaceHandle(NativeHandle());
	};


	//! Creates a plane from its cartesian equation :
	//! Ax + By + Cz + D = 0.0
	//!
	//! Raised if Sqrt (A*A + B*B + C*C) <= Resolution from gp
	XGeom_Plane::XGeom_Plane(Standard_Real A, Standard_Real B, Standard_Real C, Standard_Real D) {
		NativeHandle() = new Geom_Plane(A, B, C, D);
		SetElementarySurfaceHandle(NativeHandle());
	};


	//! Set <me> so that <me> has the same geometric properties as Pl.
	void XGeom_Plane::SetPln(xgp_Pln^ Pl) {
		NativeHandle()->SetPln(*Pl->GetPln());
	};

	//! Converts this plane into a gp_Pln plane.
	xgp_Pln^ XGeom_Plane::Pln() {
		gp_Pln* temp = new gp_Pln(NativeHandle()->Pln());
		return gcnew xgp_Pln(temp);
	};


	//! Changes the orientation of this plane in the u (or v)
	//! parametric direction. The bounds of the plane are not
	//! changed but the given parametric direction is
	//! reversed. Hence the orientation of the surface is reversed.
	void XGeom_Plane::UReverse() {
		NativeHandle()->UReverse();
	};

	//! Computes the u  parameter on the modified
	//! plane, produced when reversing the u
	//! parametric of this plane, for any point of u parameter U  on this plane.
	//! In the case of a plane, these methods return - -U.
	Standard_Real XGeom_Plane::UReversedParameter(Standard_Real U) {
		return NativeHandle()->UReversedParameter(U);
	};


	//! Changes the orientation of this plane in the u (or v)
	//! parametric direction. The bounds of the plane are not
	//! changed but the given parametric direction is
	//! reversed. Hence the orientation of the surface is reversed.
	void XGeom_Plane::VReverse() {
		NativeHandle()->VReverse();
	};

	//! Computes the v parameter on the modified
	//! plane, produced when reversing the  v
	//! parametric of this plane, for any point of v parameter V on this plane.
	//! In the case of a plane, these methods return -V.
	Standard_Real XGeom_Plane::VReversedParameter(Standard_Real V) {
		return NativeHandle()->VReversedParameter(V);
	};

	//! Computes the  parameters on the  transformed  surface for
	//! the transform of the point of parameters U,V on <me>.
	//! me->Transformed(T)->Value(U',V')
	//! is the same point as
	//! me->Value(U,V).Transformed(T)
	//! Where U',V' are the new values of U,V after calling
	//! me->TranformParameters(U,V,T)
	//! This methods multiplies U and V by T.ScaleFactor()
	void XGeom_Plane::TransformParameters(Standard_Real% U, Standard_Real% V, xgp_Trsf^ T) {
		Standard_Real XU(U); Standard_Real  XV(V);
		NativeHandle()->TransformParameters(XU, XV, *T->GetTrsf());
		U = XU; V = XV;
	};

	//! Returns a 2d transformation  used to find the  new
	//! parameters of a point on the transformed surface.
	//! me->Transformed(T)->Value(U',V')
	//! is the same point as
	//! me->Value(U,V).Transformed(T)
	//! Where U',V' are  obtained by transforming U,V with
	//! th 2d transformation returned by
	//! me->ParametricTransformation(T)
	//! This  methods  returns  a scale  centered  on  the
	//! origin with T.ScaleFactor
	xgp_GTrsf2d^ XGeom_Plane::ParametricTransformation(xgp_Trsf^ T) {
		gp_GTrsf2d* temp = new gp_GTrsf2d(NativeHandle()->ParametricTransformation(*T->GetTrsf()));
		return gcnew xgp_GTrsf2d(temp);
	};

	//! Returns the parametric bounds U1, U2, V1 and V2 of this plane.
	//! Because a plane is an infinite surface, the following is always true:
	//! - U1 = V1 =   Standard_Real::RealFirst()
	//! - U2 = V2 =   Standard_Real::RealLast().
	void XGeom_Plane::Bounds(Standard_Real% U1, Standard_Real% U2, Standard_Real% V1, Standard_Real% V2) {
		Standard_Real XU1 = Standard_Real(U1); Standard_Real XU2 = Standard_Real(U2); Standard_Real XV1 = Standard_Real(V1); Standard_Real XV2 = Standard_Real(V2);
		NativeHandle()->Bounds(XU1, XU2, XV1, XV2);
		U1 = XU1; U2 = XU2; V1 = XV1; V2 = XV2;
	};


	//! Computes the normalized coefficients of the plane's
	//! cartesian equation : Ax + By + Cz + D = 0.0
	void XGeom_Plane::Coefficients(Standard_Real% A, Standard_Real% B, Standard_Real% C, Standard_Real% D) {
		Standard_Real XA(A); Standard_Real XB(B); Standard_Real XC(C); Standard_Real XD(D);
		NativeHandle()->Coefficients(XA, XB, XC, XD);
		A = XA; B = XB; C = XC; D = XD;
	};

	//! return False
	Standard_Boolean XGeom_Plane::IsUClosed() {
		return NativeHandle()->IsUClosed();
	};

	//! return False
	Standard_Boolean XGeom_Plane::IsVClosed() {
		return NativeHandle()->IsVClosed();
	};

	//! return False.
	Standard_Boolean XGeom_Plane::IsUPeriodic() {
		return NativeHandle()->IsUPeriodic();
	};

	//! return False.
	Standard_Boolean XGeom_Plane::IsVPeriodic() {
		return NativeHandle()->IsVPeriodic();
	};


	//! Computes the U isoparametric curve.
	//! This is a Line parallel to the YAxis of the plane.
	XGeom_Curve^ XGeom_Plane::UIso(Standard_Real U) {
		return gcnew XGeom_Curve(NativeHandle()->UIso(U));
	};


	//! Computes the V isoparametric curve.
	//! This is a Line parallel to the XAxis of the plane.
	XGeom_Curve^ XGeom_Plane::VIso(Standard_Real V) {
		return gcnew XGeom_Curve(NativeHandle()->VIso(V));
	};


	//! Computes the point P (U, V) on <me>.
	//! P = O + U * XDir + V * YDir.
	//! where O is the "Location" point of the plane, XDir the
	//! "XDirection" and YDir the "YDirection" of the plane's local
	//! coordinate system.
	void XGeom_Plane::D0(Standard_Real U, Standard_Real V, xgp_Pnt^ P) {
		NativeHandle()->D0(U, V, *P->GetPnt());
	};


	//! Computes the current point and the first derivatives in the
	//! directions U and V.
	void XGeom_Plane::D1(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V) {
		NativeHandle()->D1(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec());
	};


	//! Computes the current point, the first and the second
	//! derivatives in the directions U and V.
	void XGeom_Plane::D2(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV) {
		NativeHandle()->D2(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec(), *D2U->GetVec(), *D2V->GetVec(), *D2UV->GetVec());
	};


	//! Computes the current point, the first,the second and the
	//! third derivatives in the directions U and V.
	void XGeom_Plane::D3(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV, xgp_Vec^ D3U, xgp_Vec^ D3V, xgp_Vec^ D3UUV, xgp_Vec^ D3UVV) {
		NativeHandle()->D3(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec(), *D2U->GetVec(), *D2V->GetVec(), *D2UV->GetVec(), *D3U->GetVec(), *D3V->GetVec(), *D3UUV->GetVec(), *D3UVV->GetVec());
	};


	//! Computes the derivative of order Nu in the direction u
	//! and Nv in the direction v.
	//! Raised if Nu + Nv < 1 or Nu < 0 or Nv < 0.
	xgp_Vec^ XGeom_Plane::DN(Standard_Real U, Standard_Real V, Standard_Integer Nu, Standard_Integer Nv) {
		gp_Vec* temp = new gp_Vec(NativeHandle()->DN(U, V, Nu, Nv));
		return gcnew xgp_Vec(temp);
	};

	//! Applies the transformation T to this plane.
	void XGeom_Plane::Transform(xgp_Trsf^ T) {
		NativeHandle()->Transform(*T->GetTrsf());
	};

	//! Creates a new object which is a copy of this plane.
	XGeom_Geometry^ XGeom_Plane::Copy() {
		return gcnew XGeom_Geometry(NativeHandle()->Copy());
	};
}
