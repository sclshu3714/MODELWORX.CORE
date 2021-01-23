// Created on: 1995-03-23
// Created by: Jing Cheng MEI
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

#ifndef _XBRepBuilderAPI_Sewing_HeaderFile
#define _XBRepBuilderAPI_Sewing_HeaderFile
#pragma once
#include <BRepBuilderAPI_Sewing.hxx>
#include <XTopTools_ListOfShape.h>
#include <XTopoDS_Shape.h>
#include <XTopoDS_Edge.h>
#include <XTopoDS_Face.h>
#include <XGeom_Surface.h>
#include <XTopLoc_Location.h>
#include <XGeom2d_Curve.h>
#include <XGeom_Curve.h>
#include <NCollection_Haft.h>

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <Standard_Real.hxx>
#include <Standard_Boolean.hxx>
#include <TopTools_IndexedDataMapOfShapeShape.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <Standard_Integer.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopTools_MapOfShape.hxx>
#include <Standard_Transient.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <TColStd_IndexedMapOfInteger.hxx>
#include <TColStd_SequenceOfBoolean.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <TColStd_Array1OfBoolean.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColStd_SequenceOfReal.hxx>

#include <Message_ProgressIndicator.hxx>

class BRepTools_ReShape;
class Standard_OutOfRange;
class Standard_NoSuchObject;
class Message_ProgressIndicator;
class TopoDS_Shape;
class TopoDS_Edge;
class TopoDS_Face;
class Geom_Surface;
class TopLoc_Location;
class Geom2d_Curve;
class Geom_Curve;

class BRepBuilderAPI_Sewing;
//DEFINE_STANDARD_HANDLE(BRepBuilderAPI_Sewing, Standard_Transient)

