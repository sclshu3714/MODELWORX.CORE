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

#ifndef _XGeom_OffsetSurface_HeaderFile
#define _XGeom_OffsetSurface_HeaderFile
#pragma once
#include "NCollection_Haft.h"
#include "Geom_OffsetSurface.hxx"
#include "XGeom_Surface.h"
#include "xgp_Pnt.h"
#include "xgp_Vec.h"
#include "xgp_Trsf.h"
#include "xgp_GTrsf2d.h"
#include <XGeom_Geometry.h>
#include <XGeom_Curve.h>
#include <XGeom_BSplineSurface.h>
#include <XGeom_OsculatingSurface.h>

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <Standard_Real.hxx>
#include <Geom_OsculatingSurface.hxx>
#include <GeomAbs_Shape.hxx>
#include <Geom_Surface.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_Integer.hxx>
#include <GeomEvaluator_OffsetSurface.hxx>

class Standard_ConstructionError;
class Standard_RangeError;
class Standard_NoSuchObject;
class Geom_UndefinedDerivative;
class Geom_UndefinedValue;
class gp_Pnt;
class gp_Vec;
class gp_Trsf;
class gp_GTrsf2d;
class Geom_Curve;
class Geom_Surface;
class Geom_Geometry;
class Geom_OffsetSurface;
class Geom_BSplineSurface;

