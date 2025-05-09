#include "Menu.h"
#include <fstream>
#include <sstream>
#include <iostream>

void Menu::initializeFromFile(string filename) {
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

void Menu::displayMenu() {
    for (int i = 0; i < count; i++) {
        cout << i << ": " << items[i].name << " - $" << items[i].price
             << " | " << items[i].description << endl;
    }
}

MenuItem* Menu::getItemById(int id) {
    if (id >= 0 && id < count) return &items[id];
    return nullptr;
}