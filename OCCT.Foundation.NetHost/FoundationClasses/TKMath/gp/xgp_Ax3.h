// Created on: 1993-08-02
// Created by: Laurent BOURESCHE
// Copyright (c) 1993-1999 Matra Datavision
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
//! Describes a coordinate system in 3D space. Unlike a
//! xgp_Ax2 coordinate system, a xgp_Ax3 can be
//! right-handed ("direct sense") or left-handed ("indirect sense").
//! A coordinate system is defined by:
//! -   its origin (also referred to as its "Location point"), and
//! -   three orthogonal unit vectors, termed the "X
//! Direction", the "Y Direction" and the "Direction" (also
//! referred to as the "main Direction").
//! The "Direction" of the coordinate system is called its
//! "main Direction" because whenever this unit vector is
//! modified, the "X Direction" and the "Y Direction" are
//! recomputed. However, when we modify either the "X
//! Direction" or the "Y Direction", "Direction" is not modified.
//! "Direction" is also the "Z Direction".
//! The "main Direction" is always parallel to the cross
//! product of its "X Direction" and "Y Direction".
//! If the coordinate system is right-handed, it satisfies the equation:
//! "main Direction" = "X Direction" ^ "Y Direction"
//! and if it is left-handed, it satisfies the equation:
//! "main Direction" = -"X Direction" ^ "Y Direction"
//! A coordinate system is used:
//! -   to describe geometric entities, in particular to position
//! them. The local coordinate system of a geometric
//! entity serves the same purpose as the STEP function
//! "axis placement three axes", or
//! -   to define geometric transformations.
//! Note:
//! -   We refer to the "X Axis", "Y Axis" and "Z Axis",
//! respectively, as the axes having:
//! -   the origin of the coordinate system as their origin, and
//! -   the unit vectors "X Direction", "Y Direction" and
//! "main Direction", respectively, as their unit vectors.
//! -   The "Z Axis" is also the "main Axis".
//! -   xgp_Ax2 is used to define a coordinate system that must be always right-handed.


#ifndef _xgp_Ax3_HeaderFile
#define _xgp_Ax3_HeaderFile
#pragma once
#include <gp_Ax3.hxx>
#include "xgp_Ax1.h"
#include "xgp_Ax2.h"
#include "xgp_Trsf.h"

