#include "XGeom_Transformation.h"
namespace TKG3d {
	//! Creates an identity transformation.
	XGeom_Transformation::XGeom_Transformation() {
		NativeHandle() = new Geom_Transformation();
	};

	//! Creates a transient copy of T.
	XGeom_Transformation::XGeom_Transformation(xgp_Trsf^ T) {
		NativeHandle() = new Geom_Transformation(*T->GetTrsf());
	};

	XGeom_Transformation::XGeom_Transformation(Handle(Geom_Transformation) pos) {
		NativeHandle() = pos;
	};

	void XGeom_Transformation::SetTransformationHandle(Handle(Geom_Transformation) pos) {
		NativeHandle() = pos;
	};

	Handle(Geom_Transformation) XGeom_Transformation::GetTransformation() {
		return NativeHandle();
	};

	//! Makes the transformation into a symmetrical transformation
	//! with respect to a point P.
	//! P is the center of the symmetry.
	void XGeom_Transformation::SetMirror(xgp_Pnt^ thePnt) {
		NativeHandle()->SetMirror(*thePnt->GetPnt());
	};// { gpTrsf.SetMirror(thePnt); }

	//! Makes the transformation into a symmetrical transformation
	//! with respect to an axis A1.
	//! A1 is the center of the axial symmetry.
	void XGeom_Transformation::SetMirror(xgp_Ax1^ theA1) {
		NativeHandle()->SetMirror(*theA1->GetAx1());
	};// { gpTrsf.SetMirror(theA1); }

	//! Makes the transformation into a symmetrical transformation
	//! with respect to a plane.  The plane of the symmetry is
	//! defined with the axis placement A2. It is the plane
	//! (Location, XDirection, YDirection).
	void XGeom_Transformation::SetMirror(xgp_Ax2^ theA2) {
		NativeHandle()->SetMirror(*theA2->GetAx2());
	};// { gpTrsf.SetMirror(theA2); }

	//! Makes the transformation into a rotation.
	//! A1 is the axis rotation and Ang is the angular value
	//! of the rotation in radians.
	void XGeom_Transformation::SetRotation(xgp_Ax1^ theA1, Standard_Real theAng) {
		NativeHandle()->SetRotation(*theA1->GetAx1(), theAng);
	};// { gpTrsf.SetRotation(theA1, theAng); }

	//! Makes the transformation into a scale. P is the center of
	//! the scale and S is the scaling value.
	void XGeom_Transformation::SetScale(xgp_Pnt^ thePnt, Standard_Real theScale) {
		NativeHandle()->SetScale(*thePnt->GetPnt(), theScale);
	};// { gpTrsf.SetScale(thePnt, theScale); }

	//! Makes a transformation allowing passage from the coordinate
	//! system "FromSystem1" to the coordinate system "ToSystem2".
	//! Example :
	//! In a C++ implementation :
	//! Real x1, y1, z1;  // are the coordinates of a point in the
	//! // local system FromSystem1
	//! Real x2, y2, z2;  // are the coordinates of a point in the
	//! // local system ToSystem2
	//! gp_Pnt P1 (x1, y1, z1)
	//! Geom_Transformation T;
	//! T.SetTransformation (FromSystem1, ToSystem2);
	//! gp_Pnt P2 = P1.Transformed (T);
	//! P2.Coord (x2, y2, z2);
	void XGeom_Transformation::SetTransformation(xgp_Ax3^ theFromSystem1, xgp_Ax3^ theToSystem2) {
		NativeHandle()->SetTransformation(*theFromSystem1->GetAx3(), *theToSystem2->GetAx3());
	};// { gpTrsf.SetTransformation(theFromSystem1, theToSystem2); }

	//! Makes the transformation allowing passage from the basic
	//! coordinate system
	//! {P(0.,0.,0.), VX (1.,0.,0.), VY (0.,1.,0.), VZ (0., 0. ,1.) }
	//! to the local coordinate system defined with the Ax2 ToSystem.
	//! Same utilisation as the previous method. FromSystem1 is
	//! defaulted to the absolute coordinate system.
	void XGeom_Transformation::SetTransformation(xgp_Ax3^ theToSystem) {
		NativeHandle()->SetTransformation(*theToSystem->GetAx3());
	};// { gpTrsf.SetTransformation(theToSystem); }

	//! Makes the transformation into a translation.
	//! V is the vector of the translation.
	void XGeom_Transformation::SetTranslation(xgp_Vec^ theVec) {
		NativeHandle()->SetTranslation(*theVec->GetVec());
	};// { gpTrsf.SetTranslation(theVec); }

