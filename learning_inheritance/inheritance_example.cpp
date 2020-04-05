#include <iostream>
#include "inheritance.h"
using namespace std;

class Base {
private:
    int value;
public:
   Base() : value {0}  {
            cout << "Base no-args constructor" << endl;
    }
    Base(int x)  : value {x} {
            cout << "Base (int) overloaded constructor" << endl;
    }
    virtual void get_value() const{ std::cout << value << "\n";}
};

class Derived : public Base {
private:
    int doubled_value;
public:
    Derived()
        : Base{}, doubled_value {0} {
            cout << "Derived no-args constructor " << endl;
    }
    Derived(int x)
        :  Base{x}, doubled_value {x * 2} {
            cout << "Derived (int) constructor" << endl;
    }
    void get_double() const { std::cout << doubled_value << "\n";}
};


int main()
{
    Base b1 {5};
    b1.get_value();
    Derived d1 {10};
    d1.get_value();
    d1.get_double();
    return 0;
}
