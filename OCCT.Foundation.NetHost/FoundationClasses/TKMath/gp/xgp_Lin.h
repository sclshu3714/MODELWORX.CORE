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
//! Describes a line in 3D space.
//! A line is positioned in space with an axis (a xgp_Ax1
//! object) which gives it an origin and a unit vector.
//! A line and an axis are similar objects, thus, we can
//! convert one into the other. A line provides direct access
//! to the majority of the edit and query functions available
//! on its positioning axis. In addition, however, a line has
//! specific functions for computing distances and positions.
//! See Also
//! gce_MakeLin which provides functions for more complex
//! line constructions
//! Geom_Line which provides additional functions for
//! constructing lines and works, in particular, with the
//! parametric equations of lines

#ifndef _xgp_Lin_HeaderFile
#define _xgp_Lin_HeaderFile
#pragma once
#include <gp_Lin.hxx>
#include "xgp_Ax1.h"
#include "xgp_Ax2.h"
#include "xgp_Pnt.h"
#include "xgp_Dir.h"
#include "xgp_Trsf.h"
#include "xgp_Vec.h"

namespace TKMath
{
    ref class xgp_Ax1;
    ref class xgp_Pnt;
    ref class xgp_Dir;
    ref class xgp_Ax2;
    ref class xgp_Trsf;
    ref class xgp_Vec;
    public ref class xgp_Lin
    {
    public:

        //! Creates a Line corresponding to Z axis of the
        //! reference coordinate system.
        xgp_Lin();

        /// <summary>
        /// 指针映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Lin(gp_Lin* pos);
        /// <summary>
        ///  映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Lin(gp_Lin pos);

        //! Creates a line defined by axis A1.
        xgp_Lin(xgp_Ax1^ A1);

        //! Creates a line passing through point P and parallel to
        //! vector V (P and V are, respectively, the origin and
        //! the unit vector of the positioning axis of the line).
        xgp_Lin(xgp_Pnt^ P, xgp_Dir^ V);

        //释放
        ~xgp_Lin();
        //释放
        !xgp_Lin();

        //! gp_Lin
        gp_Lin GetLin();

        void Reverse();

        //! Reverses the direction of the line.
        //! Note:
        //! -   Reverse assigns the result to this line, while
        //! -   Reversed creates a new one.
        xgp_Lin^ Reversed();

        //! Changes the direction of the line.
        void SetDirection(xgp_Dir^ V);

        //! Changes the location point (origin) of the line.
        void SetLocation(xgp_Pnt^ P);


        //! Complete redefinition of the line.
        //! The "Location" point of <A1> is the origin of the line.
        //! The "Direction" of <A1> is  the direction of the line.
        void SetPosition(xgp_Ax1^ A1);

        //! Returns the direction of the line.
        xgp_Dir^ Direction();


        //! Returns the location point (origin) of the line.
        xgp_Pnt^ Location();


        //! Returns the axis placement one axis whith the same
        //! location and direction as <me>.
        xgp_Ax1^ Position();

        //! Computes the angle between two lines in radians.
        Standard_Real^ Angle(xgp_Lin^ Other);

        //! Returns true if this line contains the point P, that is, if the
        //! distance between point P and this line is less than or
        //! equal to LinearTolerance..
        Standard_Boolean^ Contains(xgp_Pnt^ P, Standard_Real^ LinearTolerance);

        //! Computes the distance between <me> and the point P.
        Standard_Real^ Distance(xgp_Pnt^ P);

        //! Computes the distance between two lines.
        Standard_Real^ Distance(xgp_Lin^ Other);


        //! Computes the square distance between <me> and the point P.
        Standard_Real^ SquareDistance(xgp_Pnt^ P);

        //! Computes the square distance between two lines.
        Standard_Real^ SquareDistance(xgp_Lin^ Other);


        //! Computes the line normal to the direction of <me>, passing
        //! through the point P.  Raises ConstructionError
        //! if the distance between <me> and the point P is lower
        //! or equal to Resolution from gp because there is an infinity of
        //! solutions in 3D space.
        xgp_Lin^ Normal(xgp_Pnt^ P);

        void Mirror(xgp_Pnt^ P);


        //! Performs the symmetrical transformation of a line
        //! with respect to the point P which is the center of
        //! the symmetry.
        xgp_Lin^ Mirrored(xgp_Pnt^ P);

        void Mirror(xgp_Ax1^ A1);


        //! Performs the symmetrical transformation of a line
        //! with respect to an axis placement which is the axis
        //! of the symmetry.
        xgp_Lin^ Mirrored(xgp_Ax1^ A1);

        void Mirror(xgp_Ax2^ A2);


        //! Performs the symmetrical transformation of a line
        //! with respect to a plane. The axis placement  <A2>
        //! locates the plane of the symmetry :
        //! (Location, XDirection, YDirection).
        xgp_Lin^ Mirrored(xgp_Ax2^ A2);

        void Rotate(xgp_Ax1^ A1, Standard_Real^ Ang);


        //! Rotates a line. A1 is the axis of the rotation.
        //! Ang is the angular value of the rotation in radians.
        xgp_Lin^ Rotated(xgp_Ax1^ A1, Standard_Real^ Ang);

        void Scale(xgp_Pnt^ P, Standard_Real^ S);


        //! Scales a line. S is the scaling value.
        //! The "Location" point (origin) of the line is modified.
        //! The "Direction" is reversed if the scale is negative.
        xgp_Lin^ Scaled(xgp_Pnt^ P, Standard_Real^ S);

        void Transform(xgp_Trsf^ T);


        //! Transforms a line with the transformation T fromnamespace TKMath  {  public ref class Trsf.
        xgp_Lin^ Transformed(xgp_Trsf^ T);

        void Translate(xgp_Vec^ V);


        //! Translates a line in the direction of the vector V.
        //! The magnitude of the translation is the vector's magnitude.
        xgp_Lin^ Translated(xgp_Vec^ V);

        void Translate(xgp_Pnt^ P1, xgp_Pnt^ P2);


        //! Translates a line from the point P1 to the point P2.
        xgp_Lin^ Translated(xgp_Pnt^ P1, xgp_Pnt^ P2);

        /// <summary>
        /// 本地句柄
        /// </summary>
        property gp_Lin* Handle
        {
            gp_Lin* get() {
                return NativeHandle;
            }
        }

    private:
        gp_Lin* NativeHandle;
    };
}
#endif // _xgp_Lin_HeaderFile