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
//! Describes the common behavior of surfaces in 3D
//! space. The Geom package provides many
//! implementations of concrete derived surfaces, such as
//! planes, cylinders, cones, spheres and tori, surfaces of
//! linear extrusion, surfaces of revolution, Bezier and
//! BSpline surfaces, and so on.
//! The key characteristic of these surfaces is that they
//! are parameterized. Geom_Surface demonstrates:
//! - how to work with the parametric equation of a
//! surface to compute the point of parameters (u,
//! v), and, at this point, the 1st, 2nd ... Nth derivative,
//! - how to find global information about a surface in
//! each parametric direction (for example, level of
//! continuity, whether the surface is closed, its
//! periodicity, the bounds of the parameters and so on), and
//! - how the parameters change when geometric
//! transformations are applied to the surface, or the
//! orientation is modified.
//! Note that all surfaces must have a geometric
//! continuity, and any surface is at least "C0". Generally,
//! continuity is checked at construction time or when the
//! curve is edited. Where this is not the case, the
//! documentation makes this explicit.
//! Warning
//! The Geom package does not prevent the construction of
//! surfaces with null areas, or surfaces which self-intersect.

#ifndef _XGeom_Surface_HeaderFile
#define _XGeom_Surface_HeaderFile
#pragma once
#include "NCollection_Haft.h"
#include "Standard_RangeError.hxx"
#include "Standard_NoSuchObject.hxx"
#include "Standard_Type.hxx"
#include "Geom_UndefinedDerivative.hxx"	 
#include "Standard_ConstructionError.hxx"
#include "Geom_UndefinedValue.hxx"
#include "Geom_Surface.hxx"
#include "XGeom_Geometry.h"
#include "xgp_Pnt.h"
#include "xgp_Ax1.h"
#include "xgp_Ax2.h"
#include "xgp_Vec.h"
#include "xgp_Trsf.h"


