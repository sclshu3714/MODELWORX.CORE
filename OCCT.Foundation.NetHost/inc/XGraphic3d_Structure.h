// Created on: 1991-06-12
// Created by: NW,JPB,CAL
// Copyright (c) 1991-1999 Matra Datavision
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

#ifndef _XGraphic3d_Structure_HeaderFile
#define _XGraphic3d_Structure_HeaderFile
#pragma once
#include <Graphic3d_Structure.hxx>
#include <XBnd_Box.h>
#include <xgp_Pnt.h>

#include <Graphic3d_BndBox4f.hxx>
#include <Graphic3d_BndBox4d.hxx>
#include <Graphic3d_CStructure.hxx>
#include <Graphic3d_MapOfStructure.hxx>
#include <Graphic3d_SequenceOfGroup.hxx>
#include <Graphic3d_SequenceOfHClipPlane.hxx>
#include <Graphic3d_TypeOfComposition.hxx>
#include <Graphic3d_TypeOfConnection.hxx>
#include <Graphic3d_TypeOfStructure.hxx>
#include <Graphic3d_TransformPers.hxx>
#include <Graphic3d_TransModeFlags.hxx>
#include <Graphic3d_Vertex.hxx>
#include <Graphic3d_ZLayerId.hxx>
#include <NCollection_IndexedMap.hxx>
#include <XGraphic3d_TypeOfStructure.h>
#include <XGraphic3d_TypeOfConnection.h>
#include <XGeom_Transformation.h>
#include <XGraphic3d_PresentationAttributes.h>
#include <XGraphic3d_DataStructureManager.h>

class Graphic3d_StructureManager;
class Graphic3d_DataStructureManager;
class Bnd_Box;
class gp_Pnt;

