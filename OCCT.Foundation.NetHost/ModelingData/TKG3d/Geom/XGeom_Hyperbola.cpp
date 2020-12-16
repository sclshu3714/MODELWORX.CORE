#include <XGeom_Hyperbola.h>
namespace TKG3d {
	XGeom_Hyperbola::XGeom_Hyperbola() {
		//NativeHandle() = new Geom_Hyperbola();
	};

	XGeom_Hyperbola::XGeom_Hyperbola(Handle(Geom_Hyperbola) pos) {
		NativeHandle() = pos;
		SetConicHandle(NativeHandle());
	};

	void XGeom_Hyperbola::SetHyperbolaHandle(Handle(Geom_Hyperbola) pos) {
		NativeHandle() = pos;
		SetConicHandle(NativeHandle());
	};

	Handle(Geom_Hyperbola) XGeom_Hyperbola::GetHyperbola() {
		return NativeHandle();
	};

	Handle(Geom_Conic) XGeom_Hyperbola::GetConic() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Curve) XGeom_Hyperbola::GetCurve() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Geometry) XGeom_Hyperbola::GetGeometry() {
		return NativeHandle();
	};

	//! Constructs a hyperbola by conversion of the gp_Hypr hyperbola H.
	XGeom_Hyperbola::XGeom_Hyperbola(xgp_Hypr^ H) {
		NativeHandle() = new Geom_Hyperbola(*H->GetHypr());
		SetConicHandle(NativeHandle());
	};

	//! Constructs a hyperbola defined by its major and
	//! minor radii, MajorRadius and MinorRadius, where A2 locates the
	//! hyperbola and defines its orientation in 3D space such that:
	//! - the center of the hyperbola is the origin of A2,
	//! - the "X Direction" of A2 defines the major axis
	//! of the hyperbola, i.e. the major radius
	//! MajorRadius is measured along this axis,
	//! - the "Y Direction" of A2 defines the minor axis
	//! of the hyperbola, i.e. the minor radius
	//! MinorRadius is measured along this axis,
	//! - A2 is the local coordinate system of the   hyperbola.
	//! Exceptions
	//! Standard_ConstructionError if:
	//! - MajorRadius is less than 0.0,
	//! - MinorRadius is less than 0.0.
	XGeom_Hyperbola::XGeom_Hyperbola(xgp_Ax2^ A2, Standard_Real MajorRadius, Standard_Real MinorRadius) {
		NativeHandle() = new Geom_Hyperbola(*A2->GetAx2(), MajorRadius, MinorRadius);
		SetConicHandle(NativeHandle());
	};

	//! Converts the gp_Hypr hyperbola H into this hyperbola.
	void XGeom_Hyperbola::SetHypr(xgp_Hypr^ H) {
		NativeHandle()->SetHypr(*H->GetHypr());
	};

	//! Assigns a value to the major radius of this hyperbola.
	//! Exceptions
	//! Standard_ConstructionError if:
	//! - MajorRadius is less than 0.0, or
	//! - MinorRadius is less than 0.0.Raised if MajorRadius < 0.0
	void XGeom_Hyperbola::SetMajorRadius(Standard_Real MajorRadius) {
		NativeHandle()->SetMajorRadius(MajorRadius);
	};

	//! Assigns a value to the minor radius of this hyperbola.
	//! Exceptions
	//! Standard_ConstructionError if:
	//! - MajorRadius is less than 0.0, or
	//! - MinorRadius is less than 0.0.Raised if MajorRadius < 0.0
	void XGeom_Hyperbola::SetMinorRadius(Standard_Real MinorRadius) {
		NativeHandle()->SetMinorRadius(MinorRadius);
	};


	//! returns the non transient parabola from gp with the same
	//! geometric properties as <me>.
	xgp_Hypr^ XGeom_Hyperbola::Hypr() {
		gp_Hypr* temp = new gp_Hypr(NativeHandle()->Hypr());
		return gcnew xgp_Hypr(temp);
	};

	//! Computes the parameter on the reversed hyperbola,
	//! for the point of parameter U on this hyperbola.
	//! For a hyperbola, the returned value is: -U.
	Standard_Real XGeom_Hyperbola::ReversedParameter(Standard_Real U) {
		return NativeHandle()->ReversedParameter(U);
	};

	//! Returns RealFirst from Standard.
	Standard_Real XGeom_Hyperbola::FirstParameter() {
		return NativeHandle()->FirstParameter();
	};

	//! returns RealLast from Standard.
	Standard_Real XGeom_Hyperbola::LastParameter() {
		return NativeHandle()->LastParameter();
	};

	//! Returns False.
	Standard_Boolean XGeom_Hyperbola::IsClosed() {
		return NativeHandle()->IsClosed();
	};

	//! return False for an hyperbola.
	Standard_Boolean XGeom_Hyperbola::IsPeriodic() {
		return NativeHandle()->IsPeriodic();
	};


	//! In the local coordinate system of the hyperbola the equation of
	//! the hyperbola is (X*X)/(A*A) - (Y*Y)/(B*B) = 1.0 and the
	//! equation of the first asymptote is Y = (B/A)*X.
	//! Raises ConstructionError if MajorRadius = 0.0
	xgp_Ax1^ XGeom_Hyperbola::Asymptote1() {
		gp_Ax1* temp = new gp_Ax1(NativeHandle()->Asymptote1());
		return gcnew xgp_Ax1(temp);
	};


	//! In the local coordinate system of the hyperbola the equation of
	//! the hyperbola is (X*X)/(A*A) - (Y*Y)/(B*B) = 1.0 and the
	//! equation of the first asymptote is Y = -(B/A)*X.
	//! Raises ConstructionError if MajorRadius = 0.0
	xgp_Ax1^ XGeom_Hyperbola::Asymptote2() {
		gp_Ax1* temp = new gp_Ax1(NativeHandle()->Asymptote2());
		return gcnew xgp_Ax1(temp);
	};


	//! This branch of hyperbola is on the positive side of the
	//! YAxis of <me>.
	xgp_Hypr^ XGeom_Hyperbola::ConjugateBranch1() {
		gp_Hypr* temp = new gp_Hypr(NativeHandle()->ConjugateBranch1());
		return gcnew xgp_Hypr(temp);
	};


	//! This branch of hyperbola is on the negative side of the
	//! YAxis of <me>.
	//! Note: The diagram given under the class purpose
	//! indicates where these two branches of hyperbola are
	//! positioned in relation to this branch of hyperbola.
	xgp_Hypr^ XGeom_Hyperbola::ConjugateBranch2() {
		gp_Hypr* temp = new gp_Hypr(NativeHandle()->ConjugateBranch2());
		return gcnew xgp_Hypr(temp);
	};


	//! This directrix is the line normal to the XAxis of the hyperbola
	//! in the local plane (Z = 0) at a distance d = MajorRadius / e
	//! from the center of the hyperbola, where e is the eccentricity of
	//! the hyperbola.
	//! This line is parallel to the YAxis. The intersection point between
	//! directrix1 and the XAxis is the location point of the directrix1.
	//! This point is on the positive side of the XAxis.
	xgp_Ax1^ XGeom_Hyperbola::Directrix1() {
		gp_Ax1* temp = new gp_Ax1(NativeHandle()->Directrix1());
		return gcnew xgp_Ax1(temp);
	};


	//! This line is obtained by the symmetrical transformation
	//! of "directrix1" with respect to the YAxis of the hyperbola.
	xgp_Ax1^ XGeom_Hyperbola::Directrix2() {
		gp_Ax1* temp = new gp_Ax1(NativeHandle()->Directrix2());
		return gcnew xgp_Ax1(temp);
	};


	//! Returns the excentricity of the hyperbola (e > 1).
	//! If f is the distance between the location of the hyperbola
	//! and the Focus1 then the eccentricity e = f / MajorRadius.
	//! raised if MajorRadius = 0.0
	Standard_Real XGeom_Hyperbola::Eccentricity() {
		return NativeHandle()->Eccentricity();
	};


	//! Computes the focal distance. It is the distance between the
	//! two focus of the hyperbola.
	Standard_Real XGeom_Hyperbola::Focal() {
		return NativeHandle()->Focal();
	};


	//! Returns the first focus of the hyperbola. This focus is on the
	//! positive side of the XAxis of the hyperbola.
	xgp_Pnt^ XGeom_Hyperbola::Focus1() {
		gp_Pnt* temp = new gp_Pnt(NativeHandle()->Focus1());
		return gcnew xgp_Pnt(temp);
	};


	//! Returns the second focus of the hyperbola. This focus is on the
	//! negative side of the XAxis of the hyperbola.
	xgp_Pnt^ XGeom_Hyperbola::Focus2() {
		gp_Pnt* temp = new gp_Pnt(NativeHandle()->Focus2());
		return gcnew xgp_Pnt(temp);
	};

	//! Returns the major or minor radius of this hyperbola.
	//! The major radius is also the distance between the
	//! center of the hyperbola and the apex of the main
	//! branch (located on the "X Axis" of the hyperbola).
	Standard_Real XGeom_Hyperbola::MajorRadius() {
		return NativeHandle()->MajorRadius();
	};

	//! Returns the major or minor radius of this hyperbola.
	//! The minor radius is also the distance between the
	//! center of the hyperbola and the apex of a conjugate
	//! branch (located on the "Y Axis" of the hyperbola).
	Standard_Real XGeom_Hyperbola::MinorRadius() {
		return NativeHandle()->MinorRadius();
	};

	//! Computes the "other" branch of this hyperbola. This
	//! is the symmetrical branch with respect to the center of this hyperbola.
	//! Note: The diagram given under the class purpose
	//! indicates where the "other" branch is positioned in
	//! relation to this branch of the hyperbola.
	xgp_Hypr^ XGeom_Hyperbola::OtherBranch() {
		gp_Hypr* temp = new gp_Hypr(NativeHandle()->OtherBranch());
		return gcnew xgp_Hypr(temp);
	};


	//! Returns p = (e * e - 1) * MajorRadius where e is the
	//! eccentricity of the hyperbola.
	//! raised if MajorRadius = 0.0
	Standard_Real XGeom_Hyperbola::Parameter() {
		return NativeHandle()->Parameter();
	};

	//! Returns in P the point of parameter U.
	//! P = C + MajorRadius * Cosh (U) * XDir +
	//! MinorRadius * Sinh (U) * YDir
	//! where C is the center of the hyperbola , XDir the XDirection and
	//! YDir the YDirection of the hyperbola's local coordinate system.
	void XGeom_Hyperbola::D0(Standard_Real U, xgp_Pnt^ P) {
		NativeHandle()->D0(U, *P->GetPnt());
	};


	//! Returns the point P of parameter U and the first derivative V1.
	void XGeom_Hyperbola::D1(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1) {
		NativeHandle()->D1(U, *P->GetPnt(), *V1->GetVec());
	};


	//! Returns the point P of parameter U, the first and second
	//! derivatives V1 and V2.
	void XGeom_Hyperbola::D2(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2) {
		NativeHandle()->D2(U, *P->GetPnt(), *V1->GetVec(), *V2->GetVec());
	};


	//! Returns the point P of parameter U, the first second and
	//! third derivatives V1 V2 and V3.
	void XGeom_Hyperbola::D3(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2, xgp_Vec^ V3) {
		NativeHandle()->D3(U, *P->GetPnt(), *V1->GetVec(), *V2->GetVec(), *V3->GetVec());
	};


	//! The returned vector gives the value of the derivative for the
	//! order of derivation N.
	//! Raised if N < 1.
	xgp_Vec^ XGeom_Hyperbola::DN(Standard_Real U, Standard_Integer N) {
		gp_Vec* temp = new gp_Vec(NativeHandle()->DN(U, N));
		return gcnew xgp_Vec(temp);
	};

	//! Applies the transformation T to this hyperbola.
	void XGeom_Hyperbola::Transform(xgp_Trsf^ T) {
		NativeHandle()->Transform(*T->GetTrsf());
	}

	//! Creates a new object which is a copy of this hyperbola.
	XGeom_Geometry^ XGeom_Hyperbola::Copy() {
		return gcnew XGeom_Geometry(NativeHandle()->Copy());
	};
}