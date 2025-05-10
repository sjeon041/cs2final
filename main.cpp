#include "employee.h"
//#include "employee.cpp"
#include "menu.h"
#include <iostream>
using namespace std;

int main(){
    Employee* employeeTest = Employee::login();
    string x;
    Menu menuTest;
    menuTest.initializeFromFile("menu.txt");
    menuTest.displayMenu();
    return 0;
}

