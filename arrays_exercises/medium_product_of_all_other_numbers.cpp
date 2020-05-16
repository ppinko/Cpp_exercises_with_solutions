/*
https://edabit.com/challenge/4RdeNmRMMbhdGuwNN

Product of All Other Numbers

You have an array of integers, and for each index you want to find the product of every
integer except the integer at that index.

Create a function that takes an array of integers and returns an array of the products.

Examples:

getProducts([1, 7, 3, 4]) ➞ [84, 12, 28, 21]
getProducts([1, 7, 3, 4]) ➞ [84, 12, 28, 21]
getProducts([1, 2, 3, 0, 5]) ➞ [0, 0, 0, 30, 0]
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void print_vec(vector<int> v){
    for (auto const& i: v)
        cout << i << ' ';
    cout << endl;
}

int vec_product(vector<int>& v){
    int n = 1;
    for (int& i: v)
        n *= i;
    return n;
}

vector<int> getProducts(vector<int> arr) {
	vector<int> ans {};
    for (int i (0); i < arr.size(); i++){
        vector<int> copied {};
        std::copy(arr.begin(), arr.end(), back_inserter(copied));
        copied.erase(copied.begin() + i);
        int sub_total = vec_product(copied);
        ans.push_back(sub_total);
    }
    return ans;
}


int main(){

    auto v = getProducts({1, 7, 3, 4});
    print_vec(v);
    cout << "Hello" << endl;
    return 0;
}