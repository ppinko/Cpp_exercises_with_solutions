/*
https://edabit.com/challenge/ku2qwNJM6ezaLwgWv

Recomposing Strings

In this challenge, the goal is recomposing scrambled strings made of two or more words.

Every string has to be reversed not in its totality, but by vowels or consonants clusters
in the order they are found; after splitting the string in groups, and reversing every
group with more than a letter, you'll obtain the correct sequence:

String = "KiKdaola"
Separation vowels/consonants = K  i  Kd  ao  l  a
Reversing the groups = K  i  dK  oa  l  a
New string = KidKoala

Now, you have to insert a space between the words. A word starts with a capital letter:
String = "KidKoala"
Result = "Kid Koala"

Given a string, implement a function that returns, in turn, a new correct string,
following the above instructions.
*/

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <set>
#include <algorithm>

std::string recompose(std::string str) {
	std::vector<std::string> v {};
    std::string temp {};
    std::set<char> vowels {'a', 'e', 'i', 'o', 'u'};
    bool flag_consonant = true;
    bool flag_vowel = true;
    for (char& c: str){
        char k = std::tolower(c);
        if (vowels.count(k) == 0) {
            flag_vowel = false;
            if (flag_consonant == false){
                flag_consonant = true;
                v.push_back(temp);
                temp.clear();
            }
            temp += c;
        }
        else if (vowels.count(k) == 1){
            flag_consonant = false;
            if (flag_vowel == false){
                flag_vowel = true;
                v.push_back(temp);
                temp.clear();
            }
            temp += c;
        }
    }
    v.push_back(temp);
    for (auto& i: v){
        if (i.length() == 1) continue;
        else std::reverse(i.begin(), i.end());
    }
    std::vector<std::string> ans {};
    std::string t_str {};
    bool new_word = true;
    for (auto const& i: v){
        for (auto const& j: i){
            if (new_word == true){
                t_str += j;
                new_word = false;
            }
            else if (std::islower(j)) t_str += j;
            else {
                ans.push_back(t_str);
                t_str.clear();
                t_str += j;
                new_word = true;
            }
        }
    }
    ans.push_back(t_str);
    std::string s_ans {};
    for (int i (0); i < ans.size(); i++){
        if (i == ans.size() - 1) s_ans += ans[i];
        else s_ans += ans[i] + " ";
    }
    return s_ans;
}


int main(){
    std::cout << recompose("KiKdaola") << std::endl;
    std::cout << "Success" << std::endl;
    return 0;
}