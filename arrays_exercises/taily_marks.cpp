// https://edabit.com/challenge/deeB7yAgunvLKf4fJ

#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>

std::vector<int> switchNotation(std::vector<int> scores, std::string desired_notation) {
	std::vector<int> answer {};
    if (desired_notation == "normal"){
        for (int &i: scores){
            int temp {0};
            do {temp += i % 10;
                i /= 10;
            } while (i > 0);
            answer.push_back(temp);
        }
    }
    else {
        for (int &i: scores){
            int temp {0};
            while (i > 0){
                if (i >= 5){
                    if (temp == 0){
                        temp += 5;
                        i -= 5;
                    }
                    else {
                        temp *= 10;
                        temp += 5;
                        i -= 5;
                    }
                }
                else {
                    if (temp == 0){
                        temp += i;
                        i = 0;
                    }
                    else {
                        temp *= 10;
                        temp += i;
                        i = 0;
                    }
                }
            }
            answer.push_back(temp);
        }
    }
    return answer;
}


int main(){
    std::cout << std::noboolalpha;

    std::vector<int> assert_inp_1 {3, 55, 55551};
    std::vector<int> assert_res_1 {3, 10, 21};
    assert((switchNotation(assert_inp_1, "normal") == assert_res_1));

    std::vector<int> assert_inp_2 {15, 29, 5, 3};
    std::vector<int> assert_res_2 {555, 555554, 5, 3};
    assert((switchNotation(assert_inp_2, "tally") == assert_res_2));

    std::cout << "Success" << std::endl;
    return 0;
}