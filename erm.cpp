#include <string>
#include <vector>
#include <iostream>
using namespace std;
// Remember to actually include these later

class Staff
{
    public:
        void login();
        void logout();
        void clockIn();
        void clockOut();
    private:
        string username;
        string password;
        bool isClockedIn();
}
class Chef : public Staff
{
    public:
        void getOrder();
        void markFinished();
}
class Server : public Staff
{
    public:
        void takeOrder();
        void checkFinished();
        void serveOrder();
}

class Menu
{
    public:
        void addItem(); // Guess what this does
        void removeItem(); // : )
        void getItem(); // Not sure how we want to implement this. Maybe a menu number and it gives info? Or maybe you put in a name and it gives the description.
    private:
        vector<string> items;
}
class menuItem : public Menu
{
    private:
        string name;
        string price;
        string description;
        bool available;
}

class OrderQueue
{
    public:
        void addOrder();
        void moveToCooking();
        void moveToReady();
    private:
        vector<string> pending; // These maybe should be vectors of integers for order ID?
        vector<string> cooking;
        vector<string> ready;
}

class 