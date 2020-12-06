// Created on: 1993-10-14
// Created by: Remi LEQUETTE
// Copyright (c) 1993-1999 Matra Datavision
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

#ifndef _XBRepAlgoAPI_BooleanOperation_HeaderFile
#define _XBRepAlgoAPI_BooleanOperation_HeaderFile
#pragma once
#include <XStandard_Helper.h>
#include <BRepAlgoAPI_BooleanOperation.hxx>
#include <XBRepAlgoAPI_BuilderAlgo.h>
#include <XBOPAlgo_PaveFiller.h>
#include <XTopoDS_Shape.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <BOPAlgo_Operation.hxx>
#include <BRepAlgoAPI_BuilderAlgo.hxx>
class BRepAlgoAPI_BooleanOperation;
class BOPAlgo_PaveFiller;
class TopoDS_Shape;

//! The root API class for performing Boolean Operations on arbitrary shapes.
//!
//! The arguments of the operation are divided in two groups - *Objects* and *Tools*.
//! Each group can contain any number of shapes, but each shape should be valid
//! in terms of *BRepCheck_Analyzer* and *BOPAlgo_ArgumentAnalyzer*.
//! The algorithm builds the splits of the given arguments using the intersection
//! results and combines the result of Boolean Operation of given type:
//! - *FUSE* - union of two groups of objects;
//! - *COMMON* - intersection of two groups of objects;
//! - *CUT* - subtraction of one group from the other;
//! - *SECTION* - section edges and vertices of all arguments;
//!
//! The rules for the arguments and type of the operation are the following:
//! - For Boolean operation *FUSE* all arguments should have equal dimensions;
//! - For Boolean operation *CUT* the minimal dimension of *Tools* should not be
//!   less than the maximal dimension of *Objects*;
//! - For Boolean operation *COMMON* the arguments can have any dimension.
//! - For Boolean operation *SECTION* the arguments can be of any type.
//!
//! Additionally to the errors of the base class the algorithm returns
//! the following Errors:<br>
//! - *BOPAlgo_AlertBOPNotSet* - in case the type of Boolean Operation is not set.<br>
//! 
//! 
using namespace TKBRep;
namespace TKBO {
    ref class XBOPAlgo_PaveFiller;
    ref class TKBRep::XTopoDS_Shape;
    public ref class XBRepAlgoAPI_BooleanOperation : public XBRepAlgoAPI_BuilderAlgo
    {
    public:

         //! DEFINE_STANDARD_ALLOC

         //! @name Constructors

         //! Empty constructor
        XBRepAlgoAPI_BooleanOperation();

        //! Constructor with precomputed intersections of arguments.
        XBRepAlgoAPI_BooleanOperation(XBOPAlgo_PaveFiller^ thePF);

        XBRepAlgoAPI_BooleanOperation(BRepAlgoAPI_BooleanOperation* pos);

        void SetBooleanOperationHandle(BRepAlgoAPI_BooleanOperation* pos);

        virtual BRepAlgoAPI_BooleanOperation* GetBooleanOperation();

        virtual BRepAlgoAPI_BuilderAlgo* GetBuilderAlgo() Standard_OVERRIDE;

        //! @name Setting/getting arguments
        virtual XTopoDS_Shape^ Shape() Standard_OVERRIDE;

        //! Returns the first argument involved in this Boolean operation.
        //! Obsolete
        XTopoDS_Shape^ Shape1();

        //! Returns the second argument involved in this Boolean operation.
        //! Obsolete
        XTopoDS_Shape^ Shape2();

        //! Sets the Tool arguments
        void SetTools(XTopTools_ListOfShape^ theLS);

        //! Returns the Tools arguments
        XTopTools_ListOfShape^ Tools();


        //! @name Setting/Getting the type of Boolean operation

         //! Sets the type of Boolean operation
        void SetOperation(XBOPAlgo_Operation theBOP);

        //! Returns the type of Boolean Operation
        XBOPAlgo_Operation Operation();


        //! @name Performing the operation

      //! Performs the Boolean operation.
        virtual void Build() Standard_OVERRIDE;
        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property BRepAlgoAPI_BuilderAlgo* IHandle {
            BRepAlgoAPI_BuilderAlgo* get() Standard_OVERRIDE {
                return NativeHandle;
            }
            void set(BRepAlgoAPI_BuilderAlgo* handle)  Standard_OVERRIDE {
                NativeHandle = static_cast<BRepAlgoAPI_BooleanOperation*>(handle);
            }
        }

    private:
        BRepAlgoAPI_BooleanOperation* NativeHandle;
    };
}
#endif // _XBRepAlgoAPI_BooleanOperation_HeaderFile
