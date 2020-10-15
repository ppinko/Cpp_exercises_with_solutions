// https://edabit.com/challenge/rscwis53jKokoKRYo

#include <iostream>
#include <cassert>

#include <string>
#include <vector>
#include <set>

using namespace std;

vector<vector<char>> tranform_matrix(vector<vector<char>> m);
string ticTacToe(vector<vector<char>> inputs);

vector<vector<char>> tranform_matrix(vector<vector<char>> m){
    const size_t rows = m.size();
    const size_t columns = m.at(0).size();
    vector<vector<char>> t (columns, vector<char> (rows, ' '));
    for (size_t i = 0; i < columns; ++i){
        for (size_t j = 0; j < rows; ++j){
            t.at(i).at(j) = m.at(j).at(i);
        }
    }
    return t;
}

string ticTacToe(const vector<vector<char>> inputs) {
	vector<vector<char>> t = tranform_matrix(inputs);

    vector<vector<vector<char>>> v {};
    v.push_back(inputs);
    v.push_back(t);
    
    // checking rows
    for (const auto &vec: v){
        for (size_t i = 0; i < vec.size(); ++i){
            set<char> s (begin(vec.at(i)), end(vec.at(i)));
            if (s.size() == 1){
                if (s.find('X') != s.end())
                    return "Player 1 wins";
                else 
                    return "Player 2 wins";
            }
        }
    }
    // checking diagonals
    if (t.at(0).at(0) == t.at(1).at(1) && t.at(1).at(1) == t.at(2).at(2)
        || t.at(0).at(2) == t.at(1).at(1) && t.at(1).at(1) == t.at(2).at(0)){
        if (t.at(1).at(1) == 'X')
            return "Player 1 wins";
        else 
            return "Player 2 wins";
    }
    return "It's a Tie";
}

int main(int argc, char** argv){



    cout << "success" << endl;
    return 0;
}