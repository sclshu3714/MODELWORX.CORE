#include "XAIS_InteractiveObject.h"

namespace TKV3d {
	//! 
	XAIS_InteractiveObject::XAIS_InteractiveObject(void) {
	};

	//!
	XAIS_InteractiveObject::XAIS_InteractiveObject(Handle(AIS_InteractiveObject) pos) {
		NativeHandle() = pos;
		SetSelectMgr_SelectableObjectNativeHandle(NativeHandle());
	};


	//!
	XAIS_InteractiveObject::~XAIS_InteractiveObject() {
		NativeHandle() = NULL;
	};

	//!
	void XAIS_InteractiveObject::SetNativeHandle(Handle(AIS_InteractiveObject) pos) {
		NativeHandle() = pos;
		SetSelectMgr_SelectableObjectNativeHandle(NativeHandle());
	};


	Handle(AIS_InteractiveObject) XAIS_InteractiveObject::GetInteractiveObject() {
		return NativeHandle();
	};

	//! Returns the kind of Interactive Object; AIS_KOI_None by default.
	XAIS_KindOfInteractive XAIS_InteractiveObject::Type() {
		return safe_cast<XAIS_KindOfInteractive>(NativeHandle()->Type());
	};

	//! Specifies additional characteristics of Interactive Object of Type(); -1 by default.
	//! Among the datums, this signature is attributed to the shape.
	//! The remaining datums have the following default signatures:
	//! - Point          signature 1
	//! - Axis           signature 2
	//! - Trihedron      signature 3
	//! - PlaneTrihedron signature 4
	//! - Line           signature 5
	//! - Circle         signature 6
	//! - Plane          signature 7.
	Standard_Integer XAIS_InteractiveObject::Signature() {
		return NativeHandle()->Signature();
	};

	//! Updates the active presentation; if <AllModes> = Standard_True
	//! all the presentations inside are recomputed.
	//! IMPORTANT: It is preferable to call Redisplay method of
	//! corresponding AIS_InteractiveContext instance for cases when it
	//! is accessible. This method just redirects call to myCTXPtr,
	//! so this class field must be up to date for proper result.
	void XAIS_InteractiveObject::Redisplay(Standard_Boolean^ AllModes) {
		NativeHandle()->Redisplay(*AllModes);
	};

	//! Indicates whether the Interactive Object has a pointer to an interactive context.
	Standard_Boolean^ XAIS_InteractiveObject::HasInteractiveContext() {
		return NativeHandle()->HasInteractiveContext();
	};

	//! Returns the context pointer to the interactive context.
	AIS_InteractiveContext* XAIS_InteractiveObject::InteractiveContext() {
		return NativeHandle()->InteractiveContext();
	};

	//! Returns true if the object has an owner attributed to it.
	//! The owner can be a shape for a set of sub-shapes or a sub-shape for sub-shapes which it is composed of, and takes the form of a transient.
	Standard_Boolean^ XAIS_InteractiveObject::HasOwner() {
		return NativeHandle()->HasOwner();
	};

	//! Returns the owner of the Interactive Object.
	//! The owner can be a shape for a set of sub-shapes or
	//! a sub-shape for sub-shapes which it is composed of,
	//! and takes the form of a transient.
	//! There are two types of owners:
	//! -   Direct owners, decomposition shapes such as
	//! edges, wires, and faces.
	//! -   Users, presentable objects connecting to sensitive
	//! primitives, or a shape which has been decomposed.
	Handle(Standard_Transient) XAIS_InteractiveObject::GetOwner() {
		return NativeHandle()->GetOwner();
	};

	//! Allows you to attribute the owner theApplicativeEntity to
	//! an Interactive Object. This can be a shape for a set of
	//! sub-shapes or a sub-shape for sub-shapes which it
	//! is composed of. The owner takes the form of a transient.
	void XAIS_InteractiveObject::SetOwner(Handle(Standard_Transient) theApplicativeEntity) {
		return NativeHandle()->SetOwner(theApplicativeEntity);
	};

	//! Each Interactive Object has methods which allow us to attribute an Owner to it in the form of a Transient.
	//! This method removes the owner from the graphic entity.
	void XAIS_InteractiveObject::ClearOwner() {
		NativeHandle()->ClearOwner();
	};


	//! Returns the context pointer to the interactive context.
	Handle(AIS_InteractiveContext) XAIS_InteractiveObject::GetContext() {
		return NativeHandle()->GetContext();
	};
	////=======================================================================
	////function : SetContext
	////purpose  :
	////=======================================================================
	void XAIS_InteractiveObject::SetContext(Handle(AIS_InteractiveContext) theCtx) {
		NativeHandle()->SetContext(theCtx);
	};


	//! Returns TRUE when this object has a presentation in the current DisplayMode()
	Standard_Boolean^ XAIS_InteractiveObject::HasPresentation() {
		return NativeHandle()->HasPresentation();
	};

	//! Returns the current presentation of this object according to the current DisplayMode()
	Handle(Prs3d_Presentation) XAIS_InteractiveObject::Presentation() {
		return NativeHandle()->Presentation();
	};

	//=======================================================================
	//function : DumpJson
	//purpose  : 
	//=======================================================================
	void XAIS_InteractiveObject::DumpJson(Standard_OStream theOStream, Standard_Integer theDepth)
	{
		NativeHandle()->DumpJson(theOStream, theDepth);
	}
}