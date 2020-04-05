#include "Points.h"

// void Points::show_cordinates() const;

Points::Points(int x, int y)
    : x{x}, y{y} {
    std::cout << "calling constructor for point: (x,y) : (" << this->x << ","
    << this->y << ")\n";
    }

Points::~Points() {
    std::cout << "calling destructor for point: (x,y) : (" << this->x << ","
    << this->y << ")\n";
    }

void Points::show_cordinates() const{
    std::cout << "Point (x,y) = (" << this->x << "," << this->y << ")\n";
}

int Points::get_x() const {
    int a {this->x};
    return a;
}

int Points::get_y() const {
    return this->y;
}

Points add_points(const Points &p1, const Points &p2){
    int *px = new int;
    *px = p1.get_x();
    int *py = new int;
    *py = p1.get_y();
    int *p2x = new int;
    *p2x = p2.get_x();
    int *p2y = new int;
    *p2y = p2.get_y();
    Points ans {(*px) + (*p2x), (*py) + (*p2y)};
    delete px;
    delete py;
    delete p2x;
    delete p2y;
    return ans;
}

