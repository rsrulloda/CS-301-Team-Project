// Study Group 7 (Alex Milanez, John Edwin Karel Delgado, Ronell Sean Rulloda)

#include <iostream>
#include <fstream>
#include <Item.h>
#include <Transaction.h>

using namespace std;

string login(const string& filename, const string& employeeID) {
    int employeeCount = 0;
    string tempEmployeeID;
    string tempCashier;

    std::ifstream file(filename);
    if(!file.is_open()) throw std::invalid_argument("File Failed to Open");
    file >> employeeCount;

    for(int i=0; i<employeeCount*2;i++) {
        if(i%2==0) {
            file >> tempEmployeeID;
        } else {
            file >> tempCashier;
            if(tempEmployeeID==employeeID) return tempCashier;
        }
    }
    return "No Matching Employee ID\n";
}

void newTransaction(const string& cashier, const string& employeeID) {
    Transaction transaction(001, employeeID, cashier, CASH); // test
    transaction.print();
}

int main() {
    int option;
    bool appOn = true;

    while(appOn) {
        cout << "Welcome! Please Select an Option:\n1. Login\n2. Exit" << endl;
        cin >> option;

        switch (option) {
            case 1: { // Login
                string employeeID;
                cout << "\nPlease enter employee ID:" << endl;
                cin >> employeeID;
                string cashier = login("../Database/logins.txt", employeeID);

                char option2;
                bool loggedIn = true;

                while (loggedIn) {
                    cout << "\nPlease Select an Option:\n1. New Transaction\n2. Transaction History\n3. Logout" << endl;
                    cin >> option2;

                    switch (option2) {
                        case '1': { // New Transaction
                            newTransaction(cashier, employeeID);
                            break;
                        }

                        case '2': { // Implement Later
                            cout << "Transaction History" << endl;
                            break;
                        }

                        case '3': { // Logout
                            cout << "\nLogged Out" << endl;
                            loggedIn = false;
                            break;
                        }

                        default: {
                            cout << "Please enter valid option." << endl;
                            break;
                        }
                    }
                }
                break;
            }

            case 2: { // Exit
                cout << "\nExited" << endl;
                appOn = false;
                break;
            }

            default: {
                cout << "Please enter valid option." << endl;
                break;
            }
        }
    }
    return 0;
}