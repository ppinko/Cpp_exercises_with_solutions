// Anagram

#include <string>
#include <iostream>

int makeAnagram(std::string a, std::string b) {
    int counter {0};
    size_t pos {};
    for (char i: a){
        pos = b.find(i);
        if (pos != std::string::npos)
            b.erase(pos, 1);
        else
            counter++;
    }
    counter += b.length();
    return counter;
}

int main(){
    std::cout << makeAnagram("fcrxzwscanmligyxyvym", "jxwtrhvujlmrpdoqbisbwhmgpmeoke") << std::endl;
    return 0;
}