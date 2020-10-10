#include <iostream>
#include <iomanip> 

using namespace std;

int main() {

    double d = 2006.008;
    int a = d;
    double c = 2331.41592653498;

    cout << std::showbase << std::hex;
    cout << a << endl;
    cout << std::showpos << std::setprecision(2) << std::fixed;;
    std::cout << std::setfill('_');
    cout << std::setw(15) << std::right << d << endl;
    std::cout << std::resetiosflags(std::ios::showpos);
    cout << std::showpos << std::setprecision(9) << std::fixed << std::uppercase << std::scientific;;
    cout << c << endl;
    std::cout.unsetf(std::ios::scientific | std::ios::uppercase);

    cout << a << endl;

	return 0;

}