// Created on: 1993-03-10
// Created by: JCV
// Copyright (c) 1993-1999 Matra Datavision
// Copyright (c) 1999-2014 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.


#include <XGeom_Conic.h>

namespace TKG3d {
	XGeom_Conic::XGeom_Conic() {
		//NativeHandle() = new Geom_Conic();
	};

	XGeom_Conic::XGeom_Conic(Handle(Geom_Conic) pos) {
		NativeHandle() = pos;
		SetCurveHandle(NativeHandle());
	};

	Handle(Geom_Conic) XGeom_Conic::GetConic() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Curve) XGeom_Conic::GetCurve() {
		return NativeHandle();
	};


	//!
	Handle(Geom_Geometry) XGeom_Conic::GetGeometry() {
		return NativeHandle();
	};

	void XGeom_Conic::SetConicHandle(Handle(Geom_Conic) pos) {
		NativeHandle() = pos; 
		SetCurveHandle(NativeHandle());
	};

	//! Changes the orientation of the conic's plane. The normal
	//! axis to the plane is A1. The XAxis and the YAxis are recomputed.
	//!
	//! raised if the A1 is parallel to the XAxis of the conic.
	void XGeom_Conic::SetAxis(xgp_Ax1^ A1) {
		NativeHandle()->SetAxis(*A1->GetAx1());
	};

	//! changes the location point of the conic.
	void XGeom_Conic::SetLocation(xgp_Pnt^ P) {
		NativeHandle()->SetLocation(P->GetPnt());
	};

	//! changes the local coordinate system of the conic.
	void XGeom_Conic::SetPosition(xgp_Ax2^ A2) {
		NativeHandle()->SetPosition(A2->GetAx2());
	};

	//! Returns the "main Axis" of this conic. This axis is
	//! normal to the plane of the conic.
	xgp_Ax1^ XGeom_Conic::Axis() {
		gp_Ax1* temp = new gp_Ax1(NativeHandle()->Axis());
		return gcnew xgp_Ax1(temp);
	};


	//! Returns the eccentricity value of the conic e.
	//! e for a circle
	//! 0 < e < 1 for an ellipse  (e if MajorRadius = MinorRadius)
	//! e > 1 for a hyperbola
	//! e = 1 for a parabola
	//! Exceptions
	//! Standard_DomainError in the case of a hyperbola if
	//! its major radius is null.
	Standard_Real XGeom_Conic::Eccentricity() {
		return NativeHandle()->Eccentricity();
	};


	//! Returns the location point of the conic.
	//! For the circle, the ellipse and the hyperbola it is the center of
	//! the conic. For the parabola it is the Apex of the parabola.
	xgp_Pnt^ XGeom_Conic::Location() {
		return gcnew xgp_Pnt(NativeHandle()->Location());
	};


	//! Returns the local coordinates system of the conic.
	//! The main direction of the Axis2Placement is normal to the
	//! plane of the conic. The X direction of the Axis2placement
	//! is in the plane of the conic and corresponds to the origin
	//! for the conic's parametric value u.
	xgp_Ax2^ XGeom_Conic::Position() {
		return gcnew xgp_Ax2(NativeHandle()->Position());
	};


	//! Returns the XAxis of the conic.
	//! This axis defines the origin of parametrization of the conic.
	//! This axis is perpendicular to the Axis of the conic.
	//! This axis and the Yaxis define the plane of the conic.
	xgp_Ax1^ XGeom_Conic::XAxis() {
		gp_Ax1* temp = new gp_Ax1(NativeHandle()->XAxis());
		return gcnew xgp_Ax1(temp);
	};


	//! Returns the YAxis of the conic.
	//! The YAxis is perpendicular to the Xaxis.
	//! This axis and the Xaxis define the plane of the conic.
	xgp_Ax1^ XGeom_Conic::YAxis() {
		gp_Ax1* temp = new gp_Ax1(NativeHandle()->YAxis());
		return gcnew xgp_Ax1(temp);
	};


	//! Reverses the direction of parameterization of <me>.
	//! The local coordinate system of the conic is modified.
	void XGeom_Conic::Reverse() {
		return NativeHandle()->Reverse();
	};

	//! Returns the  parameter on the  reversed  curve for
	//! the point of parameter U on <me>.
	Standard_Real XGeom_Conic::ReversedParameter(Standard_Real U) {
		return NativeHandle()->ReversedParameter(U);
	};

	//! The continuity of the conic is Cn.
	XGeomAbs_Shape XGeom_Conic::Continuity() {
		return safe_cast<XGeomAbs_Shape>(NativeHandle()->Continuity());
	};

	//! Returns True.
	//! Raised if N < 0.
	Standard_Boolean XGeom_Conic::IsCN(Standard_Integer N) {
		return NativeHandle()->IsCN(N);
	};
}

