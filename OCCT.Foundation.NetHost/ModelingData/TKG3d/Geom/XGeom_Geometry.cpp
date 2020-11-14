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

//JCV 09/07/92 portage sur C1

//#include "XStandard_ConstructionError.h"  
//#include <Standard_Type.hxx>
#include "XGeom_Geometry.h"


//class Geom_Geometry;
//IMPLEMENT_STANDARD_RTTIEXT(Geom_Geometry, Standard_Transient)

namespace TKG3d
{
	XGeom_Geometry::XGeom_Geometry(void) {

	}

	XGeom_Geometry::XGeom_Geometry(Geom_Geometry* pos) {
		NativeHandle = pos;
	}

	XGeom_Geometry::~XGeom_Geometry() {
		if (NativeHandle != NULL)
			delete NativeHandle;
		NativeHandle = NULL;
	}

	Handle(Geom_Geometry) XGeom_Geometry::GetGeometry() {
		return NativeHandle;// Handle(Geom_Geometry)(NativeHandle);
	}


	void XGeom_Geometry::Mirror(xgp_Pnt^ P) {
		NativeHandle->Mirror(P->GetPnt());
	}



	void XGeom_Geometry::Mirror(xgp_Ax1^ A1) {
		NativeHandle->Mirror(A1->GetAx1());
	}


	void XGeom_Geometry::Mirror(xgp_Ax2^ A2) {
		NativeHandle->Mirror(A2->GetAx2());
	}


	void XGeom_Geometry::Rotate(xgp_Ax1^ A1, Standard_Real Ang) {
		NativeHandle->Rotate(A1->GetAx1(), Ang);
	}


	void XGeom_Geometry::Scale(xgp_Pnt^ P, Standard_Real S) {
		NativeHandle->Scale(P->GetPnt(), S);
	}


	void XGeom_Geometry::Translate(xgp_Vec^ V) {
		NativeHandle->Translate(V->GetVec());
	}


	void XGeom_Geometry::Translate(xgp_Pnt^ P1, xgp_Pnt^ P2) {
		NativeHandle->Translate(P1->GetPnt(), P2->GetPnt());
	}


	Handle(Geom_Geometry) XGeom_Geometry::Mirrored(xgp_Pnt^ P) {
		return NativeHandle->Mirrored(P->GetPnt());
	}


	Handle(Geom_Geometry) XGeom_Geometry::Mirrored(xgp_Ax1^ A1) {
		return NativeHandle->Mirrored(A1->GetAx1());
	}


	Handle(Geom_Geometry) XGeom_Geometry::Mirrored(xgp_Ax2^ A2) {
		return NativeHandle->Mirrored(A2->GetAx2());
	}



	Handle(Geom_Geometry) XGeom_Geometry::Rotated(xgp_Ax1^ A1, Standard_Real Ang) {
		return NativeHandle->Rotated(A1->GetAx1(), Ang);
	}



	Handle(Geom_Geometry) XGeom_Geometry::Scaled(xgp_Pnt^ P, Standard_Real S) {
		return NativeHandle->Scaled(P->GetPnt(), S);
	}



	Handle(Geom_Geometry) XGeom_Geometry::Transformed(xgp_Trsf^ T) {
		return NativeHandle->Transformed(T->GetTrsf());
	}



	Handle(Geom_Geometry) XGeom_Geometry::Translated(xgp_Vec^ V) {
		return NativeHandle->Translated(V->GetVec());
	}


	Handle(Geom_Geometry) XGeom_Geometry::Translated(xgp_Pnt^ P1, xgp_Pnt^ P2) {
		return NativeHandle->Translated(P1->GetPnt(), P2->GetPnt());
	}

	Handle(Geom_Geometry) XGeom_Geometry::Copy() {
		Handle(Geom_Geometry) G;
		throw Standard_ConstructionError();
	}
};

