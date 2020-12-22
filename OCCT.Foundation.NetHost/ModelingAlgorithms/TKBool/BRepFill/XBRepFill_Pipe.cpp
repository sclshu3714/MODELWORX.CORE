#include <XBRepFill_Pipe.h>
namespace TKBool {
    XBRepFill_Pipe::XBRepFill_Pipe() {
        NativeHandle = new BRepFill_Pipe();
    };

    XBRepFill_Pipe::XBRepFill_Pipe(BRepFill_Pipe* pos) {
        NativeHandle = pos;
    };

    void XBRepFill_Pipe::SetPipeHandle(BRepFill_Pipe* pos) {
        NativeHandle = pos;
    };

    BRepFill_Pipe* XBRepFill_Pipe::GetPipeHandle() {
        return NativeHandle;
    };

    //GeomFill_Trihedron aMode = GeomFill_IsCorrectedFrenet, Standard_Boolean ForceApproxC1 = Standard_False, Standard_Boolean GeneratePartCase = Standard_False
    XBRepFill_Pipe::XBRepFill_Pipe(XTopoDS_Wire^ Spine, XTopoDS_Shape^ Profile, XGeomFill_Trihedron aMode, Standard_Boolean ForceApproxC1, Standard_Boolean GeneratePartCase) {
        NativeHandle = new BRepFill_Pipe(*Spine->GetWire(), *Profile->GetShape(), safe_cast<GeomFill_Trihedron>(aMode), ForceApproxC1, GeneratePartCase);
    };

    //Standard_Boolean GeneratePartCase = Standard_False
    void XBRepFill_Pipe::Perform(XTopoDS_Wire^ Spine, XTopoDS_Shape^ Profile, Standard_Boolean GeneratePartCase) {
        NativeHandle->Perform(*Spine->GetWire(), *Profile->GetShape(), GeneratePartCase);
    };

    XTopoDS_Shape^ XBRepFill_Pipe::Spine() {
        TopoDS_Shape* temp = new TopoDS_Shape(NativeHandle->Spine());
        return gcnew XTopoDS_Shape(temp);
    };

    XTopoDS_Shape^ XBRepFill_Pipe::Profile() {
        TopoDS_Shape* temp = new TopoDS_Shape(NativeHandle->Profile());
        return gcnew XTopoDS_Shape(temp);
    };

    XTopoDS_Shape^ XBRepFill_Pipe::Shape() {
        TopoDS_Shape* temp = new TopoDS_Shape(NativeHandle->Shape());
        return gcnew XTopoDS_Shape(temp);
    };

    Standard_Real XBRepFill_Pipe::ErrorOnSurface() {
        return NativeHandle->ErrorOnSurface();
    };

    XTopoDS_Shape^ XBRepFill_Pipe::FirstShape() {
        TopoDS_Shape* temp = new TopoDS_Shape(NativeHandle->FirstShape());
        return gcnew XTopoDS_Shape(temp);
    };

    XTopoDS_Shape^ XBRepFill_Pipe::LastShape() {
        TopoDS_Shape* temp = new TopoDS_Shape(NativeHandle->LastShape());
        return gcnew XTopoDS_Shape(temp);
    };

    //! Returns the  list   of shapes generated   from the
    //! shape <S>.
    void XBRepFill_Pipe::Generated(XTopoDS_Shape^ S, XTopTools_ListOfShape^ L) {
        NativeHandle->Generated(*S->GetShape(), *L->GetListOfShapes());
    };

    //! Returns the face created from an edge of the spine
    //! and an edge of the profile.
    //! if the edges are not in the spine or the profile
    XTopoDS_Face^ XBRepFill_Pipe::Face(XTopoDS_Edge^ ESpine, XTopoDS_Edge^ EProfile) {
        TopoDS_Face* temp = new TopoDS_Face(NativeHandle->Face(*ESpine->GetEdge(), *EProfile->GetEdge()));
        return gcnew XTopoDS_Face(temp);
    };

    //! Returns the edge created from an edge of the spine
    //! and a vertex of the profile.
    //! if the edge or the vertex are not in  the spine or
    //! the profile.
    XTopoDS_Edge^ XBRepFill_Pipe::Edge(XTopoDS_Edge^ ESpine, XTopoDS_Vertex^ VProfile) {
        TopoDS_Edge* temp = new TopoDS_Edge(NativeHandle->Edge(*ESpine->GetEdge(), *VProfile->GetVertex()));
        return gcnew XTopoDS_Edge(temp);
    };

    //! Returns  the shape created from the profile at the
    //! position of the vertex VSpine.
    //! if the vertex is not in the Spine
    XTopoDS_Shape^ XBRepFill_Pipe::Section(XTopoDS_Vertex^ VSpine) {
        TopoDS_Shape* temp = new TopoDS_Shape(NativeHandle->Section( *VSpine->GetVertex()));
        return gcnew XTopoDS_Shape(temp);
    };

    //! Create a Wire by sweeping the Point along the <spine>
    //! if the <Spine> is undefined
    XTopoDS_Wire^ XBRepFill_Pipe::PipeLine(xgp_Pnt^ Point) {
        TopoDS_Wire* temp = new TopoDS_Wire(NativeHandle->PipeLine(*Point->GetPnt()));
        return gcnew XTopoDS_Wire(temp);
    };
}