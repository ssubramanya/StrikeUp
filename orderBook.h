# include "commonIncludes.h"
# include "orders.h"

class OrderBook {

    struct OrderEntry
    {
        Order* c_order;
        std::list<Order*>::iterator c_orderIterator;
    };

    private:
        std::map<double, std::list<Order*>, std::greater<double>> c_bidsMap; // key - price
        std::map<double, std::list<Order*>, std::less<double>> c_asksMap; // key - price
        std::unordered_map<uint64, OrderEntry> c_orderIdToOrderMap;
        std::map<double, uint64, std::greater<double>> c_bidsPriceToQtyMap; //key-price, value- quantity
        std::map<double, uint64, std::less<double>> c_asksPriceToQtyMap; //key-price, value- quantity

    public:
        OrderBook();
        void addOrder(Order* order);
        void modifyOrder(uint64_t orderId, uint64_t newQuantity);
        void deleteOrder(uint64_t orderId);
        void printOrderBook();
        bool CanMatch(e_side side, uint64_t price);
        void AddOrderToOrderBook(Order* order, std::list<Order*>::iterator& orderIterator);

};