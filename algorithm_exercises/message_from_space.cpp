// https://edabit.com/challenge/58iEEYqxFdnkBjEiA

#include <algorithm>
#include <cassert>
#include <cctype>
#include <iostream>
#include <iterator>
#include <string>

std::string const spaceMessage(std::string const &str)
{
    std::string msg{str};
    // find first ending bracket
    auto iter = std::find(msg.begin(), msg.end(), ']');
    while (iter != msg.end())
    {
        auto endIter = iter;
        char c = *iter;
        while (c != '[')
        {
            --iter;
            c = *iter;
        }

        std::string temp{};
        std::copy(iter + 1, endIter, std::back_inserter(temp));

        // remove the enclosed string from main string
        int idx = iter - msg.begin();
        msg.erase(iter, endIter + 1);

        // extract number and following string
        std::string repetition{}, toRepeat{};
        auto temp_iter = temp.cbegin();
        while (temp_iter != temp.cend())
        {
            auto c = *temp_iter;
            if (std::isdigit(c))
            {
                repetition.push_back(c);
                ++temp_iter;
            }
            else
            {
                std::copy(temp_iter, temp.cend(), std::back_inserter(toRepeat));
                break;
            }
        }
        auto numRepetitions = std::stoi(repetition) - 1;
        std::string const cpToRepeat{toRepeat};
        while (numRepetitions > 0)
        {
            toRepeat.append(cpToRepeat);
            --numRepetitions;
        }

        // insert decoded string to main string
        msg.insert(msg.begin() + idx, toRepeat.begin(), toRepeat.end());

        // look for next brackets
        iter = std::find(msg.begin(), msg.end(), ']');
    }
    return msg;
}

int main()
{
    assert((spaceMessage("ABCD") == "ABCD"));
    assert((spaceMessage("AB[3CD]") == "ABCDCDCD"));
    assert((spaceMessage("AB[2[3CD]]") == "ABCDCDCDCDCDCD"));
    assert((spaceMessage("IF[2E]LG[5O]D") == "IFEELGOOOOOD"));
    assert((spaceMessage("AB[2C[2EF]G]") == "ABCEFEFGCEFEFG"));
    assert((spaceMessage("MU[2B][2A][2S][2H][2I]RISN[4O]TAMA[4Z]ING") == "MUBBAASSHHIIRISNOOOOTAMAZZZZING"));
    std::cout << "success" << std::endl;

    return 0;
}