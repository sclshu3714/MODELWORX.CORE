#include <XGraphic3d_Buffer.h>
namespace TKService {
    ////! Empty constructor.
    //XGraphic3d_Buffer(XNCollection_BaseAllocator^ theAlloc) {

    //};

    XGraphic3d_Buffer::XGraphic3d_Buffer(Handle(Graphic3d_Buffer) pos) {
        NativeHandle() = pos;
    };

    void XGraphic3d_Buffer::SetBufferHandle(Handle(Graphic3d_Buffer) pos) {
        NativeHandle() = pos;
    };

    Handle(Graphic3d_Buffer) XGraphic3d_Buffer::GetBuffer() {
        return NativeHandle();
    };

    //! Return number of initially allocated elements which can fit into this buffer,
    //! while NbElements can be overwritten to smaller value.
    Standard_Integer XGraphic3d_Buffer::NbMaxElements() {
        return NativeHandle()->NbMaxElements();
    };

    //! @return array of attributes definitions
    XGraphic3d_Attribute^ XGraphic3d_Buffer::AttributesArray() {
       const Graphic3d_Attribute* temp = NativeHandle()->AttributesArray();
       XGraphic3d_Attribute^ IAttribute = gcnew XGraphic3d_Attribute();
       IAttribute->Id = safe_cast<XGraphic3d_TypeOfAttribute>(temp->Id);
       IAttribute->DataType = safe_cast<XGraphic3d_TypeOfData>(temp->DataType);
       return IAttribute;
    };

    //! @return attribute definition
    XGraphic3d_Attribute^ XGraphic3d_Buffer::Attribute(Standard_Integer theAttribIndex) {
        const Graphic3d_Attribute& temp = NativeHandle()->Attribute(theAttribIndex);
        XGraphic3d_Attribute^ IAttribute = gcnew XGraphic3d_Attribute();
        IAttribute->Id = safe_cast<XGraphic3d_TypeOfAttribute>(temp.Id);
        IAttribute->DataType = safe_cast<XGraphic3d_TypeOfData>(temp.DataType);
        return IAttribute;
    };

    //! @return attribute definition
    XGraphic3d_Attribute^ XGraphic3d_Buffer::ChangeAttribute(Standard_Integer theAttribIndex) {
        Graphic3d_Attribute& temp = NativeHandle()->ChangeAttribute(theAttribIndex);
        XGraphic3d_Attribute^ IAttribute = gcnew XGraphic3d_Attribute();
        IAttribute->Id = safe_cast<XGraphic3d_TypeOfAttribute>(temp.Id);
        IAttribute->DataType = safe_cast<XGraphic3d_TypeOfData>(temp.DataType);
        return IAttribute;
    };

    //! Find attribute index.
    //! @param theAttrib attribute to find
    //! @return attribute index or -1 if not found
    Standard_Integer XGraphic3d_Buffer::FindAttribute(XGraphic3d_TypeOfAttribute theAttrib) {
        return NativeHandle()->FindAttribute(safe_cast<Graphic3d_TypeOfAttribute>(theAttrib));
    };

    //! @name data accessors for interleaved array

    //! @return data offset to specified attribute
    Standard_Integer XGraphic3d_Buffer::AttributeOffset(Standard_Integer theAttribIndex) {
        return NativeHandle()->AttributeOffset(theAttribIndex);
    };

    //! @return data for specified attribute
    Standard_Byte* XGraphic3d_Buffer::Data(Standard_Integer theAttribIndex) {
        return (Standard_Byte*)NativeHandle()->Data(theAttribIndex);
    };

    //! @return data for specified attribute
    Standard_Byte* XGraphic3d_Buffer::ChangeData(Standard_Integer theAttribIndex) {
        return (Standard_Byte*)NativeHandle()->Data(theAttribIndex);
    };

    //! Access specified element.
    Standard_Byte* XGraphic3d_Buffer::value(Standard_Integer theElem) {
        return (Standard_Byte*)NativeHandle()->value(theElem);
    };

    //! Access specified element.
    Standard_Byte* XGraphic3d_Buffer::changeValue(Standard_Integer theElem) {
        return (Standard_Byte*)NativeHandle()->changeValue(theElem);
    };

