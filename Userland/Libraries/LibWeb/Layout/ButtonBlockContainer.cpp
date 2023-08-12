#include "LibWeb/Layout/ButtonBlockContainer.h"

namespace Web::Layout {

ButtonBlockContainer::ButtonBlockContainer(DOM::Document& document, DOM::Node* node, NonnullRefPtr<CSS::StyleProperties> style)
    : BlockContainer(document, node, move(style))
{
}

ButtonBlockContainer::ButtonBlockContainer(DOM::Document& document, DOM::Node* node, CSS::ComputedValues computed_values)
    : BlockContainer(document, node, move(computed_values))
{
}

ButtonBlockContainer::~ButtonBlockContainer() = default;

}
