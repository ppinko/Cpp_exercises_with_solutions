#ifndef _DOG_H_
#define _DOG_H_

#include <string>
#include <iostream>

class Dog {
    private:
        std::string name;
        int age;
        static int dog_counter;
    public:
        // constructors and destructors
        Dog(std::string name_val, int age_val);
        Dog();
        ~Dog();
        Dog(const Dog &source);

        // overloaded operators
        Dog &operator=(const Dog &other);
        Dog &operator++(int);
        Dog operator+(const Dog &other) const;
        
        // insertion operator
        friend std::ostream& operator<<(std::ostream &oss, const Dog &obj);

        // methods
        void get_age();
        void introduce(); 
        int after_n_year(int n = 5); 
};

#endif