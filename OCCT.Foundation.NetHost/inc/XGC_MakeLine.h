// Created on: 1992-09-28
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

#ifndef _XGC_MakeLine_HeaderFile
#define _XGC_MakeLine_HeaderFile
#pragma once
#include <NCollection_Haft.h>
#include <XGC_Root.h>
#include <GC_MakeLine.hxx>
#include <xgp_Ax1.h>
#include <xgp_Lin.h>
#include <xgp_Pnt.h>
#include <xgp_Dir.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <GC_Root.hxx>
#include <Geom_Line.hxx>
#include <XGeom_Line.h>

class StdFail_NotDone;
class gp_Ax1;
class gp_Lin;
class gp_Pnt;
class gp_Dir;

using namespace TKMath;
using namespace TKG3d;
namespace TKGeomBase {
	ref class TKMath::xgp_Ax1;
	ref class TKMath::xgp_Lin;
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Dir;
	ref class TKG3d::XGeom_Line;
	//! This class implements the following algorithms used
	//! to create a Line from Geom.
	//! * Create a Line parallel to another and passing
	//! through a point.
	//! * Create a Line passing through 2 points.
	//! A MakeLine object provides a framework for:
	//! -   defining the construction of the line,
	//! -   implementing the construction algorithm, and
	//! -   consulting the results. In particular, the Value
	//! function returns the constructed line.
	public ref class XGC_MakeLine : public XGC_Root
	{
	public:

		//! DEFINE_STANDARD_ALLOC


		XGC_MakeLine();

		XGC_MakeLine(GC_MakeLine* pos);

		void SetMakeLine(GC_MakeLine* pos);

		virtual GC_MakeLine* GetMakeLine();

		virtual GC_Root* GetRoot() Standard_OVERRIDE;

		//! Creates a line located in 3D space with the axis placement A1.
		//! The Location of A1 is the origin of the line.
		XGC_MakeLine(xgp_Ax1^ A1);


		//! Creates a line from a non persistent line from package gp.
		XGC_MakeLine(xgp_Lin^ L);


		//! P is the origin and V is the direction of the line.
		XGC_MakeLine(xgp_Pnt^ P, xgp_Dir^ V);

		//! Make a Line from Geom <TheLin> parallel to another
		//! Lin <Lin> and passing through a Pnt <Point>.
		XGC_MakeLine(xgp_Lin^ Lin, xgp_Pnt^ Point);

		//! Make a Line from Geom <TheLin> passing through 2
		//! Pnt <P1>,<P2>.
		//! It returns false if <p1> and <P2> are confused.
		//! Warning
		//! If the points P1 and P2 are coincident (that is, when
		//! IsDone returns false), the Status function returns gce_ConfusedPoints.
		XGC_MakeLine(xgp_Pnt^ P1, xgp_Pnt^ P2);

		//! Returns the constructed line.
		//! Exceptions StdFail_NotDone if no line is constructed.
		XGeom_Line^ Value();

		operator XGeom_Line^() { return Value(); }

		//! Returns true if the construction is successful.
		virtual Standard_Boolean IsDone() Standard_OVERRIDE;

		//! Returns the status of the construction:
		//! -   gce_Done, if the construction is successful, or
		//! -   another value of the gce_ErrorType enumeration
		//! indicating why the construction failed.
		virtual xgce_ErrorType Status() Standard_OVERRIDE;

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		property  GC_MakeLine* IHandle {
			GC_MakeLine* get() {
				return 	NativeHandle;
			}
			void set(GC_MakeLine* handle) {
				NativeHandle = handle;
			}
		}

	private:
		GC_MakeLine* NativeHandle;
	};
}
#endif // _XGC_MakeLine_HeaderFile
