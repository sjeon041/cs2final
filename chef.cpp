#include "chef.h"
#include <iostream>

void Chef::getOrder(Order order) {
    currentOrder = order;
    cout << "Chef started order #" << currentOrder.orderId << endl;
}

void Chef::markFinished() {
    currentOrder.status = "ready";
    cout << "Chef finished order #" << currentOrder.orderId << endl;
}

Order Chef::getCurrentOrder() {
    return currentOrder;
}