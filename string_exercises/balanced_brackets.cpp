// https://edabit.com/challenge/4fx4rbxcvcskDBY5P

#include <iostream>
#include <cassert>
#include <string>
#include <unordered_map>

using namespace std;

bool isBalanced(string str) {
    if (str.size() % 2 == 1)
        return false;

    unordered_map<char, char> brackets {};
    brackets.emplace('}', '{');
    brackets.emplace(')', '(');
    brackets.emplace(']', '[');
    while (str.size() != 0){
        bool flag = false;
        for (int i = 0; i < str.size(); ++i){
            auto it = brackets.find(str.at(i));
            if (it != brackets.end()){
                if (i == 0 || str.at(i-1) != it->second)
                    return false;
                else {
                    flag = true;
                    str.erase(i-1, 2);
                    break;
                }
            }
        }
        if (!flag)
            return false;
    }
    return true;
}

int main(){

	assert((isBalanced("()") == true));
	assert((isBalanced("{[()]}") == true));
	assert((isBalanced("{{[[(())]]}}") == true));
	assert((isBalanced("{{[[(())[]]]}}") == true));
	assert((isBalanced("[()]{}{[()()]()}") == true));
	assert((isBalanced("{[([)]]}") == false));
	assert((isBalanced("{[(") == false));
	assert((isBalanced("])}") == false));
	assert((isBalanced("[[]") == false));
	assert((isBalanced("{)(}") == false));
	assert((isBalanced("{{[[([())]]]}}") == false));

    std::cout << "Success" << std::endl;

    return 0;
}