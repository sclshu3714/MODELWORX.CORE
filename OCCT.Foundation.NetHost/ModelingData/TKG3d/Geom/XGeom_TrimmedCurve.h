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

#ifndef _XGeom_TrimmedCurve_HeaderFile
#define _XGeom_TrimmedCurve_HeaderFile

#include <Standard.hxx>
#include <Standard_Type.hxx>
#pragma once
#include "NCollection_Haft.h"
#include "Geom_TrimmedCurve.hxx"
#include "xgp_Pnt.h"
#include "xgp_Vec.h"
#include "xgp_Trsf.h"
#include "XGeom_Curve.h"
#include "XGeom_Geometry.h"
#include "XGeom_BoundedCurve.h"

#include <Geom_Curve.hxx>
#include <Geom_Geometry.hxx>

#include <Standard_Real.hxx>
#include <Geom_BoundedCurve.hxx>
#include <Standard_Boolean.hxx>
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
class Geom_Curve;
class Geom_Geometry;
class Geom_TrimmedCurve;
//DEFINE_STANDARD_HANDLE(Geom_TrimmedCurve, Geom_BoundedCurve)
using namespace TKMath;
namespace TKG3d {
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Vec;
	ref class TKMath::xgp_Trsf;
	ref class XGeom_Curve;
	ref class XGeom_Geometry;

