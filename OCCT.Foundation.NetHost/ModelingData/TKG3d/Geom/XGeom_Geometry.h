// Created on: 1993-03-09
// Created by: JVC
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
//! The abstract class Geometry for 3D space is the root
//! class of all geometric objects from the Geom
//! package. It describes the common behavior of these objects when:
//! - applying geometric transformations to objects, and
//! - constructing objects by geometric transformation (including copying).
//! Warning
//! Only transformations which do not modify the nature
//! of the geometry can be applied to Geom objects: this
//! is the case with translations, rotations, symmetries
//! and scales; this is also the case with gp_Trsf
//! composite transformations which are used to define
//! the geometric transformations applied using the
//! Transform or Transformed functions.
//! Note: Geometry defines the "prototype" of the
//! abstract method Transform which is defined for each
//! concrete type of derived object. All other
//! transformations are implemented using the Transform method.

#pragma once
#include "Geom_Geometry.hxx"
#include "Standard_ConstructionError.hxx"
#include "xgp_Pnt.h"
#include "xgp_Ax1.h"
#include "xgp_Ax2.h"
#include "xgp_Vec.h"
#include "xgp_Trsf.h"

using namespace TKMath;
namespace TKG3d
{
	ref class XStandard_ConstructionError;
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Ax1;
	ref class TKMath::xgp_Ax2;
	ref class TKMath::xgp_Vec;
	ref class TKMath::xgp_Trsf;
	public ref class XGeom_Geometry
	{

	public:

		//! 
		XGeom_Geometry(void);

		//! 
		XGeom_Geometry(Geom_Geometry* pos);

		//!
		~XGeom_Geometry();

		//!
		Handle(Geom_Geometry) GetGeometry();

		//! Performs the symmetrical transformation of a Geometry
		//! with respect to the point P which is the center of the
		//! symmetry.
		void Mirror(xgp_Pnt^ P);


		//! Performs the symmetrical transformation of a Geometry
		//! with respect to an axis placement which is the axis of the
		//! symmetry.
		void Mirror(xgp_Ax1^ A1);


		//! Performs the symmetrical transformation of a Geometry
		//! with respect to a plane. The axis placement A2 locates
		//! the plane of the symmetry : (Location, XDirection, YDirection).
		void Mirror(xgp_Ax2^ A2);


		//! Rotates a Geometry. A1 is the axis of the rotation.
		//! Ang is the angular value of the rotation in radians.
		void Rotate(xgp_Ax1^ A1, Standard_Real Ang);


		//! Scales a Geometry. S is the scaling value.
		void Scale(xgp_Pnt^ P, Standard_Real S);


		//! Translates a Geometry.  V is the vector of the tanslation.
		void Translate(xgp_Vec^ V);


		//! Translates a Geometry from the point P1 to the point P2.
		void Translate(xgp_Pnt^ P1, xgp_Pnt^ P2);


		//! Transformation of a geometric object. This tansformation
		//! can be a translation, a rotation, a symmetry, a scaling
		//! or a complex transformation obtained by combination of
		//! the previous elementaries transformations.
		//! (see class Transformation of the package Geom).
		virtual void Transform(xgp_Trsf^ T) = 0;

		Handle(Geom_Geometry) Mirrored(xgp_Pnt^ P);

		Handle(Geom_Geometry) Mirrored(xgp_Ax1^ A1);

		Handle(Geom_Geometry) Mirrored(xgp_Ax2^ A2);

		Handle(Geom_Geometry) Rotated(xgp_Ax1^ A1, Standard_Real Ang);

		Handle(Geom_Geometry) Scaled(xgp_Pnt^ P, Standard_Real S);
		
		Handle(Geom_Geometry) Transformed(xgp_Trsf^ T);

		Handle(Geom_Geometry) Translated(xgp_Vec^ V);

		Handle(Geom_Geometry) Translated(xgp_Pnt^ P1, xgp_Pnt^ P2);

		//! Creates a new object which is a copy of this geometric object.
		virtual Handle(Geom_Geometry) Copy();



	protected:
		Geom_Geometry* GeomNativeHandle;
	};
}
