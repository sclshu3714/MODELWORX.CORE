// Created by: Peter KURNEV
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

#ifndef _XBRepAlgoAPI_BuilderAlgo_HeaderFile
#define _XBRepAlgoAPI_BuilderAlgo_HeaderFile
#pragma once
#include <XStandard_Helper.h>
#include <BRepAlgoAPI_BuilderAlgo.hxx>
#include <XTopTools_ListOfShape.h>
#include <XBOPAlgo_GlueEnum.h>
#include <XBOPAlgo_PaveFiller.h>
#include <XBOPAlgo_Builder.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_Real.hxx>


#include <BOPAlgo_PPaveFiller.hxx>
#include <BOPAlgo_PBuilder.hxx>
#include <BRepAlgoAPI_Algo.hxx>
#include <BRepTools_History.hxx>
#include <Precision.hxx>

//! The class contains API level of the General Fuse algorithm.<br>
//!
//! Additionally to the options defined in the base class, the algorithm has
//! the following options:<br>
//! - *Safe processing mode* - allows to avoid modification of the input
//!                            shapes during the operation (by default it is off);
//! - *Gluing options* - allows to speed up the calculation of the intersections
//!                      on the special cases, in which some sub-shapes are coinciding.
//! - *Disabling the check for inverted solids* - Disables/Enables the check of the input solids
//!                          for inverted status (holes in the space). The default value is TRUE,
//!                          i.e. the check is performed. Setting this flag to FALSE for inverted solids,
//!                          most likely will lead to incorrect results.
//! - *Disabling history collection* - allows disabling the collection of the history
//!                                    of shapes modifications during the operation.
//!
//! It returns the following Error statuses:<br>
//! - 0 - in case of success;<br>
//! - *BOPAlgo_AlertTooFewArguments* - in case there are no enough arguments to perform the operation;<br>
//! - *BOPAlgo_AlertIntersectionFailed* - in case the intersection of the arguments has failed;<br>
//! - *BOPAlgo_AlertBuilderFailed* - in case building of the result shape has failed.<br>
//!
//! Warnings statuses from underlying DS Filler and Builder algorithms
//! are collected in the report.
//!
//! The class provides possibility to simplify the resulting shape by unification
//! of the tangential edges and faces. It is performed by the method *SimplifyResult*.
//! See description of this method for more details.
//!

