#include "employee.h"
//#include "employee.cpp"
#include "menu.h"
#include <iostream>
using namespace std;

/*int main(){
    Employee* employeeTest = Employee::login();
    Menu menuTest;
    menuTest.initializeFromFile("menu.txt");
    menuTest.displayMenu();
    while (true);
    return 0;
}*/

#include <iostream>
#include "Chef.h"
#include "Server.h"
#include "Order.h"

using namespace std;

int main() {
    while(true)
    {
        Employee* user = Employee::login(); // This could point to a Chef or Server
        while (!user) {
                cout << "Login failed.\n";
                return 1;
        }

        user->clockIn();
        Menu* currentMenu = new Menu();
        int userInput;
        if (Chef* chef = dynamic_cast<Chef*>(user)) {
            while(true)
            {
                cout << "Welcome, Chef!\n";
                cout << "Choose from one of the options below.\n";
                cout << "1. Get next order\n2. Mark current order as finished\n3. Check current order\n4. Log Out\n";
                cin >> userInput;
                /*
                if(userInput == 1)
                {
                }
                else if(userInput == 2)
                {                
                }
                else if(userInput == 3)
                {                
                }
                else if (userInput == 4)
                {
                    user->clockOut();
                    user->logout();
                    cout << "Chef " + user + " has logged out.";
                    delete user;
                    break;
                }
                else
                {
                    cout << "Invalid input. Please enter a number from 1 to 4.\n";
                }*/
            }

        } else if (Server* server = dynamic_cast<Server*>(user)) {
            while(true)
            {
                cout << "Welcome, Server!\n";
                cout << "Choose from one of the options below.\n";
                cout << "1. Take an order\n2. Check current order\n3. Serve order (Mark as finished)\n4. Display menu\n5. Log Out\n";
                cin >> userInput;
                /*if(userInput == 1)
                {
                    user->takeOrder(currentMenu)
                }
                else if(userInput == 2)
                {                
                }
                else if(userInput == 3)
                {                
                }
                else if (userInput == 4)
                {
                    currentMenu->displayMenu();
                }
                else if (userInput == 5)
                {
                        user->clockOut();
                        user->logout();
                        cout << "Server " + user + " has logged out.";
                        delete user;
                        break;
                }
                else
                {
                    cout << "Invalid input. Please enter a number from 1 to 4.\n";
                }*/
            }
        }
    }
    return 0;
}

