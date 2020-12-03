#include <XBRepPrimAPI_MakeCone.h>

namespace TKPrim {

	XBRepPrimAPI_MakeCone::XBRepPrimAPI_MakeCone() {
		//NativeHandle = new BRepPrimAPI_MakeCone();
	};

	XBRepPrimAPI_MakeCone::XBRepPrimAPI_MakeCone(BRepPrimAPI_MakeCone* handle) {
		NativeHandle = handle;
		SetMakeOneAxisHandle(NativeHandle);
	};

	void XBRepPrimAPI_MakeCone::SetMakeConeHandle(BRepPrimAPI_MakeCone* handle) {
		NativeHandle = handle;
		SetMakeOneAxisHandle(NativeHandle);
	};

	BRepPrimAPI_MakeCone* XBRepPrimAPI_MakeCone::GetMakeCone() {
		return NativeHandle;
	};

	BRepPrimAPI_MakeOneAxis* XBRepPrimAPI_MakeCone::GetMakeOneAxis() {
		return NativeHandle;
	};

	BRepBuilderAPI_MakeShape* XBRepPrimAPI_MakeCone::GetMakeShape() {
		return NativeHandle;
	};

	//! Make a cone of height H radius R1 in the plane z =
	//! 0, R2 in the plane Z = H. R1 and R2 may be null.
	XBRepPrimAPI_MakeCone::XBRepPrimAPI_MakeCone(Standard_Real R1, Standard_Real R2, Standard_Real H) {
		NativeHandle = new BRepPrimAPI_MakeCone(R1, R2, H);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Make a cone of height H radius R1 in the plane z =
	//! 0, R2 in the plane Z = H. R1 and R2 may be null.
	//! Take a section of <angle>
	XBRepPrimAPI_MakeCone::XBRepPrimAPI_MakeCone(Standard_Real R1, Standard_Real R2, Standard_Real H, Standard_Real angle) {
		NativeHandle = new BRepPrimAPI_MakeCone(R1, R2, H, angle);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Make a cone of height H radius R1 in the plane z =
	//! 0, R2 in the plane Z = H. R1 and R2 may be null.
	XBRepPrimAPI_MakeCone::XBRepPrimAPI_MakeCone(xgp_Ax2^ Axes, Standard_Real R1, Standard_Real R2, Standard_Real H) {
		NativeHandle = new BRepPrimAPI_MakeCone(Axes->GetAx2(), R1, R2, H);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Make a cone of height H radius R1 in the plane z =
	//! 0, R2 in the plane Z = H. R1 and R2 may be null.
	//! Take a section of <angle>
	//! Constructs a cone, or a portion of a cone, of height H,
	//! and radius R1 in the plane z = 0 and R2 in the plane
	//! z = H. The result is a sharp cone if R1 or R2 is equal to 0.
	//! The cone is constructed about the "Z Axis" of either:
	//! -   the global coordinate system, or
	//! -   the local coordinate system Axes.
	//! It is limited in these coordinate systems as follows:
	//! -   in the v parametric direction (the Z coordinate), by
	//! the two parameter values 0 and H,
	//! -   and in the u parametric direction (defined by the
	//! angle of rotation around the Z axis), in the case of a
	//! portion of a cone, by the two parameter values 0 and
	//! angle. Angle is given in radians.
	//! The resulting shape is composed of:
	//! -   a lateral conical face
	//! -   two planar faces in the planes z = 0 and z = H,
	//! or only one planar face in one of these two planes if a
	//! radius value is null (in the case of a complete cone,
	//! these faces are circles), and
	//! -   and in the case of a portion of a cone, two planar
	//! faces to close the shape. (either two parallelograms or
	//! two triangles, in the planes u = 0 and u = angle).
	//! Exceptions
	//! Standard_DomainError if:
	//! -   H is less than or equal to Precision::Confusion(), or
	//! -   the half-angle at the apex of the cone, defined by
	//! R1, R2 and H, is less than Precision::Confusion()/H, or greater than
	//! (Pi/2)-Precision::Confusion()/H.f
	XBRepPrimAPI_MakeCone::XBRepPrimAPI_MakeCone(xgp_Ax2^ Axes, Standard_Real R1, Standard_Real R2, Standard_Real H, Standard_Real angle) {
		NativeHandle = new BRepPrimAPI_MakeCone(Axes->GetAx2(), R1, R2, H, angle);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Returns the algorithm.
	Object^ XBRepPrimAPI_MakeCone::OneAxis() {
		return XStandard_Helper::toObject(NativeHandle->OneAxis());
	};

	//! Returns the algorithm.
	XBRepPrim_Cone^ XBRepPrimAPI_MakeCone::Cone() {
		BRepPrim_Cone* aCone = new BRepPrim_Cone(NativeHandle->Cone());
		return gcnew XBRepPrim_Cone(aCone);
	};
}


