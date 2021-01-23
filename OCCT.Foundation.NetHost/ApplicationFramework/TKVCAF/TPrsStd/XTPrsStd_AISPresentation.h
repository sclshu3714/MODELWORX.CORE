// Created on: 1998-09-30
// Created by: Denis PASCAL
// Copyright (c) 1998-1999 Matra Datavision
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

#ifndef _XTPrsStd_AISPresentation_HeaderFile
#define _XTPrsStd_AISPresentation_HeaderFile
#pragma once
#include "TPrsStd_AISPresentation.hxx" 
#include "NCollection_Haft.h"
#include "XTDF_Attribute.h"
#include "XStandard_GUID.h"
#include "XTDF_Label.h"
#include "XAIS_InteractiveObject.h"


#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <Standard_GUID.hxx>
#include <Standard_Real.hxx>
#include <Quantity_NameOfColor.hxx>
#include <Graphic3d_NameOfMaterial.hxx>
#include <Standard_Integer.hxx>
#include <Standard_Boolean.hxx>
#include <TDF_Attribute.hxx>
#include <TDataXtd_Presentation.hxx>
#include <AIS_InteractiveContext.hxx>

class AIS_InteractiveObject;
class Standard_GUID;
class TDF_Label;
class TDF_Attribute;
class TDF_RelocationTable;
class TDF_AttributeDelta;

//class XTPrsStd_AISPresentation;
//DEFINE_STANDARD_HANDLE(XTPrsStd_AISPresentation, XTDF_Attribute)

//! An attribute to associate an
//! AIS_InteractiveObject to a label in an AIS viewer.
//! This attribute works in collaboration with TPrsStd_AISViewer.
//! Note that all the Set... and Unset... attribute
//! methods as well as the query methods for
//! visualization attributes and the HasOwn... test
//! methods are shortcuts to the respective
//! AIS_InteractiveObject settings.
using namespace TKLCAF;
using namespace TKernel;
using namespace TKV3d;
namespace TKVCAF {

