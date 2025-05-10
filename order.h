#pragma once
#include "orderitem.h"
#include <iostream>

class Order {
public:
    int id;
    string customerName;
    int tableNumber;
    string comment;
    string status;
    OrderItem items[20];
    int itemCount = 0;

    void addItem(OrderItem item);
    Order placeOrder(Menu& currentMenu);
    double calculateTotal();
};