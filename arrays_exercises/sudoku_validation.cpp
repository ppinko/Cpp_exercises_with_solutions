// https://edabit.com/challenge/pn98BSiyPAqyi2d5W
#include <iostream>

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool accessBlock(const vector<int> &block){
    const unordered_set<int> us {block.cbegin(), block.cend()};
    auto min_val = min_element(block.cbegin(), block.cend());
    auto max_val = max_element(block.cbegin(), block.cend());
    // cout << us.size() << " - " << *min_val  << " - " << *max_val << endl;
    if (us.size() != 9 || *min_val != 1 || *max_val != 9){
        return false;
    }
    return true;
}

bool sudokuValidator(vector<vector<int>> arr) {
    // checking rows and columns
for (int i = 0; i < arr.size(); ++i){
   vector<int> column;
   for (int j = 0; j < arr.size(); ++j){
       column.push_back(arr.at(j).at(i));
   }
   if (!accessBlock(arr.at(i)) || !accessBlock(column))
       return false;
    }
   
    // checking blocks
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            vector<int> block {};
            auto it_begin = arr.at(3 * i).begin();
            it_begin += 3 * j;
            auto it_end = it_begin + 3;
            copy(it_begin, it_end, back_inserter(block));
           
            auto it_begin2 = arr.at(3 * i + 1).begin();
            it_begin2 += 3 * j;
            auto it_end2 = it_begin2 + 3;
            copy(it_begin2, it_end2, back_inserter(block));
           
            auto it_begin3 = arr.at(3 * i + 2).begin();
            it_begin3 += 3 * j;
            auto it_end3 = it_begin3 + 3;
            copy(it_begin3, it_end3, back_inserter(block));
           
            if (!accessBlock(block))
                return false;
        }    
    }
   
    return true;
}

int main()
{
    std::cout << accessBlock({1, 2, 3, 4, 5, 6, 7, 8, 9}) << endl;
    cout << "END" << endl;

    return 0;
}