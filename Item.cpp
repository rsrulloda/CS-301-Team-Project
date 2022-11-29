// Study Group 7 (Alex Milanez, John Edwin Karel Delgado, Ronell Sean Rulloda)

#include "Item.h"
#include <utility>

Item::Item() {
    setUPC(000000000000);
    setQty(0);
    setPrice(0);
    setDescription("");
}

Item::Item(double upc, int qty, double price, string description) {
    setUPC(upc);
    setQty(qty);
    setPrice(price);
    setDescription(std::move(description));
}

string Item::getDescription() {
    return description;
}

void Item::setDescription(string description) {
    this->description = std::move(description);
}

int Item::getQty() const{
    return qty;
}

void Item::setQty(int qty) {
    if(qty<0) {
        throw "Negative Quantity";
    }

    this->qty = qty;
}

double Item::getUPC() const {
    return upc;
}

void Item::setUPC(double upc) {
    if(upc<0 || upc>999999999999) {
        throw "Invalid UPC";
    }

    this->upc = upc;
}

double Item::getPrice() const {
    return price;
}

void Item::setPrice(double price) {
    if(price<0) {
        throw "Negative Price";
    }

    this->price = price;
}
