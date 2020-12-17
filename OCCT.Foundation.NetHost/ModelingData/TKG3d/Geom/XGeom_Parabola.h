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

#ifndef _XGeom_Parabola_HeaderFile
#define _XGeom_Parabola_HeaderFile
#pragma once
#include <NCollection_Haft.h>
#include <Geom_Parabola.hxx>
#include <XGeom_Conic.h>  
#include <xgp_Parab.h> 
#include <xgp_Ax2.h> 
#include <xgp_Ax1.h> 
#include <xgp_Pnt.h> 
#include <xgp_Vec.h> 
#include <xgp_Trsf.h> 
#include <XGeom_Geometry.h> 

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <Standard_Real.hxx>
#include <Geom_Conic.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_Integer.hxx>
class Standard_ConstructionError;
class Standard_RangeError;
class gp_Parab;
class gp_Ax2;
class gp_Ax1;
class gp_Pnt;
class gp_Vec;
class gp_Trsf;
class Geom_Geometry;
class Geom_Parabola;
//DEFINE_STANDARD_HANDLE(Geom_Parabola, Geom_Conic)

using namespace TKMath;
namespace TKG3d {
	ref class TKMath::xgp_Parab;
	ref class TKMath::xgp_Ax2;
	ref class TKMath::xgp_Ax1;
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Vec;
	ref class TKMath::xgp_Trsf;
	ref class XGeom_Geometry;
	//! Describes a parabola in 3D space.
	//! A parabola is defined by its focal length (i.e. the
	//! distance between its focus and its apex) and is
	//! positioned in space with a coordinate system
	//! (gp_Ax2 object) where:
	//! - the origin is the apex of the parabola,
	//! - the "X Axis" defines the axis of symmetry; the
	//! parabola is on the positive side of this axis,
	//! - the origin, "X Direction" and "Y Direction" define the
	//! plane of the parabola.
	//! This coordinate system is the local coordinate
	//! system of the parabola.
	//! The "main Direction" of this coordinate system is a
	//! vector normal to the plane of the parabola. The axis,
	//! of which the origin and unit vector are respectively the
	//! origin and "main Direction" of the local coordinate
	//! system, is termed the "Axis" or "main Axis" of the parabola.
	//! The "main Direction" of the local coordinate system
	//! gives an explicit orientation to the parabola,
	//! determining the direction in which the parameter
	//! increases along the parabola.
	//! The Geom_Parabola parabola is parameterized as follows:
	//! P(U) = O + U*U/(4.*F)*XDir + U*YDir
	//! where:
	//! - P is the point of parameter U,
	//! - O, XDir and YDir are respectively the origin, "X
	//! Direction" and "Y Direction" of its local coordinate system,
	//! - F is the focal length of the parabola.
	//! The parameter of the parabola is therefore its Y
	//! coordinate in the local coordinate system, with the "X
	//! Axis" of the local coordinate system defining the origin
	//! of the parameter.
	//! The parameter range is ] -infinite, +infinite [.
	public ref class XGeom_Parabola : public XGeom_Conic
	{

	public:

		XGeom_Parabola();

		XGeom_Parabola(Handle(Geom_Parabola) pos);


		void SetParabolaHandle(Handle(Geom_Parabola) pos);

		virtual Handle(Geom_Parabola) GetParabola();

		virtual Handle(Geom_Conic) GetConic() Standard_OVERRIDE;

		//!
		virtual Handle(Geom_Curve) GetCurve() Standard_OVERRIDE;

		//!
		virtual Handle(Geom_Geometry) GetGeometry() Standard_OVERRIDE;

		//! Creates a parabola from a non transient one.
		XGeom_Parabola(xgp_Parab^ Prb);


		//! Creates a parabola with its local coordinate system "A2"
		//! and it's focal length "Focal".
		//! The XDirection of A2 defines the axis of symmetry of the
		//! parabola. The YDirection of A2 is parallel to the directrix
		//! of the parabola. The Location point of A2 is the vertex of
		//! the parabola
		//! Raised if Focal < 0.0
		XGeom_Parabola(xgp_Ax2^ A2, Standard_Real Focal);


		//! D is the directrix of the parabola and F the focus point.
		//! The symmetry axis (XAxis) of the parabola is normal to the
		//! directrix and pass through the focus point F, but its
		//! location point is the vertex of the parabola.
		//! The YAxis of the parabola is parallel to D and its location
		//! point is the vertex of the parabola. The normal to the plane
		//! of the parabola is the cross product between the XAxis and the
		//! YAxis.
		XGeom_Parabola(xgp_Ax1^ D, xgp_Pnt^ F);

		//! Assigns the value Focal to the focal distance of this parabola.
		//! Exceptions Standard_ConstructionError if Focal is negative.
		void SetFocal(Standard_Real Focal);

		//! Converts the gp_Parab parabola Prb into this parabola.
		void SetParab(xgp_Parab^ Prb);


		//! Returns the non transient parabola from gp with the same
		//! geometric properties as <me>.
		xgp_Parab^ Parab();

		//! Computes the parameter on the reversed parabola,
		//! for the point of parameter U on this parabola.
		//! For a parabola, the returned value is: -U.
		Standard_Real ReversedParameter(Standard_Real U) Standard_OVERRIDE;

		//! Returns the value of the first or last parameter of this
		//! parabola. This is, respectively:
		//! - Standard_Real::RealFirst(), or
		//! - Standard_Real::RealLast().
		Standard_Real FirstParameter() Standard_OVERRIDE;

		//! Returns the value of the first or last parameter of this
		//! parabola. This is, respectively:
		//! - Standard_Real::RealFirst(), or
		//! - Standard_Real::RealLast().
		Standard_Real LastParameter() Standard_OVERRIDE;

		//! Returns False
		Standard_Boolean IsClosed() Standard_OVERRIDE;

		//! Returns False
		Standard_Boolean IsPeriodic() Standard_OVERRIDE;

		//! Computes the directrix of this parabola.
		//! This is a line normal to the axis of symmetry, in the
		//! plane of this parabola, located on the negative side
		//! of its axis of symmetry, at a distance from the apex
		//! equal to the focal length.
		//! The directrix is returned as an axis (gp_Ax1 object),
		//! where the origin is located on the "X Axis" of this parabola.
		xgp_Ax1^ Directrix();

		//! Returns 1. (which is the eccentricity of any parabola).
		Standard_Real Eccentricity() Standard_OVERRIDE;

		//! Computes the focus of this parabola. The focus is on the
		//! positive side of the "X Axis" of the local coordinate
		//! system of the parabola.
		xgp_Pnt^ Focus();

		//! Computes the focal distance of this parabola
		//! The focal distance is the distance between the apex
		//! and the focus of the parabola.
		Standard_Real Focal();

		//! Computes the parameter of this parabola which is the
		//! distance between its focus and its directrix. This
		//! distance is twice the focal length.
		//! If P is the parameter of the parabola, the equation of
		//! the parabola in its local coordinate system is: Y**2 = 2.*P*X.
		Standard_Real Parameter();

		//! Returns in P the point of parameter U.
		//! If U = 0 the returned point is the origin of the XAxis and
		//! the YAxis of the parabola and it is the vertex of the parabola.
		//! P = S + F * (U * U * XDir +  * U * YDir)
		//! where S is the vertex of the parabola, XDir the XDirection and
		//! YDir the YDirection of the parabola's local coordinate system.
		void D0(Standard_Real U, xgp_Pnt^ P) Standard_OVERRIDE;


		//! Returns the point P of parameter U and the first derivative V1.
		void D1(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1) Standard_OVERRIDE;


		//! Returns the point P of parameter U, the first and second
		//! derivatives V1 and V2.
		void D2(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2) Standard_OVERRIDE;


		//! Returns the point P of parameter U, the first second and third
		//! derivatives V1 V2 and V3.
		void D3(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2, xgp_Vec^ V3) Standard_OVERRIDE;

		//! For the point of parameter U of this parabola,
		//! computes the vector corresponding to the Nth derivative.
		//! Exceptions Standard_RangeError if N is less than 1.
		xgp_Vec^ DN(Standard_Real U, Standard_Integer N) Standard_OVERRIDE;

		//! Applies the transformation T to this parabola.
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
		Standard_Real TransformedParameter(Standard_Real U, xgp_Trsf^ T) Standard_OVERRIDE;

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
		Standard_Real ParametricTransformation(xgp_Trsf^ T) Standard_OVERRIDE;

		//! Creates a new object which is a copy of this parabola.
		XGeom_Geometry^ Copy() Standard_OVERRIDE;

		//! DEFINE_STANDARD_RTTIEXT(Geom_Parabola,Geom_Conic)
		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property Handle(Standard_Transient) IHandle {
			Handle(Standard_Transient) get() Standard_OVERRIDE {
				return 	NativeHandle();
			}
			void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
				NativeHandle() = Handle(Geom_Parabola)::DownCast(handle);
			}
		}

	private:
		NCollection_Haft<Handle(Geom_Parabola)> NativeHandle;
	};
}
#endif // _XGeom_Parabola_HeaderFile
