// Created on: 1997-02-04
// Created by: DAUTRY Philippe
// Copyright (c) 1997-1999 Matra Datavision
// Copyright (c) 1999-2014 OPEN CASCADE SAS
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

#ifndef _XTDF_Label_HeaderFile
#define _XTDF_Label_HeaderFile
#pragma once
#include <TDF_Label.hxx>
#include "XStandard_GUID.h"
#include "XTDF_Attribute.h"
//#include "XAIS_InteractiveObject.h"

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <TDF_LabelNodePtr.hxx>
#include <Standard_Integer.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_OStream.hxx>
#include <TDF_AttributeIndexedMap.hxx>
class Standard_DomainError;
class Standard_OutOfRange;
class Standard_NullObject;
class TDF_ChildIterator;
class TDF_Attribute;
class TDF_AttributeIterator;
class TDF_Data;
class TDF_LabelMapHasher;
class Standard_GUID;
class TDF_IDFilter;

//! This class provides basic operations  to define
//! a label in a data structure.
//! A label is a feature in the feature hierarchy. A
//! label is always connected to a Data from TDF.
//! To a label is attached attributes containing the
//! software components information.
//!
//! Label information:
//!
//! It is possible to know the tag, the father, the
//! depth in the tree of the label, if the label is
//! root, null or equal to another label.
//!
//! Comfort methods:
//! Some methods useful on a label.
//!
//! Attributes:
//!
//! It is possible to get an attribute in accordance
//! to an ID, or the yougest previous version of a
//! current attribute.
//! 
using namespace TKernel;
//using namespace TKV3d;
namespace TKLCAF {

