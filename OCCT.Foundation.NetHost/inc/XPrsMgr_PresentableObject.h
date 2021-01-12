// Created on: 1995-01-25
// Created by: Jean-Louis Frenkel
// Copyright (c) 1995-1999 Matra Datavision
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

#ifndef _XPrsMgr_PresentableObject_HeaderFile
#define _XPrsMgr_PresentableObject_HeaderFile
#pragma once
#include <PrsMgr_PresentableObject.hxx>
#include "NCollection_Haft.h"
#include "xgp_Trsf.h"
#include "xgp_GTrsf.h"
#include "XAspect_TypeOfFacingModel.h"
#include "XPrs3d_Drawer.h"
#include "XPrsMgr_TypeOfPresentation3d.h"
#include "XGraphic3d_NameOfMaterial.h"
#include <XGraphic3d_MaterialAspect.h>

#include <Aspect_TypeOfFacingModel.hxx>
#include <gp_GTrsf.hxx>
#include <Graphic3d_ClipPlane.hxx>
#include <Graphic3d_SequenceOfHClipPlane.hxx>
#include <Graphic3d_TransformPers.hxx>
#include <Graphic3d_TransModeFlags.hxx>
#include <Graphic3d_ZLayerId.hxx>
#include <Prs3d_Drawer.hxx>
#include <PrsMgr_ListOfPresentableObjects.hxx>
#include <PrsMgr_Presentation.hxx>
#include <PrsMgr_Presentations.hxx>
#include <PrsMgr_TypeOfPresentation3d.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <TopLoc_Datum3D.hxx>

//class PrsMgr_PresentationManager;
//typedef PrsMgr_PresentationManager PrsMgr_PresentationManager3d;

