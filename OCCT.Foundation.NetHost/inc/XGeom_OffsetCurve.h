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

#ifndef _XGeom_OffsetCurve_HeaderFile
#define _XGeom_OffsetCurve_HeaderFile
#pragma once
#include <NCollection_Haft.h>
#include <Geom_OffsetCurve.hxx>
#include <XGeom_Curve.h>
#include <XGeom_Geometry.h>
#include <xgp_Trsf.h>
#include <xgp_Pnt.h>
#include <xgp_Vec.h>
#include <xgp_Dir.h>

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <gp_Dir.hxx>
#include <Standard_Real.hxx>
#include <GeomAbs_Shape.hxx>
#include <Geom_Curve.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_Integer.hxx>
#include <GeomEvaluator_OffsetCurve.hxx>

class Geom_Curve;
class Standard_ConstructionError;
class Standard_RangeError;
class Standard_NoSuchObject;
class Geom_UndefinedDerivative;
class Geom_UndefinedValue;
class gp_Dir;
class gp_Pnt;
class gp_Vec;
class gp_Trsf;
class Geom_Geometry;
class Geom_OffsetCurve;
//DEFINE_STANDARD_HANDLE(Geom_OffsetCurve, Geom_Curve)

using namespace TKMath;
namespace TKG3d {
	ref class TKMath::xgp_Dir;
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Vec;
	ref class TKMath::xgp_Trsf;
	ref class XGeom_Geometry;
	//! This class implements the basis services for an offset curve
	//! in 3D space. The Offset curve in this package can be a self
	//! intersecting curve even if the basis curve does not
	//! self-intersect. The self intersecting portions are not deleted
	//! at the construction time.
	//! An offset curve is a curve at constant distance (Offset) from
	//! a basis curve in a reference direction V. The offset curve
	//! takes its parametrization from the basis curve.
	//! The Offset curve is in the direction of the normal N
	//! defined with the cross product  T^V, where the vector T
	//! is given by the first derivative on the basis curve with
	//! non zero length.
	//! The distance offset may be positive or negative to indicate the
	//! preferred side of the curve :
	//! . distance offset >0 => the curve is in the direction of N
	//! . distance offset <0 => the curve is in the direction of - N
	//!
	//! On the Offset curve :
	//! Value (U) = BasisCurve.Value(U) + (Offset * (T ^ V)) / ||T ^ V||
	//!
	//! At any point the Offset direction V must not be parallel to the
	//! vector T and the vector T must not have null length else the
	//! offset curve is not defined. So the offset curve has not the
	//! same continuity as the basis curve.
	//!
	//! Warnings :
	//!
	//! In this package we suppose that the continuity of the offset
	//! curve is one degree less than the continuity of the basis
	//! curve and we don't check that at any point ||T^V|| != 0.0
	//!
	//! So to evaluate the curve it is better to check that the offset
	//! curve is well defined at any point because an exception could
	//! be raised. The check is not done in this package at the creation
	//! of the offset curve because the control needs the use of an
	//! algorithm which cannot be implemented in this package.
	//!
	//! The OffsetCurve is closed if the first point and the last point
	//! are the same (The distance between these two points is lower or
	//! equal to the Resolution sea package gp) . The OffsetCurve can be
	//! closed even if the basis curve is not closed.
	public ref class XGeom_OffsetCurve : public XGeom_Curve
	{

	public:

		XGeom_OffsetCurve();

		//! 
		XGeom_OffsetCurve(Handle(Geom_OffsetCurve) pos);

		//!
		~XGeom_OffsetCurve();

		void SetOffsetCurveHandle(Handle(Geom_OffsetCurve) pos);

		virtual Handle(Geom_OffsetCurve) GetOffsetCurve();

		//!
		virtual Handle(Geom_Curve) GetCurve() Standard_OVERRIDE;

		//!
		virtual Handle(Geom_Geometry) GetGeometry() Standard_OVERRIDE;

		//! C is the basis curve, Offset is the distance between <me> and
		//! the basis curve at any point. V defines the fixed reference
		//! direction (offset direction). If P is a point on the basis
		//! curve and T the first derivative with non zero length
		//! at this point, the corresponding point on the offset curve is
		//! in the direction of the vector-product N = V ^ T   where
		//! N is a unitary vector.
		//! If isNotCheckC0 = TRUE checking if basis curve has C0-continuity
		//! is not made.
		//! Warnings :
		//! In this package the entities are not shared. The OffsetCurve is
		//! built with a copy of the curve C. So when C is modified the
		//! OffsetCurve is not modified
		//!
		//! Raised if the basis curve C is not at least C1.
		//! Warnings :
		//! No check is done to know if ||V^T|| != 0.0 at any point.
		//!  Standard_Boolean isNotCheckC0 = Standard_False
		XGeom_OffsetCurve(XGeom_Curve^ C, Standard_Real Offset, xgp_Dir^ V, Standard_Boolean isNotCheckC0);

		//! Changes the orientation of this offset curve.
		//! As a result:
		//! - the basis curve is reversed,
		//! - the start point of the initial curve becomes the
		//! end point of the reversed curve,
		//! - the end point of the initial curve becomes the
		//! start point of the reversed curve, and
		//! - the first and last parameters are recomputed.
		void Reverse() Standard_OVERRIDE;

		//! Computes the parameter on the reversed curve for
		//! the point of parameter U on this offset curve.
		Standard_Real ReversedParameter(Standard_Real U) Standard_OVERRIDE;

		//! Changes this offset curve by assigning C
		//! as the basis curve from which it is built.
		//! If isNotCheckC0 = TRUE checking if basis curve
		//! has C0-continuity is not made.
		//! Exceptions
		//! Standard_ConstructionError if the curve C is not at least "C1" continuous.
		//! Standard_Boolean isNotCheckC0 = Standard_False
		void SetBasisCurve(XGeom_Curve^ C, Standard_Boolean isNotCheckC0);

		//! Changes this offset curve by assigning V as the
		//! reference vector used to compute the offset direction.
		void SetDirection(xgp_Dir^ V);

		//! Changes this offset curve by assigning D as the offset value.
		void SetOffsetValue(Standard_Real D);

		//! Returns the basis curve of this offset curve.
		//! Note: The basis curve can be an offset curve.
		XGeom_Curve^ BasisCurve();

		//! Returns the global continuity of this offset curve as a
		//! value of the GeomAbs_Shape enumeration.
		//! The degree of continuity of this offset curve is equal
		//! to the degree of continuity of the basis curve minus 1.
		//! Continuity of the Offset curve :
		//! C0 : only geometric continuity,
		//! C1 : continuity of the first derivative all along the Curve,
		//! C2 : continuity of the second derivative all along the Curve,
		//! C3 : continuity of the third derivative all along the Curve,
		//! G1 : tangency continuity all along the Curve,
		//! G2 : curvature continuity all along the Curve,
		//! CN : the order of continuity is infinite.
		//! Warnings :
		//! Returns the continuity of the basis curve - 1.
		//! The offset curve must have a unique offset direction defined
		//! at any point.
		XGeomAbs_Shape Continuity() Standard_OVERRIDE;

		//! Returns the reference vector of this offset curve.
		//! Value and derivatives
		//! Warnings :
		//! The exception UndefinedValue or UndefinedDerivative is
		//! raised if it is not possible to compute a unique offset
		//! direction.
		//! If T is the first derivative with not null length and
		//! V the offset direction the relation ||T(U) ^ V|| != 0
		//! must be satisfied to evaluate the offset curve.
		//! No check is done at the creation time and we suppose
		//! in this package that the offset curve is well defined.
		xgp_Dir^ Direction();

		//! Warning! this should not be called
		//! if the basis curve is not at least C1. Nevertheless
		//! if used on portion where the curve is C1, it is OK
		void D0(Standard_Real U, xgp_Pnt^ P) Standard_OVERRIDE;

		//! Warning! this should not be called
		//! if the continuity of the basis curve is not C2.
		//! Nevertheless, it's OK to use it  on portion
		//! where the curve is C2
		void D1(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1) Standard_OVERRIDE;

		//! Warning! this should not be called
		//! if the continuity of the basis curve is not C3.
		//! Nevertheless, it's OK to use it  on portion
		//! where the curve is C3
		void D2(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2) Standard_OVERRIDE;

		void D3(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2, xgp_Vec^ V3) Standard_OVERRIDE;


		//! The returned vector gives the value of the derivative
		//! for the order of derivation N.
		//!
		//! The following functions compute the value and derivatives
		//! on the offset curve and returns the derivatives on the
		//! basis curve too.
		//! The computation of the value and derivatives on the basis
		//! curve are used to evaluate the offset curve
		//!
		//! Warning:
		//! The exception UndefinedValue or UndefinedDerivative is
		//! raised if it is not possible to compute a unique offset
		//! direction.
		//! Raised if N < 1.
		xgp_Vec^ DN(Standard_Real U, Standard_Integer N) Standard_OVERRIDE;

		//! Returns the value of the first parameter of this
		//! offset curve. The first parameter corresponds to the
		//! start point of the curve.
		//! Note: the first and last parameters of this offset curve
		//! are also the ones of its basis curve.
		Standard_Real FirstParameter() Standard_OVERRIDE;

		//! Returns the value of the last parameter of this
		//! offset curve. The last parameter
		//! corresponds to the end point.
		//! Note: the first and last parameters of this offset curve
		//! are also the ones of its basis curve.
		Standard_Real LastParameter() Standard_OVERRIDE;

		//! Returns the offset value of this offset curve.
		Standard_Real Offset();

		//! Returns True if the distance between the start point
		//! and the end point of the curve is lower or equal to
		//! Resolution from package gp.
		Standard_Boolean IsClosed() Standard_OVERRIDE;

		//! Returns true if the degree of continuity of the basis
		//! curve of this offset curve is at least N + 1.
		//! This method answer True if the continuity of the basis curve
		//! is N + 1.  We suppose in this class that a normal direction
		//! to the basis curve (used to compute the offset curve) is
		//! defined at any point on the basis curve.
		//! Raised if N < 0.
		Standard_Boolean IsCN(Standard_Integer N) Standard_OVERRIDE;

		//! Returns true if this offset curve is periodic, i.e. if the
		//! basis curve of this offset curve is periodic.
		Standard_Boolean IsPeriodic() Standard_OVERRIDE;

		//! Returns the period of this offset curve, i.e. the period
		//! of the basis curve of this offset curve.
		//! Exceptions
		//! Standard_NoSuchObject if the basis curve is not periodic.
		virtual Standard_Real Period() Standard_OVERRIDE;

		//! Applies the transformation T to this offset curve.
		//! Note: the basis curve is also modified.
		void Transform(xgp_Trsf^ T) Standard_OVERRIDE;

		//! Returns the  parameter on the  transformed  curve for
		//! the transform of the point of parameter U on <me>.
		//! me->Transformed(T)->Value(me->TransformedParameter(U,T))
		//! is the same point as
		//! me->Value(U).Transformed(T)
		//! This methods calls the basis curve method.
		virtual Standard_Real TransformedParameter(Standard_Real U, xgp_Trsf^ T) Standard_OVERRIDE;

		//! Returns a  coefficient to compute the parameter on
		//! the transformed  curve  for  the transform  of the
		//! point on <me>.
		//!
		//! Transformed(T)->Value(U * ParametricTransformation(T))
		//! is the same point as
		//! Value(U).Transformed(T)
		//! This methods calls the basis curve method.
		virtual Standard_Real ParametricTransformation(xgp_Trsf^ T) Standard_OVERRIDE;

		//! Creates a new object which is a copy of this offset curve.
		XGeom_Geometry^ Copy() Standard_OVERRIDE;

		//! Returns continuity of the basis curve.
		XGeomAbs_Shape GetBasisCurveContinuity();




		//DEFINE_STANDARD_RTTIEXT(Geom_OffsetCurve, Geom_Curve)
		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property Handle(Standard_Transient) IHandle {
			Handle(Standard_Transient) get() Standard_OVERRIDE {
				return 	NativeHandle();
			}
			void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
				NativeHandle() = Handle(Geom_OffsetCurve)::DownCast(handle);
			}
		}

	private:
		NCollection_Haft<Handle(Geom_OffsetCurve)> NativeHandle;
	};
}
#endif // _XGeom_OffsetCurve_HeaderFile
