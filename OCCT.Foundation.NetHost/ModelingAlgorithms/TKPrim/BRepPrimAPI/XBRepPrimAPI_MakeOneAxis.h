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

#ifndef _XBRepPrimAPI_MakeOneAxis_HeaderFile
#define _XBRepPrimAPI_MakeOneAxis_HeaderFile
#pragma once
#include <BRepPrimAPI_MakeOneAxis.hxx>
#include <XBRepBuilderAPI_MakeShape.h>
#include <XTopoDS_Face.h>
#include <XTopoDS_Shell.h>
#include <XTopoDS_Solid.h>
#include <XStandard_Helper.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>


#include <BRepBuilderAPI_MakeShape.hxx>
#include <Standard_Address.hxx>
class StdFail_NotDone;

using namespace TKBRep;
using namespace TKTopAlgo;
using namespace TKernel;
namespace TKPrim {
	//! The abstract class MakeOneAxis is the root class of
	//! algorithms used to construct rotational primitives.
	ref class TKBRep::XTopoDS_Face;
	ref class TKBRep::XTopoDS_Shell;
	ref class TKBRep::XTopoDS_Solid;
	ref class  TKernel::XStandard_Helper;
	public ref class XBRepPrimAPI_MakeOneAxis : public XBRepBuilderAPI_MakeShape
	{
	public:

		//! DEFINE_STANDARD_ALLOC

		void SetMakeOneAxisHandle(BRepPrimAPI_MakeOneAxis* handle);

		virtual BRepPrimAPI_MakeOneAxis* GetMakeOneAxis();

		virtual BRepBuilderAPI_MakeShape* GetMakeShape() Standard_OVERRIDE;

		//! The inherited commands should provide the algorithm.
		//! Returned as a pointer.
		virtual Object^ OneAxis();

		//! Stores the solid in myShape.
		virtual void Build() Standard_OVERRIDE;

		//! Returns the lateral face of the rotational primitive.
		XTopoDS_Face^ Face();
		operator XTopoDS_Face^();

		//! Returns the constructed rotational primitive as a shell.
		XTopoDS_Shell^ Shell();
		operator XTopoDS_Shell^();

		//! Returns the constructed rotational primitive as a solid.
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
				NativeHandle = static_cast<BRepPrimAPI_MakeOneAxis*>(handle);
			}
		}

	private:
		BRepPrimAPI_MakeOneAxis* NativeHandle;
	};
}
#endif // _XBRepPrimAPI_MakeOneAxis_HeaderFile
