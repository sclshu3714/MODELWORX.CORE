#include <XXCAFDoc_ColorTool.h>

namespace TKXCAF {
    XXCAFDoc_ColorTool::XXCAFDoc_ColorTool() {
        NativeHandle() = new XCAFDoc_ColorTool();
    };

    XXCAFDoc_ColorTool::XXCAFDoc_ColorTool(Handle(XCAFDoc_ColorTool) pos) {
        NativeHandle() = pos;
    };

    Handle(XCAFDoc_ColorTool) XXCAFDoc_ColorTool::GetColorTool() {
        return NativeHandle();
    };

    //! Creates (if not exist) ColorTool.
    //! static
    XXCAFDoc_ColorTool^ XXCAFDoc_ColorTool::Set(XTDF_Label^ L) {
        Handle(XCAFDoc_ColorTool) temp = XCAFDoc_ColorTool::Set(*L->GetLabel());
        return gcnew XXCAFDoc_ColorTool(temp);
    };

    //! static
    XStandard_GUID^ XXCAFDoc_ColorTool::GetID() {
        Standard_GUID temp = XCAFDoc_ColorTool::GetID();
        return gcnew XStandard_GUID(temp);
    };

    //! returns the label under which colors are stored
    XTDF_Label^ XXCAFDoc_ColorTool::BaseLabel() {
        TDF_Label temp = NativeHandle()->BaseLabel();
        return gcnew XTDF_Label(temp);
    };

    //! Returns internal XCAFDoc_ShapeTool tool
    XXCAFDoc_ShapeTool^ XXCAFDoc_ColorTool::ShapeTool() {
        Handle(XCAFDoc_ShapeTool) temp = NativeHandle()->ShapeTool();
        return gcnew XXCAFDoc_ShapeTool(temp);
    };

    //! Returns True if label belongs to a colortable and
    //! is a color definition
    Standard_Boolean XXCAFDoc_ColorTool::IsColor(XTDF_Label^ lab) {
        return NativeHandle()->IsColor(*lab->GetLabel());
    };

    //! Returns color defined by label lab
    //! Returns False if the label is not in colortable
    //! or does not define a color
    Standard_Boolean XXCAFDoc_ColorTool::GetColor(XTDF_Label^ lab, XQuantity_Color^% col) {
        Quantity_Color* temp = col->GetColor();
        Standard_Boolean Result = NativeHandle()->GetColor(*lab->GetLabel(), *temp);
        col = gcnew XQuantity_Color(temp);
        return Result;
    };

    //! Returns color defined by label lab
    //! Returns False if the label is not in colortable
    //! or does not define a color
    Standard_Boolean XXCAFDoc_ColorTool::GetColor(XTDF_Label^ lab, XQuantity_ColorRGBA^% col) {
        Quantity_ColorRGBA* temp = col->GetColorRGBA();
        Standard_Boolean Result = NativeHandle()->GetColor(*lab->GetLabel(), *temp);
        col = gcnew XQuantity_ColorRGBA(temp);
        return Result;
    };

    //! Finds a color definition in a colortable and returns
    //! its label if found
    //! Returns False if color is not found in colortable
    Standard_Boolean XXCAFDoc_ColorTool::FindColor(XQuantity_Color^ col, XTDF_Label^% lab) {
        TDF_Label* temp = lab->GetLabel();
        Standard_Boolean Result = NativeHandle()->FindColor(*col->GetColor(), *temp);
        lab = gcnew XTDF_Label(temp);
        return Result;
    };

    //! Finds a color definition in a colortable and returns
    //! its label if found
    //! Returns False if color is not found in colortable
    Standard_Boolean XXCAFDoc_ColorTool::FindColor(XQuantity_ColorRGBA^ col, XTDF_Label^% lab) {
        TDF_Label* temp = lab->GetLabel();
        Standard_Boolean Result = NativeHandle()->FindColor(*col->GetColorRGBA(), *temp);
        lab = gcnew XTDF_Label(temp);
        return Result;
    };

