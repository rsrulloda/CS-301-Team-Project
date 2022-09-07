// Study Group 7 (Alex Milanez, John Edwin Karel Delgado, Ronell Sean Rulloda)

#ifndef CS_301_TEAM_PROJECT_ITEM_H
#define CS_301_TEAM_PROJECT_ITEM_H

#include <string>

using namespace std;

class Item {
public:
    // Constructors
    Item();

    Item(string description, int qty, double upc,double price);

    // Getters & Setters
    string getDescription();
    void setDescription(string description);

    int getQty() const;
    void setQty(int qty);

    double getUPC() const;
    void setUPC(double upc);

    double getPrice() const;
    void setPrice(double price);

private:
    string description;
    int qty{};
    double upc{};
    double price{};
};


#endif //CS_301_TEAM_PROJECT_ITEM_H
