#include <xgce_Root.h>

namespace TKGeomBase {

    //! DEFINE_STANDARD_ALLOC
    xgce_Root::xgce_Root() {

    };

    xgce_Root::xgce_Root(gce_Root* pos) {
        NativeHandle = pos;
    };

    void xgce_Root::SetRoot(gce_Root* pos) {
        NativeHandle = pos;
    };

    gce_Root* xgce_Root::GetRoot() {
        return NativeHandle;
    };

    //! Returns true if the construction is successful.
    Standard_Boolean xgce_Root::IsDone() {
        return NativeHandle->IsDone();
    };

    //! Returns the status of the construction:
    //! -   gce_Done, if the construction is successful, or
    //! -   another value of the gce_ErrorType enumeration
    //! indicating why the construction failed.
    xgce_ErrorType xgce_Root::Status() {
        return safe_cast<xgce_ErrorType>(NativeHandle->Status());
    };
}
