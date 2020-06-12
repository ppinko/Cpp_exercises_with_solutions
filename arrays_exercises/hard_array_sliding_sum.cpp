/*
https://edabit.com/challenge/SkJoSKw9i3GQf62k5
*/


#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>


std::vector<std::vector<int>> slidingSum(std::vector<int> arr, int n, int k) {
	std::vector<std::vector<int>> answer {};
    for (auto it = arr.begin(); it <= arr.end() - n; it++){
        if (std::accumulate(it, it + n, 0) == k){
            std::vector<int> temp {};
            std::copy(it, it + n, std::back_inserter(temp));
            answer.push_back(temp);
        }
    }
    return answer;
}

int main(){
    std::cout << "Success" << std::endl;
    return 0;
}