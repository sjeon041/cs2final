#pragma once
#include "employee.h"
#include "order.h"

class Chef : public Employee {
private:
    Order currentOrder; // Only the chef really cares what the current ongoing order is

public:
    void getOrder(Order order);
    void markFinished();
    Order getCurrentOrder();
};