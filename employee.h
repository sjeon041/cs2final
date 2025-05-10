#pragma once
#include <string>
using namespace std;

class Employee {
private:
    string username;
    string password;
    double hoursWorked = 0;

public:
    static Employee* login();
    virtual ~Employee() = default;
    void logout();
    void clockIn();
    void clockOut();
    double getHoursWorked();
};