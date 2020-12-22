#include <XBRepOffset.h>
namespace TKOffset {
    //! returns   the  Offset  surface  computed from  the
    //! surface <Surface> at an OffsetDistance <Offset>.
    //!
    //! If possible, this method returns  the real type of
    //! the surface ( e.g. An Offset of a plane is a plane).
    //!
    //! If  no particular  case  is detected, the returned
    //! surface will have the Type Geom_OffsetSurface.
    //! Parameter allowC0 is then passed as last argument to 
    //! constructor of Geom_OffsetSurface.
    //! Standard_Boolean allowC0 = Standard_False
    //! static 
    XGeom_Surface^ XBRepOffset::Surface(XGeom_Surface^ Surface, Standard_Real Offset, XBRepOffset_Status theStatus, Standard_Boolean allowC0) {
        BRepOffset_Status theStatusx = safe_cast<BRepOffset_Status>(theStatus);
        return gcnew XGeom_Surface(BRepOffset::Surface(Surface->GetSurface(), Offset, theStatusx, allowC0));
    };

    //! Preprocess surface to be offset (bspline, bezier, or revolution based on
    //! bspline or bezier curve), by collapsing each singular side to single point.
    //!
    //! This is to avoid possible flipping of normal at the singularity 
    //! of the surface due to non-zero distance between the poles that
    //! logically should be in one point (singularity).
    //! 
    //! The (parametric) side of the surface is considered to be singularity if face 
    //! has degenerated edge whose vertex encompasses (by its tolerance) all points on that side,
    //! or if all poles defining that side fit into sphere with radius thePrecision.
    //!
    //! Returns either original surface or its modified copy (if some poles have been moved).
    //! static 
    XGeom_Surface^ XBRepOffset::CollapseSingularities(XGeom_Surface^ theSurface, XTopoDS_Face^ theFace, Standard_Real thePrecision) {
        return gcnew XGeom_Surface(BRepOffset::CollapseSingularities(theSurface->GetSurface(), *theFace->GetFace(), thePrecision));
    };
}