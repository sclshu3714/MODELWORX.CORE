#include <XBRepBuilderAPI_MakeFace.h>
namespace TKTopAlgo {

	void XBRepBuilderAPI_MakeFace::Initialize(BRepBuilderAPI_MakeFace* pos) {
		SetMakeShapeHandle(pos);
	};
	//! Not done.
	XBRepBuilderAPI_MakeFace::XBRepBuilderAPI_MakeFace() {
		NativeHandle = new BRepBuilderAPI_MakeFace();
		Initialize(NativeHandle);
	};

	//! Load a face. Usefull to add wires.
	XBRepBuilderAPI_MakeFace::XBRepBuilderAPI_MakeFace(XTopoDS_Face^ F) {
		NativeHandle = new BRepBuilderAPI_MakeFace(*F->GetFace());
		Initialize(NativeHandle);
	};

	//! Make a face from a plane.
	XBRepBuilderAPI_MakeFace::XBRepBuilderAPI_MakeFace(xgp_Pln^ P) {
		NativeHandle = new BRepBuilderAPI_MakeFace(P->GetPln());
		Initialize(NativeHandle);
	};

	//! Make a face from a cylinder.
	XBRepBuilderAPI_MakeFace::XBRepBuilderAPI_MakeFace(xgp_Cylinder^ C) {
		NativeHandle = new BRepBuilderAPI_MakeFace(*C->GetCylinder());
		Initialize(NativeHandle);
	};

	//! Make a face from a cone.
	XBRepBuilderAPI_MakeFace::XBRepBuilderAPI_MakeFace(xgp_Cone^ C) {
		NativeHandle = new BRepBuilderAPI_MakeFace(*C->GetCone());
		Initialize(NativeHandle);
	};

	//! Make a face from a sphere.
	XBRepBuilderAPI_MakeFace::XBRepBuilderAPI_MakeFace(xgp_Sphere^ S) {
		NativeHandle = new BRepBuilderAPI_MakeFace(S->GetSphere());
		Initialize(NativeHandle);
	};

	//! Make a face from a torus.
	XBRepBuilderAPI_MakeFace::XBRepBuilderAPI_MakeFace(xgp_Torus^ C) {
		NativeHandle = new BRepBuilderAPI_MakeFace(C->GetTorus());
		Initialize(NativeHandle);
	};

	//! Make a face from a Surface. Accepts tolerance value (TolDegen)
	//! for resolution of degenerated edges.
	XBRepBuilderAPI_MakeFace::XBRepBuilderAPI_MakeFace(XGeom_Surface^ S, Standard_Real TolDegen) {
		NativeHandle = new BRepBuilderAPI_MakeFace(S->GetSurface(), TolDegen);
		Initialize(NativeHandle);
	};

	//! Make a face from a plane.
	XBRepBuilderAPI_MakeFace::XBRepBuilderAPI_MakeFace(xgp_Pln^ P, Standard_Real UMin, Standard_Real UMax, Standard_Real VMin, Standard_Real VMax) {
		NativeHandle = new BRepBuilderAPI_MakeFace(P->GetPln(), UMin, UMax, VMin, VMax);
		Initialize(NativeHandle);
	};

	//! Make a face from a cylinder.
	XBRepBuilderAPI_MakeFace::XBRepBuilderAPI_MakeFace(xgp_Cylinder^ C, Standard_Real UMin, Standard_Real UMax, Standard_Real VMin, Standard_Real VMax) {
		NativeHandle = new BRepBuilderAPI_MakeFace(*C->GetCylinder(), UMin, UMax, VMin, VMax);
		Initialize(NativeHandle);
	};

	//! Make a face from a cone.
	XBRepBuilderAPI_MakeFace::XBRepBuilderAPI_MakeFace(xgp_Cone^ C, Standard_Real UMin, Standard_Real UMax, Standard_Real VMin, Standard_Real VMax) {
		NativeHandle = new BRepBuilderAPI_MakeFace(*C->GetCone(), UMin, UMax, VMin, VMax);
		Initialize(NativeHandle);
	};

