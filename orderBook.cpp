#include "orderBook.h"
#include "Trade.h"

OrderBook::OrderBook() {
    c_orderId = 0;
}

bool OrderBook::CanMatch(e_side side, double price)
{
    if (side == e_side::Buy)
    {
        return !c_asksMap.empty() && c_asksMap.begin()->first <= price;
    } else
    {
        return !c_bidsMap.empty() && c_bidsMap.begin()->first >= price;
    }   
}

bool OrderBook::CanMatchFully(e_side side, double price, uint64_t quantity)
{
    if (side == e_side::Buy)
    {
        auto itr = c_asksMap.begin();
        while(itr != c_asksMap.end() && itr.first <= price)
        {
            if(itr.second >= quantity)
            {
                return true;
            }
            quantity -= itr.second;
            itr++;
        }
    }
    else
    {
        auto itr = c_bidsMap.begin();
        while(itr != c_bidsMap.end() && itr.first >= price)
        {
            if(itr.second >= quantity)
            {
                return true;
            }
            quantity -= itr.second;
            itr++;
        }
    }
    return false;
}

Trades MatchOrders(Order* order) {
    Trades trades;

    while(true) {
        
        if(c_bidsMap.empty() || c_asksMap.empty())
        {
            break;
        }

        if(order->side() == e_side::Buy)
        {
            auto& [askPrice, askOrdersList] = c_asksMap.begin();

            if(order->price() < askPrice)
            {
                break;
            }

            while(!askOrdersList.empty() && order->remainingQuantity()>0)
            {
                auto& askOrder = askOrders.front();
                uint64_t tradeQuantity = std::min(order->remainingQuantity(), askOrder->remainingQuantity());
                order->Fill(tradeQuantity);
                askOrder->Fill(tradeQuantity);
                c_asksPriceToQtyMap[askPrice] -= tradeQuantity;

                if(askOrder->remainingQuantity() == 0)
                {
                    c_orderIdToOrderMap.erase(askOrder->orderId());
                    askOrdersList.pop_front();
                }
                //should we maintain this order matched to this? -- ask vatsa
                trades.push_back(Trade{(askPrice, tradeQuantity, askOrder->orderId())},{(askPrice, tradeQuantity, order->orderId())});

            }
            if(askOrdersList.empty())
            {
                c_asksMap.erase(askPrice);
            }
        }
        else
        {
            auto& [bidPrice, bidOrdersList] = c_bidsMap.begin();

            if(order->price() > bidPrice)
            {
                break;
            }

            while(!bidOrdersList.empty() && order->remainingQuantity()>0)
            {
                auto& bidOrder = bidOrders.front();
                uint64_t tradeQuantity = std::min(order->remainingQuantity(), bidOrder->remainingQuantity());
                order->Fill(tradeQuantity);
                bidOrder->Fill(tradeQuantity);
                c_bidsPriceToQtyMap[bidPrice] -= tradeQuantity;

                if(bidOrder->remainingQuantity() == 0)
                {
                    c_orderIdToOrderMap.erase(bidOrder->orderId());
                    bidOrdersList.pop_front();
                }

                //should we maintain this order matched to this? -- ask vatsa
                trades.push_back(Trade{(bidPrice, tradeQuantity, bidOrder->orderId())},{(bidPrice, tradeQuantity, order->orderId())});

            }
            if(bidOrdersList.empty())
            {
                c_bidsMap.erase(bidPrice);
            }
        }

        if(order->remainingQuantity() == 0)
        {
            break;
        }
    }
    return trades;
}

void AddOrderToOrderBook(Order* order, std::list<Order*>::iterator& orderIterator)
{
    if(order->side() == Buy)
    {
        auto& orders = c_bidsMap[order->price()];
        orders.push_back(order);
        orderIterator = std::prev(orders.end());
        c_bidsPriceToQtyMap[order->price()] += order->remainingQuantity();
    }
    else
    {
        auto& orders = c_asksMap[order->price()];
        orders.push_back(order);
        orderIterator = std::prev(orders.end());
        c_asksPriceToQtyMap[order->price()] += order->remainingQuantity();
    }
}

Trades AddOrder(Order* order)
{

    if(c_orderIdToOrderMap.find(order->orderId()) != c_orderIdToOrderMap.end()) {
        std::cout << "Error: Order with orderId " << order->orderId() << " already exists" << std::endl;
        return Trades();
    }

    if(order->orderType() == e_orderType::Market)
    {
        if(order->side() == e_Side::Buy && !c_asksMap.empty())
        {
            order->price = c_asksMap.rbegin()->first;
        }
        else if(order->side() == e_Side::Asks && !c_bidsMap.empty())
        {
            order->price = c_bidsMap.rbegin()->first;
        }
        else
        {
            std::cout << "Info: Market order cannot be executed" << std::endl;
            return Trades();
        }
    }
    if(order->OrderType() == e_orderType::FillAndKill && !CanMatch(order->side(), order->price()))
    {
        std::cout << "Info: FillAndKill cannot be executed" << std::endl;
        return Trades();
    }

    if(order->orderType() == e_orderType::FillOrKill && !CanMatchFully(order->sice(),order->price()))
    {
        std::cout << "Info: FillOrKill cannot be executed since quantity doesn match" << std::endl;
        return Trades();
    }

    Trades& trades = MatchOrders(order);

        
    OrderPointers::iterator orderIterator;
    if(order->remainingQuantity > 0 && order->orderType() != e_orderType::FillAndKill)
    {
        AddOrderToOrderBook(order, orderIterator);
        c_orderIdToOrderMap.emplace(order->orderId(), OrderEntry{order, orderIterator}); 
    }
    else
    {
        delete order;
    }
    return trades;
}

void CancelOrder(uint64_t orderId) {
    if(c_orderIdToOrderMap.find(orderId) == c_orderIdToOrderMap.end()) {
        std::cout << "Error: Order with orderId " << orderId << " does not exist" << std::endl;
        return;
    }

    auto& [order, orderIterator] = c_orderIdToOrderMap[orderId];
    
    if(order->side() == Buy)
    {
        auto& bid = c_bidsMap[order->price()];
        bid.erase(orderIterator);
        if(bid.empty())
        {
            c_bidsMap.erase(order->price());
        }
    }
    else 
    {
        auto& ask = c_asksMap[order->price()]
        ask.erase(orderIterator);
        if(ask.empty())
        {
            c_asksMap.erase(order->price());
        }
    }

    c_orderIdToOrderMap.erase(orderId);
}