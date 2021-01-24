// Created on: 1995-08-09
// Created by: Arnaud BOUZY/Odile Olivier
// Copyright (c) 1995-1999 Matra Datavision
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

#ifndef _XAIS_Axis_HeaderFile
#define _XAIS_Axis_HeaderFile
#pragma once
#include "AIS_Axis.hxx"
#include <XAIS_InteractiveObject.h>
#include <XAIS_TypeOfAxis.h>
#include <xgp_Dir.h>
#include <xgp_Pnt.h>
#include <XSelectMgr_Selection.h>

#include <Geom_Line.hxx>
#include <Geom_Axis1Placement.hxx>
#include <Geom_Axis2Placement.hxx>
#include <Prs3d_LineAspect.hxx>

class Geom_Line;
class Geom_Axis1Placement;
class Geom_Axis2Placement;
class Prs3d_LineAspect;

using namespace TKMath;

//! Locates the x, y and z axes in an Interactive Object.
//! These are used to orient it correctly in presentations
//! from different viewpoints, or to construct a revolved
//! shape, for example, from one of the axes. Conversely,
//! an axis can be created to build a revolved shape and
//! then situated relative to one of the axes of the view.
namespace TKV3d {

	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Dir;
	public ref class XAIS_Axis : public XAIS_InteractiveObject
	{
		//! DEFINE_STANDARD_RTTIEXT(AIS_Axis, AIS_InteractiveObject)
	public:

		//! Initializes the line aComponent
		XAIS_Axis(Handle(Geom_Line) aComponent);
		!XAIS_Axis() { IHandle = NULL; };
		~XAIS_Axis() { IHandle = NULL; };
		//! initializes the axis2 position
		//! aComponent. The coordinate system used is right-handed.
		XAIS_Axis(Handle(Geom_Axis2Placement) aComponent, XAIS_TypeOfAxis anAxisType);

		//! Initializes the axis1 position anAxis.
		XAIS_Axis(Handle(Geom_Axis1Placement) anAxis);

		//! Returns the axis entity aComponent and identifies it
		//! as a component of a shape.
		const Handle(Geom_Line) Component();

		virtual Handle(AIS_Axis) GetAxis();

		virtual Handle(AIS_InteractiveObject) GetInteractiveObject() Standard_OVERRIDE;

		virtual Handle(SelectMgr_SelectableObject) GetSelectableObject() Standard_OVERRIDE;

		virtual Handle(PrsMgr_PresentableObject) GetPresentableObject() Standard_OVERRIDE;

		//! Sets the coordinates of the lin aComponent.
		void SetComponent(Handle(Geom_Line) aComponent);

		//! Returns the position of axis2 and   positions it by
		//! identifying it as the x, y, or z axis and giving its
		//! direction in 3D space. The coordinate system used is right-handed.
		const Handle(Geom_Axis2Placement) Axis2Placement();

		//! Allows you to provide settings for aComponent:the
		//! position and direction of an axis in 3D space. The
		//! coordinate system used is right-handed.
		void SetAxis2Placement(Handle(Geom_Axis2Placement) aComponent, XAIS_TypeOfAxis anAxisType);

		//! Constructs a new line to serve as the axis anAxis in 3D space.
		void SetAxis1Placement(Handle(Geom_Axis1Placement) anAxis);

		//! Returns the type of axis.
		XAIS_TypeOfAxis TypeOfAxis();

		//! Constructs the entity theTypeAxis to stock information
		//! concerning type of axis.
		void SetTypeOfAxis(XAIS_TypeOfAxis theTypeAxis);

		//! Returns a signature of 2 for axis datums. When you
		//! activate mode 2 by a signature, you pick AIS objects
		//! of type AIS_Axis.
		Standard_Boolean IsXYZAxis();

		//! Returns true if the interactive object accepts the display mode aMode.
		Standard_Boolean AcceptDisplayMode(Standard_Integer aMode) Standard_OVERRIDE;

		virtual Standard_Integer Signature() Standard_OVERRIDE;

		virtual XAIS_KindOfInteractive Type() Standard_OVERRIDE;

		void SetColor(XQuantity_Color^ aColor) Standard_OVERRIDE;

		void SetWidth(const Standard_Real aValue) Standard_OVERRIDE;

		void UnsetColor() Standard_OVERRIDE;

		void UnsetWidth() Standard_OVERRIDE;

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property Handle(Standard_Transient) IHandle {
			Handle(Standard_Transient) get() Standard_OVERRIDE {
				return NativeHandle();
			}
			void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
				//NativeHandle() = Handle(AIS_Axis)::DownCast(handle);
				if (!handle.IsNull())
					NativeHandle() = Handle(AIS_Axis)::DownCast(handle);
				else if (!NativeHandle().IsNull())
					NativeHandle() = NULL;
			}
		}
	private:
		NCollection_Haft<Handle(AIS_Axis)> NativeHandle;

	};

	//! DEFINE_STANDARD_HANDLE(AIS_Axis, AIS_InteractiveObject)
}
#endif // _XAIS_Axis_HeaderFile