    //! Finds a color definition in a colortable and returns
    //! its label if found (or Null label else)
    XTDF_Label^ XXCAFDoc_ColorTool::FindColor(XQuantity_Color^ col) {
        TDF_Label temp = NativeHandle()->FindColor(*col->GetColor());
        return gcnew XTDF_Label(temp);
    };

    //! Finds a color definition in a colortable and returns
    //! its label if found (or Null label else)
    XTDF_Label^ XXCAFDoc_ColorTool::FindColor(XQuantity_ColorRGBA^ col) {
        TDF_Label temp = NativeHandle()->FindColor(*col->GetColorRGBA());
        return gcnew XTDF_Label(temp);
    };

    //! Adds a color definition to a colortable and returns
    //! its label (returns existing label if the same color
    //! is already defined)
    XTDF_Label^ XXCAFDoc_ColorTool::AddColor(XQuantity_Color^ col) {
        TDF_Label temp = NativeHandle()->AddColor(*col->GetColor());
        return gcnew XTDF_Label(temp);
    };

    //! Adds a color definition to a colortable and returns
    //! its label (returns existing label if the same color
    //! is already defined)
    XTDF_Label^ XXCAFDoc_ColorTool::AddColor(XQuantity_ColorRGBA^ col) {
        TDF_Label temp = NativeHandle()->AddColor(*col->GetColorRGBA());
        return gcnew XTDF_Label(temp);
    };

    //! Removes color from the colortable
    void XXCAFDoc_ColorTool::RemoveColor(XTDF_Label^ lab) {
        NativeHandle()->RemoveColor(*lab->GetLabel());
    };

    //! Returns a sequence of colors currently stored
    //! in the colortable
    void XXCAFDoc_ColorTool::GetColors(XTDF_LabelSequence^% Labels) {
        TDF_LabelSequence temp;
        NativeHandle()->GetColors(temp);
        Labels = gcnew XTDF_LabelSequence(temp);
    };

    //! Sets a link with GUID defined by <type> (see
    //! XCAFDoc::ColorRefGUID()) from label <L> to color
    //! defined by <colorL>. Color of shape is defined following way
    //! in dependance with type of color.
    //! If type of color is XCAFDoc_ColorGen - then this color
    //! defines default color for surfaces and curves.
    //! If for shape color with types XCAFDoc_ColorSurf or XCAFDoc_ColorCurv is specified
    //! then such color overrides generic color.
    void XXCAFDoc_ColorTool::SetColor(XTDF_Label^ L, XTDF_Label^ colorL, XXCAFDoc_ColorType type) {
        NativeHandle()->SetColor(*L->GetLabel(), *colorL->GetLabel(), safe_cast<XCAFDoc_ColorType>(type));
    };

    //! Sets a link with GUID defined by <type> (see
    //! XCAFDoc::ColorRefGUID()) from label <L> to color <Color>
    //! in the colortable
    //! Adds a color as necessary
    void XXCAFDoc_ColorTool::SetColor(XTDF_Label^ L, XQuantity_Color^ Color, XXCAFDoc_ColorType type) {
        NativeHandle()->SetColor(*L->GetLabel(), *Color->GetColor(), safe_cast<XCAFDoc_ColorType>(type));
    };

    //! Sets a link with GUID defined by <type> (see
    //! XCAFDoc::ColorRefGUID()) from label <L> to color <Color>
    //! in the colortable
    //! Adds a color as necessary
    void XXCAFDoc_ColorTool::SetColor(XTDF_Label^ L, XQuantity_ColorRGBA^ Color, XXCAFDoc_ColorType type) {
        NativeHandle()->SetColor(*L->GetLabel(), *Color->GetColorRGBA(), safe_cast<XCAFDoc_ColorType>(type));
    };

    //! Removes a link with GUID defined by <type> (see
    //! XCAFDoc::ColorRefGUID()) from label <L> to color
    void XXCAFDoc_ColorTool::UnSetColor(XTDF_Label^ L, XXCAFDoc_ColorType type) {
        NativeHandle()->UnSetColor(*L->GetLabel(), safe_cast<XCAFDoc_ColorType>(type));
    };

