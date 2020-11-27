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

#include <XAIS_Axis.h>

namespace TKV3d {
	//! Initializes the line aComponent
	XAIS_Axis::XAIS_Axis(Handle(Geom_Line) aComponent) {
		NativeHandle() = new AIS_Axis(aComponent);
	};

	//! initializes the axis2 position
	//! aComponent. The coordinate system used is right-handed.
	XAIS_Axis::XAIS_Axis(Handle(Geom_Axis2Placement) aComponent, XAIS_TypeOfAxis anAxisType) {
		NativeHandle() = new AIS_Axis(aComponent, safe_cast<AIS_TypeOfAxis>(anAxisType));
	};

	//! Initializes the axis1 position anAxis.
	XAIS_Axis::XAIS_Axis(Handle(Geom_Axis1Placement) anAxis) {
		NativeHandle() = new AIS_Axis(anAxis);
	};

	//! Returns the axis entity aComponent and identifies it
	//! as a component of a shape.
	const Handle(Geom_Line) XAIS_Axis::Component() {
		return NativeHandle()->Component();
	};

	Handle(AIS_Axis) XAIS_Axis::GetAxis() {
		return NativeHandle();
	};

	//! Sets the coordinates of the lin aComponent.
	void XAIS_Axis::SetComponent(Handle(Geom_Line) aComponent) {
		NativeHandle()->SetComponent(aComponent);
	};

	//! Returns the position of axis2 and   positions it by
	//! identifying it as the x, y, or z axis and giving its
	//! direction in 3D space. The coordinate system used is right-handed.
	const Handle(Geom_Axis2Placement) XAIS_Axis::Axis2Placement() {
		return NativeHandle()->Axis2Placement();
	};

	//! Allows you to provide settings for aComponent:the
	//! position and direction of an axis in 3D space. The
	//! coordinate system used is right-handed.
	void XAIS_Axis::SetAxis2Placement(Handle(Geom_Axis2Placement) aComponent, XAIS_TypeOfAxis anAxisType) {
		NativeHandle()->SetAxis2Placement(aComponent, safe_cast<AIS_TypeOfAxis>(anAxisType));
	};

	//! Constructs a new line to serve as the axis anAxis in 3D space.
	void XAIS_Axis::SetAxis1Placement(Handle(Geom_Axis1Placement) anAxis) {
		NativeHandle()->SetAxis1Placement(anAxis);
	};

	//! Returns the type of axis.
	XAIS_TypeOfAxis XAIS_Axis::TypeOfAxis() {
		return safe_cast<XAIS_TypeOfAxis>(NativeHandle()->TypeOfAxis());
	};

	//! Constructs the entity theTypeAxis to stock information
	//! concerning type of axis.
	void XAIS_Axis::SetTypeOfAxis(XAIS_TypeOfAxis theTypeAxis) {
		NativeHandle()->SetTypeOfAxis(safe_cast<AIS_TypeOfAxis>(theTypeAxis));
	};

	//! Returns a signature of 2 for axis datums. When you
	//! activate mode 2 by a signature, you pick AIS objects
	//! of type AIS_Axis.
	Standard_Boolean XAIS_Axis::IsXYZAxis() {
		return NativeHandle()->IsXYZAxis();
	};

	//! Returns true if the interactive object accepts the display mode aMode.
	Standard_Boolean XAIS_Axis::AcceptDisplayMode(Standard_Integer aMode) {
		return NativeHandle()->AcceptDisplayMode(aMode);
	};

	//! computes the presentation according to a point of view
	//! given by <aProjector>.
	//! To be Used when the associated degenerated Presentations
	//! have been transformed by <aTrsf> which is not a Pure
	//! Translation. The HLR Prs can't be deducted automatically
	//! WARNING :<aTrsf> must be applied
	//! to the object to display before computation  !!!
	void XAIS_Axis::Compute(Handle(Prs3d_Projector) aProjector, Handle(Geom_Transformation) aTrsf, Handle(Prs3d_Presentation) aPresentation) {
		NativeHandle()->Compute(aProjector, aTrsf, aPresentation);
	};

	Standard_Integer XAIS_Axis::Signature() {
		return NativeHandle()->Signature();
	};

	XAIS_KindOfInteractive XAIS_Axis::Type() {
		return safe_cast<XAIS_KindOfInteractive>(NativeHandle()->Type());
	};

	void XAIS_Axis::SetColor(XQuantity_Color^ aColor) {
		NativeHandle()->SetColor(aColor->GetColor());
	};

	void XAIS_Axis::SetWidth(const Standard_Real aValue) {
		NativeHandle()->SetWidth(aValue);
	};
							   
	void XAIS_Axis::UnsetColor() {
		NativeHandle()->UnsetColor();
	};

	void XAIS_Axis::UnsetWidth() {
		NativeHandle()->UnsetWidth();
	};
}
