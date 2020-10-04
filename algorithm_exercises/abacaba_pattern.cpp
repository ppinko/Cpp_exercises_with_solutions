// https://edabit.com/challenge/ipj3zGycaCtwWwXZ8

#include <iostream>
#include <cassert>

#include <string>

using namespace std;

string abacabaPattern(const int &n) {
    string solution {};
    int i = 1, letter = 65; // 65 equals 'A'
    while (i <= n){
        if (i == 1){
            solution.push_back('A');
        }
        else {
            solution = solution + static_cast<char>(letter) + solution;
        }
        ++i;
        ++letter;
    }
	return solution;
}

int main(){

	assert((abacabaPattern(1) =="A"));
	assert((abacabaPattern(2) =="ABA"));
	assert((abacabaPattern(3) =="ABACABA"));
	assert((abacabaPattern(4) =="ABACABADABACABA"));
	assert((abacabaPattern(5) =="ABACABADABACABAEABACABADABACABA"));
	assert((abacabaPattern(6) =="ABACABADABACABAEABACABADABACABAFABACABADABACABAEABACABADABACABA"));
	assert((abacabaPattern(7) =="ABACABADABACABAEABACABADABACABAFABACABADABACABAEABACABADABACABAGABACABADABACABAEABACABADABACABAFABACABADABACABAEABACABADABACABA"));
	assert((abacabaPattern(8) =="ABACABADABACABAEABACABADABACABAFABACABADABACABAEABACABADABACABAGABACABADABACABAEABACABADABACABAFABACABADABACABAEABACABADABACABAHABACABADABACABAEABACABADABACABAFABACABADABACABAEABACABADABACABAGABACABADABACABAEABACABADABACABAFABACABADABACABAEABACABADABACABA"));
	assert((abacabaPattern(9) =="ABACABADABACABAEABACABADABACABAFABACABADABACABAEABACABADABACABAGABACABADABACABAEABACABADABACABAFABACABADABACABAEABACABADABACABAHABACABADABACABAEABACABADABACABAFABACABADABACABAEABACABADABACABAGABACABADABACABAEABACABADABACABAFABACABADABACABAEABACABADABACABAIABACABADABACABAEABACABADABACABAFABACABADABACABAEABACABADABACABAGABACABADABACABAEABACABADABACABAFABACABADABACABAEABACABADABACABAHABACABADABACABAEABACABADABACABAFABACABADABACABAEABACABADABACABAGABACABADABACABAEABACABADABACABAFABACABADABACABAEABACABADABACABA"));

    cout << "success" << endl;
    cout << static_cast<int>('A') << endl;

    return 0;
}