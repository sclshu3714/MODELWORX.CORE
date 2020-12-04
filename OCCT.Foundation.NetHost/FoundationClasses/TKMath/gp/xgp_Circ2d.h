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
//! Describes a circle in the plane (2D space).
//! A circle is defined by its radius and positioned in the
//! plane with a coordinate system (a xgp_Ax22d object) as follows:
//! -   the origin of the coordinate system is the center of the circle, and
//! -   the orientation (direct or indirect) of the coordinate
//! system gives an implicit orientation to the circle (and
//! defines its trigonometric sense).
//! This positioning coordinate system is the "local
//! coordinate system" of the circle.
//! Note: when a xgp_Circ2d circle is converted into a
//! Geom2d_Circle circle, some implicit properties of the
//! circle are used explicitly:
//! -   the implicit orientation corresponds to the direction in
//! which parameter values increase,
//! -   the starting point for parameterization is that of the "X
//! Axis" of the local coordinate system (i.e. the "X Axis" of the circle).
//! See Also
//! GccAna and Geom2dGcc packages which provide
//! functions for constructing circles defined by geometric constraints
//! gce_MakeCirc2d which provides functions for more
//! complex circle constructions
//! Geom2d_Circle which provides additional functions for
//! constructing circles and works, with the parametric
//! equations of circles in particular  xgp_Ax22d

