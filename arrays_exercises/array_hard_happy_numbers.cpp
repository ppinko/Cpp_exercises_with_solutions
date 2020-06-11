/*
https://edabit.com/challenge/3WCghTW5jKNjJh9y9
*/


#include <iostream>
#include <vector>

float percentageHappy(std::vector<int> n) {
	int happy = 0;
    for (int i = 0; i < n.size(); i++){
        if (i == 0){
            if (n[i] == n[i+1]) happy++;
        }
        else if (i == n.size() - 1){
            if (n[i] == n[i-1]) happy++;
        }
        else {
            if (n[i] == n[i-1] || n[i] == n[i+1]) happy++;
        }
    }
    float ans = static_cast<float>(happy)/n.size();
    return ans;
}


int main(){
    std::cout << "Success" << std::endl;
    return 0;
}