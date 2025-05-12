#include "menu.h"
#include <fstream>
#include <sstream>
#include <iostream>

void Menu::initializeFromFile(string filename) {
    // Could make an argument to faciliate the ability to editing the menu and whatnot in-program, possibly in future versions
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string idStr, name, priceStr, description;

        getline(ss, idStr, '|');
        getline(ss, name, '|');
        getline(ss, priceStr, '|');
        getline(ss, description);

        double price = stod(priceStr);
        if (count < MAX_MENU_ITEMS) {
            items[count++] = MenuItem(name, price, description);
        }
    }
    file.close();
}

void Menu::displayMenu() { // Prints out the whole menu.
    for (int i = 0; i < count; i++) {
        cout << i+1 << ": " << items[i].name << " - $" << items[i].price
             << " | " << items[i].description << endl;
    }
}

MenuItem* Menu::getItemById(int id) { // Just returns a pointer to a menu item with the ID.
    if (id >= 0 && id < count) return &items[id];
    return nullptr;
}

Menu::Menu(){
    string filename = "menu.txt";
    initializeFromFile(filename);

}
