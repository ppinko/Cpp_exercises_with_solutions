// https://edabit.com/challenge/XtSiS8ErRqfw9DLPu

#include <iostream>
#include <cassert>

#include <list>
#include <algorithm>
#include <string>

using namespace std;

bool is_palindrome(const int &num);
int descendants(const int &num);
bool palindromeDescendant(const int &num);

bool is_palindrome(const int &num){
    string s1 {to_string(num)};
    string s2 {s1};
    reverse(s2.begin(), s2.end());
    return s1 == s2;
}

int descendants(const int &num){
    string s1 {};
    list<int> temp_sums {};
    int temp = num;
    while (temp != 0){
        int a = temp % 10;
        temp /= 10;
        int b = temp % 10;
        temp /= 10;
        temp_sums.push_front(a+b);
    }
    for (auto it = temp_sums.crbegin(); it != temp_sums.crend(); ++it){
        s1.append(to_string(*it));
    }
    return stoi(s1);
}

bool palindromeDescendant(const int &num) {
	int temp = num;
    string str {to_string(temp)};
    while (str.size() >= 2 && str.size() % 2 == 0){
        if (str.size() == 2){
            return is_palindrome(temp);
        }

        if (is_palindrome(temp)){
            // cout << temp << endl;
            return true;
        }
        else {
            temp = descendants(temp);
        }
        str = to_string(temp);
    }
    return false;
}

int main(){

    assert((palindromeDescendant(11211230) == false));
	assert((palindromeDescendant(11211230) == false));
	assert((palindromeDescendant(13001120) == true));
	assert((palindromeDescendant(23336014) == true));
	assert((palindromeDescendant(11) == true));
	assert((palindromeDescendant(1122) == false));
	assert((palindromeDescendant(332233) == true));
	assert((palindromeDescendant(10210112) == true));
	assert((palindromeDescendant(9735) == false));
	assert((palindromeDescendant(97358817) == false));

    cout << "success" << endl;
    cout << palindromeDescendant(11211230) << endl;

    return 0;
}