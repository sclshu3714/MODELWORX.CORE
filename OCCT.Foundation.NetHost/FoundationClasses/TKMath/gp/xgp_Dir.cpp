#include <xgp_Dir.h>

namespace TKMath
{
    //! Creates a direction corresponding to X axis.
    xgp_Dir::xgp_Dir() {
        NativeHandle = new gp_Dir();
    };

    /// <summary>
    /// 指针映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Dir::xgp_Dir(gp_Dir* pos) {
        NativeHandle = new gp_Dir(*pos);
    };
    /// <summary>
    ///  映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Dir::xgp_Dir(gp_Dir pos) {
        NativeHandle = new gp_Dir(pos);
    };

    //! Normalizes the vector V and creates a direction. Raises ConstructionError if V.Magnitude() <= Resolution.
    xgp_Dir::xgp_Dir(xgp_Vec^ V) {
        NativeHandle = new gp_Dir(V->GetVec());
    };

    //! Creates a direction from a triplet of coordinates. Raises ConstructionError if Coord.Modulus() <= Resolution from gp.
    xgp_Dir::xgp_Dir(xgp_XYZ^ Coord) {
        NativeHandle = new gp_Dir(*Coord->GetXYZ());
    };

    //! Creates a direction with its 3 cartesian coordinates. Raises ConstructionError if Sqrt(Xv*Xv + Yv*Yv + Zv*Zv) <= Resolution
    //! Modification of the direction's coordinates
    //! If Sqrt (X*X + Y*Y + Z*Z) <= Resolution from gp where
    //! X, Y ,Z are the new coordinates it is not possible to
    //! construct the direction and the method raises the
    //! exception ConstructionError.
    xgp_Dir::xgp_Dir(Standard_Real Xv, Standard_Real Yv, Standard_Real Zv) {
        NativeHandle = new gp_Dir(Xv, Yv, Zv);
    };


    //释放
    xgp_Dir::~xgp_Dir() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };
    //释放
    xgp_Dir::!xgp_Dir() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };
    //! For this unit vector,  assigns the value Xi to:
    //! -   the X coordinate if Index is 1, or
    //! -   the Y coordinate if Index is 2, or
    //! -   the Z coordinate if Index is 3,
    //! and then normalizes it.
    //! Warning
    //! Remember that all the coordinates of a unit vector are
    //! implicitly modified when any single one is changed directly.
    //! Exceptions
    //! Standard_OutOfRange if Index is not 1, 2, or 3.
    //! Standard_ConstructionError if either of the following
    //! is less than or equal to gp::Resolution():
    //! -   Sqrt(Xv*Xv + Yv*Yv + Zv*Zv), or
    //! -   the modulus of the number triple formed by the new
    //! value Xi and the two other coordinates of this vector
    //! that were not directly modified.
    void xgp_Dir::SetCoord(Standard_Integer Index, Standard_Real Xi) {
        NativeHandle->SetCoord(Index, Xi);
    };

    //! For this unit vector,  assigns the values Xv, Yv and Zv to its three coordinates.
    //! Remember that all the coordinates of a unit vector are
    //! implicitly modified when any single one is changed directly.
    void xgp_Dir::SetCoord(Standard_Real Xv, Standard_Real Yv, Standard_Real Zv) {
        NativeHandle->SetCoord(Xv, Yv, Zv);
    };

    //! Assigns the given value to the X coordinate of this   unit vector.
    void xgp_Dir::SetX(Standard_Real X) {
        NativeHandle->SetX(X);
    };

    //! Assigns the given value to the Y coordinate of this   unit vector.
    void xgp_Dir::SetY(Standard_Real Y) {
        NativeHandle->SetY(Y);
    };

    //! Assigns the given value to the Z  coordinate of this   unit vector.
    void xgp_Dir::SetZ(Standard_Real Z) {
        NativeHandle->SetZ(Z);
    };

    //! Assigns the three coordinates of Coord to this unit vector.
    void xgp_Dir::SetXYZ(xgp_XYZ^ Coord) {
        NativeHandle->SetXYZ(*Coord->GetXYZ());
    };

    //! Returns the gp_Dir
    gp_Dir xgp_Dir::GetDir() {
        return *NativeHandle;
    };
    //! Returns the coordinate of range Index :
    //! Index = 1 => X is returned
    //! Index = 2 => Y is returned
    //! Index = 3 => Z is returned
    //! Exceptions
    //! Standard_OutOfRange if Index is not 1, 2, or 3.
    Standard_Real xgp_Dir::Coord(Standard_Integer Index) {
       return NativeHandle->Coord(Index);
    };

    //! Returns for the  unit vector  its three coordinates Xv, Yv, and Zv.
    void xgp_Dir::Coord(Standard_Real Xv, Standard_Real Yv, Standard_Real Zv) {
        NativeHandle->SetCoord(Xv, Yv, Zv);
    };

    //! Returns the X coordinate for a  unit vector.
    Standard_Real xgp_Dir::X() {
        return NativeHandle->X();
    };

    //! Returns the Y coordinate for a  unit vector.
    Standard_Real xgp_Dir::Y() {
        return NativeHandle->Y();
    };

    //! Returns the Z coordinate for a  unit vector.
    Standard_Real xgp_Dir::Z() {
        return NativeHandle->Z();
    };

    //! for this unit vector, returns  its three coordinates as a number triplea.
    xgp_XYZ^ xgp_Dir::XYZ() {
        gp_XYZ* aXYZ = new gp_XYZ(NativeHandle->XYZ());
        return gcnew xgp_XYZ(aXYZ);
    };


    //! Returns True if the angle between the two directions is
    //! lower or equal to AngularTolerance.
    Standard_Boolean xgp_Dir::IsEqual(xgp_Dir^ Other, Standard_Real AngularTolerance) {
        return NativeHandle->IsEqual(Other->GetDir(), AngularTolerance);
    };


    //! Returns True if  the angle between this unit vector and the unit vector Other is equal to Pi/2 (normal).
    Standard_Boolean xgp_Dir::IsNormal(xgp_Dir^ Other, Standard_Real AngularTolerance) {
        return NativeHandle->IsNormal(Other->GetDir(), AngularTolerance);
    };


    //! Returns True if  the angle between this unit vector and the unit vector Other is equal to  Pi (opposite).
    Standard_Boolean xgp_Dir::IsOpposite(xgp_Dir^ Other, Standard_Real AngularTolerance) {
        return NativeHandle->IsOpposite(Other->GetDir(), AngularTolerance);
    };


    //! Returns true if the angle between this unit vector and the
    //! unit vector Other is equal to 0 or to Pi.
    //! Note: the tolerance criterion is given by AngularTolerance.
    Standard_Boolean xgp_Dir::IsParallel(xgp_Dir^ Other, Standard_Real AngularTolerance) {
        return NativeHandle->IsParallel(Other->GetDir(), AngularTolerance);
    };


    //! Computes the angular value in radians between <me> and
    //! <Other>. This value is always positive in 3D space.
    //! Returns the angle in the range [0, PI]
    Standard_Real xgp_Dir::Angle(xgp_Dir^ Other) {
        return NativeHandle->Angle(Other->GetDir());
    };


    //! Computes the angular value between <me> and <Other>.
    //! <VRef> is the direction of reference normal to <me> and <Other>
    //! and its orientation gives the positive sense of rotation.
    //! If the cross product <me> ^ <Other> has the same orientation
    //! as <VRef> the angular value is positive else negative.
    //! Returns the angular value in the range -PI and PI (in radians). Raises  DomainError if <me> and <Other> are not parallel this exception is raised
    //! when <VRef> is in the same plane as <me> and <Other>
    //! The tolerance criterion is Resolution from package gp.
    Standard_Real xgp_Dir::AngleWithRef(xgp_Dir^ Other, xgp_Dir^ VRef) {
        return NativeHandle->AngleWithRef(Other->GetDir(), VRef->GetDir());
    };

    //! Computes the cross product between two directions
    //! Raises the exception ConstructionError if the two directions
    //! are parallel because the computed vector cannot be normalized
    //! to create a direction.
    void xgp_Dir::Cross(xgp_Dir^ Right) {
        NativeHandle->Cross(Right->GetDir());
    };


    //! Computes the triple vector product.
    //! <me> ^ (V1 ^ V2)
    //! Raises the exception ConstructionError if V1 and V2 are parallel
    //! or <me> and (V1^V2) are parallel because the computed vector
    //! can't be normalized to create a direction.
    xgp_Dir^ xgp_Dir::Crossed(xgp_Dir^ Right) {
        return gcnew xgp_Dir(NativeHandle->Crossed(Right->GetDir()));
    };


    void xgp_Dir::CrossCross(xgp_Dir^ V1, xgp_Dir^ V2) {
        NativeHandle->CrossCross(V1->GetDir(), V2->GetDir());
    };

    //! Computes the double vector product this ^ (V1 ^ V2).
    //! -   CrossCrossed creates a new unit vector.
    //! Exceptions
    //! Standard_ConstructionError if:
    //! -   V1 and V2 are parallel, or
    //! -   this unit vector and (V1 ^ V2) are parallel.
    //! This is because, in these conditions, the computed vector
    //! is null and cannot be normalized.
    xgp_Dir^ xgp_Dir::CrossCrossed(xgp_Dir^ V1, xgp_Dir^ V2) {
        return gcnew xgp_Dir(NativeHandle->CrossCrossed(V1->GetDir(), V2->GetDir()));
    };

    //! Computes the scalar product
    Standard_Real xgp_Dir::Dot(xgp_Dir^ Other) {
        return NativeHandle->Dot(Other->GetDir());
    };


    //! Computes the triple scalar product <me> * (V1 ^ V2).
    //! Warnings :
    //! The computed vector V1' = V1 ^ V2 is not normalized
    //! to create a unitary vector. So this method never
    //! raises an exception even if V1 and V2 are parallel.
    Standard_Real xgp_Dir::DotCross(xgp_Dir^ V1, xgp_Dir^ V2) {
        return NativeHandle->DotCross(V1->GetDir(), V2->GetDir());
    };

    void xgp_Dir::Reverse() {
        return NativeHandle->Reverse();
    };

    //! Reverses the orientation of a direction
    //! geometric transformations
    //! Performs the symmetrical transformation of a direction
    //! with respect to the direction V which is the center of
    //! the  symmetry.]
    xgp_Dir^ xgp_Dir::Reversed() {
        return gcnew xgp_Dir(NativeHandle->Reversed());
    };


    void xgp_Dir::Mirror(xgp_Dir^ V) {
        NativeHandle->Mirror(V->GetDir());
    };


    //! Performs the symmetrical transformation of a direction
    //! with respect to the direction V which is the center of
    //! the  symmetry.
    xgp_Dir^ xgp_Dir::Mirrored(xgp_Dir^ V) {
        return gcnew xgp_Dir(NativeHandle->Mirrored(V->GetDir()));
    };

    void xgp_Dir::Mirror(xgp_Ax1^ A1) {
        NativeHandle->Mirror(A1->GetAx1());
    };


    //! Performs the symmetrical transformation of a direction
    //! with respect to an axis placement which is the axis
    //! of the symmetry.
    xgp_Dir^ xgp_Dir::Mirrored(xgp_Ax1^ A1) {
        return gcnew xgp_Dir(NativeHandle->Mirrored(A1->GetAx1()));
    };

    void xgp_Dir::Mirror(xgp_Ax2^ A2) {
        NativeHandle->Mirror(A2->GetAx2());
    };


    //! Performs the symmetrical transformation of a direction
    //! with respect to a plane. The axis placement A2 locates
    //! the plane of the symmetry : (Location, XDirection, YDirection).
    xgp_Dir^ xgp_Dir::Mirrored(xgp_Ax2^ A2) {
        return gcnew xgp_Dir(NativeHandle->Mirrored(A2->GetAx2()));
    };

    void xgp_Dir::Rotate(xgp_Ax1^ A1, Standard_Real Ang) {
        NativeHandle->Rotate(A1->GetAx1(), Ang);
    };


    //! Rotates a direction. A1 is the axis of the rotation.
    //! Ang is the angular value of the rotation in radians.
    xgp_Dir^ xgp_Dir::Rotated(xgp_Ax1^ A1, Standard_Real Ang) {
        return gcnew xgp_Dir(NativeHandle->Rotated(A1->GetAx1(), Ang));
    };

    void xgp_Dir::Transform(xgp_Trsf^ T) {
        NativeHandle->Transform(T->GetTrsf());
    };


    //! Transforms a direction with a "Trsf" from gp.
    //! Warnings :
    //! If the scale factor of the "Trsf" T is negative then the
    //! direction <me> is reversed.
    xgp_Dir^ xgp_Dir::Transformed(xgp_Trsf^ T) {
        return gcnew xgp_Dir(NativeHandle->Transformed(T->GetTrsf()));
    };
};

