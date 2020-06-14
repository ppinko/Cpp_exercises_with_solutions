// https://edabit.com/challenge/8omtKypw8npc9crKB


#include <iostream>
#include <string>
#include <algorithm>

std::string simplify(std::string str);
int gcd(int a, int b);

int gcd(int a, int b) {
    if (a % b == 0) return b;
    else return gcd(b, a%b);
}

std::string simplify(std::string str) {
	std::string answer {};
    std::string::iterator iter = std::find(str.begin(), str.end(), '/');
    std::string s_first (str.begin(), iter);
    std::string s_second (iter + 1, str.end());
    int first = std::stoi(s_first);
    int second = std::stoi(s_second);
    while (gcd(first, second) != 1){
        int div = gcd(first, second);
        first /= div;
        second /= div;
    }
    if (second == 1){
        std::string max_val = std::to_string(first);
        return max_val;
    }
    answer.append(std::to_string(first));
    answer.push_back('/');
    answer.append(std::to_string(second));
    return answer;
}


int main(){
    std::cout << simplify("4/6") << std::endl;
    std::cout << "Success" << std::endl;
    return 0;
}