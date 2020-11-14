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
#pragma once
#include <gp_Mat.hxx>
#include "xgp_XYZ.h"

namespace TKMath
{
    ref class xgp_XYZ;
    //! Defines a 3D cartesian point.
    public ref class xgp_Mat
    {
    public:
        //! creates  a matrix with null coefficients.
        xgp_Mat(void);

        /// <summary>
        /// 指针映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Mat(gp_Mat* pos);
        /// <summary>
        ///  映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Mat(gp_Mat pos);

        //! Creates a matrix.
        xgp_Mat(Standard_Real^ a11, Standard_Real^ a12, Standard_Real^ a13, Standard_Real^ a21, Standard_Real^ a22, Standard_Real^ a23, Standard_Real^ a31, Standard_Real^ a32, Standard_Real^ a33);

        //! Creates a matrix.
        //! Col1, Col2, Col3 are the 3 columns of the matrix.
         xgp_Mat(xgp_XYZ^ Col1, xgp_XYZ^ Col2, xgp_XYZ^ Col3);


         //释放
         ~xgp_Mat();
         //释放
         !xgp_Mat();

        //! Assigns the three coordinates of Value to the column of index
        //! Col of this matrix.
        //! Raises OutOfRange if Col < 1 or Col > 3.
         void SetCol(Standard_Integer^ Col, xgp_XYZ^ Value);

        //! Assigns the number triples Col1, Col2, Col3 to the three
        //! columns of this matrix.
         void SetCols(xgp_XYZ^ Col1, xgp_XYZ^ Col2, xgp_XYZ^ Col3);


        //! Modifies the matrix  M so that applying it to any number
        //! triple (X, Y, Z) produces the same result as the cross
        //! product of Ref and the number triple (X, Y, Z):
        //! i.e.: M * {X,Y,Z}t = Ref.Cross({X, Y ,Z})
        //! this matrix is anti symmetric. To apply this matrix to the
        //! triplet  {XYZ} is the same as to do the cross product between the
        //! triplet Ref and the triplet {XYZ}.
        //! Note: this matrix is anti-symmetric.
         void SetCross(xgp_XYZ^ Ref);


        //! Modifies the main diagonal of the matrix.
        //! <me>.Value (1, 1) = X1
        //! <me>.Value (2, 2) = X2
        //! <me>.Value (3, 3) = X3
        //! The other coefficients of the matrix are not modified.
        void SetDiagonal(Standard_Real^ X1, Standard_Real^ X2, Standard_Real^ X3);


        //! Modifies this matrix so that applying it to any number
        //! triple (X, Y, Z) produces the same result as the scalar
        //! product of Ref and the number triple (X, Y, Z):
        //! this * (X,Y,Z) = Ref.(X,Y,Z)
        //! Note: this matrix is symmetric.
         void SetDot(xgp_XYZ^ Ref);

        //! Modifies this matrix so that it represents the Identity matrix.
        void SetIdentity();


        //! Modifies this matrix so that it represents a rotation. Ang is the angular value in
        //! radians and the XYZ axis gives the direction of the
        //! rotation.
        //! Raises ConstructionError if XYZ.Modulus() <= Resolution()
         void SetRotation(xgp_XYZ^ Axis, Standard_Real^ Ang);

        //! Assigns the three coordinates of Value to the row of index
        //! Row of this matrix. Raises OutOfRange if Row < 1 or Row > 3.
         void SetRow(Standard_Integer^ Row, xgp_XYZ^ Value);

        //! Assigns the number triples Row1, Row2, Row3 to the three
        //! rows of this matrix.
         void SetRows(xgp_XYZ^ Row1, xgp_XYZ^ Row2, xgp_XYZ^ Row3);


        //! Modifies the the matrix so that it represents
        //! a scaling transformation, where S is the scale factor. :
        //! | S    0.0  0.0 |
        //! <me> =  | 0.0   S   0.0 |
        //! | 0.0  0.0   S  |
        void SetScale(Standard_Real^ S);

        //! Assigns <Value> to the coefficient of row Row, column Col of   this matrix.
        //! Raises OutOfRange if Row < 1 or Row > 3 or Col < 1 or Col > 3
        void SetValue(Standard_Integer^ Row, Standard_Integer^ Col, Standard_Real^ Value);

        //! Returns the gp_Mat
        gp_Mat GetMat();

        //! Returns the column of Col index.
        //! Raises OutOfRange if Col < 1 or Col > 3
         xgp_XYZ^ Column(Standard_Integer^ Col);

        //! Computes the determinant of the matrix.
        Standard_Real^ Determinant();

        //! Returns the main diagonal of the matrix.
         xgp_XYZ^ Diagonal();

        //! returns the row of Row index.
        //! Raises OutOfRange if Row < 1 or Row > 3
         xgp_XYZ^ Row(Standard_Integer^ Row);

        //! Returns the coefficient of range (Row, Col)
        //! Raises OutOfRange if Row < 1 or Row > 3 or Col < 1 or Col > 3
        Standard_Real^ Value(Standard_Integer^ Row, Standard_Integer^ Col);
        /*Standard_Real^ operator() (Standard_Integer^ Row, Standard_Integer^ Col) {
            return Value(Row, Col);
        }*/

        //! Returns the coefficient of range (Row, Col)
        //! Raises OutOfRange if Row < 1 or Row > 3 or Col < 1 or Col > 3
        Standard_Real^ ChangeValue(Standard_Integer^ Row, Standard_Integer^ Col);
        Standard_Real^ operator() (Standard_Integer^ Row, Standard_Integer^ Col) {
            return ChangeValue(Row, Col);
        }


        //! The Gauss LU decomposition is used to invert the matrix
        //! (see Math package) so the matrix is considered as singular if
        //! the largest pivot found is lower or equal to Resolution from gp.
        Standard_Boolean^ IsSingular();

        void Add(xgp_Mat^ Other);
        void operator += (xgp_Mat^ Other) {
            Add(Other);
        }

        //! Computes the sum of this matrix and
        //! the matrix Other for each coefficient of the matrix :
        //! <me>.Coef(i,j) + <Other>.Coef(i,j)
         xgp_Mat^ Added(xgp_Mat^ Other);
         xgp_Mat^ operator + (xgp_Mat^ Other) {
            return Added(Other);
        }

        void Divide(Standard_Real^ Scalar);
        void operator /= (Standard_Real^ Scalar) {
            Divide(Scalar);
        }

        //! Divides all the coefficients of the matrix by Scalar
         xgp_Mat^ Divided(Standard_Real^ Scalar);
         xgp_Mat^ operator / (Standard_Real^ Scalar) {
            return Divided(Scalar);
        }

         void Invert();


        //! Inverses the matrix and raises if the matrix is singular.
        //! -   Invert assigns the result to this matrix, while
        //! -   Inverted creates a new one.
        //! Warning
        //! The Gauss LU decomposition is used to invert the matrix.
        //! Consequently, the matrix is considered as singular if the
        //! largest pivot found is less than or equal to gp::Resolution().
        //! Exceptions
        //! Standard_ConstructionError if this matrix is singular,
        //! and therefore cannot be inverted.
          xgp_Mat^ Inverted();


        //! Computes  the product of two matrices <me> * <Other>
         xgp_Mat^ Multiplied(xgp_Mat^ Other);
         xgp_Mat^ operator * (xgp_Mat^ Other) {
            return Multiplied(Other);
        }

        //! Computes the product of two matrices <me> = <Other> * <me>.
        void Multiply(xgp_Mat^ Other);
        void operator *= (xgp_Mat^ Other) {
            Multiply(Other);
        }

        void PreMultiply(xgp_Mat^ Other);

         xgp_Mat^ Multiplied(Standard_Real^ Scalar);
         xgp_Mat^ operator * (Standard_Real^ Scalar) {
            return Multiplied(Scalar);
        }


        //! Multiplies all the coefficients of the matrix by Scalar
        void Multiply(Standard_Real^ Scalar);
        void operator *= (Standard_Real^ Scalar) {
            Multiply(Scalar);
        }

         void Power(Standard_Integer^ N);


        //! Computes <me> = <me> * <me> * .......* <me>,   N time.
        //! if N = 0 <me> = Identity
        //! if N < 0 <me> = <me>.Invert() *...........* <me>.Invert().
        //! If N < 0 an exception will be raised if the matrix is not
        //! inversible
         xgp_Mat^ Powered(Standard_Integer^ N);

        void Subtract(xgp_Mat^ Other);
        void operator -= (xgp_Mat^ Other) {
            Subtract(Other);
        }


        //! cOmputes for each coefficient of the matrix :
        //! <me>.Coef(i,j) - <Other>.Coef(i,j)
         xgp_Mat^ Subtracted(xgp_Mat^ Other);
         xgp_Mat^ operator - (xgp_Mat^ Other) {
            return Subtracted(Other);
        }

        void Transpose();


        //! Transposes the matrix. A(j, i) -> A (i, j)
         xgp_Mat^ Transposed();

        //! Dumps the content of me into the stream
         void DumpJson(Standard_OStream theOStream, Standard_Integer theDepth);

        /// <summary>
        /// 本地句柄
        /// </summary>
        property gp_Mat* Handle
        {
            gp_Mat* get() {
                return NativeHandle;
            }
        }

        private:
            gp_Mat* NativeHandle;
    };
}
