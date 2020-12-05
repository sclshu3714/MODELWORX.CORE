#include <XTopoDS_Builder.h>
namespace TKBRep {

    XTopoDS_Builder::XTopoDS_Builder(TopoDS_Builder* pos) {
        NativeHandle = pos;
    };

    void XTopoDS_Builder::SetTopoDSBuilderHandle(TopoDS_Builder* pos) {
        NativeHandle = pos;
    };

    TopoDS_Builder* XTopoDS_Builder::GetTopoDSBuilder() {
        return NativeHandle;
    }

    //! Make an empty Wire.
    void XTopoDS_Builder::MakeWire(XTopoDS_Wire^ W) {
        NativeHandle->MakeWire(*W->GetWire());
    };

    //! Make an empty Shell.
    void XTopoDS_Builder::MakeShell(XTopoDS_Shell^ S) {
        NativeHandle->MakeShell(*S->GetShell());
    };

    //! Make a Solid covering the whole 3D space.
    void XTopoDS_Builder::MakeSolid(XTopoDS_Solid^ S) {
        NativeHandle->MakeSolid(*S->GetSolid());
    };

    //! Make an empty Composite Solid.
    void XTopoDS_Builder::MakeCompSolid(XTopoDS_CompSolid^ C) {
        NativeHandle->MakeCompSolid(*C->GetCompSolid());
    };

    //! Make an empty Compound.
    void XTopoDS_Builder::MakeCompound(XTopoDS_Compound^ C) {
        NativeHandle->MakeCompound(*C->GetCompound());
    };

    //! Add the Shape C in the Shape S.
    //! Exceptions
    //! - TopoDS_FrozenShape if S is not free and cannot be modified.
    //! - TopoDS__UnCompatibleShapes if S and C are not compatible.
    void XTopoDS_Builder::Add(XTopoDS_Shape^ XS, XTopoDS_Shape^ XC) {
        TopoDS_Shape* S = new TopoDS_Shape(*XS->GetShape());
        TopoDS_Shape* C = new TopoDS_Shape(*XC->GetShape());
        NativeHandle->Add(*S, *C);
    };

    //! Remove the Shape C from the Shape S.
    //! Exceptions
    //! TopoDS_FrozenShape if S is frozen and cannot be modified.
    void XTopoDS_Builder::Remove(XTopoDS_Shape^ XS, XTopoDS_Shape^ XC) {
        TopoDS_Shape* S = new TopoDS_Shape(*XS->GetShape());
        TopoDS_Shape* C = new TopoDS_Shape(*XC->GetShape());
        NativeHandle->Remove(*S, *C);
    };
}
