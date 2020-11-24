#include "XTDataStd_Name.h"
namespace TKLCAF {

	XTDataStd_Name::XTDataStd_Name() : XTDF_Attribute(){
		NativeHandle() = new TDataStd_Name();
		SetNativeHandle(NativeHandle());
	};


	XTDataStd_Name::XTDataStd_Name(Handle(TDataStd_Name) pos) : XTDF_Attribute(pos){
		NativeHandle() = pos;
		SetNativeHandle(NativeHandle());
	};

	//XTDataStd_Name::XTDataStd_Name(XTDF_Attribute^ anAttr) : XTDF_Attribute(anAttr->GetAttribute()) {
	//	XTDataStd_Name^ theAttr = dynamic_cast<XTDataStd_Name^>(anAttr);
	//	NativeHandle() = theAttr->GetName();
	//	SetNativeHandle(NativeHandle());
	//};

	Handle(TDataStd_Name) XTDataStd_Name::GetName() {
		return NativeHandle();
	};

	//! class methods working on the name itself
	//! ========================================
	//! Returns the GUID for name attributes.
	XStandard_GUID^ XTDataStd_Name::GetID() {
		Standard_GUID standard_GUID = TDataStd_Name::GetID();
		return gcnew XStandard_GUID(standard_GUID);
	};

	//! Creates (if does not exist) and sets the name in the name attribute.
	//! from any label <L>  search in father  labels (L is not
	//! concerned) the first name attribute.if found set it in
	//! <father>.
	//! class methods working on the name tree
	//! ======================================
	//! Search in the  whole TDF_Data the Name attribute which
	//! fit with <fullPath>. Returns True if found.
	//! Search  under <currentLabel>  a  label which fit with
	//! <name>. Returns True if  found. Shortcut which  avoids
	//! building a ListOfExtendedStrin.
	//! Search in the whole TDF_Data the label which fit with name
	//! Returns True if found.
	//! tools methods to translate path <-> pathlist
	//! ===========================================
	//! move to draw For Draw test we may provide this tool method which convert a path in a
	//! sequence of string to call after the FindLabel methods.
	//! Example: if it's given "Assembly:Part_1:Sketch_5" it will return in <pathlist>
	//! the list of 3 strings: "Assembly","Part_1","Sketch_5".
	//! move to draw from <pathlist> build the string path
	//! Name methods
	//! ============
	XTDataStd_Name^ XTDataStd_Name::Set(XTDF_Label^ label, XTCollection_ExtendedString^ string) {
		return gcnew XTDataStd_Name(TDataStd_Name::Set(label->GetLabel(), string->GetExtendedString()));
	};

	XTDataStd_Name^ XTDataStd_Name::Set(XTDF_Label^ label, XStandard_GUID^ guid, XTCollection_ExtendedString^ string) {
		return gcnew XTDataStd_Name(TDataStd_Name::Set(label->GetLabel(), guid->GetGUID(), string->GetExtendedString()));
	};

	//! Sets <S> as name. Raises if <S> is not a valid name.
	void XTDataStd_Name::Set(XTCollection_ExtendedString^ S) {
		NativeHandle()->Set(S->GetExtendedString());
	};

	void XTDataStd_Name::SetID(const Standard_GUID& theGuid) {
		NativeHandle()->SetID(theGuid);
	};

	//! Sets the explicit user defined GUID  to the attribute.
	void XTDataStd_Name::SetID(XStandard_GUID^ guid) {
		NativeHandle()->SetID(guid->GetGUID());
	};

	//! Sets default GUID for the attribute.
	void XTDataStd_Name::SetID() {
		NativeHandle()->SetID();
	};

	//! Returns the name contained in this name attribute.
	const XTCollection_ExtendedString^ XTDataStd_Name::Get() {
		std::cout << "  Name: " << NativeHandle()->Get() << std::endl;
		return gcnew XTCollection_ExtendedString(NativeHandle()->Get());
	};


	XStandard_GUID^ XTDataStd_Name::ID() {
		return gcnew XStandard_GUID(NativeHandle()->ID());
	};

	void XTDataStd_Name::Restore(XTDF_Attribute^ with) {
		NativeHandle()->Restore(with->GetAttribute());
	};

	XTDF_Attribute^ XTDataStd_Name::NewEmpty() {
		return gcnew XTDF_Attribute(NativeHandle()->NewEmpty());
	};

	void XTDataStd_Name::Paste(XTDF_Attribute^ intoAttribute, Handle(TDF_RelocationTable)& aRelocationTable) {
		NativeHandle()->Paste(intoAttribute->GetAttribute(), aRelocationTable);
	};

	Standard_OStream& XTDataStd_Name::Dump(Standard_OStream& anOS) {
		return NativeHandle()->Dump(anOS);
	};
}