namespace TKMath
{
    ref class xgp_Ax1;
    ref class xgp_Ax2;
    ref class xgp_Pnt;
    ref class xgp_Dir;
    ref class xgp_Trsf;
    ref class xgp_Vec;
    public ref class xgp_Ax3
    {
    public:
        //! Creates an object corresponding to the reference
        //! coordinate system (OXYZ).
        xgp_Ax3(void);

        /// <summary>
        /// 指针映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Ax3(gp_Ax3* pos);

        //! Creates  a  coordinate  system from a right-handed
        //! coordinate system.
        xgp_Ax3(xgp_Ax2^ A);

        //! Creates a  right handed axis placement with the
        //! "Location"  point  P  and  two  directions, N    gives the
        //! "Direction" and Vx gives the "XDirection".
        //! Raises ConstructionError if N and Vx are parallel (same or opposite orientation).
        xgp_Ax3(xgp_Pnt^ P, xgp_Dir^ N, xgp_Dir^ Vx);


        //! Creates an axis placement with the  "Location" point <P>
        //! and the normal direction <V>.
        xgp_Ax3(xgp_Pnt^ P, xgp_Dir^ V);

        //释放
        ~xgp_Ax3();
        //释放
        !xgp_Ax3();
        //! Return the gp_Ax3
        gp_Ax3* GetAx3();

        //! Reverses the X direction of <me>.
        void XReverse();

        //! Reverses the Y direction of <me>.
        void YReverse();

        //! Reverses the Z direction of <me>.
        void ZReverse();

        //! Assigns the origin and "main Direction" of the axis A1 to
        //! this coordinate system, then recomputes its "X Direction" and "Y Direction".
        //! Note:
        //! -   The new "X Direction" is computed as follows:
        //! new "X Direction" = V1 ^(previous "X Direction" ^ V)
        //! where V is the "Direction" of A1.
        //! -   The orientation of this coordinate system
        //! (right-handed or left-handed) is not modified.
        //! Raises ConstructionError  if the "Direction" of <A1> and the "XDirection" of <me>
        //! are parallel (same or opposite orientation) because it is
        //! impossible to calculate the new "XDirection" and the new
        //! "YDirection".
        void SetAxis(xgp_Ax1^ A1);


        //! Changes the main direction of this coordinate system,
        //! then recomputes its "X Direction" and "Y Direction".
        //! Note:
        //! -   The new "X Direction" is computed as follows:
        //! new "X Direction" = V ^ (previous "X Direction" ^ V).
        //! -   The orientation of this coordinate system (left- or right-handed) is not modified.
        //! Raises ConstructionError if <V< and the previous "XDirection" are parallel
        //! because it is impossible to calculate the new "XDirection"
        //! and the new "YDirection".
        void SetDirection(xgp_Dir^ V);


        //! Changes the "Location" point (origin) of <me>.
        void SetLocation(xgp_Pnt^ P);


        //! Changes the "Xdirection" of <me>. The main direction
        //! "Direction" is not modified, the "Ydirection" is modified.
        //! If <Vx> is not normal to the main direction then <XDirection>
        //! is computed as follows XDirection = Direction ^ (Vx ^ Direction).
        //! Raises ConstructionError if <Vx> is parallel (same or opposite
        //! orientation) to the main direction of <me>
        void SetXDirection(xgp_Dir^ Vx);


        //! Changes the "Ydirection" of <me>. The main direction is not
        //! modified but the "Xdirection" is changed.
        //! If <Vy> is not normal to the main direction then "YDirection"
        //! is computed as  follows
        //! YDirection = Direction ^ (<Vy> ^ Direction).
        //! Raises ConstructionError if <Vy> is parallel to the main direction of <me>
        void SetYDirection(xgp_Dir^ Vy);


        //! Computes the angular value between the main direction of
        //! <me> and the main direction of <Other>. Returns the angle
        //! between 0 and PI in radians.
        Standard_Real Angle(xgp_Ax3^ Other);


        //! Returns the main axis of <me>. It is the "Location" point
        //! and the main "Direction".
        xgp_Ax1^ Axis();

        //! Computes a right-handed coordinate system with the
        //! same "X Direction" and "Y Direction" as those of this
        //! coordinate system, then recomputes the "main Direction".
        //! If this coordinate system is right-handed, the result
        //! returned is the same coordinate system. If this
        //! coordinate system is left-handed, the result is reversed.
        xgp_Ax2^ Ax2();


        //! Returns the main direction of <me>.
        xgp_Dir^ Direction();


        //! Returns the "Location" point (origin) of <me>.
        xgp_Pnt^ Location();


        //! Returns the "XDirection" of <me>.
        xgp_Dir^ XDirection();


        //! Returns the "YDirection" of <me>.
        xgp_Dir^ YDirection();

        //! Returns  True if  the  coordinate  system is right-handed. i.e.
        //! XDirection().Crossed(YDirection()).Dot(Direction()) > 0
        Standard_Boolean Direct();


        //! Returns True if
        //! . the distance between the "Location" point of <me> and
        //! <Other> is lower or equal to LinearTolerance and
        //! . the distance between the "Location" point of <Other> and
        //! <me> is lower or equal to LinearTolerance and
        //! . the main direction of <me> and the main direction of
        //! <Other> are parallel (same or opposite orientation).
        Standard_Boolean IsCoplanar(xgp_Ax3^ Other, Standard_Real LinearTolerance, Standard_Real AngularTolerance);

        //! Returns True if
        //! . the distance between <me> and the "Location" point of A1
        //! is lower of equal to LinearTolerance and
        //! . the distance between A1 and the "Location" point of <me>
        //! is lower or equal to LinearTolerance and
        //! . the main direction of <me> and the direction of A1 are normal.
        Standard_Boolean IsCoplanar(xgp_Ax1^ A1, Standard_Real LinearTolerance, Standard_Real AngularTolerance);

        void Mirror(xgp_Pnt^ P);


        //! Performs the symmetrical transformation of an axis
        //! placement with respect to the point P which is the
        //! center of the symmetry.
        //! Warnings :
        //! The main direction of the axis placement is not changed.
        //! The "XDirection" and the "YDirection" are reversed.
        //! So the axis placement stay right handed.
        xgp_Ax3^ Mirrored(xgp_Pnt^ P);

        void Mirror(xgp_Ax1^ A1);


        //! Performs the symmetrical transformation of an axis
        //! placement with respect to an axis placement which
        //! is the axis of the symmetry.
        //! The transformation is performed on the "Location"
        //! point, on the "XDirection" and "YDirection".
        //! The resulting main "Direction" is the cross product between
        //! the "XDirection" and the "YDirection" after transformation.
        xgp_Ax3^ Mirrored(xgp_Ax1^ A1);

        void Mirror(xgp_Ax2^ A2);


        //! Performs the symmetrical transformation of an axis
        //! placement with respect to a plane.
        //! The axis placement  <A2> locates the plane of the symmetry :
        //! (Location, XDirection, YDirection).
        //! The transformation is performed on the "Location"
        //! point, on the "XDirection" and "YDirection".
        //! The resulting main "Direction" is the cross product between
        //! the "XDirection" and the "YDirection" after transformation.
        xgp_Ax3^ Mirrored(xgp_Ax2^ A2);

        void Rotate(xgp_Ax1^ A1, Standard_Real Ang);


        //! Rotates an axis placement. <A1> is the axis of the
        //! rotation . Ang is the angular value of the rotation
        //! in radians.
        xgp_Ax3^ Rotated(xgp_Ax1^ A1, Standard_Real Ang);

        void Scale(xgp_Pnt^ P, Standard_Real S);


        //! Applies a scaling transformation on the axis placement.
        //! The "Location" point of the axisplacement is modified.
        //! Warnings :
        //! If the scale <S> is negative :
        //! . the main direction of the axis placement is not changed.
        //! . The "XDirection" and the "YDirection" are reversed.
        //! So the axis placement stay right handed.
        xgp_Ax3^ Scaled(xgp_Pnt^ P, Standard_Real S);

        void Transform(xgp_Trsf^ T);


        //! Transforms an axis placement with a Trsf.
        //! The "Location" point, the "XDirection" and the
        //! "YDirection" are transformed with T.  The resulting
        //! main "Direction" of <me> is the cross product between
        //! the "XDirection" and the "YDirection" after transformation.
        xgp_Ax3^ Transformed(xgp_Trsf^ T);

        void Translate(xgp_Vec^ V);


        //! Translates an axis plaxement in the direction of the vector
        //! <V>. The magnitude of the translation is the vector's magnitude.
        xgp_Ax3^ Translated(xgp_Vec^ V);

        void Translate(xgp_Pnt^ P1, xgp_Pnt^ P2);


        //! Translates an axis placement from the point <P1> to the
        //! point <P2>.
        xgp_Ax3^ Translated(xgp_Pnt^ P1, xgp_Pnt^ P2);

        /// <summary>
        /// 本地句柄
        /// </summary>
        property gp_Ax3* Handle
        {
            gp_Ax3* get() {
                return NativeHandle;
            }
        }

    private:
        gp_Ax3* NativeHandle;
    };
}
#endif // _xgp_Ax3_HeaderFile