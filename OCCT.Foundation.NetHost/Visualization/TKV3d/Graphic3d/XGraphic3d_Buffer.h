// Copyright (c) 2014 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.

#ifndef _XGraphic3d_Buffer_HeaderFile
#define _XGraphic3d_Buffer_HeaderFile
#pragma once
#include <Graphic3d_Buffer.hxx>
#include <XGraphic3d_BufferRange.h>
#include <NCollection_Haft.h>

#include <Graphic3d_BufferRange.hxx>
#include <Graphic3d_Vec.hxx>
#include <NCollection_Array1.hxx>
#include <NCollection_Buffer.hxx>
#include <Standard_NotImplemented.hxx>

//! Type of attribute in Vertex Buffer
public enum class XGraphic3d_TypeOfAttribute
{
  Graphic3d_TOA_POS   =  0,   //!< vertex position
  Graphic3d_TOA_NORM,         //!< normal
  Graphic3d_TOA_UV,           //!< texture coordinates
  Graphic3d_TOA_COLOR,        //!< per-vertex color
  Graphic3d_TOA_CUSTOM,       //!< custom attributes
};

//! Type of the element in Vertex or Index Buffer
public enum class XGraphic3d_TypeOfData
{
  Graphic3d_TOD_USHORT,  //!< unsigned 16-bit integer
  Graphic3d_TOD_UINT,    //!< unsigned 32-bit integer
  Graphic3d_TOD_VEC2,    //!< 2-components float vector
  Graphic3d_TOD_VEC3,    //!< 3-components float vector
  Graphic3d_TOD_VEC4,    //!< 4-components float vector
  Graphic3d_TOD_VEC4UB,  //!< 4-components unsigned byte vector
  Graphic3d_TOD_FLOAT,   //!< float value
};

//! Vertex attribute definition.
public ref struct XGraphic3d_Attribute
{
  XGraphic3d_TypeOfAttribute Id;       //!< attribute identifier in vertex shader, 0 is reserved for vertex position
  XGraphic3d_TypeOfData      DataType; //!< vec2,vec3,vec4,vec4ub

  Standard_Integer Stride() { return Stride (DataType); }

  //! @return size of attribute of specified data type
  static Standard_Integer Stride (XGraphic3d_TypeOfData theType)
  {
    switch (theType)
    {
      case XGraphic3d_TypeOfData(Graphic3d_TOD_USHORT): return sizeof(unsigned short);
      case XGraphic3d_TypeOfData(Graphic3d_TOD_UINT):   return sizeof(unsigned int);
      case XGraphic3d_TypeOfData(Graphic3d_TOD_VEC2):   return sizeof(Graphic3d_Vec2);
      case XGraphic3d_TypeOfData(Graphic3d_TOD_VEC3):   return sizeof(Graphic3d_Vec3);
      case XGraphic3d_TypeOfData(Graphic3d_TOD_VEC4):   return sizeof(Graphic3d_Vec4);
      case XGraphic3d_TypeOfData(Graphic3d_TOD_VEC4UB): return sizeof(Graphic3d_Vec4ub);
      case XGraphic3d_TypeOfData(Graphic3d_TOD_FLOAT):  return sizeof(float);
    }
    return 0;
  }
};

//typedef NCollection_Array1<Graphic3d_Attribute> Graphic3d_Array1OfAttribute;

