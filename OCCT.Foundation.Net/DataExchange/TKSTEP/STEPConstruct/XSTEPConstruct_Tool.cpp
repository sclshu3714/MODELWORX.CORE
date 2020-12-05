#include "XSTEPConstruct_Tool.h"

namespace TKSTEP {
    //! Creates an empty tool
    XSTEPConstruct_Tool::XSTEPConstruct_Tool() {
        NativeHandle = new STEPConstruct_Tool();
    };

    //! Creates an empty tool
    XSTEPConstruct_Tool::XSTEPConstruct_Tool(STEPConstruct_Tool pos) {
        NativeHandle = &pos;
    };

    //! Creates a tool and loads it with worksession
    XSTEPConstruct_Tool::XSTEPConstruct_Tool(const Handle(XSControl_WorkSession)& WS) {
        NativeHandle = new STEPConstruct_Tool(WS);
    };

    //! 
    STEPConstruct_Tool XSTEPConstruct_Tool::GetTool() {
        return *NativeHandle;
    };

    //! Returns currently loaded WorkSession
    const Handle(XSControl_WorkSession)& XSTEPConstruct_Tool::WS() {
       return NativeHandle->WS();
    };

    //! Returns current model (Null if not loaded)
    Handle(Interface_InterfaceModel) XSTEPConstruct_Tool::Model() {
        return NativeHandle->Model();
    };

    //! Returns current graph (recomputing if necessary)
    //! recompute = Standard_False
    const Interface_Graph& XSTEPConstruct_Tool::Graph(const Standard_Boolean recompute) {
        return NativeHandle->Graph(recompute);
    };

    //! Returns TransientProcess (reading; Null if not loaded)
    const Handle(Transfer_TransientProcess)& XSTEPConstruct_Tool::TransientProcess() {
        return NativeHandle->TransientProcess();
    };

    //! Returns FinderProcess (writing; Null if not loaded)
    const Handle(Transfer_FinderProcess)& XSTEPConstruct_Tool::FinderProcess() {
        return NativeHandle->FinderProcess();
    };
}