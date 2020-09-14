// https://edabit.com/challenge/aYmZ4TycBKmgow9t6

#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string expand(int num) {
    string str_num = to_string(num);
    int str_length = str_num.size();
    vector<string> subnums {};
    for (int i = 0; i < str_length; ++i){
        if (str_num.at(i) != '0'){
            string zeroes (str_length - i - 1, '0');
            zeroes.push_back(str_num.at(i));
            reverse(zeroes.begin(), zeroes.end());
            subnums.push_back(zeroes);
        }
    }
    string answer = subnums.at(0);
    for (int i = 1; i < subnums.size(); ++i){
        answer += " + ";
        answer.append(subnums.at(i));
    } 
    return answer;
}

int main(){

    cout << expand(13) << endl;

	assert((expand(13) == "10 + 3"));
	assert((expand(86) == "80 + 6"));
	assert((expand(17000000) == "10000000 + 7000000"));
	assert((expand(420370022) == "400000000 + 20000000 + 300000 + 70000 + 20 + 2"));
	assert((expand(70304) == "70000 + 300 + 4"));
	assert((expand(9000000) == "9000000"));
	assert((expand(5325) == "5000 + 300 + 20 + 5"));

    return 0;
}