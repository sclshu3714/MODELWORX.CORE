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
#ifndef _xgp_Pnt2d_HeaderFile
#define _xgp_Pnt2d_HeaderFile
#pragma once
#include "gp_Pnt2d.hxx"
#include "xgp_XY.h"
#include "xgp_Ax2d.h"
#include "xgp_Trsf2d.h"
#include "xgp_Vec2d.h"
class gp_Pnt2d;

//! Defines  a non-persistent 2D cartesian point.
namespace TKMath
{
    ref class xgp_XY;
    ref class xgp_Ax2d;
    ref class xgp_Trsf2d;
    ref class xgp_Vec2d;
    public ref class xgp_Pnt2d
    {
    public:
        //! Creates a point with zero coordinates.
        xgp_Pnt2d();

        /// <summary>
        /// 指针映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Pnt2d(gp_Pnt2d* pos);

        //! Creates a point with a doublet of coordinates.
        xgp_Pnt2d(xgp_XY^ Coord);


        //! Creates a  point with its 2 cartesian's coordinates : Xp, Yp.
        xgp_Pnt2d(Standard_Real Xp, Standard_Real Yp);


        //释放
        ~xgp_Pnt2d();
        //释放
        !xgp_Pnt2d();

        //! Assigns the value Xi to the coordinate that corresponds to Index:
        //! Index = 1 => X is modified
        //! Index = 2 => Y is modified
        //! Raises OutOfRange if Index != {1, 2}.
        void SetCoord(Standard_Integer Index, Standard_Real Xi);

        //! For this point, assigns the values Xp and Yp to its two coordinates
        void SetCoord(Standard_Real Xp, Standard_Real Yp);

        //! Assigns the given value to the X  coordinate of this point.
        void SetX(Standard_Real X);

        //! Assigns the given value to the Y  coordinate of this point.
        void SetY(Standard_Real Y);

        //! Assigns the two coordinates of Coord to this point.
        void SetXY(xgp_XY^ Coord);

        //! Returns the gp_Pnt2d
        gp_Pnt2d* GetPnt2d();

        //! Returns the coordinate of range Index :
        //! Index = 1 => X is returned
        //! Index = 2 => Y is returned
        //! Raises OutOfRange if Index != {1, 2}.
        Standard_Real Coord(Standard_Integer Index);

        //! For this point returns its two coordinates as a number pair.
        void Coord(Standard_Real Xp, Standard_Real Yp);

        //! For this point, returns its X  coordinate.
        Standard_Real X();

        //! For this point, returns its Y coordinate.
        Standard_Real Y();

        //! For this point, returns its two coordinates as a number pair.
        xgp_XY^ XY();

        //! For this point, returns its two coordinates as a number pair.
        xgp_XY^ Coord();


        //! Returns the coordinates of this point.
        //! Note: This syntax allows direct modification of the returned value.
        xgp_XY^ ChangeCoord();

        //! Comparison
        //! Returns True if the distance between the two
        //! points is lower or equal to LinearTolerance.
        Standard_Boolean IsEqual(xgp_Pnt2d^ Other, Standard_Real LinearTolerance);

        //! Computes the distance between two points.
        Standard_Real Distance(xgp_Pnt2d^ Other);

        //! Computes the square distance between two points.
        Standard_Real SquareDistance(xgp_Pnt2d^ Other);


        //! Performs the symmetrical transformation of a point
        //! with respect to the point P which is the center of
        //! the  symmetry.
        void Mirror(xgp_Pnt2d^ P);


        //! Performs the symmetrical transformation of a point
        //! with respect to an axis placement which is the axis
        xgp_Pnt2d^ Mirrored(xgp_Pnt2d^ P);

        void Mirror(xgp_Ax2d^ A);


        //! Rotates a point. A1 is the axis of the rotation.
        //! Ang is the angular value of the rotation in radians.
        xgp_Pnt2d^ Mirrored(xgp_Ax2d^ A);

        void Rotate(xgp_Pnt2d^ P, Standard_Real Ang);

        //! Scales a point. S is the scaling value.
        xgp_Pnt2d^ Rotated(xgp_Pnt2d^ P, Standard_Real Ang);

        void Scale(xgp_Pnt2d^ P, Standard_Real S);

        //! Transforms a point with the transformation T.
        xgp_Pnt2d^ Scaled(xgp_Pnt2d^ P, Standard_Real S);

        void Transform(xgp_Trsf2d^ T);


        //! Translates a point in the direction of the vector V.
        //! The magnitude of the translation is the vector's magnitude.
        xgp_Pnt2d^ Transformed(xgp_Trsf2d^ T);

        void Translate(xgp_Vec2d^ V);


        //! Translates a point from the point P1 to the point P2.
        xgp_Pnt2d^ Translated(xgp_Vec2d^ V);

        void Translate(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2);

        xgp_Pnt2d^ Translated(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2);

        /// <summary>
        /// 本地句柄
        /// </summary>
        property gp_Pnt2d* Handle
        {
            gp_Pnt2d* get() {
                return NativeHandle;
            }
        }

    private:
        gp_Pnt2d* NativeHandle;
    };
};
#endif // _xgp_Pnt2d_HeaderFile