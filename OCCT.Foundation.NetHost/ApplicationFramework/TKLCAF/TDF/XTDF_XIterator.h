#ifndef XTDF_XIterator_HeaderFile
#define XTDF_XIterator_HeaderFile
#pragma once
#include <XTDF_Label.h>
#include <NCollection_Sequence.hxx>
namespace TKLCAF {
	//!   Implementation of the Iterator interface
	typedef NCollection_Sequence<TDF_Label> TDF_LabelSequence;
	public ref class XTDF_XIterator //: public NCollection_BaseSequence::Iterator
	{
	public:
		!XTDF_XIterator() { NativeIterator = NULL; };
		~XTDF_XIterator() { NativeIterator = NULL; };
		//! Empty constructor - for later Init
		XTDF_XIterator(void) {
			NativeIterator = new TDF_LabelSequence::Iterator();
		}
		//! Constructor with initialisation
		//! const Standard_Boolean isStart = Standard_True
		XTDF_XIterator(TDF_LabelSequence theSeq, Standard_Boolean isStart) {
			NativeIterator = new TDF_LabelSequence::Iterator(theSeq, isStart);
		}

		TDF_LabelSequence::Iterator GetIterator() {
			return *NativeIterator;
		};

		//! Check end
		Standard_Boolean More(void)
		{
			return NativeIterator->More();
		}
		//! Make step
		void Next(void)
		{
			NativeIterator->Next();
		}
		//! Constant value access
		XTDF_Label^ Value(void)
		{
			TDF_Label EditValue = NativeIterator->Value();
			return gcnew XTDF_Label(EditValue);
		}
		//! Variable value access
		XTDF_Label^ ChangeValue(void)
		{
			return gcnew XTDF_Label(NativeIterator->ChangeValue());
		}
		//! Performs comparison of two iterators.
		Standard_Boolean IsEqual(XTDF_XIterator^ theOther)
		{
			return NativeIterator->IsEqual(theOther->GetIterator());
		}
	private:
		TDF_LabelSequence::Iterator* NativeIterator;
	}; // End of nested class Iterator
}
#endif // XTDF_XIterator_HeaderFile