	//! Make a face from a sphere.
	XBRepBuilderAPI_MakeFace::XBRepBuilderAPI_MakeFace(xgp_Sphere^ S, Standard_Real UMin, Standard_Real UMax, Standard_Real VMin, Standard_Real VMax) {
		NativeHandle = new BRepBuilderAPI_MakeFace(S->GetSphere(), UMin, UMax, VMin, VMax);
		Initialize(NativeHandle);
	};

	//! Make a face from a torus.
	XBRepBuilderAPI_MakeFace::XBRepBuilderAPI_MakeFace(xgp_Torus^ C, Standard_Real UMin, Standard_Real UMax, Standard_Real VMin, Standard_Real VMax) {
		NativeHandle = new BRepBuilderAPI_MakeFace(C->GetTorus(), UMin, UMax, VMin, VMax);
		Initialize(NativeHandle);
	};

	//! Make a face from a Surface. Accepts tolerance value (TolDegen)
	//! for resolution of degenerated edges.
	XBRepBuilderAPI_MakeFace::XBRepBuilderAPI_MakeFace(XGeom_Surface^ S, Standard_Real UMin, Standard_Real UMax, Standard_Real VMin, Standard_Real VMax, Standard_Real TolDegen) {
		NativeHandle = new BRepBuilderAPI_MakeFace(S->GetSurface(), UMin, UMax, VMin, VMax, TolDegen);
		Initialize(NativeHandle);
	};

	//! Find a surface from the wire and make a face.
	//! if <OnlyPlane> is true, the computed surface will be
	//! a plane. If it is not possible to find a plane, the
	//! flag NotDone will be set.
	//! Standard_Boolean OnlyPlane = Standard_False
	XBRepBuilderAPI_MakeFace::XBRepBuilderAPI_MakeFace(XTopoDS_Wire^ XW, Standard_Boolean OnlyPlane) {
		TopoDS_Wire* W = new TopoDS_Wire(*XW->GetWire());
		NativeHandle = new BRepBuilderAPI_MakeFace(*W, OnlyPlane);
		Initialize(NativeHandle);
	};

	//! Make a face from a plane and a wire.
	//! Standard_Boolean Inside = Standard_True
	XBRepBuilderAPI_MakeFace::XBRepBuilderAPI_MakeFace(xgp_Pln^ XP, XTopoDS_Wire^ XW, Standard_Boolean Inside) {
		gp_Pln* P = new gp_Pln(XP->GetPln());
		TopoDS_Wire* W = new TopoDS_Wire(*XW->GetWire());
		NativeHandle = new BRepBuilderAPI_MakeFace(*P, *W, Inside);
		Initialize(NativeHandle);
	};

	//! Make a face from a cylinder and a wire.
	//! Standard_Boolean Inside = Standard_True
	XBRepBuilderAPI_MakeFace::XBRepBuilderAPI_MakeFace(xgp_Cylinder^ C, XTopoDS_Wire^ W, Standard_Boolean Inside) {
		NativeHandle = new BRepBuilderAPI_MakeFace(*C->GetCylinder(), *W->GetWire(), Inside);
		Initialize(NativeHandle);
	};

	//! Make a face from a cone and a wire.
	//! Standard_Boolean Inside = Standard_True
	XBRepBuilderAPI_MakeFace::XBRepBuilderAPI_MakeFace(xgp_Cone^ C, XTopoDS_Wire^ W, Standard_Boolean Inside) {
		NativeHandle = new BRepBuilderAPI_MakeFace(*C->GetCone(), *W->GetWire(), Inside);
		Initialize(NativeHandle);
	};

	//! Make a face from a sphere and a wire.
	//! Standard_Boolean Inside = Standard_True
	XBRepBuilderAPI_MakeFace::XBRepBuilderAPI_MakeFace(xgp_Sphere^ S, XTopoDS_Wire^ W, Standard_Boolean Inside) {
		NativeHandle = new BRepBuilderAPI_MakeFace(S->GetSphere(), *W->GetWire(), Inside);
		Initialize(NativeHandle);
	};

