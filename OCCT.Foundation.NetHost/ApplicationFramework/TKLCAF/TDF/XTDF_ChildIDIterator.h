// Created by: DAUTRY Philippe
// Copyright (c) 1997-1999 Matra Datavision
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

#ifndef _XTDF_ChildIDIterator_HeaderFile
#define _TXDF_ChildIDIterator_HeaderFile
#pragma once
#include "TDF_ChildIDIterator.hxx"
#include "XTDF_Label.h"
#include "XStandard_GUID.h"
#include <XTDF_ChildIterator.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <Standard_GUID.hxx>
#include <TDF_ChildIterator.hxx>
#include <Standard_Boolean.hxx>
class TDF_Attribute;
class TDF_Label;
class Standard_GUID;

using namespace TKernel;
//! Iterates on the children of a label, to find
//! attributes having ID as Attribute ID.
//!
//! Level option works as TDF_ChildIterator.
namespace TKLCAF {
    ref class XTDF_Label;
    ref class TKernel::XStandard_GUID;
    public ref class XTDF_ChildIDIterator
    {
    public:

        //! Creates an empty iterator.
        XTDF_ChildIDIterator();

        //! Iterates on the children of the given label. If
        //! <allLevels> option is set to true, it explores not
        //! only the first, but all the sub label levels.
        //! Standard_Boolean allLevels = Standard_False
        XTDF_ChildIDIterator(XTDF_Label^ aLabel, XStandard_GUID^ anID, Standard_Boolean allLevels);
        //! Initializes the iteration on the children of the
        //! given label. If <allLevels> option is set to true,
        //! it explores not only the first, but all the sub
        //! label levels.
        void Initialize(XTDF_Label^ aLabel, XStandard_GUID^ anID, Standard_Boolean allLevels);
        //! Returns True if there is a current Item in the
        //! iteration.
        Standard_Boolean More();

        //! Move to the next Item
        void Next();

        //! Move to the next Brother. If there is none, go up
        //! etc. This method is interesting only with
        //! "allLevels" behavior, because it avoids to explore
        //! the current label children.
        void NextBrother();

        //! Returns the current item; a null handle if there is none.
        XTDF_Attribute^ Value();

        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property TDF_ChildIDIterator* IHandle {
            TDF_ChildIDIterator* get() {
                return NativeHandle;
            }
            void set(TDF_ChildIDIterator* handle) {
                NativeHandle = handle;
            }
        }
    private:
        TDF_ChildIDIterator* NativeHandle;
    };
}
#endif // _XTDF_ChildIDIterator_HeaderFile
