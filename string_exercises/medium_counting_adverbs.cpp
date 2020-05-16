/*
https://edabit.com/challenge/fZrg8ETk2E9ghiX2m

Counting Adverbs

Create a function that counts the number of adverbs in a sentence. An adverb is a word that ends with ly.

Examples:

countAdverbs("She ran hurriedly towards the stadium.") ➞ 1
countAdverbs("She ate the lasagna heartily and noisily.") ➞ 2
countAdverbs("He hates potatoes.") ➞ 0
countAdverbs("He was happily, crazily, foolishly over the moon.") ➞ 3
*/


#include <iostream>
#include <vector>
#include <string>
#include <cctype>

int countAdverbs(std::string s) {
    int ans {0};
    while ((s.find("ly")) != std::string::npos){
        int k = s.find("ly");
        if (!std::isalpha(s.at(k + 2))) ans++;
        s.erase(0, k + 2);
    }
    return ans;
}

int main(){
    std::cout << countAdverbs("She ate the lasagna heartily and noisily.") << std::endl;
    std::cout << "Success" << std::endl;
    return 0;
}
