#include "xgp_Ax1.h"

namespace TKMath
{
    //public
	xgp_Ax1::xgp_Ax1(void) {
		NativeHandle = new gp_Ax1();
	};

	xgp_Ax1::xgp_Ax1(gp_Ax1* pos) {
		this->NativeHandle = new gp_Ax1(*pos);
	}

	xgp_Ax1::xgp_Ax1(gp_Pnt* P, gp_Dir* V) {
		NativeHandle = new gp_Ax1(*P, *V);
	}

	xgp_Ax1::xgp_Ax1(xgp_Pnt^ P, xgp_Dir^ V) {
		NativeHandle = new gp_Ax1(P->GetPnt(), *V->Handle);
	}

	xgp_Ax1::~xgp_Ax1() {
		if (NativeHandle != NULL) {
			delete NativeHandle;
			NativeHandle = NULL;
		}
	}

	xgp_Ax1::!xgp_Ax1() {
		if (NativeHandle != NULL) {
			delete NativeHandle;
			NativeHandle = NULL;
		}
	}

	gp_Ax1* xgp_Ax1::GetAx1() {
		return NativeHandle;
	}

	void xgp_Ax1::SetDirection(xgp_Dir^ V) {
		NativeHandle->SetDirection(V->GetDir());
	}

	void xgp_Ax1::SetLocation(xgp_Pnt^ P) {
		NativeHandle->SetLocation(P->GetPnt());
	}

	xgp_Dir^ xgp_Ax1::Direction() {
		gp_Dir* tmp = new gp_Dir(NativeHandle->Direction());
		return gcnew xgp_Dir(tmp);
	}

	xgp_Pnt^ xgp_Ax1::Location() {
		gp_Pnt* tmp = new gp_Pnt(NativeHandle->Location());
		return gcnew xgp_Pnt(tmp);
	}

	Standard_Boolean xgp_Ax1::IsCoaxial(xgp_Ax1^ Other, Standard_Real AngularTolerance, Standard_Real LinearTolerance) {
		return NativeHandle->IsCoaxial(*Other->GetAx1(), AngularTolerance, LinearTolerance);
	}

	Standard_Boolean xgp_Ax1::IsNormal(xgp_Ax1^ Other, Standard_Real AngularTolerance) {
		return NativeHandle->IsNormal(*Other->GetAx1(), AngularTolerance);
	}


	Standard_Boolean xgp_Ax1::IsOpposite(xgp_Ax1^ Other, Standard_Real AngularTolerance) {
		return NativeHandle->IsOpposite(*Other->GetAx1(), AngularTolerance);
	}

	Standard_Boolean xgp_Ax1::IsParallel(xgp_Ax1^ Other, Standard_Real AngularTolerance) {
		return NativeHandle->IsParallel(*Other->GetAx1(), AngularTolerance);
	}

	Standard_Real xgp_Ax1::Angle(xgp_Ax1^ Other) {
		return NativeHandle->Angle(*Other->GetAx1());
	}
	void xgp_Ax1::Reverse() {
		NativeHandle->Reverse();
	}
	xgp_Ax1^ xgp_Ax1::Reversed() {
		gp_Ax1* temp = new gp_Ax1(NativeHandle->Reversed());
		return gcnew xgp_Ax1(temp);
	}
	void xgp_Ax1::Mirror(xgp_Pnt^ P) {
		NativeHandle->Mirror(P->GetPnt());
	}
	xgp_Ax1^ xgp_Ax1::Mirrored(xgp_Pnt^ P) {
		gp_Ax1* temp = new gp_Ax1(NativeHandle->Mirrored(P->GetPnt()));
		return gcnew xgp_Ax1(temp);
	}
	void xgp_Ax1::Mirror(xgp_Ax1^ Ax1) {
		NativeHandle->Mirror(*Ax1->GetAx1());
	}

	xgp_Ax1^ xgp_Ax1::Mirrored(xgp_Ax1^ A1) {
		gp_Ax1* temp = new gp_Ax1(NativeHandle->Mirrored(*A1->GetAx1()));
		return gcnew xgp_Ax1(temp);
	}

	void xgp_Ax1::Mirror(xgp_Ax2^ A2) {
		NativeHandle->Mirror(*A2->GetAx2());
	}

	xgp_Ax1^ xgp_Ax1::Mirrored(xgp_Ax2^ A2) {
		gp_Ax1* temp = new gp_Ax1(NativeHandle->Mirrored(*A2->GetAx2()));
		return gcnew xgp_Ax1(temp);
	}

	void xgp_Ax1::Rotate(xgp_Ax1^ A1, Standard_Real Ang) {
		NativeHandle->Rotate(*A1->GetAx1(), Ang);
	}

	xgp_Ax1^ xgp_Ax1::Rotated(xgp_Ax1^ A1, Standard_Real Ang) {
		gp_Ax1* temp = new gp_Ax1(NativeHandle->Rotated(*A1->GetAx1(), Ang));
		return gcnew xgp_Ax1(temp);
	}

	void xgp_Ax1::Scale(xgp_Pnt^ P, Standard_Real S) {
		NativeHandle->Scale(P->GetPnt(), S);
	}

	xgp_Ax1^ xgp_Ax1::Scaled(xgp_Pnt^ P, Standard_Real S) {
		gp_Ax1* temp = new gp_Ax1(NativeHandle->Scaled(P->GetPnt(), S));
		return gcnew xgp_Ax1(temp);
	}

	void xgp_Ax1::Transform(xgp_Trsf^ T) {
		NativeHandle->Transform(T->GetTrsf());
	}

	xgp_Ax1^ xgp_Ax1::Transformed(xgp_Trsf^ T) {
		gp_Ax1* temp = new gp_Ax1(NativeHandle->Transformed(T->GetTrsf()));
		return gcnew xgp_Ax1(temp);
	}

	void xgp_Ax1::Translate(xgp_Vec^ V) {
		NativeHandle->Translate(V->GetVec());
	}
	xgp_Ax1^ xgp_Ax1::Translated(xgp_Vec^ V) {
		gp_Ax1* temp = new gp_Ax1(NativeHandle->Translated(V->GetVec()));
		return gcnew xgp_Ax1(temp);
	}
	void xgp_Ax1::Translate(xgp_Pnt^ P1, xgp_Pnt^ P2) {
		NativeHandle->Translate(P1->GetPnt(),P2->GetPnt());
	}
	xgp_Ax1^ xgp_Ax1::Translated(xgp_Pnt^ P1, xgp_Pnt^ P2) {
		gp_Ax1* temp = new gp_Ax1(NativeHandle->Translated(P1->GetPnt(), P2->GetPnt()));
		return gcnew xgp_Ax1(temp);
	}
};