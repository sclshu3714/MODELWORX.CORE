#include <XBRepBuilderAPI_MakeShell.h>
namespace TKTopAlgo {
	//! Constructs an empty shell framework. The Init
		//! function is used to define the construction arguments.
		//! Warning
		//! The function Error will return
		//! BRepBuilderAPI_EmptyShell if it is called before the function Init.
	XBRepBuilderAPI_MakeShell::XBRepBuilderAPI_MakeShell() {
		NativeHandle = new BRepBuilderAPI_MakeShell();
		SetMakeShapeHandle(NativeHandle);
	};

	//! Constructs a shell from the surface S.
	//! Standard_Boolean Segment = Standard_False
	XBRepBuilderAPI_MakeShell::XBRepBuilderAPI_MakeShell(XGeom_Surface^ S, Standard_Boolean Segment) {
		NativeHandle = new BRepBuilderAPI_MakeShell(S->GetSurface(), Segment);
		SetMakeShapeHandle(NativeHandle);
	};

	//! Constructs a shell from the surface S,
	//! limited in the u parametric direction by the two
	//! parameter values UMin and UMax, and limited in the v
	//! parametric direction by the two parameter values VMin and VMax.
	//! Standard_Boolean Segment = Standard_False
	XBRepBuilderAPI_MakeShell::XBRepBuilderAPI_MakeShell(XGeom_Surface^ S, Standard_Real UMin, Standard_Real UMax, Standard_Real VMin, Standard_Real VMax, Standard_Boolean Segment) {
		NativeHandle = new BRepBuilderAPI_MakeShell(S->GetSurface(), UMin, UMax, VMin, VMax, Segment);
		SetMakeShapeHandle(NativeHandle);
	};

	//! Defines or redefines the arguments
	//! for the construction of a shell. The construction is initialized
	//! with the surface S, limited in the u parametric direction by the
	//! two parameter values UMin and UMax, and in the v parametric
	//! direction by the two parameter values VMin and VMax.
	//! Warning
	//! The function Error returns:
	//! -      BRepBuilderAPI_ShellParametersOutOfRange
	//! when the given parameters are outside the bounds of the
	//! surface or the basis surface if S is trimmed
	//! Standard_Boolean Segment = Standard_False
	void XBRepBuilderAPI_MakeShell::Init(XGeom_Surface^ S, Standard_Real UMin, Standard_Real UMax, Standard_Real VMin, Standard_Real VMax, Standard_Boolean Segment) {
		NativeHandle->Init(S->GetSurface(), UMin, UMax, VMin, VMax, Segment);
	};

	//! Returns true if the shell is built.
	Standard_Boolean XBRepBuilderAPI_MakeShell::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the construction status:
	//! -   BRepBuilderAPI_ShellDone if the shell is built, or
	//! -   another value of the BRepBuilderAPI_ShellError
	//! enumeration indicating why the construction failed.
	//! This is frequently BRepBuilderAPI_ShellParametersOutOfRange
	//! indicating that the given parameters are outside the bounds of the surface.
	XBRepBuilderAPI_ShellError XBRepBuilderAPI_MakeShell::Error() {
		return safe_cast<XBRepBuilderAPI_ShellError>(NativeHandle->Error());
	};

	//! Returns the new Shell.
	XTopoDS_Shell^ XBRepBuilderAPI_MakeShell::Shell() {
		TopoDS_Shell* temp = new TopoDS_Shell(NativeHandle->Shell());
		return gcnew XTopoDS_Shell(temp);
	};
	XBRepBuilderAPI_MakeShell::operator XTopoDS_Shell^() {
		TopoDS_Shell* temp = new TopoDS_Shell(NativeHandle->Shell());
		return gcnew XTopoDS_Shell(temp);
	};
}

