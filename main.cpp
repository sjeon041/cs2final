#include "employee.h"
//#include "employee.cpp"
#include "menu.h"
#include "global.h"
#include "FifoQueue.h"
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

#include "Chef.h"
#include "Server.h"
#include "Order.h"

int currentOrderNumber = 0;

int main() {
    const int MAX_ORDERS = 100;
    FIFOQueue<Order, MAX_ORDERS> toBePreparedQueue;
    FIFOQueue<Order, MAX_ORDERS> readyToServeQueue;
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
                cout << "1. Take an order\n2. Check current order\n3. Serve order (Mark as finished)\n4. Display menu\n5. Check queue\n6. Find order by ID\n7. Log Out\n";
                cin >> userInput;
                if(userInput == 1)
                {
                    Order temp;
                    bool ordering = true;
                    while(true)
                    {
                        if (ordering)
                        {
                            temp = server->takeOrder(currentMenu);
                        }
                        cout << "Please confirm the order above. Enter 1 to push order. Enter 2 to cancel order. Enter 3 to change order.\n";
                        cin >> userInput;
                        if(userInput == 1)
                        {
                            cout << "Server took order #" << temp.orderId << endl;
                            if (!toBePreparedQueue.enqueue(temp))
                            {
                                cout << "Queue is full.\n";
                            }
                            break;
                        }
                        else if(userInput == 2)
                        {
                            cout << "Order cancelled.\n";
                            break;
                        }
                        else if(userInput == 3)
                        {
                            cout << "Editing order.\n";
                        }
                        else
                        {
                            cout << "Invalid response.\n";
                            ordering = false;
                        }
                    }                    
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
                    toBePreparedQueue.printAll();
                }
                else if (userInput == 6)
                {
                    cin >> userInput;
                    toBePreparedQueue.searchById(userInput);

                }
                else if (userInput == 7)
                {
                        user->clockOut();
                        user->logout();
                        cout << "Server " + server->getUser() + " has logged out.";
                        delete user;
                        break;
                }
                else
                {
                    cout << "Invalid input. Please enter a number from 1 to 4.\n";
                }
            }
        }
    }
    return 0;
}

