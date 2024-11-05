#pragma once

#include "commonIncludes.h"

struct LevelInfo {
    uint32_t c_price;
    uint32_t c_quantity;
};

using levelInfos = std::vector<LevelInfo>;