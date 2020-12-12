#include <XGC_Root.h>

namespace TKGeomBase {


    //! DEFINE_STANDARD_ALLOC
    XGC_Root::XGC_Root() {
        
    };

    XGC_Root::XGC_Root(GC_Root* pos) {
        NativeHandle = pos;
    };

    void XGC_Root::SetRoot(GC_Root* pos) {
        NativeHandle = pos;
    };

    GC_Root* XGC_Root::GetRoot() {
        return NativeHandle;
    };

    //! Returns true if the construction is successful.
    Standard_Boolean XGC_Root::IsDone() {
        return NativeHandle->IsDone();
    };

    //! Returns the status of the construction:
    //! -   gce_Done, if the construction is successful, or
    //! -   another value of the gce_ErrorType enumeration
    //! indicating why the construction failed.
    xgce_ErrorType XGC_Root::Status() {
        return safe_cast<xgce_ErrorType>(NativeHandle->Status());
    };
}
