#include "server.h"
#include <iostream>

void Server::takeOrder(Order& order) {
    // Write Customer name
    // Write customer table #
    // Order ID should be automatically generated (global variable in int main)
    // Write a loop to read file and add corresponding items until order is completed and is terminated by the server giving "0" as an input

    cout << "Server took order #" << order.id << endl;
}

void Server::checkFinished() {
    cout << "Checking if any orders are ready...\n";
}

void Server::serveOrder(Order& order) {
    cout << "Served order #" << order.id << endl;
}