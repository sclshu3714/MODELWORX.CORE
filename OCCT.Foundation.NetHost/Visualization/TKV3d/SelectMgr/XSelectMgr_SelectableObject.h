// Created on: 1995-02-20
// Created by: Mister rmi
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

#ifndef _XSelectMgr_SelectableObject_HeaderFile
#define _XSelectMgr_SelectableObject_HeaderFile
#pragma once
#include "NCollection_Haft.h"
#include <SelectMgr_SelectableObject.hxx>
#include "XPrsMgr_PresentableObject.h"


#include <PrsMgr_PresentableObject.hxx>
#include <SelectMgr_IndexedMapOfOwner.hxx>
#include <SelectMgr_SequenceOfSelection.hxx>
#include <SelectMgr_Selection.hxx>
#include <SelectMgr_SequenceOfOwner.hxx>

class SelectMgr_EntityOwner;
class Standard_NotImplemented;
class SelectMgr_SelectionManager;

//! A framework to supply the structure of the object to be selected.
//! At the first pick, this structure is created by calling the appropriate algorithm and retaining this framework for further picking.
//! This abstract framework is inherited in Application Interactive Services (AIS), notably in AIS_InteractiveObject.
//! Consequently, 3D selection should be handled by the relevant daughter classes and their member functions in AIS.
//! This is particularly true in the creation of new interactive objects.
//!
//! Key interface methods to be implemented by every Selectable Object:
//! * Presentable Object (PrsMgr_PresentableObject)
//!   Consider defining an enumeration of supported Display Mode indexes for particular Interactive Object or class of Interactive Objects.
//!   - AcceptDisplayMode() accepting display modes implemented by this object;
//!   - Compute() computing presentation for the given display mode index;
//! * Selectable Object (SelectMgr_SelectableObject)
//!   Consider defining an enumeration of supported Selection Mode indexes for particular Interactive Object or class of Interactive Objects.
//!   - ComputeSelection() computing selectable entities for the given selection mode index.
namespace TKV3d {
    public ref class XSelectMgr_SelectableObject : public XPrsMgr_PresentableObject
    {
        //! DEFINE_STANDARD_RTTIEXT(SelectMgr_SelectableObject, PrsMgr_PresentableObject)
        //!    friend class SelectMgr_SelectionManager;
    public:
        XSelectMgr_SelectableObject();
        //!
        XSelectMgr_SelectableObject(Handle(SelectMgr_SelectableObject) pos);

        //! 
        void SetSelectMgr_SelectableObjectNativeHandle(Handle(SelectMgr_SelectableObject) pos);

        //! Clears all selections of the object
        virtual ~XSelectMgr_SelectableObject();

        //! Computes sensitive primitives for the given selection mode - key interface method of Selectable Object.
        //! @param theSelection selection to fill
        //! @param theMode selection mode to create sensitive primitives
        virtual void ComputeSelection(const Handle(SelectMgr_Selection)& theSelection, Standard_Integer theMode);

        //! Informs the graphic context that the interactive Object may be decomposed into sub-shapes for dynamic selection.
        //! The most used Interactive Object is AIS_Shape.
        virtual Standard_Boolean AcceptShapeDecomposition();

        //! Re-computes the sensitive primitives for all modes. IMPORTANT: Do not use
        //! this method to update selection primitives except implementing custom selection manager!
        //! This method does not take into account necessary BVH updates, but may invalidate the pointers
        //! it refers to. TO UPDATE SELECTION properly from outside classes, use method UpdateSelection.
        void RecomputePrimitives();

        //! Re-computes the sensitive primitives which correspond to the <theMode>th selection mode.
        //! IMPORTANT: Do not use this method to update selection primitives except implementing custom selection manager!
        //! selection manager! This method does not take into account necessary BVH updates, but may invalidate
        //! the pointers it refers to. TO UPDATE SELECTION properly from outside classes, use method UpdateSelection.
        void RecomputePrimitives(const Standard_Integer theMode);

        //! Adds the selection aSelection with the selection mode
        //! index aMode to this framework.
        void AddSelection(const Handle(SelectMgr_Selection)& aSelection, Standard_Integer aMode);

        //! Empties all the selections in the SelectableObject
        //! <update> parameter defines whether all object's
        //! selections should be flagged for further update or not.
        //! This improved method can be used to recompute an
        //! object's selection (without redisplaying the object
        //! completely) when some selection mode is activated not for the first time.
        //! update = Standard_False
        void ClearSelections(const Standard_Boolean update);

        //! Returns the selection having specified selection mode or NULL.
        Handle(SelectMgr_Selection) Selection(const Standard_Integer theMode);

        //! Returns true if a selection corresponding to the selection mode theMode was computed for this object.
        Standard_Boolean HasSelection(const Standard_Integer theMode);

        //! Return the sequence of selections.
        SelectMgr_SequenceOfSelection Selections();

        void ResetTransformation() Standard_OVERRIDE;

        //! Recomputes the location of the selection aSelection.
        virtual void UpdateTransformation() Standard_OVERRIDE;

        //! Updates locations in all sensitive entities from <aSelection>
        //! and in corresponding entity owners.
        virtual void UpdateTransformations(const Handle(SelectMgr_Selection)& aSelection);

        //! Method which draws selected owners ( for fast presentation draw )
        virtual void HilightSelected(const Handle(PrsMgr_PresentationManager)& thePrsMgr, SelectMgr_SequenceOfOwner& theSeq);

        //! Method which clear all selected owners belonging
        //! to this selectable object ( for fast presentation draw )
        virtual void ClearSelected();

        //! Method that needs to be implemented when the object
        //! manages selection and dynamic highlighting on its own.
        //! Clears or invalidates dynamic highlight presentation.
        //! By default it clears immediate draw of given presentation
        //! manager.
        virtual void ClearDynamicHighlight(const Handle(PrsMgr_PresentationManager)& theMgr);

        //! Method which hilight an owner belonging to
        //! this selectable object  ( for fast presentation draw )
        virtual void HilightOwnerWithColor(const Handle(PrsMgr_PresentationManager)& thePM, Handle(Prs3d_Drawer)& theStyle, Handle(SelectMgr_EntityOwner)& theOwner);

        //! If returns True, the old mechanism for highlighting selected objects is used (HilightSelected Method may be empty).
        //! If returns False, the HilightSelected method will be fully responsible for highlighting selected entity owners belonging to this selectable object.
        virtual Standard_Boolean IsAutoHilight();

        //! Set AutoHilight property to true or false.
        virtual void SetAutoHilight(const Standard_Boolean theAutoHilight);

        //! Creates or returns existing presentation for highlighting detected object.
        //! @param thePrsMgr presentation manager to create new presentation
        //! @return existing or newly created presentation (when thePrsMgr is not NULL)
        Handle(Prs3d_Presentation) GetHilightPresentation(const Handle(PrsMgr_PresentationManager)& thePrsMgr);

        //! Creates or returns existing presentation for highlighting selected object.
        //! @param thePrsMgr presentation manager to create new presentation
        //! @return existing or newly created presentation (when thePrsMgr is not NULL)
        Handle(Prs3d_Presentation) GetSelectPresentation(const Handle(PrsMgr_PresentationManager)& thePrsMgr);

        //! Removes presentations returned by GetHilightPresentation() and GetSelectPresentation().
        virtual void ErasePresentations(Standard_Boolean theToRemove);

        //! Set Z layer ID and update all presentations of the selectable object.
        //! The layers mechanism allows drawing objects in higher layers in overlay of objects in lower layers.
        virtual void SetZLayer(const Graphic3d_ZLayerId theLayerId) Standard_OVERRIDE;

        //! Sets update status FULL to selections of the object. Must be used as the only method of UpdateSelection
        //! from outer classes to prevent BVH structures from being outdated.
        //! theMode = -1
        void UpdateSelection(const Standard_Integer theMode);

        //! Sets common entity owner for assembly sensitive object entities
        //! theMode = -1
        void SetAssemblyOwner(const Handle(SelectMgr_EntityOwner)& theOwner, Standard_Integer);

        //! Returns a bounding box of sensitive entities with the owners given if they are a part of activated selection
        Bnd_Box BndBoxOfSelected(const Handle(SelectMgr_IndexedMapOfOwner)& theOwners);

        //! Returns the mode for selection of object as a whole; 0 by default.
        Standard_Integer GlobalSelectionMode();

        //! Returns the owner of mode for selection of object as a whole
        virtual Handle(SelectMgr_EntityOwner) GlobalSelOwner();

        //! Returns common entity owner if the object is an assembly
        virtual Handle(SelectMgr_EntityOwner) GetAssemblyOwner();

        //! Dumps the content of me into the stream
        //! theDepth = -1
        virtual void DumpJson(Standard_OStream& theOStream, Standard_Integer theDepth) Standard_OVERRIDE;

        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        property Handle(SelectMgr_SelectableObject) Handle
        {
            Handle(SelectMgr_SelectableObject) get() {
                return NativeHandle();
            }
        };

    private:
        NCollection_Haft<Handle(SelectMgr_SelectableObject)> NativeHandle;

    };

    //! DEFINE_STANDARD_HANDLE(SelectMgr_SelectableObject, PrsMgr_PresentableObject)
}
#endif // _XSelectMgr_SelectableObject_HeaderFile
