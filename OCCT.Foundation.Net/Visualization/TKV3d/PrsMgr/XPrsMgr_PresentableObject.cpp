#include <XPrsMgr_PresentableObject.h>

namespace TKV3d {

    XPrsMgr_PresentableObject::XPrsMgr_PresentableObject() {
        
    };

    XPrsMgr_PresentableObject::XPrsMgr_PresentableObject(Handle(PrsMgr_PresentableObject) pos) {
        NativeHandle() = pos;
    };

    //! 
    void XPrsMgr_PresentableObject::SetBaseNativeHandle(Handle(PrsMgr_PresentableObject) pos) {
        NativeHandle() = pos;
    };

    Handle(PrsMgr_PresentableObject) XPrsMgr_PresentableObject::GetPresentableObject() {
        return NativeHandle();
    };

    //! Return presentations.
    PrsMgr_Presentations& XPrsMgr_PresentableObject::Presentations() {
        return NativeHandle()->Presentations();
    };

    //! Get ID of Z layer for main presentation.
    Graphic3d_ZLayerId XPrsMgr_PresentableObject::ZLayer() {
        return NativeHandle()->ZLayer();
    };

    //! Set Z layer ID and update all presentations of the presentable object.
    //! The layers mechanism allows drawing objects in higher layers in overlay of objects in lower layers.
    void XPrsMgr_PresentableObject::SetZLayer(const Graphic3d_ZLayerId theLayerId) {
        NativeHandle()->SetZLayer(theLayerId);
    };

    //! Returns true if object has mutable nature (content or location are be changed regularly).
    //! Mutable object will be managed in different way than static onces (another optimizations).
    Standard_Boolean XPrsMgr_PresentableObject::IsMutable() {
        return NativeHandle()->IsMutable();
    };

    //! Sets if the object has mutable nature (content or location will be changed regularly).
    //! This method should be called before object displaying to take effect.
    void XPrsMgr_PresentableObject::SetMutable(const Standard_Boolean theIsMutable) {
        NativeHandle()->SetMutable(theIsMutable);
    };

    //! Returns true if the Interactive Object has display mode setting overriding global setting (within Interactive Context).
    Standard_Boolean XPrsMgr_PresentableObject::HasDisplayMode() {
        return NativeHandle()->HasDisplayMode();
    };

    //! Returns the display mode setting of the Interactive Object.
    //! The range of supported display mode indexes should be specified within object definition and filtered by AccepDisplayMode().
    //! @sa AcceptDisplayMode()
    Standard_Integer XPrsMgr_PresentableObject::DisplayMode() {
        return NativeHandle()->DisplayMode();
    };

    //! Sets the display mode for the interactive object.
    //! An object can have its own temporary display mode, which is different from that proposed by the interactive context.
    //! @sa AcceptDisplayMode()
    void XPrsMgr_PresentableObject::SetDisplayMode(const Standard_Integer theMode) {
        NativeHandle()->SetDisplayMode(theMode);
    };

    //! Removes display mode settings from the interactive object.
    void XPrsMgr_PresentableObject::UnsetDisplayMode() {
        NativeHandle()->UnsetDisplayMode();
    };

    //! Returns true if the Interactive Object is in highlight mode.
    Standard_Boolean XPrsMgr_PresentableObject::HasHilightMode() {
        return NativeHandle()->HasHilightMode();
    };

    //! Returns highlight display mode.
    //! This is obsolete method for backward compatibility - use ::HilightAttributes() and ::DynamicHilightAttributes() instead.
    Standard_Integer XPrsMgr_PresentableObject::HilightMode() {
        return NativeHandle()->HilightMode();
    };

    //! Sets highlight display mode.
    //! This is obsolete method for backward compatibility - use ::HilightAttributes() and ::DynamicHilightAttributes() instead.
    void XPrsMgr_PresentableObject::SetHilightMode(const Standard_Integer theMode) {
        return NativeHandle()->SetHilightMode(theMode);
    };

    //! Unsets highlight display mode.
    void XPrsMgr_PresentableObject::UnsetHilightMode() {
        NativeHandle()->UnsetHilightMode();
    };

