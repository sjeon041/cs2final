#pragma once
#include "employee.h"
#include "order.h"
#include "menu.h"
#include "global.h"

class Server : public Employee {
public:
    Order takeOrder(Menu* menu);
    /*
    void checkFinished();
    void serveOrder(Order& order);
    */
};