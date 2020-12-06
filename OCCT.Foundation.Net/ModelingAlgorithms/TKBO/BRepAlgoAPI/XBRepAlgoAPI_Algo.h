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

#ifndef _XBRepAlgoAPI_Algo_HeaderFile
#define _XBRepAlgoAPI_Algo_HeaderFile
#pragma once
#include <XStandard_Helper.h>
#include <BRepAlgoAPI_Algo.hxx>
#include <XBRepBuilderAPI_MakeShape.h>
#include <XTopoDS_Shape.h>
//#include <XBOPAlgo_Options.h>


#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <NCollection_BaseAllocator.hxx>
#include <Standard_Integer.hxx>
#include <Standard_Boolean.hxx>
#include <BRepBuilderAPI_MakeShape.hxx>
//#include <BOPAlgo_Options.hxx>
class Message_ProgressIndicator;
class TopoDS_Shape;
using namespace TKernel;
using namespace TKTopAlgo;
//! Provides the root interface for the API algorithms
namespace TKBO {
    //ref class XBOPAlgo_Options;
    ref class TKernel::XStandard_Helper;
    public ref class XBRepAlgoAPI_Algo : public XBRepBuilderAPI_MakeShape // , public XBOPAlgo_Options
    {
    public:

        //! Empty constructor
        XBRepAlgoAPI_Algo();

        //! Destructor
        virtual ~XBRepAlgoAPI_Algo();
        //! DEFINE_STANDARD_ALLOC

        void SetAlgoHandle(BRepAlgoAPI_Algo* pos);

        virtual BRepAlgoAPI_Algo* GetAlgo();

        virtual BRepBuilderAPI_MakeShape* GetMakeShape() Standard_OVERRIDE;

        virtual XTopoDS_Shape^ Shape() Standard_OVERRIDE;

        //! Clears all warnings and errors, and any data cached by the algorithm.
        //! User defined options are not cleared.
        virtual void Clear() Standard_OVERRIDE;

        //!@name Error reporting mechanism

        //! Adds the alert as error (fail)
        void AddError(Handle(Message_Alert)& theAlert) new;

        //! Adds the alert as warning
        void AddWarning(Handle(Message_Alert)& theAlert);

        //! Returns true if algorithm has failed
        Standard_Boolean HasErrors();

        //! Returns true if algorithm has generated error of specified type
        Standard_Boolean HasError(Handle(Standard_Type)& theType);

        //! Returns true if algorithm has generated some warning alerts
        Standard_Boolean HasWarnings();

        //! Returns true if algorithm has generated warning of specified type
        Standard_Boolean HasWarning(Handle(Standard_Type)& theType);

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
        void SetProgressIndicator(Handle(Message_ProgressIndicator)& theObj);

        //!@name Usage of Oriented Bounding boxes

        //! Enables/Disables the usage of OBB
        void SetUseOBB(Standard_Boolean theUseOBB);

        //! Returns the flag defining usage of OBB
        Standard_Boolean UseOBB();

        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property BRepBuilderAPI_MakeShape* IHandle {
            BRepBuilderAPI_MakeShape* get() Standard_OVERRIDE {
                return NativeHandle;
            }
            void set(BRepBuilderAPI_MakeShape* handle) Standard_OVERRIDE {
                NativeHandle = static_cast<BRepAlgoAPI_Algo*>(handle);
            }
        }

    private:
        BRepAlgoAPI_Algo* NativeHandle;
    };
}
#endif // _BRepAlgoAPI_Algo_HeaderFile
