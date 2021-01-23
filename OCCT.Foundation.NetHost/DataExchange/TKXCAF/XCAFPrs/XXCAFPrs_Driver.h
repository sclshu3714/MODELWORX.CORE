// Created on: 2000-08-11
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

#ifndef _XXCAFPrs_Driver_HeaderFile
#define _XXCAFPrs_Driver_HeaderFile
#pragma once
#include "XCAFPrs_Driver.hxx"
#include "XTDF_Label.h"
#include "XAIS_InteractiveObject.h"
#include "XStandard_GUID.h"
#include <XCAFDoc_ShapeTool.hxx>
#include "AIS_InteractiveObject.hxx"

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <TPrsStd_Driver.hxx>
#include <Standard_Boolean.hxx>
class TDF_Label;
class AIS_InteractiveObject;
class Standard_GUID;
class XCAFDoc_ShapeTool;

//class XCAFPrs_Driver;
//DEFINE_STANDARD_HANDLE(XCAFPrs_Driver, TPrsStd_Driver)

using namespace TKLCAF;
using namespace TKV3d;
using namespace TKernel;
namespace TKXCAF {
	//! Implements a driver for presentation of shapes in DECAF
	//! document. Its the only purpose is to initialize and return
	//! XCAFPrs_AISObject object on request
	ref class TKLCAF::XTDF_Label;
	ref class TKV3d::XAIS_InteractiveObject;
	ref class TKernel::XStandard_GUID;
	public ref class XXCAFPrs_Driver //: public TPrsStd_Driver
	{

	public:
		!XXCAFPrs_Driver() { IHandle = NULL; };
		~XXCAFPrs_Driver() { IHandle = NULL; };
		virtual Standard_Boolean Update(const TDF_Label& L, Handle(AIS_InteractiveObject)& ais);// Standard_OVERRIDE;

		virtual Standard_Boolean Update(XTDF_Label^ L, XAIS_InteractiveObject^ ais);
		//! returns GUID of the driver
		static const XStandard_GUID^ GetID();

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property XCAFPrs_Driver* IHandle {
			XCAFPrs_Driver* get() {
				return NativeHandle;
			}
			void set(XCAFPrs_Driver* handle) {
				NativeHandle = handle;
			}
		}
	private:
		XCAFPrs_Driver* NativeHandle;
		//NCollection_Haft<Handle(AIS_InteractiveObject)> NativeHandle;
	};
}
#endif // _XXCAFPrs_Driver_HeaderFile
