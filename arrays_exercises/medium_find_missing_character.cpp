/*
https://edabit.com/challenge/f5WKGMQaYK2bABjpg

Find the Missing Letter

Create a function that takes an array of increasing letters and return the missing letter.

Examples:

missingLetter(["a", "b", "c", "e", "f", "g"]) ➞ "d"
missingLetter(["O", "Q", "R", "S"]) ➞ "P"
missingLetter(["t", "u", "v", "w", "x", "z"]) ➞ "y"
missingLetter(["m", "o"]) ➞ "n"
*/


#include <iostream>
#include <vector>

char missingLetter(std::vector<char> arr) {
    for (int i = 0; i < arr.size(); i++){
        if (arr[i + 1] - arr[i] != 1){
            int n = (int)arr[i] + 1;
            char c = (char)n;
            return c;
        }
    }
    return ' ';
}

int main(){
    std::cout << missingLetter({'a', 'b', 'c', 'e', 'f', 'g'}) << std::endl;
    return 0;
}