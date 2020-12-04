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
//! Class perform linear interpolation (approximate rotation interpolation),
//! result quaternion nonunit, its length lay between. sqrt(2)/2  and 1.0

#ifndef _xgp_QuaternionNLerp_HeaderFile
#define _xgp_QuaternionNLerp_HeaderFile
#pragma once
#include <gp_QuaternionNLerp.hxx>
#include <xgp_Quaternion.h>
class gp_QuaternionNLerp;
namespace TKMath
{
    ref class xgp_Quaternion;
    public ref class xgp_QuaternionNLerp
    {
    public:

        //! Compute interpolated quaternion between two quaternions.
        //! @param theStart first  quaternion
        //! @param theEnd   second quaternion
        //! @param theT normalized interpolation coefficient within 0..1 range,
        //!             with 0 pointing to theStart and 1 to theEnd.
        static xgp_Quaternion^ Interpolate(xgp_Quaternion ^theQStart, xgp_Quaternion^ theQEnd, Standard_Real theT) {
            xgp_Quaternion^ aResult;
            xgp_QuaternionNLerp aLerp(theQStart, theQEnd);
            aLerp.Interpolate(theT, aResult);
            return aResult;
        }

    public:

        //! Empty constructor,
        xgp_QuaternionNLerp() {}

        //! Constructor with initialization.
        xgp_QuaternionNLerp(xgp_Quaternion^ theQStart, xgp_Quaternion^ theQEnd) {
            Init(theQStart, theQEnd);
        }

        //! Initialize the tool with Start and End values.
        void Init(xgp_Quaternion^ theQStart, xgp_Quaternion^ theQEnd) {
            InitFromUnit(theQStart->Normalized(), theQEnd->Normalized());
        }

        //! Initialize the tool with Start and End unit quaternions.
        void InitFromUnit(xgp_Quaternion^ theQStart, xgp_Quaternion^ theQEnd) {
            myQStart = theQStart;
            myQEnd = theQEnd;
            Standard_Real anInner = myQStart->Dot(myQEnd);
            if (anInner < 0.0) {
                myQEnd = -myQEnd;
            }
            myQEnd -= myQStart;
        }

        //! Set interpolated quaternion for theT position (from 0.0 to 1.0)
        void Interpolate(Standard_Real theT, xgp_Quaternion^ theResultQ) {
            theResultQ = *myQStart + myQEnd * theT;
        }

        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        property gp_QuaternionNLerp* Handle
        {
            gp_QuaternionNLerp* get() {
                return NativeHandle;
            }
        }

    private:
        gp_QuaternionNLerp* NativeHandle;
        xgp_Quaternion^ myQStart;
        xgp_Quaternion ^myQEnd;
    };
};
#endif // _xgp_QuaternionNLerp_HeaderFile