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

#ifndef _XTDF_Attribute_HeaderFile
#define _XTDF_Attribute_HeaderFile
#pragma once
#include "TDF_Attribute.hxx"
#include "NCollection_Haft.h"
#include "XStandard_GUID.h"
#include "XTDF_Label.h"

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <TDF_LabelNodePtr.hxx>
#include <Standard_Integer.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_OStream.hxx>
#include <TDF_AttributeIndexedMap.hxx>
#include <TDF_DeltaOnModification.hxx>
class Standard_DomainError;
class TDF_Data;
class TDF_Label;
class TDF_LabelNode;
class TDF_AttributeIterator;
class TDF_DeltaOnForget;
class Standard_GUID;
class TDF_AttributeDelta;
class TDF_DeltaOnAddition;
class TDF_DeltaOnResume;
class TDF_DeltaOnModification;
class TDF_DeltaOnRemoval;
class TDF_RelocationTable;
class TDF_DataSet;
class TDF_IDFilter;


//class TDF_Attribute;
//DEFINE_STANDARD_HANDLE(TDF_Attribute, Standard_Transient)

//! A class each application has to implement. It is
//! used to contain the application data.
//! This abstract class, alongwith Label,
//! is one of the cornerstones of Model Editor.
//! The groundwork is to define the root of
//! information. This information is to be
//! attached to a Label, and could be of any of
//! the following types:
//! -   a feature
//! -   a constraint
//! -   a comment
//!
//! Contents:
//! ---------
//!
//! Each software component who'd like to attach its
//! own information to a label has to inherit from
//! this class and has to add its own information as
//! fields of this new class.
//!
//! Identification:
//! ---------------
//!
//! An attribute can be identified by its ID. Every
//! attributes used with the same meaning (for
//! exemple: Integer, String, Topology...) have the
//! same worldwide unique ID.
//!
//! Addition:
//! ---------
//!
//! An attribute can be added to a label only if there
//! is no attribute yet with the same ID. Call-back
//! methods are offered, called automatically before
//! and after the addition action.
//!
//! Removal:
//! --------
//!
//! An attribute can be removed from a label only if
//! there is an attribute yet with the same
//! ID. Call-back methods are offered, called
//! automatically before and after the removal
//! action. A removed attribute cannot be found
//! again. After a removal, only an addition of an
//! attribute with the sane ID is possible (no
//! backup...).
//!
//! Modification & Transaction:
//! ---------------------------
//!
//! An attribute can be backuped before a
//! modification. Only one backup attribute by
//! transaction is possible. The modification can be
//! forgotten (abort transaction) or validated (commit
//! transaction).
//!
//! BackupCopy and restore are methods used by the backup or
//! abort transaction actions. BackupCopy is called by
//! Backup to generate an attribute with the same
//! contents as the current one. Restore is called
//! when aborting a transaction to transfer the
//! backuped contents into the current
//! attribute. These methods must be implemented by
//! end use inheriting classes.
//!
//! A standard implementation of BackupCopy is provided, but
//! it is not necessary a good one for any use.
//!
//! Copy use methods:
//! -----------------
//!
//! Paste and NewEmpty methods are used by the copy
//! algorithms. The goal of "Paste" is to transfer an
//! attribute new contents into another attribute. The
//! goal of "NewEmpty" is to create an attribute
//! whithout contents, to be further filled with the
//! new contents of another one. These 2 methods must
//! be implemented by end use inheriting classes.
//!
//! AttributeDelta:
//! ---------------
//!
//! An AttributeDelta is the difference between to
//! attribute values states.  These methods must be
//! implemented by end use inheriting classes, to
//! profit from the delta services.
using namespace TKernel;
namespace TKLCAF {

