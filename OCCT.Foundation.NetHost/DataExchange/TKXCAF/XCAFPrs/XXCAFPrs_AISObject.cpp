// Created on: 2000-08-11
// Created by: Andrey BETENEV
// Copyright (c) 2000-2014 OPEN CASCADE SAS
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

#include <XXCAFPrs_AISObject.h>
namespace TKXCAF {
    //! Creates an object to visualise the shape label.
    XXCAFPrs_AISObject::XXCAFPrs_AISObject(XTDF_Label^ theLabel) : XAIS_ColoredShape(gcnew XTopoDS_Shape()) {
        NativeHandle() = new XCAFPrs_AISObject(*theLabel->GetLabel());
    };


    XXCAFPrs_AISObject::XXCAFPrs_AISObject(Handle(XCAFPrs_AISObject) pos) : XAIS_ColoredShape(pos){
        NativeHandle() = pos;
    };

    Handle(XCAFPrs_AISObject) XXCAFPrs_AISObject::GetAISObject() {
        return NativeHandle();
    };

    Handle(AIS_ColoredShape) XXCAFPrs_AISObject::GetColoredShape() {
        return NativeHandle();
    };

    Handle(AIS_Shape) XXCAFPrs_AISObject::GetShape() {
        return NativeHandle();
    };

    Handle(AIS_InteractiveObject) XXCAFPrs_AISObject::GetInteractiveObject() {
        return NativeHandle();
    };

    Handle(SelectMgr_SelectableObject) XXCAFPrs_AISObject::GetSelectableObject() {
        return NativeHandle();
    };

    Handle(PrsMgr_PresentableObject) XXCAFPrs_AISObject::GetPresentableObject() {
        return NativeHandle();
    };

    //! Returns the label which was visualised by this presentation
    XTDF_Label^ XXCAFPrs_AISObject::GetLabel() {
        return gcnew XTDF_Label(NativeHandle()->GetLabel());
    };

    //! Assign the label to this presentation
    //! (but does not mark it outdated with SetToUpdate()).
    void XXCAFPrs_AISObject::SetLabel(XTDF_Label^ theLabel) {
        NativeHandle()->SetLabel(*theLabel->GetLabel());
    };

    // !Returns the Color attributes of the shape accordingly to
    //! the current facing model;
    void XXCAFPrs_AISObject::Color(XQuantity_Color^% aColor) {
        Quantity_Color* temp = aColor->GetColor();
        NativeHandle()->Color(*temp);
        aColor = gcnew XQuantity_Color(temp);
    };

    //! Fetch the Shape from associated Label and fill the map of sub-shapes styles.
    //! By default, this method is called implicitly within first ::Compute().
    //! Application might call this method explicitly to manipulate styles afterwards.
    //! @param theToSyncStyles flag indicating if method ::Compute() should call this method again
    //!                        on first compute or re-compute
    //! Standard_Boolean theToSyncStyles = Standard_False
    void XXCAFPrs_AISObject::DispatchStyles(Standard_Boolean theToSyncStyles) {
        NativeHandle()->DispatchStyles(theToSyncStyles);
    };

    //! Sets the material aspect.
    //! This method assigns the new default material without overriding XDE styles.
    //! Re-computation of existing presentation is not required after calling this method.
    void XXCAFPrs_AISObject::SetMaterial(XGraphic3d_MaterialAspect^ theMaterial) {
        NativeHandle()->SetMaterial(*theMaterial->GetMaterialAspect());
    };
}
