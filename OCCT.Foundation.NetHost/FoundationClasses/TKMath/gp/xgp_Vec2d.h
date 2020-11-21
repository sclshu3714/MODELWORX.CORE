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

#ifndef _xgp_Vec2d_HeaderFile
#define _xgp_Vec2d_HeaderFile
#pragma once
#include <gp_Vec2d.hxx>
#include "xgp_Dir2d.h"
#include "xgp_XY.h"
#include "xgp_Pnt2d.h"
#include "xgp_Trsf2d.h"
#include "xgp_Ax2d.h"

//! Defines a non-persistent vector in 2D space.
namespace TKMath
{
    ref class xgp_Dir2d;
    ref class xgp_XY;
    ref class xgp_Pnt2d;
    ref class xgp_Trsf2d;
    ref class xgp_Ax2d;
    public ref class xgp_Vec2d
    {
    public:
        //! Creates a zero vector.
        xgp_Vec2d();

        /// <summary>
        /// 指针映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Vec2d(gp_Vec2d* pos);

        /// <summary>
        ///  映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Vec2d(gp_Vec2d pos);

        //! Creates a unitary vector from a direction V.
        xgp_Vec2d(xgp_Dir2d^ V);

        //! Creates a vector with a doublet of coordinates.
        xgp_Vec2d(xgp_XY^ Coord);

        //! Creates a point with its two Cartesian coordinates.
        xgp_Vec2d(Standard_Real^ Xv, Standard_Real^ Yv);


        //! Creates a vector from two points. The length of the vector
        //! is the distance between P1 and P2
        xgp_Vec2d(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2);

        //释放
        ~xgp_Vec2d();
        //释放
        !xgp_Vec2d();

        //! Changes the coordinate of range Index
        //! Index = 1 => X is modified
        //! Index = 2 => Y is modified
        //! Raises OutOfRange if Index != {1, 2}.
        void SetCoord(Standard_Integer^ Index, Standard_Real^ Xi);

        //! For this vector, assigns
        //! the values Xv and Yv to its two coordinates
        void SetCoord(Standard_Real^ Xv, Standard_Real^ Yv);

        //! Assigns the given value to the X coordinate of this vector.
        void SetX(Standard_Real^ X);

        //! Assigns the given value to the Y coordinate of this vector.
        void SetY(Standard_Real^ Y);

        //! Assigns the two coordinates of Coord to this vector.
        void SetXY(xgp_XY^ Coord);

        //! Returns the gp_Vec2d
        gp_Vec2d GetVec2d();
        //! Returns the coordinate of range Index :
        //! Index = 1 => X is returned
        //! Index = 2 => Y is returned
        //! Raised if Index != {1, 2}.
        Standard_Real^ Coord(Standard_Integer^ Index);

        //! For this vector, returns  its two coordinates Xv and Yv
        void Coord(Standard_Real^ Xv, Standard_Real^ Yv);

        //! For this vector, returns its X  coordinate.
        Standard_Real^ X();

        //! For this vector, returns its Y  coordinate.
        Standard_Real^ Y();

        //! For this vector, returns its two coordinates as a number pair
        xgp_XY^ XY();


        //! Returns True if the two vectors have the same magnitude value
        //! and the same direction. The precision values are LinearTolerance
        //! for the magnitude and AngularTolerance for the direction.
        Standard_Boolean^ IsEqual(xgp_Vec2d^ Other, Standard_Real^ LinearTolerance, Standard_Real^ AngularTolerance);


        //! Returns True if abs(Abs(<me>.Angle(Other)) - PI/2.)
        //! <= AngularTolerance
        //! Raises VectorWithNullMagnitude if <me>.Magnitude() <= Resolution or
        //! Other.Magnitude() <= Resolution from gp.
        Standard_Boolean^ IsNormal(xgp_Vec2d^ Other, Standard_Real^ AngularTolerance);


        //! Returns True if PI - Abs(<me>.Angle(Other)) <= AngularTolerance
        //! Raises VectorWithNullMagnitude if <me>.Magnitude() <= Resolution or
        //! Other.Magnitude() <= Resolution from gp.
        Standard_Boolean^ IsOpposite(xgp_Vec2d^ Other, Standard_Real^ AngularTolerance);


        //! Returns true if Abs(Angle(<me>, Other)) <= AngularTolerance or
        //! PI - Abs(Angle(<me>, Other)) <= AngularTolerance
        //! Two vectors with opposite directions are considered as parallel.
        //! Raises VectorWithNullMagnitude if <me>.Magnitude() <= Resolution or
        //! Other.Magnitude() <= Resolution from gp
        Standard_Boolean^ IsParallel(xgp_Vec2d^ Other, Standard_Real^ AngularTolerance);


        //! Computes the angular value between <me> and <Other>
        //! returns the angle value between -PI and PI in radian.
        //! The orientation is from <me> to Other. The positive sense is the
        //! trigonometric sense.
        //! Raises VectorWithNullMagnitude if <me>.Magnitude() <= Resolution from gp or
        //! Other.Magnitude() <= Resolution because the angular value is
        //! indefinite if one of the vectors has a null magnitude.
        Standard_Real^ Angle(xgp_Vec2d^ Other);

        //! Computes the magnitude of this vector.
        Standard_Real^ Magnitude();

        //! Computes the square magnitude of this vector.
        Standard_Real^ SquareMagnitude();

        void Add(xgp_Vec2d^ Other);
        void operator += (xgp_Vec2d^ Other) {
            Add(Other);
        }

        //! Adds two vectors
        xgp_Vec2d^ Added(xgp_Vec2d^ Other);
        xgp_Vec2d^ operator + (xgp_Vec2d^ Other) {
            return Added(Other);
        }

        //! Computes the crossing product between two vectors
        Standard_Real^ Crossed(xgp_Vec2d^ Right);
        Standard_Real^ operator ^ (xgp_Vec2d^ Right) {
            return Crossed(Right);
        }


        //! Computes the magnitude of the cross product between <me> and
        //! Right. Returns || <me> ^ Right ||
        Standard_Real^ CrossMagnitude(xgp_Vec2d^ Right);


        //! Computes the square magnitude of the cross product between <me> and
        //! Right. Returns || <me> ^ Right ||**2
        Standard_Real^ CrossSquareMagnitude(xgp_Vec2d^ Right);

        void Divide(Standard_Real^ Scalar);
        void operator /= (Standard_Real^ Scalar) {
            Divide(Scalar);
        }

        //! divides a vector by a scalar
        xgp_Vec2d^ Divided(Standard_Real^ Scalar);
        xgp_Vec2d^ operator / (Standard_Real^ Scalar) {
            return Divided(Scalar);
        }

        //! Computes the scalar product
        Standard_Real^ Dot(xgp_Vec2d^ Other);
        Standard_Real^ operator * (xgp_Vec2d^ Other) {
            return Dot(Other);
        }

        xgp_Vec2d^ GetNormal();

        void Multiply(Standard_Real^ Scalar);
        void operator *= (Standard_Real^ Scalar) {
            Multiply(Scalar);
        }

        //! Normalizes a vector
        //! Raises an exception if the magnitude of the vector is
        //! lower or equal to Resolution from package gp.
        xgp_Vec2d^ Multiplied(Standard_Real^ Scalar);
        xgp_Vec2d^ operator * (Standard_Real^ Scalar) {
            return Multiplied(Scalar);
        }

        void Normalize();

        //! Normalizes a vector
        //! Raises an exception if the magnitude of the vector is
        //! lower or equal to Resolution from package gp.
        //! Reverses the direction of a vector
        xgp_Vec2d^ Normalized();

        void Reverse();

        //! Reverses the direction of a vector
        xgp_Vec2d^ Reversed();
        xgp_Vec2d^ operator -() {
            return Reversed();
        }

        //! Subtracts two vectors
        void Subtract(xgp_Vec2d^ Right);
        void operator -= (xgp_Vec2d^ Right) {
            Subtract(Right);
        }

        //! Subtracts two vectors
        xgp_Vec2d^ Subtracted(xgp_Vec2d^ Right);
        xgp_Vec2d^ operator - (xgp_Vec2d^ Right) {
            return Subtracted(Right);
        }


        //! <me> is set to the following linear form :
        //! A1 * V1 + A2 * V2 + V3
        void SetLinearForm(Standard_Real^ A1, xgp_Vec2d^ V1, Standard_Real^ A2, xgp_Vec2d^ V2, xgp_Vec2d^ V3);


        //! <me> is set to the following linear form : A1 * V1 + A2 * V2
        void SetLinearForm(Standard_Real^ A1, xgp_Vec2d^ V1, Standard_Real^ A2, xgp_Vec2d^ V2);


        //! <me> is set to the following linear form : A1 * V1 + V2
        void SetLinearForm(Standard_Real^ A1, xgp_Vec2d^ V1, xgp_Vec2d^ V2);


        //! <me> is set to the following linear form : Left + Right
        void SetLinearForm(xgp_Vec2d^ Left, xgp_Vec2d^ Right);


        //! Performs the symmetrical transformation of a vector
        //! with respect to the vector V which is the center of
        //! the  symmetry.
        void Mirror(xgp_Vec2d^ V);


        //! Performs the symmetrical transformation of a vector
        //! with respect to the vector V which is the center of
        //! the  symmetry.
        xgp_Vec2d^ Mirrored(xgp_Vec2d^ V);


        //! Performs the symmetrical transformation of a vector
        //! with respect to an axis placement which is the axis
        //! of the symmetry.
        void Mirror(xgp_Ax2d^ A1);


        //! Performs the symmetrical transformation of a vector
        //! with respect to an axis placement which is the axis
        //! of the symmetry.
        xgp_Vec2d^ Mirrored(xgp_Ax2d^ A1);

        void Rotate(Standard_Real^ Ang);


        //! Rotates a vector. Ang is the angular value of the
        //! rotation in radians.
        xgp_Vec2d^ Rotated(Standard_Real^ Ang);

        void Scale(Standard_Real^ S);

        //! Scales a vector. S is the scaling value.
        xgp_Vec2d^ Scaled(Standard_Real^ S);

        void Transform(xgp_Trsf2d^ T);

        //! Transforms a vector with a Trsf from gp.
        xgp_Vec2d^ Transformed(xgp_Trsf2d^ T);

        /// <summary>
        /// 本地句柄
        /// </summary>
        property gp_Vec2d* Handle
        {
            gp_Vec2d* get() {
                return NativeHandle;
            }
        }

    private:
        gp_Vec2d* NativeHandle;
    };
};
#endif //_xgp_Vec2d_HeaderFile