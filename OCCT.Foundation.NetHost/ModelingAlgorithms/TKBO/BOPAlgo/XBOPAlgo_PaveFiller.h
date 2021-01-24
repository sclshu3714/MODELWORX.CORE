// Created by: Peter KURNEV
// Copyright (c) 2010-2014 OPEN CASCADE SAS
// Copyright (c) 2007-2010 CEA/DEN, EDF R&D, OPEN CASCADE
// Copyright (c) 2003-2007 OPEN CASCADE, EADS/CCR, LIP6, CEA/DEN, CEDRAT,
//                         EDF R&D, LEG, PRINCIPIA R&D, BUREAU VERITAS
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

#ifndef _XBOPAlgo_PaveFiller_HeaderFile
#define _XBOPAlgo_PaveFiller_HeaderFile
#pragma once
#include <BOPAlgo_PaveFiller.hxx>
#include <XTopTools_ListOfShape.h>
#include <XBOPAlgo_GlueEnum.h>
#include <BOPDS_Iterator.hxx>
#include <xgp_Pnt.h>
#include <XTopoDS_Vertex.h>
#include <XTopoDS_Edge.h>
#include <XTopoDS_Face.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <BOPAlgo_Algo.hxx>
#include <BOPAlgo_GlueEnum.hxx>
#include <BOPAlgo_SectionAttribute.hxx>
#include <BOPDS_DataMapOfPaveBlockListOfPaveBlock.hxx>
#include <BOPDS_IndexedDataMapOfPaveBlockListOfInteger.hxx>
#include <BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.hxx>
#include <BOPDS_IndexedMapOfPaveBlock.hxx>
#include <BOPDS_ListOfPaveBlock.hxx>
#include <BOPDS_MapOfPair.hxx>
#include <BOPDS_MapOfPaveBlock.hxx>
#include <BOPDS_PDS.hxx>
#include <BOPDS_DS.hxx>
#include <BOPDS_PIterator.hxx>
#include <BOPDS_VectorOfCurve.hxx>
#include <IntSurf_ListOfPntOn2S.hxx>
#include <IntTools_ShrunkRange.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_Integer.hxx>
#include <Standard_Real.hxx>
#include <TColStd_DataMapOfIntegerInteger.hxx>
#include <TColStd_DataMapOfIntegerListOfInteger.hxx>
#include <TColStd_DataMapOfIntegerReal.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <TColStd_MapOfInteger.hxx>
#include <TopTools_DataMapOfShapeInteger.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <TopTools_IndexedMapOfShape.hxx>


