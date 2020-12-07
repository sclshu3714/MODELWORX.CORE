#include <XAIS_AnimationCamera.h>
namespace TKV3d {

    //! Main constructor.
    XAIS_AnimationCamera::XAIS_AnimationCamera(XTCollection_AsciiString^ theAnimationName, XV3d_View^ theView) {
        NativeHandle() = new AIS_AnimationCamera(*theAnimationName->GetAsciiString(), theView->GetV3dView());
        SetAnimationHandle(NativeHandle());
    };

    //! Return the target view.
    XV3d_View^ XAIS_AnimationCamera::View() {
        V3d_View* temp = new V3d_View(*NativeHandle()->View());
        return gcnew XV3d_View(temp);
    };

    //! Set target view.
    void XAIS_AnimationCamera::SetView(XV3d_View^ theView) {
        NativeHandle()->SetView(theView->GetV3dView());
    };

    //! Return camera start position.
    Handle(Graphic3d_Camera) XAIS_AnimationCamera::CameraStart() {
        return  NativeHandle()->CameraStart();
    };

    //! Define camera start position.
    void XAIS_AnimationCamera::SetCameraStart(const Handle(Graphic3d_Camera)& theCameraStart) {
        NativeHandle()->SetCameraStart(theCameraStart);
    };

    //! Return camera end position.
    Handle(Graphic3d_Camera) XAIS_AnimationCamera::CameraEnd() {
        return  NativeHandle()->CameraEnd();
    };

    //! Define camera end position.
    void XAIS_AnimationCamera::SetCameraEnd(const Handle(Graphic3d_Camera)& theCameraEnd) {
        NativeHandle()->SetCameraEnd(theCameraEnd);
    };
}
