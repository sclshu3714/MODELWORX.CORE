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

#ifndef _XGeom_Conic_HeaderFile
#define _XGeom_Conic_HeaderFile
#pragma once
#include <NCollection_Haft.h>
#include <Geom_Conic.hxx>
#include <XGeom_Curve.h>  
#include <xgp_Ax1.h> 
#include <xgp_Pnt.h>
#include <xgp_Ax2.h>

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <Standard_Real.hxx>
#include <GeomAbs_Shape.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_Integer.hxx>
class Standard_ConstructionError;
class Standard_RangeError;
class Standard_DomainError;

//
//class Geom_Conic;
//DEFINE_STANDARD_HANDLE(Geom_Conic, Geom_Curve)

//! The abstract class Conic describes the common
//! behavior of conic curves in 3D space and, in
//! particular, their general characteristics. The Geom
//! package provides four concrete classes of conics:
//! Geom_Circle, Geom_Ellipse, Geom_Hyperbola and Geom_Parabola.
//! A conic is positioned in space with a right-handed
//! coordinate system (gp_Ax2 object), where:
//! - the origin is the center of the conic (or the apex in
//! the case of a parabola),
//! - the origin, "X Direction" and "Y Direction" define the
//! plane of the conic.
//! This coordinate system is the local coordinate
//! system of the conic.
//! The "main Direction" of this coordinate system is the
//! vector normal to the plane of the conic. The axis, of
//! which the origin and unit vector are respectively the
//! origin and "main Direction" of the local coordinate
//! system, is termed the "Axis" or "main Axis" of the conic.
//! The "main Direction" of the local coordinate system
//! gives an explicit orientation to the conic, determining
//! the direction in which the parameter increases along
//! the conic. The "X Axis" of the local coordinate system
//! also defines the origin of the parameter of the conic.
using namespace TKMath;
namespace TKG3d {
	ref class TKMath::xgp_Ax1;
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Ax2;
	public ref class XGeom_Conic : public XGeom_Curve
	{

	public:
		XGeom_Conic();

		XGeom_Conic(Handle(Geom_Conic) pos);

		virtual Handle(Geom_Conic) GetConic();

		//!
		virtual Handle(Geom_Curve) GetCurve() Standard_OVERRIDE;

		//!
		virtual Handle(Geom_Geometry) GetGeometry() Standard_OVERRIDE;

		void SetConicHandle(Handle(Geom_Conic) pos);

		//! Changes the orientation of the conic's plane. The normal
		//! axis to the plane is A1. The XAxis and the YAxis are recomputed.
		//!
		//! raised if the A1 is parallel to the XAxis of the conic.
		void SetAxis(xgp_Ax1^ A1);

		//! changes the location point of the conic.
		void SetLocation(xgp_Pnt^ P);

		//! changes the local coordinate system of the conic.
		void SetPosition(xgp_Ax2^ A2);

		//! Returns the "main Axis" of this conic. This axis is
		//! normal to the plane of the conic.
		xgp_Ax1^ Axis();


		//! Returns the eccentricity value of the conic e.
		//! e for a circle
		//! 0 < e < 1 for an ellipse  (e if MajorRadius = MinorRadius)
		//! e > 1 for a hyperbola
		//! e = 1 for a parabola
		//! Exceptions
		//! Standard_DomainError in the case of a hyperbola if
		//! its major radius is null.
		virtual Standard_Real Eccentricity();


		//! Returns the location point of the conic.
		//! For the circle, the ellipse and the hyperbola it is the center of
		//! the conic. For the parabola it is the Apex of the parabola.
		xgp_Pnt^ Location();


		//! Returns the local coordinates system of the conic.
		//! The main direction of the Axis2Placement is normal to the
		//! plane of the conic. The X direction of the Axis2placement
		//! is in the plane of the conic and corresponds to the origin
		//! for the conic's parametric value u.
		xgp_Ax2^ Position();


		//! Returns the XAxis of the conic.
		//! This axis defines the origin of parametrization of the conic.
		//! This axis is perpendicular to the Axis of the conic.
		//! This axis and the Yaxis define the plane of the conic.
		xgp_Ax1^ XAxis();


		//! Returns the YAxis of the conic.
		//! The YAxis is perpendicular to the Xaxis.
		//! This axis and the Xaxis define the plane of the conic.
		xgp_Ax1^ YAxis();


		//! Reverses the direction of parameterization of <me>.
		//! The local coordinate system of the conic is modified.
		void Reverse() Standard_OVERRIDE;

		//! Returns the  parameter on the  reversed  curve for
		//! the point of parameter U on <me>.
		virtual Standard_Real ReversedParameter(Standard_Real U) Standard_OVERRIDE;

		//! The continuity of the conic is Cn.
		XGeomAbs_Shape Continuity() Standard_OVERRIDE;

		//! Returns True.
		//! Raised if N < 0.
		Standard_Boolean IsCN(Standard_Integer N) Standard_OVERRIDE;

		//! DEFINE_STANDARD_RTTIEXT(Geom_Conic,Geom_Curve)
		  /// <summary>
		  /// ±¾µØ¾ä±ú
		  /// </summary>
		virtual property Handle(Standard_Transient) IHandle {
			Handle(Standard_Transient) get() Standard_OVERRIDE {
				return 	NativeHandle();
			}
			void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
				NativeHandle() = Handle(Geom_Conic)::DownCast(handle);
			}
		}

	private:
		NCollection_Haft<Handle(Geom_Conic)> NativeHandle;
	};
}
#endif // _XGeom_Conic_HeaderFile
