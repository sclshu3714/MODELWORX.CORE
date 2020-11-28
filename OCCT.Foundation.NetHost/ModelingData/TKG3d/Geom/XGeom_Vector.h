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

#ifndef _XGeom_Vector_HeaderFile
#define _XGeom_Vector_HeaderFile
#pragma once
#include <Geom_Vector.hxx>
#include <xgp_Vec.h>
#include <XGeom_Geometry.h>


#include <Standard.hxx>
#include <Standard_Type.hxx>
#include <gp_Vec.hxx>
#include <Geom_Geometry.hxx>
#include <Standard_Real.hxx>
class Standard_ConstructionError;
class Standard_DomainError;
class gp_VectorWithNullMagnitude;
class gp_Vec;

using namespace TKMath;
//class Geom_Vector;
//DEFINE_STANDARD_HANDLE(Geom_Vector, Geom_Geometry)
namespace TKG3d {
	//! The abstract class Vector describes the common
	//! behavior of vectors in 3D space.
	//! The Geom package provides two concrete classes of
	//! vectors: Geom_Direction (unit vector) and Geom_VectorWithMagnitude.
	ref class TKMath::xgp_Vec;
	public ref class XGeom_Vector : public XGeom_Geometry
	{

	public:

		XGeom_Vector();

		XGeom_Vector(Handle(Geom_Vector) pos);

		void SetVectorHandle(Handle(Geom_Vector) handle);

		Handle(Geom_Vector) GetVector();
		//! Reverses the vector <me>.
		void Reverse();

		//! Returns a copy of <me> reversed.
		XGeom_Vector^ Reversed();

		//! Computes the angular value, in radians, between this
		//! vector and vector Other. The result is a value between 0 and Pi.
		//! Exceptions
		//! gp_VectorWithNullMagnitude if:
		//! - the magnitude of this vector is less than or equal to
		//! gp::Resolution(), or
		//! - the magnitude of vector Other is less than or equal
		//! to gp::Resolution().
		Standard_Real Angle(XGeom_Vector^ Other);

		//! Computes the angular value, in radians, between this
		//! vector and vector Other. The result is a value
		//! between -Pi and Pi. The vector VRef defines the
		//! positive sense of rotation: the angular value is positive
		//! if the cross product this ^ Other has the same
		//! orientation as VRef (in relation to the plane defined
		//! by this vector and vector Other). Otherwise, it is negative.
		//! Exceptions
		//! Standard_DomainError if this vector, vector Other
		//! and vector VRef are coplanar, except if this vector
		//! and vector Other are parallel.
		//! gp_VectorWithNullMagnitude if the magnitude of
		//! this vector, vector Other or vector VRef is less than
		//! or equal to gp::Resolution().
		Standard_Real AngleWithRef(XGeom_Vector^ Other, XGeom_Vector^ VRef);

		//! Returns the coordinates X, Y and Z of this vector.
		void Coord(Standard_Real X, Standard_Real Y, Standard_Real Z);

		//! Returns the  Magnitude of <me>.
		virtual Standard_Real Magnitude();

		//! Returns the square magnitude of <me>.
		virtual Standard_Real SquareMagnitude();

		//! Returns the X coordinate of <me>.
		Standard_Real X();

		//! Returns the Y coordinate of <me>.
		Standard_Real Y();

		//! Returns the Z coordinate of <me>.
		Standard_Real Z();


		//! Computes the cross product between <me> and <Other>.
		//!
		//! Raised if <me> is a "Direction" and if <me> and <Other>
		//! are parallel because it is not possible to build a
		//! "Direction" with null length.
		virtual void Cross(XGeom_Vector^ Other);


		//! Computes the cross product between <me> and <Other>.
		//! A new direction is returned.
		//!
		//! Raised if <me> is a "Direction" and if the two vectors
		//! are parallel because it is not possible to create a
		//! "Direction" with null length.
		virtual XGeom_Vector^ Crossed(XGeom_Vector^ Other);


		//! Computes the triple vector product  <me> ^(V1 ^ V2).
		//!
		//! Raised if <me> is a "Direction" and if V1 and V2 are parallel
		//! or <me> and (V1 ^ V2) are  parallel
		virtual void CrossCross(XGeom_Vector^ V1, XGeom_Vector^ V2);


		//! Computes the triple vector product <me> ^(V1 ^ V2).
		//!
		//! Raised if <me> is a direction and if V1 and V2 are
		//! parallel or <me> and (V1 ^ V2) are parallel
		virtual XGeom_Vector^ CrossCrossed(XGeom_Vector^ V1, XGeom_Vector^ V2);

		//! Computes the scalar product of this vector and vector Other.
		Standard_Real Dot(XGeom_Vector^ Other);


		//! Computes the triple scalar product. Returns me . (V1 ^ V2)
		Standard_Real DotCross(XGeom_Vector^ V1,XGeom_Vector^ V2);

		//! Converts this vector into a gp_Vec vector.
		xgp_Vec^ Vec();

		//! DEFINE_STANDARD_RTTIEXT(Geom_Vector, Geom_Geometry)
		//! 
		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property Handle(Standard_Transient) Handle {
			Handle(Standard_Transient) get() Standard_OVERRIDE {
				return 	NativeHandle();
			}
		}

	private:
		NCollection_Haft<Handle(Geom_Vector)> NativeHandle;
	};
}
#endif // _XGeom_Vector_HeaderFile
