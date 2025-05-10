#pragma once
#include <string>
using namespace std;

class Employee {
protected:
    string username;
    string password;
    double hoursWorked = 0;

public:
    static Employee* login();
    void logout();
    void clockIn();
    void clockOut();
    double getHoursWorked();
};