#include <XNCollection_Array1.h>
namespace TKernel {
    //! Empty constructor - for later Init
    template <class TheItemType>
    XNCollection_Array1<TheItemType>::XIterator::XIterator() {

    };

    //! Constructor with initialization
    //! Standard_Boolean theToEnd = Standard_False
    template <class TheItemType>
    XNCollection_Array1<TheItemType>::XIterator::XIterator(XNCollection_Array1<TheItemType>^ theArray, Standard_Boolean theToEnd) {

    };

    //! Initialisation
    template <class TheItemType>
    void XNCollection_Array1<TheItemType>::XIterator::Init(XNCollection_Array1<TheItemType>^ theArray) {

    };

    //! Assignment
    template <class TheItemType>
    XNCollection_Array1<TheItemType>::XIterator^ XNCollection_Array1<TheItemType>::XIterator::operator= (XNCollection_Array1<TheItemType>::XIterator^ theOther) {

    };

    //! Check end
    template <class TheItemType>
    Standard_Boolean XNCollection_Array1<TheItemType>::XIterator::More(void) {

    };

    //! Increment operator
    template <class TheItemType>
    void XNCollection_Array1<TheItemType>::XIterator::Next(void) {

    };

    //! Decrement operator
    template <class TheItemType>
    void XNCollection_Array1<TheItemType>::XIterator::Previous() {

    };

    //! Offset operator.
    template <class TheItemType>
    void XNCollection_Array1<TheItemType>::XIterator::Offset(ptrdiff_t theOffset) {

    };

    //! Difference operator.
    template <class TheItemType>
    ptrdiff_t XNCollection_Array1<TheItemType>::XIterator::Differ(XIterator^ theOther) {

    };

    //! Constant value access
    template <class TheItemType>
    TheItemType^ XNCollection_Array1<TheItemType>::XIterator::Value(void) {

    };

    //! Variable value access
    template <class TheItemType>
    TheItemType^ XNCollection_Array1<TheItemType>::XIterator::ChangeValue(void) {

    };

    //! Performs comparison of two iterators
    template <class TheItemType>
    Standard_Boolean XNCollection_Array1<TheItemType>::XIterator::IsEqual(XIterator^ theOther) {

    };

    // ---------- PUBLIC METHODS ------------

    //! Empty constructor; should be used with caution.
    //! @sa methods Resize() and Move().
    template <class TheItemType>
    XNCollection_Array1<TheItemType>::XNCollection_Array1() {

    };

    //! Constructor
    template <class TheItemType>
    XNCollection_Array1<TheItemType>::XNCollection_Array1(Standard_Integer theLower, Standard_Integer theUpper) {

    };

    //! Copy constructor 
    template <class TheItemType>
    XNCollection_Array1<TheItemType>::XNCollection_Array1(XNCollection_Array1<TheItemType>^ theOther) {

    };

    //! C array-based constructor.
    //!
    //! Makes this array to use the buffer pointed by theBegin
    //! instead of allocating it dynamically.
    //! Argument theBegin should be a reference to the first element
    //! of the pre-allocated buffer (usually local C array buffer),
    //! with size at least theUpper - theLower + 1 items.
    //!
    //! Warning: returning array object created using this constructor
    //! from function by value will result in undefined behavior
    //! if compiler performs return value optimization (this is likely
    //! to be true for all modern compilers in release mode).
    //! The same happens if array is copied using Move() function
    //! or move constructor and target object's lifespan is longer
    //! than that of the buffer.
    template <class TheItemType>
    XNCollection_Array1<TheItemType>::XNCollection_Array1(TheItemType^ theBegin, Standard_Integer theLower, Standard_Integer theUpper) {

    };

    //! Initialise the items with theValue
    template <class TheItemType>
    void XNCollection_Array1<TheItemType>::Init(TheItemType^ theValue) {

    };

    //! Size query
    template <class TheItemType>
    Standard_Integer XNCollection_Array1<TheItemType>::Size(void) {

    };
    //! Length query (the same)
    template <class TheItemType>
    Standard_Integer XNCollection_Array1<TheItemType>::Length(void) {

    };

