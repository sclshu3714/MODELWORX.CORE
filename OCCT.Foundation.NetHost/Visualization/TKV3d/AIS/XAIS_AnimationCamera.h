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

#ifndef _XAIS_AnimationCamera_HeaderFile
#define _XAIS_AnimationCamera_HeaderFile
#pragma once
#include <AIS_AnimationCamera.hxx>
#include <XAIS_Animation.h>
#include <XTCollection_AsciiString.h>
#include <XAIS_InteractiveContext.h>
#include <XAIS_InteractiveObject.h>
#include <xgp_Trsf.h>
#include <XV3d_View.h>

#include <AIS_Animation.hxx>

class AIS_AnimationCamera;
class Graphic3d_Camera;
class V3d_View;

namespace TKV3d {
    ref class XV3d_View;
    //! Camera animation.
    public ref class XAIS_AnimationCamera : public XAIS_Animation
    {
        //! DEFINE_STANDARD_RTTIEXT(AIS_AnimationCamera, AIS_Animation)
    public:

        !XAIS_AnimationCamera() { IHandle = NULL; };
        ~XAIS_AnimationCamera() { IHandle = NULL; };
        //! Main constructor.
        XAIS_AnimationCamera(XTCollection_AsciiString^ theAnimationName, XV3d_View^ theView);

        //! Return the target view.
        XV3d_View^ View();

        //! Set target view.
        void SetView(XV3d_View^ theView);

        //! Return camera start position.
        Handle(Graphic3d_Camera) CameraStart();

        //! Define camera start position.
        void SetCameraStart(const Handle(Graphic3d_Camera)& theCameraStart);

        //! Return camera end position.
        Handle(Graphic3d_Camera) CameraEnd();

        //! Define camera end position.
        void SetCameraEnd(const Handle(Graphic3d_Camera)& theCameraEnd);


        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property Handle(Standard_Transient) IHandle {
            Handle(Standard_Transient) get() Standard_OVERRIDE {
                return NativeHandle();
            }
            void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
                NativeHandle() = Handle(AIS_AnimationCamera)::DownCast(handle);
            }
        }
    private:
        NCollection_Haft<Handle(AIS_AnimationCamera)> NativeHandle;

    };

    //! DEFINE_STANDARD_HANDLE(AIS_AnimationCamera, AIS_Animation)
}
#endif // _XAIS_AnimationCamera_HeaderFile
