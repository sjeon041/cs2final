#include "order.h"

void Order::addItem(OrderItem item) {
    if (itemCount < 10) {
        items[itemCount++] = item;
    }
}

double Order::calculateTotal() {
    double total = 0.0;
    for (int i = 0; i < itemCount; i++) {
        total += items[i].menuItem.price * items[i].quantity;
    }
    return total;
}