// https://edabit.com/challenge/dN6R8xLL6WLLDEhs4

#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::string pascalsTriangle(uint64_t row){
    std::stringstream pascal;
    if (row == 1)
    {
        pascal << 1 << " " << 1;
        return pascal.str();
    }
    std::vector<uint64_t> last {1, 1};
    for (int i = 2; i <= row; ++i)
    {
        std::vector<uint64_t> temp {1};
        for (int j = 0; j < last.size() - 1; ++j)
        {
            temp.push_back(last[j] + last[j+1]);
        }
        temp.push_back(1);
        last = temp;
        temp.clear();
    }

    for (int i = 0; i < last.size() - 1; ++i)
    {
        pascal << last[i] << " ";
    }
    pascal << last[last.size() - 1];
	return pascal.str();
}

int main()
{

    // std::cout << pascalsTriangle(2) << std::endl;

	assert((pascalsTriangle(1) == "1 1"));
	assert((pascalsTriangle(2) == "1 2 1"));	
	assert((pascalsTriangle(3) == "1 3 3 1"));
	assert((pascalsTriangle(4) == "1 4 6 4 1"));
	assert((pascalsTriangle(5) == "1 5 10 10 5 1"));
	assert((pascalsTriangle(6) == "1 6 15 20 15 6 1"));

    std::cout << "Success" << std::endl;

    return 0;
}