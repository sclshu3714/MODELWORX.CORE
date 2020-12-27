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

//              11/97 ; CAL : retrait des DataStructure
//-Version	
//-Design	
//-Warning	
//-References	
//-Language	C++ 2.0
//-Declarations
// for the class

#include <XGraphic3d_DataStructureManager.h>
namespace TKV3d {
	XGraphic3d_DataStructureManager::XGraphic3d_DataStructureManager() {
		//NativeHandle() = new Graphic3d_DataStructureManager();
	};

	XGraphic3d_DataStructureManager::XGraphic3d_DataStructureManager(Handle(Graphic3d_DataStructureManager) handle) {
		NativeHandle() = handle;
	};

	void XGraphic3d_DataStructureManager::SetDataStructureManagerHandle(Handle(Graphic3d_DataStructureManager) handle) {
		NativeHandle() = handle;
	};

	Handle(Graphic3d_DataStructureManager) XGraphic3d_DataStructureManager::GetDataStructureManager() {
		return NativeHandle();
	};
}