using namespace TKMath;
namespace TKG3d
{
	class Standard_RangeError;
	class Standard_NoSuchObject;
	class Geom_UndefinedDerivative;
	class Geom_UndefinedValue;
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Ax1;
	ref class TKMath::xgp_Ax2;
	ref class TKMath::xgp_Vec;
	ref class TKMath::xgp_Trsf;
	ref class TKMath::xgp_GTrsf2d;
	public ref class XGeom_Surface : XGeom_Geometry
	{
	public:

		//!
		XGeom_Surface(void);

		//! 
		XGeom_Surface(Handle(Geom_Surface) pos);

		//!
		~XGeom_Surface();

		void SetSurfaceHandle(Handle(Geom_Surface) handle);

		//!
		Handle(Geom_Surface) GetSurface();

		//! Reverses the U direction of parametrization of <me>.
		//! The bounds of the surface are not modified.
		virtual void UReverse();


		//! Reverses the U direction of parametrization of <me>.
		//! The bounds of the surface are not modified.
		//! A copy of <me> is returned.
		Handle(Geom_Surface) UReversed();

		//! Returns the  parameter on the  Ureversed surface for
		//! the point of parameter U on <me>.
		//!
		//! me->UReversed()->Value(me->UReversedParameter(U),V)
		//!
		//! is the same point as
		//!
		//! me->Value(U,V)
		virtual Standard_Real^ UReversedParameter(Standard_Real U);


		//! Reverses the V direction of parametrization of <me>.
		//! The bounds of the surface are not modified.
		virtual void VReverse();


		//! Reverses the V direction of parametrization of <me>.
		//! The bounds of the surface are not modified.
		//! A copy of <me> is returned.
		Handle(Geom_Surface) VReversed();

		//! Returns the  parameter on the  Vreversed surface for
		//! the point of parameter V on <me>.
		//!
		//! me->VReversed()->Value(U,me->VReversedParameter(V))
		//!
		//! is the same point as
		//!
		//! me->Value(U,V)
		virtual Standard_Real^ VReversedParameter(Standard_Real V);

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
		//! This methods does not change <U> and <V>
		//!
		//! It  can be redefined.  For  example on  the Plane,
		//! Cylinder, Cone, Revolved and Extruded surfaces.
		virtual void TransformParameters(Standard_Real U, Standard_Real V, xgp_Trsf^ T);

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
		//! This methods returns an identity transformation
		//!
		//! It  can be redefined.  For  example on  the Plane,
		//! Cylinder, Cone, Revolved and Extruded surfaces.
		virtual xgp_GTrsf2d^ ParametricTransformation(xgp_Trsf^ T);

		//! Returns the parametric bounds U1, U2, V1 and V2 of this surface.
		//! If the surface is infinite, this function can return a value
		//! equal to Precision::Infinite: instead of Standard_Real::LastReal.
		virtual void Bounds(Standard_Real U1, Standard_Real U2, Standard_Real V1, Standard_Real V2);

		//! Checks whether this surface is closed in the u
		//! parametric direction.
		//! Returns true if, in the u parametric direction: taking
		//! uFirst and uLast as the parametric bounds in
		//! the u parametric direction, for each parameter v, the
		//! distance between the points P(uFirst, v) and
		//! P(uLast, v) is less than or equal to gp::Resolution().
		virtual Standard_Boolean^ IsUClosed();

		//! Checks whether this surface is closed in the u
		//! parametric direction.
		//! Returns true if, in the v parametric
		//! direction: taking vFirst and vLast as the
		//! parametric bounds in the v parametric direction, for
		//! each parameter u, the distance between the points
		//! P(u, vFirst) and P(u, vLast) is less than
		//! or equal to gp::Resolution().
		virtual Standard_Boolean^ IsVClosed();

		//! Checks if this surface is periodic in the u
		//! parametric direction. Returns true if:
		//! - this surface is closed in the u parametric direction, and
		//! - there is a constant T such that the distance
		//! between the points P (u, v) and P (u + T,
		//! v) (or the points P (u, v) and P (u, v +
		//! T)) is less than or equal to gp::Resolution().
		//! Note: T is the parametric period in the u parametric direction.
		virtual Standard_Boolean^ IsUPeriodic();

		//! Returns the period of this surface in the u
		//! parametric direction.
		//! raises if the surface is not uperiodic.
		virtual Standard_Real^ UPeriod();

		//! Checks if this surface is periodic in the v
		//! parametric direction. Returns true if:
		//! - this surface is closed in the v parametric direction, and
		//! - there is a constant T such that the distance
		//! between the points P (u, v) and P (u + T,
		//! v) (or the points P (u, v) and P (u, v +
		//! T)) is less than or equal to gp::Resolution().
		//! Note: T is the parametric period in the v parametric direction.
		virtual Standard_Boolean^ IsVPeriodic();

		//! Returns the period of this surface in the v parametric direction.
		//! raises if the surface is not vperiodic.
		virtual Standard_Real^ VPeriod();

		//! Computes the U isoparametric curve.
		virtual Handle(Geom_Curve) UIso(Standard_Real U);

		//! Computes the V isoparametric curve.
		virtual Handle(Geom_Curve) VIso(Standard_Real V);


		//! Returns the Global Continuity of the surface in direction U and V :
		//! C0 : only geometric continuity,
		//! C1 : continuity of the first derivative all along the surface,
		//! C2 : continuity of the second derivative all along the surface,
		//! C3 : continuity of the third derivative all along the surface,
		//! G1 : tangency continuity all along the surface,
		//! G2 : curvature continuity all along the surface,
		//! CN : the order of continuity is infinite.
		//! Example :
		//! If the surface is C1 in the V parametric direction and C2
		//! in the U parametric direction Shape = C1.
		virtual GeomAbs_Shape Continuity();

		//! Returns the order of continuity of the surface in the
		//! U parametric direction.
		//! Raised if N < 0.
		virtual Standard_Boolean^ IsCNu(Standard_Integer N);

		//! Returns the order of continuity of the surface in the
		//! V parametric direction.
		//! Raised if N < 0.
		virtual Standard_Boolean^ IsCNv(Standard_Integer N);

		//! Computes the point of parameter U,V on the surface.
		//!
		//! Raised only for an "OffsetSurface" if it is not possible to
		//! compute the current point.
		virtual void D0(Standard_Real U, Standard_Real V, xgp_Pnt^ P);


		//! Computes the point P and the first derivatives in the
		//! directions U and V at this point.
		//! Raised if the continuity of the surface is not C1.
		virtual void D1(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V);


		//! Computes the point P, the first and the second derivatives in
		//! the directions U and V at this point.
		//! Raised if the continuity of the surface is not C2.
		virtual void D2(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV);


		//! Computes the point P, the first,the second and the third
		//! derivatives in the directions U and V at this point.
		//! Raised if the continuity of the surface is not C2.
		virtual void D3(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV, xgp_Vec^ D3U, xgp_Vec^ D3V, xgp_Vec^ D3UUV, xgp_Vec^ D3UVV);

		//! ---Purpose ;
		//! Computes the derivative of order Nu in the direction U and Nv
		//! in the direction V at the point P(U, V).
		//!
		//! Raised if the continuity of the surface is not CNu in the U
		//! direction or not CNv in the V direction.
		//! Raised if Nu + Nv < 1 or Nu < 0 or Nv < 0.
		virtual xgp_Vec^ DN(Standard_Real U, Standard_Real V, Standard_Integer Nu, Standard_Integer Nv);


		//! Computes the point of parameter U on the surface.
		//!
		//! It is implemented with D0
		//!
		//! Raised only for an "OffsetSurface" if it is not possible to
		//! compute the current point.
		xgp_Pnt^ Value(Standard_Real U, Standard_Real V);
	
		virtual property Handle(Standard_Transient) IHandle {
			Handle(Standard_Transient) get() Standard_OVERRIDE {
				return NativeHandle();
			}
			void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
				NativeHandle() = Handle(Geom_Surface)::DownCast(handle);
			}
		};

	private:
		NCollection_Haft<Handle(Geom_Surface)> NativeHandle;
	};
}
#endif // _XGeom_Surface_HeaderFile