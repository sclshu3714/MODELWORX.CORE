// Created on: 1994-12-09
// Created by: Jacques GOUSSARD
// Copyright (c) 1994-1999 Matra Datavision
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

#ifndef _XBRepBuilderAPI_NurbsConvert_HeaderFile
#define _XBRepBuilderAPI_NurbsConvert_HeaderFile
#pragma once
#include <BRepBuilderAPI_NurbsConvert.hxx>
#include <XBRepBuilderAPI_ModifyShape.h>
#include <XTopoDS_Shape.h>
#include <XTopTools_ListOfShape.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <BRepBuilderAPI_ModifyShape.hxx>
#include <Standard_Boolean.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <BRepTools_ReShape.hxx>

class TopoDS_Shape;

using namespace TKBRep;
namespace TKTopAlgo {
	ref class TKBRep::XTopoDS_Shape;
	ref class TKBRep::XTopTools_ListOfShape;
	//! Conversion of the complete geometry of a shape
	//! (all 3D analytical representation of surfaces and curves)
	//! into NURBS geometry (execpt for Planes). For example,
	//! all curves supporting edges of the basis shape are converted
	//! into BSpline curves, and all surfaces supporting its faces are
	//! converted into BSpline surfaces.
	public ref class XBRepBuilderAPI_NurbsConvert : public XBRepBuilderAPI_ModifyShape
	{
	public:

		//DEFINE_STANDARD_ALLOC

		void SetNurbsConvertHandle(BRepBuilderAPI_NurbsConvert* handle);

		virtual BRepBuilderAPI_NurbsConvert* GetNurbsConvert();

		virtual BRepBuilderAPI_ModifyShape* GetModifyShape() Standard_OVERRIDE;

		virtual BRepBuilderAPI_MakeShape* GetMakeShape() Standard_OVERRIDE;

		//! Constructs a framework for converting the geometry of a
		//! shape into NURBS geometry. Use the function Perform
		//! to define the shape to convert.
		XBRepBuilderAPI_NurbsConvert();

		//! Builds a new shape by converting the geometry of the
		//! shape S into NURBS geometry. Specifically, all curves
		//! supporting edges of S are converted into BSpline
		//! curves, and all surfaces supporting its faces are
		//! converted into BSpline surfaces.
		//! Use the function Shape to access the new shape.
		//! Note: theructed framework can be reused to
		//! convert other shapes. You specify these with the
		//! function Perform.
		//! Standard_Boolean Copy = Standard_False
		XBRepBuilderAPI_NurbsConvert(XTopoDS_Shape^ S, Standard_Boolean Copy);

		//! Builds a new shape by converting the geometry of the
		//! shape S into NURBS geometry.
		//! Specifically, all curves supporting edges of S are
		//! converted into BSpline curves, and all surfaces
		//! supporting its faces are converted into BSpline surfaces.
		//! Use the function Shape to access the new shape.
		//! Note: this framework can be reused to convert other
		//! shapes: you specify them by calling the function Perform again.
		//! Standard_Boolean Copy = Standard_False
		void Perform(XTopoDS_Shape^ S, Standard_Boolean Copy);


		//! Returns the list  of shapes modified from the shape
		//! <S>.
		virtual XTopTools_ListOfShape^ Modified(XTopoDS_Shape^ S) Standard_OVERRIDE;

		//! Returns the modified shape corresponding to <S>.
		//! S can correspond to the entire initial shape or to its subshape.
		//! Exceptions
		//! Standard_NoSuchObject if S is not the initial shape or
		//! a subshape of the initial shape to which the
		//! transformation has been applied. 
		virtual XTopoDS_Shape^ ModifiedShape(XTopoDS_Shape^ S) Standard_OVERRIDE;

		/// <summary>
		/// ���ؾ��
		/// </summary>
		virtual property BRepBuilderAPI_MakeShape* IHandle {
			BRepBuilderAPI_MakeShape* get() Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepBuilderAPI_MakeShape* handle) Standard_OVERRIDE {
				NativeHandle = static_cast<BRepBuilderAPI_NurbsConvert*>(handle);
			}
		}

	private:
		BRepBuilderAPI_NurbsConvert* NativeHandle;
	};
}
#endif // _XBRepBuilderAPI_NurbsConvert_HeaderFile
