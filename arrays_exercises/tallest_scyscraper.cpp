/*
https://edabit.com/challenge/ZMdhDnK9QbjtjHLuA
*/
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int tallest_skyscraper(std::vector< std::vector<int> > arr) {
	 int ts_size = arr.size();
     for (int i {0}; i < ts_size; i++, ts_size--){
         auto temp = arr.at(i);
         if(std::any_of(temp.begin(), temp.end(), [](int i){return i == 1;}))
            return ts_size;
     }
     return ts_size;
}

int main(){
    std::vector< std::vector<int> > arr2 {{0,0,0}, {0, 1, 0}, {1,1,1}};
    tallest_skyscraper(arr2);
    // std::cout << tallest_skyscraper(arr2) << std::endl;
    return 0;
} 