    //! Returns true if the class of objects accepts specified display mode index.
    //! The interactive context can have a default mode of representation for the set of Interactive Objects.
    //! This mode may not be accepted by a given class of objects.
    //! Consequently, this method allowing us to get information about the class in question must be implemented.
    //! At least one display mode index should be accepted by this method.
    //! Although subclass can leave default implementation, it is highly desired defining exact list of supported modes instead,
    //! which is usually an enumeration for one object or objects class sharing similar list of display modes.
    Standard_Boolean XPrsMgr_PresentableObject::AcceptDisplayMode(const Standard_Integer theMode) {
        return NativeHandle()->AcceptDisplayMode(theMode);
    };

    //! Returns the default display mode.
    Standard_Integer XPrsMgr_PresentableObject::DefaultDisplayMode() {
        return NativeHandle()->DefaultDisplayMode();
    };

    //! Returns TRUE if any active presentation has invalidation flag.
    //! @param theToIncludeHidden when TRUE, also checks hidden presentations
    //! theToIncludeHidden = Standard_False
    Standard_Boolean XPrsMgr_PresentableObject::ToBeUpdated(Standard_Boolean theToIncludeHidden) {
        return NativeHandle()->ToBeUpdated(theToIncludeHidden);
    };

    //! Flags presentation to be updated; UpdatePresentations() will recompute these presentations.
    //! @param theMode presentation (display mode) to invalidate, or -1 to invalidate them all
    void XPrsMgr_PresentableObject::SetToUpdate(Standard_Integer theMode) {
        return NativeHandle()->SetToUpdate(theMode);
    };

    //! flags all the Presentations to be Updated.
    void XPrsMgr_PresentableObject::SetToUpdate() {
        NativeHandle()->SetToUpdate();
    };

    //! Returns true if the interactive object is infinite; FALSE by default.
    //! This flag affects various operations operating on bounding box of graphic presentations of this object.
    //! For instance, infinite objects are not taken in account for View FitAll.
    //! This does not necessarily means that object is actually infinite,
    //! auxiliary objects might be also marked with this flag to achieve desired behavior.
    Standard_Boolean XPrsMgr_PresentableObject::IsInfinite() {
        return NativeHandle()->IsInfinite();
    };

    //! Sets if object should be considered as infinite.
    //! theFlag = Standard_True
    void XPrsMgr_PresentableObject::SetInfiniteState(const Standard_Boolean theFlag) {
        NativeHandle()->SetInfiniteState(theFlag);
    };

    //! Returns information on whether the object accepts display in HLR mode or not.
    XPrsMgr_TypeOfPresentation3d XPrsMgr_PresentableObject::TypeOfPresentation3d() {
        return safe_cast<XPrsMgr_TypeOfPresentation3d>(NativeHandle()->TypeOfPresentation3d());
    };

    //! Set type of presentation.
    void XPrsMgr_PresentableObject::SetTypeOfPresentation(XPrsMgr_TypeOfPresentation3d theType) {
        NativeHandle()->SetTypeOfPresentation(safe_cast<PrsMgr_TypeOfPresentation3d>(theType));
    };

    //! @name presentation attributes

    //! Returns the attributes settings.
    XPrs3d_Drawer^ XPrsMgr_PresentableObject::Attributes() {
        return gcnew XPrs3d_Drawer(NativeHandle()->Attributes());
    };

    //! Initializes the drawing tool theDrawer.
    void XPrsMgr_PresentableObject::SetAttributes(XPrs3d_Drawer^ theDrawer) {
        NativeHandle()->SetAttributes(theDrawer->GetDrawer());
    };

    //! Returns the hilight attributes settings.
    //! When not NULL, overrides both Prs3d_TypeOfHighlight_LocalSelected and Prs3d_TypeOfHighlight_Selected defined within AIS_InteractiveContext.
    XPrs3d_Drawer^ XPrsMgr_PresentableObject::HilightAttributes() {
        return gcnew XPrs3d_Drawer(NativeHandle()->HilightAttributes());
    };

    //! Initializes the hilight drawing tool theDrawer.
    void XPrsMgr_PresentableObject::SetHilightAttributes(XPrs3d_Drawer^ theDrawer) {
        NativeHandle()->SetHilightAttributes(theDrawer->GetDrawer());
    };

