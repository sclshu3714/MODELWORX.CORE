#include "XXCAFDoc_ShapeTool.h"

namespace TKXCAF {

    //!static 
    XStandard_GUID^ XXCAFDoc_ShapeTool::GetID() {
        return gcnew XStandard_GUID(XCAFDoc_ShapeTool::GetID());
    };

    //! Create (if not exist) ShapeTool from XCAFDoc on <L>.
    //! static 
    Handle(XCAFDoc_ShapeTool) XXCAFDoc_ShapeTool::Set(XTDF_Label^ L) {
        return XCAFDoc_ShapeTool::Set(L->GetLabel());
    };

    //! Creates an empty tool
    //! Creates a tool to work with a document <Doc>
    //! Attaches to label XCAFDoc::LabelShapes()
    XXCAFDoc_ShapeTool::XXCAFDoc_ShapeTool() {
        NativeHandle() = new XCAFDoc_ShapeTool();
    };

    //! Creates an empty tool
    //! Creates a tool to work with a document <Doc>
    //! Attaches to label XCAFDoc::LabelShapes()
    XXCAFDoc_ShapeTool::XXCAFDoc_ShapeTool(Handle(XCAFDoc_ShapeTool) pos) {
        NativeHandle() = pos;
    };

    //! Returns True if the label is a label of top-level shape,
    //! as opposed to component of assembly or subshape
    Standard_Boolean XXCAFDoc_ShapeTool::IsTopLevel(XTDF_Label^ L) {
        return NativeHandle()->IsTopLevel(L->GetLabel());
    };

    //! Returns True if the label is not used by any assembly, i.e.
    //! contains sublabels which are assembly components
    //! This is relevant only if IsShape() is True
    //! (There  is  no  Father TreeNode on  this  <L>)
    //!static 
    Standard_Boolean XXCAFDoc_ShapeTool::IsFree(XTDF_Label^ L) {
        return XCAFDoc_ShapeTool::IsFree(L->GetLabel());
    };

    //! Returns True if the label represents a shape (simple shape,
    //! assembly or reference)
    //!static 
    Standard_Boolean XXCAFDoc_ShapeTool::IsShape(XTDF_Label^ L) {
        return XCAFDoc_ShapeTool::IsShape(L->GetLabel());
    };

    //! Returns True if the label is a label of simple shape
    //!static 
    Standard_Boolean XXCAFDoc_ShapeTool::IsSimpleShape(XTDF_Label^ L) {
        return XCAFDoc_ShapeTool::IsSimpleShape(L->GetLabel());
    };

    //! Return true if <L> is a located instance of other shape
    //! i.e. reference
    //!static 
    Standard_Boolean XXCAFDoc_ShapeTool::IsReference(XTDF_Label^ L) {
        return XCAFDoc_ShapeTool::IsReference(L->GetLabel());
    };

    //! Returns True if the label is a label of assembly, i.e.
    //! contains sublabels which are assembly components
    //! This is relevant only if IsShape() is True
    //!static 
    Standard_Boolean XXCAFDoc_ShapeTool::IsAssembly(XTDF_Label^ L) {
        return XCAFDoc_ShapeTool::IsAssembly(L->GetLabel());
    };

    //! Return true if <L> is reference serving as component
    //! of assembly
    //!static 
    Standard_Boolean XXCAFDoc_ShapeTool::IsComponent(XTDF_Label^ L) {
        return XCAFDoc_ShapeTool::IsComponent(L->GetLabel());
    };

    //! Returns True if the label is a label of compound, i.e.
    //! contains some sublabels
    //! This is relevant only if IsShape() is True
    //!static 
    Standard_Boolean XXCAFDoc_ShapeTool::IsCompound(XTDF_Label^ L) {
        return XCAFDoc_ShapeTool::IsCompound(L->GetLabel());
    };

