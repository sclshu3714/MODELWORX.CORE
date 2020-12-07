#include <XAIS_Animation.h>

namespace TKV3d {
    //! Creates empty animation.
    XAIS_Animation::XAIS_Animation(XTCollection_AsciiString^ theAnimationName) {
        NativeHandle() = new AIS_Animation(*theAnimationName->GetAsciiString());
    };

    //! Destruct object, clear arguments
    XAIS_Animation::~XAIS_Animation() {
        NativeHandle() = NULL;
    };

    XAIS_Animation::XAIS_Animation(Handle(AIS_Animation) pos) {
        NativeHandle() = pos;
    };

    void XAIS_Animation::SetAnimationHandle(Handle(AIS_Animation) pos) {
        NativeHandle() = pos;
    };

    Handle(AIS_Animation) XAIS_Animation::GetAnimation() {
        return NativeHandle();
    };

    //! Animation name.
    XTCollection_AsciiString^ XAIS_Animation::Name() {
        TCollection_AsciiString* temp = new TCollection_AsciiString(NativeHandle()->Name());
        return gcnew XTCollection_AsciiString(temp);
    };

    //! @return start time of the animation in the timeline
    Standard_Real XAIS_Animation::StartPts() {
        return NativeHandle()->StartPts();
    };

    //! Sets time limits for animation in the animation timeline
    void XAIS_Animation::SetStartPts(Standard_Real thePtsStart) {
        NativeHandle()->SetStartPts(thePtsStart);
    };

    //! @return duration of the animation in the timeline
    Standard_Real XAIS_Animation::Duration() {
        return NativeHandle()->Duration();
    };

    //! Update total duration considering all animations on timeline.
    void XAIS_Animation::UpdateTotalDuration() {
        NativeHandle()->UpdateTotalDuration();
    };

    //! Return true if duration is defined.
    Standard_Boolean XAIS_Animation::HasOwnDuration() {
        return NativeHandle()->HasOwnDuration();
    };

    //! @return own duration of the animation in the timeline
    Standard_Real XAIS_Animation::OwnDuration() {
        return NativeHandle()->OwnDuration();
    };

    //! Defines duration of the animation.
    void XAIS_Animation::SetOwnDuration(Standard_Real theDuration) {
        NativeHandle()->SetOwnDuration(theDuration);
    };

    //! Add single animation to the timeline.
    //! @param theAnimation input animation
    void XAIS_Animation::Add(XAIS_Animation^ theAnimation) {
        NativeHandle()->Add(theAnimation->GetAnimation());
    };

    //! Clear animation timeline - remove all animations from it.
    void XAIS_Animation::Clear() {
        NativeHandle()->Clear();
    };

    //! Return the child animation with the given name.
    XAIS_Animation^ XAIS_Animation::Find(XTCollection_AsciiString^ theAnimationName) {
        AIS_Animation* temp = new AIS_Animation(*theAnimationName->GetAsciiString());
        return gcnew XAIS_Animation(temp);
    };

    //! Remove the child animation.
    Standard_Boolean XAIS_Animation::Remove(XAIS_Animation^ theAnimation) {
        return NativeHandle()->Remove(theAnimation->GetAnimation());
    };

    //! Replace the child animation.
    Standard_Boolean XAIS_Animation::Replace(XAIS_Animation^ theAnimationOld, XAIS_Animation^ theAnimationNew) {
        return NativeHandle()->Replace(theAnimationOld->GetAnimation(), theAnimationNew->GetAnimation());
    };

    //! Clears own children and then copy child animations from another object.
    //! Copy also Start Time and Duration values.
    void XAIS_Animation::CopyFrom(XAIS_Animation^ theOther) {
        NativeHandle()->CopyFrom(theOther->GetAnimation());
    };

    //! Return sequence of child animations.
    //NCollection_Sequence<Handle(AIS_Animation)>& Children() const { return myAnimations; }
    List<XAIS_Animation^>^ XAIS_Animation::Children() {
        NCollection_Sequence<Handle(AIS_Animation)> temps =  NativeHandle()->Children();
        List<XAIS_Animation^>^ XAnimation = gcnew List<XAIS_Animation^>();
        for each (Handle(AIS_Animation) temp in temps)
            XAnimation->Add(gcnew XAIS_Animation(temp));
        return XAnimation;
    };

    //! Start animation with internally defined timer instance.
    //! Calls ::Start() internally.
    //!
    //! Note, that this method initializes a timer calculating an elapsed time (presentation timestamps within AIS_Animation::UpdateTimer()),
    //! not a multimedia timer executing Viewer updates at specific intervals!
    //! Viewer redrawing should be managed at application level, so that AIS_Animation::UpdateTimer() is called once right before each redrawing of a Viewer content.
    //!
    //! @param theStartPts    starting timer position (presentation timestamp)
    //! @param thePlaySpeed   playback speed (1.0 means normal speed)
    //! @param theToUpdate    flag to update defined animations to specified start position
    //! @param theToStopTimer flag to pause timer at the starting position
    //! Standard_Boolean theToStopTimer = Standard_False
    void XAIS_Animation::StartTimer(Standard_Real theStartPts, Standard_Real thePlaySpeed, Standard_Boolean theToUpdate, Standard_Boolean theToStopTimer) {
        NativeHandle()->StartTimer(theStartPts, thePlaySpeed, theToUpdate, theToStopTimer);
    };

    //! Update single frame of animation, update timer state
    //! @return current time of timeline progress.
    Standard_Real XAIS_Animation::UpdateTimer() {
        return NativeHandle()->UpdateTimer();
    };

    //! Return elapsed time.
    Standard_Real XAIS_Animation::ElapsedTime() {
        return NativeHandle()->ElapsedTime();
    };

    //! Start animation. This method changes status of the animation to Started.
    //! This status defines whether animation is to be performed in the timeline or not.
    //! @param theToUpdate call Update() method
    void XAIS_Animation::Start(Standard_Boolean theToUpdate) {
        NativeHandle()->Start(theToUpdate);
    };

    //! Pause the process timeline.
    void XAIS_Animation::Pause() {
        NativeHandle()->Pause();
    };

    //! Stop animation. This method changed status of the animation to Stopped.
    //! This status shows that animation will not be performed in the timeline or it is finished.
    void XAIS_Animation::Stop() {
        NativeHandle()->Stop();
    };

    //! Check if animation is to be performed in the animation timeline.
    //! @return True if it is stopped of finished.
    bool XAIS_Animation::IsStopped() {
        return NativeHandle()->IsStopped();
    };

    //! Update single frame of animation, update timer state
    //! @param thePts [in] the time moment within [0; Duration()]
    //! @return True if timeline is in progress
    Standard_Boolean XAIS_Animation::Update(Standard_Real thePts) {
        return NativeHandle()->Update(thePts);
    };
}