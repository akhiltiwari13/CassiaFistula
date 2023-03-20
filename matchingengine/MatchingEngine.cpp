#include <iostream>
#include <array>
using namespace std;

enum class Ticker { XYZ, ABC };
constexpr size_t TotalTickers = 2;

/* class OrderBook{ */
/*     public: */

/*     private: */

/* }; */

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
        } else if (order.side == 'S') {
            sellOrders[order.price].push_back(order);
        }
    }

private:
    std::map<double, std::vector<Order>> buyOrders;
    std::map<double, std::vector<Order>> sellOrders;
};


class OrderBook {
public:
    std::vector<Order> matchOrders(const Order& order) {
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


/* class MatchingEngine{ */
/*     array< OrderBook*, TotalTickers > _the_market; */

/* }; */


int main(int argc, char *argv[]) {
  std::cout << "matching_engine" << std::endl;



  return 0;
}