    //! Return true if <L> is subshape of the top-level shape
    //!static 
    Standard_Boolean XXCAFDoc_ShapeTool::IsSubShape(XTDF_Label^ L) {
        return XCAFDoc_ShapeTool::IsSubShape(L->GetLabel());
    };

    //! Checks whether shape <sub> is subshape of shape stored on
    //! label shapeL
    Standard_Boolean XXCAFDoc_ShapeTool::IsSubShape(XTDF_Label^ shapeL, TopoDS_Shape& sub) {
        return NativeHandle()->IsSubShape(shapeL->GetLabel(), sub);
    };

    Standard_Boolean XXCAFDoc_ShapeTool::SearchUsingMap(const TopoDS_Shape& S, XTDF_Label^ L, Standard_Boolean findWithoutLoc, Standard_Boolean findSubshape) {
        return NativeHandle()->SearchUsingMap(S, L->GetLabel(), findWithoutLoc, findSubshape);
    };

    //! General tool to find a (sub) shape in the document
    //! * If findInstance is True, and S has a non-null location,
    //! first tries to find the shape among the top-level shapes
    //! with this location
    //! * If not found, and findComponent is True, tries to find the shape
    //! among the components of assemblies
    //! * If not found, tries to find the shape without location
    //! among top-level shapes
    //! * If not found and findSubshape is True, tries to find a
    //! shape as a subshape of top-level simple shapes
    //! Returns False if nothing is found
    //!  Standard_Boolean findInstance = Standard_True, Standard_Boolean findComponent = Standard_True, Standard_Boolean findSubshape = Standard_True
    Standard_Boolean XXCAFDoc_ShapeTool::Search(const TopoDS_Shape& S, XTDF_Label^ L, Standard_Boolean findInstance, Standard_Boolean findComponent, Standard_Boolean findSubshape) {
        return NativeHandle()->Search(S, L->GetLabel(), findInstance, findComponent, findSubshape);
    };

    //! Returns the label corresponding to shape S
    //! (searches among top-level shapes, not including subcomponents
    //! of assemblies and subshapes)
    //! If findInstance is False (default), seach for the
    //! input shape without location
    //! If findInstance is True, searches for the
    //! input shape as is.
    //! Return True if <S> is found.
    //! Standard_Boolean findInstance = Standard_False
    Standard_Boolean XXCAFDoc_ShapeTool::FindShape(const TopoDS_Shape& S, XTDF_Label^ L, Standard_Boolean findInstance) {
        return NativeHandle()->FindShape(S, L->GetLabel(), findInstance);
    };

    //! Does the same as previous method
    //! Returns Null label if not found
    //! Standard_Boolean findInstance = Standard_False
    XTDF_Label^ XXCAFDoc_ShapeTool::FindShape(const TopoDS_Shape& S, Standard_Boolean findInstance) {
        return gcnew XTDF_Label(NativeHandle()->FindShape(S, findInstance));
    };

    //! To get TopoDS_Shape from shape's label
    //! For component, returns new shape with correct location
    //! Returns False if label does not contain shape
    //!static 
    Standard_Boolean XXCAFDoc_ShapeTool::GetShape(XTDF_Label^ L, TopoDS_Shape& S) {
        return XCAFDoc_ShapeTool::GetShape(L->GetLabel(), S);
    };

    //! To get TopoDS_Shape from shape's label
    //! For component, returns new shape with correct location
    //! Returns Null shape if label does not contain shape
    //!static 
    TopoDS_Shape XXCAFDoc_ShapeTool::GetShape(XTDF_Label^ L) {
        return XCAFDoc_ShapeTool::GetShape(L->GetLabel());
    };

    //! Creates new (empty) top-level shape.
    //! Initially it holds empty TopoDS_Compound
    XTDF_Label^ XXCAFDoc_ShapeTool::NewShape() {
        return gcnew XTDF_Label(NativeHandle()->NewShape());
    };

