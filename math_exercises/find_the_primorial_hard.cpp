/*
https://edabit.com/challenge/wm7QaM3LF6owGdKSA
*/

#include <iostream>

#include <cmath>
#include <vector>

int primorial(int n){
	int res = 0;
	int start = 2;
	std::vector<int> v;
	int i = 1;
	while (i <= n){
		if (i == 1){
			v.push_back(start);
			res = start;
			i++;
		}
		else {
			bool flag = true;
			for (int j {0}; j < v.size(); j++){
				if (start % v[j] == 0) {
					flag = false;
					break;	
			    }
            }
			if (flag){
				res *= start;
                v.push_back(start);
				i++;
			}
		}
		start++;
	}
	return res;
}

int main(){
    std::cout << primorial(2) << " equals to = 6 " << std::endl;   
    std::cout << primorial(8) << " equals to = 9699690 " << std::endl;
    return 0;
}