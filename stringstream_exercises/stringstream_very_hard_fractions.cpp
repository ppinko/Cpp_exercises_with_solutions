// https://edabit.com/challenge/9X9T7zPshHbqzdGHy

#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include <vector>
#include <cmath>

std::string mixedNumber(std::string frac);
int gcd(int a, int b);

int gcd(int a, int b){
    int bigger = std::fmax(a, b);
    int smaller = std::fmin(a, b);
    if (bigger == 1 || smaller == 1) return 1;
    if (bigger % smaller == 0) return smaller;
    else return gcd(bigger % smaller, smaller);
}

std::string mixedNumber(std::string frac) {
	std::istringstream ss {frac};
    std::string token {};
    int a {};
    std::vector<int> v {};
    while(std::getline(ss, token, '/')){
        a = std::stoi(token);
        v.push_back(a);
    }
    
    if (v.at(0) == 0) return "0";
    
    std::string answer {};
    
    if (v.at(0) < 0) answer.push_back('-'); 

    int first = std::abs(v.at(0)) / v.at(1);
    int second = std::abs(v.at(0)) % v.at(1);
    
    if (second == 0) {
        answer.append(std::to_string(first));
        return answer;
    }
    
    int gcd_res = gcd(std::abs(v.at(1)), second);
    if (gcd_res != 1){
        second /= gcd_res;
        v.at(1) /= gcd_res;  
    }

    if (first != 0){
        answer.append(std::to_string(first));
        answer.push_back(' ');
    }

    answer.append(std::to_string(second));
    answer.push_back('/');
    answer.append(std::to_string(v.at(1)));
    return answer;
}

int main(){

    std::cout << mixedNumber("-5/4") << std::endl;
    assert((mixedNumber("5/4") == "1 1/4"));
	assert((mixedNumber("6/4") == "1 1/2"));
	assert((mixedNumber("8/4") == "2"));
	assert((mixedNumber("4/6") == "2/3"));
	assert((mixedNumber("-1/4") == "-1/4"));
	assert((mixedNumber("-5/4") == "-1 1/4"));

    std::cout << "Success" << std::endl;
    return 0;
}