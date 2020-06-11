/*
https://edabit.com/challenge/JxRFXDimK2eR3Jqnr
*/

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <iterator>
#include <algorithm>

std::vector<int> countDigits(std::vector<int> arr, std::string type) {
	std::vector<int> answer {};
    std::vector<std::string> v_str {};
    std::transform(arr.begin(), arr.end(), std::back_inserter(v_str),
        [](int num) -> std::string {return std::to_string(num);});
    for (const std::string& i: v_str){
        int temp = 0;
        for (const char& c: i){
            int k = (int)c - int('0');
            if (type == "even" && k % 2 == 0)
                temp += 1;
            else if (type == "odd" && k % 2 == 1)
                temp += 1;
        }
        answer.push_back(temp);
    }
    return answer;
}


int main(){
    // std::vector<int> vec1 {5, 7, 3, 2, 8};
    // auto vec2 = replaceNextLargest(vec1);
    // for (auto i: vec2){
    //     std::cout << i << " ";
    // }
    std::cout << "Success" << std::endl;
    return 0;
}