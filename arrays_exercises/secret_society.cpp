/*
Secret Society

A group of friends have decided to start a secret society. The name will be the first letter 
of each of their names, sorted in alphabetical order.

Create a function that takes in an array of names and returns the name of the secret society.

Examples:

societyName(["Adam", "Sarah", "Malcolm"]) ➞ "AMS"

societyName(["Harry", "Newt", "Luna", "Cho"]) ➞ "CHLN"

societyName(["Phoebe", "Chandler", "Rachel", "Ross", "Monica", "Joey"]) ➞ "CJMPRR"

Notes

The secret society's name should be entirely uppercased.
*/

/*
PSEUDOCODE

1) create a copy of the vector
2) sort the vector
3) create a string
4) add first letters of all sorted words to a string
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // enables sort function

using namespace std;

std::string societyName(std::vector<std::string> friends) {
	vector <string> friends_copy;
    friends_copy = friends;
    sort(friends_copy.begin(), friends_copy.end());
    string secret_society {};
    for (auto name: friends_copy){
        secret_society += name[0];
    }
    return secret_society;
}

int main() {
    vector <string> test {"Adam", "Sarah", "Malcolm"};
    cout << societyName(test) << endl;
    return 0;
}