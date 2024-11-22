#include <served/served.hpp>
#include <served/plugins.hpp>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include "orderBook.h"  // Include your project headers
#include "orders.h"
#include "commonIncludes.h"
#include <iomanip>
using namespace std;

// Deserialize the incoming JSON request to Order
void deserializeOrderFromJson(const std::string& json_data, Order* order) 
{
    size_t json_start = json_data.find("{");
    size_t json_end = json_data.rfind("}");

    if (json_start == std::string::npos || json_end == std::string::npos) {
        throw std::runtime_error("Invalid JSON: JSON data not found.");
    }

    // Extract the JSON substring
    std::string jsonData = json_data.substr(json_start, json_end - json_start + 1);
    
    std::cout << "Parsing JSON: " << jsonData << std::endl;    
    rapidjson::Document doc;
    if (doc.Parse(jsonData.c_str()).HasParseError()) {
        throw std::runtime_error("Invalid JSON");
    }

    cout<<"2";
    // Map JSON fields to Protobuf fields
    order->c_orderId = (doc["orderId"].GetUint64());
    cout<<order->c_orderId<<" ";
/*    order->setOrderType(doc["orderType"].GetInt());
    order->setSide((doc["side"].GetInt()));*/
    order->setOrderType(static_cast<e_orderType>(doc["orderType"].GetInt()));
    cout<<order->c_orderType<<" ";
order->setSide(static_cast<e_side>(doc["side"].GetInt()));
    order->c_price = (doc["price"].GetDouble());
    order->c_initialQuantity = (doc["Quantity"].GetUint64());
//    order->c_timestamp = (doc["remainingQuantity"].GetUint64());
}

/*
// Function to serialize Trades to Protobuf binary format
void serializeTradesToProtobuf(const Trades& trades, std::string& output) {
    Trades tradesProto;
    
    for (const auto& trade : trades) {
        Trade* protoTrade = tradesProto.add_trades();
        const TradeInfo& bid = trade.GetBidTrade();
        const TradeInfo& ask = trade.GetAskTrade();

        // Set bid trade info
        TradeInfo* protoBidTrade = protoTrade->mutable_bidtrade();
        protoBidTrade->set_price(bid.price_);
        protoBidTrade->set_quantity(bid.quantity_);
        protoBidTrade->set_orderid(bid.orderId_);

        // Set ask trade info
        TradeInfo* protoAskTrade = protoTrade->mutable_asktrade();
        protoAskTrade->set_price(ask.price_);
        protoAskTrade->set_quantity(ask.quantity_);
        protoAskTrade->set_orderid(ask.orderId_);
    }

    tradesProto.SerializeToString(&output);
}

// Function to deserialize Protobuf binary data to Trades
bool deserializeTradesFromProtobuf(const std::string& input, Trades& trades) {
    Trades tradesProto;
    if (tradesProto.ParseFromString(input)) {
        for (int i = 0; i < tradesProto.trades_size(); ++i) {
            const Trade& protoTrade = tradesProto.trades(i);
            TradeInfo bid = {protoTrade.bidtrade().price(), protoTrade.bidtrade().quantity(), protoTrade.bidtrade().orderid()};
            TradeInfo ask = {protoTrade.asktrade().price(), protoTrade.asktrade().quantity(), protoTrade.asktrade().orderid()};

            trades.push_back(Trade(bid, ask));
        }
        return true;
    }
    return false;
}
*/

