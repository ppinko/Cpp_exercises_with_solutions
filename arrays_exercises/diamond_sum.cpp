// https://edabit.com/challenge/n9NtsAnWmrkhgyxBA
#include <iostream>

using namespace std;

int diamondSum(int n) {
    int total = 0;
    const int middle = n / 2 + 1;
    for (int i = 0; i < n; ++i){
        if (i == 0 || i == n-1)
            total += n*i + middle;
        else
            total += 2 * (n*i +  middle);
    }
    return total;
}

int main()
{
    cout << "Total: " << diamondSum(3) << endl;
    cout << "END" << endl;

    return 0;
}