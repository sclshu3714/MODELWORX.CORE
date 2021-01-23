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

#ifndef _XTDF_IDFilter_HeaderFile
#define _XTDF_IDFilter_HeaderFile
#pragma once
#include <TDF_IDFilter.hxx>
#include "XStandard_GUID.h"
#include "XTDF_Attribute.h"
//#include "XTDF_IDList.h"

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <Standard_Boolean.hxx>
#include <TDF_IDMap.hxx>
#include <TDF_IDList.hxx>
#include <Standard_OStream.hxx>
class Standard_GUID;
class TDF_Attribute;

using namespace TKernel;
namespace TKLCAF {
    ref class TKernel::XStandard_GUID;
    ref  class XTDF_Attribute;
    //! This class offers filtering services around an ID list.
    public ref class XTDF_IDFilter
    {
    public:
        !XTDF_IDFilter() { IHandle = NULL; };
        ~XTDF_IDFilter() { IHandle = NULL; };
        //! Creates an ID/attribute filter based on an ID
        //! list. The default mode is "ignore all but...".
        //!
        //! This filter has 2 working mode: keep and ignore.
        //!
        //! Ignore/Exclusive mode: all IDs are ignored except
        //! these set to be kept, using Keep(). Of course, it
        //! is possible set an kept ID to be ignored using
        //! Ignore().
        //!
        //! Keep/Inclusive mode: all IDs are kept except these
        //! set to be ignored, using Ignore(). Of course, it
        //! is possible set an ignored ID to be kept using
        //! Keep().
        //! ignoreMode = Standard_True
        XTDF_IDFilter(const Standard_Boolean ignoreMode);

        //! Creates an ID/attribute filter based on an ID
        XTDF_IDFilter(TDF_IDFilter& pos);

        //!
        TDF_IDFilter GetIDFilter();

        //! The list of ID is cleared and the filter mode is
        //! set to ignore mode if <keep> is true; false
        //! otherwise.
        void IgnoreAll(const Standard_Boolean ignore);

        //! Returns true is the mode is set to "ignore all
        //! but...".
        Standard_Boolean IgnoreAll();

        //! An attribute with <anID> as ID is to be kept and
        //! the filter will answer true to the question
        //! IsKept(<anID>).
        void Keep(XStandard_GUID^ anID);

        //! Attributes with ID owned by <anIDList> are to be kept and
        //! the filter will answer true to the question
        //! IsKept(<anID>) with ID from <anIDList>.
        void Keep(TDF_IDList& anIDList);

        //! Attributes with ID owned by <anIDList> are to be kept and
        //! the filter will answer true to the question
        //! IsKept(<anID>) with ID from <anIDList>.
        //! void Keep(XTDF_IDList& anIDList);

        //! An attribute with <anID> as ID is to be ignored and
        //! the filter will answer false to the question
        //! IsKept(<anID>).
        void Ignore(XStandard_GUID^ anID);

        //! Attributes with ID owned by <anIDList> are to be
        //! ignored and the filter will answer false to the
        //! question IsKept(<anID>) with ID from <anIDList>.
        void Ignore(TDF_IDList& anIDList);

        //! Returns true if the ID is to be kept.
        Standard_Boolean IsKept(XStandard_GUID^ anID);

        //! Returns true if the attribute is to be kept.
        Standard_Boolean IsKept(const Handle(TDF_Attribute)& anAtt);

        //! Returns true if the attribute is to be kept.
        Standard_Boolean IsKept(XTDF_Attribute^ anAtt);

        //! Returns true if the ID is to be ignored.
        Standard_Boolean IsIgnored(XStandard_GUID^ anID);

        //! Returns true if the attribute is to be ignored.
        Standard_Boolean IsIgnored(const Handle(TDF_Attribute)& anAtt);

        //! Returns true if the attribute is to be ignored.
        Standard_Boolean IsIgnored(XTDF_Attribute^ anAtt);

        //! Copies the list of ID to be kept or ignored in
        //! <anIDList>. <anIDList> is cleared before use.
        void IDList(TDF_IDList& anIDList);

        //! Copies the list of ID to be kept or ignored in
        //! <anIDList>. <anIDList> is cleared before use.
        //! void IDList(XTDF_IDList& anIDList);

        //! Copies into <me> the contents of
        //! <fromFilter>. <me> is cleared before copy.
        void Copy(XTDF_IDFilter^ fromFilter);

        //! Writes the contents of <me> to <OS>.
        void Dump(Standard_OStream& anOS);

        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property TDF_IDFilter* IHandle {
            TDF_IDFilter* get() {
                return NativeHandle;
            }
            void set(TDF_IDFilter* handle) {
                NativeHandle = handle;
            }
        }
    private:
        TDF_IDFilter* NativeHandle;
    };
}
#endif // _XTDF_IDFilter_HeaderFile
