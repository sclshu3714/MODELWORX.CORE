#include <XAIS_AnimationObject.h>

namespace TKV3d {
    /*XAIS_AnimationObject::XAIS_AnimationObject(XTCollection_AsciiString^ theAnimationName) : XAIS_Animation(theAnimationName){
        NativeHandle() = new AIS_AnimationObject();
        SetAnimationHandle(NativeHandle());
    };

    XAIS_AnimationObject::XAIS_AnimationObject(Handle(AIS_AnimationObject) pos) {
        NativeHandle() = pos;
        SetAnimationHandle(NativeHandle());
    };*/

    void XAIS_AnimationObject::SetAnimationObjectHandle(Handle(AIS_AnimationObject) pos) {
        NativeHandle() = pos;
        SetAnimationHandle(NativeHandle());
    };

    Handle(AIS_AnimationObject) XAIS_AnimationObject::GetAnimationObject() {
        return NativeHandle();
    };

    Handle(AIS_Animation) XAIS_AnimationObject::GetAnimation() {
        return NativeHandle();
    };

    //! Constructor with initialization.
    //! Note that start/end transformations specify exactly local transformation of the object,
    //! not the transformation to be applied to existing local transformation.
    //! @param theAnimationName animation identifier
    //! @param theContext       interactive context where object have been displayed
    //! @param theObject        object to apply local transformation
    //! @param theTrsfStart     local transformation at the start of animation (e.g. theObject->LocalTransformation())
    //! @param theTrsfEnd       local transformation at the end   of animation
    XAIS_AnimationObject::XAIS_AnimationObject(XTCollection_AsciiString^ theAnimationName, XAIS_InteractiveContext^ theContext, XAIS_InteractiveObject^ theObject, xgp_Trsf^ theTrsfStart, xgp_Trsf^ theTrsfEnd) {
        NativeHandle() = new AIS_AnimationObject(*theAnimationName->GetAsciiString(), theContext->GetInteractiveContext(), theObject->GetInteractiveObject(), *theTrsfStart->GetTrsf(), *theTrsfEnd->GetTrsf());
        SetAnimationHandle(NativeHandle());
    };
}