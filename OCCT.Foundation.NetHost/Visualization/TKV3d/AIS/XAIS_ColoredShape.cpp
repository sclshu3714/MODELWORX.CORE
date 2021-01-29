// Created on: 2014-04-24
// Created by: Kirill Gavrilov
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

#include <XAIS_ColoredShape.h>
namespace TKXCAF {

    //! Default constructor
    XAIS_ColoredShape::XAIS_ColoredShape(XTopoDS_Shape^ theShape) : XAIS_Shape(theShape) {
        NativeHandle() = new AIS_ColoredShape(*theShape->GetShape());
    };

    //! Copy constructor
    XAIS_ColoredShape::XAIS_ColoredShape(XAIS_Shape^ theShape) : XAIS_Shape(theShape->GetShape()) {
        NativeHandle() = new AIS_ColoredShape(theShape->GetShape());
    };

    XAIS_ColoredShape::XAIS_ColoredShape(Handle(AIS_ColoredShape) pos) : XAIS_Shape(pos) {
        NativeHandle() = pos;
    };

    Handle(AIS_ColoredShape) XAIS_ColoredShape::GetColoredShape() {
        return NativeHandle();
    };

    Handle(AIS_Shape) XAIS_ColoredShape::GetShape() {
        return NativeHandle();
    };

    Handle(AIS_InteractiveObject) XAIS_ColoredShape::GetInteractiveObject() {
        return NativeHandle();
    };

    Handle(SelectMgr_SelectableObject) XAIS_ColoredShape::GetSelectableObject() {
        return NativeHandle();
    };

    Handle(PrsMgr_PresentableObject) XAIS_ColoredShape::GetPresentableObject() {
        return NativeHandle();
    };

    //! @name sub-shape aspects

    //! Customize properties of specified sub-shape.
    //! The shape will be stored in the map but ignored, if it is not sub-shape of main Shape!
    //! This method can be used to mark sub-shapes with customizable properties.
    Handle(AIS_ColoredDrawer) XAIS_ColoredShape::CustomAspects(XTopoDS_Shape^ theShape) {
        return NativeHandle()->CustomAspects(*theShape->GetShape());
    };

    //! Reset the map of custom sub-shape aspects.
    void XAIS_ColoredShape::ClearCustomAspects() {
        NativeHandle()->ClearCustomAspects();
    };

    //! Reset custom properties of specified sub-shape.
    //! @param theToUnregister unregister or not sub-shape from the map
    //! Standard_Boolean theToUnregister = Standard_False
    void XAIS_ColoredShape::UnsetCustomAspects(XTopoDS_Shape^ theShape, Standard_Boolean theToUnregister) {
        NativeHandle()->UnsetCustomAspects(*theShape->GetShape(), theToUnregister);
    };

    //! Customize color of specified sub-shape
    void XAIS_ColoredShape::SetCustomColor(XTopoDS_Shape^ theShape, XQuantity_Color^ theColor) {
        NativeHandle()->SetCustomColor(*theShape->GetShape(), *theColor->GetColor());
    };

    //! Customize transparency of specified sub-shape
    void XAIS_ColoredShape::SetCustomTransparency(XTopoDS_Shape^ theShape, Standard_Real theTransparency) {
        NativeHandle()->SetCustomTransparency(*theShape->GetShape(), theTransparency);
    };

    //! Customize line width of specified sub-shape
    void XAIS_ColoredShape::SetCustomWidth(XTopoDS_Shape^ theShape, Standard_Real theLineWidth) {
        NativeHandle()->SetCustomWidth(*theShape->GetShape(), theLineWidth);
    };

    //! Return the map of custom aspects.
    AIS_DataMapOfShapeDrawer XAIS_ColoredShape::CustomAspectsMap() {
        return  NativeHandle()->CustomAspectsMap();
    };

    //! Return the map of custom aspects.
    AIS_DataMapOfShapeDrawer XAIS_ColoredShape::ChangeCustomAspectsMap() {
        return  NativeHandle()->ChangeCustomAspectsMap();
    };

    //! @name global aspects

    //! Setup color of entire shape.
    void XAIS_ColoredShape::SetColor(XQuantity_Color^ theColor) {
        NativeHandle()->SetColor(*theColor->GetColor());
    };

    //! Setup line width of entire shape.
    void XAIS_ColoredShape::SetWidth(Standard_Real theLineWidth) {
        NativeHandle()->SetWidth(theLineWidth);
    };

    //! Sets transparency value.
    void XAIS_ColoredShape::SetTransparency(Standard_Real theValue) {
        NativeHandle()->SetTransparency(theValue);
    };

    //! Sets the material aspect.
    void XAIS_ColoredShape::SetMaterial(XGraphic3d_MaterialAspect^ theAspect) {
        NativeHandle()->SetMaterial(*theAspect->GetMaterialAspect());
    };

    //! Removes the setting for transparency in the reconstructed compound shape.
    void XAIS_ColoredShape::UnsetTransparency() {
        NativeHandle()->UnsetTransparency();
    };

    //! Setup line width of entire shape.
    void XAIS_ColoredShape::UnsetWidth() {
        NativeHandle()->UnsetWidth();
    };
}
