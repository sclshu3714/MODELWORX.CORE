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

#ifndef _xgce_MakeDir2d_HeaderFile
#define _xgce_MakeDir2d_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <gp_Dir2d.hxx>
#include <gce_Root.hxx>
#include <Standard_Real.hxx>
class StdFail_NotDone;
class gp_Vec2d;
class gp_XY;
class gp_Pnt2d;
class gp_Dir2d;


//! This class implements the following algorithms used
//! to create a Dir2d from gp.
//! * Create a Dir2d with 2 points.
//! * Create a Dir2d with a Vec2d.
//! * Create a Dir2d with a XY from gp.
//! * Create a Dir2d with a 2 Reals (Coordinates).
public ref class xgce_MakeDir2d  : public gce_Root
{
public:

  //DEFINE_STANDARD_ALLOC

  
  //! Normalizes the vector V and creates a direction.
  //! Status is "NullVector" if V.Magnitude() <= Resolution.
  gce_MakeDir2d(gp_Vec2d^ V);
  
  //! Creates a direction from a triplet of coordinates.
  //! Status is "NullVector" if Coord.Modulus() <=
  //! Resolution from gp.
  gce_MakeDir2d(gp_XY^ Coord);
  
  //! Creates a direction with its 3 cartesian coordinates.
  //! Status is "NullVector" if Sqrt(Xv*Xv + Yv*Yv )
  //! <= Resolution
  gce_MakeDir2d(Standard_Real Xv, Standard_Real Yv);
  
  //! Make a Dir2d from gp <TheDir> passing through 2
  //! Pnt <P1>,<P2>.
  //! Status is "ConfusedPoints" if <P1> and <P2> are confused.
  //! Warning
  //! If an error occurs (that is, when IsDone returns
  //! false), the Status function returns:
  //! -   gce_ConfusedPoints if points P1 and P2 are coincident, or
  //! -   gce_NullVector if one of the following is less
  //! than or equal to gp::Resolution():
  //! -   the magnitude of vector V,
  //! -   the modulus of Coord,
  //! -   Sqrt(Xv*Xv + Yv*Yv).
  gce_MakeDir2d(gp_Pnt2d^ P1, gp_Pnt2d^ P2);
  
  //! Returns theructed unit vector.
  //! Exceptions StdFail_NotDone if no unit vector isructed.
  gp_Dir2d^ Value();
  
  gp_Dir2d^ Operator();
operator gp_Dir2d();




protected:





private:



  gp_Dir2d TheDir2d;


};







#endif // _xgce_MakeDir2d_HeaderFile
