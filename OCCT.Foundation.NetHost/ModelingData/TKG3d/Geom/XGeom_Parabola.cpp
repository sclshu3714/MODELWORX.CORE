#include <XGeom_Parabola.h>
namespace TKG3d {
	XGeom_Parabola::XGeom_Parabola() {
		//NativeHandle() = new Geom_Parabola();
	};

	XGeom_Parabola::XGeom_Parabola(Handle(Geom_Parabola) pos) {
		NativeHandle() = pos;
		SetConicHandle(NativeHandle());
	};


	void XGeom_Parabola::SetParabolaHandle(Handle(Geom_Parabola) pos) {
		NativeHandle() = pos;
		SetConicHandle(NativeHandle());
	};

	Handle(Geom_Parabola) XGeom_Parabola::GetParabola() {
		return NativeHandle();
	};

	Handle(Geom_Conic) XGeom_Parabola::GetConic() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Curve) XGeom_Parabola::GetCurve() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Geometry) XGeom_Parabola::GetGeometry() {
		return NativeHandle();
	};

	//! Creates a parabola from a non transient one.
	XGeom_Parabola::XGeom_Parabola(xgp_Parab^ Prb) {
		NativeHandle() = new Geom_Parabola(*Prb->GetParab());
		SetConicHandle(NativeHandle());
	};


	//! Creates a parabola with its local coordinate system "A2"
	//! and it's focal length "Focal".
	//! The XDirection of A2 defines the axis of symmetry of the
	//! parabola. The YDirection of A2 is parallel to the directrix
	//! of the parabola. The Location point of A2 is the vertex of
	//! the parabola
	//! Raised if Focal < 0.0
	XGeom_Parabola::XGeom_Parabola(xgp_Ax2^ A2, Standard_Real Focal) {
		NativeHandle() = new Geom_Parabola(*A2->GetAx2(), Focal);
		SetConicHandle(NativeHandle());
	};


	//! D is the directrix of the parabola and F the focus point.
	//! The symmetry axis (XAxis) of the parabola is normal to the
	//! directrix and pass through the focus point F, but its
	//! location point is the vertex of the parabola.
	//! The YAxis of the parabola is parallel to D and its location
	//! point is the vertex of the parabola. The normal to the plane
	//! of the parabola is the cross product between the XAxis and the
	//! YAxis.
	XGeom_Parabola::XGeom_Parabola(xgp_Ax1^ D, xgp_Pnt^ F) {
		NativeHandle() = new Geom_Parabola(*D->GetAx1(), *F->GetPnt());
		SetConicHandle(NativeHandle());
	};

	//! Assigns the value Focal to the focal distance of this parabola.
	//! Exceptions Standard_ConstructionError if Focal is negative.
	void XGeom_Parabola::SetFocal(Standard_Real Focal) {
		NativeHandle()->SetFocal(Focal);
	};

	//! Converts the gp_Parab parabola Prb into this parabola.
	void XGeom_Parabola::SetParab(xgp_Parab^ Prb) {
		NativeHandle()->SetParab(*Prb->GetParab());
	};


	//! Returns the non transient parabola from gp with the same
	//! geometric properties as <me>.
	xgp_Parab^ XGeom_Parabola::Parab() {
		gp_Parab* temp = new gp_Parab(NativeHandle()->Parab());
		return gcnew xgp_Parab(temp);
	};

	//! Computes the parameter on the reversed parabola,
	//! for the point of parameter U on this parabola.
	//! For a parabola, the returned value is: -U.
	Standard_Real XGeom_Parabola::ReversedParameter(Standard_Real U) {
		return NativeHandle()->ReversedParameter(U);
	};

	//! Returns the value of the first or last parameter of this
	//! parabola. This is, respectively:
	//! - Standard_Real::RealFirst(), or
	//! - Standard_Real::RealLast().
	Standard_Real XGeom_Parabola::FirstParameter() {
		return NativeHandle()->FirstParameter();
	};

	//! Returns the value of the first or last parameter of this
	//! parabola. This is, respectively:
	//! - Standard_Real::RealFirst(), or
	//! - Standard_Real::RealLast().
	Standard_Real XGeom_Parabola::LastParameter() {
		return NativeHandle()->LastParameter();
	};

	//! Returns False
	Standard_Boolean XGeom_Parabola::IsClosed() {
		return NativeHandle()->IsClosed();
	};

	//! Returns False
	Standard_Boolean XGeom_Parabola::IsPeriodic() {
		return NativeHandle()->IsPeriodic();
	};

	//! Computes the directrix of this parabola.
	//! This is a line normal to the axis of symmetry, in the
	//! plane of this parabola, located on the negative side
	//! of its axis of symmetry, at a distance from the apex
	//! equal to the focal length.
	//! The directrix is returned as an axis (gp_Ax1 object),
	//! where the origin is located on the "X Axis" of this parabola.
	xgp_Ax1^ XGeom_Parabola::Directrix() {
		gp_Ax1* temp = new gp_Ax1(NativeHandle()->Directrix());
		return gcnew xgp_Ax1(temp);
	};

	//! Returns 1. (which is the eccentricity of any parabola).
	Standard_Real XGeom_Parabola::Eccentricity() {
		return NativeHandle()->Eccentricity();
	};

	//! Computes the focus of this parabola. The focus is on the
	//! positive side of the "X Axis" of the local coordinate
	//! system of the parabola.
	xgp_Pnt^ XGeom_Parabola::Focus() {
		gp_Pnt* temp = new gp_Pnt(NativeHandle()->Focus());
		return gcnew xgp_Pnt(temp);
	};

	//! Computes the focal distance of this parabola
	//! The focal distance is the distance between the apex
	//! and the focus of the parabola.
	Standard_Real XGeom_Parabola::Focal() {
		return NativeHandle()->Focal();
	};

	//! Computes the parameter of this parabola which is the
	//! distance between its focus and its directrix. This
	//! distance is twice the focal length.
	//! If P is the parameter of the parabola, the equation of
	//! the parabola in its local coordinate system is: Y**2 = 2.*P*X.
	Standard_Real XGeom_Parabola::Parameter() {
		return NativeHandle()->Parameter();
	};

	//! Returns in P the point of parameter U.
	//! If U = 0 the returned point is the origin of the XAxis and
	//! the YAxis of the parabola and it is the vertex of the parabola.
	//! P = S + F * (U * U * XDir +  * U * YDir)
	//! where S is the vertex of the parabola, XDir the XDirection and
	//! YDir the YDirection of the parabola's local coordinate system.
	void XGeom_Parabola::D0(Standard_Real U, xgp_Pnt^ P) {
		NativeHandle()->D0(U, *P->GetPnt());
	};


	//! Returns the point P of parameter U and the first derivative V1.
	void XGeom_Parabola::D1(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1) {
		NativeHandle()->D1(U, *P->GetPnt(), *V1->GetVec());
	};


	//! Returns the point P of parameter U, the first and second
	//! derivatives V1 and V2.
	void XGeom_Parabola::D2(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2) {
		NativeHandle()->D2(U, *P->GetPnt(), *V1->GetVec(), *V2->GetVec());
	};


	//! Returns the point P of parameter U, the first second and third
	//! derivatives V1 V2 and V3.
	void XGeom_Parabola::D3(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2, xgp_Vec^ V3) {
		NativeHandle()->D3(U, *P->GetPnt(), *V1->GetVec(), *V2->GetVec(), *V3->GetVec());
	};

	//! For the point of parameter U of this parabola,
	//! computes the vector corresponding to the Nth derivative.
	//! Exceptions Standard_RangeError if N is less than 1.
	xgp_Vec^ XGeom_Parabola::DN(Standard_Real U, Standard_Integer N) {
		gp_Vec* temp = new gp_Vec(NativeHandle()->DN(U, N));
		return gcnew xgp_Vec(temp);
	};

	//! Applies the transformation T to this parabola.
	void XGeom_Parabola::Transform(xgp_Trsf^ T) {
		NativeHandle()->Transform(*T->GetTrsf());
	};

	//! Returns the  parameter on the  transformed  curve for
	//! the transform of the point of parameter U on <me>.
	//!
	//! me->Transformed(T)->Value(me->TransformedParameter(U,T))
	//!
	//! is the same point as
	//!
	//! me->Value(U).Transformed(T)
	//!
	//! This methods returns <U> * T.ScaleFactor()
	Standard_Real XGeom_Parabola::TransformedParameter(Standard_Real U, xgp_Trsf^ T) {
		return NativeHandle()->TransformedParameter(U, *T->GetTrsf());
	};

	//! Returns a  coefficient to compute the parameter on
	//! the transformed  curve  for  the transform  of the
	//! point on <me>.
	//!
	//! Transformed(T)->Value(U * ParametricTransformation(T))
	//!
	//! is the same point as
	//!
	//! Value(U).Transformed(T)
	//!
	//! This methods returns T.ScaleFactor()
	Standard_Real XGeom_Parabola::ParametricTransformation(xgp_Trsf^ T) {
		return NativeHandle()->ParametricTransformation(*T->GetTrsf());
	};

	//! Creates a new object which is a copy of this parabola.
	XGeom_Geometry^ XGeom_Parabola::Copy() {
		return gcnew XGeom_Geometry(NativeHandle()->Copy());
	};
}
