// Study Group 7 (Alex Milanez, John Edwin Karel Delgado, Ronell Sean Rulloda)

#include "Transaction.h"
#include <Item.h>
#include <list>

#include <utility>
#include <iostream>
#include <fstream>

Transaction::Transaction() {
    setTransactionID(0);
    setAssociateID("");
    setCashier("");
}

Transaction::Transaction(int transactionID, string associateID, string cashier, const list<Item>& itemList) {
    setTransactionID(transactionID);
    setAssociateID(std::move(associateID));
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

double Transaction::getSubtotal(list<Item> tempList) {

}

double Transaction::getTotal(list<Item> tempList) {
//    double total = getSubtotal(std::move(tempList)) + getSubtotal(std::move(tempList))*SALES_TAX;
//    return total;
}


void Transaction::scan(double upc) {
    int itemCount = 0;
    double tempUPC;
    int tempQty = 0;
    double tempPrice;
    string tempDesc;
    Item tempItem;

    // Find item in inventory
    std::fstream file1("../Database/inventory.csv",ios::out | ios::app);
    if(!file1.is_open()) throw std::invalid_argument("File Failed to Open");
    file1 >> itemCount;

    for(int i=0;i<itemCount*4;i++) {
        cin >> tempUPC;
        if(upc == tempUPC) {
            cin >> tempQty >> tempPrice >> tempDesc;
        }
        if(tempQty==0) cout << "UPC not found";
    }

    tempItem.setQty(tempQty);
    tempItem.setPrice(tempPrice);
    tempItem.setDescription(tempDesc);

    file1.close();

    // Save item to temporary transaction
    std::fstream file2("../Database/temp.csv",ios::out | ios::app);
    if(!file2.is_open()) throw std::invalid_argument("File Failed to Open");

    file2 << tempItem.getQty() << ", "
            << tempItem.getPrice() << ", "
            << tempItem.getDescription() << "\n";

    file2.close();
}

void Transaction::itemList(list<Item> tempList) {
    for(int i=0;i<tempList.size();i++) {
        cout << tempList.front().getDescription() << "\t\t\t" << tempList.front().getPrice() << endl;
    }
}

void Transaction::print(const string& paymentType, list<Item> tempList) {
    cout << "\n" << STORE_NAME << endl << endl;
    cout << "Visit Us At " << WEBSITE << endl << endl;

    cout << "STORE: " << STORE_ID << "\t";
    cout << "REGISTER: " << REGISTER_ID << endl;
    cout << "CASHIER: " << getCashier() << endl;
    cout << "ASSOCIATE: " << getAssociateID() << endl;

    cout << "-----------------------------" << endl;
    cout << "CUSTOMER RECEIPT COPY" << endl << endl;

    // Insert Items Here
    itemList(tempList);

    cout << "\n=============================" << endl;
    cout << "SUBTOTAL: " << getSubtotal(std::move(tempList)) << endl;
    cout << "SALES TAX: " << endl;
    cout << "TOTAL: " << getTotal(std::move(tempList)) << endl;
    cout << "=============================" << endl;
    cout << "AMOUNT TENDERED" << endl;

    if(paymentType=="CASH") {
        cout << "-----------------------------" << endl;
        cout << "Cash                     0.00" << endl << endl;
        cout << "TOTAL PAYMENT            0.00" << endl;
        cout << "CHANGE                   0.00" << endl;
    } else {
        cout << "VISA                     0.00" << endl;
        cout << "   ACCT: ************1234" << endl;
        cout << "   EXP: ****" << endl;
        cout << "   APPROVAL: 055181" << endl;
        cout << "   AID: a000000031010" << endl;
        cout << "   ARQC: 651316a19e2cf1f7" << endl;
        cout << "   TVR: 0880008000" << endl;
        cout << "   TSI: f800" << endl;
        cout << "   CARD INSERTED" << endl;
        cout << "TOTAL PAYMENT            0.00" << endl;
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

    remove("../Database/temp.csv");
}