using namespace TKBRep;
using namespace TKMath;
using namespace TKG3d;
using namespace TKG2d;
namespace TKTopAlgo {
    ref class TKBRep::XTopoDS_Shape;
    ref class TKBRep::XTopoDS_Edge;
    ref class TKBRep::XTopoDS_Face;
    ref class TKMath::XTopLoc_Location;
    ref class TKG3d::XGeom_Surface;
    ref class TKG3d::XGeom_Curve;
    ref class TKG2d::XGeom2d_Curve;
    ref class TKBRep::XTopTools_ListOfShape;
    //! Provides methods to
    //!
    //! - identify possible contigous boundaries (for control
    //! afterwards (of continuity: C0, C1, ...))
    //!
    //! - assemble contigous shapes into one shape.
    //! Only manifold shapes will be found. Sewing will not
    //! be done in case of multiple edges.
    //!
    //! For sewing, use this function as following:
    //! - create an empty object
    //! - default tolerance 1.E-06
    //! - with face analysis on
    //! - with sewing operation on
    //! - set the cutting option as you need (default True)
    //! - define a tolerance
    //! - add shapes to be sewed -> Add
    //! - compute -> Perfom
    //! - output the resulted shapes
    //! - output free edges if necessary
    //! - output multiple edges if necessary
    //! - output the problems if any
    public ref class XBRepBuilderAPI_Sewing //: public Standard_Transient
    {

    public:
        !XBRepBuilderAPI_Sewing() { IHandle = NULL; };
        ~XBRepBuilderAPI_Sewing() { IHandle = NULL; };

        XBRepBuilderAPI_Sewing();

        void SetSewingHandle(Handle(BRepBuilderAPI_Sewing) handle);

        virtual Handle(BRepBuilderAPI_Sewing) GetSewing();

        //! Creates an object with
        //! tolerance of connexity
        //! option for sewing (if false only control)
        //! option for analysis of degenerated shapes
        //! option for cutting of free edges.
        //! option for non manifold processing
        //! Standard_Real tolerance = 1.0e-06, Standard_Boolean option1 = Standard_True, Standard_Boolean option2 = Standard_True, Standard_Boolean option3 = Standard_True, Standard_Boolean option4 = Standard_False
        XBRepBuilderAPI_Sewing(Standard_Real tolerance, Standard_Boolean option1, Standard_Boolean option2, Standard_Boolean option3, Standard_Boolean option4);

        //! initialize the parameters if necessary
        //! Standard_Real tolerance = 1.0e-06, Standard_Boolean option1 = Standard_True, Standard_Boolean option2 = Standard_True, Standard_Boolean option3 = Standard_True, Standard_Boolean option4 = Standard_False
        void Init(Standard_Real tolerance, Standard_Boolean option1, Standard_Boolean option2, Standard_Boolean option3, Standard_Boolean option4);

        //! Loades the context shape.
        void Load(XTopoDS_Shape^ shape);

        //! Defines the shapes to be sewed or controlled
        void Add(XTopoDS_Shape^ shape);

        //! Computing
        //! thePI - progress indicator of algorithm
        //! thePI = 0
        void Perform(const Message_ProgressRange& thePI);

        //! Gives the sewed shape
        //! a null shape if nothingructed
        //! may be a face, a shell, a solid or a compound
        XTopoDS_Shape^ SewedShape();

        //! set context
        void SetContext(Handle(BRepTools_ReShape) theContext);

        //! return context
        Handle(BRepTools_ReShape) GetContext();

        //! Gives the number of free edges (edge shared by one face)
        Standard_Integer NbFreeEdges();

        //! Gives each free edge
        XTopoDS_Edge^ FreeEdge(Standard_Integer index);

        //! Gives the number of multiple edges
        //! (edge shared by more than two faces)
        Standard_Integer NbMultipleEdges();

        //! Gives each multiple edge
        XTopoDS_Edge^ MultipleEdge(Standard_Integer index);

        //! Gives the number of contigous edges (edge shared by two faces)
        Standard_Integer NbContigousEdges();

        //! Gives each contigous edge
        XTopoDS_Edge^ ContigousEdge(Standard_Integer index);

        //! Gives the sections (edge) belonging to a contigous edge
        XTopTools_ListOfShape^ ContigousEdgeCouple(Standard_Integer index);

        //! Indicates if a section is bound (before use SectionToBoundary)
        Standard_Boolean IsSectionBound(XTopoDS_Edge^ section);

        //! Gives the original edge (free boundary) which becomes the
        //! the section. Remember that sectionsitute  common edges.
        //! This imformation is important for control because with
        //! original edge we can find the surface to which the section
        //! is attached.
        XTopoDS_Edge^ SectionToBoundary(XTopoDS_Edge^ section);

        //! Gives the number of degenerated shapes
        Standard_Integer NbDegeneratedShapes();

        //! Gives each degenerated shape
        XTopoDS_Shape^ DegeneratedShape(Standard_Integer index);

        //! Indicates if a input shape is degenerated
        Standard_Boolean IsDegenerated(XTopoDS_Shape^ shape);

        //! Indicates if a input shape has been modified
        Standard_Boolean IsModified(XTopoDS_Shape^ shape);

        //! Gives a modifieded shape
        XTopoDS_Shape^ Modified(XTopoDS_Shape^ shape);

        //! Indicates if a input subshape has been modified
        Standard_Boolean IsModifiedSubShape(XTopoDS_Shape^ shape);

        //! Gives a modifieded subshape
        XTopoDS_Shape^ ModifiedSubShape(XTopoDS_Shape^ shape);

        //! print the informations
        void Dump();

        //! Gives the number of deleted faces (faces smallest than tolerance)
        Standard_Integer NbDeletedFaces();

        //! Gives each deleted face
        XTopoDS_Face^ DeletedFace(Standard_Integer index);

        //! Gives a modified shape
        //! Standard_Integer index = 1
        XTopoDS_Face^ WhichFace(XTopoDS_Edge^ theEdg, Standard_Integer index);

        //! Gets same parameter mode.
        Standard_Boolean SameParameterMode();

        //! Sets same parameter mode.
        void SetSameParameterMode(Standard_Boolean SameParameterMode);

        //! Gives set tolerance.
        Standard_Real Tolerance();

        //! Sets tolerance
        void SetTolerance(Standard_Real theToler);

        //! Gives set min tolerance.
        Standard_Real MinTolerance();

        //! Sets min tolerance
        void SetMinTolerance(Standard_Real theMinToler);

        //! Gives set max tolerance
        Standard_Real MaxTolerance();

        //! Sets max tolerance.
        void SetMaxTolerance(Standard_Real theMaxToler);

        //! Returns mode for sewing faces By default - true.
        Standard_Boolean FaceMode();

        //! Sets mode for sewing faces By default - true.
        void SetFaceMode(Standard_Boolean theFaceMode);

        //! Returns mode for sewing floating edges By default - false.
        Standard_Boolean FloatingEdgesMode();

        //! Sets mode for sewing floating edges By default - false.
        //! Returns mode for cutting floating edges By default - false.
        //! Sets mode for cutting floating edges By default - false.
        void SetFloatingEdgesMode(Standard_Boolean theFloatingEdgesMode);

        //! Returns mode for accounting of local tolerances
        //! of edges and vertices during of merging.
        Standard_Boolean LocalTolerancesMode();

        //! Sets mode for accounting of local tolerances
        //! of edges and vertices during of merging
        //! in this case WorkTolerance = myTolerance + tolEdge1+ tolEdg2;
        void SetLocalTolerancesMode(Standard_Boolean theLocalTolerancesMode);

        //! Sets mode for non-manifold sewing.
        void SetNonManifoldMode(Standard_Boolean theNonManifoldMode);

        //! Gets mode for non-manifold sewing.
        //!
        //! INTERNAL FUCTIONS ---
        Standard_Boolean NonManifoldMode();

        //DEFINE_STANDARD_RTTIEXT(BRepBuilderAPI_Sewing,Standard_Transient)
        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property Handle(BRepBuilderAPI_Sewing) IHandle {
            Handle(BRepBuilderAPI_Sewing) get() { //Standard_OVERRIDE {
                return NativeHandle();
            }
            void set(Handle(BRepBuilderAPI_Sewing) handle) { //Standard_OVERRIDE {
                NativeHandle() = handle;
            }
        }

    private:
        NCollection_Haft<Handle(BRepBuilderAPI_Sewing)> NativeHandle;
    };
}
#endif // _XBRepBuilderAPI_Sewing_HeaderFile
