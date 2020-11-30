// Created on: 1997-01-29
// Created by: Robert COUBLANC
// Copyright (c) 1997-1999 Matra Datavision
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

#include "XAIS_InteractiveContext.h"
#include <AIS_DataMapIteratorOfDataMapOfIOStatus.hxx>
#include <AIS_GlobalStatus.hxx>
#include <AIS_InteractiveContext.hxx>
#include <AIS_InteractiveObject.hxx>
#include <AIS_MapIteratorOfMapOfInteractive.hxx>
#include <AIS_MapOfInteractive.hxx>
#include <AIS_Selection.hxx>
#include <AIS_Shape.hxx>
#include <AIS_StatusOfDetection.hxx>
#include <AIS_StatusOfPick.hxx>
#include <Aspect_Grid.hxx>
#include <Prs3d_BasicAspect.hxx>
#include <Prs3d_LineAspect.hxx>
#include <Prs3d_Presentation.hxx>
#include <Quantity_Color.hxx>
#include <Select3D_SensitiveEntity.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <SelectMgr_Filter.hxx>
#include <SelectMgr_OrFilter.hxx>
#include <SelectMgr_Selection.hxx>
#include <SelectMgr_SelectionManager.hxx>
#include <Standard_Transient.hxx>
#include <StdSelect_BRepOwner.hxx>
#include <StdSelect_ViewerSelector3d.hxx>
#include <TCollection_AsciiString.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TColStd_ListIteratorOfListOfInteger.hxx>
#include <TopLoc_Location.hxx>
#include <V3d_AmbientLight.hxx>
#include <V3d_DirectionalLight.hxx>
#include <V3d_Light.hxx>
#include <V3d_PositionalLight.hxx>
#include <V3d_SpotLight.hxx>
#include <V3d_View.hxx>
#include <V3d_Viewer.hxx>

namespace TKV3d
{
    //=======================================================================
    //function : MoveTo
    //purpose  :
    //=======================================================================
    AIS_StatusOfDetection XAIS_InteractiveContext::MoveTo(Standard_Integer  theXPix, Standard_Integer  theYPix, Handle(V3d_View) theView, Standard_Boolean  theToRedrawOnUpdate)
    {
        return NativeHandle()->MoveTo(theXPix, theYPix, theView, theToRedrawOnUpdate);
    };

    //=======================================================================
    //function : AddSelect
    //purpose  : 
    //=======================================================================
    AIS_StatusOfPick XAIS_InteractiveContext::AddSelect(Handle(SelectMgr_EntityOwner) theObject)
    {
        return NativeHandle()->AddSelect(theObject);
    };

    //=======================================================================
    //function : Select
    //purpose  : 
    //=======================================================================
    AIS_StatusOfPick XAIS_InteractiveContext::Select(Standard_Integer  theXPMin, Standard_Integer  theYPMin, Standard_Integer  theXPMax, Standard_Integer  theYPMax, Handle(V3d_View) theView, Standard_Boolean  toUpdateViewer)
    {
        return NativeHandle()->Select(theXPMin, theYPMin, theXPMax, theYPMax, theView, toUpdateViewer);
    };

    //=======================================================================
    //function : Select
    //purpose  : Selection by polyline
    //=======================================================================
    AIS_StatusOfPick XAIS_InteractiveContext::Select(TColgp_Array1OfPnt2d thePolyline, Handle(V3d_View) theView, Standard_Boolean toUpdateViewer)
    {
        return NativeHandle()->Select(thePolyline, theView, toUpdateViewer);
    };

    //=======================================================================
    //function : Select
    //purpose  : 
    //=======================================================================
    AIS_StatusOfPick XAIS_InteractiveContext::Select(Standard_Boolean toUpdateViewer)
    {
        return NativeHandle()->Select(toUpdateViewer);
    };

    //=======================================================================
    //function : ShiftSelect
    //purpose  : 
    //=======================================================================
    AIS_StatusOfPick XAIS_InteractiveContext::ShiftSelect(Standard_Boolean toUpdateViewer)
    {
        return NativeHandle()->ShiftSelect(toUpdateViewer);
    };

    //=======================================================================
    //function : ShiftSelect
    //purpose  : 
    //=======================================================================
    AIS_StatusOfPick XAIS_InteractiveContext::ShiftSelect(Standard_Integer theXPMin, Standard_Integer theYPMin, Standard_Integer theXPMax, Standard_Integer theYPMax, Handle(V3d_View) theView, Standard_Boolean toUpdateViewer)
    {
        return NativeHandle()->ShiftSelect(theXPMin, theYPMin, theXPMax, theYPMax, theView, toUpdateViewer);
    };