#ifndef _xgp_Circ2d_HeaderFile
#define _xgp_Circ2d_HeaderFile
#pragma once
#include <gp_Circ2d.hxx>
#include "xgp_Ax2d.h"
#include "xgp_Ax22d.h"
#include "xgp_Pnt2d.h"
#include "xgp_Trsf2d.h"
#include "xgp_Vec2d.h"
namespace TKMath
{
    ref class xgp_Ax2d;
    ref class xgp_Ax22d;
    ref class xgp_Pnt2d;
    ref class xgp_Trsf2d;
    ref class xgp_Vec2d;
    public ref class xgp_Circ2d
    {
    public:
        //! creates an indefinite circle.
        xgp_Circ2d(void);

        /// <summary>
        /// 指针映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Circ2d(gp_Circ2d* pos);

        //! The location point of XAxis is the center of the circle.
        //! Warnings :
        //! It is not forbidden to create a circle with Radius = 0.0   Raises ConstructionError if Radius < 0.0.
        //! Raised if Radius < 0.0.
        xgp_Circ2d(xgp_Ax2d^ XAxis, Standard_Real Radius, Standard_Boolean Sense);


        //! Axis defines the Xaxis and Yaxis of the circle which defines
        //! the origin and the sense of parametrization.
        //! The location point of Axis is the center of the circle.
        //! Warnings :
        //! It is not forbidden to create a circle with Radius = 0.0 Raises ConstructionError if Radius < 0.0.
        //! Raised if Radius < 0.0.
        xgp_Circ2d(xgp_Ax22d^ Axis, Standard_Real Radius);

        //释放
        ~xgp_Circ2d();
        //释放
        !xgp_Circ2d();

        //! gp_Circ2d
        gp_Circ2d* GetCirc2d();

        //! Changes the location point (center) of the circle.
        void SetLocation(xgp_Pnt2d^ P);

        //! Changes the X axis of the circle.
        void SetXAxis(xgp_Ax2d^ A);

        //! Changes the X axis of the circle.
        void SetAxis(xgp_Ax22d^ A);

        //! Changes the Y axis of the circle.
        void SetYAxis(xgp_Ax2d^ A);

        //! Modifies the radius of this circle.
        //! Thisnamespace TKMath  {  public ref class does not prevent the creation of a circle where
        //! Radius is null.
        //! Exceptions
        //! Standard_ConstructionError if Radius is negative.
        void SetRadius(Standard_Real Radius);

        //! Computes the area of the circle.
        Standard_Real Area();


        //! Returns the normalized coefficients from the implicit equation
        //! of the circle :
        //! A * (X**2) + B * (Y**2) + 2*C*(X*Y) + 2*D*X + 2*E*Y + F = 0.0
        void Coefficients(Standard_Real A, Standard_Real B, Standard_Real C, Standard_Real D, Standard_Real E, Standard_Real F);

        //! Does <me> contain P ?
        //! Returns True if the distance between P and any point on
        //! the circumference of the circle is lower of equal to
        //! <LinearTolerance>.
        Standard_Boolean Contains(xgp_Pnt2d^ P, Standard_Real LinearTolerance);


        //! Computes the minimum of distance between the point P and any
        //! point on the circumference of the circle.
        Standard_Real Distance(xgp_Pnt2d^ P);


        //! Computes the square distance between <me> and the point P.
        Standard_Real SquareDistance(xgp_Pnt2d^ P);

        //! computes the circumference of the circle.
        Standard_Real Length();

        //! Returns the location point (center) of the circle.
        xgp_Pnt2d^ Location();

        //! Returns the radius value of the circle.
        Standard_Real Radius();

        //! returns the position of the circle.
        xgp_Ax22d^ Axis();

        //! returns the position of the circle. Idem Axis(me).
        xgp_Ax22d^ Position();

        //! returns the X axis of the circle.
        xgp_Ax2d^ XAxis();

        //! Returns the Y axis of the circle.
        //! Reverses the direction of the circle.
        xgp_Ax2d^ YAxis();

        //! Reverses the orientation of the local coordinate system
        //! of this circle (the "Y Direction" is reversed) and therefore
        //! changes the implicit orientation of this circle.
        //! Reverse assigns the result to this circle,
        void Reverse();

        //! Reverses the orientation of the local coordinate system
        //! of this circle (the "Y Direction" is reversed) and therefore
        //! changes the implicit orientation of this circle.
        //! Reversed creates a new circle.
        xgp_Circ2d^ Reversed();

        //! Returns true if the local coordinate system is direct
        //! and false in the other case.
        Standard_Boolean IsDirect();

        void Mirror(xgp_Pnt2d^ P);


        //! Performs the symmetrical transformation of a circle with respect
        //! to the point P which is the center of the symmetry
        xgp_Circ2d^ Mirrored(xgp_Pnt2d^ P);

        void Mirror(xgp_Ax2d^ A);


        //! Performs the symmetrical transformation of a circle with respect
        //! to an axis placement which is the axis of the symmetry.
        xgp_Circ2d^ Mirrored(xgp_Ax2d^ A);

        void Rotate(xgp_Pnt2d^ P, Standard_Real Ang);


        //! Rotates a circle. P is the center of the rotation.
        //! Ang is the angular value of the rotation in radians.
        xgp_Circ2d^ Rotated(xgp_Pnt2d^ P, Standard_Real Ang);

        void Scale(xgp_Pnt2d^ P, Standard_Real S);


        //! Scales a circle. S is the scaling value.
        //! Warnings :
        //! If S is negative the radius stay positive but
        //! the "XAxis" and the "YAxis" are  reversed as for
        //! an ellipse.
        xgp_Circ2d^ Scaled(xgp_Pnt2d^ P, Standard_Real S);

        void Transform(xgp_Trsf2d^ T);


        //! Transforms a circle with the transformation T fromnamespace TKMath  {  public ref class Trsf2d.
        xgp_Circ2d^ Transformed(xgp_Trsf2d^ T);

        void Translate(xgp_Vec2d^ V);


        //! Translates a circle in the direction of the vector V.
        //! The magnitude of the translation is the vector's magnitude.
        xgp_Circ2d^ Translated(xgp_Vec2d^ V);

        void Translate(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2);


        //! Translates a circle from the point P1 to the point P2.
        xgp_Circ2d^ Translated(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2);

        /// <summary>
        /// 本地句柄
        /// </summary>
        property gp_Circ2d* Handle
        {
            gp_Circ2d* get() {
                return NativeHandle;
            }
        }

    private:
        gp_Circ2d* NativeHandle;
    };
}
#endif // _xgp_Circ2d_HeaderFile