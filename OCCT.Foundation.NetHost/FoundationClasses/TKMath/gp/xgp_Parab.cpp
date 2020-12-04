#include <xgp_Parab.h>

namespace TKMath
{
    //! Creates an indefinite Parabola.
    xgp_Parab::xgp_Parab() {
        NativeHandle = new gp_Parab();
    };

    //£¡Creates an indefinite Parabola.
    xgp_Parab::xgp_Parab(gp_Parab* pos) {
        NativeHandle = new gp_Parab(*pos);
    };

    //£¡Creates an indefinite Parabola.
    xgp_Parab::xgp_Parab(gp_Parab pos) {
        NativeHandle = new gp_Parab(pos);
    };

    //! Creates a parabola with its local coordinate system "A2"
    //! and it's focal length "Focal".
    //! The XDirection of A2 defines the axis of symmetry of the
    //! parabola. The YDirection of A2 is parallel to the directrix
    //! of the parabola. The Location point of A2 is the vertex of
    //! the parabola
    //! Raises ConstructionError if Focal < 0.0
    //! Raised if Focal < 0.0
    xgp_Parab::xgp_Parab(xgp_Ax2^ A2, Standard_Real Focal) {
        NativeHandle = new gp_Parab(A2->GetAx2(), Focal);
    };


    //! D is the directrix of the parabola and F the focus point.
    //! The symmetry axis (XAxis) of the parabola is normal to the
    //! directrix and pass through the focus point F, but its
    //! location point is the vertex of the parabola.
    //! The YAxis of the parabola is parallel to D and its location
    //! point is the vertex of the parabola. The normal to the plane
    //! of the parabola is the cross product between the XAxis and the
    //! YAxis.
    xgp_Parab::xgp_Parab(xgp_Ax1^ D, xgp_Pnt^ F) {
        NativeHandle = new gp_Parab(*D->GetAx1(), F->GetPnt());
    };

