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

#ifndef _xgce_MakeCone_HeaderFile
#define _xgce_MakeCone_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <gp_Cone.hxx>
#include <gce_Root.hxx>
#include <Standard_Real.hxx>
class StdFail_NotDone;
class gp_Ax2;
class gp_Cone;
class gp_Pnt;
class gp_Ax1;
class gp_Lin;


//! This class implements the following algorithms used
//! to create a Cone from gp.
//! * Create a Cone coaxial to another and passing
//! through a point.
//! * Create a Cone coaxial to another at a distance
//! <Dist>.
//! * Create a Cone by 4 points.
//! * Create a Cone by its axis and 2 points.
//! * Create a Cone by 2 points and 2 radius.
//! * Create a Cone by an Ax2 an angle and the radius of
//! its reference section.
public ref class xgce_MakeCone  : public gce_Root
{
public:

  //DEFINE_STANDARD_ALLOC

  

  //! Creates an infinite conical surface. A2 locates the cone
  //! in the space and defines the reference plane of the surface.
  //! Ang is the conical surface semi-angle between 0 and PI/2 radians.
  //! Radius is the radius of the circle in the reference plane of
  //! the cone.
  //! If Radius is lower than 0.0 the status is "
  //! If Ang < Resolution from gp  or Ang >= (PI/2) - Resolution.
  gce_MakeCone(gp_Ax2^ A2, Standard_Real Ang, Standard_Real Radius);
  
  //! Makes a Cone from gp <TheCone> coaxial to another
  //! Cone <Cone> and passing through a Pnt <Point>.
  gce_MakeCone(gp_Cone^ Cone, gp_Pnt^ Point);
  
  //! Makes a Cone from gp <TheCone> coaxial to another
  //! Cone <Cone> at the distance <Dist> which can
  //! be greater or lower than zero.
  gce_MakeCone(gp_Cone^ Cone, Standard_Real Dist);
  
  //! Makes a Cone from gp <TheCone> by four points <P1>,
  //! <P2>,<P3> and <P4>.
  //! Its axis is <P1P2> and the radius of its base is
  //! the distance between <P3> and <P1P2>.
  //! The distance between <P4> and <P1P2> is the radius of
  //! the section passing through <P4>.
  //! If <P1> and <P2> are confused or <P3> and <P4> are
  //! confused we have the status "ConfusedPoints"
  //! if <P1>,<P2>,<P3>,<P4> are colinear we have the
  //! status "ColinearPoints"
  //! If <P3P4> is perpendicular to <P1P2> we have the
  //! status "NullAngle".
  //! <P3P4> is colinear to <P1P2> we have the status
  //! "NullAngle".
  gce_MakeCone(gp_Pnt^ P1, gp_Pnt^ P2, gp_Pnt^ P3, gp_Pnt^ P4);
  
  //! Makes a Cone by its axis <Axis> and and two points.
  //! The distance between <P1> and the axis is the radius
  //! of the section passing through <P1>.
  //! The distance between <P2> and the axis is the radius
  //! of the section passing through <P2>.
  //! If <P1P2> is colinear to <Axis> we have the status
  //! "NullAngle"
  //! If <P3P4> is perpendicular to <Axis> we have the status
  //! "NullAngle"
  //! If <P1> and <P2> are confused we have the status
  //! "ConfusedPoints"
  gce_MakeCone(gp_Ax1^ Axis, gp_Pnt^ P1, gp_Pnt^ P2);
  
  //! Makes a Cone by its axis <Axis> and and two points.
  //! The distance between <P1> and the axis is the radius
  //! of the section passing through <P1>
  //! The distance between <P2> and the axis is the radius
  //! of the section passing through <P2>
  //! If <P1P2> is colinear to <Axis> we have the status
  //! "NullAngle"
  //! If <P3P4> is perpendicular to <Axis> we have the status
  //! "NullAngle"
  //! If <P1> and <P2> are confused we have the status
  //! "ConfusedPoints"
  gce_MakeCone(gp_Lin^ Axis, gp_Pnt^ P1, gp_Pnt^ P2);
  
  //! Makes a Cone with two points and two radius.
  //! The axis of the solution is the line passing through
  //! <P1> and <P2>.
  //! <R1> is the radius of the section passing through <P1>
  //! and <R2> the radius of the section passing through <P2>.
  //! If <P1> and <P2> are confused we have the status "NullAxis".
  //! Warning
  //! If an error occurs (that is, when IsDone returns
  //! false), the Status function returns:
  //! -   gce_NegativeRadius if Radius, R1 or R2 is less than 0.0;
  //! -   gce_BadAngle if Ang is less than
  //! gp::Resolution() or greater than Pi/2.- gp::Resolution();
  //! -   gce_ConfusedPoints if P1 and P2 or P3 and P4 are coincident;
  //! -   gce_NullAxis if the points P1 and P2, are coincident (5th syntax only);
  //! -   gce_NullAngle if:
  //! -   the vector joining P1 to P2 is parallel to either
  //! Axis or the line joining P3 to P4, or
  //! -   R1 and R2 are equal, (that is, their difference is
  //! less than gp::Resolution()); or
  //! -   gce_NullRadius if:
  //! -   the vector joining P1 to P2 is perpendicular to the line joining P3 to P4,
  //! -   the vector joining P1 to P2 is perpendicular to Axis, or
  //! -   P1, P2, P3, and P4 are collinear.
  gce_MakeCone(gp_Pnt^ P1, gp_Pnt^ P2, Standard_Real R1, Standard_Real R2);
  
  //! Returns theructed cone.
  //! Exceptions StdFail_NotDone if no cone isructed.
  gp_Cone^ Value();
  
  gp_Cone^ Operator();
operator gp_Cone();




protected:





private:



  gp_Cone TheCone;


};







#endif // _xgce_MakeCone_HeaderFile
