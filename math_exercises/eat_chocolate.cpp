// https://edabit.com/challenge/3bDc3B7NbNHxQBRZu

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

int getPrice(const string &text){
    istringstream iss {text};
    string word;
    int price = 0;
    while(iss >> word){
        if (word.find_first_of("0123456789") != string::npos){
            auto it = word.begin();
            while (it != word.end()){
                if (isdigit(*it) || *it == '-')
                    ++it;
                else {
                    it = word.erase(it);
                }
            }
            price = stoi(word);
            break;
        }
    }
    return price;
}

int countChocolates(string money, string cost) {
    int m = getPrice(money), c = getPrice(cost);
    int counter = 0, bonus = 0;
    if (c <= 0)
        return counter;
    while (m >= c){
        ++counter; ++bonus;
        m -= c;
        if (bonus == 3){
            bonus = 1;
            ++counter;
        }
    }
    return counter;
}

int main()
{
    cout << "Hello" << endl;
    cout << getPrice("One chocolate costs 2$") << endl;
  // cout << countChocolates("-2$", "One chocolate costs 2$") << endl;
  return 0;
}