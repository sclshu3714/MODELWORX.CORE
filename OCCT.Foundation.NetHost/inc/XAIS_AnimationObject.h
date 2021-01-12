// Created by: Anastasia BORISOVA
// Copyright (c) 2016 OPEN CASCADE SAS
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

#ifndef _XAIS_AnimationObject_HeaderFile
#define _XAIS_AnimationObject_HeaderFile
#pragma once
#include <AIS_AnimationObject.hxx>
#include <XAIS_Animation.h>
#include <XTCollection_AsciiString.h>
#include <XAIS_InteractiveContext.h>
#include <XAIS_InteractiveObject.h>
#include <xgp_Trsf.h>

#include <AIS_Animation.hxx>
#include <AIS_InteractiveContext.hxx>
#include <gp_TrsfNLerp.hxx>
class AIS_AnimationObject;

using namespace TKernel;
using namespace TKMath;
namespace TKV3d {
    ref class XAIS_InteractiveContext;
    ref class XAIS_InteractiveObject;
    ref class TKMath::xgp_Trsf;
    ref class TKernel::XTCollection_AsciiString;
    //! Animation defining object transformation.
    public ref class XAIS_AnimationObject : public XAIS_Animation
    {
        //! DEFINE_STANDARD_RTTIEXT(AIS_AnimationObject, AIS_Animation)
    public:
        //! Creates empty animation.
       /* XAIS_AnimationObject(XTCollection_AsciiString^ theAnimationName);

        XAIS_AnimationObject(Handle(AIS_AnimationObject) pos);*/

        void SetAnimationObjectHandle(Handle(AIS_AnimationObject) pos);

        virtual Handle(AIS_AnimationObject) GetAnimationObject();

        virtual Handle(AIS_Animation) GetAnimation() Standard_OVERRIDE;

        //! Constructor with initialization.
        //! Note that start/end transformations specify exactly local transformation of the object,
        //! not the transformation to be applied to existing local transformation.
        //! @param theAnimationName animation identifier
        //! @param theContext       interactive context where object have been displayed
        //! @param theObject        object to apply local transformation
        //! @param theTrsfStart     local transformation at the start of animation (e.g. theObject->LocalTransformation())
        //! @param theTrsfEnd       local transformation at the end   of animation
        XAIS_AnimationObject(XTCollection_AsciiString^ theAnimationName,XAIS_InteractiveContext^ theContext,XAIS_InteractiveObject^ theObject, xgp_Trsf^ theTrsfStart, xgp_Trsf^ theTrsfEnd);
        
        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property Handle(Standard_Transient) IHandle {
            Handle(Standard_Transient) get() Standard_OVERRIDE {
                return NativeHandle();
            }
            void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
                NativeHandle() = Handle(AIS_AnimationObject)::DownCast(handle);
            }
        }
    private:
        NCollection_Haft<Handle(AIS_AnimationObject)> NativeHandle;
    };

    //! DEFINE_STANDARD_HANDLE(AIS_AnimationObject, AIS_Animation)
}
#endif // _XAIS_AnimationObject_HeaderFile