	ref class TKernel::XStandard_GUID;
	ref class TKLCAF::XTDF_Label;
	ref class TKV3d::XAIS_InteractiveObject;
	public ref class XTPrsStd_AISPresentation : public XTDF_Attribute
	{

	public:
		!XTPrsStd_AISPresentation() { IHandle = NULL; };
		~XTPrsStd_AISPresentation() { IHandle = NULL; };
		XTPrsStd_AISPresentation();

		XTPrsStd_AISPresentation(Handle(TPrsStd_AISPresentation) pos);

		Handle(TPrsStd_AISPresentation) GetAISPresentation();

		//£¡
		virtual Handle(TDF_Attribute) GetAttribute() Standard_OVERRIDE;

		//! Returns the GUID for TPrsStd_AISPresentation attributes.
		static const XStandard_GUID^ GetID();

		//! Creates or retrieves the presentation attribute on
		//! the label L, and sets the GUID driver.
		static Handle(TPrsStd_AISPresentation) Set(const TDF_Label& L, const Standard_GUID& driver);

		//! Creates or retrieves the presentation attribute on
		//! the label L, and sets the GUID driver.
		static XTPrsStd_AISPresentation^ Set(XTDF_Label^ L, XStandard_GUID^ driver);

		//! Delete (if exist) the presentation attribute associated to the label <L>.
		static void Unset(const TDF_Label& L);

		//! Delete (if exist) the presentation attribute associated to the label <L>.
		static void Unset(XTDF_Label^ L);

		//! Creates or retrieves the AISPresentation
		//! attribute attached to master.
		//! The GUID of the driver will be the GUID of master.
		//! master is the attribute you want to display.
		static Handle(TPrsStd_AISPresentation) Set(const Handle(TDF_Attribute)& master);

		//! Creates or retrieves the AISPresentation
		//! attribute attached to master.
		//! The GUID of the driver will be the GUID of master.
		//! master is the attribute you want to display.
		static XTPrsStd_AISPresentation^ Set(XTDF_Attribute^ master);

		void SetDisplayed(const Standard_Boolean B);

		//! Display presentation of object in AIS viewer.
		//! If <update> = True then AISObject is recomputed and all
		//! the visualization settings are applied
		//! update = Standard_False
		void Display(const Standard_Boolean update);

		//! Removes the presentation of this AIS
		//! presentation attribute from the TPrsStd_AISViewer.
		//! If remove is true, this AIS presentation attribute
		//! is removed from the interactive context.
		//! remove = Standard_False
		void Erase(const Standard_Boolean remove);

		//! Recompute presentation of object and apply the visualization settings
		void Update();

		XStandard_GUID^ GetDriverGUID();

		void SetDriverGUID(const Standard_GUID& guid);

		void SetDriverGUID(XStandard_GUID^ guid);

		//! Returns true if this AIS presentation attribute is displayed.
		Standard_Boolean IsDisplayed();

		//! Returns AIS_InteractiveObject stored in the presentation attribute
		XAIS_InteractiveObject^ GetAIS();

		//! Returns the material setting for this presentation attribute.
		XGraphic3d_NameOfMaterial^ Material();

		//! Sets the material aName for this presentation  attribute.
		void SetMaterial(XGraphic3d_NameOfMaterial aName);

		//! Sets the material aName for this presentation  attribute.
		void SetMaterial(const Standard_Integer aName);

		//! Returns true if this presentation attribute already has a material setting.
		Standard_Boolean HasOwnMaterial();

		//! Removes the material setting from this presentation attribute.
		void UnsetMaterial();


		//! Sets the transparency value aValue for this
		//! presentation attribute.
		//! This value is 0.6 by default.
		//! aValue = 0.6
		void SetTransparency(const Standard_Real aValue);

		Standard_Real Transparency();

		//! Returns true if this presentation attribute already has a transparency setting.
		Standard_Boolean HasOwnTransparency();

		//! Removes the transparency setting from this presentation attribute.
		void UnsetTransparency();

		XQuantity_NameOfColor Color();

		//! Sets the color aColor for this presentation attribute.
		void SetColor(XQuantity_NameOfColor aColor);

		//! Returns true if this presentation attribute already has a color setting.
		Standard_Boolean HasOwnColor();

		//! Removes the color setting from this presentation attribute.
		void UnsetColor();

		Standard_Real Width();

		//! Sets the width aWidth for this presentation attribute.
		void SetWidth(const Standard_Real aWidth);

		//! Returns true if this presentation attribute already has a width setting.
		Standard_Boolean HasOwnWidth();

		//! Removes the width setting from this presentation attribute.
		void UnsetWidth();

		Standard_Integer Mode();

		void SetMode(const Standard_Integer theMode);

		Standard_Boolean HasOwnMode();

		void UnsetMode();

		//! Returns selection mode(s) of the attribute.
		//! It starts with 1 .. GetNbSelectionModes().
		Standard_Integer GetNbSelectionModes();
		//£¡index = 1
		Standard_Integer SelectionMode(const int index);

		//! Sets selection mode.
		//! If "theTransaction" flag is OFF, modification of the attribute doesn't influence the transaction mechanism
		//! (the attribute doesn't participate in undo/redo because of this modification).
		//! Certainly, if any other data of the attribute is modified (display mode, color, ...),
		//! the attribute will be included into undo/redo.
		//! theTransaction = Standard_True
		void SetSelectionMode(const Standard_Integer theSelectionMode, const Standard_Boolean theTransaction);
		//! theTransaction = Standard_True
		void AddSelectionMode(const Standard_Integer theSelectionMode, const Standard_Boolean theTransaction);

		Standard_Boolean HasOwnSelectionMode();

		//! Clears all selection modes of the attribute.
		void UnsetSelectionMode();

		XStandard_GUID^ ID() Standard_OVERRIDE;

		XTDF_Attribute^ NewEmpty() Standard_OVERRIDE;

		void Restore(XTDF_Attribute^ with) Standard_OVERRIDE;

		void Paste(XTDF_Attribute^ into, Handle(TDF_RelocationTable)& RT) Standard_OVERRIDE;
		
		virtual XTDF_Attribute^ BackupCopy() Standard_OVERRIDE;

		virtual void AfterAddition() Standard_OVERRIDE;

		virtual void BeforeRemoval() Standard_OVERRIDE;

		virtual void BeforeForget() Standard_OVERRIDE;

		virtual void AfterResume() Standard_OVERRIDE;

		//forceIt = Standard_False
		virtual Standard_Boolean BeforeUndo(const Handle(TDF_AttributeDelta)& anAttDelta, const Standard_Boolean forceIt) Standard_OVERRIDE;

		//! update AIS viewer according to delta
		//! forceIt = Standard_False
		virtual Standard_Boolean AfterUndo(const Handle(TDF_AttributeDelta)& anAttDelta, const Standard_Boolean forceIt) Standard_OVERRIDE;

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property Handle(Standard_Transient) IHandle {
			Handle(Standard_Transient) get() Standard_OVERRIDE {
				return NativeHandle();
			}
			void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
				NativeHandle() = Handle(TPrsStd_AISPresentation)::DownCast(handle);
			}
		}
	private:
		NCollection_Haft<Handle(TPrsStd_AISPresentation)> NativeHandle;
	};
}
#endif // _XTPrsStd_AISPresentation_HeaderFile