	//! Make a face from a torus and a wire.
	//! Standard_Boolean Inside = Standard_True
	XBRepBuilderAPI_MakeFace::XBRepBuilderAPI_MakeFace(xgp_Torus^ C, XTopoDS_Wire^ W, Standard_Boolean Inside) {
		NativeHandle = new BRepBuilderAPI_MakeFace(C->GetTorus(), *W->GetWire(), Inside);
		Initialize(NativeHandle);
	};

	//! Make a face from a Surface and a wire.
	//! Standard_Boolean Inside = Standard_True
	XBRepBuilderAPI_MakeFace::XBRepBuilderAPI_MakeFace(XGeom_Surface^ S, XTopoDS_Wire^ W, Standard_Boolean Inside) {
		NativeHandle = new BRepBuilderAPI_MakeFace(S->GetSurface(), *W->GetWire(), Inside);
		Initialize(NativeHandle);
	};

	//! Adds the wire <W> in the face <F>
	//! A general method to create a face is to give
	//! -      a surface S as the support (the geometric domain) of the face,
	//! -      and a wire W to bound it.
	//! The bounds of the face can also be defined by four parameter values
	//! umin, umax, vmin, vmax which determine isoparametric limitations on
	//! the parametric space of the surface. In this way, a patch is
	//! defined. The parameter values are optional. If they are omitted, the
	//! natural bounds of the surface are used. A wire is automatically
	//! built using the defined bounds. Up to four edges and four vertices
	//! are created with this wire (no edge is created when the
	//! corresponding parameter value is infinite).
	//! Wires can then be added using the function Add to define other
	//! restrictions on the face. These restrictions represent holes. More
	//! than one wire may be added by this way, provided that the wires do
	//! not cross each other and that they define only one area on the
	//! surface. (Be careful, however, as this is not checked).
	//! Forbidden addition of wires
	//! Note that in this schema, the third case is valid if edges of the
	//! wire W are declared internal to the face. As a result, these edges
	//! are no longer bounds of the face.
	//! A default tolerance (Precision::Confusion()) is given to the face,
	//! this tolerance may be increased during construction of the face
	//! using various algorithms.
	//! Rules applied to the arguments
	//! For the surface:
	//! -      The surface must not be a 'null handle'.
	//! -      If the surface is a trimmed surface, the basis surface is used.
	//! -      For the wire: the wire is composed of connected edges, each
	//! edge having a parametric curve description in the parametric
	//! domain of the surface; in other words, as a pcurve.
	//! For the parameters:
	//! -      The parameter values must be in the parametric range of the
	//! surface (or the basis surface, if the surface is trimmed). If this
	//! condition is not satisfied, the face is not built, and the Error
	//! function will return BRepBuilderAPI_ParametersOutOfRange.
	//! -      The bounding parameters p1 and p2 are adjusted on a periodic
	//! surface in a given parametric direction by adding or subtracting
	//! the period to obtain p1 in the parametric range of the surface and
	//! such p2, that p2 - p1 <= Period, where Period is the period of the
	//! surface in this parametric direction.
	//! -      A parameter value may be infinite. There will be no edge and
	//! no vertex in the corresponding direction.
	XBRepBuilderAPI_MakeFace::XBRepBuilderAPI_MakeFace(XTopoDS_Face^ F, XTopoDS_Wire^ W) {
		NativeHandle = new BRepBuilderAPI_MakeFace(*F->GetFace(), *W->GetWire());
		Initialize(NativeHandle);
	};

	//! Initializes (or reinitializes) the
	//! construction of a face by creating a new object which is a copy of
	//! the face F, in order to add wires to it, using the function Add.
	//! Note: this complete copy of the geometry is only required if you
	//! want to work on the geometries of the two faces independently.
	void XBRepBuilderAPI_MakeFace::Init(XTopoDS_Face^ F) {
		NativeHandle->Init(*F->GetFace());
	};

