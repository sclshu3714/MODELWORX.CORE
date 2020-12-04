#include <xgp_Lin.h>

namespace TKMath
{
    //! Creates a Line corresponding to Z axis of the
    //! reference coordinate system.
    xgp_Lin::xgp_Lin(){ 
        NativeHandle = new gp_Lin();
    };

    /// <summary>
    /// 指针映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Lin::xgp_Lin(gp_Lin* pos){
        NativeHandle = new gp_Lin(*pos);
    };

    //! Creates a line defined by axis A1.
    xgp_Lin::xgp_Lin(xgp_Ax1^ A1){
        NativeHandle = new gp_Lin(*A1->GetAx1());
    };

    //! Creates a line passing through point P and parallel to
    //! vector V (P and V are, respectively, the origin and
    //! the unit vector of the positioning axis of the line).
    xgp_Lin::xgp_Lin(xgp_Pnt^ P, xgp_Dir^ V){
        NativeHandle = new gp_Lin(P->GetPnt(), *V->GetDir());
    };

    //释放
    xgp_Lin::~xgp_Lin(){
        if (NativeHandle != NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };
    //释放
    xgp_Lin::!xgp_Lin(){
        if (NativeHandle != NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };

    //! gp_Lin
    gp_Lin* xgp_Lin::GetLin(){
        return NativeHandle;
    };

    void xgp_Lin::Reverse(){
        return NativeHandle->Reverse();
    };

    //! Reverses the direction of the line.
    //! Note:
    //! -   Reverse assigns the result to this line, while
    //! -   Reversed creates a new one.
    xgp_Lin^ xgp_Lin::Reversed(){
        gp_Lin* temp = new gp_Lin(NativeHandle->Reversed());
        return gcnew xgp_Lin(temp);
    };

    //! Changes the direction of the line.
    void xgp_Lin::SetDirection(xgp_Dir^ V){
        return NativeHandle->SetDirection(*V->GetDir());
    };

    //! Changes the location point (origin) of the line.
    void xgp_Lin::SetLocation(xgp_Pnt^ P){
        return NativeHandle->SetLocation(P->GetPnt());
    };


    //! Complete redefinition of the line.
    //! The "Location" point of <A1> is the origin of the line.
    //! The "Direction" of <A1> is  the direction of the line.
    void xgp_Lin::SetPosition(xgp_Ax1^ A1){
        return NativeHandle->SetPosition(*A1->GetAx1());
    };

    //! Returns the direction of the line.
    xgp_Dir^ xgp_Lin::Direction(){ 
        gp_Dir* temp = new gp_Dir(NativeHandle->Direction());
        return gcnew xgp_Dir(temp);
    };


    //! Returns the location point (origin) of the line.
    xgp_Pnt^ xgp_Lin::Location(){
        return gcnew xgp_Pnt(NativeHandle->Location());
    };


    //! Returns the axis placement one axis whith the same
    //! location and direction as <me>.
    xgp_Ax1^ xgp_Lin::Position(){
        gp_Ax1* temp = new gp_Ax1(NativeHandle->Position());
        return gcnew xgp_Ax1(temp);
    };

    //! Computes the angle between two lines in radians.
    Standard_Real xgp_Lin::Angle(xgp_Lin^ Other){
        return NativeHandle->Angle(*Other->GetLin());
    };

    //! Returns true if this line contains the point P, that is, if the
    //! distance between point P and this line is less than or
    //! equal to LinearTolerance..
    Standard_Boolean xgp_Lin::Contains(xgp_Pnt^ P, Standard_Real LinearTolerance){ 
        return NativeHandle->Contains(P->GetPnt(), LinearTolerance);
    };

    //! Computes the distance between <me> and the point P.
    Standard_Real xgp_Lin::Distance(xgp_Pnt^ P){
        return NativeHandle->Distance(P->GetPnt());
    };

    //! Computes the distance between two lines.
    Standard_Real xgp_Lin::Distance(xgp_Lin^ Other){
        return NativeHandle->Distance(*Other->GetLin());
    };


    //! Computes the square distance between <me> and the point P.
    Standard_Real xgp_Lin::SquareDistance(xgp_Pnt^ P){
        return NativeHandle->SquareDistance(P->GetPnt());
    };

    //! Computes the square distance between two lines.
    Standard_Real xgp_Lin::SquareDistance(xgp_Lin^ Other){
        return NativeHandle->SquareDistance(*Other->GetLin());
    };


    //! Computes the line normal to the direction of <me>, passing
    //! through the point P.  Raises ConstructionError
    //! if the distance between <me> and the point P is lower
    //! or equal to Resolution from gp because there is an infinity of
    //! solutions in 3D space.
    xgp_Lin^ xgp_Lin::Normal(xgp_Pnt^ P){ 
        gp_Lin* temp = new gp_Lin(NativeHandle->Normal(P->GetPnt()));
        return gcnew xgp_Lin(temp);
    };

    void xgp_Lin::Mirror(xgp_Pnt^ P){  
        NativeHandle->Mirror(P->GetPnt());
    };


    //! Performs the symmetrical transformation of a line
    //! with respect to the point P which is the center of
    //! the symmetry.
    xgp_Lin^ xgp_Lin::Mirrored(xgp_Pnt^ P){
        gp_Lin* temp = new gp_Lin(NativeHandle->Mirrored(P->GetPnt()));
        return gcnew xgp_Lin(temp);
    };

    void xgp_Lin::Mirror(xgp_Ax1^ A1){  
        NativeHandle->Mirror(*A1->GetAx1());
    };


    //! Performs the symmetrical transformation of a line
    //! with respect to an axis placement which is the axis
    //! of the symmetry.
    xgp_Lin^ xgp_Lin::Mirrored(xgp_Ax1^ A1){ 
        gp_Lin* temp = new gp_Lin(NativeHandle->Mirrored(*A1->GetAx1()));
        return gcnew xgp_Lin(temp);
    };

    void xgp_Lin::Mirror(xgp_Ax2^ A2){ 
        NativeHandle->Mirrored(*A2->GetAx2());
    };


    //! Performs the symmetrical transformation of a line
    //! with respect to a plane. The axis placement  <A2>
    //! locates the plane of the symmetry :
    //! (Location, XDirection, YDirection).
    xgp_Lin^ xgp_Lin::Mirrored(xgp_Ax2^ A2){ 
        gp_Lin* temp = new gp_Lin(NativeHandle->Mirrored(*A2->GetAx2()));
        return gcnew xgp_Lin(temp);
    };

    void xgp_Lin::Rotate(xgp_Ax1^ A1, Standard_Real Ang){ 
        NativeHandle->Rotate(*A1->GetAx1(), Ang);
    };


    //! Rotates a line. A1 is the axis of the rotation.
    //! Ang is the angular value of the rotation in radians.
    xgp_Lin^ xgp_Lin::Rotated(xgp_Ax1^ A1, Standard_Real Ang){  
        gp_Lin* temp = new gp_Lin(NativeHandle->Rotated(*A1->GetAx1(), Ang));
        return gcnew xgp_Lin(temp);
    };

    void xgp_Lin::Scale(xgp_Pnt^ P, Standard_Real S){ 
        NativeHandle->Scale(P->GetPnt(), S);
    };


    //! Scales a line. S is the scaling value.
    //! The "Location" point (origin) of the line is modified.
    //! The "Direction" is reversed if the scale is negative.
    xgp_Lin^ xgp_Lin::Scaled(xgp_Pnt^ P, Standard_Real S){ 
        gp_Lin* temp = new gp_Lin(NativeHandle->Scaled(P->GetPnt(), S));
        return gcnew xgp_Lin(temp);
    };

    void xgp_Lin::Transform(xgp_Trsf^ T){  
        NativeHandle->Transform(T->GetTrsf());
    };


    //! Transforms a line with the transformation T fromnamespace TKMath  {  public ref class Trsf.
    xgp_Lin^ xgp_Lin::Transformed(xgp_Trsf^ T){ 
        gp_Lin* temp = new gp_Lin(NativeHandle->Transformed(T->GetTrsf()));
        return gcnew xgp_Lin(temp);
    };

    void xgp_Lin::Translate(xgp_Vec^ V){ 
        NativeHandle->Translate(V->GetVec());
    };


    //! Translates a line in the direction of the vector V.
    //! The magnitude of the translation is the vector's magnitude.
    xgp_Lin^ xgp_Lin::Translated(xgp_Vec^ V){  
        gp_Lin* temp = new gp_Lin(NativeHandle->Translated(V->GetVec()));
        return gcnew xgp_Lin(temp);
    };

    void xgp_Lin::Translate(xgp_Pnt^ P1, xgp_Pnt^ P2){ 
        NativeHandle->Translate(P1->GetPnt(), P2->GetPnt());
    };


    //! Translates a line from the point P1 to the point P2.
    xgp_Lin^ xgp_Lin::Translated(xgp_Pnt^ P1, xgp_Pnt^ P2){  
        gp_Lin* temp = new gp_Lin(NativeHandle->Translated(P1->GetPnt(), P2->GetPnt()));
        return gcnew xgp_Lin(temp);
    };
};
