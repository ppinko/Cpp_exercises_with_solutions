// https://edabit.com/challenge/98tt3RfDYBPCzpJi2

#include <iostream>
#include <cassert>
#include <vector>
#include <cctype>

bool overTwentyOne(std::vector<char> cards) {
	int blackjack = 0;
    for (auto const &c : cards)
    {
        if (std::isdigit(c))
            blackjack += (int)c - (int)'0';
        else if (c == 'A')
        {
            if (blackjack >= 11)
                blackjack += 11;
            else
                blackjack += 1;
        }
        else
            blackjack += 10;
        
        if (blackjack > 21)
            return true;
    }
    return false;
}

int main()
{
	assert((overTwentyOne({'A', '2', '3'}) == false));
	assert((overTwentyOne({'A', 'J', 'K'}) == false));
	assert((overTwentyOne({'A', 'J', 'K', 'Q'}) == true));
	assert((overTwentyOne({'5', '3', '6', '6', '7', '9'}) == true));

    return 0;
}