#pragma once
#include "employee.h"
#include "order.h"

class Server : public Employee {
public:
    void takeOrder(Order& order);
    void checkFinished();
    void serveOrder(Order& order);
};