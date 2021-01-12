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

#ifndef _XGeom_Curve_HeaderFile
#define _XGeom_Curve_HeaderFile
#pragma once
#include <NCollection_Haft.h>
#include <Geom_Curve.hxx>
#include <XGeom_Geometry.h>
#include <xgp_Trsf.h>
#include <xgp_Pnt.h>
#include <xgp_Vec.h>

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <Geom_Geometry.hxx>
#include <Standard_Real.hxx>
#include <Standard_Boolean.hxx>
#include <GeomAbs_Shape.hxx>
#include <Standard_Integer.hxx>
#include <XGeomAbs_Shape.h>
class Standard_RangeError;
class Standard_NoSuchObject;
class Geom_UndefinedDerivative;
class Geom_UndefinedValue;
class gp_Trsf;
class gp_Pnt;
class gp_Vec;


//class Geom_Curve;
//DEFINE_STANDARD_HANDLE(Geom_Curve, Geom_Geometry)

//! The abstract class Curve describes the common
//! behavior of curves in 3D space. The Geom package
//! provides numerous concrete classes of derived
//! curves, including lines, circles, conics, Bezier or
//! BSpline curves, etc.
//! The main characteristic of these curves is that they
//! are parameterized. The Geom_Curve class shows:
//! - how to work with the parametric equation of a curve
//! in order to calculate the point of parameter u,
//! together with the vector tangent and the derivative
//! vectors of order 2, 3,..., N at this point;
//! - how to obtain general information about the curve
//! (for example, level of continuity, closed
//! characteristics, periodicity, bounds of the parameter field);
//! - how the parameter changes when a geometric
//! transformation is applied to the curve or when the
//! orientation of the curve is inverted.
//! All curves must have a geometric continuity: a curve is
//! at least "C0". Generally, this property is checked at
//! the time of construction or when the curve is edited.
//! Where this is not the case, the documentation states so explicitly.
//! Warning
//! The Geom package does not prevent the
//! construction of curves with null length or curves which
//! self-intersect.

namespace TKG3d {