    //! Returns the hilight attributes settings.
    //! When not NULL, overrides both Prs3d_TypeOfHighlight_LocalDynamic and Prs3d_TypeOfHighlight_Dynamic defined within AIS_InteractiveContext.
    XPrs3d_Drawer^ XPrsMgr_PresentableObject::DynamicHilightAttributes() {
        return gcnew XPrs3d_Drawer(NativeHandle()->DynamicHilightAttributes());
    };

    //! Initializes the dynamic hilight drawing tool.
    void XPrsMgr_PresentableObject::SetDynamicHilightAttributes(XPrs3d_Drawer^ theDrawer) {
        NativeHandle()->SetDynamicHilightAttributes(theDrawer->GetDrawer());
    };

    //! Clears settings provided by the hilight drawing tool theDrawer.
    void XPrsMgr_PresentableObject::UnsetHilightAttributes() {
        NativeHandle()->UnsetHilightAttributes();
    };

    //! Synchronize presentation aspects after their modification.
    //!
    //! This method should be called after modifying primitive aspect properties (material, texture, shader)
    //! so that modifications will take effect on already computed presentation groups (thus avoiding re-displaying the object).
    void XPrsMgr_PresentableObject::SynchronizeAspects() {
        NativeHandle()->SynchronizeAspects();
    };

       //! @name object transformation

      //! Returns Transformation Persistence defining a special Local Coordinate system where this presentable object is located or NULL handle if not defined.
      //! Position of the object having Transformation Persistence is mutable and depends on camera position.
      //! The same applies to a bounding box of the object.
      //! @sa Graphic3d_TransformPers class description
    const Handle(Graphic3d_TransformPers)& XPrsMgr_PresentableObject::TransformPersistence() {
        return NativeHandle()->TransformPersistence();
    };

    //! Sets up Transform Persistence defining a special Local Coordinate system where this object should be located.
    //! Note that management of Transform Persistence object is more expensive than of the normal one,
    //! because it requires its position being recomputed basing on camera position within each draw call / traverse.
    //! @sa Graphic3d_TransformPers class description
    void XPrsMgr_PresentableObject::SetTransformPersistence(const Handle(Graphic3d_TransformPers)& theTrsfPers) {
        NativeHandle()->SetTransformPersistence(theTrsfPers);
    };

    //! Return the local transformation.
    //! Note that the local transformation of the object having Transformation Persistence
    //! is applied within Local Coordinate system defined by this Persistence.
    const Handle(Geom_Transformation)& XPrsMgr_PresentableObject::LocalTransformationGeom() {
          return NativeHandle()->LocalTransformationGeom();
    };

    //! Sets local transformation to theTransformation.
    //! Note that the local transformation of the object having Transformation Persistence
    //! is applied within Local Coordinate system defined by this Persistence.
    void XPrsMgr_PresentableObject::SetLocalTransformation(xgp_Trsf^ theTrsf) {
        NativeHandle()->SetLocalTransformation(*theTrsf->GetTrsf());
    };

    //! Sets local transformation to theTransformation.
    //! Note that the local transformation of the object having Transformation Persistence
    //! is applied within Local Coordinate system defined by this Persistence.
    void XPrsMgr_PresentableObject::SetLocalTransformation(const Handle(Geom_Transformation)& theTrsf) {
        NativeHandle()->SetLocalTransformation(theTrsf);
    };

    //! Returns true if object has a transformation that is different from the identity.
    Standard_Boolean XPrsMgr_PresentableObject::HasTransformation() {
        return NativeHandle()->HasTransformation();
    };

    //! Return the transformation taking into account transformation of parent object(s).
    //! Note that the local transformation of the object having Transformation Persistence
    //! is applied within Local Coordinate system defined by this Persistence.
    const Handle(Geom_Transformation)& XPrsMgr_PresentableObject::TransformationGeom() {
        return NativeHandle()->TransformationGeom();
    };

    //! Return the local transformation.
    //! Note that the local transformation of the object having Transformation Persistence
    //! is applied within Local Coordinate system defined by this Persistence.
    const xgp_Trsf^ XPrsMgr_PresentableObject::LocalTransformation() {
        gp_Trsf* temp = new gp_Trsf(NativeHandle()->LocalTransformation());
        return gcnew xgp_Trsf(temp);
    };

