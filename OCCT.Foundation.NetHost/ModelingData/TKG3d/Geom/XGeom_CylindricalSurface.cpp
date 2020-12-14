#include <XGeom_CylindricalSurface.h>
namespace TKG3d {

	/// <summary>
	/// 
	/// </summary>
	/// <param name=""></param>
	XGeom_CylindricalSurface::XGeom_CylindricalSurface(void) {
		//NativeHandle() = new Geom_CylindricalSurface();
	};

	/// <summary>
	/// 
	/// </summary>
	/// <param name="pos"></param>
	XGeom_CylindricalSurface::XGeom_CylindricalSurface(Handle(Geom_CylindricalSurface) pos) {
		NativeHandle() = pos;
		SetElementarySurfaceHandle(NativeHandle());
	};

	//!
	XGeom_CylindricalSurface::~XGeom_CylindricalSurface() {
		NativeHandle() = NULL;
		SetElementarySurfaceHandle(NativeHandle());
	};

	/// <summary>
	/// 
	/// </summary>
	/// <param name="handle"></param>
	void XGeom_CylindricalSurface::SetCylindricalSurfaceHandle(Handle(Geom_CylindricalSurface) handle) {
		NativeHandle() = handle;
		SetElementarySurfaceHandle(NativeHandle());
	};

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	Handle(Geom_CylindricalSurface) XGeom_CylindricalSurface::GetCylindricalSurface() {
		return NativeHandle();
	};