    ref class XTDF_Attribute;
    ref class TKernel::XStandard_GUID;
    //ref class TKV3d::XAIS_InteractiveObject;
    //ref class XTDataStd_Name;
    public ref class XTDF_Label
    {
    public:

        //! DEFINE_STANDARD_ALLOC
        !XTDF_Label() { IHandle = NULL; };
        ~XTDF_Label() { IHandle = NULL; };
        //! Constructs an empty label object.
        XTDF_Label();

        //! Constructs an empty label object.
        XTDF_Label(TDF_Label* pos);

        //! Constructs an empty label object.
        XTDF_Label(TDF_Label pos);

        void SetNativeHandle(TDF_Label* pos) { 
            NativeHandle = new TDF_Label(*pos);
        }

        //!  Returns the TDF_Label
        TDF_Label* GetLabel();

        //! Nullifies the label.
        void Nullify();

        //! Returns the Data owning <me>.
        Handle(TDF_Data) Data();

        //! Returns the tag of the label.
        //! This is the integer assigned randomly to a label
        //! in a data framework. This integer is used to
        //! identify this label in an entry.
        Standard_Integer Tag();

        //! Returns the label father. This label may be null
        //! if the label is root.
        XTDF_Label^ Father();

        //! Returns True if the <aLabel> is null, i.e. it has
        //! not been included in the data framework.
        Standard_Boolean IsNull();

        //! Sets or unsets <me> and all its descendants as
        //! imported label, according to <aStatus>.
        void Imported(const Standard_Boolean aStatus);

        //! Returns True if the <aLabel> is imported.
        Standard_Boolean IsImported();

        //! Returns True if the <aLabel> is equal to me (same
        //! LabelNode*).
        Standard_Boolean IsEqual(XTDF_Label^ aLabel);
        Standard_Boolean operator == (XTDF_Label^ aLabel)
        {
            return IsEqual(aLabel);
        }

        Standard_Boolean IsDifferent(XTDF_Label^ aLabel);
        Standard_Boolean operator != (XTDF_Label^ aLabel)
        {
            return IsDifferent(aLabel);
        }

        Standard_Boolean IsRoot();

        //! Returns true if <me> owns an attribute with <anID> as ID.
        Standard_Boolean IsAttribute(const Standard_GUID& anID);

        //! Adds an Attribute  to the current label. Raises if
        //! there is already one.
        void AddAttribute(const Handle(TDF_Attribute)& anAttribute, Standard_Boolean append);

        //! Forgets an  Attribute   from the  current  label,
        //! setting its   forgotten status true and  its valid
        //! status false. Raises if   the attribute is not in
        //! the structure.
        void ForgetAttribute(const Handle(TDF_Attribute)& anAttribute);

        //! Forgets the  Attribute of  GUID <aguid> from   the
        //! current label   . If the   attribute doesn't exist
        //! returns False. Otherwise returns True.
        Standard_Boolean ForgetAttribute(const Standard_GUID& aguid);

        //! Forgets all the attributes. Does it on also on the
        //! sub-labels if <clearChildren> is set to true. Of
        //! course, this method is compatible with Transaction
        //! & Delta mecanisms.
        void ForgetAllAttributes(const Standard_Boolean clearChildren);

        //! Undo Forget action, setting its forgotten status
        //! false and its valid status true. Raises if the
        //! attribute is not in the structure.
        void ResumeAttribute(const Handle(TDF_Attribute)& anAttribute);

        //! Finds an attribute of the current label, according
        //! to <anID>.
        //! If anAttribute is not a valid one, false is returned.
        //!
        //! The method returns True if found, False otherwise.
        //!
        //! A removed attribute cannot be found.
        Standard_Boolean FindAttribute(Standard_GUID anID, Handle(TDF_Attribute) anAttribute);

        //! Finds an attribute of the current label, according
        //! to <anID>.
        //! If anAttribute is not a valid one, false is returned.
        //!
        //! The method returns True if found, False otherwise.
        //!
        //! A removed attribute cannot be found.
        Standard_Boolean FindAttribute(XStandard_GUID^ anID, XTDF_Attribute^% anAttribute);

        //! Safe variant of FindAttribute() for arbitrary type of argument
        template <class T>
        Standard_Boolean FindAttribute(Standard_GUID theID, Handle(T) theAttr)
        {
            Handle(TDF_Attribute) anAttr;
            return FindAttribute(theID, anAttr) && !(theAttr = Handle(T)::DownCast(anAttr)).IsNull();
        }

        //! Finds an attribute of the current label, according
        //! to <anID> and <aTransaction>. This attribute
        //! has/had to be a valid one for the given
        //! transaction index . So, this attribute is not
        //! necessary a valid one.
        //!
        //! The method returns True if found, False otherwise.
        //!
        //! A removed attribute cannot be found nor a backuped
        //! attribute of a removed one.
        Standard_Boolean FindAttribute(const Standard_GUID& anID, Standard_Integer aTransaction, Handle(TDF_Attribute)& anAttribute);

        //! attribute of a removed one.
        Standard_Boolean FindAttribute(XStandard_GUID^ anID, Standard_Integer aTransaction, XTDF_Attribute^ anAttribute);

        ////! Finds an attribute of the current label,
        //Standard_Boolean FindAttribute(XStandard_GUID^ anID, XTDataStd_Name^ anAttribute) {
        //    /*Handle(TDF_Attribute) anAttr;*/
        //    /*Standard_Boolean result = FindAttribute(anID->GetGUID(), anAttr);
        //    Handle(TDataStd_Name) theAttr = Handle(TDataStd_Name)::DownCast(anAttr);
        //    anAttribute = gcnew XTDataStd_Name(theAttr);
        //    result &= anAttribute->GetName().IsNull();*/
        //    Handle(TDF_Attribute) anAttr;
        //    return FindAttribute(anID->GetGUID(), anAttr) && !(anAttribute = gcnew XTDataStd_Name(Handle(TDataStd_Name)::DownCast(anAttr)))->GetName().IsNull();
        //};

        //! Returns true if <me> or a DESCENDANT of <me> owns
        //! attributes not yet available in transaction 0. It
        //! means at least one of their attributes is new,
        //! modified or deleted.
        Standard_Boolean MayBeModified();

        //! Returns true if <me> owns attributes not yet
        //! available in transaction 0. It means at least one
        //! attribute is new, modified or deleted.
        Standard_Boolean AttributesModified();

        //! Returns true if this label has at least one attribute.
        Standard_Boolean HasAttribute();

        //! Returns the number of attributes.
        Standard_Integer NbAttributes();

        //! Returns the depth of the label in the data framework.
        //! This corresponds to the number of fathers which
        //! this label has, and is used in determining
        //! whether a label is root, null or equivalent to another label.
        //! Exceptions:
        //! Standard_NullObject if this label is null. This is
        //! because a null object can have no depth.
        Standard_Integer Depth();

        //! Returns True if <me> is a descendant of
        //! <aLabel>. Attention: every label is its own
        //! descendant.
        Standard_Boolean IsDescendant(XTDF_Label^ aLabel);

        //! Returns the root label Root of the data structure.
        //! This has a depth of 0.
        //! Exceptions:
        //! Standard_NullObject if this label is null. This is
        //! because a null object can have no depth.
        XTDF_Label^ Root();

        //! Returns true if this label has at least one child.
        Standard_Boolean HasChild();

        //! Returns the number of children.
        Standard_Integer NbChildren();

        //! Finds a child label having <aTag> as tag. Creates
        //! The tag aTag identifies the label which will be the parent.
        //! If create is true and no child label is found, a new one is created.
        //! Example:
        //! //creating a label with tag 10 at Root
        //! TDF_Label lab1 = aDF->Root().FindChild(10);
        //! //creating labels 7 and 2 on label 10
        //! TDF_Label lab2 = lab1.FindChild(7);
        //! TDF_Label lab3 = lab1.FindChild(2);
        XTDF_Label^ FindChild(const Standard_Integer aTag, Standard_Boolean create);

        //! Create  a new child   label of me  using autoamtic
        //! delivery tags provided by TagSource.
        XTDF_Label^ NewChild();

        //! Returns the current transaction index.
        Standard_Integer Transaction();

        //! Returns true if node address of <me> is lower than
        //! <otherLabel> one. Used to quickly sort labels (not
        //! on entry criterion).
        //!
        //! -C++: inline
        Standard_Boolean HasLowerNode(XTDF_Label^ otherLabel);

        //! Returns true if node address of <me> is greater
        //! than <otherLabel> one. Used to quickly sort labels
        //! (not on entry criterion).
        //!
        //! -C++: inline
        Standard_Boolean HasGreaterNode(XTDF_Label^ otherLabel);

        //! Dumps the minimum information about <me> on
        //! <aStream>.
        Standard_OStream& Dump(Standard_OStream& anOS);
        Standard_OStream& operator<< (Standard_OStream& anOS)
        {
            return Dump(anOS);
        }

        //! Dumps the label on <aStream> and its attributes
        //! rank in <aMap> if their IDs are kept by <IDFilter>.
        void ExtendedDump(Standard_OStream& anOS, TDF_IDFilter& aFilter, TDF_AttributeIndexedMap& aMap);

        //! Dumps the label entry.
        void EntryDump(Standard_OStream& anOS);

        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property TDF_Label* IHandle {
            TDF_Label* get() {
                return NativeHandle;
            }
            void set(TDF_Label* handle) {
                NativeHandle = handle;
            }
        }
    private:
        TDF_Label* NativeHandle;
    };
}
#endif // _XTDF_Label_HeaderFile
