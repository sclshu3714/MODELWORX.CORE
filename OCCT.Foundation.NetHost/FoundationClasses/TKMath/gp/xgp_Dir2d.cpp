#include <xgp_Dir2d.h>

namespace TKMath
{
    //! Creates a direction corresponding to X axis.
    xgp_Dir2d::xgp_Dir2d() {
        NativeHandle = new gp_Dir2d();
    };

    /// <summary>
    /// 指针映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Dir2d::xgp_Dir2d(gp_Dir2d* pos) {
        NativeHandle = new gp_Dir2d(*pos);
    };

    //! Normalizes the vector V and creates a Direction. Raises ConstructionError if V.Magnitude() <= Resolution from gp.
    xgp_Dir2d::xgp_Dir2d(xgp_Vec2d^ V) {
        NativeHandle = new gp_Dir2d(V->GetVec2d());
    };

    //! Creates a Direction from a doublet of coordinates. Raises ConstructionError if Coord.Modulus() <= Resolution from gp.
    xgp_Dir2d::xgp_Dir2d(xgp_XY^ Coord) {
        NativeHandle = new gp_Dir2d(Coord->GetXY());
    };

    //! Creates a Direction with its 2 cartesian coordinates. Raises ConstructionError if Sqrt(Xv*Xv + Yv*Yv) <= Resolution from gp.
    xgp_Dir2d::xgp_Dir2d(Standard_Real Xv, Standard_Real Yv) {
        NativeHandle = new gp_Dir2d(Xv, Yv);
    };

    //释放
    xgp_Dir2d::~xgp_Dir2d() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };
    //释放
    xgp_Dir2d::!xgp_Dir2d() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };

    //! For this unit vector, assigns:
    //! the value Xi to:
    //! -   the X coordinate if Index is 1, or
    //! -   the Y coordinate if Index is 2, and then normalizes it.
    //! Warning
    //! Remember that all the coordinates of a unit vector are
    //! implicitly modified when any single one is changed directly.
    //! Exceptions
    //! Standard_OutOfRange if Index is not 1 or 2.
    //! Standard_ConstructionError if either of the following
    //! is less than or equal to gp::Resolution():
    //! -   Sqrt(Xv*Xv + Yv*Yv), or
    //! -   the modulus of the number pair formed by the new
    //! value Xi and the other coordinate of this vector that
    //! was not directly modified.
    //! Raises OutOfRange if Index != {1, 2}.
    void xgp_Dir2d::SetCoord(Standard_Integer Index, Standard_Real Xi) {
        NativeHandle->SetCoord(Index, Xi);
    };


    //! For this unit vector, assigns:
    //! -   the values Xv and Yv to its two coordinates,
    //! Warning
    //! Remember that all the coordinates of a unit vector are
    //! implicitly modified when any single one is changed directly.
    //! Exceptions
    //! Standard_OutOfRange if Index is not 1 or 2.
    //! Standard_ConstructionError if either of the following
    //! is less than or equal to gp::Resolution():
    //! -   Sqrt(Xv*Xv + Yv*Yv), or
    //! -   the modulus of the number pair formed by the new
    //! value Xi and the other coordinate of this vector that
    //! was not directly modified.
    //! Raises OutOfRange if Index != {1, 2}.
    void xgp_Dir2d::SetCoord(Standard_Real Xv, Standard_Real Yv) {
        NativeHandle->SetCoord(Xv, Yv);
    };


    //! Assigns the given value to the X coordinate of this unit   vector,
    //! and then normalizes it.
    //! Warning
    //! Remember that all the coordinates of a unit vector are
    //! implicitly modified when any single one is changed directly.
    //! Exceptions
    //! Standard_ConstructionError if either of the following
    //! is less than or equal to gp::Resolution():
    //! -   the modulus of Coord, or
    //! -   the modulus of the number pair formed from the new
    //! X or Y coordinate and the other coordinate of this
    //! vector that was not directly modified.
    void xgp_Dir2d::SetX(Standard_Real X) {
        NativeHandle->SetX(X);
    };


    //! Assigns  the given value to the Y coordinate of this unit   vector,
    //! and then normalizes it.
    //! Warning
    //! Remember that all the coordinates of a unit vector are
    //! implicitly modified when any single one is changed directly.
    //! Exceptions
    //! Standard_ConstructionError if either of the following
    //! is less than or equal to gp::Resolution():
    //! -   the modulus of Coord, or
    //! -   the modulus of the number pair formed from the new
    //! X or Y coordinate and the other coordinate of this
    //! vector that was not directly modified.
    void xgp_Dir2d::SetY(Standard_Real Y) {
        NativeHandle->SetY(Y);
    };


    //! Assigns:
    //! -   the two coordinates of Coord to this unit vector,
    //! and then normalizes it.
    //! Warning
    //! Remember that all the coordinates of a unit vector are
    //! implicitly modified when any single one is changed directly.
    //! Exceptions
    //! Standard_ConstructionError if either of the following
    //! is less than or equal to gp::Resolution():
    //! -   the modulus of Coord, or
    //! -   the modulus of the number pair formed from the new
    //! X or Y coordinate and the other coordinate of this
    //! vector that was not directly modified.
    void xgp_Dir2d::SetXY(xgp_XY^ Coord) {
        NativeHandle->SetXY(Coord->GetXY());
    };

    //! return the gp_Dir2d
    gp_Dir2d* xgp_Dir2d::GetDir2d() {
        return NativeHandle;
    };

    //! For this unit vector returns the coordinate of range Index :
    //! Index = 1 => X is returned
    //! Index = 2 => Y is returned
    //! Raises OutOfRange if Index != {1, 2}.
    Standard_Real xgp_Dir2d::Coord(Standard_Integer Index) {
        return NativeHandle->Coord(Index);
    };

    //! For this unit vector returns its two coordinates Xv and Yv.
    //! Raises OutOfRange if Index != {1, 2}.
    void xgp_Dir2d::Coord(Standard_Real Xv, Standard_Real Yv) {
        return NativeHandle->SetCoord(Xv, Yv);
    };

    //! For this unit vector, returns its X coordinate.
    Standard_Real xgp_Dir2d::X() {
        return NativeHandle->X();
    };

    //! For this unit vector, returns its Y coordinate.
    Standard_Real xgp_Dir2d::Y() {
        return NativeHandle->Y();
    };

    //! For this unit vector, returns its two coordinates as a number pair.
    //! Comparison between Directions
    //! The precision value is an input data.
    xgp_XY^ xgp_Dir2d::XY() {
        return gcnew xgp_XY(NativeHandle->XY());
    };


    //! Returns True if the two vectors have the same direction
    //! i.e. the angle between this unit vector and the
    //! unit vector Other is less than or equal to AngularTolerance.
    Standard_Boolean xgp_Dir2d::IsEqual(xgp_Dir2d^ Other, Standard_Real AngularTolerance) {
        return NativeHandle->IsEqual(*Other->GetDir2d(), AngularTolerance);
    };


    //! Returns True if the angle between this unit vector and the
    //! unit vector Other is equal to Pi/2 or -Pi/2 (normal)
    //! i.e. Abs(Abs(<me>.Angle(Other)) - PI/2.) <= AngularTolerance
    Standard_Boolean xgp_Dir2d::IsNormal(xgp_Dir2d^ Other, Standard_Real AngularTolerance) {
        return NativeHandle->IsNormal(*Other->GetDir2d(), AngularTolerance);
    };


    //! Returns True if the angle between this unit vector and the
    //! unit vector Other is equal to Pi or -Pi (opposite).
    //! i.e.  PI - Abs(<me>.Angle(Other)) <= AngularTolerance
    Standard_Boolean xgp_Dir2d::IsOpposite(xgp_Dir2d^ Other, Standard_Real AngularTolerance) {
        return NativeHandle->IsOpposite(*Other->GetDir2d(), AngularTolerance);
    };


    //! returns true if if the angle between this unit vector and unit
    //! vector Other is equal to 0, Pi or -Pi.
    //! i.e.  Abs(Angle(<me>, Other)) <= AngularTolerance or
    //! PI - Abs(Angle(<me>, Other)) <= AngularTolerance
    Standard_Boolean xgp_Dir2d::IsParallel(xgp_Dir2d^ Other, Standard_Real AngularTolerance) {
        return NativeHandle->IsParallel(*Other->GetDir2d(), AngularTolerance);
    };


    //! Computes the angular value in radians between <me> and
    //! <Other>. Returns the angle in the range [-PI, PI].
    Standard_Real xgp_Dir2d::Angle(xgp_Dir2d^ Other) {
        return NativeHandle->Angle(*Other->GetDir2d());
    };


    //! Computes the cross product between two directions.
    Standard_Real xgp_Dir2d::Crossed(xgp_Dir2d^ Right) {
        return NativeHandle->Crossed(*Right->GetDir2d());
    };


    //! Computes the scalar product
    Standard_Real xgp_Dir2d::Dot(xgp_Dir2d^ Other) {
        return NativeHandle->Dot(*Other->GetDir2d());
    };


    void xgp_Dir2d::Reverse() {
        NativeHandle->Reverse();
    };

    //! Reverses the orientation of a direction
    xgp_Dir2d^ xgp_Dir2d::Reversed() {
        gp_Dir2d* temp = new gp_Dir2d(NativeHandle->Reversed());
        return gcnew xgp_Dir2d(temp);
    };


    void xgp_Dir2d::Mirror(xgp_Dir2d^ V) {
        NativeHandle->Mirror(*V->GetDir2d());
    };


    //! Performs the symmetrical transformation of a direction
    //! with respect to the direction V which is the center of
    //! the  symmetry.
    xgp_Dir2d^ xgp_Dir2d::Mirrored(xgp_Dir2d^ V) {
        gp_Dir2d* temp = new gp_Dir2d(NativeHandle->Mirrored(*V->GetDir2d()));
        return gcnew xgp_Dir2d(temp);
    };

    void xgp_Dir2d::Mirror(xgp_Ax2d^ A) {
        NativeHandle->Mirror(*A->GetAx2d());
    };


    //! Performs the symmetrical transformation of a direction
    //! with respect to an axis placement which is the axis
    //! of the symmetry.
    xgp_Dir2d^ xgp_Dir2d::Mirrored(xgp_Ax2d^ A) {
        gp_Dir2d* temp = new gp_Dir2d(NativeHandle->Mirrored(*A->GetAx2d()));
        return gcnew xgp_Dir2d(temp);
    };

    void xgp_Dir2d::Rotate(Standard_Real Ang) {
        NativeHandle->Rotate(Ang);
    };


    //! Rotates a direction.  Ang is the angular value of
    //! the rotation in radians.
    xgp_Dir2d^ xgp_Dir2d::Rotated(Standard_Real Ang) {
        gp_Dir2d* temp = new gp_Dir2d(NativeHandle->Rotated(Ang));
        return gcnew xgp_Dir2d(temp);
    };

    void xgp_Dir2d::Transform(xgp_Trsf2d^ T) {
        NativeHandle->Transform(T->GetTrsf2d());
    };


    //! Transforms a direction with the "Trsf" T.
    //! Warnings :
    //! If the scale factor of the "Trsf" T is negative then the
    //! direction <me> is reversed.
    xgp_Dir2d^ xgp_Dir2d::Transformed(xgp_Trsf2d^ T) {
        gp_Dir2d* temp = new gp_Dir2d(NativeHandle->Transformed(T->GetTrsf2d()));
        return gcnew xgp_Dir2d(temp);
    };
};