    //=======================================================================
    //function : ShiftSelect
    //purpose  : 
    //=======================================================================
    AIS_StatusOfPick XAIS_InteractiveContext::ShiftSelect(TColgp_Array1OfPnt2d thePolyline, Handle(V3d_View) theView, Standard_Boolean toUpdateViewer)
    {
        return NativeHandle()->ShiftSelect(thePolyline, theView, toUpdateViewer);
    };

    //=======================================================================
    //function : HilightSelected
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::HilightSelected(Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->HilightSelected(theToUpdateViewer);
    };

    ////=======================================================================
    ////function : highlightOwners
    ////purpose  :
    ////=======================================================================
    //void XAIS_InteractiveContext::highlightOwners(AIS_NListOfEntityOwner& theOwners)
    //{
    //    NativeHandle()->highlightOwners(theOwners);
    //};

    //=======================================================================
    //function : UnhilightSelected
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::UnhilightSelected(Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->UnhilightSelected(theToUpdateViewer);
    };


    //=======================================================================
    //function : ClearSelected
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::ClearSelected(Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->ClearSelected(theToUpdateViewer);
    };

    //=======================================================================
    //function : SetSelected
    //purpose  : Sets the whole object as selected and highlights it with selection color
    //=======================================================================
    void XAIS_InteractiveContext::SetSelected(Handle(AIS_InteractiveObject) theObject, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->SetSelected(theObject, theToUpdateViewer);
    };

    //=======================================================================
    //function : SetSelected
    //purpose  : Sets the whole object as selected and highlights it with selection color
    //=======================================================================
    void XAIS_InteractiveContext::SetSelected(Handle(SelectMgr_EntityOwner) theOwner, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->SetSelected(theOwner, theToUpdateViewer);
    };

    //=======================================================================
    //function : AddOrRemoveSelected
    //purpose  : Adds or removes current object from AIS selection and highlights/unhighlights it.
    //           Since this method makes sence only for neutral point selection of a whole object,
    //           if 0 selection of the object is empty this method simply does nothing.
    //=======================================================================
    void XAIS_InteractiveContext::AddOrRemoveSelected(Handle(AIS_InteractiveObject) theObject, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->AddOrRemoveSelected(theObject, theToUpdateViewer);
    };

    //=======================================================================
    //function : AddOrRemoveSelected
    //purpose  : Allows to highlight or unhighlight the owner given depending on
    //           its selection status
    //=======================================================================
    void XAIS_InteractiveContext::AddOrRemoveSelected(Handle(SelectMgr_EntityOwner) theOwner, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->AddOrRemoveSelected(theOwner, theToUpdateViewer);
    };

    // =======================================================================
    // function : SetSelectedState
    // purpose  :
    // =======================================================================
    Standard_Boolean XAIS_InteractiveContext::SetSelectedState(Handle(SelectMgr_EntityOwner) theEntity, Standard_Boolean theIsSelected)
    {
        return NativeHandle()->SetSelectedState(theEntity, theIsSelected);
    };

    //=======================================================================
    //function : IsSelected
    //purpose  :
    //=======================================================================
    Standard_Boolean XAIS_InteractiveContext::IsSelected(Handle(AIS_InteractiveObject) theObj)
    {
        return NativeHandle()->IsSelected(theObj);
    };

    //=======================================================================
    //function : FirstSelectedObject
    //purpose  :
    //=======================================================================
    Handle(AIS_InteractiveObject) XAIS_InteractiveContext::FirstSelectedObject()
    {
        return NativeHandle()->FirstSelectedObject();
    };

    //! Count a number of selected entities using InitSelected()+MoreSelected()+NextSelected() iterator.
       //! @sa SelectedOwner()/InitSelected()/MoreSelected()/NextSelected().
    Standard_Integer XAIS_InteractiveContext::NbSelected() {
        return NativeHandle()->NbSelected();
    };

    //! Initializes a scan of the selected objects.
    //! @sa SelectedOwner()/MoreSelected()/NextSelected().
    void XAIS_InteractiveContext::InitSelected() {
        NativeHandle()->InitSelected();
    };

    //! Returns true if there is another object found by the scan of the list of selected objects.
    //! @sa SelectedOwner()/InitSelected()/NextSelected().
    Standard_Boolean XAIS_InteractiveContext::MoreSelected() {
        return NativeHandle()->MoreSelected();
    };

    //! Continues the scan to the next object in the list of selected objects.
    //! @sa SelectedOwner()/InitSelected()/MoreSelected().
    void XAIS_InteractiveContext::NextSelected() {
        NativeHandle()->NextSelected();
    };

