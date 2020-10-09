// https://edabit.com/challenge/GDRaujTACyHZnnrPk 

#include <iostream>
#include <algorithm>

#include <string>
#include <cassert>
#include <vector>

using namespace std;
string elapsedTime(string sa, string st) {
    vector<vector<int>> times (2, vector<int> ());
    vector<string> strings {sa, st};
    
    // creating two vectors of integers
    for (int j = 0; j < 2; ++j){
        for (int i = 0; i < 3; ++i){
            auto digits = strings.at(j).substr(3*i, 2);
            int val = stoi(digits);
            times.at(j).push_back(val);
        }
    }

    vector<int> elapsed (3, 0);
    for (int i = 2; i >= 0; --i){
        int temp = times.at(1).at(i) - times.at(0).at(i);   
        if (temp < 0 && i != 0){
            temp += 60;
            if (times.at(1).at(i-1) != 0)
                times.at(1).at(i-1) -= 1;
            else {
                if (i - 1 == 1){
                    times.at(1).at(i-1) = 59;
                    if (times.at(1).at(0) != 0)
                        times.at(1).at(0) -= 1;
                    else 
                        times.at(1).at(0) = 23;
                }
            }
        }
        else if (temp < 0 && i == 0){
            temp += 24;
        }
        elapsed.at(i) = temp;
    }    

    string answer {};
    for (const auto &n : elapsed){
        string temp = to_string(n);
        if (temp.size() == 1)
            answer.push_back('0');
        answer.append(temp);
        answer.push_back(':');
    }
    answer.pop_back();

    // copy(elapsed.cbegin(), elapsed.cend(), ostream_iterator<int>(cout, " "));    
    // cout << endl;

    return answer;
}

int main(){

    cout << elapsedTime("11:00:00", "12:00:00") << endl;

	// elapsedTime("11:00:00", "12:00:00");
	// elapsedTime("13:01:43", "21:41:57");
	// elapsedTime("17:34:43", "17:34:42");
	// elapsedTime("15:01:27", "02:51:33");
	// elapsedTime("00:00:01", "17:34:42");
	// elapsedTime("07:59:59", "08:00:00");
	// elapsedTime("23:59:59", "00:00:00");
	// elapsedTime("15:00:00", "15:01:00");
	// elapsedTime("06:12:27", "10:34:13");
	// elapsedTime("03:22:44", "18:04:11");

	assert((elapsedTime("11:00:00", "12:00:00") == "01:00:00"));
	assert((elapsedTime("13:01:43", "21:41:57") == "08:40:14"));
	assert((elapsedTime("17:34:43", "17:34:42") == "23:59:59"));
	assert((elapsedTime("15:01:27", "02:51:33") == "11:50:06"));
	assert((elapsedTime("00:00:01", "17:34:42") == "17:34:41"));
	assert((elapsedTime("07:59:59", "08:00:00") == "00:00:01"));
	assert((elapsedTime("23:59:59", "00:00:00") == "00:00:01"));
	assert((elapsedTime("15:00:00", "15:01:00") == "00:01:00"));
	assert((elapsedTime("06:12:27", "10:34:13") == "04:21:46"));
	assert((elapsedTime("03:22:44", "18:04:11") == "14:41:27"));

    return 0;
}