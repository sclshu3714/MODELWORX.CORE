#include <xgp_Parab2d.h>

namespace TKMath
{
    //! Creates an indefinite parabola.
    xgp_Parab2d::xgp_Parab2d() {
        NativeHandle = new gp_Parab2d();
    };

    //£¡Creates an indefinite Parabola.
    xgp_Parab2d::xgp_Parab2d(gp_Parab2d* pos) {
        NativeHandle = new gp_Parab2d(*pos);
    };

    //£¡Creates an indefinite Parabola.
    xgp_Parab2d::xgp_Parab2d(gp_Parab2d pos) {
        NativeHandle = new gp_Parab2d(pos);
    };


    //! Creates a parabola with its vertex point, its axis of symmetry
    //! ("XAxis") and its focal length.
    //! The sense of parametrization is given by theSense. If theSense == TRUE
    //! (by default) then right-handed coordinate system is used,
    //! otherwise - left-handed.
    //! Warnings : It is possible to have FocalLength = 0. In this case,
    //! the parabola looks like a line, which is parallel to the symmetry-axis.
    //! Raises ConstructionError if FocalLength < 0.0
    xgp_Parab2d::xgp_Parab2d(xgp_Ax2d^ theMirrorAxis, Standard_Real theFocalLength, Standard_Boolean theSense) {
        NativeHandle = new gp_Parab2d(*theMirrorAxis->GetAx2d(), theFocalLength, theSense);
    };


    //! Creates a parabola with its vertex point, its axis of symmetry
    //! ("XAxis"), correspond Y-axis and its focal length.
    //! Warnings : It is possible to have FocalLength = 0. In this case,
    //! the parabola looks like a line, which is parallel to the symmetry-axis.
    //! Raises ConstructionError if Focal < 0.0
    xgp_Parab2d::xgp_Parab2d(xgp_Ax22d^ theAxes, Standard_Real theFocalLength) {
        NativeHandle = new gp_Parab2d(*theAxes->GetAx22d(), theFocalLength);
    };


    //! Creates a parabola with the directrix and the focus point.
    //! Y-axis of the parabola (in User Coordinate System - UCS) is
    //! the direction of theDirectrix. X-axis always directs from theDirectrix
    //! to theFocus point and always comes through theFocus.
    //! Apex of the parabola is a middle point between the theFocus and the
    //! intersection point of theDirectrix and the X-axis.
    //! Warnings : It is possible to have FocalLength = 0 (when theFocus lies
    //! in theDirectrix). In this case, X-direction of the parabola is defined 
    //! by theSense parameter. If theSense == TRUE (by default) then right-handed
    //! coordinate system is used, otherwise - left-handed. Result parabola will look
    //! like a line, which is perpendicular to the directrix.
    xgp_Parab2d::xgp_Parab2d(xgp_Ax2d^ theDirectrix, xgp_Pnt2d^ theFocus, Standard_Boolean theSense) {
        NativeHandle = new gp_Parab2d(*theDirectrix->GetAx2d(), theFocus->GetPnt2d(), theSense);
    };


