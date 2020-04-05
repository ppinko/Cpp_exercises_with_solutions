#ifndef POINTS_H
#define POINTS_H

#include <iostream>
#include <vector>

class Points
{
    private:
        int x;
        int y;
    public:
        Points(int x, int y);           // constructor
        virtual ~Points();  // destructor
        void show_cordinates() const;
        int get_x() const;
        int get_y() const;
        // std::vector<int> get_cordinate();
        // void set_cordinates(int x, int y);
};

#endif // POINTS_H

Points add_points(const Points &p1,const Points &p2);
