// Created on: 1992-08-26
// Created by: Remi GILET
// Copyright (c) 1992-1999 Matra Datavision
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

#ifndef _xgce_MakeTranslation_HeaderFile
#define _xgce_MakeTranslation_HeaderFile
#pragma once
#include <gce_MakeTranslation.hxx>
#include <xgp_Vec.h>
#include <xgp_Pnt.h>
#include <xgp_Trsf.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <gp_Trsf.hxx>
class gp_Vec;
class gp_Pnt;
class gp_Trsf;

using namespace TKMath;

namespace TKGeomBase {
	ref class TKMath::xgp_Vec;
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Trsf;
	//! This class implements elementaryruction algorithms for a
	//! translation in 3D space. The result is a gp_Trsf transformation.
	//! A MakeTranslation object provides a framework for:
	//! -   defining theruction of the transformation,
	//! -   implementing theruction algorithm, and
	//! -   consulting the result.
	public ref class xgce_MakeTranslation
	{
	public:

		//DEFINE_STANDARD_ALLOC
		//DEFINE_STANDARD_ALLOC
		xgce_MakeTranslation();

		xgce_MakeTranslation(gce_MakeTranslation* pos);

		void SetMakeTranslation(gce_MakeTranslation* pos);

		virtual gce_MakeTranslation* GetMakeTranslation();

		//! Constructs a translation along the vector " Vect"
		xgce_MakeTranslation(xgp_Vec^ Vect);

		//! Constructs a translation along the vector
		//! (Point1,Point2) defined from the point Point1 to the point Point2.
		xgce_MakeTranslation(xgp_Pnt^ Point1, xgp_Pnt^ Point2);


		//! Returns theructed transformation.
		xgp_Trsf^ Value();

		xgp_Trsf^ Operator();
		operator xgp_Trsf^();

		/// <summary>
		/// ���ؾ��
		/// </summary>
		property gce_MakeTranslation* IHandle {
			gce_MakeTranslation* get() {
				return 	NativeHandle;
			}
			void set(gce_MakeTranslation* handle) {
				NativeHandle = handle;
			}
		}

	private:
		gce_MakeTranslation* NativeHandle;
	};
}
#endif // _xgce_MakeTranslation_HeaderFile
