#include "NBA.h"
#include "AllStar.h"

int main(){

    NBA KK0 {"Kyle Kuzma", "LA Lakers"};
    AllStar LJ23 {"Lebron James", "LA Lakers"};
    KK0.introduce();
    LJ23.introduce();

    cout << LJ23.get_name() << " - " << LJ23.get_team() << endl;

    return 0;
}