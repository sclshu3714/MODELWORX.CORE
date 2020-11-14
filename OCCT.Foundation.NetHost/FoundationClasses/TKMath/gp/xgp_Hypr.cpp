#include <xgp_Hypr.h>

namespace TKMath
{
    //! Creates of an indefinite hyperbola.
    xgp_Hypr::xgp_Hypr() {
        NativeHandle = new gp_Hypr();
    };

    /// <summary>
    /// 指针映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Hypr::xgp_Hypr(gp_Hypr* pos) {
        NativeHandle = new gp_Hypr(*pos);
    };
    /// <summary>
    ///  映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Hypr::xgp_Hypr(gp_Hypr pos) {
        NativeHandle = new gp_Hypr(pos);
    };

    //! Creates a hyperbola with radii MajorRadius and
    //! MinorRadius, positioned in the space by the
    //! coordinate system A2 such that:
    //! -   the origin of A2 is the center of the hyperbola,
    //! -   the "X Direction" of A2 defines the major axis of
    //! the hyperbola, that is, the major radius
    //! MajorRadius is measured along this axis, and
    //! -   the "Y Direction" of A2 defines the minor axis of
    //! the hyperbola, that is, the minor radius
    //! MinorRadius is measured along this axis.
    //! Note: Thisnamespace TKMath  {  public ref class does not prevent the creation of a
    //! hyperbola where:
    //! -   MajorAxis is equal to MinorAxis, or
    //! -   MajorAxis is less than MinorAxis.
    //! Exceptions
    //! Standard_ConstructionError if MajorAxis or MinorAxis is negative.
    //! Raises ConstructionError if MajorRadius < 0.0 or MinorRadius < 0.0
    //! Raised if MajorRadius < 0.0 or MinorRadius < 0.0
    xgp_Hypr::xgp_Hypr(xgp_Ax2^ A2, Standard_Real^ MajorRadius, Standard_Real^ MinorRadius) {
        NativeHandle = new gp_Hypr(A2->GetAx2(), *MajorRadius, *MinorRadius);
    };


    //释放
    xgp_Hypr::~xgp_Hypr() {
        if (NativeHandle != NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };
    //释放
    xgp_Hypr::!xgp_Hypr() {
        if (NativeHandle != NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };

    //! gp_Hypr
    gp_Hypr xgp_Hypr::GetHypr() {
        return *NativeHandle;
    };

    //! Modifies this hyperbola, by redefining its local coordinate
    //! system so that:
    //! -   its origin and "main Direction" become those of the
    //! axis A1 (the "X Direction" and "Y Direction" are then
    //! recomputed in the same way as for any xgp_Ax2).
    //! Raises ConstructionError if the direction of A1 is parallel to the direction of
    //! the "XAxis" of the hyperbola.
    void xgp_Hypr::SetAxis(xgp_Ax1^ A1) {
        NativeHandle->SetAxis(A1->GetAx1());
    };

    //! Modifies this hyperbola, by redefining its local coordinate
    //! system so that its origin becomes P.
    void xgp_Hypr::SetLocation(xgp_Pnt^ P) {
        NativeHandle->SetLocation(P->GetPnt());
    };


    //! Modifies the major  radius of this hyperbola.
    //! Exceptions
    //! Standard_ConstructionError if MajorRadius is negative.
    void xgp_Hypr::SetMajorRadius(Standard_Real^ MajorRadius) {
        NativeHandle->SetMajorRadius(*MajorRadius);
    };


    //! Modifies the minor  radius of this hyperbola.
    //! Exceptions
    //! Standard_ConstructionError if MinorRadius is negative.
    void xgp_Hypr::SetMinorRadius(Standard_Real^ MinorRadius) {
        NativeHandle->SetMinorRadius(*MinorRadius);
    };

    //! Modifies this hyperbola, by redefining its local coordinate
    //! system so that it becomes A2.
    void xgp_Hypr::SetPosition(xgp_Ax2^ A2) {
        NativeHandle->SetPosition(A2->GetAx2());
    };


    //! In the local coordinate system of the hyperbola the equation of
    //! the hyperbola is (X*X)/(A*A) - (Y*Y)/(B*B) = 1.0 and the
    //! equation of the first asymptote is Y = (B/A)*X
    //! where A is the major radius and B is the minor radius. Raises ConstructionError if MajorRadius = 0.0
    xgp_Ax1^ xgp_Hypr::Asymptote1() {
        return gcnew xgp_Ax1(NativeHandle->Asymptote1());
    };


    //! In the local coordinate system of the hyperbola the equation of
    //! the hyperbola is (X*X)/(A*A) - (Y*Y)/(B*B) = 1.0 and the
    //! equation of the first asymptote is Y = -(B/A)*X.
    //! where A is the major radius and B is the minor radius. Raises ConstructionError if MajorRadius = 0.0
    xgp_Ax1^ xgp_Hypr::Asymptote2() {
        return gcnew xgp_Ax1(NativeHandle->Asymptote2());
    };

    //! Returns the axis passing through the center,
    //! and normal to the plane of this hyperbola.
    xgp_Ax1^ xgp_Hypr::Axis() {
        return gcnew xgp_Ax1(NativeHandle->Axis());
    };


    //! Computes the branch of hyperbola which is on the positive side of the
    //! "YAxis" of <me>.
    xgp_Hypr^ xgp_Hypr::ConjugateBranch1() {
        return gcnew xgp_Hypr(NativeHandle->ConjugateBranch1());
    };


    //! Computes the branch of hyperbola which is on the negative side of the
    //! "YAxis" of <me>.
    xgp_Hypr^ xgp_Hypr::ConjugateBranch2() {
        return gcnew xgp_Hypr(NativeHandle->ConjugateBranch2());
    };


    //! This directrix is the line normal to the XAxis of the hyperbola
    //! in the local plane (Z = 0) at a distance d = MajorRadius / e
    //! from the center of the hyperbola, where e is the eccentricity of
    //! the hyperbola.
    //! This line is parallel to the "YAxis". The intersection point
    //! between the directrix1 and the "XAxis" is the "Location" point
    //! of the directrix1. This point is on the positive side of the
    //! "XAxis".
    xgp_Ax1^ xgp_Hypr::Directrix1() {
        return gcnew xgp_Ax1(NativeHandle->Directrix1());
    };


    //! This line is obtained by the symmetrical transformation
    //! of "Directrix1" with respect to the "YAxis" of the hyperbola.
    xgp_Ax1^ xgp_Hypr::Directrix2() {
        return gcnew xgp_Ax1(NativeHandle->Directrix2());
    };


    //! Returns the excentricity of the hyperbola (e > 1).
    //! If f is the distance between the location of the hyperbola
    //! and the Focus1 then the eccentricity e = f / MajorRadius. Raises DomainError if MajorRadius = 0.0
    Standard_Real^ xgp_Hypr::Eccentricity() {
        return NativeHandle->Eccentricity();
    };


    //! Computes the focal distance. It is the distance between the
    //! the two focus of the hyperbola.
    Standard_Real^ xgp_Hypr::Focal() {
        return NativeHandle->Focal();
    };


    //! Returns the first focus of the hyperbola. This focus is on the
    //! positive side of the "XAxis" of the hyperbola.
    xgp_Pnt^ xgp_Hypr::Focus1() {
        return gcnew xgp_Pnt(NativeHandle->Focus1());
    };


    //! Returns the second focus of the hyperbola. This focus is on the
    //! negative side of the "XAxis" of the hyperbola.
    xgp_Pnt^ xgp_Hypr::Focus2() {
        return gcnew xgp_Pnt(NativeHandle->Focus2());
    };


    //! Returns  the location point of the hyperbola. It is the
    //! intersection point between the "XAxis" and the "YAxis".
    xgp_Pnt^ xgp_Hypr::Location() {
        return gcnew xgp_Pnt(NativeHandle->Location());
    };


    //! Returns the major radius of the hyperbola. It is the radius
    //! on the "XAxis" of the hyperbola.
    Standard_Real^ xgp_Hypr::MajorRadius() {
        return NativeHandle->MajorRadius();
    };


    //! Returns the minor radius of the hyperbola. It is the radius
    //! on the "YAxis" of the hyperbola.
    Standard_Real^ xgp_Hypr::MinorRadius() {
        return NativeHandle->MinorRadius();
    };


    //! Returns the branch of hyperbola obtained by doing the
    //! symmetrical transformation of <me> with respect to the
    //! "YAxis"  of <me>.
    xgp_Hypr^ xgp_Hypr::OtherBranch() {
        return gcnew xgp_Hypr(NativeHandle->OtherBranch());
    };


    //! Returns p = (e * e - 1) * MajorRadius where e is the
    //! eccentricity of the hyperbola.
    //! Raises DomainError if MajorRadius = 0.0
    Standard_Real^ xgp_Hypr::Parameter() {
        return NativeHandle->Parameter();
    };

    //! Returns the coordinate system of the hyperbola.
    xgp_Ax2^ xgp_Hypr::Position() {
        return gcnew xgp_Ax2(NativeHandle->Position());
    };

    //! Computes an axis, whose
    //! -   the origin is the center of this hyperbola, and
    //! -   the unit vector is the "X Direction"
    //! of the local coordinate system of this hyperbola.
    //! These axes are, the major axis (the "X
    //! Axis") and  of this hyperboReturns the "XAxis" of the hyperbola.
    xgp_Ax1^ xgp_Hypr::XAxis() {
        return gcnew xgp_Ax1(NativeHandle->XAxis());
    };

    //! Computes an axis, whose
    //! -   the origin is the center of this hyperbola, and
    //! -   the unit vector is the "Y Direction"
    //! of the local coordinate system of this hyperbola.
    //! These axes are the minor axis (the "Y Axis") of this hyperbola
    xgp_Ax1^ xgp_Hypr::YAxis() {
        return gcnew xgp_Ax1(NativeHandle->YAxis());
    };

    void xgp_Hypr::Mirror(xgp_Pnt^ P) {
        NativeHandle->Mirror(P->GetPnt());
    };


    //! Performs the symmetrical transformation of an hyperbola with
    //! respect  to the point P which is the center of the symmetry.
    xgp_Hypr^ xgp_Hypr::Mirrored(xgp_Pnt^ P) {
        return gcnew xgp_Hypr(NativeHandle->Mirrored(P->GetPnt()));
    };

    void xgp_Hypr::Mirror(xgp_Ax1^ A1) {
        NativeHandle->Mirror(A1->GetAx1());
    };


    //! Performs the symmetrical transformation of an hyperbola with
    //! respect to an axis placement which is the axis of the symmetry.
    xgp_Hypr^ xgp_Hypr::Mirrored(xgp_Ax1^ A1) {
        return gcnew xgp_Hypr(NativeHandle->Mirrored(A1->GetAx1()));
    };

    void xgp_Hypr::Mirror(xgp_Ax2^ A2) {
        NativeHandle->Mirror(A2->GetAx2());
    };


    //! Performs the symmetrical transformation of an hyperbola with
    //! respect to a plane. The axis placement A2 locates the plane
    //! of the symmetry (Location, XDirection, YDirection).
    xgp_Hypr^ xgp_Hypr::Mirrored(xgp_Ax2^ A2) {
        return gcnew xgp_Hypr(NativeHandle->Mirrored(A2->GetAx2()));
    };

    void xgp_Hypr::Rotate(xgp_Ax1^ A1, Standard_Real^ Ang) {
        NativeHandle->Rotate(A1->GetAx1(), *Ang);
    };


    //! Rotates an hyperbola. A1 is the axis of the rotation.
    //! Ang is the angular value of the rotation in radians.
    xgp_Hypr^ xgp_Hypr::Rotated(xgp_Ax1^ A1, Standard_Real^ Ang) {
        return gcnew xgp_Hypr(NativeHandle->Rotated(A1->GetAx1(), *Ang));
    };

    void xgp_Hypr::Scale(xgp_Pnt^ P, Standard_Real^ S) {
        NativeHandle->Scale(P->GetPnt(), *S);
    };


    //! Scales an hyperbola. S is the scaling value.
    xgp_Hypr^ xgp_Hypr::Scaled(xgp_Pnt^ P, Standard_Real^ S) {
        return gcnew xgp_Hypr(NativeHandle->Scaled(P->GetPnt(), *S));
    };

    void xgp_Hypr::Transform(xgp_Trsf^ T) {
        NativeHandle->Transform(T->GetTrsf());
    };


    //! Transforms an hyperbola with the transformation T from
    //!namespace TKMath  {  public ref class Trsf.
    xgp_Hypr^ xgp_Hypr::Transformed(xgp_Trsf^ T) {
        return gcnew xgp_Hypr(NativeHandle->Transformed(T->GetTrsf()));
    };

    void xgp_Hypr::Translate(xgp_Vec^ V) {
        NativeHandle->Translate(V->GetVec());
    };


    //! Translates an hyperbola in the direction of the vector V.
    //! The magnitude of the translation is the vector's magnitude.
    xgp_Hypr^ xgp_Hypr::Translated(xgp_Vec^ V) {
        return gcnew xgp_Hypr(NativeHandle->Translated(V->GetVec()));
    };

    void xgp_Hypr::Translate(xgp_Pnt^ P1, xgp_Pnt^ P2) {
        NativeHandle->Translate(P1->GetPnt(), P2->GetPnt());
    };


    //! Translates an hyperbola from the point P1 to the point P2.
    xgp_Hypr^ xgp_Hypr::Translated(xgp_Pnt^ P1, xgp_Pnt^ P2) {
        return gcnew xgp_Hypr(NativeHandle->Translated(P1->GetPnt(), P2->GetPnt()));
    };
};
