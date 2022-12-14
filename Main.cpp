// Study Group 7 (Alex Milanez, John Edwin Karel Delgado, Ronell Sean Rulloda)

#include <iostream>
#include <fstream>
#include <Item.h>
#include <Transaction.h>
#include <list>
#include <algorithm>

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
                cout << "\nLogged In";
                return tempCashier;
            }
        }
    }
    cout << "No Matching Employee ID\n";
    return "";
}

void processPayment() {}

void newTransaction(const string& cashier, const string& employeeID, list<Item> tempList) { // STEP D
    int transactionCount = 0;
    int UPC;
    char option;
    bool loop = true;

    while (loop) {
        // Loads inventory.csv to list data structure
        int inventoryCount;
        list<Item> inventoryList;

        std::fstream inventoryFile("../Database/inventory.csv");
        if(!inventoryFile.is_open()) throw std::invalid_argument("File Failed to Open");
        inventoryFile >> inventoryCount;

        for(int i=0;i<inventoryCount;i++) {
            double tempUPC;
            int tempQty;
            double tempPrice;
            string tempDescription;

            inventoryFile >> tempUPC;
            inventoryFile >> tempQty;
            inventoryFile >> tempPrice;
            inventoryFile >> tempDescription;

            Item item(tempUPC, tempQty, tempPrice, tempDescription);
            inventoryList.push_front(item);
        }

        std::fstream file("../Database/history.csv");
        if(!file.is_open()) throw std::invalid_argument("File Failed to Open");
        file >> transactionCount;
        Transaction transaction(transactionCount, employeeID, cashier, tempList);
        file.close();

        cout << "\nPlease Select an Option:\n1. Scan\n2. Remove\n3. Print\n4. Exit" << endl;
        cin >> option;

        switch (option) {
            case '1': { // Scan Item
                cout << "\nPlease enter UPC:";
                cin >> UPC;

                list<Item> tempList2;

                list<Item>::iterator it = inventoryList.begin();
                for(int i=0;i<inventoryList.size();i++) {
                    if(UPC==inventoryList.front().getUPC()) {
                        tempList.push_front(inventoryList.front());
                    }
                }

                // Prints out current items in list
                double subtotal = 0;

                cout << "\nCurrent Items in Shopping Cart: " << endl;
                for(int i=0;i<tempList.size();i++) {
                    cout << tempList.front().getDescription() << "\t\t\t" << tempList.front().getPrice() << endl;
                    subtotal += tempList.front().getPrice();
                }
                cout << "Subtotal: " << subtotal << endl;

                break;
            }

            case '2': { // Remove Item
                cout << "\nPlease enter UPC:";
                cin >> UPC;
                break;
            }

            case '3': { // Print Receipt
                string paymentType;
                char option2;

                cout << "\nTotal: " << transaction.getTotal(tempList) << endl;
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

                        double change = cash-transaction.getTotal(tempList);
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

                transaction.print(paymentType, tempList);

                inventoryFile.close();

                std::ofstream file2("../Database/history.csv");
                if(!file2.is_open()) throw std::invalid_argument("File Failed to Open");
                file2 << transactionCount;
                file2.close();
                loop = false;
                break;
            }

            case '4': { // Exit
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
    // Loads history.csv to list data structure
    list<Transaction> transactionList;

    int option;
    bool appOn = true;

    while(appOn) {
        cout << "Welcome! Please Select an Option:\n1. Login\n2. Exit" << endl;
        cin >> option;

        switch (option) { // STEP A
            case 1: { // Login
                string employeeID;
                cout << "\nPlease enter employee ID:" << endl;
                cin >> employeeID;
                string cashier = login("../Database/logins.csv", employeeID);

                char option2;
                bool loggedIn = true;

                while (loggedIn) { // STEP B
                    cout << "\nWelcome " << cashier << "!" << endl;
                    cout << "\nPlease Select an Option:\n1. New Transaction\n2. Return Transaction\n3. Transaction History\n4. Logout" << endl;
                    cin >> option2;

                    switch (option2) {
                        case '1': { // New Transaction
                            list<Item> tempList;
                            newTransaction(cashier, employeeID, tempList);
                            break;
                        }

                        case '2': { // Return Transaction
                            list<Item> tempList;
                            newTransaction(cashier, employeeID, tempList);
                            break;
                        }

                        case '3': { // Transaction History
                            int historyCount;
                            list<Transaction> historyList;

                            std::fstream historyFile("../Database/history.csv",ios::out | ios::app);
                            if(!historyFile.is_open()) throw std::invalid_argument("File Failed to Open");
                            historyFile >> historyCount;

                            cout << "\nTransaction History:" << endl;

                            for(int i=0;i<historyCount;i++) {
                                int tempTransID;
                                string tempAssociateID;
                                string tempCashier;
                                list<Item> tempList;

                                historyFile >> tempTransID;
                                historyFile >> tempAssociateID;
                                historyFile >> tempCashier;
                                historyFile >> reinterpret_cast<bool &>(tempList);

                                Transaction transaction(tempTransID, tempAssociateID, tempCashier, tempList);
                                historyList.push_front(transaction);

                                cout << historyList.front().getTransactionID() << " ";
                                cout << historyList.front().getAssociateID() << " ";
                                cout << historyList.front().getCashier() << endl;
                            }

                            cout << "000000000001 ni2195 Ronell_Rulloda Item1 Item2\n"
                                    "000000000002 nc7466 John_Delgado Item2 Item1\n"
                                    "000000000003 cu8886 Alex_Milanez Item3 Item3 Item2" << endl;
                            historyFile.close();
                            break;
                        }

                        case '4': { // Logout
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