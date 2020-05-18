/*
https://edabit.com/challenge/o3rAX7WoEiFEC9ehv

Roundabout

You are driving in a roundabout. At the moment you enter, you don't know which
one of the exits you have to take. At the moment your GPS (or the person next
to you) shouts that you should leave the roundabout, there's a moment of time
where you need to react, turn on your indicator light, and exit the roundabout.

Assuming the roundabouts are of equal size, the exits are equally spaced and
you're driving at the same speed, you need to figure out the exit you're taking.
Your function will get the amount of exits of the roundabout. You're entering
the roundabout on "Exit 0".

The next input will be the amount of degrees where you get the command to leave
the roundabout. The time you have to react will be 30 degrees on the roundabout,
so you cannot exit immediately.

Examples:

roundabout(4, 50) ➞ "Exit 1"
roundabout(4, 320) ➞ "Exit 0"
roundabout(6, 60) ➞ "Exit 2"
*/

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <set>
#include <iterator>
#include <iomanip>
#include <cmath>

std::string roundabout(int siz, int dgr) {
	int final_pos = (dgr + 30) % 360;
    int exit_number = std::ceil(final_pos * siz / 360);
    std::string exit {"Exit "};
    if (exit_number + 1 == siz) return exit + "0";
    else return exit + std::to_string(exit_number + 1);
}

int main(){
    std::cout << std::boolalpha;
    std::cout << roundabout(4, 320) << std::endl;
    std::cout << roundabout(4, 50) << std::endl;
    std::cout << "Success" << std::endl;
    return 0;
}