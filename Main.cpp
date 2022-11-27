// Study Group 7 (Alex Milanez, John Edwin Karel Delgado, Ronell Sean Rulloda)

#include <iostream>
#include <fstream>
#include <Item.h>
#include <Transaction.h>

#include "Libraries/rapidxml-1.13/rapidxml.hpp"

using namespace std;

string login(const string& filename, const string& employeeID) {
    int employeeCount = 0;
    string tempEmployeeID;
    string tempCashier;

    std::ifstream file(filename); // Opens file
    if(!file.is_open()) throw std::invalid_argument("File Failed to Open");
    file >> employeeCount;

    for(int i=0; i<employeeCount*2;i++) {
        if(i%2==0) {
            file >> tempEmployeeID;
        } else {
            file >> tempCashier;
            if(tempEmployeeID==employeeID) {
                cout << "Logged In" << endl;
                return tempCashier;
            }
        }
    }
    cout << "No Matching Employee ID\n";
    return "";
}

void newTransaction(const string& cashier, const string& employeeID) {
    int transactionCount = 0;
    int UPC;
    char option;
    bool loop = true;

    while (loop) {
        std::fstream file("../Database/history.csv");
        if(!file.is_open()) throw std::invalid_argument("File Failed to Open");
        file >> transactionCount;
        transactionCount = 1;
        Transaction transaction(transactionCount, employeeID, cashier);
        file.close();

        cout << "\nPlease Select an Option:\n1. Scan\n2. Print\n3. Exit" << endl;
        cin >> option;

        switch (option) {
            case '1': { // Scan
                cout << "\nPlease enter UPC:";
                cin >> UPC;
                transaction.scan(UPC);
                break;
            }

            case '2': { // Print Receipt
                string paymentType;
                char option2;

                cout << "\nTotal: " << transaction.getTotal() << endl;
                cout << "\nPlease Choose Payment Method: \n1. CREDIT\n2. DEBIT\n3. CASH\n4. CANCEL" << endl;
                cin >> option2;

                switch(option2) {
                    case '1': { // CREDIT
                        paymentType = "CREDIT";
                        int card;

                        cout << "\nPAYMENT METHOD: CREDIT";
                        cout << "\nPlease Insert Card:" << endl;
                        cin >> card;
                        break;
                    }

                    case '2': { // DEBIT
                        paymentType = "DEBIT";
                        int card;

                        cout << "\nPAYMENT METHOD: DEBIT";
                        cout << "\nPlease Insert Card:" << endl;
                        cin >> card;
                        break;
                    }

                    case '3': { // CASH
                        paymentType = "CASH";
                        double cash;

                        cout << "\nPAYMENT METHOD: CASH" << endl;
                        cout << "\nPlease Insert Cash:" << endl;
                        cin >> cash;

                        double change = cash-transaction.getTotal();
                        cout << "CHANGE: $" << change << endl;

                        break;
                    }

                    case '4': { // CANCEL
                        cout << "\nCANCEL" << endl;
                        break;
                    }

                    default: {
                        cout << "Please enter valid option." << endl;
                        break;
                    }
                }

                transaction.print(paymentType);

                std::ofstream file2("../Database/history.csv");
                if(!file2.is_open()) throw std::invalid_argument("File Failed to Open");
                file2 << transactionCount;
                file2.close();
                loop = false;
                break;
            }

            case '3': { // Exit
                cout << "\nExited" << endl;
                loop = false;
                break;
            }

            default: {
                cout << "Please enter valid option." << endl;
                break;
            }
        }
    }
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
                string cashier = login("../Database/logins.csv", employeeID);

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

                        case '2': { // Transaction History
                            int historyCount;

                            std::fstream file2("../Database/history.csv",ios::out | ios::app);
                            if(!file2.is_open()) throw std::invalid_argument("File Failed to Open");
                            cin >> historyCount;

                            for(int i=0;i<historyCount;i++) {
                                // cout <<                          IMPLEMENT LATER
                            }

                            file2.close();
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