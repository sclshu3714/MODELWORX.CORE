#include <xgp_Vec.h>

namespace TKMath
{
    //! Creates a zero vector.
    xgp_Vec::xgp_Vec(void) {
        NativeHandle = new gp_Vec();
    };

    /// <summary>
    /// 指针映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Vec::xgp_Vec(gp_Vec* pos) {
        NativeHandle = new gp_Vec(*pos);
    };
    /// <summary>
    ///  映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Vec::xgp_Vec(gp_Vec pos) {
        NativeHandle = new gp_Vec(pos);
    };

    //! Creates a unitary vector from a direction V.
    xgp_Vec::xgp_Vec(xgp_Dir^ V) {
        NativeHandle = new gp_Vec(V->GetDir());
    };

    //! Creates a vector with a triplet of coordinates.
    xgp_Vec::xgp_Vec(xgp_XYZ^ Coord) {
        NativeHandle = new gp_Vec(*Coord->GetXYZ());
    };

    //! Creates a point with its three cartesian coordinates.
    xgp_Vec::xgp_Vec(Standard_Real Xv, Standard_Real Yv, Standard_Real Zv) {
        NativeHandle = new gp_Vec(Xv, Yv, Zv);
    };


    //! Creates a vector from two points. The length of the vector
    //! is the distance between P1 and P2
    xgp_Vec::xgp_Vec(xgp_Pnt^ P1, xgp_Pnt^ P2) {
        NativeHandle = new gp_Vec(P1->GetPnt(), P2->GetPnt());
    };


    //释放
    xgp_Vec::~xgp_Vec() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };
    //释放
    xgp_Vec::!xgp_Vec() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };

    //! Changes the coordinate of range Index
    //! Index = 1 => X is modified
    //! Index = 2 => Y is modified
    //! Index = 3 => Z is modified
    //! Raised if Index != {1, 2, 3}.
    void xgp_Vec::SetCoord(Standard_Integer Index, Standard_Real Xi) {
        NativeHandle->SetCoord(Index, Xi);
    };

    //! For this vector, assigns
    //! -   the values Xv, Yv and Zv to its three coordinates.
    void xgp_Vec::SetCoord(Standard_Real Xv, Standard_Real Yv, Standard_Real Zv) {
        NativeHandle->SetCoord(Xv, Yv, Zv);
    };

    //! Assigns the given value to the X coordinate of this vector.
    void xgp_Vec::SetX(Standard_Real X) {
        NativeHandle->SetX(X);
    };

    //! Assigns the given value to the X coordinate of this vector.
    void xgp_Vec::SetY(Standard_Real Y) {
        NativeHandle->SetY(Y);
    };

    //! Assigns the given value to the X coordinate of this vector.
    void xgp_Vec::SetZ(Standard_Real Z) {
        NativeHandle->SetZ(Z);
    };

    //! Assigns the three coordinates of Coord to this vector.
    void xgp_Vec::SetXYZ(xgp_XYZ^ Coord) {
        NativeHandle->SetXYZ(*Coord->GetXYZ());
    };

    //! Returns the  gp_Vec
    gp_Vec xgp_Vec::GetVec() {
        return *NativeHandle;
    };
    //! Returns the coordinate of range Index :
    //! Index = 1 => X is returned
    //! Index = 2 => Y is returned
    //! Index = 3 => Z is returned
    //! Raised if Index != {1, 2, 3}.
    Standard_Real xgp_Vec::Coord(Standard_Integer Index) {
        return NativeHandle->Coord(Index);
    };

    //! For this vector returns its three coordinates Xv, Yv, and Zvinline
    void xgp_Vec::Coord(Standard_Real Xv, Standard_Real Yv, Standard_Real Zv) {
        NativeHandle->SetCoord(Xv, Yv, Zv);
    };

    //! For this vector, returns its X coordinate.
    Standard_Real xgp_Vec::X() {
        return NativeHandle->X();
    };

    //! For this vector, returns its Y coordinate.
    Standard_Real xgp_Vec::Y() {
        return NativeHandle->Y();
    };

    //! For this vector, returns its Z  coordinate.
    Standard_Real xgp_Vec::Z() {
        return NativeHandle->Z();
    };

    //! For this vector, returns
    //! -   its three coordinates as a number triple
    xgp_XYZ^ xgp_Vec::XYZ() {
        gp_XYZ* aXYZ = new gp_XYZ(NativeHandle->XYZ());
        return gcnew xgp_XYZ(aXYZ);
    };


    //! Returns True if the two vectors have the same magnitude value
    //! and the same direction. The precision values are LinearTolerance
    //! for the magnitude and AngularTolerance for the direction.
    Standard_Boolean xgp_Vec::IsEqual(xgp_Vec^ Other, Standard_Real LinearTolerance, Standard_Real AngularTolerance) {
        return NativeHandle->IsEqual(Other->GetVec(), LinearTolerance, AngularTolerance);
    };


    //! Returns True if abs(<me>.Angle(Other) - PI/2.) <= AngularTolerance
    //! Raises VectorWithNullMagnitude if <me>.Magnitude() <= Resolution or
    //! Other.Magnitude() <= Resolution from gp
    Standard_Boolean xgp_Vec::IsNormal(xgp_Vec^ Other, Standard_Real AngularTolerance) {
        return NativeHandle->IsNormal(Other->GetVec(), AngularTolerance);
    };


    //! Returns True if PI - <me>.Angle(Other) <= AngularTolerance
    //! Raises VectorWithNullMagnitude if <me>.Magnitude() <= Resolution or
    //! Other.Magnitude() <= Resolution from gp
    Standard_Boolean xgp_Vec::IsOpposite(xgp_Vec^ Other, Standard_Real AngularTolerance) {
        return NativeHandle->IsOpposite(Other->GetVec(), AngularTolerance);
    };


    //! Returns True if Angle(<me>, Other) <= AngularTolerance or
    //! PI - Angle(<me>, Other) <= AngularTolerance
    //! This definition means that two parallel vectors cannot define
    //! a plane but two vectors with opposite directions are considered
    //! as parallel. Raises VectorWithNullMagnitude if <me>.Magnitude() <= Resolution or
    //! Other.Magnitude() <= Resolution from gp
    Standard_Boolean xgp_Vec::IsParallel(xgp_Vec^ Other, Standard_Real AngularTolerance) {
        return NativeHandle->IsParallel(Other->GetVec(), AngularTolerance);
    };


    //! Computes the angular value between <me> and <Other>
    //! Returns the angle value between 0 and PI in radian.
    //! Raises VectorWithNullMagnitude if <me>.Magnitude() <= Resolution from gp or
    //! Other.Magnitude() <= Resolution because the angular value is
    //! indefinite if one of the vectors has a null magnitude.
    Standard_Real xgp_Vec::Angle(xgp_Vec^ Other) {
        return NativeHandle->Angle(Other->GetVec());
    };

    //! Computes the angle, in radians, between this vector and
    //! vector Other. The result is a value between -Pi and Pi.
    //! For this, VRef defines the positive sense of rotation: the
    //! angular value is positive, if the cross product this ^ Other
    //! has the same orientation as VRef relative to the plane
    //! defined by the vectors this and Other. Otherwise, the
    //! angular value is negative.
    //! Exceptions
    //! xgp_VectorWithNullMagnitude if the magnitude of this
    //! vector, the vector Other, or the vector VRef is less than or
    //! equal to gp::Resolution().
    //! Standard_DomainError if this vector, the vector Other,
    //! and the vector VRef are coplanar, unless this vector and
    //! the vector Other are parallel.
    Standard_Real xgp_Vec::AngleWithRef(xgp_Vec^ Other, xgp_Vec^ VRef) {
        return NativeHandle->AngleWithRef(Other->GetVec(), VRef->GetVec());
    };

    //! Computes the magnitude of this vector.
    Standard_Real xgp_Vec::Magnitude() {
        return NativeHandle->Magnitude();
    };

    //! Computes the square magnitude of this vector.
    Standard_Real xgp_Vec::SquareMagnitude() {
        return NativeHandle->SquareMagnitude();
    };

    //! Adds two vectors
    void xgp_Vec::Add(xgp_Vec^ Other) {
        NativeHandle->Add(Other->GetVec());
    };

    //! Adds two vectors
    xgp_Vec^ xgp_Vec::Added(xgp_Vec^ Other) {
       return gcnew xgp_Vec(NativeHandle->Added(Other->GetVec()));
    };


    //! Subtracts two vectors
    void xgp_Vec::Subtract(xgp_Vec^ Right) {
        NativeHandle->Subtract(Right->GetVec());
    };


    //! Subtracts two vectors
    xgp_Vec^ xgp_Vec::Subtracted(xgp_Vec^ Right) {
        return gcnew xgp_Vec(NativeHandle->Subtracted(Right->GetVec()));
    };


    //! Multiplies a vector by a scalar *=
    void xgp_Vec::Multiply(Standard_Real Scalar) {
        NativeHandle->Multiply(Scalar);
    };


    //! Multiplies a vector by a scalar  *
    xgp_Vec^ xgp_Vec::Multiplied(Standard_Real Scalar) {
        return gcnew xgp_Vec(NativeHandle->Multiplied(Scalar));
    };


    //! Divides a vector by a scalar
    void xgp_Vec::Divide(Standard_Real Scalar) {
        NativeHandle->Divide(Scalar);
    };


    //! Divides a vector by a scalar
    xgp_Vec^ xgp_Vec::Divided(Standard_Real Scalar) {
        return gcnew xgp_Vec(NativeHandle->Divided(Scalar));
    };


    //! computes the cross product between two vectors
    void xgp_Vec::Cross(xgp_Vec^ Right) {
        NativeHandle->Subtract(Right->GetVec());
    };


    //! computes the cross product between two vectors
    xgp_Vec^ xgp_Vec::Crossed(xgp_Vec^ Right) {
        return gcnew xgp_Vec(NativeHandle->Crossed(Right->GetVec()));
    };


    //! Computes the magnitude of the cross
    //! product between <me> and Right.
    //! Returns || <me> ^ Right ||
    Standard_Real xgp_Vec::CrossMagnitude(xgp_Vec^ Right) {
        return NativeHandle->CrossMagnitude(Right->GetVec());
    };


    //! Computes the square magnitude of
    //! the cross product between <me> and Right.
    //! Returns || <me> ^ Right ||**2
    Standard_Real xgp_Vec::CrossSquareMagnitude(xgp_Vec^ Right) {
        return NativeHandle->CrossSquareMagnitude(Right->GetVec());
    };

    //! Computes the triple vector product.
    //! <me> ^= (V1 ^ V2)
    void xgp_Vec::CrossCross(xgp_Vec^ V1, xgp_Vec^ V2) {
        NativeHandle->CrossCross(V1->GetVec(), V2->GetVec());
    };

    //! Computes the triple vector product.
    //! <me> ^ (V1 ^ V2)
    xgp_Vec^ xgp_Vec::CrossCrossed(xgp_Vec^ V1, xgp_Vec^ V2) {
        return gcnew xgp_Vec(NativeHandle->CrossCrossed(V1->GetVec(), V2->GetVec()));
    };

    //! computes the scalar product
    Standard_Real xgp_Vec::Dot(xgp_Vec^ Other) {
        return NativeHandle->Dot(Other->GetVec());
    };

    //! Computes the triple scalar product <me> * (V1 ^ V2).
    Standard_Real xgp_Vec::DotCross(xgp_Vec^ V1, xgp_Vec^ V2) {
        return NativeHandle->DotCross(V1->GetVec(), V2->GetVec());
    };

    //! normalizes a vector
    //! Raises an exception if the magnitude of the vector is
    //! lower or equal to Resolution from gp.
    void xgp_Vec::Normalize() {
        NativeHandle->Normalize();
    };

    //! normalizes a vector
    //! Raises an exception if the magnitude of the vector is
    //! lower or equal to Resolution from gp.
    xgp_Vec^ xgp_Vec::Normalized() {
        return gcnew xgp_Vec(NativeHandle->Normalized());
    };

    //! Reverses the direction of a vector
    void xgp_Vec::Reverse() {
        NativeHandle->Reverse();
    };

    //! Reverses the direction of a vector
    xgp_Vec^ xgp_Vec::Reversed() {
        return gcnew xgp_Vec(NativeHandle->Reversed());
    };


    //! <me> is set to the following linear form :
    //! A1 * V1 + A2 * V2 + A3 * V3 + V4
    void xgp_Vec::SetLinearForm(Standard_Real A1, xgp_Vec^ V1, Standard_Real A2, xgp_Vec^ V2, Standard_Real A3, xgp_Vec^ V3, xgp_Vec^ V4) {
        NativeHandle->SetLinearForm(A1, V1->GetVec(), A2, V2->GetVec(), A3, V3->GetVec(), V4->GetVec());
    };


    //! <me> is set to the following linear form :
    //! A1 * V1 + A2 * V2 + A3 * V3
    void xgp_Vec::SetLinearForm(Standard_Real A1, xgp_Vec^ V1, Standard_Real A2, xgp_Vec^ V2, Standard_Real A3, xgp_Vec^ V3) {
        NativeHandle->SetLinearForm(A1, V1->GetVec(), A2, V2->GetVec(), A3, V3->GetVec());
    };


    //! <me> is set to the following linear form :
    //! A1 * V1 + A2 * V2 + V3
    void xgp_Vec::SetLinearForm(Standard_Real A1, xgp_Vec^ V1, Standard_Real A2, xgp_Vec^ V2, xgp_Vec^ V3) {
        NativeHandle->SetLinearForm(A1, V1->GetVec(), A2, V2->GetVec(),V3->GetVec());
    };


    //! <me> is set to the following linear form :
    //! A1 * V1 + A2 * V2
    void xgp_Vec::SetLinearForm(Standard_Real A1, xgp_Vec^ V1, Standard_Real A2, xgp_Vec^ V2) {
        NativeHandle->SetLinearForm(A1,V1->GetVec(),A2, V2->GetVec());
    };


    //! <me> is set to the following linear form : A1 * V1 + V2
    void xgp_Vec::SetLinearForm(Standard_Real A1, xgp_Vec^ V1, xgp_Vec^ V2) {
        NativeHandle->SetLinearForm(A1,V1->GetVec(),V2->GetVec());
    };


    //! <me> is set to the following linear form : V1 + V2
    void xgp_Vec::SetLinearForm(xgp_Vec^ V1, xgp_Vec^ V2) {
        NativeHandle->SetLinearForm(V1->GetVec(), V2->GetVec());
    };

    void xgp_Vec::Mirror(xgp_Vec^ V) {
        NativeHandle->Mirror(V->GetVec());
    };


    //! Performs the symmetrical transformation of a vector
    //! with respect to the vector V which is the center of
    //! the  symmetry.
    xgp_Vec^ xgp_Vec::Mirrored(xgp_Vec^ V) {
        return gcnew xgp_Vec(NativeHandle->Mirrored(V->GetVec()));
    };

    void xgp_Vec::Mirror(xgp_Ax1^ A1) {
        NativeHandle->Mirror(*A1->GetAx1());
    };


    //! Performs the symmetrical transformation of a vector
    //! with respect to an axis placement which is the axis
    //! of the symmetry.
    xgp_Vec^ xgp_Vec::Mirrored(xgp_Ax1^ A1) {
        return gcnew xgp_Vec(NativeHandle->Mirrored(*A1->GetAx1()));
    };

    void xgp_Vec::Mirror(xgp_Ax2^ A2) {
        NativeHandle->Mirror(A2->GetAx2());
    };


    //! Performs the symmetrical transformation of a vector
    //! with respect to a plane. The axis placement A2 locates
    //! the plane of the symmetry : (Location, XDirection, YDirection).
    xgp_Vec^ xgp_Vec::Mirrored(xgp_Ax2^ A2) {
        return gcnew xgp_Vec(NativeHandle->Mirrored(A2->GetAx2()));
    };

    void xgp_Vec::Rotate(xgp_Ax1^ A1, Standard_Real Ang) {
        NativeHandle->Rotate(*A1->GetAx1(), Ang);
    };


    //! Rotates a vector. A1 is the axis of the rotation.
    //! Ang is the angular value of the rotation in radians.
    xgp_Vec^ xgp_Vec::Rotated(xgp_Ax1^ A1, Standard_Real Ang) {
        return gcnew xgp_Vec(NativeHandle->Rotated(*A1->GetAx1(), Ang));
    };

    void xgp_Vec::Scale(Standard_Real S) {
        NativeHandle->Scale(S);
    };

    //! Scales a vector. S is the scaling value.
    xgp_Vec^ xgp_Vec::Scaled(Standard_Real S) {
        return gcnew xgp_Vec(NativeHandle->Scaled(S));
    };

    //! Transforms a vector with the transformation T.
    void xgp_Vec::Transform(xgp_Trsf^ T) {
        NativeHandle->Transform(T->GetTrsf());
    };

    //! Transforms a vector with the transformation T.
    xgp_Vec^ xgp_Vec::Transformed(xgp_Trsf^ T) {
        return gcnew xgp_Vec(NativeHandle->Transformed(T->GetTrsf()));
    };
};
