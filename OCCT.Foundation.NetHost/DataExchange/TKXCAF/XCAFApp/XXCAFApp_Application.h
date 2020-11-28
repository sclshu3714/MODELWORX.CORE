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

#ifndef _XXCAFApp_Application_HeaderFile
#define _XXCAFApp_Application_HeaderFile
#pragma once
#include "XCAFApp_Application.hxx"
#include "NCollection_Haft.h"
#include "XTDocStd_Document.h"
#include "XTDocStd_Application.h"

#include <XCAFDoc_DocumentTool.hxx>

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <TDocStd_Application.hxx>
#include <TColStd_SequenceOfExtendedString.hxx>
#include <Standard_CString.hxx>
class TDocStd_Document;


//class XCAFApp_Application;
//DEFINE_STANDARD_HANDLE(XCAFApp_Application, TDocStd_Application)

using namespace TKLCAF;
namespace TKXCAF {

	ref class TKLCAF::XTDocStd_Document;
	//! Implements an Application for the DECAF documents
	public ref class XXCAFApp_Application : XTDocStd_Application
	{
	public:

		//! methods from TDocStd_Application
		//! ================================
		XXCAFApp_Application();

		//! methods from TDocStd_Application
		//! ================================
		XXCAFApp_Application(Handle(XCAFApp_Application) pos);

		//! methods from TDocStd_Application
		//! ================================
		virtual Standard_CString ResourcesName() Standard_OVERRIDE;

		//! Set XCAFDoc_DocumentTool attribute
		virtual void InitDocument(XTDocStd_Document^ aDoc) Standard_OVERRIDE;

		//! Set XCAFDoc_DocumentTool attribute
		virtual void InitDocument(Handle(TDocStd_Document) aDoc);

		//! Initializes (for the first time) and returns the
		//! static object (XCAFApp_Application)
		//! This is the only valid method to get XCAFApp_Application
		//! object, and it should be called at least once before
		//! any actions with documents in order to init application
		static Handle(XCAFApp_Application) GetApplication();

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property Handle(Standard_Transient) IHandle {
			Handle(Standard_Transient) get() Standard_OVERRIDE {
				return NativeHandle();
			}
			void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
				NativeHandle() = Handle(XCAFApp_Application)::DownCast(handle);
			}
		}
	private:
		NCollection_Haft<Handle(XCAFApp_Application)> NativeHandle;
	};
}
#endif // _XXCAFApp_Application_HeaderFile
