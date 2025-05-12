#include "server.h"
#include <iostream>

Order Server::takeOrder(Menu* menu) {
    Order customerOrder;
    customerOrder.placeOrder(menu);
    customerOrder.printOrder();
    return customerOrder;
}
/*
void Server::checkFinished() {
    cout << "Checking if any orders are ready...\n";
    // Main currently does not use this function, though it should be implemented.
}

void Server::serveOrder(Order& order) {
    cout << "Served order #" << order.orderId << endl;
    // Current implementation just marks order as finished in main. Future updates should should implement this.
}
*/