    //! Return the transformation taking into account transformation of parent object(s).
    //! Note that the local transformation of the object having Transformation Persistence
    //! is applied within Local Coordinate system defined by this Persistence.
    const xgp_Trsf^ XPrsMgr_PresentableObject::Transformation() {
        gp_Trsf* temp = new gp_Trsf(NativeHandle()->Transformation());
        return gcnew xgp_Trsf(temp);
    };

    //! Return inversed transformation.
    const xgp_GTrsf^ XPrsMgr_PresentableObject::InversedTransformation() {
        gp_GTrsf* temp = new gp_GTrsf(NativeHandle()->InversedTransformation());
        return gcnew xgp_GTrsf(temp);
    };

    //! Return combined parent transformation.
    const Handle(Geom_Transformation)& XPrsMgr_PresentableObject::CombinedParentTransformation() {
        return NativeHandle()->CombinedParentTransformation();
    };

    //! resets local transformation to identity.
    void XPrsMgr_PresentableObject::ResetTransformation() {
        NativeHandle()->ResetTransformation();
    };

    //! Updates final transformation (parent + local) of presentable object and its presentations.
    void XPrsMgr_PresentableObject::UpdateTransformation() {
        NativeHandle()->UpdateTransformation();
    };

    //! @name clipping planes

    //! Get clip planes.
    //! @return set of previously added clip planes for all display mode presentations.
    const Handle(Graphic3d_SequenceOfHClipPlane)& XPrsMgr_PresentableObject::ClipPlanes() {
        return NativeHandle()->ClipPlanes();
    };

    //! Set clip planes for graphical clipping for all display mode presentations.
    //! The composition of clip planes truncates the rendering space to convex volume.
    //! Please be aware that number of supported clip plane is limited.
    //! The planes which exceed the limit are ignored.
    //! Besides of this, some planes can be already set in view where the object is shown:
    //! the number of these planes should be subtracted from limit to predict the maximum
    //! possible number of object clipping planes.
    void XPrsMgr_PresentableObject::SetClipPlanes(const Handle(Graphic3d_SequenceOfHClipPlane)& thePlanes) {
        NativeHandle()->SetClipPlanes(thePlanes);
    };

    //! Adds clip plane for graphical clipping for all display mode
    //! presentations. The composition of clip planes truncates the rendering
    //! space to convex volume. Please be aware that number of supported
    //! clip plane is limited. The planes which exceed the limit are ignored.
    //! Besides of this, some planes can be already set in view where the object
    //! is shown: the number of these planes should be subtracted from limit
    //! to predict the maximum possible number of object clipping planes.
    //! @param thePlane [in] the clip plane to be appended to map of clip planes.
    void XPrsMgr_PresentableObject::AddClipPlane(const Handle(Graphic3d_ClipPlane)& thePlane) {
        NativeHandle()->AddClipPlane(thePlane);
    };

    //! Removes previously added clip plane.
    //! @param thePlane [in] the clip plane to be removed from map of clip planes.
    void XPrsMgr_PresentableObject::RemoveClipPlane(const Handle(Graphic3d_ClipPlane)& thePlane) {
        NativeHandle()->RemoveClipPlane(thePlane);
    };

    //! @name parent/children properties

    //! Returns parent of current object in scene hierarchy.
    XPrsMgr_PresentableObject^ XPrsMgr_PresentableObject::Parent() {
        return gcnew XPrsMgr_PresentableObject(NativeHandle()->Parent());
    };

    //! Returns children of the current object.
    const PrsMgr_ListOfPresentableObjects& XPrsMgr_PresentableObject::Children() {
        return NativeHandle()->Children();
    };

    //! Makes theObject child of current object in scene hierarchy.
    void XPrsMgr_PresentableObject::AddChild(XPrsMgr_PresentableObject^ theObject) {
        NativeHandle()->AddChild(theObject->GetPresentableObject());
    };

    //! Makes theObject child of current object in scene hierarchy with keeping the current global transformation
    //! So the object keeps the same position/orientation in the global CS.
    void XPrsMgr_PresentableObject::AddChildWithCurrentTransformation(XPrsMgr_PresentableObject^ theObject) {
        NativeHandle()->AddChildWithCurrentTransformation(theObject->GetPresentableObject());
    };