    ref class TKernel::XStandard_GUID;
    ref class XTDF_Label;
    public ref class XTDF_Attribute
    {

    public:
        XTDF_Attribute();

        //!
        XTDF_Attribute(Handle(TDF_Attribute) pos);

        //! Returns the ID of the attribute.
        virtual XStandard_GUID^  ID();

        //! Sets specific ID of the attribute (supports several attributes 
        //! of one type at the same label feature).
        virtual void SetID(const Standard_GUID& theGuid);

        //! Sets specific ID of the attribute (supports several attributes 
        //! of one type at the same label feature).
        virtual void SetID(XStandard_GUID^ theGuid);

            //! Sets default ID defined in nested class (to be used for attributes having User ID feature).
        virtual void SetID();

        //!
        void SetNativeHandle(Handle(TDF_Attribute) pos);

        //! Returns   the   label to which  the   attribute is
        //! attached. If the  label is not  included in a  DF,
        //! the label is null. See Label.
        //! Warning
        //! If the label is not included in a data
        //! framework, it is null.
        //! This function should not be redefined inline.
        XTDF_Label^ Label();

        //£¡
        Handle(TDF_Attribute) GetAttribute();

        //! Returns the transaction index in which the
        //! attribute has been created or modified.
        Standard_Integer Transaction();

        //! Returns the upper transaction index until which
        //! the attribute is/was valid. This number may
        //! vary. A removed attribute validity range is
        //! reduced to its transaction index.
        Standard_Integer UntilTransaction();

        //! Returns true if the attribute is valid; i.e. not a
        //! backuped or removed one.
        Standard_Boolean IsValid();

        //! Returns true if the attribute has no backup
        Standard_Boolean IsNew();

        //! Returns true if the attribute forgotten status is
        //! set.
        //!
        //! ShortCut Methods concerning associated attributes
        //! =================================================
        Standard_Boolean IsForgotten();

        //! Returns true if it  exists an associated attribute
        //! of <me> with <anID> as ID.
        Standard_Boolean IsAttribute(const Standard_GUID& anID);

        //! Returns true if it  exists an associated attribute
        //! of <me> with <anID> as ID.
        Standard_Boolean IsAttribute(XStandard_GUID^ anID);

        //! Finds an associated  attribute of  <me>, according
        //! to <anID>.  the returned <anAttribute> is a  valid
        //! one. The  method  returns  True if   found,  False
        //! otherwise.   A removed attribute  cannot be found using
        //! this  method.
        Standard_Boolean FindAttribute(const Standard_GUID& anID, Handle(TDF_Attribute)& anAttribute);

        //! Finds an associated  attribute of  <me>, according
        //! to <anID>.  the returned <anAttribute> is a  valid
        //! one. The  method  returns  True if   found,  False
        //! otherwise.   A removed attribute  cannot be found using
        //! this  method.
        Standard_Boolean FindAttribute(XStandard_GUID^ anID, XTDF_Attribute^ anAttribute);

        //! Safe variant for arbitrary type of argument
        template <class T>
        Standard_Boolean FindAttribute(const Standard_GUID& theID, Handle(T)& theAttr)
        {
            Handle(TDF_Attribute) anAttr = theAttr;
            return FindAttribute(theID, anAttr) && !(theAttr = Handle(T)::DownCast(anAttr)).IsNull();
        }

        //! Adds   an   Attribute <other>  to  the   label  of
        //! <me>.Raises if there is  already  one of the same
        //! GUID fhan <other>.
        void AddAttribute(const Handle(TDF_Attribute)& other);

        //! Adds   an   Attribute <other>  to  the   label  of
        //! <me>.Raises if there is  already  one of the same
        //! GUID fhan <other>.
        void AddAttribute(XTDF_Attribute^ other);

        //! Forgets  the Attribute of  GUID <aguid> associated
        //! to the label of <me>. Be  carefull that if <me> is
        //! the attribute of <guid>, <me> will have a null label
        //! after this call.  If  the attribute doesn't  exist
        //! returns False. Otherwise returns True.
        Standard_Boolean ForgetAttribute(const Standard_GUID& aguid);
        Standard_Boolean ForgetAttribute(XStandard_GUID^ aguid);

        //! Forgets all the  attributes attached to  the label
        //! of <me>.    Does   it   on  the  sub-labels   if
        //! <clearChildren> is set  to true.  Of  course, this
        //! method  is  compatible with Transaction  &  Delta
        //! mecanisms. Be carefull  that  if <me> will have a
        //! null label after this call
        //! default Standard_True
        void ForgetAllAttributes(const Standard_Boolean clearChildren);

        //! Something to do after adding an Attribute to a label.
        virtual void AfterAddition();

        //! Something to do before removing an Attribute from
        //! a label.
        virtual void BeforeRemoval();

        //! Something to do before forgetting an Attribute to a
        //! label.
        virtual void BeforeForget();

        //! Something to do after resuming an Attribute from
        //! a label.
        virtual void AfterResume();

        //! Something to do AFTER creation of an attribute by
        //! persistent-transient translation. The returned
        //! status says if AfterUndo has been performed (true)
        //! or if this callback must be called once again
        //! further (false). If <forceIt> is set to true, the
        //! method MUST perform and return true. Does nothing
        //! by default and returns true.
        //! default Standard_False
        virtual Standard_Boolean AfterRetrieval(const Standard_Boolean forceIt);

        //! Something to do before applying <anAttDelta>. The
        //! returned status says if AfterUndo has been
        //! performed (true) or if this callback must be
        //! called once again further (false). If <forceIt> is
        //! set to true, the method MUST perform and return
        //! true. Does nothing by default and returns true.
        //! default Standard_False
        virtual Standard_Boolean BeforeUndo(const Handle(TDF_AttributeDelta)& anAttDelta, Standard_Boolean forceIt);


        //! Something to do after applying <anAttDelta>. The
        //! returned status says if AfterUndo has been
        //! performed (true) or if this callback must be
        //! called once again further (false). If <forceIt> is
        //! set to true, the method MUST perform and return
        //! true. Does nothing by default and returns true.
        //! default Standard_False
        virtual Standard_Boolean AfterUndo(const Handle(TDF_AttributeDelta)& anAttDelta, Standard_Boolean forceIt);

        //! A callback.
        //! By default does nothing.
        //! It is called by TDF_Data::CommitTransaction() method.
        virtual void BeforeCommitTransaction();

        //! Backups the attribute. The backuped attribute is
        //! flagged "Backuped" and not "Valid".
        //!
        //! The method does nothing:
        //!
        //! 1) If the attribute transaction number is equal to
        //! the current transaction number (the attribute has
        //! already been backuped).
        //!
        //! 2) If the attribute is not attached to a label.
        void Backup();

        //! Returns true if the attribute backup status is
        //! set. This status is set/unset by the
        //! Backup() method.
        Standard_Boolean IsBackuped();

        //! Copies  the attribute  contents into  a  new other
        //! attribute. It is used by Backup().
        virtual XTDF_Attribute^ BackupCopy();

        //! Restores the backuped contents from <anAttribute>
        //! into this one. It is used when aborting a
        //! transaction.
        virtual void Restore(XTDF_Attribute^ anAttribute);

        //! Makes an AttributeDelta because <me>
        //! appeared. The only known use of a redefinition of
        //! this method is to return a null handle (no delta).
        virtual Handle(TDF_DeltaOnAddition) DeltaOnAddition();

        //! Makes an AttributeDelta because <me> has been
        //! forgotten.
        virtual Handle(TDF_DeltaOnForget) DeltaOnForget();

        //! Makes an AttributeDelta because <me> has been
        //! resumed.
        virtual Handle(TDF_DeltaOnResume) DeltaOnResume();

        //! Makes a DeltaOnModification between <me> and
        //! <anOldAttribute.
        virtual Handle(TDF_DeltaOnModification) DeltaOnModification(const Handle(TDF_Attribute)& anOldAttribute);

        //! Makes a DeltaOnModification between <me> and
        //! <anOldAttribute.
        virtual Handle(TDF_DeltaOnModification) DeltaOnModification(XTDF_Attribute^ anOldAttribute);

        //! Applies a DeltaOnModification to <me>.
        virtual void DeltaOnModification(const Handle(TDF_DeltaOnModification)& aDelta);

        //! Makes a DeltaOnRemoval on <me> because <me> has
        //! disappeared from the DS.
        virtual Handle(TDF_DeltaOnRemoval) DeltaOnRemoval();

        //! Returns an new empty attribute from the good end
        //! type. It is used by the copy algorithm.
        virtual XTDF_Attribute^ NewEmpty();

        //! This method is different from the "Copy" one,
        //! because it is used when copying an attribute from
        //! a source structure into a target structure. This
        //! method may paste the contents of <me> into
        //! <intoAttribute>.
        //!
        //! The given pasted attribute can be full or empty of
        //! its contents. But don't make a NEW! Just set the
        //! contents!
        //!
        //! It is possible to use <aRelocationTable> to
        //! get/set the relocation value of a source
        //! attribute.
        virtual void Paste(XTDF_Attribute^ intoAttribute, Handle(TDF_RelocationTable)& aRelocationTable);

        //! Adds the first level referenced attributes and labels
        //! to <aDataSet>.
        //!
        //! For this, use the AddLabel or AddAttribute of
        //! DataSet.
        //!
        //! If there is none, do not implement the method.
        virtual void References(const Handle(TDF_DataSet)& aDataSet);

        //! Dumps the minimum information about <me> on
        //! <aStream>.
        virtual Standard_OStream& Dump(Standard_OStream& anOS);
        Standard_OStream& operator<< (Standard_OStream& anOS)
        {
            return Dump(anOS);
        }

        //! Dumps the attribute content on <aStream>, using
        //! <aMap> like this: if an attribute is not in the
        //! map, first put add it to the map and then dump it.
        //! Use the map rank instead of dumping each attribute
        //! field.
        virtual void ExtendedDump(Standard_OStream& anOS, TDF_IDFilter& aFilter, TDF_AttributeIndexedMap& aMap);

        //! Forgets the attribute. <aTransaction> is the
        //! current transaction in which the forget is done. A
        //! forgotten attribute is also flagged not "Valid".
        //!
        //! A forgotten attribute is invisible. Set also the
        //! "Valid" status to False. Obvioulsy, DF cannot
        //! empty an attribute (this has a semantic
        //! signification), but can remove it from the
        //! structure. So, a forgotten attribute is NOT an empty
        //! one, but a soon DEAD one.
        //!
        //! Should be private.
        void Forget(const Standard_Integer aTransaction);


        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property Handle(Standard_Transient) IHandle {
            Handle(Standard_Transient) get() {
                return NativeHandle();
            }
            void set(Handle(Standard_Transient) handle) {
                NativeHandle() = Handle(TDF_Attribute)::DownCast(handle);
            }
        }
    private:
        NCollection_Haft<Handle(TDF_Attribute)> NativeHandle;
    };
}
#endif // _XTDF_Attribute_HeaderFile
