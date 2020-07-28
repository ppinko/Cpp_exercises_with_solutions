// https://edabit.com/challenge/FYKdBjg2kf7sAANiT

#include <cassert>
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <cctype>
#include <algorithm>

bool evaluate_brackets(const std::string &str);
void adding_multiply_sign(std::string &str);
void multiply_sign_in_front_of_x(std::string &str);
int evalPolynomial(std::string poly, int num); 


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

void adding_multiply_sign(std::string &str)
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
        }
        it = std::find(it, str.end(), '(');
    }
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

int evalPolynomial(std::string poly, int num) {
    poly.erase(std::remove(poly.begin(), poly.end(), ' '), poly.end());
    if (poly.size() == 0 || !evaluate_brackets(poly))
        return -1;
    return 0;

}

int main()
{
    // Testing adding_multiply_sign function
    std::string str {"2(x+2)+x(x-1)"};
    adding_multiply_sign(str);
    assert((str == "2*(x+2)+x*(x-1)"));

    // Testing multiply_sign_in_front_of_x function
    std::string str_2 {"3x^2/8"};
    multiply_sign_in_front_of_x(str_2);
    assert((str_2 == "3*x^2/8"));

    assert((evalPolynomial("4(x + 3))/2", 5) == -1)); // Invalid because parentheses not balanced.
    // assert((evalPolynomial("x+1", 1) == 2));
	// assert((evalPolynomial("x^2", 2) == 4)); // Check exponentation.
	// assert((evalPolynomial("2(x+2)+x(x-1)", 3) == 16)); // Check multiplication.
	// assert((evalPolynomial("3x^2/8", 4) == 6));
	// assert((evalPolynomial("3x&2/8", 5) == -1)); // & not a valid mathematical expression.
	// assert((evalPolynomial("print(x)", 6) == -1)); // print(x) not a valid mathematical expression.
	// assert((evalPolynomial("x//2", 7) == -1)); // // not a valid operator.
	assert((evalPolynomial("", 8) == -1)); // Expression empty.

    std::cout << "Success" << std::endl;

    return 0;
}