    //! Sets representation (TopoDS_Shape) for top-level shape.
    void XXCAFDoc_ShapeTool::SetShape(XTDF_Label^ L, TopoDS_Shape& S) {
        NativeHandle()->SetShape(L->GetLabel(), S);
    };

    //! Adds a new top-level (creates and returns a new label)
    //! If makeAssembly is True, treats TopAbs_COMPOUND shapes
    //! as assemblies (creates assembly structure).
    //! NOTE: <makePrepare> replace components without location
    //! in assmebly by located components to avoid some problems.
    //! If AutoNaming() is True then automatically attaches names.
    //! Standard_Boolean makeAssembly = Standard_True, Standard_Boolean makePrepare = Standard_True
    XTDF_Label^ XXCAFDoc_ShapeTool::AddShape(const TopoDS_Shape& S, Standard_Boolean makeAssembly, Standard_Boolean makePrepare) {
        return gcnew XTDF_Label(NativeHandle()->AddShape(S, makeAssembly, makePrepare));
    };

    //! Removes shape (whole label and all its sublabels)
    //! If removeCompletely is true, removes complete shape
    //! If removeCompletely is false, removes instance(location) only
    //! Returns False (and does nothing) if shape is not free
    //! or is not top-level shape
    //! Standard_Boolean removeCompletely = Standard_True
    Standard_Boolean XXCAFDoc_ShapeTool::RemoveShape(XTDF_Label^ L, Standard_Boolean removeCompletely) {
        return NativeHandle()->RemoveShape(L->GetLabel(), removeCompletely);
    };

    //! set hasComponents into false
    void XXCAFDoc_ShapeTool::Init() {
        NativeHandle()->Init();
    };

    //! Sets auto-naming mode to <V>. If True then for added
    //! shapes, links, assemblies and SHUO's, the TDataStd_Name attribute
    //! is automatically added. For shapes it contains a shape type
    //! (e.g. "SOLID", "SHELL", etc); for links it has a form
    //! "=>[0:1:1:2]" (where a tag is a label containing a shape
    //! without a location); for assemblies it is "ASSEMBLY", and
    //! "SHUO" for SHUO's.
    //! This setting is global; it cannot be made a member function
    //! as it is used by static methods as well.
    //! By default, auto-naming is enabled.
    //! See also AutoNaming().
    //!static 
    void XXCAFDoc_ShapeTool::SetAutoNaming(const Standard_Boolean V) {
        XCAFDoc_ShapeTool::SetAutoNaming(V);
    };

    //! Returns current auto-naming mode. See SetAutoNaming() for
    //! description.
    //!static 
    Standard_Boolean XXCAFDoc_ShapeTool::AutoNaming() {
        return XCAFDoc_ShapeTool::AutoNaming();
    };

    //! recursive
    void XXCAFDoc_ShapeTool::ComputeShapes(XTDF_Label^ L) {
        NativeHandle()->ComputeShapes(L->GetLabel());
    };

    //! Compute a sequence of simple shapes
    void XXCAFDoc_ShapeTool::ComputeSimpleShapes() {
        NativeHandle()->ComputeSimpleShapes();
    };

    //! Returns a sequence of all top-level shapes
    void XXCAFDoc_ShapeTool::GetShapes(XTDF_LabelSequence^ XLabels) {
        TDF_LabelSequence Labels;
        NativeHandle()->GetShapes(Labels);
        XLabels = gcnew XTDF_LabelSequence(Labels);
    };

    //! Returns a sequence of all top-level shapes
    //! which are free (i.e. not referred by any other)
    XTDF_LabelSequence^ XXCAFDoc_ShapeTool::GetFreeShapes() {
        TDF_LabelSequence Labels;
        NativeHandle()->GetFreeShapes(Labels);
        XTDF_LabelSequence^ FreeLabels = gcnew XTDF_LabelSequence(Labels);
        return FreeLabels;
    };

