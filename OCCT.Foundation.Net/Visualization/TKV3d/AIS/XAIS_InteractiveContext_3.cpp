// Created on: 2001-01-09
// Created by: Sergey Altukhov
// Copyright (c) 2001-2014 OPEN CASCADE SAS
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

// Modified: 22/03/04 ; SAN : OCC4895 High-level interface for controlling polygon offsets
#include <XAIS_InteractiveContext.h>
#include <AIS_GlobalStatus.hxx>
#include <AIS_InteractiveContext.hxx>
#include <AIS_InteractiveObject.hxx>
#include <Prs3d_BasicAspect.hxx>
#include <Prs3d_LineAspect.hxx>
#include <Quantity_Color.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <SelectMgr_Filter.hxx>
#include <SelectMgr_OrFilter.hxx>
#include <SelectMgr_SelectionManager.hxx>
#include <Standard_Transient.hxx>
#include <TCollection_AsciiString.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TopLoc_Location.hxx>
#include <TopoDS_Shape.hxx>
#include <V3d_View.hxx>
#include <V3d_Viewer.hxx>

// OCC4895 SAN 22/03/04 High-level interface for controlling polygon offsets
// OCC4895 SAN 22/03/04 High-level interface for controlling polygon offsets
// OCC4895 SAN 22/03/04 High-level interface for controlling polygon offsets
//=======================================================================
//function : SetPolygonOffsets 
//purpose  : 
//======================================================================= 

namespace TKV3d
{
    void XAIS_InteractiveContext::SetPolygonOffsets(Handle(AIS_InteractiveObject) anObj, Standard_Integer aMode, Standard_ShortReal aFactor, Standard_ShortReal aUnits, Standard_Boolean updateviewer)
    {
        NativeHandle()->SetPolygonOffsets(anObj, aMode, aFactor, aUnits, updateviewer);
    };


    //=======================================================================
    //function : HasPolygonOffsets 
    //purpose  : 
    //=======================================================================
    Standard_Boolean XAIS_InteractiveContext::HasPolygonOffsets(Handle(AIS_InteractiveObject) anObj)
    {
        return NativeHandle()->HasPolygonOffsets(anObj);
    };

    //=======================================================================
    //function : PolygonOffsets 
    //purpose  : 
    //=======================================================================
    void XAIS_InteractiveContext::PolygonOffsets(Handle(AIS_InteractiveObject) anObj, Standard_Integer aMode, Standard_ShortReal aFactor, Standard_ShortReal aUnits)
    {
        NativeHandle()->PolygonOffsets(anObj, aMode, aFactor, aUnits);
    };
}