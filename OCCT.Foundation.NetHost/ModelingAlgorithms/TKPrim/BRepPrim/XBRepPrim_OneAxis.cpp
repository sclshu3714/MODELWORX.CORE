#include <XBRepPrim_OneAxis.h>
namespace TKPrim {

	XBRepPrim_OneAxis::XBRepPrim_OneAxis() {
		
	};

	XBRepPrim_OneAxis::XBRepPrim_OneAxis(BRepPrim_OneAxis* handle) {
		NativeHandle = handle;
	};

	void XBRepPrim_OneAxis::SetOneAxisHandle(BRepPrim_OneAxis* handle) {
		NativeHandle = handle;
	};

	BRepPrim_OneAxis* XBRepPrim_OneAxis::GetOneAxis() {
		return NativeHandle;
	};

	//! The MeridianOffset is added  to the  parameters on
	//! the meridian curve and  to  the  V values  of  the
	//! pcurves. This is  used for the sphere for example,
	//! to give a range on the meridian  edge which is not
	//! VMin, VMax.
	//! Standard_Real MeridianOffset
	void XBRepPrim_OneAxis::SetMeridianOffset(Standard_Real MeridianOffset) {
		NativeHandle->SetMeridianOffset(MeridianOffset);
	};

	//! Returns the Ax2 from <me>.
	xgp_Ax2^ XBRepPrim_OneAxis::Axes() {
		gp_Ax2* gpAx2 = new gp_Ax2(NativeHandle->Axes());
		return gcnew xgp_Ax2(gpAx2);
	};

	void XBRepPrim_OneAxis::Axes(xgp_Ax2^ A) {
		NativeHandle->Axes(*A->GetAx2());
	};

	Standard_Real XBRepPrim_OneAxis::Angle() {
		return NativeHandle->Angle();
	};

	void XBRepPrim_OneAxis::Angle(Standard_Real A) {
		NativeHandle->Angle(A);
	};

	Standard_Real XBRepPrim_OneAxis::VMin() {
		return NativeHandle->VMin();
	};

	void XBRepPrim_OneAxis::VMin(Standard_Real V) {
		NativeHandle->VMin(V);
	};

	Standard_Real XBRepPrim_OneAxis::VMax() {
		return NativeHandle->VMax();
	};

	void XBRepPrim_OneAxis::VMax(Standard_Real V) {
		NativeHandle->VMax(V);
	};

	//! Returns a face with  no edges.  The surface is the
	//! lateral surface with normals pointing outward. The
	//! U parameter is the angle with the  origin on the X
	//! axis. The  V parameter is   the  parameter of  the
	//! meridian.
	XTopoDS_Face^ XBRepPrim_OneAxis::MakeEmptyLateralFace() {
		TopoDS_Face* aFace = new TopoDS_Face(NativeHandle->MakeEmptyLateralFace());
		return gcnew XTopoDS_Face(aFace);
	};

	//! Returns  an  edge with  a 3D curve   made from the
	//! meridian  in the XZ  plane rotated by <Ang> around
	//! the Z-axis. Ang may be 0 or myAngle.
	XTopoDS_Edge^ XBRepPrim_OneAxis::MakeEmptyMeridianEdge(Standard_Real Ang) {
		TopoDS_Edge* aEdge = new TopoDS_Edge(NativeHandle->MakeEmptyMeridianEdge(Ang));
		return gcnew XTopoDS_Edge(aEdge);
	};

	//! Sets the  parametric curve of the  edge <E> in the
	//! face  <F> to be  the   2d representation  of   the
	//! meridian.
	void XBRepPrim_OneAxis::SetMeridianPCurve(XTopoDS_Edge^ E, XTopoDS_Face^ F) {
		NativeHandle->SetMeridianPCurve(*E->GetEdge(), *F->GetFace());
	};

	//! Returns the meridian point at parameter <V> in the
	//! plane XZ.
	xgp_Pnt2d^ XBRepPrim_OneAxis::MeridianValue(Standard_Real V) {
		gp_Pnt2d* aPnt2d = new gp_Pnt2d(NativeHandle->MeridianValue(V));
		return gcnew xgp_Pnt2d(aPnt2d);
	};

