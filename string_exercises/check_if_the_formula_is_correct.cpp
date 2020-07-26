// https://edabit.com/challenge/gvcmR4McLyia2PDac

#include <string>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <cctype>

bool formula(std::string str) {
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    std::size_t found = str.find('a');
    while (found != std::string::npos)
    {
        str.replace(found, 1, "4");
        found = str.find('a');
    }
    int expressions = std::count(str.begin(), str.end(), '=') + 1;
    // std::cout << "Number of expressions = " << expressions << std::endl;
    // std::cout << "String after transformations = " << str << std::endl;
    double orig_expr, comp_expr;
    double temp_expr = 0;

    std::vector<int> nums {};
    std::string num {};
    std::vector<char> operators {};

    for (int i = 0, j = 0; i < expressions; ++i)
    {   
        // std::cout << "i = " << i << std::endl;
        while (true)
        {   
            // std::cout << "NUM = " << num << std::endl;
            if (j == str.size())
            {   
                // std::cout << "INSIDE" << std::endl;
                // std::cout << "Temp expr = " << temp_expr << std::endl;
                // std::cout << "num = " << num << std::endl;
                if (operators.size() < 1)
                    temp_expr = std::stod(num);
                else
                {
                    if (num.size() >= 1)
                    {
                        nums.push_back(std::stoi(num));
                        num.clear();
                    }
                    temp_expr = 0;
                    for (int k = 0; k < operators.size(); ++k)
                    {
                        if (k == 0)
                            temp_expr += nums[k];
                        
                        if (operators[k] == '+')
                            temp_expr += nums[k+1];
                        else if (operators[k] == '-')
                            temp_expr -= nums[k+1];
                        else if (operators[k] == '*')
                            temp_expr *= nums[k+1];
                        else if (operators[k] == '/')
                            temp_expr /= nums[k+1];
                    }
                }
                // std::cout << "Temp expr = " << temp_expr << std::endl;
                if (orig_expr != temp_expr)
                    return false;
                break;                
            }

            if (str[j] == '=')
            {   
                if (operators.size() != 0)
                {
                    if (num.size() >= 1)
                    {
                        nums.push_back(std::stoi(num));
                        num.clear();
                    }
                    temp_expr = 0;
                    for (int k = 0; k < operators.size(); ++k)
                    {
                        if (k == 0)
                            temp_expr += nums[k];
                        
                        if (operators[k] == '+')
                            temp_expr += nums[k+1];
                        else if (operators[k] == '-')
                            temp_expr -= nums[k+1];
                        else if (operators[k] == '*')
                            temp_expr *= nums[k+1];
                        else if (operators[k] == '/')
                            temp_expr /= nums[k+1];
                    }
                    // std::cout << "SUPER temp = " << temp_expr << std::endl;
                }
                else
                {
                    temp_expr = std::stod(num);
                    // std::cout << "Temp expr when no operators = " << temp_expr << std::endl;
                    num.clear();
                }

                if (i == 0){
                    orig_expr = temp_expr;
                    // std::cout << "Original expr = " << orig_expr << std::endl;
                }
                else 
                {
                    if (orig_expr != temp_expr)
                    {   
                        std::cout << "F" << std::endl;
                        return false;
                    }
                }
                nums.clear();
                operators.clear();
                ++j;
                break;
            }

            if (std::isdigit(str[j]))
            {
                num.push_back(str[j]);
            }
            else 
            {
                operators.push_back(str[j]);
                if (num.size() >= 1)
                {
                    nums.push_back(std::stoi(num));
                    num.clear();
                }
            }
            ++j;
        }
    }
    return true;
}

int main(){

    assert((formula("6 * 4 = 24") == true));
	assert((formula("120 - 7 = 100") == false));
	assert((formula("16 - 8 = 16 / 2 = 64 / 8") == true));
	assert((formula("a = a") == true));
	assert((formula("a * 7 = 90") == false));
	assert((formula("16 * 10 = 160 = 14 + 120") == false));
	assert((formula("a=4") == true));
	assert((formula("1000 / 10 = 100 = 2 * 50") == true));
	assert((formula("18 / 17 = 2") == false));
	// // assert((formula("(1+2+3+4+5+6+7+8)/a=9") == true));
	assert((formula("2 * 2 * 2 = a * 2 = 8") == true));
	assert((formula("   8/       9 =       5") == false));
	assert((formula("1111           /     101=     11") == true));
	assert((formula("a / a = a - 3") == true));

    std::cout << "Success" << std::endl;

    return 0;
}