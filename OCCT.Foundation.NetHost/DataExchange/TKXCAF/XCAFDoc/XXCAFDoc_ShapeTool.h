// Created on: 2000-06-15
// Created by: Edward AGAPOV
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

#ifndef _XXCAFDoc_ShapeTool_HeaderFile
#define _XXCAFDoc_ShapeTool_HeaderFile
#pragma once
#include "XCAFDoc_ShapeTool.hxx"
#include "NCollection_Haft.h"
#include "XStandard_GUID.h"
#include "XTDF_Label.h"
#include "XTDF_Attribute.h"
#include <XTDF_LabelSequence.h>
#include "XTopLoc_Location.h"

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <XCAFDoc_DataMapOfShapeLabel.hxx>
#include <Standard_Boolean.hxx>
#include <TDataStd_NamedData.hxx>
#include <TDF_Attribute.hxx>
#include <TDF_LabelSequence.hxx>
#include <Standard_Integer.hxx>
#include <Standard_OStream.hxx>
#include <TColStd_SequenceOfHAsciiString.hxx>
#include <TDF_AttributeSequence.hxx>
#include <TopTools_SequenceOfShape.hxx>
class Standard_GUID;
class TDF_Label;
class TopoDS_Shape;
class TopLoc_Location;
class TDF_Attribute;
class TDF_RelocationTable;
class XCAFDoc_GraphNode;


//class XCAFDoc_ShapeTool;
//DEFINE_STANDARD_HANDLE(XCAFDoc_ShapeTool, TDF_Attribute)

