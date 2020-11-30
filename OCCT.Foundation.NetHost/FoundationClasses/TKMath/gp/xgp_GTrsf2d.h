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
//! Defines a non persistent transformation in 2D space.
//! This transformation is a general transformation.
//! It can be a Trsf2d from package gp, an affinity, or you can
//! define your own transformation giving the corresponding
//! matrix of transformation.
//!
//! With a GTrsf2d you can transform only a doublet of coordinates
//! XY. It is not possible to transform other geometric objects
//! because these transformations can change the nature of non-
//! elementary geometric objects.
//! A GTrsf2d is represented with a 2 rows * 3 columns matrix :
//!
//! V1   V2   T        XY         XY
//! | a11  a12  a14 |   | x |      | x'|
//! | a21  a22  a24 |   | y |      | y'|
//! |  0    0    1  |   | 1 |      | 1 |
//!
//! where {V1, V2} defines the vectorial part of the
//! transformation and T defines the translation part of
//! the transformation.
//! Warning
//! A GTrsf2d transformation is only applicable on
//! coordinates. Be careful if you apply such a
//! transformation to all the points of a geometric object,
//! as this can change the nature of the object and thus
//! render it incoherent!
//! Typically, a circle is transformed into an ellipse by an
//! affinity transformation. To avoid modifying the nature of
//! an object, use a xgp_Trsf2d transformation instead, as
//! objects of thisnamespace TKMath  {  public ref class respect the nature of geometric objects.


#ifndef _xgp_GTrsf2d_HeaderFile
#define _xgp_GTrsf2d_HeaderFile
#pragma once
#include <gp_GTrsf2d.hxx>
#include "xgp_Trsf2d.h"
#include "xgp_Mat2d.h"
#include "xgp_XY.h"
#include "xgp_Ax2d.h"

