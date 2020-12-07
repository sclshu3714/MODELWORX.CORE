// Created by: Anastasia BORISOVA
// Copyright (c) 2016 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.

#ifndef _XAIS_Animation_HeaderFile
#define _XAIS_Animation_HeaderFile
#pragma once
#include <AIS_Animation.hxx>
#include <XTCollection_AsciiString.h>
#include <NCollection_Haft.h>
//#include <XNCollection_Sequence.h>

#include <AIS_AnimationTimer.hxx>
#include <NCollection_Sequence.hxx>
#include <TCollection_AsciiString.hxx>
class AIS_Animation;

using namespace TKernel;
namespace TKV3d {
    //! Structure defining current animation progress.
    public ref struct XAIS_AnimationProgress
    {
        Standard_Real Pts;             //!< global presentation timestamp
        Standard_Real LocalPts;        //!< presentation within current animation
        Standard_Real LocalNormalized; //!< normalized position within current animation within 0..1 range

        XAIS_AnimationProgress() : Pts(-1.0), LocalPts(-1.0), LocalNormalized(-1.0) {}
    };

    //! Defines animation state.
    public enum class XAnimationState
    {
        AnimationState_Started, //!< animation is in progress
        AnimationState_Stopped, //!< animation is finished, force stopped or not started
        AnimationState_Paused   //!< animation is paused and can be started from the pause moment
    };

    //! DEFINE_STANDARD_HANDLE(AIS_Animation, Standard_Transient)

    //! Class represents a basic animation class.
    //! AIS_Animation can be used as:
    //!
    //! - Animation Implementor
    //!   Sub-classes should override method AIS_Animation::update() to perform specific animation.
    //!   AIS package provides limited number of such animation atoms - classes AIS_AnimationObject and AIS_AnimationCamera, which could be enough for defining a simple animation.
    //!   In general case, application is expected defining own AIS_Animation sub-classes implementing application-specific animation logic
    //!   (e.g. another interpolation or another kind of transformations - like color transition and others).
    //!   The basic conception of AIS_Animation::update() is defining an exact scene state for the current presentation timestamp,
    //!   providing a smooth and continuous animation well defined at any time step and in any direction.
    //!   So that a time difference between two sequential drawn Viewer frames can vary from frame to frame without visual artifacts,
    //!   increasing rendering framerate would not lead to animation being executed too fast
    //!   and low framerate (on slow hardware) would not lead to animation played longer than defined duration.
    //!   Hence, implementation should avoid usage of incremental step logic or should apply it very carefully.
    //!
    //! - Animation Container
    //!   AIS_Animation (no sub-classing) can be used to aggregate a sequence of Animation items (children).
    //!   Each children should be defined with its own duration and start time (presentation timestamp).
    //!   It is possible defining collection of nested AIS_Animation items, so that within each container level
    //!   children define start playback time relative to its holder.
    //!
    //! - Animation playback Controller
    //!   It is suggested that application would define a single AIS_Animation instance (optional sub-classing) for controlling animation playback as whole.
    //!   Such controller should be filled in by other AIS_Animation as children objects,
    //!   and will be managed by application by calling StartTimer(), UpdateTimer() and IsStopped() methods.
    //!
    //! Note, that AIS_Animation::StartTimer() defines a timer calculating an elapsed time, not a multimedia timer executing Viewer updates at specific intervals!
    //! Application should avoid using implicit and immediate Viewer updates to ensure that AIS_Animation::UpdateTimer() is called before each redrawing of a Viewer content.
    //! Redrawing logic should be also managed at application level for managing a smooth animation
    //! (by defining a multimedia timer provided by used GUI framework executing updates at desired framerate, or as continuous redraws in loop).
    ref class TKernel::XTCollection_AsciiString;
    public ref class XAIS_Animation //: public Standard_Transient
    {
        //! DEFINE_STANDARD_RTTIEXT(AIS_Animation, Standard_Transient)
    public:

        //! Creates empty animation.
        XAIS_Animation(XTCollection_AsciiString^ theAnimationName);

        //! Destruct object, clear arguments
        virtual ~XAIS_Animation();

        XAIS_Animation(Handle(AIS_Animation) pos);

        void SetAnimationHandle(Handle(AIS_Animation) pos);

        Handle(AIS_Animation) GetAnimation();

        //! Animation name.
        XTCollection_AsciiString^ Name();

        //! @return start time of the animation in the timeline
        Standard_Real StartPts();

        //! Sets time limits for animation in the animation timeline
        void SetStartPts(Standard_Real thePtsStart);

        //! @return duration of the animation in the timeline
        Standard_Real Duration();

        //! Update total duration considering all animations on timeline.
        void UpdateTotalDuration();

        //! Return true if duration is defined.
        Standard_Boolean HasOwnDuration();

        //! @return own duration of the animation in the timeline
        Standard_Real OwnDuration();

        //! Defines duration of the animation.
        void SetOwnDuration(Standard_Real theDuration);

        //! Add single animation to the timeline.
        //! @param theAnimation input animation
        void Add(XAIS_Animation^ theAnimation);

        //! Clear animation timeline - remove all animations from it.
        void Clear();

        //! Return the child animation with the given name.
        XAIS_Animation^ Find(XTCollection_AsciiString^ theAnimationName);

        //! Remove the child animation.
        Standard_Boolean Remove(XAIS_Animation^ theAnimation);

        //! Replace the child animation.
        Standard_Boolean Replace(XAIS_Animation^ theAnimationOld, XAIS_Animation^ theAnimationNew);

        //! Clears own children and then copy child animations from another object.
        //! Copy also Start Time and Duration values.
        void CopyFrom(XAIS_Animation^ theOther);

        //! Return sequence of child animations.
        List<XAIS_Animation^>^ Children();
        //NCollection_Sequence<Handle(AIS_Animation)>& Children() const { return myAnimations; }

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
        virtual void StartTimer(Standard_Real theStartPts, Standard_Real thePlaySpeed, Standard_Boolean theToUpdate, Standard_Boolean theToStopTimer);

        //! Update single frame of animation, update timer state
        //! @return current time of timeline progress.
        virtual Standard_Real UpdateTimer();

        //! Return elapsed time.
        Standard_Real ElapsedTime();

        //! Start animation. This method changes status of the animation to Started.
        //! This status defines whether animation is to be performed in the timeline or not.
        //! @param theToUpdate call Update() method
        virtual void Start(Standard_Boolean theToUpdate);

        //! Pause the process timeline.
        virtual void Pause();

        //! Stop animation. This method changed status of the animation to Stopped.
        //! This status shows that animation will not be performed in the timeline or it is finished.
        virtual void Stop();

        //! Check if animation is to be performed in the animation timeline.
        //! @return True if it is stopped of finished.
        bool IsStopped();

        //! Update single frame of animation, update timer state
        //! @param thePts [in] the time moment within [0; Duration()]
        //! @return True if timeline is in progress
        virtual Standard_Boolean Update(Standard_Real thePts);

        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property Handle(Standard_Transient) IHandle {
            Handle(Standard_Transient) get() { // Standard_OVERRIDE {
                return NativeHandle();
            }
            void set(Handle(Standard_Transient) handle) { // Standard_OVERRIDE {
                NativeHandle() = Handle(AIS_Animation)::DownCast(handle);
            }
        }
    private:
        NCollection_Haft<Handle(AIS_Animation)> NativeHandle;
    };
}
#endif // _XAIS_Animation_HeaderFile