    //! Returns list of labels which refer shape L as component
    //! Returns number of users (0 if shape is free)
    //!static 
    Standard_Integer XXCAFDoc_ShapeTool::GetUsers(XTDF_Label^ L, TDF_LabelSequence& Labels, Standard_Boolean getsubchilds) {
        return XCAFDoc_ShapeTool::GetUsers(L->GetLabel(), Labels, getsubchilds);
    };

    //! Returns location of instance
    //!static 
    XTopLoc_Location^ XXCAFDoc_ShapeTool::GetLocation(XTDF_Label^ L) {
        return gcnew XTopLoc_Location(XCAFDoc_ShapeTool::GetLocation(L->GetLabel()));
    };

    //! Returns label which corresponds to a shape referred by L
    //! Returns False if label is not reference
    //!static 
    Standard_Boolean XXCAFDoc_ShapeTool::GetReferredShape(XTDF_Label^ L, XTDF_Label^ Label) {
        return XCAFDoc_ShapeTool::GetReferredShape(L->GetLabel(), Label->GetLabel());
    };

    //! Returns number of Assembles components
    //! Standard_Boolean getsubchilds = Standard_False
    //!static 
    Standard_Integer XXCAFDoc_ShapeTool::NbComponents(XTDF_Label^ L, Standard_Boolean getsubchilds) {
        return XCAFDoc_ShapeTool::NbComponents(L->GetLabel(), getsubchilds);
    };

    //! Returns list of components of assembly
    //! Returns False if label is not assembly
    //! Standard_Boolean getsubchilds = Standard_False
    //!static 
    Standard_Boolean XXCAFDoc_ShapeTool::GetComponents(XTDF_Label^ L, TDF_LabelSequence& Labels, Standard_Boolean getsubchilds) {
        return XCAFDoc_ShapeTool::GetComponents(L->GetLabel(), Labels, getsubchilds);
    };

    //! Adds a component given by its label and location to the assembly
    //! Note: assembly must be IsAssembly() or IsSimpleShape()
    XTDF_Label^ XXCAFDoc_ShapeTool::AddComponent(XTDF_Label^ assembly, XTDF_Label^ comp, XTopLoc_Location^ Loc) {
        return gcnew XTDF_Label(NativeHandle()->AddComponent(assembly->GetLabel(), comp->GetLabel(), Loc->GetLocation()));
    };

    //! Adds a shape (located) as a component to the assembly
    //! If necessary, creates an additional top-level shape for
    //! component and return the Label of component.
    //! If expand is True and component is Compound, it will
    //! be created as assembly also
    //! Note: assembly must be IsAssembly() or IsSimpleShape()
    //! Standard_Boolean expand = Standard_False
    XTDF_Label^ XXCAFDoc_ShapeTool::AddComponent(XTDF_Label^ assembly, TopoDS_Shape& comp, Standard_Boolean expand) {
        return gcnew XTDF_Label(NativeHandle()->AddComponent(assembly->GetLabel(), comp, expand));
    };

    //! Removes a component from its assembly
    void XXCAFDoc_ShapeTool::RemoveComponent(XTDF_Label^ comp) {
        NativeHandle()->RemoveComponent(comp->GetLabel());
    };

    //! Top-down update for all assembly compounds stored in the document.
    void XXCAFDoc_ShapeTool::UpdateAssemblies() {
        NativeHandle()->UpdateAssemblies();
    };

    //! Finds a label for subshape <sub> of shape stored on
    //! label shapeL
    //! Returns Null label if it is not found
    Standard_Boolean XXCAFDoc_ShapeTool::FindSubShape(XTDF_Label^ shapeL, TopoDS_Shape& sub, XTDF_Label^ L) {
        return NativeHandle()->FindSubShape(shapeL->GetLabel(), sub, L->GetLabel());
    };

