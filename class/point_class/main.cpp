#include <iostream>
#include "Point.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <memory>

int main()
{
    Point p1 {1,2};
    p1.get_x();
    std::unique_ptr<Point> pptr {new Point {2,3}};
    std::cout << *pptr << "\n";
    (*pptr).get_x();
    pptr->get_x();
    std::cout << pptr.get() << "\n";
    pptr.reset(new Point {10, 10});
    (*pptr).get_x();
    std::cout << pptr.get() << "\n";
    std::cout << pptr.get() << "\n";
    auto ptr2 = std::make_unique<Point>(18,17);
    std::unique_ptr<Point> ptr3 {std::move(ptr2)};
    std::cout << ptr2.get() << "\n";
    ptr3->get_x();
    std::cout << "HUURRA\n";
    std::cout << "-----------------SHARED--------------\n";

    auto p10 = std::make_shared<Point>(7,7);
    std::shared_ptr<Point> p20 {p10};
    std::cout << p10.use_count() << "\n";
    std::weak_ptr<Point> p30 {p10};
    p20.reset();

    std::cout << p10.use_count() << "\n";
    p10.reset();
    std::cout << "CHECK\n";

//    Point p2;
//    Point p3 {p1};
//
//    std::vector<Point> vec {};
//    vec.push_back(Point{2,5});
//
//    Point p4 {-p1};
//    Point p6 {10, 10};
//    Point p5 {p1 + p6};
//    Point p7;
//    p7 = p5;
//
//    std::cout << std::boolalpha;
//    std::cout << (p1 < p6) << "\n";
//
//    std::cout << "\n--------------------------\n";
//    std::cout << (p1 == p6) << "\n";
//    std::cout << (p1 == p3) << "\n";
//
//    std::cout << "\n--------------------------\n";
//    std::cout << p6 << "\n";
//
//    std::cout << "\n--------------------------\n";
//    Point p10 {};
//    std::cin >> p10;
//    std::cout << p10 << "\n";

    return 0;
}
