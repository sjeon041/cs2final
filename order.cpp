#include "order.h"
#include <iomanip>

void Order::addItem(OrderItem item) {
    if (itemCount < 20) {
        items[itemCount++] = item;
    }
}

double Order::calculateTotal() const{
    double total = 0.0;
    for (int i = 0; i < itemCount; i++) {
        total += items[i].menuItem.price * items[i].quantity;
    }
    return total;
}


void Order::printOrder() const{
    /* Prints a small receipt.
    Honestly this function is probably reused a lot more than it should be, it's called for pretty much every time there's an order to display.
    Future iterations should probably just go and have simpler outputs such as just the top part with ID, customer name, table number, and status.*/
    cout << "-----------------------------\n";
    cout << "Order ID:      " << orderId << endl;
    cout << "Customer Name: " << customerName << endl;
    cout << "Table Number:  " << tableNumber << endl;
    cout << "Status:        " << status << endl;
    if (!comment.empty()) {
        cout << "Comment:       " << comment << endl;
    }
    cout << "Items:\n";

    for (int i = 0; i < itemCount; ++i) {
        cout << "  - " << items[i].menuItem.name
             << " x" << items[i].quantity;

        if (!items[i].specialRequest.empty()) {
            cout << " (Note: " << items[i].specialRequest << ")";
        }

        cout << " — $" << fixed << setprecision(2)
             << items[i].menuItem.price * items[i].quantity << endl;
    }

    cout << "-----------------------------\n";
    cout << "Total: $" << fixed << setprecision(2) << calculateTotal() << endl;
    cout << "-----------------------------\n";
}

void Order::placeOrder(Menu* currentMenu)
{
    // Probably the most important function in the entire program. Creates an order object with the necessary details that will be accessed very often later.
    cout << "Please enter the customer's name.\n";
    cin.ignore();
    getline(cin, customerName);
    cout << "Please enter the table number.\n";
    cin >> tableNumber;
    currentMenu->displayMenu();
    int foodId;
    OrderItem currentRequest;
    orderId = ++currentOrderNumber;
    while(true)
    {
        cout << "Please input item number. Enter 0 to exit.\n";
        cin >> foodId;
        foodId--;
        if (foodId > currentMenu->getCount() || foodId < - 1)
        {
            cout << "Invalid response. Please enter a valid item number.\n";
        }
        else if (foodId == -1)
        {
            break;
        }
        else
        {
            cout << "Please enter the quantity of the dish ordered.\n";
            cin >> currentRequest.quantity;
            cout << "Please enter any special requests for the dish. Enter 'None' or press newline if there is no such request.\n";
            cin.ignore(); 
            getline(cin, currentRequest.specialRequest);
            MenuItem* foodNumber = currentMenu->getItemById(foodId);
            OrderItem newOrder = OrderItem(*foodNumber, currentRequest.quantity, currentRequest.specialRequest);
            addItem(newOrder);
        }

    } 
}