// https://edabit.com/challenge/FYKdBjg2kf7sAANiT

#include <cassert>
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <cctype>
#include <algorithm>
#include <set>
#include <iterator>
#include <cmath>

bool evaluate_brackets(const std::string &str);
bool adding_multiply_sign(std::string &str);
void multiply_sign_in_front_of_x(std::string &str);
int evalPolynomial(std::string poly, int num); 
bool testing_operator_correctness(const std::string &str);
void replace_x(std::string &str, const int num);
int calculation(std::string &str); 
void split_operations(const std::string &str, std::vector<char> &symbols, std::vector<int> &nums);

void split_operations(const std::string &str, std::vector<char> &symbols, std::vector<int> &nums)
{
    std::string temp_num {};
    for (const char &c : str)
    {
        if (std::isdigit(c))
            temp_num.push_back(c);
        else
        {
            symbols.push_back(c);
            if (temp_num.size() > 0)
            {
                nums.push_back(std::stoi(temp_num));
                temp_num.clear();
            }
        }
    }
    if (temp_num.size() > 0)
        nums.push_back(std::stoi(temp_num));
}

bool evaluate_brackets(const std::string &str)
{
    int count_brackets = 0;
    for (const auto &c : str)
    {
        if (c == '(')
            ++count_brackets;
        else if (c == ')')
        {
            --count_brackets;
            if (count_brackets < 0)
                return false;
        } 
    }
    if (count_brackets != 0)
        return false;
    return true;
}

bool testing_operator_correctness(const std::string &str){
    std::set<char> operators {'+', '-', '/', '*', '^'};
    bool oper = false;
    if (!std::isdigit(str.at(0)))
        return false;
    for (int j = 1; j < str.size(); ++j)
    {   
        auto it = operators.find(str.at(j));
        if (std::isdigit(str.at(j)) || str.at(j) == ')')
            oper = false;
        else if (oper)
        {
            if (!std::isdigit(str.at(j)) && str.at(j) != '(')
                return false;
            else if (str.at(j) == '(')
                continue;
            else 
                oper = false;
        }
        else if (it != operators.end())
            oper = true;
        else
            return false;
    }
    return true;
}

bool adding_multiply_sign(std::string &str)
{
    auto it = std::find(str.begin(), str.end(), '(');
    while (it != str.end())
    {
        if (it == str.begin())
            ++it;
        else
        {
            --it;
            if (std::isdigit(*it) || *it == 'x')
            {
                
                str.insert(it+1, '*');
                it += 3;
            }
            else
                return false;
        }
        it = std::find(it, str.end(), '(');
    }
    return true;
}

void multiply_sign_in_front_of_x(std::string &str)
{
    auto it = std::find(str.begin(), str.end(), 'x');
    while (it != str.end())
    {
        if (it == str.begin())
            ++it;
        else
        {
            --it;
            if (std::isdigit(*it))
            {
                
                str.insert(it+1, '*');
                it += 3;
            }
            else
            {
                it += 2;
            }
        }
        it = std::find(it, str.end(), 'x');
    }
}

void replace_x(std::string &str, const int num)
{
    std::string num_str = std::to_string(num);
    int num_x = std::count(str.begin(), str.end(), 'x');
    for (int i = 0; i < num_x; ++i)
    {
        int index = str.find('x');
        str.replace(index, 1, num_str);
    }
}

int calculation(std::string &str)
{
    while (str.rfind('(') != std::string::npos)
        {
            int start_parenthesis = str.rfind('(');
            int end_parenthesis = str.find(')', start_parenthesis);
            std::string temp = str.substr(start_parenthesis+1, end_parenthesis - start_parenthesis - 1);
            int rec_temp = calculation(temp);
            temp.clear();
            temp = std::to_string(rec_temp);
            str.replace(start_parenthesis, end_parenthesis - start_parenthesis + 1, temp);
        }
    std::vector<char> operators {};
    std::vector<int> operands {};
    split_operations(str, operators, operands);
    int result = 0;
    auto power = std::find(operators.begin(), operators.end(), '^');
    while (power != operators.end())
    {
        int index_power = power - operators.begin();
        int temp_result = std::pow(operands.at(index_power), operands.at(index_power + 1));
        operators.erase(power);
        operands.at(index_power+1) = temp_result;
        operands.erase(operands.begin() + index_power);
        power = std::find(operators.begin(), operators.end(), '^');
    }
    if (operators.size() == 0)
        return operands.at(0);

    auto multiplication = std::find(operators.begin(), operators.end(), '*');
    while (multiplication != operators.end())
    {
        int index_multiplication = multiplication - operators.begin();
        int temp_result = operands.at(index_multiplication) * operands.at(index_multiplication + 1);
        operators.erase(multiplication);
        operands.at(index_multiplication+1) = temp_result;
        operands.erase(operands.begin() + index_multiplication);
        multiplication = std::find(operators.begin(), operators.end(), '*');
    }    

    if (operators.size() == 0)
        return operands.at(0);

    auto division = std::find(operators.begin(), operators.end(), '/');
    while (division != operators.end())
    {
        int index_division = division - operators.begin();
        int temp_result = operands.at(index_division) / operands.at(index_division + 1);
        operators.erase(division);
        operands.at(index_division+1) = temp_result;
        operands.erase(operands.begin() + index_division);
        division = std::find(operators.begin(), operators.end(), '/');
    }    

    if (operators.size() == 0)
        return operands.at(0);

    auto addition = std::find(operators.begin(), operators.end(), '+');
    while (addition != operators.end())
    {
        int index_addition = addition - operators.begin();
        int temp_result = operands.at(index_addition) + operands.at(index_addition + 1);
        operators.erase(addition);
        operands.at(index_addition+1) = temp_result;
        operands.erase(operands.begin() + index_addition);
        addition = std::find(operators.begin(), operators.end(), '+');
    }   

    if (operators.size() == 0)
        return operands.at(0);

    auto substraction = std::find(operators.begin(), operators.end(), '-');
    while (substraction != operators.end())
    {
        int index_substraction = substraction - operators.begin();
        int temp_result = operands.at(index_substraction) - operands.at(index_substraction + 1);
        operators.erase(substraction);
        operands.at(index_substraction+1) = temp_result;
        operands.erase(operands.begin() + index_substraction);
        substraction = std::find(operators.begin(), operators.end(), '-');
    }   

    return operands.at(0);    
}

