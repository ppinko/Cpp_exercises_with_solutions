/*
https://edabit.com/challenge/SWQYtLjAqpSLn5F44
*/


#include <iostream>
#include <vector>
#include <string>

std::string convertToRoman(int num) {
	std::string roman {};
    if (num >= 900){
        if (num >= 1000){
            int num_M = num / 1000;
            for (int i = 0; i < num_M; i++)
                roman.push_back('M');
            num = num - 1000 * num_M;
        }
        if (num >= 900){
            roman.push_back('C');
            roman.push_back('M');
            num -= 900;
        } 
    }
    if (num >= 400){
        if (num >= 500){
            roman.push_back('D');
            num -= 500;
        }
        else {
            roman.push_back('C');
            roman.push_back('D');
            num -= 400;
        }
    }
    if (num >= 90){
        if (num >= 100){
            int num_C = num / 100;
            for (int i = 0; i < num_C; i++)
                roman.push_back('C');
            num = num - 100 * num_C;   
        }
        if (num >= 90){
            roman.push_back('X');
            roman.push_back('C');
            num -= 90;
        }
    }
    if (num >= 40){
        if (num >= 50){
            roman.push_back('L');
            num -= 50;
        }
        else {
            roman.push_back('X');
            roman.push_back('L');
            num -= 40;
        }
    }
    if (num >= 9){
        if (num >= 10){
            int num_X = num / 10;
            for (int i = 0; i < num_X; i++)
                roman.push_back('X');
            num = num - 10 * num_X;               
        }
        if (num == 9){
            roman.push_back('I');
            roman.push_back('X');
            return roman;
        }
    }
    if (num >= 4){
        if (num >= 5){
            roman.push_back('V');
            num -= 5;
        }
        else {
            roman.push_back('I');
            roman.push_back('V');
            return roman;;
        }
    }
    if (num > 0){
        for (int i = 0; i < num; i++)
            roman.push_back('I');
    }    
    return roman;    
}

int main(){
    std::cout << "Success" << std::endl;
    return 0;
}