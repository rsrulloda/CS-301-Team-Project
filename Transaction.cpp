// Study Group 7 (Alex Milanez, John Edwin Karel Delgado, Ronell Sean Rulloda)

#include "Transaction.h"

#include <utility>

Transaction::Transaction() {
    setTransactionID(0);
    setAssociateID(0);
    setCashier("");
}

Transaction::Transaction(int transactionID, int associateID, string cashier) {
    setTransactionID(transactionID);
    setAssociateID(associateID);
    setCashier(std::move(cashier));
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

int Transaction::getAssociateID() const {
    return associateID;
}

void Transaction::setAssociateID(int associateID) {
    if(associateID<0) {
        throw "Invalid Associate ID";
    }

    this->associateID = associateID;
}

string Transaction::getCashier() {
    return cashier;
}

void Transaction::setCashier(string cashier) {
    this->cashier = cashier;
}

void Transaction::Print() {

}