    //! 
    xgp_Parab::~xgp_Parab() {
        if (NativeHandle != NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };

    //! 
    xgp_Parab::!xgp_Parab() {
        if (NativeHandle != NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };

    //! gp_Parab
    gp_Parab xgp_Parab::GetParab() {
        return *NativeHandle;
    };

    //! Modifies this parabola by redefining its local coordinate system so that
    //! -   its origin and "main Direction" become those of the
    //! axis A1 (the "X Direction" and "Y Direction" are then
    //! recomputed in the same way as for any xgp_Ax2)
    //! Raises ConstructionError if the direction of A1 is parallel to the previous
    //! XAxis of the parabola.
    void xgp_Parab::SetAxis(xgp_Ax1^ A1) {
        NativeHandle->SetAxis(*A1->GetAx1());
    };

    //! Changes the focal distance of the parabola.
    //! Raises ConstructionError if Focal < 0.0
    void xgp_Parab::SetFocal(Standard_Real Focal) {
        NativeHandle->SetFocal(Focal);
    };


    //! Changes the location of the parabola. It is the vertex of
    //! the parabola.
    void xgp_Parab::SetLocation(xgp_Pnt^ P) {
        NativeHandle->SetLocation(P->GetPnt());
    };

    //! Changes the local coordinate system of the parabola.
    void xgp_Parab::SetPosition(xgp_Ax2^ A2) {
        NativeHandle->SetPosition(A2->GetAx2());
    };


    //! Returns the main axis of the parabola.
    //! It is the axis normal to the plane of the parabola passing
    //! through the vertex of the parabola.
    xgp_Ax1^ xgp_Parab::Axis() {
        gp_Ax1* temp = new gp_Ax1(NativeHandle->Axis());
        return gcnew xgp_Ax1(temp);
    };

    //! Computes the directrix of this parabola.
    //! The directrix is:
    //! -   a line parallel to the "Y Direction" of the local
    //! coordinate system of this parabola, and
    //! -   located on the negative side of the axis of symmetry,
    //! at a distance from the apex which is equal to the focal
    //! length of this parabola.
    //! The directrix is returned as an axis (a xgp_Ax1 object),
    //! the origin of which is situated on the "X Axis" of this parabola.
    xgp_Ax1^ xgp_Parab::Directrix() {
        gp_Ax1* temp = new gp_Ax1(NativeHandle->Directrix());
        return gcnew xgp_Ax1(temp);
    };


    //! Returns the distance between the vertex and the focus
    //! of the parabola.
    Standard_Real xgp_Parab::Focal() {
        return NativeHandle->Focal();
    };

    //! -   Computes the focus of the parabola.
    xgp_Pnt^ xgp_Parab::Focus() {
        return gcnew xgp_Pnt(NativeHandle->Focus());
    };


    //! Returns the vertex of the parabola. It is the "Location"
    //! point of the coordinate system of the parabola.
    xgp_Pnt^ xgp_Parab::Location() {
        return gcnew xgp_Pnt(NativeHandle->Location());
    };


    //! Computes the parameter of the parabola.
    //! It is the distance between the focus and the directrix of
    //! the parabola. This distance is twice the focal length.
    Standard_Real xgp_Parab::Parameter() {
        return NativeHandle->Parameter();
    };


    //! Returns the local coordinate system of the parabola.
    xgp_Ax2^ xgp_Parab::Position() {
        return gcnew xgp_Ax2(NativeHandle->Position());
    };


    //! Returns the symmetry axis of the parabola. The location point
    //! of the axis is the vertex of the parabola.
    xgp_Ax1^ xgp_Parab::XAxis() {
        gp_Ax1* temp = new gp_Ax1(NativeHandle->XAxis());
        return gcnew xgp_Ax1(temp);
    };


    //! It is an axis parallel to the directrix of the parabola.
    //! The location point of this axis is the vertex of the parabola.
    xgp_Ax1^ xgp_Parab::YAxis() {
        gp_Ax1* temp = new gp_Ax1(NativeHandle->YAxis());
        return gcnew xgp_Ax1(temp);
    };

    void xgp_Parab::Mirror(xgp_Pnt^ P) {
        NativeHandle->Mirror(P->GetPnt());
    };


    //! Performs the symmetrical transformation of a parabola
    //! with respect to the point P which is the center of the
    //! symmetry.
    xgp_Parab^ xgp_Parab::Mirrored(xgp_Pnt^ P) {
        return gcnew xgp_Parab(NativeHandle->Mirrored(P->GetPnt()));
    };

    void xgp_Parab::Mirror(xgp_Ax1^ A1) {
        NativeHandle->Mirror(*A1->GetAx1());
    };


    //! Performs the symmetrical transformation of a parabola
    //! with respect to an axis placement which is the axis of
    //! the symmetry.
    xgp_Parab^ xgp_Parab::Mirrored(xgp_Ax1^ A1) {
        return gcnew xgp_Parab(NativeHandle->Mirrored(*A1->GetAx1()));
    };

    void xgp_Parab::Mirror(xgp_Ax2^ A2) {
        NativeHandle->Mirror(A2->GetAx2());
    };


    //! Performs the symmetrical transformation of a parabola
    //! with respect to a plane. The axis placement A2 locates
    //! the plane of the symmetry (Location, XDirection, YDirection).
    xgp_Parab^ xgp_Parab::Mirrored(xgp_Ax2^ A2) {
        return gcnew xgp_Parab(NativeHandle->Mirrored(A2->GetAx2()));
    };

    void xgp_Parab::Rotate(xgp_Ax1^ A1, Standard_Real Ang) {
        NativeHandle->Rotate(*A1->GetAx1(), Ang);
    };


    //! Rotates a parabola. A1 is the axis of the rotation.
    //! Ang is the angular value of the rotation in radians.
    xgp_Parab^ xgp_Parab::Rotated(xgp_Ax1^ A1, Standard_Real Ang) {
        return gcnew xgp_Parab(NativeHandle->Rotated(*A1->GetAx1(), Ang));
    };

    void xgp_Parab::Scale(xgp_Pnt^ P, Standard_Real S) {
        NativeHandle->Scale(P->GetPnt(), S);
    };


    //! Scales a parabola. S is the scaling value.
    //! If S is negative the direction of the symmetry axis
    //! XAxis is reversed and the direction of the YAxis too.
    xgp_Parab^ xgp_Parab::Scaled(xgp_Pnt^ P, Standard_Real S) {
        return gcnew xgp_Parab(NativeHandle->Scaled(P->GetPnt(), S));
    };

    void xgp_Parab::Transform(xgp_Trsf^ T) {
        NativeHandle->Transform(T->GetTrsf());
    };


    //! Transforms a parabola with the transformation T fromnamespace TKMath  {  public ref class Trsf.
    xgp_Parab^ xgp_Parab::Transformed(xgp_Trsf^ T) {
        return gcnew xgp_Parab(NativeHandle->Transformed(T->GetTrsf()));
    };

    void xgp_Parab::Translate(xgp_Vec^ V) {
        NativeHandle->Translate(V->GetVec());
    };


    //! Translates a parabola in the direction of the vector V.
    //! The magnitude of the translation is the vector's magnitude.
    xgp_Parab^ xgp_Parab::Translated(xgp_Vec^ V) {
        return gcnew xgp_Parab(NativeHandle->Translated(V->GetVec()));
    };

    void xgp_Parab::Translate(xgp_Pnt^ P1, xgp_Pnt^ P2) {
        NativeHandle->Translate(P1->GetPnt(), P2->GetPnt());
    };


    //! Translates a parabola from the point P1 to the point P2.
    xgp_Parab^ xgp_Parab::Translated(xgp_Pnt^ P1, xgp_Pnt^ P2) {
        return gcnew xgp_Parab(NativeHandle->Translated(P1->GetPnt(), P2->GetPnt()));
    };
};
