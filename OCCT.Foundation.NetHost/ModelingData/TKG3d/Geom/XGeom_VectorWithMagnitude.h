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

#ifndef _XGeom_VectorWithMagnitude_HeaderFile
#define _XGeom_VectorWithMagnitude_HeaderFile
#pragma once
#include <Geom_VectorWithMagnitude.hxx>
#include <XGeom_Vector.h>
#include <XGeom_Geometry.h>
#include <xgp_Vec.h>
#include <xgp_Pnt.h>
#include <XGeom_Vector.h>
#include <xgp_Trsf.h>

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <Geom_Vector.hxx>
#include <Standard_Real.hxx>
class Standard_ConstructionError;
class gp_Vec;
class gp_Pnt;
class Geom_Vector;
class gp_Trsf;
class Geom_Geometry;
class Geom_VectorWithMagnitude;
//DEFINE_STANDARD_HANDLE(Geom_VectorWithMagnitude, Geom_Vector)

using namespace TKMath;
namespace TKG3d {
	ref class TKMath::xgp_Vec;
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Trsf;
	ref class XGeom_Vector;
	ref class XGeom_Geometry;
	//! Defines a vector with magnitude.
	//! A vector with magnitude can have a zero length.
	public ref class XGeom_VectorWithMagnitude : public XGeom_Vector
	{

	public:
		!XGeom_VectorWithMagnitude() { IHandle = NULL; };
		~XGeom_VectorWithMagnitude() { IHandle = NULL; };

		XGeom_VectorWithMagnitude();

		XGeom_VectorWithMagnitude(Handle(Geom_VectorWithMagnitude) pos);

		void SetVectorWithMagnitudeHandle(Handle(Geom_VectorWithMagnitude) handle);

		virtual Handle(Geom_VectorWithMagnitude) GetVectorWithMagnitude();

		virtual Handle(Geom_Vector) GetVector() Standard_OVERRIDE;

		//!
		virtual Handle(Geom_Geometry) GetGeometry() Standard_OVERRIDE;

		//! Creates a transient copy of V.
		XGeom_VectorWithMagnitude(xgp_Vec^ V);

		//! Creates a vector with three cartesian coordinates.
		XGeom_VectorWithMagnitude(Standard_Real X, Standard_Real Y, Standard_Real Z);


		//! Creates a vector from the point P1 to the point P2.
		//! The magnitude of the vector is the distance between P1 and P2
		XGeom_VectorWithMagnitude(xgp_Pnt^ P1, xgp_Pnt^ P2);

		//! Assigns the values X, Y and Z to the coordinates of this vector.
		void SetCoord(Standard_Real X, Standard_Real Y, Standard_Real Z);

		//! Converts the gp_Vec vector V into this vector.
		void SetVec(xgp_Vec^ V);

		//! Changes the X coordinate of <me>.
		void SetX(Standard_Real X);

		//! Changes the Y coordinate of <me>
		void SetY(Standard_Real Y);

		//! Changes the Z coordinate of <me>.
		void SetZ(Standard_Real Z);

		//! Returns the magnitude of <me>.
		Standard_Real Magnitude() Standard_OVERRIDE;

		//! Returns the square magnitude of <me>.
		Standard_Real SquareMagnitude() Standard_OVERRIDE;


		//! Adds the Vector Other to <me>.
		void Add(XGeom_Vector^ Other);


		//! Adds the vector Other to <me>.
		XGeom_VectorWithMagnitude^ Added(XGeom_Vector^ Other);


		//! Computes the cross product  between <me> and Other
		//! <me> ^ Other.
		void Cross(XGeom_Vector^ Other) Standard_OVERRIDE;


		//! Computes the cross product  between <me> and Other
		//! <me> ^ Other. A new vector is returned.
		XGeom_Vector^ Crossed(XGeom_Vector^ Other) Standard_OVERRIDE;


		//! Computes the triple vector product  <me> ^ (V1 ^ V2).
		void CrossCross(XGeom_Vector^ V1, XGeom_Vector^ V2) Standard_OVERRIDE;


		//! Computes the triple vector product  <me> ^ (V1 ^ V2).
		//! A new vector is returned.
		XGeom_Vector^ CrossCrossed(XGeom_Vector^ V1, XGeom_Vector^ V2) Standard_OVERRIDE;

		//! Divides <me> by a scalar.
		void Divide(Standard_Real Scalar);


		//! Divides <me> by a scalar. A new vector is returned.
		XGeom_VectorWithMagnitude^ Divided(Standard_Real Scalar);


		//! Computes the product of the vector <me> by a scalar.
		//! A new vector is returned.
		XGeom_VectorWithMagnitude^ Multiplied(Standard_Real Scalar);


		//! Computes the product of the vector <me> by a scalar.
		void Multiply(Standard_Real Scalar);

		//! Normalizes <me>.
		//!
		//! Raised if the magnitude of the vector is lower or equal to
		//! Resolution from package gp.
		void Normalize();

		//! Returns a copy of <me> Normalized.
		//!
		//! Raised if the magnitude of the vector is lower or equal to
		//! Resolution from package gp.
		XGeom_VectorWithMagnitude^ Normalized();

		//! Subtracts the Vector Other to <me>.
		void Subtract(XGeom_Vector^ Other);


		//! Subtracts the vector Other to <me>. A new vector is returned.
		XGeom_VectorWithMagnitude^ Subtracted(XGeom_Vector^ Other);

		//! Applies the transformation T to this vector.
		void Transform(xgp_Trsf^ T) Standard_OVERRIDE;

		//! Creates a new object which is a copy of this vector.
		XGeom_Geometry^ Copy() Standard_OVERRIDE;

		//! DEFINE_STANDARD_RTTIEXT(Geom_VectorWithMagnitude, Geom_Vector)
			/// <summary>
			/// ±¾µØ¾ä±ú
			/// </summary>
		virtual property Handle(Standard_Transient) IHandle {
			Handle(Standard_Transient) get() Standard_OVERRIDE {
				return 	NativeHandle();
			}
			void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
				NativeHandle() = Handle(Geom_VectorWithMagnitude)::DownCast(handle);
			}
		}

	private:
		NCollection_Haft<Handle(Geom_VectorWithMagnitude)> NativeHandle;
	};
}
#endif // _XGeom_VectorWithMagnitude_HeaderFile
