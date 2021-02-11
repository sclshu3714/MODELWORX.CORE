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

#ifndef _XXCAFPrs_AISObject_HeaderFile
#define _XXCAFPrs_AISObject_HeaderFile
#pragma once
#include <XCAFPrs_AISObject.hxx>
#include <XAIS_ColoredShape.h>
#include <XTDF_Label.h>
#include <XGraphic3d_MaterialAspect.h>

class XCAFPrs_Style;
using namespace TKLCAF;
using namespace TKService;
namespace TKXCAF {
    ref class TKLCAF::XTDF_Label;
    ref class TKService::XGraphic3d_MaterialAspect;
    //! Implements AIS_InteractiveObject functionality for shape in DECAF document.
    public ref class XXCAFPrs_AISObject : public XAIS_ColoredShape
    {
    public:

        //! Creates an object to visualise the shape label.
        XXCAFPrs_AISObject(XTDF_Label^ theLabel);


        XXCAFPrs_AISObject(Handle(XCAFPrs_AISObject) pos);

        virtual Handle(XCAFPrs_AISObject) GetAISObject();

        virtual Handle(AIS_ColoredShape) GetColoredShape() Standard_OVERRIDE;

        virtual Handle(AIS_Shape) GetShape() Standard_OVERRIDE;

        virtual Handle(AIS_InteractiveObject) GetInteractiveObject() Standard_OVERRIDE;

        virtual Handle(SelectMgr_SelectableObject) GetSelectableObject() Standard_OVERRIDE;

        virtual Handle(PrsMgr_PresentableObject) GetPresentableObject() Standard_OVERRIDE;

        //! Returns the label which was visualised by this presentation
        XTDF_Label^ GetLabel();

        //! Assign the label to this presentation
        //! (but does not mark it outdated with SetToUpdate()).
        void SetLabel(XTDF_Label^ theLabel);

        // !Returns the Color attributes of the shape accordingly to
        //! the current facing model;
        virtual void Color(XQuantity_Color ^ %aColor) Standard_OVERRIDE;

        //! Fetch the Shape from associated Label and fill the map of sub-shapes styles.
        //! By default, this method is called implicitly within first ::Compute().
        //! Application might call this method explicitly to manipulate styles afterwards.
        //! @param theToSyncStyles flag indicating if method ::Compute() should call this method again
        //!                        on first compute or re-compute
        //! Standard_Boolean theToSyncStyles = Standard_False
        virtual void DispatchStyles(Standard_Boolean theToSyncStyles);

        //! Sets the material aspect.
        //! This method assigns the new default material without overriding XDE styles.
        //! Re-computation of existing presentation is not required after calling this method.
        virtual void SetMaterial(XGraphic3d_MaterialAspect^ theMaterial) Standard_OVERRIDE;

        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property Handle(Standard_Transient) IHandle {
            Handle(Standard_Transient) get() Standard_OVERRIDE {
                return NativeHandle();
            }
            void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
                if (!handle.IsNull())
                    NativeHandle() = Handle(XCAFPrs_AISObject)::DownCast(handle);
                else NativeHandle() = NULL;
            }
        }

    private:
        NCollection_Haft<Handle(XCAFPrs_AISObject)> NativeHandle;
    };
}
#endif // _XXCAFPrs_AISObject_HeaderFile