    //! Adds a label for subshape <sub> of shape stored on
    //! label shapeL
    //! Returns Null label if it is not subshape
    XTDF_Label^ XXCAFDoc_ShapeTool::AddSubShape(XTDF_Label^ shapeL, TopoDS_Shape& sub) {
        return gcnew XTDF_Label(NativeHandle()->AddSubShape(shapeL->GetLabel(), sub));
    };

    //! Adds (of finds already existed) a label for subshape <sub> of shape stored on
    //! label shapeL. Label addedSubShapeL returns added (found) label or empty in case of wrong subshape.
    //! Returns True, if new shape was added, False in case of already existed subshape/wrong subshape
    Standard_Boolean XXCAFDoc_ShapeTool::AddSubShape(XTDF_Label^ shapeL, TopoDS_Shape& sub, XTDF_Label^ addedSubShapeL) {
        return NativeHandle()->AddSubShape(shapeL->GetLabel(), sub, addedSubShapeL->GetLabel());
    };

    XTDF_Label^ XXCAFDoc_ShapeTool::FindMainShapeUsingMap(const TopoDS_Shape& sub) {
        return gcnew XTDF_Label(NativeHandle()->FindMainShapeUsingMap(sub));
    };

    //! Performs a search among top-level shapes to find
    //! the shape containing <sub> as subshape
    //! Checks only simple shapes, and returns the first found
    //! label (which should be the only one for valid model)
    XTDF_Label^ XXCAFDoc_ShapeTool::FindMainShape(const TopoDS_Shape& sub) {
        return gcnew XTDF_Label(NativeHandle()->FindMainShape(sub));
    };

    //! Returns list of labels identifying subshapes of the given shape
    //! Returns False if no subshapes are placed on that label
    //!static 
    Standard_Boolean XXCAFDoc_ShapeTool::GetSubShapes(XTDF_Label^ L, TDF_LabelSequence& Labels) {
        return XCAFDoc_ShapeTool::GetSubShapes(L->GetLabel(), Labels);
    };

    //! returns the label under which shapes are stored
    XTDF_Label^ XXCAFDoc_ShapeTool::BaseLabel() {
        return gcnew XTDF_Label(NativeHandle()->BaseLabel());
    };

    Standard_OStream& XXCAFDoc_ShapeTool::Dump(Standard_OStream& theDumpLog, Standard_Boolean deep) {
        return NativeHandle()->Dump(theDumpLog, deep);
    };

    //! virtual 
    Standard_OStream& XXCAFDoc_ShapeTool::Dump(Standard_OStream& theDumpLog) {
        return NativeHandle()->Dump(theDumpLog);
    };

    //! Print to std::ostream <theDumpLog> type of shape found on <L> label
    //! and the entry of <L>, with <level> tabs before.
    //! If <deep>, print also TShape and Location addresses
    //! Standard_Integer level = 0, Standard_Boolean deep = Standard_False
    //!static 
    void XXCAFDoc_ShapeTool::DumpShape(Standard_OStream& theDumpLog, XTDF_Label^ L, Standard_Integer level, Standard_Boolean deep) {
        XCAFDoc_ShapeTool::DumpShape(theDumpLog, L->GetLabel(), level, deep);
    };

    XStandard_GUID^ XXCAFDoc_ShapeTool::ID() {
        return gcnew XStandard_GUID(NativeHandle()->ID());
    };

    void XXCAFDoc_ShapeTool::Restore(XTDF_Attribute^ with) {
        NativeHandle()->Restore(with->GetAttribute());
    };

    XTDF_Attribute^ XXCAFDoc_ShapeTool::NewEmpty() {
        return gcnew XTDF_Attribute(NativeHandle()->NewEmpty());
    };

    void XXCAFDoc_ShapeTool::Paste(XTDF_Attribute^ into, Handle(TDF_RelocationTable)& RT) {
        NativeHandle()->Paste(into->GetAttribute(), RT);
    };

