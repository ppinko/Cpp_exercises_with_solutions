#include "NBA.h"

// getters
string NBA::get_name() const{
    return this->name;
}

string NBA::get_team() const{
    return this->team;
}

void NBA::introduce() const{
    cout << this->get_name() << "plays for " << this->get_team() << endl;
}