	public ref class XGeom_Curve : public XGeom_Geometry
	{

	public:

		XGeom_Curve();

		//! 
		XGeom_Curve(Handle(Geom_Curve) pos);

		//!
		~XGeom_Curve();

		void SetCurveHandle(Handle(Geom_Curve) pos);

		//!
		virtual Handle(Geom_Curve) GetCurve();

		//!
		virtual Handle(Geom_Geometry) GetGeometry() Standard_OVERRIDE;

		//! Changes the direction of parametrization of <me>.
		//! The "FirstParameter" and the "LastParameter" are not changed
		//! but the orientation  of the curve is modified. If the curve
		//! is bounded the StartPoint of the initial curve becomes the
		//! EndPoint of the reversed curve  and the EndPoint of the initial
		//! curve becomes the StartPoint of the reversed curve.
		virtual void Reverse();

		//! Returns the  parameter on the  reversed  curve for
		//! the point of parameter U on <me>.
		//!
		//! me->Reversed()->Value(me->ReversedParameter(U))
		//!
		//! is the same point as
		//!
		//! me->Value(U)
		virtual Standard_Real ReversedParameter(Standard_Real U);

		//! Returns the  parameter on the  transformed  curve for
		//! the transform of the point of parameter U on <me>.
		//!
		//! me->Transformed(T)->Value(me->TransformedParameter(U,T))
		//!
		//! is the same point as
		//!
		//! me->Value(U).Transformed(T)
		//!
		//! This methods returns <U>
		//!
		//! It can be redefined. For example on the Line.
		virtual Standard_Real TransformedParameter(Standard_Real U, xgp_Trsf^ T);

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
		//! This methods returns 1.
		//!
		//! It can be redefined. For example on the Line.
		virtual Standard_Real ParametricTransformation(xgp_Trsf^ T);

		//! Returns a copy of <me> reversed.
		XGeom_Curve^ Reversed();

		//! Returns the value of the first parameter.
		//! Warnings :
		//! It can be RealFirst from package Standard
		//! if the curve is infinite
		virtual Standard_Real FirstParameter();

		//! Returns the value of the last parameter.
		//! Warnings :
		//! It can be RealLast from package Standard
		//! if the curve is infinite
		virtual Standard_Real LastParameter();

		//! Returns true if the curve is closed.
		//! Some curves such as circle are always closed, others such as line
		//! are never closed (by definition).
		//! Some Curves such as OffsetCurve can be closed or not. These curves
		//! are considered as closed if the distance between the first point
		//! and the last point of the curve is lower or equal to the Resolution
		//! from package gp wich is a fixed criterion independant of the
		//! application.
		virtual Standard_Boolean IsClosed();

		//! Is the parametrization of the curve periodic ?
		//! It is possible only if the curve is closed and if the
		//! following relation is satisfied :
		//! for each parametric value U the distance between the point
		//! P(u) and the point P (u + T) is lower or equal to Resolution
		//! from package gp, T is the period and must be a constant.
		//! There are three possibilities :
		//! . the curve is never periodic by definition (SegmentLine)
		//! . the curve is always periodic by definition (Circle)
		//! . the curve can be defined as periodic (BSpline). In this case
		//! a function SetPeriodic allows you to give the shape of the
		//! curve.  The general rule for this case is : if a curve can be
		//! periodic or not the default periodicity set is non periodic
		//! and you have to turn (explicitly) the curve into a periodic
		//! curve  if you want the curve to be periodic.
		virtual Standard_Boolean IsPeriodic();

		//! Returns the period of this curve.
		//! Exceptions Standard_NoSuchObject if this curve is not periodic.
		virtual Standard_Real Period();

		//! It is the global continuity of the curve
		//! C0 : only geometric continuity,
		//! C1 : continuity of the first derivative all along the Curve,
		//! C2 : continuity of the second derivative all along the Curve,
		//! C3 : continuity of the third derivative all along the Curve,
		//! G1 : tangency continuity all along the Curve,
		//! G2 : curvature continuity all along the Curve,
		//! CN : the order of continuity is infinite.
		virtual XGeomAbs_Shape Continuity();

		//! Returns true if the degree of continuity of this curve is at least N.
		//! Exceptions -  Standard_RangeError if N is less than 0.
		virtual Standard_Boolean IsCN(Standard_Integer N);

		//! Returns in P the point of parameter U.
		//! If the curve is periodic  then the returned point is P(U) with
		//! U = Ustart + (U - Uend)  where Ustart and Uend are the
		//! parametric bounds of the curve.
		//!
		//! Raised only for the "OffsetCurve" if it is not possible to
		//! compute the current point. For example when the first
		//! derivative on the basis curve and the offset direction
		//! are parallel.
		virtual void D0(Standard_Real U, xgp_Pnt^ P);


		//! Returns the point P of parameter U and the first derivative V1.
		//! Raised if the continuity of the curve is not C1.
		virtual void D1(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1);


		//! Returns the point P of parameter U, the first and second
		//! derivatives V1 and V2.
		//! Raised if the continuity of the curve is not C2.
		virtual void D2(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2);


		//! Returns the point P of parameter U, the first, the second
		//! and the third derivative.
		//! Raised if the continuity of the curve is not C3.
		virtual void D3(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2, xgp_Vec^ V3);


		//! The returned vector gives the value of the derivative for the
		//! order of derivation N.
		//! Raised if the continuity of the curve is not CN.
		//!
		//! Raised if the   derivative  cannot  be  computed
		//! easily. e.g. rational bspline and n > 3.
		//! Raised if N < 1.
		virtual xgp_Vec^ DN(Standard_Real U, Standard_Integer N);

		//! Computes the point of parameter U on <me>.
		//! If the curve is periodic  then the returned point is P(U) with
		//! U = Ustart + (U - Uend)  where Ustart and Uend are the
		//! parametric bounds of the curve.
		//! it is implemented with D0.
		//!
		//! Raised only for the "OffsetCurve" if it is not possible to
		//! compute the current point. For example when the first
		//! derivative on the basis curve and the offset direction are parallel.
		xgp_Pnt^ Value(Standard_Real U);




		//! DEFINE_STANDARD_RTTIEXT(Geom_Curve, Geom_Geometry)
	    /// <summary>
		/// ���ؾ��
		/// </summary>
		virtual property Handle(Standard_Transient) IHandle {
			Handle(Standard_Transient) get() Standard_OVERRIDE {
				return 	NativeHandle();
			}
			void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
				NativeHandle() = Handle(Geom_Curve)::DownCast(handle);
			}
		}

	private:
		NCollection_Haft<Handle(Geom_Curve)> NativeHandle;
	};
}
#endif // _XGeom_Curve_HeaderFile
