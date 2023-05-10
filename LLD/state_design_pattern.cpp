/** implementing a simple order state machine for managing order state */

#include <iostream>
using namespace std;


//fwd_declarations
class Order;
class OrderRoutionState;
class NerOrderState;
class ValidationState;
class ExecutionState;
class CompletionState;

// Define the abstract base class for the states
class OrderRoutingState {
    public:
        virtual void handle(Order& order) = 0;
};

// Define the concrete implementation classes for each state
class NewOrderState : public OrderRoutingState {
    public:
        void handle(Order& order) override {
            // Perform actions for a new order
            // ...
            // Transition to the next state
            order.setState(new ValidationState());
        }
};

class ValidationState : public OrderRoutingState {
    public:
        void handle(Order& order) override {
            // Perform actions for order validation
            // ...
            // Transition to the next state
            order.setState(new ExecutionState());
        }
};

class ExecutionState : public OrderRoutingState {
    public:
        void handle(Order& order) override {
            // Perform actions for order execution
            // ...
            // Transition to the next state
            order.setState(new CompletionState());
        }
};

class CompletionState : public OrderRoutingState {
    public:
        void handle(Order& order) override {
            // Perform actions for order completion
            // ...
            // No further state transitions needed
        }
};

// Define the Order class that uses the state machine
class Order {
    public:
        Order() {
            // Set the initial state to NewOrderState
            state_ = new NewOrderState();
        }

        void handleOrder() {
            // Call the current state's handle method
            state_->handle(*this);
        }

        void setState(OrderRoutingState* state) {
            // Set the new state
            state_ = state;
        }

    private:
        OrderRoutingState* state_;
};

int main() {
    // Create an order and handle it through the state machine
    Order order;
    order.handleOrder();
    order.handleOrder();
    order.handleOrder();
    order.handleOrder();
    return 0;
}

