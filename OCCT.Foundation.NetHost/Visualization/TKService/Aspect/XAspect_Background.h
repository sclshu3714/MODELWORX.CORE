// Created on: 1991-10-02
// Created by: NW,JPB,CAL
// Copyright (c) 1991-1999 Matra Datavision
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

#ifndef _XAspect_Background_HeaderFile
#define _XAspect_Background_HeaderFile
#pragma once
#include <Aspect_Background.hxx>
#include <XQuantity_Color.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <Quantity_Color.hxx>
class Quantity_Color;

using namespace TKernel;
namespace TKService {
	ref class TKernel::XQuantity_Color;
	//! This class allows the definition of
	//! a window background.
	public ref class XAspect_Background
	{
	public:

		//! DEFINE_STANDARD_ALLOC
		//! Creates a window background.
		//! Default color : NOC_MATRAGRAY.
		XAspect_Background();
		!XAspect_Background() { IHandle = NULL; };
		~XAspect_Background() { IHandle = NULL; };
		XAspect_Background(Aspect_Background* pos);

		void SetBackgroundHandle(Aspect_Background* pos);

		Aspect_Background* GetBackground();

		//! Creates a window background with the colour <AColor>.
		XAspect_Background(XQuantity_Color^ AColor);

		//! Modifies the colour of the window background <me>.
		void SetColor(XQuantity_Color^ AColor);

		//! Returns the colour of the window background <me>.
		XQuantity_Color^ Color();
		/// <summary>
		/// ���ؾ��
		/// </summary>
		virtual property Aspect_Background* IHandle {
			Aspect_Background* get() { // Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(Aspect_Background* handle) { // Standard_OVERRIDE {
				NativeHandle = handle;
			}
		}
	private:
		Aspect_Background* NativeHandle;
	};
}
#endif // _XAspect_Background_HeaderFile
