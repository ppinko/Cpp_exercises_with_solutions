// https://www.hackerrank.com/challenges/rectangle-area/problem

#include <iostream>

using namespace std;

class Rectangle {
    private:
        int width;
        int height;
    
    public:
        
        Rectangle(): width{0}, height{0} {};
        
        Rectangle(int w, int h): 
            width(w), height{h}{};

        ~Rectangle(){};

        virtual void display(){std::cout << width << " " << height << std::endl;}

        int get_width() const {return width;}

        int get_height() const {return height;}

        void read_input(){std::cin >> width >> height;}

};

class RectangleArea : public Rectangle {
    public:
        
        RectangleArea(): Rectangle(){};
        
        RectangleArea(int w, int h): 
            Rectangle(w, h){};

        ~RectangleArea(){};

        virtual void display() override{std::cout << get_width() * get_height() << std::endl;}
};


int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}