#include <xgp_Torus.h>

namespace TKMath
{
    //! creates an indefinite Torus.
    xgp_Torus::xgp_Torus(void) {
        NativeHandle = new gp_Torus();
    };

    /// <summary>
    /// 指针映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Torus::xgp_Torus(gp_Torus* pos) {
        NativeHandle = new gp_Torus(*pos);
    };
    /// <summary>
    ///  映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Torus::xgp_Torus(gp_Torus pos) {
        NativeHandle = new gp_Torus(pos);
    };

    //! a torus centered on the origin of coordinate system
    //! A3, with major radius MajorRadius and minor radius
    //! MinorRadius, and with the reference plane defined
    //! by the origin, the "X Direction" and the "Y Direction" of A3.
    //! Warnings :
    //! It is not forbidden to create a torus with
    //! MajorRadius = MinorRadius = 0.0
    //! Raises ConstructionError if MinorRadius < 0.0 or if MajorRadius < 0.0
    xgp_Torus::xgp_Torus(xgp_Ax3^ A3, Standard_Real MajorRadius, Standard_Real MinorRadius) {
        NativeHandle = new gp_Torus(A3->GetAx3(), MajorRadius, MinorRadius);
    };

    //释放
    xgp_Torus::~xgp_Torus() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };
    //释放
    xgp_Torus::!xgp_Torus() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };

    //! Modifies this torus, by redefining its local coordinate
    //! system so that:
    //! -   its origin and "main Direction" become those of the
    //! axis A1 (the "X Direction" and "Y Direction" are then recomputed).
    //! Raises ConstructionError if the direction of A1 is parallel to the "XDirection"
    //! of the coordinate system of the toroidal surface.
    void xgp_Torus::SetAxis(xgp_Ax1^ A1) {
        NativeHandle->SetAxis(A1->GetAx1());
    };

    //! Changes the location of the torus.
    void xgp_Torus::SetLocation(xgp_Pnt^ Loc) {
        NativeHandle->SetLocation(Loc->GetPnt());
    };

    //! Assigns value to the major radius  of this torus.
    //! Raises ConstructionError if MajorRadius - MinorRadius <= Resolution()
    void xgp_Torus::SetMajorRadius(Standard_Real MajorRadius) {
        NativeHandle->SetMajorRadius(MajorRadius);
    };

    //! Assigns value to the  minor radius of this torus.
    //! Raises ConstructionError if MinorRadius < 0.0 or if
    //! MajorRadius - MinorRadius <= Resolution from gp.
    void xgp_Torus::SetMinorRadius(Standard_Real MinorRadius) {
        NativeHandle->SetMinorRadius(MinorRadius);
    };

    //! Changes the local coordinate system of the surface.
    void xgp_Torus::SetPosition(xgp_Ax3^ A3) {
        NativeHandle->SetPosition(A3->GetAx3());
    };

    //! returns the gp_Torus
    gp_Torus xgp_Torus::GetTorus() {
        return *NativeHandle;
    };

    //! Computes the area of the torus.
    Standard_Real xgp_Torus::Area() {
        return NativeHandle->Area();
    };

    //! Reverses the   U   parametrization of   the  torus
    //! reversing the YAxis.
    void xgp_Torus::UReverse() {
        NativeHandle->UReverse();
    };

    //! Reverses the   V   parametrization of   the  torus
    //! reversing the ZAxis.
    void xgp_Torus::VReverse() {
        NativeHandle->VReverse();
    };

    //! returns true if the Ax3, the local coordinate system of this torus, is right handed.
    Standard_Boolean xgp_Torus::Direct() {
        return NativeHandle->Direct();
    };

    //! returns the symmetry axis of the torus.
    xgp_Ax1^ xgp_Torus::Axis() {
        return gcnew xgp_Ax1(NativeHandle->Axis());
    };

    //! Computes the coefficients of the implicit equation of the surface
    //! in the absolute Cartesian coordinate system:
    //!     Coef(1) * X^4 + Coef(2) * Y^4 + Coef(3) * Z^4 +
    //!     Coef(4) * X^3 * Y + Coef(5) * X^3 * Z + Coef(6) * Y^3 * X +
    //!     Coef(7) * Y^3 * Z + Coef(8) * Z^3 * X + Coef(9) * Z^3 * Y +
    //!     Coef(10) * X^2 * Y^2 + Coef(11) * X^2 * Z^2 +
    //!     Coef(12) * Y^2 * Z^2 + Coef(13) * X^2 * Y * Z +
    //!     Coef(14) * X * Y^2 * Z + Coef(15) * X * Y * Z^2 +
    //!     Coef(16) * X^3 + Coef(17) * Y^3 + Coef(18) * Z^3 + 
    //!     Coef(19) * X^2 * Y + Coef(20) * X^2 * Z + Coef(21) * Y^2 * X +
    //!     Coef(22) * Y^2 * Z + Coef(23) * Z^2 * X + Coef(24) * Z^2 * Y +
    //!     Coef(25) * X * Y * Z +
    //!     Coef(26) * X^2 + Coef(27) * Y^2 + Coef(28) * Z^2 +
    //!     Coef(29) * X * Y + Coef(30) * X * Z + Coef(31) * Y * Z +
    //!     Coef(32) * X + Coef(33) * Y + Coef(34) *  Z + 
    //!     Coef(35) = 0.0
    //! Raises DimensionError if the length of Coef is lower than 35.
    void xgp_Torus::Coefficients(TColStd_Array1OfReal Coef) {
        NativeHandle->Coefficients(Coef);
    };

    //! Returns the Torus's location.
    xgp_Pnt^ xgp_Torus::Location() {
        return gcnew xgp_Pnt(NativeHandle->Location());
    };

    //! Returns the local coordinates system of the torus.
    xgp_Ax3^ xgp_Torus::Position() {
        return gcnew xgp_Ax3(NativeHandle->Position());
    };

    //! returns the major radius of the torus.
    Standard_Real xgp_Torus::MajorRadius() {
        return NativeHandle->MajorRadius();
    };

    //! returns the minor radius of the torus.
    Standard_Real xgp_Torus::MinorRadius() {
        return NativeHandle->MinorRadius();
    };

    //! Computes the volume of the torus.
    Standard_Real xgp_Torus::Volume() {
        return NativeHandle->Volume();
    };

    //! returns the axis X of the torus.
    xgp_Ax1^ xgp_Torus::XAxis() {
        return gcnew xgp_Ax1(NativeHandle->XAxis());
    };

    //! returns the axis Y of the torus.
    xgp_Ax1^ xgp_Torus::YAxis() {
        return gcnew xgp_Ax1(NativeHandle->YAxis());
    };

    void xgp_Torus::Mirror(xgp_Pnt^ P) {
        NativeHandle->Mirror(P->GetPnt());
    };


    //! Performs the symmetrical transformation of a torus
    //! with respect to the point P which is the center of the
    //! symmetry.
    xgp_Torus^ xgp_Torus::Mirrored(xgp_Pnt^ P) {
        return gcnew xgp_Torus(NativeHandle->Mirrored(P->GetPnt()));
    };

    void xgp_Torus::Mirror(xgp_Ax1^ A1) {
        NativeHandle->Mirror(A1->GetAx1());
    };


    //! Performs the symmetrical transformation of a torus with
    //! respect to an axis placement which is the axis of the
    //! symmetry.
    xgp_Torus^ xgp_Torus::Mirrored(xgp_Ax1^ A1) {
        return gcnew xgp_Torus(NativeHandle->Mirrored(A1->GetAx1()));
    };

    void xgp_Torus::Mirror(xgp_Ax2^ A2) {
        NativeHandle->Mirror(A2->GetAx2());
    };


    //! Performs the symmetrical transformation of a torus with respect
    //! to a plane. The axis placement A2 locates the plane of the
    //! of the symmetry : (Location, XDirection, YDirection).
    xgp_Torus^ xgp_Torus::Mirrored(xgp_Ax2^ A2) {
        return gcnew xgp_Torus(NativeHandle->Mirrored(A2->GetAx2()));
    };

    void xgp_Torus::Rotate(xgp_Ax1^ A1, Standard_Real Ang) {
        NativeHandle->Rotate(A1->GetAx1(), Ang);
    };


    //! Rotates a torus. A1 is the axis of the rotation.
    //! Ang is the angular value of the rotation in radians.
    xgp_Torus^ xgp_Torus::Rotated(xgp_Ax1^ A1, Standard_Real Ang) {
        return gcnew xgp_Torus(NativeHandle->Rotated(A1->GetAx1(), Ang));
    };

    void xgp_Torus::Scale(xgp_Pnt^ P, Standard_Real S) {
        NativeHandle->Scale(P->GetPnt(), S);
    };


    //! Scales a torus. S is the scaling value.
    //! The absolute value of S is used to scale the torus
    xgp_Torus^ xgp_Torus::Scaled(xgp_Pnt^ P, Standard_Real S) {
        return gcnew xgp_Torus(NativeHandle->Scaled(P->GetPnt(), S));
    };

    void xgp_Torus::Transform(xgp_Trsf^ T) {
        NativeHandle->Transform(T->GetTrsf());
    };


    //! Transforms a torus with the transformation T fromnamespace TKMath  {  public ref class Trsf.
    xgp_Torus^ xgp_Torus::Transformed(xgp_Trsf^ T) {
        return gcnew xgp_Torus(NativeHandle->Transformed(T->GetTrsf()));
    };

    void xgp_Torus::Translate(xgp_Vec^ V) {
        NativeHandle->Translate(V->GetVec());
    };


    //! Translates a torus in the direction of the vector V.
    //! The magnitude of the translation is the vector's magnitude.
    xgp_Torus^ xgp_Torus::Translated(xgp_Vec^ V) {
        return gcnew xgp_Torus(NativeHandle->Translated(V->GetVec()));
    };

    void xgp_Torus::Translate(xgp_Pnt^ P1, xgp_Pnt^ P2) {
        NativeHandle->Translate(P1->GetPnt(), P2->GetPnt());
    };


    //! Translates a torus from the point P1 to the point P2.
    xgp_Torus^ xgp_Torus::Translated(xgp_Pnt^ P1, xgp_Pnt^ P2) {
        return gcnew xgp_Torus(NativeHandle->Translated(P1->GetPnt(), P2->GetPnt()));
    };
};
