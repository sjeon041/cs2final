#include <iostream>
#include "order.h"
#include "FifoQueue.h"
#include "global.h"
#include "menu.h"
using namespace std;

int currentOrderNumber = 1;

void testOrderAndQueue() {
    cout << "Running Order and Queue Tests...\n";

    // Create menu item manually
    MenuItem burger("Burger", 8.5, "Cheeseburger with lettuce");
    OrderItem orderItem(burger, 2, "No onions");

    // Create order
    Order order;
    order.customerName = "Test User";
    order.tableNumber = 3;
    order.comment = "Birthday guest";
    order.status = "pending";
    order.addItem(orderItem);

    // Test order printing
    order.printOrder();

    // Create FIFOQueue and test
    FIFOQueue<Order, 10> queue;
    queue.enqueue(order);

    cout << "\nPrinting queue:\n";
    queue.printAll();

    cout << "\nSearching for order by ID:\n";
    queue.searchById(order.orderId);

    cout << "\nDequeue and print again:\n";
    queue.dequeue();
    queue.printAll();
}

void testMenuLoading() {
    cout << "\nRunning Menu Loading Test...\n";
    Menu menu;
    menu.initializeFromFile("menu.txt");
    menu.displayMenu();

    MenuItem* item = menu.getItemById(0);
    if (item) {
        cout << "\nGot menu item: " << item->name << " - $" << item->price << endl;
    }
}

int main() {
    testOrderAndQueue();
    testMenuLoading();
    while(true){}
    return 0;
}