//! DEFINE_STANDARD_HANDLE(Graphic3d_Structure, Standard_Transient)
using namespace TKMath;
using namespace TKG3d;
namespace TKV3d {
    ref class TKMath::XBnd_Box;
    ref class TKMath::xgp_Pnt;
    ref class TKG3d::XGeom_Transformation;
    //! This class allows the definition a graphic object.
    //! This graphic structure can be displayed, erased, or highlighted.
    //! This graphic structure can be connected with another graphic structure.
    public ref class XGraphic3d_Structure //: public Standard_Transient
    {
        //! DEFINE_STANDARD_RTTIEXT(Graphic3d_Structure, Standard_Transient)
        //!    friend class Graphic3d_Group;
    public:

        //! Creates a graphic object in the manager theManager.
        //! It will appear in all the views of the visualiser.
        //! The structure is not displayed when it is created.
        //! @param theManager structure manager holding this structure
        //! @param theLinkPrs another structure for creating a shadow (linked) structure
        //! Handle(Graphic3d_Structure)& theLinkPrs = Handle(Graphic3d_Structure)()
        XGraphic3d_Structure(Handle(Graphic3d_StructureManager)& theManager, XGraphic3d_Structure^ theLinkPrs);

        //! if WithDestruction == Standard_True then
        //! suppress all the groups of primitives in the structure.
        //! and it is mandatory to create a new group in <me>.
        //! if WithDestruction == Standard_False then
        //! clears all the groups of primitives in the structure.
        //! and all the groups are conserved and empty.
        //! They will be erased at the next screen update.
        //! The structure itself is conserved.
        //! The transformation and the attributes of <me> are conserved.
        //! The childs of <me> are conserved.
        //! Standard_Boolean WithDestruction = Standard_True
        virtual void Clear(Standard_Boolean WithDestruction);

        //! Suppresses the structure <me>.
        //! It will be erased at the next screen update.
        virtual ~XGraphic3d_Structure();

        //! Displays the structure <me> in all the views of the visualiser.
        virtual void Display();

        //! Returns the current display priority for this structure.
        Standard_Integer DisplayPriority();

        //! Erases the structure <me> in all the views
        //! of the visualiser.
        virtual void Erase();

        //! Highlights the structure in all the views with the given style
        //! @param theStyle [in] the style (type of highlighting: box/color, color and opacity)
        //! @param theToUpdateMgr [in] defines whether related computed structures will be
        //! highlighted via structure manager or not
        //! Standard_Boolean theToUpdateMgr = Standard_True
        void Highlight(XGraphic3d_PresentationAttributes^ theStyle, Standard_Boolean theToUpdateMgr);

        //! Suppress the structure <me>.
        //! It will be erased at the next screen update.
        //! Warning: No more graphic operations in <me> after this call.
        //! Category: Methods to modify the class definition
        void Remove();

        //! Computes axis-aligned bounding box of a structure.
        virtual void CalculateBoundBox();

        //! Sets infinite flag.
        //! When TRUE, the MinMaxValues method returns:
        //! theXMin = theYMin = theZMin = RealFirst().
        //! theXMax = theYMax = theZMax = RealLast().
        //! By default, structure is created not infinite but empty.
        void SetInfiniteState(Standard_Boolean theToSet);

        //! Modifies the order of displaying the structure.
        //! Values are between 0 and 10.
        //! Structures are drawn according to their display priorities
        //! in ascending order.
        //! A structure of priority 10 is displayed the last and appears over the others.
        //! The default value is 5.
        //! Category: Methods to modify the class definition
        //! Warning: If <me> is displayed then the SetDisplayPriority
        //! method erase <me> and display <me> with the
        //! new priority.
        //! Raises PriorityDefinitionError if <Priority> is
        //! greater than 10 or a negative value.
        void SetDisplayPriority(Standard_Integer Priority);

        //! Reset the current priority of the structure to the
        //! previous priority.
        //! Category: Methods to modify the class definition
        //! Warning: If <me> is displayed then the SetDisplayPriority
        //! method erase <me> and display <me> with the
        //! previous priority.
        void ResetDisplayPriority();

        //! Set Z layer ID for the structure. The Z layer mechanism
        //! allows to display structures presented in higher layers in overlay
        //! of structures in lower layers by switching off z buffer depth
        //! test between layers
        //! Graphic3d_ZLayerId theLayerId
        void SetZLayer(Standard_Integer theLayerId);

        //! Get Z layer ID of displayed structure.
        //! The method returns -1 if the structure has no ID (deleted from graphic driver).
        Standard_Integer GetZLayer();

        //! Changes a sequence of clip planes slicing the structure on rendering.
        //! @param thePlanes [in] the set of clip planes.
        void SetClipPlanes(Handle(Graphic3d_SequenceOfHClipPlane)& thePlanes);

        //! Get clip planes slicing the structure on rendering.
        //! @return set of clip planes.
        Handle(Graphic3d_SequenceOfHClipPlane)& ClipPlanes();

        //! Modifies the visibility indicator to Standard_True or
        //! Standard_False for the structure <me>.
        //! The default value at the definition of <me> is
        //! Standard_True.
        void SetVisible(Standard_Boolean AValue);

        //! Modifies the visualisation mode for the structure <me>.
        virtual void SetVisual(XGraphic3d_TypeOfStructure AVisual);

        //! Modifies the minimum and maximum zoom coefficients
        //! for the structure <me>.
        //! The default value at the definition of <me> is unlimited.
        //! Category: Methods to modify the class definition
        //! Warning: Raises StructureDefinitionError if <LimitInf> is
        //! greater than <LimitSup> or if <LimitInf> or
        //! <LimitSup> is a negative value.
        void SetZoomLimit(Standard_Real LimitInf, Standard_Real LimitSup);

        //! Marks the structure <me> representing wired structure needed for highlight only so it won't be added to BVH tree.
        void SetIsForHighlight(Standard_Boolean isForHighlight);

        //! Suppresses the highlight for the structure <me>
        //! in all the views of the visualiser.
        void UnHighlight();

        virtual void Compute();

        //! Returns the new Structure defined for the new visualization
        virtual XGraphic3d_Structure^ Compute(XGraphic3d_DataStructureManager^ theProjector);

        //! Returns the new Structure defined for the new visualization
        virtual XGraphic3d_Structure^ Compute(XGraphic3d_DataStructureManager^ theProjector, XGeom_Transformation^ theTrsf);

        //! Returns the new Structure defined for the new visualization
        virtual void Compute(XGraphic3d_DataStructureManager^ theProjector, XGraphic3d_Structure^ theStructure);

        //! Returns the new Structure defined for the new visualization
        virtual void Compute(XGraphic3d_DataStructureManager^ theProjector, XGeom_Transformation^ theTrsf, XGraphic3d_Structure^ theStructure);

        //! Forces a newruction of the structure <me>
        //! if <me> is displayed and TOS_COMPUTED.
        void ReCompute();

        //! Forces a newruction of the structure <me>
        //! if <me> is displayed in <aProjetor> and TOS_COMPUTED.
        void ReCompute(XGraphic3d_DataStructureManager^ aProjector);

        //! Returns Standard_True if the structure <me> contains
        //! Polygons, Triangles or Quadrangles.
        Standard_Boolean ContainsFacet();

        //! Returns the groups sequence included in this structure.
        Graphic3d_SequenceOfGroup Groups();

        //! Returns the current number of groups in this structure.
        Standard_Integer NumberOfGroups();

        //! Append new group to this structure.
        Handle(Graphic3d_Group) NewGroup();

        //! Returns the last created group or creates new one if list is empty.
        Handle(Graphic3d_Group) CurrentGroup();

        //! Returns the highlight attributes.
        XGraphic3d_PresentationAttributes^ HighlightStyle();

        //! Returns TRUE if this structure is deleted (after Remove() call).
        Standard_Boolean IsDeleted();

        //! Returns the display indicator for this structure.
        virtual Standard_Boolean IsDisplayed();

        //! Returns Standard_True if the structure <me> is empty.
        //! Warning: A structure is empty if :
        //! it do not have group or all the groups are empties
        //! and it do not have descendant or all the descendants
        //! are empties.
        Standard_Boolean IsEmpty();

        //! Returns Standard_True if the structure <me> is infinite.
        Standard_Boolean IsInfinite();

        //! Returns the highlight indicator for this structure.
        virtual Standard_Boolean IsHighlighted();

        //! Returns TRUE if the structure is transformed.
        Standard_Boolean IsTransformed();

        //! Returns the visibility indicator for this structure.
        Standard_Boolean IsVisible();

        //! Returns the coordinates of the boundary box of the structure <me>.
        //! If <theToIgnoreInfiniteFlag> is TRUE, the method returns actual graphical
        //! boundaries of the Graphic3d_Group components. Otherwise, the
        //! method returns boundaries taking into account infinite state
        //! of the structure. This approach generally used for application
        //! specific fit operation (e.g. fitting the model into screen,
        //! not taking into accout infinite helper elements).
        //! Warning: If the structure <me> is empty then the empty box is returned,
        //! If the structure <me> is infinite then the whole box is returned.
        //! Standard_Boolean theToIgnoreInfiniteFlag = Standard_False
        XBnd_Box^ MinMaxValues(Standard_Boolean theToIgnoreInfiniteFlag);

        //! Returns the visualisation mode for the structure <me>.
        XGraphic3d_TypeOfStructure Visual();

        //! Returns Standard_True if the connection is possible between
        //! <AStructure1> and <AStructure2> without a creation
        //! of a cycle.
        //!
        //! It's not possible to call the method
        //! AStructure1->Connect (AStructure2, TypeOfConnection)
        //! if
        //! - the set of all ancestors of <AStructure1> contains
        //! <AStructure1> and if the
        //! TypeOfConnection == TOC_DESCENDANT
        //! - the set of all descendants of <AStructure1> contains
        //! <AStructure2> and if the
        //! TypeOfConnection == TOC_ANCESTOR
        static Standard_Boolean AcceptConnection(XGraphic3d_Structure^ theStructure1, XGraphic3d_Structure^ theStructure2, XGraphic3d_TypeOfConnection theType);

        //! Returns the group of structures to which <me> is connected.
        void Ancestors(Graphic3d_MapOfStructure& SG);

        //! If Atype is TOC_DESCENDANT then add <AStructure>
        //! as a child structure of  <me>.
        //! If Atype is TOC_ANCESTOR then add <AStructure>
        //! as a parent structure of <me>.
        //! The connection propagates Display, Highlight, Erase,
        //! Remove, and stacks the transformations.
        //! No connection if the graph of the structures
        //! contains a cycle and <WithCheck> is Standard_True;
        //!  Standard_Boolean theWithCheck = Standard_False
        void Connect(XGraphic3d_Structure^ theStructure, XGraphic3d_TypeOfConnection theType, Standard_Boolean theWithCheck);

        void Connect(XGraphic3d_Structure^ thePrs);

        //! Returns the group of structures connected to <me>.
        void Descendants(Graphic3d_MapOfStructure& SG);

        //! Suppress the connection between <AStructure> and <me>.
        void Disconnect(XGraphic3d_Structure^ theStructure);

        void Remove(XGraphic3d_Structure^ thePrs);// { Disconnect(thePrs.get()); }

        //! If Atype is TOC_DESCENDANT then suppress all
        //! the connections with the child structures of <me>.
        //! If Atype is TOC_ANCESTOR then suppress all
        //! the connections with the parent structures of <me>.
        void DisconnectAll(XGraphic3d_TypeOfConnection AType);

        void RemoveAll();// { XGraphic3d_TypeOfConnection TypeOfConnection = XGraphic3d_TypeOfConnection(Graphic3d_TOC_DESCENDANT); DisconnectAll(TypeOfConnection); }

        //! Returns <ASet> the group of structures :
        //! - directly or indirectly connected to <AStructure> if the
        //! TypeOfConnection == TOC_DESCENDANT
        //! - to which <AStructure> is directly or indirectly connected
        //! if the TypeOfConnection == TOC_ANCESTOR
        static void Network(XGraphic3d_Structure^ theStructure, XGraphic3d_TypeOfConnection theType, NCollection_Map<Graphic3d_Structure*>& theSet);

        void SetOwner(Object^ theOwner);

        Object^ Owner();

        void SetHLRValidation(Standard_Boolean theFlag);

        //! Hidden parts stored in this structure are valid if:
        //! 1) the owner is defined.
        //! 2) they are not invalid.
        Standard_Boolean HLRValidation();

        //! Return local transformation.
        XGeom_Transformation^ Transformation();

        //! Modifies the current local transformation
        void SetTransformation(XGeom_Transformation^ theTrsf);

        void Transform(XGeom_Transformation^ theTrsf) { SetTransformation(theTrsf); }

        //! Modifies the current transform persistence (pan, zoom or rotate)
        void SetTransformPersistence(Handle(Graphic3d_TransformPers)& theTrsfPers);

        //! @return transform persistence of the presentable object.
        Handle(Graphic3d_TransformPers)& TransformPersistence();

        //! Sets if the structure location has mutable nature (content or location will be changed regularly).
        void SetMutable(Standard_Boolean theIsMutable);

        //! Returns true if structure has mutable nature (content or location are be changed regularly).
        //! Mutable structure will be managed in different way than static onces.
        Standard_Boolean IsMutable();

        XGraphic3d_TypeOfStructure ComputeVisual();

        //! Clears the structure <me>.
        void GraphicClear(Standard_Boolean WithDestruction);

        void GraphicConnect(XGraphic3d_Structure^ theDaughter);

        void GraphicDisconnect(XGraphic3d_Structure^ theDaughter);

        //! Internal method which sets new transformation without calling graphic manager callbacks.
        void GraphicTransform(XGeom_Transformation^ theTrsf);

        //! Returns the identification number of this structure.
        Standard_Integer Identification();

        //! Prints informations about the network associated
        //! with the structure <AStructure>.
        static void PrintNetwork(XGraphic3d_Structure^ AStructure, XGraphic3d_TypeOfConnection AType);

        //! Suppress the structure in the list of descendants or in the list of ancestors.
        void Remove(XGraphic3d_Structure^ thePtr, XGraphic3d_TypeOfConnection theType);

        void SetComputeVisual(XGraphic3d_TypeOfStructure theVisual);

        //! Transforms theX, theY, theZ with the transformation theTrsf.
        static void Transforms(xgp_Trsf^ theTrsf, Standard_Real theX, Standard_Real theY, Standard_Real theZ, Standard_Real% theNewX, Standard_Real% theNewY, Standard_Real% theNewZ);

        //! Returns the low-level structure
        Handle(Graphic3d_CStructure)& CStructure();

        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property Handle(Graphic3d_Structure) IHandle {
            Handle(Graphic3d_Structure) get() { // Standard_OVERRIDE {
                return NativeHandle();
            }
            void set(Handle(Graphic3d_Structure) handle) { // Standard_OVERRIDE {
                NativeHandle() = handle;
            }
        }
    private:
        NCollection_Haft<Handle(Graphic3d_Structure)> NativeHandle;
    };
}
#endif // _XGraphic3d_Structure_HeaderFile
