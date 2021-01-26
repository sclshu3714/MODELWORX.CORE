#include "XTDF_ChildIDIterator.h"

namespace TKLCAF {
    //! Creates an empty iterator.
    XTDF_ChildIDIterator::XTDF_ChildIDIterator() {
        NativeHandle = new TDF_ChildIDIterator();
    };

    //! Iterates on the children of the given label. If
    //! <allLevels> option is set to true, it explores not
    //! only the first, but all the sub label levels.
    //! Standard_Boolean allLevels = Standard_False
    XTDF_ChildIDIterator::XTDF_ChildIDIterator(XTDF_Label^ aLabel, XStandard_GUID^ anID, Standard_Boolean allLevels) {
        NativeHandle = new TDF_ChildIDIterator(*aLabel->GetLabel(), anID->GetGUID(), allLevels);
    };
    //! Initializes the iteration on the children of the
    //! given label. If <allLevels> option is set to true,
    //! it explores not only the first, but all the sub
    //! label levels.
    void XTDF_ChildIDIterator::Initialize(XTDF_Label^ aLabel, XStandard_GUID^ anID, Standard_Boolean allLevels) {
        NativeHandle->Initialize(*aLabel->GetLabel(), anID->GetGUID(), allLevels);
    };
    //! Returns True if there is a current Item in the
    //! iteration.
    Standard_Boolean XTDF_ChildIDIterator::More() {
        return NativeHandle->More();
    };

    //! Move to the next Item
    void XTDF_ChildIDIterator::Next() {
        NativeHandle->Next();
    };

    //! Move to the next Brother. If there is none, go up
    //! etc. This method is interesting only with
    //! "allLevels" behavior, because it avoids to explore
    //! the current label children.
    void XTDF_ChildIDIterator::NextBrother() {
        NativeHandle->NextBrother();
    };

    //! Returns the current item; a null handle if there is none.
    XTDF_Attribute^ XTDF_ChildIDIterator::Value() {
        return gcnew XTDF_Attribute(NativeHandle->Value());
    };
}