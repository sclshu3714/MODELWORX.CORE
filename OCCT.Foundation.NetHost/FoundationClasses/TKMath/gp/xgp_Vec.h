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
#ifndef _xgp_Vec_HeaderFile
#define _xgp_Vec_HeaderFile
#pragma once
#include <gp_Vec.hxx>
#include "xgp_Dir.h"
#include "xgp_XYZ.h"
#include "xgp_Ax1.h"
#include "xgp_Ax2.h"
#include "xgp_Trsf.h"
#include "xgp_Pnt.h"
class gp_Vec;

namespace TKMath
{
    ref class xgp_Dir;
    ref class xgp_XYZ;
    ref class xgp_Ax1;
    ref class xgp_Ax2;
    ref class xgp_Trsf;
    ref class xgp_Pnt;
    //! Defines a 3D cartesian point.
    public ref class xgp_Vec
    {
    public:
        //! Creates a zero vector.
        xgp_Vec(void);

        /// <summary>
        /// 指针映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Vec(gp_Vec* pos);

        //! Creates a unitary vector from a direction V.
        xgp_Vec(xgp_Dir^ V);

        //! Creates a vector with a triplet of coordinates.
        xgp_Vec(xgp_XYZ^ Coord);

        //! Creates a point with its three cartesian coordinates.
        xgp_Vec(Standard_Real Xv, Standard_Real Yv, Standard_Real Zv);


        //! Creates a vector from two points. The length of the vector
        //! is the distance between P1 and P2
        xgp_Vec(xgp_Pnt^ P1, xgp_Pnt^ P2);


        //释放
        ~xgp_Vec();
        //释放
        !xgp_Vec();

        //! Changes the coordinate of range Index
        //! Index = 1 => X is modified
        //! Index = 2 => Y is modified
        //! Index = 3 => Z is modified
        //! Raised if Index != {1, 2, 3}.
        void SetCoord(Standard_Integer Index, Standard_Real Xi);

        //! For this vector, assigns
        //! -   the values Xv, Yv and Zv to its three coordinates.
        void SetCoord(Standard_Real Xv, Standard_Real Yv, Standard_Real Zv);

        //! Assigns the given value to the X coordinate of this vector.
        void SetX(Standard_Real X);

        //! Assigns the given value to the X coordinate of this vector.
        void SetY(Standard_Real Y);

        //! Assigns the given value to the X coordinate of this vector.
        void SetZ(Standard_Real Z);

        //! Assigns the three coordinates of Coord to this vector.
        void SetXYZ(xgp_XYZ^ Coord);

        //! Returns the  gp_Vec
        gp_Vec* GetVec();
        //! Returns the coordinate of range Index :
        //! Index = 1 => X is returned
        //! Index = 2 => Y is returned
        //! Index = 3 => Z is returned
        //! Raised if Index != {1, 2, 3}.
        Standard_Real Coord(Standard_Integer Index);

        //! For this vector returns its three coordinates Xv, Yv, and Zvinline
        void Coord(Standard_Real Xv, Standard_Real Yv, Standard_Real Zv);

        //! For this vector, returns its X coordinate.
        Standard_Real X();

        //! For this vector, returns its Y coordinate.
        Standard_Real Y();

        //! For this vector, returns its Z  coordinate.
        Standard_Real Z();

        //! For this vector, returns
        //! -   its three coordinates as a number triple
        xgp_XYZ^ XYZ();


        //! Returns True if the two vectors have the same magnitude value
        //! and the same direction. The precision values are LinearTolerance
        //! for the magnitude and AngularTolerance for the direction.
         Standard_Boolean IsEqual(xgp_Vec^ Other, Standard_Real LinearTolerance, Standard_Real AngularTolerance);


        //! Returns True if abs(<me>.Angle(Other) - PI/2.) <= AngularTolerance
        //! Raises VectorWithNullMagnitude if <me>.Magnitude() <= Resolution or
        //! Other.Magnitude() <= Resolution from gp
        Standard_Boolean IsNormal(xgp_Vec^ Other, Standard_Real AngularTolerance);


        //! Returns True if PI - <me>.Angle(Other) <= AngularTolerance
        //! Raises VectorWithNullMagnitude if <me>.Magnitude() <= Resolution or
        //! Other.Magnitude() <= Resolution from gp
        Standard_Boolean IsOpposite(xgp_Vec^ Other, Standard_Real AngularTolerance);


        //! Returns True if Angle(<me>, Other) <= AngularTolerance or
        //! PI - Angle(<me>, Other) <= AngularTolerance
        //! This definition means that two parallel vectors cannot define
        //! a plane but two vectors with opposite directions are considered
        //! as parallel. Raises VectorWithNullMagnitude if <me>.Magnitude() <= Resolution or
        //! Other.Magnitude() <= Resolution from gp
        Standard_Boolean IsParallel(xgp_Vec^ Other, Standard_Real AngularTolerance);


        //! Computes the angular value between <me> and <Other>
        //! Returns the angle value between 0 and PI in radian.
        //! Raises VectorWithNullMagnitude if <me>.Magnitude() <= Resolution from gp or
        //! Other.Magnitude() <= Resolution because the angular value is
        //! indefinite if one of the vectors has a null magnitude.
        Standard_Real Angle(xgp_Vec^ Other);

        //! Computes the angle, in radians, between this vector and
        //! vector Other. The result is a value between -Pi and Pi.
        //! For this, VRef defines the positive sense of rotation: the
        //! angular value is positive, if the cross product this ^ Other
        //! has the same orientation as VRef relative to the plane
        //! defined by the vectors this and Other. Otherwise, the
        //! angular value is negative.
        //! Exceptions
        //! xgp_VectorWithNullMagnitude if the magnitude of this
        //! vector, the vector Other, or the vector VRef is less than or
        //! equal to gp::Resolution().
        //! Standard_DomainError if this vector, the vector Other,
        //! and the vector VRef are coplanar, unless this vector and
        //! the vector Other are parallel.
        Standard_Real AngleWithRef(xgp_Vec^ Other, xgp_Vec^ VRef);

        //! Computes the magnitude of this vector.
        Standard_Real Magnitude();

        //! Computes the square magnitude of this vector.
        Standard_Real SquareMagnitude();

        //! Adds two vectors
        void Add(xgp_Vec^ Other);
        void operator += (xgp_Vec^ Other) {
            Add(Other);
        }

        //! Adds two vectors
         xgp_Vec^ Added(xgp_Vec^ Other);
         xgp_Vec^ operator + (xgp_Vec^ Other) {
            return Added(Other);
        }


        //! Subtracts two vectors
        void Subtract(xgp_Vec^ Right);
        void operator -= (xgp_Vec^ Right) {
            Subtract(Right);
        }

        //! Subtracts two vectors
         xgp_Vec^ Subtracted(xgp_Vec^ Right);
         xgp_Vec^ operator - (xgp_Vec^ Right) {
            return Subtracted(Right);
        }

        //! Multiplies a vector by a scalar
        void Multiply(Standard_Real Scalar);
        void operator *= (Standard_Real Scalar) {
            Multiply(Scalar);
        }

        //! Multiplies a vector by a scalar
         xgp_Vec^ Multiplied(Standard_Real Scalar);
         xgp_Vec^ operator * (Standard_Real Scalar) {
            return Multiplied(Scalar);
        }

        //! Divides a vector by a scalar
        void Divide(Standard_Real Scalar);
        void operator /= (Standard_Real Scalar) {
            Divide(Scalar);
        }

        //! Divides a vector by a scalar
         xgp_Vec^ Divided(Standard_Real Scalar);
         xgp_Vec^ operator / (Standard_Real Scalar) {
            return Divided(Scalar);
        }

        //! computes the cross product between two vectors
        void Cross(xgp_Vec^ Right);
        void operator ^= (xgp_Vec^ Right) {
            Cross(Right);
        }

        //! computes the cross product between two vectors
         xgp_Vec^ Crossed(xgp_Vec^ Right);
         xgp_Vec^ operator ^ (xgp_Vec^ Right) {
            return Crossed(Right);
        }


        //! Computes the magnitude of the cross
        //! product between <me> and Right.
        //! Returns || <me> ^ Right ||
        Standard_Real CrossMagnitude(xgp_Vec^ Right);


        //! Computes the square magnitude of
        //! the cross product between <me> and Right.
        //! Returns || <me> ^ Right ||**2
        Standard_Real CrossSquareMagnitude(xgp_Vec^ Right);

        //! Computes the triple vector product.
        //! <me> ^= (V1 ^ V2)
        void CrossCross(xgp_Vec^ V1, xgp_Vec^ V2);

        //! Computes the triple vector product.
        //! <me> ^ (V1 ^ V2)
         xgp_Vec^ CrossCrossed(xgp_Vec^ V1, xgp_Vec^ V2);

        //! computes the scalar product
        Standard_Real Dot(xgp_Vec^ Other);
        Standard_Real operator * (xgp_Vec^ Other) {
            return Dot(Other);
        }

        //! Computes the triple scalar product <me> * (V1 ^ V2).
        Standard_Real DotCross(xgp_Vec^ V1, xgp_Vec^ V2);

        //! normalizes a vector
        //! Raises an exception if the magnitude of the vector is
        //! lower or equal to Resolution from gp.
        void Normalize();

        //! normalizes a vector
        //! Raises an exception if the magnitude of the vector is
        //! lower or equal to Resolution from gp.
         xgp_Vec^ Normalized();

        //! Reverses the direction of a vector
        void Reverse();

        //! Reverses the direction of a vector
         xgp_Vec^ Reversed();
         xgp_Vec^ operator -() {
            return Reversed();
        }


        //! <me> is set to the following linear form :
        //! A1 * V1 + A2 * V2 + A3 * V3 + V4
        void SetLinearForm(Standard_Real A1, xgp_Vec^ V1, Standard_Real A2, xgp_Vec^ V2, Standard_Real A3, xgp_Vec^ V3, xgp_Vec^ V4);


        //! <me> is set to the following linear form :
        //! A1 * V1 + A2 * V2 + A3 * V3
        void SetLinearForm(Standard_Real A1, xgp_Vec^ V1, Standard_Real A2, xgp_Vec^ V2, Standard_Real A3, xgp_Vec^ V3);


        //! <me> is set to the following linear form :
        //! A1 * V1 + A2 * V2 + V3
        void SetLinearForm(Standard_Real A1, xgp_Vec^ V1, Standard_Real A2, xgp_Vec^ V2, xgp_Vec^ V3);


        //! <me> is set to the following linear form :
        //! A1 * V1 + A2 * V2
        void SetLinearForm(Standard_Real A1, xgp_Vec^ V1, Standard_Real A2, xgp_Vec^ V2);


        //! <me> is set to the following linear form : A1 * V1 + V2
        void SetLinearForm(Standard_Real A1, xgp_Vec^ V1, xgp_Vec^ V2);


        //! <me> is set to the following linear form : V1 + V2
        void SetLinearForm(xgp_Vec^ V1, xgp_Vec^ V2);

         void Mirror(xgp_Vec^ V);


        //! Performs the symmetrical transformation of a vector
        //! with respect to the vector V which is the center of
        //! the  symmetry.
          xgp_Vec^ Mirrored(xgp_Vec^ V);

         void Mirror(xgp_Ax1^ A1);


        //! Performs the symmetrical transformation of a vector
        //! with respect to an axis placement which is the axis
        //! of the symmetry.
          xgp_Vec^ Mirrored(xgp_Ax1^ A1);

         void Mirror(xgp_Ax2^ A2);


        //! Performs the symmetrical transformation of a vector
        //! with respect to a plane. The axis placement A2 locates
        //! the plane of the symmetry : (Location, XDirection, YDirection).
          xgp_Vec^ Mirrored(xgp_Ax2^ A2);

        void Rotate(xgp_Ax1^ A1, Standard_Real Ang);


        //! Rotates a vector. A1 is the axis of the rotation.
        //! Ang is the angular value of the rotation in radians.
         xgp_Vec^ Rotated(xgp_Ax1^ A1, Standard_Real Ang);

        void Scale(Standard_Real S);

        //! Scales a vector. S is the scaling value.
         xgp_Vec^ Scaled(Standard_Real S);

        //! Transforms a vector with the transformation T.
         void Transform(xgp_Trsf^ T);

        //! Transforms a vector with the transformation T.
        xgp_Vec^ Transformed(xgp_Trsf^ T);
        /// <summary>
        /// 本地句柄
        /// </summary>
        property gp_Vec* Handle
        {
            gp_Vec* get() {
                return NativeHandle;
            }
        }

    private:
        gp_Vec* NativeHandle;
    };
}
#endif //_xgp_Vec_HeaderFile
