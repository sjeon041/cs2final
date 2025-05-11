#include "employee.h"
#include "Chef.h"
#include "Server.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Employee* Employee::login() {
    string inputUser, inputPass;
    cout << "Username: ";
    cin >> inputUser;
    cout << "Password: ";
    cin >> inputPass;

    ifstream file("users.txt");
    if (!file) {
        cerr << "Error: Could not open users.txt\n";
        return nullptr;
    }

    string line, fileUser, filePass;
    char roleChar = '\0';

    while (getline(file, line)) {
        if (line.rfind("User", 0) == 0) {
            // Parse role from last character (e.g., 'User 2c' -> 'c')
            roleChar = line.back();

            // Read username line
            getline(file, line);
            if (line.rfind("username:", 0) == 0)
                fileUser = line.substr(9);
            fileUser.erase(0, fileUser.find_first_not_of(" \t"));

            // Read password line
            getline(file, line);
            if (line.rfind("password:", 0) == 0)
                filePass = line.substr(9);
            filePass.erase(0, filePass.find_first_not_of(" \t"));

            // Match input credentials
            if (inputUser == fileUser && inputPass == filePass) {
                Employee* user = nullptr;

                if (roleChar == 'c') {
                    user = new Chef();
                    cout << "Login successful as Chef.\n";
                    user->username = inputUser;
                } else if (roleChar == 's') {
                    user = new Server();
                    cout << "Login successful as Server.\n";
                    user->username = inputUser;
                } else {
                    cout << "Unknown role type.\n";
                    return nullptr;
                }
                return user;
            }
        }
    }

    cout << "Invalid credentials.\n";
    return nullptr;
}

/*void Employee::logout() {
    cout << "User " << username << " logged out.\n";
}

void Employee::clockIn() {
    cout << username << " clocked in.\n";
}

void Employee::clockOut() {
    cout << username << " clocked out.\n";
}

double Employee::getHoursWorked() {
    return hoursWorked;
}
    //I wanted to implement these but the scope of the project kept getting bigger.
*/