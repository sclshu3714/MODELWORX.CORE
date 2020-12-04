#include <xgp_Pnt2d.h>

namespace TKMath
{
    //! Creates a point with zero coordinates.
    xgp_Pnt2d::xgp_Pnt2d() {
        NativeHandle = new gp_Pnt2d();
    };

    /// <summary>
    /// 指针映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Pnt2d::xgp_Pnt2d(gp_Pnt2d* pos) {
        NativeHandle = new gp_Pnt2d(*pos);
    };
    /// <summary>
    ///  映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Pnt2d::xgp_Pnt2d(gp_Pnt2d pos) {
        NativeHandle = new gp_Pnt2d(pos);
    };

    //! Creates a point with a doublet of coordinates.
    xgp_Pnt2d::xgp_Pnt2d(xgp_XY^ Coord) {
        NativeHandle = new gp_Pnt2d(*Coord->GetXY());
    };


    //! Creates a  point with its 2 cartesian's coordinates : Xp, Yp.
    xgp_Pnt2d::xgp_Pnt2d(Standard_Real Xp, Standard_Real Yp) {
        NativeHandle = new gp_Pnt2d(Xp, Yp);
    };


    //释放
    xgp_Pnt2d::~xgp_Pnt2d() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };
    //释放
    xgp_Pnt2d::!xgp_Pnt2d() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };

    //! Assigns the value Xi to the coordinate that corresponds to Index:
    //! Index = 1 => X is modified
    //! Index = 2 => Y is modified
    //! Raises OutOfRange if Index != {1, 2}.
    void xgp_Pnt2d::SetCoord(Standard_Integer Index, Standard_Real Xi) {
        NativeHandle->SetCoord(Index, Xi);
    };

    //! For this point, assigns the values Xp and Yp to its two coordinates
    void xgp_Pnt2d::SetCoord(Standard_Real Xp, Standard_Real Yp) {
        NativeHandle->SetCoord(Xp, Yp);
    };

    //! Assigns the given value to the X  coordinate of this point.
    void xgp_Pnt2d::SetX(Standard_Real X) {
        NativeHandle->SetX(X);
    };

    //! Assigns the given value to the Y  coordinate of this point.
    void xgp_Pnt2d::SetY(Standard_Real Y) {
        NativeHandle->SetY(Y);
    };

    //! Assigns the two coordinates of Coord to this point.
    void xgp_Pnt2d::SetXY(xgp_XY^ Coord) {
        NativeHandle->SetXY(*Coord->GetXY());
    };

    //! Returns the gp_Pnt2d
    gp_Pnt2d xgp_Pnt2d::GetPnt2d() {
        return *NativeHandle;
    };

    //! Returns the coordinate of range Index :
    //! Index = 1 => X is returned
    //! Index = 2 => Y is returned
    //! Raises OutOfRange if Index != {1, 2}.
    Standard_Real xgp_Pnt2d::Coord(Standard_Integer Index) {
        return NativeHandle->Coord(Index);
    };

    //! For this point returns its two coordinates as a number pair.
    void xgp_Pnt2d::Coord(Standard_Real Xp, Standard_Real Yp) {
        return NativeHandle->SetCoord(Xp, Yp);
    };

    //! For this point, returns its X  coordinate.
    Standard_Real xgp_Pnt2d::X() {
        return NativeHandle->X();
    };

    //! For this point, returns its Y coordinate.
    Standard_Real xgp_Pnt2d::Y() {
        return NativeHandle->Y();
    };

    //! For this point, returns its two coordinates as a number pair.
    xgp_XY^ xgp_Pnt2d::XY() {
        gp_XY* temp = new gp_XY(NativeHandle->XY());
        return gcnew xgp_XY(temp);
    };

    //! For this point, returns its two coordinates as a number pair.
    xgp_XY^ xgp_Pnt2d::Coord() {
        gp_XY* temp = new gp_XY(NativeHandle->Coord());
        return gcnew xgp_XY(temp);
    };


    //! Returns the coordinates of this point.
    //! Note: This syntax allows direct modification of the returned value.
    xgp_XY^ xgp_Pnt2d::ChangeCoord() {
        gp_XY* temp = new gp_XY(NativeHandle->ChangeCoord());
        return gcnew xgp_XY(temp);
    };

    //! Comparison
    //! Returns True if the distance between the two
    //! points is lower or equal to LinearTolerance.
    Standard_Boolean xgp_Pnt2d::IsEqual(xgp_Pnt2d^ Other, Standard_Real LinearTolerance) {
        return NativeHandle->IsEqual(Other->GetPnt2d(), LinearTolerance);
    };

    //! Computes the distance between two points.
    Standard_Real xgp_Pnt2d::Distance(xgp_Pnt2d^ Other) {
        return NativeHandle->Distance(Other->GetPnt2d());
    };

    //! Computes the square distance between two points.
    Standard_Real xgp_Pnt2d::SquareDistance(xgp_Pnt2d^ Other) {
        return NativeHandle->SquareDistance(Other->GetPnt2d());
    };


    //! Performs the symmetrical transformation of a point
    //! with respect to the point P which is the center of
    //! the  symmetry.
    void xgp_Pnt2d::Mirror(xgp_Pnt2d^ P) {
        NativeHandle->Mirror(P->GetPnt2d());
    };


    //! Performs the symmetrical transformation of a point
    //! with respect to an axis placement which is the axis
    xgp_Pnt2d^ xgp_Pnt2d::Mirrored(xgp_Pnt2d^ P) {
        return gcnew xgp_Pnt2d(NativeHandle->Mirrored(P->GetPnt2d()));
    };

    void xgp_Pnt2d::Mirror(xgp_Ax2d^ A) {
        NativeHandle->Mirror(*A->GetAx2d());
    };


    //! Rotates a point. A1 is the axis of the rotation.
    //! Ang is the angular value of the rotation in radians.
    xgp_Pnt2d^ xgp_Pnt2d::Mirrored(xgp_Ax2d^ A) {
        return gcnew xgp_Pnt2d(NativeHandle->Mirrored(*A->GetAx2d()));
    };

    void xgp_Pnt2d::Rotate(xgp_Pnt2d^ P, Standard_Real Ang) {
        NativeHandle->Rotate(P->GetPnt2d(), Ang);
    };

    //! Scales a point. S is the scaling value.
    xgp_Pnt2d^ xgp_Pnt2d::Rotated(xgp_Pnt2d^ P, Standard_Real Ang) {
        return gcnew xgp_Pnt2d(NativeHandle->Rotated(P->GetPnt2d(), Ang));
    };

    void xgp_Pnt2d::Scale(xgp_Pnt2d^ P, Standard_Real S) {
        NativeHandle->Scale(P->GetPnt2d(), S);
    };

    //! Transforms a point with the transsformation T.
    xgp_Pnt2d^ xgp_Pnt2d::Scaled(xgp_Pnt2d^ P, Standard_Real S) {
        return gcnew xgp_Pnt2d(NativeHandle->Scaled(P->GetPnt2d(), S));
    };

    void xgp_Pnt2d::Transform(xgp_Trsf2d^ T) {
        NativeHandle->Transform(T->GetTrsf2d());
    };


    //! Translates a point in the direction of the vector V.
    //! The magnitude of the translation is the vector's magnitude.
    xgp_Pnt2d^ xgp_Pnt2d::Transformed(xgp_Trsf2d^ T) {
        return gcnew xgp_Pnt2d(NativeHandle->Transformed(T->GetTrsf2d()));
    };

    void xgp_Pnt2d::Translate(xgp_Vec2d^ V) {
        NativeHandle->Translate(V->GetVec2d());
    };


    //! Translates a point from the point P1 to the point P2.
    xgp_Pnt2d^ xgp_Pnt2d::Translated(xgp_Vec2d^ V) {
        return gcnew xgp_Pnt2d(NativeHandle->Translated(V->GetVec2d()));
    };

    void xgp_Pnt2d::Translate(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2) {
        NativeHandle->Translate(P1->GetPnt2d(), P2->GetPnt2d());
    };

    xgp_Pnt2d^ xgp_Pnt2d::Translated(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2) {
        return gcnew xgp_Pnt2d(NativeHandle->Translated(P1->GetPnt2d(), P2->GetPnt2d()));
    };
};
