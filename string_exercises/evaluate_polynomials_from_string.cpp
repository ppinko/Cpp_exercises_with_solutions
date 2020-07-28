// https://edabit.com/challenge/FYKdBjg2kf7sAANiT

#include <cassert>
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <cctype>
#include <algorithm>
#include <set>

bool evaluate_brackets(const std::string &str);
bool adding_multiply_sign(std::string &str);
void multiply_sign_in_front_of_x(std::string &str);
int evalPolynomial(std::string poly, int num); 
bool testing_operator_correctness(const std::string &str);
void replace_x(std::string &str, const int num);
int calculation(std::string str); // NEXT STEP IMPLEMENT RECURSIVE FORMULA FOR BRACKETS()

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
    return 0;

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

    assert((evalPolynomial("4(x + 3))/2", 5) == -1)); // Invalid because parentheses not balanced.
    // assert((evalPolynomial("x+1", 1) == 2));
	// assert((evalPolynomial("x^2", 2) == 4)); // Check exponentation.
	// assert((evalPolynomial("2(x+2)+x(x-1)", 3) == 16)); // Check multiplication.
	// assert((evalPolynomial("3x^2/8", 4) == 6));
    assert((evalPolynomial("3x&2/8", 5) == -1)); // & not a valid mathematical expression.
    assert((evalPolynomial("print(x)", 6) == -1)); // print(x) not a valid mathematical expression.
	assert((evalPolynomial("x//2", 7) == -1)); // // not a valid operator.
	assert((evalPolynomial("", 8) == -1)); // Expression empty.

    std::cout << "Success" << std::endl;

    return 0;
}