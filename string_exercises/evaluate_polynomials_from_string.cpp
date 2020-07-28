// https://edabit.com/challenge/FYKdBjg2kf7sAANiT

#include <cassert>
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <cctype>

bool evaluate_brackets(std::string &str);
int evalPolynomial(std::string poly, int num); 

bool evaluate_brackets(std::string &str)
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

int evalPolynomial(std::string poly, int num) {
	if (!evaluate_brackets(poly))
        return -1;
    return 0;
}

int main()
{
    assert((evalPolynomial("4(x + 3))/2", 5) == -1)); // Invalid because parentheses not balanced.
    // assert((evalPolynomial("x+1", 1) == 2));
	// assert((evalPolynomial("x^2", 2) == 4)); // Check exponentation.
	// assert((evalPolynomial("2(x+2)+x(x-1)", 3) == 16)); // Check multiplication.
	// assert((evalPolynomial("3x^2/8", 4) == 6));
	// assert((evalPolynomial("3x&2/8", 5) == -1)); // & not a valid mathematical expression.
	// assert((evalPolynomial("print(x)", 6) == -1)); // print(x) not a valid mathematical expression.
	// assert((evalPolynomial("x//2", 7) == -1)); // // not a valid operator.
	// assert((evalPolynomial("", 8) == -1)); // Expression empty.

    std::cout << "Success" << std::endl;

    return 0;
}