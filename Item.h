//
// Created by ronel on 9/6/2022.
//

#ifndef CS_301_TEAM_PROJECT_ITEM_H
#define CS_301_TEAM_PROJECT_ITEM_H

#include <string>

using namespace std;

class Item {
public:
    // Constructors
    Item();

    Item(string description, int UPC, int qty, double price);

    // Getters & Setters
    string getDescription();
    void setDescription(string description);

    int getUPC();
    void setUPC(int UPC);

    int getQty();
    void setQty(int Qty);

    double getPrice();
    void setPrice(double price);

private:
};


#endif //CS_301_TEAM_PROJECT_ITEM_H
