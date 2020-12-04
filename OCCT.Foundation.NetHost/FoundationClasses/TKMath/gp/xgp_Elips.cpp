#include <xgp_Elips.h>

namespace TKMath
{
    //! Creates an indefinite ellipse.
    xgp_Elips::xgp_Elips(void) {
        NativeHandle = new gp_Elips();
    };

    /// <summary>
    /// 指针映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Elips::xgp_Elips(gp_Elips* pos) {
        NativeHandle = new gp_Elips(*pos);
    };
    /// <summary>
    ///  映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Elips::xgp_Elips(gp_Elips pos) {
        NativeHandle = new gp_Elips(pos);
    };

    //! The major radius of the ellipse is on the "XAxis" and the
    //! minor radius is on the "YAxis" of the ellipse. The "XAxis"
    //! is defined with the "XDirection" of A2 and the "YAxis" is
    //! defined with the "YDirection" of A2.
    //! Warnings :
    //! It is not forbidden to create an ellipse with MajorRadius =
    //! MinorRadius.
    //! Raises ConstructionError if MajorRadius < MinorRadius or MinorRadius < 0.
    xgp_Elips::xgp_Elips(xgp_Ax2^ A2, Standard_Real MajorRadius, Standard_Real MinorRadius) {
        NativeHandle = new gp_Elips(*A2->GetAx2(), MajorRadius, MinorRadius);
    };

    //释放
    xgp_Elips::~xgp_Elips() {
        if (NativeHandle != NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };
    //释放
    xgp_Elips::!xgp_Elips() {
        if (NativeHandle != NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };

    //! gp_Elips
    gp_Elips xgp_Elips::GetElips() {
        return *NativeHandle;
    };

    //! Changes the axis normal to the plane of the ellipse.
    //! It modifies the definition of this plane.
    //! The "XAxis" and the "YAxis" are recomputed.
    //! The local coordinate system is redefined so that:
    //! -   its origin and "main Direction" become those of the
    //! axis A1 (the "X Direction" and "Y Direction" are then
    //! recomputed in the same way as for any xgp_Ax2), or
    //! Raises ConstructionError if the direction of A1
    //! is parallel to the direction of the "XAxis" of the ellipse.
    void xgp_Elips::SetAxis(xgp_Ax1^ A1) {
        NativeHandle->SetAxis(*A1->GetAx1());
    };

    //! Modifies this ellipse, by redefining its local coordinate
    //! so that its origin becomes P.
    void xgp_Elips::SetLocation(xgp_Pnt^ P) {
        NativeHandle->SetLocation(P->GetPnt());
    };


    //! The major radius of the ellipse is on the "XAxis" (major axis)
    //! of the ellipse.
    //! Raises ConstructionError if MajorRadius < MinorRadius.
    void xgp_Elips::SetMajorRadius(Standard_Real MajorRadius) {
        NativeHandle->SetMajorRadius(MajorRadius);
    };


    //! The minor radius of the ellipse is on the "YAxis" (minor axis)
    //! of the ellipse.
    //! Raises ConstructionError if MinorRadius > MajorRadius or MinorRadius < 0.
    void xgp_Elips::SetMinorRadius(Standard_Real MinorRadius) {
        NativeHandle->SetMinorRadius(MinorRadius);
    };

    //! Modifies this ellipse, by redefining its local coordinate
    //! so that it becomes A2e.
    void xgp_Elips::SetPosition(xgp_Ax2^ A2) {
        NativeHandle->SetPosition(*A2->GetAx2());
    };

    //! Computes the area of the Ellipse.
    Standard_Real xgp_Elips::Area() {
        return NativeHandle->Area();
    };


    //! Computes the axis normal to the plane of the ellipse.
    xgp_Ax1^ xgp_Elips::Axis() {
        gp_Ax1* temp = new gp_Ax1(NativeHandle->Axis());
        return gcnew xgp_Ax1(temp);
    };

    //! Computes the first or second directrix of this ellipse.
    //! These are the lines, in the plane of the ellipse, normal to
    //! the major axis, at a distance equal to
    //! MajorRadius/e from the center of the ellipse, where
    //! e is the eccentricity of the ellipse.
    //! The first directrix (Directrix1) is on the positive side of
    //! the major axis. The second directrix (Directrix2) is on
    //! the negative side.
    //! The directrix is returned as an axis (xgp_Ax1 object), the
    //! origin of which is situated on the "X Axis" of the local
    //! coordinate system of this ellipse.
    //! Exceptions
    //! Standard_ConstructionError if the eccentricity is null
    //! (the ellipse has degenerated into a circle).
    xgp_Ax1^ xgp_Elips::Directrix1() {
        gp_Ax1* temp = new gp_Ax1(NativeHandle->Directrix1());
        return gcnew xgp_Ax1(temp);
    };


    //! This line is obtained by the symmetrical transformation
    //! of "Directrix1" with respect to the "YAxis" of the ellipse.
    //! Exceptions
    //! Standard_ConstructionError if the eccentricity is null
    //! (the ellipse has degenerated into a circle).
    xgp_Ax1^ xgp_Elips::Directrix2() {
        gp_Ax1* temp = new gp_Ax1(NativeHandle->Directrix2());
        return gcnew xgp_Ax1(temp);
    };


    //! Returns the eccentricity of the ellipse  between 0.0 and 1.0
    //! If f is the distance between the center of the ellipse and
    //! the Focus1 then the eccentricity e = f / MajorRadius.
    //! Raises ConstructionError if MajorRadius = 0.0
    Standard_Real xgp_Elips::Eccentricity() {
         return NativeHandle->Eccentricity();
    };


    //! Computes the focal distance. It is the distance between the
    //! two focus focus1 and focus2 of the ellipse.
    Standard_Real xgp_Elips::Focal() {
        return NativeHandle->Focal();
    };


    //! Returns the first focus of the ellipse. This focus is on the
    //! positive side of the "XAxis" of the ellipse.
    xgp_Pnt^ xgp_Elips::Focus1() {
        return gcnew xgp_Pnt(NativeHandle->Focus1());
    };


    //! Returns the second focus of the ellipse. This focus is on the
    //! negative side of the "XAxis" of the ellipse.
    xgp_Pnt^ xgp_Elips::Focus2() {
        return gcnew xgp_Pnt(NativeHandle->Focus2());
    };


    //! Returns the center of the ellipse. It is the "Location"
    //! point of the coordinate system of the ellipse.
    xgp_Pnt^ xgp_Elips::Location() {
        return gcnew xgp_Pnt(NativeHandle->Location());
    };

    //! Returns the major radius of the ellipse.
    Standard_Real xgp_Elips::MajorRadius() {
        return NativeHandle->MajorRadius();
    };

    //! Returns the minor radius of the ellipse.
    Standard_Real xgp_Elips::MinorRadius() {
        return NativeHandle->MinorRadius();
    };


    //! Returns p = (1 - e * e) * MajorRadius where e is the eccentricity
    //! of the ellipse.
    //! Returns 0 if MajorRadius = 0
    Standard_Real xgp_Elips::Parameter() {
        return NativeHandle->Parameter();
    };

    //! Returns the coordinate system of the ellipse.
    xgp_Ax2^ xgp_Elips::Position() {
        gp_Ax2* temp = new gp_Ax2(NativeHandle->Position());
        return gcnew xgp_Ax2(temp);
    };


    //! Returns the "XAxis" of the ellipse whose origin
    //! is the center of this ellipse. It is the major axis of the
    //! ellipse.
    xgp_Ax1^ xgp_Elips::XAxis() {
        gp_Ax1* temp = new gp_Ax1(NativeHandle->XAxis());
        return gcnew xgp_Ax1(temp);
    };


    //! Returns the "YAxis" of the ellipse whose unit vector is the "X Direction" or the "Y Direction"
    //! of the local coordinate system of this ellipse.
    //! This is the minor axis of the ellipse.
    xgp_Ax1^ xgp_Elips::YAxis() {
        gp_Ax1* temp = new gp_Ax1(NativeHandle->YAxis());
        return gcnew xgp_Ax1(temp);
    };

    void xgp_Elips::Mirror(xgp_Pnt^ P) {
        NativeHandle->Mirror(P->GetPnt());
    };


    //! Performs the symmetrical transformation of an ellipse with
    //! respect to the point P which is the center of the symmetry.
    xgp_Elips^ xgp_Elips::Mirrored(xgp_Pnt^ P) {
        return gcnew xgp_Elips(NativeHandle->Mirrored(P->GetPnt()));
    };

    void xgp_Elips::Mirror(xgp_Ax1^ A1) {
        NativeHandle->Mirror(*A1->GetAx1());
    };


    //! Performs the symmetrical transformation of an ellipse with
    //! respect to an axis placement which is the axis of the symmetry.
    xgp_Elips^ xgp_Elips::Mirrored(xgp_Ax1^ A1) {
        return gcnew xgp_Elips(NativeHandle->Mirrored(*A1->GetAx1()));
    };

    void xgp_Elips::Mirror(xgp_Ax2^ A2) {
        NativeHandle->Mirrored(*A2->GetAx2());
    };


    //! Performs the symmetrical transformation of an ellipse with
    //! respect to a plane. The axis placement A2 locates the plane
    //! of the symmetry (Location, XDirection, YDirection).
    xgp_Elips^ xgp_Elips::Mirrored(xgp_Ax2^ A2) {
        return gcnew xgp_Elips(NativeHandle->Mirrored(*A2->GetAx2()));
    };

    void xgp_Elips::Rotate(xgp_Ax1^ A1, Standard_Real Ang) {
        NativeHandle->Rotate(*A1->GetAx1(), Ang);
    };


    //! Rotates an ellipse. A1 is the axis of the rotation.
    //! Ang is the angular value of the rotation in radians.
    xgp_Elips^ xgp_Elips::Rotated(xgp_Ax1^ A1, Standard_Real Ang) {
        return gcnew xgp_Elips(NativeHandle->Rotated(*A1->GetAx1(), Ang));
    };

    void xgp_Elips::Scale(xgp_Pnt^ P, Standard_Real S) {
        NativeHandle->Scale(P->GetPnt(), S);
    };


    //! Scales an ellipse. S is the scaling value.
    xgp_Elips^ xgp_Elips::Scaled(xgp_Pnt^ P, Standard_Real S) {
        return gcnew xgp_Elips(NativeHandle->Scaled(P->GetPnt(), S));
    };

    void xgp_Elips::Transform(xgp_Trsf^ T) {
        NativeHandle->Transform(T->GetTrsf());
    };


    //! Transforms an ellipse with the transformation T fromnamespace TKMath  {  public ref class Trsf.
    xgp_Elips^ xgp_Elips::Transformed(xgp_Trsf^ T) {
        return gcnew xgp_Elips(NativeHandle->Transformed(T->GetTrsf()));
    };

    void xgp_Elips::Translate(xgp_Vec^ V) {
        NativeHandle->Translate(V->GetVec());
    };


    //! Translates an ellipse in the direction of the vector V.
    //! The magnitude of the translation is the vector's magnitude.
    xgp_Elips^ xgp_Elips::Translated(xgp_Vec^ V) {
        return gcnew xgp_Elips(NativeHandle->Translated(V->GetVec()));
    };

    void xgp_Elips::Translate(xgp_Pnt^ P1, xgp_Pnt^ P2) {
        NativeHandle->Translate(P1->GetPnt(), P2->GetPnt());
    };


    //! Translates an ellipse from the point P1 to the point P2.
    xgp_Elips^ xgp_Elips::Translated(xgp_Pnt^ P1, xgp_Pnt^ P2) {
        return gcnew xgp_Elips(NativeHandle->Translated(P1->GetPnt(), P2->GetPnt()));
    };
};

