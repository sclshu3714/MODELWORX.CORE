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

#ifndef _XGeom_Plane_HeaderFile
#define _XGeom_Plane_HeaderFile
#pragma once
#include <XGeom_ElementarySurface.h>
#include <Geom_Plane.hxx>
#include <xgp_Ax3.h>
#include <xgp_Pln.h>
#include <xgp_Pnt.h>
#include <xgp_Dir.h>
#include <xgp_Trsf.h>
#include <xgp_GTrsf2d.h>
#include <xgp_Vec.h>
#include <XGeom_Curve.h>
#include <XGeom_Geometry.h>

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <Geom_ElementarySurface.hxx>
#include <Standard_Real.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_Integer.hxx>
class Standard_ConstructionError;
class Standard_RangeError;
class gp_Ax3;
class gp_Pln;
class gp_Pnt;
class gp_Dir;
class gp_Trsf;
class gp_GTrsf2d;
class gp_Vec;
class Geom_Curve;
class Geom_Geometry;
class Geom_Plane;
//DEFINE_STANDARD_HANDLE(Geom_Plane, Geom_ElementarySurface)

using namespace TKMath;
namespace TKG3d {
	ref class TKMath::xgp_Ax3;
	ref class TKMath::xgp_Pln;
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Dir;
	ref class TKMath::xgp_Trsf;
	ref class TKMath::xgp_GTrsf2d;
	ref class TKMath::xgp_Vec;
	ref class XGeom_Curve;
	ref class XGeom_Geometry;
	//! Describes a plane in 3D space.
	//! A plane is positioned in space by a coordinate system
	//! (a gp_Ax3 object) such that the plane is defined by
	//! the origin, "X Direction" and "Y Direction" of this
	//! coordinate system.
	//! This coordinate system is the "local coordinate
	//! system" of the plane. The following apply:
	//! - Its "X Direction" and "Y Direction" are respectively
	//! the u and v parametric directions of the plane.
	//! - Its origin is the origin of the u and v parameters
	//! (also called the "origin" of the plane).
	//! - Its "main Direction" is a vector normal to the plane.
	//! This normal vector gives the orientation of the
	//! plane only if the local coordinate system is "direct".
	//! (The orientation of the plane is always defined by
	//! the "X Direction" and the "Y Direction" of its local
	//! coordinate system.)
	//! The parametric equation of the plane is:
	//! P(u, v) = O + u*XDir + v*YDir
	//! where O, XDir and YDir are respectively the
	//! origin, the "X Direction" and the "Y Direction" of the
	//! local coordinate system of the plane.
	//! The parametric range of the two parameters u and v
	//! is ] -infinity, +infinity [.
	public ref class XGeom_Plane : public XGeom_ElementarySurface
	{

	public:

		//!
		XGeom_Plane(void);

		//! 
		XGeom_Plane(Handle(Geom_Plane) pos);

		//!
		~XGeom_Plane();

		!XGeom_Plane() { IHandle = NULL; };

		void SetPlaneHandle(Handle(Geom_Plane) handle);

		//! 
		virtual Handle(Geom_Plane) GetPlane();

		//! 
		virtual Handle(Geom_ElementarySurface) GetElementarySurface() Standard_OVERRIDE;

		//!
		virtual Handle(Geom_Surface) GetSurface() Standard_OVERRIDE;

		//!
		virtual Handle(Geom_Geometry) GetGeometry() Standard_OVERRIDE;

		//! Creates a plane located in 3D space with an axis placement
		//! three axis.  The "ZDirection" of "A3" is the direction normal
		//! to the plane.  The "Location" point of "A3" is the origin of
		//! the plane. The "XDirection" and "YDirection" of "A3" define
		//! the directions of the U isoparametric and V isoparametric
		//! curves.
		XGeom_Plane(xgp_Ax3^ A3);


		//! Creates a plane from a non transient plane from package gp.
		XGeom_Plane(xgp_Pln^ Pl);


		//! P is the "Location" point or origin of the plane.
		//! V is the direction normal to the plane.
		XGeom_Plane(xgp_Pnt^ P, xgp_Dir^ V);


		//! Creates a plane from its cartesian equation :
		//! Ax + By + Cz + D = 0.0
		//!
		//! Raised if Sqrt (A*A + B*B + C*C) <= Resolution from gp
		XGeom_Plane(Standard_Real A, Standard_Real B, Standard_Real C, Standard_Real D);


		//! Set <me> so that <me> has the same geometric properties as Pl.
		void SetPln(xgp_Pln^ Pl);

		//! Converts this plane into a gp_Pln plane.
		xgp_Pln^ Pln();


		//! Changes the orientation of this plane in the u (or v)
		//! parametric direction. The bounds of the plane are not
		//! changed but the given parametric direction is
		//! reversed. Hence the orientation of the surface is reversed.
		virtual void UReverse() Standard_OVERRIDE;

		//! Computes the u  parameter on the modified
		//! plane, produced when reversing the u
		//! parametric of this plane, for any point of u parameter U  on this plane.
		//! In the case of a plane, these methods return - -U.
		Standard_Real UReversedParameter(Standard_Real U) Standard_OVERRIDE;


		//! Changes the orientation of this plane in the u (or v)
		//! parametric direction. The bounds of the plane are not
		//! changed but the given parametric direction is
		//! reversed. Hence the orientation of the surface is reversed.
		virtual void VReverse() Standard_OVERRIDE;

		//! Computes the v parameter on the modified
		//! plane, produced when reversing the  v
		//! parametric of this plane, for any point of v parameter V on this plane.
		//! In the case of a plane, these methods return -V.
		Standard_Real VReversedParameter(Standard_Real V) Standard_OVERRIDE;

		//! Computes the  parameters on the  transformed  surface for
		//! the transform of the point of parameters U,V on <me>.
		//! me->Transformed(T)->Value(U',V')
		//! is the same point as
		//! me->Value(U,V).Transformed(T)
		//! Where U',V' are the new values of U,V after calling
		//! me->TranformParameters(U,V,T)
		//! This methods multiplies U and V by T.ScaleFactor()
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
		//! origin with T.ScaleFactor
		virtual xgp_GTrsf2d^ ParametricTransformation(xgp_Trsf^ T) Standard_OVERRIDE;

		//! Returns the parametric bounds U1, U2, V1 and V2 of this plane.
		//! Because a plane is an infinite surface, the following is always true:
		//! - U1 = V1 =   Standard_Real::RealFirst()
		//! - U2 = V2 =   Standard_Real::RealLast().
		void Bounds(Standard_Real% U1, Standard_Real% U2, Standard_Real% V1, Standard_Real% V2) Standard_OVERRIDE;


		//! Computes the normalized coefficients of the plane's
		//! cartesian equation : Ax + By + Cz + D = 0.0
		void Coefficients(Standard_Real% A, Standard_Real% B, Standard_Real% C, Standard_Real% D);

		//! return False
		Standard_Boolean IsUClosed() Standard_OVERRIDE;

		//! return False
		Standard_Boolean IsVClosed() Standard_OVERRIDE;

		//! return False.
		Standard_Boolean IsUPeriodic() Standard_OVERRIDE;

		//! return False.
		Standard_Boolean IsVPeriodic() Standard_OVERRIDE;


		//! Computes the U isoparametric curve.
		//! This is a Line parallel to the YAxis of the plane.
		XGeom_Curve^ UIso(Standard_Real U) Standard_OVERRIDE;


		//! Computes the V isoparametric curve.
		//! This is a Line parallel to the XAxis of the plane.
		XGeom_Curve^ VIso(Standard_Real V) Standard_OVERRIDE;


		//! Computes the point P (U, V) on <me>.
		//! P = O + U * XDir + V * YDir.
		//! where O is the "Location" point of the plane, XDir the
		//! "XDirection" and YDir the "YDirection" of the plane's local
		//! coordinate system.
		void D0(Standard_Real U, Standard_Real V, xgp_Pnt^ P) Standard_OVERRIDE;


		//! Computes the current point and the first derivatives in the
		//! directions U and V.
		void D1(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V) Standard_OVERRIDE;


		//! Computes the current point, the first and the second
		//! derivatives in the directions U and V.
		void D2(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV) Standard_OVERRIDE;


		//! Computes the current point, the first,the second and the
		//! third derivatives in the directions U and V.
		void D3(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV, xgp_Vec^ D3U, xgp_Vec^ D3V, xgp_Vec^ D3UUV, xgp_Vec^ D3UVV) Standard_OVERRIDE;


		//! Computes the derivative of order Nu in the direction u
		//! and Nv in the direction v.
		//! Raised if Nu + Nv < 1 or Nu < 0 or Nv < 0.
		xgp_Vec^ DN(Standard_Real U, Standard_Real V, Standard_Integer Nu, Standard_Integer Nv) Standard_OVERRIDE;

		//! Applies the transformation T to this plane.
		void Transform(xgp_Trsf^ T) Standard_OVERRIDE;

		//! Creates a new object which is a copy of this plane.
		XGeom_Geometry^ Copy() Standard_OVERRIDE;




		//! DEFINE_STANDARD_RTTIEXT(Geom_Plane, Geom_ElementarySurface)
		virtual property Handle(Standard_Transient) IHandle {
			Handle(Standard_Transient) get() Standard_OVERRIDE {
				return NativeHandle();
			}
			void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
				//NativeHandle() = Handle(Geom_Plane)::DownCast(handle);
				if (!handle.IsNull())
					NativeHandle() = Handle(Geom_Plane)::DownCast(handle);
				else if (!NativeHandle().IsNull())
					NativeHandle() = NULL;
			}
		};

	private:
		NCollection_Haft<Handle(Geom_Plane)> NativeHandle;
	};
}
#endif // _XGeom_Plane_HeaderFile
