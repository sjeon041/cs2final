#pragma once
#include "orderitem.h"
#include "global.h"
#include "menu.h"
#include <iostream>

class Order {
public:
    int orderId;
    string customerName;
    int tableNumber;
    string comment;
    string status;
    OrderItem items[20];
    int itemCount = 0;

    // Need to implement a getOrderId function since the constructor doesn't really give access to it
    void printOrder() const;
    void addItem(OrderItem item);
    void placeOrder(Menu* currentMenu);
    double calculateTotal() const;
};