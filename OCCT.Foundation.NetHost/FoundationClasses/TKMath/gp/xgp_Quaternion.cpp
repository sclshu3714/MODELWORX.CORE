#include <xgp_Quaternion.h>

namespace TKMath
{
    //! Creates an identity quaternion
    xgp_Quaternion::xgp_Quaternion(void) {
        NativeHandle = new gp_Quaternion();
    };

    /// <summary>
    /// 指针映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Quaternion::xgp_Quaternion(gp_Quaternion* pos) {
        NativeHandle = new gp_Quaternion(*pos);
    };

    // !Creates quaternion
    xgp_Quaternion::xgp_Quaternion(gp_Quaternion pos) {
        NativeHandle = new gp_Quaternion(pos);
    };

    //! Creates quaternion directly from component values
    xgp_Quaternion::xgp_Quaternion(Standard_Real^ x, Standard_Real^ y, Standard_Real^ z, Standard_Real^ w) {
        NativeHandle = new gp_Quaternion(*x, *y, *z, *w);
    };

    //! Creates copy of another quaternion
    xgp_Quaternion::xgp_Quaternion(xgp_Quaternion^ theToCopy) {
        NativeHandle = new gp_Quaternion(theToCopy->GetQuaternion());
    };

    //! Creates quaternion representing shortest-arc rotation
    //! operator producing vector theVecTo from vector theVecFrom.
    xgp_Quaternion::xgp_Quaternion(xgp_Vec^ theVecFrom, xgp_Vec^ theVecTo) {
        NativeHandle = new gp_Quaternion(theVecFrom->GetVec(), theVecTo->GetVec());
    };

    //! Creates quaternion representing shortest-arc rotation
    //! operator producing vector theVecTo from vector theVecFrom.
    //! Additional vector theHelpCrossVec defines preferred direction for
    //! rotation and is used when theVecTo and theVecFrom are directed
    //! oppositely.
    xgp_Quaternion::xgp_Quaternion(xgp_Vec^ theVecFrom, xgp_Vec^ theVecTo, xgp_Vec^ theHelpCrossVec) {
        NativeHandle = new gp_Quaternion(theVecFrom->GetVec(), theVecTo->GetVec(), theHelpCrossVec->GetVec());
    };

    //! Creates quaternion representing rotation on angle
    //! theAngle around vector theAxis
    xgp_Quaternion::xgp_Quaternion(xgp_Vec^ theAxis, Standard_Real^ theAngle) {
        NativeHandle = new gp_Quaternion(theAxis->GetVec(), *theAngle);
    };

    //! Creates quaternion from rotation matrix 3*3
    //! (which should be orthonormal skew-symmetric matrix)
    xgp_Quaternion::xgp_Quaternion(xgp_Mat^ theMat) {
        NativeHandle = new gp_Quaternion(theMat->GetMat());
    };

    //释放
    xgp_Quaternion::~xgp_Quaternion() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };
    //释放
    xgp_Quaternion::!xgp_Quaternion() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };
    //! Return the gp_Quaternion
    gp_Quaternion xgp_Quaternion::GetQuaternion() {
        return *NativeHandle;
    };

    //! Simple equal test without precision
    Standard_Boolean^ xgp_Quaternion::IsEqual(xgp_Quaternion^ theOther) {
        return NativeHandle->IsEqual(theOther->GetQuaternion());
    };

    //! Sets quaternion to shortest-arc rotation producing
    //! vector theVecTo from vector theVecFrom.
    //! If vectors theVecFrom and theVecTo are opposite then rotation
    //! axis is computed as theVecFrom ^ (1,0,0) or theVecFrom ^ (0,0,1).
    void xgp_Quaternion::SetRotation(xgp_Vec^ theVecFrom, xgp_Vec^ theVecTo) {
        NativeHandle->SetRotation(theVecFrom->GetVec(), theVecTo->GetVec());
    };

    //! Sets quaternion to shortest-arc rotation producing
    //! vector theVecTo from vector theVecFrom.
    //! If vectors theVecFrom and theVecTo are opposite then rotation
    //! axis is computed as theVecFrom ^ theHelpCrossVec.
    void xgp_Quaternion::SetRotation(xgp_Vec^ theVecFrom, xgp_Vec^ theVecTo, xgp_Vec^ theHelpCrossVec) {
        NativeHandle->SetRotation(theVecFrom->GetVec(), theVecTo->GetVec(), theHelpCrossVec->GetVec());
    };

    //! Create a unit quaternion from Axis+Angle representation
    void xgp_Quaternion::SetVectorAndAngle(xgp_Vec^ theAxis, Standard_Real^ theAngle) {
        NativeHandle->SetVectorAndAngle(theAxis->GetVec(), *theAngle);
    };

    //! Convert a quaternion to Axis+Angle representation,
    //! preserve the axis direction and angle from -PI to +PI
    void xgp_Quaternion::GetVectorAndAngle(xgp_Vec^ theAxis, Standard_Real theAngle) {
        NativeHandle->GetVectorAndAngle(theAxis->GetVec(), theAngle);
    };

    //! Create a unit quaternion by rotation matrix
    //! matrix must contain only rotation (not scale or shear)
    //!
    //! For numerical stability we find first the greatest component of quaternion
    //! and than search others from this one
    void xgp_Quaternion::SetMatrix(xgp_Mat^ theMat) {
        NativeHandle->SetMatrix(theMat->GetMat());
    };

    //! Returns rotation operation as 3*3 matrix
    xgp_Mat^ xgp_Quaternion::GetMatrix() {
        return gcnew xgp_Mat(NativeHandle->GetMatrix());
    };

    //! Create a unit quaternion representing rotation defined
    //! by generalized Euler angles
    void xgp_Quaternion::SetEulerAngles(int^ EulerSequence, Standard_Real^ theAlpha, Standard_Real^ theBeta, Standard_Real^ theGamma) {
        NativeHandle->SetEulerAngles((gp_EulerSequence)*EulerSequence, *theAlpha, *theBeta, *theGamma);
    };

    //! Returns Euler angles describing current rotation
    void xgp_Quaternion::GetEulerAngles(int^ EulerSequence, Standard_Real theAlpha, Standard_Real theBeta, Standard_Real theGamma) {
        NativeHandle->GetEulerAngles((gp_EulerSequence)*EulerSequence, theAlpha, theBeta, theGamma);
    };

    void xgp_Quaternion::Set(Standard_Real^ x, Standard_Real^ y, Standard_Real^ z, Standard_Real^ w) {
        NativeHandle->Set(*x, *y, *z, *w);
    };

    void xgp_Quaternion::Set(xgp_Quaternion^ theQuaternion) {
        NativeHandle->Set(theQuaternion->GetQuaternion());
    };

    Standard_Real^ xgp_Quaternion::X() {
        return NativeHandle->X();
    };

    Standard_Real^ xgp_Quaternion::Y() {
        return NativeHandle->Y();
    };

    Standard_Real^ xgp_Quaternion::Z() {
        return NativeHandle->Z();
    };

    Standard_Real^ xgp_Quaternion::W() {
        return NativeHandle->W();
    };

    //! Make identity quaternion (zero-rotation)
    void xgp_Quaternion::SetIdent() {
        return NativeHandle->SetIdent();
    };

    //! Reverse direction of rotation (conjugate quaternion)
    void xgp_Quaternion::Reverse() {
        return NativeHandle->Reverse();
    };

    //! Return rotation with reversed direction (conjugated quaternion)
    xgp_Quaternion^ xgp_Quaternion::Reversed() {
        return gcnew xgp_Quaternion(NativeHandle->Reversed());
    };

    //! Inverts quaternion (both rotation direction and norm)
    void xgp_Quaternion::Invert() {
        return NativeHandle->Invert();
    };

    //! Return inversed quaternion q^-1
    xgp_Quaternion^ xgp_Quaternion::Inverted() {
        return gcnew xgp_Quaternion(NativeHandle->Inverted());
    };

    //! Returns square norm of quaternion
    Standard_Real^ xgp_Quaternion::SquareNorm() {
        return NativeHandle->SquareNorm();
    };

    //! Returns norm of quaternion
    Standard_Real^ xgp_Quaternion::Norm() {
        return NativeHandle->Norm();
    };

    //! Scale all components by quaternion by theScale; note that
    //! rotation is not changed by this operation (except 0-scaling)
    void xgp_Quaternion::Scale(Standard_Real^ theScale) {
        NativeHandle->Scale(*theScale);
    };

    //! Returns scaled quaternion
    xgp_Quaternion^ xgp_Quaternion::Scaled(Standard_Real^ theScale) {
        return gcnew xgp_Quaternion(NativeHandle->Scaled(*theScale));
    };

    //! Stabilize quaternion length within 1 - 1/4.
    //! This operation is a lot faster than normalization
    //! and preserve length goes to 0 or infinity
    void xgp_Quaternion::StabilizeLength() {
        NativeHandle->StabilizeLength();
    };

    //! Scale quaternion that its norm goes to 1.
    //! The appearing of 0 magnitude or near is a error,
    //! so we can be sure that can divide by magnitude
    void xgp_Quaternion::Normalize() {
        NativeHandle->Normalize();
    };

    //! Returns quaternion scaled so that its norm goes to 1.
    xgp_Quaternion^ xgp_Quaternion::Normalized() {
        return gcnew xgp_Quaternion(NativeHandle->Normalized());
    };

    //! Returns quaternion with all components negated.
    //! Note that this operation does not affect neither
    //! rotation operator defined by quaternion nor its norm.
    xgp_Quaternion^ xgp_Quaternion::Negated() {
        return gcnew xgp_Quaternion(NativeHandle->Negated());
    };

    //! Makes sum of quaternion components; result is "rotations mix"
    xgp_Quaternion^ xgp_Quaternion::Added(xgp_Quaternion^ theOther) {
        return gcnew xgp_Quaternion(NativeHandle->Added(theOther->GetQuaternion()));
    };

    //! Makes difference of quaternion components; result is "rotations mix"
    xgp_Quaternion^ xgp_Quaternion::Subtracted(xgp_Quaternion^ theOther) {
        return gcnew xgp_Quaternion(NativeHandle->Subtracted(theOther->GetQuaternion()));
    };

    //! Multiply function - work the same as Matrices multiplying.
    //! qq' = (cross(v,v') + wv' + w'v, ww' - dot(v,v'))
    //! Result is rotation combination: q' than q (here q=this, q'=theQ).
    //! Notices than:
    //! qq' != q'q;
    //! qq^-1 = q;
    xgp_Quaternion^ xgp_Quaternion::Multiplied(xgp_Quaternion^ theOther) {
        return gcnew xgp_Quaternion(NativeHandle->Multiplied(theOther->GetQuaternion()));
    };

    //! Adds componnets of other quaternion; result is "rotations mix"
    void xgp_Quaternion::Add(xgp_Quaternion^ theOther) {
        NativeHandle->Add(theOther->GetQuaternion());
    };


    //! Subtracts componnets of other quaternion; result is "rotations mix"
    void xgp_Quaternion::Subtract(xgp_Quaternion^ theOther) {
         NativeHandle->Subtract(theOther->GetQuaternion());
    };


    //! Adds rotation by multiplication
    void xgp_Quaternion::Multiply(xgp_Quaternion^ theOther) {
        NativeHandle->Multiply(theOther->GetQuaternion());
    };


    //! Computes inner product / scalar product / Dot
    Standard_Real^ xgp_Quaternion::Dot(xgp_Quaternion^ theOther) {
             return NativeHandle->Dot(theOther->GetQuaternion());
    };

    //! Return rotation angle from -PI to PI
    Standard_Real^ xgp_Quaternion::GetRotationAngle() {
        return NativeHandle->GetRotationAngle();
    };

    //! Rotates vector by quaternion as rotation operator
    xgp_Vec^ xgp_Quaternion::Multiply(xgp_Vec^ theVec) {
        return gcnew xgp_Vec(NativeHandle->Multiply(theVec->GetVec()));
    };
};
