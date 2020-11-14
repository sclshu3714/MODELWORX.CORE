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

//! Describes a line in 2D space.
//! A line is positioned in the plane with an axis (a xgp_Ax2d
//! object) which gives the line its origin and unit vector. A
//! line and an axis are similar objects, thus, we can convert
//! one into the other.
//! A line provides direct access to the majority of the edit
//! and query functions available on its positioning axis. In
//! addition, however, a line has specific functions for
//! computing distances and positions.
//! See Also
//! GccAna and Geom2dGcc packages which provide
//! functions for constructing lines defined by geometric
//! constraints
//! gce_MakeLin2d which provides functions for more
//! complex line constructions
//! Geom2d_Line which provides additional functions for
//! constructing lines and works, in particular, with the
//! parametric equations of lines
#pragma once
#include <gp_Lin2d.hxx>
#include "xgp_Ax2d.h"
#include "xgp_Pnt2d.h"
#include "xgp_Dir2d.h"
#include "xgp_Trsf2d.h"
#include "xgp_Vec2d.h"

namespace TKMath
{
    ref class xgp_Ax2d;
    ref class xgp_Pnt2d;
    ref class xgp_Dir2d;
    ref class xgp_Trsf2d;
    ref class xgp_Vec2d;
    public ref class xgp_Lin2d
    {
    public:
        //! Creates a Line corresponding to X axis of the
        //! reference coordinate system.
        xgp_Lin2d();

        /// <summary>
        /// 指针映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Lin2d(gp_Lin2d* pos);
        /// <summary>
        ///  映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Lin2d(gp_Lin2d pos);

        //! Creates a line located with A.
        xgp_Lin2d(xgp_Ax2d^ A);


        //! <P> is the location point (origin) of the line and
        //! <V> is the direction of the line.
        xgp_Lin2d(xgp_Pnt2d^ P, xgp_Dir2d^ V);


        //! Creates the line from the equation A*X + B*Y + C = 0.0 Raises ConstructionError if Sqrt(A*A + B*B) <= Resolution from gp.
        //! Raised if Sqrt(A*A + B*B) <= Resolution from gp.
        xgp_Lin2d(Standard_Real^ A, Standard_Real^ B, Standard_Real^ C);


        //释放
        ~xgp_Lin2d();
        //释放
        !xgp_Lin2d();

        //! gp_Lin2d
        gp_Lin2d GetLin2d();

        void Reverse();


        //! Reverses the positioning axis of this line.
        //! Note:
        //! -   Reverse assigns the result to this line, while
        //! -   Reversed creates a new one.
        xgp_Lin2d^ Reversed();

        //! Changes the direction of the line.
        void SetDirection(xgp_Dir2d^ V);

        //! Changes the origin of the line.
        void SetLocation(xgp_Pnt2d^ P);


        //! Complete redefinition of the line.
        //! The "Location" point of <A> is the origin of the line.
        //! The "Direction" of <A> is  the direction of the line.
        void SetPosition(xgp_Ax2d^ A);


        //! Returns the normalized coefficients of the line :
        //! A * X + B * Y + C = 0.
        void Coefficients(Standard_Real A, Standard_Real B, Standard_Real C);

        //! Returns the direction of the line.
        xgp_Dir2d^ Direction();

        //! Returns the location point (origin) of the line.
        xgp_Pnt2d^ Location();


        //! Returns the axis placement one axis whith the same
        //! location and direction as <me>.
        xgp_Ax2d^ Position();

        //! Computes the angle between two lines in radians.
        Standard_Real^ Angle(xgp_Lin2d^ Other);

        //! Returns true if this line contains the point P, that is, if the
        //! distance between point P and this line is less than or
        //! equal to LinearTolerance.
        Standard_Boolean^ Contains(xgp_Pnt2d^ P, Standard_Real^ LinearTolerance);


        //! Computes the distance between <me> and the point <P>.
        Standard_Real^ Distance(xgp_Pnt2d^ P);

        //! Computes the distance between two lines.
        Standard_Real^ Distance(xgp_Lin2d^ Other);


        //! Computes the square distance between <me> and the point
        //! <P>.
        Standard_Real^ SquareDistance(xgp_Pnt2d^ P);

        //! Computes the square distance between two lines.
        Standard_Real^ SquareDistance(xgp_Lin2d^ Other);


        //! Computes the line normal to the direction of <me>,
        //! passing through the point <P>.
        xgp_Lin2d^ Normal(xgp_Pnt2d^ P);

        void Mirror(xgp_Pnt2d^ P);


        //! Performs the symmetrical transformation of a line
        //! with respect to the point <P> which is the center
        //! of the symmetry
        xgp_Lin2d^ Mirrored(xgp_Pnt2d^ P);

        void Mirror(xgp_Ax2d^ A);


        //! Performs the symmetrical transformation of a line
        //! with respect to an axis placement which is the axis
        //! of the symmetry.
        xgp_Lin2d^ Mirrored(xgp_Ax2d^ A);

        void Rotate(xgp_Pnt2d^ P, Standard_Real^ Ang);


        //! Rotates a line. P is the center of the rotation.
        //! Ang is the angular value of the rotation in radians.
        xgp_Lin2d^ Rotated(xgp_Pnt2d^ P, Standard_Real^ Ang);

        void Scale(xgp_Pnt2d^ P, Standard_Real^ S);


        //! Scales a line. S is the scaling value. Only the
        //! origin of the line is modified.
        xgp_Lin2d^ Scaled(xgp_Pnt2d^ P, Standard_Real^ S);

        void Transform(xgp_Trsf2d^ T);


        //! Transforms a line with the transformation T fromnamespace TKMath  {  public ref class Trsf2d.
        xgp_Lin2d^ Transformed(xgp_Trsf2d^ T);

        void Translate(xgp_Vec2d^ V);


        //! Translates a line in the direction of the vector V.
        //! The magnitude of the translation is the vector's magnitude.
        xgp_Lin2d^ Translated(xgp_Vec2d^ V);

        void Translate(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2);


        //! Translates a line from the point P1 to the point P2.
        xgp_Lin2d^ Translated(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2);

        /// <summary>
        /// 本地句柄
        /// </summary>
        property gp_Lin2d* Handle
        {
            gp_Lin2d* get() {
                return NativeHandle;
            }
        }

    private:
        gp_Lin2d* NativeHandle;
    };
};
