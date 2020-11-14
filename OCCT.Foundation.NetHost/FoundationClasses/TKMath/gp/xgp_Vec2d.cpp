#include <xgp_Vec2d.h>

namespace TKMath
{
    //! Creates a zero vector.
    xgp_Vec2d::xgp_Vec2d() {
        NativeHandle = new gp_Vec2d();
    };

    /// <summary>
    /// 指针映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Vec2d::xgp_Vec2d(gp_Vec2d* pos) {
        NativeHandle = new gp_Vec2d(*pos);
    };

    /// <summary>
    ///  映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Vec2d::xgp_Vec2d(gp_Vec2d pos) {
        NativeHandle = new gp_Vec2d(pos);
    };

    //! Creates a unitary vector from a direction V.
    xgp_Vec2d::xgp_Vec2d(xgp_Dir2d^ V) {
        NativeHandle = new gp_Vec2d(V->GetDir2d());
    };

    //! Creates a vector with a doublet of coordinates.
    xgp_Vec2d::xgp_Vec2d(xgp_XY^ Coord) {
        NativeHandle = new gp_Vec2d(Coord->GetXY());
    };

    //! Creates a point with its two Cartesian coordinates.
    xgp_Vec2d::xgp_Vec2d(Standard_Real^ Xv, Standard_Real^ Yv) {
        NativeHandle = new gp_Vec2d(*Xv, *Yv);
    };


    //! Creates a vector from two points. The length of the vector
    //! is the distance between P1 and P2
    xgp_Vec2d::xgp_Vec2d(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2) {
        NativeHandle = new gp_Vec2d(P1->GetPnt2d(), P2->GetPnt2d());
    };

    //释放
    xgp_Vec2d::~xgp_Vec2d() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };
    //释放
    xgp_Vec2d::!xgp_Vec2d() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };

    //! Changes the coordinate of range Index
    //! Index = 1 => X is modified
    //! Index = 2 => Y is modified
    //! Raises OutOfRange if Index != {1, 2}.
    void xgp_Vec2d::SetCoord(Standard_Integer^ Index, Standard_Real^ Xi) {
        NativeHandle->SetCoord(*Index, *Xi);
    };

    //! For this vector, assigns
    //! the values Xv and Yv to its two coordinates
    void xgp_Vec2d::SetCoord(Standard_Real^ Xv, Standard_Real^ Yv) {
        NativeHandle->SetCoord(*Xv, *Yv);
    };

    //! Assigns the given value to the X coordinate of this vector.
    void xgp_Vec2d::SetX(Standard_Real^ X) {
        NativeHandle->SetX(*X);
    };

    //! Assigns the given value to the Y coordinate of this vector.
    void xgp_Vec2d::SetY(Standard_Real^ Y) {
        NativeHandle->SetY(*Y);
    };

    //! Assigns the two coordinates of Coord to this vector.
    void xgp_Vec2d::SetXY(xgp_XY^ Coord) {
        NativeHandle->SetXY(Coord->GetXY());
    };

    //! Returns the gp_Vec2d
    gp_Vec2d xgp_Vec2d::GetVec2d() {
        return *NativeHandle;
    };
    //! Returns the coordinate of range Index :
    //! Index = 1 => X is returned
    //! Index = 2 => Y is returned
    //! Raised if Index != {1, 2}.
    Standard_Real^ xgp_Vec2d::Coord(Standard_Integer^ Index) {
        return NativeHandle->Coord(*Index);
    };

    //! For this vector, returns  its two coordinates Xv and Yv
    void xgp_Vec2d::Coord(Standard_Real^ Xv, Standard_Real^ Yv) {
        NativeHandle->SetCoord(*Xv, *Yv);
    };

    //! For this vector, returns its X  coordinate.
    Standard_Real^ xgp_Vec2d::X() {
        return NativeHandle->X();
    };

    //! For this vector, returns its Y  coordinate.
    Standard_Real^ xgp_Vec2d::Y() {
        return NativeHandle->Y();
    };

    //! For this vector, returns its two coordinates as a number pair
    xgp_XY^ xgp_Vec2d::XY() {
        return gcnew xgp_XY(NativeHandle->XY());
    };


    //! Returns True if the two vectors have the same magnitude value
    //! and the same direction. The precision values are LinearTolerance
    //! for the magnitude and AngularTolerance for the direction.
    Standard_Boolean^ xgp_Vec2d::IsEqual(xgp_Vec2d^ Other, Standard_Real^ LinearTolerance, Standard_Real^ AngularTolerance) {
        return NativeHandle->IsEqual(Other->GetVec2d(), *LinearTolerance, *AngularTolerance);
    };


    //! Returns True if abs(Abs(<me>.Angle(Other)) - PI/2.)
    //! <= AngularTolerance
    //! Raises VectorWithNullMagnitude if <me>.Magnitude() <= Resolution or
    //! Other.Magnitude() <= Resolution from gp.
    Standard_Boolean^ xgp_Vec2d::IsNormal(xgp_Vec2d^ Other, Standard_Real^ AngularTolerance) {
        return NativeHandle->IsNormal(Other->GetVec2d(), *AngularTolerance);
    };


    //! Returns True if PI - Abs(<me>.Angle(Other)) <= AngularTolerance
    //! Raises VectorWithNullMagnitude if <me>.Magnitude() <= Resolution or
    //! Other.Magnitude() <= Resolution from gp.
    Standard_Boolean^ xgp_Vec2d::IsOpposite(xgp_Vec2d^ Other, Standard_Real^ AngularTolerance) {
        return NativeHandle->IsOpposite(Other->GetVec2d(), *AngularTolerance);
    };


    //! Returns true if Abs(Angle(<me>, Other)) <= AngularTolerance or
    //! PI - Abs(Angle(<me>, Other)) <= AngularTolerance
    //! Two vectors with opposite directions are considered as parallel.
    //! Raises VectorWithNullMagnitude if <me>.Magnitude() <= Resolution or
    //! Other.Magnitude() <= Resolution from gp
    Standard_Boolean^ xgp_Vec2d::IsParallel(xgp_Vec2d^ Other, Standard_Real^ AngularTolerance) {
        return NativeHandle->IsParallel(Other->GetVec2d(), *AngularTolerance);
    };


    //! Computes the angular value between <me> and <Other>
    //! returns the angle value between -PI and PI in radian.
    //! The orientation is from <me> to Other. The positive sense is the
    //! trigonometric sense.
    //! Raises VectorWithNullMagnitude if <me>.Magnitude() <= Resolution from gp or
    //! Other.Magnitude() <= Resolution because the angular value is
    //! indefinite if one of the vectors has a null magnitude.
    Standard_Real^ xgp_Vec2d::Angle(xgp_Vec2d^ Other) {
        return NativeHandle->Angle(Other->GetVec2d());
    };

    //! Computes the magnitude of this vector.
    Standard_Real^ xgp_Vec2d::Magnitude() {
        return NativeHandle->Magnitude();
    };

    //! Computes the square magnitude of this vector.
    Standard_Real^ xgp_Vec2d::SquareMagnitude() {
        return NativeHandle->SquareMagnitude();
    };

    void xgp_Vec2d::Add(xgp_Vec2d^ Other) {
        NativeHandle->Add(Other->GetVec2d());
    };

    //! Adds two vectors
    xgp_Vec2d^ xgp_Vec2d::Added(xgp_Vec2d^ Other) {
        return gcnew xgp_Vec2d(NativeHandle->Added(Other->GetVec2d()));
    };

    //! Computes the crossing product between two vectors
    Standard_Real^ xgp_Vec2d::Crossed(xgp_Vec2d^ Right) {
        return NativeHandle->Crossed(Right->GetVec2d());
    };


    //! Computes the magnitude of the cross product between <me> and
    //! Right. Returns || <me> ^ Right ||
    Standard_Real^ xgp_Vec2d::CrossMagnitude(xgp_Vec2d^ Right) {
        return NativeHandle->CrossMagnitude(Right->GetVec2d());
    };


    //! Computes the square magnitude of the cross product between <me> and
    //! Right. Returns || <me> ^ Right ||**2
    Standard_Real^ xgp_Vec2d::CrossSquareMagnitude(xgp_Vec2d^ Right) {
        return NativeHandle->CrossSquareMagnitude(Right->GetVec2d());
    };

    void xgp_Vec2d::Divide(Standard_Real^ Scalar) {
        NativeHandle->Divide(*Scalar);
    };

    //! divides a vector by a scalar
    xgp_Vec2d^ xgp_Vec2d::Divided(Standard_Real^ Scalar) {
        return gcnew xgp_Vec2d(NativeHandle->Divided(*Scalar));
    };

    //! Computes the scalar product
    Standard_Real^ xgp_Vec2d::Dot(xgp_Vec2d^ Other) {
        return NativeHandle->Dot(Other->GetVec2d());
    };

    xgp_Vec2d^ xgp_Vec2d::GetNormal() {
        return gcnew xgp_Vec2d(NativeHandle->GetNormal());
    };

    void xgp_Vec2d::Multiply(Standard_Real^ Scalar) {
        NativeHandle->Multiply(*Scalar);
    };


    //! Normalizes a vector
    //! Raises an exception if the magnitude of the vector is
    //! lower or equal to Resolution from package gp.
    xgp_Vec2d^ xgp_Vec2d::Multiplied(Standard_Real^ Scalar) {
        return gcnew xgp_Vec2d(NativeHandle->Multiplied(*Scalar));
    };

    void xgp_Vec2d::Normalize() {
        NativeHandle->Normalize();
    };

    //! Normalizes a vector
    //! Raises an exception if the magnitude of the vector is
    //! lower or equal to Resolution from package gp.
    //! Reverses the direction of a vector
    xgp_Vec2d^ xgp_Vec2d::Normalized() {
        return gcnew xgp_Vec2d(NativeHandle->Normalized());
    };

    void xgp_Vec2d::Reverse() {
        NativeHandle->Reverse();
    };

    //! Reverses the direction of a vector
    xgp_Vec2d^ xgp_Vec2d::Reversed() {
        return gcnew xgp_Vec2d(NativeHandle->Reversed());
    };

    //! Subtracts two vectors
    void xgp_Vec2d::Subtract(xgp_Vec2d^ Right) {
        NativeHandle->Subtract(Right->GetVec2d());
    };


    //! Subtracts two vectors
    xgp_Vec2d^ xgp_Vec2d::Subtracted(xgp_Vec2d^ Right) {
        return gcnew xgp_Vec2d(NativeHandle->Subtracted(Right->GetVec2d()));
    };


    //! <me> is set to the following linear form :
    //! A1 * V1 + A2 * V2 + V3
    void xgp_Vec2d::SetLinearForm(Standard_Real^ A1, xgp_Vec2d^ V1, Standard_Real^ A2, xgp_Vec2d^ V2, xgp_Vec2d^ V3) {
        NativeHandle->SetLinearForm(*A1, V1->GetVec2d(), *A2, V2->GetVec2d(), V3->GetVec2d());
    };


    //! <me> is set to the following linear form : A1 * V1 + A2 * V2
    void xgp_Vec2d::SetLinearForm(Standard_Real^ A1, xgp_Vec2d^ V1, Standard_Real^ A2, xgp_Vec2d^ V2) {
        NativeHandle->SetLinearForm(*A1, V1->GetVec2d(), *A2, V2->GetVec2d());
    };


    //! <me> is set to the following linear form : A1 * V1 + V2
    void xgp_Vec2d::SetLinearForm(Standard_Real^ A1, xgp_Vec2d^ V1, xgp_Vec2d^ V2) {
        NativeHandle->SetLinearForm(*A1, V1->GetVec2d(), V2->GetVec2d());
    };


    //! <me> is set to the following linear form : Left + Right
    void xgp_Vec2d::SetLinearForm(xgp_Vec2d^ Left, xgp_Vec2d^ Right) {
        NativeHandle->SetLinearForm(Left->GetVec2d(), Right->GetVec2d());
    };


    //! Performs the symmetrical transformation of a vector
    //! with respect to the vector V which is the center of
    //! the  symmetry.
    void xgp_Vec2d::Mirror(xgp_Vec2d^ V) {
        NativeHandle->Mirror(V->GetVec2d());
    };


    //! Performs the symmetrical transformation of a vector
    //! with respect to the vector V which is the center of
    //! the  symmetry.
    xgp_Vec2d^ xgp_Vec2d::Mirrored(xgp_Vec2d^ V) {
        return gcnew xgp_Vec2d(NativeHandle->Mirrored(V->GetVec2d()));
    };


    //! Performs the symmetrical transformation of a vector
    //! with respect to an axis placement which is the axis
    //! of the symmetry.
    void xgp_Vec2d::Mirror(xgp_Ax2d^ A1) {
        NativeHandle->Mirror(A1->GetAx2d());
    };


    //! Performs the symmetrical transformation of a vector
    //! with respect to an axis placement which is the axis
    //! of the symmetry.
    xgp_Vec2d^ xgp_Vec2d::Mirrored(xgp_Ax2d^ A1) {
        return gcnew xgp_Vec2d(NativeHandle->Mirrored(A1->GetAx2d()));
    };

    void xgp_Vec2d::Rotate(Standard_Real^ Ang) {
        NativeHandle->Rotate(*Ang);
    };


    //! Rotates a vector. Ang is the angular value of the
    //! rotation in radians.
    xgp_Vec2d^ xgp_Vec2d::Rotated(Standard_Real^ Ang) {
        return gcnew xgp_Vec2d(NativeHandle->Rotated(*Ang));
    };

    void xgp_Vec2d::Scale(Standard_Real^ S) {
        NativeHandle->Scale(*S);
    };

    //! Scales a vector. S is the scaling value.
    xgp_Vec2d^ xgp_Vec2d::Scaled(Standard_Real^ S) {
        return gcnew xgp_Vec2d(NativeHandle->Rotated(*S));
    };

    void xgp_Vec2d::Transform(xgp_Trsf2d^ T) {
        NativeHandle->Transform(T->GetTrsf2d());
    };

    //! Transforms a vector with a Trsf from gp.
    xgp_Vec2d^ xgp_Vec2d::Transformed(xgp_Trsf2d^ T) {
        return gcnew xgp_Vec2d(NativeHandle->Transformed(T->GetTrsf2d()));
    };
};
