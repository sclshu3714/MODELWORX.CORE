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
#ifndef _xgp_Mat2d_HeaderFile
#define _xgp_Mat2d_HeaderFile
#pragma once
#include <gp_Mat2d.hxx>
#include "xgp_Trsf2d.h"
#include "xgp_GTrsf2d.h"
#include "xgp_XY.h"


//! Describes a two column, two row matrix. This sort of
//! object is used in various vectorial or matrix computations.
namespace TKMath
{
    ref class xgp_Trsf2d;
    ref class xgp_GTrsf2d;
    ref class xgp_XY;
    public ref class xgp_Mat2d
    {
    public:

        //! Creates  a matrix with null coefficients.
        xgp_Mat2d(void);

        /// <summary>
        /// 指针映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Mat2d(gp_Mat2d* pos);
        /// <summary>
        ///  映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Mat2d(gp_Mat2d pos);

        //! Col1, Col2 are the 2 columns of the matrix.
        xgp_Mat2d(xgp_XY^ Col1, xgp_XY^ Col2);

        //释放
        ~xgp_Mat2d();
        //释放
        !xgp_Mat2d();


        //! Assigns the two coordinates of Value to the column of range
        //! Col of this matrix
        //! Raises OutOfRange if Col < 1 or Col > 2.
        void SetCol(Standard_Integer^ Col, xgp_XY^ Value);

        //! Assigns the number pairs Col1, Col2 to the two columns of   this matrix
        void SetCols(xgp_XY^ Col1, xgp_XY^ Col2);


        //! Modifies the main diagonal of the matrix.
        //! <me>.Value (1, 1) = X1
        //! <me>.Value (2, 2) = X2
        //! The other coefficients of the matrix are not modified.
        void SetDiagonal(Standard_Real^ X1, Standard_Real^ X2);

        //! Modifies this matrix, so that it represents the Identity matrix.
        void SetIdentity();


        //! Modifies this matrix, so that it representso a rotation. Ang is the angular
        //! value in radian of the rotation.
        void SetRotation(Standard_Real^ Ang);

        //! Assigns the two coordinates of Value to the row of index Row of this matrix.
        //! Raises OutOfRange if Row < 1 or Row > 2.
        void SetRow(Standard_Integer^ Row, xgp_XY^ Value);

        //! Assigns the number pairs Row1, Row2 to the two rows of this matrix.
        void SetRows(xgp_XY^ Row1, xgp_XY^ Row2);

        //! Modifies the matrix such that it
        //! represents a scaling transformation, where S is the scale   factor :
        //! | S    0.0 |
        //! <me> =  | 0.0   S  |
        void SetScale(Standard_Real^ S);

        //! Assigns <Value> to the coefficient of row Row, column Col of this matrix.
        //! Raises OutOfRange if Row < 1 or Row > 2 or Col < 1 or Col > 2
        void SetValue(Standard_Integer^ Row, Standard_Integer^ Col, Standard_Real^ Value);

        //! Returns the gp_Mat2d
        gp_Mat2d GetMat2d();

        //! Returns the column of Col index.
        //! Raises OutOfRange if Col < 1 or Col > 2
        xgp_XY^ Column(Standard_Integer^ Col);

        //! Computes the determinant of the matrix.
        Standard_Real^ Determinant();

        //! Returns the main diagonal of the matrix.
        xgp_XY^ Diagonal();

        //! Returns the row of index Row.
        //! Raised if Row < 1 or Row > 2
        xgp_XY^ Row(Standard_Integer^ Row);

        //! Returns the coefficient of range (Row, Col)
        //! Raises OutOfRange
        //! if Row < 1 or Row > 2 or Col < 1 or Col > 2
        Standard_Real^ Value(Standard_Integer^ Row, Standard_Integer^ Col);
        /*Standard_Real^ operator() (Standard_Integer^ Row, Standard_Integer^ Col) {
            return Value(Row, Col);
        }*/

        //! Returns the coefficient of range (Row, Col)
        //! Raises OutOfRange
        //! if Row < 1 or Row > 2 or Col < 1 or Col > 2
        Standard_Real^ ChangeValue(Standard_Integer^ Row, Standard_Integer^ Col);
        Standard_Real^ operator() (Standard_Integer^ Row, Standard_Integer^ Col) {
            return ChangeValue(Row, Col);
        }


        //! Returns true if this matrix is singular (and therefore, cannot be inverted).
        //! The Gauss LU decomposition is used to invert the matrix
        //! so the matrix is considered as singular if the largest
        //! pivot found is lower or equal to Resolution from gp.
        Standard_Boolean^ IsSingular();

        void Add(xgp_Mat2d^ Other);
        void operator += (xgp_Mat2d^ Other) {
            Add(Other);
        }


        //! Computes the sum of this matrix and the matrix
        //! Other.for each coefficient of the matrix :
        //! <me>.Coef(i,j) + <Other>.Coef(i,j)
        //! Note:
        //! -   operator += assigns the result to this matrix, while
        //! -   operator + creates a new one.
        xgp_Mat2d^ Added(xgp_Mat2d^ Other);
        xgp_Mat2d^ operator + (xgp_Mat2d^ Other) {
            return Added(Other);
        }

        void Divide(Standard_Real^ Scalar);
        void operator /= (Standard_Real^ Scalar) {
            Divide(Scalar);
        }


        //! Divides all the coefficients of the matrix by a scalar.
        xgp_Mat2d^ Divided(Standard_Real^ Scalar);
        xgp_Mat2d^ operator / (Standard_Real^ Scalar) {
            return Divided(Scalar);
        }

        void Invert();


        //! Inverses the matrix and raises exception if the matrix
        //! is singular.
        xgp_Mat2d^ Inverted();

        xgp_Mat2d^ Multiplied(xgp_Mat2d^ Other);
        xgp_Mat2d^ operator * (xgp_Mat2d^ Other) {
            return Multiplied(Other);
        }


        //! Computes the product of two matrices <me> * <Other>
        void Multiply(xgp_Mat2d^ Other);

        //! Modifies this matrix by premultiplying it by the matrix Other
        //! <me> = Other * <me>.
        void PreMultiply(xgp_Mat2d^ Other);

        xgp_Mat2d^ Multiplied(Standard_Real^ Scalar);
        xgp_Mat2d^ operator * (Standard_Real^ Scalar) {
            return Multiplied(Scalar);
        }


        //! Multiplies all the coefficients of the matrix by a scalar.
        void Multiply(Standard_Real^ Scalar);
        void operator *= (Standard_Real^ Scalar) {
            Multiply(Scalar);
        }

        void Power(Standard_Integer^ N);


        //! computes <me> = <me> * <me> * .......* <me>, N time.
        //! if N = 0 <me> = Identity
        //! if N < 0 <me> = <me>.Invert() *...........* <me>.Invert().
        //! If N < 0 an exception can be raised if the matrix is not
        //! inversible
        xgp_Mat2d^ Powered(Standard_Integer^ N);

        void Subtract(xgp_Mat2d^ Other);
        void operator -= (xgp_Mat2d^ Other) {
            Subtract(Other);
        }


        //! Computes for each coefficient of the matrix :
        //! <me>.Coef(i,j) - <Other>.Coef(i,j)
        xgp_Mat2d^ Subtracted(xgp_Mat2d^ Other);
        xgp_Mat2d^ operator - (xgp_Mat2d^ Other) {
            return Subtracted(Other);
        }

        void Transpose();


        //! Transposes the matrix. A(j, i) -> A (i, j)
        xgp_Mat2d^ Transposed();

        /// <summary>
            /// 本地句柄
            /// </summary>
        property gp_Mat2d* Handle
        {
            gp_Mat2d* get() {
                return NativeHandle;
            }
        }

    private:
        gp_Mat2d* NativeHandle;
    };
}
#endif // _xgp_Mat2d_HeaderFile