	//! Initializes (or reinitializes) the construction of a face on
	//! the surface S. If Bound is true, a wire is
	//! automatically created from the natural bounds of the
	//! surface S and added to the face in order to bound it. If
	//! Bound is false, no wire is added. This option is used
	//! when real bounds are known. These will be added to
	//! the face after this initialization, using the function Add.
	//! TolDegen parameter is used for resolution of degenerated edges
	//! if calculation of natural bounds is turned on.
	void XBRepBuilderAPI_MakeFace::Init(XGeom_Surface^ S, Standard_Boolean Bound, Standard_Real TolDegen) {
		NativeHandle->Init(S->GetSurface(), Bound, TolDegen);
	};

	//! Initializes (or reinitializes) the construction of a face on
	//! the surface S, limited in the u parametric direction by
	//! the two parameter values UMin and UMax and in the
	//! v parametric direction by the two parameter values VMin and VMax.
	//! Warning
	//! Error returns:
	//! -      BRepBuilderAPI_ParametersOutOfRange
	//! when the parameters given are outside the bounds of the
	//! surface or the basis surface of a trimmed surface.
	//! TolDegen parameter is used for resolution of degenerated edges.
	void XBRepBuilderAPI_MakeFace::Init(XGeom_Surface^ S, Standard_Real UMin, Standard_Real UMax, Standard_Real VMin, Standard_Real VMax, Standard_Real TolDegen) {
		NativeHandle->Init(S->GetSurface(), UMin, UMax, VMin, VMax, TolDegen);
	};

	//! Adds the wire W to the constructed face as a hole.
	//! Warning
	//! W must not cross the other bounds of the face, and all
	//! the bounds must define only one area on the surface.
	//! (Be careful, however, as this is not checked.)
	//! Example
	//! // a cylinder
	//! gp_Cylinder C = ..;
	//! // a wire
	//! TopoDS_Wire W = ...;
	//! BRepBuilderAPI_MakeFace MF(C);
	//! MF.Add(W);
	//! TopoDS_Face F = MF;
	void XBRepBuilderAPI_MakeFace::Add(XTopoDS_Wire^ W) {
		NativeHandle->Add(*W->GetWire());
	};

	//! Returns true if this algorithm has a valid face.
	Standard_Boolean XBRepBuilderAPI_MakeFace::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the construction status
	//! BRepBuilderAPI_FaceDone if the face is built, or
	//! -   another value of the BRepBuilderAPI_FaceError
	//! enumeration indicating why the construction failed, in
	//! particular when the given parameters are outside the
	//! bounds of the surface.
	XBRepBuilderAPI_FaceError XBRepBuilderAPI_MakeFace::Error() {
		return safe_cast<XBRepBuilderAPI_FaceError>(NativeHandle->Error());
	};

	//! Returns the constructed face.
	//! Exceptions
	//! StdFail_NotDone if no face is built.
	XTopoDS_Face^ XBRepBuilderAPI_MakeFace::Face() {
		TopoDS_Face* face = new TopoDS_Face(NativeHandle->Face());
		return gcnew XTopoDS_Face(face);
	};
	XBRepBuilderAPI_MakeFace::operator XTopoDS_Face^() {
		TopoDS_Face* face = new TopoDS_Face(NativeHandle->Face());
		return gcnew XTopoDS_Face(face);
	};

	XTopoDS_Shape^ XBRepBuilderAPI_MakeFace::Shape() {
		TopoDS_Shape* Shape = new TopoDS_Shape(NativeHandle->Shape());
		return gcnew XTopoDS_Shape(Shape);
	};

	BRepBuilderAPI_MakeFace* XBRepBuilderAPI_MakeFace::GetMakeFace() {
		return NativeHandle;
	};

	void XBRepBuilderAPI_MakeFace::SetMakeFaceHandle(BRepBuilderAPI_MakeFace* pos) {
		NativeHandle = pos;
	};

	BRepBuilderAPI_MakeShape* XBRepBuilderAPI_MakeFace::GetMakeShape() {
		return NativeHandle;
	};
}