namespace TKMath
{
    ref class xgp_Trsf2d;
    ref class xgp_XY;
    ref class xgp_Mat2d;
    ref class xgp_Ax2d;
    public ref class xgp_GTrsf2d
    {
    public:

        //! returns identity transformation.
        xgp_GTrsf2d(void);

        /// <summary>
        /// 指针映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_GTrsf2d(gp_GTrsf2d* pos);
        /// <summary>
        ///  映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_GTrsf2d(gp_GTrsf2d pos);

        //! Converts the xgp_Trsf2d transformation T into a
        //! general transformation.
        xgp_GTrsf2d(xgp_Trsf2d^ T);

        //! Creates   a transformation based on the matrix M and the
        //! vector V where M defines the vectorial part of the
        //! transformation, and V the translation part.
        xgp_GTrsf2d(xgp_Mat2d^ M, xgp_XY^ V);



        //释放
        ~xgp_GTrsf2d();
        //释放
        !xgp_GTrsf2d();

        //! gp_GTrsf2d
        gp_GTrsf2d GetGTrsf2d();

        //! Changes this transformation into an affinity of ratio Ratio
        //! with respect to the axis A.
        //! Note: An affinity is a point-by-point transformation that
        //! transforms any point P into a point P' such that if H is
        //! the orthogonal projection of P on the axis A, the vectors
        //! HP and HP' satisfy: HP' = Ratio * HP.
        void SetAffinity(xgp_Ax2d^ A, Standard_Real Ratio);


        //! Replaces   the coefficient (Row, Col) of the matrix representing
        //! this transformation by Value,
        //! Raises OutOfRange if Row < 1 or Row > 2 or Col < 1 or Col > 3
        void SetValue(Standard_Integer Row, Standard_Integer Col, Standard_Real Value);

        //! Replacesthe translation part of this
        //! transformation by the coordinates of the number pair Coord.
        void SetTranslationPart(xgp_XY^ Coord);


        //! Assigns the vectorial and translation parts of T to this transformation.
        void SetTrsf2d(xgp_Trsf2d^ T);


        //! Replaces the vectorial part of this transformation by Matrix.
        void SetVectorialPart(xgp_Mat2d^ Matrix);


        //! Returns true if the determinant of the vectorial part of
        //! this transformation is negative.
        Standard_Boolean IsNegative();

        //! Returns true if this transformation is singular (and
        //! therefore, cannot be inverted).
        //! Note: The Gauss LU decomposition is used to invert the
        //! transformation matrix. Consequently, the transformation
        //! is considered as singular if the largest pivot found is less
        //! than or equal to gp::Resolution().
        //! Warning
        //! If this transformation is singular, it cannot be inverted.
        Standard_Boolean IsSingular();


        //! Returns the nature of the transformation.  It can be
        //! an identity transformation, a rotation, a translation, a mirror
        //! transformation (relative to a point or axis), a scaling
        //! transformation, a compound transformation or some
        //! other type of transformation.
        //! gp_TrsfForm
        int^ Form();

        //! Returns the translation part of the GTrsf2d.
        xgp_XY^ TranslationPart();


        //! Computes the vectorial part of the GTrsf2d. The returned
        //! Matrix is a 2*2 matrix.
        xgp_Mat2d^ VectorialPart();


        //! Returns the coefficients of the global matrix of transformation.
        //! Raised OutOfRange if Row < 1 or Row > 2 or Col < 1 or Col > 3
        Standard_Real Value(Standard_Integer Row, Standard_Integer Col);
        Standard_Real operator() (Standard_Integer Row, Standard_Integer Col) {
            return Value(Row, Col);
        }

        void Invert();


        //! Computes the reverse transformation.
        //! Raised an exception if the matrix of the transformation
        //! is not inversible.
        xgp_GTrsf2d^ Inverted();


        //! Computes the transformation composed with T and <me>.
        //! In a C++ implementation you can also write Tcomposed = <me> * T.
        //! Example :
        //! GTrsf2d T1, T2, Tcomp; ...............
        //! //composition :
        //! Tcomp = T2.Multiplied(T1);         // or   (Tcomp = T2 * T1)
        //! // transformation of a point
        //! XY P(10.,3.);
        //! XY P1(P);
        //! Tcomp.Transforms(P1);               //using Tcomp
        //! XY P2(P);
        //! T1.Transforms(P2);                  //using T1 then T2
        //! T2.Transforms(P2);                  // P1 = P2 !!!
        xgp_GTrsf2d^ Multiplied(xgp_GTrsf2d^ T);
        xgp_GTrsf2d^ operator * (xgp_GTrsf2d^ T) {
            return Multiplied(T);
        }

        void Multiply(xgp_GTrsf2d^ T);
        void operator *= (xgp_GTrsf2d^ T) {
            Multiply(T);
        }


        //! Computes the product of the transformation T and this
        //! transformation, and assigns the result to this transformation:
        //! this = T * this
        void PreMultiply(xgp_GTrsf2d^ T);

        void Power(Standard_Integer N);


        //! Computes the following composition of transformations
        //! <me> * <me> * .......* <me>, N time.
        //! if N = 0 <me> = Identity
        //! if N < 0 <me> = <me>.Inverse() *...........* <me>.Inverse().
        //!
        //! Raises an exception if N < 0 and if the matrix of the
        //! transformation is not inversible.
        xgp_GTrsf2d^ Powered(Standard_Integer N);

        void Transforms(xgp_XY^ Coord);

        xgp_XY^ Transformed(xgp_XY^ Coord);


        //! Applies this transformation to the coordinates:
        //! -   of the number pair Coord, or
        //! -   X and Y.
        //!
        //! Note:
        //! -   Transforms modifies X, Y, or the coordinate pair Coord, while
        //! -   Transformed creates a new coordinate pair.
        void Transforms(Standard_Real X, Standard_Real Y);


        //! Converts this transformation into a xgp_Trsf2d transformation.
        //! Exceptions
        //! Standard_ConstructionError if this transformation
        //! cannot be converted, i.e. if its form is gp_Other.
        xgp_Trsf2d^ Trsf2d();
        /// <summary>
        /// 本地句柄
        /// </summary>
        property gp_GTrsf2d* Handle
        {
            gp_GTrsf2d* get() {
                return NativeHandle;
            }
        }

    private:
        gp_GTrsf2d* NativeHandle;
    };
}
#endif // _xgp_GTrsf2d_HeaderFile