namespace TKBO {
    public ref class XBRepAlgoAPI_BuilderAlgo //: public BRepAlgoAPI_Algo
    {
    public:

        //! DEFINE_STANDARD_ALLOC
        //! @name Constructors

        //! Empty constructor
        XBRepAlgoAPI_BuilderAlgo();
        virtual ~XBRepAlgoAPI_BuilderAlgo();

        //! Constructor with prepared Filler object
        XBRepAlgoAPI_BuilderAlgo(XBOPAlgo_PaveFiller^ thePF);

        XBRepAlgoAPI_BuilderAlgo(BRepAlgoAPI_BuilderAlgo* pos);

        void SetBuilderAlgoHandle(BRepAlgoAPI_BuilderAlgo* pos);

        virtual BRepAlgoAPI_BuilderAlgo* GetBuilderAlgo();

        //! @name Setting/getting arguments
        virtual XTopoDS_Shape^ Shape();// Standard_OVERRIDE;

        //! @name Setting/Getting data for the algorithm

        //! Sets the arguments
        void SetArguments(XTopTools_ListOfShape^ theLS);

        //! Gets the arguments
        XTopTools_ListOfShape^ Arguments();


        //! @name Setting options

        //! Sets the flag that defines the mode of treatment.
        //! In non-destructive mode the argument shapes are not modified. Instead
        //! a copy of a sub-shape is created in the result if it is needed to be updated.
        void SetNonDestructive(Standard_Boolean theFlag);

        //! Returns the flag that defines the mode of treatment.
        //! In non-destructive mode the argument shapes are not modified. Instead
        //! a copy of a sub-shape is created in the result if it is needed to be updated.
        Standard_Boolean NonDestructive();

        //! Sets the glue option for the algorithm,
        //! which allows increasing performance of the intersection
        //! of the input shapes.
        void SetGlue(XBOPAlgo_GlueEnum theGlue);

        //! Returns the glue option of the algorithm
        XBOPAlgo_GlueEnum Glue();

        //! Enables/Disables the check of the input solids for inverted status
        void SetCheckInverted(Standard_Boolean theCheck);

        //! Returns the flag defining whether the check for input solids on inverted status
        //! should be performed or not.
        Standard_Boolean CheckInverted();


        //! @name Performing the operation

        //! Performs the algorithm
        virtual void Build();// Standard_OVERRIDE;


        //! @name Result simplification

        //! Simplification of the result shape is performed by the means of
        //! *ShapeUpgrade_UnifySameDomain* algorithm. The result of the operation will
        //! be overwritten with the simplified result.
        //!
        //! The simplification is performed without creation of the Internal shapes,
        //! i.e. shapes connections will never be broken.
        //!
        //! Simplification is performed on the whole result shape. Thus, if the input
        //! shapes contained connected tangent edges or faces unmodified during the operation
        //! they will also be unified.
        //!
        //! After simplification, the History of result simplification is merged into the main
        //! history of operation. So, it is taken into account when asking for Modified,
        //! Generated and Deleted shapes.
        //!
        //! Some options of the main operation are passed into the Unifier:
        //! - Fuzzy tolerance of the operation is given to the Unifier as the linear tolerance.
        //! - Non destructive mode here controls the safe input mode in Unifier.
        //!
        //! @param theUnifyEdges Controls the edges unification. TRUE by default.
        //! @param theUnifyFaces Controls the faces unification. TRUE by default.
        //! @param theAngularTol Angular criteria for tangency of edges and faces.
        //!                      Precision::Angular() by default.
        //!Standard_Boolean theUnifyEdges = Standard_True,Standard_Boolean theUnifyFaces = Standard_True,Standard_Real    theAngularTol = Precision::Angular()
        void SimplifyResult(Standard_Boolean theUnifyEdges, Standard_Boolean theUnifyFaces, Standard_Real theAngularTol);


        //! @name History support

        //! Returns the shapes modified from the shape <theS>.
        //! If any, the list will contain only those splits of the
        //! given shape, contained in the result.
        virtual XTopTools_ListOfShape^ Modified(XTopoDS_Shape^ theS);// Standard_OVERRIDE;

        //! Returns the list  of shapes generated from the shape <theS>.
        //! In frames of Boolean Operations algorithms only Edges and Faces
        //! could have Generated elements, as only they produce new elements
        //! during intersection:
        //! - Edges can generate new vertices;
        //! - Faces can generate new edges and vertices.
        virtual XTopTools_ListOfShape^ Generated(XTopoDS_Shape^ theS);// Standard_OVERRIDE;

        //! Checks if the shape <theS> has been completely removed from the result,
        //! i.e. the result does not contain the shape itself and any of its splits.
        //! Returns TRUE if the shape has been deleted.
        virtual Standard_Boolean IsDeleted(XTopoDS_Shape^ aS);//Standard_OVERRIDE;

        //! Returns true if any of the input shapes has been modified during operation.
        virtual Standard_Boolean HasModified();

        //! Returns true if any of the input shapes has generated shapes during operation.
        virtual Standard_Boolean HasGenerated();

        //! Returns true if any of the input shapes has been deleted during operation.
        //! Normally, General Fuse operation should not have Deleted elements,
        //! but all derived operation can have.
        virtual Standard_Boolean HasDeleted();


        //! @name Enabling/Disabling the history collection.

        //! Allows disabling the history collection
        void SetToFillHistory(Standard_Boolean theHistFlag);

        //! Returns flag of history availability
        Standard_Boolean HasHistory();


        //! @name Getting the section edges

        //! Returns a list of section edges.
        //! The edges represent the result of intersection between arguments of operation.
        XTopTools_ListOfShape^ SectionEdges();


        //! @name Getting tools performing the job

        //! Returns the Intersection tool
        XBOPAlgo_PaveFiller^ DSFiller();

        //! Returns the Building tool
        XBOPAlgo_Builder^ Builder();

        //! History tool
        Handle(BRepTools_History) History();

        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property BRepAlgoAPI_BuilderAlgo* IHandle {
            BRepAlgoAPI_BuilderAlgo* get() {// Standard_OVERRIDE {
                return NativeHandle;
            }
            void set(BRepAlgoAPI_BuilderAlgo* handle) {// Standard_OVERRIDE {
                NativeHandle = static_cast<BRepAlgoAPI_BuilderAlgo*>(handle);
            }
        }

    private:
        BRepAlgoAPI_BuilderAlgo* NativeHandle;
    };
}
#endif // _XBRepAlgoAPI_BuilderAlgo_HeaderFile
