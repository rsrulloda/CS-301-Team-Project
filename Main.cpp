// Study Group 7 (Alex Milanez, John Edwin Karel Delgado, Ronell Sean Rulloda)

#include <iostream>
#include <Item.h>
#include <Transaction.h>

using namespace std;

int main() {
    Transaction transaction(001, 123, "name", CASH);

    transaction.print();

    return 0;
}