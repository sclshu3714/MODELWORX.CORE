#include "XTDF_ChildIterator.h"

namespace TKLCAF {
    //! Creates an empty iterator  object to
        //! explore the children of a label.
    XTDF_ChildIterator::XTDF_ChildIterator() {
        NativeHandle = new TDF_ChildIterator();
    };

    //! Creates an empty iterator  object to
    //! explore the children of a label.
    XTDF_ChildIterator::XTDF_ChildIterator(TDF_ChildIterator* pos) {
        NativeHandle = new TDF_ChildIterator(*pos);
    };

    //! Constructs the iterator object defined by
    //! the label aLabel.  Iterates on the children of the given label. If
    //! <allLevels> option is set to true, it explores not
    //! only the first, but all the sub label levels.
    //! allLevels default false
    XTDF_ChildIterator::XTDF_ChildIterator(const TDF_Label& aLabel, const Standard_Boolean allLevels) {
        NativeHandle = new TDF_ChildIterator(aLabel, allLevels);
    };

    //! Constructs the iterator object defined by
    //! the label aLabel.  Iterates on the children of the given label. If
    //! <allLevels> option is set to true, it explores not
    //! only the first, but all the sub label levels.
    //! allLevels default false
    XTDF_ChildIterator::XTDF_ChildIterator(XTDF_Label^ aLabel, const Standard_Boolean allLevels) {
        NativeHandle = new TDF_ChildIterator(aLabel->GetLabel(), allLevels);
    };

    //! Initializes the iteration on the children of the
    //! given label.
    //! If <allLevels> option is set to true,
    //! it explores not only the first, but all the sub
    //! label levels.
    //! If allLevels is false, only the first level of
    //! child labels is explored.
    //! In the example below, the label is iterated
    //! using Initialize, More and Next and its
    //! child labels dumped using TDF_Tool::Entry.
    //! Example
    //! void DumpChildren(const
    //! TDF_Label& aLabel)
    //! {
    //! TDF_ChildIterator it;
    //! TCollection_AsciiString es;
    //! for
    //! (it.Initialize(aLabel,Standard_True);
    //! it.More(); it.Next()){
    //! TDF_Tool::Entry(it.Value(),es);
    //! std::cout << as.ToCString() << std::endl;
    //! }
    //! }
    //! allLevels default false
    void XTDF_ChildIterator::Initialize(const TDF_Label& aLabel, const Standard_Boolean allLevels) {
        NativeHandle->Initialize(aLabel, allLevels);
    };

    //! allLevels default false
    void XTDF_ChildIterator::Initialize(XTDF_Label^ aLabel, const Standard_Boolean allLevels) {
        NativeHandle->Initialize(aLabel->GetLabel(), allLevels);
    };

    //! Returns true if a current label is found in the
    //! iteration process.
    Standard_Boolean XTDF_ChildIterator::More() {
        return  NativeHandle->More();
    };        

    //! Move the  current  iteration  to the next Item.
    void XTDF_ChildIterator::Next() {
        NativeHandle->Next();
    };

    //! Moves this iteration to the next brother
    //! label. A brother label is one with the same
    //! father as an initial label.
    //! Use this function when the non-empty
    //! constructor or Initialize has allLevels set to
    //! true. The result is that the iteration does not
    //! explore the children of the current label.
    //! This method is interesting only with
    //! "allLevels" behavior, because it avoids to explore
    //! the current label children.
    void XTDF_ChildIterator::NextBrother() {
        NativeHandle->NextBrother();
    };

    //! Returns the current label; or, if there is
    //! none, a null label.
    const TDF_Label XTDF_ChildIterator::Value() {
       return NativeHandle->Value();
    };

    //! Returns the current label; or, if there is
    //! none, a null label.
    const XTDF_Label^ XTDF_ChildIterator::EditValue() {
        return gcnew XTDF_Label(NativeHandle->Value());
    };
}