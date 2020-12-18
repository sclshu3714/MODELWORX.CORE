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

#ifndef _xgce_MakeLin_HeaderFile
#define _xgce_MakeLin_HeaderFile
#pragma once
#include <gce_MakeLin.hxx>
#include <xgce_Root.h>
#include <xgp_Ax2d.h>
#include <xgp_Pnt2d.h>
#include <xgp_Dir2d.h>
#include <xgp_Lin.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <gp_Lin.hxx>
#include <gce_Root.hxx>
class StdFail_NotDone;
class gp_Ax1;
class gp_Pnt;
class gp_Dir;
class gp_Lin;

using namespace TKMath;
namespace TKGeomBase {
	ref class TKMath::xgp_Ax1;
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Dir;
	ref class TKMath::xgp_Lin;
	//! This class implements the following algorithms used
	//! to create a Lin from gp.
	//! * Create a Lin parallel to another and passing
	//! through a point.
	//! * Create a Lin passing through 2 points.
	//! * Create a lin from its axis (Ax1 from gp).
	//! * Create a lin from a point and a direction.
	public ref class xgce_MakeLin : public xgce_Root
	{
	public:

		//DEFINE_STANDARD_ALLOC


		//! Creates a line located along the axis A1.
		gce_MakeLin(gp_Ax1^ A1);


		//! <P> is the location point (origin) of the line and
		//! <V> is the direction of the line.
		gce_MakeLin(gp_Pnt^ P, gp_Dir^ V);

		//! Make a Lin from gp <TheLin> parallel to another
		//! Lin <Lin> and passing through a Pnt <Point>.
		gce_MakeLin(gp_Lin^ Lin, gp_Pnt^ Point);

		//! Make a Lin from gp <TheLin> passing through 2
		//! Pnt <P1>,<P2>.
		//! It returns false if <p1> and <P2> are confused.
		gce_MakeLin(gp_Pnt^ P1, gp_Pnt^ P2);

		//! Returns theructed line.
		//! Exceptions StdFail_NotDone is raised if no line isructed.
		gp_Lin^ Value();

		gp_Lin^ Operator();
		operator gp_Lin();




	protected:





	private:



		gp_Lin TheLin;


	};
}
#endif // _xgce_MakeLin_HeaderFile
