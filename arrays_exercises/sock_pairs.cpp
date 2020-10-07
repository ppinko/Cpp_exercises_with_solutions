// https://edabit.com/challenge/YfwuLW5bRKuSsa8FD

#include <cassert>
#include <iostream>

#include <algorithm>
#include <string>

using namespace std;

int sockPairs(const string &socks) {
	string ordered_socks {socks};
    sort(ordered_socks.begin(), ordered_socks.end());
    char c = ' ';
    int socks_counter {0}, pairs_counter {0};
    for (const auto &sock : ordered_socks){
        if (sock == c)
            ++socks_counter;
        else {
            c = sock;
            pairs_counter += socks_counter / 2;
            socks_counter = 1;
        }
    }
    pairs_counter += socks_counter / 2;
    return pairs_counter;
}


int main(){

    assert((sockPairs("AA") == 1));
    assert((sockPairs("ABABC") == 2));
    assert((sockPairs("CABBACCC") == 4));
    assert((sockPairs("AACDE") == 1));
    assert((sockPairs("ACDBE") == 0));
    assert((sockPairs("") == 0));
    assert((sockPairs("ABABAB") == 2));
    assert((sockPairs("AAAAA") == 2));
    assert((sockPairs("AAACCBB") == 3));

    cout << "Success" << endl;

    return 0;
};