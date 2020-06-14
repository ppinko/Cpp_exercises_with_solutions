// https://edabit.com/challenge/iToyry6NSoTRHN7eF

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

bool isStretched(std::string str1, std::string str2) {
    int s1 = str1.find_first_not_of(str1.at(0));
    int s2 = str2.find_first_not_of(str2.at(0));
    float ratio = static_cast<float>(s1)/s2;
    // std::cout << "ration = " << ratio << "\n";
    int last_s2 = 0;
    int last_s1 = 0;
    while (true){
        char c = str2.at(last_s2);
        int s1_test = str1.find_first_not_of(str1.at(last_s1), last_s1);
        int s2_test = str2.find_first_not_of(str2.at(last_s2), last_s2);
        // std::cout << "s1 = " << s1_test << " s2 = " << s2_test << "\n";
        if (s1_test == -1 && s2_test == -1) return true;
        else if (s1_test == -1 || s2_test == -1) return false;
        else if ((s1_test -last_s1) / (float)(s2_test - last_s2) != ratio) {
            return false;
        }
        last_s1 = s1_test;
        last_s2 = s2_test;
    }
}


int main(){
    std::cout << isStretched("pppaaannndddaaa", "panda") << std::endl;
    std::cout << "Success" << std::endl;
    return 0;
}