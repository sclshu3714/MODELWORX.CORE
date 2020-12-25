#include <XBRepBuilderAPI_FindPlane.h>
namespace TKTopAlgo {
	//! Initializes an empty algorithm. The function Init is then used to define the shape.
	XBRepBuilderAPI_FindPlane::XBRepBuilderAPI_FindPlane() {
		NativeHandle = new BRepBuilderAPI_FindPlane();
	};

	XBRepBuilderAPI_FindPlane::XBRepBuilderAPI_FindPlane(BRepBuilderAPI_FindPlane* pos) {
		NativeHandle = pos;
	};

	void XBRepBuilderAPI_FindPlane::SetFindPlaneHandle(BRepBuilderAPI_FindPlane* pos) {
		NativeHandle = pos;
	};

	BRepBuilderAPI_FindPlane* XBRepBuilderAPI_FindPlane::GetFindPlane() {
		return NativeHandle;
	};

	//! Constructs the plane containing the edges of the shape S.
	//! A plane is built only if all the edges are within a distance
	//! of less than or equal to tolerance from a planar surface.
	//! This tolerance value is equal to the larger of the following two values:
	//! -   Tol, where the default value is negative, or
	//! -   the largest of the tolerance values assigned to the individual edges of S.
	//! Use the function Found to verify that a plane is built.
	//! The resulting plane is then retrieved using the function Plane.
	//! Standard_Real Tol = -1
	XBRepBuilderAPI_FindPlane::XBRepBuilderAPI_FindPlane(XTopoDS_Shape^ S, Standard_Real Tol) {
		NativeHandle = new BRepBuilderAPI_FindPlane(*S->GetShape(), Tol);
	};

	//! Constructs the plane containing the edges of the shape S.
	//! A plane is built only if all the edges are within a distance
	//! of less than or equal to tolerance from a planar surface.
	//! This tolerance value is equal to the larger of the following two values:
	//! -   Tol, where the default value is negative, or
	//! -   the largest of the tolerance values assigned to the individual edges of S.
	//! Use the function Found to verify that a plane is built.
	//! The resulting plane is then retrieved using the function Plane.
	void XBRepBuilderAPI_FindPlane::Init(XTopoDS_Shape^ S, Standard_Real Tol) {
		NativeHandle->Init(*S->GetShape(), Tol);
	};

	//! Returns true if a plane containing the edges of the
	//! shape is found and built. Use the function Plane to consult the result.
	Standard_Boolean XBRepBuilderAPI_FindPlane::Found() {
		return NativeHandle->Found();
	};

	//! Returns the plane containing the edges of the shape.
	//! Warning
	//! Use the function Found to verify that the plane is built. If
	//! a plane is not found, Plane returns a null handle.
	XGeom_Plane^ XBRepBuilderAPI_FindPlane::Plane() {
		return gcnew XGeom_Plane(NativeHandle->Plane());
	};
}