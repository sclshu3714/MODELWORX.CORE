// Created by: Eugeny MALTCHIKOV
// Copyright (c) 2017 OPEN CASCADE SAS
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

#ifndef _xBOPAlgo_Options_HeaderFile
#define _XBOPAlgo_Options_HeaderFile
#pragma once
#include <BOPAlgo_Options.hxx>

#include <Message_Report.hxx>
#include <Standard_OStream.hxx>

#include <NCollection_BaseAllocator.hxx>

class Message_ProgressIndicator;
class BOPAlgo_Options;

//! The class provides the following options for the algorithms in Boolean Component:
//! - *Memory allocation tool* - tool for memory allocations;
//! - *Error and warning reporting* - allows recording warnings and errors occurred 
//!                              during the operation.
//!                              Error means that the algorithm has failed.
//! - *Parallel processing mode* - provides the possibility to perform operation in parallel mode;
//! - *Fuzzy tolerance* - additional tolerance for the operation to detect
//!                       touching or coinciding cases;
//! - *Progress indicator* - provides interface to track the progress of
//!                          operation and stop the operation by user's break.
//! - *Using the Oriented Bounding Boxes* - Allows using the Oriented Bounding Boxes of the shapes
//!                          for filtering the intersections.
//!
//! 
namespace TKBO {
    public ref class XBOPAlgo_Options
    {
    public:

        //! DEFINE_STANDARD_ALLOC

        //! Empty constructor
        XBOPAlgo_Options();

        //! Constructor with allocator
        XBOPAlgo_Options(const Handle(NCollection_BaseAllocator)& theAllocator);

        void SetAlgoOptionsHandle(BOPAlgo_Options* pos);

        BOPAlgo_Options* GetOptions();

        //! Destructor
        virtual ~XBOPAlgo_Options();

        //! Returns allocator
        const Handle(NCollection_BaseAllocator)& Allocator();

        //! Clears all warnings and errors, and any data cached by the algorithm.
        //! User defined options are not cleared.
        virtual void Clear();

        //!@name Error reporting mechanism

        //! Adds the alert as error (fail)
        void AddError(const Handle(Message_Alert)& theAlert);

        //! Adds the alert as warning
        void AddWarning(const Handle(Message_Alert)& theAlert);

        //! Returns true if algorithm has failed
        Standard_Boolean HasErrors();

        //! Returns true if algorithm has generated error of specified type
        Standard_Boolean HasError(const Handle(Standard_Type)& theType);

        //! Returns true if algorithm has generated some warning alerts
        Standard_Boolean HasWarnings();

        //! Returns true if algorithm has generated warning of specified type
        Standard_Boolean HasWarning(const Handle(Standard_Type)& theType);

        //! Returns report collecting all errors and warnings
        const Handle(Message_Report)& GetReport();

        //! Dumps the error status into the given stream
        void DumpErrors(Standard_OStream& theOS);

        //! Dumps the warning statuses into the given stream
        void DumpWarnings(Standard_OStream& theOS);

        //! Clears the warnings of the algorithm
        void ClearWarnings();

        //!@name Parallel processing mode

        //! Gets the global parallel mode
        static Standard_Boolean GetParallelMode();

        //! Sets the global parallel mode
        static void SetParallelMode(Standard_Boolean theNewMode);

        //! Set the flag of parallel processing
        //! if <theFlag> is true  the parallel processing is switched on
        //! if <theFlag> is false the parallel processing is switched off
        void SetRunParallel(Standard_Boolean theFlag);

        //! Returns the flag of parallel processing
        Standard_Boolean RunParallel();

        //!@name Fuzzy tolerance

        //! Sets the additional tolerance
        void SetFuzzyValue(Standard_Real theFuzz);

        //! Returns the additional tolerance
        Standard_Real FuzzyValue();
        //!@name Progress indicator

        //! Set the Progress Indicator object.
        void SetProgressIndicator(const Message_ProgressScope& theObj);

        //!@name Usage of Oriented Bounding boxes

        //! Enables/Disables the usage of OBB
        void SetUseOBB(Standard_Boolean theUseOBB);

        //! Returns the flag defining usage of OBB
        Standard_Boolean UseOBB();
        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property BOPAlgo_Options* IHandle {
            BOPAlgo_Options* get() {// Standard_OVERRIDE {
                return NativeHandle;
            }
            void set(BOPAlgo_Options* handle) {// Standard_OVERRIDE {
                NativeHandle = static_cast<BOPAlgo_Options*>(handle);
            }
        }

    private:
        BOPAlgo_Options* NativeHandle;
    };
}
#endif // _BOPAlgo_Options_HeaderFile
