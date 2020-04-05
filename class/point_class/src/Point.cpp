#include "Point.h"
#include <iostream>

Point::Point(int x_val, int y_val){
    x = new int;
    y = new int;
    *x = x_val;
    *y = y_val;
    std::cout << "Constructor (x,y) = (" << *x << "," << *y << ")\n";
}

Point::~Point(){
    std::cout << "Destructor (x,y) = (" << *x << "," << *y << ")\n";
    delete x;
    delete y;
}

Point::Point(const Point &source){
    this->x = new int;
    this->y = new int;
    *x = *source.x;
    *y = *source.y;
    std::cout << "Copy constructor (x,y) = (" << *x << "," << *y << ")\n";
}

//Point::Point(Point &&source) : x{source.x}, y{source.y} {
//    source.x = nullptr;
//    source.y = nullptr;
//    std::cout << "Move constructor (x,y) = (" << *x << "," << *y << ")\n";
//}

Point Point::operator-() const{
    std::cout << "Minus operator\n";
    return Point(-(*x), -(*y));
}

Point Point::operator+(const Point &rhs){
    std::cout << "Plus operator\n";
    return Point( *x + *rhs.x, *y + *rhs.y ) ;
}

Point &Point::operator=(const Point &rhs){
    std::cout << "assignment operator\n";
    if (this == &rhs)
        return *this;
    delete x;
    delete y;
    x = new int;
    y = new int;
    *x = *rhs.x;
    *y = *rhs.y;
    return *this;
}

bool Point::operator<(const Point &rhs){
    std::cout << "Operator '<'\n";
    int *temp1 = new int;
    int *temp2 = new int;
    *temp1 = (*x) * (*y);
    *temp2 = (*rhs.x) * (*rhs.y);
    if (*temp1 < *temp2){
        delete temp1;
        delete temp2;
        return true;
    }
    else {
        delete temp1;
        delete temp2;
        return false;
    }
}

bool Point::operator==(const Point &rhs){
    std::cout << "Operator '=='\n";
    if (*x == *rhs.x && *y == *rhs.y)
        return true;
    else
        return false;
}

std::ostream &operator<<(std::ostream &os, const Point &source) {
    os << "Point (x,y) = " << *source.x << "," << *source.y << "\n";
    return os;
}

std::istream &operator>>(std::istream &ins, Point &source){
    int x_val {};
    int y_val {};
    ins >> x_val >> y_val;
    source = Point(x_val, y_val);
    return ins;
}

void Point::get_x(){
    std::cout << "X = "<< *x << "\n";
}
