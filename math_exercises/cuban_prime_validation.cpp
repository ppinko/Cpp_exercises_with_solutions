// https://edabit.com/challenge/Pv2oMZfvYgHuqPbPm

#include <cmath>
#include <string>
#include <iostream>
#include <sstream>
#include <cassert>
#include <vector>

using namespace std;

string cubanPrime(const int num);
bool isPrime(const int num);
float roots(const int num);

bool isPrime(const int num){
    if (num == 2 || num == 3)
        return true; 
    else if (num <= 1 || num % 2 == 0)
        return false;
    for (int i = 3; i < num; i += 2){
        if (num % i == 0)
            return false;
    }
    return true;
}

float roots(const int num){
    float root = sqrtf(9 + 12 * (num - 1));
    float root_positive = (-3 + root)/6;
    return root_positive;
}

string cubanPrime(const int num){
    ostringstream oss {};
	if (!isPrime(num)){
        oss << num << " is not cuban prime";
        return oss.str();
    }
    else {
        float val = roots(num);
        int integer = static_cast<int>(val);
        if (val < 0 || val != integer){
            oss << num << " is not cuban prime";
            return oss.str();            
        }
        else {
            oss << num << " is cuban prime";
            return oss.str();  
        }
    }
    return "failed";
}


int main(){

	assert((cubanPrime(11) == "11 is not cuban prime"));
	assert((cubanPrime(40) == "40 is not cuban prime"));
	assert((cubanPrime(15) == "15 is not cuban prime"));
	assert((cubanPrime(271) == "271 is cuban prime"));
	assert((cubanPrime(919) == "919 is cuban prime"));
	assert((cubanPrime(1801) == "1801 is cuban prime"));
	assert((cubanPrime(30) == "30 is not cuban prime"));
	assert((cubanPrime(721) == "721 is not cuban prime"));
	assert((cubanPrime(217) == "217 is not cuban prime"));
	assert((cubanPrime(4447) == "4447 is cuban prime"));
	assert((cubanPrime(7) == "7 is cuban prime"));

    cout << "success" << endl;

    return 0;
}