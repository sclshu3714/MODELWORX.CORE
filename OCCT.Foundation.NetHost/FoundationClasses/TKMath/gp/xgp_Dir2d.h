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

#pragma once
#include <gp_Dir2d.hxx>
#include "xgp_XY.h"
#include "xgp_Vec2d.h"
#include "xgp_Ax2d.h"
#include "xgp_Trsf2d.h"

//! Describes a unit vector in the plane (2D space). This unit
//! vector is also called "Direction".
//! See Also
//! gce_MakeDir2d which provides functions for more
//! complex unit vector constructions
//! Geom2d_Direction which provides additional functions
//! for constructing unit vectors and works, in particular, with
//! the parametric equations of unit vectors
namespace TKMath
{
    ref class xgp_XY;
    ref class xgp_Vec2d;
    ref class xgp_Ax2d;
    ref class xgp_Trsf2d;
    public ref class xgp_Dir2d
    {
    public:

        //! Creates a direction corresponding to X axis.
        xgp_Dir2d();

        /// <summary>
        /// 指针映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Dir2d(gp_Dir2d* pos);
        /// <summary>
        ///  映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Dir2d(gp_Dir2d pos);

        //! Normalizes the vector V and creates a Direction. Raises ConstructionError if V.Magnitude() <= Resolution from gp.
        xgp_Dir2d(xgp_Vec2d^ V);

        //! Creates a Direction from a doublet of coordinates. Raises ConstructionError if Coord.Modulus() <= Resolution from gp.
        xgp_Dir2d(xgp_XY^ Coord);

        //! Creates a Direction with its 2 cartesian coordinates. Raises ConstructionError if Sqrt(Xv*Xv + Yv*Yv) <= Resolution from gp.
        xgp_Dir2d(Standard_Real^ Xv, Standard_Real^ Yv);

        //释放
        ~xgp_Dir2d();
        //释放
        !xgp_Dir2d();

        //! For this unit vector, assigns:
        //! the value Xi to:
        //! -   the X coordinate if Index is 1, or
        //! -   the Y coordinate if Index is 2, and then normalizes it.
        //! Warning
        //! Remember that all the coordinates of a unit vector are
        //! implicitly modified when any single one is changed directly.
        //! Exceptions
        //! Standard_OutOfRange if Index is not 1 or 2.
        //! Standard_ConstructionError if either of the following
        //! is less than or equal to gp::Resolution():
        //! -   Sqrt(Xv*Xv + Yv*Yv), or
        //! -   the modulus of the number pair formed by the new
        //! value Xi and the other coordinate of this vector that
        //! was not directly modified.
        //! Raises OutOfRange if Index != {1, 2}.
        void SetCoord(Standard_Integer^ Index, Standard_Real^ Xi);


        //! For this unit vector, assigns:
        //! -   the values Xv and Yv to its two coordinates,
        //! Warning
        //! Remember that all the coordinates of a unit vector are
        //! implicitly modified when any single one is changed directly.
        //! Exceptions
        //! Standard_OutOfRange if Index is not 1 or 2.
        //! Standard_ConstructionError if either of the following
        //! is less than or equal to gp::Resolution():
        //! -   Sqrt(Xv*Xv + Yv*Yv), or
        //! -   the modulus of the number pair formed by the new
        //! value Xi and the other coordinate of this vector that
        //! was not directly modified.
        //! Raises OutOfRange if Index != {1, 2}.
        void SetCoord(Standard_Real^ Xv, Standard_Real^ Yv);


        //! Assigns the given value to the X coordinate of this unit   vector,
        //! and then normalizes it.
        //! Warning
        //! Remember that all the coordinates of a unit vector are
        //! implicitly modified when any single one is changed directly.
        //! Exceptions
        //! Standard_ConstructionError if either of the following
        //! is less than or equal to gp::Resolution():
        //! -   the modulus of Coord, or
        //! -   the modulus of the number pair formed from the new
        //! X or Y coordinate and the other coordinate of this
        //! vector that was not directly modified.
        void SetX(Standard_Real^ X);


        //! Assigns  the given value to the Y coordinate of this unit   vector,
        //! and then normalizes it.
        //! Warning
        //! Remember that all the coordinates of a unit vector are
        //! implicitly modified when any single one is changed directly.
        //! Exceptions
        //! Standard_ConstructionError if either of the following
        //! is less than or equal to gp::Resolution():
        //! -   the modulus of Coord, or
        //! -   the modulus of the number pair formed from the new
        //! X or Y coordinate and the other coordinate of this
        //! vector that was not directly modified.
        void SetY(Standard_Real^ Y);


        //! Assigns:
        //! -   the two coordinates of Coord to this unit vector,
        //! and then normalizes it.
        //! Warning
        //! Remember that all the coordinates of a unit vector are
        //! implicitly modified when any single one is changed directly.
        //! Exceptions
        //! Standard_ConstructionError if either of the following
        //! is less than or equal to gp::Resolution():
        //! -   the modulus of Coord, or
        //! -   the modulus of the number pair formed from the new
        //! X or Y coordinate and the other coordinate of this
        //! vector that was not directly modified.
        void SetXY(xgp_XY^ Coord);

        //! return the gp_Dir2d
        gp_Dir2d  GetDir2d();

        //! For this unit vector returns the coordinate of range Index :
        //! Index = 1 => X is returned
        //! Index = 2 => Y is returned
        //! Raises OutOfRange if Index != {1, 2}.
        Standard_Real^ Coord(Standard_Integer^ Index);

        //! For this unit vector returns its two coordinates Xv and Yv.
        //! Raises OutOfRange if Index != {1, 2}.
        void Coord(Standard_Real^ Xv, Standard_Real^ Yv);

        //! For this unit vector, returns its X coordinate.
        Standard_Real^ X();

        //! For this unit vector, returns its Y coordinate.
        Standard_Real^ Y();

        //! For this unit vector, returns its two coordinates as a number pair.
        //! Comparison between Directions
        //! The precision value is an input data.
        xgp_XY^ XY();


        //! Returns True if the two vectors have the same direction
        //! i.e. the angle between this unit vector and the
        //! unit vector Other is less than or equal to AngularTolerance.
        Standard_Boolean^ IsEqual(xgp_Dir2d^ Other, Standard_Real^ AngularTolerance);


        //! Returns True if the angle between this unit vector and the
        //! unit vector Other is equal to Pi/2 or -Pi/2 (normal)
        //! i.e. Abs(Abs(<me>.Angle(Other)) - PI/2.) <= AngularTolerance
        Standard_Boolean^ IsNormal(xgp_Dir2d^ Other, Standard_Real^ AngularTolerance);


        //! Returns True if the angle between this unit vector and the
        //! unit vector Other is equal to Pi or -Pi (opposite).
        //! i.e.  PI - Abs(<me>.Angle(Other)) <= AngularTolerance
        Standard_Boolean^ IsOpposite(xgp_Dir2d^ Other, Standard_Real^ AngularTolerance);


        //! returns true if if the angle between this unit vector and unit
        //! vector Other is equal to 0, Pi or -Pi.
        //! i.e.  Abs(Angle(<me>, Other)) <= AngularTolerance or
        //! PI - Abs(Angle(<me>, Other)) <= AngularTolerance
        Standard_Boolean^ IsParallel(xgp_Dir2d^ Other, Standard_Real^ AngularTolerance);


        //! Computes the angular value in radians between <me> and
        //! <Other>. Returns the angle in the range [-PI, PI].
        Standard_Real^ Angle(xgp_Dir2d^ Other);


        //! Computes the cross product between two directions.
        Standard_Real^ Crossed(xgp_Dir2d^ Right);
        Standard_Real^ operator ^ (xgp_Dir2d^ Right) {
            return Crossed(Right);
        }

        //! Computes the scalar product
        Standard_Real^ Dot(xgp_Dir2d^ Other);
        Standard_Real^ operator * (xgp_Dir2d^ Other) {
            return Dot(Other);
        }

        void Reverse();

        //! Reverses the orientation of a direction
        xgp_Dir2d^ Reversed();
        xgp_Dir2d^ operator -() {
            return Reversed();
        }

        void Mirror(xgp_Dir2d^ V);


        //! Performs the symmetrical transformation of a direction
        //! with respect to the direction V which is the center of
        //! the  symmetry.
        xgp_Dir2d^ Mirrored(xgp_Dir2d^ V);

        void Mirror(xgp_Ax2d^ A);


        //! Performs the symmetrical transformation of a direction
        //! with respect to an axis placement which is the axis
        //! of the symmetry.
        xgp_Dir2d^ Mirrored(xgp_Ax2d^ A);

        void Rotate(Standard_Real^ Ang);


        //! Rotates a direction.  Ang is the angular value of
        //! the rotation in radians.
        xgp_Dir2d^ Rotated(Standard_Real^ Ang);

        void Transform(xgp_Trsf2d^ T);


        //! Transforms a direction with the "Trsf" T.
        //! Warnings :
        //! If the scale factor of the "Trsf" T is negative then the
        //! direction <me> is reversed.
        xgp_Dir2d^ Transformed(xgp_Trsf2d^ T);

        /// <summary>
        /// 本地句柄
        /// </summary>
        property gp_Dir2d* Handle
        {
            gp_Dir2d* get() {
                return NativeHandle;
            }
        }

    private:
        gp_Dir2d* NativeHandle;
    };
} 
