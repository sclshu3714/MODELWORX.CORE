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

#ifndef _XGeom_RectangularTrimmedSurface_HeaderFile
#define _XGeom_RectangularTrimmedSurface_HeaderFile
#pragma once
#include "NCollection_Haft.h"
#include "Geom_RectangularTrimmedSurface.hxx"
#include "XGeom_BoundedSurface.h"
#include "xgp_Pnt.h"
#include "xgp_Vec.h"
#include "xgp_Trsf.h"
#include "xgp_GTrsf2d.h"
#include "XGeom_Curve.h"
#include "XGeom_Surface.h"
#include "XGeom_Geometry.h"


#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <Standard_Real.hxx>
#include <Standard_Boolean.hxx>
#include <Geom_BoundedSurface.hxx>
#include <GeomAbs_Shape.hxx>
#include <Standard_Integer.hxx>
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
class Geom_RectangularTrimmedSurface;
//DEFINE_STANDARD_HANDLE(Geom_RectangularTrimmedSurface, Geom_BoundedSurface)


using namespace TKMath;
namespace TKG3d {
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Vec;
	ref class TKMath::xgp_Trsf;
	ref class XGeom_Curve;
	ref class XGeom_Geometry;
	//! Describes a portion of a surface (a patch) limited
	//! by two values of the u parameter in the u
	//! parametric direction, and two values of the v
	//! parameter in the v parametric direction. The
	//! domain of the trimmed surface must be within the
	//! domain of the surface being trimmed.
	//! The trimmed surface is defined by:
	//! - the basis surface, and
	//! - the values (umin, umax) and (vmin, vmax)
	//! which limit it in the u and v parametric directions.
	//! The trimmed surface is built from a copy of the basis
	//! surface. Therefore, when the basis surface is
	//! modified the trimmed surface is not changed.
	//! Consequently, the trimmed surface does not
	//! necessarily have the same orientation as the basis surface.
	//! Warning:  The  case of surface   being trimmed is  periodic and
	//! parametrics values are outside the domain is possible.
	//! But, domain of the  trimmed surface can be translated
	//! by (n X) the period.
	public ref class XGeom_RectangularTrimmedSurface : public XGeom_BoundedSurface
	{

	public:



		//! The U parametric direction of the surface is oriented from U1
		//! to U2. The V parametric direction of the surface is oriented
		//! from V1 to V2.
		//! These two directions define the orientation of the surface
		//! (normal). If the surface is not periodic USense and VSense are
		//! not used for the construction. If the surface S is periodic in
		//! one direction USense and VSense give the available part of the
		//! surface. By default in this case the surface has the same
		//! orientation as the basis surface S.
		//! The returned surface is not closed and not periodic.
		//! ConstructionError   Raised if
		//! S is not periodic in the UDirection and U1 or U2 are out of the
		//! bounds of S.
		//! S is not periodic in the VDirection and V1 or V2 are out of the
		//! bounds of S.
		//! U1 = U2 or V1 = V2
		//! Standard_Boolean USense = Standard_True, Standard_Boolean VSense = Standard_True
		XGeom_RectangularTrimmedSurface(XGeom_Surface^ S, Standard_Real U1, Standard_Real U2, Standard_Real V1, Standard_Real V2, Standard_Boolean USense, Standard_Boolean VSense);


		//! The basis surface S is only trim in one parametric direction.
		//! If UTrim = True the surface is trimmed in the U parametric
		//! direction else the surface is trimmed in the V parametric
		//! direction.
		//! In the considered parametric direction the resulting surface is
		//! oriented from Param1 to Param2. If S is periodic Sense gives the
		//! available part of the surface. By default the trimmed surface has
		//! the same orientation as the basis surface S in the considered
		//! parametric direction (Sense = True).
		//! If the basis surface S is closed or periodic in the parametric
		//! direction opposite to the trimming direction the trimmed surface
		//! has the same characteristics as the surface S in this direction.
		//! Warnings :
		//! In this package the entities are not shared.
		//! The RectangularTrimmedSurface is built with a copy of the
		//! surface S. So when S is modified the RectangularTrimmedSurface
		//! is not modified
		//! Raised if
		//! S is not periodic in the considered parametric direction and
		//! Param1 or Param2 are out of the bounds of S.
		//! Param1 = Param2
		//! Standard_Boolean Sense = Standard_True
		XGeom_RectangularTrimmedSurface(XGeom_Surface^ S, Standard_Real Param1, Standard_Real Param2, Standard_Boolean UTrim, Standard_Boolean Sense);

		//! Modifies this patch by changing the trim values
		//! applied to the original surface
		//! The u parametric direction of
		//! this patch is oriented from U1 to U2. The v
		//! parametric direction of this patch is oriented
		//! from V1 to V2. USense and VSense are used
		//! for the construction only if the surface is periodic
		//! in the corresponding parametric direction, and
		//! define the available part of the surface; by default
		//! in this case, this patch has the same orientation
		//! as the basis surface.
		//! Raised if
		//! The BasisSurface is not periodic in the UDirection and U1 or U2
		//! are out of the bounds of the BasisSurface.
		//! The BasisSurface is not periodic in the VDirection and V1 or V2
		//! are out of the bounds of the BasisSurface.
		//! U1 = U2 or V1 = V2
		//! Standard_Boolean USense = Standard_True, Standard_Boolean VSense = Standard_True
		void SetTrim(Standard_Real U1, Standard_Real U2, Standard_Real V1, Standard_Real V2, Standard_Boolean USense, Standard_Boolean VSense);

		//! Modifies this patch by changing the trim values
		//! applied to the original surface
		//! The basis surface is trimmed only in one parametric direction: if UTrim
		//! is true, the surface is trimmed in the u parametric
		//! direction; if it is false, it is trimmed in the v
		//! parametric direction. In the "trimmed" direction,
		//! this patch is oriented from Param1 to Param2. If
		//! the basis surface is periodic in the "trimmed"
		//! direction, Sense defines its available part. By
		//! default in this case, this patch has the same
		//! orientation as the basis surface in this parametric
		//! direction. If the basis surface is closed or periodic
		//! in the other parametric direction (i.e. not the
		//! "trimmed" direction), this patch has the same
		//! characteristics as the basis surface in that parametric direction.
		//! Raised if
		//! The BasisSurface is not periodic in the considered direction and
		//! Param1 or Param2 are out of the bounds of the BasisSurface.
		//! Param1 = Param2
		//!  Standard_Boolean Sense = Standard_True
		void SetTrim(Standard_Real Param1, Standard_Real Param2, Standard_Boolean UTrim, Standard_Boolean Sense);

		//! Returns the Basis surface of <me>.
		XGeom_Surface^ BasisSurface();

		//! Changes the orientation of this patch in the u
		//! parametric direction. The bounds of the surface are
		//! not changed, but the given parametric direction is
		//! reversed. Hence the orientation of the surface is reversed.
		void UReverse() Standard_OVERRIDE;

		//! Computes the u  parameter on the modified
		//! surface, produced by when reversing its u
		//! parametric direction, for any point of u parameter U on this patch.
		Standard_Real UReversedParameter(Standard_Real U) Standard_OVERRIDE;

		//! Changes the orientation of this patch in the v
		//! parametric direction. The bounds of the surface are
		//! not changed, but the given parametric direction is
		//! reversed. Hence the orientation of the surface is reversed.
		void VReverse() Standard_OVERRIDE;

		//! Computes the v  parameter on the modified
		//! surface, produced by when reversing its v
		//! parametric direction, for any point of v parameter V on this patch.
		Standard_Real VReversedParameter(Standard_Real V) Standard_OVERRIDE;

		//! Returns the parametric bounds U1, U2, V1 and V2 of this patch.
		void Bounds(Standard_Real% U1, Standard_Real% U2, Standard_Real% V1, Standard_Real% V2) Standard_OVERRIDE;


		//! Returns  the continuity of the surface :
		//! C0 : only geometric continuity,
		//! C1 : continuity of the first derivative all along the Surface,
		//! C2 : continuity of the second derivative all along the Surface,
		//! C3 : continuity of the third derivative all along the Surface,
		//! CN : the order of continuity is infinite.
		XGeomAbs_Shape Continuity() Standard_OVERRIDE;

		//! Returns true if this patch is closed in the given parametric direction.
		Standard_Boolean IsUClosed() Standard_OVERRIDE;

		//! Returns true if this patch is closed in the given parametric direction.
		Standard_Boolean IsVClosed() Standard_OVERRIDE;


		//! Returns true if the order of derivation in the U parametric
		//! direction is N.
		//! Raised if N < 0.
		Standard_Boolean IsCNu(Standard_Integer N) Standard_OVERRIDE;


		//! Returns true if the order of derivation in the V parametric
		//! direction is N.
		//! Raised if N < 0.
		Standard_Boolean IsCNv(Standard_Integer N) Standard_OVERRIDE;

		//! Returns true if this patch is periodic and not trimmed in the given
		//! parametric direction.
		Standard_Boolean IsUPeriodic() Standard_OVERRIDE;

		//! Returns the period of this patch in the u
		//! parametric direction.
		//! raises if the surface is not uperiodic.
		virtual Standard_Real UPeriod() Standard_OVERRIDE;


		//! Returns true if this patch is periodic and not trimmed in the given
		//! parametric direction.
		Standard_Boolean IsVPeriodic() Standard_OVERRIDE;

		//! Returns the period of this patch in the v
		//! parametric direction.
		//! raises if the surface is not vperiodic.
		//! value and derivatives
		virtual Standard_Real VPeriod() Standard_OVERRIDE;

		//! computes the U isoparametric curve.
		XGeom_Curve^ UIso(Standard_Real U) Standard_OVERRIDE;

		//! Computes the V isoparametric curve.
		XGeom_Curve^ VIso(Standard_Real V) Standard_OVERRIDE;


		//! Can be raised if the basis surface is an OffsetSurface.
		void D0(Standard_Real U, Standard_Real V, xgp_Pnt^ P) Standard_OVERRIDE;


		//! The returned derivatives have the same orientation as the
		//! derivatives of the basis surface even if the trimmed surface
		//! has not the same parametric orientation.
		//! Warning!  UndefinedDerivative  raised if the continuity of the surface is not C1.
		void D1(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V) Standard_OVERRIDE;


		//! The returned derivatives have the same orientation as the
		//! derivatives of the basis surface even if the trimmed surface
		//! has not the same parametric orientation.
		//! Warning! UndefinedDerivative raised if the continuity of the surface is not C2.
		void D2(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV) Standard_OVERRIDE;

		//! The returned derivatives have the same orientation as the
		//! derivatives of the basis surface even if the trimmed surface
		//! has not the same parametric orientation.
		//! Warning UndefinedDerivative raised if the continuity of the surface is not C3.
		void D3(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV, xgp_Vec^ D3U, xgp_Vec^ D3V, xgp_Vec^ D3UUV, xgp_Vec^ D3UVV) Standard_OVERRIDE;

		//! The returned derivative has the same orientation as the
		//! derivative of the basis surface even if the trimmed surface
		//! has not the same parametric orientation.
		//! Warning!  UndefinedDerivative raised if the continuity of the surface is not CNu in the U
		//! parametric direction and CNv in the V parametric direction.
		//! RangeError Raised if Nu + Nv < 1 or Nu < 0 or Nv < 0.
		xgp_Vec^ DN(Standard_Real U, Standard_Real V, Standard_Integer Nu, Standard_Integer Nv) Standard_OVERRIDE;

		//! Applies the transformation T to this patch.
		//! Warning
		//! As a consequence, the basis surface included in the
		//! data structure of this patch is also modified.
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
		//!
		//! This methods calls the basis surface method.
		virtual void TransformParameters(Standard_Real U, Standard_Real V, xgp_Trsf^ T) Standard_OVERRIDE;

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

		//! Creates a new object which is a copy of this patch.
		XGeom_Geometry^ Copy() Standard_OVERRIDE;


		//! DEFINE_STANDARD_RTTIEXT(Geom_RectangularTrimmedSurface, Geom_BoundedSurface)

		virtual property Handle(Standard_Transient) IHandle {
			Handle(Standard_Transient) get() Standard_OVERRIDE {
				return NativeHandle();
			}
			void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
				NativeHandle() = Handle(Geom_RectangularTrimmedSurface)::DownCast(handle);
			}
		};

	private:
		NCollection_Haft<Handle(Geom_RectangularTrimmedSurface)> NativeHandle;
	};
}
#endif // _XGeom_RectangularTrimmedSurface_HeaderFile
