#include "TradeInfo.h"
//TODO - can we optimise by keeping price & quantity to here?
class Trade
{
    public:
    Trade(double price, uint64_t quantity, uint64_t OrderId) : price_(price), quantity_(quantity), OrderId_(OrderId) {}
private:
    double price_;
    uint64_t quantity_;
    uint64_t OrderId_;
};

using Trades = std::vector<Trade>;