#include <XBRepOffsetAPI_MakePipe.h>
namespace TKOffset {
	//DEFINE_STANDARD_ALLOC
	XBRepOffsetAPI_MakePipe::XBRepOffsetAPI_MakePipe() {
		//NativeHandle = new BRepOffsetAPI_MakePipe();
	};

	XBRepOffsetAPI_MakePipe::XBRepOffsetAPI_MakePipe(BRepOffsetAPI_MakePipe* pos) {
		NativeHandle = pos;
		SetMakeSweepHandle(NativeHandle);
	};

	void XBRepOffsetAPI_MakePipe::SetMakePipeHandle(BRepOffsetAPI_MakePipe* pos) {
		NativeHandle = pos;
		SetMakeSweepHandle(NativeHandle);
	};

	BRepOffsetAPI_MakePipe* XBRepOffsetAPI_MakePipe::GetMakePipe() {
		return NativeHandle;
	};

	BRepPrimAPI_MakeSweep* XBRepOffsetAPI_MakePipe::GetMakeSweep() {
		return NativeHandle;
	};

	BRepBuilderAPI_MakeShape* XBRepOffsetAPI_MakePipe::GetMakeShape() {
		return NativeHandle;
	};

	XTopoDS_Shape^ XBRepOffsetAPI_MakePipe::Shape() {
		TopoDS_Shape* temp = new TopoDS_Shape(NativeHandle->Shape());
		return gcnew XTopoDS_Shape(temp);
	};

	//! Constructs a pipe by sweeping the shape Profile along
	//! the wire Spine.The angle made by the spine with the profile is
	//! maintained along the length of the pipe.
	//! Warning
	//! Spine must be G1 continuous; that is, on the connection
	//! vertex of two edges of the wire, the tangent vectors on
	//! the left and on the right must have the same direction,
	//! though not necessarily the same magnitude.
	//! Exceptions
	//! Standard_DomainError if the profile is a solid or a
	//! composite solid.
	XBRepOffsetAPI_MakePipe::XBRepOffsetAPI_MakePipe(XTopoDS_Wire^ Spine, XTopoDS_Shape^ Profile) {
		NativeHandle = new BRepOffsetAPI_MakePipe(*Spine->GetWire(), *Profile->GetShape());
		SetMakeSweepHandle(NativeHandle);
	};

	//! the same as previous but with setting of
	//! mode of sweep and the flag that indicates attempt
	//! to approximate a C1-continuous surface if a swept
	//! surface proved to be C0.
	//! const Standard_Boolean ForceApproxC1 = Standard_False
	XBRepOffsetAPI_MakePipe::XBRepOffsetAPI_MakePipe(XTopoDS_Wire^ Spine, XTopoDS_Shape^ Profile, XGeomFill_Trihedron aMode, Standard_Boolean ForceApproxC1) {
		NativeHandle = new BRepOffsetAPI_MakePipe(*Spine->GetWire(), *Profile->GetShape(), safe_cast<GeomFill_Trihedron>(aMode), ForceApproxC1);
		SetMakeSweepHandle(NativeHandle);
	};

	XBRepFill_Pipe^ XBRepOffsetAPI_MakePipe::Pipe() {
		BRepFill_Pipe* temp = new BRepFill_Pipe(NativeHandle->Pipe());
		return gcnew XBRepFill_Pipe(temp);
	};

	//! Builds the resulting shape (redefined from MakeShape).
	void XBRepOffsetAPI_MakePipe::Build() {
		NativeHandle->Build();
	};

	//! Returns the  TopoDS  Shape of the bottom of the prism.
	XTopoDS_Shape^ XBRepOffsetAPI_MakePipe::FirstShape() {
		TopoDS_Shape* temp = new TopoDS_Shape(NativeHandle->FirstShape());
		return gcnew XTopoDS_Shape(temp);
	};

	//! Returns the TopoDS Shape of the top of the prism.
	XTopoDS_Shape^ XBRepOffsetAPI_MakePipe::LastShape() {
		TopoDS_Shape* temp = new TopoDS_Shape(NativeHandle->LastShape());
		return gcnew XTopoDS_Shape(temp);
	};

	XTopTools_ListOfShape^ XBRepOffsetAPI_MakePipe::Generated(XTopoDS_Shape^ S) {
		TopTools_ListOfShape* temp = new TopTools_ListOfShape(NativeHandle->Generated(*S->GetShape()));
		return gcnew XTopTools_ListOfShape(temp);
	};

	XTopoDS_Shape^ XBRepOffsetAPI_MakePipe::Generated(XTopoDS_Shape^ SSpine, XTopoDS_Shape^ SProfile) {
		TopoDS_Shape* temp = new TopoDS_Shape(NativeHandle->Generated(*SSpine->GetShape(), *SProfile->GetShape()));
		return gcnew XTopoDS_Shape(temp);
	};

	Standard_Real XBRepOffsetAPI_MakePipe::ErrorOnSurface() {
		return NativeHandle->ErrorOnSurface();
	};

}