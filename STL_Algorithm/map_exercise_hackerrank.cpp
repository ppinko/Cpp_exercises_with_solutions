// https://www.hackerrank.com/challenges/cpp-maps/problem

#include <map>
#include <utility>
#include <iostream>
#include <string>

int main(){
    int num_queries, type, note;
    std::string name;
    std::map<std::string, int> m;

    std::cin >> num_queries;
    for (int i = 0; i< num_queries; ++i)
    {
        std::cin >> type >> name;
        if (type == 1){
            std::cin >> note;
            std::map<std::string, int>::iterator it = m.find(name);
            if (it == m.end()){
                m.insert(std::make_pair(name, note));
            }
            else {
                m[name] += note;
            }
        }
        else if (type == 2)
            m[name] = 0;
        else if (type == 3)
        {
            std::cout << m[name] << std::endl;
        }
    }
    return 0;
}