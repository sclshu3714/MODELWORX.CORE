// Copyright (c) 2014 OPEN CASCADE SAS
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

#ifndef _XGraphic3d_ZLayerSettings_HeaderFile
#define _XGraphic3d_ZLayerSettings_HeaderFile
#pragma once
#include <Graphic3d_ZLayerSettings.hxx>
#include <xgp_XYZ.h>

#include <gp_XYZ.hxx>
#include <Geom_Transformation.hxx>
#include <Graphic3d_LightSet.hxx>
#include <Graphic3d_PolygonOffset.hxx>
#include <Precision.hxx>
#include <TCollection_AsciiString.hxx>

using namespace TKMath;
namespace TKV3d {
    public enum class XGraphic3d_ZLayerSetting
    {
        Graphic3d_ZLayerDepthTest = 1,
        Graphic3d_ZLayerDepthWrite = 2,
        Graphic3d_ZLayerDepthClear = 4,
        Graphic3d_ZLayerDepthOffset = 8
    };

    ref class TKMath::xgp_XYZ;

    //! Structure defines list of ZLayer properties.
    public ref struct XGraphic3d_ZLayerSettings
    {
        !XGraphic3d_ZLayerSettings() { IHandle = NULL; };
        ~XGraphic3d_ZLayerSettings() { IHandle = NULL; };
        //! Default settings.
        XGraphic3d_ZLayerSettings();

        //! Return user-provided name.
        TCollection_AsciiString Name();// { return myName; }

        //! Set custom name.
        void SetName(TCollection_AsciiString& theName);// { myName = theName; }

        //! Return lights list to be used for rendering presentations within this Z-Layer; NULL by default.
        //! NULL list (but not empty list!) means that default lights assigned to the View should be used instead of per-layer lights.
        Handle(Graphic3d_LightSet) Lights();// { return myLights; }

        //! Assign lights list to be used.
        void SetLights(Handle(Graphic3d_LightSet)& theLights);// { myLights = theLights; }

        //! Return the origin of all objects within the layer.
        xgp_XYZ^ Origin();// { return myOrigin; }

        //! Return the transformation to the origin.
        Handle(TopLoc_Datum3D) OriginTransformation();// { return myOriginTrsf; }

        //! Set the origin of all objects within the layer.
        void SetOrigin(xgp_XYZ^ theOrigin);

        //! Return TRUE, if culling of distant objects (distance culling) should be performed; FALSE by default.
        //! @sa CullingDistance()
        Standard_Boolean HasCullingDistance();// { return !Precision::IsInfinite(myCullingDistance) && myCullingDistance > 0.0; }

        //! Return the distance to discard drawing of distant objects (distance from camera Eye point); by default it is Infinite (distance culling is disabled).
        //! Since camera eye definition has no strong meaning within orthographic projection, option is considered only within perspective projection.
        //! Note also that this option has effect only when frustum culling is enabled.
        Standard_Real CullingDistance();// { return myCullingDistance; }

        //! Set the distance to discard drawing objects.
        void SetCullingDistance(Standard_Real theDistance);// { myCullingDistance = theDistance; }

        //! Return TRUE, if culling of small objects (size culling) should be performed; FALSE by default.
        //! @sa CullingSize()
        Standard_Boolean HasCullingSize();// { return !Precision::IsInfinite(myCullingSize) && myCullingSize > 0.0; }

        //! Return the size to discard drawing of small objects; by default it is Infinite (size culling is disabled).
        //! Current implementation checks the length of projected diagonal of bounding box in pixels for discarding.
        //! Note that this option has effect only when frustum culling is enabled.
        Standard_Real CullingSize();// { return myCullingSize; }

        //! Set the distance to discard drawing objects.
        void SetCullingSize(Standard_Real theSize);// { myCullingSize = theSize; }

        //! Return true if this layer should be drawn after all normal (non-immediate) layers.
        Standard_Boolean IsImmediate();// { return myIsImmediate; }

        //! Set the flag indicating the immediate layer, which should be drawn after all normal (non-immediate) layers.
        void SetImmediate(Standard_Boolean theValue);// { myIsImmediate = theValue; }

        //! Returns TRUE if layer should be processed by ray-tracing renderer; TRUE by default.
        //! Note that this flag is IGNORED for layers with IsImmediate() flag.
        Standard_Boolean IsRaytracable();// { return myToRaytrace; }

        //! Sets if layer should be processed by ray-tracing renderer.
        void SetRaytracable(Standard_Boolean theToRaytrace);// { myToRaytrace = theToRaytrace; }

        //! Return flag to allow/prevent environment texture mapping usage for specific layer.
        Standard_Boolean UseEnvironmentTexture();// { return myUseEnvironmentTexture; }

        //! Set the flag to allow/prevent environment texture mapping usage for specific layer.
        void SetEnvironmentTexture(Standard_Boolean theValue);// { myUseEnvironmentTexture = theValue; }

        //! Return true if depth test should be enabled.
        Standard_Boolean ToEnableDepthTest();// { return myToEnableDepthTest; }

        //! Set if depth test should be enabled.
        void SetEnableDepthTest(Standard_Boolean theValue);// { myToEnableDepthTest = theValue; }

        //! Return true depth values should be written during rendering.
        Standard_Boolean ToEnableDepthWrite();// { return myToEnableDepthWrite; }

        //! Set if depth values should be written during rendering.
        void SetEnableDepthWrite(Standard_Boolean theValue);// { myToEnableDepthWrite = theValue; }

        //! Return true if depth values should be cleared before drawing the layer.
        Standard_Boolean ToClearDepth();// { return myToClearDepth; }

        //! Set if depth values should be cleared before drawing the layer.
        void SetClearDepth(Standard_Boolean theValue);// { myToClearDepth = theValue; }

        //! Return TRUE if layer should be rendered within depth pre-pass; TRUE by default.
        Standard_Boolean ToRenderInDepthPrepass();// { return myToRenderInDepthPrepass; }

        //! Set if layer should be rendered within depth pre-pass.
        void SetRenderInDepthPrepass(Standard_Boolean theToRender);// { myToRenderInDepthPrepass = theToRender; }

        //! Return glPolygonOffset() arguments.
        Graphic3d_PolygonOffset PolygonOffset();// { return myPolygonOffset; }

        //! Setup glPolygonOffset() arguments.
        void SetPolygonOffset(Graphic3d_PolygonOffset& theParams);// { myPolygonOffset = theParams; }

        //! Modify glPolygonOffset() arguments.
        Graphic3d_PolygonOffset ChangePolygonOffset();// { return myPolygonOffset; }


        //! Sets minimal possible positive depth offset.
        void SetDepthOffsetPositive();

        //! Sets minimal possible negative depth offset.
        void SetDepthOffsetNegative();

        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property Graphic3d_ZLayerSettings* IHandle {
            Graphic3d_ZLayerSettings* get() { // Standard_OVERRIDE {
                return NativeHandle;
            }
            void set(Graphic3d_ZLayerSettings* handle) { // Standard_OVERRIDE {
                NativeHandle = handle;
            }
        }
    private:
        Graphic3d_ZLayerSettings* NativeHandle;
    };
}
#endif // _XGraphic3d_ZLayerSettings_HeaderFile
