/*
https://edabit.com/challenge/jQShnYNzeXfpyqceD

Initialize

Create a function that takes in an array of full names and returns the initials.

Examples:

initialize(["Stephen Hawking"]) ➞ ["S. H."]

initialize(["Harry Potter", "Ron Weasley"]) ➞ ["H. P.", "R. W."]

initialize(["Sherlock Holmes", "John Watson", "Irene Adler"]) ➞ ["S. H.", "J. W.", "I. A."]

Notes

    Each initial is followed by a dot.
    Names will always be made of two words, separated by a space.

*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>


std::vector<std::string> initialize(std::vector<std::string> names) {
	std::vector<std::string> inits {};
    std::string name {};
    for (auto const& i : names){
        name.push_back(i.front());
        name += ". ";
        name.push_back(i.at(i.find(' ') + 1));
        name.push_back('.');
        inits.push_back(name);
        name.clear();
    }
    return inits;
}

int main(){
    std::cout << std::boolalpha;
    std::cout << "Success" << std::endl;
    return 0;
}