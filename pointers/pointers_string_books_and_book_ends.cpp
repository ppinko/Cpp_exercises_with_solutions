// https://edabit.com/challenge/be7jj9Qn739fDRN7A


#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <set>

int countUniqueBooks(std::string str, char bookend) {
	std::string *s = new std::string;   // pointer allocation on the heap
    std::copy(str.begin(), str.end(), std::back_inserter(*s));  // copying str to pointer

    // Now the real fun begins
    std::set<char> *set = new std::set<char>{};
    int start = 0;
    while (true){
        int a = s->find(bookend, start);
        if (a == -1) break;
        start = a + 1;
        int b = s->find(bookend, start);
        if (b == -1) break;
        start = b + 1;
        set->insert(s->begin() + a + 1, s->begin() + b);
    }
    std::cout << s << " and " << *s << std::endl;
    int ans = set->size();
    delete s;       // releasing allocating storage for string
    delete set;     // releasing allocating storage for set
    return ans;
}


int main(){
    std::cout << countUniqueBooks("AZYWABBCATTTA", 'A') << " should be equal to 4" << std::endl;
    std::cout << "Success" << std::endl;
    return 0;
}