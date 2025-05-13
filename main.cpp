#include "employee.h"
#include "Chef.h"
#include "Server.h"
#include "Order.h"
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

int currentOrderNumber = 0;

int main() {
    const int MAX_ORDERS = 100;
    FIFOQueue<Order, MAX_ORDERS> toBePreparedQueue;
    FIFOQueue<Order, MAX_ORDERS> readyToServeQueue;
    FIFOQueue<Order, MAX_ORDERS> currentlyPreparing;
    FIFOQueue<Order, MAX_ORDERS> finishedOrders;
    while(true)
    {
        Employee* user = Employee::login(); // This could point to a Chef or Server
        while (!user) {
                cout << "Login failed.\n";
                return 1; //This needs to have a looping condition to recheck the user for proper credentials on failure.
        }
        Menu* currentMenu = new Menu();
        int userInput;
        if (Chef* chef = dynamic_cast<Chef*>(user)) {
            while(true)
            {
                cout << "Welcome, Chef!\n";
                cout << "Choose from one of the options below.\n";
                cout << "1. Get next order\n2. Mark current order as finished\n3. Check current order\n4. Log Out\n";
                cin >> userInput;
                Order preparingOrder; // Chef should push all orders before logging out, inherent weakness of design with the queue implementation.
                if(userInput == 1)
                {
                    if(!toBePreparedQueue.isEmpty())
                    {
                        preparingOrder = toBePreparedQueue.dequeue();
                        preparingOrder.printOrder();
                        cout << "Now preparing Order #" << preparingOrder.orderId << endl;
                        preparingOrder.status = "Preparing\n";
                        currentlyPreparing.enqueue(preparingOrder);
                    }
                    else
                    {
                        cout << "No orders currently need preparing.\n";
                    }
                }
                else if(userInput == 2)
                {                
                    if(!currentlyPreparing.isEmpty())
                    {
                        Order finishedOrder = currentlyPreparing.dequeue();
                        finishedOrder.status = "Ready to serve\n";
                        finishedOrder.printOrder();
                        cout << "Order #" << finishedOrder.orderId << " is now ready for serving.\n";
                        readyToServeQueue.enqueue(finishedOrder);
                    }
                    else
                    {
                        cout << "No orders currently being prepared.\n";
                        // Should also have implementations for isFull but unrealistic for this demo.
                    }
                }
                else if(userInput == 3)
                {                
                    if(!currentlyPreparing.isEmpty()) // Check to prevent crashes in case of an empty queue.
                    {
                        currentlyPreparing.printAll();
                    }
                    else
                    {
                        cout << "No orders currently being prepared.\n";
                    }
                }
                else if (userInput == 4)
                {
                    cout << "Chef " + chef->getUser() + " has logged out.\n";
                    delete user;
                    break;
                    // Required for program to function currently as queues reset on program startup.
                }
                else
                {
                    cout << "Invalid input. Please enter a number from 1 to 4.\n";
                }
            }

        } else if (Server* server = dynamic_cast<Server*>(user)) {
            while(true)
            {
                cout << "Welcome, Server!\n";
                cout << "Choose from one of the options below.\n";
                cout << "1. Take an order\n2. Check ready orders\n3. Serve order (Mark as finished)\n4. Display menu\n5. Check orders not yet prepared\n6. Find order by ID\n7. Log Out\n";
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
                            temp.status = "Needs prep\n";
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
                            cout << "Editing order.\n"; // Requires the entire order to be entered again. Maybe future iterations can allow for specific variable editing.
                        }
                        else
                        {
                            cout << "Invalid response.\n";
                            ordering = false;
                            // Once an order is made, loops until valid response is given. 
                            // Done this way so user isn't repeated prompted to re-enter a new order.
                        }
                    }                    
                }
                else if(userInput == 2)
                {
                    if(!readyToServeQueue.isEmpty())
                    {
                        readyToServeQueue.printAll();
                    }
                    else
                    {
                        cout << "Queue is empty.\n";
                    }            
                }
                else if(userInput == 3)
                {                
                    if(!readyToServeQueue.isEmpty()) // Same as above.
                    {
                        Order temp2 = readyToServeQueue.dequeue(); // Dequeue is built with a native check but the previous if condition allows for better error handling instead of a generic queue underflow.
                        temp2.status = "Served\n";
                        temp2.printOrder();
                        finishedOrders.enqueue(temp2);
                    }
                    else
                    {
                        cout << "Queue is empty.\n";
                    }
                }
                else if (userInput == 4)
                {
                    currentMenu->displayMenu(); // Does print out the whole menu and can be cluttered running like this in terminal.
                }
                else if (userInput == 5)
                {
                    if(!toBePreparedQueue.isEmpty())
                    {
                        toBePreparedQueue.printAll(); // Similar problem to previous input.
                    }
                    else
                    {
                        cout << "No orders currently being prepared.\n";
                    }
                }
                else if (userInput == 6)
                {
                    cout << "Please enter the ID of the order.\n";
                    cin >> userInput;
                    // Fail condition is built into searchById in case no valid order exists.
                    if(toBePreparedQueue.searchById(userInput, true) == false && currentlyPreparing.searchById(userInput, true) == false && readyToServeQueue.searchById(userInput, true) == false && finishedOrders.searchById(userInput, true == false))
                    {
                        cout << "No order found with that ID.\n";
                    }
                }
                else if (userInput == 7)
                {
                    cout << "Server " + server->getUser() + " has logged out.\n";
                    delete user;
                    break;
                    // Multiple user login is essential as the queues are re-initialized on program startup.
                    // Maybe future iterations can write these to an external file in between runs?
                }
                else
                {
                    cout << "Invalid input. Please enter a valid number.\n";
                }
            }
        }
    }
    return 0;
}

