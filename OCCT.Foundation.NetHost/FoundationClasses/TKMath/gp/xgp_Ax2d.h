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
//! Describes an axis in the plane (2D space).
//! An axis is defined by:
//! -   its origin (also referred to as its "Location point"),   and
//! -   its unit vector (referred to as its "Direction").
//! An axis implicitly defines a direct, right-handed
//! coordinate system in 2D space by:
//! -   its origin,
//! - its "Direction" (giving the "X Direction" of the coordinate system), and
//! -   the unit vector normal to "Direction" (positive angle
//! measured in the trigonometric sense).
//! An axis is used:
//! -   to describe 2D geometric entities (for example, the
//! axis which defines angular coordinates on a circle).
//! It serves for the same purpose as the STEP function
//! "axis placement one axis", or
//! -   to define geometric transformations (axis of
//! symmetry, axis of rotation, and so on).
//! Note: to define a left-handed 2D coordinate system, use xgp_Ax22d.

#ifndef _xgp_Ax2d_HeaderFile
#define _xgp_Ax2d_HeaderFile
#pragma once
#include <gp_Ax2d.hxx>
#include "xgp_Vec2d.h"
#include "xgp_Trsf2d.h"
#include "xgp_Dir2d.h"
#include "xgp_Pnt2d.h"

namespace TKMath
{
    ref class xgp_Vec2d;
    ref class xgp_Trsf2d;
    ref class xgp_Dir2d;
    ref class xgp_Pnt2d;

    public ref class xgp_Ax2d
    {
    public:

        //! Creates an axis object representing X axis of
        //! the reference co-ordinate system.
        xgp_Ax2d(void);

        /// <summary>
        /// 指针映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Ax2d(gp_Ax2d* pos);
        /// <summary>
        ///  映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Ax2d(gp_Ax2d pos);

        //! Creates an Ax2d. <P> is the "Location" point of
        //! the axis placement and V is the "Direction" of
        //! the axis placement.
        xgp_Ax2d(xgp_Pnt2d^ P, xgp_Dir2d^ V);

        //释放
        ~xgp_Ax2d();
        //释放
        !xgp_Ax2d();

        //! Changes the "Location" point (origin) of <me>.
        void SetLocation(xgp_Pnt2d^ Locat);

        //! Changes the direction of <me>.
        void SetDirection(xgp_Dir2d^ V);

        //Returns the gp_Ax2d
        gp_Ax2d GetAx2d();

        //! Returns the origin of <me>.
        xgp_Pnt2d^ Location();

        //! Returns the direction of <me>.
        xgp_Dir2d^ Direction();


        //! Returns True if  :
        //! . the angle between <me> and <Other> is lower or equal
        //! to <AngularTolerance> and
        //! . the distance between <me>.Location() and <Other> is lower
        //! or equal to <LinearTolerance> and
        //! . the distance between <Other>.Location() and <me> is lower
        //! or equal to LinearTolerance.
        Standard_Boolean IsCoaxial(xgp_Ax2d^ Other, Standard_Real AngularTolerance, Standard_Real LinearTolerance);

        //! Returns true if this axis and the axis Other are normal to
        //! each other. That is, if the angle between the two axes is equal to Pi/2 or -Pi/2.
        //! Note: the tolerance criterion is given by AngularTolerance.
        Standard_Boolean IsNormal(xgp_Ax2d^ Other, Standard_Real AngularTolerance);

        //! Returns true if this axis and the axis Other are parallel,
        //! and have opposite orientations. That is, if the angle
        //! between the two axes is equal to Pi or -Pi.
        //! Note: the tolerance criterion is given by AngularTolerance.
        Standard_Boolean IsOpposite(xgp_Ax2d^ Other, Standard_Real AngularTolerance);

        //! Returns true if this axis and the axis Other are parallel,
        //! and have either the same or opposite orientations. That
        //! is, if the angle between the two axes is equal to 0, Pi or -Pi.
        //! Note: the tolerance criterion is given by AngularTolerance.
        Standard_Boolean IsParallel(xgp_Ax2d^ Other, Standard_Real AngularTolerance);


        //! Computes the angle, in radians, between this axis and
        //! the axis Other. The value of the angle is between -Pi and Pi.
        Standard_Real Angle(xgp_Ax2d^ Other);

        //! Reverses the direction of <me> and assigns the result to this axis.
        void Reverse();


        //! Computes a new axis placement with a direction opposite to
        //! the direction of <me>.
        xgp_Ax2d^ Reversed();

        void Mirror(xgp_Pnt2d^ P);


        //! Performs the symmetrical transformation of an axis
        //! placement with respect to the point P which is the
        //! center of the symmetry.
        xgp_Ax2d^ Mirrored(xgp_Pnt2d^ P);

        void Mirror(xgp_Ax2d^ A);


        //! Performs the symmetrical transformation of an axis
        //! placement with respect to an axis placement which
        //! is the axis of the symmetry.
        xgp_Ax2d^ Mirrored(xgp_Ax2d^ A);

        void Rotate(xgp_Pnt2d^ P, Standard_Real Ang);


        //! Rotates an axis placement. <P> is the center of the
        //! rotation . Ang is the angular value of the rotation
        //! in radians.
        xgp_Ax2d^ Rotated(xgp_Pnt2d^ P, Standard_Real Ang);

        void Scale(xgp_Pnt2d^ P, Standard_Real S);


        //! Applies a scaling transformation on the axis placement.
        //! The "Location" point of the axisplacement is modified.
        //! The "Direction" is reversed if the scale is negative.
        xgp_Ax2d^ Scaled(xgp_Pnt2d^ P, Standard_Real S);

        void Transform(xgp_Trsf2d^ T);

        //! Transforms an axis placement with a Trsf.
        xgp_Ax2d^ Transformed(xgp_Trsf2d^ T);

        void Translate(xgp_Vec2d^ V);


        //! Translates an axis placement in the direction of the vector
        //! <V>. The magnitude of the translation is the vector's magnitude.
        xgp_Ax2d^ Translated(xgp_Vec2d^ V);

        void Translate(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2);


        //! Translates an axis placement from the point <P1> to the
        //! point <P2>.
        xgp_Ax2d^ Translated(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2);

        /// <summary>
        /// 本地句柄
        /// </summary>
        property gp_Ax2d* Handle
        {
            gp_Ax2d* get() {
                return NativeHandle;
            }
        }

    private:
        gp_Ax2d* NativeHandle;
    };
}
#endif // _xgp_Ax2d_HeaderFile