// Created on: 1996-12-11
// Created by: Robert COUBLANC
// Copyright (c) 1996-1999 Matra Datavision
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
//! Defines a class of objects with display and selection services.
//! Entities which are visualized and selected are Interactive Objects.
//! Specific attributes of entities such as arrow aspect for dimensions must be loaded in a Prs3d_Drawer.
//!
//! You can make use of classes of standard Interactive Objects for which all necessary methods have already been programmed,
//! or you can implement your own classes of Interactive Objects.
//! Key interface methods to be implemented by every Interactive Object:
//! * Presentable Object (PrsMgr_PresentableObject)
//!   Consider defining an enumeration of supported Display Mode indexes for particular Interactive Object or class of Interactive Objects.
//!   - AcceptDisplayMode() accepting display modes implemented by this object;
//!   - Compute() computing presentation for the given display mode index;
//! * Selectable Object (SelectMgr_SelectableObject)
//!   Consider defining an enumeration of supported Selection Mode indexes for particular Interactive Object or class of Interactive Objects.
//!   - ComputeSelection() computing selectable entities for the given selection mode index.

#ifndef _XAIS_InteractiveObject_HeaderFile
#define _XAIS_InteractiveObject_HeaderFile
#pragma once
#include <Prs3d_BasicAspect.hxx>
#include "AIS_InteractiveObject.hxx"
#include "XAIS_InteractiveContext.h"
#include "XSelectMgr_SelectableObject.h"
//wrapper of pure C++ classes to ref classes
#include <NCollection_Haft.h>
#include <XAIS_KindOfInteractive.h>

class Prs3d_BasicAspect;

namespace TKV3d
{
	public ref class XAIS_InteractiveObject : public XSelectMgr_SelectableObject
	{
	public:
		//! 
		XAIS_InteractiveObject(void);

		//!
		XAIS_InteractiveObject(Handle(AIS_InteractiveObject) pos);

		//!
		~XAIS_InteractiveObject();

		//!
		void SetNativeHandle(Handle(AIS_InteractiveObject) pos);

		virtual Handle(AIS_InteractiveObject) GetInteractiveObject();

		virtual Handle(SelectMgr_SelectableObject) GetSelectableObject() Standard_OVERRIDE;

		virtual Handle(PrsMgr_PresentableObject) GetPresentableObject() Standard_OVERRIDE;


		//! Returns the kind of Interactive Object; AIS_KOI_None by default.
		virtual XAIS_KindOfInteractive Type();

		//! Specifies additional characteristics of Interactive Object of Type(); -1 by default.
		//! Among the datums, this signature is attributed to the shape.
		//! The remaining datums have the following default signatures:
		//! - Point          signature 1
		//! - Axis           signature 2
		//! - Trihedron      signature 3
		//! - PlaneTrihedron signature 4
		//! - Line           signature 5
		//! - Circle         signature 6
		//! - Plane          signature 7.
		virtual Standard_Integer Signature();

		//! Updates the active presentation; if <AllModes> = Standard_True
		//! all the presentations inside are recomputed.
		//! IMPORTANT: It is preferable to call Redisplay method of
		//! corresponding AIS_InteractiveContext instance for cases when it
		//! is accessible. This method just redirects call to myCTXPtr,
		//! so this class field must be up to date for proper result.
		void Redisplay(Standard_Boolean AllModes);

		//! Indicates whether the Interactive Object has a pointer to an interactive context.
		Standard_Boolean HasInteractiveContext();

		//! Returns the context pointer to the interactive context.
		AIS_InteractiveContext* InteractiveContext();

		//! Sets the interactive context aCtx and provides a link
		//! to the default drawing tool or "Drawer" if there is none.
		virtual void SetContext(Handle(AIS_InteractiveContext) aCtx);

		//! Returns true if the object has an owner attributed to it.
		//! The owner can be a shape for a set of sub-shapes or a sub-shape for sub-shapes which it is composed of, and takes the form of a transient.
		Standard_Boolean HasOwner();

		//! Returns the owner of the Interactive Object.
		//! The owner can be a shape for a set of sub-shapes or
		//! a sub-shape for sub-shapes which it is composed of,
		//! and takes the form of a transient.
		//! There are two types of owners:
		//! -   Direct owners, decomposition shapes such as
		//! edges, wires, and faces.
		//! -   Users, presentable objects connecting to sensitive
		//! primitives, or a shape which has been decomposed.
		Handle(Standard_Transient) GetOwner();

		//! Allows you to attribute the owner theApplicativeEntity to
		//! an Interactive Object. This can be a shape for a set of
		//! sub-shapes or a sub-shape for sub-shapes which it
		//! is composed of. The owner takes the form of a transient.
		void SetOwner(Handle(Standard_Transient) theApplicativeEntity);

		//! Each Interactive Object has methods which allow us to attribute an Owner to it in the form of a Transient.
		//! This method removes the owner from the graphic entity.
		void ClearOwner();

		//! Returns the context pointer to the interactive context.
		Handle(AIS_InteractiveContext) GetContext();

		//! Returns TRUE when this object has a presentation in the current DisplayMode()
		Standard_Boolean HasPresentation();

		//! Returns the current presentation of this object according to the current DisplayMode()
		Handle(Prs3d_Presentation) Presentation();

		//! Dumps the content of me into the stream
		virtual void DumpJson(Standard_OStream theOStream, Standard_Integer theDepth);


		/// <summary>
		/// 本地句柄
		/// </summary>
		virtual property Handle(Standard_Transient) IHandle {
			Handle(Standard_Transient) get() Standard_OVERRIDE {
				return NativeHandle();
			}
			void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
				NativeHandle() = Handle(AIS_InteractiveObject)::DownCast(handle);
			}
		}

	private:
		NCollection_Haft<Handle(AIS_InteractiveObject)> NativeHandle;
	};
};
#endif // _XAIS_InteractiveObject_HeaderFile