/*
https://edabit.com/challenge/GdX4bWEkxGN3osHsv
*/

#include <vector>
#include <iostream>
#include <algorithm>

int recamanIndex(int n) {
	std::vector<int> v {0};
	int num {};
	int index {0};
	while (true){
		num = v.at(v.size() -1) - v.size();
		if (num > 0 && std::find(v.begin(), v.end(), num) == v.end())
			v.push_back(num);
		else {
			num = v.at(v.size() -1) + v.size();
			v.push_back(num);
		}
        index++;
		if (num == n)
			return index;
	}
}

int main(){
    std::cout << recamanIndex(7) << " should equal to 5" << std::endl;
    return 0;
}