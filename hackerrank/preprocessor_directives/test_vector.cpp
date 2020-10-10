#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    vector<int> v (6);
    
    for (const auto &i : v){
        cout << "test - " << i << endl;
    }

    return 0;
}
