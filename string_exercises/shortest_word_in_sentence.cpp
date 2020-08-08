// https://edabit.com/challenge/WSmaJEJqxzXkqyzMj

#include <cassert>
#include <iostream>

#include <vector>
#include <sstream>
#include <climits>
#include <algorithm>
#include <iterator>
#include <cctype>
#include <string>

void word_lower(std::string &s)
{
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){return std::tolower(c);});
}

std::vector<std::string> findShortestWords(std::string s) {
	std::vector<std::string> answer {};
    std::string without_punctuation {};
    std::copy_if(s.begin(), s.end(), std::back_inserter(without_punctuation), [](char c){return !std::ispunct(c);});
    std::istringstream iss {without_punctuation};
    std::string temp {};
    int max_len = INT_MAX;
    while (iss >> temp)
    {
        if (temp.size() <= max_len)
        {   
            if (std::isdigit(temp.at(0)))
                continue; 
            if (temp.size() < max_len)
            {    
                answer.clear();
                max_len = temp.size();
            }
            word_lower(temp);
            answer.push_back(temp);
        }
    }
    std::sort(answer.begin(), answer.end(), [] (std::string a, std::string b) {return a < b;});
    return answer;
}

int main()
{   
    // auto vec = findShortestWords("The only person you are destined to become is the person you decide to be.");
    // std::copy(vec.begin(), vec.end(), std::ostream_iterator<std::string>(std::cout, " "));

	assert((findShortestWords("Strive not to be a success, but rather to be of value.") == std::vector<std::string>({"a"})));
	assert((findShortestWords("You miss 100% of the shots you don’t take.") == std::vector<std::string>({"of"})));
	assert((findShortestWords("Life is what happens to you while you’re busy making other plans.") == std::vector<std::string>({"is", "to"})));
	assert((findShortestWords("We become what we think about.") == std::vector<std::string>({"we", "we"})));
	assert((findShortestWords("The most common way people give up their power is by thinking they don’t have any.") == std::vector<std::string>({"by", "is", "up"})));
	assert((findShortestWords("The best time to plant the tree was 20 years ago. The second best time is now.") == std::vector<std::string>({"is", "to"})));
	assert((findShortestWords("Your time is limited, so don’t waste it living someone else’s life.") == std::vector<std::string>({"is", "it", "so"})));
	assert((findShortestWords("You can never cross the ocean until you have the courage to lose sight of the shore.") == std::vector<std::string>({"of", "to"})));
	assert((findShortestWords("There is only one way to avoid criticism: do nothing, say nothing, and be nothing.") == std::vector<std::string>({"be", "do", "is", "to" })));
	assert((findShortestWords("The only person you are destined to become is the person you decide to be.") == std::vector<std::string>({"be", "is", "to", "to"})));
	assert((findShortestWords("What lies behind us and what lies before us are tiny matters compared to what lies within us.") == std::vector<std::string>({"to", "us", "us", "us"})));
	assert((findShortestWords("If you are depressed you are living in the past. If you are anxious you are living in the future. If you are at peace you are living in the present.") == std::vector<std::string>({"at", "if", "if", "if", "in", "in", "in"})));
	assert((findShortestWords("Happiness depends upon ourselves.") == std::vector<std::string>({"upon"})));
	assert((findShortestWords("Chase two rabbits, catch none.") == std::vector<std::string>({"two"})));
	assert((findShortestWords("Only the truth of who you are, if realized, will set you free.") == std::vector<std::string>({"if", "of"})));
	assert((findShortestWords("If you end up with a boring miserable life because you listened to your parents, your teacher, your priest, or some guy on television, then you deserve it.") == std::vector<std::string>({"a"})));
	assert((findShortestWords("To accomplish great things, we must not only act, but also dream; not only plan, but also believe.") == std::vector<std::string>({"to", "we"})));
	assert((findShortestWords("A tiger doesn’t lose sleep over the opinion of sheep.") == std::vector<std::string>({"a"})));
	assert((findShortestWords("Kindness is a language that the deaf can hear and the blind can see.") == std::vector<std::string>({"a"})));
	assert((findShortestWords("Being realistic is the most common path to mediocrity.") == std::vector<std::string>({"is", "to"})));
	assert((findShortestWords("Bravery means finding something more important than fear.") == std::vector<std::string>({"fear", "more", "than"})));
	assert((findShortestWords("Can you imagine what I would do if I could do all I can?") == std::vector<std::string>({"i", "i", "i"})));
	assert((findShortestWords("Believe you can and you’re halfway there.") == std::vector<std::string>({"and", "can", "you"})));
	assert((findShortestWords("Remember that happiness is a way of travel, not a destination.") == std::vector<std::string>({"a", "a"})));
	assert((findShortestWords("May the best day of your past be the worst day of your future.") == std::vector<std::string>({"be", "of", "of"})));

    std::cout << "Success" << std::endl;

    return 0;
}