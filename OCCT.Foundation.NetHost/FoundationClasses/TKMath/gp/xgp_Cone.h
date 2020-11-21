// Copyright (c) 1991-1999 Matra Datavision
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
//! Defines an infinite conical surface.
//! A cone is defined by its half-angle (can be negative) at the apex and
//! positioned in space with a coordinate system (a xgp_Ax3
//! object) and a "reference radius" where:
//! -   the "main Axis" of the coordinate system is the axis of   revolution of the cone,
//! -   the plane defined by the origin, the "X Direction" and
//! the "Y Direction" of the coordinate system is the
//! reference plane of the cone; the intersection of the
//! cone with this reference plane is a circle of radius
//! equal to the reference radius,
//! if the half-angle is positive, the apex of the cone is on
//! the negative side of the "main Axis" of the coordinate
//! system. If the half-angle is negative, the apex is on the   positive side.
//! This coordinate system is the "local coordinate system" of the cone.
//! Note: when a xgp_Cone cone is converted into a
//! Geom_ConicalSurface cone, some implicit properties of
//! its local coordinate system are used explicitly:
//! -   its origin, "X Direction", "Y Direction" and "main
//! Direction" are used directly to define the parametric
//! directions on the cone and the origin of the parameters,
//! -   its implicit orientation (right-handed or left-handed)
//! gives the orientation (direct or indirect) of the
//! Geom_ConicalSurface cone.
//! See Also
//! gce_MakeCone which provides functions for more
//! complex cone constructions
//! Geom_ConicalSurface which provides additional
//! functions for constructing cones and works, in particular,
//! with the parametric equations of cones xgp_Ax3

#ifndef _xgp_Cone_HeaderFile
#define _xgp_Cone_HeaderFile
#pragma once
#include <gp_Cone.hxx>
#include "xgp_Ax1.h"
#include "xgp_Ax2.h"
#include "xgp_Ax3.h"
#include "xgp_Pnt.h"
#include "xgp_Trsf.h"
#include "xgp_Vec.h"

