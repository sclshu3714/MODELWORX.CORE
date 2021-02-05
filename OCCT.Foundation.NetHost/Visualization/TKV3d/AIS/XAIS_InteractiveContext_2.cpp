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

#include <XAIS_InteractiveContext.h>
#include <AIS_DataMapIteratorOfDataMapOfIOStatus.hxx>
#include <AIS_GlobalStatus.hxx>
#include <AIS_InteractiveContext.hxx>
#include <AIS_InteractiveObject.hxx>
#include <AIS_Selection.hxx>
#include <Graphic3d_MapIteratorOfMapOfStructure.hxx>
#include <Graphic3d_MapOfStructure.hxx>
#include <Graphic3d_Structure.hxx>
#include <Graphic3d_StructureManager.hxx>
#include <Prs3d_BasicAspect.hxx>
#include <Prs3d_LineAspect.hxx>
#include <Quantity_Color.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <SelectMgr_Filter.hxx>
#include <SelectMgr_OrFilter.hxx>
#include <SelectMgr_SelectionManager.hxx>
#include <Standard_Transient.hxx>
#include <StdSelect_ViewerSelector3d.hxx>
#include <TCollection_AsciiString.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TColStd_ListIteratorOfListOfInteger.hxx>
#include <TopLoc_Location.hxx>
#include <TopoDS_Shape.hxx>
#include <V3d_View.hxx>
#include <V3d_Viewer.hxx>

namespace TKV3d
{
    //=======================================================================
    //function : SetSelectionModeActive
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetSelectionModeActive(XAIS_InteractiveObject^ theObj, Standard_Integer theMode, Standard_Boolean theIsActive, XAIS_SelectionModesConcurrency theActiveFilter, Standard_Boolean theIsForce)
    {
        NativeHandle()->SetSelectionModeActive(theObj->GetInteractiveObject(), theMode, theIsActive, safe_cast<AIS_SelectionModesConcurrency>(theActiveFilter), theIsForce);
    };

    // ============================================================================
    // function : Activate
    // purpose  :
    // ============================================================================
    void XAIS_InteractiveContext::Activate(Standard_Integer theMode, Standard_Boolean theIsForce)
    {
        NativeHandle()->Activate(theMode, theIsForce);
    };

    //! Deactivates all the activated selection modes of an object.
    void XAIS_InteractiveContext::Deactivate(XAIS_InteractiveObject^ theObj) {
        NativeHandle()->Deactivate(theObj->GetInteractiveObject());
    };

    //! Deactivates all the activated selection modes of the interactive object anIobj with a given selection mode aMode.
    void XAIS_InteractiveContext::Deactivate(XAIS_InteractiveObject^ theObj, Standard_Integer theMode) {
        NativeHandle()->Deactivate(theObj->GetInteractiveObject(), theMode);
    };


    // ============================================================================
    // function : Deactivate
    // purpose  :
    // ============================================================================
    void XAIS_InteractiveContext::Deactivate(Standard_Integer theMode)
    {
        NativeHandle()->Deactivate(theMode);
    };

    // ============================================================================
    // function : Deactivate
    // purpose  :
    // ============================================================================
    void XAIS_InteractiveContext::Deactivate()
    {
        NativeHandle()->Deactivate();
    };

    //=======================================================================
    //function : ActivatedModes
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::ActivatedModes(XAIS_InteractiveObject^ theObj, TColStd_ListOfInteger theList)
    {
        NativeHandle()->ActivatedModes(theObj->GetInteractiveObject(), theList);
    };

    //! Sub-intensity allows temporary highlighting of particular objects with specified color in a manner of selection highlight,
      //! but without actual selection (e.g., global status and owner's selection state will not be updated).
      //! The method returns the color of such highlighting.
      //! By default, it is Quantity_NOC_GRAY40.
    XQuantity_Color^ XAIS_InteractiveContext::SubIntensityColor() {
        return gcnew XQuantity_Color(NativeHandle()->SubIntensityColor());
    };

    //! Sub-intensity allows temporary highlighting of particular objects with specified color in a manner of selection highlight,
    //! but without actual selection (e.g., global status and owner's selection state will not be updated).
    //! The method sets up the color for such highlighting.
    //! By default, this is Quantity_NOC_GRAY40.
    void XAIS_InteractiveContext::SetSubIntensityColor(XQuantity_Color^ theColor) {
        NativeHandle()->SetSubIntensityColor(*theColor->GetColor());
    };

    //=======================================================================
    //function : SubIntensityOn
    //purpose  : 
    //=======================================================================
    void XAIS_InteractiveContext::SubIntensityOn(XAIS_InteractiveObject^ anIObj, Standard_Boolean updateviewer)
    {
        NativeHandle()->SubIntensityOn(anIObj->GetInteractiveObject(), updateviewer);
    };
    //=======================================================================
    //function : SubIntensityOff
    //purpose  : 
    //=======================================================================

    void XAIS_InteractiveContext::SubIntensityOff(XAIS_InteractiveObject^ theObj, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->SubIntensityOff(theObj->GetInteractiveObject(), theToUpdateViewer);
    };

