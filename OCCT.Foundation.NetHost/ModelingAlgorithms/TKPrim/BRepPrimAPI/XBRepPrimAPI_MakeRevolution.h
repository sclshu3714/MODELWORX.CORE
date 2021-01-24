// Created on: 1993-07-22
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

#ifndef _XBRepPrimAPI_MakeRevolution_HeaderFile
#define _XBRepPrimAPI_MakeRevolution_HeaderFile
#pragma once
#include <XStandard_Helper.h>
#include <BRepPrimAPI_MakeRevolution.hxx>
#include <XBRepPrimAPI_MakeOneAxis.h>
#include <XBRepPrim_Revolution.h>
#include <XGeom_Curve.h>
#include <xgp_Ax2.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <BRepPrim_Revolution.hxx>
#include <BRepPrimAPI_MakeOneAxis.hxx>
#include <Standard_Real.hxx>
#include <Standard_Address.hxx>
class Standard_DomainError;
class Geom_Curve;
class gp_Ax2;
class BRepPrim_Revolution;

using namespace TKMath;
using namespace TKernel;
namespace TKPrim {
	ref class XBRepPrim_Revolution;
	ref class TKMath::xgp_Ax2;
	ref class TKMath::xgp_Vec2d;
	ref class TKernel::XStandard_Helper;
	//! Describes functions to build revolved shapes.
	//! A MakeRevolution object provides a framework for:
	//! -   defining the construction of a revolved shape,
	//! -   implementing the construction algorithm, and
	//! -   consulting the result.
	public ref class XBRepPrimAPI_MakeRevolution : public XBRepPrimAPI_MakeOneAxis
	{
	public:

		//! DEFINE_STANDARD_ALLOC
		!XBRepPrimAPI_MakeRevolution() { IHandle = NULL; };
		~XBRepPrimAPI_MakeRevolution() { IHandle = NULL; };
		XBRepPrimAPI_MakeRevolution();

		XBRepPrimAPI_MakeRevolution(BRepPrimAPI_MakeRevolution* handle);

		void SetMakeRevolutionHandle(BRepPrimAPI_MakeRevolution* handle);

		virtual BRepPrimAPI_MakeRevolution* GetMakeRevolution();

		virtual BRepPrimAPI_MakeOneAxis* GetMakeOneAxis() Standard_OVERRIDE;

		virtual BRepBuilderAPI_MakeShape* GetMakeShape() Standard_OVERRIDE;

		//! Make a revolution body by rotating a curve around Z.
		XBRepPrimAPI_MakeRevolution(XGeom_Curve^ Meridian);

		//! Make a revolution body by rotating a curve around Z.
		XBRepPrimAPI_MakeRevolution(XGeom_Curve^ Meridian, Standard_Real angle);

		//! Make a revolution body by rotating a curve around Z.
		XBRepPrimAPI_MakeRevolution(XGeom_Curve^ Meridian, Standard_Real VMin, Standard_Real VMax);

		//! Make a revolution body by rotating a curve around Z.
		XBRepPrimAPI_MakeRevolution(XGeom_Curve^ Meridian, Standard_Real VMin, Standard_Real VMax, Standard_Real angle);

		//! Make a revolution body by rotating a curve around Z.
		XBRepPrimAPI_MakeRevolution(xgp_Ax2^ Axes, XGeom_Curve^ Meridian);

		//! Make a revolution body by rotating a curve around Z.
		XBRepPrimAPI_MakeRevolution(xgp_Ax2^ Axes, XGeom_Curve^ Meridian, Standard_Real angle);

		//! Make a revolution body by rotating a curve around Z.
		XBRepPrimAPI_MakeRevolution(xgp_Ax2^ Axes, XGeom_Curve^ Meridian, Standard_Real VMin, Standard_Real VMax);

		//! Make a revolution body by rotating a curve around Z.
		//! For all algorithms the resulting shape is composed of
		//! -   a lateral revolved face,
		//! -   two planar faces in planes parallel to the plane z =
		//! 0, and passing by the extremities of the revolved
		//! portion of Meridian, if these points are not on the Z
		//! axis (in case of a complete revolved shape, these faces are circles),
		//! -   and in the case of a portion of a revolved shape, two
		//! planar faces to close the shape (in the planes u = 0 and u = angle).
		XBRepPrimAPI_MakeRevolution(xgp_Ax2^ Axes, XGeom_Curve^ Meridian, Standard_Real VMin, Standard_Real VMax, Standard_Real angle);

		//! Returns the algorithm.
		virtual Object^ OneAxis() Standard_OVERRIDE;

		//! Returns the algorithm.
		XBRepPrim_Revolution^ Revolution();

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property BRepBuilderAPI_MakeShape* IHandle {
			BRepBuilderAPI_MakeShape* get() Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepBuilderAPI_MakeShape* handle) Standard_OVERRIDE {
				//NativeHandle = static_cast<BRepPrimAPI_MakeRevolution*>(handle);
				if (handle == NULL)
					NativeHandle = static_cast<BRepPrimAPI_MakeRevolution*>(handle);
				else
					NativeHandle = NULL;
			}
		}

	private:
		BRepPrimAPI_MakeRevolution* NativeHandle;
	};
}
#endif // _XBRepPrimAPI_MakeRevolution_HeaderFile
