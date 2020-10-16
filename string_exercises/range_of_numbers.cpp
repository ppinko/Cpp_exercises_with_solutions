// https://edabit.com/challenge/29mzN9b9ckfmuR5Mh
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string numbersRange(vector<int> arr) {
    if (arr.size() == 0)
        return "";
    string answer {};
    sort(arr.begin(), arr.end());
    vector<int> vec {arr.at(0)};
    for (int i = 1; i < arr.size(); ++i){
        if (arr.at(i) - vec.back() == 1)
            vec.push_back(arr.at(i));
        else if (vec.size() >= 3){
            answer.append(to_string(vec.front()));
            answer.push_back('-');
            answer.append(to_string(vec.back()));
            answer.push_back(',');
            vec.clear();
            vec.push_back(arr.at(i));
        } else {
            for (auto &c : vec){
                answer.append(to_string(c));
                answer.push_back(',');
                vec.clear();
                vec.push_back(arr.at(i));
            }    
        }
    }
   
    if (vec.size() >= 3){
        answer.append(to_string(vec.front()));
        answer.push_back('-');
        answer.append(to_string(vec.back()));
        answer.push_back(',');
    } else {
        for (auto &c : vec){
            answer.append(to_string(c));
            answer.push_back(',');
        }    
    }

    answer.pop_back();
    return answer;
}

int main()
{
    cout << "END" << endl;
}