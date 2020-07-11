#include "Dog.h"

#include <string>
#include <iostream>

// initializing static variable

int Dog::dog_counter = 0;

// constructors and destructors

Dog::Dog(std::string name_val, int age_val):
    name{name_val}, age{age_val} {++dog_counter;}

Dog::Dog(): Dog("Anonymous", 0) {std::cout << "Anonymous dog was created\n"; ++dog_counter;}

Dog::~Dog(){--dog_counter; std::cout << "A dog named " << name << " was removed\n";}

Dog::Dog(const Dog &source): Dog(source.name, source.age)
    {std::cout << "Copy of the dog was created\n";}

// overloaded operators
Dog& Dog::operator=(const Dog &other){
    if (this == &other)
        return *this;
    else{
        this->name = other.name;
        this->age = other.age;
        return *this;
    }
}

Dog &Dog::operator++(int){
    ++age;
    std::cout << "My new age is " << age << std::endl;
    return *this;
}

Dog Dog::operator+(const Dog &other) const{
    int temp = this->age + other.age;
    Dog new_Dog {this->name, temp};
    return new_Dog;
}

// insertion operator
std::ostream& operator<<(std::ostream &oss, const Dog &obj){
    oss << "Dog's name: " << obj.name << ", age = " << obj.age << std::endl;
    return oss;
}

// methods
void Dog::get_age(){
    std::cout << "Dog is " << age << " years old\n";
}

void Dog::introduce(){
    std::cout << "I'm a dog and my name is " << name << std::endl;
}

int Dog::after_n_year(int n){
    return this->age + n;
}