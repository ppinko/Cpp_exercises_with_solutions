// https://edabit.com/challenge/LcQv54kCSEwPArq5G

#include <iostream>
#include <string>
#include <cassert>
#include <gsl/gsl>
#include <list>
#include <sstream>
#include <algorithm>

std::string flip(std::string str, std::string spec) {
    std::istringstream iss {str};
    std::ostringstream oss {};
    std::list<std::string> words {};
    std::string temp {};
    while (iss >> temp)
    {
        words.push_back(temp);
    }

    if (spec == "word")
    {
        std::for_each(words.begin(), words.end(), [](std::string &str)
            {std::reverse(str.begin(), str.end());});
    } else {
        std::reverse(words.begin(), words.end());
    } 
    for (const auto& word : words)
    {
        oss << word << " ";
    }
    std::string answer {oss.str()};
    answer.pop_back();
    return answer;
}

int main(){

    std::string str1 = "There's never enough time to do all the nothing you want";
    std::string str2 = "I have all these great genes but they're recessive";
    std::string str3 = "I like maxims that don't encourage behavior modification";

    assert((flip("Hello", "word") == "olleH"));
    assert((flip("Hello", "sentence") == "Hello"));
    assert((flip(str1, "word") == "s'erehT reven hguone emit ot od lla eht gnihton uoy tnaw"));
    assert((flip(str1, "sentence") == "want you nothing the all do to time enough never There's"));
    assert((flip(str2, "word") == "I evah lla eseht taerg seneg tub er'yeht evissecer"));
    assert((flip(str2, "sentence") == "recessive they're but genes great these all have I"));
    assert((flip(str3, "word") == "I ekil smixam taht t'nod egaruocne roivaheb noitacifidom"));
    assert((flip(str3, "sentence") == "modification behavior encourage don't that maxims like I"));


    return 0;
}