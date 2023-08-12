/*
 * Copyright (c) 2023, the SerenityOS developers.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibWeb/Forward.h>
#include <LibWeb/Layout/BlockContainer.h>

namespace Web::Layout {

class ButtonBlockContainer final : public BlockContainer {
    JS_CELL(ButtonBlockContainer, BlockContainer);

public:
    ButtonBlockContainer(DOM::Document&, DOM::Node*, NonnullRefPtr<CSS::StyleProperties>);
    ButtonBlockContainer(DOM::Document&, DOM::Node*, CSS::ComputedValues);

    virtual ~ButtonBlockContainer() override;
};

}
