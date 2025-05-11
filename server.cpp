#include "server.h"
#include <iostream>

Order Server::takeOrder(Menu* menu) {
    Order customerOrder;
    customerOrder.placeOrder(menu);
    customerOrder.printOrder();
    return customerOrder;
}

void Server::checkFinished() {
    cout << "Checking if any orders are ready...\n";
    // Needs implementation
}

void Server::serveOrder(Order& order) {
    cout << "Served order #" << order.orderId << endl;
    //Needs to mark order as finished
}