    //! 
    xgp_Parab2d::~xgp_Parab2d() {
        if (NativeHandle != NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };

    //! 
    xgp_Parab2d::!xgp_Parab2d() {
        if (NativeHandle != NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };

    //! gp_Parab
    gp_Parab2d xgp_Parab2d::GetParab2d() {
        return *NativeHandle;
    };

    //! Changes the focal distance of the parabola
    //! Warnings : It is possible to have Focal = 0.
    //! Raises ConstructionError if Focal < 0.0
    void xgp_Parab2d::SetFocal(Standard_Real Focal) {
        NativeHandle->SetFocal(Focal);
    };


    //! Changes the "Location" point of the parabola. It is the
    //! vertex of the parabola.
    void xgp_Parab2d::SetLocation(xgp_Pnt2d^ P) {
        NativeHandle->SetLocation(P->GetPnt2d());
    };

    //! Modifies this parabola, by redefining its local coordinate system so that
    //! its origin and "X Direction" become those of the axis
    //! MA. The "Y Direction" of the local coordinate system is
    //! then recomputed. The orientation of the local
    //! coordinate system is not modified.
    void xgp_Parab2d::SetMirrorAxis(xgp_Ax2d^ A) {
        NativeHandle->SetMirrorAxis(*A->GetAx2d());
    };


    //! Changes the local coordinate system of the parabola.
    //! The "Location" point of A becomes the vertex of the parabola.
    void xgp_Parab2d::SetAxis(xgp_Ax22d^ A) {
        NativeHandle->SetAxis(*A->GetAx22d());
    };


    //! Computes the coefficients of the implicit equation of the parabola
    //! (in WCS - World Coordinate System).
    //! A * (X**2) + B * (Y**2) + 2*C*(X*Y) + 2*D*X + 2*E*Y + F = 0.
    void xgp_Parab2d::Coefficients(Standard_Real A, Standard_Real B, Standard_Real C, Standard_Real D, Standard_Real E, Standard_Real F) {
        NativeHandle->Coefficients(A, B, C, D, E, F);
    };


    //! Computes the directrix of the parabola.
    //! The directrix is:
    //! -   a line parallel to the "Y Direction" of the local
    //! coordinate system of this parabola, and
    //! -   located on the negative side of the axis of symmetry,
    //! at a distance from the apex which is equal to the focal  length of this parabola.
    //! The directrix is returned as an axis (a xgp_Ax2d object),
    //! the origin of which is situated on the "X Axis" of this parabola.
    xgp_Ax2d^ xgp_Parab2d::Directrix() {
        gp_Ax2d* temp = new gp_Ax2d(NativeHandle->Directrix());
        return gcnew xgp_Ax2d(temp);
    };


    //! Returns the distance between the vertex and the focus
    //! of the parabola.
    Standard_Real xgp_Parab2d::Focal() {
        return NativeHandle->Focal();
    };

    //! Returns the focus of the parabola.
    xgp_Pnt2d^ xgp_Parab2d::Focus() {
        return gcnew xgp_Pnt2d(NativeHandle->Focus());
    };

    //! Returns the vertex of the parabola.
    xgp_Pnt2d^ xgp_Parab2d::Location() {
        return gcnew xgp_Pnt2d(NativeHandle->Location());
    };


    //! Returns the symmetry axis of the parabola.
    //! The "Location" point of this axis is the vertex of the parabola.
    xgp_Ax2d^ xgp_Parab2d::MirrorAxis() {
        gp_Ax2d* temp = new gp_Ax2d(NativeHandle->MirrorAxis());
        return gcnew xgp_Ax2d(temp);
    };


    //! Returns the local coordinate system of the parabola.
    //! The "Location" point of this axis is the vertex of the parabola.
    xgp_Ax22d^ xgp_Parab2d::Axis() {
        gp_Ax22d* temp = new gp_Ax22d(NativeHandle->Axis());
        return gcnew xgp_Ax22d(temp);
    };


    //! Returns the distance between the focus and the
    //! directrix of the parabola.
    Standard_Real xgp_Parab2d::Parameter() {
        return NativeHandle->Parameter();
    };

    void xgp_Parab2d::Reverse() {
        NativeHandle->Reverse();
    };


    //! Reverses the orientation of the local coordinate system
    //! of this parabola (the "Y Direction" is reversed).
    //! Therefore, the implicit orientation of this parabola is reversed.
    //! Note:
    //! -   Reverse assigns the result to this parabola, while
    //! -   Reversed creates a new one.
    xgp_Parab2d^ xgp_Parab2d::Reversed() {
        return gcnew xgp_Parab2d(NativeHandle->Reversed());
    };

    //! Returns true if the local coordinate system is direct
    //! and false in the other case.
    Standard_Boolean xgp_Parab2d::IsDirect() {
        return NativeHandle->IsDirect();
    };

    void xgp_Parab2d::Mirror(xgp_Pnt2d^ P) {
        NativeHandle->Mirror(P->GetPnt2d());
    };


    //! Performs the symmetrical transformation of a parabola with respect
    //! to the point P which is the center of the symmetry
    xgp_Parab2d^ xgp_Parab2d::Mirrored(xgp_Pnt2d^ P) {
        return gcnew xgp_Parab2d(NativeHandle->Mirrored(P->GetPnt2d()));
    };

    void xgp_Parab2d::Mirror(xgp_Ax2d^ A) {
        NativeHandle->Mirror(*A->GetAx2d());
    };


    //! Performs the symmetrical transformation of a parabola with respect
    //! to an axis placement which is the axis of the symmetry.
    xgp_Parab2d^ xgp_Parab2d::Mirrored(xgp_Ax2d^ A) {
        return gcnew xgp_Parab2d(NativeHandle->Mirrored(*A->GetAx2d()));
    };

    void xgp_Parab2d::Rotate(xgp_Pnt2d^ P, Standard_Real Ang) {
        NativeHandle->Rotate(P->GetPnt2d(), Ang);
    };


    //! Rotates a parabola. P is the center of the rotation.
    //! Ang is the angular value of the rotation in radians.
    xgp_Parab2d^ xgp_Parab2d::Rotated(xgp_Pnt2d^ P, Standard_Real Ang) {
        return gcnew xgp_Parab2d(NativeHandle->Rotated(P->GetPnt2d(), Ang));
    };

    void xgp_Parab2d::Scale(xgp_Pnt2d^ P, Standard_Real S) {
        NativeHandle->Scale(P->GetPnt2d(), S);
    };


    //! Scales a parabola. S is the scaling value.
    //! If S is negative the direction of the symmetry axis
    //! "XAxis" is reversed and the direction of the "YAxis" too.
    xgp_Parab2d^ xgp_Parab2d::Scaled(xgp_Pnt2d^ P, Standard_Real S) {
        return gcnew xgp_Parab2d(NativeHandle->Scaled(P->GetPnt2d(), S));
    };

    void xgp_Parab2d::Transform(xgp_Trsf2d^ T) {
        NativeHandle->Transform(T->GetTrsf2d());
    };


    //! Transforms an parabola with the transformation T fromnamespace TKMath  {  public ref class Trsf2d.
    xgp_Parab2d^ xgp_Parab2d::Transformed(xgp_Trsf2d^ T) {
        return gcnew xgp_Parab2d(NativeHandle->Transformed(T->GetTrsf2d()));
    };

    void xgp_Parab2d::Translate(xgp_Vec2d^ V) {
        NativeHandle->Translate(V->GetVec2d());
    };


    //! Translates a parabola in the direction of the vector V.
    //! The magnitude of the translation is the vector's magnitude.
    xgp_Parab2d^ xgp_Parab2d::Translated(xgp_Vec2d^ V) {
        return gcnew xgp_Parab2d(NativeHandle->Translated(V->GetVec2d()));
    };

    void xgp_Parab2d::Translate(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2) {
        NativeHandle->Translate(P1->GetPnt2d(), P2->GetPnt2d());
    };


    //! Translates a parabola from the point P1 to the point P2.
    xgp_Parab2d^ xgp_Parab2d::Translated(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2) {
        return gcnew xgp_Parab2d(NativeHandle->Translated(P1->GetPnt2d(), P2->GetPnt2d()));
    };
};
