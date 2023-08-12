/*
 * Copyright (c) 2023, the SerenityOS developers.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibWeb/Forward.h>
#include <LibWeb/Layout/BlockFormattingContext.h>

namespace Web::Layout {

class ButtonFormattingContext final : public BlockFormattingContext {
public:
    explicit ButtonFormattingContext(LayoutState&, BlockContainer const&, FormattingContext* parent);
    virtual ~ButtonFormattingContext() override;

    virtual void run(Box const&, LayoutMode, AvailableSpace const&) override;
};

}