	//! 
	Handle(Geom_ElementarySurface) XGeom_CylindricalSurface::GetElementarySurface() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Surface) XGeom_CylindricalSurface::GetSurface() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Geometry) XGeom_CylindricalSurface::GetGeometry() {
		return NativeHandle();
	};

	//! A3 defines the local coordinate system of the cylindrical surface.
	//! The "ZDirection" of A3 defines the direction of the surface's
	//! axis of symmetry.
	//! At the creation the parametrization of the surface is defined
	//! such that the normal Vector (N = D1U ^ D1V) is oriented towards
	//! the "outside region" of the surface.
	//! Warnings :
	//! It is not forbidden to create a cylindrical surface with
	//! Radius = 0.0
	//! Raised if Radius < 0.0
	XGeom_CylindricalSurface::XGeom_CylindricalSurface(xgp_Ax3^ A3, Standard_Real Radius) {
		NativeHandle() = new Geom_CylindricalSurface(*A3->GetAx3(), Radius);
		SetElementarySurfaceHandle(NativeHandle());
	};


	//! Creates a CylindricalSurface from a non transient Cylinder
	//! from package gp.
	XGeom_CylindricalSurface::XGeom_CylindricalSurface(xgp_Cylinder^ C) {
		NativeHandle() = new Geom_CylindricalSurface(*C->GetCylinder());
		SetElementarySurfaceHandle(NativeHandle());
	};


	//! Set <me> so that <me> has the same geometric properties as C.
	void XGeom_CylindricalSurface::SetCylinder(xgp_Cylinder^ C) {
		NativeHandle()->SetCylinder(*C->GetCylinder());
	};

	//! Changes the radius of the cylinder.
	//! Raised if R < 0.0
	void XGeom_CylindricalSurface::SetRadius(Standard_Real R) {
		NativeHandle()->SetRadius(R);
	};


	//! returns a non transient cylinder with the same geometric
	//! properties as <me>.
	xgp_Cylinder^ XGeom_CylindricalSurface::Cylinder() {
		gp_Cylinder* temp = new gp_Cylinder(NativeHandle()->Cylinder());
		return gcnew xgp_Cylinder(temp);
	};

	//! Return the  parameter on the  Ureversed surface for
	//! the point of parameter U on <me>.
	//! Return 2.PI - U.
	Standard_Real XGeom_CylindricalSurface::UReversedParameter(Standard_Real U) {
		return NativeHandle()->UReversedParameter(U);
	};

	//! Return the  parameter on the  Vreversed surface for
	//! the point of parameter V on <me>.
	//! Return -V
	Standard_Real XGeom_CylindricalSurface::VReversedParameter(Standard_Real V) {
		return NativeHandle()->VReversedParameter(V);
	};

	//! Computes the  parameters on the  transformed  surface for
	//! the transform of the point of parameters U,V on <me>.
	//! me->Transformed(T)->Value(U',V')
	//! is the same point as
	//! me->Value(U,V).Transformed(T)
	//! Where U',V' are the new values of U,V after calling
	//! me->TranformParameters(U,V,T)
	//! This methods multiplies V by T.ScaleFactor()
	void XGeom_CylindricalSurface::TransformParameters(Standard_Real U, Standard_Real V, xgp_Trsf^ T) {
		NativeHandle()->TransformParameters(U, V, *T->GetTrsf());
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
	//! U axis with T.ScaleFactor
	xgp_GTrsf2d^ XGeom_CylindricalSurface::ParametricTransformation(xgp_Trsf^ T) {
		gp_GTrsf2d* temp = new gp_GTrsf2d(NativeHandle()->ParametricTransformation(*T->GetTrsf()));
		return gcnew xgp_GTrsf2d(temp);
	};


	//! The CylindricalSurface is infinite in the V direction so
	//! V1 = Realfirst, V2 = RealLast from package Standard.
	//! U1 = 0 and U2 = 2*PI.
	void XGeom_CylindricalSurface::Bounds(Standard_Real U1, Standard_Real U2, Standard_Real V1, Standard_Real V2) {
		return NativeHandle()->Bounds(U1, U2, V1, V2);
	};


	//! Returns the coefficients of the implicit equation of the quadric
	//! in the absolute cartesian coordinate system :
	//! These coefficients are normalized.
	//! A1.X**2 + A2.Y**2 + A3.Z**2 + 2.(B1.X.Y + B2.X.Z + B3.Y.Z) +
	//! 2.(C1.X + C2.Y + C3.Z) + D = 0.0
	void XGeom_CylindricalSurface::Coefficients(Standard_Real A1, Standard_Real A2, Standard_Real A3, Standard_Real B1, Standard_Real B2, Standard_Real B3, Standard_Real C1, Standard_Real C2, Standard_Real C3, Standard_Real D) {
		NativeHandle()->Coefficients(A1, A2, A3, B1, B2, B3, C1, C2, C3, D);
	};

	//! Returns the radius of this cylinder.
	Standard_Real XGeom_CylindricalSurface::Radius() {
		return NativeHandle()->Radius();
	};

	//! Returns True.
	Standard_Boolean XGeom_CylindricalSurface::IsUClosed() {
		return NativeHandle()->IsUClosed();
	};

	//! Returns False.
	Standard_Boolean XGeom_CylindricalSurface::IsVClosed() {
		return NativeHandle()->IsVClosed();
	};

	//! Returns True.
	Standard_Boolean XGeom_CylindricalSurface::IsUPeriodic() {
		return NativeHandle()->IsUPeriodic();
	};

	//! Returns False.
	Standard_Boolean XGeom_CylindricalSurface::IsVPeriodic() {
		return NativeHandle()->IsVPeriodic();
	};


	//! The UIso curve is a Line. The location point of this line is
	//! on the placement plane (XAxis, YAxis) of the surface.
	//! This line is parallel to the axis of symmetry of the surface.
	XGeom_Curve^ XGeom_CylindricalSurface::UIso(Standard_Real U) {
		return gcnew XGeom_Curve(NativeHandle()->UIso(U));
	};


	//! The VIso curve is a circle. The start point of this circle
	//! (U = 0) is defined with the "XAxis" of the surface.
	//! The center of the circle is on the symmetry axis.
	XGeom_Curve^ XGeom_CylindricalSurface::VIso(Standard_Real V) {
		return gcnew XGeom_Curve(NativeHandle()->VIso(V));
	};


	//! Computes the  point P (U, V) on the surface.
	//! P (U, V) = Loc + Radius * (cos (U) * XDir + sin (U) * YDir) +
	//! V * ZDir
	//! where Loc is the origin of the placement plane (XAxis, YAxis)
	//! XDir is the direction of the XAxis and YDir the direction of
	//! the YAxis.
	void XGeom_CylindricalSurface::D0(Standard_Real U, Standard_Real V, xgp_Pnt^ P) {
		NativeHandle()->D0(U, V, *P->GetPnt());
	};


	//! Computes the current point and the first derivatives in the
	//! directions U and V.
	void XGeom_CylindricalSurface::D1(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V) {
		NativeHandle()->D1(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec());
	};


	//! Computes the current point, the first and the second derivatives
	//! in the directions U and V.
	void XGeom_CylindricalSurface::D2(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV) {
		NativeHandle()->D2(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec(), *D2U->GetVec(), *D2V->GetVec(), *D2UV->GetVec());
	};


	//! Computes the current point, the first, the second and the
	//! third   derivatives in the directions U and V.
	void XGeom_CylindricalSurface::D3(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV, xgp_Vec^ D3U, xgp_Vec^ D3V, xgp_Vec^ D3UUV, xgp_Vec^ D3UVV) {
		NativeHandle()->D3(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec(), *D2U->GetVec(), *D2V->GetVec(), *D2UV->GetVec(), *D3U->GetVec(), *D3V->GetVec(), *D3UUV->GetVec(), *D3UVV->GetVec());
	};


	//! Computes the derivative of order Nu in the direction u and Nv
	//! in the direction v.
	//! Raised if Nu + Nv < 1 or Nu < 0 or Nv < 0.
	xgp_Vec^ XGeom_CylindricalSurface::DN(Standard_Real U, Standard_Real V, Standard_Integer Nu, Standard_Integer Nv) {
		gp_Vec* temp = new gp_Vec(NativeHandle()->DN(U, V, Nu, Nv));
		return gcnew xgp_Vec(temp);
	};

	//! Applies the transformation T to this cylinder.
	void XGeom_CylindricalSurface::Transform(xgp_Trsf^ T) {
		NativeHandle()->Transform(*T->GetTrsf());
	};

	//! Creates a new object which is a copy of this cylinder.
	XGeom_Geometry^ XGeom_CylindricalSurface::Copy() {
		return gcnew XGeom_Geometry(NativeHandle()->Copy());
	};
}
