// Created on: 1991-01-23
// Created by: Christophe MARION
// Copyright (c) 1991-1999 Matra Datavision
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
#include <TopLoc_Datum3D.hxx>
#include "xgp_Trsf.h"
#include "XStandard_ConstructionError.h"


namespace TKMath {
    ref class XStandard_ConstructionError;
    ref class xgp_Trsf;
    //! Describes a coordinate transformation, i.e. a change
    //! to an elementary 3D coordinate system, or position in 3D space.
    //! A Datum3D is always described relative to the default datum.
    //! The default datum is described relative to itself: its
    //! origin is (0,0,0), and its axes are (1,0,0) (0,1,0) (0,0,1).
    public ref class XTopLoc_Datum3D
    {

    public:

        !XTopLoc_Datum3D() { IHandle = NULL; };
        ~XTopLoc_Datum3D() { IHandle = NULL; };
        //! Constructs a default Datum3D.
        XTopLoc_Datum3D();

        //! Constructs a default Datum3D.
        XTopLoc_Datum3D(TopLoc_Datum3D* pos);

        //! Constructs a Datum3D form a Trsf from gp. An error is
        //! raised if the Trsf is not a rigid transformation.
        XTopLoc_Datum3D(xgp_Trsf^ T);

        //!
        TopLoc_Datum3D GetDatum3D();

        //! Returns a gp_Trsf which, when applied to this datum,
        //! produces the default datum.
        xgp_Trsf^ Transformation();


        //! Dumps the content of me into the stream
        void DumpJson(Standard_OStream& theOStream, Standard_Integer theDepth);

        //! Writes the contents of this Datum3D to the stream S.
        void ShallowDump(Standard_OStream& S);


        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property TopLoc_Datum3D* IHandle {
            TopLoc_Datum3D* get() {
                return NativeHandle;
            }
            void set(TopLoc_Datum3D* handle) {
                NativeHandle = handle;
            }
        };

    private:
        TopLoc_Datum3D* NativeHandle;

    };
    inline void ShallowDump(const Handle(TopLoc_Datum3D)& me, Standard_OStream& S) {
        me->ShallowDump(S);
    };
}
