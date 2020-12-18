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

#ifndef _xgce_MakeDir_HeaderFile
#define _xgce_MakeDir_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <gp_Dir.hxx>
#include <gce_Root.hxx>
#include <Standard_Real.hxx>
class StdFail_NotDone;
class gp_Vec;
class gp_XYZ;
class gp_Pnt;
class gp_Dir;


//! This class implements the following algorithms used
//! to create a Dir from gp.
//! * Create a Dir parallel to another and passing
//! through a point.
//! * Create a Dir passing through 2 points.
//! * Create a Dir from its axis (Ax1 from gp).
//! * Create a Dir from a point and a direction.
public ref class xgce_MakeDir  : public gce_Root
{
public:

  //DEFINE_STANDARD_ALLOC

  
  //! Normalizes the vector V and creates a direction.
  //! Status is "NullVector" if V.Magnitude() <= Resolution.
  gce_MakeDir(gp_Vec^ V);
  
  //! Creates a direction from a triplet of coordinates.
  //! Status is "NullVector" if Coord.Modulus() <=
  //! Resolution from gp.
  gce_MakeDir(gp_XYZ^ Coord);
  
  //! Creates a direction with its 3 cartesian coordinates.
  //! Status is "NullVector" if Sqrt(Xv*Xv + Yv*Yv + Zv*Zv)
  //! <= Resolution
  gce_MakeDir(Standard_Real Xv, Standard_Real Yv, Standard_Real Zv);
  
  //! Make a Dir from gp <TheDir> passing through 2
  //! Pnt <P1>,<P2>.
  //! Status is "ConfusedPoints" if <p1> and <P2> are confused.
  //! Warning
  //! If an error occurs (that is, when IsDone returns
  //! false), the Status function returns:
  //! -   gce_ConfusedPoints if points P1 and P2 are coincident, or
  //! -   gce_NullVector if one of the following is less
  //! than or equal to gp::Resolution():
  //! -   the magnitude of vector V,
  //! -   the modulus of Coord,
  //! -   Sqrt(Xv*Xv + Yv*Yv + Zv*Zv).
  gce_MakeDir(gp_Pnt^ P1, gp_Pnt^ P2);
  
  //! Returns theructed unit vector.
  //! Exceptions StdFail_NotDone if no unit vector isructed.
  gp_Dir^ Value();
  
  gp_Dir^ Operator();
operator gp_Dir();




protected:





private:



  gp_Dir TheDir;


};







#endif // _xgce_MakeDir_HeaderFile
