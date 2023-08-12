/*
 * Copyright (c) 2023, the SerenityOS developers.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibWeb/Layout/ButtonFormattingContext.h>
#include <LibWeb/Layout/TextNode.h>

namespace Web::Layout {

ButtonFormattingContext::ButtonFormattingContext(LayoutState& state, BlockContainer const& root, FormattingContext* parent)
    : BlockFormattingContext(state, root, parent)
{
}

ButtonFormattingContext::~ButtonFormattingContext() = default;

void ButtonFormattingContext::run(Box const& box, LayoutMode layout_mode, AvailableSpace const& available_space)
{
    BlockFormattingContext::run(box, layout_mode, available_space);
    auto& box_state = m_state.get_mutable(box);
    [[maybe_unused]] auto specified_height = box.computed_values().height().to_px(box, box_state.content_height());
    CSSPixels content_height = 0;
    for (auto* child = box.first_child(); child; child = child->next_sibling()) {
        if (is<TextNode>(*child)) {
            content_height = max(content_height, child->line_height());
        } else if (child->is_box()) {
            content_height = max(content_height, calculate_min_content_height(static_cast<Box const&>(*child), available_space.width));
        }
    }
    auto offsets = box_state.border_top + box_state.border_bottom + box_state.padding_top + box_state.padding_bottom;
    auto height_diff = max(specified_height - content_height - offsets, 0);
    box_state.padding_top += height_diff / 2;
    box_state.padding_bottom += height_diff / 2;
    box_state.set_content_height(content_height);
}

}
