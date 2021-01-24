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

#ifndef _XGeom_SphericalSurface_HeaderFile
#define _XGeom_SphericalSurface_HeaderFile
#pragma once
#include <XGeom_ElementarySurface.h>
#include <Geom_SphericalSurface.hxx>
#include <xgp_Ax3.h>
#include <xgp_Sphere.h>
#include <xgp_Pnt.h>
#include <xgp_Trsf.h>
#include <xgp_Vec.h>
#include <XGeom_Curve.h>
#include <XGeom_Geometry.h>


#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <Standard_Real.hxx>
#include <Geom_ElementarySurface.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_Integer.hxx>
class Standard_ConstructionError;
class Standard_RangeError;
class gp_Ax3;
class gp_Sphere;
class Geom_Curve;
class gp_Pnt;
class gp_Vec;
class gp_Trsf;
class Geom_Geometry;
class Geom_SphericalSurface;
//DEFINE_STANDARD_HANDLE(Geom_SphericalSurface, Geom_ElementarySurface)

using namespace TKMath;
namespace TKG3d {
	ref class TKMath::xgp_Ax3;
	ref class TKMath::xgp_Sphere;
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Trsf;
	ref class TKMath::xgp_Vec;
	ref class XGeom_Curve;
	ref class XGeom_Geometry;
	//! Describes a sphere.
	//! A sphere is defined by its radius, and is positioned in
	//! space by a coordinate system (a gp_Ax3 object), the
	//! origin of which is the center of the sphere.
	//! This coordinate system is the "local coordinate
	//! system" of the sphere. The following apply:
	//! - Rotation around its "main Axis", in the trigonometric
	//! sense given by the "X Direction" and the "Y
	//! Direction", defines the u parametric direction.
	//! - Its "X Axis" gives the origin for the u parameter.
	//! - The "reference meridian" of the sphere is a
	//! half-circle, of radius equal to the radius of the
	//! sphere. It is located in the plane defined by the
	//! origin, "X Direction" and "main Direction", centered
	//! on the origin, and positioned on the positive side of the "X Axis".
	//! - Rotation around the "Y Axis" gives the v parameter
	//! on the reference meridian.
	//! - The "X Axis" gives the origin of the v parameter on
	//! the reference meridian.
	//! - The v parametric direction is oriented by the "main
	//! Direction", i.e. when v increases, the Z coordinate
	//! increases. (This implies that the "Y Direction"
	//! orients the reference meridian only when the local
	//! coordinate system is indirect.)
	//! - The u isoparametric curve is a half-circle obtained
	//! by rotating the reference meridian of the sphere
	//! through an angle u around the "main Axis", in the
	//! trigonometric sense defined by the "X Direction"
	//! and the "Y Direction".
	//! The parametric equation of the sphere is:
	//! P(u,v) = O + R*cos(v)*(cos(u)*XDir + sin(u)*YDir)+R*sin(v)*ZDir
	//! where:
	//! - O, XDir, YDir and ZDir are respectively the
	//! origin, the "X Direction", the "Y Direction" and the "Z
	//! Direction" of its local coordinate system, and
	//! - R is the radius of the sphere.
	//! The parametric range of the two parameters is:
	//! - [ 0, 2.*Pi ] for u, and
	//! - [ - Pi/2., + Pi/2. ] for v.
	public ref class XGeom_SphericalSurface : public XGeom_ElementarySurface
	{

	public:

		//!
		XGeom_SphericalSurface(void);

		//! 
		XGeom_SphericalSurface(Handle(Geom_SphericalSurface) pos);

		//!
		~XGeom_SphericalSurface();

		!XGeom_SphericalSurface() { IHandle = NULL; };

		void SetSphericalSurfaceHandle(Handle(Geom_SphericalSurface) handle);

		//! 
		virtual Handle(Geom_SphericalSurface) GetSphericalSurface();

		//! 
		virtual Handle(Geom_ElementarySurface) GetElementarySurface() Standard_OVERRIDE;

		//!
		virtual Handle(Geom_Surface) GetSurface() Standard_OVERRIDE;

		//!
		virtual Handle(Geom_Geometry) GetGeometry() Standard_OVERRIDE;

		//! A3 is the local coordinate system of the surface.
		//! At the creation the parametrization of the surface is defined
		//! such as the normal Vector (N = D1U ^ D1V) is directed away from
		//! the center of the sphere.
		//! The direction of increasing parametric value V is defined by the
		//! rotation around the "YDirection" of A2 in the trigonometric sense
		//! and the orientation of increasing parametric value U is defined
		//! by the rotation around the main direction of A2 in the
		//! trigonometric sense.
		//! Warnings :
		//! It is not forbidden to create a spherical surface with
		//! Radius = 0.0
		//! Raised if Radius < 0.0.
		XGeom_SphericalSurface(xgp_Ax3^ A3, Standard_Real Radius);


		//! Creates a SphericalSurface from a non persistent Sphere from
		//! package gp.
		XGeom_SphericalSurface(xgp_Sphere^ S);

		//! Assigns the value R to the radius of this sphere.
		//! Exceptions Standard_ConstructionError if R is less than 0.0.
		void SetRadius(Standard_Real R);

		//! Converts the gp_Sphere S into this sphere.
		void SetSphere(xgp_Sphere^ S);

		//! Returns a non persistent sphere with the same geometric
		//! properties as <me>.
		xgp_Sphere^ Sphere();

		//! Computes the u parameter on the modified
		//! surface, when reversing its u  parametric
		//! direction, for any point of u parameter U on this sphere.
		//! In the case of a sphere, these functions returns 2.PI - U.
		Standard_Real UReversedParameter(Standard_Real U) Standard_OVERRIDE;

		//! Computes the v parameter on the modified
		//! surface, when reversing its v parametric
		//! direction, for any point of v parameter V on this sphere.
		//! In the case of a sphere, these functions returns   -U.
		Standard_Real VReversedParameter(Standard_Real V) Standard_OVERRIDE;

		//! Computes the aera of the spherical surface.
		Standard_Real Area();

		//! Returns the parametric bounds U1, U2, V1 and V2 of this sphere.
		//! For a sphere: U1 = 0, U2 = 2*PI, V1 = -PI/2, V2 = PI/2.
		void Bounds(Standard_Real% U1, Standard_Real% U2, Standard_Real% V1, Standard_Real% V2) Standard_OVERRIDE;

		//! Returns the coefficients of the implicit equation of the
		//! quadric in the absolute cartesian coordinates system :
		//! These coefficients are normalized.
		//! A1.X**2 + A2.Y**2 + A3.Z**2 + 2.(B1.X.Y + B2.X.Z + B3.Y.Z) +
		//! 2.(C1.X + C2.Y + C3.Z) + D = 0.0
		void Coefficients(Standard_Real% A1, Standard_Real% A2, Standard_Real% A3, Standard_Real% B1, Standard_Real% B2, Standard_Real% B3, Standard_Real% C1, Standard_Real% C2, Standard_Real% C3, Standard_Real% D);

		//! Computes the coefficients of the implicit equation of
		//! this quadric in the absolute Cartesian coordinate system:
		//! A1.X**2 + A2.Y**2 + A3.Z**2 + 2.(B1.X.Y + B2.X.Z + B3.Y.Z) +
		//! 2.(C1.X + C2.Y + C3.Z) + D = 0.0
		//! An implicit normalization is applied (i.e. A1 = A2 = 1.
		//! in the local coordinate system of this sphere).
		Standard_Real Radius();

		//! Computes the volume of the spherical surface.
		Standard_Real Volume();

		//! Returns True.
		Standard_Boolean IsUClosed() Standard_OVERRIDE;

		//! Returns False.
		Standard_Boolean IsVClosed() Standard_OVERRIDE;

		//! Returns True.
		Standard_Boolean IsUPeriodic() Standard_OVERRIDE;

		//! Returns False.
		Standard_Boolean IsVPeriodic() Standard_OVERRIDE;

		//! Computes the U isoparametric curve.
		//! The U isoparametric curves of the surface are defined by the
		//! section of the spherical surface with plane obtained by rotation
		//! of the plane (Location, XAxis, ZAxis) around ZAxis. This plane
		//! defines the origin of parametrization u.
		//! For a SphericalSurface the UIso curve is a Circle.
		//! Warnings : The radius of this circle can be zero.
		XGeom_Curve^ UIso(Standard_Real U) Standard_OVERRIDE;

		//! Computes the V isoparametric curve.
		//! The V isoparametric curves of the surface  are defined by
		//! the section of the spherical surface with plane parallel to the
		//! plane (Location, XAxis, YAxis). This plane defines the origin of
		//! parametrization V.
		//! Be careful if  V is close to PI/2 or 3*PI/2 the radius of the
		//! circle becomes tiny. It is not forbidden in this toolkit to
		//! create circle with radius = 0.0
		//! For a SphericalSurface the VIso curve is a Circle.
		//! Warnings : The radius of this circle can be zero.
		XGeom_Curve^ VIso(Standard_Real V) Standard_OVERRIDE;


		//! Computes the  point P (U, V) on the surface.
		//! P (U, V) = Loc + Radius * Sin (V) * Zdir +
		//! Radius * Cos (V) * (cos (U) * XDir + sin (U) * YDir)
		//! where Loc is the origin of the placement plane (XAxis, YAxis)
		//! XDir is the direction of the XAxis and YDir the direction of
		//! the YAxis and ZDir the direction of the ZAxis.
		void D0(Standard_Real U, Standard_Real V, xgp_Pnt^ P) Standard_OVERRIDE;


		//! Computes the current point and the first derivatives in the
		//! directions U and V.
		void D1(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V) Standard_OVERRIDE;


		//! Computes the current point, the first and the second derivatives
		//! in the directions U and V.
		void D2(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV) Standard_OVERRIDE;


		//! Computes the current point, the first,the second and the third
		//! derivatives in the directions U and V.
		void D3(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV, xgp_Vec^ D3U, xgp_Vec^ D3V, xgp_Vec^ D3UUV, xgp_Vec^ D3UVV) Standard_OVERRIDE;


		//! Computes the derivative of order Nu in the direction u
		//! and Nv in the direction v.
		//! Raised if Nu + Nv < 1 or Nu < 0 or Nv < 0.
		xgp_Vec^ DN(Standard_Real U, Standard_Real V, Standard_Integer Nu, Standard_Integer Nv) Standard_OVERRIDE;

		//! Applies the transformation T to this sphere.
		void Transform(xgp_Trsf^ T) Standard_OVERRIDE;

		//! Creates a new object which is a copy of this sphere.
		XGeom_Geometry^ Copy() Standard_OVERRIDE;

		//! DEFINE_STANDARD_RTTIEXT(Geom_SphericalSurface, Geom_ElementarySurface)

		virtual property Handle(Standard_Transient) IHandle {
			Handle(Standard_Transient) get() Standard_OVERRIDE {
				return NativeHandle();
			}
			void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
				//NativeHandle() = Handle(Geom_SphericalSurface)::DownCast(handle);
				if (!handle.IsNull())
					NativeHandle() = Handle(Geom_SphericalSurface)::DownCast(handle);
				else if (!NativeHandle().IsNull())
					NativeHandle() = NULL;
			}
		};

	private:
		NCollection_Haft<Handle(Geom_SphericalSurface)> NativeHandle;
	};
}
#endif // _XGeom_SphericalSurface_HeaderFile
