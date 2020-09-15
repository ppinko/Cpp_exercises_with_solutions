// https://edabit.com/challenge/dwtpTMnvkLLYcH2hC

#include <cassert>
#include <set>
#include <cmath>

using namespace std;

bool isHappy(int n) {
	set<int> all_nums {n};
    while (true){
        int temp = 0;
        while (n > 0){
            temp += pow(n % 10, 2);
            n /= 10;
        }
        if (temp == 1)
            return true;
        else if (all_nums.count(temp) == 1)
            return false;
        else {
            all_nums.insert(temp);
            n = temp;
        }
    }
}

using namespace std;

int main(){

	assert((isHappy(100) == true));
	assert((isHappy(101) == false));
	assert((isHappy(102) == false));
	assert((isHappy(103) == true));
	assert((isHappy(104) == false));
	assert((isHappy(105) == false));
	assert((isHappy(106) == false));
	assert((isHappy(107) == false));
	assert((isHappy(108) == false));
	assert((isHappy(109) == true));
	assert((isHappy(110) == false));

    return 0;
}