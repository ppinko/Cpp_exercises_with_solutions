// https://edabit.com/challenge/TpSRsX8zrTwrnkpq5

#include <iostream>
#include <cassert>

#include <vector>

using namespace std;

vector <int> safecracker(int start, vector<int> increments) {
	vector<int> code {};
    for (int i = 0; i < 3; ++i){
        if (i == 0 || i == 2){
            start -= increments.at(i);
            if (start < 0)
                start += 100;
        } else {
            start += increments.at(i);
            if (start > 99)
                start -= 100;
        }
        code.push_back(start);
    }
    return code;
}

int main(){

    cout << "Success" << endl;

    return 0;
}