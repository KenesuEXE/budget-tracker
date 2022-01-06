#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    int balance;
    string userResponse;

    // Retrieve balance from data.txt
    fstream dataFile;
    dataFile.open("data.txt", ios::in);
    if (dataFile.is_open()) {
        string data;
        while (getline(dataFile, data)) {
            balance = stoi(data);
        }
        dataFile.close();
    }

    // Main budget tracker loop
    while (balance) {
        cout << "Your Balance: " << balance << "\n";
        cout << "Add income or deduct expense?\n";
        cout << "1 - Add Income\n";
        cout << "2 - Deduct Expenses\n";
        cout << "3 - Change Balance\n";
        // 4 - See budget history
        cout << "0 - Quit\n";

        cin >> userResponse;

        if (userResponse == "1") {
            int amountAdded;
            cout << "Insert amount to be added: ";
            cin >> amountAdded;
            balance += amountAdded;

        } else if (userResponse == "2") {
            int amountDeducted;
            cout << "Insert amount to be deducted: ";
            cin >> amountDeducted;
            balance -= amountDeducted;

        } else if (userResponse == "3") {
            cout << "Insert new amount: ";
            cin >> balance;

        } else if (userResponse == "0") {
            break;
        } // Else (incorrect input), loop back and ask again.
    }

    // Write new balance in data.txt
    dataFile.open("data.txt", ios::out);
    if (dataFile.is_open()) {
        dataFile << to_string(balance);
        dataFile.close();
        cout << "Balance saved.";
    }
    
    return 0;
}