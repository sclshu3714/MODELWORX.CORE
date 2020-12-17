#include <XGeom_VectorWithMagnitude.h>
namespace TKG3d {
	XGeom_VectorWithMagnitude::XGeom_VectorWithMagnitude() {
		//NativeHandle() = new Geom_VectorWithMagnitude();
	};

	XGeom_VectorWithMagnitude::XGeom_VectorWithMagnitude(Handle(Geom_VectorWithMagnitude) pos) {
		NativeHandle() = pos;
		SetVectorHandle(NativeHandle());
	};

	void XGeom_VectorWithMagnitude::SetVectorWithMagnitudeHandle(Handle(Geom_VectorWithMagnitude) handle) {
		NativeHandle() = handle;
		SetVectorHandle(NativeHandle());
	};

	Handle(Geom_VectorWithMagnitude) XGeom_VectorWithMagnitude::GetVectorWithMagnitude() {
		return NativeHandle();
	};

	Handle(Geom_Vector) XGeom_VectorWithMagnitude::GetVector() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Geometry) XGeom_VectorWithMagnitude::GetGeometry() {
		return NativeHandle();
	};

	//! Creates a transient copy of V.
	XGeom_VectorWithMagnitude::XGeom_VectorWithMagnitude(xgp_Vec^ V) {
		NativeHandle() = new Geom_VectorWithMagnitude(*V->GetVec());
		SetVectorHandle(NativeHandle());
	};

	//! Creates a vector with three cartesian coordinates.
	XGeom_VectorWithMagnitude::XGeom_VectorWithMagnitude(Standard_Real X, Standard_Real Y, Standard_Real Z) {
		NativeHandle() = new Geom_VectorWithMagnitude(X, Y, Z);
		SetVectorHandle(NativeHandle());
	};


	//! Creates a vector from the point P1 to the point P2.
	//! The magnitude of the vector is the distance between P1 and P2
	XGeom_VectorWithMagnitude::XGeom_VectorWithMagnitude(xgp_Pnt^ P1, xgp_Pnt^ P2) {
		NativeHandle() = new Geom_VectorWithMagnitude(*P1->GetPnt(), *P2->GetPnt());
		SetVectorHandle(NativeHandle());
	};

	//! Assigns the values X, Y and Z to the coordinates of this vector.
	void XGeom_VectorWithMagnitude::SetCoord(Standard_Real X, Standard_Real Y, Standard_Real Z) {
		NativeHandle()->SetCoord(X, Y, Z);
	};

	//! Converts the gp_Vec vector V into this vector.
	void XGeom_VectorWithMagnitude::SetVec(xgp_Vec^ V) {
		NativeHandle()->SetVec(*V->GetVec());
	};

	//! Changes the X coordinate of <me>.
	void XGeom_VectorWithMagnitude::SetX(Standard_Real X) {
		NativeHandle()->SetX(X);
	};

	//! Changes the Y coordinate of <me>
	void XGeom_VectorWithMagnitude::SetY(Standard_Real Y) {
		NativeHandle()->SetY(Y);
	};

	//! Changes the Z coordinate of <me>.
	void XGeom_VectorWithMagnitude::SetZ(Standard_Real Z) {
		NativeHandle()->SetZ(Z);
	};

	//! Returns the magnitude of <me>.
	Standard_Real XGeom_VectorWithMagnitude::Magnitude() {
		return NativeHandle()->Magnitude();
	};

	//! Returns the square magnitude of <me>.
	Standard_Real XGeom_VectorWithMagnitude::SquareMagnitude() {
		return NativeHandle()->SquareMagnitude();
	};


	//! Adds the Vector Other to <me>.
	void XGeom_VectorWithMagnitude::Add(XGeom_Vector^ Other) {
		NativeHandle()->Add(Other->GetVector());
	};


	//! Adds the vector Other to <me>.
	XGeom_VectorWithMagnitude^ XGeom_VectorWithMagnitude::Added(XGeom_Vector^ Other) {
		return gcnew XGeom_VectorWithMagnitude(NativeHandle()->Added(Other->GetVector()));
	};


	//! Computes the cross product  between <me> and Other
	//! <me> ^ Other.
	void XGeom_VectorWithMagnitude::Cross(XGeom_Vector^ Other) {
		NativeHandle()->Cross(Other->GetVector());
	};


	//! Computes the cross product  between <me> and Other
	//! <me> ^ Other. A new vector is returned.
	XGeom_Vector^ XGeom_VectorWithMagnitude::Crossed(XGeom_Vector^ Other) {
		return gcnew XGeom_Vector(NativeHandle()->Crossed(Other->GetVector()));
	};


	//! Computes the triple vector product  <me> ^ (V1 ^ V2).
	void XGeom_VectorWithMagnitude::CrossCross(XGeom_Vector^ V1, XGeom_Vector^ V2) {
		NativeHandle()->CrossCross(V1->GetVector(), V2->GetVector());
	};


	//! Computes the triple vector product  <me> ^ (V1 ^ V2).
	//! A new vector is returned.
	XGeom_Vector^ XGeom_VectorWithMagnitude::CrossCrossed(XGeom_Vector^ V1, XGeom_Vector^ V2) {
		return gcnew XGeom_Vector(NativeHandle()->CrossCrossed(V1->GetVector(), V2->GetVector()));
	};

	//! Divides <me> by a scalar.
	void XGeom_VectorWithMagnitude::Divide(Standard_Real Scalar) {
		NativeHandle()->Divide(Scalar);
	};


	//! Divides <me> by a scalar. A new vector is returned.
	XGeom_VectorWithMagnitude^ XGeom_VectorWithMagnitude::Divided(Standard_Real Scalar) {
		return gcnew XGeom_VectorWithMagnitude(NativeHandle()->Divided(Scalar));
	};


	//! Computes the product of the vector <me> by a scalar.
	//! A new vector is returned.
	XGeom_VectorWithMagnitude^ XGeom_VectorWithMagnitude::Multiplied(Standard_Real Scalar) {
		return gcnew XGeom_VectorWithMagnitude(NativeHandle()->Multiplied(Scalar));
	};


	//! Computes the product of the vector <me> by a scalar.
	void XGeom_VectorWithMagnitude::Multiply(Standard_Real Scalar) {
		NativeHandle()->Multiply(Scalar);
	};

	//! Normalizes <me>.
	//!
	//! Raised if the magnitude of the vector is lower or equal to
	//! Resolution from package gp.
	void XGeom_VectorWithMagnitude::Normalize() {
		NativeHandle()->Normalize();
	};

	//! Returns a copy of <me> Normalized.
	//!
	//! Raised if the magnitude of the vector is lower or equal to
	//! Resolution from package gp.
	XGeom_VectorWithMagnitude^ XGeom_VectorWithMagnitude::Normalized() {
		return gcnew XGeom_VectorWithMagnitude(NativeHandle()->Normalized());
	};

	//! Subtracts the Vector Other to <me>.
	void XGeom_VectorWithMagnitude::Subtract(XGeom_Vector^ Other) {
		NativeHandle()->Subtract(Other->GetVector());
	};


	//! Subtracts the vector Other to <me>. A new vector is returned.
	XGeom_VectorWithMagnitude^ XGeom_VectorWithMagnitude::Subtracted(XGeom_Vector^ Other) {
		return gcnew XGeom_VectorWithMagnitude(NativeHandle()->Subtracted(Other->GetVector()));
	};

	//! Applies the transformation T to this vector.
	void XGeom_VectorWithMagnitude::Transform(xgp_Trsf^ T) {
		NativeHandle()->Transform(*T->GetTrsf());
	};

	//! Creates a new object which is a copy of this vector.
	XGeom_Geometry^ XGeom_VectorWithMagnitude::Copy() {
		return gcnew XGeom_Geometry(NativeHandle()->Copy());
	};
}