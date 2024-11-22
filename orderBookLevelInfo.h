#pragma once

#include "levelInfo.h"


class OrderBookLevelInfo {
    public:
        OrderBookLevelInfo(const levelInfos bids, const levelInfos asks):c_bids(bids), c_asks(asks) {}
        const levelInfos& bids() const { return c_bids; }
        const levelInfos& asks() const { return c_asks; }
        
    private:
        levelInfos c_bids;
        levelInfos c_asks;
};
