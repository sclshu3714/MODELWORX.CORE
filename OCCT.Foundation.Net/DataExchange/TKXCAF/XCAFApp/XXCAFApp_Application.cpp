// Created on: 2000-05-24
// Created by: data exchange team
// Copyright (c) 2000-2014 OPEN CASCADE SAS
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

#include "XXCAFApp_Application.h"

namespace TKXCAF {

	//! methods from TDocStd_Application
		//! ================================
	XXCAFApp_Application::XXCAFApp_Application(): XTDocStd_Application(){
		NativeHandle() = XCAFApp_Application::GetApplication();
		SetNativeHandle(NativeHandle());
	};

	//! methods from TDocStd_Application
	//! ================================
	XXCAFApp_Application::XXCAFApp_Application(Handle(XCAFApp_Application) pos) {
		NativeHandle() = pos;
		SetNativeHandle(NativeHandle());
	};

	Handle(XCAFApp_Application) XXCAFApp_Application::GetXCAFApp_Application() {
		return NativeHandle();
	};

	Handle(TDocStd_Application) XXCAFApp_Application::GetTDocStd_Application() {
		return NativeHandle();
	};

	//=======================================================================
	//function : GetApplication
	//purpose  : 
	//=======================================================================
	XXCAFApp_Application^ XXCAFApp_Application::GetApplication()
	{
		return gcnew XXCAFApp_Application(XCAFApp_Application::GetApplication());
	}

	//=======================================================================
	//function : ResourcesName
	//purpose  : 
	//=======================================================================

	Standard_CString XXCAFApp_Application::ResourcesName()
	{
		return Standard_CString("XCAF");
		//  return Standard_CString("Standard");
	}

	//=======================================================================
	//function : InitDocument
	//purpose  : 
	//=======================================================================

	void XXCAFApp_Application::InitDocument(XTDocStd_Document^ aDoc)
	{
		XCAFDoc_DocumentTool::Set(aDoc->Main()->GetLabel());
	}

	//=======================================================================
	//function : InitDocument
	//purpose  : 
	//=======================================================================

	void XXCAFApp_Application::InitDocument(Handle(TDocStd_Document) aDoc)
	{
		XCAFDoc_DocumentTool::Set(aDoc->Main());
	}
}
