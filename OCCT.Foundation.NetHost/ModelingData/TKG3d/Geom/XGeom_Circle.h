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

#ifndef _XGeom_Circle_HeaderFile
#define _XGeom_Circle_HeaderFile
#pragma once
#include <NCollection_Haft.h> 
#include <XGeom_Geometry.h>	
#include <XGeom_Conic.h>
#include <Geom_Circle.hxx>
#include <xgp_Vec.h>
#include <xgp_Circ.h>
#include <xgp_Ax2.h>
#include <xgp_Pnt.h>
#include <xgp_Vec.h>
#include <xgp_Trsf.h>

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <Standard_Real.hxx>
#include <Geom_Conic.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_Integer.hxx>
class Standard_ConstructionError;
class Standard_RangeError;



//class Geom_Circle;
//DEFINE_STANDARD_HANDLE(Geom_Circle, Geom_Conic)

//! Describes a circle in 3D space.
//! A circle is defined by its radius and, as with any conic
//! curve, is positioned in space with a right-handed
//! coordinate system (gp_Ax2 object) where:
//! - the origin is the center of the circle, and
//! - the origin, "X Direction" and "Y Direction" define the
//! plane of the circle.
//! This coordinate system is the local coordinate
//! system of the circle.
//! The "main Direction" of this coordinate system is the
//! vector normal to the plane of the circle. The axis, of
//! which the origin and unit vector are respectively the
//! origin and "main Direction" of the local coordinate
//! system, is termed the "Axis" or "main Axis" of the circle.
//! The "main Direction" of the local coordinate system
//! gives an explicit orientation to the circle (definition of
//! the trigonometric sense), determining the direction in
//! which the parameter increases along the circle.
//! The Geom_Circle circle is parameterized by an angle:
//! P(U) = O + R*Cos(U)*XDir + R*Sin(U)*YDir, where:
//! - P is the point of parameter U,
//! - O, XDir and YDir are respectively the origin, "X
//! Direction" and "Y Direction" of its local coordinate system,
//! - R is the radius of the circle.
//! The "X Axis" of the local coordinate system therefore
//! defines the origin of the parameter of the circle. The
//! parameter is the angle with this "X Direction".
//! A circle is a closed and periodic curve. The period is
//! 2.*Pi and the parameter range is [ 0, 2.*Pi [.
//!  

using namespace TKMath;
namespace TKG3d {
	ref class TKMath::xgp_Circ;
	ref class TKMath::xgp_Ax2;
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Vec;
	ref class TKMath::xgp_Trsf;
	ref class XGeom_Geometry;
	public ref class XGeom_Circle : public XGeom_Conic
	{

	public:

		!XGeom_Circle() { IHandle = NULL; };
		~XGeom_Circle() { IHandle = NULL; };
		//! Constructs a circle by conversion of the gp_Circ circle C.
		XGeom_Circle(xgp_Circ^ C);

		//! Constructs a circle of radius Radius, where A2 locates the circle and
		//! defines its orientation in 3D space such that:
		//! - the center of the circle is the origin of A2,
		//! - the origin, "X Direction" and "Y Direction" of A2
		//! define the plane of the circle,
		//! - A2 is the local coordinate system of the circle.
		//! Note: It is possible to create a circle where Radius is equal to 0.0.
		//! raised if Radius < 0.
		XGeom_Circle(xgp_Ax2^ A2, Standard_Real Radius);


		XGeom_Circle(Handle(Geom_Circle) pos);

		Handle(Geom_Circle) GetCircle();

		virtual Handle(Geom_Conic) GetConic() Standard_OVERRIDE;

		//!
		virtual Handle(Geom_Curve) GetCurve() Standard_OVERRIDE;

		//!
		virtual Handle(Geom_Geometry) GetGeometry() Standard_OVERRIDE;

		void SetCircleHandle(Handle(Geom_Circle) pos);


		//! Set <me> so that <me> has the same geometric properties as C.
		void SetCirc(xgp_Circ^ C);

		//! Assigns the value R to the radius of this circle.
		//! Note: it is possible to have a circle with a radius equal to 0.0.
		//! Exceptions - Standard_ConstructionError if R is negative.
		void SetRadius(Standard_Real R);


		//! returns the non transient circle from gp with the same
		//! geometric properties as <me>.
		xgp_Circ^ Circ();

		//! Returns the radius of this circle.
		Standard_Real Radius();

		//! Computes the parameter on the reversed circle for
		//! the point of parameter U on this circle.
		//! For a circle, the returned value is: 2.*Pi - U.
		Standard_Real ReversedParameter(Standard_Real U) Standard_OVERRIDE;

		//! Returns the eccentricity  e = 0 for a circle.
		Standard_Real Eccentricity() Standard_OVERRIDE;

		//! Returns the value of the first parameter of this
		//! circle. This is  0.0, which gives the start point of this circle, or
		//! The start point and end point of a circle are coincident.
		Standard_Real FirstParameter() Standard_OVERRIDE;

		//! Returns the value of the last parameter of this
		//! circle. This is 2.*Pi, which gives the end point of this circle.
		//! The start point and end point of a circle are coincident.
		Standard_Real LastParameter() Standard_OVERRIDE;

		//! returns True.
		Standard_Boolean IsClosed() Standard_OVERRIDE;

		//! returns True.
		Standard_Boolean IsPeriodic() Standard_OVERRIDE;

		//! Returns in P the point of parameter U.
		//! P = C + R * Cos (U) * XDir + R * Sin (U) * YDir
		//! where C is the center of the circle , XDir the XDirection and
		//! YDir the YDirection of the circle's local coordinate system.
		void D0(Standard_Real U, xgp_Pnt^ P) Standard_OVERRIDE;


		//! Returns the point P of parameter U and the first derivative V1.
		void D1(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1) Standard_OVERRIDE;


		//! Returns the point P of parameter U, the first and second
		//! derivatives V1 and V2.
		void D2(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2) Standard_OVERRIDE;


		//! Returns the point P of parameter u, the first second and third
		//! derivatives V1 V2 and V3.
		void D3(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2, xgp_Vec^ V3) Standard_OVERRIDE;


		//! The returned vector gives the value of the derivative for the
		//! order of derivation N.
		//! Raised if N < 1.
		xgp_Vec^ DN(Standard_Real U, Standard_Integer N) Standard_OVERRIDE;

		//! Applies the transformation T to this circle.
		void Transform(xgp_Trsf^ T) Standard_OVERRIDE;

		//! Creates a new object which is a copy of this circle.
		XGeom_Geometry^ Copy() Standard_OVERRIDE;

		//! DEFINE_STANDARD_RTTIEXT(Geom_Circle, Geom_Conic)
		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property Handle(Standard_Transient) IHandle {
			Handle(Standard_Transient) get() Standard_OVERRIDE {
				return 	NativeHandle();
			}
			void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
				NativeHandle() = Handle(Geom_Circle)::DownCast(handle);
			}
		}

	private:
		NCollection_Haft<Handle(Geom_Circle)> NativeHandle;
	};
}
#endif // _XGeom_Circle_HeaderFile