	//! Describes a portion of a curve (termed the "basis
	//! curve") limited by two parameter values inside the
	//! parametric domain of the basis curve.
	//! The trimmed curve is defined by:
	//! - the basis curve, and
	//! - the two parameter values which limit it.
	//! The trimmed curve can either have the same
	//! orientation as the basis curve or the opposite orientation.
	public ref class XGeom_TrimmedCurve : public XGeom_BoundedCurve
	{

	public:
		XGeom_TrimmedCurve();

		//!
		~XGeom_TrimmedCurve();

		//! 
		XGeom_TrimmedCurve(Handle(Geom_TrimmedCurve) pos);


		//
		void SetTrimmedCurveHandle(Handle(Geom_TrimmedCurve) pos);

		//!
		virtual Handle(Geom_TrimmedCurve) GetTrimmedCurve();

		//!
		virtual Handle(Geom_BoundedCurve) GetBoundedCurve() Standard_OVERRIDE;

		//!
		virtual Handle(Geom_Curve) GetCurve() Standard_OVERRIDE;

		//!
		virtual Handle(Geom_Geometry) GetGeometry() Standard_OVERRIDE;

		//! Constructs a trimmed curve from the basis curve C
		//! which is limited between parameter values U1 and U2.
		//! Note: - U1 can be greater or less than U2; in both cases,
		//! the returned curve is oriented from U1 to U2.
		//! - If the basis curve C is periodic, there is an
		//! ambiguity because two parts are available. In this
		//! case, the trimmed curve has the same orientation
		//! as the basis curve if Sense is true (default value)
		//! or the opposite orientation if Sense is false.
		//! - If the curve is closed but not periodic, it is not
		//! possible to keep the part of the curve which
		//! includes the junction point (except if the junction
		//! point is at the beginning or at the end of the
		//! trimmed curve). If you tried to do this, you could
		//! alter the fundamental characteristics of the basis
		//! curve, which are used, for example, to compute
		//! the derivatives of the trimmed curve. The rules
		//! for a closed curve are therefore the same as
		//! those for an open curve.
		//! Warning: The trimmed curve is built from a copy of curve C.
		//! Therefore, when C is modified, the trimmed curve
		//! is not modified.
		//! - If the basis curve is periodic and theAdjustPeriodic is True,
		//! the bounds of the trimmed curve may be different from U1 and U2
		//! if the parametric origin of the basis curve is within
		//! the arc of the trimmed curve. In this case, the
		//! modified parameter will be equal to U1 or U2
		//! plus or minus the period.
		//! When theAdjustPeriodic is False, parameters U1 and U2 will be
		//! the same, without adjustment into the first period.
		//! Exceptions
		//! Standard_ConstructionError if:
		//! - C is not periodic and U1 or U2 is outside the
		//! bounds of C, or
		//! - U1 is equal to U2.
		//! Standard_Boolean Sense = Standard_True, Standard_Boolean theAdjustPeriodic = Standard_True
		XGeom_TrimmedCurve(XGeom_Curve^ C, Standard_Real U1, Standard_Real U2, Standard_Boolean Sense, Standard_Boolean theAdjustPeriodic);

		//! Changes the orientation of this trimmed curve.
		//! As a result:
		//! - the basis curve is reversed,
		//! - the start point of the initial curve becomes the
		//! end point of the reversed curve,
		//! - the end point of the initial curve becomes the
		//! start point of the reversed curve,
		//! - the first and last parameters are recomputed.
		//! If the trimmed curve was defined by:
		//! - a basis curve whose parameter range is [ 0., 1. ],
		//! - the two trim values U1 (first parameter) and U2 (last parameter),
		//! the reversed trimmed curve is defined by:
		//! - the reversed basis curve, whose parameter range is still [ 0., 1. ],
		//! - the two trim values 1. - U2 (first parameter) and 1. - U1 (last parameter).
		void Reverse() Standard_OVERRIDE;

		//! Computes the parameter on the reversed curve for
		//! the point of parameter U on this trimmed curve.
		Standard_Real ReversedParameter(Standard_Real U) Standard_OVERRIDE;

		//! Changes this trimmed curve, by redefining the
		//! parameter values U1 and U2 which limit its basis curve.
		//! Note: If the basis curve is periodic, the trimmed curve
		//! has the same orientation as the basis curve if Sense
		//! is true (default value) or the opposite orientation if Sense is false.
		//! Warning
		//! If the basis curve is periodic and theAdjustPeriodic is True,
		//! the bounds of the trimmed curve may be different from U1 and U2 if the
		//! parametric origin of the basis curve is within the arc of
		//! the trimmed curve. In this case, the modified
		//! parameter will be equal to U1 or U2 plus or minus the period.
		//! When theAdjustPeriodic is False, parameters U1 and U2 will be
		//! the same, without adjustment into the first period.
		//! Exceptions
		//! Standard_ConstructionError if:
		//! - the basis curve is not periodic, and either U1 or U2
		//! are outside the bounds of the basis curve, or
		//! - U1 is equal to U2.
		//! Standard_Boolean Sense = Standard_True, Standard_Boolean theAdjustPeriodic = Standard_True
		void SetTrim(Standard_Real U1, Standard_Real U2, Standard_Boolean Sense, Standard_Boolean theAdjustPeriodic);

		//! Returns the basis curve.
		//! Warning
		//! This function does not return a constant reference.
		//! Consequently, any modification of the returned value
		//! directly modifies the trimmed curve.
		XGeom_Curve^ BasisCurve();


		//! Returns the continuity of the curve :
		//! C0 : only geometric continuity,
		//! C1 : continuity of the first derivative all along the Curve,
		//! C2 : continuity of the second derivative all along the Curve,
		//! C3 : continuity of the third derivative all along the Curve,
		//! CN : the order of continuity is infinite.
		XGeomAbs_Shape Continuity() Standard_OVERRIDE;

		//! Returns true if the degree of continuity of the basis
		//! curve of this trimmed curve is at least N. A trimmed
		//! curve is at least "C0" continuous.
		//! Warnings :
		//! The continuity of the trimmed curve can be greater than
		//! the continuity of the basis curve because you consider
		//! only a part of the basis curve.
		//! Raised if N < 0.
		Standard_Boolean IsCN(Standard_Integer N) Standard_OVERRIDE;


		//! Returns the end point of <me>. This point is the
		//! evaluation of the curve for the "LastParameter".
		xgp_Pnt^ EndPoint() Standard_OVERRIDE;


		//! Returns the value of the first parameter of <me>.
		//! The first parameter is the parameter of the "StartPoint"
		//! of the trimmed curve.
		Standard_Real FirstParameter() Standard_OVERRIDE;


		//! Returns True if the distance between the StartPoint and
		//! the EndPoint is lower or equal to Resolution from package gp.
		Standard_Boolean IsClosed() Standard_OVERRIDE;

		//! Always returns FALSE (independently of the type of basis curve).
		Standard_Boolean IsPeriodic() Standard_OVERRIDE;

		//! Returns the period of the basis curve of this trimmed curve.
		//! Exceptions
		//! Standard_NoSuchObject if the basis curve is not periodic.
		virtual Standard_Real Period() Standard_OVERRIDE;


		//! Returns the value of the last parameter of <me>.
		//! The last parameter is the parameter of the "EndPoint" of the
		//! trimmed curve.
		Standard_Real LastParameter() Standard_OVERRIDE;


		//! Returns the start point of <me>.
		//! This point is the evaluation of the curve from the
		//! "FirstParameter".
		//! value and derivatives
		//! Warnings :
		//! The returned derivatives have the same orientation as the
		//! derivatives of the basis curve even if the trimmed curve
		//! has not the same orientation as the basis curve.
		xgp_Pnt^ StartPoint() Standard_OVERRIDE;

		//! Returns in P the point of parameter U.
		//!
		//! If the basis curve is an OffsetCurve sometimes it is not
		//! possible to do the evaluation of the curve at the parameter
		//! U (see class OffsetCurve).
		void D0(Standard_Real U, xgp_Pnt^ P) Standard_OVERRIDE;

		//! Raised if the continuity of the curve is not C1.
		void D1(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1) Standard_OVERRIDE;

		//! Raised if the continuity of the curve is not C2.
		void D2(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2) Standard_OVERRIDE;

		//! Raised if the continuity of the curve is not C3.
		void D3(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2, xgp_Vec^ V3) Standard_OVERRIDE;

		//! N is the order of derivation.
		//! Raised if the continuity of the curve is not CN.
		//! Raised if N < 1.
		//! geometric transformations
		xgp_Vec^ DN(Standard_Real U, Standard_Integer N) Standard_OVERRIDE;

		//! Applies the transformation T to this trimmed curve.
		//! Warning The basis curve is also modified.
		void Transform(xgp_Trsf^ T) Standard_OVERRIDE;

		//! Returns the  parameter on the  transformed  curve for
		//! the transform of the point of parameter U on <me>.
		//!
		//! me->Transformed(T)->Value(me->TransformedParameter(U,T))
		//!
		//! is the same point as
		//!
		//! me->Value(U).Transformed(T)
		//!
		//! This methods calls the basis curve method.
		virtual Standard_Real TransformedParameter(Standard_Real U, xgp_Trsf^ T) Standard_OVERRIDE;

		//! Returns a  coefficient to compute the parameter on
		//! the transformed  curve  for  the transform  of the
		//! point on <me>.
		//!
		//! Transformed(T)->Value(U * ParametricTransformation(T))
		//!
		//! is the same point as
		//!
		//! Value(U).Transformed(T)
		//!
		//! This methods calls the basis curve method.
		virtual Standard_Real ParametricTransformation(xgp_Trsf^ T) Standard_OVERRIDE;

		//! Creates a new object which is a copy of this trimmed curve.
		XGeom_Geometry^ Copy() Standard_OVERRIDE;




		//! DEFINE_STANDARD_RTTIEXT(Geom_TrimmedCurve, Geom_BoundedCurve)
		virtual property Handle(Standard_Transient) IHandle {
			Handle(Standard_Transient) get() Standard_OVERRIDE {
				return NativeHandle();
			}
			void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
				NativeHandle() = Handle(Geom_TrimmedCurve)::DownCast(handle);
			}
		};

	private:
		NCollection_Haft<Handle(Geom_TrimmedCurve)> NativeHandle;
	};
}
#endif // _XGeom_TrimmedCurve_HeaderFile