	//! Returns True if the point of  parameter <V> on the
	//! meridian is on the Axis. Default implementation is
	//! Abs(MeridianValue(V).X()) < Precision::Confusion()
	Standard_Boolean XBRepPrim_OneAxis::MeridianOnAxis(Standard_Real V) {
		return NativeHandle->MeridianOnAxis(V);
	};

	//! Returns True  if the  meridian is  closed. Default
	//! implementation                                  is
	//! MeridianValue(VMin).IsEqual(MeridianValue(VMax),
	//! Precision::Confusion())
	Standard_Boolean XBRepPrim_OneAxis::MeridianClosed() {
		return NativeHandle->MeridianClosed();
	};

	//! Returns  True   if  VMax    is  infinite.  Default
	//! Precision::IsPositiveInfinite(VMax);
	Standard_Boolean XBRepPrim_OneAxis::VMaxInfinite() {
		return NativeHandle->VMaxInfinite();
	};

	//! Returns  True   if  VMin    is  infinite.  Default
	//! Precision::IsNegativeInfinite(VMax);
	Standard_Boolean XBRepPrim_OneAxis::VMinInfinite() {
		return NativeHandle->VMinInfinite();
	};

	//! Returns True if  there is  a top  face.
	//!
	//! That is neither : VMaxInfinite()
	//! MeridianClosed()
	//! MeridianOnAxis(VMax)
	Standard_Boolean XBRepPrim_OneAxis::HasTop() {
		return NativeHandle->HasTop();
	};

	//! Returns   True if there is   a bottom  face.
	//!
	//! That is neither : VMinInfinite()
	//! MeridianClosed()
	//! MeridianOnAxis(VMin)
	Standard_Boolean XBRepPrim_OneAxis::HasBottom() {
		return NativeHandle->HasBottom();
	};

	//! Returns True if  there are Start   and  End faces.
	//!
	//! That is : 2*PI  - Angle > Precision::Angular()
	Standard_Boolean XBRepPrim_OneAxis::HasSides() {
		return NativeHandle->HasSides();
	};

	//! Returns the Shell containing all the  Faces of the
	//! primitive.
	XTopoDS_Shell^ XBRepPrim_OneAxis::Shell() {
		TopoDS_Shell* aShell = new TopoDS_Shell(NativeHandle->Shell());
		return gcnew XTopoDS_Shell(aShell);
	};

	//! Returns  the lateral Face.   It is oriented toward
	//! the outside of the primitive.
	XTopoDS_Face^ XBRepPrim_OneAxis::LateralFace() {
		TopoDS_Face* aFace = new TopoDS_Face(NativeHandle->LateralFace());
		return gcnew XTopoDS_Face(aFace);
	};

	//! Returns the   top planar  Face.    It  is Oriented
	//! toward the +Z axis (outside).
	XTopoDS_Face^ XBRepPrim_OneAxis::TopFace() {
		TopoDS_Face* aFace = new TopoDS_Face(NativeHandle->TopFace());
		return gcnew XTopoDS_Face(aFace);
	};

	//! Returns  the Bottom planar Face.   It is  Oriented
	//! toward the -Z axis (outside).
	XTopoDS_Face^ XBRepPrim_OneAxis::BottomFace() {
		TopoDS_Face* aFace = new TopoDS_Face(NativeHandle->BottomFace());
		return gcnew XTopoDS_Face(aFace);
	};

	//! Returns  the  Face   starting   the slice, it   is
	//! oriented toward the exterior of the primitive.
	XTopoDS_Face^ XBRepPrim_OneAxis::StartFace() {
		TopoDS_Face* aFace = new TopoDS_Face(NativeHandle->StartFace());
		return gcnew XTopoDS_Face(aFace);
	};

	//! Returns the Face ending the slice, it  is oriented
	//! toward the exterior of the primitive.
	XTopoDS_Face^ XBRepPrim_OneAxis::EndFace() {
		TopoDS_Face* aFace = new TopoDS_Face(NativeHandle->EndFace());
		return gcnew XTopoDS_Face(aFace);
	};

