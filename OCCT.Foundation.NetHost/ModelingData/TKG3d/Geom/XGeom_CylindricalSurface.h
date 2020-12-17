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

#ifndef _XGeom_CylindricalSurface_HeaderFile
#define _XGeom_CylindricalSurface_HeaderFile
#pragma once
#include <XGeom_ElementarySurface.h>
#include <Geom_CylindricalSurface.hxx>
#include <xgp_Cylinder.h>
#include <xgp_Ax3.h>
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
class gp_Cylinder;
class gp_Trsf;
class gp_GTrsf2d;
class Geom_Curve;
class gp_Pnt;
class gp_Vec;
class Geom_Geometry;
class Geom_CylindricalSurface;
//DEFINE_STANDARD_HANDLE(Geom_CylindricalSurface, Geom_ElementarySurface)

using namespace TKMath;
namespace TKG3d {
	ref class TKMath::xgp_Ax3;
	ref class TKMath::xgp_Cylinder;
	ref class TKMath::xgp_Trsf;
	ref class TKMath::xgp_GTrsf2d;
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Vec;
	ref class TKG3d::XGeom_Curve;
	ref class TKG3d::XGeom_Geometry;
	//! This class defines the infinite cylindrical surface.
	//!
	//! Every cylindrical surface is set by the following equation:
	//! S(U,V) = Location + R*cos(U)*XAxis + R*sin(U)*YAxis + V*ZAxis,
	//! where R is cylinder radius.
	//!
	//! The local coordinate system of the CylindricalSurface is defined
	//! with an axis placement (see class ElementarySurface).
	//!
	//! The "ZAxis" is the symmetry axis of the CylindricalSurface,
	//! it gives the direction of increasing parametric value V.
	//!
	//! The parametrization range is :
	//! U [0, 2*PI],  V ]- infinite, + infinite[
	//!
	//! The "XAxis" and the "YAxis" define the placement plane of the
	//! surface (Z = 0, and parametric value V = 0)  perpendicular to
	//! the symmetry axis. The "XAxis" defines the origin of the
	//! parameter U = 0.  The trigonometric sense gives the positive
	//! orientation for the parameter U.
	//!
	//! When you create a CylindricalSurface the U and V directions of
	//! parametrization are such that at each point of the surface the
	//! normal is oriented towards the "outside region".
	//!
	//! The methods UReverse VReverse change the orientation of the
	//! surface.
	public ref class XGeom_CylindricalSurface : public XGeom_ElementarySurface
	{

	public:
		/// <summary>
		/// 
		/// </summary>
		/// <param name=""></param>
		XGeom_CylindricalSurface(void);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="pos"></param>
		XGeom_CylindricalSurface(Handle(Geom_CylindricalSurface) pos);

		//!
		~XGeom_CylindricalSurface();

		/// <summary>
		/// 
		/// </summary>
		/// <param name="handle"></param>
		void SetCylindricalSurfaceHandle(Handle(Geom_CylindricalSurface) handle);

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		virtual Handle(Geom_CylindricalSurface) GetCylindricalSurface();

		//! 
		virtual Handle(Geom_ElementarySurface) GetElementarySurface() Standard_OVERRIDE;

		//!
		virtual Handle(Geom_Surface) GetSurface() Standard_OVERRIDE;

		//!
		virtual Handle(Geom_Geometry) GetGeometry() Standard_OVERRIDE;

		//! A3 defines the local coordinate system of the cylindrical surface.
		//! The "ZDirection" of A3 defines the direction of the surface's
		//! axis of symmetry.
		//! At the creation the parametrization of the surface is defined
		//! such that the normal Vector (N = D1U ^ D1V) is oriented towards
		//! the "outside region" of the surface.
		//! Warnings :
		//! It is not forbidden to create a cylindrical surface with
		//! Radius = 0.0
		//! Raised if Radius < 0.0
		XGeom_CylindricalSurface(xgp_Ax3^ A3, Standard_Real Radius);


		//! Creates a CylindricalSurface from a non transient Cylinder
		//! from package gp.
		XGeom_CylindricalSurface(xgp_Cylinder^ C);


		//! Set <me> so that <me> has the same geometric properties as C.
		void SetCylinder(xgp_Cylinder^ C);

		//! Changes the radius of the cylinder.
		//! Raised if R < 0.0
		void SetRadius(Standard_Real R);


		//! returns a non transient cylinder with the same geometric
		//! properties as <me>.
		xgp_Cylinder^ Cylinder();

		//! Return the  parameter on the  Ureversed surface for
		//! the point of parameter U on <me>.
		//! Return 2.PI - U.
		Standard_Real UReversedParameter(Standard_Real U) Standard_OVERRIDE;

		//! Return the  parameter on the  Vreversed surface for
		//! the point of parameter V on <me>.
		//! Return -V
		Standard_Real VReversedParameter(Standard_Real V) Standard_OVERRIDE;

		//! Computes the  parameters on the  transformed  surface for
		//! the transform of the point of parameters U,V on <me>.
		//! me->Transformed(T)->Value(U',V')
		//! is the same point as
		//! me->Value(U,V).Transformed(T)
		//! Where U',V' are the new values of U,V after calling
		//! me->TranformParameters(U,V,T)
		//! This methods multiplies V by T.ScaleFactor()
		virtual void TransformParameters(Standard_Real% U, Standard_Real% V, xgp_Trsf^ T) Standard_OVERRIDE;

		//! Returns a 2d transformation  used to find the  new
		//! parameters of a point on the transformed surface.
		//! me->Transformed(T)->Value(U',V')
		//! is the same point as
		//! me->Value(U,V).Transformed(T)
		//! Where U',V' are  obtained by transforming U,V with
		//! th 2d transformation returned by
		//! me->ParametricTransformation(T)
		//! This  methods  returns  a scale  centered  on  the
		//! U axis with T.ScaleFactor
		virtual xgp_GTrsf2d^ ParametricTransformation(xgp_Trsf^ T) Standard_OVERRIDE;


		//! The CylindricalSurface is infinite in the V direction so
		//! V1 = Realfirst, V2 = RealLast from package Standard.
		//! U1 = 0 and U2 = 2*PI.
		void Bounds(Standard_Real% U1, Standard_Real% U2, Standard_Real% V1, Standard_Real% V2) Standard_OVERRIDE;


		//! Returns the coefficients of the implicit equation of the quadric
		//! in the absolute cartesian coordinate system :
		//! These coefficients are normalized.
		//! A1.X**2 + A2.Y**2 + A3.Z**2 + 2.(B1.X.Y + B2.X.Z + B3.Y.Z) +
		//! 2.(C1.X + C2.Y + C3.Z) + D = 0.0
		void Coefficients(Standard_Real A1, Standard_Real A2, Standard_Real A3, Standard_Real B1, Standard_Real B2, Standard_Real B3, Standard_Real C1, Standard_Real C2, Standard_Real C3, Standard_Real D);

		//! Returns the radius of this cylinder.
		Standard_Real Radius();

		//! Returns True.
		Standard_Boolean IsUClosed() Standard_OVERRIDE;

		//! Returns False.
		Standard_Boolean IsVClosed() Standard_OVERRIDE;

		//! Returns True.
		Standard_Boolean IsUPeriodic() Standard_OVERRIDE;

		//! Returns False.
		Standard_Boolean IsVPeriodic() Standard_OVERRIDE;


		//! The UIso curve is a Line. The location point of this line is
		//! on the placement plane (XAxis, YAxis) of the surface.
		//! This line is parallel to the axis of symmetry of the surface.
		XGeom_Curve^ UIso(Standard_Real U) Standard_OVERRIDE;


		//! The VIso curve is a circle. The start point of this circle
		//! (U = 0) is defined with the "XAxis" of the surface.
		//! The center of the circle is on the symmetry axis.
		XGeom_Curve^ VIso(Standard_Real V) Standard_OVERRIDE;


		//! Computes the  point P (U, V) on the surface.
		//! P (U, V) = Loc + Radius * (cos (U) * XDir + sin (U) * YDir) +
		//! V * ZDir
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


		//! Computes the current point, the first, the second and the
		//! third   derivatives in the directions U and V.
		void D3(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV, xgp_Vec^ D3U, xgp_Vec^ D3V, xgp_Vec^ D3UUV, xgp_Vec^ D3UVV) Standard_OVERRIDE;


		//! Computes the derivative of order Nu in the direction u and Nv
		//! in the direction v.
		//! Raised if Nu + Nv < 1 or Nu < 0 or Nv < 0.
		xgp_Vec^ DN(Standard_Real U, Standard_Real V, Standard_Integer Nu, Standard_Integer Nv) Standard_OVERRIDE;

		//! Applies the transformation T to this cylinder.
		void Transform(xgp_Trsf^ T) Standard_OVERRIDE;

		//! Creates a new object which is a copy of this cylinder.
		XGeom_Geometry^ Copy() Standard_OVERRIDE;

		//! DEFINE_STANDARD_RTTIEXT(Geom_ElementarySurface, Geom_Surface)
		virtual property Handle(Standard_Transient) IHandle {
			Handle(Standard_Transient) get() Standard_OVERRIDE {
				return NativeHandle();
			}
			void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
				NativeHandle() = Handle(Geom_CylindricalSurface)::DownCast(handle);
			}
		};

	private:
		NCollection_Haft<Handle(Geom_CylindricalSurface)> NativeHandle;
	};
}
#endif // _XGeom_CylindricalSurface_HeaderFile
