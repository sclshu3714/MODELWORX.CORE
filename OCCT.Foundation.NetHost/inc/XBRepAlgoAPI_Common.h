// Created on: 1993-10-14
// Created by: Remi LEQUETTE
// Copyright (c) 1993-1999 Matra Datavision
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

#ifndef _XBRepAlgoAPI_Common_HeaderFile
#define _XBRepAlgoAPI_Common_HeaderFile
#pragma once
#include <BRepAlgoAPI_Common.hxx>
#include <XTopoDS_Shape.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <BRepAlgoAPI_BooleanOperation.hxx>
class BOPAlgo_PaveFiller;
class TopoDS_Shape;



//! The class provides Boolean common operation
//! between arguments and tools (Boolean Intersection).
using namespace TKBRep;
namespace TKBO {
	ref class TKBRep::XTopoDS_Shape;
	public ref class XBRepAlgoAPI_Common  //: public BRepAlgoAPI_BooleanOperation
	{
	public:

		//! DEFINE_STANDARD_ALLOC


		//! Empty constructor
		XBRepAlgoAPI_Common();
		virtual ~XBRepAlgoAPI_Common();

		//! Empty constructor
		//! <PF> - PaveFiller object that is carried out
		XBRepAlgoAPI_Common(const BOPAlgo_PaveFiller& PF);

		//! Constructor with two shapes
		//! <S1>  -argument
		//! <S2>  -tool
		//! <anOperation> - the type of the operation
		//! Obsolete
		XBRepAlgoAPI_Common(XTopoDS_Shape^ S1, XTopoDS_Shape^ S2);

		//! Constructor with two shapes
		//! <S1>  -argument
		//! <S2>  -tool
		//! <anOperation> - the type of the operation
		//! <PF> - PaveFiller object that is carried out
		//! Obsolete
		XBRepAlgoAPI_Common(XTopoDS_Shape^ S1, XTopoDS_Shape^ S2, const BOPAlgo_PaveFiller& PF);

		//! 获取图形
		virtual XTopoDS_Shape^ Shape();// Standard_OVERRIDE;

		/// <summary>
		/// 本地句柄
		/// </summary>
		virtual property BRepAlgoAPI_Common* IHandle {
			BRepAlgoAPI_Common* get() {// Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepAlgoAPI_Common* handle) {// Standard_OVERRIDE {
				NativeHandle = static_cast<BRepAlgoAPI_Common*>(handle);
			}
		}

	private:
		BRepAlgoAPI_Common* NativeHandle;
	};
}
#endif // _XBRepAlgoAPI_Common_HeaderFile
