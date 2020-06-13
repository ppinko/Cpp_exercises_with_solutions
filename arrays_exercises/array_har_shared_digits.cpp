// https://edabit.com/challenge/jQKpyhYLwhaimYPha

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

bool sharedDigits(std::vector<int> arr) {
    std::vector<std::string> digits {};
    std::transform(arr.begin(), arr.end(), std::back_inserter(digits), 
        [](int i) -> std::string {return std::to_string(i);});
	for (int i = 0; i < digits.size() - 1; i++){
        bool flag = true;
        for (char c: digits[i]){
            if (digits[i+1].find(c) != std::string::npos){
                flag = false;
                break;
            }
        }
        if (flag) return false;
    }
    return true;
}

int main(){
    // std::vector<int> vec {2, 3, 4, 5, 6, 7};
    // std::vector<int> vec {2, 3, 4, 5, 6, 7, 8};
    // auto v = chunkify(vec, 3);
    // for (auto i: v){
    //     for (auto j: i){
    //         std::cout << j << " ";
    //     }
    //     std::cout << "\n";
    // }
    std::cout << "Success" << std::endl;
    return 0;
}