    //! Returns True if label <L> has a color assignment
    //! of the type <type>
    Standard_Boolean XXCAFDoc_ColorTool::IsSet(XTDF_Label^ L, XXCAFDoc_ColorType type) {
        return  NativeHandle()->IsSet(*L->GetLabel(), safe_cast<XCAFDoc_ColorType>(type));
    };

    //! Returns label with color assigned to <L> as <type>
    //! Returns False if no such color is assigned
    //! static
    Standard_Boolean XXCAFDoc_ColorTool::GetColor(XTDF_Label^ L, XXCAFDoc_ColorType type, XTDF_Label^% colorL) {
        TDF_Label* temp = colorL->GetLabel();
        Standard_Boolean Result = XCAFDoc_ColorTool::GetColor(*L->GetLabel(), safe_cast<XCAFDoc_ColorType>(type), *temp);
        colorL = gcnew XTDF_Label(temp);
        return Result;
    };

    //! Returns color assigned to <L> as <type>
    //! Returns False if no such color is assigned
    Standard_Boolean XXCAFDoc_ColorTool::GetColor(XTDF_Label^ L, XXCAFDoc_ColorType type, XQuantity_Color^% color) {
        Quantity_Color* temp = color->GetColor();
        Standard_Boolean Result = NativeHandle()->GetColor(*L->GetLabel(), safe_cast<XCAFDoc_ColorType>(type), *temp);
        color = gcnew XQuantity_Color(temp);
        return Result;
    };

    //! Returns color assigned to <L> as <type>
    //! Returns False if no such color is assigned
    Standard_Boolean XXCAFDoc_ColorTool::GetColor(XTDF_Label^ L, XXCAFDoc_ColorType type, XQuantity_ColorRGBA^% color) {
        Quantity_ColorRGBA* temp = color->GetColorRGBA();
        Standard_Boolean Result = NativeHandle()->GetColor(*L->GetLabel(), safe_cast<XCAFDoc_ColorType>(type), *temp);
        color = gcnew XQuantity_ColorRGBA(temp);
        return Result;
    };

    //! Sets a link with GUID defined by <type> (see
    //! XCAFDoc::ColorRefGUID()) from label <L> to color
    //! defined by <colorL>
    //! Returns False if cannot find a label for shape S
    Standard_Boolean XXCAFDoc_ColorTool::SetColor(XTopoDS_Shape^ S, XTDF_Label^% colorL, XXCAFDoc_ColorType type) {
        TDF_Label* temp = colorL->GetLabel();
        Standard_Boolean Result = NativeHandle()->SetColor(*S->GetShape(), *temp, safe_cast<XCAFDoc_ColorType>(type));
        colorL = gcnew XTDF_Label(temp);
        return Result;
    };

    //! Sets a link with GUID defined by <type> (see
    //! XCAFDoc::ColorRefGUID()) from label <L> to color <Color>
    //! in the colortable
    //! Adds a color as necessary
    //! Returns False if cannot find a label for shape S
    Standard_Boolean XXCAFDoc_ColorTool::SetColor(XTopoDS_Shape^ S, XQuantity_Color^ Color, XXCAFDoc_ColorType type) {
        Quantity_Color* temp = Color->GetColor();
        Standard_Boolean Result = NativeHandle()->SetColor(*S->GetShape(), *temp, safe_cast<XCAFDoc_ColorType>(type));
        Color = gcnew XQuantity_Color(temp);
        return Result;
    };

    //! Sets a link with GUID defined by <type> (see
    //! XCAFDoc::ColorRefGUID()) from label <L> to color <Color>
    //! in the colortable
    //! Adds a color as necessary
    //! Returns False if cannot find a label for shape S
    Standard_Boolean XXCAFDoc_ColorTool::SetColor(XTopoDS_Shape^ S, XQuantity_ColorRGBA^ Color, XXCAFDoc_ColorType type) {
        Quantity_ColorRGBA* temp = Color->GetColorRGBA();
        Standard_Boolean Result = NativeHandle()->SetColor(*S->GetShape(), *temp, safe_cast<XCAFDoc_ColorType>(type));
        Color = gcnew XQuantity_ColorRGBA(temp);
        return Result;
    };

