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

#ifndef _XBRepPrimAPI_MakeSphere_HeaderFile
#define _XBRepPrimAPI_MakeSphere_HeaderFile
#pragma once
#include <XStandard_Helper.h>
#include <BRepPrimAPI_MakeSphere.hxx>
#include <XBRepPrimAPI_MakeOneAxis.h>
#include <XBRepPrim_Sphere.h>
#include <xgp_Pnt.h>
#include <xgp_Ax2.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <BRepPrim_Sphere.hxx>
#include <BRepPrimAPI_MakeOneAxis.hxx>
#include <Standard_Real.hxx>
#include <Standard_Address.hxx>
class Standard_DomainError;
class gp_Pnt;
class gp_Ax2;
class BRepPrim_Sphere;


//! Describes functions to build spheres or portions of spheres.
//! A MakeSphere object provides a framework for:
//! -   defining the construction of a sphere,
//! -   implementing the construction algorithm, and
//! -   consulting the result.
//! 
using namespace TKMath;
using namespace TKernel;
namespace TKPrim {
	ref class XBRepPrim_Sphere;
	ref class TKMath::xgp_Ax2;
	ref class TKMath::xgp_Ax2;
	ref class TKMath::xgp_Vec2d;
	ref class TKernel::XStandard_Helper;
	public ref class XBRepPrimAPI_MakeSphere : public XBRepPrimAPI_MakeOneAxis
	{
	public:

		//! DEFINE_STANDARD_ALLOC
		!XBRepPrimAPI_MakeSphere() { IHandle = NULL; };
		~XBRepPrimAPI_MakeSphere() { IHandle = NULL; };

		XBRepPrimAPI_MakeSphere();

		XBRepPrimAPI_MakeSphere(BRepPrimAPI_MakeSphere* handle);

		void SetMakeSphereHandle(BRepPrimAPI_MakeSphere* handle);

		virtual BRepPrimAPI_MakeSphere* GetMakeSphere();

		virtual BRepPrimAPI_MakeOneAxis* GetMakeOneAxis() Standard_OVERRIDE;

		virtual BRepBuilderAPI_MakeShape* GetMakeShape() Standard_OVERRIDE;

		//! Make a sphere of radius R.
		XBRepPrimAPI_MakeSphere(Standard_Real R);

		//! Make a sphere of radius R.
		XBRepPrimAPI_MakeSphere(Standard_Real R, Standard_Real angle);

		//! Make a sphere of radius R.
		XBRepPrimAPI_MakeSphere(Standard_Real R, Standard_Real angle1, Standard_Real angle2);

		//! Make a sphere of radius R.
		XBRepPrimAPI_MakeSphere(Standard_Real R, Standard_Real angle1, Standard_Real angle2, Standard_Real angle3);

		//! Make a sphere of radius R.
		XBRepPrimAPI_MakeSphere(xgp_Pnt^ Center, Standard_Real R);

		//! Make a sphere of radius R.
		XBRepPrimAPI_MakeSphere(xgp_Pnt^ Center, Standard_Real R, Standard_Real angle);

		//! Make a sphere of radius R.
		XBRepPrimAPI_MakeSphere(xgp_Pnt^ Center, Standard_Real R, Standard_Real angle1, Standard_Real angle2);

		//! Make a sphere of radius R.
		XBRepPrimAPI_MakeSphere(xgp_Pnt^ Center, Standard_Real R, Standard_Real angle1, Standard_Real angle2, Standard_Real angle3);

		//! Make a sphere of radius R.
		XBRepPrimAPI_MakeSphere(xgp_Ax2^ Axis, Standard_Real R);

		//! Make a sphere of radius R.
		XBRepPrimAPI_MakeSphere(xgp_Ax2^ Axis, Standard_Real R, Standard_Real angle);

		//! Make a sphere of radius R.
		XBRepPrimAPI_MakeSphere(xgp_Ax2^ Axis, Standard_Real R, Standard_Real angle1, Standard_Real angle2);

		//! Make a sphere of radius R.
		//! For all algorithms The resulting shape is composed of
		//! -   a lateral spherical face,
		//! -   two planar faces parallel to the plane z = 0 if the
		//! sphere is truncated in the v parametric direction, or
		//! only one planar face if angle1 is equal to -p/2 or if
		//! angle2 is equal to p/2 (these faces are circles in
		//! case of a complete truncated sphere),
		//! -   and in case of a portion of sphere, two planar faces
		//! to shut the shape.(in the planes u = 0 and u = angle).
		XBRepPrimAPI_MakeSphere(xgp_Ax2^ Axis, Standard_Real R, Standard_Real angle1, Standard_Real angle2, Standard_Real angle3);

		//! Returns the algorithm.
		virtual Object^ OneAxis() Standard_OVERRIDE;

		//! Returns the algorithm.
		XBRepPrim_Sphere^ Sphere();

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property BRepBuilderAPI_MakeShape* IHandle {
			BRepBuilderAPI_MakeShape* get() Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepBuilderAPI_MakeShape* handle) Standard_OVERRIDE {
				//NativeHandle = static_cast<BRepPrimAPI_MakeSphere*>(handle);
				if (handle == NULL)
					NativeHandle = static_cast<BRepPrimAPI_MakeSphere*>(handle);
				else
					NativeHandle = NULL;
			}
		}

	private:
		BRepPrimAPI_MakeSphere* NativeHandle;
	};
}
#endif // _XBRepPrimAPI_MakeSphere_HeaderFile
