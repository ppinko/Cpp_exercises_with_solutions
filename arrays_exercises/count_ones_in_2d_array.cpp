/*
https://edabit.com/challenge/3dBpTdfBsnGYrKGxh
*/

#include <iostream>
#include <vector>
#include <algorithm>

// int count_ones(std::vector< std::vector<int> > matrix) {
//     int tot {0};
//     int not_one {0};
//     for (auto i: matrix){
//         for (auto j: i)
//             (j == 1) ? tot++ : not_one++;
//     }
//     return tot;
// }

// Alternative solution

int count_ones(std::vector< std::vector<int> > matrix) {
	int total = 0;
  	for (std::vector<int> t : matrix) 
	{
	  total += std::count(t.begin(), t.end(), 1);
	}
  	return total;
}

int main(){
    std::vector< std::vector<int>> m {{1, 0, 1}, {0, 0, 1}, {0, 0, 1}};
    std::cout << count_ones(m) << std::endl;
}