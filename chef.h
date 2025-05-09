#pragma once
#include "Employee.h"
#include "Order.h"

class Chef : public Employee {
private:
    Order currentOrder;

public:
    void getOrder(Order order);
    void markFinished();
    Order getCurrentOrder();
};