    //! Removes theObject from children of current object in scene hierarchy.
    void XPrsMgr_PresentableObject::RemoveChild(XPrsMgr_PresentableObject^ theObject) {
        NativeHandle()->RemoveChild(theObject->GetPresentableObject());
    };

    //! Removes theObject from children of current object in scene hierarchy with keeping the current global transformation.
    //! So the object keeps the same position/orientation in the global CS.
    void XPrsMgr_PresentableObject::RemoveChildWithRestoreTransformation(XPrsMgr_PresentableObject^ theObject) {
        NativeHandle()->RemoveChildWithRestoreTransformation(theObject->GetPresentableObject());
    };

    //! Returns true if object should have own presentations.
    Standard_Boolean XPrsMgr_PresentableObject::HasOwnPresentations() {
        return NativeHandle()->HasOwnPresentations();
    };

    //! Returns bounding box of object correspondingly to its current display mode.
    //! This method requires presentation to be already computed, since it relies on bounding box of presentation structures,
    //! which are supposed to be same/close amongst different display modes of this object.
    void XPrsMgr_PresentableObject::BoundingBox(Bnd_Box& theBndBox) {

    };
    //! @name simplified presentation properties API

    //! Enables or disables on-triangulation build of isolines according to the flag given.
    void XPrsMgr_PresentableObject::SetIsoOnTriangulation(const Standard_Boolean theIsEnabled) {
        NativeHandle()->SetIsoOnTriangulation(theIsEnabled);
    };

    //! Returns the current facing model which is in effect.
    XAspect_TypeOfFacingModel XPrsMgr_PresentableObject::CurrentFacingModel() {
        return safe_cast<XAspect_TypeOfFacingModel>(NativeHandle()->CurrentFacingModel());
    };

    //! change the current facing model apply on polygons for SetColor(), SetTransparency(), SetMaterial() methods default facing model is Aspect_TOFM_TWO_SIDE.
    //! This mean that attributes is applying both on the front and back face.
    //! theModel = Aspect_TOFM_BOTH_SIDE
    void XPrsMgr_PresentableObject::SetCurrentFacingModel(XAspect_TypeOfFacingModel theModel) {
        NativeHandle()->SetCurrentFacingModel(safe_cast<Aspect_TypeOfFacingModel>(theModel));
    };

    //! Returns true if the Interactive Object has color.
    Standard_Boolean XPrsMgr_PresentableObject::HasColor() {
        return NativeHandle()->HasColor();
    };

    //! Returns the color setting of the Interactive Object.
    void XPrsMgr_PresentableObject::Color(XQuantity_Color^ theColor) {
        NativeHandle()->Color(theColor->GetColor());
    };

    //! Only the interactive object knowns which Drawer attribute is affected by the color, if any
    //! (ex: for a wire,it's the wireaspect field of the drawer, but for a vertex, only the point aspect field is affected by the color).
    //! WARNING : Do not forget to set the corresponding fields here (hasOwnColor and myDrawer->SetColor())
    void XPrsMgr_PresentableObject::SetColor(XQuantity_Color^ theColor) {
        NativeHandle()->SetColor(theColor->GetColor());
    };

    //! Removes color settings. Only the Interactive Object
    //! knows which Drawer attribute is   affected by the color
    //! setting. For a wire, for example, wire aspect is the
    //! attribute affected. For a vertex, however, only point
    //! aspect is affected by the color setting.
    void XPrsMgr_PresentableObject::UnsetColor() {
        NativeHandle()->UnsetColor();
    };

    //! Returns true if the Interactive Object has width.
    Standard_Boolean XPrsMgr_PresentableObject::HasWidth() {
        return NativeHandle()->HasWidth();
    };

    //! Returns the width setting of the Interactive Object.
    Standard_Real XPrsMgr_PresentableObject::Width() {
        return NativeHandle()->Width();
    };

    //! Allows you to provide the setting aValue for width.
    //! Only the Interactive Object knows which Drawer attribute is affected by the width setting.
    void XPrsMgr_PresentableObject::SetWidth(const Standard_Real theWidth) {
        NativeHandle()->SetWidth(theWidth);
    };

