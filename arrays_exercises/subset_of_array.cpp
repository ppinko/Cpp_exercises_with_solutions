/*

*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

// // First Solution
// bool isSubset(std::vector<int> arr1, std::vector<int> arr2) {
// 	std::sort(arr1.begin(), arr1.end());
// 	std::sort(arr2.begin(), arr2.end());
// 	std::vector<int> arr3 {};
// 	std::set_intersection(arr1.begin(), arr1.end(), 
// 												arr2.begin(), arr2.end(),
// 											 std::back_inserter(arr3));
// 	return (arr1.size() == arr3.size());
// }

// Second Solution
bool isSubset(std::vector<int> arr1, std::vector<int> arr2) {
	std::sort(arr1.begin(), arr1.end());
	std::sort(arr2.begin(), arr2.end());
	return std::includes(arr2.begin(), arr2.end(), arr1.begin(), arr1.end());
}


int main(){
    std::cout << std::boolalpha;
    std::vector<int> v1 {8, 9};
    std::vector<int> v2 {7, 1, 9, 8, 4, 5, 6};
    std::cout << isSubset(v1, v2) << " = true" << std::endl;
    return 0;
}