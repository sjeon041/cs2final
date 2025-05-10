#include "chef.h"
#include <iostream>

void Chef::getOrder(Order order) {
    currentOrder = order;
    cout << "Chef started order #" << order.id << endl;
}

void Chef::markFinished() {
    currentOrder.status = "ready";
    cout << "Chef finished order #" << currentOrder.id << endl;
}

Order Chef::getCurrentOrder() {
    return currentOrder;
}