//DEFINE_STANDARD_HANDLE(Geom_OffsetSurface, Geom_Surface)
using namespace TKMath;
namespace TKG3d
{
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Vec;
	ref class TKMath::xgp_Trsf;
	ref class TKMath::xgp_GTrsf2d;
	ref class XGeom_Curve;
	ref class XGeom_Surface;
	ref class XGeom_Geometry;
	ref class XGeom_OffsetSurface;
	ref class XGeom_BSplineSurface;
	ref class XGeom_OsculatingSurface;
	//! Describes an offset surface in 3D space.
	//! An offset surface is defined by:
	//! - the basis surface to which it is parallel, and
	//! - the distance between the offset surface and its basis surface.
	//! A point on the offset surface is built by measuring the
	//! offset value along the normal vector at a point on the
	//! basis surface. This normal vector is given by the cross
	//! product D1u^D1v, where D1u and D1v are the
	//! vectors tangential to the basis surface in the u and v
	//! parametric directions at this point. The side of the
	//! basis surface on which the offset is measured
	//! depends on the sign of the offset value.
	//! A Geom_OffsetSurface surface can be
	//! self-intersecting, even if the basis surface does not
	//! self-intersect. The self-intersecting portions are not
	//! deleted at the time of construction.
	//! Warning
	//! There must be only one normal vector defined at any
	//! point on the basis surface. This must be verified by the
	//! user as no check is made at the time of construction
	//! to detect points with multiple possible normal
	//! directions (for example, the top of a conical surface).
	public ref class XGeom_OffsetSurface : public XGeom_Surface
	{

	public:

		//!
		XGeom_OffsetSurface(void);

		//! 
		XGeom_OffsetSurface(Handle(Geom_OffsetSurface) pos);

		//!
		~XGeom_OffsetSurface();

		!XGeom_OffsetSurface() { IHandle = NULL; };

		void SetOffsetSurfaceHandle(Handle(Geom_OffsetSurface) handle);

		//!
		virtual Handle(Geom_OffsetSurface) GetOffsetSurface();

		//!
		virtual Handle(Geom_Surface) GetSurface() Standard_OVERRIDE;

		//!
		virtual Handle(Geom_Geometry) GetGeometry() Standard_OVERRIDE;

		//! Constructs a surface offset from the basis surface
		//! S, where Offset is the distance between the offset
		//! surface and the basis surface at any point.
		//! A point on the offset surface is built by measuring
		//! the offset value along a normal vector at a point on
		//! S. This normal vector is given by the cross product
		//! D1u^D1v, where D1u and D1v are the vectors
		//! tangential to the basis surface in the u and v
		//! parametric directions at this point. The side of S on
		//! which the offset value is measured is indicated by
		//! this normal vector if Offset is positive, or is the
		//! inverse sense if Offset is negative.
		//! If isNotCheckC0 = TRUE checking if basis surface has C0-continuity
		//! is not made.
		//! Warnings :
		//! - The offset surface is built with a copy of the
		//! surface S. Therefore, when S is modified the
		//! offset surface is not modified.
		//! - No check is made at the time of construction to
		//! detect points on S with multiple possible normal directions.
		//! Raised if S is not at least C1.
		//! Warnings :
		//! No check is done to verify that a unique normal direction is
		//! defined at any point of the basis surface S.
		//! Standard_Boolean isNotCheckC0 = Standard_False
		XGeom_OffsetSurface(XGeom_Surface^ S, Standard_Real Offset, Standard_Boolean isNotCheckC0);

		//!Standard_Boolean isNotCheckC0 = Standard_False;
		XGeom_OffsetSurface(XGeom_Surface^ S, Standard_Real Offset) {
			Standard_Boolean isNotCheckC0 = Standard_False;
			XGeom_OffsetSurface(S, Offset, isNotCheckC0);
		};
		//! Raised if S is not at least C1.
		//! Warnings :
		//! No check is done to verify that a unique normal direction is
		//! defined at any point of the basis surface S.
		//! If isNotCheckC0 = TRUE checking if basis surface has C0-continuity
		//! is not made.
		//! Exceptions
		//! Standard_ConstructionError if the surface S is not
		//! at least "C1" continuous.
		//! Standard_Boolean isNotCheckC0 = Standard_False
		void SetBasisSurface(XGeom_Surface^ S, Standard_Boolean isNotCheckC0);

		//!Standard_Boolean isNotCheckC0 = Standard_False
		void SetBasisSurface(XGeom_Surface^ S) {
			Standard_Boolean isNotCheckC0 = Standard_False;
			SetBasisSurface(S, isNotCheckC0);
		};
		//! Changes this offset surface by assigning D as the offset value.
		void SetOffsetValue(Standard_Real D);

		//! Returns the offset value of this offset surface.
		Standard_Real Offset();

		//! Returns the basis surface of this offset surface.
		//! Note: The basis surface can be an offset surface.
		XGeom_Surface^ BasisSurface();

		//! Returns osculating surface if base surface is B-spline or Bezier
		XGeom_OsculatingSurface^ OsculatingSurface();

		//! Changes the orientation of this offset surface in the u
		//! parametric direction. The bounds of the surface
		//! are not changed but the given parametric direction is reversed.
		void UReverse() Standard_OVERRIDE;

		//! Computes the u  parameter on the modified
		//! surface, produced by reversing the u
		//! parametric direction of this offset surface, for any
		//! point of u parameter U  on this offset surface.
		Standard_Real UReversedParameter(Standard_Real U) Standard_OVERRIDE;

		//! Changes the orientation of this offset surface in the v parametric direction. The bounds of the surface
		//! are not changed but the given parametric direction is reversed.
		void VReverse() Standard_OVERRIDE;

		//! Computes the  v parameter on the modified
		//! surface, produced by reversing the or v
		//! parametric direction of this offset surface, for any
		//! point of  v parameter V on this offset surface.
		Standard_Real VReversedParameter(Standard_Real V) Standard_OVERRIDE;

		//! Returns the parametric bounds U1, U2, V1 and V2 of
		//! this offset surface.
		//! If the surface is infinite, this function can return:
		//! - Standard_Real::RealFirst(), or
		//! - Standard_Real::RealLast().
		void Bounds(Standard_Real% U1, Standard_Real% U2, Standard_Real% V1, Standard_Real% V2) Standard_OVERRIDE;


		//! This method returns the continuity of the basis surface - 1.
		//! Continuity of the Offset surface :
		//! C0 : only geometric continuity,
		//! C1 : continuity of the first derivative all along the Surface,
		//! C2 : continuity of the second derivative all along the Surface,
		//! C3 : continuity of the third derivative all along the Surface,
		//! CN : the order of continuity is infinite.
		//! Example :
		//! If the basis surface is C2 in the V direction and C3 in the U
		//! direction Shape = C1.
		//! Warnings :
		//! If the basis surface has a unique normal direction defined at
		//! any point this method gives the continuity of the offset
		//! surface otherwise the effective continuity can be lower than
		//! the continuity of the basis surface - 1.
		XGeomAbs_Shape Continuity() Standard_OVERRIDE;


		//! This method answer True if the continuity of the basis surface
		//! is N + 1 in the U parametric direction. We suppose in this
		//! class that a unique normal is defined at any point on the basis
		//! surface.
		//! Raised if N <0.
		Standard_Boolean IsCNu(Standard_Integer N) Standard_OVERRIDE;


		//! This method answer True if the continuity of the basis surface
		//! is N + 1 in the V parametric direction. We suppose in this
		//! class that a unique normal is defined at any point on the basis
		//! surface.
		//! Raised if N <0.
		Standard_Boolean IsCNv(Standard_Integer N) Standard_OVERRIDE;

		//! Checks whether this offset surface is closed in the u
		//! parametric direction.
		//! Returns true if, taking uFirst and uLast as
		//! the parametric bounds in the u parametric direction,
		//! the distance between the points P(uFirst,v)
		//! and P(uLast,v) is less than or equal to
		//! gp::Resolution() for each value of the   parameter v.
		Standard_Boolean IsUClosed() Standard_OVERRIDE;

		//! Checks whether this offset surface is closed in the u
		//! or v parametric direction. Returns true if taking vFirst and vLast as the
		//! parametric bounds in the v parametric direction, the
		//! distance between the points P(u,vFirst) and
		//! P(u,vLast) is less than or equal to
		//! gp::Resolution() for each value of the parameter u.
		Standard_Boolean IsVClosed() Standard_OVERRIDE;


		//! Returns true if this offset surface is periodic in the u
		//! parametric direction, i.e. if the basis
		//! surface of this offset surface is periodic in this direction.
		Standard_Boolean IsUPeriodic() Standard_OVERRIDE;

		//! Returns the period of this offset surface in the u
		//! parametric direction respectively, i.e. the period of the
		//! basis surface of this offset surface in this parametric direction.
		//! raises if the surface is not uperiodic.
		virtual Standard_Real UPeriod() Standard_OVERRIDE;


		//! Returns true if this offset surface is periodic in the v
		//! parametric direction, i.e. if the basis
		//! surface of this offset surface is periodic in this direction.
		Standard_Boolean IsVPeriodic() Standard_OVERRIDE;

		//! Returns the period of this offset surface in the v
		//! parametric direction respectively, i.e. the period of the
		//! basis surface of this offset surface in this parametric direction.
		//! raises if the surface is not vperiodic.
		virtual Standard_Real VPeriod() Standard_OVERRIDE;

		//! Computes the U isoparametric curve.
		XGeom_Curve^ UIso(Standard_Real U) Standard_OVERRIDE;

		//! Computes the V isoparametric curve.
		//!
		//! Te followings methods compute value and derivatives.
		//!
		//! Warnings
		//! An exception is raised if a unique normal vector is
		//! not defined on the basis surface for the parametric
		//! value (U,V).
		//! No check is done at the creation time and we suppose
		//! in this package that the offset surface can be defined
		//! at any point.
		XGeom_Curve^ VIso(Standard_Real V) Standard_OVERRIDE;


		//! P (U, V) = Pbasis + Offset * Ndir   where
		//! Ndir = D1Ubasis ^ D1Vbasis / ||D1Ubasis ^ D1Vbasis|| is the
		//! normal direction of the basis surface. Pbasis, D1Ubasis,
		//! D1Vbasis are the point and the first derivatives on the basis
		//! surface.
		//! If Ndir is undefined this method computes an approched normal
		//! direction using the following limited development :
		//! Ndir = N0 + DNdir/DU + DNdir/DV + Eps with Eps->0 which
		//! requires to compute the second derivatives on the basis surface.
		//! If the normal direction cannot be approximate for this order
		//! of derivation the exception UndefinedValue is raised.
		//!
		//! Raised if the continuity of the basis surface is not C1.
		//! Raised if the order of derivation required to compute the
		//! normal direction is greater than the second order.
		void D0(Standard_Real U, Standard_Real V, xgp_Pnt^ P) Standard_OVERRIDE;


		//! Raised if the continuity of the basis surface is not C2.
		void D1(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V) Standard_OVERRIDE;

		//! ---Purpose ;
		//! Raised if the continuity of the basis surface is not C3.
		void D2(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV) Standard_OVERRIDE;


		//! Raised if the continuity of the basis surface is not C4.
		void D3(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV, xgp_Vec^ D3U, xgp_Vec^ D3V, xgp_Vec^ D3UUV, xgp_Vec^ D3UVV) Standard_OVERRIDE;


		//! Computes the derivative of order Nu in the direction u and Nv
		//! in the direction v.
		//! ---Purpose ;
		//! Raised if the continuity of the basis surface is not CNu + 1
		//! in the U direction and CNv + 1 in the V direction.
		//! Raised if Nu + Nv < 1 or Nu < 0 or Nv < 0.
		//!
		//! The following methods compute the value and derivatives
		//! on the offset surface and returns the derivatives on the
		//! basis surface too.
		//! The computation of the value and derivatives on the basis
		//! surface are used to evaluate the offset surface.
		//!
		//! Warnings :
		//! The exception UndefinedValue or UndefinedDerivative is
		//! raised if it is not possible to compute a unique offset
		//! direction.
		xgp_Vec^ DN(Standard_Real U, Standard_Real V, Standard_Integer Nu, Standard_Integer Nv) Standard_OVERRIDE;

		//! Applies the transformation T to this offset surface.
		//! Note: the basis surface is also modified.
		void Transform(xgp_Trsf^ T) Standard_OVERRIDE;

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
		//! This methods calls the basis surface method.
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
		//! This methods calls the basis surface method.
		virtual xgp_GTrsf2d^ ParametricTransformation(xgp_Trsf^ T) Standard_OVERRIDE;

		//! Creates a new object which is a copy of this offset surface.
		XGeom_Geometry^ Copy() Standard_OVERRIDE;

		//! returns an  equivalent surface of the offset surface
		//! when  the basis surface   is a canonic  surface or a
		//! rectangular  limited surface on canonic surface or if
		//! the offset is null.
		XGeom_Surface^ Surface();

		//! if Standard_True, L is  the local osculating surface
		//! along U at  the point U,V.   It means that  DL/DU is
		//! collinear to DS/DU .  If IsOpposite == Standard_True
		//! these vectors have opposite direction.
		Standard_Boolean UOsculatingSurface(Standard_Real U, Standard_Real V, Standard_Boolean% IsOpposite, XGeom_BSplineSurface^% UOsculSurf);

		//! if Standard_True, L is the local osculating surface
		//! along V at the point U,V.
		//! It means that  DL/DV is
		//! collinear to DS/DV .  If IsOpposite == Standard_True
		//! these vectors have opposite direction.
		Standard_Boolean VOsculatingSurface(Standard_Real U, Standard_Real V, Standard_Boolean% IsOpposite, XGeom_BSplineSurface^% VOsculSurf);

		//! Returns continuity of the basis surface.
		XGeomAbs_Shape GetBasisSurfContinuity();

		//DEFINE_STANDARD_RTTIEXT(Geom_OffsetSurface, Geom_Surface)

		virtual property Handle(Standard_Transient) IHandle {
			Handle(Standard_Transient) get() Standard_OVERRIDE {
				return NativeHandle();
			}
			void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
				//NativeHandle() = Handle(Geom_OffsetSurface)::DownCast(handle);
				if (!handle.IsNull())
					NativeHandle() = Handle(Geom_OffsetSurface)::DownCast(handle);
				else if (!NativeHandle().IsNull())
					NativeHandle() = NULL;
			}
		};

	private:
		NCollection_Haft<Handle(Geom_OffsetSurface)> NativeHandle;
	};
}
#endif // _XGeom_OffsetSurface_HeaderFile
