// https://edabit.com/challenge/xocBnmFJRR4ovxeuk
#include <iostream>

#include <string>
#include <vector>

using namespace std;

vector<long> lookAndSay(long start, int n) {
    vector<long> answer {start};
    for (int i = 0; i < n-1; ++i){
        string str = to_string(start);
        string element {};
        char c = str.at(0);
        int counter = 1;
    for (int j = 1; j < str.size(); ++j){
        if (str.at(j) == c)
            ++counter;
        else {
            element.append(to_string(counter));
            element.push_back(c);
            counter = 1;
            c = str.at(j);
        }    
    }
    element.append(to_string(counter));
    element.push_back(c);
    start = stol(element);
    answer.push_back(start);
    }
    return answer;
}

int main()
{

    cout << "END" << endl;
}