    //! Returns selection instance
    Handle(AIS_Selection) XAIS_InteractiveContext::Selection() {
        return NativeHandle()->Selection();
    };

    //! Sets selection instance to manipulate a container of selected owners
    //! @param theSelection an instance of the selection
    void XAIS_InteractiveContext::SetSelection(Handle(AIS_Selection) theSelection) {
        NativeHandle()->SetSelection(theSelection);
    };

    //=======================================================================
    //function : AddFilter
    //purpose  : 
    //=======================================================================
    void XAIS_InteractiveContext::AddFilter(Handle(SelectMgr_Filter) aFilter)
    {
        NativeHandle()->AddFilter(aFilter);
    };

    //=======================================================================
    //function : RemoveFilter
    //purpose  : 
    //=======================================================================
    void XAIS_InteractiveContext::RemoveFilter(Handle(SelectMgr_Filter) aFilter)
    {
        NativeHandle()->RemoveFilter(aFilter);
    };

    //=======================================================================
    //function : RemoveFilters
    //purpose  : 
    //=======================================================================

    void XAIS_InteractiveContext::RemoveFilters()
    {
        NativeHandle()->RemoveFilters();
    };

    //! Return picking strategy; SelectMgr_PickingStrategy_FirstAcceptable by default.
        //! @sa MoveTo()/Filters()
    XSelectMgr_PickingStrategy XAIS_InteractiveContext::PickingStrategy() {
        return safe_cast<XSelectMgr_PickingStrategy>(NativeHandle()->PickingStrategy());
    };

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
    void XAIS_InteractiveContext::SetPickingStrategy(XSelectMgr_PickingStrategy theStrategy) {
        NativeHandle()->SetPickingStrategy(safe_cast<SelectMgr_PickingStrategy>(theStrategy));
    };


    //=======================================================================
    //function : Filters
    //purpose  : 
    //=======================================================================
    SelectMgr_ListOfFilter XAIS_InteractiveContext::Filters()
    {
        return NativeHandle()->Filters();
    };

    //=======================================================================
    //function : DisplayActiveSensitive
    //purpose  : 
    //=======================================================================
    void XAIS_InteractiveContext::DisplayActiveSensitive(XV3d_View^ aviou)
    {
        NativeHandle()->DisplayActiveSensitive(aviou->GetView());
    };
    //=======================================================================
    //function : DisplayActiveSensitive
    //purpose  : 
    //=======================================================================

    void XAIS_InteractiveContext::DisplayActiveSensitive(XAIS_InteractiveObject^ theObj, XV3d_View^ theView)
    {
        NativeHandle()->DisplayActiveSensitive(theObj->GetInteractiveObject(), theView->GetView());
    };

    //=======================================================================
    //function : ClearActiveSensitive
    //purpose  : 
    //=======================================================================
    void XAIS_InteractiveContext::ClearActiveSensitive(XV3d_View^ theView)
    {
        NativeHandle()->ClearActiveSensitive(theView->GetView());
    };

    //=======================================================================
    //function : PurgeDisplay
    //purpose  : 
    //=======================================================================

    Standard_Integer XAIS_InteractiveContext::PurgeDisplay()
    {
        return NativeHandle()->PurgeDisplay();
    };


    ////=======================================================================
    ////function : PurgeViewer
    ////purpose  : 
    ////=======================================================================
    //Standard_Integer XAIS_InteractiveContext::PurgeViewer(XV3d_Viewer^ Vwr)
    //{
    //    return NativeHandle()->PurgeViewer(Vwr);
    //};

    //=======================================================================
    //function : IsImmediateModeOn
    //purpose  :
    //=======================================================================

    Standard_Boolean XAIS_InteractiveContext::IsImmediateModeOn()
    {
        return NativeHandle()->IsImmediateModeOn();
    };

    //! Redraws immediate structures in all views of the viewer given taking into account its visibility.
    void XAIS_InteractiveContext::RedrawImmediate(XV3d_Viewer^ theViewer) {
        NativeHandle()->RedrawImmediate(theViewer->GetViewer());
    };

    //=======================================================================
    //function : BeginImmediateDraw
    //purpose  :
    //=======================================================================

    Standard_Boolean XAIS_InteractiveContext::BeginImmediateDraw()
    {
        return NativeHandle()->BeginImmediateDraw();
    };

    //=======================================================================
    //function : ImmediateAdd
    //purpose  :
    //=======================================================================

    Standard_Boolean XAIS_InteractiveContext::ImmediateAdd(XAIS_InteractiveObject^ theObj, Standard_Integer theMode)
    {
        return NativeHandle()->ImmediateAdd(theObj->GetInteractiveObject(), theMode);
    };

    //=======================================================================
    //function : EndImmediateDraw
    //purpose  :
    //=======================================================================

    Standard_Boolean XAIS_InteractiveContext::EndImmediateDraw(XV3d_View^ theView)
    {
        return NativeHandle()->EndImmediateDraw(theView->GetView());
    };

    //=======================================================================
    //function : EndImmediateDraw
    //purpose  :
    //=======================================================================

    Standard_Boolean XAIS_InteractiveContext::EndImmediateDraw()
    {
        return NativeHandle()->EndImmediateDraw();
    };
};