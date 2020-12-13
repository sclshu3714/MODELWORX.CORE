// Created on: 1992-09-28
// Created by: Remi GILET
// Copyright (c) 1992-1999 Matra Datavision
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

#ifndef _XGC_MakeCircle_HeaderFile
#define _XGC_MakeCircle_HeaderFile
#pragma once
#include <XGC_Root.h>
#include <GC_MakeCircle.hxx>
#include <XGeom_TrimmedCurve.h>
#include <XGeom_Circle.h>
#include <xgp_Circ.h>
#include <xgp_Ax2.h >
#include <xgp_Pnt.h >
#include <xgp_Dir.h >
#include <xgp_Ax1.h >

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <GC_Root.hxx>
#include <Geom_Circle.hxx>

class StdFail_NotDone;
class gp_Circ;
class gp_Ax2;
class gp_Pnt;
class gp_Dir;
class gp_Ax1;

using namespace TKMath;
using namespace TKG3d;
namespace TKGeomBase {
	ref class TKMath::xgp_Circ;
	ref class TKMath::xgp_Ax2;
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Dir;
	ref class TKMath::xgp_Ax1;
	ref class TKG3d::XGeom_TrimmedCurve;
	ref class TKG3d::XGeom_Circle;
	//! This class implements the following algorithms used
	//! to create Cirlec from Geom.
	//!
	//! * Create a Circle parallel to another and passing
	//! though a point.
	//! * Create a Circle parallel to another at the distance
	//! Dist.
	//! * Create a Circle passing through 3 points.
	//! * Create a Circle with its center and the normal of its
	//! plane and its radius.
	//! * Create a Circle with its axis and radius.
	//! The circle's parameter is the angle (Radian).
	//! The parametrization range is [0,2*PI].
	//! The circle is a closed and periodic curve.
	//! The center of the circle is the Location point of its axis
	//! placement. The XDirection of the axis placement defines the
	//! origin of the parametrization.
	public ref class XGC_MakeCircle : public XGC_Root
	{
	public:

		//! DEFINE_STANDARD_ALLOC
		XGC_MakeCircle(GC_MakeCircle* pos);

		void SetMakeCircleHandle(GC_MakeCircle* pos);

		GC_MakeCircle* GetMakeCircle();

		//! creates a circle from a non persistent circle C by its conversion.
		XGC_MakeCircle(xgp_Circ^ C);


		//! A2 is the local coordinates system of the circle.
		//! It is not forbidden to create a circle with Radius = 0.0
		//! Status is "NegativeRadius" if Radius < 0.
		XGC_MakeCircle(xgp_Ax2^ A2, Standard_Real Radius);

		//! Make a Circle from Geom <TheCirc> parallel to another
		//! Circ <Circ> with a distance <Dist>.
		//! If Dist is greater than zero the result is enclosing
		//! the circle <Circ>, else the result is enclosed by the
		//! circle <Circ>.
		XGC_MakeCircle(xgp_Circ^ Circ, Standard_Real Dist);

		//! Make a Circle from Geom <TheCirc> parallel to another
		//! Circ <Circ> and passing through a Pnt <Point>.
		XGC_MakeCircle(xgp_Circ^ Circ, xgp_Pnt^ Point);

		//! Make a Circ from gp <TheCirc> passing through 3
		//! Pnt2d <P1>,<P2>,<P3>.
		XGC_MakeCircle(xgp_Pnt^ P1, xgp_Pnt^ P2, xgp_Pnt^ P3);

		//! Make a Circle from Geom <TheCirc> with its center
		//! <Center> and the normal of its plane <Norm> and
		//! its radius <Radius>.
		XGC_MakeCircle(xgp_Pnt^ Center, xgp_Dir^ Norm, Standard_Real Radius);

		//! Make a Circle from Geom <TheCirc> with its center
		//! <Center> and the normal of its plane defined by the
		//! two points <Center> and <PtAxis> and its radius <Radius>.
		XGC_MakeCircle(xgp_Pnt^ Center, xgp_Pnt^ PtAxis, Standard_Real Radius);

		//! Make a Circle from Geom <TheCirc> with its center
		//! <Center> and its radius <Radius>.
		XGC_MakeCircle(xgp_Ax1^ Axis, Standard_Real Radius);


		//! Returns the constructed circle.
		//! Exceptions
		//! StdFail_NotDone if no circle is constructed.
		XGeom_Circle^ Value();

		operator XGeom_Circle^() { return Value(); }

		//! Returns true if the construction is successful.
		virtual Standard_Boolean IsDone() Standard_OVERRIDE;

		//! Returns the status of the construction:
		//! -   gce_Done, if the construction is successful, or
		//! -   another value of the gce_ErrorType enumeration
		//! indicating why the construction failed.
		virtual xgce_ErrorType Status() Standard_OVERRIDE;

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property  GC_MakeCircle* IHandle {
			GC_MakeCircle* get() {
				return 	NativeHandle;
			}
			void set(GC_MakeCircle* handle) {
				NativeHandle = handle;
			}
		}

	private:
		GC_MakeCircle* NativeHandle;
	};
}
#endif // _XGC_MakeCircle_HeaderFile
