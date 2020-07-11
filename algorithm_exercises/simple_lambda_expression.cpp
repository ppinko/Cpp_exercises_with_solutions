/*
Print all the numbers to n which are not divisible by 2 or 3 using lambda expression
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <memory>
#include <numeric>

int main(){

    std::vector<int> v (100, 0);
    std::iota(v.begin(), v.end(), 1);

    int num_counter = 0;
    std::copy_if(v.cbegin(), v.cend(), std::ostream_iterator<int>(std::cout, " "), 
        [&num_counter](int n){if (n % 2 != 0 && n % 3 != 0){
            ++num_counter;
            return true;
        } else {return false;};});
    std::cout << std::endl << "Number of numbers not divisible by 2 or 3 is " << num_counter << std::endl;

    return 0;
}