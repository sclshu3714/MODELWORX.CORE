// Created on: 1998-05-05
// Created by: Stepan MISHIN
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

#ifndef _XGeom_OsculatingSurface_HeaderFile
#define _XGeom_OsculatingSurface_HeaderFile
#pragma once
#include "NCollection_Haft.h"
#include "Geom_OsculatingSurface.hxx"
#include "XGeom_Surface.h"
#include "XGeom_BSplineSurface.h"

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <Standard_Real.hxx>
#include <Geom_HSequenceOfBSplineSurface.hxx>
#include <TColStd_HSequenceOfInteger.hxx>
#include <TColStd_Array1OfBoolean.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_Integer.hxx>
#include <GeomAbs_IsoType.hxx>
#include <Geom_SequenceOfBSplineSurface.hxx>
class Geom_Surface;
class Geom_BSplineSurface;
class Geom_OsculatingSurface;


class Geom_OsculatingSurface;
//DEFINE_STANDARD_HANDLE(Geom_OsculatingSurface, Standard_Transient)
using namespace TKMath;
namespace TKG3d
{
	ref class XGeom_Surface;
	ref class XGeom_BSplineSurface;
	public ref class XGeom_OsculatingSurface //: public Standard_Transient
	{
	public:

		!XGeom_OsculatingSurface() { IHandle = NULL; };
		~XGeom_OsculatingSurface() { IHandle = NULL; };

		//! DEFINE_STANDARD_ALLOC
		XGeom_OsculatingSurface();

		XGeom_OsculatingSurface(Handle(Geom_OsculatingSurface) pos);

		void SetOsculatingSurfaceHandle(Handle(Geom_OsculatingSurface) pos);

		virtual Handle(Geom_OsculatingSurface) GetOsculatingSurface();


		//! detects if the  surface has punctual U  or  V
		//! isoparametric  curve along on  the bounds of the surface
		//! relativly to the tolerance Tol and Builds the corresponding
		//! osculating surfaces.
		XGeom_OsculatingSurface(XGeom_Surface^ BS, Standard_Real Tol);

		void Init(XGeom_Surface^ BS, Standard_Real Tol);

		XGeom_Surface^ BasisSurface();

		Standard_Real Tolerance();

		//! if Standard_True, L is the local osculating surface
		//! along U at the point U,V.
		Standard_Boolean UOscSurf(Standard_Real U, Standard_Real V, Standard_Boolean% t, XGeom_BSplineSurface^% L);

		//! if Standard_True, L is the local osculating surface
		//! along V at the point U,V.
		Standard_Boolean VOscSurf(Standard_Real U, Standard_Real V, Standard_Boolean% t, XGeom_BSplineSurface^% L);


		//! DEFINE_STANDARD_RTTIEXT(Geom_OsculatingSurface, Standard_Transient)
		virtual property Handle(Standard_Transient) IHandle {
			Handle(Standard_Transient) get() { //Standard_OVERRIDE {
				return NativeHandle();
			}
			void set(Handle(Standard_Transient) handle) { //Standard_OVERRIDE {
				//NativeHandle() = Handle(Geom_OsculatingSurface)::DownCast(handle);
				if (!handle.IsNull())
					NativeHandle() = Handle(Geom_OsculatingSurface)::DownCast(handle);
				else if (!NativeHandle().IsNull())
					NativeHandle() = NULL;
			}
		};

	private:
		NCollection_Haft<Handle(Geom_OsculatingSurface)> NativeHandle;
	};
}
#endif // _XGeom_OsculatingSurface_HeaderFile
