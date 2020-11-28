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

#ifndef _XGeom_Direction_HeaderFile
#define _XGeom_Direction_HeaderFile
#pragma once
#include <Geom_Direction.hxx>
#include <NCollection_Haft.h>  
#include <XGeom_Geometry.h>
#include <XGeom_Vector.h>
#include <xgp_Dir.h>
#include <xgp_Trsf.h>	

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <Geom_Vector.hxx>
#include <Standard_Real.hxx>
class Standard_ConstructionError;


using namespace TKMath;
//class Geom_Direction;
//DEFINE_STANDARD_HANDLE(Geom_Direction, Geom_Vector)


//! The class Direction specifies a vector that is never null.
//! It is a unit vector.
//! 
namespace TKG3d {
	ref class TKMath::xgp_Dir;
	ref class TKMath::xgp_Trsf;
	ref class XGeom_Vector;
	ref class XGeom_Geometry;
	public ref class XGeom_Direction : public XGeom_Vector
	{

	public:


		//! Creates a unit vector with it 3 cartesian coordinates.
		//!
		//! Raised if Sqrt( X*X + Y*Y + Z*Z) <= Resolution from gp.
		XGeom_Direction(Standard_Real X, Standard_Real Y, Standard_Real Z);

		//! Creates a transient copy of <me>.
		XGeom_Direction(xgp_Dir^ V);

		//! Sets <me> to X,Y,Z coordinates.
		//!
		//! Raised if Sqrt( X*X + Y*Y + Z*Z) <= Resolution from gp.
		void SetCoord(Standard_Real X, Standard_Real Y, Standard_Real Z);

		//! Converts the gp_Dir unit vector V into this unit vector.
		void SetDir(xgp_Dir^ V);

		//! Changes the X coordinate of <me>.
		//!
		//! Raised if Sqrt( X*X + Y*Y + Z*Z) <= Resolution from gp.
		void SetX(Standard_Real X);

		//! Changes the Y coordinate of <me>.
		//!
		//! Raised if Sqrt( X*X + Y*Y + Z*Z) <= Resolution from gp.
		void SetY(Standard_Real Y);

		//! Changes the Z coordinate of <me>.
		//!
		//! Raised if Sqrt( X*X + Y*Y + Z*Z) <= Resolution from gp.
		void SetZ(Standard_Real Z);


		//! Returns the non transient direction with the same
		//! coordinates as <me>.
		xgp_Dir^ Dir();

		//! returns 1.0 which is the magnitude of any unit vector.
		Standard_Real Magnitude() Standard_OVERRIDE;

		//! returns 1.0 which is the square magnitude of any unit vector.
		Standard_Real SquareMagnitude() Standard_OVERRIDE;


		//! Computes the cross product between <me> and <Other>.
		//!
		//! Raised if the two vectors are parallel because it is
		//! not possible to have a direction with null length.
		void Cross(XGeom_Vector^ Other) Standard_OVERRIDE;


		//! Computes the triple vector product  <me> ^(V1 ^ V2).
		//!
		//! Raised if V1 and V2 are parallel or <me> and (V1 ^ V2) are
		//! parallel
		void CrossCross(XGeom_Vector^ V1, XGeom_Vector^ V2) Standard_OVERRIDE;


		//! Computes the cross product between <me> and <Other>.
		//! A new direction is returned.
		//!
		//! Raised if the two vectors are parallel because it is
		//! not possible to have a direction with null length.
		XGeom_Vector^ Crossed(XGeom_Vector^ Other) Standard_OVERRIDE;


		//! Computes the triple vector product <me> ^(V1 ^ V2).
		//!
		//! Raised if V1 and V2 are parallel or <me> and (V1 ^ V2) are
		//! parallel
		XGeom_Vector^ CrossCrossed(XGeom_Vector^ V1, XGeom_Vector^ V2) Standard_OVERRIDE;

		//! Applies the transformation T to this unit vector, then normalizes it.
		void Transform(xgp_Trsf^ T) Standard_OVERRIDE;

		//! Creates a new object which is a copy of this unit vector.
		XGeom_Geometry^ Copy() Standard_OVERRIDE;




		//! DEFINE_STANDARD_RTTIEXT(Geom_Direction, Geom_Vector)
		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property Handle(Standard_Transient) IHandle {
			Handle(Standard_Transient) get() Standard_OVERRIDE {
				return 	NativeHandle();
			}
			void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
				NativeHandle() = Handle(Geom_Direction)::DownCast(handle);
			}
		}

	private:
		NCollection_Haft<Handle(Geom_Direction)> NativeHandle;
	};
}
#endif // _XGeom_Direction_HeaderFile
