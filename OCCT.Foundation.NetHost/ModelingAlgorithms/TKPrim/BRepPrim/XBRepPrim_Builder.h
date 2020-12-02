// Created on: 1992-03-12
// Created by: Philippe DAUTRY
// Copyright (c) 1992-1999 Matra Datavision
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

#ifndef _XBRepPrim_Builder_HeaderFile
#define _XBRepPrim_Builder_HeaderFile
#pragma once
#include <BRepPrim_Builder.hxx>
#include <XStandard_Helper.h>
#include <XBRep_Builder.h>
#include <XTopoDS_Shell.h>
#include <XTopoDS_Vertex.h>
#include <XTopoDS_Edge.h>
#include <XTopoDS_Wire.h>
#include <XTopoDS_Face.h>
#include <XTopoDS_Vertex.h>
#include <xgp_Pln.h>
#include <xgp_Lin.h>
#include <xgp_Circ.h>
#include <xgp_Lin2d.h>
#include <xgp_Circ2d.h>
#include <xgp_Ax2.h>
#include <xgp_Pnt.h>


#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <BRep_Builder.hxx>
#include <Standard_Real.hxx>
#include <Standard_Boolean.hxx>
class BRep_Builder;

using namespace TKBRep;
using namespace TKernel;
using namespace TKMath;
namespace TKPrim {

    ref class  TKernel::XStandard_Helper;
    ref class TKBRep::XTopoDS_Shell;
    ref class TKBRep::XTopoDS_Face;
    ref class TKBRep::XTopoDS_Wire;
    ref class TKBRep::XTopoDS_Edge;
    ref class TKBRep::XTopoDS_Vertex;
    ref class TKMath::xgp_Pln;
    ref class TKMath::xgp_Lin;
    ref class TKMath::xgp_Circ;
    ref class TKMath::xgp_Lin2d;
    ref class TKMath::xgp_Circ2d;
    ref class TKMath::xgp_Pnt;
    //! implements the abstract Builder with the BRep Builder
    public ref class XBRepPrim_Builder
    {
    public:

        //! DEFINE_STANDARD_ALLOC


        //! Creates an empty, useless  Builder. Necesseray for
        //! compilation.
        XBRepPrim_Builder();

        //! Creates from a Builder.
        XBRepPrim_Builder(BRepPrim_Builder* pos);

        void SetBRepPrimBuilderHandle(BRepPrim_Builder* pos);

        virtual BRepPrim_Builder* GetBRepPrimBuilder();

        XBRep_Builder^ Builder();

        //! Make a empty Shell.
        void MakeShell(XTopoDS_Shell^ S);

        //! Returns in   <F> a  Face  built  with   the  plane
        //! equation <P>. Used by all primitives.
        void MakeFace(XTopoDS_Face^ F, xgp_Pln^ P);

        //! Returns in <W> an empty Wire.
        void MakeWire(XTopoDS_Wire^ W);

        //! Returns in <E> a degenerated edge.
        void MakeDegeneratedEdge(XTopoDS_Edge^ E);

        //! Returns   in <E>  an  Edge  built  with  the  line
        //! equation  <L>.
        void MakeEdge(XTopoDS_Edge^ E, xgp_Lin^ L);

        //! Returns  in <E>   an  Edge  built  with the circle
        //! equation  <C>.
        void MakeEdge(XTopoDS_Edge^ E, xgp_Circ^ C);

        //! Sets the line <L> to be the curve representing the
        //! edge <E> in the parametric space of the surface of
        //! <F>.
        void SetPCurve(XTopoDS_Edge^ E, XTopoDS_Face^ F, xgp_Lin2d^ L);

        //! Sets the    lines  <L1,L2>  to   be     the curves
        //! representing the edge <E>  in the parametric space
        //! of the closed surface of <F>.
        void SetPCurve(XTopoDS_Edge^ E, XTopoDS_Face^ F, xgp_Lin2d^ L1, xgp_Lin2d^ L2);

        //! Sets the  circle <C> to  be the curve representing
        //! the  edge <E>  in   the  parametric  space of  the
        //! surface of <F>.
        void SetPCurve(XTopoDS_Edge^ E, XTopoDS_Face^ F, xgp_Circ2d^ C);

        //! Returns in <V> a Vertex built with the point <P>.
        void MakeVertex(XTopoDS_Vertex^ V, xgp_Pnt^ P);

        //! Reverses the Face <F>.
        void ReverseFace(XTopoDS_Face^ F);

        //! Adds the Vertex <V> in the Edge <E>.  <P> is the
        //! parameter of the vertex on the  edge.  If direct
        //! is False the Vertex is reversed.
        void AddEdgeVertex(XTopoDS_Edge^ E, XTopoDS_Vertex^ V, Standard_Real P, Standard_Boolean direct);

        //! Adds  the Vertex <V>  in the Edge <E>.   <P1,P2>
        //! are the  parameters of the  vertex on the closed
        //! edge.
        void AddEdgeVertex(XTopoDS_Edge^ E, XTopoDS_Vertex^ V, Standard_Real P1, Standard_Real P2);

        //! <P1,P2> are the parameters of the  vertex on the
        //! edge.  The edge is a closed curve.
        void SetParameters(XTopoDS_Edge^ E, XTopoDS_Vertex^ V, Standard_Real P1, Standard_Real P2);

        //! Adds the Edge <E> in the  Wire <W>, if direct is
        //! False the Edge is reversed.
        void AddWireEdge(XTopoDS_Wire^ W, XTopoDS_Edge^ E, Standard_Boolean direct);

        //! Adds the Wire <W> in  the Face <F>.
        void AddFaceWire(XTopoDS_Face^ F, XTopoDS_Wire^ W);

        //! Adds the Face <F>  in the Shell <Sh>.
        void AddShellFace(XTopoDS_Shell^ Sh, XTopoDS_Face^ F);

        //! This is called once an edge is completed. It gives
        //! the opportunity to perform any post treatment.
        void CompleteEdge(XTopoDS_Edge^ E);

        //! This is called once a wire is  completed. It gives
        //! the opportunity to perform any post treatment.
        void CompleteWire(XTopoDS_Wire^ W);

        //! This is called once a face is  completed. It gives
        //! the opportunity to perform any post treatment.
        void CompleteFace(XTopoDS_Face^ F);

        //! This is called once a shell is  completed. It gives
        //! the opportunity to perform any post treatment.
        void CompleteShell(XTopoDS_Shell^ S);
        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property BRepPrim_Builder* IHandle {
            BRepPrim_Builder* get() { //Standard_OVERRIDE {
                return NativeHandle;
            }
            void set(BRepPrim_Builder* handle) { //Standard_OVERRIDE {
                NativeHandle = static_cast<BRepPrim_Builder*>(handle);
            }
        }

    private:
        BRepPrim_Builder* NativeHandle;
    };
}
#endif // _XBRepPrim_Builder_HeaderFile