	//! Makes the transformation into a translation from the point
	//! P1 to the point P2.
	void XGeom_Transformation::SetTranslation(xgp_Pnt^ P1, xgp_Pnt^ P2) {
		NativeHandle()->SetTranslation(*P1->GetPnt(), *P2->GetPnt());
	};// { gpTrsf.SetTranslation(P1, P2); }

	//! Converts the gp_Trsf transformation T into this transformation.
	void XGeom_Transformation::SetTrsf(xgp_Trsf^ theTrsf) {
		NativeHandle()->SetTrsf(*theTrsf->GetTrsf());
	};// { gpTrsf = theTrsf; }

	//! Checks whether this transformation is an indirect
	//! transformation: returns true if the determinant of the
	//! matrix of the vectorial part of the transformation is less than 0.
	Standard_Boolean XGeom_Transformation::IsNegative() {
		return NativeHandle()->IsNegative();
	};// { return gpTrsf.IsNegative(); }

	//! Returns the nature of this transformation as a value
	//! of the gp_TrsfForm enumeration.
	xgp_TrsfForm XGeom_Transformation::Form() {
		return safe_cast<xgp_TrsfForm>(NativeHandle()->Form());
	};// { return gpTrsf.Form(); }

	//! Returns the scale value of the transformation.
	Standard_Real XGeom_Transformation::ScaleFactor() {
		return NativeHandle()->ScaleFactor();
	};// { return gpTrsf.ScaleFactor(); }

	//! Returns a non transient copy of <me>.
	xgp_Trsf^ XGeom_Transformation::Trsf() {
		gp_Trsf* temp = new gp_Trsf(NativeHandle()->Trsf());
		return gcnew xgp_Trsf(temp);
	};// { return gpTrsf; }

	//! Returns the coefficients of the global matrix of transformation.
	//! It is a 3 rows X 4 columns matrix.
	//!
	//! Raised if  Row < 1 or Row > 3  or  Col < 1 or Col > 4
	Standard_Real XGeom_Transformation::Value(Standard_Integer theRow, Standard_Integer theCol) {
		return NativeHandle()->Value(theRow, theCol);
	};// { return gpTrsf.Value(theRow, theCol); }

	//! Raised if the the transformation is singular. This means that
	//! the ScaleFactor is lower or equal to Resolution from
	//! package gp.
	void XGeom_Transformation::Invert() {
		NativeHandle()->Invert();
	};// { gpTrsf.Invert(); }

	//! Raised if the the transformation is singular. This means that
	//! the ScaleFactor is lower or equal to Resolution from
	//! package gp.
	XGeom_Transformation^ XGeom_Transformation::Inverted() {
		return gcnew XGeom_Transformation(NativeHandle()->Inverted());
	};

	//! Computes the transformation composed with Other and <me>.
	//! <me> * Other.
	//! Returns a new transformation
	XGeom_Transformation^ XGeom_Transformation::Multiplied(XGeom_Transformation^ Other) {
		return gcnew XGeom_Transformation(NativeHandle()->Multiplied(Other->GetTransformation()));
	};

	//! Computes the transformation composed with Other and <me> .
	//! <me> = <me> * Other.
	void XGeom_Transformation::Multiply(XGeom_Transformation^ theOther) {
		NativeHandle()->Multiply(theOther->GetTransformation());
	};// { gpTrsf.Multiply(theOther->Trsf()); }

	//! Computes the following composition of transformations
	//! if N > 0  <me> * <me> * .......* <me>.
	//! if N = 0  Identity
	//! if N < 0  <me>.Invert() * .........* <me>.Invert()
	//!
	//! Raised if N < 0 and if the transformation is not inversible
	void XGeom_Transformation::Power(Standard_Integer N) {
		NativeHandle()->Power(N);
	};// { gpTrsf.Power(N); }

	//! Raised if N < 0 and if the transformation is not inversible
	XGeom_Transformation^ XGeom_Transformation::Powered(Standard_Integer N) {
		return gcnew XGeom_Transformation(NativeHandle()->Powered(N));
	};

	//! Computes the matrix of the transformation composed with
	//! <me> and Other.     <me> = Other * <me>
	void XGeom_Transformation::PreMultiply(XGeom_Transformation^ Other) {
		NativeHandle()->PreMultiply(Other->GetTransformation());
	};

	//! Applies the transformation <me> to the triplet {X, Y, Z}.
	void XGeom_Transformation::Transforms(Standard_Real theX, Standard_Real theY, Standard_Real theZ) {
		NativeHandle()->Transforms(theX, theY, theZ);
	};// { gpTrsf.Transforms(theX, theY, theZ); }

	//! Creates a new object which is a copy of this transformation.
	XGeom_Transformation^ XGeom_Transformation::Copy() {
		return gcnew XGeom_Transformation(NativeHandle()->Copy());
	};
}