//! A framework to supply the Graphic3d structure of the object to be presented.
//! On the first display request, this structure is created by calling the appropriate algorithm and retaining this framework for further display.
//! This abstract framework is inherited in Application Interactive Services (AIS), notably by AIS_InteractiveObject.
//! Consequently, 3D presentation should be handled by the relevant daughter classes and their member functions in AIS.
//! This is particularly true in the creation of new interactive objects.
//!
//! Key interface methods to be implemented by every Selectable Object:
//! - AcceptDisplayMode() accepting display modes implemented by this object;
//! - Compute() computing presentation for the given display mode index.
//!
//! Warning! Methods managing standard attributes (SetColor(), SetWidth(), SetMaterial()) have different meaning for objects of different type (or no meaning at all).
//! Sub-classes might override these methods to modify Prs3d_Drawer or class properties providing a convenient short-cut depending on application needs.
//! For more sophisticated configuring, Prs3d_Drawer should be modified directly, while short-cuts might be left unimplemented.
using namespace TKMath;
namespace TKV3d {
    ref class TKMath::xgp_Trsf;
    ref class TKMath::xgp_GTrsf;
    ref class XGraphic3d_MaterialAspect;
    public ref class XPrsMgr_PresentableObject //: public Standard_Transient
    {
       //! DEFINE_STANDARD_RTTIEXT(PrsMgr_PresentableObject, Standard_Transient)
       //!     friend class PrsMgr_Presentation;
       //! friend class PrsMgr_PresentationManager;
    public:
        //!
        XPrsMgr_PresentableObject();
        //!
        XPrsMgr_PresentableObject(Handle(PrsMgr_PresentableObject) pos);

        //! 
        void SetBaseNativeHandle(Handle(PrsMgr_PresentableObject) pos);

        virtual Handle(PrsMgr_PresentableObject) GetPresentableObject();

        //! Return presentations.
        PrsMgr_Presentations& Presentations();

        //! Get ID of Z layer for main presentation.
        Graphic3d_ZLayerId ZLayer();

        //! Set Z layer ID and update all presentations of the presentable object.
        //! The layers mechanism allows drawing objects in higher layers in overlay of objects in lower layers.
        virtual void SetZLayer(const Graphic3d_ZLayerId theLayerId);

        //! Returns true if object has mutable nature (content or location are be changed regularly).
        //! Mutable object will be managed in different way than static onces (another optimizations).
        Standard_Boolean IsMutable();

        //! Sets if the object has mutable nature (content or location will be changed regularly).
        //! This method should be called before object displaying to take effect.
        virtual void SetMutable(const Standard_Boolean theIsMutable);

        //! Returns true if the Interactive Object has display mode setting overriding global setting (within Interactive Context).
        Standard_Boolean HasDisplayMode();

        //! Returns the display mode setting of the Interactive Object.
        //! The range of supported display mode indexes should be specified within object definition and filtered by AccepDisplayMode().
        //! @sa AcceptDisplayMode()
        Standard_Integer DisplayMode();

        //! Sets the display mode for the interactive object.
        //! An object can have its own temporary display mode, which is different from that proposed by the interactive context.
        //! @sa AcceptDisplayMode()
        void SetDisplayMode(const Standard_Integer theMode);

        //! Removes display mode settings from the interactive object.
        void UnsetDisplayMode();

        //! Returns true if the Interactive Object is in highlight mode.
        Standard_Boolean HasHilightMode();

        //! Returns highlight display mode.
        //! This is obsolete method for backward compatibility - use ::HilightAttributes() and ::DynamicHilightAttributes() instead.
        Standard_Integer HilightMode();

        //! Sets highlight display mode.
        //! This is obsolete method for backward compatibility - use ::HilightAttributes() and ::DynamicHilightAttributes() instead.
        void SetHilightMode(const Standard_Integer theMode);

        //! Unsets highlight display mode.
        void UnsetHilightMode();

        //! Returns true if the class of objects accepts specified display mode index.
        //! The interactive context can have a default mode of representation for the set of Interactive Objects.
        //! This mode may not be accepted by a given class of objects.
        //! Consequently, this virtual method allowing us to get information about the class in question must be implemented.
        //! At least one display mode index should be accepted by this method.
        //! Although subclass can leave default implementation, it is highly desired defining exact list of supported modes instead,
        //! which is usually an enumeration for one object or objects class sharing similar list of display modes.
        virtual Standard_Boolean AcceptDisplayMode(const Standard_Integer theMode);

        //! Returns the default display mode.
        virtual Standard_Integer DefaultDisplayMode();

        //! Returns TRUE if any active presentation has invalidation flag.
        //! @param theToIncludeHidden when TRUE, also checks hidden presentations
        //! theToIncludeHidden = Standard_False
        Standard_Boolean ToBeUpdated(Standard_Boolean theToIncludeHidden);

        //! Flags presentation to be updated; UpdatePresentations() will recompute these presentations.
        //! @param theMode presentation (display mode) to invalidate, or -1 to invalidate them all
        void SetToUpdate(Standard_Integer theMode);

        //! flags all the Presentations to be Updated.
        void SetToUpdate();

        //! Returns true if the interactive object is infinite; FALSE by default.
        //! This flag affects various operations operating on bounding box of graphic presentations of this object.
        //! For instance, infinite objects are not taken in account for View FitAll.
        //! This does not necessarily means that object is actually infinite,
        //! auxiliary objects might be also marked with this flag to achieve desired behavior.
        Standard_Boolean IsInfinite();

        //! Sets if object should be considered as infinite.
        //! theFlag = Standard_True
        void SetInfiniteState(const Standard_Boolean theFlag);

        //! Returns information on whether the object accepts display in HLR mode or not.
        XPrsMgr_TypeOfPresentation3d TypeOfPresentation3d();

        //! Set type of presentation.
        void SetTypeOfPresentation(XPrsMgr_TypeOfPresentation3d theType);

    public: //! @name presentation attributes

      //! Returns the attributes settings.
        XPrs3d_Drawer^ Attributes();

        //! Initializes the drawing tool theDrawer.
        virtual void SetAttributes(XPrs3d_Drawer^ theDrawer);

        //! Returns the hilight attributes settings.
        //! When not NULL, overrides both Prs3d_TypeOfHighlight_LocalSelected and Prs3d_TypeOfHighlight_Selected defined within AIS_InteractiveContext.
        XPrs3d_Drawer^ HilightAttributes();

        //! Initializes the hilight drawing tool theDrawer.
        virtual void SetHilightAttributes(XPrs3d_Drawer^ theDrawer);

        //! Returns the hilight attributes settings.
        //! When not NULL, overrides both Prs3d_TypeOfHighlight_LocalDynamic and Prs3d_TypeOfHighlight_Dynamic defined within AIS_InteractiveContext.
        XPrs3d_Drawer^ DynamicHilightAttributes();

        //! Initializes the dynamic hilight drawing tool.
        virtual void SetDynamicHilightAttributes(XPrs3d_Drawer^ theDrawer);

        //! Clears settings provided by the hilight drawing tool theDrawer.
        virtual void UnsetHilightAttributes();

        //! Synchronize presentation aspects after their modification.
        //!
        //! This method should be called after modifying primitive aspect properties (material, texture, shader)
        //! so that modifications will take effect on already computed presentation groups (thus avoiding re-displaying the object).
        void SynchronizeAspects();

    public: //! @name object transformation

      //! Returns Transformation Persistence defining a special Local Coordinate system where this presentable object is located or NULL handle if not defined.
      //! Position of the object having Transformation Persistence is mutable and depends on camera position.
      //! The same applies to a bounding box of the object.
      //! @sa Graphic3d_TransformPers class description
        const Handle(Graphic3d_TransformPers)& TransformPersistence();

        //! Sets up Transform Persistence defining a special Local Coordinate system where this object should be located.
        //! Note that management of Transform Persistence object is more expensive than of the normal one,
        //! because it requires its position being recomputed basing on camera position within each draw call / traverse.
        //! @sa Graphic3d_TransformPers class description
        virtual void SetTransformPersistence(const Handle(Graphic3d_TransformPers)& theTrsfPers);

        //! Return the local transformation.
        //! Note that the local transformation of the object having Transformation Persistence
        //! is applied within Local Coordinate system defined by this Persistence.
        const Handle(TopLoc_Datum3D)& LocalTransformationGeom();

        //! Sets local transformation to theTransformation.
        //! Note that the local transformation of the object having Transformation Persistence
        //! is applied within Local Coordinate system defined by this Persistence.
        void SetLocalTransformation(xgp_Trsf^ theTrsf);

        //! Sets local transformation to theTransformation.
        //! Note that the local transformation of the object having Transformation Persistence
        //! is applied within Local Coordinate system defined by this Persistence.
        void SetLocalTransformation(const Handle(TopLoc_Datum3D)& theTrsf);

        //! Returns true if object has a transformation that is different from the identity.
        Standard_Boolean HasTransformation();

        //! Return the transformation taking into account transformation of parent object(s).
        //! Note that the local transformation of the object having Transformation Persistence
        //! is applied within Local Coordinate system defined by this Persistence.
        const Handle(TopLoc_Datum3D)& TransformationGeom();

        //! Return the local transformation.
        //! Note that the local transformation of the object having Transformation Persistence
        //! is applied within Local Coordinate system defined by this Persistence.
        const xgp_Trsf^ LocalTransformation();

        //! Return the transformation taking into account transformation of parent object(s).
        //! Note that the local transformation of the object having Transformation Persistence
        //! is applied within Local Coordinate system defined by this Persistence.
        const xgp_Trsf^ Transformation();

        //! Return inversed transformation.
        const xgp_GTrsf^ InversedTransformation();

        //! Return combined parent transformation.
        const Handle(TopLoc_Datum3D)& CombinedParentTransformation();

        //! resets local transformation to identity.
        virtual void ResetTransformation();

        //! Updates final transformation (parent + local) of presentable object and its presentations.
        virtual void UpdateTransformation();

    public: //! @name clipping planes

      //! Get clip planes.
      //! @return set of previously added clip planes for all display mode presentations.
        const Handle(Graphic3d_SequenceOfHClipPlane)& ClipPlanes();

        //! Set clip planes for graphical clipping for all display mode presentations.
        //! The composition of clip planes truncates the rendering space to convex volume.
        //! Please be aware that number of supported clip plane is limited.
        //! The planes which exceed the limit are ignored.
        //! Besides of this, some planes can be already set in view where the object is shown:
        //! the number of these planes should be subtracted from limit to predict the maximum
        //! possible number of object clipping planes.
        virtual void SetClipPlanes(const Handle(Graphic3d_SequenceOfHClipPlane)& thePlanes);

        //! Adds clip plane for graphical clipping for all display mode
        //! presentations. The composition of clip planes truncates the rendering
        //! space to convex volume. Please be aware that number of supported
        //! clip plane is limited. The planes which exceed the limit are ignored.
        //! Besides of this, some planes can be already set in view where the object
        //! is shown: the number of these planes should be subtracted from limit
        //! to predict the maximum possible number of object clipping planes.
        //! @param thePlane [in] the clip plane to be appended to map of clip planes.
        virtual void AddClipPlane(const Handle(Graphic3d_ClipPlane)& thePlane);

        //! Removes previously added clip plane.
        //! @param thePlane [in] the clip plane to be removed from map of clip planes.
        virtual void RemoveClipPlane(const Handle(Graphic3d_ClipPlane)& thePlane);

    public: //! @name parent/children properties

      //! Returns parent of current object in scene hierarchy.
        XPrsMgr_PresentableObject^ Parent();

        //! Returns children of the current object.
        const PrsMgr_ListOfPresentableObjects& Children();

        //! Makes theObject child of current object in scene hierarchy.
        virtual void AddChild(XPrsMgr_PresentableObject^ theObject);

        //! Makes theObject child of current object in scene hierarchy with keeping the current global transformation
        //! So the object keeps the same position/orientation in the global CS.
        void AddChildWithCurrentTransformation(XPrsMgr_PresentableObject^ theObject);

        //! Removes theObject from children of current object in scene hierarchy.
        virtual void RemoveChild(XPrsMgr_PresentableObject^ theObject);

        //! Removes theObject from children of current object in scene hierarchy with keeping the current global transformation.
        //! So the object keeps the same position/orientation in the global CS.
        void RemoveChildWithRestoreTransformation(XPrsMgr_PresentableObject^ theObject);

        //! Returns true if object should have own presentations.
        Standard_Boolean HasOwnPresentations();

        //! Returns bounding box of object correspondingly to its current display mode.
        //! This method requires presentation to be already computed, since it relies on bounding box of presentation structures,
        //! which are supposed to be same/close amongst different display modes of this object.
        virtual void BoundingBox(Bnd_Box& theBndBox);
    public: //! @name simplified presentation properties API

      //! Enables or disables on-triangulation build of isolines according to the flag given.
        void SetIsoOnTriangulation(const Standard_Boolean theIsEnabled);

        //! Returns the current facing model which is in effect.
        XAspect_TypeOfFacingModel CurrentFacingModel();

        //! change the current facing model apply on polygons for SetColor(), SetTransparency(), SetMaterial() methods default facing model is Aspect_TOFM_TWO_SIDE.
        //! This mean that attributes is applying both on the front and back face.
        //! theModel = Aspect_TOFM_BOTH_SIDE
        void SetCurrentFacingModel(XAspect_TypeOfFacingModel theModel);

        //! Returns true if the Interactive Object has color.
        Standard_Boolean HasColor();

        //! Returns the color setting of the Interactive Object.
        virtual void Color(XQuantity_Color^ theColor);

        //! Only the interactive object knowns which Drawer attribute is affected by the color, if any
        //! (ex: for a wire,it's the wireaspect field of the drawer, but for a vertex, only the point aspect field is affected by the color).
        //! WARNING : Do not forget to set the corresponding fields here (hasOwnColor and myDrawer->SetColor())
        virtual void SetColor(XQuantity_Color^ theColor);

        //! Removes color settings. Only the Interactive Object
        //! knows which Drawer attribute is   affected by the color
        //! setting. For a wire, for example, wire aspect is the
        //! attribute affected. For a vertex, however, only point
        //! aspect is affected by the color setting.
        virtual void UnsetColor();

        //! Returns true if the Interactive Object has width.
        Standard_Boolean HasWidth();

        //! Returns the width setting of the Interactive Object.
        Standard_Real Width();

        //! Allows you to provide the setting aValue for width.
        //! Only the Interactive Object knows which Drawer attribute is affected by the width setting.
        virtual void SetWidth(const Standard_Real theWidth);

        //! Reset width to default value.
        virtual void UnsetWidth();

        //! Returns true if the Interactive Object has a setting for material.
        Standard_Boolean HasMaterial();

        //! Returns the current material setting as enumeration value.
        virtual XGraphic3d_NameOfMaterial Material();

        //! Sets the material aMat defining this display attribute
        //! for the interactive object.
        //! Material aspect determines shading aspect, color and
        //! transparency of visible entities.
        virtual void SetMaterial(XGraphic3d_MaterialAspect^ aName);

        //! Removes the setting for material.
        virtual void UnsetMaterial();

        //! Returns true if there is a transparency setting.
        Standard_Boolean IsTransparent();

        //! Returns the transparency setting.
        //! This will be between 0.0 and 1.0.
        //! At 0.0 an object will be totally opaque, and at 1.0, fully transparent.
        virtual Standard_Real Transparency();

        //! Attributes a setting aValue for transparency.
        //! The transparency value should be between 0.0 and 1.0.
        //! At 0.0 an object will be totally opaque, and at 1.0, fully transparent.
        //! Warning At a value of 1.0, there may be nothing visible.
        //! aValue = 0.6
        virtual void SetTransparency(const Standard_Real aValue);

        //! Removes the transparency setting. The object is opaque by default.
        virtual void UnsetTransparency();

        //! Returns Standard_True if <myDrawer> has non-null shading aspect
        virtual Standard_Boolean HasPolygonOffsets();

        //! Retrieves current polygon offsets settings from <myDrawer>.
        virtual void PolygonOffsets(Standard_Integer& aMode, Standard_ShortReal& aFactor, Standard_ShortReal& aUnits);

        //! Sets up polygon offsets for this object.
        //! @sa Graphic3d_Aspects::SetPolygonOffsets()
        //! aFactor = 1.0    aUnits = 0.0
        virtual void SetPolygonOffsets(const Standard_Integer aMode, const Standard_ShortReal aFactor, const Standard_ShortReal aUnits);

        //! Clears settings provided by the drawing tool aDrawer.
        virtual void UnsetAttributes();

        //! Dumps the content of me into the stream
        //! theDepth = -1
        virtual void DumpJson(Standard_OStream& theOStream, const Standard_Integer theDepth);

    public: //! @name deprecated methods
        //! Get value of the flag "propagate visual state"
        //! It means that the display/erase/color visual state is propagated automatically to all children;
        //! by default, the flag is true 
        Standard_Boolean ToPropagateVisualState();

        //! Change the value of the flag "propagate visual state"
        void SetPropagateVisualState(const Standard_Boolean theFlag);
        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property Handle(Standard_Transient) IHandle {
            Handle(Standard_Transient) get() {// Standard_OVERRIDE {
                return NativeHandle();
            }
            void set(Handle(Standard_Transient) handle) {// Standard_OVERRIDE {
                NativeHandle() = Handle(PrsMgr_PresentableObject)::DownCast(handle);
            }
        };

    private:
        NCollection_Haft<Handle(PrsMgr_PresentableObject)> NativeHandle;
    };

   //! DEFINE_STANDARD_HANDLE(PrsMgr_PresentableObject, Standard_Transient)
}
#endif // _XPrsMgr_PresentableObject_HeaderFile