	//! Returns  the wire in the lateral face.
	XTopoDS_Wire^ XBRepPrim_OneAxis::LateralWire() {
		TopoDS_Wire* aWire = new TopoDS_Wire(NativeHandle->LateralWire());
		return gcnew XTopoDS_Wire(aWire);
	};

	//! Returns the   wire in the   lateral  face with the
	//! start edge.
	XTopoDS_Wire^ XBRepPrim_OneAxis::LateralStartWire() {
		TopoDS_Wire* aWire = new TopoDS_Wire(NativeHandle->LateralStartWire());
		return gcnew XTopoDS_Wire(aWire);
	};

	//! Returns the wire with in lateral face with the end
	//! edge.
	XTopoDS_Wire^ XBRepPrim_OneAxis::LateralEndWire() {
		TopoDS_Wire* aWire = new TopoDS_Wire(NativeHandle->LateralEndWire());
		return gcnew XTopoDS_Wire(aWire);
	};

	//! Returns the wire in the top face.
	XTopoDS_Wire^ XBRepPrim_OneAxis::TopWire() {
		TopoDS_Wire* aWire = new TopoDS_Wire(NativeHandle->TopWire());
		return gcnew XTopoDS_Wire(aWire);
	};

	//! Returns the wire in the bottom face.
	XTopoDS_Wire^ XBRepPrim_OneAxis::BottomWire() {
		TopoDS_Wire* aWire = new TopoDS_Wire(NativeHandle->BottomWire());
		return gcnew XTopoDS_Wire(aWire);
	};

	//! Returns the wire  in the  start face.
	XTopoDS_Wire^ XBRepPrim_OneAxis::StartWire() {
		TopoDS_Wire* aWire = new TopoDS_Wire(NativeHandle->StartWire());
		return gcnew XTopoDS_Wire(aWire);
	};

	//! Returns  the wire   in the  start   face  with the
	//! AxisEdge.
	XTopoDS_Wire^ XBRepPrim_OneAxis::AxisStartWire() {
		TopoDS_Wire* aWire = new TopoDS_Wire(NativeHandle->AxisStartWire());
		return gcnew XTopoDS_Wire(aWire);
	};

	//! Returns the Wire in   the end face.
	XTopoDS_Wire^ XBRepPrim_OneAxis::EndWire() {
		TopoDS_Wire* aWire = new TopoDS_Wire(NativeHandle->EndWire());
		return gcnew XTopoDS_Wire(aWire);
	};

	//! Returns  the Wire  in  the   end   face  with  the
	//! AxisEdge.
	XTopoDS_Wire^ XBRepPrim_OneAxis::AxisEndWire() {
		TopoDS_Wire* aWire = new TopoDS_Wire(NativeHandle->AxisEndWire());
		return gcnew XTopoDS_Wire(aWire);
	};

	//! Returns the Edge built along the Axis and oriented
	//! on +Z of the Axis.
	XTopoDS_Edge^ XBRepPrim_OneAxis::AxisEdge() {
		TopoDS_Edge* aEdge = new TopoDS_Edge(NativeHandle->AxisEdge());
		return gcnew XTopoDS_Edge(aEdge);
	};

	//! Returns the   Edge at angle 0.
	XTopoDS_Edge^ XBRepPrim_OneAxis::StartEdge() {
		TopoDS_Edge* aEdge = new TopoDS_Edge(NativeHandle->StartEdge());
		return gcnew XTopoDS_Edge(aEdge);
	};

	//! Returns the  Edge at  angle Angle.  If !HasSides()
	//! the StartEdge and the EndEdge are the same edge.
	XTopoDS_Edge^ XBRepPrim_OneAxis::EndEdge() {
		TopoDS_Edge* aEdge = new TopoDS_Edge(NativeHandle->EndEdge());
		return gcnew XTopoDS_Edge(aEdge);
	};

	//! Returns the linear Edge between start Face and top
	//! Face.
	XTopoDS_Edge^ XBRepPrim_OneAxis::StartTopEdge() {
		TopoDS_Edge* aEdge = new TopoDS_Edge(NativeHandle->StartTopEdge());
		return gcnew XTopoDS_Edge(aEdge);
	};