// Start the REST server
void start_rest_server(OrderBook& ob) {
/*    served::multiplexer mux;

    mux.handle("/process_order").post([&ob](served::response& res, const served::request& req) {
        // Deserialize incoming JSON data to Protobuf Order
        Order* incomingOrder = new Order();
        try {
            deserializeOrderFromJson(req.body(), incomingOrder);
        } catch (const std::exception& e) {
            res.set_status(400);
            res << "Error: " << e.what();
            return;
        }

        // Process the order using your existing logic (ob.AddOrder)
        Trades processedTrades = ob.AddOrder(incomingOrder);  // Assuming AddOrder returns Trades

        // Serialize the response into Protobuf format
        std::string output;
        processedTrades.SerializeToString(&output);
        //serializeTradesToProtobuf(processedTrades, output);

        // Send the Protobuf response
        res.set_status(200);
        res.set_header("Content-Type", "application/x-protobuf");
        //res.write(output);
    });

    // Start the server
    served::net::server server("127.0.0.1", "8080", mux);
    server.run(1);  // Run with 10 worker threads
    */
    boost::asio::io_service io_service;
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 8080);
    boost::asio::ip::tcp::acceptor acceptor(io_service, endpoint);
    
    while (true) {
        boost::asio::ip::tcp::socket socket(io_service);
        acceptor.accept(socket);

        // Read the incoming request
        std::string request_data;
        boost::asio::read_until(socket, boost::asio::dynamic_buffer(request_data), "\r\n");

        // Deserialize, process, and respond
        Order* incomingOrder = new Order();
        cout<<"0"<<endl;
        try {
            deserializeOrderFromJson(request_data, incomingOrder);
            Trades processedTrades = ob.AddOrder(incomingOrder);

            // Send response (serialized as Protobuf)
            std::string response_data;
            processedTrades.SerializeToString(&response_data);

            boost::asio::write(socket, boost::asio::buffer(response_data));
        } catch (const std::exception& e) {
            // Error handling
            cout<<"5"<<endl;
            std::string error_message = "Error: " + std::string(e.what());
            cout<<error_message;
            boost::asio::write(socket, boost::asio::buffer(error_message));
        }
    }

}

int main() {
    // Initialize your OrderBook and start the REST server
    OrderBook ob;
    start_rest_server(ob);
    return 0;
}
/*


void DisplayAsTable(OrderBook& ob) 
{
    // Print Header
    std::cout << std::setw(10) << "Quantity" << std::setw(10) << "Bid"
              << std::setw(10) << "Ask" << std::setw(10) << "Quantity" << std::endl;

    std::map<double, uint64_t>::iterator itr;
    // Print rows
    itr = ob.c_bidsPriceToQtyMap.begin();
    auto itr1 = ob.c_asksPriceToQtyMap.begin();
    while(itr != ob.c_bidsPriceToQtyMap.end())
    {
        uint64_t bSize = itr->second;
        double bid = itr->first;
        double ask = itr1->first;
        uint64_t aSize = itr1->second;

        std::cout << std::setw(10) << bSize
                  << std::setw(10) << bid
                  << std::setw(10) << ask
                  << std::setw(10) << aSize << std::endl;

        itr++;
        itr1++;
    }
}

void DisplayTrade(Trades& t)
{
    if(t.size() == 0)
        cout<<"No Trade Executed"<<endl;
	for(auto itr : t)
	{
		cout<<"Buy trade done for order id : " << itr.bidTrade_.orderId_<<",  # of orders : "<< itr.bidTrade_.quantity_<< ",  Price : "<<itr.bidTrade_.price_<<endl;
		cout<<"Ask trade done for order id : "<< itr.askTrade_.orderId_<<", # of orders : "<<itr.askTrade_.quantity_<<", Price : "<<itr.askTrade_.price_<<endl;
		cout<<endl<<endl;
	}
}
int main()
{
	Order* o;
	Order* o1;
	OrderBook ob;
    o = new Order(e_orderType::GoodTillCancelled,1,e_side::Buy,100, 10);
    o1 = new Order(e_orderType::GoodTillCancelled,2,e_side::Sell,101, 20);
	Trades t = ob.AddOrder(o);
	t = ob.AddOrder(o1);
    DisplayTrade(t);
//	OrderBookLevelInfo obli = ob.GetOrderInfos();
    //DisplayAsTable(ob);
    o = new Order(e_orderType::GoodTillCancelled,3,e_side::Buy,100.5,20);
    o1 = new Order(e_orderType::GoodTillCancelled,4,e_side::Sell,100.8,30);
	t = ob.AddOrder(o);
	t = ob.AddOrder(o1);
    DisplayTrade(t);
    DisplayAsTable(ob);
	return 0;
}
*/
