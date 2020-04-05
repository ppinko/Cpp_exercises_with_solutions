/*
https://edabit.com/challenge/ZRCqCLXsqzJhteR2g
*/

#include <iostream>
#include <vector>

int count_overlapping(std::vector< std::vector<int> > intervals, int point) {
	int counter {0};
	for (auto &v : intervals){
		if (v[0] <= point && v[1] >= point)
			counter++;
	}
	return counter;
}

int main(){
    std::vector< std::vector<int> > v1 {{1,2},{2,3},{1,3},{4,5},{0,1}};
    std::cout << count_overlapping(v1, 2) << " = 3" << std::endl;
    return 0;
}