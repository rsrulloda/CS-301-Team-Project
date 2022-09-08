// Study Group 7 (Alex Milanez, John Edwin Karel Delgado, Ronell Sean Rulloda)

#include "Transaction.h"

#include <utility>
#include <iostream>

Transaction::Transaction() {
    setTransactionID(0);
    setAssociateID("");
    setCashier("");
    setTransactionType(CASH);
}

Transaction::Transaction(int transactionID, string associateID, string cashier, TRANSACTION_TYPE transactionType) {
    setTransactionID(transactionID);
    setAssociateID(std::move(associateID));
    setCashier(std::move(cashier));
    setTransactionType(transactionType);
}

int Transaction::getTransactionID() const {
    return transactionID;
}

void Transaction::setTransactionID(int transactionID) {
    if(transactionID<0) {
        throw "Invalid Transaction ID";
    }

    this->transactionID = transactionID;
}

string Transaction::getAssociateID() const {
    return associateID;
}

void Transaction::setAssociateID(string associateID) {
    this->associateID = std::move(associateID);
}

string Transaction::getCashier() {
    return cashier;
}

void Transaction::setCashier(string cashier) {
    this->cashier = std::move(cashier);
}

TRANSACTION_TYPE Transaction::getTransactionType() {
    return transactionType;
}

void Transaction::setTransactionType(TRANSACTION_TYPE transactionType) {
    this->transactionType = transactionType;
}

void Transaction::print() {
    cout << "\n" << STORE_NAME << endl << endl;
    cout << "Visit Us At " << WEBSITE << endl << endl;

    cout << "STORE: " << STORE_ID << "\t";
    cout << "REGISTER: " << REGISTER_ID << endl;
    cout << "CASHIER: " << getCashier() << endl;
    cout << "ASSOCIATE: " << getAssociateID() << endl;

    cout << "-----------------------------" << endl;
    cout << "CUSTOMER RECEIPT COPY" << endl << endl;

    // Insert Items Here
    cout << "AD BOOST UNCAGED WHT/SIL 0\t139.99" << endl; // EXAMPLE

    cout << "-----------------------------" << endl;
    cout << "SUBTOTAL: " << endl;
    cout << "SALES TAX: " << endl;
    cout << "TOTAL: " << endl;
    cout << "-----------------------------" << endl;
    cout << "AMOUNT TENDERED" << endl;

    if(getTransactionType()==CASH) {
        cout << "cash" << endl; // Implement Later
    } else {
        cout << "credit/debit" << endl; // Implement Later
    }

    cout << "-----------------------------" << endl;
    cout << "SALES TAX ANALYSIS" << endl;
    cout << "CODE\tRATE%\tTAXABLE\tTAX" << endl;
    cout << "LOCAL\t10.000\t" << "price" << "tax" << endl; // Implement Price & Tax later
    cout << "-----------------------------" << endl;
    cout << "tran: " << getTransactionID() << "\tDate & Time" << endl; // Implement Date & Time Later
    cout << "-----------------------------" << endl;
    cout << ADDRESS << endl;
    cout << PHONE << endl;
}
