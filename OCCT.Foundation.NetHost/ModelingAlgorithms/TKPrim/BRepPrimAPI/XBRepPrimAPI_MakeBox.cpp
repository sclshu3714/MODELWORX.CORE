#include <XBRepPrimAPI_MakeBox.h>
namespace TKPrim {
	XBRepPrimAPI_MakeBox::XBRepPrimAPI_MakeBox(BRepPrimAPI_MakeBox* handle) {
		NativeHandle = handle;
		SetMakeShapeHandle(NativeHandle);
	};

	void XBRepPrimAPI_MakeBox::SetMakeBoxHandle(BRepPrimAPI_MakeBox* handle) {
		NativeHandle = handle;
		SetMakeShapeHandle(NativeHandle);
	};

	BRepPrimAPI_MakeBox* XBRepPrimAPI_MakeBox::GetMakeOneAxis() {
		return NativeHandle;
	};

	BRepBuilderAPI_MakeShape* XBRepPrimAPI_MakeBox::GetMakeShape() {
		return NativeHandle;
	};


	//! Make a box with a corner at 0,0,0 and the other dx,dy,dz
	XBRepPrimAPI_MakeBox::XBRepPrimAPI_MakeBox(Standard_Real dx, Standard_Real dy, Standard_Real dz) {
		NativeHandle = new BRepPrimAPI_MakeBox(dx, dy, dz);
		SetMakeShapeHandle(NativeHandle);
	};

	//! Make a box with a corner at P and size dx, dy, dz.
	XBRepPrimAPI_MakeBox::XBRepPrimAPI_MakeBox(xgp_Pnt^ P, Standard_Real dx, Standard_Real dy, Standard_Real dz) {
		NativeHandle = new BRepPrimAPI_MakeBox(P->GetPnt(), dx, dy, dz);
		SetMakeShapeHandle(NativeHandle);
	};

	//! Make a box with corners P1,P2.
	XBRepPrimAPI_MakeBox::XBRepPrimAPI_MakeBox(xgp_Pnt^ P1, xgp_Pnt^ P2) {
		NativeHandle = new BRepPrimAPI_MakeBox(P1->GetPnt(), P2->GetPnt());
		SetMakeShapeHandle(NativeHandle);
	};

	//! Ax2 is the left corner and the axis.
	//! Constructs a box such that its sides are parallel to the axes of
	//! -   the global coordinate system, or
	//! -   the local coordinate system Axis. and
	//! -   with a corner at (0, 0, 0) and of size (dx, dy, dz), or
	//! -   with a corner at point P and of size (dx, dy, dz), or
	//! -   with corners at points P1 and P2.
	//! Exceptions
	//! Standard_DomainError if: dx, dy, dz are less than or equal to
	//! Precision::Confusion(), or
	//! -   the vector joining the points P1 and P2 has a
	//! component projected onto the global coordinate
	//! system less than or equal to Precision::Confusion().
	//! In these cases, the box would be flat.
	XBRepPrimAPI_MakeBox::XBRepPrimAPI_MakeBox(xgp_Ax2^ Axes, Standard_Real dx, Standard_Real dy, Standard_Real dz) {
		NativeHandle = new BRepPrimAPI_MakeBox(*Axes->GetAx2(), dx, dy, dz);
		SetMakeShapeHandle(NativeHandle);
	};

	//! Returns the internal algorithm.
	XBRepPrim_Wedge^ XBRepPrimAPI_MakeBox::Wedge() {
		BRepPrim_Wedge* aWedge = new BRepPrim_Wedge(NativeHandle->Wedge());
		return gcnew XBRepPrim_Wedge(aWedge);
	};

	//! Stores the solid in myShape.
	void XBRepPrimAPI_MakeBox::Build() {
		NativeHandle->Build();
	};

	//! Returns the constructed box as a shell.
	XTopoDS_Shell^ XBRepPrimAPI_MakeBox::Shell() {
		TopoDS_Shell* aShell = new TopoDS_Shell(NativeHandle->Shell());
		return gcnew XTopoDS_Shell(aShell);
	};
	XBRepPrimAPI_MakeBox::operator XTopoDS_Shell^() {
		TopoDS_Shell* aShell = new TopoDS_Shell(NativeHandle->Shell());
		return gcnew XTopoDS_Shell(aShell);
	};

	//! Returns the constructed box as a solid.
	XTopoDS_Solid^ XBRepPrimAPI_MakeBox::Solid() {
		TopoDS_Solid* aSolid = new TopoDS_Solid(NativeHandle->Solid());
		return gcnew XTopoDS_Solid(aSolid);
	};
	XBRepPrimAPI_MakeBox::operator XTopoDS_Solid^() {
		TopoDS_Solid* aSolid = new TopoDS_Solid(NativeHandle->Solid());
		return gcnew XTopoDS_Solid(aSolid);
	};

	//! Returns ZMin face
	XTopoDS_Face^ XBRepPrimAPI_MakeBox::BottomFace() {
		TopoDS_Face* aFace = new TopoDS_Face(NativeHandle->BottomFace());
		return gcnew XTopoDS_Face(aFace);
	};

	//! Returns XMin face
	XTopoDS_Face^ XBRepPrimAPI_MakeBox::BackFace() {
		TopoDS_Face* aFace = new TopoDS_Face(NativeHandle->BackFace());
		return gcnew XTopoDS_Face(aFace);
	};

	//! Returns XMax face
	XTopoDS_Face^ XBRepPrimAPI_MakeBox::FrontFace() {
		TopoDS_Face* aFace = new TopoDS_Face(NativeHandle->FrontFace());
		return gcnew XTopoDS_Face(aFace);
	};

	//! Returns YMin face
	XTopoDS_Face^ XBRepPrimAPI_MakeBox::LeftFace() {
		TopoDS_Face* aFace = new TopoDS_Face(NativeHandle->LeftFace());
		return gcnew XTopoDS_Face(aFace);
	};

	//! Returns YMax face
	XTopoDS_Face^ XBRepPrimAPI_MakeBox::RightFace() {
		TopoDS_Face* aFace = new TopoDS_Face(NativeHandle->RightFace());
		return gcnew XTopoDS_Face(aFace);
	};

	//! Returns ZMax face
	XTopoDS_Face^ XBRepPrimAPI_MakeBox::TopFace() {
		TopoDS_Face* aFace = new TopoDS_Face(NativeHandle->TopFace());
		return gcnew XTopoDS_Face(aFace);
	};
}