// Created on: 1993-07-21
// Created by: Remi LEQUETTE
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

#ifndef _XBRepPrimAPI_MakeTorus_HeaderFile
#define _XBRepPrimAPI_MakeTorus_HeaderFile
#pragma once
#include <XStandard_Helper.h>
#include <BRepPrimAPI_MakeTorus.hxx>
#include <XBRepPrimAPI_MakeOneAxis.h>
#include <XBRepPrim_Torus.h>
#include <xgp_Pnt.h>
#include <xgp_Ax2.h>


#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <BRepPrim_Torus.hxx>
#include <BRepPrimAPI_MakeOneAxis.hxx>
#include <Standard_Real.hxx>
#include <Standard_Address.hxx>
class Standard_DomainError;
class gp_Ax2;
class BRepPrim_Torus;


//! Describes functions to build tori or portions of tori.
//! A MakeTorus object provides a framework for:
//! -   defining the construction of a torus,
//! -   implementing the construction algorithm, and
//! -   consulting the result.
using namespace TKMath;
using namespace TKernel;
namespace TKPrim {
	ref class XBRepPrim_Revolution;
	ref class TKMath::xgp_Ax2;
	ref class TKernel::XStandard_Helper;
	public ref class XBRepPrimAPI_MakeTorus : public XBRepPrimAPI_MakeOneAxis
	{
	public:

		//! DEFINE_STANDARD_ALLOC


		XBRepPrimAPI_MakeTorus();

		XBRepPrimAPI_MakeTorus(BRepPrimAPI_MakeTorus* handle);

		void SetMakeTorusHandle(BRepPrimAPI_MakeTorus* handle);

		virtual BRepPrimAPI_MakeTorus* GetMakeTorus();

		virtual BRepPrimAPI_MakeOneAxis* GetMakeOneAxis() Standard_OVERRIDE;

		virtual BRepBuilderAPI_MakeShape* GetMakeShape() Standard_OVERRIDE;

		//! Make a torus of radii R1 R2.
		XBRepPrimAPI_MakeTorus(Standard_Real R1, Standard_Real R2);

		//! Make a section of a torus of radii R1 R2.
		XBRepPrimAPI_MakeTorus(Standard_Real R1, Standard_Real R2, Standard_Real angle);

		//! Make  a torus of  radii R2, R2  with angles on the
		//! small circle.
		XBRepPrimAPI_MakeTorus(Standard_Real R1, Standard_Real R2, Standard_Real angle1, Standard_Real angle2);

		//! Make  a torus of  radii R2, R2  with angles on the
		//! small circle.
		XBRepPrimAPI_MakeTorus(Standard_Real R1, Standard_Real R2, Standard_Real angle1, Standard_Real angle2, Standard_Real angle);

		//! Make a torus of radii R1 R2.
		XBRepPrimAPI_MakeTorus(xgp_Ax2^ Axes, Standard_Real R1, Standard_Real R2);

		//! Make a section of a torus of radii R1 R2.
		XBRepPrimAPI_MakeTorus(xgp_Ax2^ Axes, Standard_Real R1, Standard_Real R2, Standard_Real angle);

		//! Make a torus of radii R1 R2.
		XBRepPrimAPI_MakeTorus(xgp_Ax2^ Axes, Standard_Real R1, Standard_Real R2, Standard_Real angle1, Standard_Real angle2);

		//! Make a section of a torus of radii R1 R2.
		//! For all algorithms The resulting shape is composed of
		//! -      a lateral toroidal face,
		//! -      two conical faces (defined  by the equation v = angle1 and
		//! v = angle2) if the sphere is truncated in the v parametric
		//! direction (they may be cylindrical faces in some
		//! particular conditions), and in case of a portion
		//! of torus, two planar faces to close the shape.(in the planes
		//! u = 0 and u = angle).
		//! Notes:
		//! -      The u parameter corresponds to a rotation angle around the Z axis.
		//! -      The circle whose radius is equal to the minor radius,
		//! located in the plane defined by the X axis and the Z axis,
		//! centered on the X axis, on its positive side, and positioned
		//! at a distance from the origin equal to the major radius, is
		//! the reference circle of the torus. The rotation around an
		//! axis parallel to the Y axis and passing through the center
		//! of the reference circle gives the v parameter on the
		//! reference circle. The X axis gives the origin of the v
		//! parameter. Near 0, as v increases, the Z coordinate decreases.
		XBRepPrimAPI_MakeTorus(xgp_Ax2^ Axes, Standard_Real R1, Standard_Real R2, Standard_Real angle1, Standard_Real angle2, Standard_Real angle);

		//! Returns the algorithm.
		virtual Object^ OneAxis() Standard_OVERRIDE;

		//! Returns the algorithm.
		XBRepPrim_Torus^ Torus();

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property BRepBuilderAPI_MakeShape* IHandle {
			BRepBuilderAPI_MakeShape* get() Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepBuilderAPI_MakeShape* handle) Standard_OVERRIDE {
				NativeHandle = static_cast<BRepPrimAPI_MakeTorus*>(handle);
			}
		}

	private:
		BRepPrimAPI_MakeTorus* NativeHandle;
	};
}
#endif // _XBRepPrimAPI_MakeTorus_HeaderFile
