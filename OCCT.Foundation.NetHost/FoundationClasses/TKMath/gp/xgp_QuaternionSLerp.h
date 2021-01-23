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

#ifndef _xgp_QuaternionSLerp_HeaderFile
#define _xgp_QuaternionSLerp_HeaderFile
#pragma once
#include <gp_QuaternionSLerp.hxx>
#include <xgp_Quaternion.h>
class gp_QuaternionSLerp;
//! Perform Spherical Linear Interpolation of the quaternions,
//! return unit length quaternion.
namespace TKMath
{
    ref class xgp_Quaternion;
    public ref class xgp_QuaternionSLerp
    {
    public:

        //! Compute interpolated quaternion between two quaternions.
        //! @param theStart first  quaternion
        //! @param theEnd   second quaternion
        //! @param theT normalized interpolation coefficient within 0..1 range,
        //!             with 0 pointing to theStart and 1 to theEnd.
        static xgp_Quaternion^ Interpolate(xgp_Quaternion^ theQStart, xgp_Quaternion^ theQEnd, Standard_Real theT) {
            xgp_Quaternion^ aResult;
            xgp_QuaternionSLerp aLerp(theQStart, theQEnd);
            aLerp.Interpolate(theT, aResult);
            return aResult;
        }

    public:
        !xgp_QuaternionSLerp() { IHandle = NULL; };
        ~xgp_QuaternionSLerp() { IHandle = NULL; };
        //! Empty constructor,
        xgp_QuaternionSLerp() {}

        //! Constructor with initialization.
        xgp_QuaternionSLerp(xgp_Quaternion^ theQStart, xgp_Quaternion^ theQEnd) {
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
            Standard_Real cosOmega = myQStart->Dot(myQEnd);
            if (cosOmega < 0.0) {
                cosOmega = -(cosOmega);
                myQEnd = -myQEnd;
            }
            if (cosOmega > 0.9999) {
                cosOmega = 0.9999;
            }
            myOmega = ACos(cosOmega);
            Standard_Real invSinOmega = (1.0 / Sin(myOmega));
            myQStart->Scale(invSinOmega);
            myQEnd->Scale(invSinOmega);
        }

        //! Set interpolated quaternion for theT position (from 0.0 to 1.0)
        void Interpolate(Standard_Real theT, xgp_Quaternion^ theResultQ) {
            theResultQ = *myQStart * Sin((1.0 - theT) * myOmega) + *myQEnd * Sin(theT * myOmega);
        }

        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property gp_QuaternionSLerp* IHandle {
            gp_QuaternionSLerp* get() {
                return NativeHandle;
            }
            void set(gp_QuaternionSLerp* handle) {
                NativeHandle = handle;
            }
        }
    private:
        gp_QuaternionSLerp* NativeHandle;
        xgp_Quaternion^ myQStart;
        xgp_Quaternion^ myQEnd;
        Standard_Real myOmega;
    };
};
#endif // _xgp_QuaternionSLerp_HeaderFile