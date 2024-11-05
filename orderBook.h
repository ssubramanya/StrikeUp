# include "commonIncludes.h"
# include "orders.h"

class OrderBook {

    struct OrderEntry
    {
        Order* c_order;
        OrderPointers::iterator c_orderIterator;
    };

    private:
        std::map<double, OrderPointers, std::greater<Price>> c_bidsMap; // key - price
        std::map<double, OrderPointers, std::less<Price>> c_asksMap; // key - price
        std::unordered_map<uint64, OrderEntry> c_orderIdToOrderMap;
        std::unordered_map<double, LevelInfo> c_priceToLevelMap;

        }
    public:
        OrderBook();
        void addOrder(Order* order);
        void modifyOrder(uint64_t orderId, uint64_t newQuantity);
        void deleteOrder(uint64_t orderId);
        void printOrderBook();
        bool CanMatch(e_side side, uint64_t price);
};