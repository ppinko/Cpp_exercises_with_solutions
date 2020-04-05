#include <string>
#include <array>
#include <iostream>
#include <vector>
#include <map>

/*
tweakLetters("many", [0, 0, 0, -1]) ➞ "manx"
*/

// std::string tweakLetters(std::string s, std::vector<int> arr) {
//     std::string lower_letters = "abcdefghijklmnopqrstuvwxyz";
//     size_t alphabet_len = lower_letters.length();
//     size_t pos {0};
//     for (size_t i {0}; i < s.length(); i++){
//         if (arr[i] == 0)
//             continue;
//         pos = lower_letters.find(s[i]);
//         if (arr[i] < 0 && std::abs(arr[i]) > pos)
//             s[i] = lower_letters[alphabet_len + pos + arr[i]];
//         else if (pos + arr[i] >= 0 && pos + arr[i] < alphabet_len){
//             s[i] = lower_letters[pos + arr[i]];
//         }
//         else { 
//             s[i] = lower_letters[pos + arr[i] - alphabet_len];
//         }

//     }
//     return s;
// }

std::string tweakLetters(std::string s, std::vector<int> arr) {
    std::string lower_letters = "abcdefghijklmnopqrstuvwxyz";
    size_t alphabet_len = lower_letters.length();
    size_t pos {0};
    for (size_t i {0}; i < s.length(); i++){
        if (arr[i] == 0)
            continue;
        pos = lower_letters.find(s[i]);
        if (arr[i] < 0 && std::abs(arr[i]) > pos)
            s[i] = lower_letters[alphabet_len + pos + arr[i]];
        else if (pos + arr[i] >= 0 && pos + arr[i] < alphabet_len){
            s[i] = lower_letters[pos + arr[i]];
        }
        else { 
            s[i] = lower_letters[pos + arr[i] - alphabet_len];
        }

    }
    return s;
}


int main(){
    std::vector<int> vec {-1, -1, -1};
    std::cout << tweakLetters("abc", vec) << std::endl;
    return 0;
}