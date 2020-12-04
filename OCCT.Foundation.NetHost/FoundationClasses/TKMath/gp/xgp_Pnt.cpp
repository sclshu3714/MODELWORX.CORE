#include <xgp_Pnt.h>

namespace TKMath
{
    //! Creates a point with zero coordinates.
    xgp_Pnt::xgp_Pnt(void) {
        NativeHandle = new gp_Pnt();
    };

    //! Creates a point from a XYZ object.
    xgp_Pnt::xgp_Pnt(xgp_XYZ^ Coord) {
        NativeHandle = new gp_Pnt(*Coord->GetXYZ());
    };

    /// <summary>
    /// 指针映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Pnt::xgp_Pnt(gp_Pnt* pos) {
        NativeHandle = new gp_Pnt(*pos);
    };

    //! Creates a  point with its 3 cartesian's coordinates : Xp, Yp, Zp.
    xgp_Pnt::xgp_Pnt(Standard_Real Xp, Standard_Real Yp, Standard_Real Zp) {
        NativeHandle = new gp_Pnt(Xp, Yp, Zp);
    };

    //释放
    xgp_Pnt::~xgp_Pnt() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };
    //释放
    xgp_Pnt::!xgp_Pnt() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };

    //! Changes the coordinate of range Index :
    //! Index = 1 => X is modified
    //! Index = 2 => Y is modified
    //! Index = 3 => Z is modified
    //! Raised if Index != {1, 2, 3}.
    void xgp_Pnt::SetCoord(Standard_Integer Index, Standard_Real Xi) {
        NativeHandle->SetCoord(Index, Xi);
    };

    //! For this point, assigns  the values Xp, Yp and Zp to its three coordinates.
    void xgp_Pnt::SetCoord(Standard_Real Xp, Standard_Real Yp, Standard_Real Zp) {
        NativeHandle->SetCoord(Xp, Yp, Zp);
    };

    //! Assigns the given value to the X coordinate of this point.
    void xgp_Pnt::SetX(Standard_Real X) {
        NativeHandle->SetX(X);
    };

    //! Assigns the given value to the Y coordinate of this point.
    void xgp_Pnt::SetY(Standard_Real Y) {
        NativeHandle->SetY(Y);
    };

    //! Assigns the given value to the Z coordinate of this point.
    void xgp_Pnt::SetZ(Standard_Real Z) {
        NativeHandle->SetZ(Z);
    };

    //! Assigns the three coordinates of Coord to this point.
    void xgp_Pnt::SetXYZ(xgp_XYZ^ Coord) {
        NativeHandle->SetXYZ(*Coord->GetXYZ());
    };

    //! 获取
    gp_Pnt* xgp_Pnt::GetPnt() {
        return NativeHandle;
    };

    //! Returns the coordinate of corresponding to the value of  Index :
    //! Index = 1 => X is returned
    //! Index = 2 => Y is returned
    //! Index = 3 => Z is returned
    //! Raises OutOfRange if Index != {1, 2, 3}.
    //! Raised if Index != {1, 2, 3}.
    Standard_Real xgp_Pnt::Coord(Standard_Integer Index) {
        return NativeHandle->Coord(Index);
    };

    //! For this point gives its three coordinates Xp, Yp and Zp.
    void xgp_Pnt::Coord(Standard_Real Xp, Standard_Real Yp, Standard_Real Zp) {
        return NativeHandle->Coord(Xp, Yp, Zp);
    };

    //! For this point, returns its X coordinate.
    Standard_Real xgp_Pnt::X() {
        return NativeHandle->X();
    };

    //! For this point, returns its Y coordinate.
    Standard_Real xgp_Pnt::Y() {
        return NativeHandle->Y();
    };

    //! For this point, returns its Z coordinate.
    Standard_Real xgp_Pnt::Z() {
        return NativeHandle->Z();
    };

    //! For this point, returns its three coordinates as a XYZ object.
    xgp_XYZ^ xgp_Pnt::XYZ() {
        gp_XYZ* aXYZ = new gp_XYZ(NativeHandle->XYZ());
        return gcnew xgp_XYZ(aXYZ);
    };

    //! For this point, returns its three coordinates as a XYZ object.
    xgp_XYZ^ xgp_Pnt::Coord() {
        gp_XYZ* aXYZ = new gp_XYZ(NativeHandle->Coord());
        return gcnew xgp_XYZ(aXYZ);
    };


    //! Returns the coordinates of this point.
    //! Note: This syntax allows direct modification of the returned value.
    xgp_XYZ^ xgp_Pnt::ChangeCoord() {
        gp_XYZ* aXYZ = new gp_XYZ(NativeHandle->ChangeCoord());
        return gcnew xgp_XYZ(aXYZ);
    };

    //! Assigns the result of the following expression to this point
    //! (Alpha*this + Beta*P) / (Alpha + Beta)
    void xgp_Pnt::BaryCenter(Standard_Real Alpha, xgp_Pnt^ P, Standard_Real Beta) {
        NativeHandle->BaryCenter(Alpha, *P->GetPnt(), Beta);
    };

    //! Comparison
    //! Returns True if the distance between the two points is
    //! lower or equal to LinearTolerance.
    Standard_Boolean xgp_Pnt::IsEqual(xgp_Pnt^ Other, Standard_Real LinearTolerance) {
        return NativeHandle->IsEqual(*Other->GetPnt(), LinearTolerance);
    };

    //! Computes the distance between two points.
    Standard_Real xgp_Pnt::Distance(xgp_Pnt^ Other) {
        return NativeHandle->Distance(*Other->GetPnt());
    };

    //! Computes the square distance between two points.
    Standard_Real xgp_Pnt::SquareDistance(xgp_Pnt^ Other) {
        return NativeHandle->SquareDistance(*Other->GetPnt());
    };


    //! Performs the symmetrical transformation of a point
    //! with respect to the point P which is the center of
    //! the  symmetry.
    void xgp_Pnt::Mirror(xgp_Pnt^ P) {
        NativeHandle->Mirror(*P->GetPnt());
    };


    //! Performs the symmetrical transformation of a point
    //! with respect to an axis placement which is the axis
    //! of the symmetry.
    xgp_Pnt^ xgp_Pnt::Mirrored(xgp_Pnt^ P) {
        gp_Pnt* temp = new gp_Pnt(NativeHandle->Mirrored(*P->GetPnt()));
        return gcnew xgp_Pnt(temp);
    };

    void xgp_Pnt::Mirror(xgp_Ax1^ A1) {
        NativeHandle->Mirror(*A1->GetAx1());
    };


    //! Performs the symmetrical transformation of a point
    //! with respect to a plane. The axis placement A2 locates
    //! the plane of the symmetry : (Location, XDirection, YDirection).
    xgp_Pnt^ xgp_Pnt::Mirrored(xgp_Ax1^ A1) {
        gp_Pnt* temp = new gp_Pnt(NativeHandle->Mirrored(*A1->GetAx1()));
        return gcnew xgp_Pnt(temp);
    };

    void xgp_Pnt::Mirror(xgp_Ax2^ A2) {
        NativeHandle->Mirror(*A2->GetAx2());
    };


    //! Rotates a point. A1 is the axis of the rotation.
    //! Ang is the angular value of the rotation in radians.
    xgp_Pnt^ xgp_Pnt::Mirrored(xgp_Ax2^ A2) {
        gp_Pnt* temp = new gp_Pnt(NativeHandle->Mirrored(*A2->GetAx2()));
        return gcnew xgp_Pnt(temp);
    };

    void xgp_Pnt::Rotate(xgp_Ax1^ A1, Standard_Real Ang) {
        NativeHandle->Rotate(*A1->GetAx1(), Ang);
    };

    //! Scales a point. S is the scaling value.
    xgp_Pnt^ xgp_Pnt::Rotated(xgp_Ax1^ A1, Standard_Real Ang) {
        gp_Pnt* temp = new gp_Pnt(NativeHandle->Rotated(*A1->GetAx1(), Ang));
        return gcnew xgp_Pnt(temp);
    };

    void xgp_Pnt::Scale(xgp_Pnt^ P, Standard_Real S) {
        NativeHandle->Scale(*P->GetPnt(), S);
    };

    //! Transforms a point with the transformation T.
    xgp_Pnt^ xgp_Pnt::Scaled(xgp_Pnt^ P, Standard_Real S) {
        gp_Pnt* temp = new gp_Pnt(NativeHandle->Scaled(*P->GetPnt(), S));
        return gcnew xgp_Pnt(temp);
    };

    void xgp_Pnt::Transform(xgp_Trsf^ T) {
        NativeHandle->Transform(T->GetTrsf());
    };


    //! Translates a point in the direction of the vector V.
    //! The magnitude of the translation is the vector's magnitude.
    xgp_Pnt^ xgp_Pnt::Transformed(xgp_Trsf^ T) {
        gp_Pnt* temp = new gp_Pnt(NativeHandle->Transformed(T->GetTrsf()));
        return gcnew xgp_Pnt(temp);
    };

    void xgp_Pnt::Translate(xgp_Vec^ V) {
        NativeHandle->Translate(V->GetVec());
    };


    //! Translates a point from the point P1 to the point P2.
    xgp_Pnt^ xgp_Pnt::Translated(xgp_Vec^ V) {
        gp_Pnt* temp = new gp_Pnt(NativeHandle->Translated(V->GetVec()));
        return gcnew xgp_Pnt(temp);
    };

    void xgp_Pnt::Translate(xgp_Pnt^ P1, xgp_Pnt^ P2) {
        NativeHandle->Translate(*P1->GetPnt(), *P2->GetPnt());
    };

    xgp_Pnt^ xgp_Pnt::Translated(xgp_Pnt^ P1, xgp_Pnt^ P2) {
        gp_Pnt* temp = new gp_Pnt(NativeHandle->Translated(*P1->GetPnt(), *P2->GetPnt()));
        return gcnew xgp_Pnt(temp);
    };
};
