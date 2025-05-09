#pragma once
#include "OrderItem.h"

class Order {
public:
    int id;
    string customerName;
    int tableNumber;
    string comment;
    string status;
    OrderItem items[10];
    int itemCount = 0;

    void addItem(OrderItem item);
    double calculateTotal();
};