    //! Reset width to default value.
    void XPrsMgr_PresentableObject::UnsetWidth() {
        NativeHandle()->UnsetWidth();
    };

    //! Returns true if the Interactive Object has a setting for material.
    Standard_Boolean XPrsMgr_PresentableObject::HasMaterial() {
        return NativeHandle()->HasMaterial();
    };

    //! Returns the current material setting as enumeration value.
    XGraphic3d_NameOfMaterial XPrsMgr_PresentableObject::Material() {
        return safe_cast<XGraphic3d_NameOfMaterial>(NativeHandle()->Material());
    };

    //! Sets the material aMat defining this display attribute
    //! for the interactive object.
    //! Material aspect determines shading aspect, color and
    //! transparency of visible entities.
    void XPrsMgr_PresentableObject::SetMaterial(XGraphic3d_MaterialAspect^ aName) {
        NativeHandle()->SetMaterial(aName->GetMaterialAspect());
    };

    //! Removes the setting for material.
    void XPrsMgr_PresentableObject::UnsetMaterial() {
        NativeHandle()->UnsetMaterial();
    };

    //! Returns true if there is a transparency setting.
    Standard_Boolean XPrsMgr_PresentableObject::IsTransparent() {
         return NativeHandle()->IsTransparent();
    };

    //! Returns the transparency setting.
    //! This will be between 0.0 and 1.0.
    //! At 0.0 an object will be totally opaque, and at 1.0, fully transparent.
    Standard_Real XPrsMgr_PresentableObject::Transparency() {
        return NativeHandle()->Transparency();
    };

    //! Attributes a setting aValue for transparency.
    //! The transparency value should be between 0.0 and 1.0.
    //! At 0.0 an object will be totally opaque, and at 1.0, fully transparent.
    //! Warning At a value of 1.0, there may be nothing visible.
    //! aValue = 0.6
    void XPrsMgr_PresentableObject::SetTransparency(const Standard_Real aValue) {
         NativeHandle()->SetTransparency(aValue);
    };

    //! Removes the transparency setting. The object is opaque by default.
    void XPrsMgr_PresentableObject::UnsetTransparency() {
        NativeHandle()->UnsetTransparency();
    };

    //! Returns Standard_True if <myDrawer> has non-null shading aspect
    Standard_Boolean XPrsMgr_PresentableObject::HasPolygonOffsets() {
        return NativeHandle()->HasPolygonOffsets();
    };

    //! Retrieves current polygon offsets settings from <myDrawer>.
    void XPrsMgr_PresentableObject::PolygonOffsets(Standard_Integer& aMode, Standard_ShortReal& aFactor, Standard_ShortReal& aUnits) {
        NativeHandle()->PolygonOffsets(aMode, aFactor, aUnits);
    };

    //! Sets up polygon offsets for this object.
    //! @sa Graphic3d_Aspects::SetPolygonOffsets()
    //! aFactor = 1.0    aUnits = 0.0
    void XPrsMgr_PresentableObject::SetPolygonOffsets(const Standard_Integer aMode, const Standard_ShortReal aFactor, const Standard_ShortReal aUnits) {
        NativeHandle()->SetPolygonOffsets(aMode, aFactor, aUnits);
    };

    //! Clears settings provided by the drawing tool aDrawer.
    void XPrsMgr_PresentableObject::UnsetAttributes() {
        NativeHandle()->UnsetAttributes();
    };

    //! Dumps the content of me into the stream
    //! theDepth = -1
    void XPrsMgr_PresentableObject::DumpJson(Standard_OStream& theOStream, const Standard_Integer theDepth) {
        NativeHandle()->DumpJson(theOStream, theDepth);
    };

    //! @name deprecated methods
    //! Get value of the flag "propagate visual state"
    //! It means that the display/erase/color visual state is propagated automatically to all children;
    //! by default, the flag is true 
    Standard_Boolean XPrsMgr_PresentableObject::ToPropagateVisualState() {
         return NativeHandle()->ToPropagateVisualState();
    };

    //! Change the value of the flag "propagate visual state"
    void XPrsMgr_PresentableObject::SetPropagateVisualState(const Standard_Boolean theFlag) {
        NativeHandle()->SetPropagateVisualState(theFlag);
    };
}
