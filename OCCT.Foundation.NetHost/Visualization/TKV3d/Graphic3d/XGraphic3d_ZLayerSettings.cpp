#include <XGraphic3d_ZLayerSettings.h>
namespace TKV3d {

    //! Default settings.
    XGraphic3d_ZLayerSettings::XGraphic3d_ZLayerSettings() {
        NativeHandle = new Graphic3d_ZLayerSettings();
    };

    //! Return user-provided name.
    TCollection_AsciiString XGraphic3d_ZLayerSettings::Name() {
        return NativeHandle->Name();
    };// { return myName; }

    //! Set custom name.
    void XGraphic3d_ZLayerSettings::SetName(TCollection_AsciiString& theName) {
        NativeHandle->SetName(theName);
    };// { myName = theName; }

    //! Return lights list to be used for rendering presentations within this Z-Layer; NULL by default.
    //! NULL list (but not empty list!) means that default lights assigned to the View should be used instead of per-layer lights.
    Handle(Graphic3d_LightSet) XGraphic3d_ZLayerSettings::Lights() {
        return NativeHandle->Lights();
    };// { return myLights; }

    //! Assign lights list to be used.
    void XGraphic3d_ZLayerSettings::SetLights(Handle(Graphic3d_LightSet)& theLights) {
        NativeHandle->SetLights(theLights);
    };// { myLights = theLights; }

    //! Return the origin of all objects within the layer.
    xgp_XYZ^ XGraphic3d_ZLayerSettings::Origin() {
        gp_XYZ* temp = new gp_XYZ(NativeHandle->Origin());
        return gcnew xgp_XYZ(temp);
    };// { return myOrigin; }

    //! Return the transformation to the origin.
    Handle(TopLoc_Datum3D) XGraphic3d_ZLayerSettings::OriginTransformation() {
        return  NativeHandle->OriginTransformation();
    };// { return myOriginTrsf; }

    //! Set the origin of all objects within the layer.
    void XGraphic3d_ZLayerSettings::SetOrigin(xgp_XYZ^ theOrigin) {
        NativeHandle->SetOrigin(*theOrigin->GetXYZ());
    };

    //! Return TRUE, if culling of distant objects (distance culling) should be performed; FALSE by default.
    //! @sa CullingDistance()
    Standard_Boolean XGraphic3d_ZLayerSettings::HasCullingDistance() {
        return  NativeHandle->HasCullingDistance();
    };// { return !Precision::IsInfinite(myCullingDistance) && myCullingDistance > 0.0; }

    //! Return the distance to discard drawing of distant objects (distance from camera Eye point); by default it is Infinite (distance culling is disabled).
    //! Since camera eye definition has no strong meaning within orthographic projection, option is considered only within perspective projection.
    //! Note also that this option has effect only when frustum culling is enabled.
    Standard_Real XGraphic3d_ZLayerSettings::CullingDistance() {
        return  NativeHandle->CullingDistance();
    };// { return myCullingDistance; }

    //! Set the distance to discard drawing objects.
    void XGraphic3d_ZLayerSettings::SetCullingDistance(Standard_Real theDistance) {
        NativeHandle->SetCullingDistance(theDistance);
    };// { myCullingDistance = theDistance; }

    //! Return TRUE, if culling of small objects (size culling) should be performed; FALSE by default.
    //! @sa CullingSize()
    Standard_Boolean XGraphic3d_ZLayerSettings::HasCullingSize() {
        return  NativeHandle->HasCullingSize();
    };// { return !Precision::IsInfinite(myCullingSize) && myCullingSize > 0.0; }

    //! Return the size to discard drawing of small objects; by default it is Infinite (size culling is disabled).
    //! Current implementation checks the length of projected diagonal of bounding box in pixels for discarding.
    //! Note that this option has effect only when frustum culling is enabled.
    Standard_Real XGraphic3d_ZLayerSettings::CullingSize() {
        return  NativeHandle->CullingSize();
    };// { return myCullingSize; }

    //! Set the distance to discard drawing objects.
    void XGraphic3d_ZLayerSettings::SetCullingSize(Standard_Real theSize) {
        NativeHandle->SetCullingSize(theSize);
    };// { myCullingSize = theSize; }

    //! Return true if this layer should be drawn after all normal (non-immediate) layers.
    Standard_Boolean XGraphic3d_ZLayerSettings::IsImmediate() {
        return  NativeHandle->IsImmediate();
    };// { return myIsImmediate; }

    //! Set the flag indicating the immediate layer, which should be drawn after all normal (non-immediate) layers.
    void XGraphic3d_ZLayerSettings::SetImmediate(Standard_Boolean theValue) {
        NativeHandle->SetImmediate(theValue);
    };// { myIsImmediate = theValue; }

