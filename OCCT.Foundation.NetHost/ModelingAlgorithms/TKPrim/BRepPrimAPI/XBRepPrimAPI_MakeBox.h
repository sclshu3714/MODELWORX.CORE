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

#ifndef _XBRepPrimAPI_MakeBox_HeaderFile
#define _XBRepPrimAPI_MakeBox_HeaderFile
#pragma once
#include <BRepPrimAPI_MakeBox.hxx>
#include <XStandard_Helper.h>
#include <XBRepBuilderAPI_MakeShape.h>
#include <XBRepPrim_Wedge.h>
#include <XTopoDS_Face.h>
#include <XTopoDS_Shell.h>
#include <XTopoDS_Solid.h>
#include <xgp_Pnt.h>
#include <xgp_Ax2.h>


#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Real.hxx>
#include <gp_Vec2d.hxx>
class gp_Vec2d;
class Standard_DomainError;
class Standard_OutOfRange;
class StdFail_NotDone;


//! Describes functions to build parallelepiped boxes.
//! A MakeBox object provides a framework for:
//! -   defining the construction of a box,
//! -   implementing the construction algorithm, and
//! -   consulting the result.
using namespace TKBRep;
using namespace TKTopAlgo;
using namespace TKernel;
using namespace TKMath;
namespace TKPrim {
	ref class XBRepPrim_Wedge;
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Ax2;
	ref class TKBRep::XTopoDS_Face;
	ref class TKBRep::XTopoDS_Shell;
	ref class TKBRep::XTopoDS_Solid;
	ref class  TKernel::XStandard_Helper;
	public ref class XBRepPrimAPI_MakeBox : public XBRepBuilderAPI_MakeShape
	{
	public:

		!XBRepPrimAPI_MakeBox() { IHandle = NULL; };
		~XBRepPrimAPI_MakeBox() { IHandle = NULL; };
		//! DEFINE_STANDARD_ALLOC
		XBRepPrimAPI_MakeBox(BRepPrimAPI_MakeBox* handle);

		void SetMakeBoxHandle(BRepPrimAPI_MakeBox* handle);

		virtual BRepPrimAPI_MakeBox* GetMakeOneAxis();

		virtual BRepBuilderAPI_MakeShape* GetMakeShape() Standard_OVERRIDE;


		//! Make a box with a corner at 0,0,0 and the other dx,dy,dz
		XBRepPrimAPI_MakeBox(Standard_Real dx, Standard_Real dy, Standard_Real dz);

		//! Make a box with a corner at P and size dx, dy, dz.
		XBRepPrimAPI_MakeBox(xgp_Pnt^ P, Standard_Real dx, Standard_Real dy, Standard_Real dz);

		//! Make a box with corners P1,P2.
		XBRepPrimAPI_MakeBox(xgp_Pnt^ P1, xgp_Pnt^ P2);

		//! Ax2 is the left corner and the axis.
		//! Constructs a box such that its sides are parallel to the axes of
		//! -   the global coordinate system, or
		//! -   the local coordinate system Axis. and
		//! -   with a corner at (0, 0, 0) and of size (dx, dy, dz), or
		//! -   with a corner at point P and of size (dx, dy, dz), or
		//! -   with corners at points P1 and P2.
		//! Exceptions
		//! Standard_DomainError if: dx, dy, dz are less than or equal to
		//! Precision::Confusion(), or
		//! -   the vector joining the points P1 and P2 has a
		//! component projected onto the global coordinate
		//! system less than or equal to Precision::Confusion().
		//! In these cases, the box would be flat.
		XBRepPrimAPI_MakeBox(xgp_Ax2^ Axes, Standard_Real dx, Standard_Real dy, Standard_Real dz);

		//! Returns the internal algorithm.
		XBRepPrim_Wedge^ Wedge();

		//! Stores the solid in myShape.
		virtual void Build() Standard_OVERRIDE;

		//! Returns the constructed box as a shell.
		XTopoDS_Shell^ Shell();
		operator XTopoDS_Shell^();

		//! Returns the constructed box as a solid.
		XTopoDS_Solid^ Solid();
		operator XTopoDS_Solid^();

		//! Returns ZMin face
		XTopoDS_Face^ BottomFace();

		//! Returns XMin face
		XTopoDS_Face^ BackFace();

		//! Returns XMax face
		XTopoDS_Face^ FrontFace();

		//! Returns YMin face
		XTopoDS_Face^ LeftFace();

		//! Returns YMax face
		XTopoDS_Face^ RightFace();

		//! Returns ZMax face
		XTopoDS_Face^ TopFace();

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property BRepBuilderAPI_MakeShape* IHandle {
			BRepBuilderAPI_MakeShape* get() Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepBuilderAPI_MakeShape* handle) Standard_OVERRIDE {
				//NativeHandle = static_cast<BRepPrimAPI_MakeBox*>(handle);
				if (handle == NULL)
					NativeHandle = static_cast<BRepPrimAPI_MakeBox*>(handle);
				else
					NativeHandle = NULL;
			}
		}

	private:
		BRepPrimAPI_MakeBox* NativeHandle;
	};
}
#endif // _XBRepPrimAPI_MakeBox_HeaderFile
