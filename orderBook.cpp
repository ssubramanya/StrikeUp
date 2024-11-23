#include "orderBook.h"

OrderBook::OrderBook() {
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
        auto itr = c_asksPriceToQtyMap.begin();
        while(itr != c_asksPriceToQtyMap.end() && itr->first <= price)
        {
            if(itr->second >= quantity)
            {
                return true;
            }
            quantity -= itr->second;
            itr++;
        }
    }
    else
    {
        auto itr = c_bidsPriceToQtyMap.begin();
        while(itr != c_bidsPriceToQtyMap.end() && itr->first >= price)
        {
            if(itr->second >= quantity)
            {
                return true;
            }
            quantity -= itr->second;
            itr++;
        }
    }
    return false;
}

void OrderBook::fillTradeInfo(Trades& trades, double price, uint64_t tradeQuantity, uint64_t askOrderId, uint64_t buyOrderId)
{
    TradeInfo tradeInfo;
    tradeInfo.set_price(price);
    tradeInfo.set_quantity(tradeQuantity);
    tradeInfo.set_askorderid(askOrderId);
    tradeInfo.set_bidorderid(buyOrderId);

    TradeInfo* newTrade = trades.add_trades();
    *newTrade = tradeInfo; // Copy all fields from tradeInfo
}

Trades OrderBook::MatchOrders(Order* order) {
    Trades trades;

    while(true) {
        if(order->side() == e_side::Buy)
        {
            if(c_asksMap.empty())
                break;

            auto itr = c_asksMap.begin();
            double askPrice = itr->first;
            auto& askOrdersList = itr->second;

            if(order->price() < askPrice)
            {
                break;
            }

            while(!askOrdersList.empty() && order->remainingQuantity()>0)
            {
                auto& askOrder = askOrdersList.front();
                uint64_t tradeQuantity = std::min(order->remainingQuantity(), askOrder->remainingQuantity());
                order->Fill(tradeQuantity);
                askOrder->Fill(tradeQuantity);
                c_asksPriceToQtyMap[askPrice] -= tradeQuantity;

                if(askOrder->remainingQuantity() == 0)
                {
                    c_orderIdToOrderMap.erase(askOrder->orderId());
                    askOrdersList.pop_front();
                }
                currentRunningPrice = askPrice;
                //should we maintain this order matched to this? -- ask vatsa
                //trades.push_back(Trade{TradeInfo{askPrice, tradeQuantity, askOrder->orderId()},TradeInfo{askPrice, tradeQuantity, order->orderId()}});

                fillTradeInfo(trades,askPrice, tradeQuantity, askOrder->orderId(), order->orderId());
            }
            if(askOrdersList.empty())
            {
                c_asksMap.erase(askPrice);
            }
        }
        else
        {
            if(c_bidsMap.empty())
                break;
            auto itr = c_bidsMap.begin();
            double bidPrice = itr->first;
            auto& bidOrdersList = itr->second;

            if(order->price() > bidPrice)
            {
                break;
            }

            while(!bidOrdersList.empty() && order->remainingQuantity()>0)
            {
                auto& bidOrder = bidOrdersList.front();
                uint64_t tradeQuantity = std::min(order->remainingQuantity(), bidOrder->remainingQuantity());
                order->Fill(tradeQuantity);
                bidOrder->Fill(tradeQuantity);
                c_bidsPriceToQtyMap[bidPrice] -= tradeQuantity;

                if(bidOrder->remainingQuantity() == 0)
                {
                    c_orderIdToOrderMap.erase(bidOrder->orderId());
                    bidOrdersList.pop_front();
                }

                currentRunningPrice = bidPrice;
                //should we maintain this order matched to this? -- ask vatsa
                fillTradeInfo(trades,bidPrice, tradeQuantity, bidOrder->orderId(), order->orderId());
//                trades.push_back(Trade{TradeInfo{bidPrice, tradeQuantity, bidOrder->orderId()},TradeInfo{bidPrice, tradeQuantity, order->orderId()}});

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

void OrderBook::AddOrderToOrderBook(Order* order, std::list<Order*>::iterator& orderIterator)
{
    if(order->side() == e_side::Buy)
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

Trades OrderBook::AddOrder(Order* order)
{

    if(c_orderIdToOrderMap.find(order->orderId()) != c_orderIdToOrderMap.end()) {
        std::cout << "Error: Order with orderId " << order->orderId() << " already exists" << std::endl;
        return Trades();
    }

    if(order->orderType() == e_orderType::Market)
    {
        if(order->side() == e_side::Buy && !c_asksMap.empty())
        {
            order->setPrice(c_asksMap.rbegin()->first);
        }
        else if(order->side() == e_side::Sell && !c_bidsMap.empty())
        {
            order->setPrice(c_bidsMap.rbegin()->first);
        }
        else
        {
            std::cout << "Info: Market order cannot be executed" << std::endl;
            return Trades();
        }
    }
    if(order->orderType() == e_orderType::FillAndKill && !CanMatch(order->side(), order->price()))
    {
        std::cout << "Info: FillAndKill cannot be executed" << std::endl;
        return Trades();
    }

    if(order->orderType() == e_orderType::FillOrKill && !CanMatchFully(order->side(),order->price(), order->initialQuantity()))
    {
        std::cout << "Info: FillOrKill cannot be executed since quantity doesn match" << std::endl;
        return Trades();
    }

    Trades trades = MatchOrders(order);

    std::list<Order* >::iterator orderIterator;
    if(order->remainingQuantity() > 0 && order->orderType() != e_orderType::FillAndKill)
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

void OrderBook::CancelOrder(uint64_t orderId) {
    if(c_orderIdToOrderMap.find(orderId) == c_orderIdToOrderMap.end()) {
        std::cout << "Error: Order with orderId " << orderId << " does not exist" << std::endl;
        return;
    }

    auto orderInfo = c_orderIdToOrderMap[orderId];
    auto order = orderInfo.c_order;
    auto orderIterator = orderInfo.c_orderIterator;
    
    if(order->side() == e_side::Buy)
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
        auto& ask = c_asksMap[order->price()];
        ask.erase(orderIterator);
        if(ask.empty())
        {
            c_asksMap.erase(order->price());
        }
    }

    c_orderIdToOrderMap.erase(orderId);
}

/*	levelInfos bidInfos, askInfos;
OrderBookLevelInfo OrderBook::GetOrderInfos()
{
    bidInfos = c_bidsPriceToQtyMap;
    askInfos = c_bidsPriceToQtyMap;

levelInfos bidInfos, askInfos;
	bidInfos.reserve(orders_.size());
	askInfos.reserve(orders_.size());

	auto CreateLevelInfos = [](Price price, const OrderPointers& orders)
	{
		return LevelInfo{ price, std::accumulate(orders.begin(), orders.end(), (Quantity)0,
			[](Quantity runningSum, const OrderPointer& order)
			{ return runningSum + order->GetRemainingQuantity(); }) };
	};

	for (const auto& [price, orders] : bids_)
		bidInfos.push_back(CreateLevelInfos(price, orders));

	for (const auto& [price, orders] : asks_)
		askInfos.push_back(CreateLevelInfos(price, orders));

    bidInfos = c_bidsPriceToQtyMap;
    askInfos = c_asksPriceToQtyMap ;

}
p
        */
