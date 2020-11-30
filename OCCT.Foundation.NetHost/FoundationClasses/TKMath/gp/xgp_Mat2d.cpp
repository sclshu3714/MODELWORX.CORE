#include <xgp_Mat2d.h>

namespace TKMath
{
    //! Creates  a matrix with null coefficients.
    xgp_Mat2d::xgp_Mat2d(void) {
        NativeHandle = new gp_Mat2d();
    };

    /// <summary>
    /// 指针映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Mat2d::xgp_Mat2d(gp_Mat2d* pos) {
        NativeHandle = new gp_Mat2d(*pos);
    };
    /// <summary>
    ///  映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Mat2d::xgp_Mat2d(gp_Mat2d pos) {
        NativeHandle = new gp_Mat2d(pos);
    };

    //! Col1, Col2 are the 2 columns of the matrix.
    xgp_Mat2d::xgp_Mat2d(xgp_XY^ Col1, xgp_XY^ Col2) {
        NativeHandle = new gp_Mat2d(Col1->GetXY(), Col2->GetXY());
    };

    //释放
    xgp_Mat2d::~xgp_Mat2d() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };
    //释放
    xgp_Mat2d::!xgp_Mat2d() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };


    //! Assigns the two coordinates of Value to the column of range
    //! Col of this matrix
    //! Raises OutOfRange if Col < 1 or Col > 2.
    void xgp_Mat2d::SetCol(Standard_Integer Col, xgp_XY^ Value) {
        NativeHandle->SetCol(Col, Value->GetXY());
    };

    //! Assigns the number pairs Col1, Col2 to the two columns of   this matrix
    void xgp_Mat2d::SetCols(xgp_XY^ Col1, xgp_XY^ Col2) {
        NativeHandle->SetCols(Col1->GetXY(), Col2->GetXY());
    };


    //! Modifies the main diagonal of the matrix.
    //! <me>.Value (1, 1) = X1
    //! <me>.Value (2, 2) = X2
    //! The other coefficients of the matrix are not modified.
    void xgp_Mat2d::SetDiagonal(Standard_Real X1, Standard_Real X2) {
        NativeHandle->SetDiagonal(X1, X2);
    };

    //! Modifies this matrix, so that it represents the Identity matrix.
    void xgp_Mat2d::SetIdentity() {
        NativeHandle->SetIdentity();
    };


    //! Modifies this matrix, so that it representso a rotation. Ang is the angular
    //! value in radian of the rotation.
    void xgp_Mat2d::SetRotation(Standard_Real Ang) {
        NativeHandle->SetRotation(Ang);
    };

    //! Assigns the two coordinates of Value to the row of index Row of this matrix.
    //! Raises OutOfRange if Row < 1 or Row > 2.
    void xgp_Mat2d::SetRow(Standard_Integer Row, xgp_XY^ Value) {
        NativeHandle->SetRow(Row, Value->GetXY());
    };

    //! Assigns the number pairs Row1, Row2 to the two rows of this matrix.
    void xgp_Mat2d::SetRows(xgp_XY^ Row1, xgp_XY^ Row2) {
        NativeHandle->SetRows(Row1->GetXY(), Row2->GetXY());
    };

    //! Modifies the matrix such that it
    //! represents a scaling transformation, where S is the scale   factor :
    //! | S    0.0 |
    //! <me> =  | 0.0   S  |
    void xgp_Mat2d::SetScale(Standard_Real S) {
        NativeHandle->SetScale(S);
    };

    //! Assigns <Value> to the coefficient of row Row, column Col of this matrix.
    //! Raises OutOfRange if Row < 1 or Row > 2 or Col < 1 or Col > 2
    void xgp_Mat2d::SetValue(Standard_Integer Row, Standard_Integer Col, Standard_Real Value) {
        NativeHandle->SetValue(Row, Col, Value);
    };

    //! Returns the gp_Mat2d
    gp_Mat2d xgp_Mat2d::GetMat2d() {
        return *NativeHandle;
    };

    //! Returns the column of Col index.
    //! Raises OutOfRange if Col < 1 or Col > 2
    xgp_XY^ xgp_Mat2d::Column(Standard_Integer Col) {
        return gcnew xgp_XY(NativeHandle->Column(Col));
    };

    //! Computes the determinant of the matrix.
    Standard_Real xgp_Mat2d::Determinant() {
        return  NativeHandle->Determinant();
    };

    //! Returns the main diagonal of the matrix.
    xgp_XY^ xgp_Mat2d::Diagonal() {
        return gcnew xgp_XY(NativeHandle->Diagonal());
    };

    //! Returns the row of index Row.
    //! Raised if Row < 1 or Row > 2
    xgp_XY^ xgp_Mat2d::Row(Standard_Integer Row) {
        return gcnew xgp_XY(NativeHandle->Row(Row));
    };

    //! Returns the coefficient of range (Row, Col)
    //! Raises OutOfRange
    //! if Row < 1 or Row > 2 or Col < 1 or Col > 2
    Standard_Real xgp_Mat2d::Value(Standard_Integer Row, Standard_Integer Col) {
        return NativeHandle->Value(Row, Col);
    };

    //! Returns the coefficient of range (Row, Col)
    //! Raises OutOfRange
    //! if Row < 1 or Row > 2 or Col < 1 or Col > 2
    Standard_Real xgp_Mat2d::ChangeValue(Standard_Integer Row, Standard_Integer Col) {
        return NativeHandle->ChangeValue(Row, Col);
    };


    //! Returns true if this matrix is singular (and therefore, cannot be inverted).
    //! The Gauss LU decomposition is used to invert the matrix
    //! so the matrix is considered as singular if the largest
    //! pivot found is lower or equal to Resolution from gp.
    Standard_Boolean xgp_Mat2d::IsSingular() {
        return NativeHandle->IsSingular();
    };

    void xgp_Mat2d::Add(xgp_Mat2d^ Other) {
        NativeHandle->Add(Other->GetMat2d());    
    };


    //! Computes the sum of this matrix and the matrix
    //! Other.for each coefficient of the matrix :
    //! <me>.Coef(i,j) + <Other>.Coef(i,j)
    //! Note:
    //! -   operator += assigns the result to this matrix, while
    //! -   operator + creates a new one.
    xgp_Mat2d^ xgp_Mat2d::Added(xgp_Mat2d^ Other) {
        return gcnew xgp_Mat2d(NativeHandle->Added(Other->GetMat2d()));
    };

    void xgp_Mat2d::Divide(Standard_Real Scalar) {
        NativeHandle->Divide(Scalar);
    };


    //! Divides all the coefficients of the matrix by a scalar.
    xgp_Mat2d^ xgp_Mat2d::Divided(Standard_Real Scalar) {
        return gcnew xgp_Mat2d(NativeHandle->Divided(Scalar));
    };

    void xgp_Mat2d::Invert() {
        NativeHandle->Invert();
    };


    //! Inverses the matrix and raises exception if the matrix
    //! is singular.
    xgp_Mat2d^ xgp_Mat2d::Inverted() {
        return gcnew xgp_Mat2d(NativeHandle->Inverted());
    };

    xgp_Mat2d^ xgp_Mat2d::Multiplied(xgp_Mat2d^ Other) {
        return gcnew xgp_Mat2d(NativeHandle->Multiplied(Other->GetMat2d()));
    };


    //! Computes the product of two matrices <me> * <Other>
    void xgp_Mat2d::Multiply(xgp_Mat2d^ Other) {
        NativeHandle->Multiply(Other->GetMat2d());
    };

    //! Modifies this matrix by premultiplying it by the matrix Other
    //! <me> = Other * <me>.
    void xgp_Mat2d::PreMultiply(xgp_Mat2d^ Other) {
        NativeHandle->PreMultiply(Other->GetMat2d());
    };

    xgp_Mat2d^ xgp_Mat2d::Multiplied(Standard_Real Scalar) {
        return gcnew xgp_Mat2d(NativeHandle->Multiplied(Scalar));
    };


    //! Multiplies all the coefficients of the matrix by a scalar.
    void xgp_Mat2d::Multiply(Standard_Real Scalar) {
        NativeHandle->Multiply(Scalar);
    };


    void xgp_Mat2d::Power(Standard_Integer N) {
        NativeHandle->Power(N);
    };


    //! computes <me> = <me> * <me> * .......* <me>, N time.
    //! if N = 0 <me> = Identity
    //! if N < 0 <me> = <me>.Invert() *...........* <me>.Invert().
    //! If N < 0 an exception can be raised if the matrix is not
    //! inversible
    xgp_Mat2d^ xgp_Mat2d::Powered(Standard_Integer N) {
        return gcnew xgp_Mat2d(NativeHandle->Powered(N));
    };

    void xgp_Mat2d::Subtract(xgp_Mat2d^ Other) {
        NativeHandle->Subtract(Other->GetMat2d());
    };



    //! Computes for each coefficient of the matrix :
    //! <me>.Coef(i,j) - <Other>.Coef(i,j)
    xgp_Mat2d^ xgp_Mat2d::Subtracted(xgp_Mat2d^ Other) {
        return gcnew xgp_Mat2d(NativeHandle->Subtracted(Other->GetMat2d()));
    };


    void xgp_Mat2d::Transpose() {
        NativeHandle->Transpose();
    };


    //! Transposes the matrix. A(j, i) -> A (i, j)
    xgp_Mat2d^ xgp_Mat2d::Transposed() {
        return gcnew xgp_Mat2d(NativeHandle->Transposed());
    };
};
