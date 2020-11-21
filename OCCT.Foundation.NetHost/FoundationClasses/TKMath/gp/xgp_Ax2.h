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
//! Describes a right-handed coordinate system in 3D space.
//! A coordinate system is defined by:
//! -   its origin (also referred to as its "Location point"), and
//! -   three orthogonal unit vectors, termed respectively the
//! "X Direction", the "Y Direction" and the "Direction" (also
//! referred to as the "main Direction").
//! The "Direction" of the coordinate system is called its
//! "main Direction" because whenever this unit vector is
//! modified, the "X Direction" and the "Y Direction" are
//! recomputed. However, when we modify either the "X
//! Direction" or the "Y Direction", "Direction" is not modified.
//! The "main Direction" is also the "Z Direction".
//! Since an Ax2 coordinate system is right-handed, its
//! "main Direction" is always equal to the cross product of
//! its "X Direction" and "Y Direction". (To define a
//! left-handed coordinate system, use xgp_Ax3.)
//! A coordinate system is used:
//! -   to describe geometric entities, in particular to position
//! them. The local coordinate system of a geometric
//! entity serves the same purpose as the STEP function
//! "axis placement two axes", or
//! -   to define geometric transformations.
//! Note: we refer to the "X Axis", "Y Axis" and "Z Axis",
//! respectively, as to axes having:
//! - the origin of the coordinate system as their origin, and
//! -   the unit vectors "X Direction", "Y Direction" and "main
//! Direction", respectively, as their unit vectors.
//! The "Z Axis" is also the "main Axis".

#ifndef _xgp_Ax2_HeaderFile
#define _xgp_Ax2_HeaderFile
#pragma once
#include <gp_Ax2.hxx>
#include "xgp_Pnt.h"
#include "xgp_Dir.h"
#include "xgp_Vec.h"
#include "xgp_Ax1.h"
#include "xgp_Trsf.h"