    //! Removes a link with GUID defined by <type> (see
    //! XCAFDoc::ColorRefGUID()) from label <L> to color
    //! Returns True if such link existed
    Standard_Boolean XXCAFDoc_ColorTool::UnSetColor(XTopoDS_Shape^ S, XXCAFDoc_ColorType type) {
        Standard_Boolean Result = NativeHandle()->UnSetColor(*S->GetShape(), safe_cast<XCAFDoc_ColorType>(type));
        return Result;
    };

    //! Returns True if label <L> has a color assignment
    //! of the type <type>
    Standard_Boolean XXCAFDoc_ColorTool::IsSet(XTopoDS_Shape^ S, XXCAFDoc_ColorType type) {
        Standard_Boolean Result = NativeHandle()->IsSet(*S->GetShape(), safe_cast<XCAFDoc_ColorType>(type));
        return Result;
    };

    //! Returns label with color assigned to <L> as <type>
    //! Returns False if no such color is assigned
    Standard_Boolean XXCAFDoc_ColorTool::GetColor(XTopoDS_Shape^ S, XXCAFDoc_ColorType type, XTDF_Label^% colorL) {
        TDF_Label* temp = colorL->GetLabel();
        Standard_Boolean Result = NativeHandle()->GetColor(*S->GetShape(), safe_cast<XCAFDoc_ColorType>(type), *temp);
        colorL = gcnew XTDF_Label(temp);
        return Result;
    };

    //! Returns color assigned to <L> as <type>
    //! Returns False if no such color is assigned
    Standard_Boolean XXCAFDoc_ColorTool::GetColor(XTopoDS_Shape^ S, XXCAFDoc_ColorType type, XQuantity_Color^% color) {
        Quantity_Color* temp = color->GetColor();
        Standard_Boolean Result = NativeHandle()->GetColor(*S->GetShape(), safe_cast<XCAFDoc_ColorType>(type), *temp);
        color = gcnew XQuantity_Color(temp);
        return Result;
    };

    //! Returns color assigned to <L> as <type>
    //! Returns False if no such color is assigned
    Standard_Boolean XXCAFDoc_ColorTool::GetColor(XTopoDS_Shape^ S, XXCAFDoc_ColorType type, XQuantity_ColorRGBA^% color) {
        Quantity_ColorRGBA* temp = color->GetColorRGBA();
        Standard_Boolean Result = NativeHandle()->GetColor(*S->GetShape(), safe_cast<XCAFDoc_ColorType>(type), *temp);
        color = gcnew XQuantity_ColorRGBA(temp);
        return Result;
    };

    //! Return TRUE if object on this label is visible, FALSE if invisible.
    Standard_Boolean XXCAFDoc_ColorTool::IsVisible(XTDF_Label^ L) {
        return NativeHandle()->IsVisible(*L->GetLabel());
    };

    //! Set the visibility of object on label. Do nothing if there no any object.
    //! Set UAttribute with corresponding GUID.
    //! Standard_Boolean isvisible = Standard_True
    void XXCAFDoc_ColorTool::SetVisibility(XTDF_Label^ shapeLabel, Standard_Boolean isvisible) {
        NativeHandle()->SetVisibility(*shapeLabel->GetLabel(), isvisible);
    };

    //! Return TRUE if object color defined by its Layer, FALSE if not.
    Standard_Boolean XXCAFDoc_ColorTool::IsColorByLayer(XTDF_Label^ L) {
        return NativeHandle()->IsColorByLayer(*L->GetLabel());
    };

    //! Set the Color defined by Layer flag on label. Do nothing if there no any object.
    //! Set UAttribute with corresponding GUID.
    //! Standard_Boolean isColorByLayer = Standard_False
    void XXCAFDoc_ColorTool::SetColorByLayer(XTDF_Label^ shapeLabel, Standard_Boolean isColorByLayer) {
        NativeHandle()->SetColorByLayer(*shapeLabel->GetLabel(), isColorByLayer);
    };