int evalPolynomial(std::string poly, int num) {
    poly.erase(std::remove(poly.begin(), poly.end(), ' '), poly.end());
    if (poly.size() == 0 || !evaluate_brackets(poly))
        return -1;
    if (poly.find('(') != std::string::npos){
        bool test = adding_multiply_sign(poly);
        if (!test)
            return -1;
    }
    if (poly.find('x') != std::string::npos)
    {   
        multiply_sign_in_front_of_x(poly);
        replace_x(poly, num);
    }
    if (!testing_operator_correctness(poly))
        return -1;
    return calculation(poly);
}

int main()
{
    // // Testing adding_multiply_sign function
    // std::string str {"2(x+2)+x(x-1)"};
    // adding_multiply_sign(str);
    // assert((str == "2*(x+2)+x*(x-1)"));

    // // Testing multiply_sign_in_front_of_x function
    // std::string str_2 {"3x^2/8"};
    // multiply_sign_in_front_of_x(str_2);
    // assert((str_2 == "3*x^2/8"));

    // // Testing multiply_sign_in_front_of_x function
    // std::string str_3 {"3x&2/8"};
    // assert((testing_operator_correctness(str_3) == false));

    // std::string str_4 {"5//2"};
    // assert((testing_operator_correctness(str_4) == false));

    // std::string str_5 {"5/2*2*(2+65)"};
    // assert((testing_operator_correctness(str_5) == true));

    // // Testing replace_x function
    // std::string str_6 {"2(x+2)+x(x-1)"};
    // replace_x(str_6, 10);
    // assert((str_6 == "2(10+2)+10(10-1)"));

    // Testing split operations function

    // std::string test_split_str = "15*205-10";
    // std::vector<char> test_split_symbols {};
    // std::vector<int> test_split_nums {};
    // split_operations(test_split_str, test_split_symbols, test_split_nums);
    // std::copy(test_split_symbols.begin(), test_split_symbols.end(),
    //     std::ostream_iterator<char>(std::cout, " "));
    // std::cout << std::endl;
    // std::copy(test_split_nums.begin(), test_split_nums.end(),
    //     std::ostream_iterator<int>(std::cout, " "));
    // std::cout << std::endl;

    // // Testing calculation function
    // std::string calc_1 {"2+2*2"};
    // assert((calculation(calc_1) == 6));

    // std::string calc_2 {"(2+2)*2"};
    // assert((calculation(calc_2) == 8));
    // std::cout << evalPolynomial("3x^2/8", 4) << std::endl;

    assert((evalPolynomial("4(x + 3))/2", 5) == -1)); // Invalid because parentheses not balanced.
    assert((evalPolynomial("x+1", 1) == 2));
	assert((evalPolynomial("x^2", 2) == 4)); // Check exponentation.
	assert((evalPolynomial("2(x+2)+x(x-1)", 3) == 16)); // Check multiplication.
	assert((evalPolynomial("3x^2/8", 4) == 6));
    assert((evalPolynomial("3x&2/8", 5) == -1)); // & not a valid mathematical expression.
    assert((evalPolynomial("print(x)", 6) == -1)); // print(x) not a valid mathematical expression.
	assert((evalPolynomial("x//2", 7) == -1)); // // not a valid operator.
	assert((evalPolynomial("", 8) == -1)); // Expression empty.

    // std::string test {"pawel"};
    // if (test.rfind('o') == std::string::npos) 
    //     std::cout << "Test successfull" << std::endl;

    std::cout << "Success" << std::endl;

    return 0;
}