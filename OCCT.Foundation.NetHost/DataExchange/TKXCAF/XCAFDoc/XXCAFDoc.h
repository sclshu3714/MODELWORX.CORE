// Created on: 2000-08-08
// Created by: data exchange team
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

#ifndef _XXCAFDoc_HeaderFile
#define _XXCAFDoc_HeaderFile
#pragma once
#include <XCAFDoc.hxx>
#include <XStandard_GUID.h>
#include <XXCAFDoc_ColorType.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <XCAFDoc_ColorType.hxx>
class Standard_GUID;
class XCAFDoc_DocumentTool;
class XCAFDoc_Location;
class XCAFDoc_Color;
class XCAFDoc_DimTol;
class XCAFDoc_Dimension;
class XCAFDoc_GeomTolerance;
class XCAFDoc_Datum;
class XCAFDoc_Material;
class XCAFDoc_Volume;
class XCAFDoc_Area;
class XCAFDoc_Centroid;
class XCAFDoc_ClippingPlaneTool;
class XCAFDoc_ShapeTool;
class XCAFDoc_ShapeMapTool;
class XCAFDoc_ColorTool;
class XCAFDoc_DimTolTool;
class XCAFDoc_LayerTool;
class XCAFDoc_MaterialTool;
class XCAFDoc_GraphNode;
class XCAFDoc_Editor;
class XCAFDoc_ViewTool;
class XCAFDoc;

using namespace TKernel;
namespace TKXCAF {
	ref class TKernel::XStandard_GUID;
	//! Definition of general structure of DECAF document
	//! and tools to work with it
	//!
	//! The document is composed of sections, each section
	//! storing its own kind of data and managing by corresponding
	//! tool
	//! Some properties can be attached directly to shapes. These properties are:
	//! * Name (the standard definition from OCAF) - class TDataStd_Name
	//! * Centroid (for the validation of transfer) - class XCAFDoc_Centroid
	//! * Volume (for the validation of transfer) - class XCAFDoc_Volume
	//! * Area (for the validation of transfer) - class XCafDoc_Area
	//! Management of these attributes is realized by OCAF. For getting
	//! the attributes attached to a label the method class
	//! TDF_Label::FindAttribute() should be used.
	public ref class XXCAFDoc
	{
	public:

		//! class for containing GraphNodes.
		//! Returns GUID for UAttribute identifying assembly
		static XStandard_GUID^ AssemblyGUID();

		//! Returns GUID for TreeNode representing assembly link
		static XStandard_GUID^ ShapeRefGUID();

		//! Return GUIDs for TreeNode representing specified types of colors
		static XStandard_GUID^ ColorRefGUID(XXCAFDoc_ColorType type);

		//! Return GUIDs for TreeNode representing specified types of DGT
		static XStandard_GUID^ DimTolRefGUID();

		//! Return GUIDs for TreeNode representing specified types of Dimension
		static XStandard_GUID^ DimensionRefFirstGUID();

		//! Return GUIDs for TreeNode representing specified types of Dimension
		static XStandard_GUID^ DimensionRefSecondGUID();

		//! Return GUIDs for TreeNode representing specified types of GeomTolerance
		static XStandard_GUID^ GeomToleranceRefGUID();

		//! Return GUIDs for TreeNode representing specified types of datum
		static XStandard_GUID^ DatumRefGUID();

		//! Return GUIDs for TreeNode representing connections Datum-Toler
		static XStandard_GUID^ DatumTolRefGUID();

		static XStandard_GUID^ LayerRefGUID();

		static XStandard_GUID^ MaterialRefGUID();

		//! Return GUIDs for representing notes
		static XStandard_GUID^ NoteRefGUID();

		static XStandard_GUID^ InvisibleGUID();

		static XStandard_GUID^ ColorByLayerGUID();

		//! Returns GUID for UAttribute identifying external reference on no-step file
		static XStandard_GUID^ ExternRefGUID();

		//! Returns GUID for UAttribute identifying specified higher usage occurrence
		static XStandard_GUID^ SHUORefGUID();

		//! Return GUIDs for TreeNode representing specified types of View
		static XStandard_GUID^ ViewRefGUID();

		//! Return GUIDs for TreeNode representing specified types of View
		static XStandard_GUID^ ViewRefShapeGUID();

		//! Return GUIDs for TreeNode representing specified types of View
		static XStandard_GUID^ ViewRefGDTGUID();

		//! Return GUIDs for TreeNode representing specified types of View
		static XStandard_GUID^ ViewRefPlaneGUID();

		//! Return GUIDs for GraphNode representing specified types of View
		static XStandard_GUID^ ViewRefNoteGUID();
		static XStandard_GUID^ ViewRefAnnotationGUID();

		//! Returns GUID for UAttribute identifying lock flag
		static XStandard_GUID^ LockGUID();

	};
};
#endif // _XXCAFDoc_HeaderFile
