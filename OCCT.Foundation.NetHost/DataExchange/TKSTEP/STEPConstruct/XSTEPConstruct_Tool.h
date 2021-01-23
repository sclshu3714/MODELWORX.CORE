// Created on: 2000-09-29
// Created by: Andrey BETENEV
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

#ifndef _XSTEPConstruct_Tool_HeaderFile
#define _XSTEPConstruct_Tool_HeaderFile
#pragma once
#include "STEPConstruct_Tool.hxx"
#include "NCollection_Haft.h"

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <Standard_Boolean.hxx>
class XSControl_WorkSession;
class Transfer_FinderProcess;
class Transfer_TransientProcess;
class Interface_HGraph;
class Interface_InterfaceModel;
class Interface_Graph;


//! Provides basic functionalities for tools which are intended
//! for encoding/decoding specific STEP constructs
//!
//! It is initialized by WorkSession and allows easy access to
//! its fields and internal data such as Model, TP and FP
//!
//! NOTE: Call to method Graph() with True (or for a first time,
//! if you have updated the model since last computation of model)
//! can take a time, so it is recommended to avoid creation of
//! this (and derived) tool multiple times
namespace TKSTEP {
    public ref class XSTEPConstruct_Tool
    {
    public:

        //! DEFINE_STANDARD_ALLOC

        !XSTEPConstruct_Tool() { IHandle = NULL; };
        ~XSTEPConstruct_Tool() { IHandle = NULL; };
        //! Creates an empty tool
        XSTEPConstruct_Tool();

        //! Creates an empty tool
        XSTEPConstruct_Tool(STEPConstruct_Tool pos);

        //! Creates a tool and loads it with worksession
        XSTEPConstruct_Tool(const Handle(XSControl_WorkSession)& WS);

        //! 
        STEPConstruct_Tool GetTool();

        //! Returns currently loaded WorkSession
        const Handle(XSControl_WorkSession)& WS();

        //! Returns current model (Null if not loaded)
        Handle(Interface_InterfaceModel) Model();

        //! Returns current graph (recomputing if necessary)
        //! recompute = Standard_False
        const Interface_Graph& Graph(const Standard_Boolean recompute);

        //! Returns TransientProcess (reading; Null if not loaded)
        const Handle(Transfer_TransientProcess)& TransientProcess();

        //! Returns FinderProcess (writing; Null if not loaded)
        const Handle(Transfer_FinderProcess)& FinderProcess();

        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property STEPConstruct_Tool* IHandle {
            STEPConstruct_Tool* get() {
                return NativeHandle;
            }
            void set(STEPConstruct_Tool* handle) {
                NativeHandle = handle;
            }
        }

    private:
        STEPConstruct_Tool* NativeHandle;
        //NCollection_Haft<Handle(STEPConstruct_Tool)> NativeHandle;
    };
}
#endif // _XSTEPConstruct_Tool_HeaderFile
