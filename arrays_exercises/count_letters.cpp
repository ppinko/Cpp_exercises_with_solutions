/*
Create a function that counts the number of 
times a particular letter shows up in the word search.

Examples

letterCounter([
  ["D", "E", "Y", "H", "A", "D"],
  ["C", "B", "Z", "Y", "J", "K"],
  ["D", "B", "C", "A", "M", "N"],
  ["F", "G", "G", "R", "S", "R"],
  ["V", "X", "H", "A", "S", "S"]
], "D") ➞ 3

// "D" shows up 3 times: twice in the first row, once in the third row.

letterCounter([
  ["D", "E", "Y", "H", "A", "D"],
  ["C", "B", "Z", "Y", "J", "K"],
  ["D", "B", "C", "A", "M", "N"],
  ["F", "G", "G", "R", "S", "R"],
  ["V", "X", "H", "A", "S", "S"]
], "H") ➞ 2

Notes

You will always be given an array with five sub-arrays.

*/


/* PSEUDOCODE

1. create a counter
2. traverse throught a main vector
3. traverse through a subvectors
4. compare to a given character
5. return value

*/

#include <vector>
#include <iostream>

using namespace std;

int letterCounter(vector<vector<char>> arr, char c) {
    int counter {0};
    for (size_t i {0}; i < arr.size(); i++) {
        for (size_t j {0}; j < arr[i].size(); j++) {
            if (arr[i][j] == c)
                counter++;
        }
    }
    return counter;
}

int main(){
    return 0;
}