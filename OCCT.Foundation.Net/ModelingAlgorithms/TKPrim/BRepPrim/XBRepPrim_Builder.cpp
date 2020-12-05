#include <XBRepPrim_Builder.h>

namespace TKPrim {
    //! Creates an empty, useless  Builder. Necesseray for
        //! compilation.
    XBRepPrim_Builder::XBRepPrim_Builder() {
        NativeHandle = new BRepPrim_Builder();
    };

    //! Creates from a Builder.
    XBRepPrim_Builder::XBRepPrim_Builder(BRepPrim_Builder* pos) {
        NativeHandle = pos;
    };

    void XBRepPrim_Builder::SetBRepPrimBuilderHandle(BRepPrim_Builder* pos) {
        NativeHandle = pos;
    };

    BRepPrim_Builder* XBRepPrim_Builder::GetBRepPrimBuilder() {
        return NativeHandle;
    };

    XBRep_Builder^ XBRepPrim_Builder::Builder() {
        BRep_Builder* aBuilder = new BRep_Builder(NativeHandle->Builder());
        return gcnew XBRep_Builder(aBuilder);
    };

    //! Make a empty Shell.
    void XBRepPrim_Builder::MakeShell(XTopoDS_Shell^ S) {
        NativeHandle->MakeShell(*S->GetShell());
    };

    //! Returns in   <F> a  Face  built  with   the  plane
    //! equation <P>. Used by all primitives.
    void XBRepPrim_Builder::MakeFace(XTopoDS_Face^ F, xgp_Pln^ P) {
        NativeHandle->MakeFace(*F->GetFace(), *P->GetPln());
    };

    //! Returns in <W> an empty Wire.
    void XBRepPrim_Builder::MakeWire(XTopoDS_Wire^ W) {
        NativeHandle->MakeWire(*W->GetWire());
    };

    //! Returns in <E> a degenerated edge.
    void XBRepPrim_Builder::MakeDegeneratedEdge(XTopoDS_Edge^ E) {
        NativeHandle->MakeDegeneratedEdge(*E->GetEdge());
    };

    //! Returns   in <E>  an  Edge  built  with  the  line
    //! equation  <L>.
    void XBRepPrim_Builder::MakeEdge(XTopoDS_Edge^ E, xgp_Lin^ L) {
        NativeHandle->MakeEdge(*E->GetEdge(), *L->GetLin());
    };

    //! Returns  in <E>   an  Edge  built  with the circle
    //! equation  <C>.
    void XBRepPrim_Builder::MakeEdge(XTopoDS_Edge^ E, xgp_Circ^ C) {
        NativeHandle->MakeEdge(*E->GetEdge(), *C->GetCirc());
    };

    //! Sets the line <L> to be the curve representing the
    //! edge <E> in the parametric space of the surface of
    //! <F>.
    void XBRepPrim_Builder::SetPCurve(XTopoDS_Edge^ E, XTopoDS_Face^ F, xgp_Lin2d^ L) {
        NativeHandle->SetPCurve(*E->GetEdge(), *F->GetFace(), *L->GetLin2d());
    };

    //! Sets the    lines  <L1,L2>  to   be     the curves
    //! representing the edge <E>  in the parametric space
    //! of the closed surface of <F>.
    void XBRepPrim_Builder::SetPCurve(XTopoDS_Edge^ E, XTopoDS_Face^ F, xgp_Lin2d^ L1, xgp_Lin2d^ L2) {
        NativeHandle->SetPCurve(*E->GetEdge(), *F->GetFace(), *L1->GetLin2d(), *L2->GetLin2d());
    };

    //! Sets the  circle <C> to  be the curve representing
    //! the  edge <E>  in   the  parametric  space of  the
    //! surface of <F>.
    void XBRepPrim_Builder::SetPCurve(XTopoDS_Edge^ E, XTopoDS_Face^ F, xgp_Circ2d^ C) {
        NativeHandle->SetPCurve(*E->GetEdge(), *F->GetFace(), *C->GetCirc2d());
    };

