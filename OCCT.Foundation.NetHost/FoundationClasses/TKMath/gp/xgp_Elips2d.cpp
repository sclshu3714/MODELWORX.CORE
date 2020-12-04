#include <xgp_Elips2d.h>

namespace TKMath
{
    //! Creates an indefinite ellipse.
    xgp_Elips2d::xgp_Elips2d(void) {
        NativeHandle = new gp_Elips2d();
    };

    /// <summary>
    /// 指针映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Elips2d::xgp_Elips2d(gp_Elips2d* pos) {
        NativeHandle = new gp_Elips2d(*pos);
    };
    /// <summary>
    ///  映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Elips2d::xgp_Elips2d(gp_Elips2d pos) {
        NativeHandle = new gp_Elips2d(pos);
    };

    //! Creates an ellipse with the major axis, the major and the
    //! minor radius. The location of the MajorAxis is the center
    //! of the  ellipse.
    //! The sense of parametrization is given by Sense.
    //! Warnings :
    //! It is possible to create an ellipse with
    //! MajorRadius = MinorRadius.
    //! Raises ConstructionError if MajorRadius < MinorRadius or MinorRadius < 0.0
    xgp_Elips2d::xgp_Elips2d(xgp_Ax2d^ MajorAxis, Standard_Real MajorRadius, Standard_Real MinorRadius, Standard_Boolean Sense) {
        NativeHandle = new gp_Elips2d(*MajorAxis->GetAx2d(), MajorRadius, MinorRadius, Sense);
    };

    //! Creates an ellipse with radii MajorRadius and
    //! MinorRadius, positioned in the plane by coordinate system A where:
    //! -   the origin of A is the center of the ellipse,
    //! -   the "X Direction" of A defines the major axis of
    //! the ellipse, that is, the major radius MajorRadius
    //! is measured along this axis, and
    //! -   the "Y Direction" of A defines the minor axis of
    //! the ellipse, that is, the minor radius MinorRadius
    //! is measured along this axis, and
    //! -   the orientation (direct or indirect sense) of A
    //! gives the orientation of the ellipse.
    //! Warnings :
    //! It is possible to create an ellipse with
    //! MajorRadius = MinorRadius.
    //! Raises ConstructionError if MajorRadius < MinorRadius or MinorRadius < 0.0
    xgp_Elips2d::xgp_Elips2d(xgp_Ax22d^ A, Standard_Real MajorRadius, Standard_Real MinorRadius) {
        NativeHandle = new gp_Elips2d(A->GetAx22d(), MajorRadius, MinorRadius);
    };


    //释放
    xgp_Elips2d::~xgp_Elips2d() {
        if (NativeHandle != NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };
    //释放
    xgp_Elips2d::!xgp_Elips2d() {
        if (NativeHandle != NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };

    //! gp_Elips2d
    gp_Elips2d xgp_Elips2d::GetElips2d() {
        return *NativeHandle;
    };

    //! Modifies this ellipse, by redefining its local coordinate system so that
    //! -   its origin becomes P.
    void xgp_Elips2d::SetLocation(xgp_Pnt2d^ P) {
        NativeHandle->SetLocation(P->GetPnt2d());
    };

    //! Changes the value of the major radius.
    //! Raises ConstructionError if MajorRadius < MinorRadius.
    void xgp_Elips2d::SetMajorRadius(Standard_Real MajorRadius) {
        NativeHandle->SetMajorRadius(MajorRadius);
    };

    //! Changes the value of the minor radius.
    //! Raises ConstructionError if MajorRadius < MinorRadius or MinorRadius < 0.0
    void xgp_Elips2d::SetMinorRadius(Standard_Real MinorRadius) {
        NativeHandle->SetMinorRadius(MinorRadius);
    };

    //! Modifies this ellipse, by redefining its local coordinate system so that
    //! it becomes A.
    void xgp_Elips2d::SetAxis(xgp_Ax22d^ A) {
        NativeHandle->SetAxis(A->GetAx22d());
    };

    //! Modifies this ellipse, by redefining its local coordinate system so that
    //! its origin and its "X Direction"  become those
    //! of the axis A. The "Y  Direction"  is then
    //! recomputed. The orientation of the local coordinate
    //! system is not modified.
    void xgp_Elips2d::SetXAxis(xgp_Ax2d^ A) {
        NativeHandle->SetXAxis(*A->GetAx2d());
    };

    //! Modifies this ellipse, by redefining its local coordinate system so that
    //! its origin and its "Y Direction"  become those
    //! of the axis A. The "X  Direction"  is then
    //! recomputed. The orientation of the local coordinate
    //! system is not modified.
    void xgp_Elips2d::SetYAxis(xgp_Ax2d^ A) {
        NativeHandle->SetYAxis(*A->GetAx2d());
    };

    //! Computes the area of the ellipse.
    Standard_Real xgp_Elips2d::Area() {
        return NativeHandle->Area();
    };


    //! Returns the coefficients of the implicit equation of the ellipse.
    //! A * (X**2) + B * (Y**2) + 2*C*(X*Y) + 2*D*X + 2*E*Y + F = 0.
    void xgp_Elips2d::Coefficients(Standard_Real A, Standard_Real B, Standard_Real C, Standard_Real D, Standard_Real E, Standard_Real F) {
        NativeHandle->Coefficients(A, B, C, D, E, F);
    };


    //! This directrix is the line normal to the XAxis of the ellipse
    //! in the local plane (Z = 0) at a distance d = MajorRadius / e
    //! from the center of the ellipse, where e is the eccentricity of
    //! the ellipse.
    //! This line is parallel to the "YAxis". The intersection point
    //! between directrix1 and the "XAxis" is the location point of the
    //! directrix1. This point is on the positive side of the "XAxis".
    //!
    //! Raised if Eccentricity = 0.0. (The ellipse degenerates into a
    //! circle)
    xgp_Ax2d^ xgp_Elips2d::Directrix1() {
        gp_Ax2d* temp = new gp_Ax2d(NativeHandle->Directrix1());
        return gcnew xgp_Ax2d(temp);
    };


    //! This line is obtained by the symmetrical transformation
    //! of "Directrix1" with respect to the minor axis of the ellipse.
    //!
    //! Raised if Eccentricity = 0.0. (The ellipse degenerates into a
    //! circle).
    xgp_Ax2d^ xgp_Elips2d::Directrix2() {
        gp_Ax2d* temp = new gp_Ax2d(NativeHandle->Directrix2());
        return gcnew xgp_Ax2d(temp);
    };


    //! Returns the eccentricity of the ellipse  between 0.0 and 1.0
    //! If f is the distance between the center of the ellipse and
    //! the Focus1 then the eccentricity e = f / MajorRadius.
    //! Returns 0 if MajorRadius = 0.
    Standard_Real xgp_Elips2d::Eccentricity() {
        return NativeHandle->Eccentricity();
    };


    //! Returns the distance between the center of the ellipse
    //! and focus1 or focus2.
    Standard_Real xgp_Elips2d::Focal() {
        return NativeHandle->Focal();
    };


    //! Returns the first focus of the ellipse. This focus is on the
    //! positive side of the major axis of the ellipse.
    xgp_Pnt2d^ xgp_Elips2d::Focus1() {
        return gcnew xgp_Pnt2d(NativeHandle->Focus1());
    };


    //! Returns the second focus of the ellipse. This focus is on the
    //! negative side of the major axis of the ellipse.
    xgp_Pnt2d^ xgp_Elips2d::Focus2() {
        return gcnew xgp_Pnt2d(NativeHandle->Focus2());
    };

    //! Returns the center of the ellipse.
    xgp_Pnt2d^ xgp_Elips2d::Location() {
        return gcnew xgp_Pnt2d(NativeHandle->Location());
    };

    //! Returns the major radius of the Ellipse.
    Standard_Real xgp_Elips2d::MajorRadius() {
        return NativeHandle->MajorRadius();
    };

    //! Returns the minor radius of the Ellipse.
    Standard_Real xgp_Elips2d::MinorRadius() {
        return NativeHandle->MinorRadius();
    };


    //! Returns p = (1 - e * e) * MajorRadius where e is the eccentricity
    //! of the ellipse.
    //! Returns 0 if MajorRadius = 0
    Standard_Real xgp_Elips2d::Parameter() {
        return NativeHandle->Parameter();
    };

    //! Returns the major axis of the ellipse.
    xgp_Ax22d^ xgp_Elips2d::Axis() {
        return gcnew xgp_Ax22d(NativeHandle->Axis());
    };

    //! Returns the major axis of the ellipse.
    xgp_Ax2d^ xgp_Elips2d::XAxis() {
        gp_Ax2d* temp = new gp_Ax2d(NativeHandle->XAxis());
        return gcnew xgp_Ax2d(temp);
    };

    //! Returns the minor axis of the ellipse.
    //! Reverses the direction of the circle.
    xgp_Ax2d^ xgp_Elips2d::YAxis() {
        gp_Ax2d* temp = new gp_Ax2d(NativeHandle->YAxis());
        return gcnew xgp_Ax2d(temp);
    };

    void xgp_Elips2d::Reverse() {
        NativeHandle->Reverse();
    };

    xgp_Elips2d^ xgp_Elips2d::Reversed() {
        return gcnew xgp_Elips2d(NativeHandle->Reversed());
    };

    //! Returns true if the local coordinate system is direct
    //! and false in the other case.
    Standard_Boolean xgp_Elips2d::IsDirect() {
        return NativeHandle->IsDirect();
    };

    void xgp_Elips2d::Mirror(xgp_Pnt2d^ P) {
        NativeHandle->Mirror(P->GetPnt2d());
    };


    //! Performs the symmetrical transformation of a ellipse with respect
    //! to the point P which is the center of the symmetry
    xgp_Elips2d^ xgp_Elips2d::Mirrored(xgp_Pnt2d^ P) {
        return gcnew xgp_Elips2d(NativeHandle->Mirrored(P->GetPnt2d()));
    };

    void xgp_Elips2d::Mirror(xgp_Ax2d^ A) {
        NativeHandle->Mirror(*A->GetAx2d());
    };


    //! Performs the symmetrical transformation of a ellipse with respect
    //! to an axis placement which is the axis of the symmetry.
    xgp_Elips2d^ xgp_Elips2d::Mirrored(xgp_Ax2d^ A) {
        return gcnew xgp_Elips2d(NativeHandle->Mirrored(*A->GetAx2d()));
    };

    void xgp_Elips2d::Rotate(xgp_Pnt2d^ P, Standard_Real Ang) {
        NativeHandle->Rotate(P->GetPnt2d(), Ang);
    };

    xgp_Elips2d^ xgp_Elips2d::Rotated(xgp_Pnt2d^ P, Standard_Real Ang) {
        return gcnew xgp_Elips2d(NativeHandle->Rotated(P->GetPnt2d(), Ang));
    };

    void xgp_Elips2d::Scale(xgp_Pnt2d^ P, Standard_Real S) {
        NativeHandle->Scale(P->GetPnt2d(), S);
    };


    //! Scales a ellipse. S is the scaling value.
    xgp_Elips2d^ xgp_Elips2d::Scaled(xgp_Pnt2d^ P, Standard_Real S) {
        return gcnew xgp_Elips2d(NativeHandle->Scaled(P->GetPnt2d(), S));
    };

    void xgp_Elips2d::Transform(xgp_Trsf2d^ T) {
        NativeHandle->Transform(T->GetTrsf2d());
    };


    //! Transforms an ellipse with the transformation T fromnamespace TKMath  {  public ref class Trsf2d.
    xgp_Elips2d^ xgp_Elips2d::Transformed(xgp_Trsf2d^ T) {
        return gcnew xgp_Elips2d(NativeHandle->Transformed(T->GetTrsf2d()));
    };

    void xgp_Elips2d::Translate(xgp_Vec2d^ V) {
        NativeHandle->Translate(V->GetVec2d());
    };


    //! Translates a ellipse in the direction of the vector V.
    //! The magnitude of the translation is the vector's magnitude.
    xgp_Elips2d^ xgp_Elips2d::Translated(xgp_Vec2d^ V) {
        return gcnew xgp_Elips2d(NativeHandle->Translated(V->GetVec2d()));
    };

    void xgp_Elips2d::Translate(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2) {
        NativeHandle->Translate(P1->GetPnt2d(), P2->GetPnt2d());
    };


    //! Translates a ellipse from the point P1 to the point P2.
    xgp_Elips2d^ xgp_Elips2d::Translated(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2) {
        return gcnew xgp_Elips2d(NativeHandle->Translated(P1->GetPnt2d(), P2->GetPnt2d()));
    };
};