    //! Access element with specified position and type.
    template <typename Type_t>
    Type_t XGraphic3d_Buffer::Value(Standard_Integer theElem) {
        return NativeHandle()->Value(theElem);
    };

    //! Access element with specified position and type.
    template <typename Type_t>
    Type_t XGraphic3d_Buffer::ChangeValue(Standard_Integer theElem) {
        return NativeHandle()->ChangeValue(theElem);
    };

    //! @name general accessors

    //! Return the attribute data with stride size specific to this attribute.
    //! @param theAttrib       attribute to find
    //! @param theAttribIndex  index of found attribute
    //! @param theAttribStride stride in bytes between values of this attribute within returned data pointer
    Standard_Byte* XGraphic3d_Buffer::ChangeAttributeData(XGraphic3d_TypeOfAttribute theAttrib, Standard_Integer% theAttribIndex, Standard_Size% theAttribStride) {
        Standard_Integer theAttribIndexX(theAttribIndex); Standard_Size theAttribStrideX(theAttribStride);
        Standard_Byte* Result = (Standard_Byte*)NativeHandle()->ChangeAttributeData(safe_cast<Graphic3d_TypeOfAttribute>(theAttrib), theAttribIndexX, theAttribStrideX);
        theAttribIndex = theAttribIndexX; theAttribStride = theAttribStrideX;
        return Result;
    };

    //! Return the attribute data with stride size specific to this attribute.
    //! @param theAttrib       attribute to find
    //! @param theAttribIndex  index of found attribute
    //! @param theAttribStride stride in bytes between values of this attribute within returned data pointer
    Standard_Byte* XGraphic3d_Buffer::AttributeData(XGraphic3d_TypeOfAttribute theAttrib, Standard_Integer% theAttribIndex, Standard_Size% theAttribStride) {
        Standard_Integer theAttribIndexX(theAttribIndex); Standard_Size theAttribStrideX(theAttribStride);
        Standard_Byte* Result = (Standard_Byte*)NativeHandle()->AttributeData(safe_cast<Graphic3d_TypeOfAttribute>(theAttrib), theAttribIndexX, theAttribStrideX);
        theAttribIndex = theAttribIndexX; theAttribStride = theAttribStrideX;
        return Result;
    };

    //! Release buffer.
    void XGraphic3d_Buffer::release() {
        NativeHandle()->release();
    };

    //! Allocates new empty array
    bool XGraphic3d_Buffer::Init(Standard_Integer theNbElems, XGraphic3d_Attribute^ theAttribs, Standard_Integer theNbAttribs) {
        Graphic3d_Attribute* theAttribsX = new Graphic3d_Attribute();
        theAttribsX->Id = safe_cast<Graphic3d_TypeOfAttribute>(theAttribs->Id);
        theAttribsX->DataType = safe_cast<Graphic3d_TypeOfData>(theAttribs->DataType);
        return NativeHandle()->Init(theNbElems, theAttribsX, theNbAttribs);
    };

    //! Allocates new empty array
    bool XGraphic3d_Buffer::Init(Standard_Integer theNbElems, Graphic3d_Array1OfAttribute& theAttribs) {
        return NativeHandle()->Init(theNbElems, theAttribs);
    };

    //! Flag indicating that attributes in the buffer are interleaved; TRUE by default.
    //! Requires sub-classing for creating a non-interleaved buffer (advanced usage).
    Standard_Boolean XGraphic3d_Buffer::IsInterleaved() {
        return NativeHandle()->IsInterleaved();
    };

    //! Return TRUE if data can be invalidated; FALSE by default.
    //! Requires sub-classing for creating a mutable buffer (advanced usage).
    Standard_Boolean XGraphic3d_Buffer::IsMutable() {
        return NativeHandle()->IsMutable();
    };

    //! Return invalidated range; EMPTY by default.
    //! Requires sub-classing for creating a mutable buffer (advanced usage).
    Graphic3d_BufferRange XGraphic3d_Buffer::InvalidatedRange() {
        return NativeHandle()->InvalidatedRange();
    };

    //! Reset invalidated range.
    //! Requires sub-classing for creating a mutable buffer (advanced usage).
    void XGraphic3d_Buffer::Validate() {
        NativeHandle()->Validate();
    };

    //! Invalidate entire buffer.
    void XGraphic3d_Buffer::Invalidate() {
        NativeHandle()->Invalidate();
    };
}