//class IntTools_Context;
class BOPDS_DS;
class BOPAlgo_Algo;
class BOPAlgo_PaveFiller;
class BOPAlgo_SectionAttribute;
class BOPDS_PaveBlock;
class BOPDS_CommonBlock;
class BOPDS_Iterator;
class BOPDS_Curve;
class gp_Pnt;
class TopoDS_Vertex;
class TopoDS_Edge;
class TopoDS_Face;
class BOPAlgo_PaveFiller;
//!
//! The class represents the Intersection phase of the
//! Boolean Operations algorithm.<br>
//! It performs the pairwise intersection of the sub-shapes of
//! the arguments in the following order:<br>
//! 1. Vertex/Vertex;<br>
//! 2. Vertex/Edge;<br>
//! 3. Edge/Edge;<br>
//! 4. Vertex/Face;<br>
//! 5. Edge/Face;<br>
//! 6. Face/Face.<br>
//!
//! The results of intersection are stored into the Data Structure
//! of the algorithm.<br>
//!
//! Additionally to the options provided by the parent class,
//! the algorithm has the following options:<br>
//! - *Section attributes* - allows to customize the intersection of the faces
//!                          (avoid approximation or building 2d curves);<br>
//! - *Safe processing mode* - allows to avoid modification of the input
//!                            shapes during the operation (by default it is off);<br>
//! - *Gluing options* - allows to speed up the calculation on the special
//!                      cases, in which some sub-shapes are coincide.<br>
//!
//! The algorithm returns the following Warning statuses:
//! - *BOPAlgo_AlertSelfInterferingShape* - in case some of the argument shapes are self-interfering shapes;
//! - *BOPAlgo_AlertTooSmallEdge* - in case some edges of the input shapes have no valid range;
//! - *BOPAlgo_AlertNotSplittableEdge* - in case some edges of the input shapes has such a small
//!                                      valid range so it cannot be split;
//! - *BOPAlgo_AlertBadPositioning* - in case the positioning of the input shapes leads to creation
//!                                   of small edges;
//! - *BOPAlgo_AlertIntersectionOfPairOfShapesFailed* - in case intersection of some of the
//!                                                     sub-shapes has failed;
//! - *BOPAlgo_AlertAcquiredSelfIntersection* - in case some sub-shapes of the argument become connected
//!                                             through other shapes;
//! - *BOPAlgo_AlertBuildingPCurveFailed* - in case building 2D curve for some of the edges
//!                                         on the faces has failed.
//!
//! The algorithm returns the following Error alerts:
//! - *BOPAlgo_AlertTooFewArguments* - in case there are no enough arguments to
//!                      perform the operation;<br>
//! - *BOPAlgo_AlertIntersectionFailed* - in case some unexpected error occurred;<br>
//! - *BOPAlgo_AlertNullInputShapes* - in case some of the arguments are null shapes.<br>
//!
//! 
using namespace TKBRep;
using namespace TKMath;
namespace TKBO {
    ref class TKMath::xgp_Pnt;
    ref class TKBRep::XTopoDS_Vertex;
    ref class TKBRep::XTopoDS_Edge;
    ref class TKBRep::XTopoDS_Face;
    public ref class XBOPAlgo_PaveFiller //: public BOPAlgo_Algo
    {
    public:

        //! DEFINE_STANDARD_ALLOC
        !XBOPAlgo_PaveFiller() { IHandle = NULL; };

        XBOPAlgo_PaveFiller();

        virtual ~XBOPAlgo_PaveFiller();

        XBOPAlgo_PaveFiller(Handle(NCollection_BaseAllocator) theAllocator);

        XBOPAlgo_PaveFiller(BOPAlgo_PaveFiller* pos);

        void SetPaveFillerHandle(BOPAlgo_PaveFiller* pos);

        BOPAlgo_PaveFiller* GetPaveFiller();

        const BOPDS_DS& DS();

        BOPDS_PDS PDS();

        /*const BOPDS_PIterator& Iterator();*/

        //! Sets the arguments for operation
        void SetArguments(XTopTools_ListOfShape^ theLS);

        //! Adds the argument for operation
        void AddArgument(XTopoDS_Shape^ theShape);

        //! Returns the list of arguments
        XTopTools_ListOfShape^ Arguments();

        Handle(IntTools_Context) Context();

        void SetSectionAttribute(BOPAlgo_SectionAttribute theSecAttr);

        //! Sets the flag that defines the mode of treatment.
        //! In non-destructive mode the argument shapes are not modified. Instead
        //! a copy of a sub-shape is created in the result if it is needed to be updated.
        void SetNonDestructive(Standard_Boolean theFlag);

        //! Returns the flag that defines the mode of treatment.
        //! In non-destructive mode the argument shapes are not modified. Instead
        //! a copy of a sub-shape is created in the result if it is needed to be updated.
        Standard_Boolean NonDestructive();

        virtual void Perform();// Standard_OVERRIDE;

        //! Sets the glue option for the algorithm
        void SetGlue(XBOPAlgo_GlueEnum theGlue);

        //! Returns the glue option of the algorithm
        XBOPAlgo_GlueEnum Glue();

        //! Sets the flag to avoid building of p-curves of edges on faces
        void SetAvoidBuildPCurve(Standard_Boolean theValue);

        //! Returns the flag to avoid building of p-curves of edges on faces
        Standard_Boolean IsAvoidBuildPCurve();
        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property BOPAlgo_PaveFiller* IHandle {
            BOPAlgo_PaveFiller* get() {// Standard_OVERRIDE {
                return NativeHandle;
            }
            void set(BOPAlgo_PaveFiller* handle) {// Standard_OVERRIDE {
               // NativeHandle = static_cast<BOPAlgo_PaveFiller*>(handle);
                if (handle == NULL)
                    NativeHandle = static_cast<BOPAlgo_PaveFiller*>(handle);
                else
                    NativeHandle = NULL;
            }
        }

    private:
        BOPAlgo_PaveFiller* NativeHandle;
    };
}
#endif // _XBOPAlgo_PaveFiller_HeaderFile
