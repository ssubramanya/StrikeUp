#pragma once

# include "commonIncludes.h"
# include "orders.h"
# include "orderBookLevelInfo.h"
# include "Proto/Trades.pb.h"

class OrderBook {

    struct OrderEntry
    {
        Order* c_order;
        std::list<Order*>::iterator c_orderIterator;
    };

    private:
        std::map<double, std::list<Order*>, std::greater<double>> c_bidsMap; // key - price
        std::map<double, std::list<Order*>, std::less<double>> c_asksMap; // key - price
        std::unordered_map<uint64_t, OrderEntry> c_orderIdToOrderMap;

    public:
        //TODO: get
        double currentRunningPrice;
        std::map<double, uint64_t, std::greater<double>> c_bidsPriceToQtyMap; //key-price, value- quantity
        std::map<double, uint64_t, std::less<double>> c_asksPriceToQtyMap; //key-price, value- quantity
        OrderBook();
        Trades AddOrder(Order* order);
        void CancelOrder(uint64_t orderId);
        //void printOrderBook();
    	bool CanMatchFully(e_side side, double price, uint64_t quantity);
     	bool CanMatch(e_side side, double price);
        void AddOrderToOrderBook(Order* order, std::list<Order*>::iterator& orderIterator);
    	Trades MatchOrders(Order* order);
        void fillTradeInfo(Trades& trades, double price, uint64_t tradeQuantity, uint64_t askOrderId, uint64_t buyOrderId);
//	    OrderBookLevelInfo GetOrderInfos();
};