    //! Returns True if the label is a label of external references, i.e.
    //! there are some reference on the no-step files, which are
    //! described in document only their names
    //!static 
    Standard_Boolean XXCAFDoc_ShapeTool::IsExternRef(XTDF_Label^ L) {
        return  XCAFDoc_ShapeTool::IsExternRef(L->GetLabel());
    };

    //! Sets the names of references on the no-step files
    XTDF_Label^ XXCAFDoc_ShapeTool::SetExternRefs(const TColStd_SequenceOfHAsciiString& SHAS) {
        return gcnew XTDF_Label(NativeHandle()->SetExternRefs(SHAS));
    };

    //! Sets the names of references on the no-step files
    void XXCAFDoc_ShapeTool::SetExternRefs(XTDF_Label^ L, TColStd_SequenceOfHAsciiString& SHAS) {
        NativeHandle()->SetExternRefs(L->GetLabel(), SHAS);
    };

    //! Gets the names of references on the no-step files
    //!static 
    void XXCAFDoc_ShapeTool::GetExternRefs(XTDF_Label^ L, TColStd_SequenceOfHAsciiString& SHAS) {
        XCAFDoc_ShapeTool::GetExternRefs(L->GetLabel(), SHAS);
    };

    //! Sets the SHUO structure between upper_usage and next_usage
    //! create multy-level (if number of labels > 2) SHUO from first to last
    //! Initialise out <MainSHUOAttr> by main upper_usage SHUO attribute.
    //! Returns FALSE if some of labels in not component label
    Standard_Boolean XXCAFDoc_ShapeTool::SetSHUO(const TDF_LabelSequence& Labels, Handle(XCAFDoc_GraphNode)& MainSHUOAttr) {
         return NativeHandle()->SetSHUO(Labels, MainSHUOAttr);
    };

    //! Returns founded SHUO GraphNode attribute <aSHUOAttr>
    //! Returns false in other case
    //!static 
    Standard_Boolean XXCAFDoc_ShapeTool::GetSHUO(XTDF_Label^ SHUOLabel, Handle(XCAFDoc_GraphNode)& aSHUOAttr) {
        return XCAFDoc_ShapeTool::GetSHUO(SHUOLabel->GetLabel(), aSHUOAttr);
    };

    //! Returns founded SHUO GraphNodes of indicated component
    //! Returns false in other case
    //!static 
    Standard_Boolean XXCAFDoc_ShapeTool::GetAllComponentSHUO(XTDF_Label^ CompLabel, TDF_AttributeSequence& SHUOAttrs) {
        return XCAFDoc_ShapeTool::GetAllComponentSHUO(CompLabel->GetLabel(), SHUOAttrs);
    };

    //! Returns the sequence of labels of SHUO attributes,
    //! which is upper_usage for this next_usage SHUO attribute
    //! (that indicated by label)
    //! NOTE: returns upper_usages only on one level (not recurse)
    //! NOTE: do not clear the sequence before filling
    //!static 
    Standard_Boolean XXCAFDoc_ShapeTool::GetSHUOUpperUsage(XTDF_Label^ NextUsageL, TDF_LabelSequence& Labels) {
        return XCAFDoc_ShapeTool::GetSHUOUpperUsage(NextUsageL->GetLabel(), Labels);
    };

    //! Returns the sequence of labels of SHUO attributes,
    //! which is next_usage for this upper_usage SHUO attribute
    //! (that indicated by label)
    //! NOTE: returns next_usages only on one level (not recurse)
    //! NOTE: do not clear the sequence before filling
    //!static 
    Standard_Boolean XXCAFDoc_ShapeTool::GetSHUONextUsage(XTDF_Label^ UpperUsageL, TDF_LabelSequence& Labels) {
        return XCAFDoc_ShapeTool::GetSHUONextUsage(UpperUsageL->GetLabel(), Labels);
    };

