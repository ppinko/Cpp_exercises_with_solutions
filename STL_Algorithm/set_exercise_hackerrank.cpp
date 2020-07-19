// https://www.hackerrank.com/challenges/cpp-sets/problem

#include <iostream>
#include <set>
#include <iterator>

int main(){
    int num_queries, type, value;
    std::set<int> s;

    std::cin >> num_queries;
    for (int i = 0; i< num_queries; ++i)
    {
        std::cin >> type >> value;
        if (type == 1)
            s.insert(value);
        else if (type == 2)
            s.erase(value);
        else if (type == 3)
        {
            std::set<int>::iterator it = s.find(value);
            if (it != s.end())
                std::cout << "Yes" << std::endl;
            else
                std::cout << "No" << std::endl;            
        }
    }
    return 0;
}