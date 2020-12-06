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

#ifndef _XBOPAlgo_Builder_HeaderFile
#define _XBOPAlgo_Builder_HeaderFile
#pragma once
#include <XStandard_Helper.h>
#include <BOPAlgo_Builder.hxx>
#include <XBOPAlgo_PaveFiller.h>
#include <XBOPAlgo_Operation.h>
#include <XTopoDS_Solid.h>
#include <XTopoDS_Shape.h>
//
//#include <Standard.hxx>
//#include <Standard_DefineAlloc.hxx>
//#include <Standard_Handle.hxx>

//#include <BOPAlgo_PPaveFiller.hxx>
//#include <BOPAlgo_BuilderShape.hxx>
//#include <BOPAlgo_GlueEnum.hxx>
//#include <BOPAlgo_Operation.hxx>
//#include <BOPDS_PDS.hxx>
//#include <NCollection_BaseAllocator.hxx>
//#include <Standard_Integer.hxx>
//#include <Standard_Real.hxx>
//#include <TopTools_DataMapOfShapeListOfShape.hxx>
//#include <TopTools_DataMapOfShapeShape.hxx>
//#include <TopTools_ListOfShape.hxx>
//#include <TopTools_MapOfShape.hxx>
//#include <Standard_Boolean.hxx>
//#include <TopAbs_ShapeEnum.hxx>
//class IntTools_Context;
//class TopoDS_Shape;
//class BOPAlgo_PaveFiller;
//class TopoDS_Solid;

