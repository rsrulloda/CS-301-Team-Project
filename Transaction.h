// Study Group 7 (Alex Milanez, John Edwin Karel Delgado, Ronell Sean Rulloda)

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
    int getTransactionID() const;
    void setTransactionID(int transactionID);

    int getAssociateID() const;
    void setAssociateID(int associateID);

    string getCashier();
    void setCashier(string cashier);

    // Print Function
    void Print();

private:
    int transactionID{};
    int associateID{};
    string cashier;
};


#endif //CS_301_TEAM_PROJECT_TRANSACTION_H
