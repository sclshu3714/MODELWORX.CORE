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

#ifndef _XBRepBuilderAPI_Transform_HeaderFile
#define _XBRepBuilderAPI_Transform_HeaderFile
#pragma once
#include <BRepBuilderAPI_Transform.hxx>
#include <XBRepBuilderAPI_ModifyShape.h>
#include <XTopTools_ListOfShape.h>
#include <XTopoDS_Shape.h>
#include <xgp_Trsf.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <gp_Trsf.hxx>
#include <TopLoc_Location.hxx>
#include <Standard_Boolean.hxx>
#include <BRepBuilderAPI_ModifyShape.hxx>
#include <TopTools_ListOfShape.hxx>
class Standard_NoSuchObject;
class gp_Trsf;
class TopoDS_Shape;

using namespace TKMath;
using namespace TKBRep;
namespace TKTopAlgo {
	ref class TKMath::xgp_Trsf;
	ref class TKBRep::XTopoDS_Shape;
	ref class TKBRep::XTopTools_ListOfShape;
	//! Geometric transformation on a shape.
	//! The transformation to be applied is defined as a
	//! gp_Trsf transformation, i.e. a transformation which does
	//! not modify the underlying geometry of shapes.
	//! The transformation is applied to:
	//! -   all curves which support edges of a shape, and
	//! -   all surfaces which support its faces.
	//! A Transform object provides a framework for:
	//! -   defining the geometric transformation to be applied,
	//! -   implementing the transformation algorithm, and
	//! -   consulting the results.
	public ref class XBRepBuilderAPI_Transform : public XBRepBuilderAPI_ModifyShape
	{
	public:
		!XBRepBuilderAPI_Transform() { IHandle = NULL; };
		~XBRepBuilderAPI_Transform() { IHandle = NULL; };
		//! DEFINE_STANDARD_ALLOC
		//! DEFINE_STANDARD_ALLOC
		XBRepBuilderAPI_Transform();

		void SetTransformHandle(BRepBuilderAPI_Transform* handle);

		virtual BRepBuilderAPI_Transform* GetTransform();

		virtual BRepBuilderAPI_ModifyShape* GetModifyShape() Standard_OVERRIDE;

		virtual BRepBuilderAPI_MakeShape* GetMakeShape() Standard_OVERRIDE;

		//! Constructs a framework for applying the geometric
		//! transformation T to a shape. Use the function Perform
		//! to define the shape to transform.
		XBRepBuilderAPI_Transform(xgp_Trsf^ T);

		//! Creates a transformation from the gp_Trsf <T>, and
		//! applies it to the shape <S>. If the transformation
		//! is  direct   and isometric (determinant  =  1) and
		//! <Copy> =  Standard_False,  the resulting shape  is
		//! <S> on   which  a  new  location has    been  set.
		//! Otherwise,  the   transformation is applied   on a
		//! duplication of <S>.
		//! const Standard_Boolean Copy = Standard_False
		XBRepBuilderAPI_Transform(XTopoDS_Shape^ S, xgp_Trsf^ T, Standard_Boolean Copy);

		//! pplies the geometric transformation defined at the
		//! time of construction of this framework to the shape S.
		//! - If the transformation T is direct and isometric, in
		//! other words, if the determinant of the vectorial part
		//! of T is equal to 1., and if Copy equals false (the
		//! default value), the resulting shape is the same as
		//! the original but with a new location assigned to it.
		//! -   In all other cases, the transformation is applied to a duplicate of S.
		//! Use the function Shape to access the result.
		//! Note: this framework can be reused to apply the same
		//! geometric transformation to other shapes. You only
		//! need to specify them by calling the function Perform again.
		//! Standard_Boolean Copy = Standard_False
		void Perform(XTopoDS_Shape^ S, Standard_Boolean Copy);

		//! Returns the modified shape corresponding to <S>.
		virtual XTopoDS_Shape^ ModifiedShape(XTopoDS_Shape^ S) Standard_OVERRIDE;

		//! Returns the list  of shapes modified from the shape
		//! <S>.
		virtual XTopTools_ListOfShape^ Modified(XTopoDS_Shape^ S) Standard_OVERRIDE;

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property BRepBuilderAPI_MakeShape* IHandle {
			BRepBuilderAPI_MakeShape* get() Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepBuilderAPI_MakeShape* handle) Standard_OVERRIDE {
				//NativeHandle = static_cast<BRepBuilderAPI_Transform*>(handle);
				if (handle == NULL)
					NativeHandle = static_cast<BRepBuilderAPI_Transform*>(handle);
				else
					NativeHandle = NULL;
			}
		}

	private:
		BRepBuilderAPI_Transform* NativeHandle;
	};
}
#endif // _XBRepBuilderAPI_Transform_HeaderFile
