#include <iostream> 
#include <cctype>

bool isPalindrome(std::string str);
bool rec_Palindrome(std::string low);
std::string sentence_to_lower(std::string str);

bool isPalindrome(std::string str){
    std::string lower = sentence_to_lower(str);
    return rec_Palindrome(lower);
}

bool rec_Palindrome(std::string low){
    if (low.length() == 1 || low.length() == 0)
        return true;
    if (low[0] != low[low.length()-1])
        return false;
    else
        return rec_Palindrome(low.substr(1, low.length() - 2));
    
}

std::string sentence_to_lower(std::string str){
    std::string lower {};
    for (char c : str){
        if (std::isalpha(c))
            lower += std::tolower(c);
    }  
    return lower;  
}

int main(){
    std::cout << isPalindrome("Neuquen") << std::endl;
    std::cout << isPalindrome("Not a palindrome") << std::endl;
    std::cout << isPalindrome("A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!") << std::endl;
    return 0;
}