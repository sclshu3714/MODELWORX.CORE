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

#ifndef _xgp_Dir_HeaderFile
#define _xgp_Dir_HeaderFile
#pragma once
#include <gp_Dir.hxx>
#include "xgp_Vec.h"
#include "xgp_XYZ.h"
#include "xgp_Ax1.h"
#include "xgp_Ax2.h"
#include "xgp_Trsf.h"


//! Describes a unit vector in 3D space. This unit vector is also called "Direction".
//! See Also
//! gce_MakeDir which provides functions for more complex
//! unit vector constructions
//! Geom_Direction which provides additional functions for
//! constructing unit vectors and works, in particular, with the
//! parametric equations of unit vectors.
namespace TKMath
{
    ref class xgp_Vec;
    ref class xgp_XYZ;
    ref class xgp_Ax1;
    ref class xgp_Ax2;
    ref class xgp_Trsf;
    public ref class xgp_Dir
    {
    public:

        //! Creates a direction corresponding to X axis.
        xgp_Dir();

        /// <summary>
        /// 指针映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Dir(gp_Dir* pos);
        /// <summary>
        ///  映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Dir(gp_Dir pos);

        //! Normalizes the vector V and creates a direction. Raises ConstructionError if V.Magnitude() <= Resolution.
        xgp_Dir(xgp_Vec^ V);

        //! Creates a direction from a triplet of coordinates. Raises ConstructionError if Coord.Modulus() <= Resolution from gp.
        xgp_Dir(xgp_XYZ^ Coord);

        //! Creates a direction with its 3 cartesian coordinates. Raises ConstructionError if Sqrt(Xv*Xv + Yv*Yv + Zv*Zv) <= Resolution
        //! Modification of the direction's coordinates
        //! If Sqrt (X*X + Y*Y + Z*Z) <= Resolution from gp where
        //! X, Y ,Z are the new coordinates it is not possible to
        //! construct the direction and the method raises the
        //! exception ConstructionError.
        xgp_Dir(Standard_Real^ Xv, Standard_Real^ Yv, Standard_Real^ Zv);


        //释放
        ~xgp_Dir();
        //释放
        !xgp_Dir();
        //! For this unit vector,  assigns the value Xi to:
        //! -   the X coordinate if Index is 1, or
        //! -   the Y coordinate if Index is 2, or
        //! -   the Z coordinate if Index is 3,
        //! and then normalizes it.
        //! Warning
        //! Remember that all the coordinates of a unit vector are
        //! implicitly modified when any single one is changed directly.
        //! Exceptions
        //! Standard_OutOfRange if Index is not 1, 2, or 3.
        //! Standard_ConstructionError if either of the following
        //! is less than or equal to gp::Resolution():
        //! -   Sqrt(Xv*Xv + Yv*Yv + Zv*Zv), or
        //! -   the modulus of the number triple formed by the new
        //! value Xi and the two other coordinates of this vector
        //! that were not directly modified.
        void SetCoord(Standard_Integer^ Index, Standard_Real^ Xi);

        //! For this unit vector,  assigns the values Xv, Yv and Zv to its three coordinates.
        //! Remember that all the coordinates of a unit vector are
        //! implicitly modified when any single one is changed directly.
        void SetCoord(Standard_Real^ Xv, Standard_Real^ Yv, Standard_Real^ Zv);

        //! Assigns the given value to the X coordinate of this   unit vector.
        void SetX(Standard_Real^ X);

        //! Assigns the given value to the Y coordinate of this   unit vector.
        void SetY(Standard_Real^ Y);

        //! Assigns the given value to the Z  coordinate of this   unit vector.
        void SetZ(Standard_Real^ Z);

        //! Assigns the three coordinates of Coord to this unit vector.
        void SetXYZ(xgp_XYZ^ Coord);

        //! Returns the gp_Dir
        gp_Dir GetDir();
        //! Returns the coordinate of range Index :
        //! Index = 1 => X is returned
        //! Index = 2 => Y is returned
        //! Index = 3 => Z is returned
        //! Exceptions
        //! Standard_OutOfRange if Index is not 1, 2, or 3.
        Standard_Real^ Coord(Standard_Integer^ Index);

        //! Returns for the  unit vector  its three coordinates Xv, Yv, and Zv.
        void Coord(Standard_Real^ Xv, Standard_Real^ Yv, Standard_Real^ Zv);

        //! Returns the X coordinate for a  unit vector.
        Standard_Real^ X();

        //! Returns the Y coordinate for a  unit vector.
        Standard_Real^ Y();

        //! Returns the Z coordinate for a  unit vector.
        Standard_Real^ Z();

        //! for this unit vector, returns  its three coordinates as a number triplea.
        xgp_XYZ^ XYZ();


        //! Returns True if the angle between the two directions is
        //! lower or equal to AngularTolerance.
        Standard_Boolean^ IsEqual(xgp_Dir^ Other, Standard_Real^ AngularTolerance);


        //! Returns True if  the angle between this unit vector and the unit vector Other is equal to Pi/2 (normal).
        Standard_Boolean^ IsNormal(xgp_Dir^ Other, Standard_Real^ AngularTolerance);


        //! Returns True if  the angle between this unit vector and the unit vector Other is equal to  Pi (opposite).
        Standard_Boolean^ IsOpposite(xgp_Dir^ Other, Standard_Real^ AngularTolerance);


        //! Returns true if the angle between this unit vector and the
        //! unit vector Other is equal to 0 or to Pi.
        //! Note: the tolerance criterion is given by AngularTolerance.
        Standard_Boolean^ IsParallel(xgp_Dir^ Other, Standard_Real^ AngularTolerance);


        //! Computes the angular value in radians between <me> and
        //! <Other>. This value is always positive in 3D space.
        //! Returns the angle in the range [0, PI]
        Standard_Real^ Angle(xgp_Dir^ Other);


        //! Computes the angular value between <me> and <Other>.
        //! <VRef> is the direction of reference normal to <me> and <Other>
        //! and its orientation gives the positive sense of rotation.
        //! If the cross product <me> ^ <Other> has the same orientation
        //! as <VRef> the angular value is positive else negative.
        //! Returns the angular value in the range -PI and PI (in radians). Raises  DomainError if <me> and <Other> are not parallel this exception is raised
        //! when <VRef> is in the same plane as <me> and <Other>
        //! The tolerance criterion is Resolution from package gp.
        Standard_Real^ AngleWithRef(xgp_Dir^ Other, xgp_Dir^ VRef);

        //! Computes the cross product between two directions
        //! Raises the exception ConstructionError if the two directions
        //! are parallel because the computed vector cannot be normalized
        //! to create a direction.
        void Cross(xgp_Dir^ Right);
        void operator ^= (xgp_Dir^ Right) {
            Cross(Right);
        }

        //! Computes the triple vector product.
        //! <me> ^ (V1 ^ V2)
        //! Raises the exception ConstructionError if V1 and V2 are parallel
        //! or <me> and (V1^V2) are parallel because the computed vector
        //! can't be normalized to create a direction.
        xgp_Dir^ Crossed(xgp_Dir^ Right);
        xgp_Dir^ operator ^ (xgp_Dir^ Right) {
            return Crossed(Right);
        }

        void CrossCross(xgp_Dir^ V1, xgp_Dir^ V2);

        //! Computes the double vector product this ^ (V1 ^ V2).
        //! -   CrossCrossed creates a new unit vector.
        //! Exceptions
        //! Standard_ConstructionError if:
        //! -   V1 and V2 are parallel, or
        //! -   this unit vector and (V1 ^ V2) are parallel.
        //! This is because, in these conditions, the computed vector
        //! is null and cannot be normalized.
        xgp_Dir^ CrossCrossed(xgp_Dir^ V1, xgp_Dir^ V2);

        //! Computes the scalar product
        Standard_Real^ Dot(xgp_Dir^ Other);
        Standard_Real^ operator * (xgp_Dir^ Other) {
            return Dot(Other);
        }


        //! Computes the triple scalar product <me> * (V1 ^ V2).
        //! Warnings :
        //! The computed vector V1' = V1 ^ V2 is not normalized
        //! to create a unitary vector. So this method never
        //! raises an exception even if V1 and V2 are parallel.
        Standard_Real^ DotCross(xgp_Dir^ V1, xgp_Dir^ V2);

        void Reverse();

        //! Reverses the orientation of a direction
        //! geometric transformations
        //! Performs the symmetrical transformation of a direction
        //! with respect to the direction V which is the center of
        //! the  symmetry.]
        xgp_Dir^ Reversed();
        xgp_Dir^ operator -() {
            return Reversed();
        }

        void Mirror(xgp_Dir^ V);


        //! Performs the symmetrical transformation of a direction
        //! with respect to the direction V which is the center of
        //! the  symmetry.
        xgp_Dir^ Mirrored(xgp_Dir^ V);

        void Mirror(xgp_Ax1^ A1);


        //! Performs the symmetrical transformation of a direction
        //! with respect to an axis placement which is the axis
        //! of the symmetry.
        xgp_Dir^ Mirrored(xgp_Ax1^ A1);

        void Mirror(xgp_Ax2^ A2);


        //! Performs the symmetrical transformation of a direction
        //! with respect to a plane. The axis placement A2 locates
        //! the plane of the symmetry : (Location, XDirection, YDirection).
        xgp_Dir^ Mirrored(xgp_Ax2^ A2);

        void Rotate(xgp_Ax1^ A1, Standard_Real^ Ang);


        //! Rotates a direction. A1 is the axis of the rotation.
        //! Ang is the angular value of the rotation in radians.
        xgp_Dir^ Rotated(xgp_Ax1^ A1, Standard_Real^ Ang);

        void Transform(xgp_Trsf^ T);


        //! Transforms a direction with a "Trsf" from gp.
        //! Warnings :
        //! If the scale factor of the "Trsf" T is negative then the
        //! direction <me> is reversed.
        xgp_Dir^ Transformed(xgp_Trsf^ T);
        /// <summary>
        /// 本地句柄
        /// </summary>
        property gp_Dir* Handle
        {
            gp_Dir* get() {
                return NativeHandle;
            }
        }

    private:
        gp_Dir* NativeHandle;
    };
}
#endif // _xgp_Dir_HeaderFile