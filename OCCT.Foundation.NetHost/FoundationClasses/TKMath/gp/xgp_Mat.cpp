#include <xgp_Mat.h>

namespace TKMath
{
    //! creates  a matrix with null coefficients.
    xgp_Mat::xgp_Mat(void) {
        NativeHandle = new gp_Mat();
    };

    /// <summary>
    /// 指针映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Mat::xgp_Mat(gp_Mat* pos) {
        NativeHandle = new gp_Mat(*pos);
    };
    /// <summary>
    ///  映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Mat::xgp_Mat(gp_Mat pos) {
        NativeHandle = new gp_Mat(pos);
    };

    //! Creates a matrix.
    xgp_Mat::xgp_Mat(Standard_Real a11, Standard_Real a12, Standard_Real a13, Standard_Real a21, Standard_Real a22, Standard_Real a23, Standard_Real a31, Standard_Real a32, Standard_Real a33) {
        NativeHandle = new gp_Mat(a11, a12, a13, a21, a22, a23, a31, a32, a33);
    };

    //! Creates a matrix.
    //! Col1, Col2, Col3 are the 3 columns of the matrix.
    xgp_Mat::xgp_Mat(xgp_XYZ^ Col1, xgp_XYZ^ Col2, xgp_XYZ^ Col3) {
        NativeHandle = new gp_Mat(*Col1->GetXYZ(), *Col2->GetXYZ(), *Col3->GetXYZ());
    };


    //释放
    xgp_Mat::~xgp_Mat() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };
    //释放
    xgp_Mat::!xgp_Mat() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };

    //! Assigns the three coordinates of Value to the column of index
    //! Col of this matrix.
    //! Raises OutOfRange if Col < 1 or Col > 3.
    void xgp_Mat::SetCol(Standard_Integer Col, xgp_XYZ^ Value) {
        NativeHandle->SetCol(Col, *Value->GetXYZ());
    };

    //! Assigns the number triples Col1, Col2, Col3 to the three
    //! columns of this matrix.
    void xgp_Mat::SetCols(xgp_XYZ^ Col1, xgp_XYZ^ Col2, xgp_XYZ^ Col3) {
        NativeHandle->SetCols(*Col1->GetXYZ(), *Col2->GetXYZ(), *Col3->GetXYZ());
    };


    //! Modifies the matrix  M so that applying it to any number
    //! triple (X, Y, Z) produces the same result as the cross
    //! product of Ref and the number triple (X, Y, Z):
    //! i.e.: M * {X,Y,Z}t = Ref.Cross({X, Y ,Z})
    //! this matrix is anti symmetric. To apply this matrix to the
    //! triplet  {XYZ} is the same as to do the cross product between the
    //! triplet Ref and the triplet {XYZ}.
    //! Note: this matrix is anti-symmetric.
    void xgp_Mat::SetCross(xgp_XYZ^ Ref) {
        NativeHandle->SetCross(*Ref->GetXYZ());
    };


    //! Modifies the main diagonal of the matrix.
    //! <me>.Value (1, 1) = X1
    //! <me>.Value (2, 2) = X2
    //! <me>.Value (3, 3) = X3
    //! The other coefficients of the matrix are not modified.
    void xgp_Mat::SetDiagonal(Standard_Real X1, Standard_Real X2, Standard_Real X3) {
        NativeHandle->SetDiagonal(X1, X2, X3);
    };


    //! Modifies this matrix so that applying it to any number
    //! triple (X, Y, Z) produces the same result as the scalar
    //! product of Ref and the number triple (X, Y, Z):
    //! this * (X,Y,Z) = Ref.(X,Y,Z)
    //! Note: this matrix is symmetric.
    void xgp_Mat::SetDot(xgp_XYZ^ Ref) {
        NativeHandle->SetDot(*Ref->GetXYZ());
    };

    //! Modifies this matrix so that it represents the Identity matrix.
    void xgp_Mat::SetIdentity() {
        NativeHandle->SetIdentity();
    };


    //! Modifies this matrix so that it represents a rotation. Ang is the angular value in
    //! radians and the XYZ axis gives the direction of the
    //! rotation.
    //! Raises ConstructionError if XYZ.Modulus() <= Resolution()
    void xgp_Mat::SetRotation(xgp_XYZ^ Axis, Standard_Real Ang) {
        NativeHandle->SetRotation(*Axis->GetXYZ(), Ang);
    };

    //! Assigns the three coordinates of Value to the row of index
    //! Row of this matrix. Raises OutOfRange if Row < 1 or Row > 3.
    void xgp_Mat::SetRow(Standard_Integer Row, xgp_XYZ^ Value) {
        NativeHandle->SetRow(Row, *Value->GetXYZ());
    };

    //! Assigns the number triples Row1, Row2, Row3 to the three
    //! rows of this matrix.
    void xgp_Mat::SetRows(xgp_XYZ^ Row1, xgp_XYZ^ Row2, xgp_XYZ^ Row3) {
        NativeHandle->SetRows(*Row1->GetXYZ(), *Row2->GetXYZ(), *Row3->GetXYZ());
    };


    //! Modifies the the matrix so that it represents
    //! a scaling transformation, where S is the scale factor. :
    //! | S    0.0  0.0 |
    //! <me> =  | 0.0   S   0.0 |
    //! | 0.0  0.0   S  |
    void xgp_Mat::SetScale(Standard_Real S) {
        NativeHandle->SetScale(S);
    };

    //! Assigns <Value> to the coefficient of row Row, column Col of   this matrix.
    //! Raises OutOfRange if Row < 1 or Row > 3 or Col < 1 or Col > 3
    void xgp_Mat::SetValue(Standard_Integer Row, Standard_Integer Col, Standard_Real Value) {
        NativeHandle->SetValue(Row, Col, Value);
    };

    //! Returns the gp_Mat
    gp_Mat xgp_Mat::GetMat() {
        return *NativeHandle;
    };

    //! Returns the column of Col index.
    //! Raises OutOfRange if Col < 1 or Col > 3
    xgp_XYZ^ xgp_Mat::Column(Standard_Integer Col) {
        gp_XYZ* aXYZ = new gp_XYZ(NativeHandle->Column(Col));
        return gcnew xgp_XYZ(aXYZ);
    };

    //! Computes the determinant of the matrix.
    Standard_Real xgp_Mat::Determinant() {
        return NativeHandle->Determinant();
    };

    //! Returns the main diagonal of the matrix.
    xgp_XYZ^ xgp_Mat::Diagonal() {
        gp_XYZ* aXYZ = new gp_XYZ(NativeHandle->Diagonal());
        return gcnew xgp_XYZ(aXYZ);
    };

    //! returns the row of Row index.
    //! Raises OutOfRange if Row < 1 or Row > 3
    xgp_XYZ^ xgp_Mat::Row(Standard_Integer Row) {
        gp_XYZ* aXYZ = new gp_XYZ(NativeHandle->Row(Row));
        return gcnew xgp_XYZ(aXYZ);
    };

    //! Returns the coefficient of range (Row, Col)
    //! Raises OutOfRange if Row < 1 or Row > 3 or Col < 1 or Col > 3
    Standard_Real xgp_Mat::Value(Standard_Integer Row, Standard_Integer Col) {
        return NativeHandle->Value(Row, Col);
    };

    //! Returns the coefficient of range (Row, Col)
    //! Raises OutOfRange if Row < 1 or Row > 3 or Col < 1 or Col > 3
    Standard_Real xgp_Mat::ChangeValue(Standard_Integer Row, Standard_Integer Col) {
        return NativeHandle->ChangeValue(Row, Col);
    };


    //! The Gauss LU decomposition is used to invert the matrix
    //! (see Math package) so the matrix is considered as singular if
    //! the largest pivot found is lower or equal to Resolution from gp.
    Standard_Boolean xgp_Mat::IsSingular() {
        return NativeHandle->IsSingular();
    };

    void xgp_Mat::Add(xgp_Mat^ Other) {
        NativeHandle->Add(Other->GetMat());
    };


    //! Computes the sum of this matrix and
    //! the matrix Other for each coefficient of the matrix :
    //! <me>.Coef(i,j) + <Other>.Coef(i,j)
    xgp_Mat^ xgp_Mat::Added(xgp_Mat^ Other) {
        return gcnew xgp_Mat(NativeHandle->Added(Other->GetMat()));
    };

    void xgp_Mat::Divide(Standard_Real Scalar) {
        NativeHandle->Divide(Scalar);
    };

    //! Divides all the coefficients of the matrix by Scalar
    xgp_Mat^ xgp_Mat::Divided(Standard_Real Scalar) {
        return gcnew xgp_Mat(NativeHandle->Divided(Scalar));
    };

    void xgp_Mat::Invert() {
        NativeHandle->Invert();
    };


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
    xgp_Mat^ xgp_Mat::Inverted() {
        return gcnew xgp_Mat(NativeHandle->Inverted());
    };


    //! Computes  the product of two matrices <me> * <Other>
    xgp_Mat^ xgp_Mat::Multiplied(xgp_Mat^ Other) {
        return gcnew xgp_Mat(NativeHandle->Multiplied(Other->GetMat()));
    };

    //! Computes the product of two matrices <me> = <Other> * <me>.
    void xgp_Mat::Multiply(xgp_Mat^ Other) {
        NativeHandle->Multiply(Other->GetMat());
    };

    void xgp_Mat::PreMultiply(xgp_Mat^ Other) {
        NativeHandle->PreMultiply(Other->GetMat());
    };

    xgp_Mat^ xgp_Mat::Multiplied(Standard_Real Scalar) {
        return gcnew xgp_Mat(NativeHandle->Multiplied(Scalar));
    };


    //! Multiplies all the coefficients of the matrix by Scalar
    void xgp_Mat::Multiply(Standard_Real Scalar) {
        NativeHandle->Multiply(Scalar);
    };

    void xgp_Mat::Power(Standard_Integer N) {
        NativeHandle->Power(N);
    };


    //! Computes <me> = <me> * <me> * .......* <me>,   N time.
    //! if N = 0 <me> = Identity
    //! if N < 0 <me> = <me>.Invert() *...........* <me>.Invert().
    //! If N < 0 an exception will be raised if the matrix is not
    //! inversible
    xgp_Mat^ xgp_Mat::Powered(Standard_Integer N) {
        return gcnew xgp_Mat(NativeHandle->Powered(N));
    };

    void xgp_Mat::Subtract(xgp_Mat^ Other) {
        NativeHandle->Subtract(Other->GetMat());
    };


    //! cOmputes for each coefficient of the matrix :
    //! <me>.Coef(i,j) - <Other>.Coef(i,j)
    xgp_Mat^ xgp_Mat::Subtracted(xgp_Mat^ Other) {
        return gcnew xgp_Mat(NativeHandle->Subtracted(Other->GetMat()));
    };

    void xgp_Mat::Transpose() {
        NativeHandle->Transpose();
    };


    //! Transposes the matrix. A(j, i) -> A (i, j)
    xgp_Mat^ xgp_Mat::Transposed() {
        return gcnew xgp_Mat(NativeHandle->Transposed());
    };

    //! Dumps the content of me into the stream
    void xgp_Mat::DumpJson(Standard_OStream theOStream, Standard_Integer theDepth) {
        NativeHandle->DumpJson(theOStream, theDepth);
    };
};
