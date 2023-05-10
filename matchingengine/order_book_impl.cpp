#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

struct Order {
    int id;
    char side;
    double price;
    int quantity;
    time_t timestamp;
};

class OrderBook {
public:
    void addOrder(const Order& order) {
        if (order.side == 'B') {
            buyOrders[order.price].push_back(order);
            std::sort(buyOrders[order.price].begin(), buyOrders[order.price].end(),
                      [](const Order& a, const Order& b) { return a.timestamp < b.timestamp; });
        } else if (order.side == 'S') {
            sellOrders[order.price].push_back(order);
            std::sort(sellOrders[order.price].begin(), sellOrders[order.price].end(),
                      [](const Order& a, const Order& b) { return a.timestamp < b.timestamp; });
        }
    }

    std::vector<Order> matchOrders(Order& order) {
        std::vector<Order> matchedOrders;

        if (order.side == 'B') {
            auto it = sellOrders.begin();
            while (it != sellOrders.end() && it->first <= order.price) {
                auto& orders = it->second;
                for (auto it2 = orders.begin(); it2 != orders.end(); ) {
                    if (it2->quantity <= order.quantity) {
                        matchedOrders.push_back(*it2);
                        order.quantity -= it2->quantity;
                        it2 = orders.erase(it2);
                    } else {
                    matchedOrders.push_back({ it2->id, it2->side, it2->price, order.quantity, it2->timestamp });
                    it2->quantity -= order.quantity;
                        order.quantity = 0;
                        break;
                    }
                }
                if (orders.empty()) {
                    it = sellOrders.erase(it);
                } else {
                    ++it;
                }
                if (order.quantity == 0) {
                    break;
                }
            }
        } else if (order.side == 'S') {
            auto it = buyOrders.rbegin();
            while (it != buyOrders.rend() && it->first >= order.price) {
                auto& orders = it->second;
                for (auto it2 = orders.begin(); it2 != orders.end(); ) {
                    if (it2->quantity <= order.quantity) {
                        matchedOrders.push_back(*it2);
                        order.quantity -= it2->quantity;
                        it2 = orders.erase(it2);
                    } else {
                        matchedOrders.push_back({ it2->id, it2->side, it2->price, order.quantity, it2->timestamp });
                        it2->quantity -= order.quantity;
                        order.quantity = 0;
                        break;
                    }
                }
                if (orders.empty()) {
                    it = decltype(it){};
                } else {
                    ++it;
                }
                if (order.quantity == 0) {
                    break;
                }
            }
        }

        return matchedOrders;
    }

    auto getBuyOrders(){
        return buyOrders;
    }

    auto getSellOrders(){
        return sellOrders;
    }

private:
    std::map<double, std::vector<Order>> buyOrders;
    std::map<double, std::vector<Order>> sellOrders;
};

/* int main() { */
/*     OrderBook book; */

/*     // add some orders to the book */
/*     book.addOrder({ 1, 'B', 100.0, 10, time(nullptr) }); */
/*     book.addOrder({ 2, 'S', 101.0, 5, time(nullptr */


int main() {
    OrderBook book;

    // add some orders to the book
    book.addOrder({ 1, 'B', 100.0, 10, time(nullptr) });
    book.addOrder({ 2, 'S', 101.0, 5, time(nullptr) });
    book.addOrder({ 3, 'S', 102.0, 10, time(nullptr) });
    book.addOrder({ 4, 'B', 99.0, 3, time(nullptr) });

    // add a new order to the book
    Order newOrder = { 5, 'B', 101.0, 6, time(nullptr) };
    std::vector<Order> matchedOrders = book.matchOrders(newOrder);
    book.addOrder(newOrder);

    // print out the matched orders and the updated order book
    std::cout << "Matched orders:\n";
    for (const auto& order : matchedOrders) {
        std::cout << "id: " << order.id << ", side: " << order.side << ", price: " << order.price << ", quantity: " << order.quantity << "\n";
    }
    std::cout << "Order book:\n";
    for (const auto& pair : book.getBuyOrders()) {
        std::cout << "Buy order at price " << pair.first << ":\n";
        for (const auto& order : pair.second) {
            std::cout << "id: " << order.id << ", side: " << order.side << ", price: " << order.price << ", quantity: " << order.quantity << "\n";
        }
    }
    for (const auto& pair : book.getSellOrders()) {
        std::cout << "Sell order at price " << pair.first << ":\n";
        for (const auto& order : pair.second) {
            std::cout << "id: " << order.id << ", side: " << order.side << ", price: " << order.price << ", quantity: " << order.quantity << "\n";
        }
    }

    return 0;
}

