/*
https://edabit.com/challenge/swQedKdA2zDe5rWda
*/

#include <string>
#include <iostream>
#include <vector>

std::string check(std::vector<int> arr) {
    std::string flag;

    for (int i {0}; i < arr.size() - 1; i++){
        if (i == 0){
            if (arr[i] > arr[i+1])
                flag = "decreasing";
            else
                flag = "increasing";
        }
        if (flag == "decreasing"){
            if (arr[i] > arr[i+1])
                continue;
            else
                return "neither";
        }
        else {
            if (arr[i] < arr[i+1])
                continue;
            else
                return "neither";
        }
    }
    return flag;
}

int main(){
    std::vector<int> vec {3, 2, 1};
    std::cout << check(vec) << std::endl;
    return 0;
}