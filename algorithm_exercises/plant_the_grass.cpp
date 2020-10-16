// https://edabit.com/challenge/szij3YFmix7bMN7En

#include <iostream>

#include <iterator>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> simulateGrass(vector<string> g, int x, int y) {
    // planting first grass if not rocky ground
    const size_t rows = g.size();
    const size_t letters = g.at(0).size();

    if (g.at(x).at(y) == '.')
        g.at(x).at(y) = '+';
    else
        return g;

    bool flag = true;
    while(flag){
        flag = false;
        // taversing from top left to bottom right
        for (size_t i = 0; i < rows; ++i){
            for (size_t j = 0; j < letters; ++j){
                if (g.at(i).at(j) == '.'){
                    if (i != rows-1 && g.at(i+1).at(j) == '+'){
                        g.at(i).at(j) = '+';
                        flag = true;
                    }
                    else if (i != 0 && g.at(i-1).at(j) == '+'){
                        g.at(i).at(j) = '+';
                        flag = true;
                    }
                    else if (j != letters-1 && g.at(i).at(j+1) == '+'){
                        g.at(i).at(j) = '+';
                        flag = true;
                    }
                    else if (j != 0 && g.at(i).at(j-1) == '+'){
                        g.at(i).at(j) = '+';
                        flag = true;
                    }
                }
            }    
        }
   
        // taversing from bottom right to top left
        for (int i = rows-1; i >= 0; --i){
            for (int j = letters-1; j >= 0; --j){
                if (g.at(i).at(j) == '.'){
                    if (i != rows-1 && g.at(i+1).at(j) == '+'){
                        g.at(i).at(j) = '+';
                        flag = true;
                    }
                    else if (i != 0 && g.at(i-1).at(j) == '+'){
                        g.at(i).at(j) = '+';
                        flag = true;
                    }
                    else if (j != letters-1 && g.at(i).at(j+1) == '+'){
                        g.at(i).at(j) = '+';
                        flag = true;
                    }
                    else if (j != 0 && g.at(i).at(j-1) == '+'){
                        g.at(i).at(j) = '+';
                        flag = true;
                    }
                }
            }    
        }
    }
    return g;
}

int main()
{

    vector<string> v = simulateGrass({"xxxxxxx","x.....x","xxxx..x","x...xxx","xxxxxxx"}, 1, 1);
    for (const auto i : v)
        cout << i << endl;
   
    cout << "END" << endl;
}