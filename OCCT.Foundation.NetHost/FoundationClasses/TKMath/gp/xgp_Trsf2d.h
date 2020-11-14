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
//! Defines a non-persistent transformation in 2D space.
//! The following transformations are implemented :
//! . Translation, Rotation, Scale
//! . Symmetry with respect to a point and a line.
//! Complex transformations can be obtained by combining the
//! previous elementary transformations using the method Multiply.
//! The transformations can be represented as follow :
//!
//! V1   V2   T       XY        XY
//! | a11  a12  a13 |   | x |     | x'|
//! | a21  a22  a23 |   | y |     | y'|
//! |  0    0    1  |   | 1 |     | 1 |
//!
//! where {V1, V2} defines the vectorial part of the transformation
//! and T defines the translation part of the transformation.
//! This transformation never change the nature of the objects.

#pragma once
#include <gp_Trsf2d.hxx>
#include "xgp_Trsf.h"
#include "xgp_Vec2d.h"
#include "xgp_Pnt2d.h"
#include "xgp_Mat2d.h"
#include "xgp_XY.h"
#include "xgp_GTrsf2d.h"
#include "xgp_Ax2d.h"


namespace TKMath
{
    ref class xgp_Trsf;
    ref class xgp_Vec2d;
    ref class xgp_Pnt2d;
    ref class xgp_Mat2d;
    ref class xgp_XY;
    ref class xgp_GTrsf2d;
    ref class xgp_Ax2d;
    public ref class xgp_Trsf2d
    {
    public:
        //! Returns identity transformation.
        xgp_Trsf2d(void);

        /// <summary>
        /// 指针映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Trsf2d(gp_Trsf2d* pos);
        /// <summary>
        ///  映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Trsf2d(gp_Trsf2d pos);

        //! Creates a 2d transformation in the XY plane from a
        //! 3d transformation .
        xgp_Trsf2d(xgp_Trsf^ T);

        //释放
        ~xgp_Trsf2d();
        //释放
        !xgp_Trsf2d();


        //! Changes the transformation into a symmetrical transformation.
        //! P is the center of the symmetry.
        void SetMirror(xgp_Pnt2d^ P);


        //! Changes the transformation into a symmetrical transformation.
        //! A is the center of the axial symmetry.
        void SetMirror(xgp_Ax2d^ A);


        //! Changes the transformation into a rotation.
        //! P is the rotation's center and Ang is the angular value of the
        //! rotation in radian.
        void SetRotation(xgp_Pnt2d^ P, Standard_Real^ Ang);


        //! Changes the transformation into a scale.
        //! P is the center of the scale and S is the scaling value.
        void SetScale(xgp_Pnt2d^ P, Standard_Real^ S);


        //! Changes a transformation allowing passage from the coordinate
        //! system "FromSystem1" to the coordinate system "ToSystem2".
        void SetTransformation(xgp_Ax2d^ FromSystem1, xgp_Ax2d^ ToSystem2);


        //! Changes the transformation allowing passage from the basic
        //! coordinate system
        //! {P(0.,0.,0.), VX (1.,0.,0.), VY (0.,1.,0.)}
        //! to the local coordinate system defined with the Ax2d ToSystem.
        void SetTransformation(xgp_Ax2d^ ToSystem);


        //! Changes the transformation into a translation.
        //! V is the vector of the translation.
        void SetTranslation(xgp_Vec2d^ V);


        //! Makes the transformation into a translation from
        //! the point P1 to the point P2.
        void SetTranslation(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2);

        //! Replaces the translation vector with V.
        void SetTranslationPart(xgp_Vec2d^ V);

        //! Modifies the scale factor.
        void SetScaleFactor(Standard_Real^ S);

        //! Returns the gp_Trsf2d
        gp_Trsf2d GetTrsf2d();

        //! Returns true if the determinant of the vectorial part of
        //! this transformation is negative..
        Standard_Boolean^ IsNegative();


        //! Returns the nature of the transformation. It can be  an
        //! identity transformation, a rotation, a translation, a mirror
        //! (relative to a point or an axis), a scaling transformation,
        //! or a compound transformation.
        //! gp_TrsfForm
        int^ Form();

        //! Returns the scale factor.
        Standard_Real^ ScaleFactor();


        //! Returns the translation part of the transformation's matrix
        xgp_XY^ TranslationPart();


        //! Returns the vectorial part of the transformation. It is a
        //! 2*2 matrix which includes the scale factor.
        xgp_Mat2d^ VectorialPart();


        //! Returns the homogeneous vectorial part of the transformation.
        //! It is a 2*2 matrix which doesn't include the scale factor.
        //! The coefficients of this matrix must be multiplied by the
        //! scale factor to obtain the coefficients of the transformation.
        xgp_Mat2d^ HVectorialPart();


        //! Returns the angle corresponding to the rotational component
        //! of the transformation matrix (operation opposite to SetRotation()).
        Standard_Real^ RotationPart();


        //! Returns the coefficients of the transformation's matrix.
        //! It is a 2 rows * 3 columns matrix.
        //! Raises OutOfRange if Row < 1 or Row > 2 or Col < 1 or Col > 3
        Standard_Real^ Value(Standard_Integer^ Row, Standard_Integer^ Col);

        void Invert();


        //! Computes the reverse transformation.
        //! Raises an exception if the matrix of the transformation
        //! is not inversible, it means that the scale factor is lower
        //! or equal to Resolution from package gp.
        xgp_Trsf2d^ Inverted();

        xgp_Trsf2d^ Multiplied(xgp_Trsf2d^ T);
        xgp_Trsf2d^ operator * (xgp_Trsf2d^ T) {
            return Multiplied(T);
        }


        //! Computes the transformation composed from <me> and T.
        //! <me> = <me> * T
        void Multiply(xgp_Trsf2d^ T);
        void operator *= (xgp_Trsf2d^ T) {
            Multiply(T);
        }


        //! Computes the transformation composed from <me> and T.
        //! <me> = T * <me>
        void PreMultiply(xgp_Trsf2d^ T);

        void Power(Standard_Integer^ N);


        //! Computes the following composition of transformations
        //! <me> * <me> * .......* <me>,  N time.
        //! if N = 0 <me> = Identity
        //! if N < 0 <me> = <me>.Inverse() *...........* <me>.Inverse().
        //!
        //! Raises if N < 0 and if the matrix of the transformation not
        //! inversible.
        xgp_Trsf2d^ Powered(Standard_Integer^ N);

        void Transforms(Standard_Real^ X, Standard_Real^ Y);

        //! Transforms  a doublet XY with a Trsf2d
        void Transforms(xgp_XY^ Coord);

        //! Sets the coefficients  of the transformation. The
        //! transformation  of the  point  x,y is  the point
        //! x',y' with :
        //!
        //! x' = a11 x + a12 y + a13
        //! y' = a21 x + a22 y + a23
        //!
        //! The method Value(i,j) will return aij.
        //! Raises ConstructionError if the determinant of the aij is null.
        //! If the matrix as not a uniform scale it will be orthogonalized before future using.
        void SetValues(Standard_Real^ a11, Standard_Real^ a12, Standard_Real^ a13, Standard_Real^ a21, Standard_Real^ a22, Standard_Real^ a23);

        /// <summary>
        /// 本地句柄
        /// </summary>
        property gp_Trsf2d* Handle
        {
            gp_Trsf2d* get() {
                return NativeHandle;
            }
        }

    private:
        gp_Trsf2d* NativeHandle;


    };
};
