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

#ifndef _xgp_Pnt_HeaderFile
#define _xgp_Pnt_HeaderFile
#pragma once
#include <gp_Pnt.hxx>
#include <gp_Ax2.hxx>
#include "xgp_XYZ.h"
#include "xgp_Trsf.h"
#include "xgp_Vec.h"
#include "xgp_Ax1.h"
#include "xgp_Ax2.h"
class gp_Pnt;
class gp_Ax2;


namespace TKMath
{
    ref class xgp_XYZ;
    ref class xgp_Trsf;
    ref class xgp_Vec;
    ref class xgp_Ax1;
    ref class xgp_Ax2;
    //! Defines a 3D cartesian point.
    public ref class xgp_Pnt
    {
    public:

        //! Creates a point with zero coordinates.
        xgp_Pnt(void);

        //! Creates a point from a XYZ object.
        xgp_Pnt(xgp_XYZ^ Coord);

        /// <summary>
        /// 指针映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Pnt(gp_Pnt* pos);

        //! Creates a  point with its 3 cartesian's coordinates : Xp, Yp, Zp.
        xgp_Pnt(Standard_Real Xp, Standard_Real Yp, Standard_Real Zp);

        //! 释放
        ~xgp_Pnt();
        //! 释放
        !xgp_Pnt();

        //! Changes the coordinate of range Index :
        //! Index = 1 => X is modified
        //! Index = 2 => Y is modified
        //! Index = 3 => Z is modified
        //! Raised if Index != {1, 2, 3}.
        void SetCoord(Standard_Integer Index, Standard_Real Xi);

        //! For this point, assigns  the values Xp, Yp and Zp to its three coordinates.
        void SetCoord(Standard_Real Xp, Standard_Real Yp, Standard_Real Zp);

        //! Assigns the given value to the X coordinate of this point.
        void SetX(Standard_Real X);

        //! Assigns the given value to the Y coordinate of this point.
        void SetY(Standard_Real Y);

        //! Assigns the given value to the Z coordinate of this point.
        void SetZ(Standard_Real Z);

        //! Assigns the three coordinates of Coord to this point.
        void SetXYZ(xgp_XYZ^ Coord);

        //! 获取
        gp_Pnt* GetPnt();

        //! Returns the coordinate of corresponding to the value of  Index :
        //! Index = 1 => X is returned
        //! Index = 2 => Y is returned
        //! Index = 3 => Z is returned
        //! Raises OutOfRange if Index != {1, 2, 3}.
        //! Raised if Index != {1, 2, 3}.
        Standard_Real Coord(Standard_Integer Index);

        //! For this point gives its three coordinates Xp, Yp and Zp.
        void Coord(Standard_Real Xp, Standard_Real Yp, Standard_Real Zp);

        //! For this point, returns its X coordinate.
        Standard_Real X();

        //! For this point, returns its Y coordinate.
        Standard_Real Y();

        //! For this point, returns its Z coordinate.
        Standard_Real Z();

        //! For this point, returns its three coordinates as a XYZ object.
        xgp_XYZ^ XYZ();

        //! For this point, returns its three coordinates as a XYZ object.
        xgp_XYZ^ Coord();


        //! Returns the coordinates of this point.
        //! Note: This syntax allows direct modification of the returned value.
        xgp_XYZ^ ChangeCoord();

        //! Assigns the result of the following expression to this point
        //! (Alpha*this + Beta*P) / (Alpha + Beta)
        void BaryCenter(Standard_Real Alpha, xgp_Pnt^ P, Standard_Real Beta);

        //! Comparison
        //! Returns True if the distance between the two points is
        //! lower or equal to LinearTolerance.
        Standard_Boolean IsEqual(xgp_Pnt^ Other, Standard_Real LinearTolerance);

        //! Computes the distance between two points.
        Standard_Real Distance(xgp_Pnt^ Other);

        //! Computes the square distance between two points.
        Standard_Real SquareDistance(xgp_Pnt^ Other);


        //! Performs the symmetrical transformation of a point
        //! with respect to the point P which is the center of
        //! the  symmetry.
        void Mirror(xgp_Pnt^ P);


        //! Performs the symmetrical transformation of a point
        //! with respect to an axis placement which is the axis
        //! of the symmetry.
        xgp_Pnt^ Mirrored(xgp_Pnt^ P);

        void Mirror(xgp_Ax1^ A1);


        //! Performs the symmetrical transformation of a point
        //! with respect to a plane. The axis placement A2 locates
        //! the plane of the symmetry : (Location, XDirection, YDirection).
        xgp_Pnt^ Mirrored(xgp_Ax1^ A1);

        void Mirror(xgp_Ax2^ A2);


        //! Rotates a point. A1 is the axis of the rotation.
        //! Ang is the angular value of the rotation in radians.
         xgp_Pnt^ Mirrored(xgp_Ax2^ A2);

        void Rotate(xgp_Ax1^ A1, Standard_Real Ang);

        //! Scales a point. S is the scaling value.
        xgp_Pnt^ Rotated(xgp_Ax1^ A1, Standard_Real Ang);

        void Scale(xgp_Pnt^ P, Standard_Real S);

        //! Transforms a point with the transformation T.
        xgp_Pnt^ Scaled(xgp_Pnt^ P, Standard_Real S);

        void Transform(xgp_Trsf^ T);


        //! Translates a point in the direction of the vector V.
        //! The magnitude of the translation is the vector's magnitude.
        xgp_Pnt^ Transformed(xgp_Trsf^ T);

        void Translate(xgp_Vec^ V);


        //! Translates a point from the point P1 to the point P2.
        xgp_Pnt^ Translated(xgp_Vec^ V);

        void Translate(xgp_Pnt^ P1, xgp_Pnt^ P2);

        xgp_Pnt^ Translated(xgp_Pnt^ P1, xgp_Pnt^ P2);

        /// <summary>
        /// 本地句柄
        /// </summary>
        property gp_Pnt* Handle
        {
            gp_Pnt* get() {
                return NativeHandle;
            }
        }

    private:
        gp_Pnt* NativeHandle;
    };
}
#endif // _xgp_Pnt_HeaderFile