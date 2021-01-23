// Created by: CAL
// Copyright (c) 1995-1999 Matra Datavision
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

#ifndef _XGraphic3d_DataStructureManager_HeaderFile
#define _XGraphic3d_DataStructureManager_HeaderFile
#pragma once
#include <Graphic3d_DataStructureManager.hxx>
#include <NCollection_Haft.h>

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <Standard_Transient.hxx>


class Graphic3d_DataStructureManager;
//DEFINE_STANDARD_HANDLE(Graphic3d_DataStructureManager, Standard_Transient)

namespace TKV3d {
	//! This class allows the definition of a manager to
	//! which the graphic objects are associated.
	//! It allows them to be globally manipulated.
	//! It defines the global attributes.
	public ref class XGraphic3d_DataStructureManager //: public Standard_Transient
	{

	public:

		XGraphic3d_DataStructureManager();
        !XGraphic3d_DataStructureManager() { IHandle = NULL; };
        ~XGraphic3d_DataStructureManager() { IHandle = NULL; };
        XGraphic3d_DataStructureManager(Handle(Graphic3d_DataStructureManager) handle);

        void SetDataStructureManagerHandle(Handle(Graphic3d_DataStructureManager) handle);

        Handle(Graphic3d_DataStructureManager) GetDataStructureManager();

		//DEFINE_STANDARD_RTTIEXT(Graphic3d_DataStructureManager, Standard_Transient)
        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property Handle(Graphic3d_DataStructureManager) IHandle {
            Handle(Graphic3d_DataStructureManager) get() { // Standard_OVERRIDE {
                return NativeHandle();
            }
            void set(Handle(Graphic3d_DataStructureManager) handle) { // Standard_OVERRIDE {
                NativeHandle() = handle;
            }
        }
    private:
        NCollection_Haft<Handle(Graphic3d_DataStructureManager)> NativeHandle;
	};
}
#endif // _XGraphic3d_DataStructureManager_HeaderFile