namespace TKV3d {
    //! Buffer of vertex attributes.
   public ref class XGraphic3d_Buffer //: public NCollection_Buffer
    {
        //DEFINE_STANDARD_RTTIEXT(Graphic3d_Buffer, NCollection_Buffer)
    public:

        ////! Empty constructor.
        //XGraphic3d_Buffer(Handle(NCollection_BaseAllocator)& theAlloc);

        XGraphic3d_Buffer(Handle(Graphic3d_Buffer) pos);
        !XGraphic3d_Buffer() { IHandle = NULL; };
        ~XGraphic3d_Buffer() { IHandle = NULL; };
        void SetBufferHandle(Handle(Graphic3d_Buffer) pos);

        virtual Handle(Graphic3d_Buffer) GetBuffer();

        //! Return number of initially allocated elements which can fit into this buffer,
        //! while NbElements can be overwritten to smaller value.
        Standard_Integer NbMaxElements();

        //! @return array of attributes definitions
        XGraphic3d_Attribute^ AttributesArray();

        //! @return attribute definition
        XGraphic3d_Attribute^ Attribute(Standard_Integer theAttribIndex);

        //! @return attribute definition
        XGraphic3d_Attribute^ ChangeAttribute(Standard_Integer theAttribIndex);

        //! Find attribute index.
        //! @param theAttrib attribute to find
        //! @return attribute index or -1 if not found
        Standard_Integer FindAttribute(XGraphic3d_TypeOfAttribute theAttrib);

        //! @name data accessors for interleaved array

        //! @return data offset to specified attribute
        Standard_Integer AttributeOffset(Standard_Integer theAttribIndex);

        //! @return data for specified attribute
        Standard_Byte* Data(Standard_Integer theAttribIndex);

        //! @return data for specified attribute
        Standard_Byte* ChangeData(Standard_Integer theAttribIndex);

        //! Access specified element.
        Standard_Byte* value(Standard_Integer theElem);

        //! Access specified element.
        Standard_Byte* changeValue(Standard_Integer theElem);

        //! Access element with specified position and type.
        template <typename Type_t>
       Type_t Value(Standard_Integer theElem);

        //! Access element with specified position and type.
        template <typename Type_t>
        Type_t ChangeValue(Standard_Integer theElem);

        //! @name general accessors

        //! Return the attribute data with stride size specific to this attribute.
        //! @param theAttrib       attribute to find
        //! @param theAttribIndex  index of found attribute
        //! @param theAttribStride stride in bytes between values of this attribute within returned data pointer
        Standard_Byte* ChangeAttributeData(XGraphic3d_TypeOfAttribute theAttrib, Standard_Integer% theAttribIndex, Standard_Size% theAttribStride);

        //! Return the attribute data with stride size specific to this attribute.
        //! @param theAttrib       attribute to find
        //! @param theAttribIndex  index of found attribute
        //! @param theAttribStride stride in bytes between values of this attribute within returned data pointer
        Standard_Byte* AttributeData(XGraphic3d_TypeOfAttribute theAttrib, Standard_Integer% theAttribIndex, Standard_Size% theAttribStride);

        //! Release buffer.
        void release();

        //! Allocates new empty array
        bool Init(Standard_Integer theNbElems, XGraphic3d_Attribute^ theAttribs, Standard_Integer theNbAttribs);

        //! Allocates new empty array
        bool Init(Standard_Integer theNbElems, Graphic3d_Array1OfAttribute& theAttribs);

        //! Flag indicating that attributes in the buffer are interleaved; TRUE by default.
        //! Requires sub-classing for creating a non-interleaved buffer (advanced usage).
        virtual Standard_Boolean IsInterleaved();

        //! Return TRUE if data can be invalidated; FALSE by default.
        //! Requires sub-classing for creating a mutable buffer (advanced usage).
        virtual Standard_Boolean IsMutable();

        //! Return invalidated range; EMPTY by default.
        //! Requires sub-classing for creating a mutable buffer (advanced usage).
        virtual Graphic3d_BufferRange InvalidatedRange();

        //! Reset invalidated range.
        //! Requires sub-classing for creating a mutable buffer (advanced usage).
        virtual void Validate();

        //! Invalidate entire buffer.
        virtual void Invalidate();

        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property Handle(Standard_Transient) IHandle {
            Handle(Standard_Transient) get() {//Standard_OVERRIDE {
                return NativeHandle();
            }
            void set(Handle(Standard_Transient) handle) {//Standard_OVERRIDE {
                NativeHandle() = Handle(Graphic3d_Buffer)::DownCast(handle);
            }
        }
    private:
        NCollection_Haft<Handle(Graphic3d_Buffer)> NativeHandle;
    };

    //DEFINE_STANDARD_HANDLE(Graphic3d_Buffer, NCollection_Buffer)
}
#endif // _XGraphic3d_Buffer_HeaderFile
