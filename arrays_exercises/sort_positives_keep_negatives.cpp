/*
https://edabit.com/challenge/xwCz78P2chsEdKrr7
*/


#include <iostream>
#include <vector>
#include <algorithm>

void display_vec(std::vector<int> vec){
    auto it = vec.begin();
    std::cout << "[ ";
    for (it; it != vec.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << "]\n"; 
}

std::vector<int> posNegSort(std::vector<int> arr) {
	std::vector<int> temp{};
    for (int i : arr){
        if (i >= 0)
            temp.push_back(i);
    }
    std::sort(temp.begin(), temp.end());
    int temp_i {0};
    for (int j {0}; j < arr.size(); j++) {
        if (arr[j] >= 0){
            arr[j] = temp[temp_i];
            temp_i++;
        }
    }
    return arr;
}

int main(){
    std::vector<int> vec {6, 5, 4, -1, 3, 2, -1, 1};
    display_vec(posNegSort(vec));
    std::cout << " = [1 2 3 -1 4 5 -1 6]" << std::endl;
    return 0;
}