// Created on: 1993-01-14
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

#ifndef XTopTools_ListOfShape_HeaderFile
#define XTopTools_ListOfShape_HeaderFile
#pragma once
#include <TopTools_ListOfShape.hxx>

#include <XTopoDS_Shape.h>
#include <NCollection_List.hxx>
namespace TKBRep {
	ref class XTopoDS_Shape;
	/*typedef NCollection_List<TopoDS_Shape> TopTools_ListOfShape;
	typedef NCollection_List<TopoDS_Shape>::Iterator TopTools_ListIteratorOfListOfShape;*/
	public ref class XTopTools_ListOfShape {
	public:
		XTopTools_ListOfShape(TopTools_ListOfShape TListOfShape) {
			NListOfShape = new TopTools_ListOfShape(TListOfShape);
			ListOfShape = gcnew List<XTopoDS_Shape^>();
			TopTools_ListIteratorOfListOfShape Iterator(TListOfShape);
			for (TopTools_ListIteratorOfListOfShape Iterator(TListOfShape); Iterator.More(); Iterator.Next())
			{
				XTopoDS_Shape^ shape = gcnew XTopoDS_Shape(Iterator.Value());
				ListOfShape->Add(shape);
			}
		};
		List<XTopoDS_Shape^>^ XListOfShapes() {
			return ListOfShape;
		};

		TopTools_ListOfShape TListOfShapes() {
			return *NListOfShape;
		}

	private:
		TopTools_ListOfShape* NListOfShape;
		List<XTopoDS_Shape^>^ ListOfShape;
	};
}
#endif