    //! Remove SHUO from component sublabel,
    //! remove all dependencies on other SHUO.
    //! Returns FALSE if cannot remove SHUO dependencies.
    //! NOTE: remove any styles that associated with this SHUO.
    Standard_Boolean XXCAFDoc_ShapeTool::RemoveSHUO(XTDF_Label^ SHUOLabel) {
        return NativeHandle()->RemoveSHUO(SHUOLabel->GetLabel());
    };

    //! Serach the path of labels in the document,
    //! that corresponds the component from any assembly
    //! Try to search the sequence of labels with location that
    //! produce this shape as component of any assembly
    //! NOTE: Clear sequence of labels before filling
    Standard_Boolean XXCAFDoc_ShapeTool::FindComponent(const TopoDS_Shape& theShape, TDF_LabelSequence& Labels) {
        return NativeHandle()->FindComponent(theShape, Labels);
    };

    //! Search for the component shape that styled by shuo
    //! Returns null shape if no any shape is found.
    TopoDS_Shape XXCAFDoc_ShapeTool::GetSHUOInstance(const Handle(XCAFDoc_GraphNode)& theSHUO) {
        return NativeHandle()->GetSHUOInstance(theSHUO);
    };

    //! Search for the component shape by labelks path
    //! and set SHUO structure for founded label structure
    //! Returns null attribute if no component in any assembly found.
    Handle(XCAFDoc_GraphNode) XXCAFDoc_ShapeTool::SetInstanceSHUO(const TopoDS_Shape& theShape) {
        return NativeHandle()->SetInstanceSHUO(theShape);
    };

    //! Seaching for component shapes that styled by shuo
    //! Returns empty sequence of shape if no any shape is found.
    Standard_Boolean XXCAFDoc_ShapeTool::GetAllSHUOInstances(const Handle(XCAFDoc_GraphNode)& theSHUO, TopTools_SequenceOfShape& theSHUOShapeSeq) {
        return NativeHandle()->GetAllSHUOInstances(theSHUO, theSHUOShapeSeq);
    };

    //! Searchs the SHUO by labels of components
    //! from upper_usage componet to next_usage
    //! Returns null attribute if no SHUO found
    //!static 
    Standard_Boolean XXCAFDoc_ShapeTool::FindSHUO(const TDF_LabelSequence& Labels, Handle(XCAFDoc_GraphNode)& theSHUOAttr) {
        return XCAFDoc_ShapeTool::FindSHUO(Labels, theSHUOAttr);
    };

    //! Convert Shape (compound/compsolid/shell/wire) to assembly
    Standard_Boolean XXCAFDoc_ShapeTool::Expand(XTDF_Label^ Shape) {
        return NativeHandle()->Expand(Shape->GetLabel());
    };

    //! Method to get NamedData attribute assigned to the given shape label.
    //! @param theLabel    [in] the shape Label
    //! @param theToCreate [in] create and assign attribute if it doesn't exist
    //! @return Handle to the NamedData attribute or Null if there is none
    //! Standard_Boolean theToCreate = Standard_False
    Handle(TDataStd_NamedData) XXCAFDoc_ShapeTool::GetNamedProperties(XTDF_Label^ theLabel, Standard_Boolean theToCreate) {
        return NativeHandle()->GetNamedProperties(theLabel->GetLabel(), theToCreate);
    };

    //! Method to get NamedData attribute assigned to a label of the given shape.
    //! @param theShape    [in] input shape
    //! @param theToCreate [in] create and assign attribute if it doesn't exist
    //! @return Handle to the NamedData attribute or Null if there is none
    //!  Standard_Boolean theToCreate = Standard_False
    Handle(TDataStd_NamedData) XXCAFDoc_ShapeTool::GetNamedProperties(const TopoDS_Shape& theShape, Standard_Boolean theToCreate) {
        return NativeHandle()->GetNamedProperties(theShape, theToCreate);
    };
}