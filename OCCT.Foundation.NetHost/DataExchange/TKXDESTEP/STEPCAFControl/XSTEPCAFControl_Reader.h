// Created on: 2000-08-15
// Created by: Andrey BETENEV
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

#ifndef _XSTEPCAFControl_Reader_HeaderFile
#define _XSTEPCAFControl_Reader_HeaderFile

#pragma once
#include <vcclr.h>
#include "XTDF_Label.h"
#include <STEPCAFControl_Reader.hxx>
#include "XTDocStd_Document.h"
#include <XIFSelect_ReturnStatus.h>

#include <Resource_FormatType.hxx>
#include <STEPControl_Reader.hxx>
#include <IFSelect_ReturnStatus.hxx>
#include <TDF_LabelSequence.hxx>
#include <TopTools_MapOfShape.hxx>
#include <STEPCAFControl_DataMapOfShapePD.hxx>
#include <STEPCAFControl_DataMapOfPDExternFile.hxx>
#include <XCAFDoc_DataMapOfShapeLabel.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <XCAFDimTolObjects_DatumModifiersSequence.hxx>
#include <XCAFDimTolObjects_DatumModifWithValue.hxx>

class XSControl_WorkSession;
class TDocStd_Document;
class TCollection_AsciiString;
class STEPCAFControl_ExternFile;
class STEPControl_Reader;
class TDF_Label;
class TopoDS_Shape;
class XCAFDoc_ShapeTool;
class StepRepr_RepresentationItem;
class Transfer_TransientProcess;
class StepShape_ConnectedFaceSet;
class StepRepr_NextAssemblyUsageOccurrence;
class STEPConstruct_Tool;
class StepDimTol_Datum;

