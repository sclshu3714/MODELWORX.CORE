// Created on: 1994-02-18
// Created by: Remi LEQUETTE
// Copyright (c) 1994-1999 Matra Datavision
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

#ifndef _XBRepAlgoAPI_Section_HeaderFile
#define _XBRepAlgoAPI_Section_HeaderFile
#pragma once
#include <BRepAlgoAPI_Section.hxx>
#include <XTopoDS_Shape.h>
#include <XGeom_Surface.h>
#include <xgp_Pln.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <Standard_Boolean.hxx>
#include <BRepAlgoAPI_BooleanOperation.hxx>
class BOPAlgo_PaveFiller;
class TopoDS_Shape;
class gp_Pln;
class Geom_Surface;



//! The algorithm is to build a Secton operation between arguments and tools.
//! The result of Section operation consists of vertices and edges.
//! The result of Section operation contains:
//! 1. new vertices that are subjects of V/V, E/E, E/F, F/F interferences
//! 2. vertices that are subjects of V/E, V/F interferences
//! 3. new edges that are subjects of F/F interferences
//! 4. edges that are Common Blocks
using namespace TKBRep;
using namespace TKMath;
using namespace TKG3d;
namespace TKBO {
	ref class TKMath::xgp_Pln;
	ref class TKBRep::XTopoDS_Shape;
	ref class TKG3d::XGeom_Surface;
	public ref class XBRepAlgoAPI_Section  //: public BRepAlgoAPI_BooleanOperation
	{
	public:

		//! DEFINE_STANDARD_ALLOC


		//! Empty constructor
		XBRepAlgoAPI_Section();
		virtual ~XBRepAlgoAPI_Section();

		//! Empty constructor
		//! <PF> - PaveFiller object that is carried out
		XBRepAlgoAPI_Section(const BOPAlgo_PaveFiller& PF);

		//! Constructor with two shapes
		//! <S1>  -argument
		//! <S2>  -tool
		//! <PerformNow> - the flag:
		//! if <PerformNow>=True - the algorithm is performed immediatly
		//! Obsolete
		//! const Standard_Boolean PerformNow = Standard_True
		XBRepAlgoAPI_Section(XTopoDS_Shape^ S1, XTopoDS_Shape^ S2, Standard_Boolean PerformNow);

		//! Constructor with two shapes
		//! <S1>  -argument
		//! <S2>  -tool
		//! <PF> - PaveFiller object that is carried out
		//! <PerformNow> - the flag:
		//! if <PerformNow>=True - the algorithm is performed immediatly
		//! Obsolete
		//! const Standard_Boolean PerformNow = Standard_True
		XBRepAlgoAPI_Section(XTopoDS_Shape^ S1, XTopoDS_Shape^ S2, const BOPAlgo_PaveFiller& aDSF, Standard_Boolean PerformNow);

		//! Constructor with two shapes
		//! <S1>  - argument
		//! <Pl>  - tool
		//! <PerformNow> - the flag:
		//! if <PerformNow>=True - the algorithm is performed immediatly
		//! Obsolete
		//! const Standard_Boolean PerformNow = Standard_True
		XBRepAlgoAPI_Section(XTopoDS_Shape^ S1, xgp_Pln^ Pl, Standard_Boolean PerformNow);

		//! Constructor with two shapes
		//! <S1>  - argument
		//! <Sf>  - tool
		//! <PerformNow> - the flag:
		//! if <PerformNow>=True - the algorithm is performed immediatly
		//! Obsolete
		//! const Standard_Boolean PerformNow = Standard_True
		XBRepAlgoAPI_Section(XTopoDS_Shape^ S1, XGeom_Surface^ Sf, Standard_Boolean PerformNow);

		//! Constructor with two shapes
		//! <Sf>  - argument
		//! <S2>  - tool
		//! <PerformNow> - the flag:
		//! if <PerformNow>=True - the algorithm is performed immediatly
		//! Obsolete
		//! const Standard_Boolean PerformNow = Standard_True
		XBRepAlgoAPI_Section(XGeom_Surface^ Sf, XTopoDS_Shape^ S2, Standard_Boolean PerformNow);

		//! Constructor with two shapes
		//! <Sf1>  - argument
		//! <Sf2>  - tool
		//! <PerformNow> - the flag:
		//! if <PerformNow>=True - the algorithm is performed immediatly
		//! Obsolete
		//! const Standard_Boolean PerformNow = Standard_True
		XBRepAlgoAPI_Section(XGeom_Surface^ Sf1, XGeom_Surface^ Sf2, Standard_Boolean PerformNow);

		//! initialize the argument
		//! <S1>  - argument
		//! Obsolete
		void Init1(XTopoDS_Shape^ S1);

		//! initialize the argument
		//! <Pl>  - argument
		//! Obsolete
		void Init1(xgp_Pln^ Pl);

		//! initialize the argument
		//! <Sf>  - argument
		//! Obsolete
		void Init1(XGeom_Surface^ Sf);

		//! initialize the tool
		//! <S2>  - tool
		//! Obsolete
		void Init2(XTopoDS_Shape^ S2);

		//! initialize the tool
		//! <Pl>  - tool
		//! Obsolete
		void Init2(xgp_Pln^ Pl);

		//! initialize the tool
		//! <Sf>  - tool
		//! Obsolete
		void Init2(XGeom_Surface^ Sf);

		void Approximation(Standard_Boolean B);


		//! Indicates whether the P-Curve should be (or not)
		//! performed on the argument.
		//! By default, no parametric 2D curve (pcurve) is defined for the
		//! edges of the result.
		//! If ComputePCurve1 equals true, further computations performed
		//! to attach an P-Curve in the parametric space of the argument
		//! to the constructed edges.
		//! Obsolete
		void ComputePCurveOn1(Standard_Boolean B);


		//! Indicates whether the P-Curve should be (or not)
		//! performed on the tool.
		//! By default, no parametric 2D curve (pcurve) is defined for the
		//! edges of the result.
		//! If ComputePCurve1 equals true, further computations performed
		//! to attach an P-Curve in the parametric space of the tool
		//! to the constructed edges.
		//! Obsolete
		void ComputePCurveOn2(Standard_Boolean B);

		//! Performs the algorithm
		//! Filling interference Data Structure (if it is necessary)
		//! Building the result of the operation.
		virtual void Build() Standard_OVERRIDE;


		//! get the face of the first part giving section edge <E>.
		//! Returns True on the 3 following conditions :
		//! 1/ <E> is an edge returned by the Shape() metwod.
		//! 2/ First part of section performed is a shape.
		//! 3/ <E> is built on a intersection curve (i.e <E>
		//! is not the result of common edges)
		//! When False, F remains untouched.
		//! Obsolete
		Standard_Boolean HasAncestorFaceOn1(XTopoDS_Shape^ E, XTopoDS_Shape^ F);

		//! Identifies the ancestor faces of
		//! the intersection edge E resulting from the last
		//! computation performed in this framework, that is, the faces of
		//! the two original shapes on which the edge E lies:
		//! -      HasAncestorFaceOn1 gives the ancestor face in the first shape, and
		//! -      HasAncestorFaceOn2 gives the ancestor face in the second shape.
		//! These functions return true if an ancestor face F is found, or false if not.
		//! An ancestor face is identifiable for the edge E if the following
		//! conditions are satisfied:
		//! -  the first part on which this algorithm performed its
		//! last computation is a shape, that is, it was not given as
		//! a surface or a plane at the time of construction of this
		//! algorithm or at a later time by the Init1 function,
		//! - E is one of the elementary edges built by the
		//! last computation of this section algorithm.
		//! To use these functions properly, you have to test the returned
		//! Boolean value before using the ancestor face: F is significant
		//! only if the returned Boolean value equals true.
		//! Obsolete
		Standard_Boolean HasAncestorFaceOn2(XTopoDS_Shape^ E, XTopoDS_Shape^ F);

		//! 获取图形
		virtual XTopoDS_Shape^ Shape();// Standard_OVERRIDE;

		/// <summary>
		/// 本地句柄
		/// </summary>
		virtual property BRepAlgoAPI_Section* IHandle {
			BRepAlgoAPI_Section* get() {// Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepAlgoAPI_Section* handle) {// Standard_OVERRIDE {
				NativeHandle = static_cast<BRepAlgoAPI_Section*>(handle);
			}
		}

	private:
		BRepAlgoAPI_Section* NativeHandle;
	};
}
#endif // _XBRepAlgoAPI_Section_HeaderFile
