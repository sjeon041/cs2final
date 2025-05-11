#pragma once
#include <string>
using namespace std;

class Order;
class Menu;

class Employee {
private:
    string username;
    string password;

public:
    static Employee* login();
    string getUser()
    {
        return username;
    }
    virtual ~Employee() = default;
/*    void logout();
    void clockIn();
    void clockOut();
    double getHoursWorked();
*/
};