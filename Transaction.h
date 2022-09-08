// Study Group 7 (Alex Milanez, John Edwin Karel Delgado, Ronell Sean Rulloda)

#ifndef CS_301_TEAM_PROJECT_TRANSACTION_H
#define CS_301_TEAM_PROJECT_TRANSACTION_H

#include <string>

using namespace std;

const string STORE_NAME = "STORE NAME";
const string WEBSITE = "www.storename.com";
const string ADDRESS = "123 STREET AVE CITY, STATE";
const string PHONE = "012-345-6789";
const int STORE_ID = 12345;
const int REGISTER_ID = 001;
enum TRANSACTION_TYPE {CREDIT, DEBIT, CASH};

class Transaction {
public:
    // Constructors
    Transaction();

    Transaction(int transactionID, string associateID, string cashier, TRANSACTION_TYPE transactionType);

    // Getters & Setters
    int getTransactionID() const;
    void setTransactionID(int transactionID);

    string getAssociateID() const;
    void setAssociateID(string associateID);

    string getCashier();
    void setCashier(string cashier);

    TRANSACTION_TYPE getTransactionType();
    void setTransactionType(TRANSACTION_TYPE transactionType);

    // Print Function
    void print();

private:
    int transactionID{};
    string associateID{};
    string cashier;
    TRANSACTION_TYPE transactionType;
};


#endif //CS_301_TEAM_PROJECT_TRANSACTION_H
