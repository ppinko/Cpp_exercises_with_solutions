#include <iostream>
#include "Points.h"

int main()
{
    Points p1 {1,2};
    p1.show_cordinates();
    Points p2 {2,3};
    p2.show_cordinates();
    // std::cout << p1.x << std::endl;
    Points p3 = add_points(p1, p2);
    p3.show_cordinates();
    return 0;
}
