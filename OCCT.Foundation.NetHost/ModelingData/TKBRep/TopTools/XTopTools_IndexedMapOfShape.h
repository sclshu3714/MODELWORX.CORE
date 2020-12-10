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

#ifndef XTopTools_IndexedMapOfShape_HeaderFile
#define XTopTools_IndexedMapOfShape_HeaderFile
#pragma once
#include <TopTools_IndexedMapOfShape.hxx>


//#include <TopoDS_Shape.hxx>
//#include <TopTools_ShapeMapHasher.hxx>
//#include <NCollection_IndexedMap.hxx>
//
//typedef NCollection_IndexedMap<TopoDS_Shape,TopTools_ShapeMapHasher> TopTools_IndexedMapOfShape;

namespace TKBRep {
	public ref class XTopTools_IndexedMapOfShape {
		XTopTools_IndexedMapOfShape();
        XTopTools_IndexedMapOfShape(TopTools_IndexedMapOfShape* pos);
        void SetIndexedMapOfShapeHandle(TopTools_IndexedMapOfShape* pos);
        TopTools_IndexedMapOfShape* GetIndexedMapOfShape();
        ~XTopTools_IndexedMapOfShape();
        !XTopTools_IndexedMapOfShape();



        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property TopTools_IndexedMapOfShape* IHandle {
            TopTools_IndexedMapOfShape* get() { //Standard_OVERRIDE {
                return NativeHandle;
            }
            void set(TopTools_IndexedMapOfShape* shape) { // Standard_OVERRIDE {
                NativeHandle = shape;
            }
        }
    private:
        TopTools_IndexedMapOfShape* NativeHandle;
	};
}

#endif
