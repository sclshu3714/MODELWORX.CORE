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
#ifndef _xgp_XYZ_HeaderFile
#define _xgp_XYZ_HeaderFile
#pragma once
#include <gp_XYZ.hxx>
#include "xgp_Mat.h"

namespace TKMath
{
    ref class xgp_Mat;

    //! Defines a 3D cartesian point.
    public ref class xgp_XYZ
    {
    public:
        //! Creates an XYZ object with zero co-ordinates (0,0,0)
        xgp_XYZ(void);

        /// <summary>
        /// 指针映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_XYZ(gp_XYZ* pos);

        //! creates an XYZ with given coordinates
        xgp_XYZ(Standard_Real X, Standard_Real Y, Standard_Real Z);

        //释放
        ~xgp_XYZ();
        //释放
        !xgp_XYZ();

        //! For this XYZ object, assigns
        //! the values X, Y and Z to its three coordinates
        void SetCoord(Standard_Real X, Standard_Real Y, Standard_Real Z);


        //! modifies the coordinate of range Index
        //! Index = 1 => X is modified
        //! Index = 2 => Y is modified
        //! Index = 3 => Z is modified
        //! Raises OutOfRange if Index != {1, 2, 3}.
        void SetCoord(Standard_Integer Index, Standard_Real Xi);

        //! Assigns the given value to the X coordinate
        void SetX(Standard_Real X);

        //! Assigns the given value to the Y coordinate
        void SetY(Standard_Real Y);

        //! Assigns the given value to the Z coordinate
        void SetZ(Standard_Real Z);

        //! returns the gp_XYZ
        gp_XYZ* GetXYZ();
        //! returns the coordinate of range Index :
        //! Index = 1 => X is returned
        //! Index = 2 => Y is returned
        //! Index = 3 => Z is returned
        //!
        //! Raises OutOfRange if Index != {1, 2, 3}.
        Standard_Real Coord(Standard_Integer Index);

        Standard_Real ChangeCoord(Standard_Integer theIndex);

        void Coord(Standard_Real X, Standard_Real Y, Standard_Real Z);

        //! Returns a ptr to coordinates location.
        //! Is useful for algorithms, but DOES NOT PERFORM
        //! ANY CHECKS!
        inline Standard_Real GetData() { return (x); }

        //! Returns a ptr to coordinates location.
        //! Is useful for algorithms, but DOES NOT PERFORM
        //! ANY CHECKS!
        inline Standard_Real ChangeData() { return (x); }

        //! Returns the X coordinate
        Standard_Real X();

        //! Returns the Y coordinate
        Standard_Real Y();

        //! Returns the Z coordinate
        Standard_Real Z();

        //! computes Sqrt (X*X + Y*Y + Z*Z) where X, Y and Z are the three coordinates of this XYZ object.
        Standard_Real Modulus();

        //! Computes X*X + Y*Y + Z*Z where X, Y and Z are the three coordinates of this XYZ object.
        Standard_Real SquareModulus();


        //! Returns True if he coordinates of this XYZ object are
        //! equal to the respective coordinates Other,
        //! within the specified tolerance Tolerance. I.e.:
        //! abs(<me>.X() - Other.X()) <= Tolerance and
        //! abs(<me>.Y() - Other.Y()) <= Tolerance and
        //! abs(<me>.Z() - Other.Z()) <= Tolerance.
        Standard_Boolean IsEqual(xgp_XYZ^ Other, Standard_Real Tolerance);


        //! <me>.X() = <me>.X() + Other.X()
        //! <me>.Y() = <me>.Y() + Other.Y()
        //! <me>.Z() = <me>.Z() + Other.Z()
        void Add(xgp_XYZ^ Other);
        void operator += (xgp_XYZ^ Other) {
            Add(Other);
        }


        //! new.X() = <me>.X() + Other.X()
        //! new.Y() = <me>.Y() + Other.Y()
        //! new.Z() = <me>.Z() + Other.Z()
        xgp_XYZ^ Added(xgp_XYZ^ Other);
        xgp_XYZ^ operator + (xgp_XYZ^ Other) {
            return Added(Other);
        }


        //! <me>.X() = <me>.Y() * Other.Z() - <me>.Z() * Other.Y()
        //! <me>.Y() = <me>.Z() * Other.X() - <me>.X() * Other.Z()
        //! <me>.Z() = <me>.X() * Other.Y() - <me>.Y() * Other.X()
        void Cross(xgp_XYZ^ Right);
        void operator ^= (xgp_XYZ^ Right) {
            Cross(Right);
        }


        //! new.X() = <me>.Y() * Other.Z() - <me>.Z() * Other.Y()
        //! new.Y() = <me>.Z() * Other.X() - <me>.X() * Other.Z()
        //! new.Z() = <me>.X() * Other.Y() - <me>.Y() * Other.X()
        xgp_XYZ^ Crossed(xgp_XYZ^ Right);
        xgp_XYZ^ operator ^ (xgp_XYZ^ Right) {
            return Crossed(Right);
        }


        //! Computes the magnitude of the cross product between <me> and
        //! Right. Returns || <me> ^ Right ||
        Standard_Real CrossMagnitude(xgp_XYZ^ Right);


        //! Computes the square magnitude of the cross product between <me> and
        //! Right. Returns || <me> ^ Right ||**2
        Standard_Real CrossSquareMagnitude(xgp_XYZ^ Right);

        //! Triple vector product
        //! Computes <me> = <me>.Cross(Coord1.Cross(Coord2))
        void CrossCross(xgp_XYZ^ Coord1, xgp_XYZ^ Coord2);

        //! Triple vector product
        //! computes New = <me>.Cross(Coord1.Cross(Coord2))
        xgp_XYZ^ CrossCrossed(xgp_XYZ^ Coord1, xgp_XYZ^ Coord2);

        //! divides <me> by a real.
        void Divide(Standard_Real Scalar);
        void operator /= (Standard_Real Scalar) {
            Divide(Scalar);
        }

        //! divides <me> by a real.
        xgp_XYZ^ Divided(Standard_Real Scalar);
        xgp_XYZ^ operator / (Standard_Real Scalar) {
            return Divided(Scalar);
        }

        //! computes the scalar product between <me> and Other
        Standard_Real Dot(xgp_XYZ^ Other);
        Standard_Real operator * (xgp_XYZ^ Other) {
            return Dot(Other);
        }

        //! computes the triple scalar product
        Standard_Real DotCross(xgp_XYZ^ Coord1, xgp_XYZ^ Coord2);


        //! <me>.X() = <me>.X() * Scalar;
        //! <me>.Y() = <me>.Y() * Scalar;
        //! <me>.Z() = <me>.Z() * Scalar;
        void Multiply(Standard_Real Scalar);
        void operator *= (Standard_Real Scalar) {
            Multiply(Scalar);
        }


        //! <me>.X() = <me>.X() * Other.X();
        //! <me>.Y() = <me>.Y() * Other.Y();
        //! <me>.Z() = <me>.Z() * Other.Z();
        void Multiply(xgp_XYZ^ Other);
        void operator *= (xgp_XYZ^ Other) {
            Multiply(Other);
        }

        //! <me> = Matrix * <me>
        void Multiply(xgp_Mat^ Matrix);
        void operator *= (xgp_Mat^ Matrix) {
            Multiply(Matrix);
        }


        //! New.X() = <me>.X() * Scalar;
        //! New.Y() = <me>.Y() * Scalar;
        //! New.Z() = <me>.Z() * Scalar;
        xgp_XYZ^ Multiplied(Standard_Real Scalar);
        xgp_XYZ^ operator * (Standard_Real Scalar) {
            return Multiplied(Scalar);
        }


        //! new.X() = <me>.X() * Other.X();
        //! new.Y() = <me>.Y() * Other.Y();
        //! new.Z() = <me>.Z() * Other.Z();
        xgp_XYZ^ Multiplied(xgp_XYZ^ Other);

        //! New = Matrix * <me>
        xgp_XYZ^ Multiplied(xgp_Mat^ Matrix);
        xgp_XYZ^ operator * (xgp_Mat^ Matrix) {
            return Multiplied(Matrix);
        }


        //! <me>.X() = <me>.X()/ <me>.Modulus()
        //! <me>.Y() = <me>.Y()/ <me>.Modulus()
        //! <me>.Z() = <me>.Z()/ <me>.Modulus()
        //! Raised if <me>.Modulus() <= Resolution from gp
        void Normalize();


        //! New.X() = <me>.X()/ <me>.Modulus()
        //! New.Y() = <me>.Y()/ <me>.Modulus()
        //! New.Z() = <me>.Z()/ <me>.Modulus()
        //! Raised if <me>.Modulus() <= Resolution from gp
        xgp_XYZ^ Normalized();


        //! <me>.X() = -<me>.X()
        //! <me>.Y() = -<me>.Y()
        //! <me>.Z() = -<me>.Z()
        void Reverse();


        //! New.X() = -<me>.X()
        //! New.Y() = -<me>.Y()
        //! New.Z() = -<me>.Z()
        xgp_XYZ^ Reversed();


        //! <me>.X() = <me>.X() - Other.X()
        //! <me>.Y() = <me>.Y() - Other.Y()
        //! <me>.Z() = <me>.Z() - Other.Z()
        void Subtract(xgp_XYZ^ Right);
        void operator -= (xgp_XYZ^ Right) {
            Subtract(Right);
        }


        //! new.X() = <me>.X() - Other.X()
        //! new.Y() = <me>.Y() - Other.Y()
        //! new.Z() = <me>.Z() - Other.Z()
        xgp_XYZ^ Subtracted(xgp_XYZ^ Right);
        xgp_XYZ^ operator - (xgp_XYZ^ Right) {
            return Subtracted(Right);
        }


        //! <me> is set to the following linear form :
        //! A1 * XYZ1 + A2 * XYZ2 + A3 * XYZ3 + XYZ4
        void SetLinearForm(Standard_Real A1, xgp_XYZ^ XYZ1, Standard_Real A2, xgp_XYZ^ XYZ2, Standard_Real A3, xgp_XYZ^ XYZ3, xgp_XYZ^ XYZ4);


        //! <me> is set to the following linear form :
        //! A1 * XYZ1 + A2 * XYZ2 + A3 * XYZ3
        void SetLinearForm(Standard_Real A1, xgp_XYZ^ XYZ1, Standard_Real A2, xgp_XYZ^ XYZ2, Standard_Real A3, xgp_XYZ^ XYZ3);


        //! <me> is set to the following linear form :
        //! A1 * XYZ1 + A2 * XYZ2 + XYZ3
        void SetLinearForm(Standard_Real A1, xgp_XYZ^ XYZ1, Standard_Real A2, xgp_XYZ^ XYZ2, xgp_XYZ^ XYZ3);


        //! <me> is set to the following linear form :
        //! A1 * XYZ1 + A2 * XYZ2
        void SetLinearForm(Standard_Real A1, xgp_XYZ^ XYZ1, Standard_Real A2, xgp_XYZ^ XYZ2);


        //! <me> is set to the following linear form :
        //! A1 * XYZ1 + XYZ2
        void SetLinearForm(Standard_Real A1, xgp_XYZ^ XYZ1, xgp_XYZ^ XYZ2);


        //! <me> is set to the following linear form :
        //! XYZ1 + XYZ2
        void SetLinearForm(xgp_XYZ^ XYZ1, xgp_XYZ^ XYZ2);


        //! Dumps the content of me into the stream
        void DumpJson(Standard_OStream theOStream, Standard_Integer theDepth);

        /// <summary>
        /// 本地句柄
        /// </summary>
        property gp_XYZ* Handle
        {
            gp_XYZ* get() {
                return NativeHandle;
            }
        }
    private:
        Standard_Real x;
        Standard_Real y;
        Standard_Real z;
        gp_XYZ* NativeHandle;

    };
};
#endif //_xgp_XYZ_HeaderFile
