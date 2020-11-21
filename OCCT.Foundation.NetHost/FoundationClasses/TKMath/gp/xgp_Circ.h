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
//! Describes a circle in 3D space.
//! A circle is defined by its radius and positioned in space
//! with a coordinate system (a xgp_Ax2 object) as follows:
//! -   the origin of the coordinate system is the center of the circle, and
//! -   the origin, "X Direction" and "Y Direction" of the
//! coordinate system define the plane of the circle.
//! This positioning coordinate system is the "local
//! coordinate system" of the circle. Its "main Direction"
//! gives the normal vector to the plane of the circle. The
//! "main Axis" of the coordinate system is referred to as
//! the "Axis" of the circle.
//! Note: when a xgp_Circ circle is converted into a
//! Geom_Circle circle, some implicit properties of the
//! circle are used explicitly:
//! -   the "main Direction" of the local coordinate system
//! gives an implicit orientation to the circle (and defines
//! its trigonometric sense),
//! -   this orientation corresponds to the direction in
//! which parameter values increase,
//! -   the starting point for parameterization is that of the
//! "X Axis" of the local coordinate system (i.e. the "X Axis" of the circle).
//! See Also
//! gce_MakeCirc which provides functions for more complex circle constructions
//! Geom_Circle which provides additional functions for
//! constructing circles and works, in particular, with the
//! parametric equations of circles

#ifndef _xgp_Circ_HeaderFile
#define _xgp_Circ_HeaderFile
#pragma once
#include <gp_Circ.hxx>
#include "xgp_Ax1.h"
#include "xgp_Ax2.h"
#include "xgp_Pnt.h"
#include "xgp_Trsf.h"
#include "xgp_Vec.h"

namespace TKMath
{
    ref class xgp_Ax1;
    ref class xgp_Ax2;
    ref class xgp_Pnt;
    ref class xgp_Trsf;
    ref class xgp_Vec;
    public ref class xgp_Circ
    {
    public:

        //! Creates an indefinite circle.
        xgp_Circ(void);

        /// <summary>
        /// 指针映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Circ(gp_Circ* pos);
        /// <summary>
        ///  映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Circ(gp_Circ pos);

        //! A2 locates the circle and gives its orientation in 3D space.
        //! Warnings :
        //! It is not forbidden to create a circle with Radius = 0.0  Raises ConstructionError if Radius < 0.0
        xgp_Circ(xgp_Ax2^ A2, Standard_Real^ Radius);

        //! 释放
        ~xgp_Circ();

        //! 释放
        !xgp_Circ();

        //! gp_Circ
        gp_Circ GetCirc();

        //! Changes the main axis of the circle. It is the axis
        //! perpendicular to the plane of the circle.
        //! Raises ConstructionError if the direction of A1
        //! is parallel to the "XAxis" of the circle.
        void SetAxis(xgp_Ax1^ A1);


        //! Changes the "Location" point (center) of the circle.
        void SetLocation(xgp_Pnt^ P);

        //! Changes the position of the circle.
        void SetPosition(xgp_Ax2^ A2);

        //! Modifies the radius of this circle.
        //! Warning. Thisnamespace TKMath  {  public ref class does not prevent the creation of a circle where Radius is null.
        //! Exceptions
        //! Standard_ConstructionError if Radius is negative.
        void SetRadius(Standard_Real^ Radius);

        //! Computes the area of the circle.
        Standard_Real^ Area();


        //! Returns the main axis of the circle.
        //! It is the axis perpendicular to the plane of the circle,
        //! passing through the "Location" point (center) of the circle.
        xgp_Ax1^ Axis();

        //! Computes the circumference of the circle.
        Standard_Real^ Length();


        //! Returns the center of the circle. It is the
        //! "Location" point of the local coordinate system
        //! of the circle
        xgp_Pnt^ Location();


        //! Returns the position of the circle.
        //! It is the local coordinate system of the circle.
        xgp_Ax2^ Position();

        //! Returns the radius of this circle.
        Standard_Real^ Radius();


        //! Returns the "XAxis" of the circle.
        //! This axis is perpendicular to the axis of the conic.
        //! This axis and the "Yaxis" define the plane of the conic.
        xgp_Ax1^ XAxis();


        //! Returns the "YAxis" of the circle.
        //! This axis and the "Xaxis" define the plane of the conic.
        //! The "YAxis" is perpendicular to the "Xaxis".
        xgp_Ax1^ YAxis();


        //! Computes the minimum of distance between the point P and
        //! any point on the circumference of the circle.
        Standard_Real^ Distance(xgp_Pnt^ P);


        //! Computes the square distance between <me> and the point P.
        Standard_Real^ SquareDistance(xgp_Pnt^ P);


        //! Returns True if the point P is on the circumference.
        //! The distance between <me> and <P> must be lower or
        //! equal to LinearTolerance.
        Standard_Boolean^ Contains(xgp_Pnt^ P, Standard_Real^ LinearTolerance);

        void Mirror(xgp_Pnt^ P);


        //! Performs the symmetrical transformation of a circle
        //! with respect to the point P which is the center of the
        //! symmetry.
        xgp_Circ^ Mirrored(xgp_Pnt^ P);

        void Mirror(xgp_Ax1^ A1);


        //! Performs the symmetrical transformation of a circle with
        //! respect to an axis placement which is the axis of the
        //! symmetry.
        xgp_Circ^ Mirrored(xgp_Ax1^ A1);

        void Mirror(xgp_Ax2^ A2);


        //! Performs the symmetrical transformation of a circle with respect
        //! to a plane. The axis placement A2 locates the plane of the
        //! of the symmetry : (Location, XDirection, YDirection).
        xgp_Circ^ Mirrored(xgp_Ax2^ A2);

        void Rotate(xgp_Ax1^ A1, Standard_Real^ Ang);


        //! Rotates a circle. A1 is the axis of the rotation.
        //! Ang is the angular value of the rotation in radians.
        xgp_Circ^ Rotated(xgp_Ax1^ A1, Standard_Real^ Ang);

        void Scale(xgp_Pnt^ P, Standard_Real^ S);


        //! Scales a circle. S is the scaling value.
        //! Warnings :
        //! If S is negative the radius stay positive but
        //! the "XAxis" and the "YAxis" are  reversed as for
        //! an ellipse.
        xgp_Circ^ Scaled(xgp_Pnt^ P, Standard_Real^ S);

        void Transform(xgp_Trsf^ T);


        //! Transforms a circle with the transformation T fromnamespace TKMath  {  public ref class Trsf.
        xgp_Circ^ Transformed(xgp_Trsf^ T);

        void Translate(xgp_Vec^ V);


        //! Translates a circle in the direction of the vector V.
        //! The magnitude of the translation is the vector's magnitude.
        xgp_Circ^ Translated(xgp_Vec^ V);

        void Translate(xgp_Pnt^ P1, xgp_Pnt^ P2);


        //! Translates a circle from the point P1 to the point P2.
        xgp_Circ^ Translated(xgp_Pnt^ P1, xgp_Pnt^ P2);

        /// <summary>
        /// 本地句柄
        /// </summary>
        property gp_Circ* Handle
        {
            gp_Circ* get() {
                return NativeHandle;
            }
        }

    private:
        gp_Circ* NativeHandle;
    };
}
#endif // _xgp_Circ_HeaderFile