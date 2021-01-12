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

#ifndef _XGeom_ToroidalSurface_HeaderFile
#define _XGeom_ToroidalSurface_HeaderFile
#pragma once
#include <XGeom_ElementarySurface.h>
#include <Geom_ToroidalSurface.hxx>
#include <XGeom_Surface.h>
#include <xgp_Ax3.h>
#include <xgp_Torus.h>
#include <xgp_Pnt.h>
#include <xgp_Vec.h>
#include <xgp_Trsf.h>
#include <XGeom_Curve.h>
#include <XGeom_Geometry.h>

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <Standard_Real.hxx>
#include <Geom_ElementarySurface.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_Integer.hxx>
class Standard_ConstructionError;
class Standard_DimensionError;
class Standard_RangeError;
class gp_Ax3;
class gp_Torus;
class Geom_Curve;
class gp_Pnt;
class gp_Vec;
class gp_Trsf;
class Geom_Geometry;
class Geom_ToroidalSurface;
//DEFINE_STANDARD_HANDLE(Geom_ToroidalSurface, Geom_ElementarySurface)

using namespace TKMath;
namespace TKG3d {
	ref class TKMath::xgp_Ax3;
	ref class TKMath::xgp_Ax3;
	ref class TKMath::xgp_Torus;
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Vec;
	ref class TKMath::xgp_Trsf;
	ref class XGeom_Curve;
	ref class XGeom_Geometry;
	//! Describes a torus.
	//! A torus is defined by its major and minor radii, and
	//! positioned in space with a coordinate system (a
	//! gp_Ax3 object) as follows:
	//! - The origin is the center of the torus.
	//! - The surface is obtained by rotating a circle around
	//! the "main Direction". This circle has a radius equal
	//! to the minor radius, and is located in the plane
	//! defined by the origin, "X Direction" and "main
	//! Direction". It is centered on the "X Axis", on its
	//! positive side, and positioned at a distance from the
	//! origin equal to the major radius. This circle is the
	//! "reference circle" of the torus.
	//! - The plane defined by the origin, the "X Direction"
	//! and the "Y Direction" is called the "reference plane" of the torus.
	//! This coordinate system is the "local coordinate
	//! system" of the torus. The following apply:
	//! - Rotation around its "main Axis", in the trigonometric
	//! sense given by "X Direction" and "Y Direction",
	//! defines the u parametric direction.
	//! - The "X Axis" gives the origin for the u parameter.
	//! - Rotation around an axis parallel to the "Y Axis" and
	//! passing through the center of the "reference circle"
	//! gives the v parameter on the "reference circle".
	//! - The "X Axis" gives the origin of the v parameter on
	//! the "reference circle".
	//! - The v parametric direction is oriented by the
	//! inverse of the "main Direction", i.e. near 0, as v
	//! increases, the Z coordinate decreases. (This
	//! implies that the "Y Direction" orients the reference
	//! circle only when the local coordinate system is direct.)
	//! - The u isoparametric curve is a circle obtained by
	//! rotating the "reference circle" of the torus through
	//! an angle u about the "main Axis".
	//! The parametric equation of the torus is :
	//! P(u, v) = O + (R + r*cos(v)) * (cos(u)*XDir +
	//! sin(u)*YDir ) + r*sin(v)*ZDir, where:
	//! - O, XDir, YDir and ZDir are respectively the
	//! origin, the "X Direction", the "Y Direction" and the "Z
	//! Direction" of the local coordinate system,
	//! - r and R are, respectively, the minor and major radius.
	//! The parametric range of the two parameters is:
	//! - [ 0, 2.*Pi ] for u
	//! - [ 0, 2.*Pi ] for v
	public ref class XGeom_ToroidalSurface : public XGeom_ElementarySurface
	{

	public:

		//!
		XGeom_ToroidalSurface(void);

		//! 
		XGeom_ToroidalSurface(Handle(Geom_ToroidalSurface) pos);

		//!
		~XGeom_ToroidalSurface();

		void SetToroidalSurfaceHandle(Handle(Geom_ToroidalSurface) handle);

		//! 
		virtual Handle(Geom_ToroidalSurface) GetToroidalSurface();

		//! 
		virtual Handle(Geom_ElementarySurface) GetElementarySurface() Standard_OVERRIDE;

		//!
		virtual Handle(Geom_Surface) GetSurface() Standard_OVERRIDE;

		//!
		virtual Handle(Geom_Geometry) GetGeometry() Standard_OVERRIDE;

		//! A3 is the local coordinate system of the surface.
		//! The orientation of increasing V parametric value is defined
		//! by the rotation around the main axis (ZAxis) in the
		//! trigonometric sense. The parametrization of the surface in the
		//! U direction is defined such as the normal Vector (N = D1U ^ D1V)
		//! is oriented towards the "outside region" of the surface.
		//! Warnings :
		//! It is not forbidden to create a toroidal surface with
		//! MajorRadius = MinorRadius = 0.0
		//!
		//! Raised if MinorRadius < 0.0 or if MajorRadius < 0.0
		XGeom_ToroidalSurface(xgp_Ax3^ A3, Standard_Real MajorRadius, Standard_Real MinorRadius);


		//! Creates a ToroidalSurface from a non transient Torus from
		//! package gp.
		XGeom_ToroidalSurface(xgp_Torus^ T);

		//! Modifies this torus by changing its major radius.
		//! Exceptions
		//! Standard_ConstructionError if:
		//! - MajorRadius is negative, or
		//! - MajorRadius - r is less than or equal to
		//! gp::Resolution(), where r is the minor radius of this torus.
		void SetMajorRadius(Standard_Real MajorRadius);

		//! Modifies this torus by changing its minor radius.
		//! Exceptions
		//! Standard_ConstructionError if:
		//! - MinorRadius is negative, or
		//! - R - MinorRadius is less than or equal to
		//! gp::Resolution(), where R is the major radius of this torus.
		void SetMinorRadius(Standard_Real MinorRadius);

		//! Converts the gp_Torus torus T into this torus.
		void SetTorus(xgp_Torus^ T);


		//! Returns the non transient torus with the same geometric
		//! properties as <me>.
		xgp_Torus^ Torus();

		//! Return the  parameter on the  Ureversed surface for
		//! the point of parameter U on <me>.
		//! Return 2.PI - U.
		Standard_Real UReversedParameter(Standard_Real U) Standard_OVERRIDE;

		//! Return the  parameter on the  Ureversed surface for
		//! the point of parameter U on <me>.
		//! Return 2.PI - U.
		Standard_Real VReversedParameter(Standard_Real U) Standard_OVERRIDE;

		//! Computes the aera of the surface.
		Standard_Real Area();

		//! Returns the parametric bounds U1, U2, V1 and V2 of this torus.
		//! For a torus: U1 = V1 = 0 and U2 = V2 = 2*PI .
		void Bounds(Standard_Real% U1, Standard_Real% U2, Standard_Real% V1, Standard_Real% V2) Standard_OVERRIDE;


		//! Returns the coefficients of the implicit equation of the surface
		//! in the absolute cartesian coordinate system :
		//! Coef(1) * X**4 + Coef(2) * Y**4 + Coef(3) * Z**4 +
		//! Coef(4) * X**3 * Y + Coef(5) * X**3 * Z + Coef(6) * Y**3 * X +
		//! Coef(7) * Y**3 * Z + Coef(8) * Z**3 * X + Coef(9) * Z**3 * Y +
		//! Coef(10) * X**2 * Y**2 + Coef(11) * X**2 * Z**2 +
		//! Coef(12) * Y**2 * Z**2 + Coef(13) * X**3 + Coef(14) * Y**3 +
		//! Coef(15) * Z**3 + Coef(16) * X**2 * Y + Coef(17) * X**2 * Z +
		//! Coef(18) * Y**2 * X + Coef(19) * Y**2 * Z + Coef(20) * Z**2 * X +
		//! Coef(21) * Z**2 * Y + Coef(22) * X**2 + Coef(23) * Y**2 +
		//! Coef(24) * Z**2 + Coef(25) * X * Y + Coef(26) * X * Z +
		//! Coef(27) * Y * Z + Coef(28) * X + Coef(29) * Y + Coef(30) *  Z +
		//! Coef(31) = 0.0
		//! Raised if the length of Coef is lower than 31.
		void Coefficients(array<Standard_Real>^ Coef);

		//! Returns the major radius, or the minor radius, of this torus.
		Standard_Real MajorRadius();

		//! Returns the major radius, or the minor radius, of this torus.
		Standard_Real MinorRadius();

		//! Computes the volume.
		Standard_Real Volume();

		//! Returns True.
		Standard_Boolean IsUClosed() Standard_OVERRIDE;

		//! Returns True.
		Standard_Boolean IsVClosed() Standard_OVERRIDE;

		//! Returns True.
		Standard_Boolean IsUPeriodic() Standard_OVERRIDE;

		//! Returns True.
		Standard_Boolean IsVPeriodic() Standard_OVERRIDE;

		//! Computes the U isoparametric curve.
		//!
		//! For a toroidal surface the UIso curve is a circle.
		//! The center of the Uiso circle is at the distance MajorRadius
		//! from the location point of the toroidal surface.
		//! Warnings :
		//! The radius of the circle can be zero if for the surface
		//! MinorRadius = 0.0
		XGeom_Curve^ UIso(Standard_Real U) Standard_OVERRIDE;

		//! Computes the V isoparametric curve.
		//!
		//! For a ToroidalSurface the VIso curve is a circle.
		//! The axis of the circle is the main axis (ZAxis) of the
		//! toroidal  surface.
		//! Warnings :
		//! The radius of the circle can be zero if for the surface
		//! MajorRadius = MinorRadius
		XGeom_Curve^ VIso(Standard_Real V) Standard_OVERRIDE;


		//! Computes the  point P (U, V) on the surface.
		//! P (U, V) = Loc + MinorRadius * Sin (V) * Zdir +
		//! (MajorRadius + MinorRadius * Cos(V)) *
		//! (cos (U) * XDir + sin (U) * YDir)
		//! where Loc is the origin of the placement plane (XAxis, YAxis)
		//! XDir is the direction of the XAxis and YDir the direction of
		//! the YAxis and ZDir the direction of the ZAxis.
		void D0(Standard_Real U, Standard_Real V, xgp_Pnt^ P) Standard_OVERRIDE;


		//! Computes the current point and the first derivatives in
		//! the directions U and V.
		void D1(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V) Standard_OVERRIDE;


		//! Computes the current point, the first and the second derivatives
		//! in the directions U and V.
		void D2(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV) Standard_OVERRIDE;


		//! Computes the current point, the first,the second and the
		//! third derivatives in the directions U and V.
		void D3(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV, xgp_Vec^ D3U, xgp_Vec^ D3V, xgp_Vec^ D3UUV, xgp_Vec^ D3UVV) Standard_OVERRIDE;


		//! Computes the derivative of order Nu in the direction u and
		//! Nv in the direction v.
		//! Raised if Nu + Nv < 1 or Nu < 0 or Nv < 0.
		xgp_Vec^ DN(Standard_Real U, Standard_Real V, Standard_Integer Nu, Standard_Integer Nv) Standard_OVERRIDE;

		//! Applies the transformation T to this torus.
		void Transform(xgp_Trsf^ T) Standard_OVERRIDE;

		//! Creates a new object which is a copy of this torus.
		XGeom_Geometry^ Copy() Standard_OVERRIDE;

		//! DEFINE_STANDARD_RTTIEXT(Geom_ToroidalSurface, Geom_ElementarySurface)
		virtual property Handle(Standard_Transient) IHandle {
			Handle(Standard_Transient) get() Standard_OVERRIDE {
				return NativeHandle();
			}
			void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
				NativeHandle() = Handle(Geom_ToroidalSurface)::DownCast(handle);
			}
		};

	private:
		NCollection_Haft<Handle(Geom_ToroidalSurface)> NativeHandle;
	};
}
#endif // _XGeom_ToroidalSurface_HeaderFile
