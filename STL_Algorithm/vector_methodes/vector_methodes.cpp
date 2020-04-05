#include <vector>
#include <algorithm>
#include <iomanip>
#include <iostream>

int main(){
    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> vec2 {0,5,8};
    std::vector<int> vec3 {};
    vec3 = std::copy(vec.cbegin(), vec.cend(), vec3.begin());
    vec3 = vec.insert(vec3.end(), vec2.crbegin(), vec2.crend());
    vec.assign(5, 10);
    
    //vec.erase(vec.begin()+3, vec.end()-1);

    // std::vector<int>::iterator it = vec.begin();
    // while (it != vec.end()){
    //     if (*it % 3 == 1)
    //         vec.erase(it);
    //     else
    //         it++;
    // }
    // auto it2 = vec.begin() + 5;
    // vec.insert(it2, vec2.begin(), vec2.end());

    std::for_each(vec.begin(), vec.end(), [] (int i) {std::cout << i << std::endl;});
    // std::for_each(vec2.begin(), vec2.end(), [] (int i) {std::cout << i << std::endl;});
    return 0;
}