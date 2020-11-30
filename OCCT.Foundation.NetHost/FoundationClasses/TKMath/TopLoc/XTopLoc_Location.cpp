#include "XTopLoc_Location.h"


namespace TKMath {


    //!ructs an empty local coordinate system object.
    //! Note: A Locationructed from a default datum is said to be "empty".
    XTopLoc_Location::XTopLoc_Location(void) {
        NativeHandle = new TopLoc_Location();
    };

    //!ructs an empty local coordinate system object.
    //! Note: A Locationructed from a default datum is said to be "empty".
    XTopLoc_Location::XTopLoc_Location(TopLoc_Location* pos) {
        NativeHandle = new TopLoc_Location(*pos);
    };

    //!ructs an empty local coordinate system object.
    //! Note: A Locationructed from a default datum is said to be "empty".
    XTopLoc_Location::XTopLoc_Location(TopLoc_Location pos) {
        NativeHandle = new TopLoc_Location(pos);
    };

    //!ructs the local coordinate system object defined
    //! by the transformation T. T invokes in turn, a TopLoc_Datum3D object.
    XTopLoc_Location::XTopLoc_Location(xgp_Trsf^ T) {
        NativeHandle = new TopLoc_Location(T->GetTrsf());
    };

    //!ructs the local coordinate system object defined by the 3D datum D.
    //! Exceptions
    //! Standard_ConstructionError if the transformation
    //! T does not represent a 3D coordinate system.
    XTopLoc_Location::XTopLoc_Location(const Handle(TopLoc_Datum3D) D) {
        NativeHandle = new TopLoc_Location(D);
    };

    //! ÊÍ·Å
    XTopLoc_Location::~XTopLoc_Location() {
        if (NativeHandle != NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };

    //!
    TopLoc_Location XTopLoc_Location::GetLocation() {
        return *NativeHandle;
    };

    //! Returns true if this location is equal to the Identity transformation.
    Standard_Boolean XTopLoc_Location::IsIdentity() {
        return NativeHandle->IsIdentity();
    };

    //! Resets this location to the Identity transformation.
    void XTopLoc_Location::Identity() {
        NativeHandle->Identity();
    };

    //! Returns    the  first   elementary  datum  of  the
    //! Location.  Use the NextLocation function recursively to access
    //! the other data comprising this location.
    //! Exceptions
    //! Standard_NoSuchObject if this location is empty.
    Handle(TopLoc_Datum3D) XTopLoc_Location::FirstDatum() {
        return NativeHandle->FirstDatum();
    };

    //! Returns   the  power  elevation  of    the   first
    //! elementary datum.
    //! Exceptions
    //! Standard_NoSuchObject if this location is empty.
    Standard_Integer XTopLoc_Location::FirstPower() {
        return NativeHandle->FirstPower();
    };

    //! Returns  a Location representing  <me> without the
    //! first datum. We have the relation :
    //!
    //! <me> = NextLocation() * FirstDatum() ^ FirstPower()
    //! Exceptions
    //! Standard_NoSuchObject if this location is empty.
    XTopLoc_Location^ XTopLoc_Location::NextLocation() {
        return gcnew XTopLoc_Location(NativeHandle->NextLocation());
    };

    //! Returns  the transformation    associated  to  the
    //! coordinate system.
    xgp_Trsf^ XTopLoc_Location::Transformation() {
        return gcnew xgp_Trsf(NativeHandle->Transformation());
    };

    //! Returns the inverse of <me>.
    //!
    //! <me> * Inverted() is an Identity.
    XTopLoc_Location^ XTopLoc_Location::Inverted() {
        return gcnew XTopLoc_Location(NativeHandle->Inverted());
    };

    //! Returns <me> * <Other>, the  elementary datums are
    //! concatenated.
    XTopLoc_Location^ XTopLoc_Location::Multiplied(XTopLoc_Location^ Other) {
        return gcnew XTopLoc_Location(NativeHandle->Multiplied(Other->GetLocation()));
    };

    //! Returns  <me> / <Other>.
    XTopLoc_Location^ XTopLoc_Location::Divided(XTopLoc_Location^ Other) {
        return gcnew XTopLoc_Location(NativeHandle->Divided(Other->GetLocation()));
    };

    //! Returns <Other>.Inverted() * <me>.
    XTopLoc_Location^ XTopLoc_Location::Predivided(XTopLoc_Location^ Other) {
        return gcnew XTopLoc_Location(NativeHandle->Predivided(Other->GetLocation()));
    };

    //! Returns me at the power <pwr>.   If <pwr>  is zero
    //! returns  Identity.  <pwr> can  be lower  than zero
    //! (usual meaning for powers).
    XTopLoc_Location^ XTopLoc_Location::Powered(Standard_Integer pwr) {
        return gcnew XTopLoc_Location(NativeHandle->Powered(pwr));
    };

    //! Returns a hashed value for this local coordinate system. This value is used, with map tables, to store and
    //! retrieve the object easily, and is in the range [1, theUpperBound].
    //! @param theUpperBound the upper bound of the range a computing hash code must be within
    //! @return a computed hash code, in the range [1, theUpperBound]
    Standard_Integer XTopLoc_Location::HashCode(Standard_Integer theUpperBound) {
        return NativeHandle->HashCode(theUpperBound);
    };

    //! Returns true if this location and the location Other
    //! have the same elementary data, i.e. contain the same
    //! series of TopLoc_Datum3D and respective powers.
    //! This method is an alias for operator ==.
    Standard_Boolean XTopLoc_Location::IsEqual(XTopLoc_Location^ Other) {
        return NativeHandle->IsEqual(Other->GetLocation());
    };

    //! Returns true if this location and the location Other do
    //! not have the same elementary data, i.e. do not
    //! contain the same series of TopLoc_Datum3D and respective powers.
    //! This method is an alias for operator !=.
    Standard_Boolean XTopLoc_Location::IsDifferent(XTopLoc_Location^ Other) {
        return NativeHandle->IsDifferent(Other->GetLocation());
    };

    //! Dumps the content of me into the stream
    void XTopLoc_Location::DumpJson(Standard_OStream theOStream, Standard_Integer theDepth) {
        NativeHandle->DumpJson(theOStream, theDepth);
    };

    //! Prints the contents of <me> on the stream <s>.
    void XTopLoc_Location::ShallowDump(Standard_OStream S) {
        NativeHandle->ShallowDump(S);
    };
};