    //! Returns the owner of the selected entity.
    //! @sa InitSelected()/MoreSelected()/NextSelected().
    Handle(SelectMgr_EntityOwner) XAIS_InteractiveContext::SelectedOwner() {
        return NativeHandle()->SelectedOwner();
    };

    //! Return Handle(AIS_InteractiveObject)::DownCast (SelectedOwner()->Selectable()).
    //! @sa SelectedOwner().
    Handle(AIS_InteractiveObject) XAIS_InteractiveContext::SelectedInteractive() {
        return NativeHandle()->SelectedInteractive();
    };

    //=======================================================================
    //function : HasSelectedShape
    //purpose  :
    //=======================================================================
    Standard_Boolean XAIS_InteractiveContext::HasSelectedShape()
    {
        return NativeHandle()->HasSelectedShape();
    };

    //=======================================================================
    //function : SelectedShape
    //purpose  :
    //=======================================================================
    TopoDS_Shape XAIS_InteractiveContext::SelectedShape()
    {
        return NativeHandle()->SelectedShape();
    };

    //=======================================================================
    //function : EntityOwners
    //purpose  : 
    //=======================================================================
    void XAIS_InteractiveContext::EntityOwners(Handle(SelectMgr_IndexedMapOfOwner) theOwners, Handle(AIS_InteractiveObject) theIObj, Standard_Integer theMode)
    {
        NativeHandle()->EntityOwners(theOwners, theIObj, theMode);
    };

    //=======================================================================
    //function : HasDetectedShape
    //purpose  : 
    //=======================================================================
    /*Standard_Boolean XAIS_InteractiveContext::HasDetectedShape()
    {
        return NativeHandle()->HasDetectedShape();
    };*/

    //=======================================================================
    //function : DetectedShape
    //purpose  : 
    //=======================================================================
    /*TopoDS_Shape XAIS_InteractiveContext::DetectedShape()
    {
        return NativeHandle()->DetectedShape();
    };*/

    //! returns True if other entities were detected in the last mouse detection
        //! @sa HilightPreviousDetected()/HilightNextDetected().
    Standard_Boolean XAIS_InteractiveContext::HasNextDetected() {
        return NativeHandle()->HasNextDetected();
    };

    //=======================================================================
    //function : HilightNextDetected
    //purpose  :
    //=======================================================================
    Standard_Integer XAIS_InteractiveContext::HilightNextDetected(Handle(V3d_View) theView, Standard_Boolean  theToRedrawImmediate)
    {
        return NativeHandle()->HilightNextDetected(theView, theToRedrawImmediate);
    };

    //=======================================================================
    //function : HilightPreviousDetected
    //purpose  :
    //=======================================================================
    Standard_Integer XAIS_InteractiveContext::HilightPreviousDetected(Handle(V3d_View) theView, Standard_Boolean  theToRedrawImmediate)
    {
        return NativeHandle()->HilightPreviousDetected(theView, theToRedrawImmediate);
    };


    //! Initialization for iteration through mouse-detected objects in
    //! interactive context or in local context if it is opened.
    //! @sa DetectedCurrentOwner()/MoreDetected()/NextDetected().
    void XAIS_InteractiveContext::InitDetected() {
        NativeHandle()->InitDetected();
    };

    //! Return TRUE if there is more mouse-detected objects after the current one
    //! during iteration through mouse-detected interactive objects.
    //! @sa DetectedCurrentOwner()/InitDetected()/NextDetected().
    Standard_Boolean XAIS_InteractiveContext::MoreDetected() {
        return NativeHandle()->MoreDetected();
    };

    //! Gets next current object during iteration through mouse-detected interactive objects.
    //! @sa DetectedCurrentOwner()/InitDetected()/MoreDetected().
    void XAIS_InteractiveContext::NextDetected() {
        NativeHandle()->NextDetected();
    };

    //=======================================================================
    //function : DetectedCurrentOwner
    //purpose  :
    //=======================================================================
    Handle(SelectMgr_EntityOwner) XAIS_InteractiveContext::DetectedCurrentOwner()
    {
        return NativeHandle()->DetectedCurrentOwner();
    };

    //=======================================================================
    //function : DetectedCurrentShape
    //purpose  :
    //=======================================================================
    /*TopoDS_Shape XAIS_InteractiveContext::DetectedCurrentShape()
    {
        return NativeHandle()->DetectedCurrentShape();
    };*/

    //=======================================================================
    //function : DetectedCurrentObject
    //purpose  :
    //=======================================================================
    /*Handle(AIS_InteractiveObject) XAIS_InteractiveContext::DetectedCurrentObject()
    {
        return NativeHandle()->DetectedCurrentObject();
    };*/
};