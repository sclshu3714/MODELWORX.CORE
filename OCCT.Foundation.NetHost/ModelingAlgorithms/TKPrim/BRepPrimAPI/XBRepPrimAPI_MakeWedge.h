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

#ifndef _XBRepPrimAPI_MakeWedge_HeaderFile
#define _XBRepPrimAPI_MakeWedge_HeaderFile
#pragma once
#include <XStandard_Helper.h>
#include <BRepPrimAPI_MakeWedge.hxx>
#include <XBRepPrimAPI_MakeOneAxis.h>
#include <XBRepPrim_Wedge.h>
#include <xgp_Pnt.h>
#include <xgp_Ax2.h>


#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <BRepPrim_Wedge.hxx>
#include <BRepBuilderAPI_MakeShape.hxx>
#include <Standard_Real.hxx>
class Standard_DomainError;
class StdFail_NotDone;
class gp_Ax2;
class BRepPrim_Wedge;
class TopoDS_Shell;
class TopoDS_Solid;


//! Describes functions to build wedges, i.e. boxes with inclined faces.
//! A MakeWedge object provides a framework for:
//! -   defining the construction of a wedge,
//! -   implementing the construction algorithm, and
//! -   consulting the result.
//! 
using namespace TKMath;
using namespace TKernel;
namespace TKPrim {
	ref class XBRepPrim_Revolution;
	ref class TKMath::xgp_Ax2;
	ref class TKernel::XStandard_Helper;
	public ref class XBRepPrimAPI_MakeWedge : public XBRepBuilderAPI_MakeShape
	{
	public:
		!XBRepPrimAPI_MakeWedge() { IHandle = NULL; };
		~XBRepPrimAPI_MakeWedge() { IHandle = NULL; };
		//! DEFINE_STANDARD_ALLOC
		XBRepPrimAPI_MakeWedge();

		XBRepPrimAPI_MakeWedge(BRepPrimAPI_MakeWedge* handle);

		void SetMakeWedgeHandle(BRepPrimAPI_MakeWedge* handle);

		virtual BRepPrimAPI_MakeWedge* GetMakeWedge();

		virtual BRepBuilderAPI_MakeShape* GetMakeShape() Standard_OVERRIDE;

		//! Make a STEP right angular wedge. (ltx >= 0)
		XBRepPrimAPI_MakeWedge(Standard_Real dx, Standard_Real dy, Standard_Real dz, Standard_Real ltx);

		//! Make a STEP right angular wedge. (ltx >= 0)
		XBRepPrimAPI_MakeWedge(xgp_Ax2^ Axes, Standard_Real dx, Standard_Real dy, Standard_Real dz, Standard_Real ltx);

		//! Make a wedge. The face at dy is xmin,zmin xmax,zmax
		XBRepPrimAPI_MakeWedge(Standard_Real dx, Standard_Real dy, Standard_Real dz, Standard_Real xmin, Standard_Real zmin, Standard_Real xmax, Standard_Real zmax);

		//! Make a wedge. The face at dy is xmin,zmin xmax,zmax
		XBRepPrimAPI_MakeWedge(xgp_Ax2^ Axes, Standard_Real dx, Standard_Real dy, Standard_Real dz, Standard_Real xmin, Standard_Real zmin, Standard_Real xmax, Standard_Real zmax);

		//! Returns the internal algorithm.
		XBRepPrim_Wedge^ Wedge();

		//! Stores the solid in myShape.
		virtual void Build() Standard_OVERRIDE;

		//! Returns the constructed box in the form of a shell.
		XTopoDS_Shell^ Shell();
		operator XTopoDS_Shell^();

		//! Returns the constructed box in the form of a solid.
		XTopoDS_Solid^ Solid();
		operator XTopoDS_Solid^();

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property BRepBuilderAPI_MakeShape* IHandle {
			BRepBuilderAPI_MakeShape* get() Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepBuilderAPI_MakeShape* handle) Standard_OVERRIDE {
				//NativeHandle = static_cast<BRepPrimAPI_MakeWedge*>(handle);
				if (handle == NULL)
					NativeHandle = static_cast<BRepPrimAPI_MakeWedge*>(handle);
				else
					NativeHandle = NULL;
			}
		}

	private:
		BRepPrimAPI_MakeWedge* NativeHandle;
	};
}
#endif // _XBRepPrimAPI_MakeWedge_HeaderFile
