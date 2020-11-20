// Created on: 1993-04-26
// Created by: Jean-Louis Frenkel
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

#ifndef _XPrs3d_LineAspect_HeaderFile
#define _XPrs3d_LineAspect_HeaderFile
#pragma once
#include <Prs3d_LineAspect.hxx>
#include "XQuantity_Color.h"
#include "XAspect_TypeOfLine.h"
#include "NCollection_Haft.h"
#include "XGraphic3d_AspectLine3d.h"
#include "XPrs3d_LineAspect.h"
#include "XGraphic3d_AspectLine3d.h"

#include <Aspect_TypeOfLine.hxx>
#include <Graphic3d_AspectLine3d.hxx>
#include <Prs3d_BasicAspect.hxx>
#include <Quantity_Color.hxx>

//! A framework for defining how a line will be displayed
//! in a presentation. Aspects of line display include
//! width, color and type of line.
//! The definition set by this class is then passed to the
//! attribute manager Prs3d_Drawer.
//! Any object which requires a value for line aspect as
//! an argument may then be given the attribute manager
//! as a substitute argument in the form of a field such as myDrawer for example.
using namespace TKernel;
using namespace TKV3d;
namespace TKV3d {
	ref class TKernel::XQuantity_Color;	
	ref class TKV3d::XGraphic3d_AspectLine3d;
	public ref class XPrs3d_LineAspect //: public Prs3d_BasicAspect
	{
		//! DEFINE_STANDARD_RTTIEXT(Prs3d_LineAspect, Prs3d_BasicAspect)
	public:

		//! Constructs a framework for line aspect defined by
		//! -   the color aColor
		//! -   the type of line aType and
		//! -   the line thickness aWidth.
		//! Type of line refers to whether the line is solid or dotted, for example.
		XPrs3d_LineAspect(XQuantity_Color^ theColor, XAspect_TypeOfLine theType, const Standard_Real theWidth);

		XPrs3d_LineAspect(Handle(Prs3d_LineAspect) theAspect);

		XPrs3d_LineAspect(XGraphic3d_AspectLine3d^ theAspect);

		void SetNativeHandle(Handle(Prs3d_LineAspect) theAspect);

		Handle(Prs3d_LineAspect) GetLineAspect();

		//! Sets the line color defined at the time of construction.
		//! Default value: Quantity_NOC_YELLOW
		void SetColor(XQuantity_Color^ theColor);

		//! Sets the type of line defined at the time of construction.
		//! This could, for example, be solid, dotted or made up of dashes.
		//! Default value: Aspect_TOL_SOLID
		void SetTypeOfLine(XAspect_TypeOfLine theType);

		//! Sets the line width defined at the time of construction.
		//! Default value: 1.
		void SetWidth(const Standard_Real theWidth);

		//! Returns the line aspect. This is defined as the set of
		//! color, type and thickness attributes.
		XGraphic3d_AspectLine3d^ Aspect();

		void SetAspect(XGraphic3d_AspectLine3d^ theAspect);

		//! Dumps the content of me into the stream
		//!  theDepth = -1
		virtual void DumpJson(Standard_OStream& theOStream, const Standard_Integer theDepth) Standard_OVERRIDE;

		/// <summary>
		/// ���ؾ��
		/// </summary>
		property Handle(Prs3d_LineAspect) Handle
		{
			Handle(Prs3d_LineAspect) get() {
				return NativeHandle();
			}
		};
	private:
		NCollection_Haft<Handle(Prs3d_LineAspect)> NativeHandle;

	};
	//! DEFINE_STANDARD_HANDLE(Prs3d_LineAspect, Prs3d_BasicAspect)
}
#endif // _XPrs3d_LineAspect_HeaderFile
