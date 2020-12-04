#include <xgp_XYZ.h>

namespace TKMath
{
    //! Creates an XYZ object with zero co-ordinates (0,0,0)
    xgp_XYZ::xgp_XYZ(void) {
        NativeHandle = new gp_XYZ();
    };

    /// <summary>
    /// 指针映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_XYZ::xgp_XYZ(gp_XYZ* pos) {
        NativeHandle = new gp_XYZ(*pos);
    };

    //! creates an XYZ with given coordinates
    xgp_XYZ::xgp_XYZ(Standard_Real X, Standard_Real Y, Standard_Real Z) {
        NativeHandle = new gp_XYZ(X, Y, Z);
    };

    //释放
    xgp_XYZ::~xgp_XYZ() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };
    //释放
    xgp_XYZ::!xgp_XYZ() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };

    //! For this XYZ object, assigns
    //! the values X, Y and Z to its three coordinates
    void xgp_XYZ::SetCoord(Standard_Real X, Standard_Real Y, Standard_Real Z) {
        NativeHandle->SetCoord(X, Y, Z);
    };


    //! modifies the coordinate of range Index
    //! Index = 1 => X is modified
    //! Index = 2 => Y is modified
    //! Index = 3 => Z is modified
    //! Raises OutOfRange if Index != {1, 2, 3}.
    void xgp_XYZ::SetCoord(Standard_Integer Index, Standard_Real Xi) {
        NativeHandle->SetCoord(Index, Xi);
    };

    //! Assigns the given value to the X coordinate
    void xgp_XYZ::SetX(Standard_Real X) {
        NativeHandle->SetX(X);
    };

    //! Assigns the given value to the Y coordinate
    void xgp_XYZ::SetY(Standard_Real Y) {
        NativeHandle->SetY(Y);
    };

    //! Assigns the given value to the Z coordinate
    void xgp_XYZ::SetZ(Standard_Real Z) {
        NativeHandle->SetZ(Z);
    };

    //! returns the gp_XYZ
    gp_XYZ* xgp_XYZ::GetXYZ() {
        return NativeHandle;
    };
    //! returns the coordinate of range Index :
    //! Index = 1 => X is returned
    //! Index = 2 => Y is returned
    //! Index = 3 => Z is returned
    //!
    //! Raises OutOfRange if Index != {1, 2, 3}.
    Standard_Real xgp_XYZ::Coord(Standard_Integer Index) {
        return NativeHandle->Coord(Index);
    };

    Standard_Real xgp_XYZ::ChangeCoord(Standard_Integer theIndex) {
        return NativeHandle->ChangeCoord(theIndex);
    };

    void xgp_XYZ::Coord(Standard_Real X, Standard_Real Y, Standard_Real Z) {
        return NativeHandle->SetCoord(X, Y, Z);
    };


    //! Returns the X coordinate
    Standard_Real xgp_XYZ::X() {
        return NativeHandle->X();
    };

    //! Returns the Y coordinate
    Standard_Real xgp_XYZ::Y() {
        return NativeHandle->Y();
    };

    //! Returns the Z coordinate
    Standard_Real xgp_XYZ::Z() {
        return NativeHandle->Z();
    };

    //! computes Sqrt (X*X + Y*Y + Z*Z) where X, Y and Z are the three coordinates of this XYZ object.
    Standard_Real xgp_XYZ::Modulus() {
        return NativeHandle->Modulus();
    };

    //! Computes X*X + Y*Y + Z*Z where X, Y and Z are the three coordinates of this XYZ object.
    Standard_Real xgp_XYZ::SquareModulus() {
        return NativeHandle->SquareModulus();
    };


    //! Returns True if he coordinates of this XYZ object are
    //! equal to the respective coordinates Other,
    //! within the specified tolerance Tolerance. I.e.:
    //! abs(<me>.X() - Other.X()) <= Tolerance and
    //! abs(<me>.Y() - Other.Y()) <= Tolerance and
    //! abs(<me>.Z() - Other.Z()) <= Tolerance.
    Standard_Boolean xgp_XYZ::IsEqual(xgp_XYZ^ Other, Standard_Real Tolerance) {
        return NativeHandle->IsEqual(*Other->GetXYZ(), Tolerance);
    };


    //! <me>.X() = <me>.X() + Other.X()
    //! <me>.Y() = <me>.Y() + Other.Y()
    //! <me>.Z() = <me>.Z() + Other.Z()
    void xgp_XYZ::Add(xgp_XYZ^ Other) {
        NativeHandle->Add(*Other->GetXYZ());
    };


    //! new.X() = <me>.X() + Other.X()
    //! new.Y() = <me>.Y() + Other.Y()
    //! new.Z() = <me>.Z() + Other.Z()
    xgp_XYZ^ xgp_XYZ::Added(xgp_XYZ^ Other) {
        gp_XYZ* aXYZ = new gp_XYZ(NativeHandle->Added(*Other->GetXYZ()));
        return gcnew xgp_XYZ(aXYZ);
    };


    //! <me>.X() = <me>.Y() * Other.Z() - <me>.Z() * Other.Y()
    //! <me>.Y() = <me>.Z() * Other.X() - <me>.X() * Other.Z()
    //! <me>.Z() = <me>.X() * Other.Y() - <me>.Y() * Other.X()
    void xgp_XYZ::Cross(xgp_XYZ^ Right) {
        NativeHandle->Cross(*Right->GetXYZ());
    };


    //! new.X() = <me>.Y() * Other.Z() - <me>.Z() * Other.Y()
    //! new.Y() = <me>.Z() * Other.X() - <me>.X() * Other.Z()
    //! new.Z() = <me>.X() * Other.Y() - <me>.Y() * Other.X()
    xgp_XYZ^ xgp_XYZ::Crossed(xgp_XYZ^ Right) {
        gp_XYZ* aXYZ = new gp_XYZ(NativeHandle->Crossed(*Right->GetXYZ()));
        return gcnew xgp_XYZ(aXYZ);
    };


    //! Computes the magnitude of the cross product between <me> and
    //! Right. Returns || <me> ^ Right ||
    Standard_Real xgp_XYZ::CrossMagnitude(xgp_XYZ^ Right) {
        return NativeHandle->CrossMagnitude(*Right->GetXYZ());
    };


    //! Computes the square magnitude of the cross product between <me> and
    //! Right. Returns || <me> ^ Right ||**2
    Standard_Real xgp_XYZ::CrossSquareMagnitude(xgp_XYZ^ Right) {
        return NativeHandle->CrossSquareMagnitude(*Right->GetXYZ());
    };

    //! Triple vector product
    //! Computes <me> = <me>.Cross(Coord1.Cross(Coord2))
    void xgp_XYZ::CrossCross(xgp_XYZ^ Coord1, xgp_XYZ^ Coord2) {
        return NativeHandle->CrossCross(*Coord1->GetXYZ(), *Coord2->GetXYZ());
    };

    //! Triple vector product
    //! computes New = <me>.Cross(Coord1.Cross(Coord2))
    xgp_XYZ^ xgp_XYZ::CrossCrossed(xgp_XYZ^ Coord1, xgp_XYZ^ Coord2) {
        gp_XYZ* aXYZ = new gp_XYZ(NativeHandle->CrossCrossed(*Coord1->GetXYZ(), *Coord2->GetXYZ()));
        return gcnew xgp_XYZ(aXYZ);
    };

    //! divides <me> by a real.
    void xgp_XYZ::Divide(Standard_Real Scalar) {
        NativeHandle->Divide(Scalar);
    };

    //! divides <me> by a real.
    xgp_XYZ^ xgp_XYZ::Divided(Standard_Real Scalar) {
        gp_XYZ* aXYZ = new gp_XYZ(NativeHandle->Divided(Scalar));
        return gcnew xgp_XYZ(aXYZ);
    };

    //! computes the scalar product between <me> and Other
    Standard_Real xgp_XYZ::Dot(xgp_XYZ^ Other) {
        return NativeHandle->Dot(*Other->GetXYZ());
    };

    //! computes the triple scalar product
    Standard_Real xgp_XYZ::DotCross(xgp_XYZ^ Coord1, xgp_XYZ^ Coord2) {
        return NativeHandle->DotCross(*Coord1->GetXYZ(), *Coord2->GetXYZ());
    };


    //! <me>.X() = <me>.X() * Scalar;
    //! <me>.Y() = <me>.Y() * Scalar;
    //! <me>.Z() = <me>.Z() * Scalar;
    void xgp_XYZ::Multiply(Standard_Real Scalar) {
        NativeHandle->Multiply(Scalar);
    };


    //! <me>.X() = <me>.X() * Other.X();
    //! <me>.Y() = <me>.Y() * Other.Y();
    //! <me>.Z() = <me>.Z() * Other.Z();
    void xgp_XYZ::Multiply(xgp_XYZ^ Other) {
        return NativeHandle->Multiply(*Other->GetXYZ());
    };

    //! <me> = Matrix * <me>
    void xgp_XYZ::Multiply(xgp_Mat^ Matrix) {
        NativeHandle->Multiply(*Matrix->GetMat());
    };


    //! New.X() = <me>.X() * Scalar;
    //! New.Y() = <me>.Y() * Scalar;
    //! New.Z() = <me>.Z() * Scalar;
    xgp_XYZ^ xgp_XYZ::Multiplied(Standard_Real Scalar) {
        gp_XYZ* aXYZ = new gp_XYZ(NativeHandle->Multiplied(Scalar));
        return gcnew xgp_XYZ(aXYZ);
    };


    //! new.X() = <me>.X() * Other.X();
    //! new.Y() = <me>.Y() * Other.Y();
    //! new.Z() = <me>.Z() * Other.Z();
    xgp_XYZ^ xgp_XYZ::Multiplied(xgp_XYZ^ Other) {
        gp_XYZ* aXYZ = new gp_XYZ(NativeHandle->Multiplied(*Other->GetXYZ()));
        return gcnew xgp_XYZ(aXYZ);
    };

    //! New = Matrix * <me>
    xgp_XYZ^ xgp_XYZ::Multiplied(xgp_Mat^ Matrix) {
        gp_XYZ* aXYZ = new gp_XYZ(NativeHandle->Multiplied(*Matrix->GetMat()));
        return gcnew xgp_XYZ(aXYZ);
    };


    //! <me>.X() = <me>.X()/ <me>.Modulus()
    //! <me>.Y() = <me>.Y()/ <me>.Modulus()
    //! <me>.Z() = <me>.Z()/ <me>.Modulus()
    //! Raised if <me>.Modulus() <= Resolution from gp
    void xgp_XYZ::Normalize() {
        NativeHandle->Normalize();
    };


    //! New.X() = <me>.X()/ <me>.Modulus()
    //! New.Y() = <me>.Y()/ <me>.Modulus()
    //! New.Z() = <me>.Z()/ <me>.Modulus()
    //! Raised if <me>.Modulus() <= Resolution from gp
    xgp_XYZ^ xgp_XYZ::Normalized() {
        gp_XYZ* aXYZ = new gp_XYZ(NativeHandle->Normalized());
        return gcnew xgp_XYZ(aXYZ);
    };


    //! <me>.X() = -<me>.X()
    //! <me>.Y() = -<me>.Y()
    //! <me>.Z() = -<me>.Z()
    void xgp_XYZ::Reverse() {
        NativeHandle->Reverse();
    };


    //! New.X() = -<me>.X()
    //! New.Y() = -<me>.Y()
    //! New.Z() = -<me>.Z()
    xgp_XYZ^ xgp_XYZ::Reversed() {
        gp_XYZ* aXYZ = new gp_XYZ(NativeHandle->Reversed());
        return gcnew xgp_XYZ(aXYZ);
    };


    //! <me>.X() = <me>.X() - Other.X()
    //! <me>.Y() = <me>.Y() - Other.Y()
    //! <me>.Z() = <me>.Z() - Other.Z()
    void xgp_XYZ::Subtract(xgp_XYZ^ Right) {
        NativeHandle->Subtract(*Right->GetXYZ());
    };


    //! new.X() = <me>.X() - Other.X()
    //! new.Y() = <me>.Y() - Other.Y()
    //! new.Z() = <me>.Z() - Other.Z()
    xgp_XYZ^ xgp_XYZ::Subtracted(xgp_XYZ^ Right) {
        gp_XYZ* aXYZ = new gp_XYZ(NativeHandle->Subtracted(*Right->GetXYZ()));
        return gcnew xgp_XYZ(aXYZ);
    };


    //! <me> is set to the following linear form :
    //! A1 * XYZ1 + A2 * XYZ2 + A3 * XYZ3 + XYZ4
    void xgp_XYZ::SetLinearForm(Standard_Real A1, xgp_XYZ^ XYZ1, Standard_Real A2, xgp_XYZ^ XYZ2, Standard_Real A3, xgp_XYZ^ XYZ3, xgp_XYZ^ XYZ4) {
        NativeHandle->SetLinearForm(A1, *XYZ1->GetXYZ(), A2, *XYZ2->GetXYZ(), A3, *XYZ3->GetXYZ(), *XYZ4->GetXYZ());
    };


    //! <me> is set to the following linear form :
    //! A1 * XYZ1 + A2 * XYZ2 + A3 * XYZ3
    void xgp_XYZ::SetLinearForm(Standard_Real A1, xgp_XYZ^ XYZ1, Standard_Real A2, xgp_XYZ^ XYZ2, Standard_Real A3, xgp_XYZ^ XYZ3) {
        NativeHandle->SetLinearForm(A1, *XYZ1->GetXYZ(), A2, *XYZ2->GetXYZ(), A3, *XYZ3->GetXYZ());
    };


    //! <me> is set to the following linear form :
    //! A1 * XYZ1 + A2 * XYZ2 + XYZ3
    void xgp_XYZ::SetLinearForm(Standard_Real A1, xgp_XYZ^ XYZ1, Standard_Real A2, xgp_XYZ^ XYZ2, xgp_XYZ^ XYZ3) {
        NativeHandle->SetLinearForm(A1, *XYZ1->GetXYZ(), A2, *XYZ2->GetXYZ(), *XYZ3->GetXYZ());
    };


    //! <me> is set to the following linear form :
    //! A1 * XYZ1 + A2 * XYZ2
    void xgp_XYZ::SetLinearForm(Standard_Real A1, xgp_XYZ^ XYZ1, Standard_Real A2, xgp_XYZ^ XYZ2) {
        NativeHandle->SetLinearForm(A1, *XYZ1->GetXYZ(), A2, *XYZ2->GetXYZ());
    };


    //! <me> is set to the following linear form :
    //! A1 * XYZ1 + XYZ2
    void xgp_XYZ::SetLinearForm(Standard_Real A1, xgp_XYZ^ XYZ1, xgp_XYZ^ XYZ2) {
        NativeHandle->SetLinearForm(A1, *XYZ1->GetXYZ(), *XYZ2->GetXYZ());
    };


    //! <me> is set to the following linear form :
    //! XYZ1 + XYZ2
    void xgp_XYZ::SetLinearForm(xgp_XYZ^ XYZ1, xgp_XYZ^ XYZ2) {
        NativeHandle->SetLinearForm(*XYZ1->GetXYZ(), *XYZ2->GetXYZ());
    };


    //! Dumps the content of me into the stream
    void xgp_XYZ::DumpJson(Standard_OStream theOStream, Standard_Integer theDepth) {
        NativeHandle->DumpJson(theOStream, theDepth);
    };
};
