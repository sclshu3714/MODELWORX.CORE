#include <xgp_Hypr2d.h>

namespace TKMath
{
    //! Creates of an indefinite hyperbola.
    xgp_Hypr2d::xgp_Hypr2d() {
        NativeHandle = new gp_Hypr2d();
    };

    /// <summary>
    /// 指针映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Hypr2d::xgp_Hypr2d(gp_Hypr2d* pos) {
        NativeHandle = new gp_Hypr2d(*pos);
    };

    //! Creates a hyperbola with radii MajorRadius and
    //! MinorRadius, centered on the origin of MajorAxis
    //! and where the unit vector of MajorAxis is the "X
    //! Direction" of the local coordinate system of the
    //! hyperbola. This coordinate system is direct if Sense
    //! is true (the default value), and indirect if Sense is false.
    //! Warnings :
    //! It is yet  possible to create an Hyperbola with
    //! MajorRadius <= MinorRadius.
    //! Raises ConstructionError if MajorRadius < 0.0 or MinorRadius < 0.0
    xgp_Hypr2d::xgp_Hypr2d(xgp_Ax2d^ MajorAxis, Standard_Real MajorRadius, Standard_Real MinorRadius, Standard_Boolean Sense) {
        NativeHandle = new gp_Hypr2d(*MajorAxis->GetAx2d(), MajorRadius, MinorRadius, Sense);
    };


    //! a hyperbola with radii MajorRadius and
    //! MinorRadius, positioned in the plane by coordinate system A where:
    //! -   the origin of A is the center of the hyperbola,
    //! -   the "X Direction" of A defines the major axis of
    //! the hyperbola, that is, the major radius
    //! MajorRadius is measured along this axis, and
    //! -   the "Y Direction" of A defines the minor axis of
    //! the hyperbola, that is, the minor radius
    //! MinorRadius is measured along this axis, and
    //! -   the orientation (direct or indirect sense) of A
    //! gives the implicit orientation of the hyperbola.
    //! Warnings :
    //! It is yet  possible to create an Hyperbola with
    //! MajorRadius <= MinorRadius.
    //! Raises ConstructionError if MajorRadius < 0.0 or MinorRadius < 0.0
    xgp_Hypr2d::xgp_Hypr2d(xgp_Ax22d^ A, Standard_Real MajorRadius, Standard_Real MinorRadius) {
        NativeHandle = new gp_Hypr2d(*A->GetAx22d(), MajorRadius, MinorRadius);
    };


    //释放
    xgp_Hypr2d::~xgp_Hypr2d() {
        if (NativeHandle != NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };
    //释放
    xgp_Hypr2d::!xgp_Hypr2d() {
        if (NativeHandle != NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };

    //!gp_Hypr2d
    gp_Hypr2d* xgp_Hypr2d::GetHypr2d() {
        return NativeHandle;
    };


    //! Modifies this hyperbola, by redefining its local
    //! coordinate system so that its origin becomes P.
    void xgp_Hypr2d::SetLocation(xgp_Pnt2d^ P) {
        NativeHandle->SetLocation(*P->GetPnt2d());
    };

    //! Modifies the major or minor radius of this hyperbola.
    //! Exceptions
    //! Standard_ConstructionError if MajorRadius or
    //! MinorRadius is negative.
    void xgp_Hypr2d::SetMajorRadius(Standard_Real MajorRadius) {
        NativeHandle->SetMajorRadius(MajorRadius);
    };

    //! Modifies the major or minor radius of this hyperbola.
    //! Exceptions
    //! Standard_ConstructionError if MajorRadius or
    //! MinorRadius is negative.
    void xgp_Hypr2d::SetMinorRadius(Standard_Real MinorRadius) {
        NativeHandle->SetMinorRadius(MinorRadius);
    };

    //! Modifies this hyperbola, by redefining its local
    //! coordinate system so that it becomes A.
    void xgp_Hypr2d::SetAxis(xgp_Ax22d^ A) {
        NativeHandle->SetAxis(*A->GetAx22d());
    };


    //! Changes the major axis of the hyperbola. The minor axis is
    //! recomputed and the location of the hyperbola too.
    void xgp_Hypr2d::SetXAxis(xgp_Ax2d^ A) {
        NativeHandle->SetXAxis(*A->GetAx2d());
    };


    //! Changes the minor axis of the hyperbola.The minor axis is
    //! recomputed and the location of the hyperbola too.
    void xgp_Hypr2d::SetYAxis(xgp_Ax2d^ A) {
        NativeHandle->SetYAxis(*A->GetAx2d());
    };


    //! In the local coordinate system of the hyperbola the equation of
    //! the hyperbola is (X*X)/(A*A) - (Y*Y)/(B*B) = 1.0 and the
    //! equation of the first asymptote is Y = (B/A)*X
    //! where A is the major radius of the hyperbola and B the minor
    //! radius of the hyperbola.
    //! Raises ConstructionError if MajorRadius = 0.0
    xgp_Ax2d^ xgp_Hypr2d::Asymptote1() {
        gp_Ax2d* temp = new gp_Ax2d(NativeHandle->Asymptote1());
        return gcnew xgp_Ax2d(temp);
    };


    //! In the local coordinate system of the hyperbola the equation of
    //! the hyperbola is (X*X)/(A*A) - (Y*Y)/(B*B) = 1.0 and the
    //! equation of the first asymptote is Y = -(B/A)*X
    //! where A is the major radius of the hyperbola and B the minor
    //! radius of the hyperbola.
    //! Raises ConstructionError if MajorRadius = 0.0
    xgp_Ax2d^ xgp_Hypr2d::Asymptote2() {
        gp_Ax2d* temp = new gp_Ax2d(NativeHandle->Asymptote2());
        return gcnew xgp_Ax2d(temp);
    };


    //! Computes the coefficients of the implicit equation of
    //! the hyperbola :
    //! A * (X**2) + B * (Y**2) + 2*C*(X*Y) + 2*D*X + 2*E*Y + F = 0.
    void xgp_Hypr2d::Coefficients(Standard_Real A, Standard_Real B, Standard_Real C, Standard_Real D, Standard_Real E, Standard_Real F) {
        NativeHandle->Coefficients(A, B, C, D, E, F);
    };


    //! Computes the branch of hyperbola which is on the positive side of the
    //! "YAxis" of <me>.
    xgp_Hypr2d^ xgp_Hypr2d::ConjugateBranch1() {
        gp_Hypr2d* temp = new gp_Hypr2d(NativeHandle->ConjugateBranch1());
        return gcnew xgp_Hypr2d(temp);
    };


    //! Computes the branch of hyperbola which is on the negative side of the
    //! "YAxis" of <me>.
    xgp_Hypr2d^ xgp_Hypr2d::ConjugateBranch2() {
        gp_Hypr2d* temp = new gp_Hypr2d(NativeHandle->ConjugateBranch2());
        return gcnew xgp_Hypr2d(temp);
    };


    //! Computes the directrix which is the line normal to the XAxis of the hyperbola
    //! in the local plane (Z = 0) at a distance d = MajorRadius / e
    //! from the center of the hyperbola, where e is the eccentricity of
    //! the hyperbola.
    //! This line is parallel to the "YAxis". The intersection point
    //! between the "Directrix1" and the "XAxis" is the "Location" point
    //! of the "Directrix1".
    //! This point is on the positive side of the "XAxis".
    xgp_Ax2d^ xgp_Hypr2d::Directrix1() {
        gp_Ax2d* temp = new gp_Ax2d(NativeHandle->Directrix1());
        return gcnew xgp_Ax2d(temp);
    };


    //! This line is obtained by the symmetrical transformation
    //! of "Directrix1" with respect to the "YAxis" of the hyperbola.
    xgp_Ax2d^ xgp_Hypr2d::Directrix2() {
        gp_Ax2d* temp = new gp_Ax2d(NativeHandle->Directrix2());
        return gcnew xgp_Ax2d(temp);
    };


    //! Returns the excentricity of the hyperbola (e > 1).
    //! If f is the distance between the location of the hyperbola
    //! and the Focus1 then the eccentricity e = f / MajorRadius. Raises DomainError if MajorRadius = 0.0.
    Standard_Real xgp_Hypr2d::Eccentricity() {
        return NativeHandle->Eccentricity();
    };


    //! Computes the focal distance. It is the distance between the
    //! "Location" of the hyperbola and "Focus1" or "Focus2".
    Standard_Real xgp_Hypr2d::Focal() {
        return NativeHandle->Focal();
    };


    //! Returns the first focus of the hyperbola. This focus is on the
    //! positive side of the "XAxis" of the hyperbola.
    xgp_Pnt2d^ xgp_Hypr2d::Focus1() {
        gp_Pnt2d* temp = new gp_Pnt2d(NativeHandle->Focus1());
        return gcnew xgp_Pnt2d(temp);
    };


    //! Returns the second focus of the hyperbola. This focus is on the
    //! negative side of the "XAxis" of the hyperbola.
    xgp_Pnt2d^ xgp_Hypr2d::Focus2() {
        gp_Pnt2d* temp = new gp_Pnt2d(NativeHandle->Focus2());
        return gcnew xgp_Pnt2d(temp);
    };


    //! Returns  the location point of the hyperbola.
    //! It is the intersection point between the "XAxis" and
    //! the "YAxis".
    xgp_Pnt2d^ xgp_Hypr2d::Location() {
        gp_Pnt2d* temp = new gp_Pnt2d(NativeHandle->Location());
        return gcnew xgp_Pnt2d(temp);
    };


    //! Returns the major radius of the hyperbola (it is the radius
    //! corresponding to the "XAxis" of the hyperbola).
    Standard_Real xgp_Hypr2d::MajorRadius() {
        return NativeHandle->MajorRadius();
    };


    //! Returns the minor radius of the hyperbola (it is the radius
    //! corresponding to the "YAxis" of the hyperbola).
    Standard_Real xgp_Hypr2d::MinorRadius() {
        return NativeHandle->MinorRadius();
    };


    //! Returns the branch of hyperbola obtained by doing the
    //! symmetrical transformation of <me> with respect to the
    //! "YAxis" of <me>.
    xgp_Hypr2d^ xgp_Hypr2d::OtherBranch() {
        gp_Hypr2d* temp = new gp_Hypr2d(NativeHandle->OtherBranch());
        return gcnew xgp_Hypr2d(temp);
    };


    //! Returns p = (e * e - 1) * MajorRadius where e is the
    //! eccentricity of the hyperbola.
    //! Raises DomainError if MajorRadius = 0.0
    Standard_Real xgp_Hypr2d::Parameter() {
        return NativeHandle->Parameter();
    };

    //! Returns the axisplacement of the hyperbola.
    xgp_Ax22d^ xgp_Hypr2d::Axis() {
        gp_Ax22d* temp = new gp_Ax22d(NativeHandle->Axis());
        return gcnew xgp_Ax22d(temp);
    };

    //! Computes an axis whose
    //! -   the origin is the center of this hyperbola, and
    //! -   the unit vector is the "X Direction" or "Y Direction"
    //! respectively of the local coordinate system of this hyperbola
    //! Returns the major axis of the hyperbola.
    xgp_Ax2d^ xgp_Hypr2d::XAxis() {
        gp_Ax2d* temp = new gp_Ax2d(NativeHandle->XAxis());
        return gcnew xgp_Ax2d(temp);
    };

    //! Computes an axis whose
    //! -   the origin is the center of this hyperbola, and
    //! -   the unit vector is the "X Direction" or "Y Direction"
    //! respectively of the local coordinate system of this hyperbola
    //! Returns the minor axis of the hyperbola.
    xgp_Ax2d^ xgp_Hypr2d::YAxis() {
        gp_Ax2d* temp = new gp_Ax2d(NativeHandle->YAxis());
        return gcnew xgp_Ax2d(temp);
    };

    void xgp_Hypr2d::Reverse() {
        NativeHandle->Reverse();
    };

    //! Reverses the orientation of the local coordinate system
    //! of this hyperbola (the "Y Axis" is reversed). Therefore,
    //! the implicit orientation of this hyperbola is reversed.
    //! Note:
    //! -   Reverse assigns the result to this hyperbola, while
    //! -   Reversed creates a new one.
    xgp_Hypr2d^ xgp_Hypr2d::Reversed() {
        gp_Hypr2d* temp = new gp_Hypr2d(NativeHandle->Reversed());
        return gcnew xgp_Hypr2d(temp);
    };

    //! Returns true if the local coordinate system is direct
    //! and false in the other case.
    Standard_Boolean xgp_Hypr2d::IsDirect() {
        return NativeHandle->IsDirect();
    };

    void xgp_Hypr2d::Mirror(xgp_Pnt2d^ P) {
        return NativeHandle->Mirror(*P->GetPnt2d());
    };


    //! Performs the symmetrical transformation of an hyperbola with
    //! respect  to the point P which is the center of the symmetry.
    xgp_Hypr2d^ xgp_Hypr2d::Mirrored(xgp_Pnt2d^ P) {
        gp_Hypr2d* temp = new gp_Hypr2d(NativeHandle->Mirrored(*P->GetPnt2d()));
        return gcnew xgp_Hypr2d(temp);
    };

    void xgp_Hypr2d::Mirror(xgp_Ax2d^ A) {
        NativeHandle->Mirror(*A->GetAx2d());
    };


    //! Performs the symmetrical transformation of an hyperbola with
    //! respect to an axis placement which is the axis of the symmetry.
    xgp_Hypr2d^ xgp_Hypr2d::Mirrored(xgp_Ax2d^ A) {
        gp_Hypr2d* temp = new gp_Hypr2d(NativeHandle->Mirrored(*A->GetAx2d()));
        return gcnew xgp_Hypr2d(temp);
    };

    void xgp_Hypr2d::Rotate(xgp_Pnt2d^ P, Standard_Real Ang) {
        NativeHandle->Rotate(*P->GetPnt2d(), Ang);
    };


    //! Rotates an hyperbola. P is the center of the rotation.
    //! Ang is the angular value of the rotation in radians.
    xgp_Hypr2d^ xgp_Hypr2d::Rotated(xgp_Pnt2d^ P, Standard_Real Ang) {
        gp_Hypr2d* temp = new gp_Hypr2d(NativeHandle->Rotated(*P->GetPnt2d(), Ang));
        return gcnew xgp_Hypr2d(temp);
    };

    void xgp_Hypr2d::Scale(xgp_Pnt2d^ P, Standard_Real S) {
        NativeHandle->Scale(*P->GetPnt2d(), S);
    };


    //! Scales an hyperbola. <S> is the scaling value.
    //! If <S> is positive only the location point is
    //! modified. But if <S> is negative the "XAxis" is
    //! reversed and the "YAxis" too.
    xgp_Hypr2d^ xgp_Hypr2d::Scaled(xgp_Pnt2d^ P, Standard_Real S) {
        gp_Hypr2d* temp = new gp_Hypr2d(NativeHandle->Scaled(*P->GetPnt2d(), S));
        return gcnew xgp_Hypr2d(temp);
    };

    void xgp_Hypr2d::Transform(xgp_Trsf2d^ T) {
        NativeHandle->Transform(T->GetTrsf2d());
    };


    //! Transforms an hyperbola with the transformation T from
    //!namespace TKMath  {  public ref class Trsf2d.
    xgp_Hypr2d^ xgp_Hypr2d::Transformed(xgp_Trsf2d^ T) {
        gp_Hypr2d* temp = new gp_Hypr2d(NativeHandle->Transformed(T->GetTrsf2d()));
        return gcnew xgp_Hypr2d(temp);
    };

    void xgp_Hypr2d::Translate(xgp_Vec2d^ V) {
        NativeHandle->Translate(V->GetVec2d());
    };

    //! Translates an hyperbola in the direction of the vector V.
    //! The magnitude of the translation is the vector's magnitude.
    xgp_Hypr2d^ xgp_Hypr2d::Translated(xgp_Vec2d^ V) {
        gp_Hypr2d* temp = new gp_Hypr2d(NativeHandle->Translated(V->GetVec2d()));
        return gcnew xgp_Hypr2d(temp);
    };

    void xgp_Hypr2d::Translate(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2) {
        NativeHandle->Translate(*P1->GetPnt2d(), *P2->GetPnt2d());
    };

    //! Translates an hyperbola from the point P1 to the point P2.
    xgp_Hypr2d^ xgp_Hypr2d::Translated(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2) {
        gp_Hypr2d* temp = new gp_Hypr2d(NativeHandle->Translated(*P1->GetPnt2d(), *P2->GetPnt2d()));
        return gcnew xgp_Hypr2d(temp);
    };
};