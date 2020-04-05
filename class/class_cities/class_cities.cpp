#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

/*
My own class defining cities
Implement:
- name as pointer option get
- number of cities as static
- friend function to number of cities
*/

class City {
        friend void get_num_cities();
    private:
        std::string *name;
        static int num_cities;
    public:
        City(std::string n = "Not specified");  // overloaded constructor
        ~City();                                // destructor
        City(const City &source);               // copy constructor
        City(City &&source);                    // move constructor
        City &operator=(const City &rhs);
        void get_name() const;
        void set_name(std::string new_name);
        bool compare_cities(const City &other);
};

int City::num_cities {0};

City::City(std::string n) {
    name = new std::string;
    *name = n;
    std::cout << "Constructor\n";
    num_cities++;
}

City::~City(){
    delete name;
    std::cout << "Destructor\n";
    num_cities--;
}

City::City(const City &source){
    name = new std::string;
    *name = *source.name;
    std::cout << "Copy constructor\n";
    num_cities++;
}

City::City(City &&source) {
    name = source.name;
    source.name = nullptr;
    std::cout << "Move constructor\n";
}

void City::get_name() const{
    std::cout << *name << std::endl;
}

void City::set_name(std::string new_name){
    *name = new_name;
}

void get_num_cities(){
    std::cout << "Number of cities = " << City::num_cities << std::endl;
}

bool City::compare_cities(const City &other){
    if (this == &other)
        return 0;
    else
        return 1;
}

int main(){
    // City noname;
    City herborn {"Herborn"};
    City haiger {herborn};

    City dillenburg {City("NYC")};
//
//    noname.get_name();
//    herborn.get_name();
//    haiger.get_name();
//
//    herborn.set_name("Bear town");
//    herborn.get_name();
//    haiger.get_name();
//    get_num_cities();
//    std::cout << "HELLO\n";
//    std::cout << std::boolalpha << (herborn.compare_cities(noname)) << std::endl;
//    std::vector<City> vec {};
//    vec.push_back(herborn);
//    vec.push_back(City{"Legnica"});
//    City *ptr_city = new City("NYC");
//    ptr_city->get_name();
//    delete ptr_city;
    return 0;
}
