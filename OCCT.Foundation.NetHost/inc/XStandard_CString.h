// Copyright (c) 1998-1999 Matra Datavision
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

//!@file Functions working with plain C strings

#ifndef _XStandard_CString_HeaderFile
#define _XStandard_CString_HeaderFile
#pragma once
#include <Standard_CString.hxx>
#include <Standard_Integer.hxx>
#include <Standard_Macro.hxx>
# include <string.h>
# include <stdio.h>
namespace TKernel {

    public ref class XStandard_CString {

        XStandard_CString();

        XStandard_CString(Standard_CString* pos);

        Standard_CString GetCString();

        //! Returns bounded hash code for the null-terminated string, in the range [1, theUpperBound]
        //! @param theString the null-terminated string which hash code is to be computed
        //! @param theUpperBound the upper bound of the range a computing hash code must be within
        //! @return a computed hash code, in the range [1, theUpperBound]
        Standard_Integer HashCode(XStandard_CString^ theString, Standard_Integer theUpperBound);

        //! Returns 32-bit hash code for the first theLen characters in the string theStr.
        //! The result is unbound (may be not only positive, but also negative)
        //! @param theString the string which hash code is to be computed
        //! @param theLength the length of the given string
        //! @return a computed hash code of the given string
        Standard_Integer HashCodes(XStandard_CString^ theString, Standard_Integer theLength);

        //! Returns bounded hash code for the first theLength characters in the string theString, in the range [1, theUpperBound]
        //! @param theString the string which hash code is to be computed
        //! @param theLength the length of the initial substring of the given string which hash code is to be computed
        //! @param theUpperBound the upper bound of the range a computing hash code must be within
        //! @return a computed hash code of the given string
        Standard_Integer HashCode(XStandard_CString^ theString, Standard_Integer theLength, Standard_Integer theUpperBound);
  

        //! Returns Standard_True if two strings are equal
        Standard_Boolean IsEqual(XStandard_CString^ theOne, XStandard_CString^ theTwo);

        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        property Standard_CString* Handle
        {
            Standard_CString* get() {
                return NativeHandle;
            }
        }
    private:
        Standard_CString* NativeHandle;
    };
}
#endif  // _XStandard_CString_HeaderFile
