// Created on: 2010-05-11
// Created by: Kirill GAVRILOV
// Copyright (c) 2010-2014 OPEN CASCADE SAS
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
//! Represents operation of rotation in 3d space as queternion
//! and implements operations with rotations basing on
//! quaternion mathematics.
//!
//! In addition, provides methods for conversion to and from other
//! representatons of rotation (3*3 matrix, vector and
//! angle, Euler angles)
#pragma once
#include <gp_Quaternion.hxx>
#include "xgp_Vec.h"
#include "xgp_Mat.h"

namespace TKMath
{
    ref class xgp_Vec;
    ref class xgp_Mat;
    public ref class xgp_Quaternion
    {
    public:
        //! Creates an identity quaternion
        xgp_Quaternion(void);

        /// <summary>
        /// 指针映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Quaternion(gp_Quaternion* pos);

        //! Creates quaternion 
        xgp_Quaternion(gp_Quaternion pos);

        //! Creates quaternion directly from component values
        xgp_Quaternion(Standard_Real^ x, Standard_Real^ y, Standard_Real^ z, Standard_Real^ w);

        //! Creates copy of another quaternion
        xgp_Quaternion(xgp_Quaternion^ theToCopy);

        //! Creates quaternion representing shortest-arc rotation
        //! operator producing vector theVecTo from vector theVecFrom.
        xgp_Quaternion(xgp_Vec^ theVecFrom, xgp_Vec^ theVecTo);

        //! Creates quaternion representing shortest-arc rotation
        //! operator producing vector theVecTo from vector theVecFrom.
        //! Additional vector theHelpCrossVec defines preferred direction for
        //! rotation and is used when theVecTo and theVecFrom are directed
        //! oppositely.
        xgp_Quaternion(xgp_Vec^ theVecFrom, xgp_Vec^ theVecTo, xgp_Vec^ theHelpCrossVec);

        //! Creates quaternion representing rotation on angle
        //! theAngle around vector theAxis
        xgp_Quaternion(xgp_Vec^ theAxis, Standard_Real^ theAngle);

        //! Creates quaternion from rotation matrix 3*3
        //! (which should be orthonormal skew-symmetric matrix)
        xgp_Quaternion(xgp_Mat^ theMat);

        //释放
        ~xgp_Quaternion();
        //释放
        !xgp_Quaternion();
        //! Return the gp_Quaternion
        gp_Quaternion GetQuaternion();

        //! Simple equal test without precision
        Standard_Boolean^ IsEqual(xgp_Quaternion^ theOther);

        //! Sets quaternion to shortest-arc rotation producing
        //! vector theVecTo from vector theVecFrom.
        //! If vectors theVecFrom and theVecTo are opposite then rotation
        //! axis is computed as theVecFrom ^ (1,0,0) or theVecFrom ^ (0,0,1).
        void SetRotation(xgp_Vec^ theVecFrom, xgp_Vec^ theVecTo);

        //! Sets quaternion to shortest-arc rotation producing
        //! vector theVecTo from vector theVecFrom.
        //! If vectors theVecFrom and theVecTo are opposite then rotation
        //! axis is computed as theVecFrom ^ theHelpCrossVec.
        void SetRotation(xgp_Vec^ theVecFrom, xgp_Vec^ theVecTo, xgp_Vec^ theHelpCrossVec);

        //! Create a unit quaternion from Axis+Angle representation
        void SetVectorAndAngle(xgp_Vec^ theAxis, Standard_Real^ theAngle);

        //! Convert a quaternion to Axis+Angle representation,
        //! preserve the axis direction and angle from -PI to +PI
        void GetVectorAndAngle(xgp_Vec^ theAxis, Standard_Real theAngle);

        //! Create a unit quaternion by rotation matrix
        //! matrix must contain only rotation (not scale or shear)
        //!
        //! For numerical stability we find first the greatest component of quaternion
        //! and than search others from this one
        void SetMatrix(xgp_Mat^ theMat);

        //! Returns rotation operation as 3*3 matrix
        xgp_Mat^ GetMatrix();

        //! Create a unit quaternion representing rotation defined
        //! by generalized Euler angles
        void SetEulerAngles(int^ EulerSequence, Standard_Real^ theAlpha, Standard_Real^ theBeta, Standard_Real^ theGamma);

        //! Returns Euler angles describing current rotation
        void GetEulerAngles(int^ EulerSequence, Standard_Real theAlpha, Standard_Real theBeta, Standard_Real theGamma);

        void Set(Standard_Real^ x, Standard_Real^ y, Standard_Real^ z, Standard_Real^ w);

        void Set(xgp_Quaternion^ theQuaternion);

        Standard_Real^ X();

        Standard_Real^ Y();

        Standard_Real^ Z();

        Standard_Real^ W();

        //! Make identity quaternion (zero-rotation)
        void SetIdent();

        //! Reverse direction of rotation (conjugate quaternion)
        void Reverse();

        //! Return rotation with reversed direction (conjugated quaternion)
        xgp_Quaternion^ Reversed();

        //! Inverts quaternion (both rotation direction and norm)
        void Invert();

        //! Return inversed quaternion q^-1
        xgp_Quaternion^ Inverted();

        //! Returns square norm of quaternion
        Standard_Real^ SquareNorm();

        //! Returns norm of quaternion
        Standard_Real^ Norm();

        //! Scale all components by quaternion by theScale; note that
        //! rotation is not changed by this operation (except 0-scaling)
        void Scale(Standard_Real^ theScale);
        void operator *= (Standard_Real^ theScale) {
            Scale(theScale);
        }

        //! Returns scaled quaternion
        xgp_Quaternion^ Scaled(Standard_Real^ theScale);
        xgp_Quaternion^ operator * (Standard_Real^ theScale) {
            return Scaled(theScale);
        }

        //! Stabilize quaternion length within 1 - 1/4.
        //! This operation is a lot faster than normalization
        //! and preserve length goes to 0 or infinity
        void StabilizeLength();

        //! Scale quaternion that its norm goes to 1.
        //! The appearing of 0 magnitude or near is a error,
        //! so we can be sure that can divide by magnitude
        void Normalize();

        //! Returns quaternion scaled so that its norm goes to 1.
        xgp_Quaternion^ Normalized();

        //! Returns quaternion with all components negated.
        //! Note that this operation does not affect neither
        //! rotation operator defined by quaternion nor its norm.
        xgp_Quaternion^ Negated();
        xgp_Quaternion^ operator -() {
            return Negated();
        }

        //! Makes sum of quaternion components; result is "rotations mix"
        xgp_Quaternion^ Added(xgp_Quaternion^ theOther);
        xgp_Quaternion^ operator + (xgp_Quaternion^ theOther) {
            return Added(theOther);
        }

        //! Makes difference of quaternion components; result is "rotations mix"
        xgp_Quaternion^ Subtracted(xgp_Quaternion^ theOther);
        xgp_Quaternion^ operator - (xgp_Quaternion^ theOther) {
            return Subtracted(theOther);
        }

        //! Multiply function - work the same as Matrices multiplying.
        //! qq' = (cross(v,v') + wv' + w'v, ww' - dot(v,v'))
        //! Result is rotation combination: q' than q (here q=this, q'=theQ).
        //! Notices than:
        //! qq' != q'q;
        //! qq^-1 = q;
        xgp_Quaternion^ Multiplied(xgp_Quaternion^ theOther);
        xgp_Quaternion^ operator * (xgp_Quaternion^ theOther) {
            return Multiplied(theOther);
        }

        //! Adds componnets of other quaternion; result is "rotations mix"
        void Add(xgp_Quaternion^ theOther);
        void operator += (xgp_Quaternion^ theOther) {
            Add(theOther);
        }

        //! Subtracts componnets of other quaternion; result is "rotations mix"
        void Subtract(xgp_Quaternion^ theOther);
        void operator -= (xgp_Quaternion^ theOther) {
            Subtract(theOther);
        }

        //! Adds rotation by multiplication
        void Multiply(xgp_Quaternion^ theOther);
        void operator *= (xgp_Quaternion^ theOther) {
            Multiply(theOther);
        }

        //! Computes inner product / scalar product / Dot
        Standard_Real^ Dot(xgp_Quaternion^ theOther);

        //! Return rotation angle from -PI to PI
        Standard_Real^ GetRotationAngle();

        //! Rotates vector by quaternion as rotation operator
        xgp_Vec^ Multiply(xgp_Vec^ theVec);
        xgp_Vec^ operator * (xgp_Vec^ theVec) {
            return Multiply(theVec);
        }
        /// <summary>
                /// 本地句柄
                /// </summary>
        property gp_Quaternion* Handle
        {
            gp_Quaternion* get() {
                return NativeHandle;
            }
        }

    private:
        gp_Quaternion* NativeHandle;
    };
};
