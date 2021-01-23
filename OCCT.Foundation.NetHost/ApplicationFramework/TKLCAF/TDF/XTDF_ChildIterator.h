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

#ifndef _XTDF_ChildIterator_HeaderFile
#define _XTDF_ChildIterator_HeaderFile
#pragma once
#include "TDF_ChildIterator.hxx"
#include "XTDF_Label.h"
#include "NCollection_Haft.h"

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <TDF_LabelNodePtr.hxx>
#include <Standard_Integer.hxx>
#include <Standard_Boolean.hxx>
#include <TDF_Label.hxx>
class TDF_Label;


//! Iterates on the children of a label, at the first
//! level only. It is possible to ask the iterator to
//! explore all the sub label levels of the given one,
//! with the option "allLevels".
//! 
namespace TKLCAF {
    ref class XTDF_Label;
    public ref class XTDF_ChildIterator
    {
    public:
        !XTDF_ChildIterator() { IHandle = NULL; };
        ~XTDF_ChildIterator() { IHandle = NULL; };
        //! Creates an empty iterator  object to
        //! explore the children of a label.
        XTDF_ChildIterator();

        //! Creates an empty iterator  object to
        //! explore the children of a label.
        XTDF_ChildIterator(TDF_ChildIterator* pos);

        //! Constructs the iterator object defined by
        //! the label aLabel.  Iterates on the children of the given label. If
        //! <allLevels> option is set to true, it explores not
        //! only the first, but all the sub label levels.
        //! allLevels default false
        XTDF_ChildIterator(const TDF_Label& aLabel, const Standard_Boolean allLevels);

        //! Constructs the iterator object defined by
        //! the label aLabel.  Iterates on the children of the given label. If
        //! <allLevels> option is set to true, it explores not
        //! only the first, but all the sub label levels.
        //! allLevels default false
        XTDF_ChildIterator(XTDF_Label^ aLabel, const Standard_Boolean allLevels);

        //! Initializes the iteration on the children of the
        //! given label.
        //! If <allLevels> option is set to true,
        //! it explores not only the first, but all the sub
        //! label levels.
        //! If allLevels is false, only the first level of
        //! child labels is explored.
        //! In the example below, the label is iterated
        //! using Initialize, More and Next and its
        //! child labels dumped using TDF_Tool::Entry.
        //! Example
        //! void DumpChildren(const
        //! TDF_Label& aLabel)
        //! {
        //! TDF_ChildIterator it;
        //! TCollection_AsciiString es;
        //! for
        //! (it.Initialize(aLabel,Standard_True);
        //! it.More(); it.Next()){
        //! TDF_Tool::Entry(it.Value(),es);
        //! std::cout << as.ToCString() << std::endl;
        //! }
        //! }
        //! allLevels default false
        void Initialize(const TDF_Label& aLabel, const Standard_Boolean allLevels);

        //! allLevels default false
        void Initialize(XTDF_Label^ aLabel, const Standard_Boolean allLevels);

        //! Returns true if a current label is found in the
        //! iteration process.
        Standard_Boolean More();

        //! Move the  current  iteration  to the next Item.
        void Next();

        //! Moves this iteration to the next brother
        //! label. A brother label is one with the same
        //! father as an initial label.
        //! Use this function when the non-empty
        //! constructor or Initialize has allLevels set to
        //! true. The result is that the iteration does not
        //! explore the children of the current label.
        //! This method is interesting only with
        //! "allLevels" behavior, because it avoids to explore
        //! the current label children.
        void NextBrother();

        //! Returns the current label; or, if there is
        //! none, a null label.
        const XTDF_Label^ Value();

        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property TDF_ChildIterator* IHandle {
            TDF_ChildIterator* get() {
                return NativeHandle;
            }
            void set(TDF_ChildIterator* handle) {
                NativeHandle = handle;
            }
        }
    private:
        TDF_ChildIterator* NativeHandle;
    };
}
#endif // _XTDF_ChildIterator_HeaderFile
