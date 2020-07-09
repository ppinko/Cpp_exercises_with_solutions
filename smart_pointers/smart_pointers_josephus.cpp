// https://edabit.com/challenge/yYwNg8Dw2HZyGRwrf

#include <iostream>
#include <cassert>
#include <memory>
#include <vector>

int whoGoesFree(int n, int k) {
	auto ptr = std::make_unique<std::vector<int>>();
    
    for (int i = 0; i < n; ++i) 
        ptr->push_back(i);
    
    int last_pos = -1;
    for (int i = 0; i < n - 1; ++i){ 
        int temp = (last_pos + k) % ptr->size();
        ptr->erase(ptr->begin() + temp);
        last_pos = temp - 1;
    }
    return ptr->at(0);
}

int main(){

    assert((whoGoesFree(9, 2) == 2));
	assert((whoGoesFree(9, 3) == 0));
	assert((whoGoesFree(7, 2) == 6));
	assert((whoGoesFree(7, 3) == 3));
	assert((whoGoesFree(15, 4) == 12));
	assert((whoGoesFree(14, 3) == 1));
    std::cout << "Success" << std::endl;
    return 0;
}