namespace TKMath
{
    ref class xgp_Pnt;
    ref class xgp_Dir;
    ref class xgp_Vec;
    ref class xgp_Ax1;
    ref class xgp_Trsf;
    public ref class xgp_Ax2
    {
    public:
        //! Creates an object corresponding to the reference
        //! coordinate system (OXYZ).
        xgp_Ax2(void);

        /// <summary>
        /// 指针映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Ax2(gp_Ax2* pos);

        /// <summary>
        ///  映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Ax2(gp_Ax2 pos);
        //! Creates an axis placement with an origin P such that:
        //! -   N is the Direction, and
        //! -   the "X Direction" is normal to N, in the plane
        //! defined by the vectors (N, Vx): "X
        //! Direction" = (N ^ Vx) ^ N,
        //! Exception: raises ConstructionError if N and Vx are parallel (same or opposite orientation).
        xgp_Ax2(xgp_Pnt^ P, xgp_Dir^ N, xgp_Dir^ Vx);

        //! Creates an axis placement with an origin P such that:
        //! -   N is the Direction, and
        //! -   the "X Direction" is normal to N, in the plane
        //! defined by the vectors (N, Vx): "X
        //! Direction" = (N ^ Vx) ^ N,
        //! Exception: raises ConstructionError if N and Vx are parallel (same or opposite orientation).
        xgp_Ax2(gp_Pnt P, gp_Dir N, gp_Dir Vx);

        //! Creates -   a coordinate system with an origin P, where V
        //! gives the "main Direction" (here, "X Direction" and "Y
        //! Direction" are defined automatically).
        xgp_Ax2(xgp_Pnt^ P, xgp_Dir^ V);

        //! Creates -   a coordinate system with an origin P, where V
       //! gives the "main Direction" (here, "X Direction" and "Y
       //! Direction" are defined automatically).
        xgp_Ax2(gp_Pnt P, gp_Dir V);

        //释放
        ~xgp_Ax2();
        //释放
        !xgp_Ax2();

        //! Assigns the origin and "main Direction" of the axis A1 to
        //! this coordinate system, then recomputes its "X Direction" and "Y Direction".
        //! Note: The new "X Direction" is computed as follows:
        //! new "X Direction" = V1 ^(previous "X Direction" ^ V)
        //! where V is the "Direction" of A1.
        //! Exceptions
        //! Standard_ConstructionError if A1 is parallel to the "X
        //! Direction" of this coordinate system.
        void SetAxis(xgp_Ax1^ A1);


        //! Changes the "main Direction" of this coordinate system,
        //! then recomputes its "X Direction" and "Y Direction".
        //! Note: the new "X Direction" is computed as follows:
        //! new "X Direction" = V ^ (previous "X Direction" ^ V)
        //! Exceptions
        //! Standard_ConstructionError if V is parallel to the "X
        //! Direction" of this coordinate system.
        void SetDirection(xgp_Dir^ V);


        //! Changes the "Location" point (origin) of <me>.
        void SetLocation(xgp_Pnt^ P);


        //! Changes the "Xdirection" of <me>. The main direction
        //! "Direction" is not modified, the "Ydirection" is modified.
        //! If <Vx> is not normal to the main direction then <XDirection>
        //! is computed as follows XDirection = Direction ^ (Vx ^ Direction).
        //! Exceptions
        //! Standard_ConstructionError if Vx or Vy is parallel to
        //! the "main Direction" of this coordinate system.
        void SetXDirection(xgp_Dir^ Vx);


        //! Changes the "Ydirection" of <me>. The main direction is not
        //! modified but the "Xdirection" is changed.
        //! If <Vy> is not normal to the main direction then "YDirection"
        //! is computed as  follows
        //! YDirection = Direction ^ (<Vy> ^ Direction).
        //! Exceptions
        //! Standard_ConstructionError if Vx or Vy is parallel to
        //! the "main Direction" of this coordinate system.
        void SetYDirection(xgp_Dir^ Vy);


        //! Computes the angular value, in radians, between the main direction of
        //! <me> and the main direction of <Other>. Returns the angle
        //! between 0 and PI in radians.
        Standard_Real^ Angle(xgp_Ax2^ Other);

        //获取gp_Ax2
        gp_Ax2 GetAx2();

        //! Returns the main axis of <me>. It is the "Location" point
        //! and the main "Direction".
        xgp_Ax1^ Axis();


        //! Returns the main direction of <me>.
        xgp_Dir^ Direction();


        //! Returns the "Location" point (origin) of <me>.
        xgp_Pnt^ Location();


        //! Returns the "XDirection" of <me>.
        xgp_Dir^ XDirection();


        //! Returns the "YDirection" of <me>.
        xgp_Dir^ YDirection();

        Standard_Boolean^ IsCoplanar(xgp_Ax2^ Other, Standard_Real^ LinearTolerance, Standard_Real^ AngularTolerance);


        //! Returns True if
        //! . the distance between <me> and the "Location" point of A1
        //! is lower of equal to LinearTolerance and
        //! . the main direction of <me> and the direction of A1 are normal.
        //! Note: the tolerance criterion for angular equality is given by AngularTolerance.
        Standard_Boolean^ IsCoplanar(xgp_Ax1^ A1, Standard_Real^ LinearTolerance, Standard_Real^ AngularTolerance);


        //! Performs a symmetrical transformation of this coordinate
        //! system with respect to:
        //! -   the point P, and assigns the result to this coordinate system.
        //! Warning
        //! This transformation is always performed on the origin.
        //! In case of a reflection with respect to a point:
        //! - the main direction of the coordinate system is not changed, and
        //! - the "X Direction" and the "Y Direction" are simply reversed
        //! In case of a reflection with respect to an axis or a plane:
        //! -   the transformation is applied to the "X Direction"
        //! and the "Y Direction", then
        //! -   the "main Direction" is recomputed as the cross
        //! product "X Direction" ^ "Y   Direction".
        //! This maintains the right-handed property of the
        //! coordinate system.
        void Mirror(xgp_Pnt^ P);


        //! Performs a symmetrical transformation of this coordinate
        //! system with respect to:
        //! -   the point P, and creates a new one.
        //! Warning
        //! This transformation is always performed on the origin.
        //! In case of a reflection with respect to a point:
        //! - the main direction of the coordinate system is not changed, and
        //! - the "X Direction" and the "Y Direction" are simply reversed
        //! In case of a reflection with respect to an axis or a plane:
        //! -   the transformation is applied to the "X Direction"
        //! and the "Y Direction", then
        //! -   the "main Direction" is recomputed as the cross
        //! product "X Direction" ^ "Y   Direction".
        //! This maintains the right-handed property of the
        //! coordinate system.
        xgp_Ax2^ Mirrored(xgp_Pnt^ P);


        //! Performs a symmetrical transformation of this coordinate
        //! system with respect to:
        //! -   the axis A1, and assigns the result to this coordinate systeme.
        //! Warning
        //! This transformation is always performed on the origin.
        //! In case of a reflection with respect to a point:
        //! - the main direction of the coordinate system is not changed, and
        //! - the "X Direction" and the "Y Direction" are simply reversed
        //! In case of a reflection with respect to an axis or a plane:
        //! -   the transformation is applied to the "X Direction"
        //! and the "Y Direction", then
        //! -   the "main Direction" is recomputed as the cross
        //! product "X Direction" ^ "Y   Direction".
        //! This maintains the right-handed property of the
        //! coordinate system.
        void Mirror(xgp_Ax1^ A1);


        //! Performs a symmetrical transformation of this coordinate
        //! system with respect to:
        //! -   the axis A1, and  creates a new one.
        //! Warning
        //! This transformation is always performed on the origin.
        //! In case of a reflection with respect to a point:
        //! - the main direction of the coordinate system is not changed, and
        //! - the "X Direction" and the "Y Direction" are simply reversed
        //! In case of a reflection with respect to an axis or a plane:
        //! -   the transformation is applied to the "X Direction"
        //! and the "Y Direction", then
        //! -   the "main Direction" is recomputed as the cross
        //! product "X Direction" ^ "Y   Direction".
        //! This maintains the right-handed property of the
        //! coordinate system.
        xgp_Ax2^ Mirrored(xgp_Ax1^ A1);


        //! Performs a symmetrical transformation of this coordinate
        //! system with respect to:
        //! -   the plane defined by the origin, "X Direction" and "Y
        //! Direction" of coordinate system A2 and  assigns the result to this coordinate systeme.
        //! Warning
        //! This transformation is always performed on the origin.
        //! In case of a reflection with respect to a point:
        //! - the main direction of the coordinate system is not changed, and
        //! - the "X Direction" and the "Y Direction" are simply reversed
        //! In case of a reflection with respect to an axis or a plane:
        //! -   the transformation is applied to the "X Direction"
        //! and the "Y Direction", then
        //! -   the "main Direction" is recomputed as the cross
        //! product "X Direction" ^ "Y   Direction".
        //! This maintains the right-handed property of the
        //! coordinate system.
        void Mirror(xgp_Ax2^ A2);


        //! Performs a symmetrical transformation of this coordinate
        //! system with respect to:
        //! -   the plane defined by the origin, "X Direction" and "Y
        //! Direction" of coordinate system A2 and creates a new one.
        //! Warning
        //! This transformation is always performed on the origin.
        //! In case of a reflection with respect to a point:
        //! - the main direction of the coordinate system is not changed, and
        //! - the "X Direction" and the "Y Direction" are simply reversed
        //! In case of a reflection with respect to an axis or a plane:
        //! -   the transformation is applied to the "X Direction"
        //! and the "Y Direction", then
        //! -   the "main Direction" is recomputed as the cross
        //! product "X Direction" ^ "Y   Direction".
        //! This maintains the right-handed property of the
        //! coordinate system.
        xgp_Ax2^ Mirrored(xgp_Ax2^ A2);

        void Rotate(xgp_Ax1^ A1, Standard_Real^ Ang);


        //! Rotates an axis placement. <A1> is the axis of the
        //! rotation . Ang is the angular value of the rotation
        //! in radians.
        xgp_Ax2^ Rotated(xgp_Ax1^ A1, Standard_Real^ Ang);

        void Scale(xgp_Pnt^ P, Standard_Real^ S);


        //! Applies a scaling transformation on the axis placement.
        //! The "Location" point of the axisplacement is modified.
        //! Warnings :
        //! If the scale <S> is negative :
        //! . the main direction of the axis placement is not changed.
        //! . The "XDirection" and the "YDirection" are reversed.
        //! So the axis placement stay right handed.
        xgp_Ax2^ Scaled(xgp_Pnt^ P, Standard_Real^ S);

        void Transform(xgp_Trsf^ T);


        //! Transforms an axis placement with a Trsf.
        //! The "Location" point, the "XDirection" and the
        //! "YDirection" are transformed with T.  The resulting
        //! main "Direction" of <me> is the cross product between
        //! the "XDirection" and the "YDirection" after transformation.
        xgp_Ax2^ Transformed(xgp_Trsf^ T);

        void Translate(xgp_Vec^ V);


        //! Translates an axis plaxement in the direction of the vector
        //! <V>. The magnitude of the translation is the vector's magnitude.
        xgp_Ax2^ Translated(xgp_Vec^ V);

        void Translate(xgp_Pnt^ P1, xgp_Pnt^ P2);


        //! Translates an axis placement from the point <P1> to the
        //! point <P2>.
        xgp_Ax2^ Translated(xgp_Pnt^ P1, xgp_Pnt^ P2);

        /// <summary>
        /// 本地句柄
        /// </summary>
        property gp_Ax2* Handle
        {
            gp_Ax2* get() {
                return NativeHandle;
            }
        }

    private:
        gp_Ax2* NativeHandle;
    };
}
#endif // _xgp_Ax2_HeaderFile