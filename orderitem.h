#pragma once
#include "menuitem.h"

class OrderItem {
public:
    MenuItem menuItem;
    int quantity;
    string specialRequest;

    OrderItem() {}
    OrderItem(MenuItem m, int q, string r)
    {
        menuItem = m;
        quantity = q;
        specialRequest = r;
    }
};