    //! Returns in <V> a Vertex built with the point <P>.
    void XBRepPrim_Builder::MakeVertex(XTopoDS_Vertex^ V, xgp_Pnt^ P) {
        NativeHandle->MakeVertex(*V->GetVertex(), *P->GetPnt());
    };

    //! Reverses the Face <F>.
    void XBRepPrim_Builder::ReverseFace(XTopoDS_Face^ F) {
        NativeHandle->ReverseFace(*F->GetFace());
    };

    //! Adds the Vertex <V> in the Edge <E>.  <P> is the
    //! parameter of the vertex on the  edge.  If direct
    //! is False the Vertex is reversed.
    void XBRepPrim_Builder::AddEdgeVertex(XTopoDS_Edge^ E, XTopoDS_Vertex^ V, Standard_Real P, Standard_Boolean direct) {
        NativeHandle->AddEdgeVertex(*E->GetEdge(), *V->GetVertex(), P, direct);
    };

    //! Adds  the Vertex <V>  in the Edge <E>.   <P1,P2>
    //! are the  parameters of the  vertex on the closed
    //! edge.
    void XBRepPrim_Builder::AddEdgeVertex(XTopoDS_Edge^ E, XTopoDS_Vertex^ V, Standard_Real P1, Standard_Real P2) {
        NativeHandle->AddEdgeVertex(*E->GetEdge(), *V->GetVertex(), P1, P2);
    };

    //! <P1,P2> are the parameters of the  vertex on the
    //! edge.  The edge is a closed curve.
    void XBRepPrim_Builder::SetParameters(XTopoDS_Edge^ E, XTopoDS_Vertex^ V, Standard_Real P1, Standard_Real P2) {
        NativeHandle->SetParameters(*E->GetEdge(), *V->GetVertex(), P1, P2);
    };

    //! Adds the Edge <E> in the  Wire <W>, if direct is
    //! False the Edge is reversed.
    void XBRepPrim_Builder::AddWireEdge(XTopoDS_Wire^ W, XTopoDS_Edge^ E, Standard_Boolean direct) {
        NativeHandle->AddWireEdge(*W->GetWire(), *E->GetEdge(), direct);
    };

    //! Adds the Wire <W> in  the Face <F>.
    void XBRepPrim_Builder::AddFaceWire(XTopoDS_Face^ F, XTopoDS_Wire^ W) {
        NativeHandle->AddFaceWire(*F->GetFace(), *W->GetWire());
    };

    //! Adds the Face <F>  in the Shell <Sh>.
    void XBRepPrim_Builder::AddShellFace(XTopoDS_Shell^ Sh, XTopoDS_Face^ F) {
        NativeHandle->AddShellFace(*Sh->GetShell(), *F->GetFace());
    };

    //! This is called once an edge is completed. It gives
    //! the opportunity to perform any post treatment.
    void XBRepPrim_Builder::CompleteEdge(XTopoDS_Edge^ E) {
        NativeHandle->CompleteEdge(*E->GetEdge());
    };

    //! This is called once a wire is  completed. It gives
    //! the opportunity to perform any post treatment.
    void XBRepPrim_Builder::CompleteWire(XTopoDS_Wire^ W) {
        NativeHandle->CompleteWire(*W->GetWire());
    };

    //! This is called once a face is  completed. It gives
    //! the opportunity to perform any post treatment.
    void XBRepPrim_Builder::CompleteFace(XTopoDS_Face^ F) {
        NativeHandle->CompleteFace(*F->GetFace());
    };

    //! This is called once a shell is  completed. It gives
    //! the opportunity to perform any post treatment.
    void XBRepPrim_Builder::CompleteShell(XTopoDS_Shell^ S) {
        NativeHandle->CompleteShell(*S->GetShell());
    };
}