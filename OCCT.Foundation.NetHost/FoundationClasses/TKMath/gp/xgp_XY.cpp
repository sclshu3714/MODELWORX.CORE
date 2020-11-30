#include <xgp_XY.h>

namespace TKMath
{
    //! Creates XY object with zero coordinates (0,0).
    xgp_XY::xgp_XY(void) {
        NativeHandle = new gp_XY();
    };

    /// <summary>
    /// 指针映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_XY::xgp_XY(gp_XY* pos) {
        NativeHandle = new gp_XY(*pos);
    };
    /// <summary>
    ///  映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_XY::xgp_XY(gp_XY pos) {
        NativeHandle = new gp_XY(pos);
    };

    //! a number pair defined by the XY coordinates
    xgp_XY::xgp_XY(Standard_Real X, Standard_Real Y) {
        NativeHandle = new gp_XY(X, Y);
    };

    //释放
    xgp_XY::~xgp_XY() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };
    //释放
    xgp_XY::!xgp_XY() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };

    //! modifies the coordinate of range Index
    //! Index = 1 => X is modified
    //! Index = 2 => Y is modified
    //! Raises OutOfRange if Index != {1, 2}.
    void xgp_XY::SetCoord(Standard_Integer Index, Standard_Real Xi) {
        NativeHandle->SetCoord(Index, Xi);
    };

    //! For this number pair, assigns
    //! the values X and Y to its coordinates
    void xgp_XY::SetCoord(Standard_Real X, Standard_Real Y) {
        NativeHandle->SetCoord(X, Y);
    };

    //! Assigns the given value to the X coordinate of this number pair.
    void xgp_XY::SetX(Standard_Real X) {
        NativeHandle->SetX(X);
    };

    //! Assigns the given value to the Y  coordinate of this number pair.
    void xgp_XY::SetY(Standard_Real Y) {
        NativeHandle->SetY(Y);
    };

    //! returns the gp_XY
    gp_XY xgp_XY::GetXY() {
        return *NativeHandle;
    };

    //! returns the coordinate of range Index :
    //! Index = 1 => X is returned
    //! Index = 2 => Y is returned
    //! Raises OutOfRange if Index != {1, 2}.
    Standard_Real xgp_XY::Coord(Standard_Integer Index) {
       return NativeHandle->Coord(Index);
    };

    Standard_Real xgp_XY::ChangeCoord(Standard_Integer theIndex) {
        return  NativeHandle->ChangeCoord(theIndex);
    };

    //! For this number pair, returns its coordinates X and Y.
    void xgp_XY::Coord(Standard_Real X, Standard_Real Y) {
        NativeHandle->SetCoord(X, Y);
    };

    //! Returns the X coordinate of this number pair.
    Standard_Real xgp_XY::X() {
        return  NativeHandle->X();
    };

    //! Returns the Y coordinate of this number pair.
    Standard_Real xgp_XY::Y() {
        return  NativeHandle->Y();
    };

    //! Computes Sqrt (X*X + Y*Y) where X and Y are the two coordinates of this number pair.
    Standard_Real xgp_XY::Modulus() {
        return  NativeHandle->Modulus();
    };

    //! Computes X*X + Y*Y where X and Y are the two coordinates of this number pair.
    Standard_Real xgp_XY::SquareModulus() {
        return NativeHandle->SquareModulus();
    };


    //! Returns true if the coordinates of this number pair are
    //! equal to the respective coordinates of the number pair
    //! Other, within the specified tolerance Tolerance. I.e.:
    //! abs(<me>.X() - Other.X()) <= Tolerance and
    //! abs(<me>.Y() - Other.Y()) <= Tolerance and
    //! computations
    Standard_Boolean xgp_XY::IsEqual(xgp_XY^ Other, Standard_Real Tolerance) {
        return NativeHandle->IsEqual(Other->GetXY(), Tolerance);
    };

    //! Computes the sum of this number pair and number pair Other
    //! <me>.X() = <me>.X() + Other.X()
    //! <me>.Y() = <me>.Y() + Other.Y()
    void xgp_XY::Add(xgp_XY^ Other) {
        NativeHandle->Add(Other->GetXY());
    };

    //! Computes the sum of this number pair and number pair Other
    //! new.X() = <me>.X() + Other.X()
    //! new.Y() = <me>.Y() + Other.Y()
    xgp_XY^ xgp_XY::Added(xgp_XY^ Other) {
        return gcnew xgp_XY(NativeHandle->Added(Other->GetXY()));
    };


    //! Real D = <me>.X() * Other.Y() - <me>.Y() * Other.X()
    Standard_Real xgp_XY::Crossed(xgp_XY^ Right) {
        return NativeHandle->Crossed(Right->GetXY());
    };


    //! computes the magnitude of the cross product between <me> and
    //! Right. Returns || <me> ^ Right ||
    Standard_Real xgp_XY::CrossMagnitude(xgp_XY^ Right) {
        return NativeHandle->CrossMagnitude(Right->GetXY());
    };


    //! computes the square magnitude of the cross product between <me> and
    //! Right. Returns || <me> ^ Right ||**2
    Standard_Real xgp_XY::CrossSquareMagnitude(xgp_XY^ Right) {
        return NativeHandle->CrossSquareMagnitude(Right->GetXY());
    };

    //! divides <me> by a real.
    void xgp_XY::Divide(Standard_Real Scalar) {
        return NativeHandle->Divide(Scalar);
    };

    //! Divides <me> by a real.
    xgp_XY^ xgp_XY::Divided(Standard_Real Scalar) {
        return gcnew xgp_XY(NativeHandle->Divided(Scalar));
    };

    //! Computes the scalar product between <me> and Other
    Standard_Real xgp_XY::Dot(xgp_XY^ Other) {
        return NativeHandle->Dot(Other->GetXY());
    };


    //! <me>.X() = <me>.X() * Scalar;
    //! <me>.Y() = <me>.Y() * Scalar;
    void xgp_XY::Multiply(Standard_Real Scalar) {
        NativeHandle->Multiply(Scalar);
    };


    //! <me>.X() = <me>.X() * Other.X();
    //! <me>.Y() = <me>.Y() * Other.Y();
    void xgp_XY::Multiply(xgp_XY^ Other) {
        NativeHandle->Multiply(Other->GetXY());
    };

    //! <me> = Matrix * <me>
    void xgp_XY::Multiply(xgp_Mat2d^ Matrix) {
        NativeHandle->Multiply(Matrix->GetMat2d());
    };


    //! New.X() = <me>.X() * Scalar;
    //! New.Y() = <me>.Y() * Scalar;
    xgp_XY^ xgp_XY::Multiplied(Standard_Real Scalar) {
        return gcnew xgp_XY(NativeHandle->Multiplied(Scalar));
    };


    //! new.X() = <me>.X() * Other.X();
    //! new.Y() = <me>.Y() * Other.Y();
    xgp_XY^ xgp_XY::Multiplied(xgp_XY^ Other) {
        return gcnew xgp_XY(NativeHandle->Multiplied(Other->GetXY()));
    };

    //! New = Matrix * <me>
    xgp_XY^ xgp_XY::Multiplied(xgp_Mat2d^ Matrix) {
        return gcnew xgp_XY(NativeHandle->Multiplied(Matrix->GetMat2d()));
    };


    //! <me>.X() = <me>.X()/ <me>.Modulus()
    //! <me>.Y() = <me>.Y()/ <me>.Modulus()
    //! Raises ConstructionError if <me>.Modulus() <= Resolution from gp
    void xgp_XY::Normalize() {
        NativeHandle->Normalize();
    };


    //! New.X() = <me>.X()/ <me>.Modulus()
    //! New.Y() = <me>.Y()/ <me>.Modulus()
    //! Raises ConstructionError if <me>.Modulus() <= Resolution from gp
    xgp_XY^ xgp_XY::Normalized() {
        return gcnew xgp_XY(NativeHandle->Normalized());
    };


    //! <me>.X() = -<me>.X()
    //! <me>.Y() = -<me>.Y()
    void xgp_XY::Reverse() {
        NativeHandle->Reverse();
    };


    //! New.X() = -<me>.X()
    //! New.Y() = -<me>.Y()
    xgp_XY^ xgp_XY::Reversed() {
        return gcnew xgp_XY(NativeHandle->Reversed());
    };


    //! Computes  the following linear combination and
    //! assigns the result to this number pair:
    //! A1 * XY1 + A2 * XY2
    void xgp_XY::SetLinearForm(Standard_Real A1, xgp_XY^ XY1, Standard_Real A2, xgp_XY^ XY2) {
        NativeHandle->SetLinearForm(A1, XY1->GetXY(), A2, XY2->GetXY());
    };


    //! --  Computes  the following linear combination and
    //! assigns the result to this number pair:
    //! A1 * XY1 + A2 * XY2 + XY3
    void xgp_XY::SetLinearForm(Standard_Real A1, xgp_XY^ XY1, Standard_Real A2, xgp_XY^ XY2, xgp_XY^ XY3) {
        NativeHandle->SetLinearForm(A1, XY1->GetXY(), A2, XY2->GetXY(), XY3->GetXY());
    };


    //! Computes  the following linear combination and
    //! assigns the result to this number pair:
    //! A1 * XY1 + XY2
    void xgp_XY::SetLinearForm(Standard_Real A1, xgp_XY^ XY1, xgp_XY^ XY2) {
        NativeHandle->SetLinearForm(A1, XY1->GetXY(), XY2->GetXY());
    };


    //! Computes  the following linear combination and
    //! assigns the result to this number pair:
    //! XY1 + XY2
    void xgp_XY::SetLinearForm(xgp_XY^ XY1, xgp_XY^ XY2) {
        NativeHandle->SetLinearForm(XY1->GetXY(), XY2->GetXY());
    };


    //! <me>.X() = <me>.X() - Other.X()
    //! <me>.Y() = <me>.Y() - Other.Y()
    void xgp_XY::Subtract(xgp_XY^ Right) {
        NativeHandle->Subtract(Right->GetXY());
    };


    //! new.X() = <me>.X() - Other.X()
    //! new.Y() = <me>.Y() - Other.Y()
    xgp_XY^ xgp_XY::Subtracted(xgp_XY^ Right) {
        return gcnew xgp_XY(NativeHandle->Subtracted(Right->GetXY()));
    };
};

