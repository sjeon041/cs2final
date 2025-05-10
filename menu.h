#pragma once
#include "menuitem.h"
#include <string>
using namespace std;

const int MAX_MENU_ITEMS = 100;

class Menu {
private:
    MenuItem items[MAX_MENU_ITEMS];
    int count = 0;

public:
    void initializeFromFile(string filename);
    void displayMenu();
    MenuItem* getItemById(int id);
};