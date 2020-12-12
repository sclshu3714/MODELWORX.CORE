#include <XGeomTools.h>

namespace TKGeomBase {
	//! A set of Curves from Geom2d.
	//! Dumps the surface on the stream.
	//! static 
	void XGeomTools::Dump(XGeom_Surface^% S, Standard_OStream% OS) {
		Handle(Geom_Surface) XS(S->GetSurface());
		GeomTools::Dump(XS, OS);
		S = gcnew XGeom_Surface(XS);
	};

	//! Writes the surface on the stream.
	//! static 
	void XGeomTools::Write(XGeom_Surface^% S, Standard_OStream% OS) {
		Handle(Geom_Surface) XS(S->GetSurface());
		GeomTools::Write(XS, OS);
		S = gcnew XGeom_Surface(XS);
	};

	//! Reads the surface from the stream.
	//! static 
	void XGeomTools::Read(XGeom_Surface^% S, Standard_IStream% IS) {
		Handle(Geom_Surface) XS(S->GetSurface());
		GeomTools::Read(XS, IS);
		S = gcnew XGeom_Surface(XS);
	};

	//! Dumps the Curve on the stream.
	//! static 
	void XGeomTools::Dump(XGeom_Curve^% C, Standard_OStream% OS) {
		Handle(Geom_Curve) XS(C->GetCurve());
		GeomTools::Dump(XS, OS);
		C = gcnew XGeom_Curve(XS);
	};

	//! Writes the Curve on the stream.
	//! static 
	void XGeomTools::Write(XGeom_Curve^% C, Standard_OStream% OS) {
		Handle(Geom_Curve) XS(C->GetCurve());
		GeomTools::Write(XS, OS);
		C = gcnew XGeom_Curve(XS);
	};

	//! Reads the Curve from the stream.
	//! static 
	void XGeomTools::Read(XGeom_Curve^% C, Standard_IStream% IS) {
		Handle(Geom_Curve) XS(C->GetCurve());
		GeomTools::Read(XS, IS);
		C = gcnew XGeom_Curve(XS);
	};

	//! Dumps the Curve on the stream.
	//! static 
	void XGeomTools::Dump(XGeom2d_Curve^% C, Standard_OStream% OS) {
		Handle(Geom2d_Curve) XS(C->GetCurve());
		GeomTools::Dump(XS, OS);
		C = gcnew XGeom2d_Curve(XS);
	};

	//! Writes the Curve on the stream.
	//! static 
	void XGeomTools::Write(XGeom2d_Curve^% C, Standard_OStream% OS) {
		Handle(Geom2d_Curve) XS(C->GetCurve());
		GeomTools::Write(XS, OS);
		C = gcnew XGeom2d_Curve(XS);
	};

	//! Reads the Curve from the stream.
	//! static 
	void XGeomTools::Read(XGeom2d_Curve^% C, Standard_IStream% IS) {
		Handle(Geom2d_Curve) XS(C->GetCurve());
		GeomTools::Read(XS, IS);
		C = gcnew XGeom2d_Curve(XS);
	};

	//! static 
	void XGeomTools::SetUndefinedTypeHandler(const Handle(GeomTools_UndefinedTypeHandler)& aHandler) {
		GeomTools::SetUndefinedTypeHandler(aHandler);
	};

	//! static 
	Handle(GeomTools_UndefinedTypeHandler) XGeomTools::GetUndefinedTypeHandler() {
		return GeomTools::GetUndefinedTypeHandler();
	};

	//! Reads the Standard_Real value from the stream. Zero is read
	//! in case of error
	//! static 
	void XGeomTools::GetReal(Standard_IStream% IS, Standard_Real% theValue) {
		Standard_Real theValueX(theValue);
		GeomTools::GetReal(IS, theValueX);
		theValue = Standard_Real(theValueX);
	};
}
