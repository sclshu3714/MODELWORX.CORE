// Created on: 1993-03-10
// Created by: Philippe DAUTRY
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

#ifndef _XGeom_Line_HeaderFile
#define _XGeom_Line_HeaderFile
#pragma once
#include <Geom_Line.hxx>
#include <NCollection_Haft.h>  
#include <XGeom_Geometry.h>
#include <XGeom_Curve.h>
#include <xgp_Ax1.h>
#include <xgp_Lin.h>
#include <xgp_Pnt.h>
#include <xgp_Dir.h>
#include <xgp_Vec.h>
#include <xgp_Trsf.h>	
#include <XGeomAbs_Shape.h>

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <gp_Ax1.hxx>
#include <Geom_Curve.hxx>
#include <Standard_Real.hxx>
#include <Standard_Boolean.hxx>
#include <GeomAbs_Shape.hxx>
#include <Standard_Integer.hxx>
class Standard_RangeError;
class gp_Ax1;
class gp_Lin;
class gp_Pnt;
class gp_Dir;
class gp_Vec;
class gp_Trsf;
class Geom_Geometry;

using namespace TKMath;
//class Geom_Line;
//DEFINE_STANDARD_HANDLE(Geom_Line, Geom_Curve)

namespace TKG3d {
	//! Describes an infinite line.
	//! A line is defined and positioned in space with an axis
	//! (gp_Ax1 object) which gives it an origin and a unit vector.
	//! The Geom_Line line is parameterized:
	//! P (U) = O + U*Dir, where:
	//! - P is the point of parameter U,
	//! - O is the origin and Dir the unit vector of its positioning axis.
	//! The parameter range is ] -infinite, +infinite [.
	//! The orientation of the line is given by the unit vector
	//! of its positioning axis.
	ref class TKMath::xgp_Ax1;
	ref class TKMath::xgp_Lin;
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Dir;
	ref class TKMath::xgp_Vec;
	ref class TKMath::xgp_Trsf;
	ref class XGeom_Geometry;
	public ref class XGeom_Line : public XGeom_Curve
	{

	public:

		!XGeom_Line() { IHandle = NULL; };
		~XGeom_Line() { IHandle = NULL; };
		//! Creates a line located in 3D space with the axis placement A1.
		//! The Location of A1 is the origin of the line.
		XGeom_Line(xgp_Ax1^ A1);


		//! Creates a line from a non transient line from package gp.
		XGeom_Line(xgp_Lin^ L);

		XGeom_Line(Handle(Geom_Line) pos);
		//! Constructs a line passing through point P and parallel to vector V
		//! (P and V are, respectively, the origin and the unit
		//! vector of the positioning axis of the line).
		XGeom_Line(xgp_Pnt^ P, xgp_Dir^ V);

		void SetLineHandle(Handle(Geom_Line) pos);

		Handle(Geom_Line) GetHLine();

		//!
		virtual Handle(Geom_Curve) GetCurve() Standard_OVERRIDE;

		//!
		virtual Handle(Geom_Geometry) GetGeometry() Standard_OVERRIDE;

		//! Set <me> so that <me> has the same geometric properties as L.
		void SetLin(xgp_Lin^ L);

		//! changes the direction of the line.
		void SetDirection(xgp_Dir^ V);


		//! changes the "Location" point (origin) of the line.
		void SetLocation(xgp_Pnt^ P);


		//! changes the "Location" and a the "Direction" of <me>.
		void SetPosition(xgp_Ax1^ A1);


		//! Returns non transient line from gp with the same geometric
		//! properties as <me>
		xgp_Lin^ Lin();

		//! Returns the positioning axis of this line; this is also its local coordinate system.
		xgp_Ax1^ Position();

		//! Changes the orientation of this line. As a result, the
		//! unit vector of the positioning axis of this line is reversed.
		void Reverse() Standard_OVERRIDE;

		//! Computes the parameter on the reversed line for the
		//! point of parameter U on this line.
		//! For a line, the returned value is -U.
		Standard_Real ReversedParameter(Standard_Real U) Standard_OVERRIDE;

		//! Returns the value of the first parameter of this
		//! line. This is Standard_Real::RealFirst().
		Standard_Real FirstParameter() Standard_OVERRIDE;

		//! Returns the value of the last parameter of this
		//! line. This is  Standard_Real::RealLast().
		Standard_Real LastParameter() Standard_OVERRIDE;

		//! returns False
		Standard_Boolean IsClosed() Standard_OVERRIDE;

		//! returns False
		Standard_Boolean IsPeriodic() Standard_OVERRIDE;

		//! Returns GeomAbs_CN, which is the global continuity of any line.
		XGeomAbs_Shape Continuity() Standard_OVERRIDE;

		//! returns True.
		//! Raised if N < 0.
		Standard_Boolean IsCN(Standard_Integer N) Standard_OVERRIDE;

		//! Returns in P the point of parameter U.
		//! P (U) = O + U * Dir where O is the "Location" point of the
		//! line and Dir the direction of the line.
		void D0(Standard_Real U, xgp_Pnt^ P) Standard_OVERRIDE;


		//! Returns the point P of parameter u and the first derivative V1.
		void D1(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1) Standard_OVERRIDE;


		//! Returns the point P of parameter U, the first and second
		//! derivatives V1 and V2. V2 is a vector with null magnitude
		//! for a line.
		void D2(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2) Standard_OVERRIDE;


		//! V2 and V3 are vectors with null magnitude for a line.
		void D3(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2, xgp_Vec^ V3) Standard_OVERRIDE;


		//! The returned vector gives the value of the derivative for the
		//! order of derivation N.
		//! Raised if N < 1.
		xgp_Vec^ DN(Standard_Real U, Standard_Integer N) Standard_OVERRIDE;

		//! Applies the transformation T to this line.
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
		//! This methods returns <U> * T.ScaleFactor()
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
		//! This methods returns T.ScaleFactor()
		virtual Standard_Real ParametricTransformation(xgp_Trsf^ T) Standard_OVERRIDE;

		//! Creates a new object which is a copy of this line.
		XGeom_Geometry^ Copy() Standard_OVERRIDE;

		//! DEFINE_STANDARD_RTTIEXT(Geom_Line,Geom_Curve)
		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property Handle(Standard_Transient) IHandle {
			Handle(Standard_Transient) get() Standard_OVERRIDE {
				return 	NativeHandle();
			}
			void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
				NativeHandle() = Handle(Geom_Line)::DownCast(handle);
			}
		}

	private:
		NCollection_Haft<Handle(Geom_Line)> NativeHandle;
	};
}
#endif // _XGeom_Line_HeaderFile
