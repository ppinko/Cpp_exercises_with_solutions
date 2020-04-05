/*
In each input array, every number repeats at least once, except for two.

Write a function that returns the two unique numbers.

Examples

returnUnique([1, 9, 8, 8, 7, 6, 1, 6]) ➞ [9, 7]

returnUnique([5, 5, 2, 4, 4, 4, 9, 9, 9, 1]) ➞ [2, 1]

returnUnique([9, 5, 6, 8, 7, 7, 1, 1, 1, 1, 1, 9, 8]) ➞ [5, 6]

Notes

Keep the same ordering in the output.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> returnUnique(vector<int> arr) {
    vector <int> copy_vector {};
    for (auto element : arr) {
        copy_vector.push_back(element);
    }
    sort(arr.begin(), arr.end());
    vector<int> temp {};
    size_t arr_length {arr.size()};
    for (size_t i {0}; i < arr_length; i++){
        if (i == 0){
            if (arr.at(i) == arr.at(i+1)){
                i++;
            }
            else {
                temp.push_back(arr.at(i));
            }
        }
        else if (i == arr_length - 1){
            if (arr.at(i) != arr.at(i-1)){
                temp.push_back(arr.at(i));
                break;
            }
        }
        else {
            if (arr.at(i) == arr.at(i+1)){
                i++;
            }
            else if (arr.at(i) == arr.at(i-1)){
            }
            else {
                temp.push_back(arr.at(i));
            }
        }
    }
    int a, b;
    int c {0};
    for (int element: copy_vector){
        if (element == temp.at(0)){
            a = c;
            }
        else if (element == temp.at(1)){
            b = c;
            }
        c++;
    }

    if (a < b)
        return temp;
    else {
        a = temp.at(0);
        b = temp.at(1);
        temp.at(0) = b;
        temp.at(1) = a;
        return temp;
    }
}

int main(){
    vector<int> temp = returnUnique({5, 5, 2, 4, 4, 4, 9, 9, 9, 1});
    for (auto element: temp)
        cout << element << " ";
    cout << endl;
    return 0;
}
