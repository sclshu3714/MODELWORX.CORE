#include <XBRepBuilderAPI_MakeSolid.h>

namespace TKTopAlgo {


	//! Initializes the construction of a solid. An empty solid is
	//! considered to cover the whole space. The Add function
	//! is used to define shells to bound it.
	XBRepBuilderAPI_MakeSolid::XBRepBuilderAPI_MakeSolid() {
		NativeHandle = new BRepBuilderAPI_MakeSolid();
		SetMakeShapeHandle(NativeHandle);
	};

	XBRepBuilderAPI_MakeSolid::XBRepBuilderAPI_MakeSolid(BRepBuilderAPI_MakeSolid* handle) {
		NativeHandle = handle;
		SetMakeShapeHandle(NativeHandle);
	};

	void XBRepBuilderAPI_MakeSolid::SetMakeSolidHandle(BRepBuilderAPI_MakeSolid* handle) {
		NativeHandle = handle;
		SetMakeShapeHandle(NativeHandle);
	};

	BRepBuilderAPI_MakeShape* XBRepBuilderAPI_MakeSolid::GetMakeShape() {
		return NativeHandle;
	};

	//! Make a solid from a CompSolid.
	XBRepBuilderAPI_MakeSolid::XBRepBuilderAPI_MakeSolid(XTopoDS_CompSolid^ S) {
		NativeHandle = new BRepBuilderAPI_MakeSolid(*S->GetCompSolid());
		SetMakeShapeHandle(NativeHandle);
	};

	//! Make a solid from a shell.
	XBRepBuilderAPI_MakeSolid::XBRepBuilderAPI_MakeSolid(XTopoDS_Shell^ S) {
		NativeHandle = new BRepBuilderAPI_MakeSolid(*S->GetShell());
		SetMakeShapeHandle(NativeHandle);
	};

	//! Make a solid from two shells.
	XBRepBuilderAPI_MakeSolid::XBRepBuilderAPI_MakeSolid(XTopoDS_Shell^ S1, XTopoDS_Shell^ S2) {
		NativeHandle = new BRepBuilderAPI_MakeSolid(*S1->GetShell(), *S2->GetShell());
		SetMakeShapeHandle(NativeHandle);
	};

	//! Make a solid from three shells.
	//! Constructs a solid
	//! -   covering the whole space, or
	//! -   from shell S, or
	//! -   from two shells S1 and S2, or
	//! -   from three shells S1, S2 and S3, or
	//! Warning
	//! No check is done to verify the conditions of coherence
	//! of the resulting solid. In particular, S1, S2 (and S3) must
	//! not intersect each other.
	//! Besides, after all shells have been added using the Add
	//! function, one of these shells should constitute the outside
	//! skin of the solid; it may be closed (a finite solid) or open
	//! (an infinite solid). Other shells form hollows (cavities) in
	//! these previous ones. Each must bound a closed volume.
	XBRepBuilderAPI_MakeSolid::XBRepBuilderAPI_MakeSolid(XTopoDS_Shell^ S1, XTopoDS_Shell^ S2, XTopoDS_Shell^ S3) {
		NativeHandle = new BRepBuilderAPI_MakeSolid(*S1->GetShell(), *S2->GetShell(), *S3->GetShell());
		SetMakeShapeHandle(NativeHandle);
	};

	//! Make a solid from a solid. Usefull for adding later.
	XBRepBuilderAPI_MakeSolid::XBRepBuilderAPI_MakeSolid(XTopoDS_Solid^ So) {
		NativeHandle = new BRepBuilderAPI_MakeSolid(*So->GetSolid());
		SetMakeShapeHandle(NativeHandle);
	};

	//! Add a shell to a solid.
	//!
	//! Constructs a solid:
	//! -   from the solid So, to which shells can be added, or
	//! -   by adding the shell S to the solid So.
	//! Warning
	//! No check is done to verify the conditions of coherence
	//! of the resulting solid. In particular S must not intersect the solid S0.
	//! Besides, after all shells have been added using the Add
	//! function, one of these shells should constitute the outside
	//! skin of the solid. It may be closed (a finite solid) or open
	//! (an infinite solid). Other shells form hollows (cavities) in
	//! the previous ones. Each must bound a closed volume.
	XBRepBuilderAPI_MakeSolid::XBRepBuilderAPI_MakeSolid(XTopoDS_Solid^ So, XTopoDS_Shell^ S) {
		NativeHandle = new BRepBuilderAPI_MakeSolid(*So->GetSolid(), *S->GetShell());
		SetMakeShapeHandle(NativeHandle);
	};

	//! Adds the shell to the current solid.
	//! Warning
	//! No check is done to verify the conditions of coherence
	//! of the resulting solid. In particular, S must not intersect
	//! other shells of the solid under construction.
	//! Besides, after all shells have been added, one of
	//! these shells should constitute the outside skin of the
	//! solid. It may be closed (a finite solid) or open (an
	//! infinite solid). Other shells form hollows (cavities) in
	//! these previous ones. Each must bound a closed volume.
	void XBRepBuilderAPI_MakeSolid::Add(XTopoDS_Shell^ S) {
		NativeHandle->Add(*S->GetShell());
	};

	//! Returns true if the solid is built.
	//! For this class, a solid under construction is always valid.
	//! If no shell has been added, it could be a whole-space
	//! solid. However, no check was done to verify the
	//! conditions of coherence of the resulting solid.
	Standard_Boolean XBRepBuilderAPI_MakeSolid::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the new Solid.
	XTopoDS_Solid^ XBRepBuilderAPI_MakeSolid::Solid() {
		TopoDS_Solid* aSolid = new TopoDS_Solid(NativeHandle->Solid());
		return gcnew XTopoDS_Solid(aSolid);
	};
	XBRepBuilderAPI_MakeSolid::operator XTopoDS_Solid^() {
		TopoDS_Solid* aSolid = new TopoDS_Solid(NativeHandle->Solid());
		return gcnew XTopoDS_Solid(aSolid);
	};

	Standard_Boolean XBRepBuilderAPI_MakeSolid::IsDeleted(XTopoDS_Shape^ S) {
		return NativeHandle->IsDeleted(*S->GetShape());
	};
}
