#pragma once
#include "MenuItem.h"

class OrderItem {
public:
    MenuItem menuItem;
    int quantity;
    string specialRequest;

    OrderItem() {}
    OrderItem(MenuItem m, int q, string r);
};