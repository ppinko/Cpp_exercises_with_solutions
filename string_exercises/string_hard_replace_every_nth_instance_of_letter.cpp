// https://edabit.com/challenge/FBN4ohizzRMZFyjhd

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

std::string replaceNth(std::string str, int nth, std::string oldChar, std::string newChar) {
	if (nth <= 0 || nth > std::count(str.begin(), str.end(), oldChar[0]))
        return str;
    int counter = 0;
    std::string answer {};
    for (char &c: str){
        if (c == oldChar[0]) {
            counter++;
            answer.push_back(c);
        } else {
            answer.push_back(c);
        }
        if (counter == nth){
            answer.pop_back();
            answer.append(newChar);
            counter = 0;
        }
    }
    return answer;   
}

int main(){
    std::cout << replaceNth("Sometimes it is better to just walk away from things and go back to them later when you’re in a better frame of mind.", 3, "e", "_") << " should equal to 6." << std::endl;
    std::cout << "Success" << std::endl;
    return 0;
}