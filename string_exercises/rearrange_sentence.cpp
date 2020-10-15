// https://edabit.com/challenge/ap8RPaHhkEPAkCSAZ

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

string rearrange(string sentence) {
    string answer {""};
    if (sentence.find_first_of("0123456789") == string::npos)
        return answer;
   
    map<int, string> m {};
    istringstream iss {sentence};
    string temp;
    while (iss >> temp){
        auto pos = temp.find_first_of("0123456789");
        int key = static_cast<int>(temp.at(pos)) - int('0');
        temp.erase(pos, 1);
        m.emplace(key, temp);
    }
   
    for (auto it = m.begin(); it != m.end(); ++it){
        answer.append(it->second);    
        answer.push_back(' ');
    }
    answer.pop_back();
    return answer;
}

int main(int argc, char** argv){

    cout << "success" << endl;
    return 0;
}