using namespace TKLCAF;
//! Provides a tool to read STEP file and put it into
//! DECAF document. Besides transfer of shapes (including
//! assemblies) provided by STEPControl, supports also
//! colors and part names
//!
//! This reader supports reading files with external references
//! i.e. multifile reading
//! It behaves as usual Reader (from STEPControl) for the main
//! file (e.g. if it is single file)
//! Results of reading other files can be accessed by name of the
//! file or by iterating on a readers
namespace TKXDESTEP {
    ref class TKLCAF::XTDF_Label;
    ref class TKLCAF::XTDocStd_Document;
    public ref class XSTEPCAFControl_Reader
    {
    public:

        //! Creates a reader with an empty
        //! STEP model and sets ColorMode, LayerMode, NameMode and
        //! PropsMode to Standard_True.
        XSTEPCAFControl_Reader();

        //! Creates a reader with an empty
       //! STEP model and sets ColorMode, LayerMode, NameMode and
       //! PropsMode to Standard_True.
        XSTEPCAFControl_Reader(STEPCAFControl_Reader* pos);
        //! Creates a reader tool and attaches it to an already existing Session
        //! Clears the session if it was not yet set for STEP
        XSTEPCAFControl_Reader(const Handle(XSControl_WorkSession)& WS, const Standard_Boolean scratch);

        //! Clears the internal data structures and attaches to a new session
        //! Clears the session if it was not yet set for STEP
        void Init(const Handle(XSControl_WorkSession)& WS, const Standard_Boolean scratch);

        //! Loads a file and returns the read status
        //! Provided for use like single-file reader
        XIFSelect_ReturnStatus ReadFile(const Standard_CString filename);

        //! Loads a file and returns the read status
        //! Provided for use like single-file reader
        //! IFSelect_ReturnStatus
        XIFSelect_ReturnStatus ReadFile(System::String^ theFileName);

        //! Returns number of roots recognized for transfer
        //! Shortcut for Reader().NbRootsForTransfer()
        Standard_Integer NbRootsForTransfer();

        //! Translates currently loaded STEP file into the document
        //! Returns True if succeeded, and False in case of fail
        //! Provided for use like single-file reader
        Standard_Boolean TransferOneRoot(const Standard_Integer num, Handle(TDocStd_Document)& doc);

        //! Translates currently loaded STEP file into the document
        //! Returns True if succeeded, and False in case of fail
        //! Provided for use like single-file reader
        Standard_Boolean Transfer(Handle(TDocStd_Document)& doc);

        //! Translates currently loaded STEP file into the document
        //! Returns True if succeeded, and False in case of fail
        //! Provided for use like single-file reader
        Standard_Boolean Transfer(XTDocStd_Document^ doc);

        Standard_Boolean Perform(const TCollection_AsciiString& filename, Handle(TDocStd_Document)& doc);

        //! Translate STEP file given by filename into the document
        //! Return True if succeeded, and False in case of fail
        Standard_Boolean Perform(const Standard_CString filename, Handle(TDocStd_Document)& doc);

        //! Returns data on external files
        //! Returns Null handle if no external files are read
        NCollection_DataMap<TCollection_AsciiString, Handle(STEPCAFControl_ExternFile)> ExternFiles();

        //! Returns data on external file by its name
        //! Returns False if no external file with given name is read
        Standard_Boolean ExternFile(const Standard_CString name, Handle(STEPCAFControl_ExternFile)& ef);

        //! Returns basic reader
        STEPControl_Reader& ChangeReader();

        //! Returns basic reader as const
        const STEPControl_Reader& Reader();

        //! Returns label of instance of an assembly component
        //! corresponding to a given NAUO
        static XTDF_Label^ FindInstance (const Handle(StepRepr_NextAssemblyUsageOccurrence)& NAUO, const Handle(XCAFDoc_ShapeTool)& STool, const STEPConstruct_Tool& Tool, const XCAFDoc_DataMapOfShapeLabel& ShapeLabelMap);

        //! Set ColorMode for indicate read Colors or not.
        void SetColorMode(const Standard_Boolean colormode);

        Standard_Boolean GetColorMode();

        //! Set NameMode for indicate read Name or not.
        void SetNameMode(const Standard_Boolean namemode);

        Standard_Boolean GetNameMode();

        //! Return the encoding of STEP file for converting names into UNICODE.
        //! Initialized from "read.stepcaf.codepage" variable by constructor, which is Resource_UTF8 by default.
        Resource_FormatType SourceCodePage();

        //! Return the encoding of STEP file for converting names into UNICODE.
        void SetSourceCodePage(Resource_FormatType theCode);

        //! Set LayerMode for indicate read Layers or not.
        void SetLayerMode(const Standard_Boolean layermode);

        Standard_Boolean GetLayerMode();

        //! PropsMode for indicate read Validation properties or not.
        void SetPropsMode(const Standard_Boolean propsmode);

        Standard_Boolean GetPropsMode();

        //! Set SHUO mode for indicate write SHUO or not.
        void SetSHUOMode(const Standard_Boolean shuomode);

        Standard_Boolean GetSHUOMode();

        //! Set GDT mode for indicate write GDT or not.
        void SetGDTMode(const Standard_Boolean gdtmode);

        Standard_Boolean GetGDTMode();

        //! Set Material mode
        void SetMatMode(const Standard_Boolean matmode);

        Standard_Boolean GetMatMode();

        //! Set View mode
        void SetViewMode(const Standard_Boolean viewmode);

        //! Get View mode
        Standard_Boolean GetViewMode();

        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        property STEPCAFControl_Reader* Handle
        {
            STEPCAFControl_Reader* get() {
                return NativeHandle;
            }
        }
    private:
        STEPCAFControl_Reader* NativeHandle;
    };

    //! Auxiliary tool for converting C# string into UTF-8 string.
    static TCollection_AsciiString toAsciiString(System::String^ theString) {
        if (theString == nullptr) {
            return TCollection_AsciiString();
        }

        pin_ptr<const wchar_t> aPinChars = PtrToStringChars(theString);
        const wchar_t* aWCharPtr = aPinChars;
        if (aWCharPtr == NULL
            || *aWCharPtr == L'\0') {
            return TCollection_AsciiString();
        }
        return TCollection_AsciiString(aWCharPtr);
    }
}
#endif // _XSTEPCAFControl_Reader_HeaderFile
