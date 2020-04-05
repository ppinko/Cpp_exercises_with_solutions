#ifndef POINT_H
#define POINT_H
#include <iostream>

class Point
{
    private:
        int *x;
        int *y;
    public:
        Point(int x_val = 0, int y_val = 0);    // constructor
        ~Point();                               // destructor
        Point(const Point &source);             // copy constructor
        // Point(Point &&source);                  // move constructor - it does NOT work
        Point operator-() const;               // overloading '-'
        Point operator+(const Point &rhs);     // overloading '+'
        Point &operator=(const Point &rhs);    // overloading '='
        bool operator<(const Point &rhs);     // overloading '<'
        bool operator==(const Point &rhs);      // overloading '=='
        friend std::ostream &operator<<(std::ostream &os, const Point &source);
        friend std::istream &operator>>(std::istream &ins, Point &source);
        void get_x();
};

#endif // POINT_H