//!
//! The class is a General Fuse algorithm - base algorithm for the
//! algorithms in the Boolean Component. Its main purpose is to build
//! the split parts of the argument shapes from which the result of
//! the operations is combined.<br>
//! The result of the General Fuse algorithm itself is a compound
//! containing all split parts of the arguments. <br>
//!
//! Additionally to the options of the base classes, the algorithm has
//! the following options:<br>
//! - *Safe processing mode* - allows to avoid modification of the input
//!                            shapes during the operation (by default it is off);<br>
//! - *Gluing options* - allows to speed up the calculation of the intersections
//!                      on the special cases, in which some sub-shapes are coinciding.<br>
//! - *Disabling the check for inverted solids* - Disables/Enables the check of the input solids
//!                          for inverted status (holes in the space). The default value is TRUE,
//!                          i.e. the check is performed. Setting this flag to FALSE for inverted solids,
//!                          most likely will lead to incorrect results.
//!
//! The algorithm returns the following warnings:
//! - *BOPAlgo_AlertUnableToOrientTheShape* - in case the check on the orientation of the split shape
//!                                           to match the orientation of the original shape has failed.
//!
//! The algorithm returns the following Error statuses:
//! - *BOPAlgo_AlertTooFewArguments* - in case there are no enough arguments to perform the operation;
//! - *BOPAlgo_AlertNoFiller* - in case the intersection tool has not been created;
//! - *BOPAlgo_AlertIntersectionFailed* - in case the intersection of the arguments has failed;
//! - *BOPAlgo_AlertBuilderFailed* - in case building splits of arguments has failed with some unexpected error.
//!
//! 
using namespace TKBRep;
namespace TKBO {
    ref class TKBRep::XTopoDS_Shape;
    ref class XBOPAlgo_PaveFiller;
    ref class TKBRep::XTopoDS_Solid;
    public ref class XBOPAlgo_Builder //: public BOPAlgo_BuilderShape
    {
    public:

        //! DEFINE_STANDARD_ALLOC

        //! Empty constructor.
        XBOPAlgo_Builder();
        virtual ~XBOPAlgo_Builder();

        XBOPAlgo_Builder(Handle(NCollection_BaseAllocator)& theAllocator);

        XBOPAlgo_Builder(BOPAlgo_Builder* pos);

        void SetAlgoBuilderHandle(BOPAlgo_Builder* pos);

        BOPAlgo_Builder* GetAlgoBuilder();

        //! Clears the content of the algorithm.
        virtual void Clear();// Standard_OVERRIDE;

        ////! Returns the PaveFiller, algorithm for sub-shapes intersection.
        //XBOPAlgo_PaveFiller^ PPaveFiller();

        //! Returns the Data Structure, holder of intersection information.
        BOPDS_PDS PDS();

        //! Returns the Context, tool for cashing heavy algorithms.
        Handle(IntTools_Context) Context();

        //! @name Arguments

        //! Adds the argument to the operation.
        virtual void AddArgument(XTopoDS_Shape^ theShape);

        //! Sets the list of arguments for the operation.
        virtual void SetArguments(XTopTools_ListOfShape^ theLS);

        //! Returns the list of arguments.
        XTopTools_ListOfShape^ Arguments();
        //! @name Options

        //! Sets the flag that defines the mode of treatment.
        //! In non-destructive mode the argument shapes are not modified. Instead
        //! a copy of a sub-shape is created in the result if it is needed to be updated.
        //! This flag is taken into account if internal PaveFiller is used only.
        //! In the case of calling PerformWithFiller the corresponding flag of that PaveFiller
        //! is in force.
        void SetNonDestructive(Standard_Boolean theFlag);

        //! Returns the flag that defines the mode of treatment.
        //! In non-destructive mode the argument shapes are not modified. Instead
        //! a copy of a sub-shape is created in the result if it is needed to be updated.
        Standard_Boolean NonDestructive();

        //! Sets the glue option for the algorithm
        void SetGlue(XBOPAlgo_GlueEnum theGlue);

        //! Returns the glue option of the algorithm
        XBOPAlgo_GlueEnum Glue();

        //! Enables/Disables the check of the input solids for inverted status
        void SetCheckInverted(Standard_Boolean theCheck);

        //! Returns the flag defining whether the check for input solids on inverted status
        //! should be performed or not.
        Standard_Boolean CheckInverted();


        //! @name Performing the operation

        //! Performs the operation.
        //! The intersection will be performed also.
        virtual void Perform(); //Standard_OVERRIDE;

        //! Performs the operation with the prepared filler.
        //! The intersection will not be performed in this case.
        virtual void PerformWithFiller(XBOPAlgo_PaveFiller^ theFiller);


        //! @name BOPs on open solids

        //! Builds the result shape according to the given states for the objects
        //! and tools. These states can be unambiguously converted into the Boolean operation type.
        //! Thus, it performs the Boolean operation on the given groups of shapes.
        //!
        //! The result is built basing on the result of Builder operation (GF or any other).
        //! The only condition for the Builder is that the splits of faces should be created
        //! and classified relatively solids.
        //!
          //! The method uses classification approach for choosing the faces which will
          //! participate in building the result shape:
          //! - All faces from each group having the given state for the opposite group
          //!   will be taken into result.
          //!
          //! Such approach shows better results (in comparison with BOPAlgo_BuilderSolid approach)
          //! when working with open solids. However, the result may not be always
          //! correct on such data (at least, not as expected) as the correct classification
          //! of the faces relatively open solids is not always possible and may vary
          //! depending on the chosen classification point on the face.
          //!
          //! History is not created for the solids in this method.
          //!
          //! To avoid pollution of the report of Builder algorithm, there is a possibility to pass
          //! the different report to collect the alerts of the method only. But, if the new report
          //! is not given, the Builder report will be used.
          //! So, even if Builder passed without any errors, but some error has been stored into its report
          //! in this method, for the following calls the Builder report must be cleared.
          //!
          //! The method may set the following errors:
          //! - BOPAlgo_AlertBuilderFailed - Building operation has not been performed yet or failed;
          //! - BOPAlgo_AlertBOPNotSet - invalid BOP type is given (COMMON/FUSE/CUT/CUT21 are supported);
          //! - BOPAlgo_AlertTooFewArguments - arguments are not given;
          //! - BOPAlgo_AlertUnknownShape - the shape is unknown for the operation.
          //!
          //! Parameters:
          //! @param theObjects   - The group of Objects for BOP;
          //! @param theObjState  - State for objects faces to pass into result;
          //! @param theTools     - The group of Tools for BOP;
          //! @param theObjState  - State for tools faces to pass into result;
          //! @param theReport    - The alternative report to avoid pollution of the main one.
          //! Handle(Message_Report)      theReport = NULL
        virtual void BuildBOP(XTopTools_ListOfShape^ theObjects, XTopAbs_State theObjState, XTopTools_ListOfShape^ theTools, XTopAbs_State theToolsState, Handle(Message_Report) theReport);

        //! Builds the result of Boolean operation of given type
        //! basing on the result of Builder operation (GF or any other).
        //!
        //! The method converts the given type of operation into the states
        //! for the objects and tools required for their face to pass into result
        //! and performs the call to the same method, but with states instead
        //! of operation type.
        //!
        //! The conversion looks as follows:
        //! - COMMON is built from the faces of objects located IN any of the tools
        //!          and vice versa.
        //! - FUSE   is built from the faces OUT of all given shapes;
        //! - CUT    is built from the faces of the objects OUT of the tools and
        //!          faces of the tools located IN solids of the objects.
        //!
        //! @param theObjects   - The group of Objects for BOP;
        //! @param theTools     - The group of Tools for BOP;
        //! @param theOperation - The BOP type;
        //! @param theReport    - The alternative report to avoid pollution of the global one.
        //! Handle(Message_Report)      theReport = NULL
        void BuildBOP(XTopTools_ListOfShape^ theObjects, XTopTools_ListOfShape^ theTools, XBOPAlgo_Operation theOperation, Handle(Message_Report) theReport);
        
        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property BOPAlgo_Builder* IHandle {
            BOPAlgo_Builder* get() {// Standard_OVERRIDE {
                return NativeHandle;
            }
            void set(BOPAlgo_Builder* handle) {// Standard_OVERRIDE {
                NativeHandle = static_cast<BOPAlgo_Builder*>(handle);
            }
        }

    private:
        BOPAlgo_Builder* NativeHandle;
    };
}
#endif // _XBOPAlgo_Builder_HeaderFile
