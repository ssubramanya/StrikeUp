#include "orderBook.h"
#include "Trade.h"

OrderBook::OrderBook() {
    c_orderId = 0;
}

bool OrderBook::CanMatch(e_side side, uint64_t price) {
    if (side == Buy) {
        return !c_asksMap.empty() && c_asksMap.begin()->first <= price;
    } else {
        return !c_bidsMap.empty() && c_bidsMap.begin()->first >= price;
    }   
}

Trades MatchOrders() {
    Trades trades;

    while(true) {
        if(c_bidsMap.empty() || c_asksMap.empty()) {
            break;
        }
        auto& [bidPrice, bidOrders] = c_bidsMap.begin();
        auto& [askPrice, askOrders] = c_asksMap.begin();

        if(bidPrice < askPrice) {
            break;
        }

        while(!bidOrders.empty() && !askOrders.empty()) {
            auto& bid = bidOrders.front();
            auto& ask = askOrders.front();

            uint64_t tradeQuantity = std::min(bid->remainingQuantity(), ask->remainingQuantity());

            bid->Fill(tradeQuantity);
            ask->Fill(tradeQuantity);

            if(bid->remainingQuantity() == 0) {
                c_orderIdToOrderMap.erase(bid->orderId());
                bidOrders.pop_front();
            }

            if(ask->remainingQuantity() == 0) {
                c_orderIdToOrderMap.erase(ask->orderId());
                askOrders.pop_front();
            }

            if(bid.empty()) {
                c_bidsMap.erase(bidPrice);
            }
            if(ask.empty()) {
                c_asksMap.erase(askPrice);
            }
        }
    }

    if(!c_bidsMap.empty()) {
        auto& order = c_bidsMap.begin()->second.front();
        if(order->GetOrderType() == e_orderType::FillAndKill) {
            cancelOrder(order->orderId());
        }
    }
    if(!c_asksMap.empty()) {
        auto& order = c_asksMap.begin()->second.front();
        if(order->GetOrderType() == e_orderType::FillAndKill) {
            cancelOrder(order->orderId());
        }
    }
    
    return trades;
}

Trades AddOrder(Order* order) {
    if(c_orderIdToOrderMap.find(order->orderId()) != c_orderIdToOrderMap.end()) {
        std::cout << "Error: Order with orderId " << order->orderId() << " already exists" << std::endl;
        return Trades();
    }

    if(order->OrderType() == e_orderType::FillAndKill && !CanMatch(order->side(), order->price())) {
        std::cout << "Info: FillAndKill cannot be executed" << std::endl;
        return Trades();
    }

    OrderPointers::iterator orderIterator;
    if(order->e_side() == Buy) {
        auto &orders = c_bidsMap[order->price()];
        orders.push_back(order);
        orderIterator = std::prev(orders.end());
    } else {
        auto &orders = c_asksMap[order->price()];
        orders.push_back(order);
        orderIterator = std::prev(orders.end());        
    }

    c_orderIdToOrderMap.emplace(order->orderId(), OrderEntry{order, orderIterator}); 
    return MatchOrders();
}

void CancelOrder(uint64_t orderId) {
    if(c_orderIdToOrderMap.find(orderId) == c_orderIdToOrderMap.end()) {
        std::cout << "Error: Order with orderId " << orderId << " does not exist" << std::endl;
        return;
    }

    auto& [order, orderIterator] = c_orderIdToOrderMap[orderId];
    
    if(order->side() == Buy) {
        auto& bid = c_bidsMap[order->price()];
        bid.erase(orderIterator);
        if(bid.empty()) {
            c_bidsMap.erase(order->price());
        }
    } else {
        auto& ask = c_asksMap[order->price()]
        ask.erase(orderIterator);
        if(ask.empty()) {
            c_asksMap.erase(order->price());
        }
    }

    c_orderIdToOrderMap.erase(orderId);
}