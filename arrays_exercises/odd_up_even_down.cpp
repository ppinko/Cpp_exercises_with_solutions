/*
Create a function that performs an even-odd transform to an array, n times. Each even-odd transformation:

    Adds two (+2) to each odd integer.
    Subtracts two (-2) to each even integer.

Examples

evenOddTransform([3, 4, 9], 3) ➞ [9, -2, 15]
// Since [3, 4, 9] => [5, 2, 11] => [7, 0, 13] => [9, -2, 15]

evenOddTransform([0, 0, 0], 10) ➞ [-20, -20, -20]

evenOddTransform([1, 2, 3], 1) ➞ [3, 0, 5]

*/

#include <iostream>
#include <vector>

using namespace std;

std::vector<int> evenOddTransform(std::vector<int> arr, int n) {
    int j {0};
    for (int i : arr) {
        if (i % 2 == 0)
            arr.at(j) -= 2 * n;
        else
            arr.at(j) += 2 * n;
        j++;
    }
    return arr;
}

int main() {
    vector <int> k {1, 2, 3, 4, 5};
    int l {2};
    vector <int> ans = evenOddTransform(k, l);
    for (auto element: ans)
        cout << element << " ";
    cout << endl;
    for (auto element: k)
        cout << element << " ";
    cout << endl;
return 0;
}
