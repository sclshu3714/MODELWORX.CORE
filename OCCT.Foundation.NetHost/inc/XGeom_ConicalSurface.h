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

#ifndef _XGeom_ConicalSurface_HeaderFile
#define _XGeom_ConicalSurface_HeaderFile
#pragma once
#include <XGeom_ElementarySurface.h>
#include <Geom_ConicalSurface.hxx>
#include <xgp_Ax3.h>
#include <xgp_Cone.h>
#include <xgp_Trsf.h>
#include <xgp_GTrsf2d.h>
#include <xgp_Pnt.h>
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
class gp_Cone;
class gp_Trsf;
class gp_GTrsf2d;
class gp_Pnt;
class gp_Vec;
class Geom_Curve;
class Geom_Geometry;
class Geom_ConicalSurface;
//DEFINE_STANDARD_HANDLE(Geom_ConicalSurface, Geom_ElementarySurface)

using namespace TKMath;
namespace TKG3d {
	ref class TKMath::xgp_Ax3;
	ref class TKMath::xgp_Cone;
	ref class TKMath::xgp_Trsf;
	ref class TKMath::xgp_GTrsf2d;
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Vec;
	ref class TKG3d::XGeom_Curve;
	ref class TKG3d::XGeom_Geometry;
	//! Describes a cone.
	//! A cone is defined by the half-angle (can be negative) at its apex, and
	//! is positioned in space by a coordinate system (a
	//! gp_Ax3 object) and a reference radius as follows:
	//! - The "main Axis" of the coordinate system is the
	//! axis of revolution of the cone.
	//! - The plane defined by the origin, the "X Direction"
	//! and the "Y Direction" of the coordinate system is
	//! the reference plane of the cone. The intersection
	//! of the cone with this reference plane is a circle of
	//! radius equal to the reference radius.
	//! - The apex of the cone is on the negative side of
	//! the "main Axis" of the coordinate system if the
	//! half-angle is positive, and on the positive side if
	//! the half-angle is negative.
	//! This coordinate system is the "local coordinate
	//! system" of the cone. The following apply:
	//! - Rotation around its "main Axis", in the
	//! trigonometric sense given by the "X Direction"
	//! and the "Y Direction", defines the u parametric direction.
	//! - Its "X Axis" gives the origin for the u parameter.
	//! - Its "main Direction" is the v parametric direction of the cone.
	//! - Its origin is the origin of the v parameter.
	//! The parametric range of the two parameters is:
	//! - [ 0, 2.*Pi ] for u, and - ] -infinity, +infinity [ for v
	//! The parametric equation of the cone is:  P(u, v) =
	//! O + (R + v*sin(Ang)) * (cos(u)*XDir + sin(u)*YDir) + v*cos(Ang)*ZDir where:
	//! - O, XDir, YDir and ZDir are respectively
	//! the origin, the "X Direction", the "Y Direction" and
	//! the "Z Direction" of the cone's local coordinate system,
	//! - Ang is the half-angle at the apex of the cone,   and
	//! - R is the reference radius.
	public ref class XGeom_ConicalSurface : public XGeom_ElementarySurface
	{

	public:

		/// <summary>
		/// 
		/// </summary>
		/// <param name=""></param>
		XGeom_ConicalSurface(void);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="pos"></param>
		XGeom_ConicalSurface(Handle(Geom_ConicalSurface) pos);

		
		~XGeom_ConicalSurface();

		/// <summary>
		/// 
		/// </summary>
		/// <param name="handle"></param>
		void SetConicalSurfaceHandle(Handle(Geom_ConicalSurface) handle);

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		virtual Handle(Geom_ConicalSurface) GetConicalSurface();

		//! 
		virtual Handle(Geom_ElementarySurface) GetElementarySurface() Standard_OVERRIDE;

		//!
		virtual Handle(Geom_Surface) GetSurface() Standard_OVERRIDE;

		//!
		virtual Handle(Geom_Geometry) GetGeometry() Standard_OVERRIDE;

		//! A3 defines the local coordinate system of the conical surface.
		//! Ang is the conical surface semi-angle. Its absolute value is in range
		//! ]0, PI/2[.
		//! Radius is the radius of the circle Viso in the placement plane
		//! of the conical surface defined with "XAxis" and "YAxis".
		//! The "ZDirection" of A3 defines the direction of the surface's
		//! axis of symmetry.
		//! If the location point of A3 is the apex of the surface
		//! Radius = 0 .
		//! At the creation the parametrization of the surface is defined
		//! such that the normal Vector (N = D1U ^ D1V) is oriented towards
		//! the "outside region" of the surface.
		//!
		//! Raised if Radius < 0.0 or Abs(Ang) < Resolution from gp or
		//! Abs(Ang) >= PI/2 - Resolution
		XGeom_ConicalSurface(xgp_Ax3^ A3, Standard_Real Ang, Standard_Real Radius);


		//! Creates a ConicalSurface from a non transient Cone from
		//! package gp.
		XGeom_ConicalSurface(xgp_Cone^ C);


		//! Set <me> so that <me> has the same geometric properties as C.
		void SetCone(xgp_Cone^ C);


		//! Changes the radius of the conical surface in the placement
		//! plane (Z = 0, V = 0).  The local coordinate system is not
		//! modified.
		//! Raised if R < 0.0
		void SetRadius(Standard_Real R);


		//! Changes the semi angle of the conical surface.
		//! Semi-angle can be negative. Its absolute value
		//! Abs(Ang) is in range ]0,PI/2[.
		//! Raises ConstructionError if Abs(Ang) < Resolution from gp or
		//! Abs(Ang) >= PI/2 - Resolution
		void SetSemiAngle(Standard_Real Ang);


		//! returns a non transient cone with the same geometric properties
		//! as <me>.
		xgp_Cone^ Cone();

		//! return 2.PI - U.
		Standard_Real UReversedParameter(Standard_Real U) Standard_OVERRIDE;

		//! Computes the u (or v) parameter on the modified
		//! surface, when reversing its u (or v) parametric
		//! direction, for any point of u parameter U (or of v
		//! parameter V) on this cone.
		//! In the case of a cone, these functions return respectively:
		//! - 2.*Pi - U, -V.
		Standard_Real VReversedParameter(Standard_Real V) Standard_OVERRIDE;

		//! Changes the orientation of this cone in the v
		//! parametric direction. The bounds of the surface are
		//! not changed but the v parametric direction is reversed.
		//! As a consequence, for a cone:
		//! - the "main Direction" of the local coordinate system
		//! is reversed, and
		//! - the half-angle at the apex is inverted.
		virtual void VReverse() Standard_OVERRIDE;

		//! Computes the  parameters on the  transformed  surface for
		//! the transform of the point of parameters U,V on <me>.
		//!
		//! me->Transformed(T)->Value(U',V')
		//!
		//! is the same point as
		//!
		//! me->Value(U,V).Transformed(T)
		//!
		//! Where U',V' are the new values of U,V after calling
		//!
		//! me->TranformParameters(U,V,T)
		//!
		//! This methods multiplies V by T.ScaleFactor()
		virtual void TransformParameters(Standard_Real% U, Standard_Real% V, xgp_Trsf^ T) Standard_OVERRIDE;

		//! Returns a 2d transformation  used to find the  new
		//! parameters of a point on the transformed surface.
		//!
		//! me->Transformed(T)->Value(U',V')
		//!
		//! is the same point as
		//!
		//! me->Value(U,V).Transformed(T)
		//!
		//! Where U',V' are  obtained by transforming U,V with
		//! th 2d transformation returned by
		//!
		//! me->ParametricTransformation(T)
		//!
		//! This  methods  returns  a scale  centered  on  the
		//! U axis with T.ScaleFactor
		virtual xgp_GTrsf2d^ ParametricTransformation(xgp_Trsf^ T) Standard_OVERRIDE;

		//! Computes the apex of this cone. It is on the negative
		//! side of the axis of revolution of this cone if the
		//! half-angle at the apex is positive, and on the positive
		//! side of the "main Axis" if the half-angle is negative.
		xgp_Pnt^ Apex();


		//! The conical surface is infinite in the V direction so
		//! V1 = Realfirst from Standard and V2 = RealLast.
		//! U1 = 0 and U2 = 2*PI.
		void Bounds(Standard_Real% U1, Standard_Real% U2, Standard_Real% V1, Standard_Real% V2) Standard_OVERRIDE;


		//! Returns the coefficients of the implicit equation of the
		//! quadric in the absolute cartesian coordinate system :
		//! These coefficients are normalized.
		//! A1.X**2 + A2.Y**2 + A3.Z**2 + 2.(B1.X.Y + B2.X.Z + B3.Y.Z) +
		//! 2.(C1.X + C2.Y + C3.Z) + D = 0.0
		void Coefficients(Standard_Real A1, Standard_Real A2, Standard_Real A3, Standard_Real B1, Standard_Real B2, Standard_Real B3, Standard_Real C1, Standard_Real C2, Standard_Real C3, Standard_Real D);

		//! Returns the reference radius of this cone.
		//! The reference radius is the radius of the circle formed
		//! by the intersection of this cone and its reference
		//! plane (i.e. the plane defined by the origin, "X
		//! Direction" and "Y Direction" of the local coordinate
		//! system of this cone).
		//! If the apex of this cone is on the origin of the local
		//! coordinate system of this cone, the returned value is 0.
		Standard_Real RefRadius();


		//! Returns the semi-angle at the apex of this cone.
		//! Attention! Semi-angle can be negative.
		Standard_Real SemiAngle();

		//! returns True.
		Standard_Boolean IsUClosed() Standard_OVERRIDE;

		//! returns False.
		Standard_Boolean IsVClosed() Standard_OVERRIDE;

		//! Returns True.
		Standard_Boolean IsUPeriodic() Standard_OVERRIDE;

		//! Returns False.
		Standard_Boolean IsVPeriodic() Standard_OVERRIDE;

		//! Builds the U isoparametric line of this cone. The
		//! origin of this line is on the reference plane of this
		//! cone (i.e. the plane defined by the origin, "X Direction"
		//! and "Y Direction" of the local coordinate system of this cone).
		XGeom_Curve^ UIso(Standard_Real U) Standard_OVERRIDE;

		//! Builds the V isoparametric circle of this cone. It is the
		//! circle on this cone, located in the plane of Z
		//! coordinate V*cos(Semi-Angle) in the local coordinate system of this
		//! cone. The "Axis" of this circle is the axis of revolution
		//! of this cone. Its starting point is defined by the "X
		//! Direction" of this cone.
		//! Warning
		//! If the V isoparametric circle is close to the apex of
		//! this cone, the radius of the circle becomes very small.
		//! It is possible to have a circle with radius equal to 0.0.
		XGeom_Curve^ VIso(Standard_Real V) Standard_OVERRIDE;


		//! Computes the  point P (U, V) on the surface.
		//! P (U, V) = Loc +
		//! (RefRadius + V * sin (Semi-Angle)) * (cos (U) * XDir + sin (U) * YDir) +
		//! V * cos (Semi-Angle) * ZDir
		//! where Loc is the origin of the placement plane (XAxis, YAxis)
		//! XDir is the direction of the XAxis and YDir the direction of
		//! the YAxis.
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

		//! Computes the derivative of order Nu in the u
		//! parametric direction, and Nv in the v parametric
		//! direction at the point of parameters (U, V) of this cone.
		//! Exceptions
		//! Standard_RangeError if:
		//! - Nu + Nv is less than 1,
		//! - Nu or Nv is negative.
		xgp_Vec^ DN(Standard_Real U, Standard_Real V, Standard_Integer Nu, Standard_Integer Nv) Standard_OVERRIDE;

		//! Applies the transformation T to this cone.
		void Transform(xgp_Trsf^ T) Standard_OVERRIDE;

		//! Creates a new object which is a copy of this cone.
		XGeom_Geometry^ Copy() Standard_OVERRIDE;




		//! DEFINE_STANDARD_RTTIEXT(Geom_ElementarySurface, Geom_Surface)
		virtual property Handle(Standard_Transient) IHandle {
			Handle(Standard_Transient) get() Standard_OVERRIDE {
				return NativeHandle();
			}
			void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
				NativeHandle() = Handle(Geom_ConicalSurface)::DownCast(handle);
			}
		};

	private:
		NCollection_Haft<Handle(Geom_ConicalSurface)> NativeHandle;
	};
}
#endif // _XGeom_ConicalSurface_HeaderFile
