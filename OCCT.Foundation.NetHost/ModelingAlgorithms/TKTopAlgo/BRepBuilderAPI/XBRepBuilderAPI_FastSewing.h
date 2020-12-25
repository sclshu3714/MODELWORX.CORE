//! Created on: 2015-04-24
//! Created by: NIKOLAI BUKHALOV
//! Copyright (c) 2015 OPEN CASCADE SAS
//!
//! This file is part of Open CASCADE Technology software library.
//!
//! This library is free software; you can redistribute it and/or modify it under
//! the terms of the GNU Lesser General Public License version 2.1 as published
//! by the Free Software Foundation, with special exception defined in the file
//! OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
//! distribution for complete text of the license and disclaimer of any warranty.
//!
//! Alternatively, this file may be used under the terms of Open CASCADE
//! commercial license or contractual agreement.

#ifndef _XBRepBuilderAPI_FastSewing_HeaderFile
#define _XBRepBuilderAPI_FastSewing_HeaderFile
#pragma once
#include <BRepBuilderAPI_FastSewing.hxx>
#include <XTopoDS_Edge.h>
#include <XTopoDS_Face.h>
#include <XTopoDS_Vertex.h>
#include <XTopoDS_Wire.h>
#include <XGeom_Surface.h>

#include <Standard_Transient.hxx>
#include <BRep_Builder.hxx>

#include <NCollection_List.hxx>
#include <NCollection_Sequence.hxx>
#include <NCollection_Vector.hxx>
#include <NCollection_CellFilter.hxx>

#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Wire.hxx>

//! Enumeration of result statuses
//ATTENTION!!! If you add new status, please
//    describe it in GetStatuses() method
public enum class XFS_Statuses
{
    FS_OK = 0x00000000,
    FS_Degenerated = 0x00000001,
    FS_FindVertexError = 0x00000002,
    FS_FindEdgeError = 0x00000004,
    FS_FaceWithNullSurface = 0x00000008,
    FS_NotNaturalBoundsFace = 0x00000010,
    FS_InfiniteSurface = 0x00000020,
    FS_EmptyInput = 0x00000040,
    FS_Exception = 0x00000080
};

using namespace TKBRep;
using namespace TKG3d;
namespace TKTopAlgo {
    ref class TKBRep::XTopoDS_Edge;
    ref class TKBRep::XTopoDS_Face;
    ref class TKBRep::XTopoDS_Vertex;
    ref class TKBRep::XTopoDS_Wire;
    ref class TKG3d::XGeom_Surface;
    //! This class performs fast sewing of surfaces (faces). It supposes
    //! that all surfaces are finite and are naturally restricted by their bounds.
    //! Moreover, it supposes that stitched together surfaces have the same parameterization
    //! along common boundaries, therefore it does not perform time-consuming check for
    //! SameParameter property of edges.
    //!
    //! For sewing, use this function as following:
    //! - set tolerance value (default tolerance is 1.E-06)
    //! - add all necessary surfaces (faces)
    //! - check status if adding is correctly completed.
    //! - compute -> Perform
    //! - retrieve the error status if any
    //! - retrieve the resulted shape
    public ref class XBRepBuilderAPI_FastSewing //: public Standard_Transient
    {
    public:

        XBRepBuilderAPI_FastSewing();

        XBRepBuilderAPI_FastSewing(Handle(BRepBuilderAPI_FastSewing) handle);

        void SetFastSewingHandle(Handle(BRepBuilderAPI_FastSewing) handle);

        virtual Handle(BRepBuilderAPI_FastSewing) GetFastSewing();

        //! Creates an object with tolerance of connexity
        //! const Standard_Real theTolerance = 1.0e-06
        XBRepBuilderAPI_FastSewing(Standard_Real theTolerance);

        //! Adds faces of a shape
        Standard_Boolean Add(XTopoDS_Shape^ theShape);

        //! Adds a surface
        Standard_Boolean Add(XGeom_Surface^ theSurface);

        //! Compute resulted shape
        void Perform(void);

        //! Sets tolerance
        void SetTolerance(Standard_Real theToler);

        //! Returns tolerance
        Standard_Real GetTolerance();

        //! Returns resulted shape
        XTopoDS_Shape^ GetResult();

        //! Returns list of statuses. Print message if theOS != 0
        //! Standard_OStream* const theOS = 0
        XFS_Statuses GetStatuses(Standard_OStream theOS);

        /// <summary>
       /// ±¾µØ¾ä±ú
       /// </summary>
        virtual property Handle(BRepBuilderAPI_FastSewing) IHandle {
            Handle(BRepBuilderAPI_FastSewing) get() { //Standard_OVERRIDE {
                return NativeHandle();
            }
            void set(Handle(BRepBuilderAPI_FastSewing) handle) { //Standard_OVERRIDE {
                NativeHandle() = handle;
            }
        }

    private:
        NCollection_Haft<Handle(BRepBuilderAPI_FastSewing)> NativeHandle;
    };
}
#endif // _XBRepBuilderAPI_FastSewing_HeaderFile
