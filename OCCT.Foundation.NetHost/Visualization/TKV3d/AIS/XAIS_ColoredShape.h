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

#ifndef _XAIS_ColoredShape_HeaderFile
#define _XAIS_ColoredShape_HeaderFile
#pragma once
#include <AIS_ColoredShape.hxx>
#include <XAIS_Shape.h>
#include <XTopoDS_Shape.h>
#include <XQuantity_Color.h>
#include <XGraphic3d_MaterialAspect.h>

#include <AIS_DataMapOfShapeDrawer.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <StdPrs_Volume.hxx>
#include <TopoDS_Compound.hxx>
#include <TopTools_MapOfShape.hxx>
#include <TColStd_MapTransientHasher.hxx>

class StdSelect_BRepOwner;

//! Presentation of the shape with customizable sub-shapes properties.
using namespace TKBRep;
using namespace TKernel;
using namespace TKMath;
using namespace TKV3d;
namespace TKXCAF {

    ref class TKBRep::XTopoDS_Shape;
    ref class TKernel::XQuantity_Color;
    ref class TKV3d::XAIS_Shape;
    ref class TKV3d::XGraphic3d_MaterialAspect;
    public ref class XAIS_ColoredShape : public XAIS_Shape
    {
    public:
        //! Default constructor
        XAIS_ColoredShape(XTopoDS_Shape^ theShape);

        //! Copy constructor
        XAIS_ColoredShape(XAIS_Shape^ theShape);

        XAIS_ColoredShape(Handle(AIS_ColoredShape) pos);

        virtual Handle(AIS_ColoredShape) GetColoredShape();

        virtual Handle(AIS_Shape) GetShape() Standard_OVERRIDE;

        virtual Handle(AIS_InteractiveObject) GetInteractiveObject() Standard_OVERRIDE;

        virtual Handle(SelectMgr_SelectableObject) GetSelectableObject() Standard_OVERRIDE;

        virtual Handle(PrsMgr_PresentableObject) GetPresentableObject() Standard_OVERRIDE;

    public: //! @name sub-shape aspects

      //! Customize properties of specified sub-shape.
      //! The shape will be stored in the map but ignored, if it is not sub-shape of main Shape!
      //! This method can be used to mark sub-shapes with customizable properties.
        virtual Handle(AIS_ColoredDrawer) CustomAspects(XTopoDS_Shape^ theShape);

        //! Reset the map of custom sub-shape aspects.
        virtual void ClearCustomAspects();

        //! Reset custom properties of specified sub-shape.
        //! @param theToUnregister unregister or not sub-shape from the map
        //! Standard_Boolean theToUnregister = Standard_False
        void UnsetCustomAspects(XTopoDS_Shape^ theShape, Standard_Boolean theToUnregister);

        //! Customize color of specified sub-shape
        void SetCustomColor(XTopoDS_Shape^ theShape, XQuantity_Color^ theColor);

        //! Customize transparency of specified sub-shape
        void SetCustomTransparency(XTopoDS_Shape^ theShape, Standard_Real theTransparency);

        //! Customize line width of specified sub-shape
        void SetCustomWidth(XTopoDS_Shape^ theShape, Standard_Real theLineWidth);

        //! Return the map of custom aspects.
        AIS_DataMapOfShapeDrawer CustomAspectsMap();

        //! Return the map of custom aspects.
        AIS_DataMapOfShapeDrawer ChangeCustomAspectsMap();

    public: //! @name global aspects

      //! Setup color of entire shape.
        virtual void SetColor(XQuantity_Color^ theColor) Standard_OVERRIDE;

        //! Setup line width of entire shape.
        virtual void SetWidth(Standard_Real theLineWidth) Standard_OVERRIDE;

        //! Sets transparency value.
        virtual void SetTransparency(Standard_Real theValue) Standard_OVERRIDE;

        //! Sets the material aspect.
        virtual void SetMaterial(XGraphic3d_MaterialAspect^ theAspect) Standard_OVERRIDE;

    public:

        //! Removes the setting for transparency in the reconstructed compound shape.
        virtual void UnsetTransparency() Standard_OVERRIDE;

        //! Setup line width of entire shape.
        virtual void UnsetWidth() Standard_OVERRIDE;

        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property Handle(Standard_Transient) IHandle {
            Handle(Standard_Transient) get() Standard_OVERRIDE {
                return NativeHandle();
            }
            void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
                //NativeHandle() = Handle(AIS_Shape)::DownCast(handle);
                if (!handle.IsNull())
                    NativeHandle() = Handle(AIS_ColoredShape)::DownCast(handle);
                else NativeHandle() = NULL;
            }
        }

    private:
        NCollection_Haft<Handle(AIS_ColoredShape)> NativeHandle;

    };
}
#endif // _XAIS_ColoredShape_HeaderFile