	//! Returns the linear  Edge between  start  Face  and
	//! bottom Face.
	XTopoDS_Edge^ XBRepPrim_OneAxis::StartBottomEdge() {
		TopoDS_Edge* aEdge = new TopoDS_Edge(NativeHandle->StartBottomEdge());
		return gcnew XTopoDS_Edge(aEdge);
	};

	//! Returns the linear Edge  between end Face and  top
	//! Face.
	XTopoDS_Edge^ XBRepPrim_OneAxis::EndTopEdge() {
		TopoDS_Edge* aEdge = new TopoDS_Edge(NativeHandle->EndTopEdge());
		return gcnew XTopoDS_Edge(aEdge);
	};

	//! Returns  the  linear  Edge  between end  Face  and
	//! bottom Face.
	XTopoDS_Edge^ XBRepPrim_OneAxis::EndBottomEdge() {
		TopoDS_Edge* aEdge = new TopoDS_Edge(NativeHandle->EndBottomEdge());
		return gcnew XTopoDS_Edge(aEdge);
	};

	//! Returns the edge at VMax. If  MeridianClosed() the
	//! TopEdge and the BottomEdge are the same edge.
	XTopoDS_Edge^ XBRepPrim_OneAxis::TopEdge() {
		TopoDS_Edge* aEdge = new TopoDS_Edge(NativeHandle->TopEdge());
		return gcnew XTopoDS_Edge(aEdge);
	};

	//! Returns the edge  at VMin. If MeridianClosed() the
	//! TopEdge and the BottomEdge are the same edge.
	XTopoDS_Edge^ XBRepPrim_OneAxis::BottomEdge() {
		TopoDS_Edge* aEdge = new TopoDS_Edge(NativeHandle->BottomEdge());
		return gcnew XTopoDS_Edge(aEdge);
	};

	//! Returns the Vertex at the Top altitude on the axis.
	XTopoDS_Vertex^ XBRepPrim_OneAxis::AxisTopVertex() {
		TopoDS_Vertex* aVertex = new TopoDS_Vertex(NativeHandle->AxisTopVertex());
		return gcnew XTopoDS_Vertex(aVertex);
	};

	//! Returns the Vertex  at the Bottom  altitude on the
	//! axis.
	XTopoDS_Vertex^ XBRepPrim_OneAxis::AxisBottomVertex() {
		TopoDS_Vertex* aVertex = new TopoDS_Vertex(NativeHandle->AxisBottomVertex());
		return gcnew XTopoDS_Vertex(aVertex);
	};

	//! Returns the vertex (0,VMax)
	XTopoDS_Vertex^ XBRepPrim_OneAxis::TopStartVertex() {
		TopoDS_Vertex* aVertex = new TopoDS_Vertex(NativeHandle->TopStartVertex());
		return gcnew XTopoDS_Vertex(aVertex);
	};

	//! Returns the vertex (angle,VMax)
	XTopoDS_Vertex^ XBRepPrim_OneAxis::TopEndVertex() {
		TopoDS_Vertex* aVertex = new TopoDS_Vertex(NativeHandle->TopEndVertex());
		return gcnew XTopoDS_Vertex(aVertex);
	};

	//! Returns the vertex (0,VMin)
	XTopoDS_Vertex^ XBRepPrim_OneAxis::BottomStartVertex() {
		TopoDS_Vertex* aVertex = new TopoDS_Vertex(NativeHandle->BottomStartVertex());
		return gcnew XTopoDS_Vertex(aVertex);
	};

	//! Returns the vertex (angle,VMax)
	XTopoDS_Vertex^ XBRepPrim_OneAxis::BottomEndVertex() {
		TopoDS_Vertex* aVertex = new TopoDS_Vertex(NativeHandle->BottomEndVertex());
		return gcnew XTopoDS_Vertex(aVertex);
	};
	XBRepPrim_OneAxis:: ~XBRepPrim_OneAxis() {
		NativeHandle = NULL;
	};
}