//! A tool to store shapes in an XDE
//! document in the form of assembly structure, and to maintain this structure.
//! Attribute containing Shapes section of DECAF document.
//! Provide tools for management of Shapes section.
//! The API provided by this class allows to work with this
//! structure regardless of its low-level implementation.
//! All the shapes are stored on child labels of a main label which is
//! XCAFDoc_DocumentTool::LabelShapes(). The label for assembly also has
//! sub-labels, each of which represents the instance of
//! another shape in that assembly (component). Such sub-label
//! stores reference to the label of the original shape in the form
//! of TDataStd_TreeNode with GUID XCAFDoc::ShapeRefGUID(), and its
//! location encapsulated into the NamedShape.
//! For correct work with an XDE document, it is necessary to use
//! methods for analysis and methods for working with shapes.
//! For example:
//! if ( STool->IsAssembly(aLabel) )
//! { Standard_Boolean subchilds = Standard_False; (default)
//! Standard_Integer nbc = STool->NbComponents
//! (aLabel[,subchilds]);
//! }
//! If subchilds is True, commands also consider sub-levels. By
//! default, only level one is checked.
//! In this example, number of children from the first level of
//! assembly will be returned. Methods for creation and initialization:
//! Constructor:
//! XCAFDoc_ShapeTool::XCAFDoc_ShapeTool()
//! Getting a guid:
//! Standard_GUID GetID ();
//! Creation (if does not exist) of ShapeTool on label L:
//! Handle(XCAFDoc_ShapeTool) XCAFDoc_ShapeTool::Set(XTDF_Label^ L)
//! Analyze whether shape is a simple shape or an instance or a
//! component of an assembly or it is an assembly ( methods of analysis).
//! For example:
//! STool->IsShape(aLabel) ;
//! Analyze that the label represents a shape (simple
//! shape, assembly or reference) or
//! STool->IsTopLevel(aLabel);
//! Analyze that the label is a label of a top-level shape.
//! Work with simple shapes, assemblies and instances (
//! methods for work with shapes).
//! For example:
//! Add shape:
//! Standard_Boolean makeAssembly;
//! // True to interpret a Compound as an Assembly, False to take it
//! as a whole
//! aLabel = STool->AddShape(aShape, makeAssembly);
//! Get shape:
//! TDF_Label aLabel...
//! // A label must be present if
//! (aLabel.IsNull()) { ... no such label : abandon .. }
//! TopoDS_Shape aShape;
//! aShape = STool->GetShape(aLabel);
//! if (aShape.IsNull())
//! { ... this label is not for a Shape ... }
//! To get a label from shape.
//! Standard_Boolean findInstance = Standard_False;
//! (this is default value)
//! aLabel = STool->FindShape(aShape [,findInstance]);
//! if (aLabel.IsNull())
//! { ... no label found for this shape ... }
//! 
using namespace TKLCAF;
using namespace TKernel;
using namespace TKMath;
namespace TKXCAF {
    ref class TKLCAF::XTDF_Attribute;
    ref class TKernel::XStandard_GUID;
    ref class TKLCAF::XTDF_Label;
    ref class TKMath::XTopLoc_Location;
    public ref class XXCAFDoc_ShapeTool : public XTDF_Attribute
    {

    public:

        static XStandard_GUID^ GetID();

        //! Create (if not exist) ShapeTool from XCAFDoc on <L>.
        static XXCAFDoc_ShapeTool^ Set(XTDF_Label^ L);

        //! Creates an empty tool
        //! Creates a tool to work with a document <Doc>
        //! Attaches to label XCAFDoc::LabelShapes()
        XXCAFDoc_ShapeTool();

        !XXCAFDoc_ShapeTool() { };// { IHandle = NULL; };
        ~XXCAFDoc_ShapeTool() { IHandle = NULL; };
        //! Creates an empty tool
        //! Creates a tool to work with a document <Doc>
        //! Attaches to label XCAFDoc::LabelShapes()
        XXCAFDoc_ShapeTool(Handle(XCAFDoc_ShapeTool) pos);

        Handle(XCAFDoc_ShapeTool) GetShapeTool();

        //£¡
        virtual Handle(TDF_Attribute) GetAttribute() Standard_OVERRIDE;

        //! Returns True if the label is a label of top-level shape,
        //! as opposed to component of assembly or subshape
        Standard_Boolean IsTopLevel(XTDF_Label^ L);

        //! Returns True if the label is not used by any assembly, i.e.
        //! contains sublabels which are assembly components
        //! This is relevant only if IsShape() is True
        //! (There  is  no  Father TreeNode on  this  <L>)
        static Standard_Boolean IsFree(XTDF_Label^ L);

        //! Returns True if the label represents a shape (simple shape,
        //! assembly or reference)
        static Standard_Boolean IsShape(XTDF_Label^ L);

        //! Returns True if the label is a label of simple shape
        static Standard_Boolean IsSimpleShape(XTDF_Label^ L);

        //! Return true if <L> is a located instance of other shape
        //! i.e. reference
        static Standard_Boolean IsReference(XTDF_Label^ L);

        //! Returns True if the label is a label of assembly, i.e.
        //! contains sublabels which are assembly components
        //! This is relevant only if IsShape() is True
        static Standard_Boolean IsAssembly(XTDF_Label^ L);

        //! Return true if <L> is reference serving as component
        //! of assembly
        static Standard_Boolean IsComponent(XTDF_Label^ L);

        //! Returns True if the label is a label of compound, i.e.
        //! contains some sublabels
        //! This is relevant only if IsShape() is True
        static Standard_Boolean IsCompound(XTDF_Label^ L);

        //! Return true if <L> is subshape of the top-level shape
        static Standard_Boolean IsSubShape(XTDF_Label^ L);

        //! Checks whether shape <sub> is subshape of shape stored on
        //! label shapeL
        Standard_Boolean IsSubShape(XTDF_Label^ shapeL, TopoDS_Shape& sub);

        Standard_Boolean SearchUsingMap(const TopoDS_Shape& S, XTDF_Label^ L, Standard_Boolean findWithoutLoc, Standard_Boolean findSubshape);

        //! General tool to find a (sub) shape in the document
        //! * If findInstance is True, and S has a non-null location,
        //! first tries to find the shape among the top-level shapes
        //! with this location
        //! * If not found, and findComponent is True, tries to find the shape
        //! among the components of assemblies
        //! * If not found, tries to find the shape without location
        //! among top-level shapes
        //! * If not found and findSubshape is True, tries to find a
        //! shape as a subshape of top-level simple shapes
        //! Returns False if nothing is found
        //!  Standard_Boolean findInstance = Standard_True, Standard_Boolean findComponent = Standard_True, Standard_Boolean findSubshape = Standard_True
        Standard_Boolean Search(const TopoDS_Shape& S, XTDF_Label^ L, Standard_Boolean findInstance, Standard_Boolean findComponent, Standard_Boolean findSubshape);

        //! Returns the label corresponding to shape S
        //! (searches among top-level shapes, not including subcomponents
        //! of assemblies and subshapes)
        //! If findInstance is False (default), seach for the
        //! input shape without location
        //! If findInstance is True, searches for the
        //! input shape as is.
        //! Return True if <S> is found.
        //! Standard_Boolean findInstance = Standard_False
        Standard_Boolean FindShape(const TopoDS_Shape& S, XTDF_Label^ L, Standard_Boolean findInstance);

        //! Does the same as previous method
        //! Returns Null label if not found
        //! Standard_Boolean findInstance = Standard_False
        XTDF_Label^ FindShape(const TopoDS_Shape& S, Standard_Boolean findInstance);

        //! To get TopoDS_Shape from shape's label
        //! For component, returns new shape with correct location
        //! Returns False if label does not contain shape
        static Standard_Boolean GetShape(XTDF_Label^ L, TopoDS_Shape& S);

        //! To get TopoDS_Shape from shape's label
        //! For component, returns new shape with correct location
        //! Returns Null shape if label does not contain shape
        static TopoDS_Shape GetShape(XTDF_Label^ L);

        //! Creates new (empty) top-level shape.
        //! Initially it holds empty TopoDS_Compound
        XTDF_Label^ NewShape();

        //! Sets representation (TopoDS_Shape) for top-level shape.
        void SetShape(XTDF_Label^ L, TopoDS_Shape& S);

        //! Adds a new top-level (creates and returns a new label)
        //! If makeAssembly is True, treats TopAbs_COMPOUND shapes
        //! as assemblies (creates assembly structure).
        //! NOTE: <makePrepare> replace components without location
        //! in assmebly by located components to avoid some problems.
        //! If AutoNaming() is True then automatically attaches names.
        //! Standard_Boolean makeAssembly = Standard_True, Standard_Boolean makePrepare = Standard_True
        XTDF_Label^ AddShape(const TopoDS_Shape& S, Standard_Boolean makeAssembly, Standard_Boolean makePrepare);

        //! Removes shape (whole label and all its sublabels)
        //! If removeCompletely is true, removes complete shape
        //! If removeCompletely is false, removes instance(location) only
        //! Returns False (and does nothing) if shape is not free
        //! or is not top-level shape
        //! Standard_Boolean removeCompletely = Standard_True
        Standard_Boolean RemoveShape(XTDF_Label^ L, Standard_Boolean removeCompletely);

        //! set hasComponents into false
        void Init();

        //! Sets auto-naming mode to <V>. If True then for added
        //! shapes, links, assemblies and SHUO's, the TDataStd_Name attribute
        //! is automatically added. For shapes it contains a shape type
        //! (e.g. "SOLID", "SHELL", etc); for links it has a form
        //! "=>[0:1:1:2]" (where a tag is a label containing a shape
        //! without a location); for assemblies it is "ASSEMBLY", and
        //! "SHUO" for SHUO's.
        //! This setting is global; it cannot be made a member function
        //! as it is used by static methods as well.
        //! By default, auto-naming is enabled.
        //! See also AutoNaming().
        static void SetAutoNaming(const Standard_Boolean V);

        //! Returns current auto-naming mode. See SetAutoNaming() for
        //! description.
        static Standard_Boolean AutoNaming();

        //! recursive
        void ComputeShapes(XTDF_Label^ L);

        //! Compute a sequence of simple shapes
        void ComputeSimpleShapes();

        //! Returns a sequence of all top-level shapes
        void GetShapes(XTDF_LabelSequence^ Labels);

        //! Returns a sequence of all top-level shapes
        //! which are free (i.e. not referred by any other)
        XTDF_LabelSequence^ GetFreeShapes();

        //! Returns a sequence of all top-level shapes
        //! which are free (i.e. not referred by any other)
        void GetFreeShapes(XTDF_LabelSequence^ %FreeLabels);

        //! Returns list of labels which refer shape L as component
        //! Returns number of users (0 if shape is free)
        //! Standard_Boolean getsubchilds = Standard_False
        static Standard_Integer GetUsers(XTDF_Label^ L, TDF_LabelSequence& Labels, Standard_Boolean getsubchilds);

        //! Returns location of instance
        static XTopLoc_Location^ GetLocation(XTDF_Label^ L);

        //! Returns label which corresponds to a shape referred by L
        //! Returns False if label is not reference
        static Standard_Boolean GetReferredShape(XTDF_Label^ L, XTDF_Label^ Label);

        //! Returns number of Assembles components
        //! Standard_Boolean getsubchilds = Standard_False
        static Standard_Integer NbComponents(XTDF_Label^ L, Standard_Boolean getsubchilds);

        //! Returns list of components of assembly
        //! Returns False if label is not assembly
        //! Standard_Boolean getsubchilds = Standard_False
        static Standard_Boolean GetComponents(XTDF_Label^ L, TDF_LabelSequence& Labels, Standard_Boolean getsubchilds);

        //! Adds a component given by its label and location to the assembly
        //! Note: assembly must be IsAssembly() or IsSimpleShape()
        XTDF_Label^ AddComponent(XTDF_Label^ assembly, XTDF_Label^ comp, XTopLoc_Location^ Loc);

        //! Adds a shape (located) as a component to the assembly
        //! If necessary, creates an additional top-level shape for
        //! component and return the Label of component.
        //! If expand is True and component is Compound, it will
        //! be created as assembly also
        //! Note: assembly must be IsAssembly() or IsSimpleShape()
        //! Standard_Boolean expand = Standard_False
        XTDF_Label^ AddComponent(XTDF_Label^ assembly, TopoDS_Shape& comp, Standard_Boolean expand);

        //! Removes a component from its assembly
        void RemoveComponent(XTDF_Label^ comp);

        //! Top-down update for all assembly compounds stored in the document.
        void UpdateAssemblies();

        //! Finds a label for subshape <sub> of shape stored on
        //! label shapeL
        //! Returns Null label if it is not found
        Standard_Boolean FindSubShape(XTDF_Label^ shapeL, TopoDS_Shape& sub, XTDF_Label^ L);

        //! Adds a label for subshape <sub> of shape stored on
        //! label shapeL
        //! Returns Null label if it is not subshape
        XTDF_Label^ AddSubShape(XTDF_Label^ shapeL, TopoDS_Shape& sub);

        //! Adds (of finds already existed) a label for subshape <sub> of shape stored on
        //! label shapeL. Label addedSubShapeL returns added (found) label or empty in case of wrong subshape.
        //! Returns True, if new shape was added, False in case of already existed subshape/wrong subshape
        Standard_Boolean AddSubShape(XTDF_Label^ shapeL, TopoDS_Shape& sub, XTDF_Label^ addedSubShapeL);

        XTDF_Label^ FindMainShapeUsingMap(const TopoDS_Shape& sub);

        //! Performs a search among top-level shapes to find
        //! the shape containing <sub> as subshape
        //! Checks only simple shapes, and returns the first found
        //! label (which should be the only one for valid model)
        XTDF_Label^ FindMainShape(const TopoDS_Shape& sub);

        //! Returns list of labels identifying subshapes of the given shape
        //! Returns False if no subshapes are placed on that label
        static Standard_Boolean GetSubShapes(XTDF_Label^ L, TDF_LabelSequence& Labels);

        //! returns the label under which shapes are stored
        XTDF_Label^ BaseLabel();

        Standard_OStream& Dump(Standard_OStream& theDumpLog, Standard_Boolean deep);

        virtual Standard_OStream& Dump(Standard_OStream& theDumpLog) Standard_OVERRIDE;

        //! Print to std::ostream <theDumpLog> type of shape found on <L> label
        //! and the entry of <L>, with <level> tabs before.
        //! If <deep>, print also TShape and Location addresses
        //! Standard_Integer level = 0, Standard_Boolean deep = Standard_False
        static void DumpShape(Standard_OStream& theDumpLog, XTDF_Label^ L, Standard_Integer level, Standard_Boolean deep);

        XStandard_GUID^ ID() Standard_OVERRIDE;

        void Restore(XTDF_Attribute^ with) Standard_OVERRIDE;

       XTDF_Attribute^ NewEmpty() Standard_OVERRIDE;

        void Paste(XTDF_Attribute^ into, Handle(TDF_RelocationTable)& RT) Standard_OVERRIDE;

        //! Returns True if the label is a label of external references, i.e.
        //! there are some reference on the no-step files, which are
        //! described in document only their names
        static Standard_Boolean IsExternRef(XTDF_Label^ L);

        //! Sets the names of references on the no-step files
        XTDF_Label^ SetExternRefs(const TColStd_SequenceOfHAsciiString& SHAS);

        //! Sets the names of references on the no-step files
        void SetExternRefs(XTDF_Label^ L, TColStd_SequenceOfHAsciiString& SHAS);

        //! Gets the names of references on the no-step files
        static void GetExternRefs(XTDF_Label^ L, TColStd_SequenceOfHAsciiString& SHAS);

        //! Sets the SHUO structure between upper_usage and next_usage
        //! create multy-level (if number of labels > 2) SHUO from first to last
        //! Initialise out <MainSHUOAttr> by main upper_usage SHUO attribute.
        //! Returns FALSE if some of labels in not component label
        Standard_Boolean SetSHUO(const TDF_LabelSequence& Labels, Handle(XCAFDoc_GraphNode)& MainSHUOAttr);

        //! Returns founded SHUO GraphNode attribute <aSHUOAttr>
        //! Returns false in other case
        static Standard_Boolean GetSHUO(XTDF_Label^ SHUOLabel, Handle(XCAFDoc_GraphNode)& aSHUOAttr);

        //! Returns founded SHUO GraphNodes of indicated component
        //! Returns false in other case
        static Standard_Boolean GetAllComponentSHUO(XTDF_Label^ CompLabel, TDF_AttributeSequence& SHUOAttrs);

        //! Returns the sequence of labels of SHUO attributes,
        //! which is upper_usage for this next_usage SHUO attribute
        //! (that indicated by label)
        //! NOTE: returns upper_usages only on one level (not recurse)
        //! NOTE: do not clear the sequence before filling
        static Standard_Boolean GetSHUOUpperUsage(XTDF_Label^ NextUsageL, TDF_LabelSequence& Labels);

        //! Returns the sequence of labels of SHUO attributes,
        //! which is next_usage for this upper_usage SHUO attribute
        //! (that indicated by label)
        //! NOTE: returns next_usages only on one level (not recurse)
        //! NOTE: do not clear the sequence before filling
        static Standard_Boolean GetSHUONextUsage(XTDF_Label^ UpperUsageL, TDF_LabelSequence& Labels);

        //! Remove SHUO from component sublabel,
        //! remove all dependencies on other SHUO.
        //! Returns FALSE if cannot remove SHUO dependencies.
        //! NOTE: remove any styles that associated with this SHUO.
        Standard_Boolean RemoveSHUO(XTDF_Label^ SHUOLabel);

        //! Serach the path of labels in the document,
        //! that corresponds the component from any assembly
        //! Try to search the sequence of labels with location that
        //! produce this shape as component of any assembly
        //! NOTE: Clear sequence of labels before filling
        Standard_Boolean FindComponent(const TopoDS_Shape& theShape, TDF_LabelSequence& Labels);

        //! Search for the component shape that styled by shuo
        //! Returns null shape if no any shape is found.
        TopoDS_Shape GetSHUOInstance(const Handle(XCAFDoc_GraphNode)& theSHUO);

        //! Search for the component shape by labelks path
        //! and set SHUO structure for founded label structure
        //! Returns null attribute if no component in any assembly found.
        Handle(XCAFDoc_GraphNode) SetInstanceSHUO(const TopoDS_Shape& theShape);

        //! Seaching for component shapes that styled by shuo
        //! Returns empty sequence of shape if no any shape is found.
        Standard_Boolean GetAllSHUOInstances(const Handle(XCAFDoc_GraphNode)& theSHUO, TopTools_SequenceOfShape& theSHUOShapeSeq);

        //! Searchs the SHUO by labels of components
        //! from upper_usage componet to next_usage
        //! Returns null attribute if no SHUO found
        static Standard_Boolean FindSHUO(const TDF_LabelSequence& Labels, Handle(XCAFDoc_GraphNode)& theSHUOAttr);

        //! Convert Shape (compound/compsolid/shell/wire) to assembly
        Standard_Boolean Expand(XTDF_Label^ Shape);

        //! Method to get NamedData attribute assigned to the given shape label.
        //! @param theLabel    [in] the shape Label
        //! @param theToCreate [in] create and assign attribute if it doesn't exist
        //! @return Handle to the NamedData attribute or Null if there is none
        //! Standard_Boolean theToCreate = Standard_False
        Handle(TDataStd_NamedData) GetNamedProperties(XTDF_Label^ theLabel, Standard_Boolean theToCreate);

        //! Method to get NamedData attribute assigned to a label of the given shape.
        //! @param theShape    [in] input shape
        //! @param theToCreate [in] create and assign attribute if it doesn't exist
        //! @return Handle to the NamedData attribute or Null if there is none
        //!  Standard_Boolean theToCreate = Standard_False
        Handle(TDataStd_NamedData) GetNamedProperties(const TopoDS_Shape& theShape, Standard_Boolean theToCreate);

        //! DEFINE_STANDARD_RTTIEXT(XCAFDoc_ShapeTool, TDF_Attribute)
        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property Handle(Standard_Transient) IHandle {
            Handle(Standard_Transient) get() Standard_OVERRIDE {
                return NativeHandle();
            }
            void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
                //NativeHandle() = Handle(XCAFDoc_ShapeTool)::DownCast(handle);
                if (!handle.IsNull())
                    NativeHandle() = Handle(XCAFDoc_ShapeTool)::DownCast(handle);
                else if (!NativeHandle().IsNull())
                    NativeHandle() = NULL;
            }
        }
    private:
        NCollection_Haft<Handle(XCAFDoc_ShapeTool)> NativeHandle;
    };
}
#endif // _XXCAFDoc_ShapeTool_HeaderFile
