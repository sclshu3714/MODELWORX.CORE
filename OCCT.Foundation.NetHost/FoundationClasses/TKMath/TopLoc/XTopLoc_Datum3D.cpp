#include "XTopLoc_Datum3D.h"
namespace TKMath {

    //=======================================================================
    //function : TopLoc_Datum3D
    //purpose  : Identity
    //=======================================================================
    XTopLoc_Datum3D::XTopLoc_Datum3D()
    {
        NativeHandle() = new TopLoc_Datum3D();
    };

    //! Constructs a default Datum3D.
    XTopLoc_Datum3D::XTopLoc_Datum3D(Handle(TopLoc_Datum3D) pos) {
        NativeHandle() = pos;
    };

    //=======================================================================
    //function : TopLoc_Datum3D
    //purpose  : 
    //=======================================================================

    XTopLoc_Datum3D::XTopLoc_Datum3D(xgp_Trsf^ T)
    {
        NativeHandle() = new TopLoc_Datum3D(*T->GetTrsf());
    };

    //!
    Handle(TopLoc_Datum3D) XTopLoc_Datum3D::GetDatum3D() {
        return NativeHandle();
    };

    //! Returns a gp_Trsf which, when applied to this datum,
        //! produces the default datum.
    xgp_Trsf^ XTopLoc_Datum3D::Transformation() {
        gp_Trsf* temp = new gp_Trsf(NativeHandle()->Transformation());
        return gcnew xgp_Trsf(temp);
    };
    //=======================================================================
    //function : DumpJson
    //purpose  : 
    //=======================================================================
    void XTopLoc_Datum3D::DumpJson(Standard_OStream& theOStream, const Standard_Integer theDepth) {
        NativeHandle()->DumpJson(theOStream, theDepth);
    };                       

    //=======================================================================
    //function : ShallowDump
    //purpose  : 
    //=======================================================================

    void  XTopLoc_Datum3D::ShallowDump(Standard_OStream& S)  {
        NativeHandle()->ShallowDump(S);
    };
}


    