namespace TKMath
{
    ref class xgp_Ax1;
    ref class xgp_Ax2;
    ref class xgp_Ax3;
    ref class xgp_Pnt;
    ref class xgp_Trsf;
    ref class xgp_Vec;
    public ref class xgp_Cone
    {
    public:
       
        //! Creates an indefinite Cone.
        xgp_Cone(void);

        /// <summary>
        /// 指针映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Cone(gp_Cone* pos);
        /// <summary>
        ///  映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Cone(gp_Cone pos);

        //! Creates an infinite conical surface. A3 locates the cone
        //! in the space and defines the reference plane of the surface.
        //! Ang is the conical surface semi-angle. Its absolute value is in range
        //! ]0, PI/2[.
        //! Radius is the radius of the circle in the reference plane of
        //! the cone.
        //! Raises ConstructionError
        //! * if Radius is lower than 0.0
        //! * Abs(Ang) < Resolution from gp  or Abs(Ang) >= (PI/2) - Resolution.
        xgp_Cone(xgp_Ax3^ A3, Standard_Real^ Ang, Standard_Real^ Radius);


        //释放
        ~xgp_Cone();
        //释放
        !xgp_Cone();

        //! gp_Cone
        gp_Cone GetCone();

        //! Changes the symmetry axis of the cone.  Raises ConstructionError
        //! the direction of A1 is parallel to the "XDirection"
        //! of the coordinate system of the cone.
        void SetAxis(xgp_Ax1^ A1);

        //! Changes the location of the cone.
        void SetLocation(xgp_Pnt^ Loc);


        //! Changes the local coordinate system of the cone.
        //! This coordinate system defines the reference plane of the cone.
        void SetPosition(xgp_Ax3^ A3);


        //! Changes the radius of the cone in the reference plane of
        //! the cone.
        //! Raised if R < 0.0
        void SetRadius(Standard_Real^ R);


        //! Changes the semi-angle of the cone.
        //! Semi-angle can be negative. Its absolute value
        //! Abs(Ang) is in range ]0,PI/2[.
        //! Raises ConstructionError if Abs(Ang) < Resolution from gp or Abs(Ang) >= PI/2 - Resolution
        void SetSemiAngle(Standard_Real^ Ang);


        //! Computes the cone's top. The Apex of the cone is on the
        //! negative side of the symmetry axis of the cone.
        xgp_Pnt^ Apex();

        //! Reverses the   U   parametrization of   the  cone
        //! reversing the YAxis.
        void UReverse();

        //! Reverses the   V   parametrization of   the  cone  reversing the ZAxis.
        void VReverse();

        //! Returns true if the local coordinate system of this cone is right-handed.
        Standard_Boolean^ Direct();

        //! returns the symmetry axis of the cone.
        xgp_Ax1^ Axis();


        //! Computes the coefficients of the implicit equation of the quadric
        //! in the absolute cartesian coordinates system :
        //! A1.X**2 + A2.Y**2 + A3.Z**2 + 2.(B1.X.Y + B2.X.Z + B3.Y.Z) +
        //! 2.(C1.X + C2.Y + C3.Z) + D = 0.0
        void Coefficients(Standard_Real A1, Standard_Real A2, Standard_Real A3, Standard_Real B1, Standard_Real B2, Standard_Real B3, Standard_Real C1, Standard_Real C2, Standard_Real C3, Standard_Real D);

        //! returns the "Location" point of the cone.
        xgp_Pnt^ Location();


        //! Returns the local coordinates system of the cone.
        xgp_Ax3^ Position();


        //! Returns the radius of the cone in the reference plane.
        Standard_Real^ RefRadius();

        //! Returns the half-angle at the apex of this cone.
        //! Attention! Semi-angle can be negative.
        Standard_Real^ SemiAngle();

        //! Returns the XAxis of the reference plane.
        xgp_Ax1^ XAxis();

        //! Returns the YAxis of the reference plane.
        xgp_Ax1^ YAxis();

        void Mirror(xgp_Pnt^ P);


        //! Performs the symmetrical transformation of a cone
        //! with respect to the point P which is the center of the
        //! symmetry.
        xgp_Cone^ Mirrored(xgp_Pnt^ P);

        void Mirror(xgp_Ax1^ A1);


        //! Performs the symmetrical transformation of a cone with
        //! respect to an axis placement which is the axis of the
        //! symmetry.
        xgp_Cone^ Mirrored(xgp_Ax1^ A1);

        void Mirror(xgp_Ax2^ A2);


        //! Performs the symmetrical transformation of a cone with respect
        //! to a plane. The axis placement A2 locates the plane of the
        //! of the symmetry : (Location, XDirection, YDirection).
        xgp_Cone^ Mirrored(xgp_Ax2^ A2);

        void Rotate(xgp_Ax1^ A1, Standard_Real^ Ang);


        //! Rotates a cone. A1 is the axis of the rotation.
        //! Ang is the angular value of the rotation in radians.
        xgp_Cone^ Rotated(xgp_Ax1^ A1, Standard_Real^ Ang);

        void Scale(xgp_Pnt^ P, Standard_Real^ S);


        //! Scales a cone. S is the scaling value.
        //! The absolute value of S is used to scale the cone
        xgp_Cone^ Scaled(xgp_Pnt^ P, Standard_Real^ S);

        void Transform(xgp_Trsf^ T);


        //! Transforms a cone with the transformation T fromnamespace TKMath  {  public ref class Trsf.
        xgp_Cone^ Transformed(xgp_Trsf^ T);

        void Translate(xgp_Vec^ V);


        //! Translates a cone in the direction of the vector V.
        //! The magnitude of the translation is the vector's magnitude.
        xgp_Cone^ Translated(xgp_Vec^ V);

        void Translate(xgp_Pnt^ P1, xgp_Pnt^ P2);


        //! Translates a cone from the point P1 to the point P2.
        xgp_Cone^ Translated(xgp_Pnt^ P1, xgp_Pnt^ P2);

        /// <summary>
        /// 本地句柄
        /// </summary>
        property gp_Cone* Handle
        {
            gp_Cone* get() {
                return NativeHandle;
            }
        }

    private:
        gp_Cone* NativeHandle;
    };
}
#endif // _xgp_Cone_HeaderFile