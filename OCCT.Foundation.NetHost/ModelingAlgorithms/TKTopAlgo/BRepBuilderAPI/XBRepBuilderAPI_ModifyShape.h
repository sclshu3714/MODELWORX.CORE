// Created on: 1994-12-02
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

#ifndef _XBRepBuilderAPI_ModifyShape_HeaderFile
#define _XBRepBuilderAPI_ModifyShape_HeaderFile
#pragma once
#include <BRepBuilderAPI_ModifyShape.hxx>
#include <XBRepBuilderAPI_MakeShape.h>
#include <XTopTools_ListOfShape.h>
#include <XTopoDS_Shape.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <BRepTools_Modifier.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepBuilderAPI_MakeShape.hxx>
#include <TopTools_ListOfShape.hxx>
class BRepTools_Modification;
class Standard_NullObject;
class Standard_NoSuchObject;
class TopoDS_Shape;

using namespace TKBRep;
namespace TKTopAlgo {
	ref class TKBRep::XTopoDS_Shape;
	ref class TKBRep::XTopTools_ListOfShape;
	//! Implements   the  methods   of MakeShape for   the
	//! constant  topology modifications.  The methods are
	//! implemented  when the modification uses a Modifier
	//! from BRepTools. Some of  them have to be redefined
	//! if  the  modification is  implemented with another
	//! tool (see Transform from BRepBuilderAPI for example).
	//! The BRepBuilderAPI package provides the following
	//! frameworks to perform modifications of this sort:
	//! -   BRepBuilderAPI_Copy to produce the copy of a shape,
	//! -   BRepBuilderAPI_Transform and
	//! BRepBuilderAPI_GTransform to apply a geometric
	//! transformation to a shape,
	//! -   BRepBuilderAPI_NurbsConvert to convert the
	//! whole geometry of a shape into NURBS geometry,
	//! -   BRepOffsetAPI_DraftAngle to build a tapered shape.
	public ref class XBRepBuilderAPI_ModifyShape : public XBRepBuilderAPI_MakeShape
	{
	public:

		!XBRepBuilderAPI_ModifyShape() { IHandle = NULL; };
		~XBRepBuilderAPI_ModifyShape() { IHandle = NULL; };
		//! DEFINE_STANDARD_ALLOC
		XBRepBuilderAPI_ModifyShape();

		void SetModifyShapeHandle(BRepBuilderAPI_ModifyShape* handle);

		virtual BRepBuilderAPI_ModifyShape* GetModifyShape();

		virtual BRepBuilderAPI_MakeShape* GetMakeShape() Standard_OVERRIDE;

		//! Returns the list  of shapes modified from the shape
		//! <S>.
		virtual XTopTools_ListOfShape^ Modified(XTopoDS_Shape^ S) Standard_OVERRIDE;

		//! Returns the modified shape corresponding to <S>.
		//! S can correspond to the entire initial shape or to its subshape.
		//! Exceptions
		//! Standard_NoSuchObject if S is not the initial shape or
		//! a subshape of the initial shape to which the
		//! transformation has been applied. Raises NoSuchObject from Standard
		//! if S is not the initial shape or a sub-shape
		//! of the initial shape.
		virtual XTopoDS_Shape^ ModifiedShape(XTopoDS_Shape^ S);

		/// <summary>
		/// ���ؾ��
		/// </summary>
		virtual property BRepBuilderAPI_MakeShape* IHandle {
			BRepBuilderAPI_MakeShape* get() Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepBuilderAPI_MakeShape* handle) Standard_OVERRIDE {
				NativeHandle = static_cast<BRepBuilderAPI_ModifyShape*>(handle);
			}
		}

	private:
		BRepBuilderAPI_ModifyShape* NativeHandle;
	};
}
#endif // _XBRepBuilderAPI_ModifyShape_HeaderFile
