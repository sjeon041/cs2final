#pragma once
#include <string>
using namespace std;

class MenuItem {
public:
    string name;
    double price;
    string description;

    MenuItem() {}
    MenuItem(string n, double p, string d);
};