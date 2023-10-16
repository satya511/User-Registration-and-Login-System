#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

map<string, string> users;

void LoadUsersFromFile() {
    ifstream file("users.txt");
    if (file.is_open()) {
        string username, password;
        while (file >> username >> password) {
            users[username] = password;
        }
        file.close();
    }
}

void SaveUsersToFile() {
    ofstream file("users.txt");
    if (file.is_open()) {
        for (const auto& user : users) {
            file << user.first << " " << user.second << endl;
        }
        file.close();
    }
}

void Register() {
    string username, password;

    cout << "Enter a new username: ";
    cin >> username;

    if (users.find(username) != users.end()) {
        cout << "Username already exists. Please choose a different one." << endl;
        return;
    }

    cout << "Enter a password: ";
    cin >> password;

    users[username] = password;

    SaveUsersToFile();

    cout << "Registration successful!" << endl;
}

void Login() {
    string username, password;

    cout << "Enter your username: ";
    cin >> username;

    if (users.find(username) == users.end()) {
        cout << "Username not found. Please register first." << endl;
        return;
    }

    cout << "Enter your password: ";
    cin >> password;

    if (users[username] == password) {
        cout << "Login successful!" << endl;
    } else {
        cout << "Incorrect password. Please try again." << endl;
    }
}

int main() {
    LoadUsersFromFile(); // Load existing user data from the file

    int choice;

    while (true) {
        cout << "Choose an option:" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                Register();
                break;
            case 2:
                Login();
                break;
            case 3:
                SaveUsersToFile(); // Save user data to the file before quitting
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
