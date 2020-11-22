// Created on: 2000-08-30
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

#ifndef _XXCAFDoc_DocumentTool_HeaderFile
#define _XXCAFDoc_DocumentTool_HeaderFile
#pragma once
#include "XCAFDoc_DocumentTool.hxx"
#include "XTDF_Attribute.h"
#include "NCollection_Haft.h"
#include "XTDF_Label.h"
#include "XStandard_GUID.h"
#include "XXCAFDoc_ShapeTool.h"

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <TDF_Attribute.hxx>
#include <Standard_Boolean.hxx>
class Standard_GUID;
class TDF_Label;
class TDocStd_Document;
class XCAFDoc_ShapeTool;
class XCAFDoc_ColorTool;
class XCAFDoc_ClippingPlaneTool;
class XCAFDoc_LayerTool;
class XCAFDoc_DimTolTool;
class XCAFDoc_MaterialTool;
class XCAFDoc_NotesTool;
class XCAFDoc_ViewTool;
class TDF_Attribute;
class TDF_RelocationTable;


//class XCAFDoc_DocumentTool;
//DEFINE_STANDARD_HANDLE(XCAFDoc_DocumentTool, TDF_Attribute)
using namespace TKLCAF;
using namespace TKernel;
namespace TKXCAF {

	ref class TKLCAF::XTDF_Attribute;
	ref class TKernel::XStandard_GUID;
	ref class TKLCAF::XTDF_Label;
	//! Defines sections structure of an XDE document.
	//! attribute marking CAF document as being DECAF document.
	//! Creates the sections structure of the document.
	public ref class XXCAFDoc_DocumentTool : public XTDF_Attribute
	{

	public:
		

		static XStandard_GUID^ GetID();

		//! Create (if not exist) DocumentTool attribute
		//! on 0.1 label if <IsAcces> is true, else
		//! on <L> label.
		//! This label will be returned by DocLabel();
		//! If the attribute is already set it won't be reset on
		//! <L> even if <IsAcces> is false.
		//! ColorTool and ShapeTool attributes are also set by this method.
		//! IsAcces = Standard_True
		static XXCAFDoc_DocumentTool^ Set(XTDF_Label^ L, Standard_Boolean IsAcces);

		static Standard_Boolean IsXCAFDocument(const Handle(TDocStd_Document)& Doc);

		//! Returns label where the DocumentTool attribute is or
		//! 0.1 if DocumentTool is not yet set.
		static XTDF_Label^ DocLabel(XTDF_Label^ acces);

		//! Returns sub-label of DocLabel() with tag 1.
		static XTDF_Label^ ShapesLabel(XTDF_Label^ acces);

		//! Returns sub-label of DocLabel() with tag 2.
		static XTDF_Label^ ColorsLabel(XTDF_Label^ acces);

		//! Returns sub-label of DocLabel() with tag 3.
		static XTDF_Label^ LayersLabel(XTDF_Label^ acces);

		//! Returns sub-label of DocLabel() with tag 4.
		static XTDF_Label^ DGTsLabel(XTDF_Label^ acces);

		//! Returns sub-label of DocLabel() with tag 5.
		static XTDF_Label^ MaterialsLabel(XTDF_Label^ acces);

		//! Returns sub-label of DocLabel() with tag 7.
		static XTDF_Label^ ViewsLabel(XTDF_Label^ acces);

		//! Returns sub-label of DocLabel() with tag 8.
		static XTDF_Label^ ClippingPlanesLabel(XTDF_Label^ acces);

		//! Returns sub-label of DocLabel() with tag 9.
		static XTDF_Label^ NotesLabel(XTDF_Label^ acces);

		//! Creates (if it does not exist) ShapeTool attribute on ShapesLabel().
		static XXCAFDoc_ShapeTool^ ShapeTool(XTDF_Label^ acces);

		//! Creates (if it does not exist) ColorTool attribute on ColorsLabel().
		static Handle(XCAFDoc_ColorTool) ColorTool(XTDF_Label^ acces);

		//! Creates (if it does not exist) LayerTool attribute on LayersLabel().
		static Handle(XCAFDoc_LayerTool) LayerTool(XTDF_Label^ acces);

		//! Creates (if it does not exist) DimTolTool attribute on DGTsLabel().
		static Handle(XCAFDoc_DimTolTool) DimTolTool(XTDF_Label^ acces);

		//! Creates (if it does not exist) DimTolTool attribute on DGTsLabel().
		static Handle(XCAFDoc_MaterialTool) MaterialTool(XTDF_Label^ acces);

		//! Creates (if it does not exist) ViewTool attribute on ViewsLabel().
		static Handle(XCAFDoc_ViewTool) ViewTool(XTDF_Label^ acces);

		//! Creates (if it does not exist) ClippingPlaneTool attribute on ClippingPlanesLabel().
		static Handle(XCAFDoc_ClippingPlaneTool) ClippingPlaneTool(XTDF_Label^ acces);

		//! Creates (if it does not exist) NotesTool attribute on NotesLabel().
		static Handle(XCAFDoc_NotesTool) NotesTool(XTDF_Label^ acces);

		XXCAFDoc_DocumentTool();

		//! to be called when reading this attribute from file
		void Init();

		//!
		XXCAFDoc_DocumentTool(Handle(XCAFDoc_DocumentTool) pos);

		XStandard_GUID^ ID() Standard_OVERRIDE;

		void Restore(XTDF_Attribute^ with) Standard_OVERRIDE;

		XTDF_Attribute^ NewEmpty() Standard_OVERRIDE;

		void Paste(XTDF_Attribute^ into, Handle(TDF_RelocationTable)& RT) Standard_OVERRIDE;

		//! DEFINE_STANDARD_RTTIEXT(XCAFDoc_DocumentTool, TDF_Attribute)
		//! 
		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		property Handle(XCAFDoc_DocumentTool) DHandle
		{
			Handle(XCAFDoc_DocumentTool) get() {
				return NativeHandle();
			}
		}
	private:
		NCollection_Haft<Handle(XCAFDoc_DocumentTool)> NativeHandle;
	};
}
#endif // _XXCAFDoc_DocumentTool_HeaderFile
