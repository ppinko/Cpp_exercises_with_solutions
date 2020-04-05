/*
https://edabit.com/challenge/NGD8wv2rKoFDKzmEu
*/

#include <string>
#include <iostream>
#include <sstream>
#include <limits>   // necesarry for min int and max int


std::string highLow(std::string str) {
  auto ss = std::istringstream(str);
  int min = std::numeric_limits<int>::max();
  int max = std::numeric_limits<int>::min();
  int num = 0;
  while (ss >> num)
  {
    if (num < min) min = num;
    if (num > max) max = num;
  }
  return std::to_string(max) + ' ' + std::to_string(min);
}

int main(){
    std::cout << highLow("1 2 3 4 5") << " = 5 1" << std::endl;
    std::cout << highLow("1 2 -3 4 5") << " = 5 -3" << std::endl;
    std::cout << highLow("1 9 3 4 -5") << " = 9 -5" << std::endl;
    std::cout << highLow("13") << " = 13 13" << std::endl;
    return 0;
}