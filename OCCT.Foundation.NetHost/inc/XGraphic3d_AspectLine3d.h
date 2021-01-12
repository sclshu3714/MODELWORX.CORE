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

#ifndef _XGraphic3d_AspectLine3d_HeaderFile
#define _XGraphic3d_AspectLine3d_HeaderFile
#pragma once
#include <Graphic3d_AspectLine3d.hxx>
#include "XQuantity_Color.h"
#include "XAspect_TypeOfLine.h"
#include "NCollection_Haft.h"

#include <Graphic3d_Aspects.hxx>

using namespace TKernel;
//! Creates and updates a group of attributes for 3d line primitives.
//! This group contains the color, the type of line, and its thickness.
namespace TKV3d {
    ref class TKernel::XQuantity_Color;
   public ref class XGraphic3d_AspectLine3d //: public Graphic3d_Aspects
    {
        //! DEFINE_STANDARD_RTTIEXT(Graphic3d_AspectLine3d, Graphic3d_Aspects)
    public:

        //! Creates a context table for line primitives
        //! defined with the following default values:
        //!
        //! Color = Quantity_NOC_YELLOW;
        //! Type  = Aspect_TOL_SOLID;
        //! Width = 1.0;
        XGraphic3d_AspectLine3d();

        XGraphic3d_AspectLine3d(Handle(Graphic3d_AspectLine3d) posAspectLine);

        //! Creates a context table for line primitives defined with the specified values.
        //! Warning: theWidth is the "line width scale factor".
        //! The nominal line width is 1 pixel.
        //! The width of the line is determined by applying the line width scale factor to this nominal line width.
        //! The supported line widths vary by 1-pixel units.
        XGraphic3d_AspectLine3d(XQuantity_Color^ theColor, XAspect_TypeOfLine theType, Standard_Real theWidth);

        virtual Handle(Graphic3d_AspectLine3d) GetAspectLine3d();

        //! 
        void SetNativeHandle(Handle(Graphic3d_AspectLine3d) theAspect);

        //! Return line type.
        XAspect_TypeOfLine Type();

        //! Modifies the type of line.
        void SetType(XAspect_TypeOfLine theType);

        //! Return line width.
        Standard_ShortReal Width();

        //! Modifies the line thickness.
        //! Warning: Raises Standard_OutOfRange if the width is a negative value.
        void SetWidth(const Standard_Real theWidth) { SetWidth((float)theWidth); }

        //! Modifies the line thickness.
        //! Warning: Raises Standard_OutOfRange if the width is a negative value.
        void SetWidth(Standard_ShortReal theWidth)
        {
            NativeHandle()->SetLineWidth(theWidth);
        }

        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property Handle(Standard_Transient) IHandle {
            Handle(Standard_Transient) get() {//Standard_OVERRIDE {
                return NativeHandle();
            }
            void set(Handle(Standard_Transient) handle) {//Standard_OVERRIDE {
                NativeHandle() = Handle(Graphic3d_AspectLine3d)::DownCast(handle);
            }
        }
    private:
        NCollection_Haft<Handle(Graphic3d_AspectLine3d)> NativeHandle;
    };

    //! DEFINE_STANDARD_HANDLE(Graphic3d_AspectLine3d, Graphic3d_Aspects)
}
#endif // _XGraphic3d_AspectLine3d_HeaderFile