    //! Return TRUE if array has zero length.
    template <class TheItemType>
    Standard_Boolean XNCollection_Array1<TheItemType>::IsEmpty() {

    };

    //! Lower bound
    template <class TheItemType>
    Standard_Integer XNCollection_Array1<TheItemType>::Lower(void) {

    };
    //! Upper bound
    template <class TheItemType>
    Standard_Integer XNCollection_Array1<TheItemType>::Upper(void) {

    };

    //! myDeletable flag
    template <class TheItemType>
    Standard_Boolean XNCollection_Array1<TheItemType>::IsDeletable(void) {

    };

    //! IsAllocated flag - for naming compatibility
    template <class TheItemType>
    Standard_Boolean XNCollection_Array1<TheItemType>::IsAllocated(void) {

    };

    //! Copies data of theOther array to this.
    //! This array should be pre-allocated and have the same length as theOther;
    //! otherwise exception Standard_DimensionMismatch is thrown.
    template <class TheItemType>
    XNCollection_Array1<TheItemType>^ XNCollection_Array1<TheItemType>::Assign(XNCollection_Array1^ theOther) {

    };

    //! Move assignment.
    //! This array will borrow all the data from theOther.
    //! The moved object will keep pointer to the memory buffer and
    //! range, but it will not free the buffer on destruction.
    template <class TheItemType>
    XNCollection_Array1<TheItemType>^ XNCollection_Array1<TheItemType>::Move(XNCollection_Array1<TheItemType>^ theOther) {

    };

    //! Assignment operator; @sa Assign()
    template <class TheItemType>
    XNCollection_Array1<TheItemType>^ XNCollection_Array1<TheItemType>::operator= (XNCollection_Array1<TheItemType>^ theOther) {

    };

    //! @return first element
    template <class TheItemType>
    TheItemType^ XNCollection_Array1<TheItemType>::First() {

    };

    //! @return first element
    template <class TheItemType>
    TheItemType^ XNCollection_Array1<TheItemType>::ChangeFirst() {

    };

    //! @return last element
    template <class TheItemType>
    TheItemType^ XNCollection_Array1<TheItemType>::Last() {

    };

    //! @return last element
    template <class TheItemType>
    TheItemType^ XNCollection_Array1<TheItemType>::ChangeLast() {

    };

    //! Constant value access
    template <class TheItemType>
    TheItemType^ XNCollection_Array1<TheItemType>::Value(Standard_Integer theIndex) {

    };

    //! operator() - alias to Value
    template <class TheItemType>
    TheItemType^ XNCollection_Array1<TheItemType>::operator() (Standard_Integer theIndex) {

    };

    //! operator[] - alias to Value
    template <class TheItemType>
    TheItemType^ XNCollection_Array1<TheItemType>::operator[] (Standard_Integer theIndex) {

    };

    //! Variable value access
    template <class TheItemType>
    TheItemType^ XNCollection_Array1<TheItemType>::ChangeValue(Standard_Integer theIndex) {

    };

    //! operator() - alias to ChangeValue
    template <class TheItemType>
    TheItemType^ XNCollection_Array1<TheItemType>::operator() (Standard_Integer theIndex) {

    };

    //! operator[] - alias to ChangeValue
    template <class TheItemType>
    TheItemType^ XNCollection_Array1<TheItemType>::operator[] (Standard_Integer theIndex) {

    };

    //! Set value 
    template <class TheItemType>
    void XNCollection_Array1<TheItemType>::SetValue(Standard_Integer theIndex, TheItemType^ theItem) {

    };

    //! Resizes the array to specified bounds.
    //! No re-allocation will be done if length of array does not change,
    //! but existing values will not be discarded if theToCopyData set to FALSE.
    //! @param theLower new lower bound of array
    //! @param theUpper new upper bound of array
    //! @param theToCopyData flag to copy existing data into new array
    template <class TheItemType>
    void XNCollection_Array1<TheItemType>::Resize(Standard_Integer theLower, Standard_Integer theUpper, Standard_Boolean theToCopyData) {

    };

    //! Destructor - releases the memory
    template <class TheItemType>
    XNCollection_Array1<TheItemType>::~XNCollection_Array1(void) {

    };
}