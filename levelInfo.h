#pragma once

#include "commonIncludes.h"

struct levelInfo {
    uint32_t c_price;
    uint32_t c_quantity;
};

using levelInfos = std::vector<levelInfo>;