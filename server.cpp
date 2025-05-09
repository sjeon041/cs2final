#include "Server.h"
#include <iostream>

void Server::takeOrder(Order& order) {
    cout << "Server took order #" << order.id << endl;
}

void Server::checkFinished() {
    cout << "Checking if any orders are ready...\n";
}

void Server::serveOrder(Order& order) {
    cout << "Served order #" << order.id << endl;
}