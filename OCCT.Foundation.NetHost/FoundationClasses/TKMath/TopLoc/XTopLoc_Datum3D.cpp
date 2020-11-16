#include "XTopLoc_Datum3D.h"
namespace TKMath {

    //=======================================================================
    //function : TopLoc_Datum3D
    //purpose  : Identity
    //=======================================================================
    XTopLoc_Datum3D::XTopLoc_Datum3D()
    {
        NativeHandle = new TopLoc_Datum3D();
    };

    //! Constructs a default Datum3D.
    XTopLoc_Datum3D::XTopLoc_Datum3D(TopLoc_Datum3D* pos) {
        NativeHandle = new TopLoc_Datum3D(*pos);
    };

    //=======================================================================
    //function : TopLoc_Datum3D
    //purpose  : 
    //=======================================================================

    XTopLoc_Datum3D::XTopLoc_Datum3D(xgp_Trsf^ T)
    {
        NativeHandle = new TopLoc_Datum3D(T->GetTrsf());
    };

    //!
    TopLoc_Datum3D XTopLoc_Datum3D::GetDatum3D() {
        return *NativeHandle;
    };

    //! Returns a gp_Trsf which, when applied to this datum,
        //! produces the default datum.
    xgp_Trsf^ XTopLoc_Datum3D::Transformation() {
        return gcnew xgp_Trsf(NativeHandle->Transformation());
    };
    //=======================================================================
    //function : DumpJson
    //purpose  : 
    //=======================================================================
    void XTopLoc_Datum3D::DumpJson(Standard_OStream& theOStream, const Standard_Integer theDepth) {
        NativeHandle->DumpJson(theOStream, theDepth);
    };                       

    //=======================================================================
    //function : ShallowDump
    //purpose  : 
    //=======================================================================

    void  XTopLoc_Datum3D::ShallowDump(Standard_OStream& S)  {
        NativeHandle->ShallowDump(S);
    };
}


    
