/*
https://edabit.com/challenge/GzfsAoqpAQrNq64Q6
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

std::vector<int> toArray(int num) {
	std::vector<int> v {};
    if (num == 0) {
        v.push_back(0);
        return v;
    }
    while (num > 0){
        v.push_back(num % 10);
        num = num / 10;
    }
    std::reverse(v.begin(), v.end());
    return v;
}

int toNumber(std::vector<int> arr) {
	int ans {0};
    int j {0};
    while (!arr.empty()){
        ans += arr.back() * pow(10, j);
        arr.pop_back();
        j++;
    }
    return ans;
}

int main(){
    std::cout << "Success" << std::endl;
    return 0;
}