    //! Sets the color of component that styled with SHUO structure
    //! Returns FALSE if no sush component found
    //! NOTE: create SHUO structeure if it is necessary and if <isCreateSHUO>
    //! Standard_Boolean isCreateSHUO = Standard_True
    Standard_Boolean XXCAFDoc_ColorTool::SetInstanceColor(XTopoDS_Shape^ theShape, XXCAFDoc_ColorType type, XQuantity_Color^ color, Standard_Boolean isCreateSHUO) {
        return NativeHandle()->SetInstanceColor(*theShape->GetShape(), safe_cast<XCAFDoc_ColorType>(type), *color->GetColor(), isCreateSHUO);
    };

    //! Sets the color of component that styled with SHUO structure
    //! Returns FALSE if no sush component found
    //! NOTE: create SHUO structeure if it is necessary and if <isCreateSHUO>
    //! Standard_Boolean isCreateSHUO = Standard_True
    Standard_Boolean XXCAFDoc_ColorTool::SetInstanceColor(XTopoDS_Shape^ theShape, XXCAFDoc_ColorType type, XQuantity_ColorRGBA^ color, Standard_Boolean isCreateSHUO) {
        return NativeHandle()->SetInstanceColor(*theShape->GetShape(), safe_cast<XCAFDoc_ColorType>(type), *color->GetColorRGBA(), isCreateSHUO);
    };

    //! Gets the color of component that styled with SHUO structure
    //! Returns FALSE if no sush component or color type
    Standard_Boolean XXCAFDoc_ColorTool::GetInstanceColor(XTopoDS_Shape^ theShape, XXCAFDoc_ColorType type, XQuantity_Color^% color) {
        Quantity_Color* temp = color->GetColor();
        Standard_Boolean Result = NativeHandle()->GetInstanceColor(*theShape->GetShape(), safe_cast<XCAFDoc_ColorType>(type), *temp);
        color = gcnew XQuantity_Color(temp);
        return Result;
    };

    //! Gets the color of component that styled with SHUO structure
    //! Returns FALSE if no sush component or color type
    Standard_Boolean XXCAFDoc_ColorTool::GetInstanceColor(XTopoDS_Shape^ theShape, XXCAFDoc_ColorType type, XQuantity_ColorRGBA^% color) {
        Quantity_ColorRGBA* temp = color->GetColorRGBA();
        Standard_Boolean Result = NativeHandle()->GetInstanceColor(*theShape->GetShape(), safe_cast<XCAFDoc_ColorType>(type), *temp);
        color = gcnew XQuantity_ColorRGBA(temp);
        return Result;
    };

    //! Gets the visibility status of component that styled with SHUO structure
    //! Returns FALSE if no sush component
    Standard_Boolean XXCAFDoc_ColorTool::IsInstanceVisible(XTopoDS_Shape^ theShape) {
        return NativeHandle()->IsInstanceVisible(*theShape->GetShape());
    };

    //! Reverses order in chains of TreeNodes (from Last to First) under
    //! each Color Label since we became to use function ::Prepend()
    //! instead of ::Append() in method SetColor() for acceleration
    Standard_Boolean XXCAFDoc_ColorTool::ReverseChainsOfTreeNodes() {
        return NativeHandle()->ReverseChainsOfTreeNodes();
    };

    XStandard_GUID^ XXCAFDoc_ColorTool::ID() {
        return gcnew XStandard_GUID(NativeHandle()->ID());
    };

    void XXCAFDoc_ColorTool::Restore(XTDF_Attribute^ with) {
        NativeHandle()->Restore(with->GetAttribute());
    };

    XTDF_Attribute^ XXCAFDoc_ColorTool::NewEmpty() {
        return gcnew  XTDF_Attribute(NativeHandle()->NewEmpty());
    };

    void XXCAFDoc_ColorTool::Paste(XTDF_Attribute^ into, Handle(TDF_RelocationTable)& RT) {
        NativeHandle()->Paste(into->GetAttribute(), RT);
    };
}