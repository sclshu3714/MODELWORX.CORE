#include <XGeom_BezierCurve.h>
namespace TKG3d {
	XGeom_BezierCurve::XGeom_BezierCurve() {
		//NativeHandle() = new Geom_BezierCurve();
	};

	//! 
	XGeom_BezierCurve::XGeom_BezierCurve(Handle(Geom_BezierCurve) pos) {
		NativeHandle() = pos;
		SetBoundedCurveHandle(NativeHandle());
	};

	//!
	XGeom_BezierCurve::~XGeom_BezierCurve() {
		NativeHandle() = NULL;
		SetBoundedCurveHandle(NativeHandle());
	};

	void XGeom_BezierCurve::SetBezierCurveHandle(Handle(Geom_BezierCurve) pos) {
		NativeHandle() = pos;
		SetBoundedCurveHandle(NativeHandle());
	};

	//!
	Handle(Geom_BezierCurve) XGeom_BezierCurve::GetBezierCurve() {
		return NativeHandle();
	};

	//!
	Handle(Geom_BoundedCurve) XGeom_BezierCurve::GetBoundedCurve() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Curve) XGeom_BezierCurve::GetCurve() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Geometry) XGeom_BezierCurve::GetGeometry() {
		return NativeHandle();
	};

	//! Creates a non rational Bezier curve with a set of poles
	//! CurvePoles.  The weights are defaulted to all being 1.
	//! Raises ConstructionError if the number of poles is greater than MaxDegree + 1
	//! or lower than 2.
	XGeom_BezierCurve::XGeom_BezierCurve(List<xgp_Pnt^>^ CurvePoles) {
		Standard_Integer i = 0;
		TColgp_Array1OfPnt TCurvePoles;
		for each (xgp_Pnt^ cPnt in CurvePoles)
			TCurvePoles.SetValue(i++, *cPnt->GetPnt());
		NativeHandle() = new Geom_BezierCurve(TCurvePoles);
		SetBoundedCurveHandle(NativeHandle());
	};

	//! Creates a rational Bezier curve with the set of poles
	//! CurvePoles and the set of weights  PoleWeights .
	//! If all the weights are identical the curve is considered
	//! as non rational. Raises ConstructionError if
	//! the number of poles is greater than  MaxDegree + 1 or lower
	//! than 2 or CurvePoles and CurveWeights have not the same length
	//! or one weight value is lower or equal to Resolution from package gp.
	XGeom_BezierCurve::XGeom_BezierCurve(List<xgp_Pnt^>^ CurvePoles, List<Standard_Real>^ PoleWeights) {
		Standard_Integer i = 0, j = 0;
		TColgp_Array1OfPnt TCurvePoles;
		TColStd_Array1OfReal TPoleWeights;
		for each (xgp_Pnt ^ cPnt in CurvePoles)
			TCurvePoles.SetValue(i++, *cPnt->GetPnt());
		for each (Standard_Real cReal in PoleWeights)
			TPoleWeights.SetValue(j++, cReal);
		NativeHandle() = new Geom_BezierCurve(TCurvePoles, TPoleWeights);
		SetBoundedCurveHandle(NativeHandle());
	};

	//! Increases the degree of a bezier curve. Degree is the new
	//! degree of <me>. Raises ConstructionError
	//! if Degree is greater than MaxDegree or lower than 2
	//! or lower than the initial degree of <me>.
	void XGeom_BezierCurve::Increase(Standard_Integer Degree) {
		NativeHandle()->Increase(Degree);
	};

	//! Inserts a pole P after the pole of range Index.
	//! If the curve <me> is rational the weight value for the new
	//! pole of range Index is 1.0.
	//! raised if Index is not in the range [1, NbPoles]
	//!
	//! raised if the resulting number of poles is greater than
	//! MaxDegree + 1.
	void XGeom_BezierCurve::InsertPoleAfter(Standard_Integer Index, xgp_Pnt^ P) {
		NativeHandle()->InsertPoleAfter(Index, *P->GetPnt());
	};


	//! Inserts a pole with its weight in the set of poles after the
	//! pole of range Index. If the curve was non rational it can
	//! become rational if all the weights are not identical.
	//! Raised if Index is not in the range [1, NbPoles]
	//!
	//! Raised if the resulting number of poles is greater than
	//! MaxDegree + 1.
	//! Raised if Weight is lower or equal to Resolution from package gp.
	void XGeom_BezierCurve::InsertPoleAfter(Standard_Integer Index, xgp_Pnt^ P, Standard_Real Weight) {
		NativeHandle()->InsertPoleAfter(Index, *P->GetPnt(), Weight);
	};

	//! Inserts a pole P before the pole of range Index.
	//! If the curve <me> is rational the weight value for the new
	//! pole of range Index is 1.0.
	//! Raised if Index is not in the range [1, NbPoles]
	//!
	//! Raised if the resulting number of poles is greater than
	//! MaxDegree + 1.
	void XGeom_BezierCurve::InsertPoleBefore(Standard_Integer Index, xgp_Pnt^ P) {
		NativeHandle()->InsertPoleBefore(Index, *P->GetPnt());
	};


	//! Inserts a pole with its weight in the set of poles after
	//! the pole of range Index. If the curve was non rational it
	//! can become rational if all the weights are not identical.
	//! Raised if Index is not in the range [1, NbPoles]
	//!
	//! Raised if the resulting number of poles is greater than
	//! MaxDegree + 1.
	//! Raised if Weight is lower or equal to Resolution from
	//! package gp.
	void XGeom_BezierCurve::InsertPoleBefore(Standard_Integer Index, xgp_Pnt^ P, Standard_Real Weight) {
		NativeHandle()->InsertPoleBefore(Index, *P->GetPnt(), Weight);
	};

	//! Removes the pole of range Index.
	//! If the curve was rational it can become non rational.
	//! Raised if Index is not in the range [1, NbPoles]
	//! Raised if Degree is lower than 2.
	void XGeom_BezierCurve::RemovePole(Standard_Integer Index) {
		NativeHandle()->RemovePole(Index);
	};


	//! Reverses the direction of parametrization of <me>
	//! Value (NewU) =  Value (1 - OldU)
	void XGeom_BezierCurve::Reverse() {
		NativeHandle()->Reverse();
	};

	//! Returns the  parameter on the  reversed  curve for
	//! the point of parameter U on <me>.
	//!
	//! returns 1-U
	Standard_Real XGeom_BezierCurve::ReversedParameter(Standard_Real U) {
		return NativeHandle()->ReversedParameter(U);
	};


	//! Segments the curve between U1 and U2 which can be out
	//! of the bounds of the curve. The curve is oriented from U1
	//! to U2.
	//! The control points are modified, the first and the last point
	//! are not the same but the parametrization range is [0, 1]
	//! else it could not be a Bezier curve.
	//! Warnings :
	//! Even if <me> is not closed it can become closed after the
	//! segmentation for example if U1 or U2 are out of the bounds
	//! of the curve <me> or if the curve makes loop.
	//! After the segmentation the length of a curve can be null.
	void XGeom_BezierCurve::Segment(Standard_Real U1, Standard_Real U2) {
		NativeHandle()->Segment(U1, U2);
	};


	//! Substitutes the pole of range index with P.
	//! If the curve <me> is rational the weight of range Index
	//! is not modified.
	//! raiseD if Index is not in the range [1, NbPoles]
	void XGeom_BezierCurve::SetPole(Standard_Integer Index, xgp_Pnt^ P) {
		NativeHandle()->SetPole(Index, *P->GetPnt());
	};


	//! Substitutes the pole and the weights of range Index.
	//! If the curve <me> is not rational it can become rational
	//! if all the weights are not identical.
	//! If the curve was rational it can become non rational if
	//! all the weights are identical.
	//! Raised if Index is not in the range [1, NbPoles]
	//! Raised if Weight <= Resolution from package gp
	void XGeom_BezierCurve::SetPole(Standard_Integer Index, xgp_Pnt^ P, Standard_Real Weight) {
		NativeHandle()->SetPole(Index, *P->GetPnt(), Weight);
	};


	//! Changes the weight of the pole of range Index.
	//! If the curve <me> is not rational it can become rational
	//! if all the weights are not identical.
	//! If the curve was rational it can become non rational if
	//! all the weights are identical.
	//! Raised if Index is not in the range [1, NbPoles]
	//! Raised if Weight <= Resolution from package gp
	void XGeom_BezierCurve::SetWeight(Standard_Integer Index, Standard_Real Weight) {
		NativeHandle()->SetWeight(Index, Weight);
	};


	//! Returns True if the distance between the first point
	//! and the last point of the curve is lower or equal to
	//! the Resolution from package gp.
	Standard_Boolean XGeom_BezierCurve::IsClosed() {
		return NativeHandle()->IsClosed();
	};

	//! Continuity of the curve, returns True.
	Standard_Boolean XGeom_BezierCurve::IsCN(Standard_Integer N) {
		return NativeHandle()->IsCN(N);
	};


	//! Returns True if the parametrization of a curve is periodic.
	//! (P(u) = P(u + T) T = constante)
	Standard_Boolean XGeom_BezierCurve::IsPeriodic() {
		return NativeHandle()->IsPeriodic();
	};


	//! Returns false if all the weights are identical. The tolerance
	//! criterion is Resolution from package gp.
	Standard_Boolean XGeom_BezierCurve::IsRational() {
		return NativeHandle()->IsRational();
	};

	//! a Bezier curve is CN
	XGeomAbs_Shape XGeom_BezierCurve::Continuity() {
		return safe_cast<XGeomAbs_Shape>(NativeHandle()->Continuity());
	};

	//! Returns the polynomial degree of the curve.
	//! it is the number of poles - 1
	//! point P and derivatives (V1, V2, V3) computation
	//! The Bezier Curve has a Polynomial representation so the
	//! parameter U can be out of the bounds of the curve.
	Standard_Integer XGeom_BezierCurve::Degree() {
		return NativeHandle()->Degree();
	};

	void XGeom_BezierCurve::D0(Standard_Real U, xgp_Pnt^ P) {
		NativeHandle()->D0(U, *P->GetPnt());
	};

	void XGeom_BezierCurve::D1(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1) {
		NativeHandle()->D1(U, *P->GetPnt(),*V1->GetVec());
	};

	void XGeom_BezierCurve::D2(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2) {
		NativeHandle()->D2(U, *P->GetPnt(), *V1->GetVec(), *V2->GetVec());
	};

	//! For this Bezier curve, computes
	//! - the point P of parameter U, or
	//! - the point P and one or more of the following values:
	//! - V1, the first derivative vector,
	//! - V2, the second derivative vector,
	//! - V3, the third derivative vector.
	//! Note: the parameter U can be outside the bounds of the curve.
	void XGeom_BezierCurve::D3(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2, xgp_Vec^ V3) {
		NativeHandle()->D3(U, *P->GetPnt(), *V1->GetVec(), *V2->GetVec(), *V3->GetVec());
	};

	//! For the point of parameter U of this Bezier curve,
	//! computes the vector corresponding to the Nth derivative.
	//! Note: the parameter U can be outside the bounds of the curve.
	//! Exceptions Standard_RangeError if N is less than 1.
	xgp_Vec^ XGeom_BezierCurve::DN(Standard_Real U, Standard_Integer N) {
		gp_Vec* temp = new gp_Vec(NativeHandle()->DN(U, N));
		return gcnew xgp_Vec(temp);
	};

	//! Returns Value (U=0.), it is the first control point of the curve.
	xgp_Pnt^ XGeom_BezierCurve::StartPoint() {
		gp_Pnt* temp = new gp_Pnt(NativeHandle()->StartPoint());
		return gcnew xgp_Pnt(temp);
	};

	//! Returns Value (U=1.), it is the last control point of the Bezier curve.
	xgp_Pnt^ XGeom_BezierCurve::EndPoint() {
		gp_Pnt* temp = new gp_Pnt(NativeHandle()->EndPoint());
		return gcnew xgp_Pnt(temp);
	};

	//! Returns the value of the first  parameter of this
	//! Bezier curve. This is 0.0, which gives the start point of this Bezier curve
	Standard_Real XGeom_BezierCurve::FirstParameter() {
		return NativeHandle()->FirstParameter();
	};

	//! Returns the value of the last parameter of this
	//! Bezier curve. This is  1.0, which gives the end point of this Bezier curve.
	Standard_Real XGeom_BezierCurve::LastParameter() {
		return NativeHandle()->LastParameter();
	};

	//! Returns the number of poles of this Bezier curve.
	Standard_Integer XGeom_BezierCurve::NbPoles() {
		return NativeHandle()->NbPoles();
	};

	//! Returns the pole of range Index.
	//! Raised if Index is not in the range [1, NbPoles]
	xgp_Pnt^ XGeom_BezierCurve::Pole(Standard_Integer Index) {
		gp_Pnt* temp = new gp_Pnt(NativeHandle()->Pole(Index));
		return gcnew xgp_Pnt(temp);
	};

	//! Returns all the poles of the curve.
	//!
	//! Raised if the length of P is not equal to the number of poles.
	void XGeom_BezierCurve::Poles(List<xgp_Pnt^>^ P) {
		Standard_Integer i = 0;
		TColgp_Array1OfPnt TP;
		for each (xgp_Pnt ^ cPnt in P)
			TP.SetValue(i++, *cPnt->GetPnt());
		NativeHandle()->Poles(TP);
	};

	//! Returns all the poles of the curve.
	List<xgp_Pnt^>^ XGeom_BezierCurve::Poles() {
		List<xgp_Pnt^>^ P = gcnew List<xgp_Pnt^>();
		TColgp_Array1OfPnt TP = NativeHandle()->Poles();
		Standard_Integer i = 0;
		for each (gp_Pnt cPnt in TP) {
			gp_Pnt* temp = new gp_Pnt(cPnt);
			xgp_Pnt^ xtemp = gcnew xgp_Pnt(temp);
			P->Add(xtemp);
		}
		return P;
	};

	//! Returns the weight of range Index.
	//! Raised if Index is not in the range [1, NbPoles]
	Standard_Real XGeom_BezierCurve::Weight(Standard_Integer Index) {
		return NativeHandle()->Weight(Index);
	};

	//! Returns all the weights of the curve.
	//!
	//! Raised if the length of W is not equal to the number of poles.
	void XGeom_BezierCurve::Weights(List<Standard_Real>^ W) {
		TColStd_Array1OfReal TW;
		Standard_Integer i = 0;
		for each (Standard_Integer cPnt in W)
			TW.SetValue(i++, cPnt);
		NativeHandle()->Weights(TW);
	};

	//! Returns all the weights of the curve.
	List<Standard_Real>^ XGeom_BezierCurve::Weights() {
		List<Standard_Real>^ P = gcnew List<Standard_Real>();
		const TColStd_Array1OfReal* TW = NativeHandle()->Weights();
		for (Standard_Integer i = 0; i < TW->Length(); i++) {
			P->Add(TW->Value(i));
		}
		return P;
	};

	//! Applies the transformation T to this Bezier curve.
	void XGeom_BezierCurve::Transform(xgp_Trsf^ T) {
		NativeHandle()->Transform(*T->GetTrsf());
	};


	//! Returns the value of the maximum polynomial degree
	//! of any Geom_BezierCurve curve. This value is 25.
	//! static 
	Standard_Integer XGeom_BezierCurve::MaxDegree() {
		return Geom_BezierCurve::MaxDegree();
	};

	//! Computes for this Bezier curve the parametric
	//! tolerance UTolerance for a given 3D tolerance Tolerance3D.
	//! If f(t) is the equation of this Bezier curve,
	//! UTolerance ensures that:
	//! |t1-t0| < UTolerance ===> |f(t1)-f(t0)| < Tolerance3D
	void XGeom_BezierCurve::Resolution(Standard_Real Tolerance3D, Standard_Real UTolerance) {
		NativeHandle()->Resolution(Tolerance3D, UTolerance);
	};

	//! Creates a new object which is a copy of this Bezier curve.
	XGeom_Geometry^ XGeom_BezierCurve::Copy() {
		return gcnew XGeom_Geometry(NativeHandle()->Copy());
	};
}
