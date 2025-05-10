#include "order.h"
#include "menu.h"

void Order::addItem(OrderItem item) {
    if (itemCount < 20) {
        items[itemCount++] = item;
    }
}

double Order::calculateTotal() {
    double total = 0.0;
    for (int i = 0; i < itemCount; i++) {
        total += items[i].menuItem.price * items[i].quantity;
    }
    return total;
}

Order Order::placeOrder(Menu& currentMenu)
{
    cout << "Please enter the customer's name.\n";
    cin >> customerName;
    cout << "Please enter the table number.\n";
    cin >> tableNumber;
    currentMenu.displayMenu();
    int orderNumber;
    while(true)
    {
        cout << "Please input item number. Enter 0 to exit.\n";
        cin >> orderNumber;
        if (orderNumber > currentMenu.getCount())
        {
            cout << "Invalid response. Please enter a valid item number.\n"
        }

    } 
}