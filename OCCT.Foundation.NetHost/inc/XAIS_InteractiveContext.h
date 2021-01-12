// Created on: 1996-12-18
// Created by: Robert COUBLANC
// Copyright (c) 1996-1999 Matra Datavision
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

#ifndef _XAIS_InteractiveContext_HeaderFile
#define _XAIS_InteractiveContext_HeaderFile
#pragma once
#include <AIS_InteractiveContext.hxx>
#include "xgp_Pnt.h"
#include "XTopLoc_Location.h"
#include "NCollection_Haft.h"
#include "XAIS_InteractiveObject.h"

#include <AIS_DataMapOfIOStatus.hxx>
#include <AIS_DisplayMode.hxx>
#include <AIS_DisplayStatus.hxx>
#include <AIS_ClearMode.hxx>
#include <AIS_KindOfInteractive.hxx>
#include <AIS_ListOfInteractive.hxx>
#include <AIS_Selection.hxx>
#include <AIS_SelectionModesConcurrency.hxx>
#include <AIS_StatusOfDetection.hxx>
#include <AIS_StatusOfPick.hxx>
#include <AIS_TypeOfIso.hxx>
#include <Aspect_TypeOfFacingModel.hxx>
#include <Prs3d_Drawer.hxx>
#include <Prs3d_TypeOfHighlight.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <SelectMgr_IndexedMapOfOwner.hxx>
#include <SelectMgr_ListOfFilter.hxx>
#include <SelectMgr_PickingStrategy.hxx>
#include <Standard.hxx>
#include <Standard_Type.hxx>
#include <StdSelect_ViewerSelector3d.hxx>
#include <TCollection_AsciiString.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <Quantity_Color.hxx>
#include <TopoDS_Shape.hxx>
class SelectMgr_SelectionManager;
class V3d_Viewer;
class SelectMgr_OrFilter;
class V3d_View;
class TopLoc_Location;
class TCollection_ExtendedString;
class Prs3d_LineAspect;
class Prs3d_BasicAspect;
class TopoDS_Shape;
class SelectMgr_EntityOwner;
class SelectMgr_Filter;
using namespace TKMath;
//! The Interactive Context allows you to manage graphic behavior and selection of Interactive Objects in one or more viewers.
//! Class methods make this highly transparent.
//! It is essential to remember that an Interactive Object which is already known by the Interactive Context must be modified using Context methods.
//! You can only directly call the methods available for an Interactive Object if it has not been loaded into an Interactive Context.
//!
//! Each selectable object must specify the selection mode that is
//! responsible for selection of object as a whole (global selection mode).
//! Interactive context itself supports decomposed object selection with selection filters support.
//! By default, global selection mode is equal to 0, but it might be redefined if needed.
namespace TKV3d
{
    ref class TKMath::xgp_Pnt;
    ref class TKMath::XTopLoc_Location;
    ref class XAIS_InteractiveObject;
    public ref class XAIS_InteractiveContext// : public Standard_Transient
    {
    public: //! @name object display management

        //! Constructs the interactive context object defined by the principal viewer MainViewer.
        XAIS_InteractiveContext(Handle(V3d_Viewer) MainViewer);


        //! Constructs the interactive context object defined by the principal viewer MainViewer.
        XAIS_InteractiveContext(Handle(AIS_InteractiveContext) pos);

        virtual Handle(AIS_InteractiveContext)  GetInteractiveContext();

        //! Destructor.
        virtual ~XAIS_InteractiveContext();

        //! Returns the display status of the entity anIobj.
        //! This will be one of the following:
        //! - AIS_DS_Displayed displayed in main viewer
        //! - AIS_DS_Erased    hidden in main viewer
        //! - AIS_DS_Temporary temporarily displayed
        //! - AIS_DS_None      nowhere displayed.
        AIS_DisplayStatus DisplayStatus(Handle(AIS_InteractiveObject) anIobj);

        //! Returns the status of the Interactive Context for the view of the Interactive Object.
        void Status(Handle(AIS_InteractiveObject) anObj, TCollection_ExtendedString astatus);

        //! Returns true if Object is displayed in the interactive context.
        Standard_Boolean IsDisplayed(Handle(AIS_InteractiveObject) anIobj);

        Standard_Boolean IsDisplayed(Handle(AIS_InteractiveObject) aniobj, Standard_Integer aMode);

        //! Enable or disable automatic activation of default selection mode while displaying the object.
        void SetAutoActivateSelection(Standard_Boolean theIsAuto);

        //! Manages displaying the new object should also automatically activate default selection mode; TRUE by default.
        Standard_Boolean GetAutoActivateSelection();

        //! Displays the object in this Context using default Display Mode.
        //! This will be the object's default display mode, if there is one. Otherwise, it will be the context mode.
        //! The Interactive Object's default selection mode is activated if GetAutoActivateSelection() is TRUE. In general, this is 0.
        void Display(Handle(AIS_InteractiveObject) theIObj, Standard_Boolean theToUpdateViewer);

        //! Displays the object in this Context using default Display Mode.
        //! This will be the object's default display mode, if there is one. Otherwise, it will be the context mode.
        //! The Interactive Object's default selection mode is activated if GetAutoActivateSelection() is TRUE. In general, this is 0.
        void Display(XAIS_InteractiveObject^ theIObj, Standard_Boolean theToUpdateViewer);

        //! Sets status, display mode and selection mode for specified Object
        //! If theSelectionMode equals -1, theIObj will not be activated: it will be displayed but will not be selectable.
        void Display(Handle(AIS_InteractiveObject) theIObj, Standard_Integer theDispMode, Standard_Integer theSelectionMode, Standard_Boolean theToUpdateViewer, AIS_DisplayStatus theDispStatus);

        //! Sets status, display mode and selection mode for specified Object
        //! If theSelectionMode equals -1, theIObj will not be activated: it will be displayed but will not be selectable.
        //! AIS_DisplayStatus theDispStatus
        void Display(XAIS_InteractiveObject^ theIObj, Standard_Integer theDispMode, Standard_Integer theSelectionMode, Standard_Boolean theToUpdateViewer, Standard_Integer theDispStatus);

        //! Allows you to load the Interactive Object with a given selection mode,
        //! and/or with the desired decomposition option, whether the object is visualized or not.
        //! The loaded objects will be selectable but displayable in highlighting only when detected by the Selector.
        void Load(Handle(AIS_InteractiveObject) theObj, Standard_Integer theSelectionMode);

        //! Allows you to load the Interactive Object with a given selection mode,
        //! and/or with the desired decomposition option, whether the object is visualized or not.
        //! The loaded objects will be selectable but displayable in highlighting only when detected by the Selector.
        void Load(XAIS_InteractiveObject^ theObj, Standard_Integer theSelectionMode);

        void Display(Handle(AIS_InteractiveObject) theIObj, Standard_Integer theDispMode,  Standard_Integer theSelectionMode, Standard_Boolean theToUpdateViewer, Standard_Boolean theToAllowDecomposition, AIS_DisplayStatus theDispStatus) {
            (void)theToAllowDecomposition;
            Display(theIObj, theDispMode, theSelectionMode, theToUpdateViewer, theDispStatus);
        }

        //! AIS_DisplayStatus   theDispStatus
        void Display(XAIS_InteractiveObject^ theIObj, Standard_Integer theDispMode, Standard_Integer theSelectionMode, Standard_Boolean theToUpdateViewer, Standard_Boolean theToAllowDecomposition, Standard_Integer theDispStatus);

        void Load(Handle(AIS_InteractiveObject) theObj, Standard_Integer theSelectionMode, Standard_Boolean) { Load(theObj, theSelectionMode); }

        void Load(XAIS_InteractiveObject^ theObj, Standard_Integer theSelectionMode, Standard_Boolean);
        //! Hides the object. The object's presentations are simply flagged as invisible and therefore excluded from redrawing.
        //! To show hidden objects, use Display().
        void Erase(Handle(AIS_InteractiveObject) theIObj, Standard_Boolean theToUpdateViewer);

        //! Hides the object. The object's presentations are simply flagged as invisible and therefore excluded from redrawing.
        //! To show hidden objects, use Display().
        void Erase(XAIS_InteractiveObject^ theIObj, Standard_Boolean theToUpdateViewer);

        //! Hides all objects. The object's presentations are simply flagged as invisible and therefore excluded from redrawing.
        //! To show all hidden objects, use DisplayAll().
        void EraseAll(Standard_Boolean theToUpdateViewer);

        //! Displays all hidden objects.
        void DisplayAll(Standard_Boolean theToUpdateViewer);

        //! Hides selected objects. The object's presentations are simply flagged as invisible and therefore excluded from redrawing.
        //! To show hidden objects, use Display().
        void EraseSelected(Standard_Boolean theToUpdateViewer);

        //! Displays current objects.
        void DisplaySelected(Standard_Boolean theToUpdateViewer);

        //! Empties the graphic presentation of the mode indexed by aMode.
        //! Warning! Removes theIObj. theIObj is still active if it was previously activated.
        void ClearPrs(Handle(AIS_InteractiveObject) theIObj, Standard_Integer theMode, Standard_Boolean theToUpdateViewer);


        //! Empties the graphic presentation of the mode indexed by aMode.
        //! Warning! Removes theIObj. theIObj is still active if it was previously activated.
        void ClearPrs(XAIS_InteractiveObject^ theIObj, Standard_Integer theMode, Standard_Boolean theToUpdateViewer);

        //! Removes Object from every viewer.
        void Remove(Handle(AIS_InteractiveObject) theIObj, Standard_Boolean theToUpdateViewer);

        //! Removes Object from every viewer.
        void Remove(XAIS_InteractiveObject^ theIObj, Standard_Boolean theToUpdateViewer);

        //! Removes all the objects from Context.
        void RemoveAll(Standard_Boolean theToUpdateViewer);

        //! Recomputes the seen parts presentation of the Object.
        //! If theAllModes equals true, all presentations are present in the object even if unseen.
        void Redisplay(Handle(AIS_InteractiveObject) theIObj, Standard_Boolean theToUpdateViewer, Standard_Boolean theAllModes);

        //! Recomputes the seen parts presentation of the Object.
        //! If theAllModes equals true, all presentations are present in the object even if unseen.
        void Redisplay(XAIS_InteractiveObject^ theIObj, Standard_Boolean theToUpdateViewer, Standard_Boolean theAllModes);

        //! Recomputes the Prs/Selection of displayed objects of a given type and a given signature.
        //! if signature = -1  doesn't take signature criterion.
        void Redisplay(AIS_KindOfInteractive theTypeOfObject, Standard_Integer theSignature, Standard_Boolean theToUpdateViewer);

        //! Recomputes the displayed presentations, flags the others.
        //! Doesn't update presentations.
        void RecomputePrsOnly(Handle(AIS_InteractiveObject) theIObj, Standard_Boolean theToUpdateViewer, Standard_Boolean theAllModes);

        //! Recomputes the displayed presentations, flags the others.
        //! Doesn't update presentations.
        void RecomputePrsOnly(XAIS_InteractiveObject^ theIObj, Standard_Boolean theToUpdateViewer, Standard_Boolean theAllModes);

        //! Recomputes the active selections, flags the others.
        //! Doesn't update presentations.
        void RecomputeSelectionOnly(Handle(AIS_InteractiveObject) anIObj);

        //! Recomputes the active selections, flags the others.
        //! Doesn't update presentations.
        void RecomputeSelectionOnly(XAIS_InteractiveObject^ anIObj);

        //! Updates displayed interactive object by checking and recomputing its flagged as "to be recomputed" presentation and selection structures.
        //! This method does not force any recomputation on its own.
        //! The method recomputes selections even if they are loaded without activation in particular selector.
        void Update(Handle(AIS_InteractiveObject) theIObj, Standard_Boolean theUpdateViewer);

        //! Updates displayed interactive object by checking and recomputing its flagged as "to be recomputed" presentation and selection structures.
        //! This method does not force any recomputation on its own.
        //! The method recomputes selections even if they are loaded without activation in particular selector.
        void Update(XAIS_InteractiveObject^ theIObj, Standard_Boolean theUpdateViewer);

    public: //! @name highlighting management

      //! Returns highlight style settings.   enum:Prs3d_TypeOfHighlight
        Handle(Prs3d_Drawer) HighlightStyle(Prs3d_TypeOfHighlight theStyleType);

        //! Setup highlight style settings.
        //! It is preferred modifying existing style returned by method HighlightStyle()
        //! instead of creating a new drawer.
        //!
        //! If a new highlight style is created, its presentation Zlayer should be checked,
        //! otherwise highlighting might not work as expected.
        //! Default values are:
        //!  - Prs3d_TypeOfHighlight_Dynamic:      Graphic3d_ZLayerId_Top,
        //!    object highlighting is drawn on top of main scene within Immediate Layers,
        //!    so that V3d_View::RedrawImmediate() will be enough to see update;
        //!  - Prs3d_TypeOfHighlight_LocalDynamic: Graphic3d_ZLayerId_Topmost,
        //!    object parts highlighting is drawn on top of main scene within Immediate Layers
        //!    with depth cleared (even overlapped geometry will be revealed);
        //!  - Prs3d_TypeOfHighlight_Selected:     Graphic3d_ZLayerId_UNKNOWN,
        //!    object highlighting is drawn on top of main scene within the same layer
        //!    as object itself (e.g. Graphic3d_ZLayerId_Default by default) and increased priority.
        //! enum:Prs3d_TypeOfHighlight
        void SetHighlightStyle(Prs3d_TypeOfHighlight theStyleType, Handle(Prs3d_Drawer) theStyle);

        //! Returns current dynamic highlight style settings.
        //! By default:
        //!   - the color of dynamic highlight is Quantity_NOC_CYAN1;
        //!   - the presentation for dynamic highlight is completely opaque;
        //!   - the type of highlight is Aspect_TOHM_COLOR.
        Handle(Prs3d_Drawer) HighlightStyle();

        //! Setup the style of dynamic highlighting.
        //! It is preferred modifying existing style returned by method HighlightStyle()
        //! instead of creating a new drawer.
        //!
        //! If a new highlight style is created, its presentation Zlayer should be checked,
        //! otherwise highlighting might not work as expected.
        //! Default value is Graphic3d_ZLayerId_Top,
        //! object highlighting is drawn on top of main scene within Immediate Layers,
        //! so that V3d_View::RedrawImmediate() will be enough to see update;
        void SetHighlightStyle(Handle(Prs3d_Drawer) theStyle);

        //! Returns current selection style settings.
        //! By default:
        //!   - the color of selection is Quantity_NOC_GRAY80;
        //!   - the presentation for selection is completely opaque;
        //!   - the type of highlight is Aspect_TOHM_COLOR.
        Handle(Prs3d_Drawer) SelectionStyle();

        //! Setup the style of selection highlighting.
        void SetSelectionStyle(Handle(Prs3d_Drawer) theStyle);

        //! Returns highlight style of the object if it is marked as highlighted via global status
        //! @param theObj [in] the object to check
        Standard_Boolean HighlightStyle(Handle(AIS_InteractiveObject) theObj, Handle(Prs3d_Drawer) theStyle);

        //! Returns highlight style of the owner if it is selected
        //! @param theOwner [in] the owner to check
        Standard_Boolean HighlightStyle(Handle(SelectMgr_EntityOwner) theOwner, Handle(Prs3d_Drawer) theStyle);

        //! Returns true if the object is marked as highlighted via its global status
        //! @param theObj [in] the object to check
        Standard_Boolean IsHilighted(Handle(AIS_InteractiveObject) theObj);

        //! Returns true if the owner is marked as selected
        //! @param theOwner [in] the owner to check
        Standard_Boolean IsHilighted(Handle(SelectMgr_EntityOwner) theOwner);

        //! Updates the display in the viewer to take dynamic detection into account.
        //! On dynamic detection by the mouse cursor, sensitive primitives are highlighted.
        //! The highlight color of entities detected by mouse movement is white by default.
        //void Hilight(Handle(AIS_InteractiveObject) theObj, Standard_Boolean theIsToUpdateViewer);

        //! Changes the color of all the lines of the object in view.
        void HilightWithColor(Handle(AIS_InteractiveObject) theObj, Handle(Prs3d_Drawer) theStyle, Standard_Boolean theToUpdateViewer);

        //! Removes hilighting from the Object.
        void Unhilight(Handle(AIS_InteractiveObject) theIObj, Standard_Boolean theToUpdateViewer);

    public: //! @name object presence management (View affinity, Layer, Priority)

      //! Returns the display priority of the Object.
        Standard_Integer DisplayPriority(Handle(AIS_InteractiveObject) theIObj);

        //! Sets the display priority of the seen parts presentation of the Object.
        void SetDisplayPriority(Handle(AIS_InteractiveObject) theIObj, Standard_Integer thePriority);

        //! Get Z layer id set for displayed interactive object.
        Graphic3d_ZLayerId GetZLayer(Handle(AIS_InteractiveObject) theIObj);

        //! Set Z layer id for interactive object.
        //! The Z layers can be used to display temporarily presentations of some object in front of the other objects in the scene.
        //! The ids for Z layers are generated by V3d_Viewer.
        void SetZLayer(Handle(AIS_InteractiveObject) theIObj, Graphic3d_ZLayerId theLayerId);

        //! Setup object visibility in specified view.
        //! Has no effect if object is not displayed in this context.
        void SetViewAffinity(Handle(AIS_InteractiveObject) theIObj, Handle(V3d_View) theView, Standard_Boolean theIsVisible);

    public: //! @name Display Mode management

        //! Returns the Display Mode setting to be used by default.
        Standard_Integer DisplayMode();

        //! Sets the display mode of seen Interactive Objects (which have no overridden Display Mode).
        void SetDisplayMode(Standard_Integer theMode, Standard_Boolean theToUpdateViewer);

        //! Sets the display mode of seen Interactive Objects.
        //! theMode provides the display mode index of the entity theIObj.
        void SetDisplayMode(Handle(AIS_InteractiveObject) theIObj, Standard_Integer theMode, Standard_Boolean theToUpdateViewer);

        //! Unsets the display mode of seen Interactive Objects.
        void UnsetDisplayMode(Handle(AIS_InteractiveObject) theIObj, Standard_Boolean theToUpdateViewer);

    public: //! @name object local transformation management

      //! Puts the location on the initial graphic representation and the selection for the Object.
        void SetLocation(Handle(AIS_InteractiveObject) theObject, XTopLoc_Location^ theLocation);

        //! Puts the Object back into its initial position.
        void ResetLocation(Handle(AIS_InteractiveObject) theObject);

        //! Returns true if the Object has a location.
        Standard_Boolean HasLocation(Handle(AIS_InteractiveObject) theObject);

        //! Returns the location of the Object.
        XTopLoc_Location^ Location(Handle(AIS_InteractiveObject) theObject);

        //! Sets transform persistence.
        void SetTransformPersistence(Handle(AIS_InteractiveObject) theObject, Handle(Graphic3d_TransformPers) theTrsfPers);

        
        void SetTransformPersistence(Handle(AIS_InteractiveObject) theObj, Graphic3d_TransModeFlags theFlag, xgp_Pnt^ thePoint) {
            SetTransformPersistence(theObj, Graphic3d_TransformPers::FromDeprecatedParams(theFlag, *thePoint->GetPnt()));
        }

    public: //! @name mouse picking logic (detection and dynamic highlighting of entities under cursor)

      //! Setup pixel tolerance for MoveTo() operation.
      //! @sa MoveTo().
        void SetPixelTolerance(Standard_Integer thePrecision);

        //! Returns the pixel tolerance, default is 2.
        //! Pixel Tolerance extends sensitivity within MoveTo() operation (picking by point)
        //! and can be adjusted by application based on user input precision (e.g. screen pixel density, input device precision, etc.).
        Standard_Integer PixelTolerance();

        //! Allows to manage sensitivity of a particular selection of interactive object theObject
        //! and changes previous sensitivity value of all sensitive entities in selection with theMode
        //! to the given theNewSensitivity.
        void SetSelectionSensitivity(Handle(AIS_InteractiveObject) theObject, Standard_Integer theMode, Standard_Integer theNewSensitivity);

        //! Returns last active View (argument of MoveTo()/Select() methods).
        Handle(V3d_View) LastActiveView();

        //! Relays mouse position in pixels theXPix and theYPix to the interactive context selectors.
        //! This is done by the view theView passing this position to the main viewer and updating it.
        //! If theToRedrawOnUpdate is set to false, callee should call RedrawImmediate() to highlight detected object.
        //! @sa PickingStrategy()
        AIS_StatusOfDetection MoveTo(Standard_Integer theXPix, Standard_Integer theYPix, Handle(V3d_View) theView, Standard_Boolean theToRedrawOnUpdate);

        //! Clears the list of entities detected by MoveTo() and resets dynamic highlighting.
        //! @param theToRedrawImmediate if TRUE, the main Viewer will be redrawn on update
        //! @return TRUE if viewer needs to be updated (e.g. there were actually dynamically highlighted entities)
        Standard_Boolean ClearDetected(Standard_Boolean theToRedrawImmediate);

        //! Returns true if there is a mouse-detected entity in context.
        //! @sa DetectedOwner()/HasNextDetected()/HilightPreviousDetected()/HilightNextDetected().
        Standard_Boolean HasDetected();

        //! Returns the owner of the detected sensitive primitive which is currently dynamically highlighted.
        //! WARNING! This method is irrelevant to InitDetected()/MoreDetected()/NextDetected().
        //! @sa HasDetected()/HasNextDetected()/HilightPreviousDetected()/HilightNextDetected().
        Handle(SelectMgr_EntityOwner) DetectedOwner();

        //! Returns the interactive objects last detected in context.
        //! In general this is just a wrapper for Handle(AIS_InteractiveObject)::DownCast(DetectedOwner()->Selectable()).
        //! @sa DetectedOwner()
        Handle(AIS_InteractiveObject) DetectedInteractive();

        //! Returns true if there is a detected shape in local context.
        //! @sa HasDetected()/DetectedShape()
        //! Standard_Boolean HasDetectedShape();

        //! Returns the shape detected in local context.
        //! @sa DetectedOwner()
        //! TopoDS_Shape DetectedShape();

        //! returns True if other entities were detected in the last mouse detection
        //! @sa HilightPreviousDetected()/HilightNextDetected().
        Standard_Boolean HasNextDetected();

        //! If more than 1 object is detected by the selector, only the "best" owner is hilighted at the mouse position.
        //! This Method allows the user to hilight one after another the other detected entities.
        //! If The method select is called, the selected entity will be the hilighted one!
        //! WARNING: Loop Method. When all the detected entities have been hilighted, the next call will hilight the first one again.
        //! @return the Rank of hilighted entity
        //! @sa HasNextDetected()/HilightPreviousDetected().
        Standard_Integer HilightNextDetected(Handle(V3d_View) theView, Standard_Boolean theToRedrawImmediate);

        //! Same as previous methods in reverse direction.
        //! @sa HasNextDetected()/HilightNextDetected().
        Standard_Integer HilightPreviousDetected(Handle(V3d_View) theView, Standard_Boolean theToRedrawImmediate);

    public: //! @name iteration through detected entities

          //! Initialization for iteration through mouse-detected objects in
          //! interactive context or in local context if it is opened.
          //! @sa DetectedCurrentOwner()/MoreDetected()/NextDetected().
        void InitDetected();

        //! Return TRUE if there is more mouse-detected objects after the current one
        //! during iteration through mouse-detected interactive objects.
        //! @sa DetectedCurrentOwner()/InitDetected()/NextDetected().
        Standard_Boolean MoreDetected();

        //! Gets next current object during iteration through mouse-detected interactive objects.
        //! @sa DetectedCurrentOwner()/InitDetected()/MoreDetected().
        void NextDetected();

        //! Returns the owner from detected list pointed by current iterator position.
        //! WARNING! This method is irrelevant to DetectedOwner() which returns last picked Owner regardless of iterator position!
        //! @sa InitDetected()/MoreDetected()/NextDetected().
        Handle(SelectMgr_EntityOwner) DetectedCurrentOwner();

    public: //! @name Selection management

        //! Sets the graphic basic aspect to the current presentation of ALL selected objects.
        //void SetSelectedAspect(Handle(Prs3d_BasicAspect) theAspect,  Standard_Boolean theToUpdateViewer);

        //! Adds object in the selection.
        AIS_StatusOfPick AddSelect(Handle(SelectMgr_EntityOwner) theObject);

        //! Adds object in the selection.
        AIS_StatusOfPick AddSelect(Handle(AIS_InteractiveObject) theObject) {
            return AddSelect(theObject->GlobalSelOwner());
        }

        //! Selects everything found in the bounding rectangle defined by the pixel minima and maxima, XPMin, YPMin, XPMax, and YPMax in the view.
        //! The objects detected are passed to the main viewer, which is then updated.
        AIS_StatusOfPick Select(Standard_Integer theXPMin, Standard_Integer theYPMin, Standard_Integer theXPMax, Standard_Integer theYPMax, Handle(V3d_View) theView, Standard_Boolean theToUpdateViewer);

        //! polyline selection; clears the previous picked list
        AIS_StatusOfPick Select(TColgp_Array1OfPnt2d thePolyline, Handle(V3d_View) theView, Standard_Boolean theToUpdateViewer);

        //! Stores and hilights the previous detected; Unhilights the previous picked.
        //! @sa MoveTo().
        AIS_StatusOfPick Select(Standard_Boolean theToUpdateViewer);

        //! Adds the last detected to the list of previous picked.
        //! If the last detected was already declared as picked, removes it from the Picked List.
        //! @sa MoveTo().
        AIS_StatusOfPick ShiftSelect(Standard_Boolean theToUpdateViewer);

        //! Adds the last detected to the list of previous picked.
        //! If the last detected was already declared as picked, removes it from the Picked List.
        AIS_StatusOfPick ShiftSelect(TColgp_Array1OfPnt2d thePolyline, Handle(V3d_View) theView, Standard_Boolean theToUpdateViewer);

        //! Rectangle of selection; adds new detected entities into the picked list,
        //! removes the detected entities that were already stored.
        AIS_StatusOfPick ShiftSelect(Standard_Integer theXPMin, Standard_Integer theYPMin, Standard_Integer theXPMax, Standard_Integer theYPMax, Handle(V3d_View) theView, Standard_Boolean theToUpdateViewer);

        //! Returns bounding box of selected objects.
        Bnd_Box BoundingBoxOfSelection();

        //! Fits the view correspondingly to the bounds of selected objects.
        //! Infinite objects are ignored if infinite state of AIS_InteractiveObject is set to true.
        void FitSelected(Handle(V3d_View) theView, Standard_Real theMargin, Standard_Boolean theToUpdate);

        //! Fits the view correspondingly to the bounds of selected objects.
        //! Infinite objects are ignored if infinite state of AIS_InteractiveObject is set to true.
        void FitSelected(Handle(V3d_View) theView);

        //! Return value specified whether selected object must be hilighted when mouse cursor is moved above it
        //! @sa MoveTo()
        Standard_Boolean ToHilightSelected();

        //! Specify whether selected object must be hilighted when mouse cursor is moved above it (in MoveTo method).
        //! By default this value is false and selected object is not hilighted in this case.
        //! @sa MoveTo()
        void SetToHilightSelected(Standard_Boolean toHilight);

        //! Returns true if the automatic highlight mode is active; TRUE by default.
        //! @sa MoveTo(), Select(), HilightWithColor(), Unhilight()
        Standard_Boolean AutomaticHilight();

        //! Sets the highlighting status of detected and selected entities.
        //! This function allows you to disconnect the automatic mode.
        //!
        //! MoveTo() will fill the list of detected entities
        //! and Select() will set selected state to detected objects regardless of this flag,
        //! but with disabled AutomaticHiligh() their highlighting state will be left unaffected,
        //! so that application will be able performing custom highlighting in a different way, if needed.
        //!
        //! This API should be distinguished from SelectMgr_SelectableObject::SetAutoHilight()
        //! that is used to implement custom highlighting logic for a specific interactive object class.
        //!
        //! @sa MoveTo(), Select(), HilightWithColor(), Unhilight()
        void SetAutomaticHilight(Standard_Boolean theStatus);

        //! Unhighlights previously selected owners and marks them as not selected.
        //! Marks owner given as selected and highlights it.
        //! Performs selection filters check.
        void SetSelected(Handle(SelectMgr_EntityOwner) theOwners, Standard_Boolean theToUpdateViewer);

        //! Puts the interactive object aniObj in the list of selected objects.
        //! Performs selection filters check.
        void SetSelected(Handle(AIS_InteractiveObject) theObject, Standard_Boolean theToUpdateViewer);

        //! Allows to highlight or unhighlight the owner given depending on its selection status
        void AddOrRemoveSelected(Handle(AIS_InteractiveObject) theObject, Standard_Boolean theToUpdateViewer);

        //! Updates Selected state of specified owner without calling HilightSelected().
        //! Has no effect if Selected state is not changed, and redirects to AddOrRemoveSelected() otherwise.
        //! @param theOwner owner object to set selected state
        //! @param theIsSelected new selected state
        //! @return TRUE if Selected state has been changed
        Standard_Boolean SetSelectedState(Handle(SelectMgr_EntityOwner) theOwner, Standard_Boolean theIsSelected);

        //! Highlights selected objects.
        void HilightSelected(Standard_Boolean theToUpdateViewer);

        //! Removes highlighting from selected objects.
        void UnhilightSelected(Standard_Boolean theToUpdateViewer);

        //! Updates the list of selected objects:
        //! i.e. highlights the newly selected ones and unhighlights previously selected objects.
        //! @sa HilightSelected().
        void UpdateSelected(Standard_Boolean theToUpdateViewer) { HilightSelected(theToUpdateViewer); }

        //! Empties previous selected objects in order to get the selected objects detected by the selector using UpdateSelected.
        void ClearSelected(Standard_Boolean theToUpdateViewer);

        //! Allows to highlight or unhighlight the owner given depending on its selection status
        void AddOrRemoveSelected(Handle(SelectMgr_EntityOwner) theOwner, Standard_Boolean theToUpdateViewer);

        //! Returns true is the owner given is selected
        Standard_Boolean IsSelected(Handle(SelectMgr_EntityOwner) theOwner) { return !theOwner.IsNull() && theOwner->IsSelected(); }

        //! Returns true is the object given is selected
        Standard_Boolean IsSelected(Handle(AIS_InteractiveObject) theObj);

        //! Returns the first selected object in the list of current selected.
        Handle(AIS_InteractiveObject) FirstSelectedObject();

        //! Count a number of selected entities using InitSelected()+MoreSelected()+NextSelected() iterator.
        //! @sa SelectedOwner()/InitSelected()/MoreSelected()/NextSelected().
        Standard_Integer NbSelected();

        //! Initializes a scan of the selected objects.
        //! @sa SelectedOwner()/MoreSelected()/NextSelected().
        void InitSelected();

        //! Returns true if there is another object found by the scan of the list of selected objects.
        //! @sa SelectedOwner()/InitSelected()/NextSelected().
        Standard_Boolean MoreSelected();

        //! Continues the scan to the next object in the list of selected objects.
        //! @sa SelectedOwner()/InitSelected()/MoreSelected().
        void NextSelected();

        //! Returns the owner of the selected entity.
        //! @sa InitSelected()/MoreSelected()/NextSelected().
        Handle(SelectMgr_EntityOwner) SelectedOwner();

        //! Return Handle(AIS_InteractiveObject)::DownCast (SelectedOwner()->Selectable()).
        //! @sa SelectedOwner().
        Handle(AIS_InteractiveObject) SelectedInteractive();

        //! Returns TRUE if the interactive context has a shape selected.
        //! @sa SelectedShape().
        Standard_Boolean HasSelectedShape();

        //! Returns the selected shape.
        //! Basically it is just a shape returned stored by StdSelect_BRepOwner with graphic transformation being applied:
        //! @code
        //!   Handle(StdSelect_BRepOwner) aBRepOwner = Handle(StdSelect_BRepOwner)::DownCast (SelectedOwner());
        //!   TopoDS_Shape aSelShape     = aBRepOwner->Shape();
        //!   TopoDS_Shape aLocatedShape = aSelShape.Located (aBRepOwner->Location() * aSelShape.Location());
        //! @endcode
        //! @sa SelectedOwner()/HasSelectedShape().
        TopoDS_Shape SelectedShape();

        //! Returns SelectedInteractive()->HasOwner().
        //! @sa SelectedOwner().
        Standard_Boolean HasApplicative() { return SelectedInteractive()->HasOwner(); }

        //! Returns SelectedInteractive()->GetOwner().
        //! @sa SelectedOwner().
        Handle(Standard_Transient) Applicative() { return SelectedInteractive()->GetOwner(); }

    public: //! @name immediate mode rendering

      //! initializes the list of presentations to be displayed
      //! returns False if no local context is opened.
        Standard_Boolean BeginImmediateDraw();

        //! returns True if <anIObj> has been stored in the list.
        Standard_Boolean ImmediateAdd(Handle(AIS_InteractiveObject) theObj, Standard_Integer theMode);

        //! returns True if the immediate display has been done.
        Standard_Boolean EndImmediateDraw(Handle(V3d_View) theView);

        //! Uses the First Active View of Main Viewer!
        //! returns True if the immediate display has been done.
        Standard_Boolean EndImmediateDraw();

        Standard_Boolean IsImmediateModeOn();

        //! Redraws immediate structures in all views of the viewer given taking into account its visibility.
        void RedrawImmediate(Handle(V3d_Viewer) theViewer);

    public: //! @name management of active Selection Modes

          //! Activates or deactivates the selection mode for specified object.
          //! Has no effect if selection mode was already active/deactivated.
          //! @param theObj         object to activate/deactivate selection mode
          //! @param theMode        selection mode to activate/deactivate;
          //!                       deactivation of -1 selection mode will effectively deactivate all selection modes;
          //!                       activation of -1 selection mode with AIS_SelectionModesConcurrency_Single
          //!                       will deactivate all selection modes, and will has no effect otherwise
          //! @param theToActivate  activation/deactivation flag
          //! @param theConcurrency specifies how to handle already activated selection modes;
          //!                       default value (AIS_SelectionModesConcurrency_Multiple) means active selection modes should be left as is,
          //!                       AIS_SelectionModesConcurrency_Single can be used if only one selection mode is expected to be active
          //!                       and AIS_SelectionModesConcurrency_GlobalOrLocal can be used if either AIS_InteractiveObject::GlobalSelectionMode()
          //!                       or any combination of Local selection modes is acceptable;
          //!                       this value is considered only if theToActivate set to TRUE
          //! @param theIsForce     when set to TRUE, the display status will be ignored while activating selection mode
        void SetSelectionModeActive(Handle(AIS_InteractiveObject) theObj,  Standard_Integer theMode,  Standard_Boolean theToActivate, AIS_SelectionModesConcurrency theConcurrency, Standard_Boolean theIsForce);

        //! Activates the selection mode aMode whose index is given, for the given interactive entity anIobj.
        void Activate(Handle(AIS_InteractiveObject)& theObj, Standard_Integer theMode, Standard_Boolean theIsForce) {
            SetSelectionModeActive(theObj, theMode, Standard_True, AIS_SelectionModesConcurrency_GlobalOrLocal, theIsForce);
        }

        //! Activates the given selection mode for the all displayed objects.
        void Activate(Standard_Integer theMode, Standard_Boolean theIsForce);

        //! Deactivates all the activated selection modes of an object.
        void Deactivate(Handle(AIS_InteractiveObject) theObj);

        //! Deactivates all the activated selection modes of the interactive object anIobj with a given selection mode aMode.
        void Deactivate(Handle(AIS_InteractiveObject) theObj, Standard_Integer theMode);

        //! Deactivates the given selection mode for all displayed objects.
        void Deactivate(Standard_Integer theMode);

        //! Deactivates all the activated selection mode at all displayed objects.
        void Deactivate();

        //! Returns the list of activated selection modes.
        void ActivatedModes(Handle(AIS_InteractiveObject) anIobj, TColStd_ListOfInteger theList);

        //! Returns a collection containing all entity owners created for the interactive object in specified selection mode (in all active modes if the Mode == -1)
        void EntityOwners(Handle(SelectMgr_IndexedMapOfOwner) theOwners, Handle(AIS_InteractiveObject) theIObj, Standard_Integer theMode);

    public: //! @name Selection Filters management

      //! Returns the list of filters active in a local context.
        SelectMgr_ListOfFilter Filters();

        //! Allows you to add the filter.
        void AddFilter(Handle(SelectMgr_Filter) theFilter);

        //! Removes a filter from context.
        void RemoveFilter(Handle(SelectMgr_Filter) theFilter);

        //! Remove all filters from context.
        void RemoveFilters();

        //! Return picking strategy; SelectMgr_PickingStrategy_FirstAcceptable by default.
        //! @sa MoveTo()/Filters()
        SelectMgr_PickingStrategy PickingStrategy();

        //! Setup picking strategy - which entities detected by picking line will be accepted, considering Selection Filters.
        //! By default (SelectMgr_PickingStrategy_FirstAcceptable), Selection Filters reduce the list of entities
        //! so that the context accepts topmost in remaining.
        //!
        //! This means that entities behind non-selectable (by filters) parts can be picked by user.
        //! If this behavior is undesirable, and user wants that non-selectable (by filters) parts
        //! should remain an obstacle for picking, SelectMgr_PickingStrategy_OnlyTopmost can be set instead.
        //!
        //! Notice, that since Selection Manager operates only objects registered in it,
        //! SelectMgr_PickingStrategy_OnlyTopmost will NOT prevent picking entities behind
        //! visible by unregistered in Selection Manager presentations (e.g. deactivated).
        //! Hence, SelectMgr_PickingStrategy_OnlyTopmost changes behavior only with Selection Filters enabled.
        void SetPickingStrategy(SelectMgr_PickingStrategy theStrategy);

    public: //! @name common properties

        //! Returns the default attribute manager.
        //! This contains all the color and line attributes which can be used by interactive objects which do not have their own attributes.
        Handle(Prs3d_Drawer) DefaultDrawer();

        //! Returns the current viewer.
        Handle(V3d_Viewer) CurrentViewer();

        Handle(SelectMgr_SelectionManager) SelectionManager();

        Handle(PrsMgr_PresentationManager3d) MainPrsMgr();

        Handle(StdSelect_ViewerSelector3d) MainSelector();

        //! Updates the current viewer.
        void UpdateCurrentViewer();

        //! Returns the list of displayed objects of a particular Type WhichKind and Signature WhichSignature.
        //! By Default, WhichSignature equals -1. This means that there is a check on type only.
        void DisplayedObjects(AIS_ListOfInteractive aListOfIO);

        //! gives the list of displayed objects of a particular Type and signature.
        //! by Default, <WhichSignature> = -1 means control only on <WhichKind>.
        void DisplayedObjects(AIS_KindOfInteractive theWhichKind, Standard_Integer theWhichSignature, AIS_ListOfInteractive theListOfIO);

        //! Returns the list theListOfIO of erased objects (hidden objects) particular Type WhichKind and Signature WhichSignature.
        //! By Default, WhichSignature equals 1. This means that there is a check on type only.
        void ErasedObjects(AIS_ListOfInteractive theListOfIO);

        //! gives the list of erased objects (hidden objects)
        //! Type and signature by Default, <WhichSignature> = -1 means control only on <WhichKind>.
        void ErasedObjects(AIS_KindOfInteractive theWhichKind, Standard_Integer theWhichSignature, AIS_ListOfInteractive theListOfIO);

        //! Returns the list theListOfIO of objects with indicated display status particular Type WhichKind and Signature WhichSignature.
        //! By Default, WhichSignature equals 1. This means that there is a check on type only.
        void ObjectsByDisplayStatus(AIS_DisplayStatus theStatus, AIS_ListOfInteractive theListOfIO);

        //! gives the list of objects with indicated display status
        //! Type and signature by Default, <WhichSignature> = -1 means control only on <WhichKind>.
        void ObjectsByDisplayStatus(AIS_KindOfInteractive WhichKind, Standard_Integer WhichSignature, AIS_DisplayStatus theStatus, AIS_ListOfInteractive theListOfIO);

        //! fills <aListOfIO> with objects of a particular Type and Signature with no consideration of display status.
        //! by Default, <WhichSignature> = -1 means control only on <WhichKind>.
        //! if <WhichKind> = AIS_KOI_None and <WhichSignature> = -1, all the objects are put into the list.
        void ObjectsInside(AIS_ListOfInteractive aListOfIO, AIS_KindOfInteractive WhichKind, Standard_Integer WhichSignature);

        //! Rebuilds 1st level of BVH selection forcibly
        void RebuildSelectionStructs();

        //! Disconnects theObjToDisconnect from theAssembly and removes dependent selection structures
        void Disconnect(Handle(AIS_InteractiveObject) theAssembly, Handle(AIS_InteractiveObject) theObjToDisconnect);

        //! Query objects visible or hidden in specified view due to affinity mask.
        void ObjectsForView(AIS_ListOfInteractive theListOfIO, Handle(V3d_View) theView, Standard_Boolean theIsVisibleInView, AIS_DisplayStatus theStatus);

        //! Clears all the structures which don't belong to objects displayed at neutral point
        //! only effective when no Local Context is opened...
        //! returns the number of removed  structures from the viewers.
        Standard_Integer PurgeDisplay();

        //! Return rotation gravity point.
        virtual xgp_Pnt^ GravityPoint(Handle(V3d_View) theView);

    public: //! @name debug visualization

      //! Visualization of sensitives - for debugging purposes!
        void DisplayActiveSensitive(Handle(V3d_View) aView);

        //! Clear visualization of sensitives.
        void ClearActiveSensitive(Handle(V3d_View) aView);

        //! Visualization of sensitives - for debugging purposes!
        void DisplayActiveSensitive(Handle(AIS_InteractiveObject) anObject, Handle(V3d_View) aView);

    public: //! @name common object display attributes

      //! Sets the graphic attributes of the interactive object, such as visualization mode, color, and material.
        void SetLocalAttributes(Handle(AIS_InteractiveObject) theIObj, Handle(Prs3d_Drawer) theDrawer, Standard_Boolean theToUpdateViewer);

        //! Removes the settings for local attributes of the Object and returns to defaults.
        void UnsetLocalAttributes(Handle(AIS_InteractiveObject) theIObj, Standard_Boolean theToUpdateViewer);

        //! change the current facing model apply on polygons for SetColor(), SetTransparency(), SetMaterial() methods default facing model is Aspect_TOFM_TWO_SIDE.
        //! This mean that attributes is applying both on the front and back face.
        void SetCurrentFacingModel(Handle(AIS_InteractiveObject) aniobj, Aspect_TypeOfFacingModel aModel);

        //! Returns true if a view of the Interactive Object has color.
        Standard_Boolean HasColor(Handle(AIS_InteractiveObject) aniobj);

        //! Returns the color of the Object in the interactive context.
        void Color(Handle(AIS_InteractiveObject) aniobj, Quantity_Color acolor);

        //! Sets the color of the selected entity.
        void SetColor(Handle(AIS_InteractiveObject) theIObj, Quantity_Color theColor, Standard_Boolean theToUpdateViewer);

        //! Removes the color selection for the selected entity.
        void UnsetColor(Handle(AIS_InteractiveObject) theIObj, Standard_Boolean theToUpdateViewer);

        //! Returns the width of the Interactive Object in the interactive context.
        virtual Standard_Real Width(Handle(AIS_InteractiveObject) aniobj);

        //! Sets the width of the Object.
        virtual void SetWidth(Handle(AIS_InteractiveObject) theIObj, Standard_Real theValue, Standard_Boolean theToUpdateViewer);

        //! Removes the width setting of the Object.
        virtual void UnsetWidth(Handle(AIS_InteractiveObject) theIObj, Standard_Boolean theToUpdateViewer);

        //! Provides the type of material setting for the view of the Object.
        void SetMaterial(Handle(AIS_InteractiveObject) theIObj, Graphic3d_MaterialAspect theMaterial, Standard_Boolean theToUpdateViewer);

        //! Removes the type of material setting for viewing the Object.
        void UnsetMaterial(Handle(AIS_InteractiveObject) theIObj, Standard_Boolean theToUpdateViewer);

        //! Provides the transparency settings for viewing the Object.
        //! The transparency value aValue may be between 0.0, opaque, and 1.0, fully transparent.
        void SetTransparency(Handle(AIS_InteractiveObject) theIObj, Standard_Real theValue, Standard_Boolean theToUpdateViewer);

        //! Removes the transparency settings for viewing the Object.
        void UnsetTransparency(Handle(AIS_InteractiveObject) theIObj, Standard_Boolean theToUpdateViewer);

        //! Sets up polygon offsets for the given AIS_InteractiveObject.
        //! It simply calls AIS_InteractiveObject::SetPolygonOffsets().
        void SetPolygonOffsets(Handle(AIS_InteractiveObject) theIObj, Standard_Integer theMode, Standard_ShortReal theFactor, Standard_ShortReal theUnits, Standard_Boolean theToUpdateViewer);

        //! Simply calls AIS_InteractiveObject::HasPolygonOffsets().
        Standard_Boolean HasPolygonOffsets(Handle(AIS_InteractiveObject) anObj);

        //! Retrieves current polygon offsets settings for Object.
        void PolygonOffsets(Handle(AIS_InteractiveObject) anObj, Standard_Integer aMode, Standard_ShortReal aFactor, Standard_ShortReal aUnits);

    public: //! @name trihedron display attributes

      //! Sets the size aSize of the trihedron.
      //! Is used to change the default value 100 mm for display of trihedra.
      //! Use of this function in one of your own interactive objects requires a call to the Compute function of the new class.
      //! This will recalculate the presentation for every trihedron displayed.
        void SetTrihedronSize(Standard_Real theSize, Standard_Boolean theToUpdateViewer);

        //! returns the current value of trihedron size.
        Standard_Real TrihedronSize();

    public: //! @name plane display attributes

      //! Sets the plane size defined by the length in the X direction XSize and that in the Y direction YSize.
        void SetPlaneSize(Standard_Real theSizeX, Standard_Real theSizeY, Standard_Boolean theToUpdateViewer);

        //! Sets the plane size aSize.
        void SetPlaneSize(Standard_Real theSize, Standard_Boolean theToUpdateViewer);

        //! Returns true if the length in the X direction XSize is the same as that in the Y direction YSize.
        Standard_Boolean PlaneSize(Standard_Real XSize, Standard_Real YSize);

    public: //! @name tessellation deviation properties for automatic triangulation

      //! Sets the deviation coefficient theCoefficient.
      //! Drawings of curves or patches are made with respect to a maximal chordal deviation.
      //! A Deviation coefficient is used in the shading display mode.
      //! The shape is seen decomposed into triangles.
      //! These are used to calculate reflection of light from the surface of the object.
      //! The triangles are formed from chords of the curves in the shape.
      //! The deviation coefficient theCoefficient gives the highest value of the angle with which a chord can deviate from a tangent to a curve.
      //! If this limit is reached, a new triangle is begun.
      //! This deviation is absolute and is set through the method: SetMaximalChordialDeviation.
      //! The default value is 0.001.
      //! In drawing shapes, however, you are allowed to ask for a relative deviation.
      //! This deviation will be: SizeOfObject * DeviationCoefficient.
        void SetDeviationCoefficient(Handle(AIS_InteractiveObject) theIObj, Standard_Real theCoefficient, Standard_Boolean theToUpdateViewer);

        void SetDeviationAngle(Handle(AIS_InteractiveObject) theIObj, Standard_Real theAngle, Standard_Boolean theToUpdateViewer);

        //! Calls the AIS_Shape SetAngleAndDeviation to set both Angle and Deviation coefficients
        void SetAngleAndDeviation(Handle(AIS_InteractiveObject) theIObj, Standard_Real theAngle, Standard_Boolean theToUpdateViewer);


        //! Sets the deviation coefficient aCoefficient for removal of hidden lines created by different viewpoints in different presentations.
        //! The Default value is 0.02.
        //! void SetHLRDeviationCoefficient(Handle(AIS_InteractiveObject) theIObj,  Standard_Real theCoefficient,  Standard_Boolean theToUpdateViewer);

        //! void SetHLRDeviationAngle(Handle(AIS_InteractiveObject) theIObj, Standard_Real theAngle, Standard_Boolean theToUpdateViewer);

        //! Computes a HLRAngle and a HLRDeviationCoefficient by means of the angle anAngle
        //! and sets the corresponding methods in the default drawing tool with these values.
        //! void SetHLRAngleAndDeviation(Handle(AIS_InteractiveObject) theIObj, Standard_Real theAngle, Standard_Boolean theToUpdateViewer);

        //! Sets the deviation coefficient theCoefficient.
        //! Drawings of curves or patches are made with respect to a maximal chordal deviation.
        //! A Deviation coefficient is used in the shading display mode.
        //! The shape is seen decomposed into triangles.
        //! These are used to calculate reflection of light from the surface of the object.
        //! The triangles are formed from chords of the curves in the shape.
        //! The deviation coefficient theCoefficient gives the highest value of the angle with which a chord can deviate from a tangent to a curve.
        //! If this limit is reached, a new triangle is begun.
        //! This deviation is absolute and is set through the method: SetMaximalChordialDeviation.
        //! The default value is 0.001.
        //! In drawing shapes, however, you are allowed to ask for a relative deviation.
        //! This deviation will be: SizeOfObject * DeviationCoefficient.
        void SetDeviationCoefficient(Standard_Real theCoefficient);

        //! Returns the deviation coefficient.
        //! Drawings of curves or patches are made with respect to a maximal chordal deviation.
        //! A Deviation coefficient is used in the shading display mode.
        //! The shape is seen decomposed into triangles.
        //! These are used to calculate reflection of light from the surface of the object.
        //! The triangles are formed from chords of the curves in the shape.
        //! The deviation coefficient gives the highest value of the angle with which a chord can deviate from a tangent to a curve.
        //! If this limit is reached, a new triangle is begun.
        //! This deviation is absolute and is set through Prs3d_Drawer::SetMaximalChordialDeviation.
        //! The default value is 0.001.
        //! In drawing shapes, however, you are allowed to ask for a relative deviation.
        //! This deviation will be: SizeOfObject * DeviationCoefficient.
        Standard_Real DeviationCoefficient();

        //! default 12 degrees
        void SetDeviationAngle(Standard_Real anAngle);

        Standard_Real DeviationAngle();

        //! Sets the deviation coefficient aCoefficient for removal of hidden lines created by different viewpoints in different presentations.
        //! The Default value is 0.02.
        //! void SetHLRDeviationCoefficient(Standard_Real aCoefficient);

        //! Returns the real number value of the hidden line removal deviation coefficient.
        //! A Deviation coefficient is used in the shading display mode.
        //! The shape is seen decomposed into triangles.
        //! These are used to calculate reflection of light from the surface of the object.
        //! The triangles are formed from chords of the curves in the shape.
        //! The deviation coefficient give the highest value of the angle with which a chord can deviate from a tangent to a curve.
        //! If this limit is reached, a new triangle is begun.
        //! To find the hidden lines, hidden line display mode entails recalculation of the view at each different projector perspective.
        //! Because hidden lines entail calculations of more than usual complexity to decompose them into these triangles,
        //! a deviation coefficient allowing greater tolerance is used.
        //! This increases efficiency in calculation.
        //! The Default value is 0.02.
       //!  Standard_Real HLRDeviationCoefficient();

        //! Sets the HLR angle.
        //! void SetHLRAngle(Standard_Real theAngle);

        //! Returns the real number value of the deviation angle in hidden line removal views in this interactive context.
        //! The default value is 20*PI/180.
       //!  Standard_Real HLRAngle();

        //! compute with theAngle a HLRAngle and a HLRDeviationCoefficient
        //! and set them in myHLRAngle and in myHLRDeviationCoefficient of myDefaultDrawer;
        //! theAngle is in radian; ( 1 deg < angle in deg < 20 deg)
        //! void SetHLRAngleAndDeviation(Standard_Real theAngle);

    public: //! @name HLR (Hidden Line Removal) display attributes

      //! Initializes hidden line aspect in the default drawing tool, or Drawer.
      //! The default values are:
      //! Color: Quantity_NOC_YELLOW
      //! Type of line: Aspect_TOL_DASH
      //! Width: 1.
        Handle(Prs3d_LineAspect) HiddenLineAspect();

        //! Sets the hidden line aspect anAspect.
        //! Aspect defines display attributes for hidden lines in HLR projections.
        void SetHiddenLineAspect(Handle(Prs3d_LineAspect) anAspect);

        //! returns Standard_True if the hidden lines are to be drawn.
        //! By default the hidden lines are not drawn.
        Standard_Boolean DrawHiddenLine();

        void EnableDrawHiddenLine();

        void DisableDrawHiddenLine();

    public: //! @name iso-line display attributes

      //! Sets the number of U and V isoparameters displayed.
        void SetIsoNumber(Standard_Integer NbIsos, AIS_TypeOfIso WhichIsos);

        //! Returns the number of U and V isoparameters displayed.
        Standard_Integer IsoNumber(AIS_TypeOfIso WhichIsos);

        //! Returns True if drawing isoparameters on planes is enabled.
        void IsoOnPlane(Standard_Boolean SwitchOn);

        //! Returns True if drawing isoparameters on planes is enabled.
        //! if <forUIsos> = False,
        Standard_Boolean IsoOnPlane();

        //! Enables or disables on-triangulation build for isolines for a particular object.
        //! In case if on-triangulation builder is disabled, default on-plane builder will compute isolines for the object given.
        void IsoOnTriangulation(Standard_Boolean theIsEnabled, Handle(AIS_InteractiveObject) theObject);

        //! Enables or disables on-triangulation build for isolines for default drawer.
        //! In case if on-triangulation builder is disabled, default on-plane builder will compute isolines for the object given.
        void IsoOnTriangulation(Standard_Boolean theToSwitchOn);

        //! Returns true if drawing isolines on triangulation algorithm is enabled.
        Standard_Boolean IsoOnTriangulation();

        //! @name obsolete methods
    public:

        //! Updates the view of the current object in open context.
        //! Objects selected when there is no open local context are called current objects; those selected in open local context, selected objects.
        void SetCurrentObject(Handle(AIS_InteractiveObject) theIObj, Standard_Boolean theToUpdateViewer) {
            SetSelected(theIObj, theToUpdateViewer);
        }

        //! Allows to add or remove the object given to the list of current and highlight/unhighlight it correspondingly.
        //! Is valid for global context only; for local context use method AddOrRemoveSelected.
        //! Since this method makes sence only for neutral point selection of a whole object,
        //! if 0 selection of the object is empty this method simply does nothing.
        void AddOrRemoveCurrentObject(Handle(AIS_InteractiveObject) theObj, Standard_Boolean theIsToUpdateViewer) {
            AddOrRemoveSelected(theObj, theIsToUpdateViewer);
        }

        //! Updates the list of current objects, i.e. hilights new current objects, removes hilighting from former current objects.
        //! Objects selected when there is no open local context are called current objects; those selected in open local context, selected objects.
        void UpdateCurrent() { UpdateSelected(Standard_True); }

        //! Returns true if there is a non-null interactive object in Neutral Point.
        //! Objects selected when there is no open local context are called current objects;
        //! those selected in open local context, selected objects.
        Standard_Boolean IsCurrent(Handle(AIS_InteractiveObject)& theObject) { return IsSelected(theObject); }

        //! Initializes a scan of the current selected objects in Neutral Point.
        //! Objects selected when there is no open local context are called current objects; those selected in open local context, selected objects.
        void InitCurrent() { InitSelected(); }

        //! Returns true if there is another object found by the scan of the list of current objects.
        //! Objects selected when there is no open local context are called current objects; those selected in open local context, selected objects.
        Standard_Boolean MoreCurrent() { return MoreSelected(); }

        //! Continues the scan to the next object in the list of current objects.
        //! Objects selected when there is no open local context are called current objects; those selected in open local context, selected objects.
        void NextCurrent() { NextSelected(); }

        //! Returns the current interactive object.
        //! Objects selected when there is no open local context are called current objects; those selected in open local context, selected objects.
        Handle(AIS_InteractiveObject) Current() { return SelectedInteractive(); }

        Standard_Integer NbCurrents() { return NbSelected(); }

        //! Highlights current objects.
        //! Objects selected when there is no open local context are called current objects; those selected in open local context, selected objects.
        void HilightCurrents(Standard_Boolean theToUpdateViewer) { HilightSelected(theToUpdateViewer); }

        //! Removes highlighting from current objects.
        //! Objects selected when there is no open local context are called current objects; those selected in open local context, selected objects.
        void UnhilightCurrents(Standard_Boolean theToUpdateViewer) { UnhilightSelected(theToUpdateViewer); }

        //! Empties previous current objects in order to get the current objects detected by the selector using UpdateCurrent.
        //! Objects selected when there is no open local context are called current objects; those selected in open local context, selected objects.
        void ClearCurrents(Standard_Boolean theToUpdateViewer) { ClearSelected(theToUpdateViewer); }

        //! @return current mouse-detected shape or empty (null) shape, if current interactive object
        //! is not a shape (AIS_Shape) or there is no current mouse-detected interactive object at all.
        //! @sa DetectedCurrentOwner()/InitDetected()/MoreDetected()/NextDetected().
        //！TopoDS_Shape DetectedCurrentShape();

        //! @return current mouse-detected interactive object or null object, if there is no currently detected interactives
        //! @sa DetectedCurrentOwner()/InitDetected()/MoreDetected()/NextDetected().
        //！Handle(AIS_InteractiveObject) DetectedCurrentObject();

    public: //! @name sub-intensity management (deprecated)

      //! Sub-intensity allows temporary highlighting of particular objects with specified color in a manner of selection highlight,
      //! but without actual selection (e.g., global status and owner's selection state will not be updated).
      //! The method returns the color of such highlighting.
      //! By default, it is Quantity_NOC_GRAY40.
        Quantity_Color SubIntensityColor();

        //! Sub-intensity allows temporary highlighting of particular objects with specified color in a manner of selection highlight,
        //! but without actual selection (e.g., global status and owner's selection state will not be updated).
        //! The method sets up the color for such highlighting.
        //! By default, this is Quantity_NOC_GRAY40.
        void SetSubIntensityColor(Quantity_Color theColor);

        //! Highlights, and removes highlights from, the displayed object which is displayed at Neutral Point with subintensity color.
        //! Available only for active local context.
        //! There is no effect if there is no local context.
        //! If a local context is open, the presentation of the Interactive Object activates the selection mode.
        void SubIntensityOn(Handle(AIS_InteractiveObject) theIObj, Standard_Boolean theToUpdateViewer);

        //! Removes the subintensity option for the entity.
        //! If a local context is open, the presentation of the Interactive Object activates the selection mode.
        void SubIntensityOff(Handle(AIS_InteractiveObject) theIObj, Standard_Boolean theToUpdateViewer);

        //! Returns selection instance
        Handle(AIS_Selection) Selection();

        //! Sets selection instance to manipulate a container of selected owners
        //! @param theSelection an instance of the selection
        void SetSelection(Handle(AIS_Selection) theSelection);

        /// <summary>
        /// 本地句柄
        /// </summary>
        virtual property Handle(Standard_Transient) IHandle {
            Handle(Standard_Transient) get(){// Standard_OVERRIDE {
                return NativeHandle();
            }
            void set(Handle(Standard_Transient) handle) {// Standard_OVERRIDE {
                NativeHandle() = Handle(AIS_InteractiveContext)::DownCast(handle);
            }
        };
    protected: //! @name internal fields
        NCollection_Haft<Handle(AIS_InteractiveContext)> NativeHandle;
    };
};
#endif // _XAIS_InteractiveContext_HeaderFile