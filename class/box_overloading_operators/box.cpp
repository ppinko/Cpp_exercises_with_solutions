// https://www.hackerrank.com/challenges/box-it/problem

//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

#include <iomanip>
#include <iostream>
#include <string>

class Box {
    private:
        long long l;
        long long b;
        long long h;
    public:
        Box(): Box {0, 0, 0} {}
        Box(int l_val, int b_val,int h_val):
            l{l_val}, b{b_val}, h{h_val}{}
        bool operator<(Box &rhs) const {
            if (this->l < rhs.l) return true;
            else if (this->l == rhs.l && this->b < rhs.b) return true;
            else if (this->l == rhs.l && this->b == rhs.b && this->h < rhs.h) return true;
            else return false;
        }
        friend std::ostream &operator<<(std::ostream &os, const Box &rhs);

        int getLength() const {return l;}
        int getBreadth() const {return b;}
        int getHeight() const {return h;}
        long long CalculateVolume(){return b * l * h;}
};

std::ostream &operator<<(std::ostream &os, const Box &rhs) {
    os << rhs.getLength() << " " << rhs.getBreadth() << " " << rhs.getHeight();
    return os;}

int main(){
    std::cout << std::boolalpha;
    Box b1 {10, 10, 10};
    Box b2 {10, 15, 10};
    std::cout << (b2 < b1) << std::endl;
    std::cout << b2 << std::endl;
    return 0;
}