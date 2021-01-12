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

#ifndef _XGeom_Ellipse_HeaderFile
#define _XGeom_Ellipse_HeaderFile
#pragma once
#include <NCollection_Haft.h> 
#include <XGeom_Geometry.h>	
#include <XGeom_Conic.h>
#include <Geom_Ellipse.hxx>
#include <xgp_Elips.h>
#include <xgp_Ax2.h>
#include <xgp_Ax1.h>
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


using namespace TKMath;

//class Geom_Ellipse;
//DEFINE_STANDARD_HANDLE(Geom_Ellipse, Geom_Conic)

//! Describes an ellipse in 3D space.
//! An ellipse is defined by its major and minor radii and,
//! as with any conic curve, is positioned in space with a
//! right-handed coordinate system (gp_Ax2 object) where:
//! - the origin is the center of the ellipse,
//! - the "X Direction" defines the major axis, and
//! - the "Y Direction" defines the minor axis.
//! The origin, "X Direction" and "Y Direction" of this
//! coordinate system define the plane of the ellipse. The
//! coordinate system is the local coordinate system of the ellipse.
//! The "main Direction" of this coordinate system is the
//! vector normal to the plane of the ellipse. The axis, of
//! which the origin and unit vector are respectively the
//! origin and "main Direction" of the local coordinate
//! system, is termed the "Axis" or "main Axis" of the ellipse.
//! The "main Direction" of the local coordinate system
//! gives an explicit orientation to the ellipse (definition of
//! the trigonometric sense), determining the direction in
//! which the parameter increases along the ellipse.
//! The Geom_Ellipse ellipse is parameterized by an angle:
//! P(U) = O + MajorRad*Cos(U)*XDir + MinorRad*Sin(U)*YDir
//! where:
//! - P is the point of parameter U,
//! - O, XDir and YDir are respectively the origin, "X
//! Direction" and "Y Direction" of its local coordinate system,
//! - MajorRad and MinorRad are the major and minor radii of the ellipse.
//! The "X Axis" of the local coordinate system therefore
//! defines the origin of the parameter of the ellipse.
//! An ellipse is a closed and periodic curve. The period
//! is 2.*Pi and the parameter range is [ 0, 2.*Pi [.
//! 
namespace TKG3d {
	ref class TKMath::xgp_Elips;
	ref class TKMath::xgp_Ax2;
	ref class TKMath::xgp_Ax1;
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Vec;
	ref class TKMath::xgp_Trsf;
	ref class XGeom_Geometry;
	public ref class XGeom_Ellipse : public XGeom_Conic
	{

	public:


		//! Constructs an ellipse by conversion of the gp_Elips ellipse E.
		XGeom_Ellipse(xgp_Elips^ E);

		//! Constructs an ellipse
		//! defined by its major and minor radii, MajorRadius
		//! and MinorRadius, where A2 locates the ellipse
		//! and defines its orientation in 3D space such that:
		//! - the center of the ellipse is the origin of A2,
		//! - the "X Direction" of A2 defines the major axis
		//! of the ellipse, i.e. the major radius
		//! MajorRadius is measured along this axis,
		//! - the "Y Direction" of A2 defines the minor axis
		//! of the ellipse, i.e. the minor radius
		//! MinorRadius is measured along this axis,
		//! - A2 is the local coordinate system of the ellipse.
		//! Exceptions
		//! Standard_ConstructionError if:
		//! - MajorRadius is less than MinorRadius, or
		//! - MinorRadius is less than 0.
		//! Warning The Geom package does not prevent the
		//! construction of an ellipse where MajorRadius and
		//! MinorRadius are equal.
		XGeom_Ellipse(xgp_Ax2^ A2, Standard_Real MajorRadius, Standard_Real MinorRadius);

		//! 
		XGeom_Ellipse(Handle(Geom_Ellipse) pos);

		void SetEllipseHandle(Handle(Geom_Ellipse) pos);

		//!
		virtual Handle(Geom_Conic) GetConic() Standard_OVERRIDE;
		//!
		virtual Handle(Geom_Curve) GetCurve() Standard_OVERRIDE;

		//!
		virtual Handle(Geom_Geometry) GetGeometry() Standard_OVERRIDE;

		//! Converts the gp_Elips ellipse E into this ellipse.
		void SetElips(xgp_Elips^ E);

		//! Assigns a value to the major radius of this ellipse.
		//! ConstructionError raised if MajorRadius < MinorRadius.
		void SetMajorRadius(Standard_Real MajorRadius);

		//! Assigns a value to the minor radius of this ellipse.
		//! ConstructionError raised if MajorRadius < MinorRadius or if MinorRadius < 0.
		void SetMinorRadius(Standard_Real MinorRadius);


		//! returns the non transient ellipse from gp with the same
		xgp_Elips^ Elips();

		//! Computes the parameter on the reversed ellipse for
		//! the point of parameter U on this ellipse.
		//! For an ellipse, the returned value is: 2.*Pi - U.
		Standard_Real ReversedParameter(Standard_Real U) Standard_OVERRIDE;


		//! This directrix is the line normal to the XAxis of the ellipse
		//! in the local plane (Z = 0) at a distance d = MajorRadius / e
		//! from the center of the ellipse, where e is the eccentricity of
		//! the ellipse.
		//! This line is parallel to the "YAxis". The intersection point
		//! between directrix1 and the "XAxis" is the "Location" point
		//! of the directrix1. This point is on the positive side of
		//! the "XAxis".
		//! Raised if Eccentricity = 0.0. (The ellipse degenerates
		//! into a circle)
		xgp_Ax1^ Directrix1();


		//! This line is obtained by the symmetrical transformation
		//! of "Directrix1" with respect to the "YAxis" of the ellipse.
		//!
		//! Raised if Eccentricity = 0.0. (The ellipse degenerates into a
		//! circle).
		xgp_Ax1^ Directrix2();


		//! Returns the eccentricity of the ellipse  between 0.0 and 1.0
		//! If f is the distance between the center of the ellipse and
		//! the Focus1 then the eccentricity e = f / MajorRadius.
		//! Returns 0 if MajorRadius = 0
		Standard_Real Eccentricity() Standard_OVERRIDE;


		//! Computes the focal distance. It is the distance between the
		//! the two focus of the ellipse.
		Standard_Real Focal();


		//! Returns the first focus of the ellipse. This focus is on the
		//! positive side of the "XAxis" of the ellipse.
		xgp_Pnt^ Focus1();


		//! Returns the second focus of the ellipse. This focus is on
		//! the negative side of the "XAxis" of the ellipse.
		xgp_Pnt^ Focus2();

		//! Returns the major  radius of this ellipse.
		Standard_Real MajorRadius();

		//! Returns the minor radius of this ellipse.
		Standard_Real MinorRadius();


		//! Returns p = (1 - e * e) * MajorRadius where e is the eccentricity
		//! of the ellipse.
		//! Returns 0 if MajorRadius = 0
		Standard_Real Parameter();

		//! Returns the value of the first parameter of this
		//! ellipse. This is respectively:
		//! - 0.0, which gives the start point of this ellipse, or
		//! The start point and end point of an ellipse are coincident.
		Standard_Real FirstParameter() Standard_OVERRIDE;

		//! Returns the value of the  last parameter of this
		//! ellipse. This is respectively:
		//! - 2.*Pi, which gives the end point of this ellipse.
		//! The start point and end point of an ellipse are coincident.
		Standard_Real LastParameter() Standard_OVERRIDE;

		//! return True.
		Standard_Boolean IsClosed() Standard_OVERRIDE;

		//! return True.
		Standard_Boolean IsPeriodic() Standard_OVERRIDE;

		//! Returns in P the point of parameter U.
		//! P = C + MajorRadius * Cos (U) * XDir + MinorRadius * Sin (U) * YDir
		//! where C is the center of the ellipse , XDir the direction of
		//! the "XAxis" and "YDir" the "YAxis" of the ellipse.
		void D0(Standard_Real U, xgp_Pnt^ P) Standard_OVERRIDE;

		void D1(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1) Standard_OVERRIDE;


		//! Returns the point P of parameter U. The vectors V1 and V2
		//! are the first and second derivatives at this point.
		void D2(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2) Standard_OVERRIDE;


		//! Returns the point P of parameter U, the first second and
		//! third derivatives V1 V2 and V3.
		void D3(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2, xgp_Vec^ V3) Standard_OVERRIDE;

		//! For the point of parameter U of this ellipse, computes
		//! the vector corresponding to the Nth derivative.
		//! Exceptions Standard_RangeError if N is less than 1.
		xgp_Vec^ DN(Standard_Real U, Standard_Integer N) Standard_OVERRIDE;

		//! Applies the transformation T to this ellipse.
		void Transform(xgp_Trsf^ T) Standard_OVERRIDE;

		//! Creates a new object which is a copy of this ellipse.
		XGeom_Geometry^ Copy() Standard_OVERRIDE;




		//! DEFINE_STANDARD_RTTIEXT(Geom_Ellipse, Geom_Conic)
			/// <summary>
			/// ±¾µØ¾ä±ú
			/// </summary>
		virtual property Handle(Standard_Transient) IHandle {
			Handle(Standard_Transient) get() Standard_OVERRIDE {
				return 	NativeHandle();
			}
			void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
				NativeHandle() = Handle(Geom_Ellipse)::DownCast(handle);
			}
		}

	private:
		NCollection_Haft<Handle(Geom_Ellipse)> NativeHandle;
	};
}
#endif // _XGeom_Ellipse_HeaderFile