    //! Returns TRUE if layer should be processed by ray-tracing renderer; TRUE by default.
    //! Note that this flag is IGNORED for layers with IsImmediate() flag.
    Standard_Boolean XGraphic3d_ZLayerSettings::IsRaytracable() {
        return  NativeHandle->IsRaytracable();
    };// { return myToRaytrace; }

    //! Sets if layer should be processed by ray-tracing renderer.
    void XGraphic3d_ZLayerSettings::SetRaytracable(Standard_Boolean theToRaytrace) {
        NativeHandle->SetRaytracable(theToRaytrace);
    };// { myToRaytrace = theToRaytrace; }

    //! Return flag to allow/prevent environment texture mapping usage for specific layer.
    Standard_Boolean XGraphic3d_ZLayerSettings::UseEnvironmentTexture() {
        return  NativeHandle->UseEnvironmentTexture();
    };// { return myUseEnvironmentTexture; }

    //! Set the flag to allow/prevent environment texture mapping usage for specific layer.
    void XGraphic3d_ZLayerSettings::SetEnvironmentTexture(Standard_Boolean theValue) {
        NativeHandle->SetEnvironmentTexture(theValue);
    };// { myUseEnvironmentTexture = theValue; }

    //! Return true if depth test should be enabled.
    Standard_Boolean XGraphic3d_ZLayerSettings::ToEnableDepthTest() {
        return  NativeHandle->ToEnableDepthTest();
    };// { return myToEnableDepthTest; }

    //! Set if depth test should be enabled.
    void XGraphic3d_ZLayerSettings::SetEnableDepthTest(Standard_Boolean theValue) {
        NativeHandle->SetEnableDepthTest(theValue);
    };// { myToEnableDepthTest = theValue; }

    //! Return true depth values should be written during rendering.
    Standard_Boolean XGraphic3d_ZLayerSettings::ToEnableDepthWrite() {
        return  NativeHandle->ToEnableDepthWrite();
    };// { return myToEnableDepthWrite; }

    //! Set if depth values should be written during rendering.
    void XGraphic3d_ZLayerSettings::SetEnableDepthWrite(Standard_Boolean theValue) {
        NativeHandle->SetEnableDepthWrite(theValue);
    };// { myToEnableDepthWrite = theValue; }

    //! Return true if depth values should be cleared before drawing the layer.
    Standard_Boolean XGraphic3d_ZLayerSettings::ToClearDepth() {
        return  NativeHandle->ToClearDepth();
    };// { return myToClearDepth; }

    //! Set if depth values should be cleared before drawing the layer.
    void XGraphic3d_ZLayerSettings::SetClearDepth(Standard_Boolean theValue) {
        NativeHandle->SetClearDepth(theValue);
    };// { myToClearDepth = theValue; }

    //! Return TRUE if layer should be rendered within depth pre-pass; TRUE by default.
    Standard_Boolean XGraphic3d_ZLayerSettings::ToRenderInDepthPrepass() {
        return  NativeHandle->ToRenderInDepthPrepass();
    };// { return myToRenderInDepthPrepass; }

    //! Set if layer should be rendered within depth pre-pass.
    void XGraphic3d_ZLayerSettings::SetRenderInDepthPrepass(Standard_Boolean theToRender) {
        NativeHandle->SetRenderInDepthPrepass(theToRender);
    };// { myToRenderInDepthPrepass = theToRender; }

    //! Return glPolygonOffset() arguments.
    Graphic3d_PolygonOffset XGraphic3d_ZLayerSettings::PolygonOffset() {
        return  NativeHandle->PolygonOffset();
    };// { return myPolygonOffset; }

    //! Setup glPolygonOffset() arguments.
    void XGraphic3d_ZLayerSettings::SetPolygonOffset(Graphic3d_PolygonOffset& theParams) {
        NativeHandle->SetPolygonOffset(theParams);
    };// { myPolygonOffset = theParams; }

    //! Modify glPolygonOffset() arguments.
    Graphic3d_PolygonOffset XGraphic3d_ZLayerSettings::ChangePolygonOffset() {
        return  NativeHandle->ChangePolygonOffset();
    };// { return myPolygonOffset; }


    //! Sets minimal possible positive depth offset.
    void XGraphic3d_ZLayerSettings::SetDepthOffsetPositive() {
        NativeHandle->SetDepthOffsetPositive();
    };

    //! Sets minimal possible negative depth offset.
    void XGraphic3d_ZLayerSettings::SetDepthOffsetNegative() {
        NativeHandle->SetDepthOffsetNegative();
    };
}
