#pragma once
#include "Employee.h"
#include "Order.h"

class Server : public Employee {
public:
    void takeOrder(Order& order);
    void checkFinished();
    void serveOrder(Order& order);
};