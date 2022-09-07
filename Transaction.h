//
// Created by ronel on 9/6/2022.
//

#ifndef CS_301_TEAM_PROJECT_TRANSACTION_H
#define CS_301_TEAM_PROJECT_TRANSACTION_H

#include <string>

const int STORE_ID = 12345;
const int REGISTER_ID = 001;

using namespace std;

class Transaction {
public:
    // Constructors
    Transaction();

    Transaction(int transactionID, int associateID, string cashier);

    // Getters & Setters
    int getTransactionID();
    void setTransactionID(int transactionID);

    int getAssociateID();
    void setAssociateID(int associateID);

    string getCashier();
    void setCashier(string cashier);

    // Print Function
    void Print();

private:
};


#endif //CS_301_TEAM_PROJECT_TRANSACTION_H
