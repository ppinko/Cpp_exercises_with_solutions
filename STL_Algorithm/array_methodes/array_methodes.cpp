#include <array>
#include <iostream>

int main(){
    std::array<int, 5> arr{1,2,3,4,5};
    std::cout << arr.size() << " " << arr.at(4) << " " << arr[0] << "\n"; 
    int x = arr.front();
    int y = arr.back();
    std::cout << x << " " << y << "\n";
    arr.fill(10);
    std::cout << arr.size() << " " << arr.at(4) << " " << arr[0] << "\n";
    for (int i {0}; i < 5; i++){
        arr[i] += 1;
    } 
    std::cout << arr.size() << " " << arr.at(4) << " " << arr[0] << "\n";
    // arr.at(5) = 7;
    std::array<int, 5> arr2{};
    arr2.fill(7);
    std::cout << arr2.size() << " " << arr2.at(4) << " " << arr2[0] << "\n";
    return 0;
}