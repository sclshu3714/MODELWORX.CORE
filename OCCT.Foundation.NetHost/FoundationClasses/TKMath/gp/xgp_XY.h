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
//! Thisnamespace TKMath  {  public ref class describes a cartesian coordinate entity in 2D
//! space {X,Y}. Thisnamespace TKMath  {  public ref class is non persistent. This entity used
//! for algebraic calculation. An XY can be transformed with a
//! Trsf2d or a  GTrsf2d from package gp.
//! It is used in vectorial computations or for holding this type
//! of information in data structures.
#ifndef _xgp_XY_HeaderFile
#define _xgp_XY_HeaderFile
#pragma once
#include <gp_XY.hxx>
#include "xgp_Mat2d.h"
class gp_XY;

namespace TKMath  
{  
    ref class xgp_Mat2d;
    public ref class xgp_XY
    {
    public:
        //! Creates XY object with zero coordinates (0,0).
        xgp_XY(void);

        /// <summary>
        /// 指针映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_XY(gp_XY* pos);

        //! a number pair defined by the XY coordinates
        xgp_XY(Standard_Real X, Standard_Real Y);

        //释放
        ~xgp_XY();
        //释放
        !xgp_XY();

        //! modifies the coordinate of range Index
        //! Index = 1 => X is modified
        //! Index = 2 => Y is modified
        //! Raises OutOfRange if Index != {1, 2}.
        void SetCoord(Standard_Integer Index, Standard_Real Xi);

        //! For this number pair, assigns
        //! the values X and Y to its coordinates
        void SetCoord(Standard_Real X, Standard_Real Y);

        //! Assigns the given value to the X coordinate of this number pair.
        void SetX(Standard_Real X);

        //! Assigns the given value to the Y  coordinate of this number pair.
        void SetY(Standard_Real Y);

        //! returns the gp_XY
        gp_XY* GetXY();
        //! returns the coordinate of range Index :
        //! Index = 1 => X is returned
        //! Index = 2 => Y is returned
        //! Raises OutOfRange if Index != {1, 2}.
        Standard_Real Coord(Standard_Integer Index);

        Standard_Real ChangeCoord(Standard_Integer theIndex);

        //! For this number pair, returns its coordinates X and Y.
        void Coord(Standard_Real X, Standard_Real Y);

        //! Returns the X coordinate of this number pair.
        Standard_Real X();

        //! Returns the Y coordinate of this number pair.
        Standard_Real Y();

        //! Computes Sqrt (X*X + Y*Y) where X and Y are the two coordinates of this number pair.
        Standard_Real Modulus();

        //! Computes X*X + Y*Y where X and Y are the two coordinates of this number pair.
        Standard_Real SquareModulus();


        //! Returns true if the coordinates of this number pair are
        //! equal to the respective coordinates of the number pair
        //! Other, within the specified tolerance Tolerance. I.e.:
        //! abs(<me>.X() - Other.X()) <= Tolerance and
        //! abs(<me>.Y() - Other.Y()) <= Tolerance and
        //! computations
        Standard_Boolean IsEqual(xgp_XY^ Other, Standard_Real Tolerance);

        //! Computes the sum of this number pair and number pair Other
        //! <me>.X() = <me>.X() + Other.X()
        //! <me>.Y() = <me>.Y() + Other.Y()
        void Add(xgp_XY^ Other);
        void operator += (xgp_XY^ Other) {
            Add(Other);
        }

        //! Computes the sum of this number pair and number pair Other
        //! new.X() = <me>.X() + Other.X()
        //! new.Y() = <me>.Y() + Other.Y()
        xgp_XY^ Added(xgp_XY^ Other);
        xgp_XY^ operator + (xgp_XY^ Other) {
            return Added(Other);
        }


        //! Real D = <me>.X() * Other.Y() - <me>.Y() * Other.X()
        Standard_Real Crossed(xgp_XY^ Right);
        Standard_Real operator ^ (xgp_XY^ Right) {
            return Crossed(Right);
        }


        //! computes the magnitude of the cross product between <me> and
        //! Right. Returns || <me> ^ Right ||
        Standard_Real CrossMagnitude(xgp_XY^ Right);


        //! computes the square magnitude of the cross product between <me> and
        //! Right. Returns || <me> ^ Right ||**2
        Standard_Real CrossSquareMagnitude(xgp_XY^ Right);

        //! divides <me> by a real.
        void Divide(Standard_Real Scalar);
        void operator /= (Standard_Real Scalar) {
            Divide(Scalar);
        }

        //! Divides <me> by a real.
        xgp_XY^ Divided(Standard_Real Scalar);
        xgp_XY^ operator / (Standard_Real Scalar) {
            return Divided(Scalar);
        }

        //! Computes the scalar product between <me> and Other
        Standard_Real Dot(xgp_XY^ Other);
        Standard_Real operator * (xgp_XY^ Other) {
            return Dot(Other);
        }


        //! <me>.X() = <me>.X() * Scalar;
        //! <me>.Y() = <me>.Y() * Scalar;
        void Multiply(Standard_Real Scalar);
        void operator *= (Standard_Real Scalar) {
            Multiply(Scalar);
        }


        //! <me>.X() = <me>.X() * Other.X();
        //! <me>.Y() = <me>.Y() * Other.Y();
        void Multiply(xgp_XY^ Other);
        void operator *= (xgp_XY^ Other) {
            Multiply(Other);
        }

        //! <me> = Matrix * <me>
        void Multiply(xgp_Mat2d^ Matrix);
        void operator *= (xgp_Mat2d^ Matrix) {
            Multiply(Matrix);
        }


        //! New.X() = <me>.X() * Scalar;
        //! New.Y() = <me>.Y() * Scalar;
        xgp_XY^ Multiplied(Standard_Real Scalar);
        xgp_XY^ operator * (Standard_Real Scalar) {
            return Multiplied(Scalar);
        }


        //! new.X() = <me>.X() * Other.X();
        //! new.Y() = <me>.Y() * Other.Y();
        xgp_XY^ Multiplied(xgp_XY^ Other);

        //! New = Matrix * <me>
        xgp_XY^ Multiplied(xgp_Mat2d^ Matrix);
        xgp_XY^ operator * (xgp_Mat2d^ Matrix) {
            return Multiplied(Matrix);
        }


        //! <me>.X() = <me>.X()/ <me>.Modulus()
        //! <me>.Y() = <me>.Y()/ <me>.Modulus()
        //! Raises ConstructionError if <me>.Modulus() <= Resolution from gp
        void Normalize();


        //! New.X() = <me>.X()/ <me>.Modulus()
        //! New.Y() = <me>.Y()/ <me>.Modulus()
        //! Raises ConstructionError if <me>.Modulus() <= Resolution from gp
        xgp_XY^ Normalized();


        //! <me>.X() = -<me>.X()
        //! <me>.Y() = -<me>.Y()
        void Reverse();


        //! New.X() = -<me>.X()
        //! New.Y() = -<me>.Y()
        xgp_XY^ Reversed();
        xgp_XY^ operator -() {
            return Reversed();
        }


        //! Computes  the following linear combination and
        //! assigns the result to this number pair:
        //! A1 * XY1 + A2 * XY2
        void SetLinearForm(Standard_Real A1, xgp_XY^ XY1, Standard_Real A2, xgp_XY^ XY2);


        //! --  Computes  the following linear combination and
        //! assigns the result to this number pair:
        //! A1 * XY1 + A2 * XY2 + XY3
        void SetLinearForm(Standard_Real A1, xgp_XY^ XY1, Standard_Real A2, xgp_XY^ XY2, xgp_XY^ XY3);


        //! Computes  the following linear combination and
        //! assigns the result to this number pair:
        //! A1 * XY1 + XY2
        void SetLinearForm(Standard_Real A1, xgp_XY^ XY1, xgp_XY^ XY2);


        //! Computes  the following linear combination and
        //! assigns the result to this number pair:
        //! XY1 + XY2
        void SetLinearForm(xgp_XY^ XY1, xgp_XY^ XY2);
                                               

        //! <me>.X() = <me>.X() - Other.X()
        //! <me>.Y() = <me>.Y() - Other.Y()
        void Subtract(xgp_XY^ Right);
        void operator -= (xgp_XY^ Right) {
            Subtract(Right);
        }


        //! new.X() = <me>.X() - Other.X()
        //! new.Y() = <me>.Y() - Other.Y()
        xgp_XY^ Subtracted(xgp_XY^ Right);
        xgp_XY^ operator - (xgp_XY^ Right) {
            return Subtracted(Right);
        }
        /// <summary>
        /// 本地句柄
        /// </summary>
        property gp_XY* Handle
        {
            gp_XY* get() {
                return NativeHandle;
            }
        }

        private:
            gp_XY* NativeHandle;
    };
};
#endif //_xgp_XY_HeaderFile