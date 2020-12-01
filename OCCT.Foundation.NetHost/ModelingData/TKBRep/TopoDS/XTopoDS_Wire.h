// Created on: 1990-12-17
// Created by: Remi Lequette
// Copyright (c) 1990-1999 Matra Datavision
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

#ifndef _XTopoDS_Wire_HeaderFile
#define _XTopoDS_Wire_HeaderFile
#pragma once
#include <TopoDS_Wire.hxx>
#include <XTopoDS_Shape.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>




//! Describes a wire which
//! - references an underlying wire with the potential to
//! be given a location and an orientation
//! - has a location for the underlying wire, giving its
//! placement in the local coordinate system
//! - has an orientation for the underlying wire, in terms
//! of its geometry (as opposed to orientation in relation to other shapes).
//! 
namespace TKBRep {
    public ref class XTopoDS_Wire : public XTopoDS_Shape
    {
    public:

       //! DEFINE_STANDARD_ALLOC


        //! Undefined Wire.
        XTopoDS_Wire();

        XTopoDS_Wire(TopoDS_Wire* pos);

        TopoDS_Wire* GetWire();
        //!
        virtual TopoDS_Shape* GetShape() Standard_OVERRIDE;
        /// <summary>
      /// ���ؾ��
      /// </summary>
        virtual property TopoDS_Shape* IHandle {
            TopoDS_Shape* get() Standard_OVERRIDE {
                return NativeHandle;
            }
            void set(TopoDS_Shape* shape) Standard_OVERRIDE {
                NativeHandle = static_cast<TopoDS_Wire*>(shape);
            }
        }
    private:
        TopoDS_Wire* NativeHandle;
    };
}
#endif // _XTopoDS_Wire_HeaderFile
