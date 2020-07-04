// https://edabit.com/challenge/k2Tt4w7RihAQS2GHp

#include <vector>
#include <iostream>

int ulam(int n) {
    std::vector<int> sequence {1, 2};
    int current = 2;
    int next = sequence.back() + 1;
    while (current < n){
        int counter = 0;
        bool ulam_number = true;
        for (int i = 0; i < sequence.size() - 1; i++){
            for (int j = i+1; j < sequence.size(); j++){
                int to_test = sequence.at(i) + sequence.at(j);
                if (to_test == next) counter++;
                else if (to_test > next) break;
                if (counter >= 2) {
                    ulam_number = false;
                    break;
                }
            }
            if (!ulam_number) break;            }
        if (ulam_number && counter == 1){
            sequence.push_back(next);
            current++;
        }
        next++;
    }
    return sequence.at(n-1);
}


int main(){
    std::cout << ulam(38) << std::endl;
    return 0;
}