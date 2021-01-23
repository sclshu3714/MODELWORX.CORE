// Created on: 1990-12-19
// Created by: Christophe MARION
// Copyright (c) 1990-1999 Matra Datavision
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
#pragma once
#include <TopLoc_Location.hxx>
#include "xgp_Trsf.h"




//! A Location is a composite transition. It comprises a
//! series of elementary reference coordinates, i.e.
//! objects of type TopLoc_Datum3D, and the powers to
//! which these objects are raised.

namespace TKMath {

    ref class xgp_Trsf;
    public ref class XTopLoc_Location
    {
    public:

        //!ructs an empty local coordinate system object.
        //! Note: A Locationructed from a default datum is said to be "empty".
        XTopLoc_Location(void);

        //!ructs an empty local coordinate system object.
        //! Note: A Locationructed from a default datum is said to be "empty".
        XTopLoc_Location(TopLoc_Location* pos);

        //!ructs an empty local coordinate system object.
        //! Note: A Locationructed from a default datum is said to be "empty".
        XTopLoc_Location(TopLoc_Location pos);

        //!ructs the local coordinate system object defined
        //! by the transformation T. T invokes in turn, a TopLoc_Datum3D object.
        XTopLoc_Location(xgp_Trsf^ T);

        //!ructs the local coordinate system object defined by the 3D datum D.
        //! Exceptions
        //! Standard_ConstructionError if the transformation
        //! T does not represent a 3D coordinate system.
        XTopLoc_Location(const Handle(TopLoc_Datum3D) D);

        //! ÊÍ·Å
        ~XTopLoc_Location();
        !XTopLoc_Location() { IHandle = NULL; };
        //!
        virtual TopLoc_Location* GetLocation();

        //! Returns true if this location is equal to the Identity transformation.
        Standard_Boolean IsIdentity();

        //! Resets this location to the Identity transformation.
        void Identity();

        //! Returns    the  first   elementary  datum  of  the
        //! Location.  Use the NextLocation function recursively to access
        //! the other data comprising this location.
        //! Exceptions
        //! Standard_NoSuchObject if this location is empty.
        Handle(TopLoc_Datum3D) FirstDatum();

        //! Returns   the  power  elevation  of    the   first
        //! elementary datum.
        //! Exceptions
        //! Standard_NoSuchObject if this location is empty.
        Standard_Integer FirstPower();

        //! Returns  a Location representing  <me> without the
        //! first datum. We have the relation :
        //!
        //! <me> = NextLocation() * FirstDatum() ^ FirstPower()
        //! Exceptions
        //! Standard_NoSuchObject if this location is empty.
        XTopLoc_Location^ NextLocation();

        //! Returns  the transformation    associated  to  the
        //! coordinate system.
        xgp_Trsf^ Transformation();
        operator xgp_Trsf ^ () {
            return Transformation();
        };

        //! Returns the inverse of <me>.
        //!
        //! <me> * Inverted() is an Identity.
        XTopLoc_Location^ Inverted();

        //! Returns <me> * <Other>, the  elementary datums are
        //! concatenated.
        XTopLoc_Location^ Multiplied(XTopLoc_Location^ Other);
        XTopLoc_Location^ operator* (XTopLoc_Location^ Other)
        {
            return Multiplied(Other);
        }

        //! Returns  <me> / <Other>.
        XTopLoc_Location^ Divided(XTopLoc_Location^ Other);
        XTopLoc_Location^ operator/ (XTopLoc_Location^ Other)
        {
            return Divided(Other);
        }

        //! Returns <Other>.Inverted() * <me>.
        XTopLoc_Location^ Predivided(XTopLoc_Location^ Other);

        //! Returns me at the power <pwr>.   If <pwr>  is zero
        //! returns  Identity.  <pwr> can  be lower  than zero
        //! (usual meaning for powers).
        XTopLoc_Location^ Powered(Standard_Integer pwr);

        //! Returns a hashed value for this local coordinate system. This value is used, with map tables, to store and
        //! retrieve the object easily, and is in the range [1, theUpperBound].
        //! @param theUpperBound the upper bound of the range a computing hash code must be within
        //! @return a computed hash code, in the range [1, theUpperBound]
        Standard_Integer HashCode(Standard_Integer theUpperBound);

        //! Returns true if this location and the location Other
        //! have the same elementary data, i.e. contain the same
        //! series of TopLoc_Datum3D and respective powers.
        //! This method is an alias for operator ==.
        Standard_Boolean IsEqual(XTopLoc_Location^ Other);
        Standard_Boolean operator == (XTopLoc_Location^ Other)
        {
            return IsEqual(Other);
        }

        //! Returns true if this location and the location Other do
        //! not have the same elementary data, i.e. do not
        //! contain the same series of TopLoc_Datum3D and respective powers.
        //! This method is an alias for operator !=.
        Standard_Boolean IsDifferent(XTopLoc_Location^ Other);
        Standard_Boolean operator != (XTopLoc_Location^ Other)
        {
            return IsDifferent(Other);
        }

        //! Dumps the content of me into the stream
        void DumpJson(Standard_OStream theOStream, Standard_Integer theDepth);

        //! Prints the contents of <me> on the stream <s>.
        void ShallowDump(Standard_OStream S);

        /// <summary>
        /// 本地句柄
        /// </summary>
        virtual property TopLoc_Location* IHandle {
            TopLoc_Location* get() {
                return NativeHandle;
            }
            void set(TopLoc_Location* handle) {
                NativeHandle = handle;
            }
        }
    private:
        TopLoc_Location* NativeHandle;
    };
    //! Computes a hash code for the given location, in the range [1, theUpperBound]
    //! @param theLocation the location which hash code is to be computed
    //! @param theUpperBound the upper bound of the range a computing hash code must be within
    //! @return a computed hash code, in the range [1, theUpperBound]
    inline Standard_Integer HashCode(XTopLoc_Location^ theLocation, Standard_Integer theUpperBound)
    {
        return theLocation->GetLocation()->HashCode(theUpperBound);
    }

    inline void ShallowDump(XTopLoc_Location^ me, Standard_OStream S) {
        me->GetLocation()->ShallowDump(S);
    }
};



